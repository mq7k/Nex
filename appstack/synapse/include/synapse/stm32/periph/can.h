#ifndef STM32_CAN_H
#define STM32_CAN_H

#include "synapse/specs.h"

#if defined(STM32_CAN_V1)
#include "synapse/stm32/drivers/can/can_v1.h"
#else
#error "No CAN version specified."
#endif

#endif
