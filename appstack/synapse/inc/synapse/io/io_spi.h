#ifndef BEIO_SPI_H
#define BEIO_SPI_H

#include "io/ioif.h"
#include "libcom/util.h"
#include "synapse/soc/stm32/drivers/dma/dmaif.h"
#include "synapse/soc/stm32/drivers/spi/spiif.h"

BEGIN_DECLARATIONS

struct beio_spi
{
  struct spiif_config spiconf;

  struct dmaif_config rxconf;
  struct dmaif_config txconf;

  volatile void* cs_port;
  u32 cs_pin;

  u32 cflags;
  u32 sflags;

  u32 dma_active_caps;
  u32 spi_active_caps;

  u16 dummy;

  struct async_fn on_complete;
};

enum beio_spi_flag : u32
{
  BEIO_SPI_CFLAG_DMA = BIT(0),
  BEIO_SPI_CFLAG_AUTO_CONFIG = BIT(1),
  BEIO_SPI_CFLAG_SKIP_DUMMY_DATA = BIT(2),
  BEIO_SPI_CFLAG_TC = BIT(3)
};

enum beio_spi_sflag : u32
{
  BEIO_SPI_SFLAG_STREAM = BIT(0),
  BEIO_SPI_SFLAG_BUSY = BIT(1)
};

extern struct ioops ioops_spi;

END_DECLARATIONS

#endif
