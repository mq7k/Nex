#ifndef NEX_BYTEBUF_H
#define NEX_BYTEBUF_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

struct nex_bytebuf
{
  u8* buf;
  u32 len;
  u32 cur;
};

void
nex_bytebuf_init(
  struct nex_bytebuf* stream,
  u8* buf,
  u32 len
);

void
nex_bytebuf_serialize_u16(
  u16 value,
  u8* buf
);

void
nex_bytebuf_serialize_u32(
  u32 value,
  u8* buf
);

u16
nex_bytebuf_deserialize_u16(
  u8* buf
);

u32
nex_bytebuf_deserialize_u32(
  u8* buf
);

u32
nex_bytebuf_bytes_left(
  struct nex_bytebuf* stream
);

u32
nex_bytebuf_get_cur(
  struct nex_bytebuf* stream
);

void
nex_bytebuf_set_cur(
  struct nex_bytebuf* stream,
  u32 offset
);

u32
nex_bytebuf_read_u8(
  struct nex_bytebuf* stream,
  u8* var
);

void
nex_bytebuf_read_u8_unsafe(
  struct nex_bytebuf* stream,
  u8* var
);

void
nex_bytebuf_read_u8_arr_unsafe(
  struct nex_bytebuf* bytebuf,
  u8* buf,
  u32 len
);

u32
nex_bytebuf_read_u8_arr(
  struct nex_bytebuf* bytebuf,
  u8* buf,
  u32 len
);

u32
nex_bytebuf_read_u16(
  struct nex_bytebuf* stream,
  u16* var
);

void
nex_bytebuf_read_u16_unsafe(
  struct nex_bytebuf* stream,
  u16* var
);

u32
nex_bytebuf_read_u32(
  struct nex_bytebuf* stream,
  u32* var
);

void
nex_bytebuf_read_u32_unsafe(
  struct nex_bytebuf* stream,
  u32* var
);

u32
nex_bytebuf_read_str_fixed(
  struct nex_bytebuf* stream,
  char* buf,
  u32 max_len,
  u32* read_count
);


u32
nex_bytebuf_write_u8_arr(
  struct nex_bytebuf* stream,
  u8* buf,
  u32 len
);

void
nex_bytebuf_write_u8_arr_unsafe(
  struct nex_bytebuf* stream,
  u8* buf,
  u32 len
);

u32
nex_bytebuf_write_u8(
  struct nex_bytebuf* stream,
  u8 var
);

void
nex_bytebuf_write_u8_unsafe(
  struct nex_bytebuf* stream,
  u8 var
);

u32
nex_bytebuf_write_u16(
  struct nex_bytebuf* stream,
  u16 var
);

void
nex_bytebuf_write_u16_unsafe(
  struct nex_bytebuf* stream,
  u16 var
);

u32
nex_bytebuf_write_u32(
  struct nex_bytebuf* stream,
  u32 var
);

void
nex_bytebuf_write_u32_unsafe(
  struct nex_bytebuf* stream,
  u32 var
);

u32
nex_bytebuf_write_str(
  struct nex_bytebuf* stream,
  const char* buf,
  u32 len
);

void
nex_bytebuf_write_str_unsafe(
  struct nex_bytebuf* stream,
  const char* buf,
  u32 len
);

END_DECLARATIONS

#endif
