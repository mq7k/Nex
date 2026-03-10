#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/exti/exti_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  EXTI = (struct exti_registers_map*) membuf;
}

// └─Skipping type 'bitmap (TODO)' (exti_interrupt_line)
int
main(void)
{
  return 0;
}
