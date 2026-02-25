#include "libcom/sys/runtime.h"
#include "libcom/unit.h"
#include "libcom/util.h"
#include "synapse/arch/cortex/periph/nvic.h"
#include "synapse/common/util/common.h"
#include "system/scheduler/backend/sif.h"
#include "system/scheduler/scheduler.h"
#include "system/scheduler/task_history.h"
#include "system/scheduler/wiring/dispatcher.h"
#include "system/scheduler/backend/ts/stm32_tim.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/tim.h"
#include "synapse/stm32/periph/usart.h"
#include "system/time/time.h"
#include "system/time/wiring/dispatcher.h"
#include "system/time/backend/stm32_tim.h"
#include "synapse/arch/cortex/common/sys.h"
#include "synapse/arch/cortex/periph/fpu.h"

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
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  gpio_set_port_pins_output_type(
    GPIOC,
    GPIO13,
    GPIO_OUTPUT_TYPE_PUSHPULL
  );

  gpio_setup_port_pins(
    GPIOB,
    GPIO2 | GPIO10,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO9,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO10,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(GPIOA, GPIO9 | GPIO10, GPIO_ALTFN7);

  gpio_setup_port_pins(
    GPIOB,
    GPIO12,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOC,
    GPIO15,
    GPIO_MODE_INPUT,
    GPIO_SPEED_HIGH
  );

  gpio_set_port_pins_io_resistor(
    GPIOC,
    GPIO15,
    GPIO_IO_RESISTOR_PULLUP
  );
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 apb2_clock = 16'000'000;
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
  // TIM2
  tim_set_prescaler(TIM2, 0);
  tim_set_clock_division(TIM2, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM2, 0xfffe);
  tim_oc_preload_enable(TIM2, TIM_CHANNEL4);
  tim_set_counter_direction(TIM2, TIM_COUNTER_DIRECTION_UP);
  tim_cc_channel_enable(TIM2, TIM_CHANNEL4);
  tim_interrupt_enable(TIM2, TIM_INTERRUPT_UPDATE);
  tim_counter_enable(TIM2);
}

void
timer_setup(void)
{
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_auto_reload_preload_enable(TIM1);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_set_prescaler(TIM1, 7999);
  tim_set_autoreload_value(TIM1, 1);
  // tim_set_prescaler(TIM1, 7999);
  // tim_set_autoreload_value(TIM1, 1999);
  tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
  tim_interrupt_enable(TIM1, TIM_INTERRUPT_UPDATE);
}

void
nvic_setup(void)
{
  nvic_irq_enable(NVIC_IRQ_TIM1_UPDATE_TIM10);
  nvic_irq_enable(NVIC_IRQ_TIM2);
}

void
tim1_up_isr(void)
{
  nvic_clear_pending_irq(NVIC_IRQ_TIM1_UPDATE_TIM10);
  tim_flag_clear(TIM1, TIM_FLAG_UPDATE);
  system_scheduler_wakeup(&scheduler);
}

void
tim2_isr(void)
{
  system_time_handle_overflow();
  nvic_clear_pending_irq(NVIC_IRQ_TIM2);
  tim_flag_clear(TIM2, TIM_FLAG_UPDATE);
}

static void
_toggle_led(
  struct scheduler_task* task,
  void* ctx
)
{
  (void) ctx;
  (void) task;
  gpio_pin_toggle(GPIOC, GPIO13);
}

static void
_toggle_led_green(
  struct scheduler_task* task,
  void* ctx
)
{
  (void) task;
  (void) ctx;
  gpio_pin_toggle(GPIOB, GPIO2);
}

static void
_toggle_led_red(
  struct scheduler_task* task,
  void* ctx
)
{
  (void) task;
  (void) ctx;
  gpio_pin_toggle(GPIOB, GPIO10);
}

static void
_check_btn(
  struct scheduler_task* task,
  void* ctx
)
{
  (void) ctx;
  (void) task;
  if (gpio_pin_read(GPIOC, GPIO15) == 0)
  {
    gpio_pin_toggle(GPIOB, GPIO12);
  }
}

