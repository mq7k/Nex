#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/spdifrx/spdifrx_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  SPDIFRX = (struct spdifrx_registers_map*) membuf;
}

void
test_spdifrx_set_active_block(void)
{
  // scope=self.reg='CR', self.shift=0, self.mask='0x3', self.varsmap={'block': 'SPDIFRX_BLOCK_IDLE'}, self.value='0b00', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_active_block(SPDIFRX_BLOCK_IDLE);
  ASSERT_EQ(SPDIFRX->CR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 0);
  spdifrx_set_active_block(SPDIFRX_BLOCK_IDLE);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=0, self.mask='0x3', self.varsmap={'block': 'SPDIFRX_BLOCK_SYNC_ONLY'}, self.value='0b01', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_active_block(SPDIFRX_BLOCK_SYNC_ONLY);
  ASSERT_EQ(SPDIFRX->CR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 0);
  spdifrx_set_active_block(SPDIFRX_BLOCK_SYNC_ONLY);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=0, self.mask='0x3', self.varsmap={'block': 'SPDIFRX_BLOCK_RECEIVER'}, self.value='0b11', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_active_block(SPDIFRX_BLOCK_RECEIVER);
  ASSERT_EQ(SPDIFRX->CR, (0b11u << 0));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 0);
  spdifrx_set_active_block(SPDIFRX_BLOCK_RECEIVER);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 0) | (0b11u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_receiver_dma(void)
{
  SPDIFRX->CR = 0;
  spdifrx_receiver_dma_enable();
  ASSERT_EQ(SPDIFRX->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 2);
  spdifrx_receiver_dma_enable();
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 2);
  spdifrx_receiver_dma_disable();
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_receiver_dma_disable();
  ASSERT_EQ(SPDIFRX->CR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_set_audio_mode(void)
{
  SPDIFRX->CR = 0;
  spdifrx_set_audio_mode(SPDIFRX_AUDIO_MODE_STEREO);
  ASSERT_EQ(SPDIFRX->CR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 3);
  spdifrx_set_audio_mode(SPDIFRX_AUDIO_MODE_STEREO);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 3);
  spdifrx_set_audio_mode(SPDIFRX_AUDIO_MODE_MONO);
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_set_audio_mode(SPDIFRX_AUDIO_MODE_MONO);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_set_rx_data_format(void)
{
  // scope=self.reg='CR', self.shift=4, self.mask='0x3', self.varsmap={'format': 'SPDIFRX_RX_DATA_FORMAT_32BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_rx_data_format(SPDIFRX_RX_DATA_FORMAT_32BIT);
  ASSERT_EQ(SPDIFRX->CR, (0b10u << 4));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 4);
  spdifrx_set_rx_data_format(SPDIFRX_RX_DATA_FORMAT_32BIT);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 4) | (0b10u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=4, self.mask='0x3', self.varsmap={'format': 'SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED'}, self.value='0b01', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_rx_data_format(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(SPDIFRX->CR, (0b01u << 4));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 4);
  spdifrx_set_rx_data_format(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 4) | (0b01u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=4, self.mask='0x3', self.varsmap={'format': 'SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED'}, self.value='0b00', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_rx_data_format(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(SPDIFRX->CR, (0b00u << 4));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 4);
  spdifrx_set_rx_data_format(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 4) | (0b00u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_copy_bit(void)
{
  SPDIFRX->CR = 0;
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_PARITY);
  ASSERT_EQ(SPDIFRX->CR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 6);
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_PARITY);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 6);
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_PARITY);
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_PARITY);
  ASSERT_EQ(SPDIFRX->CR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->CR = 0;
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_VALIDITY);
  ASSERT_EQ(SPDIFRX->CR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 7);
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_VALIDITY);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 7);
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_VALIDITY);
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_VALIDITY);
  ASSERT_EQ(SPDIFRX->CR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->CR = 0;
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_CHANNEL_STATUS);
  ASSERT_EQ(SPDIFRX->CR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 8);
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_CHANNEL_STATUS);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 8);
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_CHANNEL_STATUS);
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_CHANNEL_STATUS);
  ASSERT_EQ(SPDIFRX->CR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->CR = 0;
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_PREABLE);
  ASSERT_EQ(SPDIFRX->CR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 9);
  spdifrx_copy_bit_enable(SPDIFRX_BIT_MASK_PREABLE);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 9);
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_PREABLE);
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_copy_bit_disable(SPDIFRX_BIT_MASK_PREABLE);
  ASSERT_EQ(SPDIFRX->CR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_dma_control_flow(void)
{
  SPDIFRX->CR = 0;
  spdifrx_dma_control_flow_enable();
  ASSERT_EQ(SPDIFRX->CR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 10);
  spdifrx_dma_control_flow_enable();
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 10);
  spdifrx_dma_control_flow_disable();
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_dma_control_flow_disable();
  ASSERT_EQ(SPDIFRX->CR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_set_channel_flow_control(void)
{
  SPDIFRX->CR = 0;
  spdifrx_set_channel_flow_control(SPDIFRX_CHANNELB);
  ASSERT_EQ(SPDIFRX->CR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 11);
  spdifrx_set_channel_flow_control(SPDIFRX_CHANNELB);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 11);
  spdifrx_set_channel_flow_control(SPDIFRX_CHANNELA);
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_set_channel_flow_control(SPDIFRX_CHANNELA);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_set_max_allowed_retries(void)
{
  // scope=self.reg='CR', self.shift=12, self.mask='0x3', self.varsmap={'retries': 'SPDIFRX_RETRIES_NORETRIES'}, self.value='0b00', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_NORETRIES);
  ASSERT_EQ(SPDIFRX->CR, (0b00u << 12));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 12);
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_NORETRIES);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 12) | (0b00u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=12, self.mask='0x3', self.varsmap={'retries': 'SPDIFRX_RETRIES_3RETRIES'}, self.value='0b01', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_3RETRIES);
  ASSERT_EQ(SPDIFRX->CR, (0b01u << 12));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 12);
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_3RETRIES);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 12) | (0b01u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=12, self.mask='0x3', self.varsmap={'retries': 'SPDIFRX_RETRIES_15RETRIES'}, self.value='0b10', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_15RETRIES);
  ASSERT_EQ(SPDIFRX->CR, (0b10u << 12));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 12);
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_15RETRIES);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 12) | (0b10u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=12, self.mask='0x3', self.varsmap={'retries': 'SPDIFRX_RETRIES_63RETRIES'}, self.value='0b11', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_63RETRIES);
  ASSERT_EQ(SPDIFRX->CR, (0b11u << 12));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x3u << 12);
  spdifrx_set_max_allowed_retries(SPDIFRX_RETRIES_63RETRIES);
  ASSERT_EQ(SPDIFRX->CR, ~(0x3u << 12) | (0b11u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_set_sync_policy(void)
{
  SPDIFRX->CR = 0;
  spdifrx_set_sync_policy(SPDIFRX_SYNC_POLICY_WAIT_IN);
  ASSERT_EQ(SPDIFRX->CR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(1u << 14);
  spdifrx_set_sync_policy(SPDIFRX_SYNC_POLICY_WAIT_IN);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = (1u << 14);
  spdifrx_set_sync_policy(SPDIFRX_SYNC_POLICY_DONT_WAIT);
  ASSERT_EQ(SPDIFRX->CR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = 0xffffffff;
  spdifrx_set_sync_policy(SPDIFRX_SYNC_POLICY_DONT_WAIT);
  ASSERT_EQ(SPDIFRX->CR, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_set_input(void)
{
  // scope=self.reg='CR', self.shift=16, self.mask='0x7', self.varsmap={'input': 'SPDIFRX_INPUT_IN1'}, self.value='0b000', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_input(SPDIFRX_INPUT_IN1);
  ASSERT_EQ(SPDIFRX->CR, (0b000u << 16));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x7u << 16);
  spdifrx_set_input(SPDIFRX_INPUT_IN1);
  ASSERT_EQ(SPDIFRX->CR, ~(0x7u << 16) | (0b000u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x7', self.varsmap={'input': 'SPDIFRX_INPUT_IN2'}, self.value='0b001', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_input(SPDIFRX_INPUT_IN2);
  ASSERT_EQ(SPDIFRX->CR, (0b001u << 16));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x7u << 16);
  spdifrx_set_input(SPDIFRX_INPUT_IN2);
  ASSERT_EQ(SPDIFRX->CR, ~(0x7u << 16) | (0b001u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x7', self.varsmap={'input': 'SPDIFRX_INPUT_IN3'}, self.value='0b010', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_input(SPDIFRX_INPUT_IN3);
  ASSERT_EQ(SPDIFRX->CR, (0b010u << 16));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x7u << 16);
  spdifrx_set_input(SPDIFRX_INPUT_IN3);
  ASSERT_EQ(SPDIFRX->CR, ~(0x7u << 16) | (0b010u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x7', self.varsmap={'input': 'SPDIFRX_INPUT_IN4'}, self.value='0b011', self.ifdef=[], self.halt=False
  SPDIFRX->CR = 0;
  spdifrx_set_input(SPDIFRX_INPUT_IN4);
  ASSERT_EQ(SPDIFRX->CR, (0b011u << 16));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CR = ~(0x7u << 16);
  spdifrx_set_input(SPDIFRX_INPUT_IN4);
  ASSERT_EQ(SPDIFRX->CR, ~(0x7u << 16) | (0b011u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_interrupt(void)
{
  SPDIFRX->IMR = 0;
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_RXNE);
  ASSERT_EQ(SPDIFRX->IMR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = ~(1u << 0);
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_RXNE);
  ASSERT_EQ(SPDIFRX->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = (1u << 0);
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_RXNE);
  ASSERT_EQ(SPDIFRX->IMR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = 0xffffffff;
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_RXNE);
  ASSERT_EQ(SPDIFRX->IMR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IMR = 0;
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_CTRL_BUF_READY);
  ASSERT_EQ(SPDIFRX->IMR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = ~(1u << 1);
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_CTRL_BUF_READY);
  ASSERT_EQ(SPDIFRX->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = (1u << 1);
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_CTRL_BUF_READY);
  ASSERT_EQ(SPDIFRX->IMR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = 0xffffffff;
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_CTRL_BUF_READY);
  ASSERT_EQ(SPDIFRX->IMR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IMR = 0;
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_PARITY_ERR);
  ASSERT_EQ(SPDIFRX->IMR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = ~(1u << 2);
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_PARITY_ERR);
  ASSERT_EQ(SPDIFRX->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = (1u << 2);
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_PARITY_ERR);
  ASSERT_EQ(SPDIFRX->IMR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = 0xffffffff;
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_PARITY_ERR);
  ASSERT_EQ(SPDIFRX->IMR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IMR = 0;
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_OVERRUN_ERR);
  ASSERT_EQ(SPDIFRX->IMR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = ~(1u << 3);
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_OVERRUN_ERR);
  ASSERT_EQ(SPDIFRX->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = (1u << 3);
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_OVERRUN_ERR);
  ASSERT_EQ(SPDIFRX->IMR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = 0xffffffff;
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_OVERRUN_ERR);
  ASSERT_EQ(SPDIFRX->IMR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IMR = 0;
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_SYNC_DETECTED);
  ASSERT_EQ(SPDIFRX->IMR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = ~(1u << 4);
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_SYNC_DETECTED);
  ASSERT_EQ(SPDIFRX->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = (1u << 4);
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_SYNC_DETECTED);
  ASSERT_EQ(SPDIFRX->IMR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = 0xffffffff;
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_SYNC_DETECTED);
  ASSERT_EQ(SPDIFRX->IMR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IMR = 0;
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_SYNC_COMPLETE);
  ASSERT_EQ(SPDIFRX->IMR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = ~(1u << 5);
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_SYNC_COMPLETE);
  ASSERT_EQ(SPDIFRX->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = (1u << 5);
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_SYNC_COMPLETE);
  ASSERT_EQ(SPDIFRX->IMR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = 0xffffffff;
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_SYNC_COMPLETE);
  ASSERT_EQ(SPDIFRX->IMR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IMR = 0;
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_SERIAL_INTERFACE_ERR);
  ASSERT_EQ(SPDIFRX->IMR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = ~(1u << 6);
  spdifrx_interrupt_enable(SPDIFRX_INTERRUPT_SERIAL_INTERFACE_ERR);
  ASSERT_EQ(SPDIFRX->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = (1u << 6);
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_SERIAL_INTERFACE_ERR);
  ASSERT_EQ(SPDIFRX->IMR, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IMR = 0xffffffff;
  spdifrx_interrupt_disable(SPDIFRX_INTERRUPT_SERIAL_INTERFACE_ERR);
  ASSERT_EQ(SPDIFRX->IMR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_is_flag_set(void)
{
  u32 res;

  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_RXNE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 0);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_RXNE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 0);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_RXNE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_RXNE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_CTRL_BUF_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 1);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_CTRL_BUF_READY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 1);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_CTRL_BUF_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_CTRL_BUF_READY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 2);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_PARITY_ERR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 2);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_PARITY_ERR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_OVERRUN_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 3);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_OVERRUN_ERR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 3);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_OVERRUN_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_OVERRUN_ERR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_DETECTED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 4);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_DETECTED);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 4);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_DETECTED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_DETECTED);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 5);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 5);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_FRAMING_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 6);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_FRAMING_ERR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 6);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_FRAMING_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_FRAMING_ERR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 7);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_ERR);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 7);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_SYNC_ERR);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  SPDIFRX->SR = 0;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_TIMEOUT_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = (1u << 8);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_TIMEOUT_ERR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(1u << 8);
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_TIMEOUT_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0xffffffff;
  res = spdifrx_is_flag_set(SPDRFRX_FLAG_TIMEOUT_ERR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_get_5symbols_clock_count(void)
{
  u32 res;

  // read_bits
  SPDIFRX->SR = 0;
  res = spdifrx_get_5symbols_clock_count();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = ~(0x7fffu << 16);
  res = spdifrx_get_5symbols_clock_count();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->SR = 0x7fffu << 16;
  res = spdifrx_get_5symbols_clock_count();
  ASSERT_EQ(res, 0x7fff);
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_flag_clear(void)
{
  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_RXNE);
  ASSERT_EQ(SPDIFRX->IFCR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->IFCR = ~(1u << 0);
  spdifrx_flag_clear(SPDRFRX_FLAG_RXNE);
  ASSERT_EQ(SPDIFRX->IFCR, ~(1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_CTRL_BUF_READY);
  ASSERT_EQ(SPDIFRX->IFCR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->IFCR = ~(1u << 1);
  spdifrx_flag_clear(SPDRFRX_FLAG_CTRL_BUF_READY);
  ASSERT_EQ(SPDIFRX->IFCR, ~(1u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_PARITY_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IFCR = ~(1u << 2);
  spdifrx_flag_clear(SPDRFRX_FLAG_PARITY_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_OVERRUN_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IFCR = ~(1u << 3);
  spdifrx_flag_clear(SPDRFRX_FLAG_OVERRUN_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_SYNC_DETECTED);
  ASSERT_EQ(SPDIFRX->IFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IFCR = ~(1u << 4);
  spdifrx_flag_clear(SPDRFRX_FLAG_SYNC_DETECTED);
  ASSERT_EQ(SPDIFRX->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_SYNC_COMPLETE);
  ASSERT_EQ(SPDIFRX->IFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SPDIFRX->IFCR = ~(1u << 5);
  spdifrx_flag_clear(SPDRFRX_FLAG_SYNC_COMPLETE);
  ASSERT_EQ(SPDIFRX->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_FRAMING_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->IFCR = ~(1u << 6);
  spdifrx_flag_clear(SPDRFRX_FLAG_FRAMING_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, ~(1u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_SYNC_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->IFCR = ~(1u << 7);
  spdifrx_flag_clear(SPDRFRX_FLAG_SYNC_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, ~(1u << 7));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SPDIFRX->IFCR = 0;
  spdifrx_flag_clear(SPDRFRX_FLAG_TIMEOUT_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->IFCR = ~(1u << 8);
  spdifrx_flag_clear(SPDRFRX_FLAG_TIMEOUT_ERR);
  ASSERT_EQ(SPDIFRX->IFCR, ~(1u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_spdifrx_get_recv_bit(void)
{
  u32 res;

  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->DR = ~(0x1u << 0);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->DR = ~(0x1u << 1);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->DR = ~(0x1u << 2);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SPDIFRX->DR = ~(0x1u << 3);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_32BIT, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 0);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 1);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 1;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0x1u << 1);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 2);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 2;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 3);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 3;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0x1u << 3);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 24);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 24;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_PARITY_ERR);
  ASSERT_EQ(res, 0x1u << 24);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 25);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 25;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_VALIDITY);
  ASSERT_EQ(res, 0x1u << 25);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 26);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 26;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_USER);
  ASSERT_EQ(res, 0x1u << 26);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0x1u << 27);
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0x1u << 27;
  res = spdifrx_get_recv_bit(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED, SPDIFRX_RECV_BIT_CHANNEL_STATUS);
  ASSERT_EQ(res, 0x1u << 27);
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_get_recv_preamble(void)
{
  u32 res;

  // read_reg
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_preamble(SPDIFRX_RX_DATA_FORMAT_32BIT);
  ASSERT_EQ(res, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // read_bits
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_preamble(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0u << 4);
  res = spdifrx_get_recv_preamble(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0u << 4;
  res = spdifrx_get_recv_preamble(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());


  // read_bits
  SPDIFRX->DR = 0;
  res = spdifrx_get_recv_preamble(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0u << 28);
  res = spdifrx_get_recv_preamble(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0u << 28;
  res = spdifrx_get_recv_preamble(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_get_data(void)
{
  u32 res;

  // read_reg
  SPDIFRX->DR = 0;
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_32BIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0xffffffff;
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_32BIT);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  SPDIFRX->DR = 0;
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0xffffffu << 8);
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0xffffffu << 8;
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_LEFT_ALIGNED);
  ASSERT_EQ(res, 0xffffff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  SPDIFRX->DR = 0;
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = ~(0xffffffu << 0);
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DR = 0xffffffu << 0;
  res = spdifrx_get_data(SPDIFRX_RX_DATA_FORMAT_RIGHT_ALIGNED);
  ASSERT_EQ(res, 0xffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_get_user_data_info(void)
{
  u32 res;

  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 0);
  res = spdifrx_get_user_data_info(0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 0;
  res = spdifrx_get_user_data_info(0);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 1);
  res = spdifrx_get_user_data_info(1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 1;
  res = spdifrx_get_user_data_info(1);
  ASSERT_EQ(res, 0x1u << 1);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 2);
  res = spdifrx_get_user_data_info(2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 2;
  res = spdifrx_get_user_data_info(2);
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 3);
  res = spdifrx_get_user_data_info(3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 3;
  res = spdifrx_get_user_data_info(3);
  ASSERT_EQ(res, 0x1u << 3);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 4);
  res = spdifrx_get_user_data_info(4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 4;
  res = spdifrx_get_user_data_info(4);
  ASSERT_EQ(res, 0x1u << 4);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 5);
  res = spdifrx_get_user_data_info(5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 5;
  res = spdifrx_get_user_data_info(5);
  ASSERT_EQ(res, 0x1u << 5);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 6);
  res = spdifrx_get_user_data_info(6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 6;
  res = spdifrx_get_user_data_info(6);
  ASSERT_EQ(res, 0x1u << 6);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 7);
  res = spdifrx_get_user_data_info(7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 7;
  res = spdifrx_get_user_data_info(7);
  ASSERT_EQ(res, 0x1u << 7);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(8);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 8);
  res = spdifrx_get_user_data_info(8);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 8;
  res = spdifrx_get_user_data_info(8);
  ASSERT_EQ(res, 0x1u << 8);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(9);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 9);
  res = spdifrx_get_user_data_info(9);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 9;
  res = spdifrx_get_user_data_info(9);
  ASSERT_EQ(res, 0x1u << 9);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(10);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 10);
  res = spdifrx_get_user_data_info(10);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 10;
  res = spdifrx_get_user_data_info(10);
  ASSERT_EQ(res, 0x1u << 10);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(11);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 11);
  res = spdifrx_get_user_data_info(11);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 11;
  res = spdifrx_get_user_data_info(11);
  ASSERT_EQ(res, 0x1u << 11);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(12);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 12);
  res = spdifrx_get_user_data_info(12);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 12;
  res = spdifrx_get_user_data_info(12);
  ASSERT_EQ(res, 0x1u << 12);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(13);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 13);
  res = spdifrx_get_user_data_info(13);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 13;
  res = spdifrx_get_user_data_info(13);
  ASSERT_EQ(res, 0x1u << 13);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(14);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 14);
  res = spdifrx_get_user_data_info(14);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 14;
  res = spdifrx_get_user_data_info(14);
  ASSERT_EQ(res, 0x1u << 14);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_user_data_info(15);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 15);
  res = spdifrx_get_user_data_info(15);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 15;
  res = spdifrx_get_user_data_info(15);
  ASSERT_EQ(res, 0x1u << 15);
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_get_channel_status_info(void)
{
  u32 res;

  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 16);
  res = spdifrx_get_channel_status_info(0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 16;
  res = spdifrx_get_channel_status_info(0);
  ASSERT_EQ(res, 0x1u << 16);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 17);
  res = spdifrx_get_channel_status_info(1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 17;
  res = spdifrx_get_channel_status_info(1);
  ASSERT_EQ(res, 0x1u << 17);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 18);
  res = spdifrx_get_channel_status_info(2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 18;
  res = spdifrx_get_channel_status_info(2);
  ASSERT_EQ(res, 0x1u << 18);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 19);
  res = spdifrx_get_channel_status_info(3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 19;
  res = spdifrx_get_channel_status_info(3);
  ASSERT_EQ(res, 0x1u << 19);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 20);
  res = spdifrx_get_channel_status_info(4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 20;
  res = spdifrx_get_channel_status_info(4);
  ASSERT_EQ(res, 0x1u << 20);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 21);
  res = spdifrx_get_channel_status_info(5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 21;
  res = spdifrx_get_channel_status_info(5);
  ASSERT_EQ(res, 0x1u << 21);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 22);
  res = spdifrx_get_channel_status_info(6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 22;
  res = spdifrx_get_channel_status_info(6);
  ASSERT_EQ(res, 0x1u << 22);
  ASSERT_FALSE(execution_halted());


  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_channel_status_info(7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 23);
  res = spdifrx_get_channel_status_info(7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 23;
  res = spdifrx_get_channel_status_info(7);
  ASSERT_EQ(res, 0x1u << 23);
  ASSERT_FALSE(execution_halted());


}

void
test_spdifrx_get_start_of_block(void)
{
  u32 res;

  // read_bit
  SPDIFRX->CSR = 0;
  res = spdifrx_get_start_of_block();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = ~(0x1u << 24);
  res = spdifrx_get_start_of_block();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->CSR = 0x1u << 24;
  res = spdifrx_get_start_of_block();
  ASSERT_EQ(res, 0x1u << 24);
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_get_threshold_high(void)
{
  u32 res;

  // read_bits
  SPDIFRX->DIR = 0;
  res = spdifrx_get_threshold_high();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DIR = ~(0x1fffu << 0);
  res = spdifrx_get_threshold_high();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DIR = 0x1fffu << 0;
  res = spdifrx_get_threshold_high();
  ASSERT_EQ(res, 0x1fff);
  ASSERT_FALSE(execution_halted());

}

void
test_spdifrx_get_threshold_low(void)
{
  u32 res;

  // read_bits
  SPDIFRX->DIR = 0;
  res = spdifrx_get_threshold_low();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DIR = ~(0x1fffu << 16);
  res = spdifrx_get_threshold_low();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SPDIFRX->DIR = 0x1fffu << 16;
  res = spdifrx_get_threshold_low();
  ASSERT_EQ(res, 0x1fff);
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_spdifrx_set_active_block),
    TEST_FUNC(test_spdifrx_receiver_dma),
    TEST_FUNC(test_spdifrx_set_audio_mode),
    TEST_FUNC(test_spdifrx_set_rx_data_format),
    TEST_FUNC(test_spdifrx_copy_bit),
    TEST_FUNC(test_spdifrx_dma_control_flow),
    TEST_FUNC(test_spdifrx_set_channel_flow_control),
    TEST_FUNC(test_spdifrx_set_max_allowed_retries),
    TEST_FUNC(test_spdifrx_set_sync_policy),
    TEST_FUNC(test_spdifrx_set_input),
    TEST_FUNC(test_spdifrx_interrupt),
    TEST_FUNC(test_spdifrx_is_flag_set),
    TEST_FUNC(test_spdifrx_get_5symbols_clock_count),
    TEST_FUNC(test_spdifrx_flag_clear),
    TEST_FUNC(test_spdifrx_get_recv_bit),
    TEST_FUNC(test_spdifrx_get_recv_preamble),
    TEST_FUNC(test_spdifrx_get_data),
    TEST_FUNC(test_spdifrx_get_user_data_info),
    TEST_FUNC(test_spdifrx_get_channel_status_info),
    TEST_FUNC(test_spdifrx_get_start_of_block),
    TEST_FUNC(test_spdifrx_get_threshold_high),
    TEST_FUNC(test_spdifrx_get_threshold_low),
  };

  return TESTS_RUN(tests);
}
