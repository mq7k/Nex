#include "libcom/bytebuf.h"
#include "libcom/util.h"

void
nex_bytebuf_init(
  struct nex_bytebuf* stream,
  u8* buf,
  u32 len
)
{
  stream->buf = buf;
  stream->len = len;
  stream->cur = 0;
}

void
nex_bytebuf_serialize_u16(
  u16 value,
  u8* buf
)
{
  buf[0] = (u8) (value >> 0);
  buf[1] = (u8) (value >> 8);
}

void
nex_bytebuf_serialize_u32(
  u32 value,
  u8* buf
)
{
  buf[0] = (u8) (value >> 0);
  buf[1] = (u8) (value >> 8);
  buf[2] = (u8) (value >> 16);
  buf[3] = (u8) (value >> 24);
}

u16
nex_bytebuf_deserialize_u16(
  u8* buf
)
{
  u8 byte0 = buf[0];
  u8 byte1 = buf[1];

  u16 var = 0;
  var |= (byte0 << 0);
  var |= (byte1 << 8);
  return var;
}

u32
nex_bytebuf_deserialize_u32(
  u8* buf
)
{
  // Little endian
  u8 byte0 = buf[0];
  u8 byte1 = buf[1];
  u8 byte2 = buf[2];
  u8 byte3 = buf[3];

  u32 var = 0;
  var |= (u32) (byte0 << 0);
  var |= (u32) (byte1 << 8);
  var |= (u32) (byte2 << 16);
  var |= (u32) (byte3 << 24);
  return var;
}

u32
nex_bytebuf_bytes_left(
  struct nex_bytebuf* stream
)
{
  return stream->len - stream->cur;
}

u32
nex_bytebuf_get_cur(
  struct nex_bytebuf* stream
)
{
  return stream->cur;
}

void
nex_bytebuf_set_cur(
  struct nex_bytebuf* stream,
  u32 offset
)
{
  stream->cur = offset;
}

u32
nex_bytebuf_read_u8(
  struct nex_bytebuf* stream,
  u8* var
)
{
  if (stream->cur + 1 > stream->len)
  {
    return NEX_FAILURE;
  }

  *var = stream->buf[stream->cur++];
  return NEX_SUCCESS;
}

void
nex_bytebuf_read_u8_unsafe(
  struct nex_bytebuf* stream,
  u8* var
)
{
  *var = stream->buf[stream->cur++];
}

u32
nex_bytebuf_read_u8_arr(
  struct nex_bytebuf* bytebuf,
  u8* buf,
  u32 len
)
{
  for (u32 i = 0; i < len; ++i)
  {
    if (nex_bytebuf_read_u8(bytebuf, &buf[i]) != NEX_SUCCESS)
    {
      return NEX_FAILURE;
    }
  }

  return NEX_SUCCESS;
}

void
nex_bytebuf_read_u8_arr_unsafe(
  struct nex_bytebuf* bytebuf,
  u8* buf,
  u32 len
)
{
  for (u32 i = 0; i < len; ++i)
  {
    nex_bytebuf_read_u8_unsafe(bytebuf, &buf[i]);
  }
}

