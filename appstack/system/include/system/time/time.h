#ifndef SYSL_TIME_H
#define SYSL_TIME_H

#include "libcom/types.h"
#include "libcom/util.h"
#include "system/time/backend/timeif.h"

BEGIN_DECLARATIONS

struct sys_time_backend
{
  struct sys_time_vtable* vtable;
  void* ctx;
};

void
system_set_time_source(
  struct sys_time_backend* backend
);

u64 
system_get_time(void);

void
system_time_handle_overflow(void);

END_DECLARATIONS

#endif
