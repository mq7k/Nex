#ifndef STM32_SYSCFG_H
#define STM32_SYSCFG_H

#include "synapse/specs.h"

#if defined(STM32_SYSCFG_V1)
#include "synapse/stm32/drivers/syscfg/syscfg_v1.h"
#elif defined(STM32_SYSCFG_V2)
#include "synapse/stm32/drivers/syscfg/syscfg_v2.h"
#else
#error "No SYSCFG version specified."
#endif

#endif
