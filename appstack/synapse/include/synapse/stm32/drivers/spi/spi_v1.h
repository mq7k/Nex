#ifndef STM32_DRIVER_SPI_H
#define STM32_DRIVER_SPI_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct spi_registers_map
{
  u32 CR1;
  u32 CR2;
  u32 SR;
  u32 DR;
  u32 CRCPR;
  u32 RXCRCR;
  u32 TXCRCR;
  u32 I2SCFGR;
  u32 I2SPR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum spi_cr1 : u32
{
  SPI_CR1_CPHA = (1 << 0),
  SPI_CR1_CPOL = (1 << 1),
  SPI_CR1_MSTR = (1 << 2),
  SPI_CR1_SPE = (1 << 6),
  SPI_CR1_LSBFIRST = (1 << 7),
  SPI_CR1_SSI = (1 << 8),
  SPI_CR1_SSM = (1 << 9),
  SPI_CR1_RXONLY = (1 << 10),
  SPI_CR1_DFF = (1 << 11),
  SPI_CR1_CRCNEXT = (1 << 12),
  SPI_CR1_CRCEN = (1 << 13),
  SPI_CR1_BIDIOE = (1 << 14),
  SPI_CR1_BIDIMODE = (1 << 15)
};

#define SPI_CR1_BR_SHIFT (3)
#define SPI_CR1_BR_MASK (0x7)

enum spi_cr1_br : u32
{
  SPI_CR1_BR_DIV2 = 0b000,
  SPI_CR1_BR_DIV4 = 0b001,
  SPI_CR1_BR_DIV8 = 0b010,
  SPI_CR1_BR_DIV16 = 0b011,
  SPI_CR1_BR_DIV32 = 0b100,
  SPI_CR1_BR_DIV64 = 0b101,
  SPI_CR1_BR_DIV128 = 0b110,
  SPI_CR1_BR_DIV256 = 0b111
};

enum spi_cr2 : u32
{
  SPI_CR2_RXDMAEN = (1 << 0),
  SPI_CR2_TXDMAEN = (1 << 1),
  SPI_CR2_SSOE = (1 << 2),

#if defined(STM32_SPI_FRAME_STANDARD)
  SPI_CR2_FRF = (1 << 4),
#endif

  SPI_CR2_ERRIE = (1 << 5),
  SPI_CR2_RXNEIE = (1 << 6),
  SPI_CR2_TXEIE = (1 << 7)
};

enum spi_sr : u32
{
  SPI_SR_RXNE = (1 << 0),
  SPI_SR_TXE = (1 << 1),
  SPI_SR_CHSIDE = (1 << 2),
  SPI_SR_UDR = (1 << 3),
  SPI_SR_CRCERR = (1 << 4),
  SPI_SR_MODF = (1 << 5),
  SPI_SR_OVR = (1 << 6),
  SPI_SR_BSY = (1 << 7),

#if defined(STM32_SPI_FRAME_STANDARD)
  SPI_SR_FRE = (1 << 8)
#endif
};

#define SPI_DR_MASK (0xffff)
#define SPI_CRCPR_MASK (0xffff)
#define SPI_RXCRCR_MASK (0xffff)
#define SPI_TXCRCR_MASK (0xffff)

enum spi_i2scfgr : u32
{
  SPI_I2SCFGR_CHLEN = (1 << 0),
  SPI_I2SCFGR_CKPOL = (1 << 3),
  SPI_I2SCFGR_PCMSYNC = (1 << 7),
  SPI_I2SCFGR_I2SE = (1 << 10),
  SPI_I2SCFGR_I2SMOD = (1 << 11),

#if defined(STM32_SPI_ASYNC_START)
  SPI_I2SCFGR_ASTREN = (1 << 12)
#endif
};

#define SPI_I2SCFGR_DATLEN_SHIFT (1)
#define SPI_I2SCFGR_DATLEN_MASK (0x3)

enum spi_i2scfgr_datlen : u32
{
  SPI_I2SCFGR_DATLEN_16BITS = 0b00,
  SPI_I2SCFGR_DATLEN_24BITS = 0b01,
  SPI_I2SCFGR_DATLEN_32BITS = 0b10
};

#define SPI_I2SCFGR_I2SSTD_SHIFT (4)
#define SPI_I2SCFGR_I2SSTD_MASK (0x3)

enum spi_i2scfgr_i2sstd : u32
{
  SPI_I2SCFGR_I2SSTD_PHILIPS = 0b00,
  SPI_I2SCFGR_I2SSTD_MSB_JUSTIFIED = 0b01,
  SPI_I2SCFGR_I2SSTD_LSB_JUSTIFIED = 0b10,
  SPI_I2SCFGR_I2SSTD_PCM = 0b11
};

#define SPI_I2SCFGR_I2SCFG_SHIFT (8)
#define SPI_I2SCFGR_I2SCFG_MASK (0x3)

enum spi_i2scfgr_i2scfg : u32
{
  SPI_I2SCFGR_I2SCFG_SLAVE_TX = 0b00,
  SPI_I2SCFGR_I2SCFG_SLAVE_RX = 0b01,
  SPI_I2SCFGR_I2SCFG_MASTER_TX = 0b10,
  SPI_I2SCFGR_I2SCFG_MASTER_RX = 0b11
};

enum spi_i2spr : u32
{
  SPI_I2SPR_ODD = (1 << 8),
  SPI_I2SPR_MCKOE = (1 << 9)
};

#define SPI_I2SPR_I2SDIV_SHIFT (0)
#define SPI_I2SPR_I2SDIV_MASK (0xff)

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum spi_clock_phase
{
  SPI_CLOCK_PHASE_FIRST_TRANSITION,
  SPI_CLOCK_PHASE_SECOND_TRANSITION
};

enum spi_clock_polarity
{
  SPI_CLOCK_POLARITY_LOW_ON_IDLE,
  SPI_CLOCK_POLARITY_HIGH_ON_IDLE
};

enum spi_role
{
  SPI_ROLE_SLAVE,
  SPI_ROLE_MASTER
};

enum spi_baudrate_control
{
  SPI_BAUDRATE_CONTROL_DIV2,
  SPI_BAUDRATE_CONTROL_DIV4,
  SPI_BAUDRATE_CONTROL_DIV8,
  SPI_BAUDRATE_CONTROL_DIV16,
  SPI_BAUDRATE_CONTROL_DIV32,
  SPI_BAUDRATE_CONTROL_DIV64,
  SPI_BAUDRATE_CONTROL_DIV128,
  SPI_BAUDRATE_CONTROL_DIV256
};

enum spi_frame_format
{
  SPI_FRAME_FORMAT_MSB_FIRST,
  SPI_FRAME_FORMAT_LSB_FIRST
};

enum spi_data_frame_format
{
  SPI_DATA_FRAME_FORMAT_8BITS,
  SPI_DATA_FRAME_FORMAT_16BITS
};

enum spi_unidirectional_mode
{
  SPI_UNIDIRECTIONAL_MODE_TX_RX,
  SPI_UNIDIRECTIONAL_MODE_RX_ONLY
};

enum spi_bidirectional_mode
{
  SPI_BIDIRECTIONAL_MODE_RX_ONLY,
  SPI_BIDIRECTIONAL_MODE_TX_ONLY
};

enum spi_communication_mode
{
  SPI_COMMUNICATION_MODE_2LINES,
  SPI_COMMUNICATION_MODE_1LINE
};

#if defined(STM32_SPI_FRAME_STANDARD)
enum spi_frame_standard
{
  SPI_FRAME_STANDARD_MOTOROLA,
  SPI_FRAME_STANDARD_TI
};
#endif

enum spi_interrupt
{
  SPI_INTERRUPT_ERROR,
  SPI_INTERRUPT_RX_BUF_NOT_EMPTY,
  SPI_INTERRUPT_TX_BUF_EMPTY
};

enum spi_flag
{
  SPI_FLAG_RX_BUF_NOT_EMPTY,
  SPI_FLAG_TX_BUF_EMPTY,
  SPI_FLAG_CHANNEL_RIGHT_TX,
  SPI_FLAG_UNDERRUN,
  SPI_FLAG_CRC_ERROR,
  SPI_FLAG_MODE_FAULT,
  SPI_FLAG_OVERRUN,
  SPI_FLAG_BUSY,

#if defined(STM32_SPI_FRAME_STANDARD)
  SPI_FLAG_FRAME_ERROR
#endif
};

enum spi_channel_length
{
  SPI_CHANNEL_LENGTH_16BITS,
  SPI_CHANNEL_LENGTH_32BITS
};

enum spi_data_length
{
  SPI_DATA_LENGTH_16BITS,
  SPI_DATA_LENGTH_24BITS,
  SPI_DATA_LENGTH_32BITS
};

enum spi_i2s_clock_polarity
{
  SPI_I2S_CLOCK_POLARITY_LOW,
  SPI_I2S_CLOCK_POLARITY_HIGH
};

enum spi_i2s_standard
{
  SPI_I2S_STANDARD_PHILIPS,
  SPI_I2S_STANDARD_MSB_JUSTIFIED,
  SPI_I2S_STANDARD_LSB_JUSTIFIED,
  SPI_I2S_STANDARD_PCM
};

enum spi_pcm_frame_sync
{
  SPI_PCM_FRAME_SYNC_SHORT,
  SPI_PCM_FRAME_SYNC_LONG
};

enum spi_i2s_config_mode
{
  SPI_I2S_CONFIG_MODE_SLAVE_TX,
  SPI_I2S_CONFIG_MODE_SLAVE_RX,
  SPI_I2S_CONFIG_MODE_MASTER_TX,
  SPI_I2S_CONFIG_MODE_MASTER_RX
};

enum spi_mode
{
  SPI_MODE_SPI,
  SPI_MODE_I2S
};

enum spi_prescaler_odd_factor
{
  SPI_PRESCALER_ODD_FACTOR_MUL2,
  SPI_PRESCALER_ODD_FACTOR_MUL2_PLUS1
};

#if defined(STM32_SPI1)
extern volatile struct spi_registers_map* SPI1;
#endif

#if defined(STM32_SPI2)
extern volatile struct spi_registers_map* SPI2;
#endif

#if defined(STM32_SPI3)
extern volatile struct spi_registers_map* SPI3;
#endif

#if defined(STM32_SPI4)
extern volatile struct spi_registers_map* SPI4;
#endif

#if defined(STM32_SPI5)
extern volatile struct spi_registers_map* SPI5;
#endif

#if defined(STM32_SPI6)
extern volatile struct spi_registers_map* SPI6;
#endif

void
spi_set_clock_phase(
  volatile struct spi_registers_map* spi,
  enum spi_clock_phase phase
);

void
spi_set_clock_polarity(
  volatile struct spi_registers_map* spi,
  enum spi_clock_polarity polarity
);

void
spi_set_role(
  volatile struct spi_registers_map* spi,
  enum spi_role role
);

void
spi_set_baudrate_control(
  volatile struct spi_registers_map* spi,
  enum spi_baudrate_control control
);

void
spi_enable(
  volatile struct spi_registers_map* spi
);

void
spi_disable(
  volatile struct spi_registers_map* spi
);

void
spi_set_frame_format(
  volatile struct spi_registers_map* spi,
  enum spi_frame_format format
);

void
spi_internal_slave_select_enable(
  volatile struct spi_registers_map* spi
);

void
spi_internal_slave_select_disable(
  volatile struct spi_registers_map* spi
);

void
spi_software_slave_management_enable(
  volatile struct spi_registers_map* spi
);

void
spi_software_slave_management_disable(
  volatile struct spi_registers_map* spi
);

void
spi_set_unidirectional_mode(
  volatile struct spi_registers_map* spi,
  enum spi_unidirectional_mode mode
);

void
spi_set_data_frame_format(
  volatile struct spi_registers_map* spi,
  enum spi_data_frame_format format
);

void
spi_crc_transfer_next_enable(
  volatile struct spi_registers_map* spi
);

void
spi_crc_transfer_next_disable(
  volatile struct spi_registers_map* spi
);

void
spi_hardware_crc_enable(
  volatile struct spi_registers_map* spi
);

void
spi_hardware_crc_disable(
  volatile struct spi_registers_map* spi
);

void
spi_set_bidirectional_mode(
  volatile struct spi_registers_map* spi,
  enum spi_bidirectional_mode mode
);

void
spi_set_communication_mode(
  volatile struct spi_registers_map* spi,
  enum spi_communication_mode mode
);

void
spi_dma_rx_enable(
  volatile struct spi_registers_map* spi
);

void
spi_dma_rx_disable(
  volatile struct spi_registers_map* spi
);

void
spi_dma_tx_enable(
  volatile struct spi_registers_map* spi
);

void
spi_dma_tx_disable(
  volatile struct spi_registers_map* spi
);

void
spi_slave_select_enable(
  volatile struct spi_registers_map* spi
);

void
spi_slave_select_disable(
  volatile struct spi_registers_map* spi
);

#if defined(STM32_SPI_FRAME_STANDARD)
void
spi_set_frame_standard(
  volatile struct spi_registers_map* spi,
  enum spi_frame_standard standard
);
#endif

void
spi_interrupt_enable(
  volatile struct spi_registers_map* spi,
  enum spi_interrupt interrupt
);

void
spi_interrupt_disable(
  volatile struct spi_registers_map* spi,
  enum spi_interrupt interrupt
);

u32
spi_is_flag_set(
  volatile struct spi_registers_map* spi,
  enum spi_flag flag
);

void
spi_crc_error_flag_clear(
  volatile struct spi_registers_map* spi
);

u32
spi_data_read(
  volatile struct spi_registers_map* spi
);

void
spi_data_write(
  volatile struct spi_registers_map* spi,
  u32 data
);

u32
spi_transceive_byte(
  volatile struct spi_registers_map* spi,
  u32 byte
);

void
spi_transceive_bytes(
  volatile struct spi_registers_map* spi,
  u32* bytes,
  u32 count,
  u32* buf
);

void
spi_transfer_byte(
  volatile struct spi_registers_map* spi,
  u32 byte
);

void
spi_transfer_bytes(
  volatile struct spi_registers_map* spi,
  const u8* bytes,
  u32 count
);

u32
spi_receive_byte(
  volatile struct spi_registers_map* spi
);

void
spi_receive_bytes(
  volatile struct spi_registers_map* spi,
  u8* buf,
  u32 count
);

void
spi_set_crc_polynomial(
  volatile struct spi_registers_map* spi,
  u32 polynomial
);

u32
spi_get_rx_crc(
  volatile struct spi_registers_map* spi
);

u32
spi_get_tx_crc(
  volatile struct spi_registers_map* spi
);

void
spi_set_channel_length(
  volatile struct spi_registers_map* spi,
  enum spi_channel_length length
);

void
spi_set_data_length(
  volatile struct spi_registers_map* spi,
  enum spi_data_length length
);

void
spi_set_i2s_steady_clock_polarity(
  volatile struct spi_registers_map* spi,
  enum spi_i2s_clock_polarity polarity
);

void
spi_set_i2s_standard(
  volatile struct spi_registers_map* spi,
  enum spi_i2s_standard std
);

void
spi_set_pcm_frame_sync(
  volatile struct spi_registers_map* spi,
  enum spi_pcm_frame_sync sync
);

void
spi_set_i2s_configuration_mode(
  volatile struct spi_registers_map* spi,
  enum spi_i2s_config_mode mode
);

void
spi_i2s_enable(
  volatile struct spi_registers_map* spi
);

void
spi_i2s_disable(
  volatile struct spi_registers_map* spi
);

void
spi_set_mode(
  volatile struct spi_registers_map* spi,
  enum spi_mode mode
);

#if defined(STM32_SPI_ASYNC_START)
void
spi_async_start_enable(
  volatile struct spi_registers_map* spi
);

void
spi_async_start_disable(
  volatile struct spi_registers_map* spi
);
#endif

void
spi_set_i2s_linear_prescaler(
  volatile struct spi_registers_map* spi,
  u32 prescaler
);

void
spi_set_i2s_prescaler_odd_factor(
  volatile struct spi_registers_map* spi,
  enum spi_prescaler_odd_factor factor
);

void
spi_master_clock_output_enable(
  volatile struct spi_registers_map* spi
);

void
spi_master_clock_output_disable(
  volatile struct spi_registers_map* spi
);

END_DECLARATIONS

#endif
