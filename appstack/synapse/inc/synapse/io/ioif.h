#ifndef SYN_IOIF_H
#define SYN_IOIF_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

enum io_status
{
  IO_STATUS_OK,
  IO_STATUS_BUSY,
  IO_STATUS_ERR
};

struct ioops
{
  u32 (*init)(void* ctx);
  u32 (*write)(void* ctx, u8* data, u32 len);
  u32 (*read)(void* ctx, u8* data, u32 len);
  enum io_status (*write_async)(void* ctx, u8* data, u32 len);
  enum io_status (*read_async)(void* ctx, u8* data, u32 len);
  void (*start_stream)(void* ctx);
  void (*stop_stream)(void* ctx);
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

enum io_status
beio_write_async(
  struct beio* beio,
  u8* buf,
  u32 len
);

enum io_status
beio_read_async(
  struct beio* beio,
  u8* buf,
  u32 len
);

void
beio_start_stream(
  struct beio* beio
);

void
beio_stop_stream(
  struct beio* beio
);

END_DECLARATIONS

#endif
