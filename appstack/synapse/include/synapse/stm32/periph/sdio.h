#ifndef STM32_SDIO_H
#define STM32_SDIO_H

#include "synapse/specs.h"

#if defined(STM32_SDIO_V1)
#include "synapse/stm32/drivers/sdio/sdio_v1.h"
#else
#error "No SDIO version specified."
#endif

#endif
