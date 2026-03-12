#ifndef STM32_DRIVER_SAI_H
#define STM32_DRIVER_SAI_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct sai_registers_map
{
#if defined(STM32_SAI_GCR)
  u32 GCR;
#else
  u32 _reserved0;
#endif

  u32 CR1;
  u32 CR2;
  u32 FRCR;
  u32 SLOTR;
  u32 IM;
  u32 SR;
  u32 CLRFR;
  u32 DR;
};

// Core

#if defined(STM32_SAI_GCR)
#define SAI_GCR_SYNCIN_SHIFT (0)
#define SAI_GCR_SYNCIN_MASK (0x3)

#define SAI_GCR_SYNCOUT_SHIFT (4)
#define SAI_GCR_SYNCOUT_MASK (0x3)

enum sai_cgr_syncout : u32
{
  SAI_CGR_SYNCOUT_NOSYNC = 0b00,
  SAI_CGR_SYNCOUT_SYNC_BLOCKA = 0b01,
  SAI_CGR_SYNCOUT_SYNC_BLOCKB = 0b10
};

#endif

enum sai_cr1 : u32
{
  SAI_CR1_LSBFIRST = (1 << 8),
  SAI_CR1_CKSTR = (1 << 9),
  SAI_CR1_MONO = (1 << 12),
  SAI_CR1_OUTDRIV = (1 << 13),
  SAI_CR1_SAIEN = (1 << 16),
  SAI_CR1_DMAEN = (1 << 17),
  SAI_CR1_NODIV = (1 << 19)
};

#define SAI_CR1_MODE_SHIFT (0)
#define SAI_CR1_MODE_MASK (0x3)

enum sai_cr1_mode : u32
{
  SAI_CR1_MODE_MASTER_TX = 0b00,
  SAI_CR1_MODE_MASTER_RX = 0b01,
  SAI_CR1_MODE_SLAVE_TX = 0b10,
  SAI_CR1_MODE_SLAVE_RX = 0b11
};

#define SAI_CR1_PRTCFG_SHIFT (2)
#define SAI_CR1_PRTCFG_MASK (0x3)

enum sai_cr1_prtcfg : u32
{
  SAI_CR1_PRTCFG_FREE = 0b00,
  SAI_CR1_PRTCFG_SPDIF = 0b01,
  SAI_CR1_PRTCFG_AC97 = 0b10
};

#define SAI_CR1_DS_SHIFT (5)
#define SAI_CR1_DS_MASK (0x7)

enum sai_cr1_ds : u32
{
  SAI_CR1_DS_8BIT = 0b010,
  SAI_CR1_DS_10BIT = 0b011,
  SAI_CR1_DS_16BIT = 0b100,
  SAI_CR1_DS_20BIT = 0b101,
  SAI_CR1_DS_24BIT = 0b110,
  SAI_CR1_DS_32BIT = 0b111
};

#define SAI_CR1_SYNCEN_SHIFT (10)
#define SAI_CR1_SYNCEN_MASK (0x3)

enum sai_cr1_syncen : u32
{
  SAI_CR1_SYNCEN_ASYNC = 0b00,
  SAI_CR1_SYNCEN_SYNC_INTERNAL = 0b01,
  SAI_CR1_SYNCEN_SYNC_EXTERNAL = 0b10
};

#define SAI_CR1_MCKDIV_SHIFT (20)
#define SAI_CR1_MCKDIV_MASK (0xf)

enum sai_cr2 : u32
{
  SAI_CR2_FFLUSH = (1 << 3),
  SAI_CR2_TRIS = (1 << 4),
  SAI_CR2_MUTE = (1 << 5),
  SAI_CR2_MUTEVAL = (1 << 6),
  SAI_CR2_CPL = (1 << 13)
};

#define SAI_CR2_FTH_SHIFT (0)
#define SAI_CR2_FTH_MASK (0x7)

enum sai_cr2_fth : u32
{
  SAI_CR2_FTH_FIFO_EMPTY = 0b000,
  SAI_CR2_FTH_1over4_FULL = 0b001,
  SAI_CR2_FTH_1over2_FULL = 0b010,
  SAI_CR2_FTH_3over4_FULL = 0b011,
  SAI_CR2_FTH_FULL = 0b100
};

#define SAI_CR2_MUTECNT_SHIFT (7)
#define SAI_CR2_MUTECNT_MASK (0x3f)

