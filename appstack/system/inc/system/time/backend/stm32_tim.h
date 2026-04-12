#ifndef SYSL_STM32_TIM_BACKEND_H
#define SYSL_STM32_TIM_BACKEND_H

#include "libcom/types.h"
#include "libcom/util.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "time/backend/timeif.h"

BEGIN_DECLARATIONS

struct system_stm32_timer_backend_ctx
{
  volatile struct tim_registers_map* tim;
  u32 value_width_bits;
  u32 ofcount;
};

extern struct sys_coarse_time_vtable stm32_coarse_time_backend;
extern struct sys_monotonic_time_vtable stm32_monotonic_time_backend;

END_DECLARATIONS

#endif
