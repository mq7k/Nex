#ifndef NEX_QUEUE_H
#define NEX_QUEUE_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

struct queue
{
  u8* buf;
  u32 head;
  u32 tail;
  u32 size;
  u32 len;
  u32 element_sz;
};

void
nex_queue_init(
  struct queue* queue,
  void* buf,
  u32 len,
  u32 element_sz
);

void*
nex_queue_alloc(
  struct queue* queue
);

void*
nex_queue_peek_head(
  struct queue* queue
);

void*
nex_queue_peek_tail(
  struct queue* queue
);

void*
nex_queue_peek_nth(
  struct queue* queue,
  u32 idx
);

void
nex_queue_pop_head(
  struct queue* io
);

void
nex_queue_pop_tail(
  struct queue* io
);

void
nex_queue_clear(
  struct queue* queue
);

u32
nex_queue_is_empty(
  struct queue* queue
);

u32
nex_queue_size(
  struct queue* queue
);

END_DECLARATIONS

#endif
