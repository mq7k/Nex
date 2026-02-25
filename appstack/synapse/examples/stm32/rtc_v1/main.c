#include "synapse/common/util/common.h"
#include "libcom/unit.h"
#include "libcom/types.h"
#include "synapse/stm32/periph/rtc.h"
#include "synapse/stm32/periph/exti.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/pwr.h"
#include "synapse/stm32/periph/usart.h"
#include "synapse/arch/cortex/periph/nvic.h"
#include "synapse/arch/cortex/common/sys.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_PWR);

  pwr_backup_domain_protection_disable();
  rcc_backup_domain_reset();

  rcc_osc_enable(RCC_OSC_LSE);
  WAIT_UNTIL(rcc_is_osc_ready(RCC_OSC_LSE));
  
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_LSE);
  rcc_periph_clock_enable(RCC_PERIPH_RTC);
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOA,
    GPIO9,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO10,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(GPIOA, GPIO9 | GPIO10, GPIO_ALTFN7);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 clock = nex_convert_freq_unit(16, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, clock, baudrate);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  usart_transmitter_enable(USART1);
  usart_parity_control_disable(USART1);
  usart_cts_disable(USART1);
  usart_rts_disable(USART1);
  usart_enable(USART1);
}

void
rtc_setup(void)
{
  pwr_backup_domain_protection_disable();

  syn_delay_nop(100000);

  rtc_unlock_write_protection();

  rtc_init_mode_enable();
  WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_INIT));

  struct rtc_prescalers prescalers;
  prescalers.async_prescaler = 127;
  prescalers.sync_prescaler = 255;
  rtc_set_prescalers(&prescalers);

  struct rtc_calendar_time time;
  time.seconds = 0;
  time.minutes = 14;
  time.hours = 14;
  rtc_set_calendar_time(&time);
  
  struct rtc_calendar_date date;
  date.date = 13;
  date.month = 8;
  date.day = RTC_WEEKDAY_WEDNESDAY;
  date.year = 2025;
  rtc_set_calendar_date(&date);

  rtc_set_time_format(RTC_TIME_FORMAT_24HOURS);

  rtc_init_mode_disable();

  rtc_alarm_disable(RTC_ALARMA);

  rtc_flag_clear(RTC_FLAG_SYNC);
  WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_SYNC));

  rtc_alarm_disable(RTC_ALARMA);

  WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE));

  struct rtc_alarm_datetime dt;
  dt.seconds = 2;
  dt.alarm_masks = RTC_ALARM_MASK_MINUTES | RTC_ALARM_MASK_HOURS | RTC_ALARM_MASK_DATE;
  WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE));
  rtc_set_alarm_time(RTC_ALARMA, &dt);

  rtc_flag_clear(RTC_FLAG_SYNC);
  WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_SYNC));
  
  syn_delay_nop(100000);

  rtc_alarm_enable(RTC_ALARMA);
  rtc_interrupt_enable(RTC_INTERRUPT_ALARMA);

  nvic_irq_enable(NVIC_IRQ_RTC_ALARM);

  exti_trigger_event_line_enable(17, EXTI_TRIGGER_EVENT_RISING);

  exti_trigger_event_line_disable(17, EXTI_TRIGGER_EVENT_FALLING);

  exti_interrupt_line_enable(17);

  exti_trigger_update_event_clear(17);
}

void
rtc_alarm_isr(void)
{
  gpio_pin_toggle(GPIOC, GPIO13);
  rtc_flag_clear(RTC_FLAG_ALARMA);

  exti_trigger_update_event_clear(17);

  cm_dsb();
  cm_isb();
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  usart_setup();
  rtc_setup();

  gpio_set_pin_low(GPIOC, GPIO13);

  u32 cr_reg = RTC->CR;
  usart_send_strfln(USART1, "RTC->CR ALRAE bit: %u", (cr_reg >> 8) & 1);
  usart_send_strfln(USART1, "RTC->CR ALRAIE bit: %u", (cr_reg >> 12) & 1);

  while (1)
  {
    syn_delay_nop(2000000);

    struct rtc_calendar_time time;
    rtc_get_calendar_time(&time);

    struct rtc_calendar_date date;
    rtc_get_calendar_date(&date);

    usart_send_strfln(
      USART1,
      "%u/%u/%u - %u:%u:%u",
      date.date, date.month, date.year,
      time.hours, time.minutes, time.seconds
    );
  }
}
