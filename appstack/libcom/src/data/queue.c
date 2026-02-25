#include "libcom/data/queue.h"

static u8*
_get_entry(
  struct queue* queue,
  u32 idx
)
{
  const u32 mapped_idx = queue->element_sz * idx;
  return &queue->buf[mapped_idx];
}

void
nex_queue_init(
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
  return _get_entry(queue, queue->head);
}

void*
nex_queue_peek_tail(
  struct queue* queue
)
{
  return _get_entry(queue, queue->tail - 1);
}

void*
nex_queue_peek_nth(
  struct queue* queue,
  u32 idx
)
{
  return _get_entry(queue, queue->head + idx);
}

void
nex_queue_pop_head(
  struct queue* queue
)
{
  queue->head = FAST_MOD(queue->head + 1, queue->len);
  --queue->size;
}

void
nex_queue_pop_tail(
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
