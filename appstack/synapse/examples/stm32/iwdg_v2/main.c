#include "synapse/common/util/common.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/iwdg.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);

  rcc_osc_enable(RCC_OSC_LSI);
  WAIT_UNTIL(rcc_osc_is_ready(RCC_OSC_LSI));
}

void
gpio_setup(void)
{
  gpio_setup_port(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );
}

void
iwdg_setup(void)
{
  iwdg_write_unlock();

  WAIT_UNTIL(iwdg_is_flag_set(IWDG_FLAG_COUNTER_UPDATE) == 0);
  iwdg_set_reload_value(5);

  WAIT_UNTIL(iwdg_is_flag_set(IWDG_FLAG_PRESCALER_UPDATE) == 0);
  iwdg_set_prescaler(IWDG_PRESCALER_DIV256);
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  iwdg_setup();

  for (u32 i = 0; i < 10; ++i)
  {
    gpio_pin_toggle(GPIOC, GPIO13);
    syn_delay_nop(1000000);
  }

  gpio_set_pin_high(GPIOC, GPIO13);

  iwdg_start();
  while (1);
}

