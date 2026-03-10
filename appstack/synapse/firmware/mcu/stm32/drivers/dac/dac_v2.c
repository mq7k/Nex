#include "synapse/stm32/drivers/dac/dac_v2.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"

typedef volatile struct dac_registers_map dac_periph;
dac_periph* DAC = (dac_periph*) (DAC_ADDR);

void
dac_channel_enable(
    enum dac_channel channel
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR |= DAC_CR_EN1;
      break;

    case DAC_CHANNEL2:
      DAC->CR |= DAC_CR_EN2;
      break;

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
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR &= ~DAC_CR_EN1;
      break;

    case DAC_CHANNEL2:
      DAC->CR &= ~DAC_CR_EN2;
      break;

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_buffer_enable(
    enum dac_channel channel
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR |= DAC_CR_BOFF1;
      break;

    case DAC_CHANNEL2:
      DAC->CR |= DAC_CR_BOFF2;
      break;

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_channel_buffer_disable(
    enum dac_channel channel
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR &= ~DAC_CR_BOFF1;
      break;

    case DAC_CHANNEL2:
      DAC->CR &= ~DAC_CR_BOFF2;
      break;

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
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR |= DAC_CR_TEN1;
      break;

    case DAC_CHANNEL2:
      DAC->CR |= DAC_CR_TEN2;
      break;

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
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR &= ~DAC_CR_TEN1;
      break;

    case DAC_CHANNEL2:
      DAC->CR &= ~DAC_CR_TEN2;
      break;

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_set_channel_trigger(
    enum dac_channel channel,
  enum dac_channel_trigger trigger
)
{
  devmode_assert_lower_or_eq(channel, DAC_CHANNEL2);

  volatile u32* reg = &DAC->CR;
  const u32 shift = channel == 0 ? DAC_CR_TSEL1_SHIFT : DAC_CR_TSEL2_SHIFT;
  const u32 mask = (channel == 0 ? DAC_CR_TSEL1_MASK : DAC_CR_TSEL2_MASK) << shift;
  
  switch (trigger)
  {
    case DAC_CHANNEL_TRIGGER_TIM6:
      *reg &= ~mask;
      break;

    case DAC_CHANNEL_TRIGGER_TIM3:
      syn_set_register_bits(reg, mask, DAC_CR_TSEL_TIM3_TRGO << shift);
      break;

    case DAC_CHANNEL_TRIGGER_TIM7:
      syn_set_register_bits(reg, mask, DAC_CR_TSEL_TIM7_TRGO << shift);
      break;

    case DAC_CHANNEL_TRIGGER_TIM5:
      syn_set_register_bits(reg, mask, DAC_CR_TSEL_TIM5_TRGO << shift);
      break;

    case DAC_CHANNEL_TRIGGER_TIM2:
      syn_set_register_bits(reg, mask, DAC_CR_TSEL_TIM2_TRGO << shift);
      break;

    case DAC_CHANNEL_TRIGGER_TIM4:
      syn_set_register_bits(reg, mask, DAC_CR_TSEL_TIM4_TRGO << shift);
      break;

    case DAC_CHANNEL_TRIGGER_EXT_LINE9:
      syn_set_register_bits(reg, mask, DAC_CR_TSEL_EXT_LINE9 << shift);
      break;

    case DAC_CHANNEL_TRIGGER_SOFTWARE:
      // syn_set_register_bits(reg, mask, DAC_CR_TSEL_SWTRG << shift);
      *reg |= (DAC_CR_TSEL_SWTRG << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dac_channel_trigger, trigger);
      break;
  }
}

void
dac_set_channel_wave(
    enum dac_channel channel,
  enum dac_wave wave
)
{
  devmode_assert_lower_or_eq(channel, DAC_CHANNEL2);

  volatile u32* reg = &DAC->CR;
  const u32 shift = channel == 0 ? DAC_CR_WAVE1_SHIFT : DAC_CR_WAVE2_SHIFT;
  const u32 mask = (channel == 0 ? DAC_CR_WAVE1_MASK : DAC_CR_WAVE2_MASK) << shift;

  switch (wave)
  {
    case DAC_WAVE_OFF:
      *reg &= ~mask;
      break;

    case DAC_WAVE_NOISE:
      syn_set_register_bits(reg, mask, DAC_CR_WAVE_NOISE << shift);
      break;

    case DAC_WAVE_TRIANGLE:  
      *reg |= (DAC_CR_WAVE_TRIANGLE << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dac_wave, wave);
      break;
  }
}

void
dac_set_channel_amplitude(
    enum dac_channel channel,
  enum dac_amplitude amplitude
)
{
  devmode_assert_lower_or_eq(channel, DAC_CHANNEL2);

  volatile u32* reg = &DAC->CR;
  const u32 shift = channel == 0 ? DAC_CR_MAMP1_SHIFT : DAC_CR_MAMP2_SHIFT;
  const u32 mask = (channel == 0 ? DAC_CR_MAMP1_MASK : DAC_CR_MAMP2_MASK) << shift;

  switch (amplitude)
  {
    case DAC_AMPLITUDE1:
      *reg &= ~mask;
      break;

    case DAC_AMPLITUDE3:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE3 << shift);
      break;

    case DAC_AMPLITUDE7:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE7 << shift);
      break;

    case DAC_AMPLITUDE15:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE15 << shift);
      break;

    case DAC_AMPLITUDE31:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE31 << shift);
      break;

    case DAC_AMPLITUDE63:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE63 << shift);
      break;

    case DAC_AMPLITUDE127:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE127 << shift);
      break;

    case DAC_AMPLITUDE255:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE255 << shift);
      break;

    case DAC_AMPLITUDE511:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE511 << shift);
      break;

    case DAC_AMPLITUDE1023:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE1023 << shift);
      break;

    case DAC_AMPLITUDE2047:
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE2047 << shift);
      break;

    case DAC_AMPLITUDE4095:  
      syn_set_register_bits(reg, mask, DAC_CR_MAMP_AMPLITUDE4095 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dac_amplitude, amplitude);
      break;
  }
}

