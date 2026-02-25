#ifndef STM32_SAI_H
#define STM32_SAI_H

#include "synapse/specs.h"

#if defined(STM32_SAI_V1)
#include "synapse/stm32/drivers/sai/sai_v1.h"
#else
#error "No SAI version specified."
#endif

#endif
