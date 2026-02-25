#include "synapse/stm32/drivers/sai/sai_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct sai_registers_map sai_periph;

sai_periph* SAI1A = (sai_periph*) (SAI1A_ADDR);
sai_periph* SAI1B = (sai_periph*) (SAI1B_ADDR);

#if defined(STM32_SAI2)
sai_periph* SAI2A = (sai_periph*) (SAI2A_ADDR);
sai_periph* SAI2B = (sai_periph*) (SAI2B_ADDR);
#endif

#if defined(STM32_SAI_GCR)
void
sai_set_sync_output(
  volatile struct sai_registers_map* sai,
  enum sai_sync_out sync
)
{
  constexpr u32 shift = SAI_GCR_SYNCOUT_SHIFT;
  constexpr u32 mask = SAI_GCR_SYNCOUT_MASK << shift;
  volatile u32* reg = &sai->GCR;
  switch (sync)
  {
    case SAI_SYNC_OUT_NOSYNC:
      *reg &= ~mask;
      break;

    case SAI_SYNC_OUT_SYNC_BLOCKA:
      syn_set_register_bits(reg, mask, SAI_CGR_SYNCOUT_SYNC_BLOCKA << shift);
      break;

    case SAI_SYNC_OUT_SYNC_BLOCKB:
      syn_set_register_bits(reg, mask, SAI_CGR_SYNCOUT_SYNC_BLOCKB << shift);
      break;

    default:
      devmode_invalid_enum(enum sai_sync_out, sync);
      break;
  }
}
#endif

void
sai_set_block_mode(
  volatile struct sai_registers_map* sai,
  enum sai_block_mode mode
)
{
  constexpr u32 shift = SAI_CR1_MODE_SHIFT;
  constexpr u32 mask = SAI_CR1_MODE_MASK << shift;
  volatile u32* reg = &sai->CR1;

  switch (mode)
  {
    case SAI_BLOCK_MODE_MASTER_TX:
      *reg &= ~mask;
      break;

    case SAI_BLOCK_MODE_MASTER_RX:
      syn_set_register_bits(reg, mask, SAI_CR1_MODE_MASTER_RX << shift);
      break;

    case SAI_BLOCK_MODE_SLAVE_TX:
      syn_set_register_bits(reg, mask, SAI_CR1_MODE_SLAVE_TX << shift);
      break;

    case SAI_BLOCK_MODE_SLAVE_RX:
      *reg |= (SAI_CR1_MODE_SLAVE_RX << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sai_block_mode, mode);
      break;
  }
}

void
sai_set_protocol(
  volatile struct sai_registers_map* sai,
  enum sai_protocol protocol
)
{
  constexpr u32 shift = SAI_CR1_PRTCFG_SHIFT;
  constexpr u32 mask = SAI_CR1_PRTCFG_MASK << shift;
  volatile u32* reg = &sai->CR1;

  switch (protocol)
  {
    case SAI_PROTOCOL_FREE:
      *reg &= ~mask;
      break;

    case SAI_PROTOCOL_SPDIF:
      syn_set_register_bits(reg, mask, SAI_CR1_PRTCFG_SPDIF << shift);
      break;

    case SAI_PROTOCOL_AC97:
      syn_set_register_bits(reg, mask, SAI_CR1_PRTCFG_AC97 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sai_protocol, protocol);
      break;
  }
}

