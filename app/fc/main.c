#include "blackbird/motors/actuator.h"
#include "blackbird/proto/dshot.h"
#include "blackbird/proto/pwm.h"
#include "blackbird/vehicle/airplane.h"
#include "blackbird/modes/acro.h"
#include "blackbird/proto/crsf.h"
#include "blackbird/vehicle/vehicle.h"
#include "blackbird/vehicle/quadcopter.h"
#include "blackbird/inputs.h"
#include "drivers/mpu9250.h"
#include "io/io_spi.h"
#include "libcom/format.h"
#include "libcom/sys/runtime.h"
#include "libcom/types.h"
#include "libcom/unit.h"
#include "libcom/util.h"
#include "soc/stm32/drivers/dma/dma_v1.h"
#include "soc/stm32/drivers/dma/dma_v2.h"
#include "soc/stm32/drivers/pwr/pwr_v2.h"
#include "soc/stm32/drivers/spi/spiif.h"
#include "soc/stm32/drivers/tim/tim_v1.h"
#include "soc/stm32/drivers/usart/usart_v1.h"
#include "synapse/cpu/cortex/periph/nvic.h"
#include "synapse/common/common.h"
#include "system/scheduler/scheduler.h"
#include "system/scheduler/task_history.h"
#include "synapse/soc/stm32/periph/rcc.h"
#include "synapse/soc/stm32/periph/dma.h"
#include "synapse/soc/stm32/periph/spi.h"
#include "synapse/soc/stm32/periph/gpio.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "synapse/soc/stm32/periph/usart.h"
#include "synapse/soc/stm32/periph/flash.h"
#include "system/time/time.h"
#include "system/time/dispatcher.h"
#include "system/time/backend/stm32_tim.h"
#include "synapse/cpu/cortex/common/sys.h"
#include "synapse/cpu/cortex/periph/fpu.h"
#include "synapse/cpu/cortex/common/memory.h"
#include "libcom/math/nxmath.h"
#include "synapse/cpu/cortex/common/string.h"

// Functions declarations.

static void
send_battery_status(void);

static void
send_heartbeat(void);

static i32
send_flight_mode(void);

static void
_usend(
  u8* buf,
  u32 len
);

static void
_handle_pkt(
  struct bb_crsf_port* port, 
  struct bb_crsf_frame* frame
);

static u32
_getleft(void);

static void
_onfail(void);

// Global variables.

struct bb_input_channels inputs = {};

u16 scaled_values[4];
u16 dshot_bit_patterns[32] = {};
volatile u16 dshot_bp[32] = {};
u16 pwm_cc_values[1] = {};
volatile u16 pwm_cc[1] = {};

struct bb_dshot_periods ds_periods;

struct bb_crsf_port_ops ops = {
  .send = _usend,
  .on_packet_ready = _handle_pkt,
  .get_items_left = _getleft,
  .on_parse_fail = _onfail
};

struct bb_crsf_node node = {
  .ops = &ops
};

i32 port_idx;

struct system_scheduler scheduler;

struct bb_vehicle vehicle = {
  .pitch_pid = {
    .imax = 100,
    .imin = -100,
    .kp = 0.05f,
    .kd = 0.0f,
    .ki = 0.0f
  },
  .roll_pid = {
    .imax = 100,
    .imin = -100,
    .kp = 0.05f,
    .kd = 0.0f,
    .ki = 0.0f
  },
  .yaw_pid = {
    .imax = 100,
    .imin = -100,
    .kp = 0.05f,
    .kd = 0.0f,
    .ki = 0.0f
  },

  .config = {
    .yaw_range_min = -250.0f,
    .yaw_range_max =  250.0f,

    .roll_range_min = -250.0f,
    .roll_range_max =  250.0f,

    .pitch_range_min = -250.0f,
    .pitch_range_max =  250.0f,
    
    .max_thrust = 1.0f
  },

  .flight_mode = BB_FLIGHT_MODE_ACRO,
  .thrust_mode = BB_VEHICLE_THRUST_RANGE_MODE_LERP
};

#define ACTUATORS_COUNT (2)

