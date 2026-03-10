#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/fmpi2c/fmpi2c_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  FMPI2C1 = (struct fmpi2c_registers_map*) membuf;
}

void
test_fmpi2c(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 0);
  fmpi2c_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 0);
  fmpi2c_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_interrupt(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_TX);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 1);
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_TX);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 1);
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_TX);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_TX);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_RX);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 2));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 2);
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_RX);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 2);
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_RX);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_RX);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_ADDR_MATCH);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 3));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 3);
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_ADDR_MATCH);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 3);
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_ADDR_MATCH);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_ADDR_MATCH);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_NACK);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 4);
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_NACK);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 4);
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_NACK);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_NACK);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_STOP);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 5);
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_STOP);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 5);
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_STOP);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_STOP);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 6));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 6);
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 6);
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_ERR);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 7);
  fmpi2c_interrupt_enable(FMPI2C1, FMPI2C_INTERRUPT_ERR);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 7);
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_ERR);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_interrupt_disable(FMPI2C1, FMPI2C_INTERRUPT_ERR);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_fmpi2c_set_digital_noise_filter(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_set_digital_noise_filter(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->CR1, 0u << 8);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_set_digital_noise_filter(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->CR1, ~(0xfu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_set_digital_noise_filter(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->CR1, 0xfu << 8);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_set_digital_noise_filter(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->CR1, ~(0xfu << 8) | (0xfu << 8));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR1 = 0;
  fmpi2c_set_digital_noise_filter(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->CR1, 0x10u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_set_digital_noise_filter(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->CR1, ~(0xfu << 8) | (0x10u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_analog_noise_filter(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_analog_noise_filter_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 12);
  fmpi2c_analog_noise_filter_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 12);
  fmpi2c_analog_noise_filter_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_analog_noise_filter_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_dma_tx(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_dma_tx_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 14));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 14);
  fmpi2c_dma_tx_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 14);
  fmpi2c_dma_tx_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_dma_tx_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_dma_rx(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_dma_rx_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 15);
  fmpi2c_dma_rx_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 15);
  fmpi2c_dma_rx_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_dma_rx_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_target_byte(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_target_byte_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 16));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 16);
  fmpi2c_target_byte_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 16);
  fmpi2c_target_byte_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_target_byte_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_clock_stretching(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_clock_stretching_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 17));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 17);
  fmpi2c_clock_stretching_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 17);
  fmpi2c_clock_stretching_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_clock_stretching_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_general_call(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_general_call_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 19));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 19);
  fmpi2c_general_call_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 19);
  fmpi2c_general_call_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_general_call_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_smbus_host_addr(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_smbus_host_addr_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 20));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 20);
  fmpi2c_smbus_host_addr_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 20);
  fmpi2c_smbus_host_addr_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_smbus_host_addr_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_smbus_device_default_addr(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_smbus_device_default_addr_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 21));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 21);
  fmpi2c_smbus_device_default_addr_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 21);
  fmpi2c_smbus_device_default_addr_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_smbus_device_default_addr_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_smbus_alert(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_smbus_alert_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 22));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 22);
  fmpi2c_smbus_alert_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 22);
  fmpi2c_smbus_alert_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_smbus_alert_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_pec(void)
{
  FMPI2C1->CR1 = 0;
  fmpi2c_pec_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, (1u << 23));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = ~(1u << 23);
  fmpi2c_pec_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = (1u << 23);
  fmpi2c_pec_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR1 = 0xffffffff;
  fmpi2c_pec_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR1, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_set_target_addr(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_set_target_addr(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->CR2, 0u << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_target_addr(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->CR2, ~(0x3ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR2 = 0;
  fmpi2c_set_target_addr(FMPI2C1, 0x3ff);
  ASSERT_EQ(FMPI2C1->CR2, 0x3ffu << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_target_addr(FMPI2C1, 0x3ff);
  ASSERT_EQ(FMPI2C1->CR2, ~(0x3ffu << 0) | (0x3ffu << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR2 = 0;
  fmpi2c_set_target_addr(FMPI2C1, 0x400);
  ASSERT_EQ(FMPI2C1->CR2, 0x400u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_target_addr(FMPI2C1, 0x400);
  ASSERT_EQ(FMPI2C1->CR2, ~(0x3ffu << 0) | (0x400u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_transfer_direction(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_set_transfer_direction(FMPI2C1, FMPI2C_TRANSFER_DIR_READ);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 10);
  fmpi2c_set_transfer_direction(FMPI2C1, FMPI2C_TRANSFER_DIR_READ);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = (1u << 10);
  fmpi2c_set_transfer_direction(FMPI2C1, FMPI2C_TRANSFER_DIR_WRITE);
  ASSERT_EQ(FMPI2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_transfer_direction(FMPI2C1, FMPI2C_TRANSFER_DIR_WRITE);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_set_addressing_mode(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_set_addressing_mode(FMPI2C1, FMPI2C_ADDRESSING_MODE_10BIT);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 11));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 11);
  fmpi2c_set_addressing_mode(FMPI2C1, FMPI2C_ADDRESSING_MODE_10BIT);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = (1u << 11);
  fmpi2c_set_addressing_mode(FMPI2C1, FMPI2C_ADDRESSING_MODE_7BIT);
  ASSERT_EQ(FMPI2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_addressing_mode(FMPI2C1, FMPI2C_ADDRESSING_MODE_7BIT);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_set_10bit_addr_dir_change_seq(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_set_10bit_addr_dir_change_seq(FMPI2C1, FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_HEADER_ONLY);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 12);
  fmpi2c_set_10bit_addr_dir_change_seq(FMPI2C1, FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_HEADER_ONLY);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = (1u << 12);
  fmpi2c_set_10bit_addr_dir_change_seq(FMPI2C1, FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_FULL);
  ASSERT_EQ(FMPI2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_10bit_addr_dir_change_seq(FMPI2C1, FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_FULL);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff & ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_generate_start(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_generate_start(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 13));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 13);
  fmpi2c_generate_start(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_generate_stop(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_generate_stop(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 14));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 14);
  fmpi2c_generate_stop(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_generate_nack(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_generate_nack(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 15);
  fmpi2c_generate_nack(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_set_transfer_bytes_count(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_set_transfer_bytes_count(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->CR2, 0u << 16);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_transfer_bytes_count(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->CR2, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR2 = 0;
  fmpi2c_set_transfer_bytes_count(FMPI2C1, 0xff);
  ASSERT_EQ(FMPI2C1->CR2, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_transfer_bytes_count(FMPI2C1, 0xff);
  ASSERT_EQ(FMPI2C1->CR2, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->CR2 = 0;
  fmpi2c_set_transfer_bytes_count(FMPI2C1, 0x100);
  ASSERT_EQ(FMPI2C1->CR2, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_transfer_bytes_count(FMPI2C1, 0x100);
  ASSERT_EQ(FMPI2C1->CR2, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_reload_mode(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_set_reload_mode(FMPI2C1, FMPI2C_RELOAD_MODE_CONTINUE);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 24));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 24);
  fmpi2c_set_reload_mode(FMPI2C1, FMPI2C_RELOAD_MODE_CONTINUE);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = (1u << 24);
  fmpi2c_set_reload_mode(FMPI2C1, FMPI2C_RELOAD_MODE_COMPLETE);
  ASSERT_EQ(FMPI2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_reload_mode(FMPI2C1, FMPI2C_RELOAD_MODE_COMPLETE);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff & ~(1u << 24));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_set_end_mode(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_set_end_mode(FMPI2C1, FMPI2C_END_MODE_AUTOMATIC);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 25));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 25);
  fmpi2c_set_end_mode(FMPI2C1, FMPI2C_END_MODE_AUTOMATIC);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = (1u << 25);
  fmpi2c_set_end_mode(FMPI2C1, FMPI2C_END_MODE_SOFTWARE);
  ASSERT_EQ(FMPI2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_set_end_mode(FMPI2C1, FMPI2C_END_MODE_SOFTWARE);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff & ~(1u << 25));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_pec_byte(void)
{
  FMPI2C1->CR2 = 0;
  fmpi2c_pec_byte_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, (1u << 26));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = ~(1u << 26);
  fmpi2c_pec_byte_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = (1u << 26);
  fmpi2c_pec_byte_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->CR2 = 0xffffffff;
  fmpi2c_pec_byte_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->CR2, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_set_interface_7bit_addr(void)
{
  FMPI2C1->OAR1 = 0;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR1, 0);
  ASSERT_EQ(FMPI2C1->OAR1, 0u << 1);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR1, 0);
  ASSERT_EQ(FMPI2C1->OAR1, ~(0x7fu << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR1 = 0;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR1, 0x7f);
  ASSERT_EQ(FMPI2C1->OAR1, 0x7fu << 1);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR1, 0x7f);
  ASSERT_EQ(FMPI2C1->OAR1, ~(0x7fu << 1) | (0x7fu << 1));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR1 = 0;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR1, 0x80);
  ASSERT_EQ(FMPI2C1->OAR1, 0x80u << 1);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR1, 0x80);
  ASSERT_EQ(FMPI2C1->OAR1, ~(0x7fu << 1) | (0x80u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FMPI2C1->OAR2 = 0;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR2, 0);
  ASSERT_EQ(FMPI2C1->OAR2, 0u << 1);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR2 = 0xffffffff;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR2, 0);
  ASSERT_EQ(FMPI2C1->OAR2, ~(0x7fu << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR2 = 0;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR2, 0x7f);
  ASSERT_EQ(FMPI2C1->OAR2, 0x7fu << 1);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR2 = 0xffffffff;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR2, 0x7f);
  ASSERT_EQ(FMPI2C1->OAR2, ~(0x7fu << 1) | (0x7fu << 1));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR2 = 0;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR2, 0x80);
  ASSERT_EQ(FMPI2C1->OAR2, 0x80u << 1);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->OAR2 = 0xffffffff;
  fmpi2c_set_interface_7bit_addr(FMPI2C1, FMPI2C_INTERFACE_ADDR2, 0x80);
  ASSERT_EQ(FMPI2C1->OAR2, ~(0x7fu << 1) | (0x80u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_interface_10bit_addr(void)
{
  FMPI2C1->OAR1 = 0;
  fmpi2c_set_interface_10bit_addr(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->OAR1, 0u << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_set_interface_10bit_addr(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->OAR1, ~(0x3ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR1 = 0;
  fmpi2c_set_interface_10bit_addr(FMPI2C1, 0x3ff);
  ASSERT_EQ(FMPI2C1->OAR1, 0x3ffu << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_set_interface_10bit_addr(FMPI2C1, 0x3ff);
  ASSERT_EQ(FMPI2C1->OAR1, ~(0x3ffu << 0) | (0x3ffu << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR1 = 0;
  fmpi2c_set_interface_10bit_addr(FMPI2C1, 0x400);
  ASSERT_EQ(FMPI2C1->OAR1, 0x400u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_set_interface_10bit_addr(FMPI2C1, 0x400);
  ASSERT_EQ(FMPI2C1->OAR1, ~(0x3ffu << 0) | (0x400u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_interface_addr1_type(void)
{
  FMPI2C1->OAR1 = 0;
  fmpi2c_set_interface_addr1_type(FMPI2C1, FMPI2C_INTERFACE_ADDR_TYPE_10BIT);
  ASSERT_EQ(FMPI2C1->OAR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = ~(1u << 10);
  fmpi2c_set_interface_addr1_type(FMPI2C1, FMPI2C_INTERFACE_ADDR_TYPE_10BIT);
  ASSERT_EQ(FMPI2C1->OAR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = (1u << 10);
  fmpi2c_set_interface_addr1_type(FMPI2C1, FMPI2C_INTERFACE_ADDR_TYPE_7BIT);
  ASSERT_EQ(FMPI2C1->OAR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_set_interface_addr1_type(FMPI2C1, FMPI2C_INTERFACE_ADDR_TYPE_7BIT);
  ASSERT_EQ(FMPI2C1->OAR1, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_interface_addr(void)
{
  FMPI2C1->OAR1 = 0;
  fmpi2c_interface_addr_enable(FMPI2C1, FMPI2C_INTERFACE_ADDR1);
  ASSERT_EQ(FMPI2C1->OAR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = ~(1u << 15);
  fmpi2c_interface_addr_enable(FMPI2C1, FMPI2C_INTERFACE_ADDR1);
  ASSERT_EQ(FMPI2C1->OAR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = (1u << 15);
  fmpi2c_interface_addr_disable(FMPI2C1, FMPI2C_INTERFACE_ADDR1);
  ASSERT_EQ(FMPI2C1->OAR1, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR1 = 0xffffffff;
  fmpi2c_interface_addr_disable(FMPI2C1, FMPI2C_INTERFACE_ADDR1);
  ASSERT_EQ(FMPI2C1->OAR1, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR2 = 0;
  fmpi2c_interface_addr_enable(FMPI2C1, FMPI2C_INTERFACE_ADDR2);
  ASSERT_EQ(FMPI2C1->OAR2, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR2 = ~(1u << 15);
  fmpi2c_interface_addr_enable(FMPI2C1, FMPI2C_INTERFACE_ADDR2);
  ASSERT_EQ(FMPI2C1->OAR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR2 = (1u << 15);
  fmpi2c_interface_addr_disable(FMPI2C1, FMPI2C_INTERFACE_ADDR2);
  ASSERT_EQ(FMPI2C1->OAR2, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR2 = 0xffffffff;
  fmpi2c_interface_addr_disable(FMPI2C1, FMPI2C_INTERFACE_ADDR2);
  ASSERT_EQ(FMPI2C1->OAR2, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


}

void
test_fmpi2c_set_interface_addr2_mask(void)
{
  FMPI2C1->OAR2 = 0;
  fmpi2c_set_interface_addr2_mask(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->OAR2, 0u << 8);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR2 = 0xffffffff;
  fmpi2c_set_interface_addr2_mask(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->OAR2, ~(0x7u << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR2 = 0;
  fmpi2c_set_interface_addr2_mask(FMPI2C1, 0x7);
  ASSERT_EQ(FMPI2C1->OAR2, 0x7u << 8);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->OAR2 = 0xffffffff;
  fmpi2c_set_interface_addr2_mask(FMPI2C1, 0x7);
  ASSERT_EQ(FMPI2C1->OAR2, ~(0x7u << 8) | (0x7u << 8));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->OAR2 = 0;
  fmpi2c_set_interface_addr2_mask(FMPI2C1, 0x8);
  ASSERT_EQ(FMPI2C1->OAR2, 0x8u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->OAR2 = 0xffffffff;
  fmpi2c_set_interface_addr2_mask(FMPI2C1, 0x8);
  ASSERT_EQ(FMPI2C1->OAR2, ~(0x7u << 8) | (0x8u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_scl_low_period(void)
{
  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_scl_low_period(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_scl_low_period(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_scl_low_period(FMPI2C1, 0xff);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_scl_low_period(FMPI2C1, 0xff);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_scl_low_period(FMPI2C1, 0x100);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_scl_low_period(FMPI2C1, 0x100);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_scl_high_period(void)
{
  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_scl_high_period(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_scl_high_period(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_scl_high_period(FMPI2C1, 0xff);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_scl_high_period(FMPI2C1, 0xff);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_scl_high_period(FMPI2C1, 0x100);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_scl_high_period(FMPI2C1, 0x100);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_data_hold_time(void)
{
  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_data_hold_time(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_data_hold_time(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_data_hold_time(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0xfu << 16);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_data_hold_time(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 16) | (0xfu << 16));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_data_hold_time(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0x10u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_data_hold_time(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 16) | (0x10u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_data_setup_time(void)
{
  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_data_setup_time(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0u << 20);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_data_setup_time(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 20) | (0u << 20));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_data_setup_time(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0xfu << 20);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_data_setup_time(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 20) | (0xfu << 20));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_data_setup_time(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0x10u << 20);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_data_setup_time(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 20) | (0x10u << 20));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_timing_prescaler(void)
{
  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_timing_prescaler(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0u << 28);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_timing_prescaler(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 28) | (0u << 28));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_timing_prescaler(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0xfu << 28);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_timing_prescaler(FMPI2C1, 0xf);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 28) | (0xfu << 28));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMINGR = 0;
  fmpi2c_set_timing_prescaler(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->TIMINGR, 0x10u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->TIMINGR = 0xffffffff;
  fmpi2c_set_timing_prescaler(FMPI2C1, 0x10);
  ASSERT_EQ(FMPI2C1->TIMINGR, ~(0xfu << 28) | (0x10u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_set_timeouta(void)
{
  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_set_timeouta(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_set_timeouta(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_set_timeouta(FMPI2C1, 0xfff);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_set_timeouta(FMPI2C1, 0xfff);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_set_timeouta(FMPI2C1, 0x1000);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_set_timeouta(FMPI2C1, 0x1000);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(0xfffu << 0) | (0x1000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_idle_clock_timeout(void)
{
  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_idle_clock_timeout_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = ~(1u << 12);
  fmpi2c_idle_clock_timeout_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = (1u << 12);
  fmpi2c_idle_clock_timeout_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_idle_clock_timeout_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_clock_timeout(void)
{
  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_clock_timeout_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = ~(1u << 15);
  fmpi2c_clock_timeout_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = (1u << 15);
  fmpi2c_clock_timeout_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_clock_timeout_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_set_timeoutb(void)
{
  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_set_timeoutb(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_set_timeoutb(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(0xfffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_set_timeoutb(FMPI2C1, 0xfff);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0xfffu << 16);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_set_timeoutb(FMPI2C1, 0xfff);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(0xfffu << 16) | (0xfffu << 16));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_set_timeoutb(FMPI2C1, 0x1000);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0x1000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_set_timeoutb(FMPI2C1, 0x1000);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(0xfffu << 16) | (0x1000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_extended_clock_timeout(void)
{
  FMPI2C1->TIMEOUTR = 0;
  fmpi2c_extended_clock_timeout_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = ~(1u << 31);
  fmpi2c_extended_clock_timeout_enable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = (1u << 31);
  fmpi2c_extended_clock_timeout_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->TIMEOUTR = 0xffffffff;
  fmpi2c_extended_clock_timeout_disable(FMPI2C1);
  ASSERT_EQ(FMPI2C1->TIMEOUTR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_is_flag_set(void)
{
  u32 res;

  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 0);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 0);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 1);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 1);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TXI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_RXNE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 2);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_RXNE);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 2);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_RXNE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_RXNE);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ADDR_MATCH);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 3);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ADDR_MATCH);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 3);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ADDR_MATCH);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ADDR_MATCH);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_NACK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 4);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_NACK);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 4);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_NACK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_NACK);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_STOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 5);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_STOP);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 5);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_STOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_STOP);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 6);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 6);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 7);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 7);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 8);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_ERR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 8);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_ERR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ARBITRATION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 9);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ARBITRATION_LOST);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 9);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ARBITRATION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_ARBITRATION_LOST);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 10);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 10);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_PEC_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 11);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_PEC_ERR);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 11);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_PEC_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_PEC_ERR);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 12);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 12);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 13);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 13);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 15);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 15);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ISR = 0;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_DIRECTION);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = (1u << 16);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_DIRECTION);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 16);
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_DIRECTION);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0xffffffff;
  res = fmpi2c_is_flag_set(FMPI2C1, FMPI2C_FLAG_TRANSFER_DIRECTION);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_fmpi2c_get_addr_match_code(void)
{
  u32 res;

  // read_bits
  FMPI2C1->ISR = 0;
  res = fmpi2c_get_addr_match_code(FMPI2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(0x7fu << 17);
  res = fmpi2c_get_addr_match_code(FMPI2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = 0x7fu << 17;
  res = fmpi2c_get_addr_match_code(FMPI2C1);
  ASSERT_EQ(res, 0x7f);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_flush_tx(void)
{
  FMPI2C1->ISR = 0;
  fmpi2c_flush_tx(FMPI2C1);
  ASSERT_EQ(FMPI2C1->ISR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 0);
  fmpi2c_flush_tx(FMPI2C1);
  ASSERT_EQ(FMPI2C1->ISR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_generate_txis_event(void)
{
  FMPI2C1->ISR = 0;
  fmpi2c_generate_txis_event(FMPI2C1);
  ASSERT_EQ(FMPI2C1->ISR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ISR = ~(1u << 1);
  fmpi2c_generate_txis_event(FMPI2C1);
  ASSERT_EQ(FMPI2C1->ISR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_flag_clear(void)
{
  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TXE);
  ASSERT_EQ(FMPI2C1->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->ICR = ~(1u << 0);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TXE);
  ASSERT_EQ(FMPI2C1->ICR, ~(1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TXI);
  ASSERT_EQ(FMPI2C1->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->ICR = ~(1u << 1);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TXI);
  ASSERT_EQ(FMPI2C1->ICR, ~(1u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_RXNE);
  ASSERT_EQ(FMPI2C1->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->ICR = ~(1u << 2);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_RXNE);
  ASSERT_EQ(FMPI2C1->ICR, ~(1u << 2));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_ADDR_MATCH);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 3);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_ADDR_MATCH);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_NACK);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 4);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_NACK);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_STOP);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 5);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_STOP);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(FMPI2C1->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->ICR = ~(1u << 6);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(FMPI2C1->ICR, ~(1u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD);
  ASSERT_EQ(FMPI2C1->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->ICR = ~(1u << 7);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD);
  ASSERT_EQ(FMPI2C1->ICR, ~(1u << 7));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_BUS_ERR);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 8);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_BUS_ERR);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_ARBITRATION_LOST);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 9);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_ARBITRATION_LOST);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 10);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_PEC_ERR);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 11);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_PEC_ERR);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TIMEOUT);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 12);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TIMEOUT);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(FMPI2C1->ICR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  FMPI2C1->ICR = ~(1u << 13);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(FMPI2C1->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_BUS_BUSY);
  ASSERT_EQ(FMPI2C1->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->ICR = ~(1u << 14);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_BUS_BUSY);
  ASSERT_EQ(FMPI2C1->ICR, ~(1u << 14));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FMPI2C1->ICR = 0;
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TRANSFER_DIRECTION);
  ASSERT_EQ(FMPI2C1->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FMPI2C1->ICR = ~(1u << 15);
  fmpi2c_flag_clear(FMPI2C1, FMPI2C_FLAG_TRANSFER_DIRECTION);
  ASSERT_EQ(FMPI2C1->ICR, ~(1u << 15));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_fmpi2c_get_pec(void)
{
  u32 res;

  // read_bits
  FMPI2C1->PECR = 0;
  res = fmpi2c_get_pec(FMPI2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->PECR = ~(0xffu << 0);
  res = fmpi2c_get_pec(FMPI2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->PECR = 0xffu << 0;
  res = fmpi2c_get_pec(FMPI2C1);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_read_data(void)
{
  u32 res;

  // read_reg
  FMPI2C1->RXDR = 0;
  res = fmpi2c_read_data(FMPI2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FMPI2C1->RXDR = 0xffffffff;
  res = fmpi2c_read_data(FMPI2C1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_fmpi2c_write_data(void)
{
  FMPI2C1->TXDR = 0;
  fmpi2c_write_data(FMPI2C1, 0);
  ASSERT_EQ(FMPI2C1->TXDR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_fmpi2c),
    TEST_FUNC(test_fmpi2c_interrupt),
    TEST_FUNC(test_fmpi2c_set_digital_noise_filter),
    TEST_FUNC(test_fmpi2c_analog_noise_filter),
    TEST_FUNC(test_fmpi2c_dma_tx),
    TEST_FUNC(test_fmpi2c_dma_rx),
    TEST_FUNC(test_fmpi2c_target_byte),
    TEST_FUNC(test_fmpi2c_clock_stretching),
    TEST_FUNC(test_fmpi2c_general_call),
    TEST_FUNC(test_fmpi2c_smbus_host_addr),
    TEST_FUNC(test_fmpi2c_smbus_device_default_addr),
    TEST_FUNC(test_fmpi2c_smbus_alert),
    TEST_FUNC(test_fmpi2c_pec),
    TEST_FUNC(test_fmpi2c_set_target_addr),
    TEST_FUNC(test_fmpi2c_set_transfer_direction),
    TEST_FUNC(test_fmpi2c_set_addressing_mode),
    TEST_FUNC(test_fmpi2c_set_10bit_addr_dir_change_seq),
    TEST_FUNC(test_fmpi2c_generate_start),
    TEST_FUNC(test_fmpi2c_generate_stop),
    TEST_FUNC(test_fmpi2c_generate_nack),
    TEST_FUNC(test_fmpi2c_set_transfer_bytes_count),
    TEST_FUNC(test_fmpi2c_set_reload_mode),
    TEST_FUNC(test_fmpi2c_set_end_mode),
    TEST_FUNC(test_fmpi2c_pec_byte),
    TEST_FUNC(test_fmpi2c_set_interface_7bit_addr),
    TEST_FUNC(test_fmpi2c_set_interface_10bit_addr),
    TEST_FUNC(test_fmpi2c_set_interface_addr1_type),
    TEST_FUNC(test_fmpi2c_interface_addr),
    TEST_FUNC(test_fmpi2c_set_interface_addr2_mask),
    TEST_FUNC(test_fmpi2c_set_scl_low_period),
    TEST_FUNC(test_fmpi2c_set_scl_high_period),
    TEST_FUNC(test_fmpi2c_set_data_hold_time),
    TEST_FUNC(test_fmpi2c_set_data_setup_time),
    TEST_FUNC(test_fmpi2c_set_timing_prescaler),
    TEST_FUNC(test_fmpi2c_set_timeouta),
    TEST_FUNC(test_fmpi2c_idle_clock_timeout),
    TEST_FUNC(test_fmpi2c_clock_timeout),
    TEST_FUNC(test_fmpi2c_set_timeoutb),
    TEST_FUNC(test_fmpi2c_extended_clock_timeout),
    TEST_FUNC(test_fmpi2c_is_flag_set),
    TEST_FUNC(test_fmpi2c_get_addr_match_code),
    TEST_FUNC(test_fmpi2c_flush_tx),
    TEST_FUNC(test_fmpi2c_generate_txis_event),
    TEST_FUNC(test_fmpi2c_flag_clear),
    TEST_FUNC(test_fmpi2c_get_pec),
    TEST_FUNC(test_fmpi2c_read_data),
    TEST_FUNC(test_fmpi2c_write_data),
  };

  return TESTS_RUN(tests);
}
