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

i32
nex_bytebuf_read_u8(
  struct nex_bytebuf* stream,
  u8* var
);

u8
nex_bytebuf_read_u8_unsafe(
  struct nex_bytebuf* stream
);

i32
nex_bytebuf_read_u8_arr(
  struct nex_bytebuf* bytebuf,
  u8* buf,
  u32 len
);

void
nex_bytebuf_read_u8_arr_unsafe(
  struct nex_bytebuf* bytebuf,
  u8* buf,
  u32 len
);

i32
nex_bytebuf_read_u16_le(
  struct nex_bytebuf* stream,
  u16* var
);

i32
nex_bytebuf_read_u16_be(
  struct nex_bytebuf* stream,
  u16* var
);

u16
nex_bytebuf_read_u16_le_unsafe(
  struct nex_bytebuf* stream
);

u16
nex_bytebuf_read_u16_be_unsafe(
  struct nex_bytebuf* stream
);

i32
nex_bytebuf_read_u32_le(
  struct nex_bytebuf* stream,
  u32* var
);

i32
nex_bytebuf_read_u32_be(
  struct nex_bytebuf* stream,
  u32* var
);

u32
nex_bytebuf_read_u32_le_unsafe(
  struct nex_bytebuf* stream
);

u32
nex_bytebuf_read_u32_be_unsafe(
  struct nex_bytebuf* stream
);

i32
nex_bytebuf_read_str(
  struct nex_bytebuf* stream,
  u8* buf
);

u32
nex_bytebuf_read_str_unsafe(
  struct nex_bytebuf* stream,
  u8* buf
);

i32
nex_bytebuf_write_u8(
  struct nex_bytebuf* stream,
  u8 var
);

void
nex_bytebuf_write_u8_unsafe(
  struct nex_bytebuf* stream,
  u8 var
);

i32
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

i32
nex_bytebuf_write_u16_le(
  struct nex_bytebuf* stream,
  u16 var
);

i32
nex_bytebuf_write_u16_be(
  struct nex_bytebuf* stream,
  u16 var
);

void
nex_bytebuf_write_u16_le_unsafe(
  struct nex_bytebuf* stream,
  u16 var
);

void
nex_bytebuf_write_u16_be_unsafe(
  struct nex_bytebuf* stream,
  u16 var
);

i32
nex_bytebuf_write_u16_arr(
  struct nex_bytebuf* stream,
  u16* buf,
  u32 len
);

void
nex_bytebuf_write_u16_arr_unsafe(
  struct nex_bytebuf* stream,
  u16* buf,
  u32 len
);

i32
nex_bytebuf_write_u24_le(
  struct nex_bytebuf* stream,
  u32 var
);

i32
nex_bytebuf_write_u24_be(
  struct nex_bytebuf* stream,
  u32 var
);

void
nex_bytebuf_write_u24_le_unsafe(
  struct nex_bytebuf* stream,
  u32 var
);

void
nex_bytebuf_write_u24_be_unsafe(
  struct nex_bytebuf* stream,
  u32 var
);

void
nex_bytebuf_write_u24_be_unsafe(
  struct nex_bytebuf* stream,
  u32 var
);

i32
nex_bytebuf_write_u32_le(
  struct nex_bytebuf* stream,
  u32 var
);

i32
nex_bytebuf_write_u32_be(
  struct nex_bytebuf* stream,
  u32 var
);

void
nex_bytebuf_write_u32_le_unsafe(
  struct nex_bytebuf* stream,
  u32 var
);

void
nex_bytebuf_write_u32_be_unsafe(
  struct nex_bytebuf* stream,
  u32 var
);

i32
nex_bytebuf_write_u32_arr(
  struct nex_bytebuf* stream,
  u32* buf,
  u32 len
);

void
nex_bytebuf_write_u32_arr_unsafe(
  struct nex_bytebuf* stream,
  u32* buf,
  u32 len
);

i32
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
