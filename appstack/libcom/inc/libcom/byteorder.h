#ifndef NEX_BYTEORDER_H
#define NEX_BYTEORDER_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

void
nex_serialize_u16_le(
  u16 value,
  u8* buf
);

void
nex_serialize_u32_le(
  u32 value,
  u8* buf
);

u16
nex_deserialize_u16_le(
  u8* buf
);

u32
nex_deserialize_u32_le(
  u8* buf
);

void
nex_serialize_u16_be(
  u16 value,
  u8* buf
);

void
nex_serialize_u32_be(
  u32 value,
  u8* buf
);

u16
nex_deserialize_u16_be(
  u8* buf
);

u32
nex_deserialize_u32_be(
  u8* buf
);

END_DECLARATIONS

#endif
