#include "libcom/bytebuf.h"
#include "libcom/byteorder.h"
#include "libcom/errcodes.h"
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

i32
nex_bytebuf_read_u8(
  struct nex_bytebuf* stream,
  u8* var
)
{
  if (stream->cur + 1 > stream->len)
  {
    return -NERR_EMPTY;
  }

  *var = nex_bytebuf_read_u8_unsafe(stream);
  return NOK;
}

u8
nex_bytebuf_read_u8_unsafe(
  struct nex_bytebuf* stream
)
{
  return stream->buf[stream->cur++];
}

i32
nex_bytebuf_read_u8_arr(
  struct nex_bytebuf* bytebuf,
  u8* buf,
  u32 len
)
{
  i32 code;
  for (u32 i = 0; i < len; ++i)
  {
    code = nex_bytebuf_read_u8(bytebuf, &buf[i]);
    if (code < 0)
    {
      return code;
    }
  }

  return NOK;
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
    buf[i] = nex_bytebuf_read_u8_unsafe(bytebuf);
  }
}

i32
nex_bytebuf_read_u16_le(
  struct nex_bytebuf* stream,
  u16* var
)
{
  i32 code;
  u8 buf[2];

  code = nex_bytebuf_read_u8(stream, &buf[0]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[1]);
  if (code < 0)
  {
    return code;
  }

  *var = nex_deserialize_u16_le(buf);
  return NOK;
}

i32
nex_bytebuf_read_u16_be(
  struct nex_bytebuf* stream,
  u16* var
)
{
  i32 code;
  u8 buf[2];

  code = nex_bytebuf_read_u8(stream, &buf[0]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[1]);
  if (code < 0)
  {
    return code;
  }

  *var = nex_deserialize_u16_be(buf);
  return NOK;
}

u16
nex_bytebuf_read_u16_le_unsafe(
  struct nex_bytebuf* stream
)
{
  u16 value = nex_deserialize_u16_le(&stream->buf[stream->cur]);
  stream->cur += sizeof(u16);
  return value;
}

u16
nex_bytebuf_read_u16_be_unsafe(
  struct nex_bytebuf* stream
)
{
  u16 value = nex_deserialize_u16_be(&stream->buf[stream->cur]);
  stream->cur += sizeof(u16);
  return value;
}

i32
nex_bytebuf_read_u32_le(
  struct nex_bytebuf* stream,
  u32* var
)
{
  i32 code;
  u8 buf[4];

  code = nex_bytebuf_read_u8(stream, &buf[0]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[1]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[2]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[3]);
  if (code < 0)
  {
    return code;
  }
  
  *var = nex_deserialize_u32_le(buf);
  return NOK;
}

i32
nex_bytebuf_read_u32_be(
  struct nex_bytebuf* stream,
  u32* var
)
{
  i32 code;
  u8 buf[4];

  code = nex_bytebuf_read_u8(stream, &buf[0]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[1]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[2]);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(stream, &buf[3]);
  if (code < 0)
  {
    return code;
  }
  
  *var = nex_deserialize_u32_be(buf);
  return NOK;
}

u32
nex_bytebuf_read_u32_le_unsafe(
  struct nex_bytebuf* stream
)
{
  u32 value = nex_deserialize_u32_le(&stream->buf[stream->cur]);
  stream->cur += sizeof(u32);
  return value;
}

u32
nex_bytebuf_read_u32_be_unsafe(
  struct nex_bytebuf* stream
)
{
  u32 value = nex_deserialize_u32_be(&stream->buf[stream->cur]);
  stream->cur += sizeof(u32);
  return value;
}

i32
nex_bytebuf_read_str(
  struct nex_bytebuf* stream,
  u8* buf
)
{
  i32 code;
  u32 count = 0;

  code = nex_bytebuf_read_u32_le(stream, &count);
  if (code < 0)
  {
    return code;
  }

  u32 i;
  for (i = 0; i < count; ++i)
  {
    code = nex_bytebuf_read_u8(stream, &buf[i]);
    if (code < 0)
    {
      return code;
    }
  }

  return (i32) i;
}

u32
nex_bytebuf_read_str_unsafe(
  struct nex_bytebuf* bytebuf,
  u8* buf
)
{
  u32 count = nex_bytebuf_read_u32_le_unsafe(bytebuf);
  for (u32 i = 0; i < count; ++i)
  {
    buf[i] = nex_bytebuf_read_u8_unsafe(bytebuf);
  }

  return count;
}

