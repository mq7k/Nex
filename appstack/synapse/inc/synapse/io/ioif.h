#ifndef SYN_IOIF_H
#define SYN_IOIF_H

#include "libcom/errcodes.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

typedef void (*async_cb)(void*);

struct async_fn
{
  void* ctx;
  async_cb fn;
};

struct ioops
{
  u32 (*init)(void* ctx);
  u32 (*write)(void* ctx, u8* data, u32 len);
  u32 (*read)(void* ctx, u8* data, u32 len);
  enum nex_code (*write_async)(void* ctx, u8* data, u32 len, struct async_fn* fn);
  enum nex_code (*read_async)(void* ctx, u8* data, u32 len, struct async_fn* fn);
  void (*transfer_complete)(void* ctx);
  void (*start_stream)(void* ctx);
  void (*stop_stream)(void* ctx);
  void (*set_flag)(void* ctx, u32 flag);
  void (*clear_flag)(void* ctx, u32 flag);
};

struct beio
{
  void* ctx;
  struct ioops* ops;
};

u32
beio_init(
  struct beio* beio
);

u32
beio_write(
  struct beio* beio,
  u8* buf,
  u32 len
);

u32
beio_read(
  struct beio* beio,
  u8* buf,
  u32 len
);

enum nex_code
beio_write_async(
  struct beio* beio,
  u8* buf,
  u32 len,
  struct async_fn* fn
);

enum nex_code
beio_read_async(
  struct beio* beio,
  u8* buf,
  u32 len,
  struct async_fn* fn
);

void
beio_transfer_complete(
  struct beio* beio
);

void
beio_start_stream(
  struct beio* beio
);

void
beio_stop_stream(
  struct beio* beio
);

void
beio_set_flag(
  struct beio* beio,
  u32 flag
);

void
beio_clear_flag(
  struct beio* beio,
  u32 flag
);

END_DECLARATIONS

#endif
