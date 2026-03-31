#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/exti/exti_v1.h"
#include "libtest/libtest.hpp"

#define ASSERT_ADDR(periph, reg, offset)\
	ASSERT_EQ(offsetof(periph, reg), offset)


void
setup(void)
{
  EXTI = (struct exti_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_ADDR(struct exti_registers_map, IMR, 0x00lu);
  ASSERT_ADDR(struct exti_registers_map, EMR, 0x04lu);
  ASSERT_ADDR(struct exti_registers_map, RTSR, 0x08lu);
  ASSERT_ADDR(struct exti_registers_map, FTSR, 0x0clu);
  ASSERT_ADDR(struct exti_registers_map, SWIER, 0x10lu);
  ASSERT_ADDR(struct exti_registers_map, PR, 0x14lu);
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