i32
nex_bytebuf_write_u8(
  struct nex_bytebuf* stream,
  u8 var
)
{
  if (stream->cur + 1 > stream->len)
  {
    return -NERR_FULL;
  }

  nex_bytebuf_write_u8_unsafe(stream, var);
  return NOK;
}

void
nex_bytebuf_write_u8_unsafe(
  struct nex_bytebuf* stream,
  u8 var
)
{
  stream->buf[stream->cur++] = var;
}

i32
nex_bytebuf_write_u8_arr(
  struct nex_bytebuf* stream,
  u8* buf,
  u32 len
)
{
  if (nex_bytebuf_bytes_left(stream) < len)
  {
    return -NERR_EMPTY;
  }

  i32 code;
  for (u32 i = 0; i < len; ++i)
  {
    code = nex_bytebuf_write_u8(stream, buf[i]);
    if (code < 0)
    {
      return code;
    }
  }

  return NOK;
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

i32
nex_bytebuf_write_u16_le(
  struct nex_bytebuf* stream,
  u16 var
)
{
  i32 code;
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);

  code = nex_bytebuf_write_u8(stream, byte0);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte1);
  if (code < 0)
  {
    return code;
  }

  return NOK;
}

i32
nex_bytebuf_write_u16_be(
  struct nex_bytebuf* stream,
  u16 var
)
{
  i32 code;
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);

  code = nex_bytebuf_write_u8(stream, byte1);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte0);
  if (code < 0)
  {
    return code;
  }

  return NOK;
}

void
nex_bytebuf_write_u16_le_unsafe(
  struct nex_bytebuf* stream,
  u16 var
)
{
  u8 buf[2];
  nex_serialize_u16_le(var, buf);

  nex_bytebuf_write_u8_unsafe(stream, buf[0]);
  nex_bytebuf_write_u8_unsafe(stream, buf[1]);
}

void
nex_bytebuf_write_u16_be_unsafe(
  struct nex_bytebuf* stream,
  u16 var
)
{
  u8 buf[2];
  nex_serialize_u16_le(var, buf);

  nex_bytebuf_write_u8_unsafe(stream, buf[1]);
  nex_bytebuf_write_u8_unsafe(stream, buf[0]);
}

i32
nex_bytebuf_write_u16_arr(
  struct nex_bytebuf* stream,
  u16* buf,
  u32 len
)
{
  // 1 element = 2 bytes
  // So we need len * 2 (= len << 1) bytes.
  if (nex_bytebuf_bytes_left(stream) < (len << 1))
  {
    return -NERR_EMPTY;
  }

  i32 code;
  for (u32 i = 0; i < len; ++i)
  {
    code = nex_bytebuf_write_u16_le(stream, buf[i]);
    if (code < 0)
    {
      return code;
    }
  }

  return NOK;
}

void
nex_bytebuf_write_u16_arr_unsafe(
  struct nex_bytebuf* stream,
  u16* buf,
  u32 len
)
{
  for (u32 i = 0; i < len; ++i)
  {
    nex_bytebuf_write_u16_le_unsafe(stream, buf[i]);
  }
}

i32
nex_bytebuf_write_u24_le(
  struct nex_bytebuf* stream,
  u32 var
)
{
  i32 code;
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);
  u8 byte2 = (u8) ((var >> 16) & 0xff);

  code = nex_bytebuf_write_u8(stream, byte0);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte1);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte2);
  if (code < 0)
  {
    return code;
  }

  return NOK;
}

i32
nex_bytebuf_write_u24_be(
  struct nex_bytebuf* stream,
  u32 var
)
{
  i32 code;
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);
  u8 byte2 = (u8) ((var >> 16) & 0xff);

  code = nex_bytebuf_write_u8(stream, byte2);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte1);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte0);
  if (code < 0)
  {
    return code;
  }

  return NOK;
}

void
nex_bytebuf_write_u24_le_unsafe(
  struct nex_bytebuf* stream,
  u32 var
)
{
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);
  u8 byte2 = (u8) ((var >> 16) & 0xff);

  nex_bytebuf_write_u8_unsafe(stream, byte0);
  nex_bytebuf_write_u8_unsafe(stream, byte1);
  nex_bytebuf_write_u8_unsafe(stream, byte2);
}

