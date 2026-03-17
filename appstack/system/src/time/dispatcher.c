#include "system/time/dispatcher.h"
#include "system/time/backend/stm32_tim.h"
#include <stddef.h>

struct sys_time_vtable*
system_get_time_backend(
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
