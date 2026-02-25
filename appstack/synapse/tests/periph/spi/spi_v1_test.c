#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/spi/spi_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  SPI1 = (struct spi_registers_map*) membuf;
}

void
test_spi_set_clock_phase(void)
{
  SPI1->CR1 = 0;
  spi_set_clock_phase(SPI1, SPI_CLOCK_PHASE_SECOND_TRANSITION);
  ASSERT_EQ(SPI1->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 0);
  spi_set_clock_phase(SPI1, SPI_CLOCK_PHASE_SECOND_TRANSITION);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 0);
  spi_set_clock_phase(SPI1, SPI_CLOCK_PHASE_FIRST_TRANSITION);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_clock_phase(SPI1, SPI_CLOCK_PHASE_FIRST_TRANSITION);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_clock_polarity(void)
{
  SPI1->CR1 = 0;
  spi_set_clock_polarity(SPI1, SPI_CLOCK_POLARITY_HIGH_ON_IDLE);
  ASSERT_EQ(SPI1->CR1, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 1);
  spi_set_clock_polarity(SPI1, SPI_CLOCK_POLARITY_HIGH_ON_IDLE);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 1);
  spi_set_clock_polarity(SPI1, SPI_CLOCK_POLARITY_LOW_ON_IDLE);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_clock_polarity(SPI1, SPI_CLOCK_POLARITY_LOW_ON_IDLE);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_role(void)
{
  SPI1->CR1 = 0;
  spi_set_role(SPI1, SPI_ROLE_MASTER);
  ASSERT_EQ(SPI1->CR1, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 2);
  spi_set_role(SPI1, SPI_ROLE_MASTER);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 2);
  spi_set_role(SPI1, SPI_ROLE_SLAVE);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_role(SPI1, SPI_ROLE_SLAVE);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_baudrate_control(void)
{
  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV2'}, self.value='0b000', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV2);
  ASSERT_EQ(SPI1->CR1, (0b000u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV2);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b000u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV4'}, self.value='0b001', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV4);
  ASSERT_EQ(SPI1->CR1, (0b001u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV4);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b001u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV8'}, self.value='0b010', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV8);
  ASSERT_EQ(SPI1->CR1, (0b010u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV8);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b010u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV16'}, self.value='0b011', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV16);
  ASSERT_EQ(SPI1->CR1, (0b011u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV16);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b011u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV32'}, self.value='0b100', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV32);
  ASSERT_EQ(SPI1->CR1, (0b100u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV32);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b100u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV64'}, self.value='0b101', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV64);
  ASSERT_EQ(SPI1->CR1, (0b101u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV64);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b101u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV128'}, self.value='0b110', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV128);
  ASSERT_EQ(SPI1->CR1, (0b110u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV128);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b110u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=3, self.mask='0x7', self.varsmap={'control': 'SPI_BAUDRATE_CONTROL_DIV256'}, self.value='0b111', self.ifdef=[], self.halt=False
  SPI1->CR1 = 0;
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV256);
  ASSERT_EQ(SPI1->CR1, (0b111u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(0x7u << 3);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV256);
  ASSERT_EQ(SPI1->CR1, ~(0x7u << 3) | (0b111u << 3));
  ASSERT_FALSE(execution_halted());


}

void
test_spi(void)
{
  SPI1->CR1 = 0;
  spi_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 6);
  spi_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 6);
  spi_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_frame_format(void)
{
  SPI1->CR1 = 0;
  spi_set_frame_format(SPI1, SPI_FRAME_FORMAT_LSB_FIRST);
  ASSERT_EQ(SPI1->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 7);
  spi_set_frame_format(SPI1, SPI_FRAME_FORMAT_LSB_FIRST);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 7);
  spi_set_frame_format(SPI1, SPI_FRAME_FORMAT_MSB_FIRST);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_frame_format(SPI1, SPI_FRAME_FORMAT_MSB_FIRST);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_internal_slave_select(void)
{
  SPI1->CR1 = 0;
  spi_internal_slave_select_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 8);
  spi_internal_slave_select_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 8);
  spi_internal_slave_select_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_internal_slave_select_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_software_slave_management(void)
{
  SPI1->CR1 = 0;
  spi_software_slave_management_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 9);
  spi_software_slave_management_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 9);
  spi_software_slave_management_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_software_slave_management_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_unidirectional_mode(void)
{
  SPI1->CR1 = 0;
  spi_set_unidirectional_mode(SPI1, SPI_UNIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(SPI1->CR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 10);
  spi_set_unidirectional_mode(SPI1, SPI_UNIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 10);
  spi_set_unidirectional_mode(SPI1, SPI_UNIDIRECTIONAL_MODE_TX_RX);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_unidirectional_mode(SPI1, SPI_UNIDIRECTIONAL_MODE_TX_RX);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_data_frame_format(void)
{
  SPI1->CR1 = 0;
  spi_set_data_frame_format(SPI1, SPI_DATA_FRAME_FORMAT_16BITS);
  ASSERT_EQ(SPI1->CR1, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 11);
  spi_set_data_frame_format(SPI1, SPI_DATA_FRAME_FORMAT_16BITS);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 11);
  spi_set_data_frame_format(SPI1, SPI_DATA_FRAME_FORMAT_8BITS);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_data_frame_format(SPI1, SPI_DATA_FRAME_FORMAT_8BITS);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_crc_transfer_next(void)
{
  SPI1->CR1 = 0;
  spi_crc_transfer_next_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 12);
  spi_crc_transfer_next_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 12);
  spi_crc_transfer_next_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_crc_transfer_next_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_hardware_crc(void)
{
  SPI1->CR1 = 0;
  spi_hardware_crc_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 13);
  spi_hardware_crc_enable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 13);
  spi_hardware_crc_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_hardware_crc_disable(SPI1);
  ASSERT_EQ(SPI1->CR1, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_bidirectional_mode(void)
{
  SPI1->CR1 = 0;
  spi_set_bidirectional_mode(SPI1, SPI_BIDIRECTIONAL_MODE_TX_ONLY);
  ASSERT_EQ(SPI1->CR1, (1u << 14));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 14);
  spi_set_bidirectional_mode(SPI1, SPI_BIDIRECTIONAL_MODE_TX_ONLY);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 14);
  spi_set_bidirectional_mode(SPI1, SPI_BIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_bidirectional_mode(SPI1, SPI_BIDIRECTIONAL_MODE_RX_ONLY);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_communication_mode(void)
{
  SPI1->CR1 = 0;
  spi_set_communication_mode(SPI1, SPI_COMMUNICATION_MODE_1LINE);
  ASSERT_EQ(SPI1->CR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = ~(1u << 15);
  spi_set_communication_mode(SPI1, SPI_COMMUNICATION_MODE_1LINE);
  ASSERT_EQ(SPI1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = (1u << 15);
  spi_set_communication_mode(SPI1, SPI_COMMUNICATION_MODE_2LINES);
  ASSERT_EQ(SPI1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR1 = 0xffffffff;
  spi_set_communication_mode(SPI1, SPI_COMMUNICATION_MODE_2LINES);
  ASSERT_EQ(SPI1->CR1, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_dma_rx(void)
{
  SPI1->CR2 = 0;
  spi_dma_rx_enable(SPI1);
  ASSERT_EQ(SPI1->CR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = ~(1u << 0);
  spi_dma_rx_enable(SPI1);
  ASSERT_EQ(SPI1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = (1u << 0);
  spi_dma_rx_disable(SPI1);
  ASSERT_EQ(SPI1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = 0xffffffff;
  spi_dma_rx_disable(SPI1);
  ASSERT_EQ(SPI1->CR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_dma_tx(void)
{
  SPI1->CR2 = 0;
  spi_dma_tx_enable(SPI1);
  ASSERT_EQ(SPI1->CR2, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = ~(1u << 1);
  spi_dma_tx_enable(SPI1);
  ASSERT_EQ(SPI1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = (1u << 1);
  spi_dma_tx_disable(SPI1);
  ASSERT_EQ(SPI1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = 0xffffffff;
  spi_dma_tx_disable(SPI1);
  ASSERT_EQ(SPI1->CR2, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_slave_select(void)
{
  SPI1->CR2 = 0;
  spi_slave_select_enable(SPI1);
  ASSERT_EQ(SPI1->CR2, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = ~(1u << 2);
  spi_slave_select_enable(SPI1);
  ASSERT_EQ(SPI1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = (1u << 2);
  spi_slave_select_disable(SPI1);
  ASSERT_EQ(SPI1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = 0xffffffff;
  spi_slave_select_disable(SPI1);
  ASSERT_EQ(SPI1->CR2, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_SPI_FRAME_STANDARD)
void
test_spi_set_frame_standard(void)
{
  SPI1->CR2 = 0;
  spi_set_frame_standard(SPI1, SPI_FRAME_STANDARD_TI);
  ASSERT_EQ(SPI1->CR2, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = ~(1u << 4);
  spi_set_frame_standard(SPI1, SPI_FRAME_STANDARD_TI);
  ASSERT_EQ(SPI1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = (1u << 4);
  spi_set_frame_standard(SPI1, SPI_FRAME_STANDARD_MOTOROLA);
  ASSERT_EQ(SPI1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = 0xffffffff;
  spi_set_frame_standard(SPI1, SPI_FRAME_STANDARD_MOTOROLA);
  ASSERT_EQ(SPI1->CR2, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_spi_interrupt(void)
{
  SPI1->CR2 = 0;
  spi_interrupt_enable(SPI1, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(SPI1->CR2, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = ~(1u << 5);
  spi_interrupt_enable(SPI1, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(SPI1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = (1u << 5);
  spi_interrupt_disable(SPI1, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(SPI1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = 0xffffffff;
  spi_interrupt_disable(SPI1, SPI_INTERRUPT_ERROR);
  ASSERT_EQ(SPI1->CR2, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  SPI1->CR2 = 0;
  spi_interrupt_enable(SPI1, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(SPI1->CR2, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = ~(1u << 6);
  spi_interrupt_enable(SPI1, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(SPI1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = (1u << 6);
  spi_interrupt_disable(SPI1, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(SPI1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = 0xffffffff;
  spi_interrupt_disable(SPI1, SPI_INTERRUPT_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(SPI1->CR2, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  SPI1->CR2 = 0;
  spi_interrupt_enable(SPI1, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(SPI1->CR2, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = ~(1u << 7);
  spi_interrupt_enable(SPI1, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(SPI1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = (1u << 7);
  spi_interrupt_disable(SPI1, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(SPI1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->CR2 = 0xffffffff;
  spi_interrupt_disable(SPI1, SPI_INTERRUPT_TX_BUF_EMPTY);
  ASSERT_EQ(SPI1->CR2, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_is_flag_set(void)
{
  u32 res;

  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 0);
  res = spi_is_flag_set(SPI1, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 0);
  res = spi_is_flag_set(SPI1, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_RX_BUF_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 1);
  res = spi_is_flag_set(SPI1, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 1);
  res = spi_is_flag_set(SPI1, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_TX_BUF_EMPTY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 2);
  res = spi_is_flag_set(SPI1, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 2);
  res = spi_is_flag_set(SPI1, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_CHANNEL_RIGHT_TX);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 3);
  res = spi_is_flag_set(SPI1, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 3);
  res = spi_is_flag_set(SPI1, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_UNDERRUN);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 4);
  res = spi_is_flag_set(SPI1, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 4);
  res = spi_is_flag_set(SPI1, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_CRC_ERROR);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 5);
  res = spi_is_flag_set(SPI1, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 5);
  res = spi_is_flag_set(SPI1, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_MODE_FAULT);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 6);
  res = spi_is_flag_set(SPI1, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 6);
  res = spi_is_flag_set(SPI1, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 7);
  res = spi_is_flag_set(SPI1, SPI_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 7);
  res = spi_is_flag_set(SPI1, SPI_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SPI_FRAME_STANDARD)
  SPI1->SR = 0;
  res = spi_is_flag_set(SPI1, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = (1u << 8);
  res = spi_is_flag_set(SPI1, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SPI1->SR = ~(1u << 8);
  res = spi_is_flag_set(SPI1, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->SR = 0xffffffff;
  res = spi_is_flag_set(SPI1, SPI_FLAG_FRAME_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

}

// └─Skipping type 'fn_call (TODO)' (spi_crc_error_flag_clear)
void
test_spi_data_read(void)
{
  u32 res;

  // read_reg
  SPI1->DR = 0;
  res = spi_data_read(SPI1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->DR = 0xffffffff;
  res = spi_data_read(SPI1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_spi_data_write(void)
{
  SPI1->DR = 0;
  spi_data_write(SPI1, 0);
  ASSERT_EQ(SPI1->DR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SPI1->DR = 0xffffffff;
  spi_data_write(SPI1, 0);
  ASSERT_EQ(SPI1->DR, 0);
  ASSERT_FALSE(execution_halted());


}

void
test_spi_set_crc_polynomial(void)
{
  SPI1->CRCPR = 0;
  spi_set_crc_polynomial(SPI1, 0);
  ASSERT_EQ(SPI1->CRCPR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  SPI1->CRCPR = 0;
  spi_set_crc_polynomial(SPI1, 0xffff);
  ASSERT_EQ(SPI1->CRCPR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  SPI1->CRCPR = 0;
  spi_set_crc_polynomial(SPI1, 0x10000);
  ASSERT_EQ(SPI1->CRCPR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_spi_get_rx_crc(void)
{
  u32 res;

  // read_reg
  SPI1->RXCRCR = 0;
  res = spi_get_rx_crc(SPI1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->RXCRCR = 0xffffffff;
  res = spi_get_rx_crc(SPI1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_spi_get_tx_crc(void)
{
  u32 res;

  // read_reg
  SPI1->TXCRCR = 0;
  res = spi_get_tx_crc(SPI1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->TXCRCR = 0xffffffff;
  res = spi_get_tx_crc(SPI1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_channel_length(void)
{
  SPI1->I2SCFGR = 0;
  spi_set_channel_length(SPI1, SPI_CHANNEL_LENGTH_32BITS);
  ASSERT_EQ(SPI1->I2SCFGR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(1u << 0);
  spi_set_channel_length(SPI1, SPI_CHANNEL_LENGTH_32BITS);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = (1u << 0);
  spi_set_channel_length(SPI1, SPI_CHANNEL_LENGTH_16BITS);
  ASSERT_EQ(SPI1->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = 0xffffffff;
  spi_set_channel_length(SPI1, SPI_CHANNEL_LENGTH_16BITS);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_data_length(void)
{
  // scope=self.reg='I2SCFGR', self.shift=1, self.mask='0x3', self.varsmap={'length': 'SPI_DATA_LENGTH_16BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_data_length(SPI1, SPI_DATA_LENGTH_16BITS);
  ASSERT_EQ(SPI1->I2SCFGR, (0b00u << 1));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 1);
  spi_set_data_length(SPI1, SPI_DATA_LENGTH_16BITS);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 1) | (0b00u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=1, self.mask='0x3', self.varsmap={'length': 'SPI_DATA_LENGTH_24BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_data_length(SPI1, SPI_DATA_LENGTH_24BITS);
  ASSERT_EQ(SPI1->I2SCFGR, (0b01u << 1));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 1);
  spi_set_data_length(SPI1, SPI_DATA_LENGTH_24BITS);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 1) | (0b01u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=1, self.mask='0x3', self.varsmap={'length': 'SPI_DATA_LENGTH_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_data_length(SPI1, SPI_DATA_LENGTH_32BITS);
  ASSERT_EQ(SPI1->I2SCFGR, (0b10u << 1));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 1);
  spi_set_data_length(SPI1, SPI_DATA_LENGTH_32BITS);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 1) | (0b10u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_set_i2s_steady_clock_polarity(void)
{
  SPI1->I2SCFGR = 0;
  spi_set_i2s_steady_clock_polarity(SPI1, SPI_I2S_CLOCK_POLARITY_HIGH);
  ASSERT_EQ(SPI1->I2SCFGR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(1u << 3);
  spi_set_i2s_steady_clock_polarity(SPI1, SPI_I2S_CLOCK_POLARITY_HIGH);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = (1u << 3);
  spi_set_i2s_steady_clock_polarity(SPI1, SPI_I2S_CLOCK_POLARITY_LOW);
  ASSERT_EQ(SPI1->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = 0xffffffff;
  spi_set_i2s_steady_clock_polarity(SPI1, SPI_I2S_CLOCK_POLARITY_LOW);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_i2s_standard(void)
{
  // scope=self.reg='I2SCFGR', self.shift=4, self.mask='0x3', self.varsmap={'standard': 'SPI_I2S_STANDARD_PHILIPS'}, self.value='0b00', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_PHILIPS);
  ASSERT_EQ(SPI1->I2SCFGR, (0b00u << 4));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_PHILIPS);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 4) | (0b00u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=4, self.mask='0x3', self.varsmap={'standard': 'SPI_I2S_STANDARD_MSB_JUSTIFIED'}, self.value='0b01', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_MSB_JUSTIFIED);
  ASSERT_EQ(SPI1->I2SCFGR, (0b01u << 4));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_MSB_JUSTIFIED);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 4) | (0b01u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=4, self.mask='0x3', self.varsmap={'standard': 'SPI_I2S_STANDARD_LSB_JUSTIFIED'}, self.value='0b10', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_LSB_JUSTIFIED);
  ASSERT_EQ(SPI1->I2SCFGR, (0b10u << 4));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_LSB_JUSTIFIED);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 4) | (0b10u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=4, self.mask='0x3', self.varsmap={'standard': 'SPI_I2S_STANDARD_PCM'}, self.value='0b11', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_PCM);
  ASSERT_EQ(SPI1->I2SCFGR, (0b11u << 4));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 4);
  spi_set_i2s_standard(SPI1, SPI_I2S_STANDARD_PCM);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 4) | (0b11u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_set_pcm_frame_sync(void)
{
  SPI1->I2SCFGR = 0;
  spi_set_pcm_frame_sync(SPI1, SPI_PCM_FRAME_SYNC_LONG);
  ASSERT_EQ(SPI1->I2SCFGR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(1u << 7);
  spi_set_pcm_frame_sync(SPI1, SPI_PCM_FRAME_SYNC_LONG);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = (1u << 7);
  spi_set_pcm_frame_sync(SPI1, SPI_PCM_FRAME_SYNC_SHORT);
  ASSERT_EQ(SPI1->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = 0xffffffff;
  spi_set_pcm_frame_sync(SPI1, SPI_PCM_FRAME_SYNC_SHORT);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_i2s_configuration_mode(void)
{
  // scope=self.reg='I2SCFGR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'SPI_I2S_CONFIG_MODE_SLAVE_TX'}, self.value='0b00', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_SLAVE_TX);
  ASSERT_EQ(SPI1->I2SCFGR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_SLAVE_TX);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'SPI_I2S_CONFIG_MODE_SLAVE_RX'}, self.value='0b01', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_SLAVE_RX);
  ASSERT_EQ(SPI1->I2SCFGR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_SLAVE_RX);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'SPI_I2S_CONFIG_MODE_MASTER_TX'}, self.value='0b10', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_MASTER_TX);
  ASSERT_EQ(SPI1->I2SCFGR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_MASTER_TX);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='I2SCFGR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'SPI_I2S_CONFIG_MODE_MASTER_RX'}, self.value='0b11', self.ifdef=[], self.halt=False
  SPI1->I2SCFGR = 0;
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_MASTER_RX);
  ASSERT_EQ(SPI1->I2SCFGR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(0x3u << 8);
  spi_set_i2s_configuration_mode(SPI1, SPI_I2S_CONFIG_MODE_MASTER_RX);
  ASSERT_EQ(SPI1->I2SCFGR, ~(0x3u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_spi_i2s(void)
{
  SPI1->I2SCFGR = 0;
  spi_i2s_enable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(1u << 10);
  spi_i2s_enable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = (1u << 10);
  spi_i2s_disable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = 0xffffffff;
  spi_i2s_disable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_set_mode(void)
{
  SPI1->I2SCFGR = 0;
  spi_set_mode(SPI1, SPI_MODE_I2S);
  ASSERT_EQ(SPI1->I2SCFGR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(1u << 11);
  spi_set_mode(SPI1, SPI_MODE_I2S);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = (1u << 11);
  spi_set_mode(SPI1, SPI_MODE_SPI);
  ASSERT_EQ(SPI1->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = 0xffffffff;
  spi_set_mode(SPI1, SPI_MODE_SPI);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_SPI_ASYNC_START)
void
test_spi_async_start(void)
{
  SPI1->I2SCFGR = 0;
  spi_async_start_enable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = ~(1u << 12);
  spi_async_start_enable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = (1u << 12);
  spi_async_start_disable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SCFGR = 0xffffffff;
  spi_async_start_disable(SPI1);
  ASSERT_EQ(SPI1->I2SCFGR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_spi_set_i2s_linear_prescaler(void)
{
  SPI1->I2SPR = 0;
  spi_set_i2s_linear_prescaler(SPI1, 0);
  ASSERT_EQ(SPI1->I2SPR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = 0xffffffff;
  spi_set_i2s_linear_prescaler(SPI1, 0);
  ASSERT_EQ(SPI1->I2SPR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  SPI1->I2SPR = 0;
  spi_set_i2s_linear_prescaler(SPI1, 0xff);
  ASSERT_EQ(SPI1->I2SPR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = 0xffffffff;
  spi_set_i2s_linear_prescaler(SPI1, 0xff);
  ASSERT_EQ(SPI1->I2SPR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  SPI1->I2SPR = 0;
  spi_set_i2s_linear_prescaler(SPI1, 0x100);
  ASSERT_EQ(SPI1->I2SPR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPI1->I2SPR = 0xffffffff;
  spi_set_i2s_linear_prescaler(SPI1, 0x100);
  ASSERT_EQ(SPI1->I2SPR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_spi_set_i2s_prescaler_odd_factor(void)
{
  SPI1->I2SPR = 0;
  spi_set_i2s_prescaler_odd_factor(SPI1, SPI_PRESCALER_ODD_FACTOR_MUL2_PLUS1);
  ASSERT_EQ(SPI1->I2SPR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = ~(1u << 8);
  spi_set_i2s_prescaler_odd_factor(SPI1, SPI_PRESCALER_ODD_FACTOR_MUL2_PLUS1);
  ASSERT_EQ(SPI1->I2SPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = (1u << 8);
  spi_set_i2s_prescaler_odd_factor(SPI1, SPI_PRESCALER_ODD_FACTOR_MUL2);
  ASSERT_EQ(SPI1->I2SPR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = 0xffffffff;
  spi_set_i2s_prescaler_odd_factor(SPI1, SPI_PRESCALER_ODD_FACTOR_MUL2);
  ASSERT_EQ(SPI1->I2SPR, 0xffffffff & ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_spi_master_clock_output(void)
{
  SPI1->I2SPR = 0;
  spi_master_clock_output_enable(SPI1);
  ASSERT_EQ(SPI1->I2SPR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = ~(1u << 9);
  spi_master_clock_output_enable(SPI1);
  ASSERT_EQ(SPI1->I2SPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = (1u << 9);
  spi_master_clock_output_disable(SPI1);
  ASSERT_EQ(SPI1->I2SPR, 0);
  ASSERT_FALSE(execution_halted());

  SPI1->I2SPR = 0xffffffff;
  spi_master_clock_output_disable(SPI1);
  ASSERT_EQ(SPI1->I2SPR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
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
    TEST_FUNC(test_spi_data_read),
    TEST_FUNC(test_spi_data_write),
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
