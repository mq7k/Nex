#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/usart/usart_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  USART1 = (struct usart_registers_map*) membuf;
}

void
test_usart_is_flag_set(void)
{
  u32 res;

  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_PARITY_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 0);
  res = usart_is_flag_set(USART1, USART_FLAG_PARITY_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 0);
  res = usart_is_flag_set(USART1, USART_FLAG_PARITY_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_PARITY_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_FRAMING_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 1);
  res = usart_is_flag_set(USART1, USART_FLAG_FRAMING_ERROR);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 1);
  res = usart_is_flag_set(USART1, USART_FLAG_FRAMING_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_FRAMING_ERROR);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_NOISE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 2);
  res = usart_is_flag_set(USART1, USART_FLAG_NOISE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 2);
  res = usart_is_flag_set(USART1, USART_FLAG_NOISE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_NOISE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_OVERRUN_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 3);
  res = usart_is_flag_set(USART1, USART_FLAG_OVERRUN_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 3);
  res = usart_is_flag_set(USART1, USART_FLAG_OVERRUN_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_OVERRUN_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_IDLE_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 4);
  res = usart_is_flag_set(USART1, USART_FLAG_IDLE_LINE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 4);
  res = usart_is_flag_set(USART1, USART_FLAG_IDLE_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_IDLE_LINE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_READ_REG_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 5);
  res = usart_is_flag_set(USART1, USART_FLAG_READ_REG_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 5);
  res = usart_is_flag_set(USART1, USART_FLAG_READ_REG_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_READ_REG_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMISSION_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 6);
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMISSION_COMPLETE);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 6);
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMISSION_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMISSION_COMPLETE);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMIT_REG_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 7);
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMIT_REG_EMPTY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 7);
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMIT_REG_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_TRANSMIT_REG_EMPTY);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_LIN_BREAK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 8);
  res = usart_is_flag_set(USART1, USART_FLAG_LIN_BREAK);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 8);
  res = usart_is_flag_set(USART1, USART_FLAG_LIN_BREAK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_LIN_BREAK);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  USART1->SR = 0;
  res = usart_is_flag_set(USART1, USART_FLAG_CTS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = (1u << 9);
  res = usart_is_flag_set(USART1, USART_FLAG_CTS);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  USART1->SR = ~(1u << 9);
  res = usart_is_flag_set(USART1, USART_FLAG_CTS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->SR = 0xffffffff;
  res = usart_is_flag_set(USART1, USART_FLAG_CTS);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


}

void
test_usart_flag_clear(void)
{










}

// └─Skipping type 'flag_clear (TODO)' (usart_flag_clear_multibuffer)
void
test_usart_data_read(void)
{
  u32 res;

  // read_reg
  USART1->DR = 0;
  res = usart_data_read(USART1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  USART1->DR = 0xffffffff;
  res = usart_data_read(USART1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_usart_send_byte(void)
{
  USART1->DR = 0;
  usart_send_byte(USART1, 0);
  ASSERT_EQ(USART1->DR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  USART1->DR = 0;
  usart_send_byte(USART1, 0x1ff);
  ASSERT_EQ(USART1->DR, 0x1ffu << 0);
  ASSERT_FALSE(execution_halted());


  USART1->DR = 0;
  usart_send_byte(USART1, 0x200);
  ASSERT_EQ(USART1->DR, 0x200u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_usart_set_bittime(void)
{
  USART1->BRR = 0;
  usart_set_bittime(USART1, 0);
  ASSERT_EQ(USART1->BRR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  USART1->BRR = 0;
  usart_set_bittime(USART1, 0xffff);
  ASSERT_EQ(USART1->BRR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  USART1->BRR = 0;
  usart_set_bittime(USART1, 0x10000);
  ASSERT_EQ(USART1->BRR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_usart_set_div_fraction(void)
{
  USART1->BRR = 0;
  usart_set_div_fraction(USART1, 0);
  ASSERT_EQ(USART1->BRR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  USART1->BRR = 0xffffffff;
  usart_set_div_fraction(USART1, 0);
  ASSERT_EQ(USART1->BRR, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  USART1->BRR = 0;
  usart_set_div_fraction(USART1, 0xf);
  ASSERT_EQ(USART1->BRR, 0xfu << 0);
  ASSERT_FALSE(execution_halted());

  USART1->BRR = 0xffffffff;
  usart_set_div_fraction(USART1, 0xf);
  ASSERT_EQ(USART1->BRR, ~(0xfu << 0) | (0xfu << 0));
  ASSERT_FALSE(execution_halted());


  USART1->BRR = 0;
  usart_set_div_fraction(USART1, 0x10);
  ASSERT_EQ(USART1->BRR, 0x10u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  USART1->BRR = 0xffffffff;
  usart_set_div_fraction(USART1, 0x10);
  ASSERT_EQ(USART1->BRR, ~(0xfu << 0) | (0x10u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_usart_set_div_mantissa(void)
{
  USART1->BRR = 0;
  usart_set_div_mantissa(USART1, 0);
  ASSERT_EQ(USART1->BRR, 0u << 4);
  ASSERT_FALSE(execution_halted());

  USART1->BRR = 0xffffffff;
  usart_set_div_mantissa(USART1, 0);
  ASSERT_EQ(USART1->BRR, ~(0xfffu << 4) | (0u << 4));
  ASSERT_FALSE(execution_halted());


  USART1->BRR = 0;
  usart_set_div_mantissa(USART1, 0xfff);
  ASSERT_EQ(USART1->BRR, 0xfffu << 4);
  ASSERT_FALSE(execution_halted());

  USART1->BRR = 0xffffffff;
  usart_set_div_mantissa(USART1, 0xfff);
  ASSERT_EQ(USART1->BRR, ~(0xfffu << 4) | (0xfffu << 4));
  ASSERT_FALSE(execution_halted());


  USART1->BRR = 0;
  usart_set_div_mantissa(USART1, 0x1000);
  ASSERT_EQ(USART1->BRR, 0x1000u << 4);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  USART1->BRR = 0xffffffff;
  usart_set_div_mantissa(USART1, 0x1000);
  ASSERT_EQ(USART1->BRR, ~(0xfffu << 4) | (0x1000u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_usart_send_break(void)
{
  USART1->CR1 = 0;
  usart_send_break(USART1);
  ASSERT_EQ(USART1->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 0);
  usart_send_break(USART1);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_usart_set_receiver_mode(void)
{
  USART1->CR1 = 0;
  usart_set_receiver_mode(USART1, USART_RECEIVER_MODE_MUTE);
  ASSERT_EQ(USART1->CR1, (1u << 1));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 1);
  usart_set_receiver_mode(USART1, USART_RECEIVER_MODE_MUTE);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 1);
  usart_set_receiver_mode(USART1, USART_RECEIVER_MODE_ACTIVE);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_set_receiver_mode(USART1, USART_RECEIVER_MODE_ACTIVE);
  ASSERT_EQ(USART1->CR1, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_receiver(void)
{
  USART1->CR1 = 0;
  usart_receiver_enable(USART1);
  ASSERT_EQ(USART1->CR1, (1u << 2));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 2);
  usart_receiver_enable(USART1);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 2);
  usart_receiver_disable(USART1);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_receiver_disable(USART1);
  ASSERT_EQ(USART1->CR1, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_transmitter(void)
{
  USART1->CR1 = 0;
  usart_transmitter_enable(USART1);
  ASSERT_EQ(USART1->CR1, (1u << 3));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 3);
  usart_transmitter_enable(USART1);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 3);
  usart_transmitter_disable(USART1);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_transmitter_disable(USART1);
  ASSERT_EQ(USART1->CR1, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_interrupt(void)
{
  USART1->CR1 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_IDLE);
  ASSERT_EQ(USART1->CR1, (1u << 4));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 4);
  usart_interrupt_enable(USART1, USART_INTERRUPT_IDLE);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 4);
  usart_interrupt_disable(USART1, USART_INTERRUPT_IDLE);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_IDLE);
  ASSERT_EQ(USART1->CR1, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  USART1->CR1 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_READ_REG_NOT_EMPTY);
  ASSERT_EQ(USART1->CR1, (1u << 5));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 5);
  usart_interrupt_enable(USART1, USART_INTERRUPT_READ_REG_NOT_EMPTY);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 5);
  usart_interrupt_disable(USART1, USART_INTERRUPT_READ_REG_NOT_EMPTY);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_READ_REG_NOT_EMPTY);
  ASSERT_EQ(USART1->CR1, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  USART1->CR1 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_TRANSMITTION_COMPLETE);
  ASSERT_EQ(USART1->CR1, (1u << 6));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 6);
  usart_interrupt_enable(USART1, USART_INTERRUPT_TRANSMITTION_COMPLETE);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 6);
  usart_interrupt_disable(USART1, USART_INTERRUPT_TRANSMITTION_COMPLETE);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_TRANSMITTION_COMPLETE);
  ASSERT_EQ(USART1->CR1, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  USART1->CR1 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_WRITE_REG_EMPTY);
  ASSERT_EQ(USART1->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 7);
  usart_interrupt_enable(USART1, USART_INTERRUPT_WRITE_REG_EMPTY);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 7);
  usart_interrupt_disable(USART1, USART_INTERRUPT_WRITE_REG_EMPTY);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_WRITE_REG_EMPTY);
  ASSERT_EQ(USART1->CR1, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  USART1->CR1 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_PARITY_ERROR);
  ASSERT_EQ(USART1->CR1, (1u << 8));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 8);
  usart_interrupt_enable(USART1, USART_INTERRUPT_PARITY_ERROR);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 8);
  usart_interrupt_disable(USART1, USART_INTERRUPT_PARITY_ERROR);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_PARITY_ERROR);
  ASSERT_EQ(USART1->CR1, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  USART1->CR2 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_LINE_BREAK_DETECTION);
  ASSERT_EQ(USART1->CR2, (1u << 6));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(1u << 6);
  usart_interrupt_enable(USART1, USART_INTERRUPT_LINE_BREAK_DETECTION);
  ASSERT_EQ(USART1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = (1u << 6);
  usart_interrupt_disable(USART1, USART_INTERRUPT_LINE_BREAK_DETECTION);
  ASSERT_EQ(USART1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_LINE_BREAK_DETECTION);
  ASSERT_EQ(USART1->CR2, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  USART1->CR3 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_ERROR);
  ASSERT_EQ(USART1->CR3, (1u << 0));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 0);
  usart_interrupt_enable(USART1, USART_INTERRUPT_ERROR);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 0);
  usart_interrupt_disable(USART1, USART_INTERRUPT_ERROR);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_ERROR);
  ASSERT_EQ(USART1->CR3, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  USART1->CR3 = 0;
  usart_interrupt_enable(USART1, USART_INTERRUPT_CTS);
  ASSERT_EQ(USART1->CR3, (1u << 10));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 10);
  usart_interrupt_enable(USART1, USART_INTERRUPT_CTS);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 10);
  usart_interrupt_disable(USART1, USART_INTERRUPT_CTS);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_interrupt_disable(USART1, USART_INTERRUPT_CTS);
  ASSERT_EQ(USART1->CR3, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_usart_set_parity(void)
{
  USART1->CR1 = 0;
  usart_set_parity(USART1, USART_PARITY_ODD);
  ASSERT_EQ(USART1->CR1, (1u << 9));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 9);
  usart_set_parity(USART1, USART_PARITY_ODD);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 9);
  usart_set_parity(USART1, USART_PARITY_EVEN);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_set_parity(USART1, USART_PARITY_EVEN);
  ASSERT_EQ(USART1->CR1, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_parity_control(void)
{
  USART1->CR1 = 0;
  usart_parity_control_enable(USART1);
  ASSERT_EQ(USART1->CR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 10);
  usart_parity_control_enable(USART1);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 10);
  usart_parity_control_disable(USART1);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_parity_control_disable(USART1);
  ASSERT_EQ(USART1->CR1, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_set_wakeup_method(void)
{
  USART1->CR1 = 0;
  usart_set_wakeup_method(USART1, USART_WAKEUP_METHOD_ADDRESS_MARK);
  ASSERT_EQ(USART1->CR1, (1u << 11));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 11);
  usart_set_wakeup_method(USART1, USART_WAKEUP_METHOD_ADDRESS_MARK);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 11);
  usart_set_wakeup_method(USART1, USART_WAKEUP_METHOD_IDLE_LINE);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_set_wakeup_method(USART1, USART_WAKEUP_METHOD_IDLE_LINE);
  ASSERT_EQ(USART1->CR1, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_set_word_length(void)
{
  USART1->CR1 = 0;
  usart_set_word_length(USART1, USART_WORD_LENGTH_9BITS);
  ASSERT_EQ(USART1->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 12);
  usart_set_word_length(USART1, USART_WORD_LENGTH_9BITS);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 12);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  ASSERT_EQ(USART1->CR1, 0xffffffff & ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_usart(void)
{
  USART1->CR1 = 0;
  usart_enable(USART1);
  ASSERT_EQ(USART1->CR1, (1u << 13));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 13);
  usart_enable(USART1);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 13);
  usart_disable(USART1);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_disable(USART1);
  ASSERT_EQ(USART1->CR1, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_USART_OVERSAMPLING)
void
test_usart_set_oversampling_mode(void)
{
  USART1->CR1 = 0;
  usart_set_oversampling_mode(USART1, USART_OVERSAMPLING_MODE8);
  ASSERT_EQ(USART1->CR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = ~(1u << 15);
  usart_set_oversampling_mode(USART1, USART_OVERSAMPLING_MODE8);
  ASSERT_EQ(USART1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = (1u << 15);
  usart_set_oversampling_mode(USART1, USART_OVERSAMPLING_MODE16);
  ASSERT_EQ(USART1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR1 = 0xffffffff;
  usart_set_oversampling_mode(USART1, USART_OVERSAMPLING_MODE16);
  ASSERT_EQ(USART1->CR1, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_usart_set_node_address(void)
{
  USART1->CR2 = 0;
  usart_set_node_address(USART1, 0);
  ASSERT_EQ(USART1->CR2, 0u << 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_set_node_address(USART1, 0);
  ASSERT_EQ(USART1->CR2, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  USART1->CR2 = 0;
  usart_set_node_address(USART1, 0xf);
  ASSERT_EQ(USART1->CR2, 0xfu << 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_set_node_address(USART1, 0xf);
  ASSERT_EQ(USART1->CR2, ~(0xfu << 0) | (0xfu << 0));
  ASSERT_FALSE(execution_halted());


  USART1->CR2 = 0;
  usart_set_node_address(USART1, 0x10);
  ASSERT_EQ(USART1->CR2, 0x10u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  USART1->CR2 = 0xffffffff;
  usart_set_node_address(USART1, 0x10);
  ASSERT_EQ(USART1->CR2, ~(0xfu << 0) | (0x10u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_usart_set_line_break_detection_length(void)
{
  USART1->CR2 = 0;
  usart_set_line_break_detection_length(USART1, USART_LINE_BREAK_LENGTH_11BITS);
  ASSERT_EQ(USART1->CR2, (1u << 5));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(1u << 5);
  usart_set_line_break_detection_length(USART1, USART_LINE_BREAK_LENGTH_11BITS);
  ASSERT_EQ(USART1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = (1u << 5);
  usart_set_line_break_detection_length(USART1, USART_LINE_BREAK_LENGTH_10BITS);
  ASSERT_EQ(USART1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_set_line_break_detection_length(USART1, USART_LINE_BREAK_LENGTH_10BITS);
  ASSERT_EQ(USART1->CR2, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_last_bit_clock_pulse_output(void)
{
  USART1->CR2 = 0;
  usart_last_bit_clock_pulse_output_enable(USART1);
  ASSERT_EQ(USART1->CR2, (1u << 8));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(1u << 8);
  usart_last_bit_clock_pulse_output_enable(USART1);
  ASSERT_EQ(USART1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = (1u << 8);
  usart_last_bit_clock_pulse_output_disable(USART1);
  ASSERT_EQ(USART1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_last_bit_clock_pulse_output_disable(USART1);
  ASSERT_EQ(USART1->CR2, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_set_clock_phase(void)
{
  USART1->CR2 = 0;
  usart_set_clock_phase(USART1, USART_CLOCK_PHASE_SECOND);
  ASSERT_EQ(USART1->CR2, (1u << 9));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(1u << 9);
  usart_set_clock_phase(USART1, USART_CLOCK_PHASE_SECOND);
  ASSERT_EQ(USART1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = (1u << 9);
  usart_set_clock_phase(USART1, USART_CLOCK_PHASE_FIRST);
  ASSERT_EQ(USART1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_set_clock_phase(USART1, USART_CLOCK_PHASE_FIRST);
  ASSERT_EQ(USART1->CR2, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_set_clock_polarity(void)
{
  USART1->CR2 = 0;
  usart_set_clock_polarity(USART1, USART_CLOCK_POLARITY_STEADY_HIGH);
  ASSERT_EQ(USART1->CR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(1u << 10);
  usart_set_clock_polarity(USART1, USART_CLOCK_POLARITY_STEADY_HIGH);
  ASSERT_EQ(USART1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = (1u << 10);
  usart_set_clock_polarity(USART1, USART_CLOCK_POLARITY_STEADY_LOW);
  ASSERT_EQ(USART1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_set_clock_polarity(USART1, USART_CLOCK_POLARITY_STEADY_LOW);
  ASSERT_EQ(USART1->CR2, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_clock(void)
{
  USART1->CR2 = 0;
  usart_clock_enable(USART1);
  ASSERT_EQ(USART1->CR2, (1u << 11));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(1u << 11);
  usart_clock_enable(USART1);
  ASSERT_EQ(USART1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = (1u << 11);
  usart_clock_disable(USART1);
  ASSERT_EQ(USART1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_clock_disable(USART1);
  ASSERT_EQ(USART1->CR2, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_set_stop_bits(void)
{
  // scope=self.reg='CR2', self.shift=12, self.mask='0x3', self.varsmap={'bits': 'USART_STOP_BITS_1BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  USART1->CR2 = 0;
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  ASSERT_EQ(USART1->CR2, (0b00u << 12));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(0x3u << 12);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  ASSERT_EQ(USART1->CR2, ~(0x3u << 12) | (0b00u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=12, self.mask='0x3', self.varsmap={'bits': 'USART_STOP_BITS_0DOT5_BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  USART1->CR2 = 0;
  usart_set_stop_bits(USART1, USART_STOP_BITS_0DOT5_BITS);
  ASSERT_EQ(USART1->CR2, (0b01u << 12));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(0x3u << 12);
  usart_set_stop_bits(USART1, USART_STOP_BITS_0DOT5_BITS);
  ASSERT_EQ(USART1->CR2, ~(0x3u << 12) | (0b01u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=12, self.mask='0x3', self.varsmap={'bits': 'USART_STOP_BITS_2BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  USART1->CR2 = 0;
  usart_set_stop_bits(USART1, USART_STOP_BITS_2BITS);
  ASSERT_EQ(USART1->CR2, (0b10u << 12));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(0x3u << 12);
  usart_set_stop_bits(USART1, USART_STOP_BITS_2BITS);
  ASSERT_EQ(USART1->CR2, ~(0x3u << 12) | (0b10u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=12, self.mask='0x3', self.varsmap={'bits': 'USART_STOP_BITS_1DOT5_BITS'}, self.value='0b11', self.ifdef=[], self.halt=False
  USART1->CR2 = 0;
  usart_set_stop_bits(USART1, USART_STOP_BITS_1DOT5_BITS);
  ASSERT_EQ(USART1->CR2, (0b11u << 12));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(0x3u << 12);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1DOT5_BITS);
  ASSERT_EQ(USART1->CR2, ~(0x3u << 12) | (0b11u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_usart_line_mode(void)
{
  USART1->CR2 = 0;
  usart_line_mode_enable(USART1);
  ASSERT_EQ(USART1->CR2, (1u << 14));
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = ~(1u << 14);
  usart_line_mode_enable(USART1);
  ASSERT_EQ(USART1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = (1u << 14);
  usart_line_mode_disable(USART1);
  ASSERT_EQ(USART1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR2 = 0xffffffff;
  usart_line_mode_disable(USART1);
  ASSERT_EQ(USART1->CR2, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_irda_mode(void)
{
  USART1->CR3 = 0;
  usart_irda_mode_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 1));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 1);
  usart_irda_mode_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 1);
  usart_irda_mode_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_irda_mode_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_irda_low_power(void)
{
  USART1->CR3 = 0;
  usart_irda_low_power_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 2));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 2);
  usart_irda_low_power_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 2);
  usart_irda_low_power_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_irda_low_power_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_half_duplex(void)
{
  USART1->CR3 = 0;
  usart_half_duplex_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 3));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 3);
  usart_half_duplex_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 3);
  usart_half_duplex_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_half_duplex_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_smartcard_nack(void)
{
  USART1->CR3 = 0;
  usart_smartcard_nack_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 4));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 4);
  usart_smartcard_nack_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 4);
  usart_smartcard_nack_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_smartcard_nack_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_smardcard_mode(void)
{
  USART1->CR3 = 0;
  usart_smardcard_mode_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 5));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 5);
  usart_smardcard_mode_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 5);
  usart_smardcard_mode_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_smardcard_mode_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_dma_reception(void)
{
  USART1->CR3 = 0;
  usart_dma_reception_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 6));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 6);
  usart_dma_reception_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 6);
  usart_dma_reception_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_dma_reception_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_dma_transmission(void)
{
  USART1->CR3 = 0;
  usart_dma_transmission_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 7));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 7);
  usart_dma_transmission_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 7);
  usart_dma_transmission_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_dma_transmission_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_rts(void)
{
  USART1->CR3 = 0;
  usart_rts_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 8));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 8);
  usart_rts_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 8);
  usart_rts_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_rts_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_usart_cts(void)
{
  USART1->CR3 = 0;
  usart_cts_enable(USART1);
  ASSERT_EQ(USART1->CR3, (1u << 9));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 9);
  usart_cts_enable(USART1);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 9);
  usart_cts_disable(USART1);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_cts_disable(USART1);
  ASSERT_EQ(USART1->CR3, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_USART_ONEBIT_SAMPLING)
void
test_usart_set_onebit_sampling_method(void)
{
  USART1->CR3 = 0;
  usart_set_onebit_sampling_method(USART1, USART_ONEBIT_SAMPLING_METHOD_ONE_SAMPLE);
  ASSERT_EQ(USART1->CR3, (1u << 11));
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = ~(1u << 11);
  usart_set_onebit_sampling_method(USART1, USART_ONEBIT_SAMPLING_METHOD_ONE_SAMPLE);
  ASSERT_EQ(USART1->CR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = (1u << 11);
  usart_set_onebit_sampling_method(USART1, USART_ONEBIT_SAMPLING_METHOD_THREE_SAMPLE);
  ASSERT_EQ(USART1->CR3, 0);
  ASSERT_FALSE(execution_halted());

  USART1->CR3 = 0xffffffff;
  usart_set_onebit_sampling_method(USART1, USART_ONEBIT_SAMPLING_METHOD_THREE_SAMPLE);
  ASSERT_EQ(USART1->CR3, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_usart_set_prescaler(void)
{
  USART1->GTPR = 0;
  usart_set_prescaler(USART1, 0);
  ASSERT_EQ(USART1->GTPR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  USART1->GTPR = 0xffffffff;
  usart_set_prescaler(USART1, 0);
  ASSERT_EQ(USART1->GTPR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  USART1->GTPR = 0;
  usart_set_prescaler(USART1, 0xff);
  ASSERT_EQ(USART1->GTPR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  USART1->GTPR = 0xffffffff;
  usart_set_prescaler(USART1, 0xff);
  ASSERT_EQ(USART1->GTPR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  USART1->GTPR = 0;
  usart_set_prescaler(USART1, 0x100);
  ASSERT_EQ(USART1->GTPR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  USART1->GTPR = 0xffffffff;
  usart_set_prescaler(USART1, 0x100);
  ASSERT_EQ(USART1->GTPR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_usart_set_guard_time(void)
{
  USART1->GTPR = 0;
  usart_set_guard_time(USART1, 0);
  ASSERT_EQ(USART1->GTPR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  USART1->GTPR = 0xffffffff;
  usart_set_guard_time(USART1, 0);
  ASSERT_EQ(USART1->GTPR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  USART1->GTPR = 0;
  usart_set_guard_time(USART1, 0xff);
  ASSERT_EQ(USART1->GTPR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  USART1->GTPR = 0xffffffff;
  usart_set_guard_time(USART1, 0xff);
  ASSERT_EQ(USART1->GTPR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  USART1->GTPR = 0;
  usart_set_guard_time(USART1, 0x100);
  ASSERT_EQ(USART1->GTPR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  USART1->GTPR = 0xffffffff;
  usart_set_guard_time(USART1, 0x100);
  ASSERT_EQ(USART1->GTPR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_usart_is_flag_set),
    TEST_FUNC(test_usart_flag_clear),
    TEST_FUNC(test_usart_data_read),
    TEST_FUNC(test_usart_send_byte),
    TEST_FUNC(test_usart_set_bittime),
    TEST_FUNC(test_usart_set_div_fraction),
    TEST_FUNC(test_usart_set_div_mantissa),
    TEST_FUNC(test_usart_send_break),
    TEST_FUNC(test_usart_set_receiver_mode),
    TEST_FUNC(test_usart_receiver),
    TEST_FUNC(test_usart_transmitter),
    TEST_FUNC(test_usart_interrupt),
    TEST_FUNC(test_usart_set_parity),
    TEST_FUNC(test_usart_parity_control),
    TEST_FUNC(test_usart_set_wakeup_method),
    TEST_FUNC(test_usart_set_word_length),
    TEST_FUNC(test_usart),
#if defined(STM32_USART_OVERSAMPLING)
    TEST_FUNC(test_usart_set_oversampling_mode),
#endif
    TEST_FUNC(test_usart_set_node_address),
    TEST_FUNC(test_usart_set_line_break_detection_length),
    TEST_FUNC(test_usart_last_bit_clock_pulse_output),
    TEST_FUNC(test_usart_set_clock_phase),
    TEST_FUNC(test_usart_set_clock_polarity),
    TEST_FUNC(test_usart_clock),
    TEST_FUNC(test_usart_set_stop_bits),
    TEST_FUNC(test_usart_line_mode),
    TEST_FUNC(test_usart_irda_mode),
    TEST_FUNC(test_usart_irda_low_power),
    TEST_FUNC(test_usart_half_duplex),
    TEST_FUNC(test_usart_smartcard_nack),
    TEST_FUNC(test_usart_smardcard_mode),
    TEST_FUNC(test_usart_dma_reception),
    TEST_FUNC(test_usart_dma_transmission),
    TEST_FUNC(test_usart_rts),
    TEST_FUNC(test_usart_cts),
#if defined(STM32_USART_ONEBIT_SAMPLING)
    TEST_FUNC(test_usart_set_onebit_sampling_method),
#endif
    TEST_FUNC(test_usart_set_prescaler),
    TEST_FUNC(test_usart_set_guard_time),
  };

  return TESTS_RUN(tests);
}
