#ifndef STM32_WWDG_H
#define STM32_WWDG_H

#include "synapse/specs.h"

#if defined(STM32_WWDG_V1)
#include "synapse/stm32/drivers/wwdg/wwdg_v1.h"
#else
#error "No WWDG version specified."
#endif

#endif
