#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/exti/exti_v1.h"
#include "libtest/libtest.hpp"


void
setup(void)
{
  EXTI = (struct exti_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_OFFSET(struct exti_registers_map, IMR, 0x00lu);
  ASSERT_OFFSET(struct exti_registers_map, EMR, 0x04lu);
  ASSERT_OFFSET(struct exti_registers_map, RTSR, 0x08lu);
  ASSERT_OFFSET(struct exti_registers_map, FTSR, 0x0clu);
  ASSERT_OFFSET(struct exti_registers_map, SWIER, 0x10lu);
  ASSERT_OFFSET(struct exti_registers_map, PR, 0x14lu);
}

// └─Skipping type 'bitmap (TODO)' (exti_interrupt_line)
int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
  };

  return TESTS_RUN(tests);
}
