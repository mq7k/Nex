#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/iwdg/iwdg_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  IWDG = (struct iwdg_registers_map*) membuf;
}

// └─Skipping type 'fn_call (TODO)' (iwdg_reset)
// └─Skipping type 'fn_call (TODO)' (iwdg_write_unlock)
// └─Skipping type 'fn_call (TODO)' (iwdg_start)
void
test_iwdg_set_prescaler(void)
{
  // scope=self.reg='PR', self.shift=0, self.mask='0x7', self.varsmap={'prescaler': 'IWDG_PRESCALER_DIV4'}, self.value='0b000', self.ifdef=[], self.halt=False
  IWDG->PR = 0;
  iwdg_set_prescaler(IWDG_PRESCALER_DIV4);
  ASSERT_EQ(IWDG->PR, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->PR = ~(0x7u << 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV4);
  ASSERT_EQ(IWDG->PR, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PR', self.shift=0, self.mask='0x7', self.varsmap={'prescaler': 'IWDG_PRESCALER_DIV8'}, self.value='0b001', self.ifdef=[], self.halt=False
  IWDG->PR = 0;
  iwdg_set_prescaler(IWDG_PRESCALER_DIV8);
  ASSERT_EQ(IWDG->PR, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->PR = ~(0x7u << 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV8);
  ASSERT_EQ(IWDG->PR, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PR', self.shift=0, self.mask='0x7', self.varsmap={'prescaler': 'IWDG_PRESCALER_DIV16'}, self.value='0b010', self.ifdef=[], self.halt=False
  IWDG->PR = 0;
  iwdg_set_prescaler(IWDG_PRESCALER_DIV16);
  ASSERT_EQ(IWDG->PR, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->PR = ~(0x7u << 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV16);
  ASSERT_EQ(IWDG->PR, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PR', self.shift=0, self.mask='0x7', self.varsmap={'prescaler': 'IWDG_PRESCALER_DIV32'}, self.value='0b011', self.ifdef=[], self.halt=False
  IWDG->PR = 0;
  iwdg_set_prescaler(IWDG_PRESCALER_DIV32);
  ASSERT_EQ(IWDG->PR, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->PR = ~(0x7u << 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV32);
  ASSERT_EQ(IWDG->PR, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PR', self.shift=0, self.mask='0x7', self.varsmap={'prescaler': 'IWDG_PRESCALER_DIV64'}, self.value='0b100', self.ifdef=[], self.halt=False
  IWDG->PR = 0;
  iwdg_set_prescaler(IWDG_PRESCALER_DIV64);
  ASSERT_EQ(IWDG->PR, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->PR = ~(0x7u << 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV64);
  ASSERT_EQ(IWDG->PR, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PR', self.shift=0, self.mask='0x7', self.varsmap={'prescaler': 'IWDG_PRESCALER_DIV128'}, self.value='0b101', self.ifdef=[], self.halt=False
  IWDG->PR = 0;
  iwdg_set_prescaler(IWDG_PRESCALER_DIV128);
  ASSERT_EQ(IWDG->PR, (0b101u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->PR = ~(0x7u << 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV128);
  ASSERT_EQ(IWDG->PR, ~(0x7u << 0) | (0b101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PR', self.shift=0, self.mask='0x7', self.varsmap={'prescaler': 'IWDG_PRESCALER_DIV256'}, self.value='0b110', self.ifdef=[], self.halt=False
  IWDG->PR = 0;
  iwdg_set_prescaler(IWDG_PRESCALER_DIV256);
  ASSERT_EQ(IWDG->PR, (0b110u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->PR = ~(0x7u << 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV256);
  ASSERT_EQ(IWDG->PR, ~(0x7u << 0) | (0b110u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_iwdg_set_reload_value(void)
{
  IWDG->RLR = 0;
  iwdg_set_reload_value(0);
  ASSERT_EQ(IWDG->RLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  IWDG->RLR = 0xffffffff;
  iwdg_set_reload_value(0);
  ASSERT_EQ(IWDG->RLR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  IWDG->RLR = 0;
  iwdg_set_reload_value(0xfff);
  ASSERT_EQ(IWDG->RLR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  IWDG->RLR = 0xffffffff;
  iwdg_set_reload_value(0xfff);
  ASSERT_EQ(IWDG->RLR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  IWDG->RLR = 0;
  iwdg_set_reload_value(0x1000);
  ASSERT_EQ(IWDG->RLR, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  IWDG->RLR = 0xffffffff;
  iwdg_set_reload_value(0x1000);
  ASSERT_EQ(IWDG->RLR, ~(0xfffu << 0) | (0x1000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_iwdg_is_flag_set(void)
{
  u32 res;

  IWDG->SR = 0;
  res = iwdg_is_flag_set(IWDG_FLAG_PRESCALER_UPDATE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  IWDG->SR = (1u << 0);
  res = iwdg_is_flag_set(IWDG_FLAG_PRESCALER_UPDATE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  IWDG->SR = ~(1u << 0);
  res = iwdg_is_flag_set(IWDG_FLAG_PRESCALER_UPDATE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  IWDG->SR = 0xffffffff;
  res = iwdg_is_flag_set(IWDG_FLAG_PRESCALER_UPDATE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  IWDG->SR = 0;
  res = iwdg_is_flag_set(IWDG_FLAG_COUNTER_UPDATE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  IWDG->SR = (1u << 1);
  res = iwdg_is_flag_set(IWDG_FLAG_COUNTER_UPDATE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  IWDG->SR = ~(1u << 1);
  res = iwdg_is_flag_set(IWDG_FLAG_COUNTER_UPDATE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  IWDG->SR = 0xffffffff;
  res = iwdg_is_flag_set(IWDG_FLAG_COUNTER_UPDATE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_iwdg_set_prescaler),
    TEST_FUNC(test_iwdg_set_reload_value),
    TEST_FUNC(test_iwdg_is_flag_set),
  };

  return TESTS_RUN(tests);
}
