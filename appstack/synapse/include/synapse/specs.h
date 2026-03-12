#ifndef SYN_SPECSMUX_H
#define SYN_SPECSMUX_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#if defined(STM32)
#include "synapse/soc/stm32/system/specs.h"
#else
#error "No vendor family specified."
#endif

#if defined(CORTEX)
#include "synapse/cpu/cortex/specs.h"
#else
#error "No CPU family specified."
#endif

END_DECLARATIONS

#endif
