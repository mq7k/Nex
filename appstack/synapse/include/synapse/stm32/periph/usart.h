#ifndef STM32_USART_H
#define STM32_USART_H

#include "synapse/specs.h"

#if defined(STM32_USART_V1)
#include "synapse/stm32/drivers/usart/usart_v1.h"
#else
#error "No USART version specified."
#endif

#endif
