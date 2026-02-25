#ifndef STM32_RCC_H
#define STM32_RCC_H

#include "synapse/specs.h"

#if defined(STM32_RCC_V1)
#include "synapse/stm32/drivers/rcc/rcc_v1.h"
#elif defined(STM32_RCC_V2)
#include "synapse/stm32/drivers/rcc/rcc_v2.h"
#else
#error "No RCC version specified."
#endif

#endif
