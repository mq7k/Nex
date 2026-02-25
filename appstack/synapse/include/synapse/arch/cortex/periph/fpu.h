#ifndef ARCH_FPU_H
#define ARCH_FPU_H

#include "synapse/common/util/common.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

#if defined(ARCH_FPU_V1)
#include "synapse/arch/cortex/drivers/fpu/fpu_v1.h"
#else
#error "No FPU version specified."
#endif

END_DECLARATIONS

#endif
