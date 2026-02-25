#include "system/time/time.h"

static struct sys_time_backend* time_backend;

void
system_set_time_source(
  struct sys_time_backend* backend
)
{
  time_backend = backend;
}

u64 
system_get_time(void)
{
  return time_backend->vtable->now(time_backend->ctx);
}

void
system_time_handle_overflow(void)
{
  time_backend->vtable->on_overflow(time_backend->ctx);
}
