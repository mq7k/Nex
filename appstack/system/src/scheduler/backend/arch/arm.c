#include "system/scheduler/backend/sif.h"
#include "synapse/arch/cortex/common/sys.h"

static void
_irq_disable(void)
{
  cm_irq_disable();
}

static void
_irq_enable(void)
{
  cm_irq_enable();
}

static void
_sleep(void)
{
  cm_wfi();
}

const struct scheduler_arch_backend_vtable scheduler_arch_backend_arm = {
  .irq_disable = _irq_disable,
  .irq_enable = _irq_enable,
  .sleep = _sleep
};
