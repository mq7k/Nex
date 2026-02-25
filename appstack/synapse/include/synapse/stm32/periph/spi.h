#ifndef STM32_SPI_H
#define STM32_SPI_H

#include "synapse/specs.h"

#if defined(STM32_SPI_V1)
#include "synapse/stm32/drivers/spi/spi_v1.h"
#else
#error "No SPI version specified."
#endif

#endif
