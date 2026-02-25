#ifndef STM32_FLASH_H
#define STM32_FLASH_H

#include "synapse/specs.h"

#if defined(STM32_FLASH_V1)
#include "synapse/stm32/drivers/flash/flash_v1.h"
#elif defined(STM32_FLASH_V2)
#include "synapse/stm32/drivers/flash/flash_v2.h"
#else
#error "No FLASH version specified."
#endif

#endif
