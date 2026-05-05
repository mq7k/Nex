#ifndef SYSL_TIMEIF_H
#define SYSL_TIMEIF_H

#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

struct sys_monotonic_time_vtable
{
  u64 (*now)(void*);
  void (*on_overflow)(void*);
};

struct sys_coarse_time_vtable
{
  u32 (*now)(void*);
};

END_DECLARATIONS

#endif
