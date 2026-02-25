#include "synapse/stm32/drivers/spi/spi_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"

typedef volatile struct spi_registers_map spi_periph;

#if defined(STM32_SPI1)
spi_periph* SPI1 = (spi_periph*) (SPI1_ADDR);
#endif

#if defined(STM32_SPI2)
spi_periph* SPI2 = (spi_periph*) (SPI2_ADDR);
#endif

#if defined(STM32_SPI3)
spi_periph* SPI3 = (spi_periph*) (SPI3_ADDR);
#endif

#if defined(STM32_SPI4)
spi_periph* SPI4 = (spi_periph*) (SPI4_ADDR);
#endif

#if defined(STM32_SPI5)
spi_periph* SPI5 = (spi_periph*) (SPI5_ADDR);
#endif

#if defined(STM32_SPI6)
spi_periph* SPI6 = (spi_periph*) (SPI6_ADDR);
#endif

void
spi_set_clock_phase(
  volatile struct spi_registers_map* spi,
  enum spi_clock_phase phase
)
{
  volatile u32* reg = &spi->CR1;
  switch (phase)
  {
    case SPI_CLOCK_PHASE_FIRST_TRANSITION:
      *reg &= ~SPI_CR1_CPHA;
      break;

    case SPI_CLOCK_PHASE_SECOND_TRANSITION:
      *reg |= SPI_CR1_CPHA;
      break;

    default:
      devmode_error_invalid_enum(enum spi_clock_phase, phase);
      break;
  }
}

void
spi_set_clock_polarity(
  volatile struct spi_registers_map* spi,
  enum spi_clock_polarity polarity
)
{
  volatile u32* reg = &spi->CR1;
  switch (polarity)
  {
    case SPI_CLOCK_POLARITY_LOW_ON_IDLE:
      *reg &= ~SPI_CR1_CPOL;
      break;

    case SPI_CLOCK_POLARITY_HIGH_ON_IDLE:
      *reg |= SPI_CR1_CPOL;
      break;
      
    default:
      devmode_error_invalid_enum(enum spi_clock_polarity, polarity);
      break;
  }
}

void
spi_set_role(
  volatile struct spi_registers_map* spi,
  enum spi_role role
)
{
  volatile u32* reg = &spi->CR1;
  switch (role)
  {
    case SPI_ROLE_SLAVE:
      *reg &= ~SPI_CR1_MSTR;
      break;

    case SPI_ROLE_MASTER:
      *reg |= SPI_CR1_MSTR;
      break;

    default:
      devmode_error_invalid_enum(enum spi_role, role);
      break;
  }
}

void
spi_set_baudrate_control(
  volatile struct spi_registers_map* spi,
  enum spi_baudrate_control control
)
{
  constexpr u32 shift = SPI_CR1_BR_SHIFT;
  constexpr u32 mask = SPI_CR1_BR_MASK << shift;
  volatile u32* reg = &spi->CR1;

  switch (control)
  {
    case SPI_BAUDRATE_CONTROL_DIV2:
      *reg &= ~mask;
      break;

    case SPI_BAUDRATE_CONTROL_DIV4:
      syn_set_register_bits(reg, mask, SPI_CR1_BR_DIV4 << shift);
      break;

    case SPI_BAUDRATE_CONTROL_DIV8:
      syn_set_register_bits(reg, mask, SPI_CR1_BR_DIV8 << shift);
      break;

    case SPI_BAUDRATE_CONTROL_DIV16:
      syn_set_register_bits(reg, mask, SPI_CR1_BR_DIV16 << shift);
      break;

    case SPI_BAUDRATE_CONTROL_DIV32:
      syn_set_register_bits(reg, mask, SPI_CR1_BR_DIV32 << shift);
      break;

    case SPI_BAUDRATE_CONTROL_DIV64:
      syn_set_register_bits(reg, mask, SPI_CR1_BR_DIV64 << shift);
      break;

    case SPI_BAUDRATE_CONTROL_DIV128:
      syn_set_register_bits(reg, mask, SPI_CR1_BR_DIV128 << shift);
      break;

    case SPI_BAUDRATE_CONTROL_DIV256:
      syn_set_register_bits(reg, mask, SPI_CR1_BR_DIV256 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum spi_baudrate_control, control);
      break;
  }
}

void
spi_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 |= SPI_CR1_SPE;
}

void
spi_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 &= ~SPI_CR1_SPE;
}

