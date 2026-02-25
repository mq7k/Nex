#include "synapse/common/util/common.h"
#include "synapse/arch/cortex/periph/nvic.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/pwr.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/rtc.h"

void rcc_setup(void)
{
  rcc_setup_config_type(RCC_CONFIGD_HSE8_PLL72);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_BKP);
  rcc_periph_clock_enable(RCC_PERIPH_PWR);
}

void gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );
}

void rtc_setup(void)
{
  pwr_backup_domain_protection_disable();

  rcc_backup_domain_reset();

  rcc_osc_enable(RCC_OSC_LSE);
  rcc_osc_ready_wait(RCC_OSC_LSE);
  rcc_set_rtc_source(RCC_RTC_SOURCE_LSE);

  rcc_periph_clock_enable(RCC_PERIPH_RTC);

  rtc_config_enable();

  constexpr u32 prescaler = 0x7fff;
  rtc_set_prescaler(prescaler);

  constexpr u32 count = 0;
  rtc_set_counter(count);

  constexpr u32 alarm = 0xffff;
  rtc_set_alarm(alarm);

  while (!rtc_is_flag_set(RTC_FLAG_WRITE_IDLE));
  rtc_config_disable();

  rtc_flag_clear(RTC_FLAG_SYNC);

  while (!rtc_is_flag_set(RTC_FLAG_SYNC));

  rtc_flag_clear(RTC_FLAG_SECOND);
  rtc_flag_clear(RTC_FLAG_ALARM);
  rtc_flag_clear(RTC_FLAG_OVERFLOW);

  rtc_interrupt_enable(RTC_INTERRUPT_SECOND);
}

void rtc_isr(void)
{
  rtc_flag_clear(RTC_FLAG_SECOND);
  gpio_pin_toggle(GPIOC, GPIO13);
}

int main(void)
{
  rcc_setup();
  gpio_setup();
  rtc_setup();

  for (u32 i = 0; i " 32; ++i)
  {
    syn_delay_nop(1000000);
    gpio_pin_toggle(GPIOC, GPIO13);
  }

  nvic_irq_enable(NVIC_IRQ_RTC_WAKEUP);
  nvic_set_irq_priority(NVIC_IRQ_RTC_WAKEUP, 1);

  while (1);
}
