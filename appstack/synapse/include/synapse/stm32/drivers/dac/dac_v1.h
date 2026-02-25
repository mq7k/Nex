#ifndef STM32_DAC_H
#define STM32_DAC_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct dac_registers_map
{
  u32 CR;
  u32 SWTRIGR;
  u32 DHR12R1;
  u32 DHR12L1;
  u32 DHR8R1;

#if defined(STM32_DAC_CHANNEL2)
  u32 DHR12R2;
  u32 DHR12L2;
  u32 DHR8R2;
#else
  u32 _reserved0[3];
#endif
  
#if defined(STM32_DAC_CHANNEL_COMMON)
  u32 DHR12RD;
  u32 DHR12LD;
  u32 DHR8RD;
#else
  u32 _reserved1[3];
#endif

  u32 DOR1;

#if defined(STM32_DAC_CHANNEL2)
  u32 DOR2;
#else
  u32 _reserved2;
#endif

  u32 SR;
};

enum dac_cr : u32
{
  DAC_CR_EN1 = (1 << 0),
  DAC_CR_BOFF1 = (1 << 1),
  DAC_CR_TEN1 = (1 << 2),
  DAC_CR_DMAEN1 = (1 << 12),
  DAC_CR_DMAUDRIE1 = (1 << 13),

#if defined(STM32_DAC_CHANNEL2)
  DAC_CR_EN2 = (1 << 16),
  DAC_CR_BOFF2 = (1 << 17),
  DAC_CR_TEN2 = (1 << 18),
  DAC_CR_DMAEN2 = (1 << 28),
  DAC_CR_DMAUDRIE2 = (1 << 29)
#endif
};

#define DAC_CR_TSEL1_SHIFT (3)
#define DAC_CR_TSEL1_MASK (0x7u)

#if defined(STM32_DAC_CHANNEL2)
#define DAC_CR_TSEL2_SHIFT (19)
#define DAC_CR_TSEL2_MASK (0x7u)
#endif

enum dac_cr_tsel : u32
{
#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC_CR_TSEL_TIM6_TRGO = 0b000,
  DAC_CR_TSEL_TIM8_TRGO = 0b001,
  DAC_CR_TSEL_TIM7_TRGO = 0b010,
#endif

  DAC_CR_TSEL_TIM5_TRGO = 0b011,

#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC_CR_TSEL_TIM2_TRGO = 0b100,
  DAC_CR_TSEL_TIM4_TRGO = 0b101,
#endif

  DAC_CR_TSEL_EXTERNAL_LINE9 = 0b110,
  DAC_CR_TSEL_SOFTWARE_TRIGGER = 0b111
};

#define DAC_CR_WAVE1_SHIFT (6)
#define DAC_CR_WAVE1_MASK (0x3u)

#if defined(STM32_DAC_CHANNEL2)
#define DAC_CR_WAVE2_SHIFT (22)
#define DAC_CR_WAVE2_MASK (0x3u)
#endif

enum dac_cr_wave : u32
{
  DAC_CR_WAVE_OFF = 0b00,
  DAC_CR_WAVE_NOISE = 0b01,
  DAC_CR_WAVE_TRIANGLE = 0b10
};

#define DAC_CR_MAMP1_SHIFT (8)
#define DAC_CR_MAMP1_MASK (0xfu)

#if defined(STM32_DAC_CHANNEL2)
#define DAC_CR_MAMP2_SHIFT (24)
#define DAC_CR_MAMP2_MASK (0xfu)
#endif

enum dac_cr_mamp : u32
{
  DAC_CR_MAMP_AMPLITUDE1 = 0b0000,
  DAC_CR_MAMP_AMPLITUDE3 = 0b0001,
  DAC_CR_MAMP_AMPLITUDE7 = 0b0010,
  DAC_CR_MAMP_AMPLITUDE15 = 0b0011,
  DAC_CR_MAMP_AMPLITUDE31 = 0b0100,
  DAC_CR_MAMP_AMPLITUDE63 = 0b0101,
  DAC_CR_MAMP_AMPLITUDE127 = 0b0110,
  DAC_CR_MAMP_AMPLITUDE255 = 0b0111,
  DAC_CR_MAMP_AMPLITUDE511 = 0b1000,
  DAC_CR_MAMP_AMPLITUDE1023 = 0b1001,
  DAC_CR_MAMP_AMPLITUDE2047 = 0b1010,
  DAC_CR_MAMP_AMPLITUDE4095 = 0b1011
};

enum dac_swtrigr : u32
{
  DAC_SWTRIGR_SWTRIG1 = (1 << 0),

#if defined(STM32_DAC_CHANNEL2)
  DAC_SWTRIGR_SWTRIG2 = (1 << 1)
#endif
};

#define DAC_DHR12R1_SHIFT (0)
#define DAC_DHR12R1_MASK (0xfff)

#define DAC_DHR12L1_SHIFT (4)
#define DAC_DHR12L1_MASK (0xfff)

#define DAC_DHR8R1_SHIFT (0)
#define DAC_DHR8R1_MASK (0xff)

#if defined(STM32_DAC_CHANNEL2)
#define DAC_DHR12R2_SHIFT (0)
#define DAC_DHR12R2_MASK (0xfff)

#define DAC_DHR12L2_SHIFT (4)
#define DAC_DHR12L2_MASK (0xfff)

