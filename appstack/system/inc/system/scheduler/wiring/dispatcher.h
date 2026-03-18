#ifndef SYSTEM_SCHEDULER_BACKEND_DISPATCHER_H
#define SYSTEM_SCHEDULER_BACKEND_DISPATCHER_H

#include "libcom/util.h"
#include "system/scheduler/backend/sif.h"

BEGIN_DECLARATIONS

enum scheduler_ts_backend
{
  SCHEDULER_BACKEND_STM32_TIM
};

enum scheduler_arch_backend
{
  SCHEDULER_ARCH_BACKEND_ARM
};

struct scheduler_ts_backend_vtable*
scheduler_get_backend_vtable(
  enum scheduler_ts_backend backend
);

struct scheduler_arch_backend_vtable*
scheduler_get_arch_backend_vtable(
  enum scheduler_arch_backend backend
);

END_DECLARATIONS

#endif