void
spi_set_frame_format(
  volatile struct spi_registers_map* spi,
  enum spi_frame_format format
)
{
  volatile u32* reg = &spi->CR1;
  switch (format)
  {
    case SPI_FRAME_FORMAT_MSB_FIRST:
      *reg &= ~SPI_CR1_LSBFIRST;
      break;

    case SPI_FRAME_FORMAT_LSB_FIRST:
      *reg |= SPI_CR1_LSBFIRST;
      break;

    default:
      devmode_error_invalid_enum(enum spi_frame_format, format);
      break;
  }
}

void
spi_internal_slave_select_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 |= SPI_CR1_SSI;
}

void
spi_internal_slave_select_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 &= ~SPI_CR1_SSI;
}

void
spi_software_slave_management_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 |= SPI_CR1_SSM;
}

void
spi_software_slave_management_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 &= ~SPI_CR1_SSM;
}

void
spi_set_unidirectional_mode(
  volatile struct spi_registers_map* spi,
  enum spi_unidirectional_mode mode
)
{
  volatile u32* reg = &spi->CR1;
  switch (mode)
  {
    case SPI_UNIDIRECTIONAL_MODE_TX_RX:
      *reg &= ~SPI_CR1_RXONLY;
      break;

    case SPI_UNIDIRECTIONAL_MODE_RX_ONLY:
      *reg |= SPI_CR1_RXONLY;
      break;

    default:
      devmode_error_invalid_enum(enum spi_unidirectional_mode, mode);
      break;
  }
}

void
spi_set_data_frame_format(
  volatile struct spi_registers_map* spi,
  enum spi_data_frame_format format
)
{
  volatile u32* reg = &spi->CR1;
  switch (format)
  {
    case SPI_DATA_FRAME_FORMAT_8BITS:
      *reg &= ~SPI_CR1_DFF;
      break;

    case SPI_DATA_FRAME_FORMAT_16BITS:
      *reg |= SPI_CR1_DFF;
      break;

    default:
      devmode_error_invalid_enum(enum spi_data_frame_format, format);
      break;
  }
}

void
spi_crc_transfer_next_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 |= SPI_CR1_CRCNEXT;
}

void
spi_crc_transfer_next_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 &= ~SPI_CR1_CRCNEXT;
}

void
spi_hardware_crc_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 |= SPI_CR1_CRCEN;
}

void
spi_hardware_crc_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR1 &= ~SPI_CR1_CRCEN;
}

void
spi_set_bidirectional_mode(
  volatile struct spi_registers_map* spi,
  enum spi_bidirectional_mode mode
)
{
  volatile u32* reg = &spi->CR1;
  switch (mode)
  {
    case SPI_BIDIRECTIONAL_MODE_RX_ONLY:
      *reg &= ~SPI_CR1_BIDIOE;
      break;

    case SPI_BIDIRECTIONAL_MODE_TX_ONLY:
      *reg |= SPI_CR1_BIDIOE;
      break;

    default:
      devmode_error_invalid_enum(enum spi_bidirectional_mode, mode);
      break;
  }
}

void
spi_set_communication_mode(
  volatile struct spi_registers_map* spi,
  enum spi_communication_mode mode
)
{
  volatile u32* reg = &spi->CR1;
  switch (mode)
  {
    case SPI_COMMUNICATION_MODE_2LINES:
      *reg &= ~SPI_CR1_BIDIMODE;
      break;

    case SPI_COMMUNICATION_MODE_1LINE:
      *reg |= SPI_CR1_BIDIMODE;
      break;

    default:
      devmode_error_invalid_enum(enum spi_communication_mode, mode);
      break;
  }
}

void
spi_dma_rx_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR2 |= SPI_CR2_RXDMAEN;
}

void
spi_dma_rx_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR2 &= ~SPI_CR2_RXDMAEN;
}

void
spi_dma_tx_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR2 |= SPI_CR2_TXDMAEN;
}

void
spi_dma_tx_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR2 &= ~SPI_CR2_TXDMAEN;
}

void
spi_slave_select_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR2 |= SPI_CR2_SSOE;
}

void
spi_slave_select_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->CR2 &= ~SPI_CR2_SSOE;
}

#if defined(STM32_SPI_FRAME_STANDARD)
void
spi_set_frame_standard(
  volatile struct spi_registers_map* spi,
  enum spi_frame_standard standard
)
{
  volatile u32* reg = &spi->CR2;
  switch (standard)
  {
    case SPI_FRAME_STANDARD_MOTOROLA:
      *reg &= ~SPI_CR2_FRF;
      break;

    case SPI_FRAME_STANDARD_TI:
      *reg |= SPI_CR2_FRF;
      break;

    default:
      devmode_error_invalid_enum(enum spi_frame_format, standard);
      break;
  }
}
#endif

