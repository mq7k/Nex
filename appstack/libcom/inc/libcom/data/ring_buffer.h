#ifndef NEX_RING_BUFFER_H
#define NEX_RING_BUFFER_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

struct nex_ring_buffer
{
  u8* buffer;
  u32 head;
  u32 tail;
  u32 size;
  u32 len;
};

i32
nex_ring_buffer_init(
  struct nex_ring_buffer* buffer,
  u8* rawbuf,
  u32 len
);

void
nex_ring_buffer_init_unsafe(
  struct nex_ring_buffer* buffer,
  u8* rawbuf,
  u32 len
);

u32
nex_ring_buffer_size(
  struct nex_ring_buffer* buffer
);

u32
nex_ring_buffer_space_left(
  struct nex_ring_buffer* buffer
);

u32
nex_ring_buffer_len(
  struct nex_ring_buffer* buffer
);

u32
nex_ring_buffer_is_empty(
  struct nex_ring_buffer* buffer
);

void
nex_ring_buffer_clear(
  struct nex_ring_buffer* buffer
);

i32
nex_ring_buffer_write(
  struct nex_ring_buffer* buffer,
  u8 byte
);

void
nex_ring_buffer_write_unsafe(
  struct nex_ring_buffer* buffer,
  u8 byte
);

i32
nex_ring_buffer_pop_head(
  struct nex_ring_buffer* buffer,
  u8* byte
);

u8
nex_ring_buffer_pop_head_unsafe(
  struct nex_ring_buffer* buffer
);

i32
nex_ring_buffer_consume(
  struct nex_ring_buffer* buffer,
  u32 len
);

void
nex_ring_buffer_consume_unsafe(
  struct nex_ring_buffer* buffer,
  u32 len
);

i32
nex_ring_buffer_head_peek(
  struct nex_ring_buffer* buffer,
  u8* byte
);

u8
nex_ring_buffer_head_peek_unsafe(
  struct nex_ring_buffer* buffer
);

i32
nex_ring_buffer_copy(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
);

u32
nex_ring_buffer_copy_unsafe(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
);

i32
nex_ring_buffer_peek_copy(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
);

u32
nex_ring_buffer_peek_copy_unsafe(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
);

i32
nex_ring_buffer_write_bytes(
  struct nex_ring_buffer* buffer,
  u8* src,
  u32 count
);

u32
nex_ring_buffer_write_bytes_unsafe(
  struct nex_ring_buffer* buffer,
  u8* src,
  u32 count
);

i32
nex_ring_buffer_find(
  struct nex_ring_buffer* buffer,
  u8 byte,
  u32 starting_at
);

u32
nex_ring_buffer_head_tell(
  struct nex_ring_buffer* buffer
);

u32
nex_ring_buffer_tail_tell(
  struct nex_ring_buffer* buffer
);

void
nex_ring_buffer_head_pos(
  struct nex_ring_buffer* buffer,
  u32 pos
);

void
nex_ring_buffer_tail_pos(
  struct nex_ring_buffer* buffer,
  u32 pos
);

END_DECLARATIONS

#endif
