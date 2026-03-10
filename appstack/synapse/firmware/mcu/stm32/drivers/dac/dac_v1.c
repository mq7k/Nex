#include "synapse/stm32/drivers/dac/dac_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct dac_registers_map dac_periph;
dac_periph* DAC = (dac_periph*) (DAC_ADDR);

static enum dac_cr_tsel
convert_dac_tsel_api_to_impl(
  enum dac_channel_trigger trigger
)
{
  switch (trigger)
  {
#if defined(STM32_DAC_TSEL_EXTENDED)
    case DAC_CHANNEL_TRIGGER_TIM6_TRGO:
      return DAC_CR_TSEL_TIM6_TRGO;

    case DAC_CHANNEL_TRIGGER_TIM8_TRGO:
      return DAC_CR_TSEL_TIM8_TRGO;

    case DAC_CHANNEL_TRIGGER_TIM7_TRGO:
      return DAC_CR_TSEL_TIM7_TRGO;
#endif

    case DAC_CHANNEL_TRIGGER_TIM5_TRGO:
      return DAC_CR_TSEL_TIM5_TRGO;

#if defined(STM32_DAC_TSEL_EXTENDED)
    case DAC_CHANNEL_TRIGGER_TIM2_TRGO:
      return DAC_CR_TSEL_TIM2_TRGO;

    case DAC_CHANNEL_TRIGGER_TIM4_TRGO:
      return DAC_CR_TSEL_TIM4_TRGO;
#endif

    case DAC_CHANNEL_TRIGGER_EXTERNAL_LINE9:
      return DAC_CR_TSEL_EXTERNAL_LINE9;

    case DAC_CHANNEL_TRIGGER_SOFTWARE_TRIGGER:
      return DAC_CR_TSEL_SOFTWARE_TRIGGER;

    default:
      devmode_error_invalid_enum(enum dac_channel_trigger, trigger);
      return 0;
  }
}

static enum dac_cr_wave
convert_dac_wave_api_to_impl(
  enum dac_channel_wave wave
)
{
  switch (wave)
  {
    case DAC_CHANNEL_WAVE_OFF:
      return DAC_CR_WAVE_OFF;

    case DAC_CHANNEL_WAVE_NOISE:
      return DAC_CR_WAVE_NOISE;

    case DAC_CHANNEL_WAVE_TRIANGLE:
      return DAC_CR_WAVE_TRIANGLE;

    default:
      devmode_error_invalid_enum(enum dac_channel_wave, wave);
      return 0;
  }
}

static enum dac_cr_mamp
convert_dac_amplitude_api_to_impl(
  enum dac_channel_amplitude amplitude
)
{
  switch (amplitude)
  {
    case DAC_CHANNEL_AMPLITUDE1:
      return DAC_CR_MAMP_AMPLITUDE1;

    case DAC_CHANNEL_AMPLITUDE3:
      return DAC_CR_MAMP_AMPLITUDE3;

    case DAC_CHANNEL_AMPLITUDE7:
      return DAC_CR_MAMP_AMPLITUDE7;

    case DAC_CHANNEL_AMPLITUDE15:
      return DAC_CR_MAMP_AMPLITUDE15;

    case DAC_CHANNEL_AMPLITUDE31:
      return DAC_CR_MAMP_AMPLITUDE31;

    case DAC_CHANNEL_AMPLITUDE63:
      return DAC_CR_MAMP_AMPLITUDE63;

    case DAC_CHANNEL_AMPLITUDE127:
      return DAC_CR_MAMP_AMPLITUDE127;

    case DAC_CHANNEL_AMPLITUDE255:
      return DAC_CR_MAMP_AMPLITUDE255;

    case DAC_CHANNEL_AMPLITUDE511:
      return DAC_CR_MAMP_AMPLITUDE511;

    case DAC_CHANNEL_AMPLITUDE1023:
      return DAC_CR_MAMP_AMPLITUDE1023;

    case DAC_CHANNEL_AMPLITUDE2047:
      return DAC_CR_MAMP_AMPLITUDE2047;

    case DAC_CHANNEL_AMPLITUDE4095:
      return DAC_CR_MAMP_AMPLITUDE4095;

    default:
      devmode_error_invalid_enum(enum dac_channel_amplitude, amplitude);
      return 0;
  }
}

