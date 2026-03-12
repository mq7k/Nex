#include "libcom/util.h"
#include "synapse/io/ioif.h"
#include "synapse/soc/stm32/drivers/dma/dmaif.h"
#include "synapse/soc/stm32/drivers/spi/spi_v1.h"
#include "synapse/soc/stm32/drivers/spi/spiif.h"
#include "synapse/io/io_spi.h"

static u32
_init_dma(
  struct beio_spi* bespi
)
{
  const u32 auto_config = bespi->cflags & BEIO_SPI_CFLAG_AUTO_CONFIG;
  if (auto_config)
  {
    const u32 dma_16bit_cap = bespi->dma_active_caps & DMAIF_CAP_PERIPH_16bit_WIDE;
    const u32 spi_16bit_cap = bespi->spi_active_caps & SPIIF_CAP_16BIT_FRAME;

    if ((!!dma_16bit_cap) != (!!spi_16bit_cap))
    {
      bespi->dma_active_caps &= ~DMAIF_CAP_PERIPH_16bit_WIDE;
      bespi->spi_active_caps &= ~SPIIF_CAP_16BIT_FRAME;
    }

    enum dmaif_code dma_code;
    dma_code = dmaif_auto_config(&bespi->rxconf, bespi->dma_active_caps);
    if (dma_code != DMAIF_CODE_OK)
    {
      return NEX_FAILURE;
    }

    dma_code = dmaif_auto_config(&bespi->txconf, bespi->dma_active_caps);
    if (dma_code != DMAIF_CODE_OK)
    {
      return NEX_FAILURE;
    }
  }
  else
  {
    enum dmaif_code dma_code;
    dma_code = dmaif_configure(&bespi->rxconf);
    if (dma_code != DMAIF_CODE_OK)
    {
      return NEX_FAILURE;
    }

    dma_code = dmaif_configure(&bespi->txconf);
    if (dma_code != DMAIF_CODE_OK)
    {
      return NEX_FAILURE;
    }
  }

  return NEX_SUCCESS;
}

static u32
_init(
  void* ctx
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;

  if (bespi->cflags & BEIO_SPI_CFLAG_DMA)
  {
    if (_init_dma(bespi) != NEX_SUCCESS)
    {
      return NEX_FAILURE;
    }
  }

  if (bespi->cflags & BEIO_SPI_CFLAG_AUTO_CONFIG)
  {
    enum spiif_code code;
    code = spiif_auto_config(&bespi->spiconf, bespi->spi_active_caps);
    if (code != SPIIF_CODE_OK)
    {
      return NEX_FAILURE;
    }
  }
  else
  {
    enum spiif_code spi_code;
    spi_code = spiif_configure(&bespi->spiconf);
    if (spi_code != SPIIF_CODE_OK)
    {
      return NEX_FAILURE;
    }
  }

  return NEX_SUCCESS;
}

static u32
_write(
  void* ctx,
  u8* data,
  u32 len
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;
  spiif_transmit_bytes(&bespi->spiconf, data, len);
  return len;
}

static u32
_read(
  void* ctx,
  u8* data,
  u32 len
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;

  if (bespi->cflags & BEIO_SPI_CFLAG_SKIP_DUMMY_DATA)
  {
    spi_receive_bytes_after(bespi->spiconf.spi, data, len, (u8) bespi->dummy);
  }
  else
  {
    spiif_receive_bytes(&bespi->spiconf, data, len);
  }

  return len;
}

static enum io_status
_write_async(
  void* ctx,
  u8* data,
  u32 len
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;

  (void) bespi;
  (void) data;
  (void) len;
  
  // dmaif_set_src_addr();
  // dmaif_set_dst_addr();
  // dmaif_set_items_count();
  // dmaif_start_transfer();
  return IO_STATUS_OK;
}

static enum io_status
_read_async(
  void* ctx,
  u8* data,
  u32 len
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;
  (void) bespi;
  (void) data;
  (void) len;

  // dmaif_set_src_addr();
  // dmaif_set_dst_addr();
  // dmaif_set_items_count();
  // dmaif_start_transfer();
  return IO_STATUS_OK;
}

static void
_start_stream(
  void* ctx
)
{
  struct beio_spi* spi = (struct beio_spi*) ctx;
  spi->sflags |= BEIO_SPI_SFLAG_STREAM;
}

static void
_stop_stream(
  void* ctx
)
{
  struct beio_spi* spi = (struct beio_spi*) ctx;
  spi->sflags &= ~BEIO_SPI_SFLAG_STREAM;
}

struct ioops ioops_spi = {
  .init = _init,
  .read = _read,
  .read_async = _read_async,
  .write = _write,
  .write_async = _write_async,
  .start_stream = _start_stream,
  .stop_stream = _stop_stream
};
