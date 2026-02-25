#ifndef STM32_DRIVER_SPDIFRX_H
#define STM32_DRIVER_SPDIFRX_H

#include "libcom/util.h"
#include "synapse/common/util/common.h"
#include "libcom/types.h"

/**
 * Supports:
 *  - STM32F4
 */

BEGIN_DECLARATIONS

struct spdifrx_registers_map
{
  u32 CR;
  u32 IMR;
  u32 SR;
  u32 IFCR;
  u32 DR;
  u32 CSR;
  u32 DIR;
};

// Core

enum spdifrx_cr : u32
{
  SPDIFRX_CR_RXDMAEN = (1 << 2),
  SPDIFRX_CR_RXSTEO = (1 << 3),
  SPDIFRX_CR_PMSK = (1 << 6),
  SPDIFRX_CR_VMSK = (1 << 7),
  SPDIFRX_CR_CUMSK = (1 << 8),
  SPDIFRX_CR_PTMSK = (1 << 9),
  SPDIFRX_CR_CBDMAEN = (1 << 10),
  SPDIFRX_CR_CHSEL = (1 << 11),
  SPDIFRX_CR_WFA = (1 << 14)
};

#define SPDIFRX_CR_SPDIFRXEN_SHIFT (0)
#define SPDIFRX_CR_SPDIFRXEN_MASK (0x3)

enum spdifrx_cr_spdifrxen : u32
{
  SPDIFRX_CR_SPDIFRXEN_IDLE = 0b00,
  SPDIFRX_CR_SPDIFRXEN_ENABLE_SYNC_ONLY = 0b01,
  SPDIFRX_CR_SPDIFRXEN_ENABLE_RECEIVER = 0b11
};

#define SPDIFRX_CR_DRFMT_SHIFT (4)
#define SPDIFRX_CR_DRFMT_MASK (0x3)

enum spdifrx_cr_drfmt : u32
{
  SPDIFRX_CR_DRFMT_RIGHT_ALIGNED = 0b00,
  SPDIFRX_CR_DRFMT_LEFT_ALIGNED = 0b01,
  SPDIFRX_CR_DRFMT_32BIT = 0b10
};

#define SPDIFRX_CR_NBTR_SHIFT (12)
#define SPDIFRX_CR_NBTR_MASK (0x3)

enum spdifrx_cr_nbtr : u32
{
  SPDIFRX_CR_NBTR_NORETRY = 0b00,
  SPDIFRX_CR_NBTR_3RETRIES = 0b01,
  SPDIFRX_CR_NBTR_15RETRIES = 0b10,
  SPDIFRX_CR_NBTR_63RETRIES = 0b11
};

#define SPDIFRX_CR_INSEL_SHIFT (16)
#define SPDIFRX_CR_INSEL_MASK (0x7)

enum spdifrx_cr_insel : u32
{
  SPDIFRX_CR_INSEL_IN1 = 0b000,
  SPDIFRX_CR_INSEL_IN2 = 0b001,
  SPDIFRX_CR_INSEL_IN3 = 0b010,
  SPDIFRX_CR_INSEL_IN4 = 0b011
};

enum spdifrx_imr : u32
{
  SPDIFRX_IMR_RXNEIE = (1 << 0),
  SPDIFRX_IMR_CSRNEIE = (1 << 1),
  SPDIFRX_IMR_PERRIE = (1 << 2),
  SPDIFRX_IMR_OVRIE = (1 << 3),
  SPDIFRX_IMR_SBLKIE = (1 << 4),
  SPDIFRX_IMR_SYNCDIE = (1 << 5),
  SPDIFRX_IMR_IFEIE = (1 << 6)
};

enum spdifrx_sr : u32
{
  SPDIFRX_SR_RXNE = (1 << 0),
  SPDIFRX_SR_CSRNE = (1 << 1),
  SPDIFRX_SR_PERR = (1 << 2),
  SPDIFRX_SR_OVR = (1 << 3),
  SPDIFRX_SR_SBD = (1 << 4),
  SPDIFRX_SR_SYNCD = (1 << 5),
  SPDIFRX_SR_FERR = (1 << 6),
  SPDIFRX_SR_SERR = (1 << 7),
  SPDIFRX_SR_TERR = (1 << 8)
};

