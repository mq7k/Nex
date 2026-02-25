#ifndef SYSL_TIME_DISPATCHER_H
#define SYSL_TIME_DISPATCHER_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

enum system_time_backend
{
  SYSTEM_TIME_BACKEND_STM32_TIM
};

struct sys_time_vtable*
system_get_time_backend_vtable(
  enum system_time_backend backend
);

END_DECLARATIONS

#endif
