#ifndef STM32_I2C_H
#define STM32_I2C_H

#include "synapse/specs.h"

#if defined(STM32_I2C_V1)
#include "synapse/stm32/drivers/i2c/i2c_v1.h"
#else
#error "No I2C version specified."
#endif

#endif
