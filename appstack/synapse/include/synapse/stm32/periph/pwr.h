#ifndef STM32_PWR_H
#define STM32_PWR_H

#include "synapse/specs.h"

#if defined(STM32_PWR_V1)
#include "synapse/stm32/drivers/pwr/pwr_v1.h"
#elif defined(STM32_PWR_V2)
#include "synapse/stm32/drivers/pwr/pwr_v2.h"
#else
#error "No PWR version specified."
#endif

#endif
