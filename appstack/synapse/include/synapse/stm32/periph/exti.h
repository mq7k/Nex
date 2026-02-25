#ifndef STM32_EXTI_H
#define STM32_EXTI_H

#include "synapse/specs.h"

#if defined(STM32_EXTI_V1)
#include "synapse/stm32/drivers/exti/exti_v1.h"
#else
#error "No EXTI version specified."
#endif

#endif
