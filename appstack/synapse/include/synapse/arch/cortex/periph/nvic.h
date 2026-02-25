#ifndef ARCH_NVIC_H
#define ARCH_NVIC_H

#include "synapse/common/util/common.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

#if defined(ARCH_NVIC_V1)
#include "synapse/arch/cortex/drivers/nvic/nvic_v1.h"
#elif defined(ARCH_NVIC_V2)
#include "synapse/arch/cortex/drivers/nvic/nvic_v2.h"
#else
#error "No NVIC version specified."
#endif

END_DECLARATIONS

#endif