void
dac_dma_enable(
    enum dac_channel channel
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR |= DAC_CR_DMAEN1;
      break;

    case DAC_CHANNEL2:
      DAC->CR |= DAC_CR_DMAEN2;
      break;
      
    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_dma_disable(
    enum dac_channel channel
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->CR &= ~DAC_CR_DMAEN1;
      break;

    case DAC_CHANNEL2:
      DAC->CR &= ~DAC_CR_DMAEN2;
      break;

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
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
      break;

    case DAC_CHANNEL2:
      DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG2;
      break;

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
  switch (channel)
  {
    case DAC_CHANNEL1:
      DAC->SWTRIGR &= ~DAC_SWTRIGR_SWTRIG1;
      break;

    case DAC_CHANNEL2:
      DAC->SWTRIGR &= ~DAC_SWTRIGR_SWTRIG2;
      break;

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
    {
      constexpr u32 shift = DAC_DHR12R1_DACC1DHR_SHIFT;
      constexpr u32 mask = DAC_DHR12R1_DACC1DHR_MASK;

      syn_set_register_bits(
        &DAC->DHR12R1,
        mask << shift,
        (data & mask) << shift
      );

      break;
    }
    case DAC_CHANNEL2:
    {
      constexpr u32 shift = DAC_DHR12R2_DACC2DHR_SHIFT;
      constexpr u32 mask = DAC_DHR12R2_DACC2DHR_MASK;

      syn_set_register_bits(
        &DAC->DHR12R2,
        mask << shift,
        (data & mask) << shift
      );

      break;
    }

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
    {
      constexpr u32 shift = DAC_DHR12L1_DACC1DHR_SHIFT;
      constexpr u32 mask = DAC_DHR12L1_DACC1DHR_MASK;
      devmode_assert_lower_or_eq(data, mask);

      syn_set_register_bits(
        &DAC->DHR12L1,
        mask << shift,
        (data & mask) << shift
      );

      break;
    }
    case DAC_CHANNEL2:
    {
      constexpr u32 shift = DAC_DHR12L2_DACC2DHR_SHIFT;
      constexpr u32 mask = DAC_DHR12L2_DACC2DHR_MASK;
      devmode_assert_lower_or_eq(data, mask);

      syn_set_register_bits(
        &DAC->DHR12L2,
        mask << shift,
        (data & mask) << shift
      );

      break;
    }

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_set_channel_8bit_data(
    enum dac_channel channel,
  u32 data
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
    {
      constexpr u32 shift = DAC_DHR8R1_DACC1DHR_SHIFT;
      constexpr u32 mask = DAC_DHR8R1_DACC1DHR_MASK;
      devmode_assert_lower_or_eq(data, mask);

      syn_set_register_bits(
        &DAC->DHR8R1,
        mask << shift,
        (data & mask) << shift
      );

      break;
    }
    case DAC_CHANNEL2:
    {
      constexpr u32 shift = DAC_DHR8R2_DACC2DHR_SHIFT;
      constexpr u32 mask = DAC_DHR8R2_DACC2DHR_MASK;
      devmode_assert_lower_or_eq(data, mask);

      syn_set_register_bits(
        &DAC->DHR8R2,
        mask << shift,
        (data & mask) << shift
      );

      break;
    }

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      break;
  }
}

void
dac_set_channels_12bit_data(
    enum dac_alignment alignment,
  u32 ch1_data,
  u32 ch2_data
)
{
  devmode_assert_lower_or_eq(ch1_data, DAC_DHR12RD_DACC1DHR_MASK);
  devmode_assert_lower_or_eq(ch2_data, DAC_DHR12RD_DACC2DHR_MASK);
  u32 reg;

  switch (alignment)
  {
    case DAC_ALIGNMENT_RIGHT:
      ch1_data <<= DAC_DHR12RD_DACC1DHR_SHIFT;
      ch2_data <<= DAC_DHR12RD_DACC2DHR_SHIFT;

      reg = ch1_data | ch2_data;

      DAC->DHR12RD = reg;
      break;

    case DAC_ALIGNMENT_LEFT:
      ch1_data <<= DAC_DHR12LD_DACC1DHR_SHIFT;
      ch2_data <<= DAC_DHR12LD_DACC2DHR_SHIFT;

      reg = ch1_data | ch2_data;

      DAC->DHR12LD = reg;
      break;

    default:
      devmode_error_invalid_enum(enum alignment, alignment);
      break;
  }
}

void
dac_set_channels_8bit_data(
    u32 ch1_data,
  u32 ch2_data
)
{
  devmode_assert_lower_or_eq(ch1_data, DAC_DHR8RD_DACC1DHR_MASK);
  devmode_assert_lower_or_eq(ch2_data, DAC_DHR8RD_DACC2DHR_MASK);
  ch1_data <<= DAC_DHR8RD_DACC1DHR_SHIFT;
  ch2_data <<= DAC_DHR8RD_DACC2DHR_SHIFT;

  u32 reg = ch1_data | ch2_data;
  DAC->DHR8RD = reg;
}

u32
dac_get_channel_output_data(
    enum dac_channel channel
)
{
  switch (channel)
  {
    case DAC_CHANNEL1:
      return DAC->DOR1 & DAC_DOR1_DACC1DOR_MASK;

    case DAC_CHANNEL2:
      return DAC->DOR2 & DAC_DOR2_DACC2DOR_MASK;

    default:
      devmode_error_invalid_enum(enum dac_channel, channel);
      return 0;
  }
}
