#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/rtc/rtc_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  RTC = (struct rtc_registers_map*) membuf;
}

void
test_rtc_interrupt(void)
{
  RTC->CRH = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_SECOND);
  ASSERT_EQ(RTC->CRH, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CRH = ~(1u << 0);
  rtc_interrupt_enable(RTC_INTERRUPT_SECOND);
  ASSERT_EQ(RTC->CRH, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CRH = (1u << 0);
  rtc_interrupt_disable(RTC_INTERRUPT_SECOND);
  ASSERT_EQ(RTC->CRH, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRH = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_SECOND);
  ASSERT_EQ(RTC->CRH, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->CRH = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_ALARM);
  ASSERT_EQ(RTC->CRH, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->CRH = ~(1u << 1);
  rtc_interrupt_enable(RTC_INTERRUPT_ALARM);
  ASSERT_EQ(RTC->CRH, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CRH = (1u << 1);
  rtc_interrupt_disable(RTC_INTERRUPT_ALARM);
  ASSERT_EQ(RTC->CRH, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRH = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_ALARM);
  ASSERT_EQ(RTC->CRH, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  RTC->CRH = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_OVERFLOW);
  ASSERT_EQ(RTC->CRH, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->CRH = ~(1u << 2);
  rtc_interrupt_enable(RTC_INTERRUPT_OVERFLOW);
  ASSERT_EQ(RTC->CRH, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CRH = (1u << 2);
  rtc_interrupt_disable(RTC_INTERRUPT_OVERFLOW);
  ASSERT_EQ(RTC->CRH, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRH = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_OVERFLOW);
  ASSERT_EQ(RTC->CRH, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


}

void
test_rtc_is_flag_set(void)
{
  u32 res;

  RTC->CRL = 0;
  res = rtc_is_flag_set(RTC_FLAG_SECOND);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = (1u << 0);
  res = rtc_is_flag_set(RTC_FLAG_SECOND);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CRL = ~(1u << 0);
  res = rtc_is_flag_set(RTC_FLAG_SECOND);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_SECOND);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = 0;
  res = rtc_is_flag_set(RTC_FLAG_ALARM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = (1u << 1);
  res = rtc_is_flag_set(RTC_FLAG_ALARM);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->CRL = ~(1u << 1);
  res = rtc_is_flag_set(RTC_FLAG_ALARM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_ALARM);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = 0;
  res = rtc_is_flag_set(RTC_FLAG_OVERFLOW);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = (1u << 2);
  res = rtc_is_flag_set(RTC_FLAG_OVERFLOW);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->CRL = ~(1u << 2);
  res = rtc_is_flag_set(RTC_FLAG_OVERFLOW);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_OVERFLOW);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = 0;
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = (1u << 3);
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RTC->CRL = ~(1u << 3);
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = 0;
  res = rtc_is_flag_set(RTC_FLAG_CONFIGURATION);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = (1u << 4);
  res = rtc_is_flag_set(RTC_FLAG_CONFIGURATION);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->CRL = ~(1u << 4);
  res = rtc_is_flag_set(RTC_FLAG_CONFIGURATION);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_CONFIGURATION);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = 0;
  res = rtc_is_flag_set(RTC_FLAG_WRITE_IDLE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = (1u << 5);
  res = rtc_is_flag_set(RTC_FLAG_WRITE_IDLE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RTC->CRL = ~(1u << 5);
  res = rtc_is_flag_set(RTC_FLAG_WRITE_IDLE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_WRITE_IDLE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_rtc_flag_clear(void)
{
  RTC->CRL = (1u << 0);
  rtc_flag_clear(RTC_FLAG_SECOND);
  ASSERT_EQ(RTC->CRL, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_SECOND);
  ASSERT_EQ(RTC->CRL, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = (1u << 1);
  rtc_flag_clear(RTC_FLAG_ALARM);
  ASSERT_EQ(RTC->CRL, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_ALARM);
  ASSERT_EQ(RTC->CRL, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = (1u << 2);
  rtc_flag_clear(RTC_FLAG_OVERFLOW);
  ASSERT_EQ(RTC->CRL, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_OVERFLOW);
  ASSERT_EQ(RTC->CRL, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = (1u << 3);
  rtc_flag_clear(RTC_FLAG_SYNC);
  ASSERT_EQ(RTC->CRL, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_SYNC);
  ASSERT_EQ(RTC->CRL, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  RTC->CRL = (1u << 4);
  rtc_flag_clear(RTC_FLAG_CONFIGURATION);
  ASSERT_EQ(RTC->CRL, (1u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->CRL = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_CONFIGURATION);
  ASSERT_EQ(RTC->CRL, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RTC->CRL = (1u << 5);
  rtc_flag_clear(RTC_FLAG_WRITE_IDLE);
  ASSERT_EQ(RTC->CRL, (1u << 5));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->CRL = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_WRITE_IDLE);
  ASSERT_EQ(RTC->CRL, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rtc_config(void)
{
  RTC->CRL = 0;
  rtc_config_enable();
  ASSERT_EQ(RTC->CRL, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->CRL = ~(1u << 4);
  rtc_config_enable();
  ASSERT_EQ(RTC->CRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = (1u << 4);
  rtc_config_disable();
  ASSERT_EQ(RTC->CRL, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CRL = 0xffffffff;
  rtc_config_disable();
  ASSERT_EQ(RTC->CRL, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'fn_set_value (TODO)' (rtc_set_prescaler)
// └─Skipping type 'fn_get (TODO)' (rtc_get_prescaler_divider)
// └─Skipping type 'fn_set_value (TODO)' (rtc_set_counter)
// └─Skipping type 'fn_set_value (TODO)' (rtc_set_alarm)
int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_rtc_interrupt),
    TEST_FUNC(test_rtc_is_flag_set),
    TEST_FUNC(test_rtc_flag_clear),
    TEST_FUNC(test_rtc_config),
  };

  return TESTS_RUN(tests);
}
