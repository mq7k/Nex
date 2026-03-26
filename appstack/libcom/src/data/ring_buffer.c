#include "libcom/data/ring_buffer.h"
#include "errcodes.h"
#include "libcom/util.h"
#include <limits.h>

static void
_advance_head(
  struct nex_ring_buffer* buffer,
  u32 len
)
{
  buffer->head = FAST_MOD(buffer->head + len, buffer->len);
  buffer->size -= len;
}

static void
_advance_tail(
  struct nex_ring_buffer* buffer,
  u32 len
)
{
  buffer->tail = FAST_MOD(buffer->tail + len, buffer->len);
  buffer->size += len;
}

i32
nex_ring_buffer_init(
  struct nex_ring_buffer* buffer,
  u8* rawbuf,
  u32 len
)
{
  if (!nex_is_power_of_two(len))
  {
    return -NERR_INV_ARG;
  }

  nex_ring_buffer_init_unsafe(buffer, rawbuf, len);
  return NOK;
}

void
nex_ring_buffer_init_unsafe(
  struct nex_ring_buffer* buffer,
  u8* rawbuf,
  u32 len
)
{
  buffer->head = 0;
  buffer->tail = 0;
  buffer->size = 0;
  buffer->buffer = rawbuf;
  buffer->len = len;
}

u32
nex_ring_buffer_size(
  struct nex_ring_buffer* buffer
)
{
  return buffer->size;
}

u32
nex_ring_buffer_space_left(
  struct nex_ring_buffer* buffer
)
{
  return buffer->len - nex_ring_buffer_size(buffer);
}

u32
nex_ring_buffer_len(
  struct nex_ring_buffer* buffer
)
{
  return buffer->len;
}

u32
nex_ring_buffer_is_empty(
  struct nex_ring_buffer* buffer
)
{
  return buffer->size == 0;
}

void
nex_ring_buffer_clear(
  struct nex_ring_buffer* buffer
)
{
  buffer->head = 0;
  buffer->tail = 0;
  buffer->size = 0;
}

i32
nex_ring_buffer_write(
  struct nex_ring_buffer* buffer,
  u8 byte
)
{
  if (buffer->size == buffer->len)
  {
    return -NERR_FULL;
  }

  nex_ring_buffer_write_unsafe(buffer, byte);
  return NOK;
}

void
nex_ring_buffer_write_unsafe(
  struct nex_ring_buffer* buffer,
  u8 byte
)
{
  buffer->buffer[buffer->tail] = byte;
  _advance_tail(buffer, 1);
}

i32
nex_ring_buffer_pop_head(
  struct nex_ring_buffer* buffer,
  u8* byte
)
{
  if (nex_ring_buffer_is_empty(buffer))
  {
    return -NERR_EMPTY;
  }

  *byte = nex_ring_buffer_pop_head_unsafe(buffer);
  return NOK;
}

u8
nex_ring_buffer_pop_head_unsafe(
  struct nex_ring_buffer* buffer
)
{
  u8 byte = buffer->buffer[buffer->head];
  _advance_head(buffer, 1);
  return byte;
}

i32
nex_ring_buffer_consume(
  struct nex_ring_buffer* buffer,
  u32 len
)
{
  if (len > buffer->size)
  {
    return -NERR_INV_ARG;
  }

  nex_ring_buffer_consume_unsafe(buffer, len);
  return NOK;
}

void
nex_ring_buffer_consume_unsafe(
  struct nex_ring_buffer* buffer,
  u32 len
)
{
  _advance_head(buffer, len);
}

i32
nex_ring_buffer_head_peek(
  struct nex_ring_buffer* buffer,
  u8* byte
)
{
  if (nex_ring_buffer_is_empty(buffer))
  {
    return -NERR_EMPTY;
  }

  *byte = nex_ring_buffer_head_peek_unsafe(buffer);
  return NOK;
}

u8
nex_ring_buffer_head_peek_unsafe(
  struct nex_ring_buffer* buffer
)
{
  return buffer->buffer[buffer->head];
}

i32
nex_ring_buffer_copy(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
)
{
  if (dst == NULL)
  {
    return -NERR_INV_ARG;
  }

  if (count > nex_ring_buffer_len(buffer))
  {
    return -NERR_INV_ARG;
  }

  if (count > INT_MAX)
  {
    return -NERR_RANGE;
  }

  u32 size = nex_ring_buffer_size(buffer);
  if (count > size)
  {
    count = size;
  }

  return (i32) nex_ring_buffer_copy_unsafe(buffer, dst, count);
}

