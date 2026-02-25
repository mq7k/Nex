#ifndef STM32_SPDIFRX_H
#define STM32_SPDIFRX_H

#include "synapse/specs.h"

#if defined(STM32_SPDIFRX_V1)
#include "synapse/stm32/drivers/spdifrx/spdifrx_v1.h"
#else
#error "No SPDIFRX version specified."
#endif

#endif
