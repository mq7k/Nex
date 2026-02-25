#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/dma/dma_v2.h"
#include "libtest/libtest.h"

void
setup(void)
{
  DMA1 = (struct dma_registers_map*) membuf;
}

void
test_dma_is_channel_flag_set(void)
{
  u32 res;

  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 0);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 0);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 1);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 1);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 2);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 2);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 3);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 3);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 4);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 4);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 5);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 5);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 6);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 6);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 7);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 7);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 8);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 8);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 9);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 9);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 10);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 10);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 11);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 11);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 12);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 12);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 13);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 13);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 14);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 14);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 15);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 15);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 16);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 16);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 17);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 17);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 18);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 18);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 19);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 19);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 20);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 20);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 21);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 21);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 22);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 22);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 23);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 23);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 23));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 24);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 24);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 25);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 25);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 26);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 26);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());


  DMA1->ISR = 0;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = (1u << 27);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = ~(1u << 27);
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->ISR = 0xffffffff;
  res = dma_is_channel_flag_set(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_flag_clear(void)
{
  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 0);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 1);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 2);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 3);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 4);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 5);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 6);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 7);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL2, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 8);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 9);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 10);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 11);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL3, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 12);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 13);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 14);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 15);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL4, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 16);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 17);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 18);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 19);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL5, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 20);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 21);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 22);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 23);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL6, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 24);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_GLOBAL_INTERRUPT);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 25);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSER_COMPLETE);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 26);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->IFCR = 0;
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  DMA1->IFCR = ~(1u << 27);
  dma_channel_flag_clear(DMA1, DMA_CHANNEL7, DMA_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel(void)
{
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << None);
  dma_channel_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << None);
  dma_channel_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << None);
  dma_channel_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << None);
  dma_channel_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << None);
  dma_channel_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << None);
  dma_channel_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << None);
  dma_channel_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << None);
  dma_channel_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << None);
  dma_channel_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << None);
  dma_channel_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << None);
  dma_channel_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << None);
  dma_channel_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << None);
  dma_channel_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << None);
  dma_channel_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_interrupt(void)
{
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << 1);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << 1);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << 2);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << 2);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << 3);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << 3);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL1, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << 1);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << 1);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << 2);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << 2);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << 3);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << 3);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL2, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << 1);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << 1);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << 2);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << 2);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << 3);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << 3);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL3, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << 1);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << 1);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << 2);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << 2);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << 3);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << 3);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL4, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << 1);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << 1);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << 2);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << 2);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << 3);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << 3);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL5, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << 1);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << 1);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << 2);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << 2);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << 3);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << 3);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL6, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << 1);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << 1);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << 2);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << 2);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_HALF_TRANSFER);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << 3);
  dma_channel_interrupt_enable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << 3);
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_interrupt_disable(DMA1, DMA_CHANNEL7, DMA_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_set_data_transfer_direction(void)
{
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL1, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL1, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL1, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL1, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff & ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL2, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL2, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL2, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL2, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff & ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL3, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL3, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL3, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL3, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff & ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL4, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL4, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL4, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL4, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff & ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL5, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL5, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL5, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL5, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff & ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL6, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL6, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL6, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL6, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff & ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL7, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL7, DMA_TRANSFER_DIRECTION_FROM_MEMORY);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << None);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL7, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL7, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff & ~(1u << None));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_circular_mode(void)
{
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << 5);
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << 5);
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << 5);
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << 5);
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << 5);
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << 5);
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << 5);
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << 5);
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << 5);
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << 5);
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << 5);
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << 5);
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << 5);
  dma_channel_circular_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << 5);
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_circular_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_periph_increment_mode(void)
{
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << 6);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << 6);
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << 6);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << 6);
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << 6);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << 6);
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << 6);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << 6);
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << 6);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << 6);
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << 6);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << 6);
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << 6);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << 6);
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_periph_increment_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_memory_increment_mode(void)
{
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << 7);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << 7);
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << 7);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << 7);
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << 7);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << 7);
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << 7);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << 7);
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << 7);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << 7);
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << 7);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << 7);
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << 7);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << 7);
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_memory_increment_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_set_periph_size(void)
{
  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_PERIPH_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL1, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL1, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_PERIPH_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL1, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL1, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_PERIPH_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL1, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL1, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_PERIPH_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL2, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL2, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_PERIPH_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL2, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL2, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_PERIPH_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL2, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL2, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_PERIPH_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL3, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL3, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_PERIPH_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL3, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL3, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_PERIPH_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL3, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL3, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_PERIPH_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL4, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL4, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_PERIPH_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL4, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL4, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_PERIPH_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL4, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL4, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_PERIPH_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL5, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL5, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_PERIPH_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL5, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL5, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_PERIPH_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL5, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL5, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_PERIPH_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL6, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL6, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_PERIPH_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL6, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL6, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_PERIPH_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL6, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL6, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_PERIPH_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL7, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL7, DMA_PERIPH_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_PERIPH_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL7, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL7, DMA_PERIPH_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_PERIPH_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL7, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL7, DMA_PERIPH_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_set_memory_size(void)
{
  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_MEMORY_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL1, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL1, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_MEMORY_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL1, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL1, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_MEMORY_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL1, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL1, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_MEMORY_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL2, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL2, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_MEMORY_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL2, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL2, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_MEMORY_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL2, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL2, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_MEMORY_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL3, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL3, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_MEMORY_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL3, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL3, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_MEMORY_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL3, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL3, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_MEMORY_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL4, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL4, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_MEMORY_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL4, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL4, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_MEMORY_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL4, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL4, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_MEMORY_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL5, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL5, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_MEMORY_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL5, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL5, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_MEMORY_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL5, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL5, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_MEMORY_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL6, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL6, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_MEMORY_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL6, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL6, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_MEMORY_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL6, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL6, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_MEMORY_SIZE_8BITS'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL7, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL7, DMA_MEMORY_SIZE_8BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_MEMORY_SIZE_16BITS'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL7, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL7, DMA_MEMORY_SIZE_16BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_MEMORY_SIZE_32BITS'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL7, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL7, DMA_MEMORY_SIZE_32BITS);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_set_priority_level(void)
{
  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_CHANNEL_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_CHANNEL_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_CHANNEL_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL1', 'size': 'DMA_CHANNEL_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (0b11u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL1, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(0u << 0) | (0b11u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_CHANNEL_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_CHANNEL_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_CHANNEL_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL2', 'size': 'DMA_CHANNEL_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (0b11u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL2, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(0u << 0) | (0b11u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_CHANNEL_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_CHANNEL_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_CHANNEL_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL3', 'size': 'DMA_CHANNEL_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (0b11u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL3, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(0u << 0) | (0b11u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_CHANNEL_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_CHANNEL_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_CHANNEL_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL4', 'size': 'DMA_CHANNEL_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (0b11u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL4, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(0u << 0) | (0b11u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_CHANNEL_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_CHANNEL_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_CHANNEL_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL5', 'size': 'DMA_CHANNEL_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (0b11u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL5, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(0u << 0) | (0b11u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_CHANNEL_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_CHANNEL_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_CHANNEL_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL6', 'size': 'DMA_CHANNEL_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (0b11u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL6, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(0u << 0) | (0b11u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_CHANNEL_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b00u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b00u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_CHANNEL_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b01u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b01u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_CHANNEL_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b10u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b10u << None));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='channels[{channel}].CCR', self.shift=None, self.mask=None, self.varsmap={'channel': 'DMA_CHANNEL7', 'size': 'DMA_CHANNEL_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (0b11u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(0u << 0);
  dma_channel_set_priority_level(DMA1, DMA_CHANNEL7, {level});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(0u << 0) | (0b11u << None));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_mem2mem_mode(void)
{
  DMA1->channels[DMA_CHANNEL1].CCR = 0;
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = ~(1u << None);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = (1u << None);
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CCR = 0xffffffff;
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL1);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CCR = 0;
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = ~(1u << None);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = (1u << None);
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CCR = 0xffffffff;
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL2);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CCR = 0;
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = ~(1u << None);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = (1u << None);
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CCR = 0xffffffff;
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL3);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CCR = 0;
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = ~(1u << None);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = (1u << None);
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CCR = 0xffffffff;
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL4);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CCR = 0;
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = ~(1u << None);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = (1u << None);
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CCR = 0xffffffff;
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL5);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CCR = 0;
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = ~(1u << None);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = (1u << None);
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CCR = 0xffffffff;
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL6);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CCR = 0;
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, (1u << None));
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = ~(1u << None);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = (1u << None);
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CCR = 0xffffffff;
  dma_channel_mem2mem_mode_disable(DMA1, DMA_CHANNEL7);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CCR, ~(1u << None));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_set_channel_transfer_items_count(void)
{
  DMA1->channels[DMA_CHANNEL1].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL1, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL1, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CNDTR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL1].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL1, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CNDTR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL1, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CNDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL2, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL2, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CNDTR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL2, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CNDTR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL2, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CNDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL3, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL3, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CNDTR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL3, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CNDTR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL3, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CNDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL4, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL4, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CNDTR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL4, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CNDTR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL4, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CNDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL5, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL5, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CNDTR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL5, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CNDTR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL5, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CNDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL6, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL6, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CNDTR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL6, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CNDTR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL6, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CNDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL7, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL7, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CNDTR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CNDTR = 0;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL7, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CNDTR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CNDTR = 0xffffffff;
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL7, {count});
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CNDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_get_channel_transfer_items_left(void)
{
  u32 res;

  // read_reg
  DMA1->channels[DMA_CHANNEL1].CNDTR = 0;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CNDTR = 0xffffffff;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  DMA1->channels[DMA_CHANNEL2].CNDTR = 0;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CNDTR = 0xffffffff;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  DMA1->channels[DMA_CHANNEL3].CNDTR = 0;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CNDTR = 0xffffffff;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  DMA1->channels[DMA_CHANNEL4].CNDTR = 0;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CNDTR = 0xffffffff;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  DMA1->channels[DMA_CHANNEL5].CNDTR = 0;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CNDTR = 0xffffffff;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  DMA1->channels[DMA_CHANNEL6].CNDTR = 0;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CNDTR = 0xffffffff;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  DMA1->channels[DMA_CHANNEL7].CNDTR = 0;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CNDTR = 0xffffffff;
  res = dma_get_channel_transfer_items_left(DMA1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_set_periph_address(void)
{
  DMA1->channels[DMA_CHANNEL1].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL1, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL1, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL1].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL1, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL1, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL2, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL2, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL2, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL2, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL3, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL3, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL3, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL3, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL4, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL4, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL4, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL4, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL5, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL5, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL5, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL5, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL6, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL6, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL6, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL6, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL7, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL7, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CPAR = 0;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL7, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CPAR = 0xffffffff;
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL7, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_channel_set_memory_address(void)
{
  DMA1->channels[DMA_CHANNEL1].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL1, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL1, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL1].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL1, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL1].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL1, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL1].CMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL2, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL2, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL2].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL2, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL2].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL2, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL2].CMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL3, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL3, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL3].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL3, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL3].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL3, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL3].CMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL4, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL4, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL4].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL4, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL4].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL4, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL4].CMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL5, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL5, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL5].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL5, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL5].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL5, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL5].CMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL6, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL6, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL6].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL6, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL6].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL6, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL6].CMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL7, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL7, 0);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->channels[DMA_CHANNEL7].CMAR = 0;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL7, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->channels[DMA_CHANNEL7].CMAR = 0xffffffff;
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL7, 0xffffffff);
  ASSERT_EQ(DMA1->channels[DMA_CHANNEL7].CMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_dma_is_channel_flag_set),
    TEST_FUNC(test_dma_channel_flag_clear),
    TEST_FUNC(test_dma_channel),
    TEST_FUNC(test_dma_channel_interrupt),
    TEST_FUNC(test_dma_channel_set_data_transfer_direction),
    TEST_FUNC(test_dma_channel_circular_mode),
    TEST_FUNC(test_dma_channel_periph_increment_mode),
    TEST_FUNC(test_dma_channel_memory_increment_mode),
    TEST_FUNC(test_dma_channel_set_periph_size),
    TEST_FUNC(test_dma_channel_set_memory_size),
    TEST_FUNC(test_dma_channel_set_priority_level),
    TEST_FUNC(test_dma_channel_mem2mem_mode),
    TEST_FUNC(test_dma_set_channel_transfer_items_count),
    TEST_FUNC(test_dma_get_channel_transfer_items_left),
    TEST_FUNC(test_dma_channel_set_periph_address),
    TEST_FUNC(test_dma_channel_set_memory_address),
  };

  return TESTS_RUN(tests);
}
