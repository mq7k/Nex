#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/wwdg/wwdg_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  WWDG = (struct wwdg_registers_map*) membuf;
}

void
test_wwdg_set_counter(void)
{
  WWDG->CR = 0;
  wwdg_set_counter(0);
  ASSERT_EQ(WWDG->CR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  WWDG->CR = 0xffffffff;
  wwdg_set_counter(0);
  ASSERT_EQ(WWDG->CR, ~(0x7fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  WWDG->CR = 0;
  wwdg_set_counter(0x7f);
  ASSERT_EQ(WWDG->CR, 0x7fu << 0);
  ASSERT_FALSE(execution_halted());

  WWDG->CR = 0xffffffff;
  wwdg_set_counter(0x7f);
  ASSERT_EQ(WWDG->CR, ~(0x7fu << 0) | (0x7fu << 0));
  ASSERT_FALSE(execution_halted());


  WWDG->CR = 0;
  wwdg_set_counter(0x80);
  ASSERT_EQ(WWDG->CR, 0x80u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  WWDG->CR = 0xffffffff;
  wwdg_set_counter(0x80);
  ASSERT_EQ(WWDG->CR, ~(0x7fu << 0) | (0x80u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_wwdg_get_counter(void)
{
  u32 res;

  // read_bits
  WWDG->CR = 0;
  res = wwdg_get_counter();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  WWDG->CR = ~(0x7fu << 0);
  res = wwdg_get_counter();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  WWDG->CR = 0x7fu << 0;
  res = wwdg_get_counter();
  ASSERT_EQ(res, 0x7f);
  ASSERT_FALSE(execution_halted());

}

void
test_wwdg_start(void)
{
  WWDG->CR = 0;
  wwdg_start();
  ASSERT_EQ(WWDG->CR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  WWDG->CR = ~(1u << 7);
  wwdg_start();
  ASSERT_EQ(WWDG->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_wwdg_set_upper_threshold(void)
{
  WWDG->CFR = 0;
  wwdg_set_upper_threshold(0);
  ASSERT_EQ(WWDG->CFR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = 0xffffffff;
  wwdg_set_upper_threshold(0);
  ASSERT_EQ(WWDG->CFR, ~(0x7fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  WWDG->CFR = 0;
  wwdg_set_upper_threshold(0x7f);
  ASSERT_EQ(WWDG->CFR, 0x7fu << 0);
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = 0xffffffff;
  wwdg_set_upper_threshold(0x7f);
  ASSERT_EQ(WWDG->CFR, ~(0x7fu << 0) | (0x7fu << 0));
  ASSERT_FALSE(execution_halted());


  WWDG->CFR = 0;
  wwdg_set_upper_threshold(0x80);
  ASSERT_EQ(WWDG->CFR, 0x80u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  WWDG->CFR = 0xffffffff;
  wwdg_set_upper_threshold(0x80);
  ASSERT_EQ(WWDG->CFR, ~(0x7fu << 0) | (0x80u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_wwdg_set_prescaler(void)
{
  // scope=self.reg='CFR', self.shift=7, self.mask='0x3', self.varsmap={'prescaler': 'WWDG_PRESCALER_DIV1'}, self.value='0b00', self.ifdef=[], self.halt=False
  WWDG->CFR = 0;
  wwdg_set_prescaler(WWDG_PRESCALER_DIV1);
  ASSERT_EQ(WWDG->CFR, (0b00u << 7));
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = ~(0x3u << 7);
  wwdg_set_prescaler(WWDG_PRESCALER_DIV1);
  ASSERT_EQ(WWDG->CFR, ~(0x3u << 7) | (0b00u << 7));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFR', self.shift=7, self.mask='0x3', self.varsmap={'prescaler': 'WWDG_PRESCALER_DIV2'}, self.value='0b01', self.ifdef=[], self.halt=False
  WWDG->CFR = 0;
  wwdg_set_prescaler(WWDG_PRESCALER_DIV2);
  ASSERT_EQ(WWDG->CFR, (0b01u << 7));
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = ~(0x3u << 7);
  wwdg_set_prescaler(WWDG_PRESCALER_DIV2);
  ASSERT_EQ(WWDG->CFR, ~(0x3u << 7) | (0b01u << 7));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFR', self.shift=7, self.mask='0x3', self.varsmap={'prescaler': 'WWDG_PRESCALER_DIV4'}, self.value='0b10', self.ifdef=[], self.halt=False
  WWDG->CFR = 0;
  wwdg_set_prescaler(WWDG_PRESCALER_DIV4);
  ASSERT_EQ(WWDG->CFR, (0b10u << 7));
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = ~(0x3u << 7);
  wwdg_set_prescaler(WWDG_PRESCALER_DIV4);
  ASSERT_EQ(WWDG->CFR, ~(0x3u << 7) | (0b10u << 7));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFR', self.shift=7, self.mask='0x3', self.varsmap={'prescaler': 'WWDG_PRESCALER_DIV8'}, self.value='0b11', self.ifdef=[], self.halt=False
  WWDG->CFR = 0;
  wwdg_set_prescaler(WWDG_PRESCALER_DIV8);
  ASSERT_EQ(WWDG->CFR, (0b11u << 7));
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = ~(0x3u << 7);
  wwdg_set_prescaler(WWDG_PRESCALER_DIV8);
  ASSERT_EQ(WWDG->CFR, ~(0x3u << 7) | (0b11u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_wwdg_early_wakeup_interrupt(void)
{
  WWDG->CFR = 0;
  wwdg_early_wakeup_interrupt_enable();
  ASSERT_EQ(WWDG->CFR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = ~(1u << 9);
  wwdg_early_wakeup_interrupt_enable();
  ASSERT_EQ(WWDG->CFR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = (1u << 9);
  wwdg_early_wakeup_interrupt_disable();
  ASSERT_EQ(WWDG->CFR, 0);
  ASSERT_FALSE(execution_halted());

  WWDG->CFR = 0xffffffff;
  wwdg_early_wakeup_interrupt_disable();
  ASSERT_EQ(WWDG->CFR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_wwdg_is_early_wakeup_interrupt_flag_set(void)
{
  u32 res;

  WWDG->SR = 0;
  res = wwdg_is_early_wakeup_interrupt_flag_set();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  WWDG->SR = (1u << 0);
  res = wwdg_is_early_wakeup_interrupt_flag_set();
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  WWDG->SR = ~(1u << 0);
  res = wwdg_is_early_wakeup_interrupt_flag_set();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  WWDG->SR = 0xffffffff;
  res = wwdg_is_early_wakeup_interrupt_flag_set();
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_wwdg_early_wakeup_interrupt_flag_clear(void)
{
  WWDG->SR = (1u << 0);
  wwdg_early_wakeup_interrupt_flag_clear();
  ASSERT_EQ(WWDG->SR, 0);
  ASSERT_FALSE(execution_halted());

  WWDG->SR = 0xffffffff;
  wwdg_early_wakeup_interrupt_flag_clear();
  ASSERT_EQ(WWDG->SR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_wwdg_set_counter),
    TEST_FUNC(test_wwdg_get_counter),
    TEST_FUNC(test_wwdg_start),
    TEST_FUNC(test_wwdg_set_upper_threshold),
    TEST_FUNC(test_wwdg_set_prescaler),
    TEST_FUNC(test_wwdg_early_wakeup_interrupt),
    TEST_FUNC(test_wwdg_is_early_wakeup_interrupt_flag_set),
    TEST_FUNC(test_wwdg_early_wakeup_interrupt_flag_clear),
  };

  return TESTS_RUN(tests);
}
