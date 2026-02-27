#include "synapse/common/util/common.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/rcc.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
}

void
gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_2MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );
}

int
main(void)
{
  rcc_setup();
  gpio_setup();

  while (1)
  {
    gpio_pin_toggle(GPIOC, GPIO13);
    syn_delay_nop(750000);
  }

  return 0;
}