static void
_sysinfo(
  struct scheduler_task* task,
  void* ctx
)
{
  (void) ctx;
  (void) task;

  u32 ram_used = nex_get_RAM_usage();
  u32 flash_used = nex_get_flash_usage();

  enum nex_byte_unit ram_used_unit;
  enum nex_byte_unit flash_used_unit;
  ram_used = nex_convert_byte_to_largest(ram_used, NEX_BYTE_UNIT_BYTE, &ram_used_unit);
  flash_used = nex_convert_byte_to_largest(flash_used, NEX_BYTE_UNIT_BYTE, &flash_used_unit);

  usart_send_strln(USART1, "Runtime system resources:");
  usart_send_strfln(USART1, "RAM usage: %u %s", ram_used, nex_byte_unit_to_string(ram_used_unit));
  usart_send_strfln(USART1, "Flash usage: %u %s", flash_used, nex_byte_unit_to_string(flash_used_unit));
  usart_send_strfln(USART1, "Tick time: %L", scheduler.acc);
  usart_send_strfln(USART1, "Tasks usage:");

  for (u32 i = 0; i < scheduler.active_tasks_count; ++i)
  {
    u32 idx = scheduler.active_tasks[i];
    struct scheduler_task* t = &scheduler.allocated_tasks[idx];
    u64 time = task_history_get_last_exec_time(&t->history);
    usart_send_strfln(
      USART1,
      "%s: %u%% CPU (time: %l, tick time: %u)",
      t->name,
      system_scheduler_get_task_cpu_usage(t),
      time,
      system_scheduler_get_task_tick_usage(t)
    );
  }

  usart_send_strln(USART1, "********************");
}

int 
main() {
  fpu_set_access_level(FPU_ACCESS_LEVEL_FULL);

  rcc_setup();
  gpio_setup();
  usart_setup();
  timer_setup();
  nvic_setup();

  struct sys_time_vtable* vtable;
  vtable = system_get_time_backend_vtable(SYSTEM_TIME_BACKEND_STM32_TIM);

  struct system_stm32_timer_backend_ctx time_ctx = {
    .tim = TIM2,
    .value_width_bits = 16 
  };

  struct sys_time_backend time_backend = {
    .vtable = vtable,
    .ctx = &time_ctx
  }; 

  system_set_time_source(&time_backend);

  system_timer_setup();

  struct scheduler_stm32_tim_backend backend = {
    .tim = TIM1
  };

  struct scheduler_ts_backend_vtable* scheduler_ts_vtable;
  struct scheduler_arch_backend_vtable* scheduler_arch_vtable;

  scheduler_ts_vtable = scheduler_get_backend_vtable(SCHEDULER_BACKEND_STM32_TIM);
  scheduler_arch_vtable = scheduler_get_arch_backend_vtable(SCHEDULER_ARCH_BACKEND_ARM);

  system_scheduler_init(&scheduler);
  
  scheduler.backend.arch_vtable = scheduler_arch_vtable;
  scheduler.backend.ts_vtable = scheduler_ts_vtable;
  scheduler.backend.ts_ctx = &backend;
  scheduler.max_tick_time_us = 1'000;
  scheduler.max_tick_time_tt = (u32) (1'000'000 / 62.5);

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

  struct scheduler_task* sys_info = system_scheduler_task_alloc(&scheduler);
  sys_info->name = "System info";
  sys_info->priority = 1;
  sys_info->delay_us = nex_convert_time_unit(1, NEX_TIME_UNIT_SECOND, NEX_TIME_UNIT_MICROSECOND);
  sys_info->callback = _sysinfo;
  // sys_info->flags |= SCHEDULER_TASK_EXCLUDE_FROM_STATS;

  system_scheduler_task_enable(&scheduler, gl_task);
  system_scheduler_task_enable(&scheduler, rl_task);
  system_scheduler_task_enable(&scheduler, bl_task);
  system_scheduler_task_enable(&scheduler, btn_check);
  // system_scheduler_task_enable(&scheduler, sys_info);

  system_scheduler_start(&scheduler);
  system_scheduler_loop(&scheduler);

  while (1);
}
