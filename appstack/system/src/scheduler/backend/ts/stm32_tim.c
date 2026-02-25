#include "synapse/stm32/periph/tim.h"
#include "system/scheduler/backend/sif.h"
#include "system/scheduler/backend/ts/stm32_tim.h"

static void
_start(
  void* handle
)
{
  struct scheduler_stm32_tim_backend* ctx;
  ctx = (struct scheduler_stm32_tim_backend*) handle;
  tim_counter_enable(ctx->tim);
}

static void
_stop(
  void* handle
)
{
  struct scheduler_stm32_tim_backend* ctx;
  ctx = (struct scheduler_stm32_tim_backend*) handle;
  tim_counter_disable(ctx->tim);
}

const struct scheduler_ts_backend_vtable scheduler_stm32_tim_backend = {
  .start = _start,
  .stop = _stop
};