#define SAI_CR2_COMP_SHIFT (14)
#define SAI_CR2_COMP_MASK (0x3)

enum sai_cr2_comp : u32
{
  SAI_CR2_COMP_NOALGO = 0b00,
  SAI_CR2_COMP_uLAW_ALGO = 0b10,
  SAI_CR2_COMP_ALAW_ALGO = 0b11
};

enum sai_frcr : u32
{
  SAI_FRCR_FSDEF = (1 << 16),
  SAI_FRCR_FSPOL = (1 << 17),
  SAI_FRCR_FSOFF = (1 << 18)
};

#define SAI_FRCR_FRL_SHIFT (0)
#define SAI_FRCR_FRL_MASK (0xff)

#define SAI_FRCR_FSALL_SHIFT (8)
#define SAI_FRCR_FSALL_MASK (0x7f)

#define SAI_SLOTR_FBOFF_SHIFT (0)
#define SAI_SLOTR_FBOFF_MASK (0x1f)

#define SAI_SLOTR_SLOTSZ_SHIFT (6)
#define SAI_SLOTR_SLOTSZ_MASK (0x3)

enum sai_slotr_slotsz : u32
{
  SAI_SLOTR_SLOTSZ_DATASIZE = 0b00,
  SAI_SLOTR_SLOTSZ_16BIT = 0b01,
  SAI_SLOTR_SLOTSZ_32BIT = 0b10
};

#define SAI_SLOTR_NBSLOT_SHIFT (8)
#define SAI_SLOTR_NBSLOT_MASK (0xf)

#define SAI_SLOTR_SLOTEN_SHIFT (16)
#define SAI_SLOTR_SLOTEN_MAX_SLOT (15)

enum sai_im : u32
{
  SAI_IM_OVRUDRIE = (1 << 0),
  SAI_IM_MUTEDETIE = (1 << 1),
  SAI_IM_WCKCFGIE = (1 << 2),
  SAI_IM_FREQIE = (1 << 3),
  SAI_IM_CNRDYIE = (1 << 4),
  SAI_IM_AFSDETIE = (1 << 5),
  SAI_IM_LFSDETIE = (1 << 6)
};

enum sai_sr : u32
{
  SAI_SR_OVRUDR = (1 << 0),
  SAI_SR_MUTEDET = (1 << 1),
  SAI_SR_WCKCFG = (1 << 2),
  SAI_SR_FREQ = (1 << 3),
  SAI_SR_CNRDY = (1 << 4),
  SAI_SR_AFSDET = (1 << 5),
  SAI_SR_LFSDET = (1 << 6)
};

#define SAI_SR_FLTH_SHIFT (16)
#define SAI_SR_FLTH_MASK (0x7)

enum sai_sr_flvl : u32
{
  SAI_SR_FLVL_FIFO_EMPTY = 0b000,
  SAI_SR_FLVL_FIFO_BET_1over4_ZERO = 0b001,
  SAI_SR_FLVL_FIFO_BET_1over4_1over2 = 0b010,
  SAI_SR_FLVL_FIFO_BET_1over2_3over4 = 0b011,
  SAI_SR_FLVL_FIFO_BET_3over4_FULL = 0b100,
  SAI_SR_FLVL_FIFO_FULL = 0b101
};

enum sai_clrfr : u32
{
  SAI_CLRFR_COVRUDR = (1 << 0),
  SAI_CLRFR_CMUTEDET = (1 << 1),
  SAI_CLRFR_CWCKCFG = (1 << 2),
  SAI_CLRFR_CCNRDY = (1 << 4),
  SAI_CLRFR_CAFSDET = (1 << 5),
  SAI_CLRFR_CLFSDET = (1 << 6)
};

// API

#if defined(STM32_SAI_GCR)
enum sai_sync_out
{
  SAI_SYNC_OUT_NOSYNC,
  SAI_SYNC_OUT_SYNC_BLOCKA,
  SAI_SYNC_OUT_SYNC_BLOCKB
};
#endif

enum sai_block_mode
{
  SAI_BLOCK_MODE_MASTER_TX,
  SAI_BLOCK_MODE_MASTER_RX,
  SAI_BLOCK_MODE_SLAVE_TX,
  SAI_BLOCK_MODE_SLAVE_RX
};

enum sai_protocol
{
  SAI_PROTOCOL_FREE,
  SAI_PROTOCOL_SPDIF,
  SAI_PROTOCOL_AC97
};

