#include "system/time/time.h"

static struct sys_coarse_time_backend* coarse_time_backend;
static struct sys_monotonic_time_backend* monotonic_time_backend;

void
system_set_coarse_time_source(
  struct sys_coarse_time_backend* backend
)
{
  coarse_time_backend = backend;
}

void
system_set_monotonic_time_source(
  struct sys_monotonic_time_backend* backend
)
{
  monotonic_time_backend = backend;
}

u32
system_get_coarse_time(void)
{
  return coarse_time_backend->vtable->now(coarse_time_backend->ctx);
}

u64 
system_get_monotonic_time(void)
{
  return monotonic_time_backend->vtable->now(monotonic_time_backend->ctx);
}

void
system_time_handle_overflow(void)
{
  monotonic_time_backend->vtable->on_overflow(monotonic_time_backend->ctx);
}