u32
nex_ring_buffer_copy_unsafe(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
)
{
  if (buffer->head + count <= buffer->len)
  {
    // No need to wrap around.
    __builtin_memcpy(dst, &buffer->buffer[buffer->head], count);
    _advance_head(buffer, count);
    return count;
  }

  const u32 original_count = count;

  u32 bytes_left_before_wrap = buffer->len - buffer->head;
  __builtin_memcpy(dst, &buffer->buffer[buffer->head], bytes_left_before_wrap);

  count -= bytes_left_before_wrap;
  __builtin_memcpy(dst + bytes_left_before_wrap, buffer->buffer, count);

  buffer->size -= original_count;
  buffer->head = count;

  return original_count;
}

i32
nex_ring_buffer_peek_copy(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
)
{
  if (dst == NULL)
  {
    return -NERR_INV_ARG;
  }

  if (count > INT_MAX)
  {
    return -NERR_RANGE;
  }

  u32 size = nex_ring_buffer_size(buffer);
  if (count > size)
  {
    count = size;
  }

  return (i32) nex_ring_buffer_peek_copy_unsafe(buffer, dst, count);
}

u32
nex_ring_buffer_peek_copy_unsafe(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
)
{
  if (buffer->head + count <= buffer->len)
  {
    // No need to wrap around.
    __builtin_memcpy(dst, &buffer->buffer[buffer->head], count);
    return count;
  }

  const u32 original_count = count;

  u32 bytes_left_before_wrap = buffer->len - buffer->head;
  __builtin_memcpy(dst, &buffer->buffer[buffer->head], bytes_left_before_wrap);

  count -= bytes_left_before_wrap;
  __builtin_memcpy(dst + bytes_left_before_wrap, buffer->buffer, count);

  return original_count;
}

i32
nex_ring_buffer_write_bytes(
  struct nex_ring_buffer* buffer,
  u8* src,
  u32 count
)
{
  if (src == NULL)
  {
    return -NERR_RANGE;
  }

  if (count > INT_MAX)
  {
    return -NERR_RANGE;
  }

  u32 space_left = nex_ring_buffer_space_left(buffer);
  if (count > space_left)
  {
    count = space_left;
  }

  return (i32) nex_ring_buffer_write_bytes_unsafe(buffer, src, count);
}

u32
nex_ring_buffer_write_bytes_unsafe(
  struct nex_ring_buffer* buffer,
  u8* src,
  u32 count
)
{
  const u32 bytes_left = buffer->len - buffer->tail;
  if (bytes_left >= count)
  {
    // No need to wrap around.
    __builtin_memcpy(&buffer->buffer[buffer->tail], src, count);
    _advance_tail(buffer, count);
    return count;
  }

  const u32 original_count = count;

  __builtin_memcpy(&buffer->buffer[buffer->tail], src, bytes_left);
  count -= bytes_left;
  __builtin_memcpy(&buffer->buffer[0], src + bytes_left, count);

  _advance_tail(buffer, original_count);
  return count;
}

i32
nex_ring_buffer_find(
  struct nex_ring_buffer* buffer,
  u8 byte,
  u32 starting_at
)
{
  u32 sz = nex_ring_buffer_size(buffer);
  for (u32 i = starting_at; i < sz; ++i)
  {
    u32 idx = FAST_MOD(buffer->head + i, buffer->len);
    if (buffer->buffer[idx] == byte)
    {
      return (i32) (i - starting_at);
    }
  }

  return -NERR_NOT_FOUND;
}

u32
nex_ring_buffer_head_tell(
  struct nex_ring_buffer* buffer
)
{
  return buffer->head;
}

u32
nex_ring_buffer_tail_tell(
  struct nex_ring_buffer* buffer
)
{
  return buffer->tail;
}

void
nex_ring_buffer_head_pos(
  struct nex_ring_buffer* buffer,
  u32 pos
)
{
  buffer->head = pos;
}

void
nex_ring_buffer_tail_pos(
  struct nex_ring_buffer* buffer,
  u32 pos
)
{
  buffer->tail = pos;
}
