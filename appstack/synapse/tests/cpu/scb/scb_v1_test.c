#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/cpu/cortex/drivers/scb/scb_v1.h"
#include "libtest/libtest.h"


void
setup(void)
{
  SCB = (struct scb_registers_map*) membuf;
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
    TEST_FUNC(test_scb_interrupt_multi_cycle_intructions),
    TEST_FUNC(test_scb_folding_it_instructions),
  };

  return TESTS_RUN(tests);
}