#define SPDIFRX_SR_WIDTH5_SHIFT (16)
#define SPDIFRX_SR_WIDTH5_MASK (0x7fff)

enum spdifrx_ifcr : u32
{
  SPDIFRX_IFCR_PERRCF = (1 << 2),
  SPDIFRX_IFCR_OVRCF = (1 << 3),
  SPDIFRX_IFCR_SBDCF = (1 << 4),
  SPDIFRX_IFCR_SYNCDCF = (1 << 5)
};

enum spdifrx_fmt0_dr : u32
{
  SPDIFRX_FMT0_DR_PE = (1 << 24),
  SPDIFRX_FMT0_DR_V = (1 << 25),
  SPDIFRX_FMT0_DR_U = (1 << 26),
  SPDIFRX_FMT0_DR_C = (1 << 27)
};

#define SPDIFRX_FMT0_DR_DR_SHIFT (0)
#define SPDIFRX_FMT0_DR_DR_MASK (0xffffff)

#define SPDIFRX_FMT0_DR_PT_SHIFT (28)
#define SPDIFRX_FMT0_DR_PT_MASK (0x3)

enum spdifrx_fmt_dr_pt : u32
{
  SPDIFRX_FMT0_DR_PT_B_RECEIVED = 0b01,
  SPDIFRX_FMT0_DR_PT_M_RECEIVED = 0b10,
  SPDIFRX_FMT0_DR_PT_W_RECEIVED = 0b11
};

enum spdifrx_fmt1_dr : u32
{
  SPDIFRX_FMT1_DR_PE = (1 << 0),
  SPDIFRX_FMT1_DR_V = (1 << 1),
  SPDIFRX_FMT1_DR_U = (1 << 2),
  SPDIFRX_FMT1_DR_C = (1 << 3)
};

#define SPDIFRX_FMT1_DR_PT_SHIFT (4)
#define SPDIFRX_FMT1_DR_PT_MASK (0x3)

#define SPDIFRX_FMT1_DR_DR_SHIFT (8)
#define SPDIFRX_FMT1_DR_DR_MASK (0xffffff)

#define SPDIFRX_FMT2_DR_DRNL1_SHIFT (0)
#define SPDIFRX_FMT2_DR_DRNL1_MASK (0xffff)

#define SPDIFRX_FMT2_DR_DRNL2_SHIFT (16)
#define SPDIFRX_FMT2_DR_DRNL2_MASK (0xffff)

enum spdifrx_csr : u32
{
  SPDIFRX_CSR_SOB = (1 << 24)
};

#define SPDIFRX_CSR_USR_SHIFT (0)
#define SPDIFRX_CSR_USR_MASK (0xffff)

#define SPDIFRX_CSR_CS_SHIFT (16)
#define SPDIFRX_CSR_CS_MASK (0xff)

#define SPDIFRX_DIR_THI_SHIFT (0)
#define SPDIFRX_DIR_THI_MASK (0x1fff)

#define SPDIFRX_DIR_TLO_SHIFT (16)
#define SPDIFRX_DIR_TLO_MASK (0x1fff)

// API

enum spdifrx_block
{
  SPDIFRX_BLOCK_IDLE,
  SPDIFRX_BLOCK_SYNC_ONLY,
  SPDIFRX_BLOCK_RECEIVER
};

enum spdifrx_audio_mode
{
  SPDIFRX_AUDIO_MODE_STEREO,
  SPDIFRX_AUDIO_MODE_MONO
};

enum spdifrx_rx_data_format
{
  SPDIFRX_RX_DATA_FORMAT_32BIT,
  SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED,
  SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED
};

enum spdifrx_bit
{
  SPDIFRX_BIT_MASK_PARITY,
  SPDIFRX_BIT_MASK_VALIDITY,
  SPDIFRX_BIT_MASK_CHANNEL_STATUS,
  SPDIFRX_BIT_MASK_PREABLE
};

enum spdifrx_channel
{
  SPDIFRX_CHANNELA,
  SPDIFRX_CHANNELB
};

