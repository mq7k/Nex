#ifndef SYN_CORTEX_SPECS_H
#define SYN_CORTEX_SPECS_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#if defined(CORTEX_M4)
#include "synapse/arch/cortex/cm4/cm4.h"
#elif defined(CORTEX_M4F)
#include "synapse/arch/cortex/cm4f/cm4f.h"
#else
#error "No Cortex family specified."
#endif

END_DECLARATIONS

#endif
