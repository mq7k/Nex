#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/spi/spi_v1.h"
#include "libtest/libtest.hpp"

volatile struct spi_registers_map* _SPI;

void
setup(void)
{
  _SPI = (struct spi_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_OFFSET(struct spi_registers_map, CR1, 0x00lu);
  ASSERT_OFFSET(struct spi_registers_map, CR2, 0x04lu);
  ASSERT_OFFSET(struct spi_registers_map, SR, 0x08lu);
  ASSERT_OFFSET(struct spi_registers_map, DR, 0x0clu);
  ASSERT_OFFSET(struct spi_registers_map, CRCPR, 0x10lu);
  ASSERT_OFFSET(struct spi_registers_map, RXCRCR, 0x14lu);
  ASSERT_OFFSET(struct spi_registers_map, TXCRCR, 0x18lu);
  ASSERT_OFFSET(struct spi_registers_map, I2SCFGR, 0x1clu);
  ASSERT_OFFSET(struct spi_registers_map, I2SPR, 0x20lu);
}

void
test_spi_set_clock_phase(void)
{
  _SPI->CR1 = 0;
  spi_set_clock_phase(_SPI, SPI_CLOCK_PHASE_SECOND_TRANSITION);
  ASSERT_EQ(_SPI->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 0);
  spi_set_clock_phase(_SPI, SPI_CLOCK_PHASE_SECOND_TRANSITION);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 0);
  spi_set_clock_phase(_SPI, SPI_CLOCK_PHASE_FIRST_TRANSITION);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_clock_phase(_SPI, SPI_CLOCK_PHASE_FIRST_TRANSITION);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_clock_polarity(void)
{
  _SPI->CR1 = 0;
  spi_set_clock_polarity(_SPI, SPI_CLOCK_POLARITY_HIGH_ON_IDLE);
  ASSERT_EQ(_SPI->CR1, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 1);
  spi_set_clock_polarity(_SPI, SPI_CLOCK_POLARITY_HIGH_ON_IDLE);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 1);
  spi_set_clock_polarity(_SPI, SPI_CLOCK_POLARITY_LOW_ON_IDLE);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_clock_polarity(_SPI, SPI_CLOCK_POLARITY_LOW_ON_IDLE);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_role(void)
{
  _SPI->CR1 = 0;
  spi_set_role(_SPI, SPI_ROLE_MASTER);
  ASSERT_EQ(_SPI->CR1, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 2);
  spi_set_role(_SPI, SPI_ROLE_MASTER);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 2);
  spi_set_role(_SPI, SPI_ROLE_SLAVE);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_role(_SPI, SPI_ROLE_SLAVE);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_baudrate_control(void)
{
  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV2);
  ASSERT_EQ(_SPI->CR1, (0b000u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV2);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b000u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV4);
  ASSERT_EQ(_SPI->CR1, (0b001u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV4);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b001u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV8);
  ASSERT_EQ(_SPI->CR1, (0b010u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV8);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b010u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV16);
  ASSERT_EQ(_SPI->CR1, (0b011u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV16);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b011u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV32);
  ASSERT_EQ(_SPI->CR1, (0b100u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV32);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b100u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV64);
  ASSERT_EQ(_SPI->CR1, (0b101u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV64);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b101u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV128);
  ASSERT_EQ(_SPI->CR1, (0b110u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV128);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b110u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->CR1 = 0;
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV256);
  ASSERT_EQ(_SPI->CR1, (0b111u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(_SPI, SPI_BAUDRATE_CONTROL_DIV256);
  ASSERT_EQ(_SPI->CR1, ~(0x7u << 3) | (0b111u << 3));
  ASSERT_FALSE(execution_halted());


}

void
test_spi(void)
{
  _SPI->CR1 = 0;
  spi_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 6);
  spi_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 6);
  spi_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_frame_format(void)
{
  _SPI->CR1 = 0;
  spi_set_frame_format(_SPI, SPI_FRAME_FORMAT_LSB_FIRST);
  ASSERT_EQ(_SPI->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 7);
  spi_set_frame_format(_SPI, SPI_FRAME_FORMAT_LSB_FIRST);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 7);
  spi_set_frame_format(_SPI, SPI_FRAME_FORMAT_MSB_FIRST);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_frame_format(_SPI, SPI_FRAME_FORMAT_MSB_FIRST);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_internal_slave_select(void)
{
  _SPI->CR1 = 0;
  spi_internal_slave_select_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 8);
  spi_internal_slave_select_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 8);
  spi_internal_slave_select_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_internal_slave_select_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_software_slave_management(void)
{
  _SPI->CR1 = 0;
  spi_software_slave_management_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 9);
  spi_software_slave_management_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 9);
  spi_software_slave_management_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_software_slave_management_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_unidirectional_mode(void)
{
  _SPI->CR1 = 0;
  spi_set_unidirectional_mode(_SPI, SPI_UNIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(_SPI->CR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 10);
  spi_set_unidirectional_mode(_SPI, SPI_UNIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 10);
  spi_set_unidirectional_mode(_SPI, SPI_UNIDIRECTIONAL_MODE_TX_RX);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_unidirectional_mode(_SPI, SPI_UNIDIRECTIONAL_MODE_TX_RX);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_data_frame_format(void)
{
  _SPI->CR1 = 0;
  spi_set_data_frame_format(_SPI, SPI_DATA_FRAME_FORMAT_16BITS);
  ASSERT_EQ(_SPI->CR1, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 11);
  spi_set_data_frame_format(_SPI, SPI_DATA_FRAME_FORMAT_16BITS);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 11);
  spi_set_data_frame_format(_SPI, SPI_DATA_FRAME_FORMAT_8BITS);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_data_frame_format(_SPI, SPI_DATA_FRAME_FORMAT_8BITS);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_crc_transfer_next(void)
{
  _SPI->CR1 = 0;
  spi_crc_transfer_next_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 12);
  spi_crc_transfer_next_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 12);
  spi_crc_transfer_next_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_crc_transfer_next_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_hardware_crc(void)
{
  _SPI->CR1 = 0;
  spi_hardware_crc_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 13);
  spi_hardware_crc_enable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 13);
  spi_hardware_crc_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_hardware_crc_disable(_SPI);
  ASSERT_EQ(_SPI->CR1, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_bidirectional_mode(void)
{
  _SPI->CR1 = 0;
  spi_set_bidirectional_mode(_SPI, SPI_BIDIRECTIONAL_MODE_TX_ONLY);
  ASSERT_EQ(_SPI->CR1, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 14);
  spi_set_bidirectional_mode(_SPI, SPI_BIDIRECTIONAL_MODE_TX_ONLY);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 14);
  spi_set_bidirectional_mode(_SPI, SPI_BIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_bidirectional_mode(_SPI, SPI_BIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_communication_mode(void)
{
  _SPI->CR1 = 0;
  spi_set_communication_mode(_SPI, SPI_COMMUNICATION_MODE_1LINE);
  ASSERT_EQ(_SPI->CR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = ~(1u << 15);
  spi_set_communication_mode(_SPI, SPI_COMMUNICATION_MODE_1LINE);
  ASSERT_EQ(_SPI->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = (1u << 15);
  spi_set_communication_mode(_SPI, SPI_COMMUNICATION_MODE_2LINES);
  ASSERT_EQ(_SPI->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR1 = 0xffffffff;
  spi_set_communication_mode(_SPI, SPI_COMMUNICATION_MODE_2LINES);
  ASSERT_EQ(_SPI->CR1, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_dma_rx(void)
{
  _SPI->CR2 = 0;
  spi_dma_rx_enable(_SPI);
  ASSERT_EQ(_SPI->CR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = ~(1u << 0);
  spi_dma_rx_enable(_SPI);
  ASSERT_EQ(_SPI->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = (1u << 0);
  spi_dma_rx_disable(_SPI);
  ASSERT_EQ(_SPI->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = 0xffffffff;
  spi_dma_rx_disable(_SPI);
  ASSERT_EQ(_SPI->CR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_dma_tx(void)
{
  _SPI->CR2 = 0;
  spi_dma_tx_enable(_SPI);
  ASSERT_EQ(_SPI->CR2, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = ~(1u << 1);
  spi_dma_tx_enable(_SPI);
  ASSERT_EQ(_SPI->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = (1u << 1);
  spi_dma_tx_disable(_SPI);
  ASSERT_EQ(_SPI->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = 0xffffffff;
  spi_dma_tx_disable(_SPI);
  ASSERT_EQ(_SPI->CR2, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_slave_select(void)
{
  _SPI->CR2 = 0;
  spi_slave_select_enable(_SPI);
  ASSERT_EQ(_SPI->CR2, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = ~(1u << 2);
  spi_slave_select_enable(_SPI);
  ASSERT_EQ(_SPI->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = (1u << 2);
  spi_slave_select_disable(_SPI);
  ASSERT_EQ(_SPI->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = 0xffffffff;
  spi_slave_select_disable(_SPI);
  ASSERT_EQ(_SPI->CR2, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_SPI_FRAME_STANDARD)
void
test_spi_set_frame_standard(void)
{
  _SPI->CR2 = 0;
  spi_set_frame_standard(_SPI, SPI_FRAME_STANDARD_TI);
  ASSERT_EQ(_SPI->CR2, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = ~(1u << 4);
  spi_set_frame_standard(_SPI, SPI_FRAME_STANDARD_TI);
  ASSERT_EQ(_SPI->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = (1u << 4);
  spi_set_frame_standard(_SPI, SPI_FRAME_STANDARD_MOTOROLA);
  ASSERT_EQ(_SPI->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = 0xffffffff;
  spi_set_frame_standard(_SPI, SPI_FRAME_STANDARD_MOTOROLA);
  ASSERT_EQ(_SPI->CR2, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_spi_interrupt(void)
{
  _SPI->CR2 = 0;
  spi_interrupt_enable(_SPI, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(_SPI->CR2, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = ~(1u << 5);
  spi_interrupt_enable(_SPI, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(_SPI->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = (1u << 5);
  spi_interrupt_disable(_SPI, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(_SPI->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = 0xffffffff;
  spi_interrupt_disable(_SPI, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(_SPI->CR2, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _SPI->CR2 = 0;
  spi_interrupt_enable(_SPI, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(_SPI->CR2, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = ~(1u << 6);
  spi_interrupt_enable(_SPI, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(_SPI->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = (1u << 6);
  spi_interrupt_disable(_SPI, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(_SPI->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = 0xffffffff;
  spi_interrupt_disable(_SPI, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(_SPI->CR2, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  _SPI->CR2 = 0;
  spi_interrupt_enable(_SPI, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(_SPI->CR2, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = ~(1u << 7);
  spi_interrupt_enable(_SPI, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(_SPI->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = (1u << 7);
  spi_interrupt_disable(_SPI, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(_SPI->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->CR2 = 0xffffffff;
  spi_interrupt_disable(_SPI, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(_SPI->CR2, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_is_flag_set(void)
{
  u32 res;

  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 0);
  res = spi_is_flag_set(_SPI, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 0);
  res = spi_is_flag_set(_SPI, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 1);
  res = spi_is_flag_set(_SPI, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 1);
  res = spi_is_flag_set(_SPI, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 2);
  res = spi_is_flag_set(_SPI, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 2);
  res = spi_is_flag_set(_SPI, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 3);
  res = spi_is_flag_set(_SPI, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 3);
  res = spi_is_flag_set(_SPI, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 4);
  res = spi_is_flag_set(_SPI, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 4);
  res = spi_is_flag_set(_SPI, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 5);
  res = spi_is_flag_set(_SPI, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 5);
  res = spi_is_flag_set(_SPI, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 6);
  res = spi_is_flag_set(_SPI, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 6);
  res = spi_is_flag_set(_SPI, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 7);
  res = spi_is_flag_set(_SPI, SPI_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 7);
  res = spi_is_flag_set(_SPI, SPI_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SPI_FRAME_STANDARD)
  _SPI->SR = 0;
  res = spi_is_flag_set(_SPI, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = (1u << 8);
  res = spi_is_flag_set(_SPI, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _SPI->SR = ~(1u << 8);
  res = spi_is_flag_set(_SPI, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->SR = 0xffffffff;
  res = spi_is_flag_set(_SPI, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

}

// └─Skipping type 'fn_call (TODO)' (spi_crc_error_flag_clear)
void
test_spi_read_byte(void)
{
  u32 res;

  _SPI->DR = 0;
  res = spi_read_byte(_SPI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->DR = ~(0xffu << 0);
  res = spi_read_byte(_SPI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->DR = 0xffu << 0;
  res = spi_read_byte(_SPI);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_spi_write_byte(void)
{
  _SPI->DR = 0;
  spi_write_byte(_SPI, 0);
  ASSERT_EQ(_SPI->DR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _SPI->DR = 0;
  spi_write_byte(_SPI, 0xff);
  ASSERT_EQ(_SPI->DR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_spi_set_crc_polynomial(void)
{
  _SPI->CRCPR = 0;
  spi_set_crc_polynomial(_SPI, 0);
  ASSERT_EQ(_SPI->CRCPR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _SPI->CRCPR = 0;
  spi_set_crc_polynomial(_SPI, 0xffff);
  ASSERT_EQ(_SPI->CRCPR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _SPI->CRCPR = 0;
  spi_set_crc_polynomial(_SPI, 0x10000);
  ASSERT_EQ(_SPI->CRCPR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_spi_get_rx_crc(void)
{
  u32 res;

  _SPI->RXCRCR = 0;
  res = spi_get_rx_crc(_SPI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->RXCRCR = 0xffffffff;
  res = spi_get_rx_crc(_SPI);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_spi_get_tx_crc(void)
{
  u32 res;

  _SPI->TXCRCR = 0;
  res = spi_get_tx_crc(_SPI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->TXCRCR = 0xffffffff;
  res = spi_get_tx_crc(_SPI);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_channel_length(void)
{
  _SPI->I2SCFGR = 0;
  spi_set_channel_length(_SPI, SPI_CHANNEL_LENGTH_32BITS);
  ASSERT_EQ(_SPI->I2SCFGR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(1u << 0);
  spi_set_channel_length(_SPI, SPI_CHANNEL_LENGTH_32BITS);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = (1u << 0);
  spi_set_channel_length(_SPI, SPI_CHANNEL_LENGTH_16BITS);
  ASSERT_EQ(_SPI->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = 0xffffffff;
  spi_set_channel_length(_SPI, SPI_CHANNEL_LENGTH_16BITS);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_data_length(void)
{
  _SPI->I2SCFGR = 0;
  spi_set_data_length(_SPI, SPI_DATA_LENGTH_16BITS);
  ASSERT_EQ(_SPI->I2SCFGR, (0b00u << 1));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 1);
  spi_set_data_length(_SPI, SPI_DATA_LENGTH_16BITS);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 1) | (0b00u << 1));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_data_length(_SPI, SPI_DATA_LENGTH_24BITS);
  ASSERT_EQ(_SPI->I2SCFGR, (0b01u << 1));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 1);
  spi_set_data_length(_SPI, SPI_DATA_LENGTH_24BITS);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 1) | (0b01u << 1));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_data_length(_SPI, SPI_DATA_LENGTH_32BITS);
  ASSERT_EQ(_SPI->I2SCFGR, (0b10u << 1));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 1);
  spi_set_data_length(_SPI, SPI_DATA_LENGTH_32BITS);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 1) | (0b10u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_set_i2s_steady_clock_polarity(void)
{
  _SPI->I2SCFGR = 0;
  spi_set_i2s_steady_clock_polarity(_SPI, SPI_I2S_CLOCK_POLARITY_HIGH);
  ASSERT_EQ(_SPI->I2SCFGR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(1u << 3);
  spi_set_i2s_steady_clock_polarity(_SPI, SPI_I2S_CLOCK_POLARITY_HIGH);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = (1u << 3);
  spi_set_i2s_steady_clock_polarity(_SPI, SPI_I2S_CLOCK_POLARITY_LOW);
  ASSERT_EQ(_SPI->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = 0xffffffff;
  spi_set_i2s_steady_clock_polarity(_SPI, SPI_I2S_CLOCK_POLARITY_LOW);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_i2s_standard(void)
{
  _SPI->I2SCFGR = 0;
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_PHILIPS);
  ASSERT_EQ(_SPI->I2SCFGR, (0b00u << 4));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_PHILIPS);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 4) | (0b00u << 4));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_MSB_JUSTIFIED);
  ASSERT_EQ(_SPI->I2SCFGR, (0b01u << 4));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_MSB_JUSTIFIED);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 4) | (0b01u << 4));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_LSB_JUSTIFIED);
  ASSERT_EQ(_SPI->I2SCFGR, (0b10u << 4));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_LSB_JUSTIFIED);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 4) | (0b10u << 4));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_PCM);
  ASSERT_EQ(_SPI->I2SCFGR, (0b11u << 4));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(_SPI, SPI_I2S_STANDARD_PCM);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 4) | (0b11u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_set_pcm_frame_sync(void)
{
  _SPI->I2SCFGR = 0;
  spi_set_pcm_frame_sync(_SPI, SPI_PCM_FRAME_SYNC_LONG);
  ASSERT_EQ(_SPI->I2SCFGR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(1u << 7);
  spi_set_pcm_frame_sync(_SPI, SPI_PCM_FRAME_SYNC_LONG);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = (1u << 7);
  spi_set_pcm_frame_sync(_SPI, SPI_PCM_FRAME_SYNC_SHORT);
  ASSERT_EQ(_SPI->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = 0xffffffff;
  spi_set_pcm_frame_sync(_SPI, SPI_PCM_FRAME_SYNC_SHORT);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_i2s_configuration_mode(void)
{
  _SPI->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_SLAVE_TX);
  ASSERT_EQ(_SPI->I2SCFGR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_SLAVE_TX);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_SLAVE_RX);
  ASSERT_EQ(_SPI->I2SCFGR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_SLAVE_RX);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_MASTER_TX);
  ASSERT_EQ(_SPI->I2SCFGR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_MASTER_TX);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_MASTER_RX);
  ASSERT_EQ(_SPI->I2SCFGR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(_SPI, SPI_I2S_CONFIG_MODE_MASTER_RX);
  ASSERT_EQ(_SPI->I2SCFGR, ~(0x3u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_i2s(void)
{
  _SPI->I2SCFGR = 0;
  spi_i2s_enable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(1u << 10);
  spi_i2s_enable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = (1u << 10);
  spi_i2s_disable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = 0xffffffff;
  spi_i2s_disable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_mode(void)
{
  _SPI->I2SCFGR = 0;
  spi_set_mode(_SPI, SPI_MODE_I2S);
  ASSERT_EQ(_SPI->I2SCFGR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(1u << 11);
  spi_set_mode(_SPI, SPI_MODE_I2S);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = (1u << 11);
  spi_set_mode(_SPI, SPI_MODE_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = 0xffffffff;
  spi_set_mode(_SPI, SPI_MODE_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_SPI_ASYNC_START)
void
test_spi_async_start(void)
{
  _SPI->I2SCFGR = 0;
  spi_async_start_enable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = ~(1u << 12);
  spi_async_start_enable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = (1u << 12);
  spi_async_start_disable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SCFGR = 0xffffffff;
  spi_async_start_disable(_SPI);
  ASSERT_EQ(_SPI->I2SCFGR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_spi_set_i2s_linear_prescaler(void)
{
  _SPI->I2SPR = 0;
  spi_set_i2s_linear_prescaler(_SPI, 0);
  ASSERT_EQ(_SPI->I2SPR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = 0xffffffff;
  spi_set_i2s_linear_prescaler(_SPI, 0);
  ASSERT_EQ(_SPI->I2SPR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SPR = 0;
  spi_set_i2s_linear_prescaler(_SPI, 0xff);
  ASSERT_EQ(_SPI->I2SPR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = 0xffffffff;
  spi_set_i2s_linear_prescaler(_SPI, 0xff);
  ASSERT_EQ(_SPI->I2SPR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  _SPI->I2SPR = 0;
  spi_set_i2s_linear_prescaler(_SPI, 0x100);
  ASSERT_EQ(_SPI->I2SPR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _SPI->I2SPR = 0xffffffff;
  spi_set_i2s_linear_prescaler(_SPI, 0x100);
  ASSERT_EQ(_SPI->I2SPR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_spi_set_i2s_prescaler_odd_factor(void)
{
  _SPI->I2SPR = 0;
  spi_set_i2s_prescaler_odd_factor(_SPI, SPI_PRESCALER_ODD_FACTOR_MUL2_PLUS1);
  ASSERT_EQ(_SPI->I2SPR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = ~(1u << 8);
  spi_set_i2s_prescaler_odd_factor(_SPI, SPI_PRESCALER_ODD_FACTOR_MUL2_PLUS1);
  ASSERT_EQ(_SPI->I2SPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = (1u << 8);
  spi_set_i2s_prescaler_odd_factor(_SPI, SPI_PRESCALER_ODD_FACTOR_MUL2);
  ASSERT_EQ(_SPI->I2SPR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = 0xffffffff;
  spi_set_i2s_prescaler_odd_factor(_SPI, SPI_PRESCALER_ODD_FACTOR_MUL2);
  ASSERT_EQ(_SPI->I2SPR, 0xffffffff & ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_master_clock_output(void)
{
  _SPI->I2SPR = 0;
  spi_master_clock_output_enable(_SPI);
  ASSERT_EQ(_SPI->I2SPR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = ~(1u << 9);
  spi_master_clock_output_enable(_SPI);
  ASSERT_EQ(_SPI->I2SPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = (1u << 9);
  spi_master_clock_output_disable(_SPI);
  ASSERT_EQ(_SPI->I2SPR, 0);
  ASSERT_FALSE(execution_halted());

  _SPI->I2SPR = 0xffffffff;
  spi_master_clock_output_disable(_SPI);
  ASSERT_EQ(_SPI->I2SPR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
    TEST_FUNC(test_spi_set_clock_phase),
    TEST_FUNC(test_spi_set_clock_polarity),
    TEST_FUNC(test_spi_set_role),
    TEST_FUNC(test_spi_set_baudrate_control),
    TEST_FUNC(test_spi),
    TEST_FUNC(test_spi_set_frame_format),
    TEST_FUNC(test_spi_internal_slave_select),
    TEST_FUNC(test_spi_software_slave_management),
    TEST_FUNC(test_spi_set_unidirectional_mode),
    TEST_FUNC(test_spi_set_data_frame_format),
    TEST_FUNC(test_spi_crc_transfer_next),
    TEST_FUNC(test_spi_hardware_crc),
    TEST_FUNC(test_spi_set_bidirectional_mode),
    TEST_FUNC(test_spi_set_communication_mode),
    TEST_FUNC(test_spi_dma_rx),
    TEST_FUNC(test_spi_dma_tx),
    TEST_FUNC(test_spi_slave_select),
#if defined(STM32_SPI_FRAME_STANDARD)
    TEST_FUNC(test_spi_set_frame_standard),
#endif
    TEST_FUNC(test_spi_interrupt),
    TEST_FUNC(test_spi_is_flag_set),
    TEST_FUNC(test_spi_read_byte),
    TEST_FUNC(test_spi_write_byte),
    TEST_FUNC(test_spi_set_crc_polynomial),
    TEST_FUNC(test_spi_get_rx_crc),
    TEST_FUNC(test_spi_get_tx_crc),
    TEST_FUNC(test_spi_set_channel_length),
    TEST_FUNC(test_spi_set_data_length),
    TEST_FUNC(test_spi_set_i2s_steady_clock_polarity),
    TEST_FUNC(test_spi_set_i2s_standard),
    TEST_FUNC(test_spi_set_pcm_frame_sync),
    TEST_FUNC(test_spi_set_i2s_configuration_mode),
    TEST_FUNC(test_spi_i2s),
    TEST_FUNC(test_spi_set_mode),
#if defined(STM32_SPI_ASYNC_START)
    TEST_FUNC(test_spi_async_start),
#endif
    TEST_FUNC(test_spi_set_i2s_linear_prescaler),
    TEST_FUNC(test_spi_set_i2s_prescaler_odd_factor),
    TEST_FUNC(test_spi_master_clock_output),
  };

  return TESTS_RUN(tests);
}
