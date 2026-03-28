#include "synapse/common/common.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/periph/flash.h"
#include "synapse/soc/stm32/periph/rcc.h"
#include "synapse/soc/stm32/periph/gpio.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "synapse/soc/stm32/periph/dma.h"
#include "synapse/soc/stm32/periph/adc.h"
#include "synapse/cpu/cortex/common/sys.h"
#include "synapse/cpu/cortex/periph/systick.h"
#include "synapse/cpu/cortex/periph/fpu.h"
#include "synapse/cpu/cortex/periph/nvic.h"

// DShot150
// #define TIM_AUTORELOAD_VALUE (667)

// DShot300
#define TIM_AUTORELOAD_VALUE (334)

// DShot600
// #define TIM_AUTORELOAD_VALUE (167)

// DShot1200
// #define TIM_AUTORELOAD_VALUE (83)

#define CC_PERIOD_HIGH ((u32) (TIM_AUTORELOAD_VALUE * .75))
#define CC_PERIOD_LOW ((u32) (TIM_AUTORELOAD_VALUE * .375))

#define PERIODS_ARRAY_LENGTH (17)
u16 arr[PERIODS_ARRAY_LENGTH];

struct dshot_config
{
  // 11 bit
  u32 motor_speed;

  // 1 bit
  u32 telemetry;
};

u32
dshot_motor_speed_percentage(
  u32 percentage
)
{
  return (u32) (((float) percentage / 100.0f) * 2000) + 48;
}

u32
dshot_pack_frame(
  struct dshot_config* config
)
{
  u32 frame = 0;
  frame |= ((config->motor_speed & 2047) << 1);
  frame |= ((config->telemetry & 1) << 0);

  u32 crc = ((frame >> 8) ^ (frame >> 4) ^ (frame)) & 0xf;

  frame = (frame << 4) | crc;
  return frame;
}

void
dshot_calc_periods(
  u32 frame,
  u16* buf
)
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

  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSI);
  rcc_set_main_pll_factorM(8);
  rcc_set_main_pll_factorN(100);
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV2);

  rcc_osc_enable(RCC_OSC_PLL);
  while (rcc_is_osc_ready(RCC_OSC_PLL) == 0);

  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLL);
  rcc_system_clock_source_ready_wait(RCC_SYSTEM_CLOCK_SOURCE_PLL);

  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  rcc_periph_clock_enable(RCC_PERIPH_TIM2);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOA,
    GPIO9 | GPIO10 | GPIO11,
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

  dma_stream_set_periph_address(
    DMA2,
    DMA_STREAM5,
    (u32) &TIM1->CCR4
  );

  dma_stream_set_memory_address(
    DMA2,
    DMA_STREAM5,
    DMA_STREAM_MEMORY0,
    (u32) arr
  );

  dma_stream_set_items_transfer_count(DMA2, DMA_STREAM5, ARR_SIZE(arr));
  dma_stream_set_channel(DMA2, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  dma_stream_set_priority(DMA2, DMA_STREAM5, DMA_STREAM_PRIORITY_VERY_HIGH);
  dma_stream_direct_mode_enable(DMA2, DMA_STREAM5);

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
timer_sys_setup(void)
{
  tim_set_prescaler(TIM2, 3);
  tim_set_clock_division(TIM2, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM2, 24);
  tim_set_counter_direction(TIM2, TIM_COUNTER_DIRECTION_UP);
  tim_set_cc_value(TIM2, TIM_CHANNEL4, 0);
  tim_interrupt_enable(TIM2, TIM_INTERRUPT_UPDATE);
  nvic_irq_enable(NVIC_IRQ_TIM2);
}

void
adc_setup(void)
{
  u32 sequence[] = { ADC_REG_CHANNEL0 };
  adc_set_reg_sequence(ADC1, sequence, ARR_SIZE(sequence));
  adc_set_channel_sample_rate(ADC1, ADC_REG_CHANNEL0, ADC_SAMPLE_RATE_480CYCLES);
  adc_enable(ADC1);
}

volatile u32 delay;

void
tim2_isr(void)
{
  tim_flag_clear(TIM2, TIM_FLAG_UPDATE);
  nvic_clear_pending_irq(NVIC_IRQ_TIM2);

  if (delay > 0)
  {
    --delay;
  }
}

void
delay_us(u32 us)
{
  tim_set_counter_value(TIM2, 0);
  delay = us;
  tim_counter_enable(TIM2);
  while (delay > 0);
  tim_counter_disable(TIM2);

  cm_dmb();
}

int
main(void)
{
  fpu_set_access_level(FPU_ACCESS_LEVEL_FULL);

  struct dshot_config conf;
  conf.motor_speed = dshot_motor_speed_percentage(0);
  conf.telemetry = 0;
  u32 frame = dshot_pack_frame(&conf);
  dshot_calc_periods(frame, arr);

  rcc_setup();
  gpio_setup();
  adc_setup();
  dma_setup();
  timer_setup();
  timer_sys_setup();

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

        // If the ESC receives a throttle value > 2048,
        // it immediately shuts down the motor.
        if (speed > 100)
        {
          speed = 100;
        }

        conf.motor_speed = dshot_motor_speed_percentage(speed);
        frame = dshot_pack_frame(&conf);
        dshot_calc_periods(frame, arr);
      }

      delay_us(25);
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

