#ifndef STM32_CRYP_H
#define STM32_CRYP_H

#include "synapse/specs.h"

#if defined(STM32_CRYP_V1)
#include "synapse/stm32/drivers/cryp/cryp_v1.h"
#else
#error "No CRYP version specified."
#endif

#endif
