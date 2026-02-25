#ifndef STM32_RNG_H
#define STM32_RNG_H

#include "synapse/specs.h"

#if defined(STM32_RNG_V1)
#include "synapse/stm32/drivers/rng/rng_v1.h"
#else
#error "No LTDC version specified."
#endif

#endif
