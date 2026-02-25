#include "libcom/types.h"
#include "system/profiler/profiler.h"
#include "synapse/common/util/common.h"
#include "libcom/unit.h"
#include "synapse/arch/cortex/periph/nvic.h"
#include "synapse/arch/cortex/common/sys.h"
#include "synapse/stm32/periph/tim.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/usart.h"
#include "system/time/backend/stm32_tim.h"
#include "system/time/time.h"
#include "system/time/wiring/dispatcher.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);

  // TIM1
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);

  // TIM2
  // rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  
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
  const u32 clock = convert_freq_unit(16, FREQ_UNIT_MHz, FREQ_UNIT_Hz);
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
  // TIM1
  tim_set_prescaler(TIM1, 0);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM1, 0xffff);
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
  tim_interrupt_enable(TIM1, TIM_INTERRUPT_UPDATE);
  tim_counter_enable(TIM1);

  // TIM2
  // tim_set_prescaler(TIM2, 0);
  // tim_set_clock_division(TIM2, TIM_CLOCK_DIVISION_NODIV);
  // tim_set_autoreload_value(TIM2, 0xffff);
  // tim_oc_preload_enable(TIM2, TIM_CHANNEL4);
  // tim_set_counter_direction(TIM2, TIM_COUNTER_DIRECTION_UP);
  // tim_cc_channel_enable(TIM2, TIM_CHANNEL4);
  // tim_interrupt_enable(TIM2, TIM_INTERRUPT_UPDATE);
  // tim_counter_enable(TIM2);
}

void
nvic_setup(void)
{
  nvic_irq_enable(NVIC_IRQ_TIM2);
}

// TIM1
void
tim1_up_isr(void)
{
  system_time_handle_overflow();
  nvic_clear_pending_irq(NVIC_IRQ_TIM1_UPDATE_TIM10);
  tim_flag_clear(TIM1, TIM_FLAG_UPDATE);
}

// TIM2
// void
// tim2_isr(void)
// {
//   system_time_handle_overflow();
//   nvic_clear_pending_irq(NVIC_IRQ_TIM2);
//   tim_flag_clear(TIM2, TIM_FLAG_UPDATE);
// }

int
main(void)
{
  rcc_setup();
  gpio_setup();
  timer_setup();
  usart_setup();
  nvic_setup();

  // TIM1
  struct system_stm32_timer_backend_ctx ctx = {
    .tim = TIM1,
  };

  // TIM2
  // struct system_stm32_timer_backend_ctx ctx = {
  //   .tim = TIM2,
  // };

  struct sys_time_backend backend = {
    .vtable = system_get_time_backend_vtable(SYSTEM_TIME_BACKEND_STM32_TIM),
    .ctx = &ctx
  };

  system_set_time_source(&backend);

  usart_send_strfln(USART1, "\n");
  usart_send_strfln(USART1, "Starting profiler...");

  struct profiler_section nop_section = {};

  u64 start = system_get_time();
  syn_delay_nop(1000000);

  // 1s delay.
  // while (start + 16'000'000u > system_get_time());

  u64 end = system_get_time();
  profiler_section_update(&nop_section, (end - start));

  usart_send_strfln(USART1, "call_count: %u", nop_section.call_count);
  usart_send_strfln(USART1, "total_ticks: %L", nop_section.total_ticks);
  usart_send_strfln(USART1, "min_ticks: %L", nop_section.min_ticks);
  usart_send_strfln(USART1, "max_ticks: %L", nop_section.max_ticks);
  usart_send_strfln(USART1, "avg_ticks: %L", nop_section.total_ticks / nop_section.call_count);

  while (1);
}
