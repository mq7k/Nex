#ifndef SYN_SPIIF_H
#define SYN_SPIIF_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct spiif_config
{
  volatile void* spi;
  u32 clk_phase;
  u32 clk_polarity;

  // Configured by the user.
  u32 role;

  u32 baudrate;
  u32 frame_fmt;
  u32 frame_len;
  u32 frame_type;

  // Single-bit configuration field.
  u32 options;
};

enum spiif_cap
{
  SPIIF_CAP_CLK_PHASE_OFF = BIT(0),
  SPIIF_CAP_IDLE_CLK_POLARITY = BIT(1),
  SPIIF_CAP_MASTER = BIT(2),
  SPIIF_CAP_SLAVE = BIT(3),
  SPIIF_CAP_MSB = BIT(4),
  SPIIF_CAP_LSB = BIT(5),
  SPIIF_CAP_8BIT_FRAME = BIT(6),
  SPIIF_CAP_16BIT_FRAME = BIT(7),
  SPIIF_CAP_HWCRC = BIT(8),
  SPIIF_CAP_BIMODE = BIT(9),
  SPIIF_CAP_RXDMA = BIT(10),
  SPIIF_CAP_TXDMA = BIT(11),
  SPIIF_CAP_FRAME_TI = BIT(12),

  // Slave select auto.
  SPIIF_CAP_SSA = BIT(13)
};

enum spiif_code
{
  SPIIF_CODE_OK,
  SPIIF_CODE_INVALID_CFG,
  SPIIF_CODE_INVALID_CLK_PHASE,
  SPIIF_CODE_INVALID_CLK_POLARITY,
  SPIIF_CODE_INVALID_ROLE,
  SPIIF_CODE_INVALID_BAUDRATE,
  SPIIF_CODE_INVALID_FRAME_FMT,
  SPIIF_CODE_INVALID_FRAME_LEN,
  SPIIF_CODE_INVALID_FRAME_TYPE
};

enum spiif_clk_phase
{
  SPIIF_CLK_PHASE_FIRST,
  SPIIF_CLK_PHASE_SECOND
};

enum spiif_clk_polarity
{
  SPIIF_CLK_POLARITY_CLK_IDLE0,
  SPIIF_CLK_POLARITY_CLK_IDLE1
};

enum spiif_role
{
  SPIIF_ROLE_MASTER,
  SPIIF_ROLE_SLAVE
};

enum spiif_frame_fmt
{
  SPIIF_FRAME_FMT_MSB_FIRST,
  SPIIF_FRAME_FMT_LSB_FIRST
};

enum spiif_frame_len
{
  SPIIF_FRAME_LEN_8BIT,
  SPIIF_FRAME_LEN_16BIT
};

enum spiif_baudrate
{
  SPIIF_BAUDRATE_CLK_DIV2,
  SPIIF_BAUDRATE_CLK_DIV4,
  SPIIF_BAUDRATE_CLK_DIV8,
  SPIIF_BAUDRATE_CLK_DIV16,
  SPIIF_BAUDRATE_CLK_DIV64,
  SPIIF_BAUDRATE_CLK_DIV128,
  SPIIF_BAUDRATE_CLK_DIV256
};

enum spiif_frame_type
{
  SPIIF_FRAME_TYPE_MOTOROLA,
  SPIIF_FRAME_TYPE_TI
};

u32
spiif_get_capabilities(void);

u32
spiif_is_capability_supported(
  enum spiif_cap cap
);

enum spiif_code
spiif_auto_config(
  struct spiif_config* config,
  u32 enabled_caps
);

enum spiif_code
spiif_configure(
  struct spiif_config* config
);

END_DECLARATIONS

#endif
