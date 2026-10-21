#include "system/time/time.h"
#include "libcom/sys/devmode.h"
#include "libcom/util.h"

struct system_coarse_time* coarse_time = 0;
struct system_monotonic_time* monotonic_time = 0;

void
system_coarse_time_set_source(
  struct system_coarse_time* time
)
{
  coarse_time = time;
}

void
system_monotonic_time_set_source(
  struct system_monotonic_time* time
)
{
  monotonic_time = time;
}

u32 NEX_WEAK
system_coarse_time_get_value(
  void* ctx
)
{
  (void) ctx;
  return 0;
}

u32 NEX_WEAK
system_monotonic_time_get_value(
  void* ctx
)
{
  (void) ctx;
  return 0;
}

void
system_monotonic_time_overflow(void)
{
  devmode_assert_nonzero(coarse_time);
  ++monotonic_time->ofcount;
}

u32
system_coarse_time_now(void)
{
  devmode_assert_nonzero(coarse_time);
  return system_coarse_time_get_value(coarse_time);
}

u64
system_monotonic_time_now(void)
{
  devmode_assert_nonzero(monotonic_time);
  u32 shift = monotonic_time->value_width_bits;
  u32 cur = system_monotonic_time_get_value(monotonic_time);
  u32 ofcount = monotonic_time->ofcount;
  return ((u64) ofcount << shift) | cur;
}