#define DAC_DHR8R2_SHIFT (0)
#define DAC_DHR8R2_MASK (0xff)
#endif

#if defined(STM32_DAC_CHANNEL_COMMON)
#define DAC_DHR12RD_DACC1DHR_SHIFT (0)
#define DAC_DHR12RD_DACC1DHR_MASK (0xfff)

#define DAC_DHR12RD_DACC2DHR_SHIFT (16)
#define DAC_DHR12RD_DACC2DHR_MASK (0xfff)

#define DAC_DHR12LD_DACC1DHR_SHIFT (4)
#define DAC_DHR12LD_DACC1DHR_MASK (0xfff)

#define DAC_DHR12LD_DACC2DHR_SHIFT (20)
#define DAC_DHR12LD_DACC2DHR_MASK (0xfff)

#define DAC_DHR8RD_DACC1DHR_SHIFT (0)
#define DAC_DHR8RD_DACC1DHR_MASK (0xff)

#define DAC_DHR8RD_DACC2DHR_SHIFT (8)
#define DAC_DHR8RD_DACC2DHR_MASK (0xff)
#endif

enum dac_sr : u32
{
  DAC_SR_DMAUDR1 = (1 << 13),
  DAC_SR_DMAUDR2 = (1 << 29)
};


// API
enum dac_channel
{
  DAC_CHANNEL1,

#if defined(STM32_DAC_CHANNEL2)
  DAC_CHANNEL2
#endif
};

enum dac_channel_trigger
{
#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC_CHANNEL_TRIGGER_TIM6_TRGO,
  DAC_CHANNEL_TRIGGER_TIM8_TRGO,
  DAC_CHANNEL_TRIGGER_TIM7_TRGO,
#endif

  DAC_CHANNEL_TRIGGER_TIM5_TRGO,

#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC_CHANNEL_TRIGGER_TIM2_TRGO,
  DAC_CHANNEL_TRIGGER_TIM4_TRGO,
#endif

  DAC_CHANNEL_TRIGGER_EXTERNAL_LINE9,
  DAC_CHANNEL_TRIGGER_SOFTWARE_TRIGGER
};

enum dac_channel_wave
{
  DAC_CHANNEL_WAVE_OFF,
  DAC_CHANNEL_WAVE_NOISE,
  DAC_CHANNEL_WAVE_TRIANGLE
};

enum dac_channel_amplitude
{
  DAC_CHANNEL_AMPLITUDE1,
  DAC_CHANNEL_AMPLITUDE3,
  DAC_CHANNEL_AMPLITUDE7,
  DAC_CHANNEL_AMPLITUDE15,
  DAC_CHANNEL_AMPLITUDE31,
  DAC_CHANNEL_AMPLITUDE63,
  DAC_CHANNEL_AMPLITUDE127,
  DAC_CHANNEL_AMPLITUDE255,
  DAC_CHANNEL_AMPLITUDE511,
  DAC_CHANNEL_AMPLITUDE1023,
  DAC_CHANNEL_AMPLITUDE2047,
  DAC_CHANNEL_AMPLITUDE4095
};

extern volatile struct dac_registers_map* DAC;

void
dac_channel_enable(
  enum dac_channel channel
);

void
dac_channel_disable(
  enum dac_channel channel
);

void
dac_channel_output_buffer_enable(
  enum dac_channel channel
);

void
dac_channel_output_buffer_disable(
  enum dac_channel channel
);

void
dac_channel_trigger_enable(
  enum dac_channel channel
);

void
dac_channel_trigger_disable(
  enum dac_channel channel
);

void
dac_channel_set_trigger(
  enum dac_channel channel,
  enum dac_channel_trigger trigger
);

void
dac_channel_set_wave(
  enum dac_channel channel,
  enum dac_channel_wave wave
);

void
dac_set_channel_amplitude(
  enum dac_channel channel,
  enum dac_channel_amplitude amplitude
);

void
dac_channel_dma_enable(
  enum dac_channel channel
);

void
dac_channel_dma_disable(
  enum dac_channel channel
);

void
dac_channel_dma_underrun_interrupt_enable(
  enum dac_channel channel
);

void
dac_channel_dma_underrun_interrupt_disable(
  enum dac_channel channel
);

void
dac_channel_software_trigger_enable(
  enum dac_channel channel
);

void
dac_channel_software_trigger_disable(
  enum dac_channel channel
);

void
dac_set_channel_12bit_right_aligned_data(
  enum dac_channel channel,
  u32 data
);

void
dac_set_channel_12bit_left_aligned_data(
  enum dac_channel channel,
  u32 data
);

void
dac_set_channel_8bit_right_aligned_data(
  enum dac_channel channel,
  u32 data
);

#if defined(STM32_DAC_CHANNEL_COMMON)
void
dac_set_channels_12bit_right_aligned_data(
  u32 ch1_data,
  u32 ch2_data
);

void
dac_set_channels_12bit_left_aligned_data(
  u32 ch1_data,
  u32 ch2_data
);

void
dac_set_channels_8bit_data(
  u32 ch1_data,
  u32 ch2_data
);
#endif

u32
dac_get_channel_output_data(
  enum dac_channel channel
);

u32
dac_is_dma_underrun_flag_set(
  enum dac_channel channel
);

void
dac_dma_underrun_flag_clear(
  enum dac_channel channel
);

END_DECLARATIONS

#endif
