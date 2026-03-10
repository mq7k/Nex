#include "synapse/stm32/drivers/spi/spiif.h"

enum spiif_code
spiif_auto_config(
  struct spiif_config* config,
  u32 enabled_caps
)
{
  if (!config)
  {
    return SPIIF_CODE_INVALID_CFG;
  }

  const u32 supported_caps = spiif_get_capabilities();
  const u32 active_caps = supported_caps & enabled_caps;

  config->clk_phase = SPIIF_CLK_PHASE_FIRST;
  config->clk_polarity = SPIIF_CLK_POLARITY_CLK_IDLE0;
  config->baudrate = SPIIF_BAUDRATE_CLK_DIV2;

  if (active_caps & SPIIF_CAP_16BIT_FRAME)
  {
    config->frame_len = SPIIF_FRAME_LEN_16BIT;
  }
  else
  {
    config->frame_len = SPIIF_FRAME_LEN_8BIT;
  }

  if (active_caps & SPIIF_CAP_MSB)
  {
    config->frame_fmt = SPIIF_FRAME_FMT_MSB_FIRST;
  }
  else
  {
    config->frame_fmt = SPIIF_FRAME_FMT_LSB_FIRST;
  }

  if (active_caps & SPIIF_CAP_HWCRC)
  {
    config->options |= SPIIF_CAP_HWCRC;
  }
  
  if (active_caps & SPIIF_CAP_RXDMA)
  {
    config->options |= SPIIF_CAP_RXDMA;
  }

  if (active_caps & SPIIF_CAP_TXDMA)
  {
    config->options |= SPIIF_CAP_TXDMA;
  }

  if (active_caps & SPIIF_CAP_FRAME_TI)
  {
    config->frame_type = SPIIF_FRAME_TYPE_TI;
  }
  else
  {
    config->frame_type = SPIIF_FRAME_TYPE_MOTOROLA;
  }

  if (active_caps & SPIIF_CAP_SSA)
  {
    config->options |= SPIIF_CAP_SSA;
  }

  // TODO: Handle bimode.
  return spiif_configure(config);
}