void
nex_bytebuf_write_u24_be_unsafe(
  struct nex_bytebuf* stream,
  u32 var
)
{
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);
  u8 byte2 = (u8) ((var >> 16) & 0xff);

  nex_bytebuf_write_u8_unsafe(stream, byte2);
  nex_bytebuf_write_u8_unsafe(stream, byte1);
  nex_bytebuf_write_u8_unsafe(stream, byte0);
}

i32
nex_bytebuf_write_u32_le(
  struct nex_bytebuf* stream,
  u32 var
)
{
  i32 code;
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);
  u8 byte2 = (u8) ((var >> 16) & 0xff);
  u8 byte3 = (u8) ((var >> 24) & 0xff);

  code = nex_bytebuf_write_u8(stream, byte0);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte1);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte2);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte3);
  if (code < 0)
  {
    return code;
  }

  return NOK;
}

i32
nex_bytebuf_write_u32_be(
  struct nex_bytebuf* stream,
  u32 var
)
{
  i32 code;
  u8 byte0 = (u8) ((var >> 0) & 0xff);
  u8 byte1 = (u8) ((var >> 8) & 0xff);
  u8 byte2 = (u8) ((var >> 16) & 0xff);
  u8 byte3 = (u8) ((var >> 24) & 0xff);

  code = nex_bytebuf_write_u8(stream, byte3);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte2);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte1);
  if (code < 0)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(stream, byte0);
  if (code < 0)
  {
    return code;
  }

  return NOK;
}

void
nex_bytebuf_write_u32_le_unsafe(
  struct nex_bytebuf* stream,
  u32 var
)
{
  u8 buf[4];
  nex_serialize_u32_le(var, buf);

  nex_bytebuf_write_u8_unsafe(stream, buf[0]);
  nex_bytebuf_write_u8_unsafe(stream, buf[1]);
  nex_bytebuf_write_u8_unsafe(stream, buf[2]);
  nex_bytebuf_write_u8_unsafe(stream, buf[3]);
}

void
nex_bytebuf_write_u32_be_unsafe(
  struct nex_bytebuf* stream,
  u32 var
)
{
  u8 buf[4];
  nex_serialize_u32_le(var, buf);

  nex_bytebuf_write_u8_unsafe(stream, buf[3]);
  nex_bytebuf_write_u8_unsafe(stream, buf[2]);
  nex_bytebuf_write_u8_unsafe(stream, buf[1]);
  nex_bytebuf_write_u8_unsafe(stream, buf[0]);
}

i32
nex_bytebuf_write_u32_arr(
  struct nex_bytebuf* stream,
  u32* buf,
  u32 len
)
{
  // 1 element = 4 bytes
  // So we need len * 4 (= len << 2) bytes.
  if (nex_bytebuf_bytes_left(stream) < (len << 2))
  {
    return -NERR_EMPTY;
  }

  i32 code;
  for (u32 i = 0; i < len; ++i)
  {
    code = nex_bytebuf_write_u32_le(stream, buf[i]);
    if (code < 0)
    {
      return code;
    }
  }

  return NOK;
}

void
nex_bytebuf_write_u32_arr_unsafe(
  struct nex_bytebuf* stream,
  u32* buf,
  u32 len
)
{
  for (u32 i = 0; i < len; ++i)
  {
    nex_bytebuf_write_u32_le_unsafe(stream, buf[i]);
  }
}

i32
nex_bytebuf_write_str(
  struct nex_bytebuf* stream,
  const char* buf,
  u32 len
)
{
  i32 code;
  code = nex_bytebuf_write_u32_le(stream, len);
  if (code < 0)
  {
    return code;
  }

  for (u32 i = 0; i < len; ++i)
  {
    code = nex_bytebuf_write_u8(stream, (u8) buf[i]);
    if (code < 0)
    {
      return code;
    }
  }

  return NOK;
}

void
nex_bytebuf_write_str_unsafe(
  struct nex_bytebuf* stream,
  const char* buf,
  u32 len
)
{
  nex_bytebuf_write_u32_le_unsafe(stream, len);

  for (u32 i = 0; i < len; ++i)
  {
    nex_bytebuf_write_u8_unsafe(stream, (u8) buf[i]);
  }
}
