#include "synapse/stm32/drivers/spdifrx/spdifrx_v1.h"
#include "libcom/sys/devmode.h"
#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/stm32/system/chips/f4/memorymap.h"

typedef struct spdifrx_registers_map spdifrx_periph;
spdifrx_periph* SPDIFRX = (spdifrx_periph*) (SPDIFRX_ADDR);

void
spdifrx_set_active_block(
  enum spdifrx_block block
)
{
  constexpr u32 shift = SPDIFRX_CR_SPDIFRXEN_SHIFT;
  constexpr u32 mask = SPDIFRX_CR_SPDIFRXEN_MASK << shift;
  volatile u32* reg = &SPDIFRX->CR;

  switch (block)
  {
    case SPDIFRX_BLOCK_IDLE:
      *reg &= ~mask;
      break;

    case SPDIFRX_BLOCK_SYNC_ONLY:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_SPDIFRXEN_ENABLE_SYNC_ONLY << shift
      );
      break;

    case SPDIFRX_BLOCK_RECEIVER:
      *reg |= (SPDIFRX_CR_SPDIFRXEN_ENABLE_RECEIVER << shift);
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_block, block);
      break;
  }
}

void
spdifrx_receiver_dma_enable(void)
{
  SPDIFRX->CR |= SPDIFRX_CR_RXDMAEN;
}

void
spdifrx_receiver_dma_disable(void)
{
  SPDIFRX->CR &= ~SPDIFRX_CR_RXDMAEN;
}

void
spdifrx_set_audio_mode(
  enum spdifrx_audio_mode mode
)
{
  volatile u32* reg = &SPDIFRX->CR;
  switch (mode)
  {
    case SPDIFRX_AUDIO_MODE_STEREO:
      *reg |= SPDIFRX_CR_RXSTEO;
      break;

    case SPDIFRX_AUDIO_MODE_MONO:
      *reg &= ~SPDIFRX_CR_RXSTEO;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_audio_mode, mode);
      break;
  }
}

void
spdifrx_set_rx_data_format(
  enum spdifrx_rx_data_format format
)
{
  volatile u32* reg = &SPDIFRX->CR;
  constexpr u32 shift = SPDIFRX_CR_DRFMT_SHIFT;
  constexpr u32 mask = SPDIFRX_CR_DRFMT_MASK << shift;

  switch (format)
  {
    case SPDIFRX_RX_DATA_FORMAT_32BIT:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_DRFMT_32BIT << shift
      );
      break;

    case SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_DRFMT_LEFT_ALIGNED << shift
      );
      break;

    case SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED:
      *reg |= (SPDIFRX_CR_DRFMT_RIGHT_ALIGNED << shift);
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_rx_data_format, format);
      break;
  }
}

void
spdifrx_copy_bit_enable(
  enum spdifrx_bit bit
)
{
  volatile u32* reg = &SPDIFRX->CR;
  switch (bit)
  {
    case SPDIFRX_BIT_MASK_PARITY:
      *reg |= SPDIFRX_CR_PMSK;
      break;

    case SPDIFRX_BIT_MASK_VALIDITY:
      *reg |= SPDIFRX_CR_VMSK;
      break;

    case SPDIFRX_BIT_MASK_CHANNEL_STATUS:
      *reg |= SPDIFRX_CR_CUMSK;
      break;

    case SPDIFRX_BIT_MASK_PREABLE:
      *reg |= SPDIFRX_CR_PTMSK;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_bit, bit);
      break;
  }
}

void
spdifrx_copy_bit_disable(
  enum spdifrx_bit bit
)
{
  volatile u32* reg = &SPDIFRX->CR;
  switch (bit)
  {
    case SPDIFRX_BIT_MASK_PARITY:
      *reg &= ~SPDIFRX_CR_PMSK;
      break;

    case SPDIFRX_BIT_MASK_VALIDITY:
      *reg &= ~SPDIFRX_CR_VMSK;
      break;

    case SPDIFRX_BIT_MASK_CHANNEL_STATUS:
      *reg &= ~SPDIFRX_CR_CUMSK;
      break;

    case SPDIFRX_BIT_MASK_PREABLE:
      *reg &= ~SPDIFRX_CR_PTMSK;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_bit, bit);
      break;
  }
}

void
spdifrx_dma_control_flow_enable(void)
{
  SPDIFRX->CR |= SPDIFRX_CR_CBDMAEN;
}

void
spdifrx_dma_control_flow_disable(void)
{
  SPDIFRX->CR &= ~SPDIFRX_CR_CBDMAEN;
}

