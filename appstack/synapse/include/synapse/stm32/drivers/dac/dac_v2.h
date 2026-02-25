#ifndef STM32_DRIVER_DAC_H
#define STM32_DRIVER_DAC_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F1x
 */

BEGIN_DECLARATIONS

struct dac_registers_map
{
  u32 CR;
  u32 SWTRIGR;
  u32 DHR12R1;
  u32 DHR12L1;
  u32 DHR8R1;
  u32 DHR12R2;
  u32 DHR12L2;
  u32 DHR8R2;
  u32 DHR12RD;
  u32 DHR12LD;
  u32 DHR8RD;
  u32 DOR1;
  u32 DOR2;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#define DAC_CR_CHANNEL_SZ (16)

enum dac_cr : u32
{
  DAC_CR_EN1 = (1 << 0),
  DAC_CR_BOFF1 = (1 << 1),
  DAC_CR_TEN1 = (1 << 2),
  DAC_CR_DMAEN1 = (1 << 12),
  DAC_CR_EN2 = (1 << 16),
  DAC_CR_BOFF2 = (1 << 17),
  DAC_CR_TEN2 = (1 << 18),
  DAC_CR_DMAEN2 = (1 << 28)
};

/* Bits[5:3] */
#define DAC_CR_TSEL1_SHIFT (3)
#define DAC_CR_TSEL1_MASK (0x7u)

/* Bits[21:19] */
#define DAC_CR_TSEL2_SHIFT (19)
#define DAC_CR_TSEL2_MASK (0x7u)

enum dac_cr_tsel : u32
{
  DAC_CR_TSEL_TIM6_TRGO = 0b000,
  DAC_CR_TSEL_TIM3_TRGO = 0b001,
  DAC_CR_TSEL_TIM7_TRGO = 0b010,
  DAC_CR_TSEL_TIM5_TRGO = 0b011,
  DAC_CR_TSEL_TIM2_TRGO = 0b100,
  DAC_CR_TSEL_TIM4_TRGO = 0b101,
  DAC_CR_TSEL_EXT_LINE9 = 0b110,
  DAC_CR_TSEL_SWTRG = 0b111
};

/* Bits[7:6] */
#define DAC_CR_WAVE1_SHIFT (6)
#define DAC_CR_WAVE1_MASK (0x3u)

/* Bits[23:22] */
#define DAC_CR_WAVE2_SHIFT (22)
#define DAC_CR_WAVE2_MASK (0x3u)

enum dac_cr_wave : u32
{
  DAC_CR_WAVE_DISABLE = 0b00,
  DAC_CR_WAVE_NOISE = 0b01,
  DAC_CR_WAVE_TRIANGLE = 0b10
};

/* Bits[11:8] */
#define DAC_CR_MAMP1_SHIFT (8)
#define DAC_CR_MAMP1_MASK (0xfu)

/* Bits[27:24] */
#define DAC_CR_MAMP2_SHIFT (24)
#define DAC_CR_MAMP2_MASK (0xfu)

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
  DAC_SWTRIGR_SWTRIG2 = (1 << 1)
};

/* Bits[11:0] */
#define DAC_DHR12R1_DACC1DHR_SHIFT (0)
#define DAC_DHR12R1_DACC1DHR_MASK (0xfffu)

/* Bits[15:4] */
#define DAC_DHR12L1_DACC1DHR_SHIFT (4)
#define DAC_DHR12L1_DACC1DHR_MASK (0xfffu)

/* Bits[7:0] */
#define DAC_DHR8R1_DACC1DHR_SHIFT (0)
#define DAC_DHR8R1_DACC1DHR_MASK (0xffu)

/* Bits[11:0] */
#define DAC_DHR12R2_DACC2DHR_SHIFT (0)
#define DAC_DHR12R2_DACC2DHR_MASK (0xfffu)

/* Bits[15:4] */
#define DAC_DHR12L2_DACC2DHR_SHIFT (4)
#define DAC_DHR12L2_DACC2DHR_MASK (0xfffu)