void
spi_interrupt_enable(
  volatile struct spi_registers_map* spi,
  enum spi_interrupt interrupt
)
{
  volatile u32* reg = &spi->CR2;
  switch (interrupt)
  {
    case SPI_INTERRUPT_ERROR:
      *reg |= SPI_CR2_ERRIE;
      break;

    case SPI_INTERRUPT_RX_BUF_NOT_EMPTY:
      *reg |= SPI_CR2_RXNEIE;
      break;

    case SPI_INTERRUPT_TX_BUF_EMPTY:
      *reg |= SPI_CR2_TXEIE;  
      break;

    default:
      devmode_error_invalid_enum(enum spi_interrupt, interrupt);
      break;
  }
}

void
spi_interrupt_disable(
  volatile struct spi_registers_map* spi,
  enum spi_interrupt interrupt
)
{
  volatile u32* reg = &spi->CR2;
  switch (interrupt)
  {
    case SPI_INTERRUPT_ERROR:
      *reg &= ~SPI_CR2_ERRIE;
      break;

    case SPI_INTERRUPT_RX_BUF_NOT_EMPTY:
      *reg &= ~SPI_CR2_RXNEIE;
      break;

    case SPI_INTERRUPT_TX_BUF_EMPTY:
      *reg &= ~SPI_CR2_TXEIE;  
      break;

    default:
      devmode_error_invalid_enum(enum spi_interrupt, interrupt);
      break;
  }
}

u32
spi_is_flag_set(
  volatile struct spi_registers_map* spi,
  enum spi_flag flag
)
{
  volatile u32* reg = &spi->SR;
  switch (flag)
  {
    case SPI_FLAG_RX_BUF_NOT_EMPTY:
      return *reg & SPI_SR_RXNE;

    case SPI_FLAG_TX_BUF_EMPTY:
      return *reg & SPI_SR_TXE;

    case SPI_FLAG_CHANNEL_RIGHT_TX:
      return *reg & SPI_SR_CHSIDE;

    case SPI_FLAG_UNDERRUN:
      return *reg & SPI_SR_UDR;

    case SPI_FLAG_CRC_ERROR:
      return *reg & SPI_SR_CRCERR;

    case SPI_FLAG_MODE_FAULT:
      return *reg & SPI_SR_MODF;

    case SPI_FLAG_OVERRUN:
      return *reg & SPI_SR_OVR;

    case SPI_FLAG_BUSY:
      return *reg & SPI_SR_BSY;

#if defined(STM32_SPI_FRAME_STANDARD)
    case SPI_FLAG_FRAME_ERROR:
      return *reg & SPI_SR_FRE;
#endif

    default:
      devmode_error_invalid_enum(enum spi_flag, flag);
      return 0;
  }
}

void
spi_crc_error_flag_clear(
  volatile struct spi_registers_map* spi
)
{
  spi->SR &= ~SPI_SR_CRCERR;
}

u32
spi_data_read(
  volatile struct spi_registers_map* spi
)
{
  return spi->DR;
}

void
spi_data_write(
  volatile struct spi_registers_map* spi,
  u32 data
)
{
  spi->DR = data;
}

u32
spi_transceive_byte(
  volatile struct spi_registers_map* spi,
  u32 byte
)
{
  WAIT_UNTIL(spi_is_flag_set(spi, SPI_FLAG_TX_BUF_EMPTY));
  spi_data_write(spi, byte);

  WAIT_UNTIL(spi_is_flag_set(SPI1, SPI_FLAG_BUSY) == 0);

  WAIT_UNTIL(spi_is_flag_set(SPI1, SPI_FLAG_RX_BUF_NOT_EMPTY));
  u32 data = spi_data_read(SPI1);
  return data;
}

void
spi_transceive_bytes(
  volatile struct spi_registers_map* spi,
  u32* bytes,
  u32 count,
  u32* buf
)
{
  for (u32 i = 0; i < count; ++i)
  {
    buf[i] = spi_transceive_byte(spi, bytes[i]);
  }
}

void
spi_transfer_byte(
  volatile struct spi_registers_map* spi,
  u32 byte
)
{
  WAIT_UNTIL(spi_is_flag_set(spi, SPI_FLAG_TX_BUF_EMPTY));
  spi_data_write(spi, byte);

  WAIT_UNTIL(spi_is_flag_set(spi, SPI_FLAG_BUSY) == 0);

  WAIT_UNTIL(spi_is_flag_set(spi, SPI_FLAG_RX_BUF_NOT_EMPTY));
  (void) spi_data_read(spi);
}

