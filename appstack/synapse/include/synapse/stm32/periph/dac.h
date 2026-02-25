#ifndef STM32_DAC_H
#define STM32_DAC_H

#include "synapse/specs.h"

#if defined(STM32_DAC_V1)
#include "synapse/stm32/drivers/dac/dac_v1.h"
#elif defined(STM32_DAC_V2)
#include "synapse/stm32/drivers/dac/dac_v2.h"
#else
#error "No DAC version specified."
#endif

#endif
