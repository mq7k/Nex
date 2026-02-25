#ifndef ARCH_SCB_H
#define ARCH_SCB_H

#include "synapse/common/util/common.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

#if defined(ARCH_SCB_V1)
#include "synapse/arch/cortex/drivers/scb/scb_v1.h"
#else
#error "No SCB version specified."
#endif

END_DECLARATIONS

#endif