void
spi_transfer_bytes(
  volatile struct spi_registers_map* spi,
  const u8* bytes,
  u32 count
)
{
  for (u32 i = 0; i < count; ++i)
  {
    spi_transfer_byte(spi, bytes[i]);
  }
}

u32
spi_receive_byte(
  volatile struct spi_registers_map* spi
)
{
  WAIT_UNTIL(spi_is_flag_set(spi, SPI_FLAG_TX_BUF_EMPTY));
  spi_data_write(spi, 0xff);

  WAIT_UNTIL(spi_is_flag_set(spi, SPI_FLAG_BUSY) == 0);

  WAIT_UNTIL(spi_is_flag_set(spi, SPI_FLAG_RX_BUF_NOT_EMPTY));
  return spi_data_read(spi);
}

void
spi_receive_bytes(
  volatile struct spi_registers_map* spi,
  u8* buf,
  u32 count
)
{
  for (u32 i = 0; i < count; ++i)
  {
    buf[i] = (u8) spi_receive_byte(spi);
  }
}

void
spi_set_crc_polynomial(
  volatile struct spi_registers_map* spi,
  u32 polynomial
)
{
  devmode_assert_lower_or_eq(polynomial, SPI_CRCPR_MASK);
  spi->CRCPR = polynomial;
}

u32
spi_get_rx_crc(
  volatile struct spi_registers_map* spi
)
{
  return spi->RXCRCR;
}

u32
spi_get_tx_crc(
  volatile struct spi_registers_map* spi
)
{
  return spi->TXCRCR;
}

void
spi_set_channel_length(
  volatile struct spi_registers_map* spi,
  enum spi_channel_length length
)
{
  volatile u32* reg = &spi->I2SCFGR;
  switch (length)
  {
    case SPI_CHANNEL_LENGTH_16BITS:
      *reg &= ~SPI_I2SCFGR_CHLEN;
      break;

    case SPI_CHANNEL_LENGTH_32BITS:
      *reg |= SPI_I2SCFGR_CHLEN;
      break;

    default:
      devmode_error_invalid_enum(enum spi_channel_length, length);
      break;
  }
}

void
spi_set_data_length(
  volatile struct spi_registers_map* spi,
  enum spi_data_length length
)
{
  constexpr u32 shift = SPI_I2SCFGR_DATLEN_SHIFT;
  constexpr u32 mask = SPI_I2SCFGR_DATLEN_MASK << shift;
  volatile u32* reg = &spi->I2SCFGR;

  switch (length)
  {
    case SPI_DATA_LENGTH_16BITS:
      *reg &= ~mask;
      break;

    case SPI_DATA_LENGTH_24BITS:
      syn_set_register_bits(reg, mask, SPI_I2SCFGR_DATLEN_24BITS << shift);
      break;

    case SPI_DATA_LENGTH_32BITS:
      syn_set_register_bits(reg, mask, SPI_I2SCFGR_DATLEN_32BITS << shift);
      break;

    default:
      devmode_error_invalid_enum(enum spi_data_length, length);
      break;
  }
}

void
spi_set_i2s_steady_clock_polarity(
  volatile struct spi_registers_map* spi,
  enum spi_i2s_clock_polarity polarity
)
{
  volatile u32* reg = &spi->I2SCFGR;
  switch (polarity)
  {
    case SPI_I2S_CLOCK_POLARITY_LOW:
      *reg &= ~SPI_I2SCFGR_CKPOL;
      break;

    case SPI_I2S_CLOCK_POLARITY_HIGH:
      *reg |= SPI_I2SCFGR_CKPOL;
      break;

    default:
      devmode_error_invalid_enum(enum spi_i2s_clock_polarity, polarity);
      break;
  }
}

void
spi_set_i2s_standard(
  volatile struct spi_registers_map* spi,
  enum spi_i2s_standard std
)
{
  constexpr u32 shift = SPI_I2SCFGR_I2SSTD_SHIFT;
  constexpr u32 mask = SPI_I2SCFGR_I2SSTD_MASK << shift;
  volatile u32* reg = &spi->I2SCFGR;

  switch (std)
  {
    case SPI_I2S_STANDARD_PHILIPS:
      *reg &= ~mask;
      break;

    case SPI_I2S_STANDARD_MSB_JUSTIFIED:
      syn_set_register_bits(reg, mask, SPI_I2SCFGR_I2SSTD_MSB_JUSTIFIED << shift);
      break;

    case SPI_I2S_STANDARD_LSB_JUSTIFIED:
      syn_set_register_bits(reg, mask, SPI_I2SCFGR_I2SSTD_LSB_JUSTIFIED << shift);
      break;

    case SPI_I2S_STANDARD_PCM:
      *reg |= (SPI_I2SCFGR_I2SSTD_PCM << shift);
      break;

    default:
      devmode_error_invalid_enum(enum spi_i2s_standard, std);
      break;
  }
}

