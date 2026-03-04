#ifndef BEIO_SPI_H
#define BEIO_SPI_H

#include "libcom/util.h"
#include "synapse/stm32/drivers/dma/dmaif.h"
#include "synapse/stm32/drivers/spi/spiif.h"

BEGIN_DECLARATIONS

struct beio_spi
{
  struct spiif_config spiconf;

  struct dmaif_config rxconf;
  struct dmaif_config txconf;

  u32 cflags;
  u32 sflags;

  u32 dma_active_caps;
  u32 spi_active_caps;

  u16 dummy;
};

enum beio_spi_flag
{
  BEIO_SPI_CFLAG_DMA,
  BEIO_SPI_CFLAG_AUTO_CONFIG,
  BEIO_SPI_CFLAG_SKIP_DUMMY_DATA,
};

enum beio_spi_sflag : u32
{
  BEIO_SPI_SFLAG_STREAM
};

extern struct ioops ioops_spi;

END_DECLARATIONS

#endif
