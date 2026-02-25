#include "system/scheduler/wiring/dispatcher.h"
#include "libcom/types.h"
#include "system/scheduler/backend/sif.h"

// Time source backends.
extern struct scheduler_ts_backend_vtable scheduler_stm32_tim_backend;

// Arch backends.
extern struct scheduler_arch_backend_vtable scheduler_arch_backend_arm;

struct scheduler_ts_backend_vtable*
scheduler_get_backend_vtable(
  enum scheduler_ts_backend backend
)
{
  switch (backend)
  {
    case SCHEDULER_BACKEND_STM32_TIM:
      return &scheduler_stm32_tim_backend;

    default:
      return NULL;
  }
}

struct scheduler_arch_backend_vtable*
scheduler_get_arch_backend_vtable(
  enum scheduler_arch_backend backend
)
{
  switch (backend)
  {
    case SCHEDULER_ARCH_BACKEND_ARM:
      return &scheduler_arch_backend_arm;

    default:
      return NULL;
  }
}
