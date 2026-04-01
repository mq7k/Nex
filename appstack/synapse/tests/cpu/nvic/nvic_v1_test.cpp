#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/cpu/cortex/drivers/nvic/nvic_v1.h"
#include "libtest/libtest.hpp"

#define ASSERT_ADDR(periph, reg, offset)\
	ASSERT_EQ(offsetof(periph, reg), offset)


void
setup(void)
{
  NVIC = (struct nvic_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_ADDR(struct nvic_registers_map, ISER, 0x00lu);
  ASSERT_ADDR(struct nvic_registers_map, ICER, 0x80lu);
  ASSERT_ADDR(struct nvic_registers_map, ISPR, 0x100lu);
  ASSERT_ADDR(struct nvic_registers_map, ICPR, 0x180lu);
  ASSERT_ADDR(struct nvic_registers_map, IABR, 0x200lu);
  ASSERT_ADDR(struct nvic_registers_map, IPR, 0x300lu);
  ASSERT_ADDR(struct nvic_registers_map, STIR, 0xe00lu);
}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
  };

  return TESTS_RUN(tests);
}
