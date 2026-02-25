#include "synapse/common/util/common.h"
#include "libcom/types.h"

#include "synapse/stm32/periph/flash.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/usart.h"
#include "synapse/stm32/periph/tim.h"
#include "synapse/stm32/periph/dma.h"
#include "synapse/stm32/periph/adc.h"
#include "synapse/arch/cortex/common/sys.h"
#include "synapse/arch/cortex/periph/systick.h"

// DShot150
#define TIM_AUTORELOAD_VALUE (667)

// DShot300
// #define TIM_AUTORELOAD_VALUE (334)

// DShot600
// #define TIM_AUTORELOAD_VALUE (167)

// DShot1200
// #define TIM_AUTORELOAD_VALUE (83)

#define CC_PERIOD_HIGH ((u32) (TIM_AUTORELOAD_VALUE * .75))
#define CC_PERIOD_LOW ((u32) (TIM_AUTORELOAD_VALUE * .375))

#define PERIODS_ARRAY_LENGTH (18)
u16 arr[PERIODS_ARRAY_LENGTH];

struct dshot_config
{
  // 11 bit
  u32 motor_speed;

  // 1 bit
  u32 telemetry;
};

u32
dshot_motor_speed_percentage(u32 percentage)
{
  return (u32) (((float) percentage / 100.0f) * 2000) + 48;
}

u32
dshot_pack_frame(struct dshot_config* config)
{
  u32 frame = 0;
  frame |= ((config->motor_speed & 2047) << 1);
  frame |= ((config->telemetry & 1) << 0);

  u32 crc = ((frame >> 8) ^ (frame >> 4) ^ (frame)) & 0xf;

  frame = (frame << 4) | crc;
  return frame;
}

void
dshot_calc_periods(u32 frame, u16* buf)
{
  for (u32 i = 0; i < 16; ++i)
  {
    if ((frame & (1u << (16 - 1 - i))))
    {
      buf[i] = CC_PERIOD_HIGH;
    }
    else
    {
      buf[i] = CC_PERIOD_LOW;
    }
  }

  for (u32 i = 16; i < PERIODS_ARRAY_LENGTH; ++i)
  {
    buf[i] = 0;
  }
}

void
rcc_setup(void)
{
  flash_set_wait_state(FLASH_WAIT_STATE3);
  flash_prefetch_enable();

  // HSI runs at 16 Mhz on F4
  rcc_osc_enable(RCC_OSC_HSI);
  WAIT_UNTIL(rcc_is_osc_ready(RCC_OSC_HSI));

  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSI);
  rcc_set_main_pll_factorM(8);
  rcc_set_main_pll_factorN(100);
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV2);

  rcc_osc_enable(RCC_OSC_PLL);
  WAIT_UNTIL(rcc_is_osc_ready(RCC_OSC_PLL));

  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLL);
  rcc_system_clock_source_ready_wait(RCC_SYSTEM_CLOCK_SOURCE_PLL);

  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 clock = 100000000;
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
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOA,
    GPIO11,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

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

  gpio_set_pin_alternate_function(
    GPIOA,
    GPIO11,
    GPIO_ALTFN1
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO0,
    GPIO_MODE_ANALOG,
    GPIO_SPEED_HIGH
  );

  gpio_set_port_pins_io_resistor(
    GPIOA,
    GPIO0,
    GPIO_IO_RESISTOR_NO_PULLUPDOWN
  );
}