/* Bits[7:0] */
#define DAC_DHR8R2_DACC2DHR_SHIFT (0)
#define DAC_DHR8R2_DACC2DHR_MASK (0xffu)

/* Bits[11:0] */
#define DAC_DHR12RD_DACC1DHR_SHIFT (0)
#define DAC_DHR12RD_DACC1DHR_MASK (0xfffu)

/* Bits[27:16] */
#define DAC_DHR12RD_DACC2DHR_SHIFT (16)
#define DAC_DHR12RD_DACC2DHR_MASK (0xfffu)

/* Bits[15:4] */
#define DAC_DHR12LD_DACC1DHR_SHIFT (4)
#define DAC_DHR12LD_DACC1DHR_MASK (0xfffu)

/* Bits[31:20] */
#define DAC_DHR12LD_DACC2DHR_SHIFT (20)
#define DAC_DHR12LD_DACC2DHR_MASK (0xfffu)

/* Bits[7:0] */
#define DAC_DHR8RD_DACC1DHR_SHIFT (0)
#define DAC_DHR8RD_DACC1DHR_MASK (0xffu)

/* Bits[15:8] */
#define DAC_DHR8RD_DACC2DHR_SHIFT (8)
#define DAC_DHR8RD_DACC2DHR_MASK (0xffu)

/* Bits[11:0] */
#define DAC_DOR1_DACC1DOR_SHIFT (0)
#define DAC_DOR1_DACC1DOR_MASK (0xfffu)

/* Bits[11:0] */
#define DAC_DOR2_DACC2DOR_SHIFT (0)
#define DAC_DOR2_DACC2DOR_MASK (0xfffu)

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum dac_channel
{
  DAC_CHANNEL1,
  DAC_CHANNEL2
};

enum dac_alignment
{
  DAC_ALIGNMENT_RIGHT,
  DAC_ALIGNMENT_LEFT
};

enum dac_channel_trigger
{
  DAC_CHANNEL_TRIGGER_TIM6,
  DAC_CHANNEL_TRIGGER_TIM3,
  DAC_CHANNEL_TRIGGER_TIM7,
  DAC_CHANNEL_TRIGGER_TIM5,
  DAC_CHANNEL_TRIGGER_TIM2,
  DAC_CHANNEL_TRIGGER_TIM4,
  DAC_CHANNEL_TRIGGER_EXT_LINE9,
  DAC_CHANNEL_TRIGGER_SOFTWARE
};

enum dac_wave
{
  DAC_WAVE_OFF,
  DAC_WAVE_NOISE,
  DAC_WAVE_TRIANGLE
};

enum dac_amplitude
{
  DAC_AMPLITUDE1,
  DAC_AMPLITUDE3,
  DAC_AMPLITUDE7,
  DAC_AMPLITUDE15,
  DAC_AMPLITUDE31,
  DAC_AMPLITUDE63,
  DAC_AMPLITUDE127,
  DAC_AMPLITUDE255,
  DAC_AMPLITUDE511,
  DAC_AMPLITUDE1023,
  DAC_AMPLITUDE2047,
  DAC_AMPLITUDE4095
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
dac_channel_buffer_enable(
    enum dac_channel channel
);

void
dac_channel_buffer_disable(
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
dac_set_channel_trigger(
    enum dac_channel channel,
  enum dac_channel_trigger trigger
);

void
dac_set_channel_wave(
    enum dac_channel channel,
  enum dac_wave wave
);

void
dac_set_channel_amplitude(
    enum dac_channel channel,
  enum dac_amplitude amplitude
);

void
dac_dma_enable(
    enum dac_channel channel
);

void
dac_dma_disable(
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
dac_set_channel_8bit_data(
    enum dac_channel channel,
  u32 data
);

void
dac_set_channels_12bit_data(
    enum dac_alignment alignment,
  u32 ch1_data,
  u32 ch2_data
);

void
dac_set_channels_8bit_data(
    u32 ch1_data,
  u32 ch2_data
);

u32
dac_get_channel_output_data(
    enum dac_channel channel
);

END_DECLARATIONS

#endif
