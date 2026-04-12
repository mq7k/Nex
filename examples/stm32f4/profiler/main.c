#include "libcom/types.h"
#include "system/profiler/profiler.h"
#include "synapse/common/common.h"
#include "libcom/unit.h"
#include "synapse/cpu/cortex/periph/nvic.h"
#include "synapse/cpu/cortex/common/sys.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "synapse/soc/stm32/periph/rcc.h"
#include "synapse/soc/stm32/periph/gpio.h"
#include "synapse/soc/stm32/periph/usart.h"
#include "system/time/backend/stm32_tim.h"
#include "system/time/time.h"
#include "system/time/dispatcher.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_TIM2);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOA,
    GPIO9 | GPIO10,
    GPIO_MODE_ALTFN,
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
  usart_receiver_enable(USART1);
  usart_parity_control_disable(USART1);
  usart_cts_disable(USART1);
  usart_rts_disable(USART1);
  usart_enable(USART1);
}

void
timer_setup(void)
{
  tim_set_prescaler(TIM2, 0);
  tim_set_clock_division(TIM2, TIM_CLOCK_DIVISION_NODIV);
  tim_oc_preload_enable(TIM2, TIM_CHANNEL4);
  tim_set_counter_direction(TIM2, TIM_COUNTER_DIRECTION_UP);
  tim_cc_channel_enable(TIM2, TIM_CHANNEL4);
  tim_counter_enable(TIM2);
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  timer_setup();
  usart_setup();

  struct system_stm32_timer_backend_ctx time_ctx = {
    .tim = TIM2,
    .value_width_bits = 32 
  };

  struct sys_coarse_time_backend time_backend = {
    .vtable = system_get_coarse_time_backend(SYSTEM_COARSE_TIME_BACKEND_STM32_TIM),
    .ctx = &time_ctx
  };

  system_set_coarse_time_source(&time_backend);

  usart_send_strfln(USART1, "\n");
  usart_send_strfln(USART1, "Starting profiler...");

  struct profiler_section nop_section = {};

  u32 start = system_get_coarse_time();
  syn_delay_nop(1000000);

  u32 end = system_get_coarse_time();
  profiler_section_update(&nop_section, (end - start));

  usart_send_strfln(USART1, "call_count: %u", nop_section.call_count);
  usart_send_strfln(USART1, "total_ticks: %L", nop_section.total_ticks);
  usart_send_strfln(USART1, "min_ticks: %L", nop_section.min_ticks);
  usart_send_strfln(USART1, "max_ticks: %L", nop_section.max_ticks);
  usart_send_strfln(USART1, "avg_ticks: %L", nop_section.total_ticks / nop_section.call_count);

  while (1);
}
