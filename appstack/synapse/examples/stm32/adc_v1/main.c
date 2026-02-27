#include <synapse/stm32/periph/rcc.h>
#include <synapse/stm32/periph/gpio.h>
#include <synapse/stm32/periph/adc.h>

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
}

int main() {}

// static void
// adc_setup(void)
// {
// }
