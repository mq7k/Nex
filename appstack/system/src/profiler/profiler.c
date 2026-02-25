#include "system/profiler/profiler.h"

void
profiler_section_update(
  struct profiler_section* section,
  u64 ticks
)
{
  ++section->call_count;
  section->total_ticks += ticks;

  if (section->min_ticks > ticks || section->min_ticks == 0)
  {
    section->min_ticks = ticks;
  }

  if (section->max_ticks < ticks)
  {
    section->max_ticks = ticks;
  }
}
