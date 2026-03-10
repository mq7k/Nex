#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/i2c/i2c_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  I2C1 = (struct i2c_registers_map*) membuf;
}

void
test_i2c(void)
{
  I2C1->CR1 = 0;
  i2c_enable(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 0);
  i2c_enable(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 0);
  i2c_disable(I2C1);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_disable(I2C1);
  ASSERT_EQ(I2C1->CR1, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_operational_mode(void)
{
  I2C1->CR1 = 0;
  i2c_set_operational_mode(I2C1, I2C_OPERATIONAL_MODE_SMBUS);
  ASSERT_EQ(I2C1->CR1, (1u << 1));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 1);
  i2c_set_operational_mode(I2C1, I2C_OPERATIONAL_MODE_SMBUS);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 1);
  i2c_set_operational_mode(I2C1, I2C_OPERATIONAL_MODE_I2C);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_set_operational_mode(I2C1, I2C_OPERATIONAL_MODE_I2C);
  ASSERT_EQ(I2C1->CR1, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_smbus_type(void)
{
  I2C1->CR1 = 0;
  i2c_set_smbus_type(I2C1, I2C_SMBUS_TYPE_HOST);
  ASSERT_EQ(I2C1->CR1, (1u << 3));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 3);
  i2c_set_smbus_type(I2C1, I2C_SMBUS_TYPE_HOST);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 3);
  i2c_set_smbus_type(I2C1, I2C_SMBUS_TYPE_DEVICE);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_set_smbus_type(I2C1, I2C_SMBUS_TYPE_DEVICE);
  ASSERT_EQ(I2C1->CR1, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_config(void)
{
  I2C1->CR1 = 0;
  i2c_config_enable(I2C1, I2C_CONFIG_ARP);
  ASSERT_EQ(I2C1->CR1, (1u << 4));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 4);
  i2c_config_enable(I2C1, I2C_CONFIG_ARP);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 4);
  i2c_config_disable(I2C1, I2C_CONFIG_ARP);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_config_disable(I2C1, I2C_CONFIG_ARP);
  ASSERT_EQ(I2C1->CR1, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  I2C1->CR1 = 0;
  i2c_config_enable(I2C1, I2C_CONFIG_PEC);
  ASSERT_EQ(I2C1->CR1, (1u << 5));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 5);
  i2c_config_enable(I2C1, I2C_CONFIG_PEC);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 5);
  i2c_config_disable(I2C1, I2C_CONFIG_PEC);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_config_disable(I2C1, I2C_CONFIG_PEC);
  ASSERT_EQ(I2C1->CR1, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  I2C1->CR1 = 0;
  i2c_config_enable(I2C1, I2C_CONFIG_GENERAL_CALL);
  ASSERT_EQ(I2C1->CR1, (1u << 6));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 6);
  i2c_config_enable(I2C1, I2C_CONFIG_GENERAL_CALL);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 6);
  i2c_config_disable(I2C1, I2C_CONFIG_GENERAL_CALL);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_config_disable(I2C1, I2C_CONFIG_GENERAL_CALL);
  ASSERT_EQ(I2C1->CR1, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  I2C1->CR1 = 0;
  i2c_config_enable(I2C1, I2C_CONFIG_NO_CLOCK_STRETCH);
  ASSERT_EQ(I2C1->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 7);
  i2c_config_enable(I2C1, I2C_CONFIG_NO_CLOCK_STRETCH);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 7);
  i2c_config_disable(I2C1, I2C_CONFIG_NO_CLOCK_STRETCH);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_config_disable(I2C1, I2C_CONFIG_NO_CLOCK_STRETCH);
  ASSERT_EQ(I2C1->CR1, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_i2c_transaction_start(void)
{
  I2C1->CR1 = 0;
  i2c_transaction_start(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 8));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 8);
  i2c_transaction_start(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_transaction_stop(void)
{
  I2C1->CR1 = 0;
  i2c_transaction_stop(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 9));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 9);
  i2c_transaction_stop(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_send_ack(void)
{
  I2C1->CR1 = 0;
  i2c_send_ack(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 10);
  i2c_send_ack(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'fn_call (TODO)' (i2c_send_nack)
void
test_i2c_nack_on_next_byte(void)
{
  I2C1->CR1 = 0;
  i2c_nack_on_next_byte(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 11));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 11);
  i2c_nack_on_next_byte(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'fn_call (TODO)' (i2c_nack_on_current_byte)
void
test_i2c_send_pec_byte(void)
{
  I2C1->CR1 = 0;
  i2c_send_pec_byte(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 12);
  i2c_send_pec_byte(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_send_smbus_alert(void)
{
  I2C1->CR1 = 0;
  i2c_send_smbus_alert_enable(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 13));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 13);
  i2c_send_smbus_alert_enable(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 13);
  i2c_send_smbus_alert_disable(I2C1);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_send_smbus_alert_disable(I2C1);
  ASSERT_EQ(I2C1->CR1, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_software_reset(void)
{
  I2C1->CR1 = 0;
  i2c_software_reset_enable(I2C1);
  ASSERT_EQ(I2C1->CR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = ~(1u << 15);
  i2c_software_reset_enable(I2C1);
  ASSERT_EQ(I2C1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = (1u << 15);
  i2c_software_reset_disable(I2C1);
  ASSERT_EQ(I2C1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR1 = 0xffffffff;
  i2c_software_reset_disable(I2C1);
  ASSERT_EQ(I2C1->CR1, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_peripheral_clock_frequency(void)
{
  I2C1->CR2 = 0;
  i2c_set_peripheral_clock_frequency(I2C1, 0);
  ASSERT_EQ(I2C1->CR2, 0u << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = 0xffffffff;
  i2c_set_peripheral_clock_frequency(I2C1, 0);
  ASSERT_EQ(I2C1->CR2, ~(0x3fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->CR2 = 0;
  i2c_set_peripheral_clock_frequency(I2C1, 0x3f);
  ASSERT_EQ(I2C1->CR2, 0x3fu << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = 0xffffffff;
  i2c_set_peripheral_clock_frequency(I2C1, 0x3f);
  ASSERT_EQ(I2C1->CR2, ~(0x3fu << 0) | (0x3fu << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->CR2 = 0;
  i2c_set_peripheral_clock_frequency(I2C1, 0x40);
  ASSERT_EQ(I2C1->CR2, 0x40u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->CR2 = 0xffffffff;
  i2c_set_peripheral_clock_frequency(I2C1, 0x40);
  ASSERT_EQ(I2C1->CR2, ~(0x3fu << 0) | (0x40u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_i2c_interrupt(void)
{
  I2C1->CR2 = 0;
  i2c_interrupt_enable(I2C1, I2C_INTERRUPT_ERROR);
  ASSERT_EQ(I2C1->CR2, (1u << 8));
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = ~(1u << 8);
  i2c_interrupt_enable(I2C1, I2C_INTERRUPT_ERROR);
  ASSERT_EQ(I2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = (1u << 8);
  i2c_interrupt_disable(I2C1, I2C_INTERRUPT_ERROR);
  ASSERT_EQ(I2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = 0xffffffff;
  i2c_interrupt_disable(I2C1, I2C_INTERRUPT_ERROR);
  ASSERT_EQ(I2C1->CR2, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  I2C1->CR2 = 0;
  i2c_interrupt_enable(I2C1, I2C_INTERRUPT_EVENT);
  ASSERT_EQ(I2C1->CR2, (1u << 9));
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = ~(1u << 9);
  i2c_interrupt_enable(I2C1, I2C_INTERRUPT_EVENT);
  ASSERT_EQ(I2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = (1u << 9);
  i2c_interrupt_disable(I2C1, I2C_INTERRUPT_EVENT);
  ASSERT_EQ(I2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = 0xffffffff;
  i2c_interrupt_disable(I2C1, I2C_INTERRUPT_EVENT);
  ASSERT_EQ(I2C1->CR2, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  I2C1->CR2 = 0;
  i2c_interrupt_enable(I2C1, I2C_INTERRUPT_BUFFER);
  ASSERT_EQ(I2C1->CR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = ~(1u << 10);
  i2c_interrupt_enable(I2C1, I2C_INTERRUPT_BUFFER);
  ASSERT_EQ(I2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = (1u << 10);
  i2c_interrupt_disable(I2C1, I2C_INTERRUPT_BUFFER);
  ASSERT_EQ(I2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = 0xffffffff;
  i2c_interrupt_disable(I2C1, I2C_INTERRUPT_BUFFER);
  ASSERT_EQ(I2C1->CR2, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_i2c_dma_requests(void)
{
  I2C1->CR2 = 0;
  i2c_dma_requests_enable(I2C1);
  ASSERT_EQ(I2C1->CR2, (1u << 11));
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = ~(1u << 11);
  i2c_dma_requests_enable(I2C1);
  ASSERT_EQ(I2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = (1u << 11);
  i2c_dma_requests_disable(I2C1);
  ASSERT_EQ(I2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = 0xffffffff;
  i2c_dma_requests_disable(I2C1);
  ASSERT_EQ(I2C1->CR2, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_dma_last_transfer(void)
{
  I2C1->CR2 = 0;
  i2c_dma_last_transfer_enable(I2C1);
  ASSERT_EQ(I2C1->CR2, (1u << 12));
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = ~(1u << 12);
  i2c_dma_last_transfer_enable(I2C1);
  ASSERT_EQ(I2C1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = (1u << 12);
  i2c_dma_last_transfer_disable(I2C1);
  ASSERT_EQ(I2C1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CR2 = 0xffffffff;
  i2c_dma_last_transfer_disable(I2C1);
  ASSERT_EQ(I2C1->CR2, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_7bit_address(void)
{
  I2C1->OAR1 = 0;
  i2c_set_7bit_address(I2C1, 0);
  ASSERT_EQ(I2C1->OAR1, 0u << 1);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR1 = 0xffffffff;
  i2c_set_7bit_address(I2C1, 0);
  ASSERT_EQ(I2C1->OAR1, ~(0x3fu << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  I2C1->OAR1 = 0;
  i2c_set_7bit_address(I2C1, 0x3f);
  ASSERT_EQ(I2C1->OAR1, 0x3fu << 1);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR1 = 0xffffffff;
  i2c_set_7bit_address(I2C1, 0x3f);
  ASSERT_EQ(I2C1->OAR1, ~(0x3fu << 1) | (0x3fu << 1));
  ASSERT_FALSE(execution_halted());


  I2C1->OAR1 = 0;
  i2c_set_7bit_address(I2C1, 0x40);
  ASSERT_EQ(I2C1->OAR1, 0x40u << 1);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->OAR1 = 0xffffffff;
  i2c_set_7bit_address(I2C1, 0x40);
  ASSERT_EQ(I2C1->OAR1, ~(0x3fu << 1) | (0x40u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_i2c_set_10bit_address(void)
{
  I2C1->OAR1 = 0;
  i2c_set_10bit_address(I2C1, 0);
  ASSERT_EQ(I2C1->OAR1, 0u << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR1 = 0xffffffff;
  i2c_set_10bit_address(I2C1, 0);
  ASSERT_EQ(I2C1->OAR1, ~(0x3ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->OAR1 = 0;
  i2c_set_10bit_address(I2C1, 0x3ff);
  ASSERT_EQ(I2C1->OAR1, 0x3ffu << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR1 = 0xffffffff;
  i2c_set_10bit_address(I2C1, 0x3ff);
  ASSERT_EQ(I2C1->OAR1, ~(0x3ffu << 0) | (0x3ffu << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->OAR1 = 0;
  i2c_set_10bit_address(I2C1, 0x400);
  ASSERT_EQ(I2C1->OAR1, 0x400u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->OAR1 = 0xffffffff;
  i2c_set_10bit_address(I2C1, 0x400);
  ASSERT_EQ(I2C1->OAR1, ~(0x3ffu << 0) | (0x400u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_i2c_set_address_mode(void)
{
  I2C1->OAR1 = 0;
  i2c_set_address_mode(I2C1, I2C_ADDRESS_MODE_10BITS);
  ASSERT_EQ(I2C1->OAR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  I2C1->OAR1 = ~(1u << 15);
  i2c_set_address_mode(I2C1, I2C_ADDRESS_MODE_10BITS);
  ASSERT_EQ(I2C1->OAR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR1 = (1u << 15);
  i2c_set_address_mode(I2C1, I2C_ADDRESS_MODE_7BITS);
  ASSERT_EQ(I2C1->OAR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR1 = 0xffffffff;
  i2c_set_address_mode(I2C1, I2C_ADDRESS_MODE_7BITS);
  ASSERT_EQ(I2C1->OAR1, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_dual_addressing_mode(void)
{
  I2C1->OAR2 = 0;
  i2c_dual_addressing_mode_enable(I2C1);
  ASSERT_EQ(I2C1->OAR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  I2C1->OAR2 = ~(1u << 0);
  i2c_dual_addressing_mode_enable(I2C1);
  ASSERT_EQ(I2C1->OAR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR2 = (1u << 0);
  i2c_dual_addressing_mode_disable(I2C1);
  ASSERT_EQ(I2C1->OAR2, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR2 = 0xffffffff;
  i2c_dual_addressing_mode_disable(I2C1);
  ASSERT_EQ(I2C1->OAR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_secondary_address(void)
{
  I2C1->OAR2 = 0;
  i2c_set_secondary_address(I2C1, 0);
  ASSERT_EQ(I2C1->OAR2, 0u << 1);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR2 = 0xffffffff;
  i2c_set_secondary_address(I2C1, 0);
  ASSERT_EQ(I2C1->OAR2, ~(0x7fu << 1) | (0u << 1));
  ASSERT_FALSE(execution_halted());


  I2C1->OAR2 = 0;
  i2c_set_secondary_address(I2C1, 0x7f);
  ASSERT_EQ(I2C1->OAR2, 0x7fu << 1);
  ASSERT_FALSE(execution_halted());

  I2C1->OAR2 = 0xffffffff;
  i2c_set_secondary_address(I2C1, 0x7f);
  ASSERT_EQ(I2C1->OAR2, ~(0x7fu << 1) | (0x7fu << 1));
  ASSERT_FALSE(execution_halted());


  I2C1->OAR2 = 0;
  i2c_set_secondary_address(I2C1, 0x80);
  ASSERT_EQ(I2C1->OAR2, 0x80u << 1);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->OAR2 = 0xffffffff;
  i2c_set_secondary_address(I2C1, 0x80);
  ASSERT_EQ(I2C1->OAR2, ~(0x7fu << 1) | (0x80u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_i2c_send_byte(void)
{
  I2C1->DR = 0;
  i2c_send_byte(I2C1, 0);
  ASSERT_EQ(I2C1->DR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->DR = 0xffffffff;
  i2c_send_byte(I2C1, 0);
  ASSERT_EQ(I2C1->DR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->DR = 0;
  i2c_send_byte(I2C1, 0xff);
  ASSERT_EQ(I2C1->DR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->DR = 0xffffffff;
  i2c_send_byte(I2C1, 0xff);
  ASSERT_EQ(I2C1->DR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->DR = 0;
  i2c_send_byte(I2C1, 0x100);
  ASSERT_EQ(I2C1->DR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->DR = 0xffffffff;
  i2c_send_byte(I2C1, 0x100);
  ASSERT_EQ(I2C1->DR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_i2c_read_byte(void)
{
  u32 res;

  // read_bits
  I2C1->DR = 0;
  res = i2c_read_byte(I2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->DR = ~(0xffu << 0);
  res = i2c_read_byte(I2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->DR = 0xffu << 0;
  res = i2c_read_byte(I2C1);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_is_flag_set(void)
{
  u32 res;

  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 0);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 0);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 1);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 1);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 2);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 2);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS10);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 3);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS10);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 3);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS10);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS10);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_STOP_BIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 4);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_STOP_BIT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 4);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_STOP_BIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_STOP_BIT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 6);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 6);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 7);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 7);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 8);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 8);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 9);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 9);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ACK_FAIL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 10);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ACK_FAIL);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 10);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ACK_FAIL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_ACK_FAIL);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 11);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 11);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_PEC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 12);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_PEC_ERROR);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 12);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_PEC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_PEC_ERROR);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 14);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 14);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_TIMEOUT);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = (1u << 15);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = ~(1u << 15);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_MASTER_SLAVE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = (1u << 0);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_MASTER_SLAVE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(1u << 0);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_MASTER_SLAVE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_MASTER_SLAVE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = (1u << 1);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(1u << 1);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BUS_BUSY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTES_TRANSMITTED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = (1u << 2);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTES_TRANSMITTED);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(1u << 2);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTES_TRANSMITTED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_BYTES_TRANSMITTED);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_GENERAL_CALL_ADDRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = (1u << 4);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_GENERAL_CALL_ADDRESS);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(1u << 4);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_GENERAL_CALL_ADDRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_GENERAL_CALL_ADDRESS);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_DEFAULT_ADDRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = (1u << 5);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_DEFAULT_ADDRESS);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(1u << 5);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_DEFAULT_ADDRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_DEFAULT_ADDRESS);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_HOST_HEADER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = (1u << 6);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_HOST_HEADER);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(1u << 6);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_HOST_HEADER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_SMBUS_HOST_HEADER);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = 0;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DUAL_FLAG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = (1u << 7);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DUAL_FLAG);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(1u << 7);
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DUAL_FLAG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffffffff;
  res = i2c_is_flag_set(I2C1, I2C_FLAG_DUAL_FLAG);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_i2c_flag_clear(void)
{
  I2C1->SR1 = (1u << 0);
  i2c_flag_clear(I2C1, I2C_FLAG_START_BIT);
  ASSERT_EQ(I2C1->SR1, (1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_START_BIT);
  ASSERT_EQ(I2C1->SR1, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR1 = (1u << 1);
  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS);
  ASSERT_EQ(I2C1->SR1, (1u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS);
  ASSERT_EQ(I2C1->SR1, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR1 = (1u << 2);
  i2c_flag_clear(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED);
  ASSERT_EQ(I2C1->SR1, (1u << 2));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED);
  ASSERT_EQ(I2C1->SR1, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR1 = (1u << 3);
  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS10);
  ASSERT_EQ(I2C1->SR1, (1u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS10);
  ASSERT_EQ(I2C1->SR1, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR1 = (1u << 4);
  i2c_flag_clear(I2C1, I2C_FLAG_STOP_BIT);
  ASSERT_EQ(I2C1->SR1, (1u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_STOP_BIT);
  ASSERT_EQ(I2C1->SR1, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR1 = (1u << 6);
  i2c_flag_clear(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY);
  ASSERT_EQ(I2C1->SR1, (1u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY);
  ASSERT_EQ(I2C1->SR1, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR1 = (1u << 7);
  i2c_flag_clear(I2C1, I2C_FLAG_DATA_REG_EMPTY);
  ASSERT_EQ(I2C1->SR1, (1u << 7));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_DATA_REG_EMPTY);
  ASSERT_EQ(I2C1->SR1, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR1 = (1u << 8);
  i2c_flag_clear(I2C1, I2C_FLAG_BUS_ERROR);
  ASSERT_EQ(I2C1->SR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_BUS_ERROR);
  ASSERT_EQ(I2C1->SR1, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = (1u << 9);
  i2c_flag_clear(I2C1, I2C_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(I2C1->SR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(I2C1->SR1, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = (1u << 10);
  i2c_flag_clear(I2C1, I2C_FLAG_ACK_FAIL);
  ASSERT_EQ(I2C1->SR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_ACK_FAIL);
  ASSERT_EQ(I2C1->SR1, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = (1u << 11);
  i2c_flag_clear(I2C1, I2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(I2C1->SR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(I2C1->SR1, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = (1u << 12);
  i2c_flag_clear(I2C1, I2C_FLAG_PEC_ERROR);
  ASSERT_EQ(I2C1->SR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_PEC_ERROR);
  ASSERT_EQ(I2C1->SR1, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = (1u << 14);
  i2c_flag_clear(I2C1, I2C_FLAG_TIMEOUT);
  ASSERT_EQ(I2C1->SR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_TIMEOUT);
  ASSERT_EQ(I2C1->SR1, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


  I2C1->SR1 = (1u << 15);
  i2c_flag_clear(I2C1, I2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(I2C1->SR1, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR1 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_SMBUS_ALERT);
  ASSERT_EQ(I2C1->SR1, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  I2C1->SR2 = (1u << 0);
  i2c_flag_clear(I2C1, I2C_FLAG_MASTER_SLAVE);
  ASSERT_EQ(I2C1->SR2, (1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR2 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_MASTER_SLAVE);
  ASSERT_EQ(I2C1->SR2, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR2 = (1u << 1);
  i2c_flag_clear(I2C1, I2C_FLAG_BUS_BUSY);
  ASSERT_EQ(I2C1->SR2, (1u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR2 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_BUS_BUSY);
  ASSERT_EQ(I2C1->SR2, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR2 = (1u << 2);
  i2c_flag_clear(I2C1, I2C_FLAG_BYTES_TRANSMITTED);
  ASSERT_EQ(I2C1->SR2, (1u << 2));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR2 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_BYTES_TRANSMITTED);
  ASSERT_EQ(I2C1->SR2, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR2 = (1u << 4);
  i2c_flag_clear(I2C1, I2C_FLAG_GENERAL_CALL_ADDRESS);
  ASSERT_EQ(I2C1->SR2, (1u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR2 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_GENERAL_CALL_ADDRESS);
  ASSERT_EQ(I2C1->SR2, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR2 = (1u << 5);
  i2c_flag_clear(I2C1, I2C_FLAG_SMBUS_DEFAULT_ADDRESS);
  ASSERT_EQ(I2C1->SR2, (1u << 5));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR2 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_SMBUS_DEFAULT_ADDRESS);
  ASSERT_EQ(I2C1->SR2, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR2 = (1u << 6);
  i2c_flag_clear(I2C1, I2C_FLAG_SMBUS_HOST_HEADER);
  ASSERT_EQ(I2C1->SR2, (1u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR2 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_SMBUS_HOST_HEADER);
  ASSERT_EQ(I2C1->SR2, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  I2C1->SR2 = (1u << 7);
  i2c_flag_clear(I2C1, I2C_FLAG_DUAL_FLAG);
  ASSERT_EQ(I2C1->SR2, (1u << 7));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->SR2 = 0xffffffff;
  i2c_flag_clear(I2C1, I2C_FLAG_DUAL_FLAG);
  ASSERT_EQ(I2C1->SR2, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_i2c_get_pec(void)
{
  u32 res;

  // read_bits
  I2C1->SR2 = 0;
  res = i2c_get_pec(I2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = ~(0xffu << 8);
  res = i2c_get_pec(I2C1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->SR2 = 0xffu << 8;
  res = i2c_get_pec(I2C1);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_clock(void)
{
  I2C1->CCR = 0;
  i2c_set_clock(I2C1, 0);
  ASSERT_EQ(I2C1->CCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = 0xffffffff;
  i2c_set_clock(I2C1, 0);
  ASSERT_EQ(I2C1->CCR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->CCR = 0;
  i2c_set_clock(I2C1, 0xfff);
  ASSERT_EQ(I2C1->CCR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = 0xffffffff;
  i2c_set_clock(I2C1, 0xfff);
  ASSERT_EQ(I2C1->CCR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->CCR = 0;
  i2c_set_clock(I2C1, 0x1000);
  ASSERT_EQ(I2C1->CCR, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->CCR = 0xffffffff;
  i2c_set_clock(I2C1, 0x1000);
  ASSERT_EQ(I2C1->CCR, ~(0xfffu << 0) | (0x1000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_i2c_set_fm_duty_cycle(void)
{
  I2C1->CCR = 0;
  i2c_set_fm_duty_cycle(I2C1, I2C_FM_DUTY_CYCLE_16_9);
  ASSERT_EQ(I2C1->CCR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = ~(1u << 14);
  i2c_set_fm_duty_cycle(I2C1, I2C_FM_DUTY_CYCLE_16_9);
  ASSERT_EQ(I2C1->CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = (1u << 14);
  i2c_set_fm_duty_cycle(I2C1, I2C_FM_DUTY_CYCLE_2);
  ASSERT_EQ(I2C1->CCR, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = 0xffffffff;
  i2c_set_fm_duty_cycle(I2C1, I2C_FM_DUTY_CYCLE_2);
  ASSERT_EQ(I2C1->CCR, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_master_mode(void)
{
  I2C1->CCR = 0;
  i2c_set_master_mode(I2C1, I2C_MASTER_MODE_FM);
  ASSERT_EQ(I2C1->CCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = ~(1u << 15);
  i2c_set_master_mode(I2C1, I2C_MASTER_MODE_FM);
  ASSERT_EQ(I2C1->CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = (1u << 15);
  i2c_set_master_mode(I2C1, I2C_MASTER_MODE_SM);
  ASSERT_EQ(I2C1->CCR, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->CCR = 0xffffffff;
  i2c_set_master_mode(I2C1, I2C_MASTER_MODE_SM);
  ASSERT_EQ(I2C1->CCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_i2c_set_trise_time(void)
{
  I2C1->TRISE = 0;
  i2c_set_trise_time(I2C1, 0);
  ASSERT_EQ(I2C1->TRISE, 0u << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->TRISE = 0xffffffff;
  i2c_set_trise_time(I2C1, 0);
  ASSERT_EQ(I2C1->TRISE, ~(0x3fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->TRISE = 0;
  i2c_set_trise_time(I2C1, 0x3f);
  ASSERT_EQ(I2C1->TRISE, 0x3fu << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->TRISE = 0xffffffff;
  i2c_set_trise_time(I2C1, 0x3f);
  ASSERT_EQ(I2C1->TRISE, ~(0x3fu << 0) | (0x3fu << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->TRISE = 0;
  i2c_set_trise_time(I2C1, 0x40);
  ASSERT_EQ(I2C1->TRISE, 0x40u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->TRISE = 0xffffffff;
  i2c_set_trise_time(I2C1, 0x40);
  ASSERT_EQ(I2C1->TRISE, ~(0x3fu << 0) | (0x40u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

#if defined(STM32_I2C_FILTER)
void
test_i2c_set_digital_noise_filter_capability(void)
{
  I2C1->FLTR = 0;
  i2c_set_digital_noise_filter_capability(I2C1, 0);
  ASSERT_EQ(I2C1->FLTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->FLTR = 0xffffffff;
  i2c_set_digital_noise_filter_capability(I2C1, 0);
  ASSERT_EQ(I2C1->FLTR, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->FLTR = 0;
  i2c_set_digital_noise_filter_capability(I2C1, 0xf);
  ASSERT_EQ(I2C1->FLTR, 0xfu << 0);
  ASSERT_FALSE(execution_halted());

  I2C1->FLTR = 0xffffffff;
  i2c_set_digital_noise_filter_capability(I2C1, 0xf);
  ASSERT_EQ(I2C1->FLTR, ~(0xfu << 0) | (0xfu << 0));
  ASSERT_FALSE(execution_halted());


  I2C1->FLTR = 0;
  i2c_set_digital_noise_filter_capability(I2C1, 0x10);
  ASSERT_EQ(I2C1->FLTR, 0x10u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  I2C1->FLTR = 0xffffffff;
  i2c_set_digital_noise_filter_capability(I2C1, 0x10);
  ASSERT_EQ(I2C1->FLTR, ~(0xfu << 0) | (0x10u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_I2C_FILTER)
void
test_i2c_digital_noise_filter(void)
{
  I2C1->FLTR = 0;
  i2c_digital_noise_filter_enable(I2C1);
  ASSERT_EQ(I2C1->FLTR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  I2C1->FLTR = ~(1u << 4);
  i2c_digital_noise_filter_enable(I2C1);
  ASSERT_EQ(I2C1->FLTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  I2C1->FLTR = (1u << 4);
  i2c_digital_noise_filter_disable(I2C1);
  ASSERT_EQ(I2C1->FLTR, 0);
  ASSERT_FALSE(execution_halted());

  I2C1->FLTR = 0xffffffff;
  i2c_digital_noise_filter_disable(I2C1);
  ASSERT_EQ(I2C1->FLTR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_i2c),
    TEST_FUNC(test_i2c_set_operational_mode),
    TEST_FUNC(test_i2c_set_smbus_type),
    TEST_FUNC(test_i2c_config),
    TEST_FUNC(test_i2c_transaction_start),
    TEST_FUNC(test_i2c_transaction_stop),
    TEST_FUNC(test_i2c_send_ack),
    TEST_FUNC(test_i2c_nack_on_next_byte),
    TEST_FUNC(test_i2c_send_pec_byte),
    TEST_FUNC(test_i2c_send_smbus_alert),
    TEST_FUNC(test_i2c_software_reset),
    TEST_FUNC(test_i2c_set_peripheral_clock_frequency),
    TEST_FUNC(test_i2c_interrupt),
    TEST_FUNC(test_i2c_dma_requests),
    TEST_FUNC(test_i2c_dma_last_transfer),
    TEST_FUNC(test_i2c_set_7bit_address),
    TEST_FUNC(test_i2c_set_10bit_address),
    TEST_FUNC(test_i2c_set_address_mode),
    TEST_FUNC(test_i2c_dual_addressing_mode),
    TEST_FUNC(test_i2c_set_secondary_address),
    TEST_FUNC(test_i2c_send_byte),
    TEST_FUNC(test_i2c_read_byte),
    TEST_FUNC(test_i2c_is_flag_set),
    TEST_FUNC(test_i2c_flag_clear),
    TEST_FUNC(test_i2c_get_pec),
    TEST_FUNC(test_i2c_set_clock),
    TEST_FUNC(test_i2c_set_fm_duty_cycle),
    TEST_FUNC(test_i2c_set_master_mode),
    TEST_FUNC(test_i2c_set_trise_time),
#if defined(STM32_I2C_FILTER)
    TEST_FUNC(test_i2c_set_digital_noise_filter_capability),
#endif
#if defined(STM32_I2C_FILTER)
    TEST_FUNC(test_i2c_digital_noise_filter),
#endif
  };

  return TESTS_RUN(tests);
}