void
spdifrx_set_channel_flow_control(
  enum spdifrx_channel channel
)
{
  volatile u32* reg = &SPDIFRX->CR;
  switch (channel)
  {
    case SPDIFRX_CHANNELA:
      *reg &= ~SPDIFRX_CR_CHSEL;
      break;

    case SPDIFRX_CHANNELB:
      *reg |= SPDIFRX_CR_CHSEL;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_channel, channel);
      break;
  }
}

void
spdifrx_set_max_allowed_retries(
  enum spdifrx_retries retries
)
{
  volatile u32* reg = &SPDIFRX->CR;
  constexpr u32 shift = SPDIFRX_CR_NBTR_SHIFT;
  constexpr u32 mask = SPDIFRX_CR_NBTR_MASK << shift;

  switch (retries)
  {
    case SPDIFRX_RETRIES_NORETRIES:
      *reg &= ~mask;
      break;

    case SPDIFRX_RETRIES_3RETRIES:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_NBTR_3RETRIES << shift
      );
      break;

    case SPDIFRX_RETRIES_15RETRIES:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_NBTR_15RETRIES << shift
      );
      break;

    case SPDIFRX_RETRIES_63RETRIES:
      *reg |= (SPDIFRX_CR_NBTR_63RETRIES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_retries, retries);
      break;
  }
}

void
spdifrx_set_sync_policy(
  enum spdifrx_sync_policy policy
)
{
  volatile u32* reg = &SPDIFRX->CR;
  switch (policy)
  {
    case SPDIFRX_SYNC_POLICY_WAIT_IN:
      *reg |= SPDIFRX_CR_WFA;
      break;

    case SPDIFRX_SYNC_POLICY_DONT_WAIT:
      *reg &= ~SPDIFRX_CR_WFA;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_sync_policy, policy);
      break;
  }
}

void
spdifrx_set_input(
  enum spdifrx_input input
)
{
  volatile u32* reg = &SPDIFRX->CR;
  constexpr u32 shift = SPDIFRX_CR_INSEL_SHIFT;
  constexpr u32 mask = SPDIFRX_CR_INSEL_MASK << shift;

  switch (input)
  {
    case SPDIFRX_INPUT_IN1:
      *reg &= ~mask;
      break;

    case SPDIFRX_INPUT_IN2:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_INSEL_IN2 << shift
      );
      break;

    case SPDIFRX_INPUT_IN3:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_INSEL_IN3 << shift
      );
      break;

    case SPDIFRX_INPUT_IN4:
      syn_set_register_bits(
        reg,
        mask,
        SPDIFRX_CR_INSEL_IN4 << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_input, input);
      break;
  }
}

void
spdifrx_interrupt_enable(
  enum spdifrx_interrupt interrupt
)
{
  volatile u32* reg = &SPDIFRX->IMR;
  switch (interrupt)
  {
    case SPDIFRX_INTERRUPT_RXNE:
      *reg |= SPDIFRX_IMR_RXNEIE;
      break;

    case SPDIFRX_INTERRUPT_CTRL_BUF_READY:
      *reg |= SPDIFRX_IMR_CSRNEIE;
      break;

    case SPDIFRX_INTERRUPT_PARITY_ERR:
      *reg |= SPDIFRX_IMR_PERRIE;
      break;

    case SPDIFRX_INTERRUPT_OVERRUN_ERR:
      *reg |= SPDIFRX_IMR_OVRIE;
      break;

    case SPDIFRX_INTERRUPT_SYNC_DETECTED:
      *reg |= SPDIFRX_IMR_SBLKIE;
      break;

    case SPDIFRX_INTERRUPT_SYNC_COMPLETE:
      *reg |= SPDIFRX_IMR_SYNCDIE;
      break;

    case SPDIFRX_INTERRUPT_SERIAL_INTERFACE_ERR:
      *reg |= SPDIFRX_IMR_IFEIE;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_interrupt, interrupt);
      break;
  }
}

