#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/bkp/bkp_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  BKP = (struct bkp_registers_map*) membuf;
}

void
test_bkp_data_write(void)
{
  BKP->DR0[0] = 0;
  bkp_data_write(0, 0);
  ASSERT_EQ(BKP->DR0[0], 0u << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR0[0] = 0xffffffff;
  bkp_data_write(0, 0);
  ASSERT_EQ(BKP->DR0[0], 0);
  ASSERT_FALSE(execution_halted());


  BKP->DR0[9] = 0;
  bkp_data_write(9, 0);
  ASSERT_EQ(BKP->DR0[9], 0u << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR0[9] = 0xffffffff;
  bkp_data_write(9, 0);
  ASSERT_EQ(BKP->DR0[9], 0);
  ASSERT_FALSE(execution_halted());


  BKP->DR1[0] = 0;
  bkp_data_write(10, 0);
  ASSERT_EQ(BKP->DR1[0], 0u << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR1[0] = 0xffffffff;
  bkp_data_write(10, 0);
  ASSERT_EQ(BKP->DR1[0], 0);
  ASSERT_FALSE(execution_halted());


  BKP->DR1[BKP_DR_MAX_IDX-11] = 0;
  bkp_data_write(BKP_DR_MAX_IDX-1, 0);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-11], 0u << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR1[BKP_DR_MAX_IDX-11] = 0xffffffff;
  bkp_data_write(BKP_DR_MAX_IDX-1, 0);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-11], 0);
  ASSERT_FALSE(execution_halted());


  BKP->DR1[BKP_DR_MAX_IDX-10] = 0;
  bkp_data_write(BKP_DR_MAX_IDX, 0);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-10], 0u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->DR1[BKP_DR_MAX_IDX-10] = 0xffffffff;
  bkp_data_write(BKP_DR_MAX_IDX, 0);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-10], 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  BKP->DR0[0] = 0;
  bkp_data_write(0, 0xffff);
  ASSERT_EQ(BKP->DR0[0], 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR0[0] = 0xffffffff;
  bkp_data_write(0, 0xffff);
  ASSERT_EQ(BKP->DR0[0], 0xffff);
  ASSERT_FALSE(execution_halted());


  BKP->DR0[9] = 0;
  bkp_data_write(9, 0xffff);
  ASSERT_EQ(BKP->DR0[9], 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR0[9] = 0xffffffff;
  bkp_data_write(9, 0xffff);
  ASSERT_EQ(BKP->DR0[9], 0xffff);
  ASSERT_FALSE(execution_halted());


  BKP->DR1[0] = 0;
  bkp_data_write(10, 0xffff);
  ASSERT_EQ(BKP->DR1[0], 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR1[0] = 0xffffffff;
  bkp_data_write(10, 0xffff);
  ASSERT_EQ(BKP->DR1[0], 0xffff);
  ASSERT_FALSE(execution_halted());


  BKP->DR1[BKP_DR_MAX_IDX-11] = 0;
  bkp_data_write(BKP_DR_MAX_IDX-1, 0xffff);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-11], 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR1[BKP_DR_MAX_IDX-11] = 0xffffffff;
  bkp_data_write(BKP_DR_MAX_IDX-1, 0xffff);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-11], 0xffff);
  ASSERT_FALSE(execution_halted());


  BKP->DR1[BKP_DR_MAX_IDX-10] = 0;
  bkp_data_write(BKP_DR_MAX_IDX, 0xffff);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-10], 0xffffu << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->DR1[BKP_DR_MAX_IDX-10] = 0xffffffff;
  bkp_data_write(BKP_DR_MAX_IDX, 0xffff);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-10], 0xffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  BKP->DR0[0] = 0;
  bkp_data_write(0, 0x10000);
  ASSERT_EQ(BKP->DR0[0], 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->DR0[0] = 0xffffffff;
  bkp_data_write(0, 0x10000);
  ASSERT_EQ(BKP->DR0[0], 0x10000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  BKP->DR0[9] = 0;
  bkp_data_write(9, 0x10000);
  ASSERT_EQ(BKP->DR0[9], 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->DR0[9] = 0xffffffff;
  bkp_data_write(9, 0x10000);
  ASSERT_EQ(BKP->DR0[9], 0x10000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  BKP->DR1[0] = 0;
  bkp_data_write(10, 0x10000);
  ASSERT_EQ(BKP->DR1[0], 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->DR1[0] = 0xffffffff;
  bkp_data_write(10, 0x10000);
  ASSERT_EQ(BKP->DR1[0], 0x10000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  BKP->DR1[BKP_DR_MAX_IDX-11] = 0;
  bkp_data_write(BKP_DR_MAX_IDX-1, 0x10000);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-11], 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->DR1[BKP_DR_MAX_IDX-11] = 0xffffffff;
  bkp_data_write(BKP_DR_MAX_IDX-1, 0x10000);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-11], 0x10000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  BKP->DR1[BKP_DR_MAX_IDX-10] = 0;
  bkp_data_write(BKP_DR_MAX_IDX, 0x10000);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-10], 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->DR1[BKP_DR_MAX_IDX-10] = 0xffffffff;
  bkp_data_write(BKP_DR_MAX_IDX, 0x10000);
  ASSERT_EQ(BKP->DR1[BKP_DR_MAX_IDX-10], 0x10000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_bkp_data_read(void)
{
  u32 res;

  // read_reg
  BKP->DR0[0] = 0;
  res = bkp_data_read(0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR0[0] = 0xffffffff;
  res = bkp_data_read(0);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  BKP->DR0[9] = 0;
  res = bkp_data_read(9);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR0[9] = 0xffffffff;
  res = bkp_data_read(9);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  BKP->DR1[0] = 0;
  res = bkp_data_read(10);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR1[0] = 0xffffffff;
  res = bkp_data_read(10);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  BKP->DR1[BKP_DR_MAX_IDX-11] = 0;
  res = bkp_data_read(BKP_DR_MAX_IDX-1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->DR1[BKP_DR_MAX_IDX-11] = 0xffffffff;
  res = bkp_data_read(BKP_DR_MAX_IDX-1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  BKP->DR1[BKP_DR_MAX_IDX] = 0;
  res = bkp_data_read(BKP_DR_MAX_IDX);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_bkp_set_rtc_calibration_value(void)
{
  BKP->RTCCR = 0;
  bkp_set_rtc_calibration_value(0);
  ASSERT_EQ(BKP->RTCCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  BKP->RTCCR = 0xffffffff;
  bkp_set_rtc_calibration_value(0);
  ASSERT_EQ(BKP->RTCCR, ~(0x7fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  BKP->RTCCR = 0;
  bkp_set_rtc_calibration_value(0x7f);
  ASSERT_EQ(BKP->RTCCR, 0x7fu << 0);
  ASSERT_FALSE(execution_halted());

  BKP->RTCCR = 0xffffffff;
  bkp_set_rtc_calibration_value(0x7f);
  ASSERT_EQ(BKP->RTCCR, ~(0x7fu << 0) | (0x7fu << 0));
  ASSERT_FALSE(execution_halted());


  BKP->RTCCR = 0;
  bkp_set_rtc_calibration_value(0x80);
  ASSERT_EQ(BKP->RTCCR, 0x80u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  BKP->RTCCR = 0xffffffff;
  bkp_set_rtc_calibration_value(0x80);
  ASSERT_EQ(BKP->RTCCR, ~(0x7fu << 0) | (0x80u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_bkp_rtc_calib_clock_output(void)
{
  BKP->RTCCR = 0;
  bkp_rtc_calib_clock_output_enable();
  ASSERT_EQ(BKP->RTCCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  BKP->RTCCR = ~(1u << 7);
  bkp_rtc_calib_clock_output_enable();
  ASSERT_EQ(BKP->RTCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_rtc_signal_output(void)
{
  BKP->RTCCR = 0;
  bkp_rtc_signal_output_enable();
  ASSERT_EQ(BKP->RTCCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  BKP->RTCCR = ~(1u << 8);
  bkp_rtc_signal_output_enable();
  ASSERT_EQ(BKP->RTCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_set_rtc_output_signal(void)
{
  BKP->RTCCR = 0;
  bkp_set_rtc_output_signal(BKP_RTC_SIGNAL_SECOND);
  ASSERT_EQ(BKP->RTCCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  BKP->RTCCR = ~(1u << 9);
  bkp_set_rtc_output_signal(BKP_RTC_SIGNAL_SECOND);
  ASSERT_EQ(BKP->RTCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  BKP->RTCCR = (1u << 9);
  bkp_set_rtc_output_signal(BKP_RTC_SIGNAL_ALARM);
  ASSERT_EQ(BKP->RTCCR, 0);
  ASSERT_FALSE(execution_halted());

  BKP->RTCCR = 0xffffffff;
  bkp_set_rtc_output_signal(BKP_RTC_SIGNAL_ALARM);
  ASSERT_EQ(BKP->RTCCR, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_tamper_pin(void)
{
  BKP->CR = 0;
  bkp_tamper_pin_enable();
  ASSERT_EQ(BKP->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  BKP->CR = ~(1u << 0);
  bkp_tamper_pin_enable();
  ASSERT_EQ(BKP->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  BKP->CR = (1u << 0);
  bkp_tamper_pin_disable();
  ASSERT_EQ(BKP->CR, 0);
  ASSERT_FALSE(execution_halted());

  BKP->CR = 0xffffffff;
  bkp_tamper_pin_disable();
  ASSERT_EQ(BKP->CR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_set_tamper_pin_active_level(void)
{
  BKP->CR = 0;
  bkp_set_tamper_pin_active_level(BKP_TAMPER_PIN_LEVEL_LOW);
  ASSERT_EQ(BKP->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  BKP->CR = ~(1u << 1);
  bkp_set_tamper_pin_active_level(BKP_TAMPER_PIN_LEVEL_LOW);
  ASSERT_EQ(BKP->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  BKP->CR = (1u << 1);
  bkp_set_tamper_pin_active_level(BKP_TAMPER_PIN_LEVEL_HIGH);
  ASSERT_EQ(BKP->CR, 0);
  ASSERT_FALSE(execution_halted());

  BKP->CR = 0xffffffff;
  bkp_set_tamper_pin_active_level(BKP_TAMPER_PIN_LEVEL_HIGH);
  ASSERT_EQ(BKP->CR, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_tamper_event_clear(void)
{
  BKP->CSR = 0;
  bkp_tamper_event_clear();
  ASSERT_EQ(BKP->CSR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  BKP->CSR = ~(1u << 0);
  bkp_tamper_event_clear();
  ASSERT_EQ(BKP->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_tamper_interrupt_clear(void)
{
  BKP->CSR = 0;
  bkp_tamper_interrupt_clear();
  ASSERT_EQ(BKP->CSR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  BKP->CSR = ~(1u << 1);
  bkp_tamper_interrupt_clear();
  ASSERT_EQ(BKP->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_tamper_interrupt(void)
{
  BKP->CSR = 0;
  bkp_tamper_interrupt_enable();
  ASSERT_EQ(BKP->CSR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  BKP->CSR = ~(1u << 2);
  bkp_tamper_interrupt_enable();
  ASSERT_EQ(BKP->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  BKP->CSR = (1u << 2);
  bkp_tamper_interrupt_disable();
  ASSERT_EQ(BKP->CSR, 0);
  ASSERT_FALSE(execution_halted());

  BKP->CSR = 0xffffffff;
  bkp_tamper_interrupt_disable();
  ASSERT_EQ(BKP->CSR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_is_tamper_event_flag_set(void)
{
  u32 res;

  // read_bit
  BKP->CSR = 0;
  res = bkp_is_tamper_event_flag_set();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->CSR = ~(1u << 8);
  res = bkp_is_tamper_event_flag_set();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->CSR = 1u << 8;
  res = bkp_is_tamper_event_flag_set();
  ASSERT_EQ(res, 1u << 8);
  ASSERT_FALSE(execution_halted());

}

void
test_bkp_is_tamper_interrupt_flag_set(void)
{
  u32 res;

  // read_bit
  BKP->CSR = 0;
  res = bkp_is_tamper_interrupt_flag_set();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->CSR = ~(1u << 9);
  res = bkp_is_tamper_interrupt_flag_set();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  BKP->CSR = 1u << 9;
  res = bkp_is_tamper_interrupt_flag_set();
  ASSERT_EQ(res, 1u << 9);
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_bkp_data_write),
    TEST_FUNC(test_bkp_data_read),
    TEST_FUNC(test_bkp_set_rtc_calibration_value),
    TEST_FUNC(test_bkp_rtc_calib_clock_output),
    TEST_FUNC(test_bkp_rtc_signal_output),
    TEST_FUNC(test_bkp_set_rtc_output_signal),
    TEST_FUNC(test_bkp_tamper_pin),
    TEST_FUNC(test_bkp_set_tamper_pin_active_level),
    TEST_FUNC(test_bkp_tamper_event_clear),
    TEST_FUNC(test_bkp_tamper_interrupt_clear),
    TEST_FUNC(test_bkp_tamper_interrupt),
    TEST_FUNC(test_bkp_is_tamper_event_flag_set),
    TEST_FUNC(test_bkp_is_tamper_interrupt_flag_set),
  };

  return TESTS_RUN(tests);
}