struct bb_actuator actuators[ACTUATORS_COUNT] = {
  {
    .min_speed_v = 48,
    .max_speed_v = 2047,
    .axes_vec = {
      .x = 1.0f
    },
  },
  {
    .min_speed_v = 1000,
    .max_speed_v = 2000,
    .axes_vec = {
      .w = 1.0f
    }
  }
};

u16 actuators_values[ACTUATORS_COUNT];

u32 volt = 10;
float rem = 100.0f;

static void
_usend(
  u8* buf,
  u32 len
)
{
  dma_stream_set_memory_address(DMA2, DMA_STREAM7, DMA_STREAM_MEMORY0, (u32) buf);
  dma_stream_set_items_transfer_count(DMA2, DMA_STREAM7, len);
  dma_stream_enable(DMA2, DMA_STREAM7);
}

static void
_handle_pkt(
  struct bb_crsf_port* port, 
  struct bb_crsf_frame* frame
)
{
  (void) port;
  (void) frame;

  if (frame->type == 0x16)
  {
    memcpy(inputs.channels, frame->bc.rc_channels.channels, sizeof(u16) * 16);
  }
}

static u32
_getleft(void)
{
  return dma_stream_get_items_transfer_count(DMA2, DMA_STREAM2);
}

static void
_onfail(void)
{
  gpio_pin_toggle(GPIOA, GPIO0);
}

void
rcc_setup(void)
{
  flash_set_wait_state(FLASH_WAIT_STATE3);
  flash_prefetch_enable();

  rcc_osc_enable(RCC_OSC_HSE);
  while (rcc_is_osc_ready(RCC_OSC_HSE) == 0);

  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV2);

  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSE);
  rcc_set_main_pll_factorM(25);
  rcc_set_main_pll_factorN(200);
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV2);

  rcc_osc_enable(RCC_OSC_PLL);
  while (rcc_is_osc_ready(RCC_OSC_PLL) == 0);

  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLL);
  rcc_system_clock_source_ready_wait(RCC_SYSTEM_CLOCK_SOURCE_PLL);

  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  rcc_periph_clock_enable(RCC_PERIPH_TIM2);
  rcc_periph_clock_enable(RCC_PERIPH_TIM3);
  rcc_periph_clock_enable(RCC_PERIPH_TIM4);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_DMA1);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
  rcc_periph_clock_enable(RCC_PERIPH_SPI1);
}

