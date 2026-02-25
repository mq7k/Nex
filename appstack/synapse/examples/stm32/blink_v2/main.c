#include "synapse/common/util/common.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"

void
rcc_setup(void)
{  
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_MEDIUM
  );

  gpio_set_port_pins_output_type(
    GPIOC,
    GPIO13,
    GPIO_OUTPUT_TYPE_PUSHPULL
  );
}

int
main(void)
{
  rcc_setup();
  gpio_setup();

  while (1)
  {
    syn_delay_nop(400000);
    gpio_pin_toggle(GPIOC, GPIO13);
  }
}
