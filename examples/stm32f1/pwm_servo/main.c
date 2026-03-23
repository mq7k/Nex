#include "synapse/common/common.h"
#include "synapse/soc/stm32/periph/rcc.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "synapse/soc/stm32/periph/flash.h"
#include "synapse/soc/stm32/periph/gpio.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
}

void
gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOA,
    GPIO11,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );
}

void
timer_setup(void)
{
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_auto_reload_preload_enable(TIM1);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_center_aligned_mode(TIM1, TIM_CENTER_ALIGNED_MODE_EDGE);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_set_oc_mode(TIM1, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  tim_set_prescaler(TIM1, 7);
  tim_set_autoreload_value(TIM1, 19999);
  tim_main_output_enable(TIM1);
  tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
  tim_counter_enable(TIM1);
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  timer_setup();

  u32 value = 1000;
  u32 dir = 10;

  tim_set_cc_value(TIM1, TIM_CHANNEL4, value);

  while (1)
  {
    syn_delay_nop(1000);
    gpio_pin_toggle(GPIOC, GPIO13);

    value += dir;

    if (value <= 1000)
    {
      value = 1000;
      dir = -dir;
      syn_delay_nop(1000000);

    }
    else if (value >= 2000)
    {
      value = 2000;
      dir = -dir;
      syn_delay_nop(1000000);
    }

    tim_set_cc_value(TIM1, TIM_CHANNEL4, value);
  }
}
