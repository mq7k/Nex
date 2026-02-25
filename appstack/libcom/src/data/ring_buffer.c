#include "libcom/data/ring_buffer.h"
#include "libcom/util.h"

#include <string.h>

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

void
nex_ring_buffer_init(
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

u32
nex_ring_buffer_write(
  struct nex_ring_buffer* buffer,
  u8 byte
)
{
  if (buffer->size == buffer->len)
  {
    return NEX_FAILURE;
  }

  buffer->buffer[buffer->tail] = byte;
  _advance_tail(buffer, 1);

  return NEX_SUCCESS;
}

u8
nex_ring_buffer_pop_head(
  struct nex_ring_buffer* buffer
)
{
  u8 byte = buffer->buffer[buffer->head];
  _advance_head(buffer, 1);
  return byte;
}

u8
nex_ring_buffer_read(
  struct nex_ring_buffer* buffer
)
{
  u8 byte = buffer->buffer[buffer->head];
  _advance_head(buffer, 1);
  return byte;
}

void
nex_ring_buffer_consume(
  struct nex_ring_buffer* buffer,
  u32 len
)
{
  if (len > buffer->size)
  {
    len = buffer->len;
  }

  _advance_head(buffer, len);
}

void
nex_ring_buffer_advance_tail(
  struct nex_ring_buffer* buffer,
  u32 len
)
{
  _advance_tail(buffer, len);
}

u8
nex_ring_buffer_head_peek(
  struct nex_ring_buffer* buffer
)
{
  return buffer->buffer[buffer->head];
}

void
nex_ring_buffer_readable_bytes_until_wrap(
  struct nex_ring_buffer* buffer,
  u8** ptr,
  u32* len
)
{
  *ptr = &buffer->buffer[buffer->head];

  if (buffer->tail > buffer->head)
  {
    *len = buffer->size;
  }
  else
  {
    *len = buffer->len - buffer->head;
  }
}

void
nex_ring_buffer_writable_bytes_until_wrap(
  struct nex_ring_buffer* buffer,
  u8** ptr,
  u32* len
)
{
  *ptr = &buffer->buffer[buffer->tail];

  if (buffer->tail >= buffer->head)
  {
    *len = buffer->len - buffer->tail;
  }
  else
  {
    *len = buffer->head - buffer->tail;
  }
}

u32
nex_ring_buffer_copy(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
)
{
  u32 sz = nex_ring_buffer_size(buffer);
  if (count > sz)
  {
    count = sz;
  }

  if (buffer->head + count < buffer->len)
  {
    // No need to wrap around.
    memcpy(dst, &buffer->buffer[buffer->head], count);
    buffer->size -= count;
    buffer->head += count;
    return count;
  }

  const u32 original_count = count;

  u32 bytes_left_before_wrap = buffer->len - buffer->head;
  memcpy(dst, &buffer->buffer[buffer->head], bytes_left_before_wrap);

  count -= bytes_left_before_wrap;
  memcpy(dst + bytes_left_before_wrap, buffer->buffer, count);

  buffer->size -= original_count;
  buffer->head = count;

  return count;
}

u32
nex_ring_buffer_peek_copy(
  struct nex_ring_buffer* buffer,
  u8* dst,
  u32 count
)
{
  u32 sz = nex_ring_buffer_size(buffer);
  if (count > sz)
  {
    count = sz;
  }

  if (buffer->head + count < buffer->len)
  {
    // No need to wrap around.
    memcpy(dst, &buffer->buffer[buffer->head], count);
    // buffer->size -= count;
    // buffer->head += count;
    return count;
  }

  const u32 original_count = count;

  u32 bytes_left_before_wrap = buffer->len - buffer->head;
  memcpy(dst, &buffer->buffer[buffer->head], bytes_left_before_wrap);

  count -= bytes_left_before_wrap;
  memcpy(dst + bytes_left_before_wrap, buffer->buffer, count);

  _advance_head(buffer, original_count);
  return original_count;
}

u32
nex_ring_buffer_write_bytes(
  struct nex_ring_buffer* buffer,
  u8* src,
  u32 count
)
{
  u32 size = nex_ring_buffer_len(buffer);
  if (count > size)
  {
    count = size;
  }

  const u32 bytes_left = buffer->len - buffer->tail;
  // printf("[PC] Bytes left: %u (%u, %u)\n", bytes_left, buffer->len, buffer->tail);
  if (bytes_left >= count)
  {
    // No need to wrap around.
    memcpy(&buffer->buffer[buffer->tail], src, count);
    buffer->tail += count;
    buffer->size += count;
    // printf("[PC] All written, returning %u\n", count);
    return count;
  }

  const u32 original_count = count;

  memcpy(&buffer->buffer[buffer->tail], src, bytes_left);
  count -= bytes_left;
  memcpy(&buffer->buffer[0], src + bytes_left, count);

  _advance_tail(buffer, original_count);

  // printf("[PC] Wrap write, returning %u\n", count);
  return count;
}

u32
nex_ring_buffer_find(
  struct nex_ring_buffer* buffer,
  u8 byte,
  u32 starting_at,
  u32* pos
)
{
  u32 sz = nex_ring_buffer_size(buffer);
  for (u32 i = starting_at; i < sz; ++i)
  {
    u32 idx = FAST_MOD(buffer->head + i, buffer->len);
    if (buffer->buffer[idx] == byte)
    {
      *pos = i;
      return NEX_SUCCESS;
    }
  }

  return NEX_FAILURE;
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