enum sai_data_size
{
  SAI_DATA_SIZE_8BIT,
  SAI_DATA_SIZE_10BIT,
  SAI_DATA_SIZE_16BIT,
  SAI_DATA_SIZE_20BIT,
  SAI_DATA_SIZE_24BIT,
  SAI_DATA_SIZE_32BIT
};

enum sai_endianess
{
  SAI_ENDIANESS_MSB_FIRST,
  SAI_ENDIANESS_LSB_FIRST
};

enum sai_clock_strobe
{
  SAI_CLOCK_STROBE_GENERATE_ON_RISING,
  SAI_CLOCK_STROBE_GENERATE_ON_FALLING
};

enum sai_subblock_sync
{
  SAI_SUBBLOCK_SYNC_ASYNC,
  SAI_SUBBLOCK_SYNC_SYNC_INTERNAL,
  SAI_SUBBLOCK_SYNC_SYNC_EXTERNAL
};

enum sai_audio_mode
{
  SAI_AUDIO_MODE_STEREO,
  SAI_AUDIO_MODE_MONO
};

enum sai_outdrive
{
  SAI_OUTDRIVE_MANUAL,
  SAI_OUTDRIVE_AUTO
};

enum sai_fifo_threshold
{
  SAI_FIFO_THRESHOLD_EMPTY,
  SAI_FIFO_THRESHOLD_1over4_FULL,
  SAI_FIFO_THRESHOLD_1over2_FULL,
  SAI_FIFO_THRESHOLD_3over4_FULL,
  SAI_FIFO_THRESHOLD_FULL
};

enum sai_tristate_management
{
  SAI_TRISTATE_MANAGEMENT_KEEP_DRIVE,
  SAI_TRISTATE_MANAGEMENT_RELEASE
};

enum sai_mute_value
{
  SAI_MUTE_VALUE_BIT_VALUE0,
  SAI_MUTE_VALUE_LAST
};

enum sai_bit_complement
{
  SAI_BIT_COMPLEMENT1,
  SAI_BIT_COMPLEMENT2
};

enum sai_companding_mode
{
  SAI_COMPANDING_MODE_NOCOMPANDING,
  SAI_COMPANDING_MODE_uLAW_ALGO,
  SAI_COMPANDING_MODE_ALAW_ALGO
};

enum sai_frame_sync_mode
{
  SAI_FRAME_SYNC_MODE_FRAME_START,
  SAI_FRAME_SYNC_MODE_FRAME_START_CHANNEL_SIDE
};

enum sai_frame_sync_polarity
{
  SAI_FRAME_SYNC_POLARITY_ACTIVE_LOW,
  SAI_FRAME_SYNC_POLARITY_ACTIVE_HIGH
};

enum sai_frame_sync_offset
{
  SAI_FRAME_SYNC_OFFSET_FIRST_BIT,
  SAI_FRAME_SYNC_OFFSET_BEFORE_FIRST_BIT
};

enum sai_slot_size
{
  SAI_SLOT_SIZE_DATASIZE,
  SAI_SLOT_SIZE_16BIT,
  SAI_SLOT_SIZE_32BIT
};

enum sai_interrupt
{
  SAI_INTERRUPT_OVERRUN_UNDERRUN,
  SAI_INTERRUPT_MUTE_DETECTION,
  SAI_INTERRUPT_WRONG_CLOCK,
  SAI_INTERRUPT_FIFO_REQUEST,
  SAI_INTERRUPT_CODEC_NOT_READY,
  SAI_INTERRUPT_ANTICIPATED_FRAME_SYNC,
  SAI_INTERRUPT_LATE_FRAME_SYNC
};

enum sai_flag
{
  SAI_FLAG_OVERRUN_UNDERRUN,
  SAI_FLAG_MUTE,
  SAI_FLAG_WRONG_CLOCK,
  SAI_FLAG_FIFO_REQUEST,
  SAI_FLAG_CODEC_NOT_READY,
  SAI_FLAG_ANTICIPATED_FRAME_SYNC,
  SAI_FLAG_LATE_FRAME_SYNC
};

extern volatile struct sai_registers_map* SAI1A;
extern volatile struct sai_registers_map* SAI1B;

#if defined(STM32_SAI2)
extern volatile struct sai_registers_map* SAI2A;
extern volatile struct sai_registers_map* SAI2B;
#endif

