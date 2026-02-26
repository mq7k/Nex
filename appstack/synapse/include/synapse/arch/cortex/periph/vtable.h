#ifndef ARCH_VTABLE_H
#define ARCH_VTABLE_H

#include "synapse/common/util/common.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

#if defined(ARCH_VTABLE_V1)
#include "synapse/arch/cortex/drivers/vtable/vtable_v1.h"
#if defined(ARCH_VTABLE_V2)
#include "synapse/arch/cortex/drivers/vtable/vtable_v2.h"
#else
#error "No VTABLE version specified."
#endif

END_DECLARATIONS

#endif
