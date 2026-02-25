#ifndef STM32_BKP_H
#define STM32_BKP_H

#include "synapse/specs.h"

#if defined(STM32_BKP_V1)
#include "synapse/stm32/drivers/bkp/bkp_v1.h"
#else
#error "No BKP version specified."
#endif

#endif
