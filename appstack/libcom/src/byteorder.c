#include "libcom/byteorder.h"

void
nex_serialize_u16_be(
  u16 value,
  u8* buf
)
{
  buf[0] = (u8) (value >> 8);
  buf[1] = (u8) (value >> 0);
}

void
nex_serialize_u32_be(
  u32 value,
  u8* buf
)
{
  buf[0] = (u8) (value >> 24);
  buf[1] = (u8) (value >> 16);
  buf[2] = (u8) (value >> 8);
  buf[3] = (u8) (value >> 0);
}

u16
nex_deserialize_u16_be(
  u8* buf
)
{
  u8 byte0 = buf[0];
  u8 byte1 = buf[1];

  u16 var = 0;
  var |= (u16) (byte0 << 8);
  var |= (u16) (byte1 << 0);
  return var;
}

u32
nex_deserialize_u32_be(
  u8* buf
)
{
  u8 byte0 = buf[0];
  u8 byte1 = buf[1];
  u8 byte2 = buf[2];
  u8 byte3 = buf[3];

  u32 var = 0;
  var |= (u32) (byte0 << 24);
  var |= (u32) (byte1 << 16);
  var |= (u32) (byte2 << 8);
  var |= (u32) (byte3 << 0);
  return var;
}

void
nex_serialize_u16_le(
  u16 value,
  u8* buf
)
{
  buf[0] = (u8) (value >> 0);
  buf[1] = (u8) (value >> 8);
}

void
nex_serialize_u32_le(
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
nex_deserialize_u16_le(
  u8* buf
)
{
  u8 byte0 = buf[0];
  u8 byte1 = buf[1];

  u16 var = 0;
  var |= (u16) (byte0 << 0);
  var |= (u16) (byte1 << 8);
  return var;
}

u32
nex_deserialize_u32_le(
  u8* buf
)
{
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
