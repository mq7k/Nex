#include "system/time/backend/stm32_tim.h"
#include "system/time/backend/timeif.h"

static u32
_now(
  void* handle
)
{
  struct system_stm32_timer_backend_ctx* ctx;
  ctx = (struct system_stm32_timer_backend_ctx*) handle;
  return tim_get_counter_value(ctx->tim);
}

struct sys_coarse_time_vtable stm32_coarse_time_backend = {
  .now = _now
};
