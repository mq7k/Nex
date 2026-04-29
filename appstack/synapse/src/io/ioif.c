#include "synapse/io/ioif.h"

u32
beio_init(
  struct beio* beio
)
{
  return beio->ops->init(beio->ctx);
}

u32
beio_write(
  struct beio* beio,
  u8* buf,
  u32 len
)
{
  return beio->ops->write(beio->ctx, buf, len);
}

u32
beio_read(
  struct beio* beio,
  u8* buf,
  u32 len
)
{
  return beio->ops->read(beio->ctx, buf, len);
}

enum nex_code
beio_write_async(
  struct beio* beio,
  u8* buf,
  u32 len,
  struct async_fn* fn
)
{
  return beio->ops->write_async(beio->ctx, buf, len, fn);
}

enum nex_code
beio_read_async(
  struct beio* beio,
  u8* buf,
  u32 len,
  struct async_fn* fn
)
{
  return beio->ops->read_async(beio->ctx, buf, len, fn);
}

void
beio_transfer_complete(
  struct beio* beio
)
{
  beio->ops->transfer_complete(beio->ctx);
}

void
beio_start_stream(
  struct beio* beio
)
{
  beio->ops->start_stream(beio->ctx);
}

void
beio_stop_stream(
  struct beio* beio
)
{
  beio->ops->stop_stream(beio->ctx);
}

void
beio_set_flag(
  struct beio* beio,
  u32 flag
)
{
  beio->ops->set_flag(beio->ctx, flag);
}

void
beio_clear_flag(
  struct beio* beio,
  u32 flag
)
{
  beio->ops->clear_flag(beio->ctx, flag);
}