void
dma_setup(void)
{
  dma_stream_disable(DMA2, DMA_STREAM5);
  WAIT_UNTIL((DMA2->streams[DMA_STREAM5].SCR & (1u << 0)) == 0);

  dma_stream_set_periph_address(DMA2, DMA_STREAM5, (u32) &TIM1->CCR4);
  dma_stream_set_memory_address(DMA2, DMA_STREAM5, DMA_STREAM_MEMORY0, (u32) arr);
  dma_stream_set_items_transfer_count(DMA2, DMA_STREAM5, ARR_SIZE(arr));
  dma_stream_set_channel(DMA2, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  dma_stream_set_priority(DMA2, DMA_STREAM5, DMA_STREAM_PRIORITY_VERY_HIGH);
  dma_stream_direct_mode_enable(DMA2, DMA_STREAM5);

  dma_stream_set_data_transfer_direction(DMA2, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  dma_stream_memory_increment_mode_enable(DMA2, DMA_STREAM5);
  dma_stream_periph_increment_mode_disable(DMA2, DMA_STREAM5);
  dma_stream_set_memory_burst_transfer(DMA2, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  dma_stream_set_periph_burst_transfer(DMA2, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  dma_stream_set_memory_data_size(DMA2, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  dma_stream_set_periph_data_size(DMA2, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  dma_stream_circular_mode_disable(DMA2, DMA_STREAM5);
  dma_stream_enable(DMA2, DMA_STREAM5);
}

void
timer_setup(void)
{
  tim_set_prescaler(TIM1, 0);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM1, TIM_AUTORELOAD_VALUE - 1);
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_set_oc_mode(TIM1, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  tim_set_center_aligned_mode(TIM1, TIM_CENTER_ALIGNED_MODE_EDGE);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_set_cc_value(TIM1, TIM_CHANNEL4, 0);
  tim_counter_enable(TIM1);
  tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
  tim_main_output_enable(TIM1);

  tim_dma_request_enable(TIM1, TIM_DMA_MODE_UPDATE);
  tim_set_cc_dma_request_source(TIM1, TIM_CC_DMA_REQUEST_SOURCE_UPDATE_EVENT);
}

void
adc_setup(void)
{
  u32 sequence[] = { ADC_REG_CHANNEL0 };
  adc_set_reg_sequence(ADC1, sequence, ARR_SIZE(sequence));
  adc_set_channel_sample_rate(ADC1, ADC_REG_CHANNEL0, ADC_SAMPLE_RATE_480CYCLES);
  adc_enable(ADC1);
}

void
systick_setup(void)
{
  systick_set_clock_source(SYSTICK_CLOCK_SOURCE_PROCESSOR);
  systick_set_reload_value(99);
  systick_set_current_value(0);
  systick_interrupt_enable();
  systick_enable();
}

u32 delay;
u32 tick;

void
systick_handler(void)
{
  if (delay > 0)
  {
    --delay;
  }

  ++tick;

  cm_isb();
  cm_dsb();
}

void
delay_us(u32 us)
{
  delay = us;
  systick_interrupt_enable();
  while (delay > 0);
  systick_interrupt_disable();
}

int
main(void)
{
  syn_delay_nop(1000000);

  for (u32 i = 0; i < PERIODS_ARRAY_LENGTH; ++i)
  {
    arr[i] = CC_PERIOD_LOW;
  }

  struct dshot_config conf;
  conf.motor_speed = dshot_motor_speed_percentage(0);
  conf.telemetry = 0;
  u32 frame = dshot_pack_frame(&conf);
  dshot_calc_periods(frame, arr);

  rcc_setup();
  gpio_setup();
  usart_setup();
  adc_setup();
  dma_setup();
  timer_setup();
  systick_setup();

  u32 speed = 0;
  u32 adc_data = 0;
  u32 update_speed = 0;

  while (1)
  {
    if (dma_is_stream_flag_set(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
    {
      dma_stream_flag_clear(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);

      if (update_speed)
      {
        update_speed = 0;
        speed = (u32) ((float) adc_data / 4095.0f * 100.0f);
        conf.motor_speed = dshot_motor_speed_percentage(speed);
        frame = dshot_pack_frame(&conf);
        dshot_calc_periods(frame, arr);
      }

      delay_us(10);
      dma_stream_enable(DMA2, DMA_STREAM5);
    }

    if (!adc_is_flag_set(ADC1, ADC_FLAG_START))
    {
      adc_reg_start(ADC1);
    }
    else if (adc_is_flag_set(ADC1, ADC_FLAG_EOC))
    {
      adc_flag_clear(ADC1, ADC_FLAG_EOC);
      adc_flag_clear(ADC1, ADC_FLAG_START);

      adc_data = adc_reg_data_read(ADC1);
      update_speed = 1;
    }
  }
}
