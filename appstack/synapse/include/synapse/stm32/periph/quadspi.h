#ifndef STM32_QUADSPI_H
#define STM32_QUADSPI_H

#include "synapse/specs.h"

#if defined(STM32_QUADSPI_V1)
#include "synapse/stm32/drivers/quadspi/quadspi_v1.h"
#else
#error "No QUADSPI version specified."
#endif

#endif
