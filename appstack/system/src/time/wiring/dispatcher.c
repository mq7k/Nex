#include "system/time/wiring/dispatcher.h"
#include <stddef.h>

extern struct sys_time_vtable stm32_tim_backend;

struct sys_time_vtable*
system_get_time_backend_vtable(
  enum system_time_backend backend
)
{
  switch (backend)
  {
    case SYSTEM_TIME_BACKEND_STM32_TIM:
      return &stm32_tim_backend;

    default:
      return NULL;
  }
}