u32
nex_bytebuf_read_u16(
  struct nex_bytebuf* stream,
  u16* var
)
{
  u8 buf[2];

  if (nex_bytebuf_read_u8(stream, &buf[0]) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_read_u8(stream, &buf[1]) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  *var = nex_bytebuf_deserialize_u16(buf);
  return NEX_SUCCESS;
}

void
nex_bytebuf_read_u16_unsafe(
  struct nex_bytebuf* stream,
  u16* var
)
{
  *var = nex_bytebuf_deserialize_u16(&stream->buf[stream->cur]);
  stream->cur += sizeof(u16);
}

u32
nex_bytebuf_read_u32(
  struct nex_bytebuf* stream,
  u32* var
)
{
  u8 buf[4];

  if (nex_bytebuf_read_u8(stream, &buf[0]) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_read_u8(stream, &buf[1]) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_read_u8(stream, &buf[2]) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_read_u8(stream, &buf[3]) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }
  
  *var = nex_bytebuf_deserialize_u32(buf);
  return NEX_SUCCESS;
}

void
nex_bytebuf_read_u32_unsafe(
  struct nex_bytebuf* stream,
  u32* var
)
{
  *var = nex_bytebuf_deserialize_u32(&stream->buf[stream->cur]);
  stream->cur += sizeof(u32);
}

u32
bytebuf_read_str(
  struct nex_bytebuf* stream,
  u8* buf,
  u32* read_count
)
{
  // TODO: Make sure count is initialized before using it in the loop.
  u32 count = 0;
  nex_bytebuf_read_u32(stream, &count);

  u32 i;
  for (i = 0; i < count; ++i)
  {
    buf[i] = stream->buf[stream->cur++];
  }

  *read_count = i;
  return NEX_SUCCESS;
}


u32
nex_bytebuf_write_u8_arr(
  struct nex_bytebuf* stream,
  u8* buf,
  u32 len
)
{
  if (nex_bytebuf_bytes_left(stream) < len)
  {
    return NEX_FAILURE;
  }

  for (u32 i = 0; i < len; ++i)
  {
    nex_bytebuf_write_u8(stream, buf[i]);
  }

  return NEX_SUCCESS;
}

void
nex_bytebuf_write_u8_arr_unsafe(
  struct nex_bytebuf* stream,
  u8* buf,
  u32 len
)
{
  for (u32 i = 0; i < len; ++i)
  {
    nex_bytebuf_write_u8_unsafe(stream, buf[i]);
  }
}

u32
nex_bytebuf_write_u8(
  struct nex_bytebuf* stream,
  u8 var
)
{
  if (stream->cur + 1 > stream->len)
  {
    return NEX_FAILURE;
  }

  stream->buf[stream->cur++] = var;
  return NEX_SUCCESS;
}

void
nex_bytebuf_write_u8_unsafe(
  struct nex_bytebuf* stream,
  u8 var
)
{
  stream->buf[stream->cur++] = var;
}

u32
nex_bytebuf_write_u16(
  struct nex_bytebuf* stream,
  u16 var
)
{
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);

  if (nex_bytebuf_write_u8(stream, byte0) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_write_u8(stream, byte1) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

void
nex_bytebuf_write_u16_unsafe(
  struct nex_bytebuf* stream,
  u16 var
)
{
  u8 buf[2];
  nex_bytebuf_serialize_u16(var, buf);

  nex_bytebuf_write_u8_unsafe(stream, buf[0]);
  nex_bytebuf_write_u8_unsafe(stream, buf[1]);
}

u32
nex_bytebuf_write_u32(
  struct nex_bytebuf* stream,
  u32 var
)
{
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);
  u8 byte2 = (u8) ((var >> 16) & 0xff);
  u8 byte3 = (u8) ((var >> 24) & 0xff);

  if (nex_bytebuf_write_u8(stream, byte0) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_write_u8(stream, byte1) != NEX_FAILURE)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_write_u8(stream, byte2) != NEX_FAILURE)
  {
    return NEX_FAILURE;
  }

  if (nex_bytebuf_write_u8(stream, byte3) != NEX_FAILURE)
  {
    return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

void
nex_bytebuf_write_u32_unsafe(
  struct nex_bytebuf* stream,
  u32 var
)
{
  u8 buf[4];
  nex_bytebuf_serialize_u32(var, buf);

  nex_bytebuf_write_u8_unsafe(stream, buf[0]);
  nex_bytebuf_write_u8_unsafe(stream, buf[1]);
  nex_bytebuf_write_u8_unsafe(stream, buf[2]);
  nex_bytebuf_write_u8_unsafe(stream, buf[3]);
}

u32
nex_bytebuf_write_str(
  struct nex_bytebuf* stream,
  const char* buf,
  u32 len
)
{
  if (nex_bytebuf_write_u32(stream, len) != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  for (u32 i = 0; i < len; ++i)
  {
    if (nex_bytebuf_write_u8(stream, (u8) buf[i]) != NEX_SUCCESS)
    {
      return NEX_FAILURE;
    }
  }

  return NEX_SUCCESS;
}

void
nex_bytebuf_write_str_unsafe(
  struct nex_bytebuf* stream,
  const char* buf,
  u32 len
)
{
  nex_bytebuf_write_u32_unsafe(stream, len);

  for (u32 i = 0; i < len; ++i)
  {
    nex_bytebuf_write_u8_unsafe(stream, (u8) buf[i]);
  }
}