void
gpio_setup(void)
{
  // Debug LED
  gpio_setup_port_pins(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  // Debug LED
  gpio_setup_port_pins(
    GPIOA,
    GPIO0,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  // DShot signal out
  gpio_setup_port_pins(
    GPIOA,
    GPIO11,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(
    GPIOA,
    GPIO11,
    GPIO_ALTFN1
  );

  // PWM signal out
  gpio_setup_port_pins(
    GPIOB,
    GPIO0,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(
    GPIOB,
    GPIO0,
    GPIO_ALTFN2
  );

  // USART 1
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
  constexpr u32 baudrate = 420000;
  const u32 apb2_clock = nex_convert_freq_unit(100, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, apb2_clock, baudrate);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  usart_transmitter_enable(USART1);
  usart_receiver_enable(USART1);
  usart_parity_control_disable(USART1);
  usart_cts_disable(USART1);
  usart_rts_disable(USART1);
  usart_dma_transmission_enable(USART1);
  usart_dma_reception_enable(USART1);
  // usart_interrupt_enable(USART1, USART_INTERRUPT_IDLE);
  usart_enable(USART1);
}

void
system_timer_setup(void)
{
  tim_set_prescaler(TIM2, 99);
  tim_set_clock_division(TIM2, TIM_CLOCK_DIVISION_NODIV);
  tim_oc_preload_enable(TIM2, TIM_CHANNEL4);
  tim_set_counter_direction(TIM2, TIM_COUNTER_DIRECTION_UP);
  tim_cc_channel_enable(TIM2, TIM_CHANNEL4);
  tim_trigger_event_generation(TIM2, TIM_EVENT_UPDATE);
  tim_counter_enable(TIM2);
}

void
timer_setup(void)
{
  // Scheduler tick
  tim_oc_preload_enable(TIM4, TIM_CHANNEL4);
  tim_auto_reload_preload_enable(TIM4);
  tim_set_clock_division(TIM4, TIM_CLOCK_DIVISION_NODIV);
  tim_set_counter_direction(TIM4, TIM_COUNTER_DIRECTION_UP);
  tim_set_prescaler(TIM4, 1);
  tim_set_autoreload_value(TIM4, 50000-1);
  tim_cc_channel_enable(TIM4, TIM_CHANNEL4);
  tim_interrupt_enable(TIM4, TIM_INTERRUPT_UPDATE);
  tim_trigger_event_generation(TIM4, TIM_EVENT_UPDATE);

  // DShot generator
  tim_set_prescaler(TIM1, 0);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM1, 334 - 1);
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_set_oc_mode(TIM1, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  tim_set_center_aligned_mode(TIM1, TIM_CENTER_ALIGNED_MODE_EDGE);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_set_cc_value(TIM1, TIM_CHANNEL4, 0);
  tim_trigger_event_generation(TIM1, TIM_EVENT_UPDATE);
  tim_counter_enable(TIM1);
  tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
  tim_main_output_enable(TIM1);
  tim_dma_request_enable(TIM1, TIM_DMA_MODE_UPDATE);
  tim_set_cc_dma_request_source(TIM1, TIM_CC_DMA_REQUEST_SOURCE_UPDATE_EVENT);

  // PWM generator
  tim_set_prescaler(TIM3, 100-1);
  tim_set_clock_division(TIM3, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM3, 20000-1);
  tim_oc_preload_enable(TIM3, TIM_CHANNEL3);
  tim_set_oc_mode(TIM3, TIM_CHANNEL3, TIM_OC_MODE_PWM1);
  tim_set_center_aligned_mode(TIM3, TIM_CENTER_ALIGNED_MODE_EDGE);
  tim_set_counter_direction(TIM3, TIM_COUNTER_DIRECTION_UP);
  tim_set_cc_value(TIM3, TIM_CHANNEL3, 1000);
  tim_trigger_event_generation(TIM3, TIM_EVENT_UPDATE);
  tim_counter_enable(TIM3);
  tim_cc_channel_enable(TIM3, TIM_CHANNEL3);
  tim_main_output_enable(TIM3);
  tim_dma_request_enable(TIM3, TIM_DMA_MODE_UPDATE);
  tim_set_cc_dma_request_source(TIM3, TIM_CC_DMA_REQUEST_SOURCE_UPDATE_EVENT);
}

void
dma_setup(void)
{
  // USART tx
  dma_stream_set_channel(DMA2, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  dma_stream_set_data_transfer_direction(DMA2, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  dma_stream_set_periph_address(DMA2, DMA_STREAM7, (u32) &USART1->DR);
  dma_stream_memory_increment_mode_enable(DMA2, DMA_STREAM7);
  dma_stream_periph_increment_mode_disable(DMA2, DMA_STREAM7);
  dma_stream_set_memory_data_size(DMA2, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_BYTE);
  dma_stream_set_periph_data_size(DMA2, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_BYTE);
  dma_stream_set_priority(DMA2, DMA_STREAM7, DMA_STREAM_PRIORITY_LOW);
  dma_stream_set_fifo_threshold(DMA2, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_FULL);
  dma_stream_interrupt_enable(DMA2, DMA_STREAM7, DMA_STREAM_INTERRUPT_TRANSFER_COMPLETE);

  // USART rx
  dma_stream_set_channel(DMA2, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  dma_stream_set_data_transfer_direction(DMA2, DMA_STREAM2, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  dma_stream_set_periph_address(DMA2, DMA_STREAM2, (u32) &USART1->DR);
  dma_stream_set_memory_address(DMA2, DMA_STREAM2, DMA_STREAM_MEMORY0, (u32) &node.ports[0].inbuf);
  dma_stream_set_items_transfer_count(DMA2, DMA_STREAM2, BB_CRSF_PORT_INBUF_LEN);
  dma_stream_memory_increment_mode_enable(DMA2, DMA_STREAM2);
  dma_stream_periph_increment_mode_disable(DMA2, DMA_STREAM2);
  dma_stream_set_memory_data_size(DMA2, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_BYTE);
  dma_stream_set_periph_data_size(DMA2, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_BYTE);
  dma_stream_set_priority(DMA2, DMA_STREAM2, DMA_STREAM_PRIORITY_MEDIUM);
  dma_stream_set_fifo_threshold(DMA2, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_FULL);
  dma_stream_circular_mode_enable(DMA2, DMA_STREAM2);
  dma_stream_enable(DMA2, DMA_STREAM2);

  // Timer (DShot)
  dma_stream_disable(DMA2, DMA_STREAM5);

  dma_stream_interrupt_enable(DMA2, DMA_STREAM5, DMA_STREAM_INTERRUPT_TRANSFER_COMPLETE);

  dma_stream_set_periph_address(
    DMA2,
    DMA_STREAM5,
    (u32) &TIM1->CCR4
  );

  dma_stream_set_memory_address(
    DMA2,
    DMA_STREAM5,
    DMA_STREAM_MEMORY0,
    (u32) dshot_bp
  );

  dma_stream_set_items_transfer_count(DMA2, DMA_STREAM5, ARR_SIZE(dshot_bp));
  dma_stream_set_channel(DMA2, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  dma_stream_set_priority(DMA2, DMA_STREAM5, DMA_STREAM_PRIORITY_VERY_HIGH);
  dma_stream_direct_mode_enable(DMA2, DMA_STREAM5);
  dma_stream_set_fifo_threshold(DMA2, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_FULL);

  dma_stream_set_data_transfer_direction(
    DMA2,
    DMA_STREAM5,
    DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH
  );

  dma_stream_memory_increment_mode_enable(DMA2, DMA_STREAM5);
  dma_stream_periph_increment_mode_disable(DMA2, DMA_STREAM5);

  dma_stream_set_memory_burst_transfer(
    DMA2,
    DMA_STREAM5,
    DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER
  );

  dma_stream_set_periph_burst_transfer(
    DMA2,
    DMA_STREAM5,
    DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER
  );

  dma_stream_set_memory_data_size(
    DMA2,
    DMA_STREAM5,
    DMA_STREAM_MEMORY_SIZE_HALF_WORD
  );

  dma_stream_set_periph_data_size(
    DMA2,
    DMA_STREAM5,
    DMA_STREAM_PERIPH_SIZE_HALF_WORD
  );

  dma_stream_circular_mode_disable(DMA2, DMA_STREAM5);
  dma_stream_enable(DMA2, DMA_STREAM5);

  // Timer (PWM)
  dma_stream_disable(DMA1, DMA_STREAM2);

  dma_stream_interrupt_enable(DMA1, DMA_STREAM2, DMA_STREAM_INTERRUPT_TRANSFER_COMPLETE);

  dma_stream_set_periph_address(
    DMA1,
    DMA_STREAM2,
    (u32) &TIM3->CCR3
  );

  dma_stream_set_memory_address(
    DMA1,
    DMA_STREAM2,
    DMA_STREAM_MEMORY0,
    (u32) pwm_cc
  );

  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, ARR_SIZE(pwm_cc));
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_VERY_HIGH);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM2);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_FULL);

  dma_stream_set_data_transfer_direction(
    DMA1,
    DMA_STREAM2,
    DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH
  );

  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM2);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM2);

  dma_stream_set_memory_burst_transfer(
    DMA1,
    DMA_STREAM2,
    DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER
  );

  dma_stream_set_periph_burst_transfer(
    DMA1,
    DMA_STREAM2,
    DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER
  );

  dma_stream_set_memory_data_size(
    DMA1,
    DMA_STREAM2,
    DMA_STREAM_MEMORY_SIZE_HALF_WORD
  );

  dma_stream_set_periph_data_size(
    DMA1,
    DMA_STREAM2,
    DMA_STREAM_PERIPH_SIZE_HALF_WORD
  );

  dma_stream_circular_mode_disable(DMA1, DMA_STREAM2);
  dma_stream_enable(DMA1, DMA_STREAM2);
}

void
nvic_setup(void)
{
  nvic_irq_enable(NVIC_IRQ_TIM1_UPDATE_TIM10);
  nvic_irq_enable(NVIC_IRQ_USART1);
  nvic_irq_enable(NVIC_IRQ_TIM2);
  nvic_irq_enable(NVIC_IRQ_TIM4);
  nvic_irq_enable(NVIC_IRQ_DMA1_STREAM2);
  nvic_irq_enable(NVIC_IRQ_DMA2_STREAM2);
  nvic_irq_enable(NVIC_IRQ_DMA2_STREAM5);
  nvic_irq_enable(NVIC_IRQ_DMA2_STREAM7);

  nvic_set_irq_priority(NVIC_IRQ_DMA2_STREAM5, 0);
}

void
tim4_isr(void)
{
  nvic_clear_pending_irq(NVIC_IRQ_TIM4);
  tim_flag_clear(TIM4, TIM_FLAG_UPDATE);
  system_scheduler_wakeup(&scheduler);
}

static u32 last = 0;

static void
_fc_tick(
  struct scheduler_task*,
  void*
)
{
  cm_irq_disable();
  bb_vehicle_tick(&vehicle, &inputs, 0.001f);

  bb_airplane_mixer_compute(
    &vehicle,
    actuators,
    scaled_values,
    ACTUATORS_COUNT
  );

  bb_proto_dshot_pack_norm_sequence(
    &ds_periods,
    scaled_values,
    1,
    (void*) dshot_bit_patterns
  );

  last = scaled_values[0];
  pwm_cc_values[0] = scaled_values[1];

  // if (inputs.channels[7] > 1500)
  // {
  //   gpio_set_pin_low(GPIOC, GPIO13);
  // }
  // else
  // {
  //   gpio_set_pin_high(GPIOC, GPIO13);
  // }

  cm_irq_enable();
}

u32 it = 0;
u32 fm = 0;
u32 last_fm = 0;

static void
_receiver_tick(
  struct scheduler_task*,
  void*
)
{
  bb_crsf_node_tick(&node);

  if (0)
    send_heartbeat();

  ++it;
  if (it >= 40 || last_fm != vehicle.flight_mode)
  {
    fm = 1;
  }

  if (fm)
  {
    i32 code = send_flight_mode();
    if (code == NOK)
    {
      fm = 0;
      it = 0;
    }
  }
  else if ((it % 20) == 0)
  {
    if (0)
    send_battery_status();
  }
}

void
dma2_stream5_isr(void)
{
  nvic_clear_pending_irq(NVIC_IRQ_DMA2_STREAM5);


  if (dma_is_stream_flag_set(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
  {
    tim_dma_request_disable(TIM1, TIM_DMA_MODE_UPDATE);

    for (u32 i = 0; i < 16; ++i)
    {
      dshot_bp[i] = dshot_bit_patterns[i];
    }

    cm_isb();
    cm_dsb();
    cm_dmb();

    dma_stream_flag_clear(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
    dma_stream_set_items_transfer_count(DMA2, DMA_STREAM5, ARR_SIZE(dshot_bp));
    dma_stream_enable(DMA2, DMA_STREAM5);
    tim_trigger_event_generation(TIM1, TIM_EVENT_UPDATE);

    tim_dma_request_enable(TIM1, TIM_DMA_MODE_UPDATE);
  }
}

void
dma1_stream2_isr(void)
{
  nvic_clear_pending_irq(NVIC_IRQ_DMA1_STREAM2);

  if (dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
  {
    for (u32 i = 0; i < 1; ++i)
    {
      pwm_cc[i] = pwm_cc_values[i];
    }

    dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
    dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, ARR_SIZE(pwm_cc));
    dma_stream_enable(DMA1, DMA_STREAM2);
  }
}

void
dma2_stream7_isr()
{
  if (dma_is_stream_flag_set(DMA2, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
  {
    dma_stream_flag_clear(DMA2, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
    bb_crsf_node_tx_complete(&node, port_idx);
  }

  nvic_clear_pending_irq(NVIC_IRQ_DMA2_STREAM7);
}

void
send_heartbeat(void)
{
  struct bb_crsf_frame frame;
  frame.type = BB_CRSF_FRAME_TYPE_HEARTBEAT;
  frame.bc.heartbeat.origin_address = 0xc8;
  bb_crsf_port_enqueue_packet(&node, port_idx, &frame);
}

i32
send_flight_mode(void)
{
  struct bb_crsf_frame frame;
  frame.type = BB_CRSF_FRAME_TYPE_FLIGHT_MODE;

  const char* fmode;

  switch (vehicle.flight_mode)
  {
    case BB_FLIGHT_MODE_DDRIVE:
      fmode = "DDrive";
      break;

    case BB_FLIGHT_MODE_ACRO:
      fmode = "Acro";
      break;

    case BB_FLIGHT_MODE_ANGLE:
      fmode = "Angle";
      break;

    default:
      fmode = "Unknown";
      break;
  }

  u32 len = strlen(fmode) + 1;
  memcpy(frame.bc.flight_mode.flight_mode, fmode, len);
  frame.bc.flight_mode.flight_mode[len] = 0;
  i32 code = bb_crsf_port_enqueue_packet(&node, port_idx, &frame);
  if (code == NOK)
  {
    last_fm = vehicle.flight_mode;
  }

  return code;
}

void
send_battery_status(void)
{
  struct bb_crsf_frame frame;
  frame.type = BB_CRSF_FRAME_TYPE_BATTERY_SENSOR;
  frame.bc.battery.voltage = 74;
  frame.bc.battery.current = 900;
  frame.bc.battery.capacity_used = 392;
  frame.bc.battery.remaining = (u8) rem;

  bb_crsf_port_enqueue_packet(&node, port_idx, &frame);

  volt = -volt;
  if (volt)
  {
    rem -= 0.25f;
  }

  if (rem <= 0.0f)
  {
    rem = 100.0f;
  }
}

int 
main() 
{
  fpu_set_access_level(FPU_ACCESS_LEVEL_FULL);

  nvic_irq_enable(NVIC_IRQ_DMA2_STREAM2);
  nvic_irq_enable(NVIC_IRQ_DMA1_STREAM2);

  rcc_setup();
  gpio_setup();

  dma_setup();
  nvic_setup();

  usart_setup();

  timer_setup();

  struct system_stm32_timer_backend_ctx time_ctx = {
    .tim = TIM2,
    .value_width_bits = 32 
  };

  struct sys_coarse_time_backend time_backend = {
    .vtable = system_get_coarse_time_backend(SYSTEM_COARSE_TIME_BACKEND_STM32_TIM),
    .ctx = &time_ctx
  };

  system_set_coarse_time_source(&time_backend);
  system_timer_setup();

  system_scheduler_init(&scheduler);
  scheduler.max_tick_time_us = 1'000;

  struct scheduler_task* fc_task = system_scheduler_task_alloc(&scheduler);
  fc_task->name = "FC";
  fc_task->priority = 1;
  fc_task->delay_us = nex_convert_time_unit(1, NEX_TIME_UNIT_MILLISECOND, NEX_TIME_UNIT_MICROSECOND);
  fc_task->callback = _fc_tick;

  struct scheduler_task* receiver_tick_task = system_scheduler_task_alloc(&scheduler);
  receiver_tick_task->name = "Receiver tick";
  receiver_tick_task->priority = 2;
  receiver_tick_task->delay_us = nex_convert_time_unit(1, NEX_TIME_UNIT_MILLISECOND, NEX_TIME_UNIT_MICROSECOND);
  receiver_tick_task->callback = _receiver_tick;

  bb_dshot_get_bit_periods(BB_DSHOT300, &ds_periods, 10);
  port_idx = bb_crsf_node_add_port(&node, USART1);
  bb_crsf_port_set_sync_byte(&node, port_idx, BB_CRSF_ADDR_FC);
  
  system_scheduler_task_enable(&scheduler, fc_task);
  // system_scheduler_task_enable(&scheduler, sensors_task);
  system_scheduler_task_enable(&scheduler, receiver_tick_task);

  tim_counter_enable(TIM4);
  system_scheduler_loop(&scheduler);

  while (1);
}

