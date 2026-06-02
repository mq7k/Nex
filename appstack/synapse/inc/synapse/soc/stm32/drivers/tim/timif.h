#ifndef SYN_TIMIF_H
#define SYN_TIMIF_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct timif_config
{
  volatile void* tim;
  u32 channel;
  u32 clkdiv;
  u32 oc_mode;
  u32 align;
  u32 direction;
  u32 dma_req;
  u32 dma_req_src;
  u32 options;
};

enum timif_capability
{
  TIMIF_CAP_OC_PRELOAD = BIT(0),
  TIMIF_CAP_MAIN_OUT = BIT(1),
};

enum timif_channel
{
  TIMIF_CH1,
  TIMIF_CH2,
  TIMIF_CH3,
  TIMIF_CH4
};

enum timif_clkdiv
{
  TIMIF_CLKDIV_NODIV,
  TIMIF_CLKDIV_DIV2,
  TIMIF_CLKDIV_DIV4
};

enum timif_oc_mode
{
  TIMIF_OC_MODE_FROZEN,
  TIMIF_OC_MODE_FORCED_HIGH,
  TIMIF_OC_MODE_FORCED_LOW,
  TIMIF_OC_MODE_TOGGLE,
  TIMIF_OC_MODE_FORCE_INACTIVE,
  TIMIF_OC_MODE_FORCE_ACTIVE,
  TIMIF_OC_MODE_PWM1,
  TIMIF_OC_MODE_PWM2
};

enum timif_align
{
  TIMIF_ALIGN_EDGE,
  TIMIF_ALIGN_MODE1,
  TIMIF_ALIGN_MODE2,
  TIMIF_ALIGN_MODE3
};

enum timif_direction
{
  TIMIF_DIRECTION_UP,
  TIMIF_DIRECTION_DOWN
};

enum timif_dma_req
{
  TIMIF_DMA_REQ_UP,
  TIMIF_DMA_REQ_CC1,
  TIMIF_DMA_REQ_CC2,
  TIMIF_DMA_REQ_CC3,
  TIMIF_DMA_REQ_CC4,
  TIMIF_DMA_REQ_COM,
  TIMIF_DMA_REQ_TRIGGER
};

enum timif_dma_req_src
{
  TIMIF_DMA_REQ_SRC_CC,
  TIMIF_DMA_REQ_SRC_UP
};

enum timif_code
{
  TIMIF_CODE_OK,
  TIMIF_CODE_INVALID_CLKDIV,
  TIMIF_CODE_INVALID_OC_MODE,
  TIMIF_CODE_INVALID_ALIGN,
  TIMIF_CODE_INVALID_DIRECTION,
  TIMIF_CODE_INVALID_DMA_REQ,
  TIMIF_CODE_INVALID_DMA_REQ_SRC
};

u32
timif_get_capabitilies(void);

u32
timif_is_capability_supported(
  enum timif_capability cap
);

enum timif_code
timif_auto_config(
  struct timif_config* config,
  u32 enabled_caps
);

enum timif_code
timif_configure(
  struct timif_config* config
);

void
timif_counter_enable(
  struct timif_config* config
);

void
timif_set_cc_value(
  struct timif_config* config,
  u32 value
);

END_DECLARATIONS

#endif
