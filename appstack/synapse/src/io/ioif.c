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

enum io_status
beio_write_async(
  struct beio* beio,
  u8* buf,
  u32 len
)
{
  return beio->ops->write_async(beio->ctx, buf, len);
}

enum io_status
beio_read_async(
  struct beio* beio,
  u8* buf,
  u32 len
)
{
  return beio->ops->read_async(beio->ctx, buf, len);
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
