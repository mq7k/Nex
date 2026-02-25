#ifndef STM32_AFIO_H
#define STM32_AFIO_H

#include "synapse/specs.h"

#if defined(STM32_AFIO_V1)
#include "synapse/stm32/drivers/afio/afio_v1.h"
#else
#error "No AFIO version specified."
#endif

#endif
