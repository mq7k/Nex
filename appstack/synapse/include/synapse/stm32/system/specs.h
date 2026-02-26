#ifndef STM32_SPECS_H
#define STM32_SPECS_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#if defined(STM32F1)
#include "synapse/stm32/system/chips/f1/f1.h"
#elif defined(STM32F4)
#include "synapse/stm32/system/chips/f4/f4.h"
#else
#error "No STM32 family specified."
#endif

END_DECLARATIONS

#endif