void
sai_set_data_size(
  volatile struct sai_registers_map* sai,
  enum sai_data_size size
)
{
  constexpr u32 shift = SAI_CR1_DS_SHIFT;
  constexpr u32 mask = SAI_CR1_DS_MASK << shift;
  volatile u32* reg = &sai->CR1;

  switch (size)
  {
    case SAI_DATA_SIZE_8BIT:
      syn_set_register_bits(reg, mask, SAI_CR1_DS_8BIT << shift);
      break;

    case SAI_DATA_SIZE_10BIT:
      syn_set_register_bits(reg, mask, SAI_CR1_DS_10BIT << shift);
      break;

    case SAI_DATA_SIZE_16BIT:
      syn_set_register_bits(reg, mask, SAI_CR1_DS_16BIT << shift);
      break;

    case SAI_DATA_SIZE_20BIT:
      syn_set_register_bits(reg, mask, SAI_CR1_DS_20BIT << shift);
      break;

    case SAI_DATA_SIZE_24BIT:
      syn_set_register_bits(reg, mask, SAI_CR1_DS_24BIT << shift);
      break;

    case SAI_DATA_SIZE_32BIT:
      syn_set_register_bits(reg, mask, SAI_CR1_DS_32BIT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sai_data_size, size);
      break;
  }
}

void
sai_set_endianess(
  volatile struct sai_registers_map* sai,
  enum sai_endianess endianess
)
{
  volatile u32* reg = &sai->CR1;
  switch (endianess)
  {
    case SAI_ENDIANESS_MSB_FIRST:
      *reg &= ~SAI_CR1_LSBFIRST;
      break;

    case SAI_ENDIANESS_LSB_FIRST:
      *reg |= SAI_CR1_LSBFIRST;
      break;

    default:
      devmode_error_invalid_enum(enum sai_endianess, endianess);
      break;
  }
}

void
sai_set_clock_strobe(
  volatile struct sai_registers_map* sai,
  enum sai_clock_strobe strobe
)
{
  volatile u32* reg = &sai->CR1;
  switch (strobe)
  {
    case SAI_CLOCK_STROBE_GENERATE_ON_RISING:
      *reg &= ~SAI_CR1_CKSTR;
      break;

    case SAI_CLOCK_STROBE_GENERATE_ON_FALLING:
      *reg |= SAI_CR1_CKSTR;
      break;

    default:
      devmode_error_invalid_enum(enum sai_clock_strobe, strobe);
      break;
  }
}

void
sai_set_subblock_sync(
  volatile struct sai_registers_map* sai,
  enum sai_subblock_sync sync
)
{
  constexpr u32 shift = SAI_CR1_SYNCEN_SHIFT;
  constexpr u32 mask = SAI_CR1_SYNCEN_MASK << shift;
  volatile u32* reg = &sai->CR1;

  switch (sync)
  {
    case SAI_SUBBLOCK_SYNC_ASYNC:
      *reg &= ~mask;
      break;

    case SAI_SUBBLOCK_SYNC_SYNC_INTERNAL:
      syn_set_register_bits(reg, mask, SAI_CR1_SYNCEN_SYNC_INTERNAL << shift);
      break;

    case SAI_SUBBLOCK_SYNC_SYNC_EXTERNAL:
      syn_set_register_bits(reg, mask, SAI_CR1_SYNCEN_SYNC_EXTERNAL << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sai_subblock_sync, sync);
      break;
  }
}

void
sai_set_audio_mode(
  volatile struct sai_registers_map* sai,
  enum sai_audio_mode mode
)
{
  volatile u32* reg = &sai->CR1;
  switch (mode)
  {
    case SAI_AUDIO_MODE_STEREO:
      *reg &= ~SAI_CR1_MONO;
      break;

    case SAI_AUDIO_MODE_MONO:
      *reg |= SAI_CR1_MONO;
      break;

    default:
      devmode_error_invalid_enum(enum sai_audio_mode, mode);
      break;
  }
}

void
sai_set_outdrive(
  volatile struct sai_registers_map* sai,
  enum sai_outdrive outdrive
)
{
  volatile u32* reg = &sai->CR1;
  switch (outdrive)
  {
    case SAI_OUTDRIVE_MANUAL:
      *reg &= ~SAI_CR1_OUTDRIV;
      break;

    case SAI_OUTDRIVE_AUTO:
      *reg |= SAI_CR1_OUTDRIV;
      break;

    default:
      devmode_error_invalid_enum(enum sai_outdrive, outdrive);
      break;
  }
}

