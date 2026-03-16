#include "system/time/backend/stm32_tim.h"
#include "system/time/backend/timeif.h"

static u64
_now(
  void* handle
)
{
  struct system_stm32_timer_backend_ctx* ctx;
  ctx = (struct system_stm32_timer_backend_ctx*) handle;
  u32 shift = ctx->value_width_bits;

  u32 cur = tim_get_counter_value(ctx->tim);
  return ((u64) ctx->ofcount << shift) | cur;
}

static void
_on_overflow(
  void* handle
)
{
  struct system_stm32_timer_backend_ctx* ctx;
  ctx = (struct system_stm32_timer_backend_ctx*) handle;
  ++ctx->ofcount;
}

struct sys_time_vtable stm32_tim_backend = {
  .now = _now,
  .on_overflow = _on_overflow
};