void
dac_channel_enable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg |= DAC_CR_EN1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg |= DAC_CR_EN2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_disable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg &= ~DAC_CR_EN1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg &= ~DAC_CR_EN2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_output_buffer_enable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg |= DAC_CR_BOFF1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg |= DAC_CR_BOFF2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_output_buffer_disable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg &= ~DAC_CR_BOFF1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg &= ~DAC_CR_BOFF2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_trigger_enable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg |= DAC_CR_TEN1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg |= DAC_CR_TEN2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_trigger_disable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg &= ~DAC_CR_TEN1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg &= ~DAC_CR_TEN2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_set_trigger(
  enum dac_channel channel,
  enum dac_channel_trigger trigger
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DAC->CR;
  enum dac_cr_tsel tsel_bits = convert_dac_tsel_api_to_impl(trigger);

  switch (channel)
  {
    case DAC_CHANNEL1:
      shift = DAC_CR_TSEL1_SHIFT;
      mask = DAC_CR_TSEL1_MASK << shift;
      syn_set_register_bits(reg, mask, tsel_bits << shift);
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      shift = DAC_CR_TSEL2_SHIFT;
      mask = DAC_CR_TSEL2_MASK << shift;
      syn_set_register_bits(reg, mask, tsel_bits << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_set_wave(
  enum dac_channel channel,
  enum dac_channel_wave wave
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DAC->CR;
  enum dac_cr_wave wave_bits = convert_dac_wave_api_to_impl(wave);

  switch (channel)
  {
    case DAC_CHANNEL1:
      shift = DAC_CR_WAVE1_SHIFT;
      mask = DAC_CR_WAVE1_MASK << shift;
      syn_set_register_bits(reg, mask, wave_bits << shift);
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      shift = DAC_CR_WAVE2_SHIFT;
      mask = DAC_CR_WAVE2_MASK << shift;
      syn_set_register_bits(reg, mask, wave_bits << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_set_channel_amplitude(
  enum dac_channel channel,
  enum dac_channel_amplitude amplitude
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DAC->CR;
  enum dac_cr_mamp mamp_bits = convert_dac_amplitude_api_to_impl(amplitude);

  switch (channel)
  {
    case DAC_CHANNEL1:
      shift = DAC_CR_MAMP1_SHIFT;
      mask = DAC_CR_MAMP1_MASK << shift;
      syn_set_register_bits(reg, mask, mamp_bits << shift);
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      shift = DAC_CR_MAMP2_SHIFT;
      mask = DAC_CR_MAMP2_MASK << shift;
      syn_set_register_bits(reg, mask, mamp_bits << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_dma_enable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg |= DAC_CR_DMAEN1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg |= DAC_CR_DMAEN2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_dma_disable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg &= ~DAC_CR_DMAEN1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg &= ~DAC_CR_DMAEN2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_dma_underrun_interrupt_enable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg |= DAC_CR_DMAUDRIE1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg |= DAC_CR_DMAUDRIE2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_dma_underrun_interrupt_disable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->CR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg &= ~DAC_CR_DMAUDRIE1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg &= ~DAC_CR_DMAUDRIE2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_software_trigger_enable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->SWTRIGR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg |= DAC_SWTRIGR_SWTRIG1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg |= DAC_SWTRIGR_SWTRIG2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_software_trigger_disable(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->SWTRIGR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg &= ~DAC_SWTRIGR_SWTRIG1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg &= ~DAC_SWTRIGR_SWTRIG2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_set_channel_12bit_right_aligned_data(
  enum dac_channel channel,
  u32 data
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      devmode_assert_lower_or_eq(data, DAC_DHR12R1_MASK);
      DAC->DHR12R1 = (data << DAC_DHR12R1_SHIFT);
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      devmode_assert_lower_or_eq(data, DAC_DHR12R2_MASK);
      DAC->DHR12R2 = (data << DAC_DHR12R2_SHIFT);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_set_channel_12bit_left_aligned_data(
  enum dac_channel channel,
  u32 data
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      devmode_assert_lower_or_eq(data, DAC_DHR12L1_MASK);
      DAC->DHR12L1 = (data << DAC_DHR12L1_SHIFT);
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      devmode_assert_lower_or_eq(data, DAC_DHR12L2_MASK);
      DAC->DHR12L2 = (data << DAC_DHR12L2_SHIFT);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_set_channel_8bit_right_aligned_data(
  enum dac_channel channel,
  u32 data
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      devmode_assert_lower_or_eq(data, DAC_DHR8R1_MASK);
      DAC->DHR8R1 = (data << DAC_DHR8R1_SHIFT);
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      devmode_assert_lower_or_eq(data, DAC_DHR8R2_MASK);
      DAC->DHR8R2 = (data << DAC_DHR8R2_SHIFT);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

#if defined(STM32_DAC_CHANNEL_COMMON)
void
dac_set_channels_12bit_right_aligned_data(
  u32 ch1_data,
  u32 ch2_data
)
{
  devmode_assert_lower_or_eq(ch1_data, DAC_DHR12RD_DACC1DHR_MASK);
  devmode_assert_lower_or_eq(ch2_data, DAC_DHR12RD_DACC2DHR_MASK);

  u32 data = 0;
  data |= (ch1_data << DAC_DHR12RD_DACC1DHR_SHIFT);
  data |= (ch2_data << DAC_DHR12RD_DACC2DHR_SHIFT);
  DAC->DHR12RD = data;
}

void
dac_set_channels_12bit_left_aligned_data(
  u32 ch1_data,
  u32 ch2_data
)
{
  devmode_assert_lower_or_eq(ch1_data, DAC_DHR12LD_DACC1DHR_MASK);
  devmode_assert_lower_or_eq(ch2_data, DAC_DHR12LD_DACC2DHR_MASK);

  u32 data = 0;
  data |= (ch1_data << DAC_DHR12LD_DACC1DHR_SHIFT);
  data |= (ch2_data << DAC_DHR12LD_DACC2DHR_SHIFT);
  DAC->DHR12LD = data;
}

void
dac_set_channels_8bit_data(
  u32 ch1_data,
  u32 ch2_data
)
{
  devmode_assert_lower_or_eq(ch1_data, DAC_DHR8RD_DACC1DHR_MASK);
  devmode_assert_lower_or_eq(ch2_data, DAC_DHR8RD_DACC2DHR_MASK);

  u32 data = 0;
  data |= (ch1_data << DAC_DHR8RD_DACC1DHR_SHIFT);
  data |= (ch2_data << DAC_DHR8RD_DACC2DHR_SHIFT);
  DAC->DHR8RD = data;
}
#endif

u32
dac_get_channel_output_data(
  enum dac_channel channel
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      return DAC->DOR1;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      return DAC->DOR2;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      return 0;
  }
}

u32
dac_is_dma_underrun_flag_set(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->SR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      return *reg & DAC_SR_DMAUDR1;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      return *reg & DAC_SR_DMAUDR2;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      return 0;
  }
}

void
dac_dma_underrun_flag_clear(
  enum dac_channel channel
)
{
  volatile u32* reg = &DAC->SR;
  switch (channel)
  {
    case DAC_CHANNEL1:
      *reg |= DAC_SR_DMAUDR1;
      break;

#if defined(STM32_DAC_CHANNEL2)
    case DAC_CHANNEL2:
      *reg |= DAC_SR_DMAUDR2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}