void
sai_audio_block_enable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR1 |= SAI_CR1_SAIEN;
}

void
sai_audio_block_disable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR1 &= ~SAI_CR1_SAIEN;
}

void
sai_dma_enable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR1 |= SAI_CR1_DMAEN;
}

void
sai_dma_disable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR1 &= ~SAI_CR1_DMAEN;
}

void
sai_clock_divider_enable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR1 &= ~SAI_CR1_NODIV;
}

void
sai_clock_divider_disable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR1 |= SAI_CR1_NODIV;
}

void
sai_set_clock_divider(
  volatile struct sai_registers_map* sai,
  u32 divider
)
{
  devmode_assert_lower_or_eq(divider, SAI_CR1_MCKDIV_MASK);
  constexpr u32 shift = SAI_CR1_MCKDIV_SHIFT;
  constexpr u32 mask = SAI_CR1_MCKDIV_MASK << shift;
  volatile u32* reg = &sai->CR1;
  syn_set_register_bits(reg, mask, divider << shift);
}

void
sai_set_fifo_threshold(
  volatile struct sai_registers_map* sai,
  enum sai_fifo_threshold threshold
)
{
  constexpr u32 shift = SAI_CR2_FTH_SHIFT;
  constexpr u32 mask = SAI_CR2_FTH_MASK << shift;
  volatile u32* reg = &sai->CR2;

  switch (threshold)
  {
    case SAI_FIFO_THRESHOLD_EMPTY:
      *reg &= ~mask;
      break;

    case SAI_FIFO_THRESHOLD_1over4_FULL:
      syn_set_register_bits(reg, mask, SAI_CR2_FTH_1over4_FULL << shift);
      break;

    case SAI_FIFO_THRESHOLD_1over2_FULL:
      syn_set_register_bits(reg, mask, SAI_CR2_FTH_1over2_FULL << shift);
      break;

    case SAI_FIFO_THRESHOLD_3over4_FULL:
      syn_set_register_bits(reg, mask, SAI_CR2_FTH_3over4_FULL << shift);
      break;

    case SAI_FIFO_THRESHOLD_FULL:
      syn_set_register_bits(reg, mask, SAI_CR2_FTH_FULL << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sai_fifo_threshold, threshold);
      break;
  }
}

void
sai_fifo_flush(
  volatile struct sai_registers_map* sai
)
{
  sai->CR2 |= SAI_CR2_FFLUSH;
}

void
sai_set_tristate_management(
  volatile struct sai_registers_map* sai,
  enum sai_tristate_management management
)
{
  volatile u32* reg = &sai->CR2;
  switch (management)
  {
    case SAI_TRISTATE_MANAGEMENT_KEEP_DRIVE:
      *reg &= ~SAI_CR2_TRIS;
      break;

    case SAI_TRISTATE_MANAGEMENT_RELEASE:
      *reg |= SAI_CR2_TRIS;
      break;

    default:
      devmode_error_invalid_enum(enum sai_tristate_management, management);
      break;
  }
}

void
sai_mute_enable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR2 |= SAI_CR2_MUTE;
}

void
sai_mute_disable(
  volatile struct sai_registers_map* sai
)
{
  sai->CR2 &= ~SAI_CR2_MUTE;
}

void
sai_set_mute_value(
  volatile struct sai_registers_map* sai,
  enum sai_mute_value value
)
{
  volatile u32* reg = &sai->CR2;
  switch (value)
  {
    case SAI_MUTE_VALUE_BIT_VALUE0:
      *reg &= ~SAI_CR2_MUTEVAL;
      break;

    case SAI_MUTE_VALUE_LAST:
      *reg |= SAI_CR2_MUTEVAL;
      break;

    default:
      devmode_error_invalid_enum(enum sai_mute_value, value);
      break;
  }
}

