#ifndef SYN_CORTEX_SPECS_H
#define SYN_CORTEX_SPECS_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#if defined(CPU_CM3)
#include "synapse/arch/cortex/cm3/cm3.h"
#elif defined(CPU_CM4)
#include "synapse/arch/cortex/cm4/cm4.h"
#elif defined(CPU_CM4F)
#include "synapse/arch/cortex/cm4f/cm4f.h"
#else
#error "No Cortex family specified."
#endif

END_DECLARATIONS

#endif