void
spdifrx_interrupt_disable(
  enum spdifrx_interrupt interrupt
)
{
  volatile u32* reg = &SPDIFRX->IMR;
  switch (interrupt)
  {
    case SPDIFRX_INTERRUPT_RXNE:
      *reg &= ~SPDIFRX_IMR_RXNEIE;
      break;

    case SPDIFRX_INTERRUPT_CTRL_BUF_READY:
      *reg &= ~SPDIFRX_IMR_CSRNEIE;
      break;

    case SPDIFRX_INTERRUPT_PARITY_ERR:
      *reg &= ~SPDIFRX_IMR_PERRIE;
      break;

    case SPDIFRX_INTERRUPT_OVERRUN_ERR:
      *reg &= ~SPDIFRX_IMR_OVRIE;
      break;

    case SPDIFRX_INTERRUPT_SYNC_DETECTED:
      *reg &= ~SPDIFRX_IMR_SBLKIE;
      break;

    case SPDIFRX_INTERRUPT_SYNC_COMPLETE:
      *reg &= ~SPDIFRX_IMR_SYNCDIE;
      break;

    case SPDIFRX_INTERRUPT_SERIAL_INTERFACE_ERR:
      *reg &= ~SPDIFRX_IMR_IFEIE;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_interrupt, interrupt);
      break;
  }
}

u32
spdifrx_is_flag_set(
  enum spdifrx_flag flag
)
{
  volatile u32* reg = &SPDIFRX->SR;
  switch (flag)
  {
    case SPDRFRX_FLAG_RXNE:
      return *reg & SPDIFRX_SR_RXNE;

    case SPDRFRX_FLAG_CTRL_BUF_READY:
      return *reg & SPDIFRX_SR_CSRNE;

    case SPDRFRX_FLAG_PARITY_ERR:
      return *reg & SPDIFRX_SR_PERR;

    case SPDRFRX_FLAG_OVERRUN_ERR:
      return *reg & SPDIFRX_SR_OVR;

    case SPDRFRX_FLAG_SYNC_DETECTED:
      return *reg & SPDIFRX_SR_SBD;

    case SPDRFRX_FLAG_SYNC_COMPLETE:
      return *reg & SPDIFRX_SR_SYNCD;

    case SPDRFRX_FLAG_FRAMING_ERR:
      return *reg & SPDIFRX_SR_FERR;

    case SPDRFRX_FLAG_SYNC_ERR:
      return *reg & SPDIFRX_SR_SERR;

    case SPDRFRX_FLAG_TIMEOUT_ERR:
      return *reg & SPDIFRX_SR_TERR;

    default:
      devmode_error_invalid_enum(enum spdifrx_flag, flag);
      return 0;
  }
}

u32
spdifrx_get_5symbols_clock_count(void)
{
  volatile u32* reg = &SPDIFRX->SR;
  constexpr u32 shift = SPDIFRX_SR_WIDTH5_SHIFT;
  constexpr u32 mask = SPDIFRX_SR_WIDTH5_MASK;
  return (*reg >> shift) & mask;
}

void
spdifrx_flag_clear(
  enum spdifrx_flag flag
)
{
  volatile u32* reg = &SPDIFRX->IFCR;

  switch (flag)
  {
    case SPDRFRX_FLAG_PARITY_ERR:
      *reg |= SPDIFRX_IFCR_PERRCF;
      break;

    case SPDRFRX_FLAG_OVERRUN_ERR:
      *reg |= SPDIFRX_IFCR_OVRCF;
      break;

    case SPDRFRX_FLAG_SYNC_DETECTED:
      *reg |= SPDIFRX_IFCR_SBDCF;
      break;

    case SPDRFRX_FLAG_SYNC_COMPLETE:
      *reg |= SPDIFRX_IFCR_SYNCDCF;
      break;

    default:
      devmode_error_invalid_enum(enum spdifrx_flag, flag);
      break;
  }
}

static u32
_spdifrx_get_recv_bit_fmt_lsb(
  enum spdifrx_recv_bit bit
)
{
  volatile u32* reg = &SPDIFRX->DR;
  switch (bit)
  {
    case SPDIFRX_RECV_BIT_PARITY_ERR:
      return *reg & SPDIFRX_FMT0_DR_PE;

    case SPDIFRX_RECV_BIT_VALIDITY:
      return *reg & SPDIFRX_FMT0_DR_V;

    case SPDIFRX_RECV_BIT_USER:
      return *reg & SPDIFRX_FMT0_DR_U;

    case SPDIFRX_RECV_BIT_CHANNEL_STATUS:
      return *reg & SPDIFRX_FMT0_DR_C;

    default:
      return 0;
  }
}