void
sai_set_mute_counter(
  volatile struct sai_registers_map* sai,
  u32 counter
)
{
  devmode_assert_lower_or_eq(counter, SAI_CR2_MUTECNT_MASK);
  constexpr u32 shift = SAI_CR2_MUTECNT_SHIFT;
  constexpr u32 mask = SAI_CR2_MUTECNT_MASK << shift;
  volatile u32* reg = &sai->CR2;
  syn_set_register_bits(reg, mask, counter << shift);
}

void
sai_set_bit_complement(
  volatile struct sai_registers_map* sai,
  enum sai_bit_complement complement
)
{
  volatile u32* reg = &sai->CR2;
  switch (complement)
  {
    case SAI_BIT_COMPLEMENT1:
      *reg &= ~SAI_CR2_CPL;
      break;

    case SAI_BIT_COMPLEMENT2:
      *reg |= SAI_CR2_CPL;
      break;

    default:
      devmode_error_invalid_enum(enum sai_bit_complement, complement);
      break;
  }
}

void
sai_set_companding_mode(
  volatile struct sai_registers_map* sai,
  enum sai_companding_mode mode
)
{
  constexpr u32 shift = SAI_CR2_COMP_SHIFT;
  constexpr u32 mask = SAI_CR2_COMP_MASK << shift;
  volatile u32* reg = &sai->CR2;

  switch (mode)
  {
    case SAI_COMPANDING_MODE_NOCOMPANDING:
      *reg &= ~mask;
      break;

    case SAI_COMPANDING_MODE_uLAW_ALGO:
      syn_set_register_bits(reg, mask, SAI_CR2_COMP_uLAW_ALGO << shift);
      break;

    case SAI_COMPANDING_MODE_ALAW_ALGO:
      *reg |= (SAI_CR2_COMP_ALAW_ALGO << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sai_companding_mode, mode);
      break;
  }
}

void
sai_set_frame_length(
  volatile struct sai_registers_map* sai,
  u32 length
)
{
  devmode_assert_lower_or_eq(length, SAI_FRCR_FRL_MASK);
  constexpr u32 shift = SAI_FRCR_FRL_SHIFT;
  constexpr u32 mask = SAI_FRCR_FRL_MASK << shift;
  volatile u32* reg = &sai->FRCR;
  syn_set_register_bits(reg, mask, length << shift);
}

void
sai_set_frame_sync_active_level(
  volatile struct sai_registers_map* sai,
  u32 level
)
{
  devmode_assert_lower_or_eq(level, SAI_FRCR_FSALL_MASK);
  constexpr u32 shift = SAI_FRCR_FSALL_SHIFT;
  constexpr u32 mask = SAI_FRCR_FSALL_MASK << shift;
  volatile u32* reg = &sai->FRCR;
  syn_set_register_bits(reg, mask, level << shift);
}

u32
sai_get_frame_sync_mode(
  volatile struct sai_registers_map* sai
)
{
  return sai->FRCR & SAI_FRCR_FSDEF;
}

void
sai_set_frame_sync_polarity(
  volatile struct sai_registers_map* sai,
  enum sai_frame_sync_polarity polarity
)
{
  volatile u32* reg = &sai->FRCR;
  switch (polarity)
  {
    case SAI_FRAME_SYNC_POLARITY_ACTIVE_LOW:
      *reg &= ~SAI_FRCR_FSPOL;
      break;

    case SAI_FRAME_SYNC_POLARITY_ACTIVE_HIGH:
      *reg |= SAI_FRCR_FSPOL;
      break;

    default:
      devmode_error_invalid_enum(enum sai_frame_sync_polarity, polarity);
      break;
  }
}

void
sai_set_frame_sync_offset(
  volatile struct sai_registers_map* sai,
  enum sai_frame_sync_offset offset
)
{
  volatile u32* reg = &sai->FRCR;
  switch (offset)
  {
    case SAI_FRAME_SYNC_OFFSET_FIRST_BIT:
      *reg &= ~SAI_FRCR_FSOFF;
      break;

    case SAI_FRAME_SYNC_OFFSET_BEFORE_FIRST_BIT:
      *reg |= SAI_FRCR_FSOFF;
      break;

    default:
      devmode_error_invalid_enum(enum sai_frame_sync_offset, offset);
      break;
  }
}

