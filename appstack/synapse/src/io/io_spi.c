#include "libcom/errcodes.h"
#include "libcom/util.h"
#include "soc/stm32/drivers/gpio/gpioif.h"
#include "synapse/io/ioif.h"
#include "synapse/soc/stm32/drivers/dma/dmaif.h"
#include "synapse/soc/stm32/drivers/spi/spi_v1.h"
#include "synapse/soc/stm32/drivers/spi/spiif.h"
#include "synapse/io/io_spi.h"

const u8 test = 0xff;

static u32
_is_sflag_set(
  struct beio_spi* beiospi,
  enum beio_spi_sflag sflag
)
{
  return beiospi->sflags & sflag;
}

static u32
_is_cflag_set(
  struct beio_spi* beiospi,
  enum beio_spi_flag cflag
)
{
  return beiospi->cflags & cflag;
}

static void
_cs_low(
  struct beio_spi* bespi
)
{
  gpioif_pin_set_low(bespi->cs_port, bespi->cs_pin);
}

static void
_cs_high(
  struct beio_spi* bespi
)
{
  gpioif_pin_set_high(bespi->cs_port, bespi->cs_pin);
}

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

  _cs_low(bespi);
  spiif_transmit_bytes(&bespi->spiconf, data, len);

  if (bespi->cflags & BEIO_SPI_CFLAG_TC)
  {
    _cs_high(bespi);
  }

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

  _cs_low(bespi);
  if (bespi->cflags & BEIO_SPI_CFLAG_SKIP_DUMMY_DATA)
  {
    spi_receive_bytes_after(bespi->spiconf.spi, data, len, (u8) bespi->dummy);
  }
  else
  {
    spiif_receive_bytes(&bespi->spiconf, data, len);
  }

  if (bespi->cflags & BEIO_SPI_CFLAG_TC)
  {
    _cs_high(bespi);
  }

  return len;
}

static enum nex_code
_write_async(
  void* ctx,
  u8* data,
  u32 len,
  struct async_fn* fn
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;
  if (_is_sflag_set(bespi, BEIO_SPI_SFLAG_BUSY))
  {
    return NERR_BUSY;
  }

  if (fn)
  {
    bespi->on_complete = *fn;
  }
  
  if (_is_cflag_set(bespi, BEIO_SPI_CFLAG_TC))
  {
    dmaif_interrupt_disable(&bespi->rxconf, DMAIF_INTERRUPT_TC);
    dmaif_interrupt_enable(&bespi->txconf, DMAIF_INTERRUPT_TC);
  }

  _cs_low(bespi);
  spiif_dma_tx_enable(&bespi->spiconf);
  spiif_dma_rx_disable(&bespi->spiconf);
  dmaif_set_mem_addr(&bespi->txconf, DMAIF_MEMORY0, (uptr) data);
  dmaif_set_periph_addr(&bespi->txconf, (uptr) &SPI1->DR);
  dmaif_set_items_count(&bespi->txconf, len);
  dmaif_start_transfer(&bespi->txconf);

  return NOK;
}

static enum nex_code
_read_async(
  void* ctx,
  u8* data,
  u32 len,
  struct async_fn* fn
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;
  if (_is_sflag_set(bespi, BEIO_SPI_SFLAG_BUSY))
  {
    return NERR_BUSY; 
  }

  if (fn)
  {
    bespi->on_complete = *fn;
  }

  if (_is_cflag_set(bespi, BEIO_SPI_CFLAG_TC))
  {
    dmaif_interrupt_enable(&bespi->rxconf, DMAIF_INTERRUPT_TC);
    dmaif_interrupt_disable(&bespi->txconf, DMAIF_INTERRUPT_TC);
  }

  spiif_dma_tx_enable(&bespi->spiconf);
  spiif_dma_rx_enable(&bespi->spiconf);

  dmaif_set_mem_addr(&bespi->txconf, DMAIF_MEMORY0, (uptr) &test);
  dmaif_set_periph_addr(&bespi->txconf, (uptr) &SPI1->DR);
  dmaif_set_items_count(&bespi->txconf, len);

  dmaif_set_mem_addr(&bespi->rxconf, DMAIF_MEMORY0, (uptr) data);
  dmaif_set_periph_addr(&bespi->rxconf, (uptr) &SPI1->DR);
  dmaif_set_items_count(&bespi->rxconf, len);
  dmaif_start_transfer(&bespi->rxconf);
  dmaif_start_transfer(&bespi->txconf);

  return NOK;
}

static void
_transfer_complete(
  void* ctx
)
{
  struct beio_spi* bespi = (struct beio_spi*) ctx;

  if (bespi->cflags & BEIO_SPI_CFLAG_TC)
  {
    _cs_high(bespi);

    if (bespi->on_complete.fn)
    {
      bespi->on_complete.fn(bespi->on_complete.ctx);
      bespi->on_complete.fn = 0;
      bespi->on_complete.ctx = 0;
    }

    bespi->cflags &= ~BEIO_SPI_CFLAG_TC;
  }
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

void
_set_flag(
  void* ctx,
  u32 flag
)
{
  struct beio_spi* beio = (struct beio_spi*) ctx;
  beio->cflags |= flag;
}

void
_clear_flag(
  void* ctx,
  u32 flag
)
{
  struct beio_spi* beio = (struct beio_spi*) ctx;
  beio->cflags &= ~flag;
}

struct ioops ioops_spi = {
  .init = _init,
  .read = _read,
  .read_async = _read_async,
  .write = _write,
  .write_async = _write_async,
  .transfer_complete = _transfer_complete,
  .start_stream = _start_stream,
  .stop_stream = _stop_stream,
  .set_flag = _set_flag,
  .clear_flag = _clear_flag
};