void
spi_set_pcm_frame_sync(
  volatile struct spi_registers_map* spi,
  enum spi_pcm_frame_sync sync
)
{
  volatile u32* reg = &spi->I2SCFGR;
  switch (sync)
  {
    case SPI_PCM_FRAME_SYNC_SHORT:
      *reg &= ~SPI_I2SCFGR_PCMSYNC;
      break;

    case SPI_PCM_FRAME_SYNC_LONG:
      *reg |= SPI_I2SCFGR_PCMSYNC;
      break;

    default:
      devmode_error_invalid_enum(enum spi_pcm_frame_sync, sync);
      break;
  }
}

void
spi_set_i2s_configuration_mode(
  volatile struct spi_registers_map* spi,
  enum spi_i2s_config_mode mode
)
{
  constexpr u32 shift = SPI_I2SCFGR_I2SCFG_SHIFT;
  constexpr u32 mask = SPI_I2SCFGR_I2SCFG_MASK << shift;
  volatile u32* reg = &spi->I2SCFGR;

  switch (mode)
  {
    case SPI_I2S_CONFIG_MODE_SLAVE_TX:
      *reg &= ~mask;
      break;

    case SPI_I2S_CONFIG_MODE_SLAVE_RX:
      syn_set_register_bits(reg, mask, SPI_I2SCFGR_I2SCFG_SLAVE_RX << shift);
      break;

    case SPI_I2S_CONFIG_MODE_MASTER_TX:
      syn_set_register_bits(reg, mask, SPI_I2SCFGR_I2SCFG_MASTER_TX << shift);
      break;

    case SPI_I2S_CONFIG_MODE_MASTER_RX:
      *reg |= (SPI_I2SCFGR_I2SCFG_MASTER_RX << shift);
      break;

    default:
      devmode_error_invalid_enum(enum spi_i2s_config_mode, mode);
      break;
  }
}

void
spi_i2s_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->I2SCFGR |= SPI_I2SCFGR_I2SE;
}

void
spi_i2s_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->I2SCFGR &= ~SPI_I2SCFGR_I2SE;
}

void
spi_set_mode(
  volatile struct spi_registers_map* spi,
  enum spi_mode mode
)
{
  volatile u32* reg = &spi->I2SCFGR;
  switch (mode)
  {
    case SPI_MODE_SPI:
      *reg &= ~SPI_I2SCFGR_I2SMOD;
      break;

    case SPI_MODE_I2S:
      *reg |= SPI_I2SCFGR_I2SMOD;
      break;

    default:
      devmode_error_invalid_enum(enum spi_mode, mode);
      break;
  }
}

#if defined(STM32_SPI_ASYNC_START)
void
spi_async_start_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->I2SCFGR |= SPI_I2SCFGR_ASTREN;
}

void
spi_async_start_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->I2SCFGR &= ~SPI_I2SCFGR_ASTREN;
}
#endif

void
spi_set_i2s_linear_prescaler(
  volatile struct spi_registers_map* spi,
  u32 prescaler
)
{
  devmode_assert_lower_or_eq(prescaler, SPI_I2SPR_I2SDIV_MASK);

  constexpr u32 shift = SPI_I2SPR_I2SDIV_SHIFT;
  constexpr u32 mask = SPI_I2SPR_I2SDIV_MASK << shift;
  volatile u32* reg = &spi->I2SPR;
  syn_set_register_bits(reg, mask, prescaler);
}

void
spi_set_i2s_prescaler_odd_factor(
  volatile struct spi_registers_map* spi,
  enum spi_prescaler_odd_factor factor
)
{
  volatile u32* reg = &spi->I2SPR;
  switch (factor)
  {
    case SPI_PRESCALER_ODD_FACTOR_MUL2:
      *reg &= ~SPI_I2SPR_ODD;
      break;

    case SPI_PRESCALER_ODD_FACTOR_MUL2_PLUS1:
      *reg |= SPI_I2SPR_ODD;
      break;

    default:
      devmode_error_invalid_enum(enum spi_prescaler_odd_factor, factor);
      break;
  }
}

void
spi_master_clock_output_enable(
  volatile struct spi_registers_map* spi
)
{
  spi->I2SPR |= SPI_I2SPR_MCKOE;
}

void
spi_master_clock_output_disable(
  volatile struct spi_registers_map* spi
)
{
  spi->I2SPR &= ~SPI_I2SPR_MCKOE;
}