void
sai_set_first_bit_offset(
  volatile struct sai_registers_map* sai,
  u32 offset
)
{
  devmode_assert_lower_or_eq(offset, SAI_SLOTR_FBOFF_MASK);
  constexpr u32 shift = SAI_SLOTR_FBOFF_SHIFT;
  constexpr u32 mask = SAI_SLOTR_FBOFF_MASK << shift;
  volatile u32* reg = &sai->SLOTR;
  syn_set_register_bits(reg, mask, offset << shift);
}

void
sai_set_slot_size(
  volatile struct sai_registers_map* sai,
  enum sai_slot_size size
)
{
  constexpr u32 shift = SAI_SLOTR_SLOTSZ_SHIFT;
  constexpr u32 mask = SAI_SLOTR_SLOTSZ_MASK << shift;
  volatile u32* reg = &sai->SLOTR;
  switch (size)
  {
    case SAI_SLOT_SIZE_DATASIZE:
      *reg &= ~mask;
      break;

    case SAI_SLOT_SIZE_16BIT:
      syn_set_register_bits(reg, mask, SAI_SLOTR_SLOTSZ_16BIT << shift);
      break;

    case SAI_SLOT_SIZE_32BIT:
      syn_set_register_bits(reg, mask, SAI_SLOTR_SLOTSZ_32BIT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sai_slot_size, size);
      break;
  }
}

void
sai_set_audio_frame_slots_count(
  volatile struct sai_registers_map* sai,
  u32 count
)
{
  devmode_assert_lower_or_eq(count, SAI_SLOTR_NBSLOT_MASK);
  constexpr u32 shift = SAI_SLOTR_NBSLOT_SHIFT;
  constexpr u32 mask = SAI_SLOTR_NBSLOT_MASK << shift;
  volatile u32* reg = &sai->SLOTR;
  syn_set_register_bits(reg, mask, count << shift);
}

void
sai_slot_enable(
  volatile struct sai_registers_map* sai,
  u32 slot
)
{
  devmode_assert_lower_or_eq(slot, SAI_SLOTR_SLOTEN_MAX_SLOT);
  sai->SLOTR |= 1u << (SAI_SLOTR_SLOTEN_SHIFT + slot);
}

void
sai_slot_disable(
  volatile struct sai_registers_map* sai,
  u32 slot
)
{
  devmode_assert_lower_or_eq(slot, SAI_SLOTR_SLOTEN_MAX_SLOT);
  sai->SLOTR &= ~(1u << (SAI_SLOTR_SLOTEN_SHIFT + slot));
}

void
sai_interrupt_enable(
  volatile struct sai_registers_map* sai,
  enum sai_interrupt interrupt
)
{
  volatile u32* reg = &sai->IM;
  switch (interrupt)
  {
    case SAI_INTERRUPT_OVERRUN_UNDERRUN:
      *reg |= SAI_IM_OVRUDRIE;
      break;

    case SAI_INTERRUPT_MUTE_DETECTION:
      *reg |= SAI_IM_MUTEDETIE;
      break;

    case SAI_INTERRUPT_WRONG_CLOCK:
      *reg |= SAI_IM_WCKCFGIE;
      break;

    case SAI_INTERRUPT_FIFO_REQUEST:
      *reg |= SAI_IM_FREQIE;
      break;

    case SAI_INTERRUPT_CODEC_NOT_READY:
      *reg |= SAI_IM_CNRDYIE;
      break;

    case SAI_INTERRUPT_ANTICIPATED_FRAME_SYNC:
      *reg |= SAI_IM_AFSDETIE;
      break;

    case SAI_INTERRUPT_LATE_FRAME_SYNC:
      *reg |= SAI_IM_LFSDETIE;
      break;

    default:
      devmode_error_invalid_enum(enum sai_interrupt, interrupt);
      break;
  }
}

