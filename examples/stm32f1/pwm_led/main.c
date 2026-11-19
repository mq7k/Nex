#include "synapse/common/common.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "synapse/soc/stm32/periph/rcc.h"
#include "synapse/soc/stm32/periph/gpio.h"

#if defined(STM32_TIM1)
#define TIM TIM1
#define TIM_PERIPH RCC_PERIPH_TIM1
#elif defined(STM32_TIM3)
#define TIM TIM3
#define TIM_PERIPH RCC_PERIPH_TIM3
#endif

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
  rcc_periph_clock_enable(TIM_PERIPH);
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
    GPIOA,
    GPIO9,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );
}

void
timer_setup(void)
{
  constexpr u32 prescaler = 27;
  constexpr u32 auto_reload = 255;

  tim_oc_preload_enable(TIM, TIM_CHANNEL1);
  tim_auto_reload_preload_enable(TIM);

  tim_set_clock_division(TIM, TIM_CLOCK_DIVISION_NODIV);
  tim_set_center_aligned_mode(TIM, TIM_CENTER_ALIGNED_MODE_EDGE);
  tim_set_counter_direction(TIM, TIM_COUNTER_DIRECTION_UP);
  tim_set_oc_mode(TIM, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  tim_set_oc_mode(TIM, TIM_CHANNEL2, TIM_OC_MODE_PWM1);
  tim_cc_channel_enable(TIM, TIM_CHANNEL4);
  tim_cc_channel_enable(TIM, TIM_CHANNEL2);
  tim_set_prescaler(TIM, prescaler);
  tim_set_autoreload_value(TIM, auto_reload);
  tim_main_output_enable(TIM);
  tim_counter_enable(TIM);
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  timer_setup();

  u32 value = 0;
  u32 dir = 1;

  while (1)
  {
    syn_delay_nop(30000);

    value += dir;
    if (value == 255 || value == 0)
    {
      dir = -dir;
    }

    tim_set_cc_value(TIM, TIM_CHANNEL4, value);
    tim_set_cc_value(TIM, TIM_CHANNEL2, 255 - value);
  }
}
