#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/wwdg.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_WWDG);
}

void
gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );
}

void
wwdg_setup(void)
{
  wwdg_set_prescaler(WWDG_PRESCALER_DIV8);
  wwdg_set_upper_threshold(0x7f);
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  wwdg_setup();

  for (u32 i = 0; i < 10; ++i)
  {
    gpio_pin_toggle(GPIOC, GPIO13);
    syn_delay_nop(1000000);
  }

  gpio_set_pin_high(GPIOC, GPIO13);
  syn_delay_nop(4000000);

  wwdg_start();
  while (1);
}
