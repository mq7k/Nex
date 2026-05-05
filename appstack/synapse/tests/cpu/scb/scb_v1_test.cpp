#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/cpu/cortex/drivers/scb/scb_v1.h"
#include "libtest/libtest.hpp"

#define ASSERT_ADDR(periph, reg, offset)\
	ASSERT_EQ(offsetof(periph, reg), offset)


void
setup(void)
{
  SCB = (struct scb_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_ADDR(struct scb_registers_map, ACTLR, 0x00lu);
  ASSERT_ADDR(struct scb_registers_map, CPUID, 0xcf8lu);
  ASSERT_ADDR(struct scb_registers_map, ICSR, 0xcfclu);
  ASSERT_ADDR(struct scb_registers_map, VTOR, 0xd00lu);
  ASSERT_ADDR(struct scb_registers_map, AIRCR, 0xd04lu);
  ASSERT_ADDR(struct scb_registers_map, SCR, 0xd08lu);
  ASSERT_ADDR(struct scb_registers_map, CCR, 0xd0clu);
  ASSERT_ADDR(struct scb_registers_map, SHPR1, 0xd10lu);
  ASSERT_ADDR(struct scb_registers_map, SHPR2, 0xd14lu);
  ASSERT_ADDR(struct scb_registers_map, SHPR3, 0xd18lu);
  ASSERT_ADDR(struct scb_registers_map, SHCSR, 0xd1clu);
  ASSERT_ADDR(struct scb_registers_map, CFSR, 0xd20lu);
  ASSERT_ADDR(struct scb_registers_map, HFSR, 0xd24lu);
  ASSERT_ADDR(struct scb_registers_map, DFSR, 0xd28lu);
  ASSERT_ADDR(struct scb_registers_map, MMFAR, 0xd2clu);
  ASSERT_ADDR(struct scb_registers_map, BFAR, 0xd30lu);
  ASSERT_ADDR(struct scb_registers_map, AFSR, 0xd34lu);
}

void
test_scb_interrupt_multi_cycle_intructions(void)
{
  SCB->ACTLR = 0;
  scb_interrupt_multi_cycle_intructions_disable();
  ASSERT_EQ(SCB->ACTLR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SCB->ACTLR = ~(1u << 0);
  scb_interrupt_multi_cycle_intructions_disable();
  ASSERT_EQ(SCB->ACTLR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SCB->ACTLR = (1u << 0);
  scb_interrupt_multi_cycle_intructions_enable();
  ASSERT_EQ(SCB->ACTLR, 0);
  ASSERT_FALSE(execution_halted());

  SCB->ACTLR = 0xffffffff;
  scb_interrupt_multi_cycle_intructions_enable();
  ASSERT_EQ(SCB->ACTLR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'fn_toggle (TODO)' (scb_write_buffer)
void
test_scb_folding_it_instructions(void)
{
  SCB->ACTLR = 0;
  scb_folding_it_instructions_disable();
  ASSERT_EQ(SCB->ACTLR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SCB->ACTLR = ~(1u << 2);
  scb_folding_it_instructions_disable();
  ASSERT_EQ(SCB->ACTLR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SCB->ACTLR = (1u << 2);
  scb_folding_it_instructions_enable();
  ASSERT_EQ(SCB->ACTLR, 0);
  ASSERT_FALSE(execution_halted());

  SCB->ACTLR = 0xffffffff;
  scb_folding_it_instructions_enable();
  ASSERT_EQ(SCB->ACTLR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
    TEST_FUNC(test_scb_interrupt_multi_cycle_intructions),
    TEST_FUNC(test_scb_folding_it_instructions),
  };

  return TESTS_RUN(tests);
}