#if defined(STM32_SAI_GCR)
void
sai_set_sync_output(
  volatile struct sai_registers_map* sai,
  enum sai_sync_out sync
);
#endif

void
sai_set_block_mode(
  volatile struct sai_registers_map* sai,
  enum sai_block_mode mode
);

void
sai_set_protocol(
  volatile struct sai_registers_map* sai,
  enum sai_protocol protocol
);

void
sai_set_data_size(
  volatile struct sai_registers_map* sai,
  enum sai_data_size size
);

void
sai_set_endianess(
  volatile struct sai_registers_map* sai,
  enum sai_endianess endianess
);

void
sai_set_clock_strobe(
  volatile struct sai_registers_map* sai,
  enum sai_clock_strobe strobe
);

void
sai_set_subblock_sync(
  volatile struct sai_registers_map* sai,
  enum sai_subblock_sync sync
);

void
sai_set_audio_mode(
  volatile struct sai_registers_map* sai,
  enum sai_audio_mode mode
);

void
sai_set_outdrive(
  volatile struct sai_registers_map* sai,
  enum sai_outdrive outdrive
);

void
sai_audio_block_enable(
  volatile struct sai_registers_map* sai
);

void
sai_audio_block_disable(
  volatile struct sai_registers_map* sai
);

void
sai_dma_enable(
  volatile struct sai_registers_map* sai
);

void
sai_dma_disable(
  volatile struct sai_registers_map* sai
);

void
sai_clock_divider_enable(
  volatile struct sai_registers_map* sai
);

void
sai_clock_divider_disable(
  volatile struct sai_registers_map* sai
);

void
sai_set_clock_divider(
  volatile struct sai_registers_map* sai,
  u32 divider
);

void
sai_set_fifo_threshold(
  volatile struct sai_registers_map* sai,
  enum sai_fifo_threshold threshold
);

void
sai_fifo_flush(
  volatile struct sai_registers_map* sai
);

void
sai_set_tristate_management(
  volatile struct sai_registers_map* sai,
  enum sai_tristate_management management
);

void
sai_mute_enable(
  volatile struct sai_registers_map* sai
);

void
sai_mute_disable(
  volatile struct sai_registers_map* sai
);

void
sai_set_mute_value(
  volatile struct sai_registers_map* sai,
  enum sai_mute_value value
);

void
sai_set_mute_counter(
  volatile struct sai_registers_map* sai,
  u32 counter
);

void
sai_set_bit_complement(
  volatile struct sai_registers_map* sai,
  enum sai_bit_complement complement
);

void
sai_set_companding_mode(
  volatile struct sai_registers_map* sai,
  enum sai_companding_mode mode
);

void
sai_set_frame_length(
  volatile struct sai_registers_map* sai,
  u32 length
);

void
sai_set_frame_sync_active_level(
  volatile struct sai_registers_map* sai,
  u32 level
);

u32
sai_get_frame_sync_mode(
  volatile struct sai_registers_map* sai
);

void
sai_set_frame_sync_polarity(
  volatile struct sai_registers_map* sai,
  enum sai_frame_sync_polarity polarity
);

void
sai_set_frame_sync_offset(
  volatile struct sai_registers_map* sai,
  enum sai_frame_sync_offset offset
);

void
sai_set_first_bit_offset(
  volatile struct sai_registers_map* sai,
  u32 offset
);

void
sai_set_slot_size(
  volatile struct sai_registers_map* sai,
  enum sai_slot_size size
);

void
sai_set_audio_frame_slots_count(
  volatile struct sai_registers_map* sai,
  u32 count
);

void
sai_slot_enable(
  volatile struct sai_registers_map* sai,
  u32 slot
);

void
sai_slot_disable(
  volatile struct sai_registers_map* sai,
  u32 slot
);

void
sai_interrupt_enable(
  volatile struct sai_registers_map* sai,
  enum sai_interrupt interrupt
);

void
sai_interrupt_disable(
  volatile struct sai_registers_map* sai,
  enum sai_interrupt interrupt
);

u32
sai_is_flag_set(
  volatile struct sai_registers_map* sai,
  enum sai_flag flag
);

u32
sai_get_fifo_threshold_level(
  volatile struct sai_registers_map* sai
);

void
sai_flag_clear(
  volatile struct sai_registers_map* sai,
  enum sai_flag flag
);

void
sai_write_data(
  volatile struct sai_registers_map* sai,
  u32 data
);

END_DECLARATIONS

#endif
