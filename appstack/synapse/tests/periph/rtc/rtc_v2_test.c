#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/rtc/rtc_v2.h"
#include "libtest/libtest.h"

void
setup(void)
{
  RTC = (struct rtc_registers_map*) membuf;
}

// └─Skipping type 'fn_set_value (TODO)' (rtc_set_calendar_time)
// └─Skipping type 'fn_set_value (TODO)' (rtc_set_calendar_date)
// └─Skipping type 'fn_get (TODO)' (rtc_get_calendar_time)
// └─Skipping type 'fn_get (TODO)' (rtc_get_calendar_date)
void
test_rtc_set_calendar_time_format(void)
{
  RTC->TR = 0;
  rtc_set_calendar_time_format(RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->TR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RTC->TR = ~(1u << 22);
  rtc_set_calendar_time_format(RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->TR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TR = (1u << 22);
  rtc_set_calendar_time_format(RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->TR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TR = 0xffffffff;
  rtc_set_calendar_time_format(RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->TR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_set_wakeup_clock(void)
{
  // scope=self.reg='CR', self.shift=0, self.mask='0x7', self.varsmap={'clock': 'RTC_WAKEUP_CLOCK_DIV16'}, self.value='0b000', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV16);
  ASSERT_EQ(RTC->CR, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x7u << 0);
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV16);
  ASSERT_EQ(RTC->CR, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=0, self.mask='0x7', self.varsmap={'clock': 'RTC_WAKEUP_CLOCK_DIV8'}, self.value='0b001', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV8);
  ASSERT_EQ(RTC->CR, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x7u << 0);
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV8);
  ASSERT_EQ(RTC->CR, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=0, self.mask='0x7', self.varsmap={'clock': 'RTC_WAKEUP_CLOCK_DIV4'}, self.value='0b010', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV4);
  ASSERT_EQ(RTC->CR, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x7u << 0);
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV4);
  ASSERT_EQ(RTC->CR, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=0, self.mask='0x7', self.varsmap={'clock': 'RTC_WAKEUP_CLOCK_DIV2'}, self.value='0b011', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV2);
  ASSERT_EQ(RTC->CR, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x7u << 0);
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_DIV2);
  ASSERT_EQ(RTC->CR, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=0, self.mask='0x7', self.varsmap={'clock': 'RTC_WAKEUP_CLOCK_NODIV'}, self.value='0b100', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_NODIV);
  ASSERT_EQ(RTC->CR, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x7u << 0);
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_NODIV);
  ASSERT_EQ(RTC->CR, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=0, self.mask='0x7', self.varsmap={'clock': 'RTC_WAKEUP_CLOCK_NODIV_OFFSET'}, self.value='0b110', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_NODIV_OFFSET);
  ASSERT_EQ(RTC->CR, (0b110u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x7u << 0);
  rtc_set_wakeup_clock(RTC_WAKEUP_CLOCK_NODIV_OFFSET);
  ASSERT_EQ(RTC->CR, ~(0x7u << 0) | (0b110u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_rtc_set_timestamp_event_edge(void)
{
  RTC->CR = 0;
  rtc_set_timestamp_event_edge(RTC_EVENT_EDGE_FALLING);
  ASSERT_EQ(RTC->CR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 3);
  rtc_set_timestamp_event_edge(RTC_EVENT_EDGE_FALLING);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 3);
  rtc_set_timestamp_event_edge(RTC_EVENT_EDGE_RISING);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_set_timestamp_event_edge(RTC_EVENT_EDGE_RISING);
  ASSERT_EQ(RTC->CR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_reference_clock(void)
{
  RTC->CR = 0;
  rtc_reference_clock_enable();
  ASSERT_EQ(RTC->CR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 4);
  rtc_reference_clock_enable();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 4);
  rtc_reference_clock_disable();
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_reference_clock_disable();
  ASSERT_EQ(RTC->CR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_shadow_register_bypass(void)
{
  RTC->CR = 0;
  rtc_shadow_register_bypass_enable();
  ASSERT_EQ(RTC->CR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 5);
  rtc_shadow_register_bypass_enable();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 5);
  rtc_shadow_register_bypass_disable();
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_shadow_register_bypass_disable();
  ASSERT_EQ(RTC->CR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_set_time_format(void)
{
  RTC->CR = 0;
  rtc_set_time_format(RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->CR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 6);
  rtc_set_time_format(RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 6);
  rtc_set_time_format(RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_set_time_format(RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->CR, 0xffffffff & ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_RTC_COARSE_DIGITAL_CALIB)
void
test_rtc_coarse_digital_calib(void)
{
  RTC->CR = 0;
  rtc_coarse_digital_calib_enable();
  ASSERT_EQ(RTC->CR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 7);
  rtc_coarse_digital_calib_enable();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 7);
  rtc_coarse_digital_calib_disable();
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_coarse_digital_calib_disable();
  ASSERT_EQ(RTC->CR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_rtc_alarm(void)
{
  RTC->CR = 0;
  rtc_alarm_enable(RTC_ALARMA);
  ASSERT_EQ(RTC->CR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 8);
  rtc_alarm_enable(RTC_ALARMA);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 8);
  rtc_alarm_disable(RTC_ALARMA);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_alarm_disable(RTC_ALARMA);
  ASSERT_EQ(RTC->CR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->CR = 0;
  rtc_alarm_enable(RTC_ALARMB);
  ASSERT_EQ(RTC->CR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 9);
  rtc_alarm_enable(RTC_ALARMB);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 9);
  rtc_alarm_disable(RTC_ALARMB);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_alarm_disable(RTC_ALARMB);
  ASSERT_EQ(RTC->CR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rtc_wakeup_timer(void)
{
  RTC->CR = 0;
  rtc_wakeup_timer_enable();
  ASSERT_EQ(RTC->CR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 10);
  rtc_wakeup_timer_enable();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 10);
  rtc_wakeup_timer_disable();
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_wakeup_timer_disable();
  ASSERT_EQ(RTC->CR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_timestamp(void)
{
  RTC->CR = 0;
  rtc_timestamp_enable();
  ASSERT_EQ(RTC->CR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 11);
  rtc_timestamp_enable();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 11);
  rtc_timestamp_disable();
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_timestamp_disable();
  ASSERT_EQ(RTC->CR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_interrupt(void)
{
  RTC->CR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_ALARMA);
  ASSERT_EQ(RTC->CR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 12);
  rtc_interrupt_enable(RTC_INTERRUPT_ALARMA);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 12);
  rtc_interrupt_disable(RTC_INTERRUPT_ALARMA);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_ALARMA);
  ASSERT_EQ(RTC->CR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->CR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_ALARMB);
  ASSERT_EQ(RTC->CR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 13);
  rtc_interrupt_enable(RTC_INTERRUPT_ALARMB);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 13);
  rtc_interrupt_disable(RTC_INTERRUPT_ALARMB);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_ALARMB);
  ASSERT_EQ(RTC->CR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

  RTC->CR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_WAKEUP_TIMER);
  ASSERT_EQ(RTC->CR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 14);
  rtc_interrupt_enable(RTC_INTERRUPT_WAKEUP_TIMER);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 14);
  rtc_interrupt_disable(RTC_INTERRUPT_WAKEUP_TIMER);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_WAKEUP_TIMER);
  ASSERT_EQ(RTC->CR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


  RTC->CR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TIMESTAMP);
  ASSERT_EQ(RTC->CR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 15);
  rtc_interrupt_enable(RTC_INTERRUPT_TIMESTAMP);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 15);
  rtc_interrupt_disable(RTC_INTERRUPT_TIMESTAMP);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TIMESTAMP);
  ASSERT_EQ(RTC->CR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAFCR_REG)
  RTC->TAFCR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 2);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 2);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2) && defined(STM32_RTC_TAFCR_REG)
  RTC->TAFCR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 2);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 2);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3) && defined(STM32_RTC_TAFCR_REG)
  RTC->TAFCR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 2);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 2);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPCR_REG)
  RTC->TAMPCR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 16);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 16);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2) && defined(STM32_RTC_TAMPCR_REG)
  RTC->TAMPCR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 19);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 19);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3) && defined(STM32_RTC_TAMPCR_REG)
  RTC->TAMPCR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 22);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 22);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAFCR_REG) && defined(STM32_RTC_TAMPCR_REG)
  RTC->CR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 2);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 2);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->CR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPCR_REG)
  RTC->TAMPCR = 0;
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->TAMPCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 2);
  rtc_interrupt_enable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 2);
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_interrupt_disable(RTC_INTERRUPT_TAMPER_ALL);
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

}

