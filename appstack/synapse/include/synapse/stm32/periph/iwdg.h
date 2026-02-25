#ifndef STM32_IWDG_H
#define STM32_IWDG_H

#include "synapse/specs.h"

#if defined(STM32_IWDG_V1)
#include "synapse/stm32/drivers/iwdg/iwdg_v1.h"
#else
#error "No IWDG version specified."
#endif

#endif
