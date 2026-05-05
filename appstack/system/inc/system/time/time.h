#ifndef SYSL_TIME_H
#define SYSL_TIME_H

#include "libcom/types.h"
#include "libcom/util.h"
#include "system/time/backend/timeif.h"

BEGIN_DECLARATIONS

struct sys_coarse_time_backend
{
  struct sys_coarse_time_vtable* vtable;
  void* ctx;
};

struct sys_monotonic_time_backend
{
  struct sys_monotonic_time_vtable* vtable;
  void* ctx;
};

void
system_set_coarse_time_source(
  struct sys_coarse_time_backend* backend
);

void
system_set_monotonic_time_source(
  struct sys_monotonic_time_backend* backend
);

u32
system_get_coarse_time(void);

u64 
system_get_monotonic_time(void);

void
system_time_handle_monotonic_overflow(void);

END_DECLARATIONS

#endif
