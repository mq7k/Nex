#ifndef SYSL_PROFILER_H
#define SYSL_PROFILER_H

#include "libcom/types.h"
#include "libcom/util.h"
#include "system/time/time.h"

BEGIN_DECLARATIONS

#define PROFILER_BENCHMARK_SECTION(section, expr)\
  u64 _systemtimenstart = system_get_time();\
  expr;\
  u64 _systemtimeend = system_get_time();\
  u32 elapsed = _systemtimeend - _systemtimenstart;\
  profiler_section_update(&section, elapsed);

struct profiler_section
{
  u32 call_count;
  u64 total_ticks;
  u64 min_ticks;
  u64 max_ticks;
};

void
profiler_section_update(
  struct profiler_section* section,
  u64 ticks
);

END_DECLARATIONS

#endif
