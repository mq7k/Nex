#ifndef STM32_CRC_H
#define STM32_CRC_H

#include "synapse/specs.h"

#if defined(STM32_CRC_V1)
#include "synapse/stm32/drivers/crc/crc_v1.h"
#else
#error "No CRC version specified."
#endif

#endif
