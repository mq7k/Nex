#ifndef SYSTEM_SCHEDULER_STM32_TIM_BACKEND_H
#define SYSTEM_SCHEDULER_STM32_TIM_BACKEND_H

#include "libcom/util.h"
#include "synapse/stm32/periph/tim.h"

BEGIN_DECLARATIONS

struct scheduler_stm32_tim_backend
{
  volatile struct tim_registers_map* tim;
};

END_DECLARATIONS

#endif
