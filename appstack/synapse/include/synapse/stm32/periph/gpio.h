#ifndef STM32_GPIO_H
#define STM32_GPIO_H

#include "synapse/specs.h"

#if defined(STM32_GPIO_V1)
#include "synapse/stm32/drivers/gpio/gpio_v1.h"
#elif defined(STM32_GPIO_V2)
#include "synapse/stm32/drivers/gpio/gpio_v2.h"
#else
#error "No GPIO version specified."
#endif

#endif
