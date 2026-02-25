#ifndef STM32_TIM_H
#define STM32_TIM_H

#include "synapse/specs.h"

#if defined(STM32_TIM_V1)
#include "synapse/stm32/drivers/tim/tim_v1.h"
#elif defined(STM32_TIM_V2)
#include "synapse/stm32/drivers/tim/tim_v2.h"
#else
#error "No TIM version specified."
#endif

#endif