enum spdifrx_retries
{
  SPDIFRX_RETRIES_NORETRIES,
  SPDIFRX_RETRIES_3RETRIES,
  SPDIFRX_RETRIES_15RETRIES,
  SPDIFRX_RETRIES_63RETRIES
};

enum spdifrx_sync_policy
{
  SPDIFRX_SYNC_POLICY_WAIT_IN,
  SPDIFRX_SYNC_POLICY_DONT_WAIT
};

enum spdifrx_input
{
  SPDIFRX_INPUT_IN1,
  SPDIFRX_INPUT_IN2,
  SPDIFRX_INPUT_IN3,
  SPDIFRX_INPUT_IN4
};

enum spdifrx_interrupt
{
  SPDIFRX_INTERRUPT_RXNE,
  SPDIFRX_INTERRUPT_CTRL_BUF_READY,
  SPDIFRX_INTERRUPT_PARITY_ERR,
  SPDIFRX_INTERRUPT_OVERRUN_ERR,
  SPDIFRX_INTERRUPT_SYNC_DETECTED,
  SPDIFRX_INTERRUPT_SYNC_COMPLETE,
  SPDIFRX_INTERRUPT_SERIAL_INTERFACE_ERR
};

enum spdifrx_flag
{
  SPDRFRX_FLAG_RXNE,
  SPDRFRX_FLAG_CTRL_BUF_READY,
  SPDRFRX_FLAG_PARITY_ERR,
  SPDRFRX_FLAG_OVERRUN_ERR,
  SPDRFRX_FLAG_SYNC_DETECTED,
  SPDRFRX_FLAG_SYNC_COMPLETE,
  SPDRFRX_FLAG_FRAMING_ERR,
  SPDRFRX_FLAG_SYNC_ERR,
  SPDRFRX_FLAG_TIMEOUT_ERR
};

enum spdifrx_recv_bit
{
  SPDIFRX_RECV_BIT_PARITY_ERR,
  SPDIFRX_RECV_BIT_VALIDITY,
  SPDIFRX_RECV_BIT_USER,
  SPDIFRX_RECV_BIT_CHANNEL_STATUS
};

extern struct spdifrx_registers_map* SPDIFRX;

void
spdifrx_set_active_block(
  enum spdifrx_block block
);

void
spdifrx_receiver_dma_enable(void);

void
spdifrx_receiver_dma_disable(void);

void
spdifrx_set_audio_mode(
  enum spdifrx_audio_mode mode
);

void
spdifrx_set_rx_data_format(
  enum spdifrx_rx_data_format format
);

void
spdifrx_copy_bit_enable(
  enum spdifrx_bit bit
);

void
spdifrx_copy_bit_disable(
  enum spdifrx_bit bit
);

void
spdifrx_dma_control_flow_enable(void);

void
spdifrx_dma_control_flow_disable(void);

void
spdifrx_set_channel_flow_control(
  enum spdifrx_channel channel
);

void
spdifrx_set_max_allowed_retries(
  enum spdifrx_retries retries
);

void
spdifrx_set_sync_policy(
  enum spdifrx_sync_policy policy
);

void
spdifrx_set_input(
  enum spdifrx_input input
);

void
spdifrx_interrupt_enable(
  enum spdifrx_interrupt interrupt
);

void
spdifrx_interrupt_disable(
  enum spdifrx_interrupt interrupt
);

u32
spdifrx_is_flag_set(
  enum spdifrx_flag flag
);

u32
spdifrx_get_5symbols_clock_count(void);

void
spdifrx_flag_clear(
  enum spdifrx_flag flag
);

u32
spdifrx_get_recv_bit(
  enum spdifrx_rx_data_format fmt,
  enum spdifrx_recv_bit bit
);

u32
spdifrx_get_recv_preamble(
  enum spdifrx_rx_data_format fmt
);

u32
spdifrx_get_data(
  enum spdifrx_rx_data_format fmt
);

u32
spdifrx_get_user_data_info(
  u32 idx
);

u32
spdifrx_get_channel_status_info(
  u32 idx
);

u32
spdifrx_get_start_of_block(void);

u32
spdifrx_get_threshold_high(void);

u32
spdifrx_get_threshold_low(void);

END_DECLARATIONS

#endif