static u32
_spdifrx_get_recv_bit_fmt_msb(
  enum spdifrx_recv_bit bit
)
{
  volatile u32* reg = &SPDIFRX->DR;
  switch (bit)
  {
    case SPDIFRX_RECV_BIT_PARITY_ERR:
      return *reg & SPDIFRX_FMT1_DR_PE;

    case SPDIFRX_RECV_BIT_VALIDITY:
      return *reg & SPDIFRX_FMT1_DR_V;

    case SPDIFRX_RECV_BIT_USER:
      return *reg & SPDIFRX_FMT1_DR_U;

    case SPDIFRX_RECV_BIT_CHANNEL_STATUS:
      return *reg & SPDIFRX_FMT1_DR_C;

    default:
      return 0;
  }
}

u32
spdifrx_get_recv_bit(
  enum spdifrx_rx_data_format fmt,
  enum spdifrx_recv_bit bit
)
{
  switch (fmt)
  {
    case SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED:
      return _spdifrx_get_recv_bit_fmt_msb(bit);

    case SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED:
      return _spdifrx_get_recv_bit_fmt_lsb(bit);

    default:
      devmode_error_invalid_enum(enum spdifrx_rx_data_format, fmt);
      return 0;
  }
}

static u32
_spdifrx_get_recv_preamble_fmt_lsb(void)
{
  volatile u32* reg = &SPDIFRX->IMR;
  constexpr u32 shift = SPDIFRX_FMT0_DR_PT_SHIFT;
  constexpr u32 mask = SPDIFRX_FMT0_DR_PT_MASK;
  return (*reg >> shift) & mask;
}

static u32
_spdifrx_get_recv_preamble_fmt_msb(void)
{
  volatile u32* reg = &SPDIFRX->IMR;
  constexpr u32 shift = SPDIFRX_FMT1_DR_PT_SHIFT;
  constexpr u32 mask = SPDIFRX_FMT1_DR_PT_MASK;
  return (*reg >> shift) & mask;
}

u32
spdifrx_get_recv_preamble(
  enum spdifrx_rx_data_format fmt
)
{
  switch (fmt)
  {
    case SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED:
      return _spdifrx_get_recv_preamble_fmt_lsb();

    case SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED:
      return _spdifrx_get_recv_preamble_fmt_msb();

    default:
      devmode_error_invalid_enum(enum spdifrx_rx_data_format, fmt);
      return 0;
  }
}

static u32
_spdifrx_get_data_32bit(void)
{
  return SPDIFRX->DR;
}

static u32
_spdifrx_get_data_lsb(void)
{
  volatile u32* reg = &SPDIFRX->DR;
  constexpr u32 shift = SPDIFRX_FMT0_DR_DR_SHIFT;
  constexpr u32 mask = SPDIFRX_FMT0_DR_DR_MASK;
  return (*reg >> shift) & mask;
}

static u32
_spdifrx_get_data_msb(void)
{
  volatile u32* reg = &SPDIFRX->DR;
  constexpr u32 shift = SPDIFRX_FMT1_DR_DR_SHIFT;
  constexpr u32 mask = SPDIFRX_FMT1_DR_DR_MASK;
  return (*reg >> shift) & mask;
}

u32
spdifrx_get_data(
  enum spdifrx_rx_data_format fmt
)
{
  switch (fmt)
  {
    case SPDIFRX_RX_DATA_FORMAT_32BIT:
      return _spdifrx_get_data_32bit();

    case SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED:
      return _spdifrx_get_data_msb();

    case SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED:
      return _spdifrx_get_data_lsb();

    default:
      return 0;
  }
}

u32
spdifrx_get_user_data_info(
  u32 idx
)
{
  constexpr u32 shift = SPDIFRX_CSR_USR_SHIFT;
  return SPDIFRX->CSR & (1u << (idx + shift));
}

u32
spdifrx_get_channel_status_info(
  u32 idx
)
{
  constexpr u32 shift = SPDIFRX_CSR_CS_SHIFT;
  return SPDIFRX->CSR & (1u << (idx + shift));
}

u32
spdifrx_get_start_of_block(void)
{
  return SPDIFRX->CSR & SPDIFRX_CSR_SOB;
}

u32
spdifrx_get_threshold_high(void)
{
  volatile u32* reg = &SPDIFRX->DIR;
  constexpr u32 shift = SPDIFRX_DIR_THI_SHIFT;
  constexpr u32 mask = SPDIFRX_DIR_THI_MASK;
  return (*reg >> shift) & mask;
}

u32
spdifrx_get_threshold_low(void)
{
  volatile u32* reg = &SPDIFRX->DIR;
  constexpr u32 shift = SPDIFRX_DIR_TLO_SHIFT;
  constexpr u32 mask = SPDIFRX_DIR_TLO_MASK;
  return (*reg >> shift) & mask;
}
