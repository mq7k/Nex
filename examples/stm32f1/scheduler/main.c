#include "libcom/sys/runtime.h"
#include "libcom/unit.h"
#include "libcom/util.h"
#include "synapse/cpu/cortex/periph/nvic.h"
#include "synapse/common/common.h"
#include "system/scheduler/scheduler.h"
#include "system/scheduler/task_history.h"
#include "synapse/soc/stm32/periph/rcc.h"
#include "synapse/soc/stm32/periph/gpio.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "synapse/soc/stm32/periph/usart.h"
#include "system/time/dispatcher.h"
#include "system/time/time.h"
#include "system/time/dispatcher.h"
#include "system/time/backend/stm32_tim.h"
#include "synapse/cpu/cortex/common/sys.h"

struct system_scheduler scheduler;

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  rcc_periph_clock_enable(RCC_PERIPH_TIM2);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
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

  gpio_setup_port(
    GPIOB,
    GPIO1 | GPIO10,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );

  gpio_setup_port(
    GPIOA,
    GPIO9 | GPIO10,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port(
    GPIOB,
    GPIO12,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );

  gpio_setup_port(
    GPIOC,
    GPIO15,
    GPIO_MODE_INPUT,
    GPIO_CNF_INPUT_PULL_UPDOWN
  );

  gpio_set_pin_high(GPIOC, GPIO15);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 apb2_clock = nex_convert_freq_unit(8, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, apb2_clock, baudrate);
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
system_timer_setup(void)
{
  tim_set_prescaler(TIM2, 7);
  tim_set_clock_division(TIM2, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM2, 0xfffe);
  tim_oc_preload_enable(TIM2, TIM_CHANNEL4);
  tim_set_counter_direction(TIM2, TIM_COUNTER_DIRECTION_UP);
  tim_cc_channel_enable(TIM2, TIM_CHANNEL4);
  tim_counter_enable(TIM2);
}

void
timer_setup(void)
{
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_auto_reload_preload_enable(TIM1);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_set_prescaler(TIM1, 0);
  tim_set_autoreload_value(TIM1, 7999);
  tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
  tim_interrupt_enable(TIM1, TIM_INTERRUPT_UPDATE);
}

void
nvic_setup(void)
{
  nvic_irq_enable(NVIC_IRQ_TIM1_UPDATE);
  nvic_irq_enable(NVIC_IRQ_TIM2);
}

void
tim1_up_isr(void)
{
  nvic_clear_pending_irq(NVIC_IRQ_TIM1_UPDATE);
  tim_flag_clear(TIM1, TIM_FLAG_UPDATE);
  system_scheduler_wakeup(&scheduler);
}

static void
_toggle_led(
  struct scheduler_task*,
  void*
)
{
  gpio_pin_toggle(GPIOC, GPIO13);
}

static void
_toggle_led_green(
  struct scheduler_task*,
  void*
)
{
  gpio_pin_toggle(GPIOB, GPIO1);
}

static void
_toggle_led_red(
  struct scheduler_task*,
  void*
)
{
  gpio_pin_toggle(GPIOB, GPIO10);
}

static void
_check_btn(
  struct scheduler_task*,
  void*
)
{
  if (gpio_pin_read(GPIOC, GPIO15) == 0)
  {
    gpio_pin_toggle(GPIOB, GPIO12);
  }
}

int 
main() 
{
  rcc_setup();
  gpio_setup();
  usart_setup();
  timer_setup();
  nvic_setup();

  struct system_stm32_timer_backend_ctx time_ctx = {
    .tim = TIM2,
    .value_width_bits = 16 
  };

  struct sys_coarse_time_backend time_backend = {
    .vtable = system_get_coarse_time_backend(SYSTEM_COARSE_TIME_BACKEND_STM32_TIM),
    .ctx = &time_ctx
  };

  system_set_coarse_time_source(&time_backend);
  system_timer_setup();

  system_scheduler_init(&scheduler);
  scheduler.max_tick_time_us = 1'000;

  struct scheduler_task* gl_task = system_scheduler_task_alloc(&scheduler);
  gl_task->name = "Green Led Task";
  gl_task->priority = 2;
  gl_task->delay_us = nex_convert_time_unit(100, NEX_TIME_UNIT_MILLISECOND, NEX_TIME_UNIT_MICROSECOND);
  gl_task->callback = _toggle_led_green;

  struct scheduler_task* rl_task = system_scheduler_task_alloc(&scheduler);
  rl_task->name = "Red Led Task";
  rl_task->priority = 2;
  rl_task->delay_us = nex_convert_time_unit(200, NEX_TIME_UNIT_MILLISECOND, NEX_TIME_UNIT_MICROSECOND);
  rl_task->callback = _toggle_led_red;

  struct scheduler_task* bl_task = system_scheduler_task_alloc(&scheduler);
  bl_task->name = "Blue Led Task";
  bl_task->priority = 2;
  bl_task->delay_us = nex_convert_time_unit(250, NEX_TIME_UNIT_MILLISECOND, NEX_TIME_UNIT_MICROSECOND);
  bl_task->callback = _toggle_led;

  struct scheduler_task* btn_check = system_scheduler_task_alloc(&scheduler);
  btn_check->name = "Btn check Task";
  btn_check->priority = 2;
  btn_check->delay_us = nex_convert_time_unit(32, NEX_TIME_UNIT_MILLISECOND, NEX_TIME_UNIT_MICROSECOND);
  btn_check->callback = _check_btn;

  system_scheduler_task_enable(&scheduler, gl_task);
  system_scheduler_task_enable(&scheduler, rl_task);
  system_scheduler_task_enable(&scheduler, bl_task);
  system_scheduler_task_enable(&scheduler, btn_check);

  tim_counter_enable(TIM1);
  system_scheduler_loop(&scheduler);

  while (1);
}
