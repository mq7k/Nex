#ifndef STM32_HASH_H
#define STM32_HASH_H

#include "synapse/specs.h"

#if defined(STM32_HASH_V1)
#include "synapse/stm32/drivers/hash/hash_v1.h"
#else
#error "No HASH version specified."
#endif

#endif
