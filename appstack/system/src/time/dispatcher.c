#include "system/time/dispatcher.h"
#include "system/time/backend/stm32_tim.h"
#include "system/time/backend/timeif.h"

struct sys_coarse_time_vtable*
system_get_coarse_time_backend(
  enum system_coarse_time_backend backend
)
{
  switch (backend)
  {
    case SYSTEM_COARSE_TIME_BACKEND_STM32_TIM:
      return &stm32_coarse_time_backend;

    default:
      return NULL;
  }
}

struct sys_monotonic_time_vtable*
system_get_monotonic_time_backend(
  enum system_monotonic_time_backend backend
)
{
  switch (backend)
  {
    case SYSTEM_MONOTONIC_TIME_BACKEND_STM32_TIM:
      return &stm32_monotonic_time_backend;

    default:
      return NULL;
  }
}
