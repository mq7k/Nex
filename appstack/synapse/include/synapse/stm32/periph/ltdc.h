#ifndef STM32_LTDC_H
#define STM32_LTDC_H

#include "synapse/specs.h"

#if defined(STM32_LTDC_V1)
#include "synapse/stm32/drivers/ltdc/ltdc_v1.h"
#else
#error "No LTDC version specified."
#endif

#endif
