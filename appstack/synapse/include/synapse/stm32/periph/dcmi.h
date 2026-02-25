#ifndef STM32_DCMI_H
#define STM32_DCMI_H

#include "synapse/specs.h"

#if defined(STM32_DCMI_V1)
#include "synapse/stm32/drivers/dcmi/dcmi_v1.h"
#else
#error "No DCMI version specified."
#endif

#endif
