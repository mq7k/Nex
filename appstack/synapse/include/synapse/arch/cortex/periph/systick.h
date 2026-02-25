#ifndef ARCH_SYSTICK_H
#define ARCH_SYSTICK_H

#include "synapse/common/util/common.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

#if defined(ARCH_SYSTICK_V1)
#include "synapse/arch/cortex/drivers/systick/systick_v1.h"
#else
#error "No Systick version specified."
#endif

END_DECLARATIONS

#endif
