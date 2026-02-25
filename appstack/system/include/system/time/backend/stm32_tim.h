#ifndef SYSL_STM32_TIM_BACKEND_H
#define SYSL_STM32_TIM_BACKEND_H

#include "libcom/types.h"
#include "libcom/util.h"
#include "synapse/stm32/periph/tim.h"

BEGIN_DECLARATIONS

struct system_stm32_timer_backend_ctx
{
  volatile struct tim_registers_map* tim;
  u32 value_width_bits;
};

END_DECLARATIONS

#endif