void
sai_interrupt_disable(
  volatile struct sai_registers_map* sai,
  enum sai_interrupt interrupt
)
{
  volatile u32* reg = &sai->IM;
  switch (interrupt)
  {
    case SAI_INTERRUPT_OVERRUN_UNDERRUN:
      *reg &= ~SAI_IM_OVRUDRIE;
      break;

    case SAI_INTERRUPT_MUTE_DETECTION:
      *reg &= ~SAI_IM_MUTEDETIE;
      break;

    case SAI_INTERRUPT_WRONG_CLOCK:
      *reg &= ~SAI_IM_WCKCFGIE;
      break;

    case SAI_INTERRUPT_FIFO_REQUEST:
      *reg &= ~SAI_IM_FREQIE;
      break;

    case SAI_INTERRUPT_CODEC_NOT_READY:
      *reg &= ~SAI_IM_CNRDYIE;
      break;

    case SAI_INTERRUPT_ANTICIPATED_FRAME_SYNC:
      *reg &= ~SAI_IM_AFSDETIE;
      break;

    case SAI_INTERRUPT_LATE_FRAME_SYNC:
      *reg &= ~SAI_IM_LFSDETIE;
      break;

    default:
      devmode_error_invalid_enum(enum sai_interrupt, interrupt);
      break;
  }
}

u32
sai_is_flag_set(
  volatile struct sai_registers_map* sai,
  enum sai_flag flag
)
{
  volatile u32* reg = &sai->SR;
  switch (flag)
  {
    case SAI_FLAG_OVERRUN_UNDERRUN:
      return *reg & SAI_SR_OVRUDR;

    case SAI_FLAG_MUTE:
      return *reg & SAI_SR_MUTEDET;

    case SAI_FLAG_WRONG_CLOCK:
      return *reg & SAI_SR_WCKCFG;

    case SAI_FLAG_FIFO_REQUEST:
      return *reg & SAI_SR_FREQ;

    case SAI_FLAG_CODEC_NOT_READY:
      return *reg & SAI_SR_CNRDY;

    case SAI_FLAG_ANTICIPATED_FRAME_SYNC:
      return *reg & SAI_SR_AFSDET;

    case SAI_FLAG_LATE_FRAME_SYNC:
      return *reg & SAI_SR_LFSDET;

    default:
      devmode_error_invalid_enum(enum sai_flag, flag);
      return 0;
  }
}

u32
sai_get_fifo_threshold_level(
  volatile struct sai_registers_map* sai
)
{
  constexpr u32 shift = SAI_SR_FLTH_SHIFT;
  constexpr u32 mask = SAI_SR_FLTH_MASK;
  volatile u32* reg = &sai->SR;
  return (*reg >> shift) & mask;
}

void
sai_flag_clear(
  volatile struct sai_registers_map* sai,
  enum sai_flag flag
)
{
  volatile u32* reg = &sai->CLRFR;
  switch (flag)
  {
    case SAI_FLAG_OVERRUN_UNDERRUN:
      *reg |= SAI_CLRFR_COVRUDR;
      break;

    case SAI_FLAG_MUTE:
      *reg |= SAI_CLRFR_CMUTEDET;
      break;

    case SAI_FLAG_WRONG_CLOCK:
      *reg |= SAI_CLRFR_CWCKCFG;
      break;

    case SAI_FLAG_CODEC_NOT_READY:
      *reg |= SAI_CLRFR_CCNRDY;
      break;

    case SAI_FLAG_ANTICIPATED_FRAME_SYNC:
      *reg |= SAI_CLRFR_CAFSDET;
      break;

    case SAI_FLAG_LATE_FRAME_SYNC:
      *reg |= SAI_CLRFR_CLFSDET;
      break;

    default:
      devmode_error_invalid_enum(enum sai_flag, flag);
      break;
  }
}

void
sai_write_data(
  volatile struct sai_registers_map* sai,
  u32 data
)
{
  sai->DR = data;
}
