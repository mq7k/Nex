#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/sai/sai_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  SAI1A = (struct sai_registers_map*) membuf;
}

#if defined(STM32_SAI_GCR)
void
test_sai_set_sync_output(void)
{
  // scope=self.reg='GCR', self.shift=4, self.mask='0x3', self.varsmap={'sync': 'SAI_SYNC_OUT_NOSYNC'}, self.value='0b00', self.ifdef=[], self.halt=False
  SAI1A->GCR = 0;
  sai_set_sync_output(SAI1A, SAI_SYNC_OUT_NOSYNC);
  ASSERT_EQ(SAI1A->GCR, (0b00u << 4));
  ASSERT_FALSE(execution_halted());

  SAI1A->GCR = ~(0x3u << 4);
  sai_set_sync_output(SAI1A, SAI_SYNC_OUT_NOSYNC);
  ASSERT_EQ(SAI1A->GCR, ~(0x3u << 4) | (0b00u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='GCR', self.shift=4, self.mask='0x3', self.varsmap={'sync': 'SAI_SYNC_OUT_SYNC_BLOCKA'}, self.value='0b01', self.ifdef=[], self.halt=False
  SAI1A->GCR = 0;
  sai_set_sync_output(SAI1A, SAI_SYNC_OUT_SYNC_BLOCKA);
  ASSERT_EQ(SAI1A->GCR, (0b01u << 4));
  ASSERT_FALSE(execution_halted());

  SAI1A->GCR = ~(0x3u << 4);
  sai_set_sync_output(SAI1A, SAI_SYNC_OUT_SYNC_BLOCKA);
  ASSERT_EQ(SAI1A->GCR, ~(0x3u << 4) | (0b01u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='GCR', self.shift=4, self.mask='0x3', self.varsmap={'sync': 'SAI_SYNC_OUT_SYNC_BLOCKB'}, self.value='0b10', self.ifdef=[], self.halt=False
  SAI1A->GCR = 0;
  sai_set_sync_output(SAI1A, SAI_SYNC_OUT_SYNC_BLOCKB);
  ASSERT_EQ(SAI1A->GCR, (0b10u << 4));
  ASSERT_FALSE(execution_halted());

  SAI1A->GCR = ~(0x3u << 4);
  sai_set_sync_output(SAI1A, SAI_SYNC_OUT_SYNC_BLOCKB);
  ASSERT_EQ(SAI1A->GCR, ~(0x3u << 4) | (0b10u << 4));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_sai_set_block_mode(void)
{
  // scope=self.reg='CR1', self.shift=0, self.mask='0x3', self.varsmap={'mode': 'SAI_BLOCK_MODE_MASTER_TX'}, self.value='0b00', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_MASTER_TX);
  ASSERT_EQ(SAI1A->CR1, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 0);
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_MASTER_TX);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=0, self.mask='0x3', self.varsmap={'mode': 'SAI_BLOCK_MODE_MASTER_RX'}, self.value='0b01', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_MASTER_RX);
  ASSERT_EQ(SAI1A->CR1, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 0);
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_MASTER_RX);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=0, self.mask='0x3', self.varsmap={'mode': 'SAI_BLOCK_MODE_SLAVE_TX'}, self.value='0b10', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_SLAVE_TX);
  ASSERT_EQ(SAI1A->CR1, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 0);
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_SLAVE_TX);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=0, self.mask='0x3', self.varsmap={'mode': 'SAI_BLOCK_MODE_SLAVE_RX'}, self.value='0b11', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_SLAVE_RX);
  ASSERT_EQ(SAI1A->CR1, (0b11u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 0);
  sai_set_block_mode(SAI1A, SAI_BLOCK_MODE_SLAVE_RX);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 0) | (0b11u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_set_protocol(void)
{
  // scope=self.reg='CR1', self.shift=2, self.mask='0x3', self.varsmap={'protocol': 'SAI_PROTOCOL_FREE'}, self.value='0b00', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_protocol(SAI1A, SAI_PROTOCOL_FREE);
  ASSERT_EQ(SAI1A->CR1, (0b00u << 2));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 2);
  sai_set_protocol(SAI1A, SAI_PROTOCOL_FREE);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 2) | (0b00u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=2, self.mask='0x3', self.varsmap={'protocol': 'SAI_PROTOCOL_SPDIF'}, self.value='0b01', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_protocol(SAI1A, SAI_PROTOCOL_SPDIF);
  ASSERT_EQ(SAI1A->CR1, (0b01u << 2));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 2);
  sai_set_protocol(SAI1A, SAI_PROTOCOL_SPDIF);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 2) | (0b01u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=2, self.mask='0x3', self.varsmap={'protocol': 'SAI_PROTOCOL_AC97'}, self.value='0b10', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_protocol(SAI1A, SAI_PROTOCOL_AC97);
  ASSERT_EQ(SAI1A->CR1, (0b10u << 2));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 2);
  sai_set_protocol(SAI1A, SAI_PROTOCOL_AC97);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 2) | (0b10u << 2));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_set_data_size(void)
{
  // scope=self.reg='CR1', self.shift=5, self.mask='0x7', self.varsmap={'size': 'SAI_DATA_SIZE_8BIT'}, self.value='0b010', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_8BIT);
  ASSERT_EQ(SAI1A->CR1, (0b010u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x7u << 5);
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_8BIT);
  ASSERT_EQ(SAI1A->CR1, ~(0x7u << 5) | (0b010u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x7', self.varsmap={'size': 'SAI_DATA_SIZE_10BIT'}, self.value='0b011', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_10BIT);
  ASSERT_EQ(SAI1A->CR1, (0b011u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x7u << 5);
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_10BIT);
  ASSERT_EQ(SAI1A->CR1, ~(0x7u << 5) | (0b011u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x7', self.varsmap={'size': 'SAI_DATA_SIZE_16BIT'}, self.value='0b100', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_16BIT);
  ASSERT_EQ(SAI1A->CR1, (0b100u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x7u << 5);
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_16BIT);
  ASSERT_EQ(SAI1A->CR1, ~(0x7u << 5) | (0b100u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x7', self.varsmap={'size': 'SAI_DATA_SIZE_20BIT'}, self.value='0b101', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_20BIT);
  ASSERT_EQ(SAI1A->CR1, (0b101u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x7u << 5);
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_20BIT);
  ASSERT_EQ(SAI1A->CR1, ~(0x7u << 5) | (0b101u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x7', self.varsmap={'size': 'SAI_DATA_SIZE_24BIT'}, self.value='0b110', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_24BIT);
  ASSERT_EQ(SAI1A->CR1, (0b110u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x7u << 5);
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_24BIT);
  ASSERT_EQ(SAI1A->CR1, ~(0x7u << 5) | (0b110u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x7', self.varsmap={'size': 'SAI_DATA_SIZE_32BIT'}, self.value='0b111', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_32BIT);
  ASSERT_EQ(SAI1A->CR1, (0b111u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x7u << 5);
  sai_set_data_size(SAI1A, SAI_DATA_SIZE_32BIT);
  ASSERT_EQ(SAI1A->CR1, ~(0x7u << 5) | (0b111u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_set_endianess(void)
{
  SAI1A->CR1 = 0;
  sai_set_endianess(SAI1A, SAI_ENDIANESS_LSB_FIRST);
  ASSERT_EQ(SAI1A->CR1, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(1u << 8);
  sai_set_endianess(SAI1A, SAI_ENDIANESS_LSB_FIRST);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = (1u << 8);
  sai_set_endianess(SAI1A, SAI_ENDIANESS_MSB_FIRST);
  ASSERT_EQ(SAI1A->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_set_endianess(SAI1A, SAI_ENDIANESS_MSB_FIRST);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff & ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_clock_strobe(void)
{
  SAI1A->CR1 = 0;
  sai_set_clock_strobe(SAI1A, SAI_CLOCK_STROBE_GENERATE_ON_FALLING);
  ASSERT_EQ(SAI1A->CR1, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(1u << 9);
  sai_set_clock_strobe(SAI1A, SAI_CLOCK_STROBE_GENERATE_ON_FALLING);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = (1u << 9);
  sai_set_clock_strobe(SAI1A, SAI_CLOCK_STROBE_GENERATE_ON_RISING);
  ASSERT_EQ(SAI1A->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_set_clock_strobe(SAI1A, SAI_CLOCK_STROBE_GENERATE_ON_RISING);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_subblock_sync(void)
{
  // scope=self.reg='CR1', self.shift=10, self.mask='0x3', self.varsmap={'sync': 'SAI_SUBBLOCK_SYNC_ASYNC'}, self.value='0b00', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_subblock_sync(SAI1A, SAI_SUBBLOCK_SYNC_ASYNC);
  ASSERT_EQ(SAI1A->CR1, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 10);
  sai_set_subblock_sync(SAI1A, SAI_SUBBLOCK_SYNC_ASYNC);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=10, self.mask='0x3', self.varsmap={'sync': 'SAI_SUBBLOCK_SYNC_SYNC_INTERNAL'}, self.value='0b01', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_subblock_sync(SAI1A, SAI_SUBBLOCK_SYNC_SYNC_INTERNAL);
  ASSERT_EQ(SAI1A->CR1, (0b01u << 10));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 10);
  sai_set_subblock_sync(SAI1A, SAI_SUBBLOCK_SYNC_SYNC_INTERNAL);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 10) | (0b01u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=10, self.mask='0x3', self.varsmap={'sync': 'SAI_SUBBLOCK_SYNC_SYNC_EXTERNAL'}, self.value='0b10', self.ifdef=[], self.halt=False
  SAI1A->CR1 = 0;
  sai_set_subblock_sync(SAI1A, SAI_SUBBLOCK_SYNC_SYNC_EXTERNAL);
  ASSERT_EQ(SAI1A->CR1, (0b10u << 10));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(0x3u << 10);
  sai_set_subblock_sync(SAI1A, SAI_SUBBLOCK_SYNC_SYNC_EXTERNAL);
  ASSERT_EQ(SAI1A->CR1, ~(0x3u << 10) | (0b10u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_set_audio_mode(void)
{
  SAI1A->CR1 = 0;
  sai_set_audio_mode(SAI1A, SAI_AUDIO_MODE_MONO);
  ASSERT_EQ(SAI1A->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(1u << 12);
  sai_set_audio_mode(SAI1A, SAI_AUDIO_MODE_MONO);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = (1u << 12);
  sai_set_audio_mode(SAI1A, SAI_AUDIO_MODE_STEREO);
  ASSERT_EQ(SAI1A->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_set_audio_mode(SAI1A, SAI_AUDIO_MODE_STEREO);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff & ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_outdrive(void)
{
  SAI1A->CR1 = 0;
  sai_set_outdrive(SAI1A, SAI_OUTDRIVE_AUTO);
  ASSERT_EQ(SAI1A->CR1, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(1u << 13);
  sai_set_outdrive(SAI1A, SAI_OUTDRIVE_AUTO);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = (1u << 13);
  sai_set_outdrive(SAI1A, SAI_OUTDRIVE_MANUAL);
  ASSERT_EQ(SAI1A->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_set_outdrive(SAI1A, SAI_OUTDRIVE_MANUAL);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff & ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_audio_block(void)
{
  SAI1A->CR1 = 0;
  sai_audio_block_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, (1u << 16));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(1u << 16);
  sai_audio_block_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = (1u << 16);
  sai_audio_block_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_audio_block_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_dma(void)
{
  SAI1A->CR1 = 0;
  sai_dma_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, (1u << 17));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(1u << 17);
  sai_dma_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = (1u << 17);
  sai_dma_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_dma_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_clock_divider(void)
{
  SAI1A->CR1 = 0;
  sai_clock_divider_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, (1u << 19));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = ~(1u << 19);
  sai_clock_divider_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = (1u << 19);
  sai_clock_divider_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_clock_divider_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR1, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_clock_divider(void)
{
  SAI1A->CR1 = 0;
  sai_set_clock_divider(SAI1A, 0);
  ASSERT_EQ(SAI1A->CR1, 0u << 20);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_set_clock_divider(SAI1A, 0);
  ASSERT_EQ(SAI1A->CR1, ~(0xfu << 20) | (0u << 20));
  ASSERT_FALSE(execution_halted());


  SAI1A->CR1 = 0;
  sai_set_clock_divider(SAI1A, 0xf);
  ASSERT_EQ(SAI1A->CR1, 0xfu << 20);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR1 = 0xffffffff;
  sai_set_clock_divider(SAI1A, 0xf);
  ASSERT_EQ(SAI1A->CR1, ~(0xfu << 20) | (0xfu << 20));
  ASSERT_FALSE(execution_halted());


  SAI1A->CR1 = 0;
  sai_set_clock_divider(SAI1A, 0x10);
  ASSERT_EQ(SAI1A->CR1, 0x10u << 20);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SAI1A->CR1 = 0xffffffff;
  sai_set_clock_divider(SAI1A, 0x10);
  ASSERT_EQ(SAI1A->CR1, ~(0xfu << 20) | (0x10u << 20));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_sai_set_fifo_threshold(void)
{
  // scope=self.reg='CR2', self.shift=0, self.mask='0x7', self.varsmap={'threshold': 'SAI_FIFO_THRESHOLD_EMPTY'}, self.value='0b000', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_EMPTY);
  ASSERT_EQ(SAI1A->CR2, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x7u << 0);
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_EMPTY);
  ASSERT_EQ(SAI1A->CR2, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=0, self.mask='0x7', self.varsmap={'threshold': 'SAI_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b001', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(SAI1A->CR2, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x7u << 0);
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(SAI1A->CR2, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=0, self.mask='0x7', self.varsmap={'threshold': 'SAI_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b010', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(SAI1A->CR2, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x7u << 0);
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(SAI1A->CR2, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=0, self.mask='0x7', self.varsmap={'threshold': 'SAI_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b011', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(SAI1A->CR2, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x7u << 0);
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(SAI1A->CR2, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=0, self.mask='0x7', self.varsmap={'threshold': 'SAI_FIFO_THRESHOLD_FULL'}, self.value='0b100', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(SAI1A->CR2, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x7u << 0);
  sai_set_fifo_threshold(SAI1A, SAI_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(SAI1A->CR2, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_fifo_flush(void)
{
  SAI1A->CR2 = 0;
  sai_fifo_flush(SAI1A);
  ASSERT_EQ(SAI1A->CR2, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(1u << 3);
  sai_fifo_flush(SAI1A);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_tristate_management(void)
{
  SAI1A->CR2 = 0;
  sai_set_tristate_management(SAI1A, SAI_TRISTATE_MANAGEMENT_RELEASE);
  ASSERT_EQ(SAI1A->CR2, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(1u << 4);
  sai_set_tristate_management(SAI1A, SAI_TRISTATE_MANAGEMENT_RELEASE);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = (1u << 4);
  sai_set_tristate_management(SAI1A, SAI_TRISTATE_MANAGEMENT_KEEP_DRIVE);
  ASSERT_EQ(SAI1A->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = 0xffffffff;
  sai_set_tristate_management(SAI1A, SAI_TRISTATE_MANAGEMENT_KEEP_DRIVE);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_mute(void)
{
  SAI1A->CR2 = 0;
  sai_mute_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR2, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(1u << 5);
  sai_mute_enable(SAI1A);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = (1u << 5);
  sai_mute_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = 0xffffffff;
  sai_mute_disable(SAI1A);
  ASSERT_EQ(SAI1A->CR2, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_mute_value(void)
{
  SAI1A->CR2 = 0;
  sai_set_mute_value(SAI1A, SAI_MUTE_VALUE_LAST);
  ASSERT_EQ(SAI1A->CR2, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(1u << 6);
  sai_set_mute_value(SAI1A, SAI_MUTE_VALUE_LAST);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = (1u << 6);
  sai_set_mute_value(SAI1A, SAI_MUTE_VALUE_BIT_VALUE0);
  ASSERT_EQ(SAI1A->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = 0xffffffff;
  sai_set_mute_value(SAI1A, SAI_MUTE_VALUE_BIT_VALUE0);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff & ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_mute_counter(void)
{
  SAI1A->CR2 = 0;
  sai_set_mute_counter(SAI1A, 0);
  ASSERT_EQ(SAI1A->CR2, 0u << 7);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = 0xffffffff;
  sai_set_mute_counter(SAI1A, 0);
  ASSERT_EQ(SAI1A->CR2, ~(0x3fu << 7) | (0u << 7));
  ASSERT_FALSE(execution_halted());


  SAI1A->CR2 = 0;
  sai_set_mute_counter(SAI1A, 0x3f);
  ASSERT_EQ(SAI1A->CR2, 0x3fu << 7);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = 0xffffffff;
  sai_set_mute_counter(SAI1A, 0x3f);
  ASSERT_EQ(SAI1A->CR2, ~(0x3fu << 7) | (0x3fu << 7));
  ASSERT_FALSE(execution_halted());


  SAI1A->CR2 = 0;
  sai_set_mute_counter(SAI1A, 0x40);
  ASSERT_EQ(SAI1A->CR2, 0x40u << 7);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SAI1A->CR2 = 0xffffffff;
  sai_set_mute_counter(SAI1A, 0x40);
  ASSERT_EQ(SAI1A->CR2, ~(0x3fu << 7) | (0x40u << 7));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_sai_set_bit_complement(void)
{
  SAI1A->CR2 = 0;
  sai_set_bit_complement(SAI1A, SAI_BIT_COMPLEMENT2);
  ASSERT_EQ(SAI1A->CR2, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(1u << 13);
  sai_set_bit_complement(SAI1A, SAI_BIT_COMPLEMENT2);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = (1u << 13);
  sai_set_bit_complement(SAI1A, SAI_BIT_COMPLEMENT1);
  ASSERT_EQ(SAI1A->CR2, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = 0xffffffff;
  sai_set_bit_complement(SAI1A, SAI_BIT_COMPLEMENT1);
  ASSERT_EQ(SAI1A->CR2, 0xffffffff & ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_companding_mode(void)
{
  // scope=self.reg='CR2', self.shift=14, self.mask='0x3', self.varsmap={'mode': 'SAI_COMPANDING_MODE_NOCOMPANDING'}, self.value='0b00', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_companding_mode(SAI1A, SAI_COMPANDING_MODE_NOCOMPANDING);
  ASSERT_EQ(SAI1A->CR2, (0b00u << 14));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x3u << 14);
  sai_set_companding_mode(SAI1A, SAI_COMPANDING_MODE_NOCOMPANDING);
  ASSERT_EQ(SAI1A->CR2, ~(0x3u << 14) | (0b00u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=14, self.mask='0x3', self.varsmap={'mode': 'SAI_COMPANDING_MODE_uLAW_ALGO'}, self.value='0b10', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_companding_mode(SAI1A, SAI_COMPANDING_MODE_uLAW_ALGO);
  ASSERT_EQ(SAI1A->CR2, (0b10u << 14));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x3u << 14);
  sai_set_companding_mode(SAI1A, SAI_COMPANDING_MODE_uLAW_ALGO);
  ASSERT_EQ(SAI1A->CR2, ~(0x3u << 14) | (0b10u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=14, self.mask='0x3', self.varsmap={'mode': 'SAI_COMPANDING_MODE_ALAW_ALGO'}, self.value='0b11', self.ifdef=[], self.halt=False
  SAI1A->CR2 = 0;
  sai_set_companding_mode(SAI1A, SAI_COMPANDING_MODE_ALAW_ALGO);
  ASSERT_EQ(SAI1A->CR2, (0b11u << 14));
  ASSERT_FALSE(execution_halted());

  SAI1A->CR2 = ~(0x3u << 14);
  sai_set_companding_mode(SAI1A, SAI_COMPANDING_MODE_ALAW_ALGO);
  ASSERT_EQ(SAI1A->CR2, ~(0x3u << 14) | (0b11u << 14));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_set_frame_length(void)
{
  SAI1A->FRCR = 0;
  sai_set_frame_length(SAI1A, 0);
  ASSERT_EQ(SAI1A->FRCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_length(SAI1A, 0);
  ASSERT_EQ(SAI1A->FRCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  SAI1A->FRCR = 0;
  sai_set_frame_length(SAI1A, 0xff);
  ASSERT_EQ(SAI1A->FRCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_length(SAI1A, 0xff);
  ASSERT_EQ(SAI1A->FRCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  SAI1A->FRCR = 0;
  sai_set_frame_length(SAI1A, 0x100);
  ASSERT_EQ(SAI1A->FRCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_length(SAI1A, 0x100);
  ASSERT_EQ(SAI1A->FRCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_sai_set_frame_sync_active_level(void)
{
  SAI1A->FRCR = 0;
  sai_set_frame_sync_active_level(SAI1A, 0);
  ASSERT_EQ(SAI1A->FRCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_sync_active_level(SAI1A, 0);
  ASSERT_EQ(SAI1A->FRCR, ~(0x7fu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  SAI1A->FRCR = 0;
  sai_set_frame_sync_active_level(SAI1A, 0x7f);
  ASSERT_EQ(SAI1A->FRCR, 0x7fu << 8);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_sync_active_level(SAI1A, 0x7f);
  ASSERT_EQ(SAI1A->FRCR, ~(0x7fu << 8) | (0x7fu << 8));
  ASSERT_FALSE(execution_halted());


  SAI1A->FRCR = 0;
  sai_set_frame_sync_active_level(SAI1A, 0x80);
  ASSERT_EQ(SAI1A->FRCR, 0x80u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_sync_active_level(SAI1A, 0x80);
  ASSERT_EQ(SAI1A->FRCR, ~(0x7fu << 8) | (0x80u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_sai_get_frame_sync_mode(void)
{
  u32 res;

  // read_bit
  SAI1A->FRCR = 0;
  res = sai_get_frame_sync_mode(SAI1A);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = ~(0x1u << 16);
  res = sai_get_frame_sync_mode(SAI1A);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = 0x1u << 16;
  res = sai_get_frame_sync_mode(SAI1A);
  ASSERT_EQ(res, 0x1u << 16);
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_frame_sync_polarity(void)
{
  SAI1A->FRCR = 0;
  sai_set_frame_sync_polarity(SAI1A, SAI_FRAME_SYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(SAI1A->FRCR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = ~(1u << 17);
  sai_set_frame_sync_polarity(SAI1A, SAI_FRAME_SYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(SAI1A->FRCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = (1u << 17);
  sai_set_frame_sync_polarity(SAI1A, SAI_FRAME_SYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(SAI1A->FRCR, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_sync_polarity(SAI1A, SAI_FRAME_SYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(SAI1A->FRCR, 0xffffffff & ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_frame_sync_offset(void)
{
  SAI1A->FRCR = 0;
  sai_set_frame_sync_offset(SAI1A, SAI_FRAME_SYNC_OFFSET_BEFORE_FIRST_BIT);
  ASSERT_EQ(SAI1A->FRCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = ~(1u << 18);
  sai_set_frame_sync_offset(SAI1A, SAI_FRAME_SYNC_OFFSET_BEFORE_FIRST_BIT);
  ASSERT_EQ(SAI1A->FRCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = (1u << 18);
  sai_set_frame_sync_offset(SAI1A, SAI_FRAME_SYNC_OFFSET_FIRST_BIT);
  ASSERT_EQ(SAI1A->FRCR, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->FRCR = 0xffffffff;
  sai_set_frame_sync_offset(SAI1A, SAI_FRAME_SYNC_OFFSET_FIRST_BIT);
  ASSERT_EQ(SAI1A->FRCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());

}

void
test_sai_set_first_bit_offset(void)
{
  SAI1A->SLOTR = 0;
  sai_set_first_bit_offset(SAI1A, 0);
  ASSERT_EQ(SAI1A->SLOTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SLOTR = 0xffffffff;
  sai_set_first_bit_offset(SAI1A, 0);
  ASSERT_EQ(SAI1A->SLOTR, ~(0x1fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  SAI1A->SLOTR = 0;
  sai_set_first_bit_offset(SAI1A, 0x1f);
  ASSERT_EQ(SAI1A->SLOTR, 0x1fu << 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SLOTR = 0xffffffff;
  sai_set_first_bit_offset(SAI1A, 0x1f);
  ASSERT_EQ(SAI1A->SLOTR, ~(0x1fu << 0) | (0x1fu << 0));
  ASSERT_FALSE(execution_halted());


  SAI1A->SLOTR = 0;
  sai_set_first_bit_offset(SAI1A, 0x20);
  ASSERT_EQ(SAI1A->SLOTR, 0x20u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SAI1A->SLOTR = 0xffffffff;
  sai_set_first_bit_offset(SAI1A, 0x20);
  ASSERT_EQ(SAI1A->SLOTR, ~(0x1fu << 0) | (0x20u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_sai_set_slot_size(void)
{
  // scope=self.reg='SLOTR', self.shift=6, self.mask='0x3', self.varsmap={'size': 'SAI_SLOT_SIZE_DATASIZE'}, self.value='0b00', self.ifdef=[], self.halt=False
  SAI1A->SLOTR = 0;
  sai_set_slot_size(SAI1A, SAI_SLOT_SIZE_DATASIZE);
  ASSERT_EQ(SAI1A->SLOTR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  SAI1A->SLOTR = ~(0x3u << 6);
  sai_set_slot_size(SAI1A, SAI_SLOT_SIZE_DATASIZE);
  ASSERT_EQ(SAI1A->SLOTR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SLOTR', self.shift=6, self.mask='0x3', self.varsmap={'size': 'SAI_SLOT_SIZE_16BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  SAI1A->SLOTR = 0;
  sai_set_slot_size(SAI1A, SAI_SLOT_SIZE_16BIT);
  ASSERT_EQ(SAI1A->SLOTR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  SAI1A->SLOTR = ~(0x3u << 6);
  sai_set_slot_size(SAI1A, SAI_SLOT_SIZE_16BIT);
  ASSERT_EQ(SAI1A->SLOTR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SLOTR', self.shift=6, self.mask='0x3', self.varsmap={'size': 'SAI_SLOT_SIZE_32BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  SAI1A->SLOTR = 0;
  sai_set_slot_size(SAI1A, SAI_SLOT_SIZE_32BIT);
  ASSERT_EQ(SAI1A->SLOTR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  SAI1A->SLOTR = ~(0x3u << 6);
  sai_set_slot_size(SAI1A, SAI_SLOT_SIZE_32BIT);
  ASSERT_EQ(SAI1A->SLOTR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_set_audio_frame_slots_count(void)
{
  SAI1A->SLOTR = 0;
  sai_set_audio_frame_slots_count(SAI1A, 0);
  ASSERT_EQ(SAI1A->SLOTR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  SAI1A->SLOTR = 0xffffffff;
  sai_set_audio_frame_slots_count(SAI1A, 0);
  ASSERT_EQ(SAI1A->SLOTR, ~(0xfu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  SAI1A->SLOTR = 0;
  sai_set_audio_frame_slots_count(SAI1A, 0xf);
  ASSERT_EQ(SAI1A->SLOTR, 0xfu << 8);
  ASSERT_FALSE(execution_halted());

  SAI1A->SLOTR = 0xffffffff;
  sai_set_audio_frame_slots_count(SAI1A, 0xf);
  ASSERT_EQ(SAI1A->SLOTR, ~(0xfu << 8) | (0xfu << 8));
  ASSERT_FALSE(execution_halted());


  SAI1A->SLOTR = 0;
  sai_set_audio_frame_slots_count(SAI1A, 0x10);
  ASSERT_EQ(SAI1A->SLOTR, 0x10u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SAI1A->SLOTR = 0xffffffff;
  sai_set_audio_frame_slots_count(SAI1A, 0x10);
  ASSERT_EQ(SAI1A->SLOTR, ~(0xfu << 8) | (0x10u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

// └─Skipping type 'bitmap (TODO)' (sai_slot)
void
test_sai_interrupt(void)
{
  SAI1A->IM = 0;
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_OVERRUN_UNDERRUN);
  ASSERT_EQ(SAI1A->IM, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = ~(1u << 0);
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_OVERRUN_UNDERRUN);
  ASSERT_EQ(SAI1A->IM, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = (1u << 0);
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_OVERRUN_UNDERRUN);
  ASSERT_EQ(SAI1A->IM, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = 0xffffffff;
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_OVERRUN_UNDERRUN);
  ASSERT_EQ(SAI1A->IM, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  SAI1A->IM = 0;
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_MUTE_DETECTION);
  ASSERT_EQ(SAI1A->IM, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = ~(1u << 1);
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_MUTE_DETECTION);
  ASSERT_EQ(SAI1A->IM, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = (1u << 1);
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_MUTE_DETECTION);
  ASSERT_EQ(SAI1A->IM, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = 0xffffffff;
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_MUTE_DETECTION);
  ASSERT_EQ(SAI1A->IM, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  SAI1A->IM = 0;
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_WRONG_CLOCK);
  ASSERT_EQ(SAI1A->IM, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = ~(1u << 2);
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_WRONG_CLOCK);
  ASSERT_EQ(SAI1A->IM, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = (1u << 2);
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_WRONG_CLOCK);
  ASSERT_EQ(SAI1A->IM, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = 0xffffffff;
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_WRONG_CLOCK);
  ASSERT_EQ(SAI1A->IM, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  SAI1A->IM = 0;
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_FIFO_REQUEST);
  ASSERT_EQ(SAI1A->IM, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = ~(1u << 3);
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_FIFO_REQUEST);
  ASSERT_EQ(SAI1A->IM, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = (1u << 3);
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_FIFO_REQUEST);
  ASSERT_EQ(SAI1A->IM, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = 0xffffffff;
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_FIFO_REQUEST);
  ASSERT_EQ(SAI1A->IM, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  SAI1A->IM = 0;
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_CODEC_NOT_READY);
  ASSERT_EQ(SAI1A->IM, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = ~(1u << 4);
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_CODEC_NOT_READY);
  ASSERT_EQ(SAI1A->IM, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = (1u << 4);
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_CODEC_NOT_READY);
  ASSERT_EQ(SAI1A->IM, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = 0xffffffff;
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_CODEC_NOT_READY);
  ASSERT_EQ(SAI1A->IM, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  SAI1A->IM = 0;
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = ~(1u << 5);
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = (1u << 5);
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = 0xffffffff;
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  SAI1A->IM = 0;
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_LATE_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = ~(1u << 6);
  sai_interrupt_enable(SAI1A, SAI_INTERRUPT_LATE_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = (1u << 6);
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_LATE_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->IM = 0xffffffff;
  sai_interrupt_disable(SAI1A, SAI_INTERRUPT_LATE_FRAME_SYNC);
  ASSERT_EQ(SAI1A->IM, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_is_flag_set(void)
{
  u32 res;

  SAI1A->SR = 0;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = (1u << 0);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(1u << 0);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0xffffffff;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  SAI1A->SR = 0;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_MUTE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = (1u << 1);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_MUTE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(1u << 1);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_MUTE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0xffffffff;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_MUTE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  SAI1A->SR = 0;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_WRONG_CLOCK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = (1u << 2);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_WRONG_CLOCK);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(1u << 2);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_WRONG_CLOCK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0xffffffff;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_WRONG_CLOCK);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  SAI1A->SR = 0;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_FIFO_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = (1u << 3);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_FIFO_REQUEST);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(1u << 3);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_FIFO_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0xffffffff;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_FIFO_REQUEST);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  SAI1A->SR = 0;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_CODEC_NOT_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = (1u << 4);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_CODEC_NOT_READY);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(1u << 4);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_CODEC_NOT_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0xffffffff;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_CODEC_NOT_READY);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  SAI1A->SR = 0;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = (1u << 5);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(1u << 5);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0xffffffff;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  SAI1A->SR = 0;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_LATE_FRAME_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = (1u << 6);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_LATE_FRAME_SYNC);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(1u << 6);
  res = sai_is_flag_set(SAI1A, SAI_FLAG_LATE_FRAME_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0xffffffff;
  res = sai_is_flag_set(SAI1A, SAI_FLAG_LATE_FRAME_SYNC);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_sai_get_fifo_threshold_level(void)
{
  u32 res;

  // read_bits
  SAI1A->SR = 0;
  res = sai_get_fifo_threshold_level(SAI1A);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = ~(0x7u << 16);
  res = sai_get_fifo_threshold_level(SAI1A);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->SR = 0x7u << 16;
  res = sai_get_fifo_threshold_level(SAI1A);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());

}

void
test_sai_flag_clear(void)
{
  SAI1A->CLRFR = 0;
  sai_flag_clear(SAI1A, SAI_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(SAI1A->CLRFR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SAI1A->CLRFR = ~(1u << 0);
  sai_flag_clear(SAI1A, SAI_FLAG_OVERRUN_UNDERRUN);
  ASSERT_EQ(SAI1A->CLRFR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SAI1A->CLRFR = 0;
  sai_flag_clear(SAI1A, SAI_FLAG_MUTE);
  ASSERT_EQ(SAI1A->CLRFR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SAI1A->CLRFR = ~(1u << 1);
  sai_flag_clear(SAI1A, SAI_FLAG_MUTE);
  ASSERT_EQ(SAI1A->CLRFR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SAI1A->CLRFR = 0;
  sai_flag_clear(SAI1A, SAI_FLAG_WRONG_CLOCK);
  ASSERT_EQ(SAI1A->CLRFR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SAI1A->CLRFR = ~(1u << 2);
  sai_flag_clear(SAI1A, SAI_FLAG_WRONG_CLOCK);
  ASSERT_EQ(SAI1A->CLRFR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SAI1A->CLRFR = 0;
  sai_flag_clear(SAI1A, SAI_FLAG_FIFO_REQUEST);
  ASSERT_EQ(SAI1A->CLRFR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SAI1A->CLRFR = ~(1u << 3);
  sai_flag_clear(SAI1A, SAI_FLAG_FIFO_REQUEST);
  ASSERT_EQ(SAI1A->CLRFR, ~(1u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SAI1A->CLRFR = 0;
  sai_flag_clear(SAI1A, SAI_FLAG_CODEC_NOT_READY);
  ASSERT_EQ(SAI1A->CLRFR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SAI1A->CLRFR = ~(1u << 4);
  sai_flag_clear(SAI1A, SAI_FLAG_CODEC_NOT_READY);
  ASSERT_EQ(SAI1A->CLRFR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SAI1A->CLRFR = 0;
  sai_flag_clear(SAI1A, SAI_FLAG_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(SAI1A->CLRFR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SAI1A->CLRFR = ~(1u << 5);
  sai_flag_clear(SAI1A, SAI_FLAG_ANTICIPATED_FRAME_SYNC);
  ASSERT_EQ(SAI1A->CLRFR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SAI1A->CLRFR = 0;
  sai_flag_clear(SAI1A, SAI_FLAG_LATE_FRAME_SYNC);
  ASSERT_EQ(SAI1A->CLRFR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SAI1A->CLRFR = ~(1u << 6);
  sai_flag_clear(SAI1A, SAI_FLAG_LATE_FRAME_SYNC);
  ASSERT_EQ(SAI1A->CLRFR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_sai_write_data(void)
{
  SAI1A->DR = 0;
  sai_write_data(SAI1A, 0);
  ASSERT_EQ(SAI1A->DR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SAI1A->DR = 0xffffffff;
  sai_write_data(SAI1A, 0);
  ASSERT_EQ(SAI1A->DR, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
#if defined(STM32_SAI_GCR)
    TEST_FUNC(test_sai_set_sync_output),
#endif
    TEST_FUNC(test_sai_set_block_mode),
    TEST_FUNC(test_sai_set_protocol),
    TEST_FUNC(test_sai_set_data_size),
    TEST_FUNC(test_sai_set_endianess),
    TEST_FUNC(test_sai_set_clock_strobe),
    TEST_FUNC(test_sai_set_subblock_sync),
    TEST_FUNC(test_sai_set_audio_mode),
    TEST_FUNC(test_sai_set_outdrive),
    TEST_FUNC(test_sai_audio_block),
    TEST_FUNC(test_sai_dma),
    TEST_FUNC(test_sai_clock_divider),
    TEST_FUNC(test_sai_set_clock_divider),
    TEST_FUNC(test_sai_set_fifo_threshold),
    TEST_FUNC(test_sai_fifo_flush),
    TEST_FUNC(test_sai_set_tristate_management),
    TEST_FUNC(test_sai_mute),
    TEST_FUNC(test_sai_set_mute_value),
    TEST_FUNC(test_sai_set_mute_counter),
    TEST_FUNC(test_sai_set_bit_complement),
    TEST_FUNC(test_sai_set_companding_mode),
    TEST_FUNC(test_sai_set_frame_length),
    TEST_FUNC(test_sai_set_frame_sync_active_level),
    TEST_FUNC(test_sai_get_frame_sync_mode),
    TEST_FUNC(test_sai_set_frame_sync_polarity),
    TEST_FUNC(test_sai_set_frame_sync_offset),
    TEST_FUNC(test_sai_set_first_bit_offset),
    TEST_FUNC(test_sai_set_slot_size),
    TEST_FUNC(test_sai_set_audio_frame_slots_count),
    TEST_FUNC(test_sai_interrupt),
    TEST_FUNC(test_sai_is_flag_set),
    TEST_FUNC(test_sai_get_fifo_threshold_level),
    TEST_FUNC(test_sai_flag_clear),
    TEST_FUNC(test_sai_write_data),
  };

  return TESTS_RUN(tests);
}
