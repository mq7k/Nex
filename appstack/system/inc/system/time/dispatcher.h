#ifndef SYSL_TIME_DISPATCHER_H
#define SYSL_TIME_DISPATCHER_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

enum system_coarse_time_backend
{
  SYSTEM_COARSE_TIME_BACKEND_STM32_TIM
};

enum system_monotonic_time_backend
{
  SYSTEM_MONOTONIC_TIME_BACKEND_STM32_TIM
};

struct sys_coarse_time_vtable*
system_get_coarse_time_backend(
  enum system_coarse_time_backend backend
);

struct sys_monotonic_time_vtable*
system_get_monotonic_time_backend(
  enum system_monotonic_time_backend backend
);

END_DECLARATIONS

#endif
