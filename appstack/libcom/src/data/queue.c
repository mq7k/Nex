#include "libcom/data/queue.h"
#include "errcodes.h"
#include "util.h"

static u8*
_get_entry(
  struct queue* queue,
  u32 idx
)
{
  const u32 mapped_idx = queue->element_sz * idx;
  return &queue->buf[mapped_idx];
}

i32
nex_queue_init(
  struct queue* queue,
  void* buf,
  u32 len,
  u32 element_sz
)
{
  if (!nex_is_power_of_two(len))
  {
    return -NERR_INV_ARG;
  }

  nex_queue_init_unsafe(queue, buf, len, element_sz);
  return NOK;
}

void
nex_queue_init_unsafe(
  struct queue* queue,
  void* buf,
  u32 len,
  u32 element_sz
)
{
  queue->buf = buf;
  queue->len = len;
  queue->head = 0;
  queue->tail = 0;
  queue->size = 0;
  queue->element_sz = element_sz;
}

void*
nex_queue_alloc(
  struct queue* queue
)
{
  if (queue->size >= queue->len)
  {
    return NULL;
  }

  return nex_queue_alloc_unsafe(queue);
}

void*
nex_queue_alloc_unsafe(
  struct queue* queue
)
{
  u8* element_ptr = _get_entry(queue, queue->tail);
  queue->tail = FAST_MOD(queue->tail + 1, queue->len);
  ++queue->size;
  return element_ptr;
}

void*
nex_queue_peek_head(
  struct queue* queue
)
{
  if (nex_queue_is_empty(queue))
  {
    return NULL;
  }

  return nex_queue_peek_head_unsafe(queue);
}

void*
nex_queue_peek_head_unsafe(
  struct queue* queue
)
{
  return _get_entry(queue, queue->head);
}

void*
nex_queue_peek_tail(
  struct queue* queue
)
{
  if (nex_queue_is_empty(queue))
  {
    return NULL;
  }

  return nex_queue_peek_tail_unsafe(queue);
}

void*
nex_queue_peek_tail_unsafe(
  struct queue* queue
)
{
  const u32 idx = FAST_MOD(queue->tail - 1, queue->len);
  return _get_entry(queue, idx);
}

void*
nex_queue_peek_nth(
  struct queue* queue,
  u32 idx
)
{
  if (nex_queue_size(queue) < idx)
  {
    return NULL;
  }

  return nex_queue_peek_nth_unsafe(queue, idx);
}

void*
nex_queue_peek_nth_unsafe(
  struct queue* queue,
  u32 idx
)
{
  return _get_entry(queue, queue->head + idx);
}

i32
nex_queue_pop_head(
  struct queue* queue
)
{
  if (nex_queue_is_empty(queue))
  {
    return -NERR_EMPTY;
  }

  nex_queue_pop_head_unsafe(queue);
  return NOK;
}

void
nex_queue_pop_head_unsafe(
  struct queue* queue
)
{
  queue->head = FAST_MOD(queue->head + 1, queue->len);
  --queue->size;
}

i32
nex_queue_pop_tail(
  struct queue* queue
)
{
  if (nex_queue_is_empty(queue))
  {
    return -NERR_EMPTY;
  }

  nex_queue_pop_tail_unsafe(queue);
  return NOK;
}

void
nex_queue_pop_tail_unsafe(
  struct queue* queue
)
{
  queue->tail = FAST_MOD(queue->tail - 1 + queue->len, queue->len);
  --queue->size;
}

void
nex_queue_clear(
  struct queue* queue
)
{
  queue->head = 0;
  queue->tail = 0;
  queue->size = 0;
}

u32
nex_queue_is_empty(
  struct queue* queue
)
{
  return queue->size == 0;
}

u32
nex_queue_size(
  struct queue* queue
)
{
  return queue->size;
}
