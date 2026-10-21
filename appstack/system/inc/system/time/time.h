#ifndef SYSL_TIME_H
#define SYSL_TIME_H

#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

struct system_coarse_time
{
  volatile void* ctx;
};

struct system_monotonic_time
{
  volatile void* ctx;
  u32 value_width_bits;
  u32 ofcount;
};

void
system_coarse_time_set_source(
  struct system_coarse_time* time
);

void
system_monotonic_time_set_source(
  struct system_monotonic_time* time
);

u32
system_coarse_time_get_value(
  void* ctx
);

u32
system_monotonic_time_get_value(
  void* ctx
);

void
system_monotonic_time_overflow(void);

u32
system_coarse_time_now(void);

u64
system_monotonic_time_now(void);

END_DECLARATIONS

#endif
