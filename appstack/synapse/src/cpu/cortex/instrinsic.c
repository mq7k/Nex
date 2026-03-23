#include "synapse/backends/arch/cpu_instrinsic.h"
#include "synapse/cpu/cortex/common/sys.h"

void
syn_irq_enable(void)
{
  cm_irq_enable();
}

void
syn_irq_disable(void)
{
  cm_irq_disable();
}

void
syn_wait_for_interrupt(void)
{
  cm_wfi();
}