// └─Skipping type 'enum_set (TODO)' (rtc_set_time_offset)
void
test_rtc_daylight_time_change_save(void)
{
  RTC->CR = 0;
  rtc_daylight_time_change_save();
  ASSERT_EQ(RTC->CR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 18);
  rtc_daylight_time_change_save();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_set_calibration_output(void)
{
  RTC->CR = 0;
  rtc_set_calibration_output(RTC_CALIBRATION_OUTPUT_1HZ);
  ASSERT_EQ(RTC->CR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 19);
  rtc_set_calibration_output(RTC_CALIBRATION_OUTPUT_1HZ);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 19);
  rtc_set_calibration_output(RTC_CALIBRATION_OUTPUT_512HZ);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_set_calibration_output(RTC_CALIBRATION_OUTPUT_512HZ);
  ASSERT_EQ(RTC->CR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_set_alarm_output_polarity(void)
{
  RTC->CR = 0;
  rtc_set_alarm_output_polarity(RTC_ALARM_OUTPUT_POLARITY_LOW);
  ASSERT_EQ(RTC->CR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 20);
  rtc_set_alarm_output_polarity(RTC_ALARM_OUTPUT_POLARITY_LOW);
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 20);
  rtc_set_alarm_output_polarity(RTC_ALARM_OUTPUT_POLARITY_HIGH);
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_set_alarm_output_polarity(RTC_ALARM_OUTPUT_POLARITY_HIGH);
  ASSERT_EQ(RTC->CR, 0xffffffff & ~(1u << 20));
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_set_output(void)
{
  // scope=self.reg='CR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RTC_OUTPUT_OFF'}, self.value='0b00', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_output(RTC_OUTPUT_OFF);
  ASSERT_EQ(RTC->CR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x3u << 21);
  rtc_set_output(RTC_OUTPUT_OFF);
  ASSERT_EQ(RTC->CR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RTC_OUTPUT_ALARMA'}, self.value='0b01', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_output(RTC_OUTPUT_ALARMA);
  ASSERT_EQ(RTC->CR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x3u << 21);
  rtc_set_output(RTC_OUTPUT_ALARMA);
  ASSERT_EQ(RTC->CR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  // scope=self.reg='CR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RTC_OUTPUT_ALARMB'}, self.value='0b10', self.ifdef=['STM32_RTC_ALARMB'], self.halt=False
  RTC->CR = 0;
  rtc_set_output(RTC_OUTPUT_ALARMB);
  ASSERT_EQ(RTC->CR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x3u << 21);
  rtc_set_output(RTC_OUTPUT_ALARMB);
  ASSERT_EQ(RTC->CR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RTC_OUTPUT_WAKEUP'}, self.value='0b11', self.ifdef=[], self.halt=False
  RTC->CR = 0;
  rtc_set_output(RTC_OUTPUT_WAKEUP);
  ASSERT_EQ(RTC->CR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(0x3u << 21);
  rtc_set_output(RTC_OUTPUT_WAKEUP);
  ASSERT_EQ(RTC->CR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


}

void
test_rtc_calibration_output(void)
{
  RTC->CR = 0;
  rtc_calibration_output_enable();
  ASSERT_EQ(RTC->CR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 23);
  rtc_calibration_output_enable();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 23);
  rtc_calibration_output_disable();
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_calibration_output_disable();
  ASSERT_EQ(RTC->CR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
void
test_rtc_internal_event_timestamp_enable(void)
{
  RTC->CR = 0;
  rtc_internal_event_timestamp_enable_enable();
  ASSERT_EQ(RTC->CR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RTC->CR = ~(1u << 24);
  rtc_internal_event_timestamp_enable_enable();
  ASSERT_EQ(RTC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CR = (1u << 24);
  rtc_internal_event_timestamp_enable_disable();
  ASSERT_EQ(RTC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CR = 0xffffffff;
  rtc_internal_event_timestamp_enable_disable();
  ASSERT_EQ(RTC->CR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_rtc_is_flag_set(void)
{
  u32 res;

  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 0);
  res = rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 0);
  res = rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_ALARMB_WRITE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 1);
  res = rtc_is_flag_set(RTC_FLAG_ALARMB_WRITE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 1);
  res = rtc_is_flag_set(RTC_FLAG_ALARMB_WRITE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_ALARMB_WRITE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER_WRITE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 2);
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER_WRITE);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 2);
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER_WRITE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER_WRITE);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_SHIFT_OP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 3);
  res = rtc_is_flag_set(RTC_FLAG_SHIFT_OP);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 3);
  res = rtc_is_flag_set(RTC_FLAG_SHIFT_OP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_SHIFT_OP);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_INIT_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 4);
  res = rtc_is_flag_set(RTC_FLAG_INIT_STATUS);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 4);
  res = rtc_is_flag_set(RTC_FLAG_INIT_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_INIT_STATUS);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 5);
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 5);
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_SYNC);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_INIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 6);
  res = rtc_is_flag_set(RTC_FLAG_INIT);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 6);
  res = rtc_is_flag_set(RTC_FLAG_INIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_INIT);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_ALARMA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 8);
  res = rtc_is_flag_set(RTC_FLAG_ALARMA);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 8);
  res = rtc_is_flag_set(RTC_FLAG_ALARMA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_ALARMA);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_ALARMB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 9);
  res = rtc_is_flag_set(RTC_FLAG_ALARMB);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 9);
  res = rtc_is_flag_set(RTC_FLAG_ALARMB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_ALARMB);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 10);
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 10);
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_WAKEUP_TIMER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 11);
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 11);
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP_OVERFLOW);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 12);
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP_OVERFLOW);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 12);
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP_OVERFLOW);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_TIMESTAMP_OVERFLOW);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_TAMPER1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 13);
  res = rtc_is_flag_set(RTC_FLAG_TAMPER1);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 13);
  res = rtc_is_flag_set(RTC_FLAG_TAMPER1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_TAMPER1);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_TAMPER2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 14);
  res = rtc_is_flag_set(RTC_FLAG_TAMPER2);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 14);
  res = rtc_is_flag_set(RTC_FLAG_TAMPER2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_TAMPER2);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_TAMPER3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 15);
  res = rtc_is_flag_set(RTC_FLAG_TAMPER3);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 15);
  res = rtc_is_flag_set(RTC_FLAG_TAMPER3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_TAMPER3);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_INTERNAL_TIMESTAMP_EVENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 17);
  res = rtc_is_flag_set(RTC_FLAG_INTERNAL_TIMESTAMP_EVENT);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 17);
  res = rtc_is_flag_set(RTC_FLAG_INTERNAL_TIMESTAMP_EVENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_INTERNAL_TIMESTAMP_EVENT);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

  RTC->ISR = 0;
  res = rtc_is_flag_set(RTC_FLAG_RECALIB_PENDING);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 16);
  res = rtc_is_flag_set(RTC_FLAG_RECALIB_PENDING);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 16);
  res = rtc_is_flag_set(RTC_FLAG_RECALIB_PENDING);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  res = rtc_is_flag_set(RTC_FLAG_RECALIB_PENDING);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_rtc_flag_clear(void)
{
  RTC->ISR = (1u << 0);
  rtc_flag_clear(RTC_FLAG_ALARMA_WRITE);
  ASSERT_EQ(RTC->ISR, (1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_ALARMA_WRITE);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_RTC_ALARMB)
  RTC->ISR = (1u << 1);
  rtc_flag_clear(RTC_FLAG_ALARMB_WRITE);
  ASSERT_EQ(RTC->ISR, (1u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_ALARMB_WRITE);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

  RTC->ISR = (1u << 2);
  rtc_flag_clear(RTC_FLAG_WAKEUP_TIMER_WRITE);
  ASSERT_EQ(RTC->ISR, (1u << 2));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_WAKEUP_TIMER_WRITE);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RTC->ISR = (1u << 3);
  rtc_flag_clear(RTC_FLAG_SHIFT_OP);
  ASSERT_EQ(RTC->ISR, (1u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_SHIFT_OP);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RTC->ISR = (1u << 4);
  rtc_flag_clear(RTC_FLAG_INIT_STATUS);
  ASSERT_EQ(RTC->ISR, (1u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_INIT_STATUS);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RTC->ISR = (1u << 5);
  rtc_flag_clear(RTC_FLAG_SYNC);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_SYNC);
  ASSERT_EQ(RTC->ISR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = (1u << 6);
  rtc_flag_clear(RTC_FLAG_INIT);
  ASSERT_EQ(RTC->ISR, (1u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_INIT);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RTC->ISR = (1u << 8);
  rtc_flag_clear(RTC_FLAG_ALARMA);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_ALARMA);
  ASSERT_EQ(RTC->ISR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->ISR = (1u << 9);
  rtc_flag_clear(RTC_FLAG_ALARMB);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_ALARMB);
  ASSERT_EQ(RTC->ISR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

  RTC->ISR = (1u << 10);
  rtc_flag_clear(RTC_FLAG_WAKEUP_TIMER);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_WAKEUP_TIMER);
  ASSERT_EQ(RTC->ISR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = (1u << 11);
  rtc_flag_clear(RTC_FLAG_TIMESTAMP);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_TIMESTAMP);
  ASSERT_EQ(RTC->ISR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = (1u << 12);
  rtc_flag_clear(RTC_FLAG_TIMESTAMP_OVERFLOW);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_TIMESTAMP_OVERFLOW);
  ASSERT_EQ(RTC->ISR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  RTC->ISR = (1u << 13);
  rtc_flag_clear(RTC_FLAG_TAMPER1);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_TAMPER1);
  ASSERT_EQ(RTC->ISR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  RTC->ISR = (1u << 14);
  rtc_flag_clear(RTC_FLAG_TAMPER2);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_TAMPER2);
  ASSERT_EQ(RTC->ISR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  RTC->ISR = (1u << 15);
  rtc_flag_clear(RTC_FLAG_TAMPER3);
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_TAMPER3);
  ASSERT_EQ(RTC->ISR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
  RTC->ISR = (1u << 17);
  rtc_flag_clear(RTC_FLAG_INTERNAL_TIMESTAMP_EVENT);
  ASSERT_EQ(RTC->ISR, (1u << 17));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_INTERNAL_TIMESTAMP_EVENT);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

  RTC->ISR = (1u << 16);
  rtc_flag_clear(RTC_FLAG_RECALIB_PENDING);
  ASSERT_EQ(RTC->ISR, (1u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ISR = 0xffffffff;
  rtc_flag_clear(RTC_FLAG_RECALIB_PENDING);
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rtc_init_mode(void)
{
  RTC->ISR = 0;
  rtc_init_mode_enable();
  ASSERT_EQ(RTC->ISR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RTC->ISR = ~(1u << 7);
  rtc_init_mode_enable();
  ASSERT_EQ(RTC->ISR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = (1u << 7);
  rtc_init_mode_disable();
  ASSERT_EQ(RTC->ISR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ISR = 0xffffffff;
  rtc_init_mode_disable();
  ASSERT_EQ(RTC->ISR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'fn_set_value (TODO)' (rtc_set_prescalers)
void
test_rtc_set_wakeup_auto_reload_value(void)
{
  RTC->WUTR = 0;
  rtc_set_wakeup_auto_reload_value(0);
  ASSERT_EQ(RTC->WUTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RTC->WUTR = 0xffffffff;
  rtc_set_wakeup_auto_reload_value(0);
  ASSERT_EQ(RTC->WUTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->WUTR = 0;
  rtc_set_wakeup_auto_reload_value(0xffff);
  ASSERT_EQ(RTC->WUTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  RTC->WUTR = 0xffffffff;
  rtc_set_wakeup_auto_reload_value(0xffff);
  ASSERT_EQ(RTC->WUTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  RTC->WUTR = 0;
  rtc_set_wakeup_auto_reload_value(0x10000);
  ASSERT_EQ(RTC->WUTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->WUTR = 0xffffffff;
  rtc_set_wakeup_auto_reload_value(0x10000);
  ASSERT_EQ(RTC->WUTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

#if defined(STM32_RTC_EXTENDED)
void
test_rtc_set_digital_calib(void)
{
  RTC->CALIBR = 0;
  rtc_set_digital_calib(0);
  ASSERT_EQ(RTC->CALIBR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RTC->CALIBR = 0xffffffff;
  rtc_set_digital_calib(0);
  ASSERT_EQ(RTC->CALIBR, ~(0x1fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->CALIBR = 0;
  rtc_set_digital_calib(0x1f);
  ASSERT_EQ(RTC->CALIBR, 0x1fu << 0);
  ASSERT_FALSE(execution_halted());

  RTC->CALIBR = 0xffffffff;
  rtc_set_digital_calib(0x1f);
  ASSERT_EQ(RTC->CALIBR, ~(0x1fu << 0) | (0x1fu << 0));
  ASSERT_FALSE(execution_halted());


  RTC->CALIBR = 0;
  rtc_set_digital_calib(0x20);
  ASSERT_EQ(RTC->CALIBR, 0x20u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->CALIBR = 0xffffffff;
  rtc_set_digital_calib(0x20);
  ASSERT_EQ(RTC->CALIBR, ~(0x1fu << 0) | (0x20u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RTC_EXTENDED)
void
test_rtc_set_digital_calib_sign(void)
{
  RTC->CALIBR = 0;
  rtc_set_digital_calib_sign(RTC_DIGITAL_CALIB_SIGN_NEGATIVE);
  ASSERT_EQ(RTC->CALIBR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RTC->CALIBR = ~(1u << 7);
  rtc_set_digital_calib_sign(RTC_DIGITAL_CALIB_SIGN_NEGATIVE);
  ASSERT_EQ(RTC->CALIBR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CALIBR = (1u << 7);
  rtc_set_digital_calib_sign(RTC_DIGITAL_CALIB_SIGN_POSITIVE);
  ASSERT_EQ(RTC->CALIBR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CALIBR = 0xffffffff;
  rtc_set_digital_calib_sign(RTC_DIGITAL_CALIB_SIGN_POSITIVE);
  ASSERT_EQ(RTC->CALIBR, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}
#endif

// └─Skipping type 'fn_set_value (TODO)' (rtc_set_alarm_time)
void
test_rtc_set_alarm_time_format(void)
{
  RTC->ALRMAR = 0;
  rtc_set_alarm_time_format(RTC_ALARMA, RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->ALRMAR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = ~(1u << 22);
  rtc_set_alarm_time_format(RTC_ALARMA, RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = (1u << 22);
  rtc_set_alarm_time_format(RTC_ALARMA, RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->ALRMAR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = 0xffffffff;
  rtc_set_alarm_time_format(RTC_ALARMA, RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBR = 0;
  rtc_set_alarm_time_format(RTC_ALARMB, RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->ALRMBR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = ~(1u << 22);
  rtc_set_alarm_time_format(RTC_ALARMB, RTC_TIME_FORMAT_12HOURS);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = (1u << 22);
  rtc_set_alarm_time_format(RTC_ALARMB, RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->ALRMBR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = 0xffffffff;
  rtc_set_alarm_time_format(RTC_ALARMB, RTC_TIME_FORMAT_24HOURS);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rtc_alarm_compare(void)
{
  RTC->ALRMAR = 0;
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMAR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = ~(1u << 7);
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = (1u << 7);
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMAR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMAR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  RTC->ALRMAR = 0;
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMAR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = ~(1u << 15);
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = (1u << 15);
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMAR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMAR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  RTC->ALRMAR = 0;
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMAR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = ~(1u << 23);
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = (1u << 23);
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMAR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMAR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());


  RTC->ALRMAR = 0;
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMAR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = ~(1u << 31);
  rtc_alarm_compare_enable(RTC_ALARMA, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = (1u << 31);
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMAR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMA, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMAR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBR = 0;
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMBR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = ~(1u << 7);
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = (1u << 7);
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMBR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_SECONDS);
  ASSERT_EQ(RTC->ALRMBR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBR = 0;
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMBR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = ~(1u << 15);
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = (1u << 15);
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMBR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_MINUTES);
  ASSERT_EQ(RTC->ALRMBR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBR = 0;
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMBR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = ~(1u << 23);
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = (1u << 23);
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMBR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_HOURS);
  ASSERT_EQ(RTC->ALRMBR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBR = 0;
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMBR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = ~(1u << 31);
  rtc_alarm_compare_enable(RTC_ALARMB, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = (1u << 31);
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMBR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = 0xffffffff;
  rtc_alarm_compare_disable(RTC_ALARMB, RTC_ALARM_COMPARE_DATE);
  ASSERT_EQ(RTC->ALRMBR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rtc_set_datetime_type(void)
{
  RTC->ALRMAR = 0;
  rtc_set_datetime_type(RTC_ALARMA, RTC_DATETIME_TYPE_WEEKDAY);
  ASSERT_EQ(RTC->ALRMAR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = ~(1u << 30);
  rtc_set_datetime_type(RTC_ALARMA, RTC_DATETIME_TYPE_WEEKDAY);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = (1u << 30);
  rtc_set_datetime_type(RTC_ALARMA, RTC_DATETIME_TYPE_DATE);
  ASSERT_EQ(RTC->ALRMAR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMAR = 0xffffffff;
  rtc_set_datetime_type(RTC_ALARMA, RTC_DATETIME_TYPE_DATE);
  ASSERT_EQ(RTC->ALRMAR, 0xffffffff & ~(1u << 30));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBR = 0;
  rtc_set_datetime_type(RTC_ALARMB, RTC_DATETIME_TYPE_WEEKDAY);
  ASSERT_EQ(RTC->ALRMBR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = ~(1u << 30);
  rtc_set_datetime_type(RTC_ALARMB, RTC_DATETIME_TYPE_WEEKDAY);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = (1u << 30);
  rtc_set_datetime_type(RTC_ALARMB, RTC_DATETIME_TYPE_DATE);
  ASSERT_EQ(RTC->ALRMBR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBR = 0xffffffff;
  rtc_set_datetime_type(RTC_ALARMB, RTC_DATETIME_TYPE_DATE);
  ASSERT_EQ(RTC->ALRMBR, 0xffffffff & ~(1u << 30));
  ASSERT_FALSE(execution_halted());

#endif

}

// └─Skipping type 'fn_call (TODO)' (rtc_unlock_write_protection)
void
test_rtc_get_async_prescaler_subsecond_value(void)
{
  u32 res;

  // read_bits
  RTC->SSR = 0;
  res = rtc_get_async_prescaler_subsecond_value();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->SSR = ~(0xffffu << 0);
  res = rtc_get_async_prescaler_subsecond_value();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->SSR = 0xffffu << 0;
  res = rtc_get_async_prescaler_subsecond_value();
  ASSERT_EQ(res, 0xffff);
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_set_subsecond_value(void)
{
  RTC->SHIFTR = 0;
  rtc_set_subsecond_value(0);
  ASSERT_EQ(RTC->SHIFTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RTC->SHIFTR = 0xffffffff;
  rtc_set_subsecond_value(0);
  ASSERT_EQ(RTC->SHIFTR, ~(0x3fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->SHIFTR = 0;
  rtc_set_subsecond_value(0x3fff);
  ASSERT_EQ(RTC->SHIFTR, 0x3fffu << 0);
  ASSERT_FALSE(execution_halted());

  RTC->SHIFTR = 0xffffffff;
  rtc_set_subsecond_value(0x3fff);
  ASSERT_EQ(RTC->SHIFTR, ~(0x3fffu << 0) | (0x3fffu << 0));
  ASSERT_FALSE(execution_halted());


  RTC->SHIFTR = 0;
  rtc_set_subsecond_value(0x4000);
  ASSERT_EQ(RTC->SHIFTR, 0x4000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->SHIFTR = 0xffffffff;
  rtc_set_subsecond_value(0x4000);
  ASSERT_EQ(RTC->SHIFTR, ~(0x3fffu << 0) | (0x4000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

// └─Skipping type 'fn_set_value (TODO)' (rtc_set_seconds_offset)
// └─Skipping type 'fn_get (TODO)' (rtc_get_timestamp_time)
// └─Skipping type 'fn_get (TODO)' (rtc_get_tamper_date)
void
test_rtc_get_timestamp_format(void)
{
  u32 res;

  // read_bit
  RTC->TSTR = 0;
  res = rtc_get_timestamp_format();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TSTR = ~(0x1u << 22);
  res = rtc_get_timestamp_format();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TSTR = 0x1u << 22;
  res = rtc_get_timestamp_format();
  ASSERT_EQ(res, 0x1u << 22);
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_get_timestamp_subsecond(void)
{
  u32 res;

  // read_bits
  RTC->TSSSR = 0;
  res = rtc_get_timestamp_subsecond();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TSSSR = ~(0xffffu << 0);
  res = rtc_get_timestamp_subsecond();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TSSSR = 0xffffu << 0;
  res = rtc_get_timestamp_subsecond();
  ASSERT_EQ(res, 0xffff);
  ASSERT_FALSE(execution_halted());

}

void
test_rtc_set_calibration_minus(void)
{
  RTC->CALR = 0;
  rtc_set_calibration_minus(0);
  ASSERT_EQ(RTC->CALR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RTC->CALR = 0xffffffff;
  rtc_set_calibration_minus(0);
  ASSERT_EQ(RTC->CALR, ~(0x1ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->CALR = 0;
  rtc_set_calibration_minus(0x1ff);
  ASSERT_EQ(RTC->CALR, 0x1ffu << 0);
  ASSERT_FALSE(execution_halted());

  RTC->CALR = 0xffffffff;
  rtc_set_calibration_minus(0x1ff);
  ASSERT_EQ(RTC->CALR, ~(0x1ffu << 0) | (0x1ffu << 0));
  ASSERT_FALSE(execution_halted());


  RTC->CALR = 0;
  rtc_set_calibration_minus(0x200);
  ASSERT_EQ(RTC->CALR, 0x200u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->CALR = 0xffffffff;
  rtc_set_calibration_minus(0x200);
  ASSERT_EQ(RTC->CALR, ~(0x1ffu << 0) | (0x200u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rtc_set_calibration_cycle_period(void)
{
  // scope=self.reg='CALR', self.shift=14, self.mask=None, self.varsmap={'period': 'RTC_CALIBRATION_CYCLE_PERIOD_8SECODNS'}, self.value=1, self.ifdef=[], self.halt=False
  RTC->CALR = 0;
  rtc_set_calibration_cycle_period(RTC_CALIBRATION_CYCLE_PERIOD_8SECODNS);
  ASSERT_EQ(RTC->CALR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RTC->CALR = ~(0u << 14);
  rtc_set_calibration_cycle_period(RTC_CALIBRATION_CYCLE_PERIOD_8SECODNS);
  ASSERT_EQ(RTC->CALR, ~(0u << 14) | (1u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CALR', self.shift=13, self.mask=None, self.varsmap={'period': 'RTC_CALIBRATION_CYCLE_PERIOD_16SECONDS'}, self.value=1, self.ifdef=[], self.halt=False
  RTC->CALR = 0;
  rtc_set_calibration_cycle_period(RTC_CALIBRATION_CYCLE_PERIOD_16SECONDS);
  ASSERT_EQ(RTC->CALR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->CALR = ~(0u << 13);
  rtc_set_calibration_cycle_period(RTC_CALIBRATION_CYCLE_PERIOD_16SECONDS);
  ASSERT_EQ(RTC->CALR, ~(0u << 13) | (1u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_rtc_increase_frequency(void)
{
  RTC->CALR = 0;
  rtc_increase_frequency_enable();
  ASSERT_EQ(RTC->CALR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RTC->CALR = ~(1u << 15);
  rtc_increase_frequency_enable();
  ASSERT_EQ(RTC->CALR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->CALR = (1u << 15);
  rtc_increase_frequency_disable();
  ASSERT_EQ(RTC->CALR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->CALR = 0xffffffff;
  rtc_increase_frequency_disable();
  ASSERT_EQ(RTC->CALR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_tamper(void)
{
  RTC->TAMPCR = 0;
  rtc_tamper_enable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 0);
  rtc_tamper_enable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 0);
  rtc_tamper_disable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_tamper_disable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  RTC->TAMPCR = 0;
  rtc_tamper_enable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 3);
  rtc_tamper_enable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 3);
  rtc_tamper_disable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_tamper_disable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  RTC->TAMPCR = 0;
  rtc_tamper_enable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 5);
  rtc_tamper_enable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 5);
  rtc_tamper_disable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_tamper_disable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_set_tamper_active_level(void)
{
  // scope=self.reg='TAMPCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW'}, self.value=0, self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAMPCR, (0u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE'}, self.value=0, self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, (0u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH'}, self.value=1, self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAMPCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE'}, self.value=1, self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAMPCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAMPCR, (0u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 4) | (0u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAMPCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, (0u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 4) | (0u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAMPCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAMPCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAMPCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAMPCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAMPCR, (0u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 6) | (0u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAMPCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, (0u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 6) | (0u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAMPCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAMPCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAMPCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAMPCR, ~(0x1u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_timestamp_on_tamper_event(void)
{
  RTC->TAMPCR = 0;
  rtc_timestamp_on_tamper_event_enable();
  ASSERT_EQ(RTC->TAMPCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 7);
  rtc_timestamp_on_tamper_event_enable();
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 7);
  rtc_timestamp_on_tamper_event_disable();
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_timestamp_on_tamper_event_disable();
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_set_tamper_sampling_frequency(void)
{
  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768'}, self.value='0b000', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768);
  ASSERT_EQ(RTC->TAMPCR, (0b000u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384'}, self.value='0b001', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384);
  ASSERT_EQ(RTC->TAMPCR, (0b001u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192'}, self.value='0b010', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192);
  ASSERT_EQ(RTC->TAMPCR, (0b010u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096'}, self.value='0b011', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096);
  ASSERT_EQ(RTC->TAMPCR, (0b011u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048'}, self.value='0b100', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048);
  ASSERT_EQ(RTC->TAMPCR, (0b100u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024'}, self.value='0b101', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024);
  ASSERT_EQ(RTC->TAMPCR, (0b101u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV512'}, self.value='0b110', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV512);
  ASSERT_EQ(RTC->TAMPCR, (0b110u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV512);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV256'}, self.value='0b111', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV256);
  ASSERT_EQ(RTC->TAMPCR, (0b111u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV256);
  ASSERT_EQ(RTC->TAMPCR, ~(0x7u << 8) | (0b111u << 8));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_set_tamper_filter_count(void)
{
  // scope=self.reg='TAMPCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_NOSKIP'}, self.value='0b00', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_NOSKIP);
  ASSERT_EQ(RTC->TAMPCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_NOSKIP);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_SKIP2'}, self.value='0b01', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP2);
  ASSERT_EQ(RTC->TAMPCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP2);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_SKIP4'}, self.value='0b10', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP4);
  ASSERT_EQ(RTC->TAMPCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP4);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_SKIP8'}, self.value='0b11', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP8);
  ASSERT_EQ(RTC->TAMPCR, (0b11u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP8);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 11) | (0b11u << 11));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_set_tamper_precharge_duration(void)
{
  // scope=self.reg='TAMPCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_1CYCLE'}, self.value='0b00', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_1CYCLE);
  ASSERT_EQ(RTC->TAMPCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_1CYCLE);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_2CYCLES'}, self.value='0b01', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_2CYCLES);
  ASSERT_EQ(RTC->TAMPCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_2CYCLES);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_4CYCLES'}, self.value='0b10', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_4CYCLES);
  ASSERT_EQ(RTC->TAMPCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_4CYCLES);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAMPCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_8CYCLES'}, self.value='0b11', self.ifdef=[], self.halt=False
  RTC->TAMPCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_8CYCLES);
  ASSERT_EQ(RTC->TAMPCR, (0b11u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_8CYCLES);
  ASSERT_EQ(RTC->TAMPCR, ~(0x3u << 13) | (0b11u << 13));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_tamper_pullup(void)
{
  RTC->TAMPCR = 0;
  rtc_tamper_pullup_enable();
  ASSERT_EQ(RTC->TAMPCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 15);
  rtc_tamper_pullup_enable();
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 15);
  rtc_tamper_pullup_disable();
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_tamper_pullup_disable();
  ASSERT_EQ(RTC->TAMPCR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RTC_TAFCR_REG)
void
test_rtc_tamper(void)
{
  RTC->TAFCR = 0;
  rtc_tamper_enable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 0);
  rtc_tamper_enable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 0);
  rtc_tamper_disable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_tamper_disable(RTC_TAMPER1);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  RTC->TAFCR = 0;
  rtc_tamper_enable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 3);
  rtc_tamper_enable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 3);
  rtc_tamper_disable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_tamper_disable(RTC_TAMPER2);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  RTC->TAFCR = 0;
  rtc_tamper_enable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 5);
  rtc_tamper_enable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 5);
  rtc_tamper_disable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_tamper_disable(RTC_TAMPER3);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_RTC_TAFCR_REG)
void
test_rtc_set_tamper_active_level(void)
{
  // scope=self.reg='TAFCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW'}, self.value=0, self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAFCR, (0u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE'}, self.value=0, self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAFCR, (0u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH'}, self.value=1, self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAFCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=1, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER1', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE'}, self.value=1, self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAFCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 1);
  rtc_set_tamper_active_level(RTC_TAMPER1, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAFCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAFCR, (0u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 4) | (0u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAFCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAFCR, (0u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 4) | (0u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAFCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER2)
  // scope=self.reg='TAFCR', self.shift=4, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER2', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER2'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 4);
  rtc_set_tamper_active_level(RTC_TAMPER2, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAFCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAFCR, (0u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 6) | (0u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAFCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE'}, self.value=0, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAFCR, (0u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 6) | (0u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAFCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAFCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  // scope=self.reg='TAFCR', self.shift=6, self.mask='0x1', self.varsmap={'tamper': 'RTC_TAMPER3', 'level': 'RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE'}, self.value=1, self.ifdef=['STM32_RTC_TAMPER3'], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAFCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x1u << 6);
  rtc_set_tamper_active_level(RTC_TAMPER3, RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE);
  ASSERT_EQ(RTC->TAFCR, ~(0x1u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_RTC_TAFCR_REG)
void
test_rtc_timestamp_on_tamper_event(void)
{
  RTC->TAFCR = 0;
  rtc_timestamp_on_tamper_event_enable();
  ASSERT_EQ(RTC->TAFCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 7);
  rtc_timestamp_on_tamper_event_enable();
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 7);
  rtc_timestamp_on_tamper_event_disable();
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_timestamp_on_tamper_event_disable();
  ASSERT_EQ(RTC->TAFCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RTC_TAFCR_REG)
void
test_rtc_set_tamper_sampling_frequency(void)
{
  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768'}, self.value='0b000', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768);
  ASSERT_EQ(RTC->TAFCR, (0b000u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384'}, self.value='0b001', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384);
  ASSERT_EQ(RTC->TAFCR, (0b001u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192'}, self.value='0b010', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192);
  ASSERT_EQ(RTC->TAFCR, (0b010u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096'}, self.value='0b011', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096);
  ASSERT_EQ(RTC->TAFCR, (0b011u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048'}, self.value='0b100', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048);
  ASSERT_EQ(RTC->TAFCR, (0b100u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024'}, self.value='0b101', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024);
  ASSERT_EQ(RTC->TAFCR, (0b101u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV512'}, self.value='0b110', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV512);
  ASSERT_EQ(RTC->TAFCR, (0b110u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV512);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=8, self.mask='0x7', self.varsmap={'frequency': 'RTC_TAMPER_SAMPLING_FREQUENCY_DIV256'}, self.value='0b111', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV256);
  ASSERT_EQ(RTC->TAFCR, (0b111u << 8));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x7u << 8);
  rtc_set_tamper_sampling_frequency(RTC_TAMPER_SAMPLING_FREQUENCY_DIV256);
  ASSERT_EQ(RTC->TAFCR, ~(0x7u << 8) | (0b111u << 8));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_TAFCR_REG)
void
test_rtc_set_tamper_filter_count(void)
{
  // scope=self.reg='TAFCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_NOSKIP'}, self.value='0b00', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_NOSKIP);
  ASSERT_EQ(RTC->TAFCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_NOSKIP);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_SKIP2'}, self.value='0b01', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP2);
  ASSERT_EQ(RTC->TAFCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP2);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_SKIP4'}, self.value='0b10', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP4);
  ASSERT_EQ(RTC->TAFCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP4);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=11, self.mask='0x3', self.varsmap={'count': 'RTC_TAMPER_FILTER_COUNT_SKIP8'}, self.value='0b11', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP8);
  ASSERT_EQ(RTC->TAFCR, (0b11u << 11));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 11);
  rtc_set_tamper_filter_count(RTC_TAMPER_FILTER_COUNT_SKIP8);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 11) | (0b11u << 11));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_TAFCR_REG)
void
test_rtc_set_tamper_precharge_duration(void)
{
  // scope=self.reg='TAFCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_1CYCLE'}, self.value='0b00', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_1CYCLE);
  ASSERT_EQ(RTC->TAFCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_1CYCLE);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_2CYCLES'}, self.value='0b01', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_2CYCLES);
  ASSERT_EQ(RTC->TAFCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_2CYCLES);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_4CYCLES'}, self.value='0b10', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_4CYCLES);
  ASSERT_EQ(RTC->TAFCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_4CYCLES);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='TAFCR', self.shift=13, self.mask='0x3', self.varsmap={'duration': 'RTC_TAMPER_PRECHARGE_DURATION_8CYCLES'}, self.value='0b11', self.ifdef=[], self.halt=False
  RTC->TAFCR = 0;
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_8CYCLES);
  ASSERT_EQ(RTC->TAFCR, (0b11u << 13));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(0x3u << 13);
  rtc_set_tamper_precharge_duration(RTC_TAMPER_PRECHARGE_DURATION_8CYCLES);
  ASSERT_EQ(RTC->TAFCR, ~(0x3u << 13) | (0b11u << 13));
  ASSERT_FALSE(execution_halted());


}
#endif

// └─Skipping type 'fn_toggle (TODO)' (rtc_tamper_pullup)
// └─Skipping type 'bienum_set (TODO, currently unused)' (rtc_set_tamper_mapping)
// └─Skipping type 'bienum_set (TODO, currently unused)' (rtc_set_timestamp_mapping)
#if defined(STM32_RTC_TAFCR_REG) && defined(STM32_RTC_GPIO_CONTROL)
void
test_rtc_set_alarm_output_pin_configuration(void)
{
  RTC->TAFCR = 0;
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC13, RTC_OUTPUT_PIN_CONFIG_PUSHPULL);
  ASSERT_EQ(RTC->TAFCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 18);
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC13, RTC_OUTPUT_PIN_CONFIG_PUSHPULL);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 18);
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC13, RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC13, RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  RTC->TAFCR = 0;
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC14, RTC_OUTPUT_PIN_CONFIG_PUSHPULL);
  ASSERT_EQ(RTC->TAFCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 20);
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC14, RTC_OUTPUT_PIN_CONFIG_PUSHPULL);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 20);
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC14, RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC14, RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff & ~(1u << 20));
  ASSERT_FALSE(execution_halted());


  RTC->TAFCR = 0;
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC15, RTC_OUTPUT_PIN_CONFIG_PUSHPULL);
  ASSERT_EQ(RTC->TAFCR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 22);
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC15, RTC_OUTPUT_PIN_CONFIG_PUSHPULL);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 22);
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC15, RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_set_alarm_output_pin_configuration(RTC_OUTPUT_PIN_PC15, RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_TAFCR_REG) && defined(STM32_RTC_GPIO_CONTROL)
void
test_rtc_force_pushpull_output(void)
{
  RTC->TAFCR = 0;
  rtc_force_pushpull_output_enable(RTC_OUTPUT_PIN_PC13);
  ASSERT_EQ(RTC->TAFCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 19);
  rtc_force_pushpull_output_enable(RTC_OUTPUT_PIN_PC13);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 19);
  rtc_force_pushpull_output_disable(RTC_OUTPUT_PIN_PC13);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_force_pushpull_output_disable(RTC_OUTPUT_PIN_PC13);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  RTC->TAFCR = 0;
  rtc_force_pushpull_output_enable(RTC_OUTPUT_PIN_PC14);
  ASSERT_EQ(RTC->TAFCR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 21);
  rtc_force_pushpull_output_enable(RTC_OUTPUT_PIN_PC14);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 21);
  rtc_force_pushpull_output_disable(RTC_OUTPUT_PIN_PC14);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_force_pushpull_output_disable(RTC_OUTPUT_PIN_PC14);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());


  RTC->TAFCR = 0;
  rtc_force_pushpull_output_enable(RTC_OUTPUT_PIN_PC15);
  ASSERT_EQ(RTC->TAFCR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 23);
  rtc_force_pushpull_output_enable(RTC_OUTPUT_PIN_PC15);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 23);
  rtc_force_pushpull_output_disable(RTC_OUTPUT_PIN_PC15);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_force_pushpull_output_disable(RTC_OUTPUT_PIN_PC15);
  ASSERT_EQ(RTC->TAFCR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_TAFCR_REG) && defined(STM32_RTC_ALARM_TYPE)
void
test_rtc_set_alarm_output_type(void)
{
  RTC->TAFCR = 0;
  rtc_set_alarm_output_type(RTC_ALARM_OUTPUT_TYPE_PUSH_PULL);
  ASSERT_EQ(RTC->TAFCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = ~(1u << 18);
  rtc_set_alarm_output_type(RTC_ALARM_OUTPUT_TYPE_PUSH_PULL);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = (1u << 18);
  rtc_set_alarm_output_type(RTC_ALARM_OUTPUT_TYPE_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAFCR = 0xffffffff;
  rtc_set_alarm_output_type(RTC_ALARM_OUTPUT_TYPE_OPEN_DRAIN);
  ASSERT_EQ(RTC->TAFCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_set_tamper_erase(void)
{
  RTC->TAMPCR = 0;
  rtc_set_tamper_erase(RTC_TAMPER1, RTC_TAMPER_ERASE_OFF);
  ASSERT_EQ(RTC->TAMPCR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 17);
  rtc_set_tamper_erase(RTC_TAMPER1, RTC_TAMPER_ERASE_OFF);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 17);
  rtc_set_tamper_erase(RTC_TAMPER1, RTC_TAMPER_ERASE_ON);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_set_tamper_erase(RTC_TAMPER1, RTC_TAMPER_ERASE_ON);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff & ~(1u << 17));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  RTC->TAMPCR = 0;
  rtc_set_tamper_erase(RTC_TAMPER2, RTC_TAMPER_ERASE_OFF);
  ASSERT_EQ(RTC->TAMPCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 20);
  rtc_set_tamper_erase(RTC_TAMPER2, RTC_TAMPER_ERASE_OFF);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 20);
  rtc_set_tamper_erase(RTC_TAMPER2, RTC_TAMPER_ERASE_ON);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_set_tamper_erase(RTC_TAMPER2, RTC_TAMPER_ERASE_ON);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff & ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  RTC->TAMPCR = 0;
  rtc_set_tamper_erase(RTC_TAMPER3, RTC_TAMPER_ERASE_OFF);
  ASSERT_EQ(RTC->TAMPCR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 23);
  rtc_set_tamper_erase(RTC_TAMPER3, RTC_TAMPER_ERASE_OFF);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 23);
  rtc_set_tamper_erase(RTC_TAMPER3, RTC_TAMPER_ERASE_ON);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_set_tamper_erase(RTC_TAMPER3, RTC_TAMPER_ERASE_ON);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff & ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_RTC_TAMPCR_REG)
void
test_rtc_set_tamper_mask(void)
{
  RTC->TAMPCR = 0;
  rtc_set_tamper_mask(RTC_TAMPER1, RTC_TAMPER_MASK_AUTO);
  ASSERT_EQ(RTC->TAMPCR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 17);
  rtc_set_tamper_mask(RTC_TAMPER1, RTC_TAMPER_MASK_AUTO);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 17);
  rtc_set_tamper_mask(RTC_TAMPER1, RTC_TAMPER_MASK_MANUAL);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_set_tamper_mask(RTC_TAMPER1, RTC_TAMPER_MASK_MANUAL);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff & ~(1u << 17));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RTC_TAMPER2)
  RTC->TAMPCR = 0;
  rtc_set_tamper_mask(RTC_TAMPER2, RTC_TAMPER_MASK_AUTO);
  ASSERT_EQ(RTC->TAMPCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 20);
  rtc_set_tamper_mask(RTC_TAMPER2, RTC_TAMPER_MASK_AUTO);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 20);
  rtc_set_tamper_mask(RTC_TAMPER2, RTC_TAMPER_MASK_MANUAL);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_set_tamper_mask(RTC_TAMPER2, RTC_TAMPER_MASK_MANUAL);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff & ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_TAMPER3)
  RTC->TAMPCR = 0;
  rtc_set_tamper_mask(RTC_TAMPER3, RTC_TAMPER_MASK_AUTO);
  ASSERT_EQ(RTC->TAMPCR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = ~(1u << 23);
  rtc_set_tamper_mask(RTC_TAMPER3, RTC_TAMPER_MASK_AUTO);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = (1u << 23);
  rtc_set_tamper_mask(RTC_TAMPER3, RTC_TAMPER_MASK_MANUAL);
  ASSERT_EQ(RTC->TAMPCR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->TAMPCR = 0xffffffff;
  rtc_set_tamper_mask(RTC_TAMPER3, RTC_TAMPER_MASK_MANUAL);
  ASSERT_EQ(RTC->TAMPCR, 0xffffffff & ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

void
test_rtc_set_alarm_subsecond_value(void)
{
  RTC->ALRMASSR = 0;
  rtc_set_alarm_subsecond_value(RTC_ALARMA, 0);
  ASSERT_EQ(RTC->ALRMASSR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMASSR = 0xffffffff;
  rtc_set_alarm_subsecond_value(RTC_ALARMA, 0);
  ASSERT_EQ(RTC->ALRMASSR, ~(0x7fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  RTC->ALRMASSR = 0;
  rtc_set_alarm_subsecond_value(RTC_ALARMA, 0x7fff);
  ASSERT_EQ(RTC->ALRMASSR, 0x7fffu << 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMASSR = 0xffffffff;
  rtc_set_alarm_subsecond_value(RTC_ALARMA, 0x7fff);
  ASSERT_EQ(RTC->ALRMASSR, ~(0x7fffu << 0) | (0x7fffu << 0));
  ASSERT_FALSE(execution_halted());


  RTC->ALRMASSR = 0;
  rtc_set_alarm_subsecond_value(RTC_ALARMA, 0x8000);
  ASSERT_EQ(RTC->ALRMASSR, 0x8000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ALRMASSR = 0xffffffff;
  rtc_set_alarm_subsecond_value(RTC_ALARMA, 0x8000);
  ASSERT_EQ(RTC->ALRMASSR, ~(0x7fffu << 0) | (0x8000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBSSR = 0;
  rtc_set_alarm_subsecond_value(RTC_ALARMB, 0);
  ASSERT_EQ(RTC->ALRMBSSR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBSSR = 0xffffffff;
  rtc_set_alarm_subsecond_value(RTC_ALARMB, 0);
  ASSERT_EQ(RTC->ALRMBSSR, ~(0x7fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBSSR = 0;
  rtc_set_alarm_subsecond_value(RTC_ALARMB, 0x7fff);
  ASSERT_EQ(RTC->ALRMBSSR, 0x7fffu << 0);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBSSR = 0xffffffff;
  rtc_set_alarm_subsecond_value(RTC_ALARMB, 0x7fff);
  ASSERT_EQ(RTC->ALRMBSSR, ~(0x7fffu << 0) | (0x7fffu << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBSSR = 0;
  rtc_set_alarm_subsecond_value(RTC_ALARMB, 0x8000);
  ASSERT_EQ(RTC->ALRMBSSR, 0x8000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ALRMBSSR = 0xffffffff;
  rtc_set_alarm_subsecond_value(RTC_ALARMB, 0x8000);
  ASSERT_EQ(RTC->ALRMBSSR, ~(0x7fffu << 0) | (0x8000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

}

void
test_rtc_set_alarm_mask_bits(void)
{
  RTC->ALRMASSR = 0;
  rtc_set_alarm_mask_bits(RTC_ALARMA, 0);
  ASSERT_EQ(RTC->ALRMASSR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMASSR = 0xffffffff;
  rtc_set_alarm_mask_bits(RTC_ALARMA, 0);
  ASSERT_EQ(RTC->ALRMASSR, ~(0xfu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  RTC->ALRMASSR = 0;
  rtc_set_alarm_mask_bits(RTC_ALARMA, 0xf);
  ASSERT_EQ(RTC->ALRMASSR, 0xfu << 24);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMASSR = 0xffffffff;
  rtc_set_alarm_mask_bits(RTC_ALARMA, 0xf);
  ASSERT_EQ(RTC->ALRMASSR, ~(0xfu << 24) | (0xfu << 24));
  ASSERT_FALSE(execution_halted());


  RTC->ALRMASSR = 0;
  rtc_set_alarm_mask_bits(RTC_ALARMA, 0x10);
  ASSERT_EQ(RTC->ALRMASSR, 0x10u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ALRMASSR = 0xffffffff;
  rtc_set_alarm_mask_bits(RTC_ALARMA, 0x10);
  ASSERT_EQ(RTC->ALRMASSR, ~(0xfu << 24) | (0x10u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBSSR = 0;
  rtc_set_alarm_mask_bits(RTC_ALARMB, 0);
  ASSERT_EQ(RTC->ALRMBSSR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBSSR = 0xffffffff;
  rtc_set_alarm_mask_bits(RTC_ALARMB, 0);
  ASSERT_EQ(RTC->ALRMBSSR, ~(0xfu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBSSR = 0;
  rtc_set_alarm_mask_bits(RTC_ALARMB, 0xf);
  ASSERT_EQ(RTC->ALRMBSSR, 0xfu << 24);
  ASSERT_FALSE(execution_halted());

  RTC->ALRMBSSR = 0xffffffff;
  rtc_set_alarm_mask_bits(RTC_ALARMB, 0xf);
  ASSERT_EQ(RTC->ALRMBSSR, ~(0xfu << 24) | (0xfu << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RTC_ALARMB)
  RTC->ALRMBSSR = 0;
  rtc_set_alarm_mask_bits(RTC_ALARMB, 0x10);
  ASSERT_EQ(RTC->ALRMBSSR, 0x10u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RTC->ALRMBSSR = 0xffffffff;
  rtc_set_alarm_mask_bits(RTC_ALARMB, 0x10);
  ASSERT_EQ(RTC->ALRMBSSR, ~(0xfu << 24) | (0x10u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

}

#if defined(STM32_RTC_OR)
void
test_rtc_set_timestamp_mapping(void)
{
  // scope=self.reg='OR', self.shift=1, self.mask='0x3', self.varsmap={'mapping': 'RTC_TIMESTAMP_MAPPING_PC13'}, self.value='0b00', self.ifdef=[], self.halt=False
  RTC->OR = 0;
  rtc_set_timestamp_mapping(RTC_TIMESTAMP_MAPPING_PC13);
  ASSERT_EQ(RTC->OR, (0b00u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->OR = ~(0x3u << 1);
  rtc_set_timestamp_mapping(RTC_TIMESTAMP_MAPPING_PC13);
  ASSERT_EQ(RTC->OR, ~(0x3u << 1) | (0b00u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OR', self.shift=1, self.mask='0x3', self.varsmap={'mapping': 'RTC_TIMESTAMP_MAPPING_PI8'}, self.value='0b01', self.ifdef=[], self.halt=False
  RTC->OR = 0;
  rtc_set_timestamp_mapping(RTC_TIMESTAMP_MAPPING_PI8);
  ASSERT_EQ(RTC->OR, (0b01u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->OR = ~(0x3u << 1);
  rtc_set_timestamp_mapping(RTC_TIMESTAMP_MAPPING_PI8);
  ASSERT_EQ(RTC->OR, ~(0x3u << 1) | (0b01u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OR', self.shift=1, self.mask='0x3', self.varsmap={'mapping': 'RTC_TIMESTAMP_MAPPING_PC1'}, self.value='0b10', self.ifdef=[], self.halt=False
  RTC->OR = 0;
  rtc_set_timestamp_mapping(RTC_TIMESTAMP_MAPPING_PC1);
  ASSERT_EQ(RTC->OR, (0b10u << 1));
  ASSERT_FALSE(execution_halted());

  RTC->OR = ~(0x3u << 1);
  rtc_set_timestamp_mapping(RTC_TIMESTAMP_MAPPING_PC1);
  ASSERT_EQ(RTC->OR, ~(0x3u << 1) | (0b10u << 1));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RTC_OR)
void
test_rtc_set_alarm_type(void)
{
  RTC->OR = 0;
  rtc_set_alarm_type(RTC_ALARM_TYPE_PUSH_PULL);
  ASSERT_EQ(RTC->OR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RTC->OR = ~(1u << 3);
  rtc_set_alarm_type(RTC_ALARM_TYPE_PUSH_PULL);
  ASSERT_EQ(RTC->OR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RTC->OR = (1u << 3);
  rtc_set_alarm_type(RTC_ALARM_TYPE_OPEN_DRAIN);
  ASSERT_EQ(RTC->OR, 0);
  ASSERT_FALSE(execution_halted());

  RTC->OR = 0xffffffff;
  rtc_set_alarm_type(RTC_ALARM_TYPE_OPEN_DRAIN);
  ASSERT_EQ(RTC->OR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}
#endif

// └─Skipping type 'fn_set_value (TODO)' (rtc_backup_data_write)
// └─Skipping type 'fn_get (TODO)' (rtc_backup_data_read)
int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_rtc_set_calendar_time_format),
    TEST_FUNC(test_rtc_set_wakeup_clock),
    TEST_FUNC(test_rtc_set_timestamp_event_edge),
    TEST_FUNC(test_rtc_reference_clock),
    TEST_FUNC(test_rtc_shadow_register_bypass),
    TEST_FUNC(test_rtc_set_time_format),
#if defined(STM32_RTC_COARSE_DIGITAL_CALIB)
    TEST_FUNC(test_rtc_coarse_digital_calib),
#endif
    TEST_FUNC(test_rtc_alarm),
    TEST_FUNC(test_rtc_wakeup_timer),
    TEST_FUNC(test_rtc_timestamp),
    TEST_FUNC(test_rtc_interrupt),
    TEST_FUNC(test_rtc_daylight_time_change_save),
    TEST_FUNC(test_rtc_set_calibration_output),
    TEST_FUNC(test_rtc_set_alarm_output_polarity),
    TEST_FUNC(test_rtc_set_output),
    TEST_FUNC(test_rtc_calibration_output),
#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
    TEST_FUNC(test_rtc_internal_event_timestamp_enable),
#endif
    TEST_FUNC(test_rtc_is_flag_set),
    TEST_FUNC(test_rtc_flag_clear),
    TEST_FUNC(test_rtc_init_mode),
    TEST_FUNC(test_rtc_set_wakeup_auto_reload_value),
#if defined(STM32_RTC_EXTENDED)
    TEST_FUNC(test_rtc_set_digital_calib),
#endif
#if defined(STM32_RTC_EXTENDED)
    TEST_FUNC(test_rtc_set_digital_calib_sign),
#endif
    TEST_FUNC(test_rtc_set_alarm_time_format),
    TEST_FUNC(test_rtc_alarm_compare),
    TEST_FUNC(test_rtc_set_datetime_type),
    TEST_FUNC(test_rtc_get_async_prescaler_subsecond_value),
    TEST_FUNC(test_rtc_set_subsecond_value),
    TEST_FUNC(test_rtc_get_timestamp_format),
    TEST_FUNC(test_rtc_get_timestamp_subsecond),
    TEST_FUNC(test_rtc_set_calibration_minus),
    TEST_FUNC(test_rtc_set_calibration_cycle_period),
    TEST_FUNC(test_rtc_increase_frequency),
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_tamper),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_set_tamper_active_level),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_timestamp_on_tamper_event),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_set_tamper_sampling_frequency),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_set_tamper_filter_count),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_set_tamper_precharge_duration),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_tamper_pullup),
#endif
#if defined(STM32_RTC_TAFCR_REG)
    TEST_FUNC(test_rtc_tamper),
#endif
#if defined(STM32_RTC_TAFCR_REG)
    TEST_FUNC(test_rtc_set_tamper_active_level),
#endif
#if defined(STM32_RTC_TAFCR_REG)
    TEST_FUNC(test_rtc_timestamp_on_tamper_event),
#endif
#if defined(STM32_RTC_TAFCR_REG)
    TEST_FUNC(test_rtc_set_tamper_sampling_frequency),
#endif
#if defined(STM32_RTC_TAFCR_REG)
    TEST_FUNC(test_rtc_set_tamper_filter_count),
#endif
#if defined(STM32_RTC_TAFCR_REG)
    TEST_FUNC(test_rtc_set_tamper_precharge_duration),
#endif
#if defined(STM32_RTC_TAFCR_REG) && defined(STM32_RTC_GPIO_CONTROL)
    TEST_FUNC(test_rtc_set_alarm_output_pin_configuration),
#endif
#if defined(STM32_RTC_TAFCR_REG) && defined(STM32_RTC_GPIO_CONTROL)
    TEST_FUNC(test_rtc_force_pushpull_output),
#endif
#if defined(STM32_RTC_TAFCR_REG) && defined(STM32_RTC_ALARM_TYPE)
    TEST_FUNC(test_rtc_set_alarm_output_type),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_set_tamper_erase),
#endif
#if defined(STM32_RTC_TAMPCR_REG)
    TEST_FUNC(test_rtc_set_tamper_mask),
#endif
    TEST_FUNC(test_rtc_set_alarm_subsecond_value),
    TEST_FUNC(test_rtc_set_alarm_mask_bits),
#if defined(STM32_RTC_OR)
    TEST_FUNC(test_rtc_set_timestamp_mapping),
#endif
#if defined(STM32_RTC_OR)
    TEST_FUNC(test_rtc_set_alarm_type),
#endif
  };

  return TESTS_RUN(tests);
}
