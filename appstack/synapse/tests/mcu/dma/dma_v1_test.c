#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/dma/dma_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  DMA1 = (struct dma_registers_map*) membuf;
}

void
test_dma_is_stream_flag_set(void)
{
  u32 res;

  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 0);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 0);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 2);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 2);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 3);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 3);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 4);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 4);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 5);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 5);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 6);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 6);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 8);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 8);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 9);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 9);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 10);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 10);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 11);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 11);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 16);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 16);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 18);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 18);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 19);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 19);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 20);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 20);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 21);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 21);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 22);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 22);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 24);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 24);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 25);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 25);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 26);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 26);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());


  DMA1->LISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = (1u << 27);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = ~(1u << 27);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 0);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 0);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 2);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 2);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 3);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 3);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 4);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 4);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 5);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 5);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 6);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 6);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 8);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 8);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 9);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 9);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 10);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 10);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 11);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 11);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 16);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 16);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 18);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 18);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 19);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 19);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 20);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 20);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 21);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 21);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 22);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 22);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 24);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 24);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 25);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 25);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 26);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 26);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());


  DMA1->HISR = 0;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = (1u << 27);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = ~(1u << 27);
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_flag_clear(void)
{
  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 0);
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 2);
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 3);
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 4);
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 5);
  dma_stream_flag_clear(DMA1, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 6);
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 8);
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 9);
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 10);
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 11);
  dma_stream_flag_clear(DMA1, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 16);
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 18);
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 19);
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 20);
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 21);
  dma_stream_flag_clear(DMA1, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 22);
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 24);
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 25);
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 26);
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->LIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  DMA1->LIFCR = ~(1u << 27);
  dma_stream_flag_clear(DMA1, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 0);
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 2);
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 3);
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 4);
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 5);
  dma_stream_flag_clear(DMA1, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 6);
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 8);
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 9);
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 10);
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 11);
  dma_stream_flag_clear(DMA1, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 16);
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 18);
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 19);
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 20);
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 21);
  dma_stream_flag_clear(DMA1, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 22);
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 24);
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 25);
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 26);
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->HIFCR = 0;
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  DMA1->HIFCR = ~(1u << 27);
  dma_stream_flag_clear(DMA1, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA1->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_is_enabled(void)
{
  u32 res;

  // read_bit
  DMA1->streams[DMA_STREAM0].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM0);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  DMA1->streams[DMA_STREAM1].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM1);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  DMA1->streams[DMA_STREAM2].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM2);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  DMA1->streams[DMA_STREAM3].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM3);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  DMA1->streams[DMA_STREAM4].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM4);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  DMA1->streams[DMA_STREAM5].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM5);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  DMA1->streams[DMA_STREAM6].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM6);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  // read_bit
  DMA1->streams[DMA_STREAM7].SCR = 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(DMA1, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(DMA1, DMA_STREAM7);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 0);
  dma_stream_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 0);
  dma_stream_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'fn_toggle (TODO)' (dma_stream_interrupt)
void
test_dma_stream_set_flow_controller(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 5);
  dma_stream_set_flow_controller(DMA1, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_flow_controller(DMA1, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_data_transfer_direction(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM0, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM0, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM1, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM1, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM2, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM2, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM3, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM3, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM4, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM4, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM5, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM5, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM6, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM6, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'direction': 'DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM7, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM7, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=6, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'direction': 'DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(DMA1, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_circular_mode(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 8);
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_periph_increment_mode(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_memory_increment_mode(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_periph_data_size(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'size': 'DMA_STREAM_PERIPH_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'size': 'DMA_STREAM_PERIPH_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=11, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'size': 'DMA_STREAM_PERIPH_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_memory_data_size(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'size': 'DMA_STREAM_MEMORY_SIZE_BYTE'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'size': 'DMA_STREAM_MEMORY_SIZE_HALF_WORD'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=13, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'size': 'DMA_STREAM_MEMORY_SIZE_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_periph_inc_offset(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_priority(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM0, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM1, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM2, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM3, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM4, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM5, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM6, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'priority': 'DMA_STREAM_PRIORITY_LOW'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'priority': 'DMA_STREAM_PRIORITY_MEDIUM'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'priority': 'DMA_STREAM_PRIORITY_HIGH'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=16, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'priority': 'DMA_STREAM_PRIORITY_VERY_HIGH'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(DMA1, DMA_STREAM7, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_double_buffer_mode(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(DMA1, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_current_target(void)
{
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_current_target(DMA1, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = (1u << 19);
  dma_stream_set_current_target(DMA1, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_current_target(DMA1, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_periph_burst_transfer(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=21, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_PERIPH_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_memory_burst_transfer(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR4'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR8'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=23, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'burst': 'DMA_STREAM_MEMORY_BURST_INCR16'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(DMA1, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_DMA_CHSEL_4BIT)
void
test_dma_stream_set_channel(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0xf', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_DMA_CHSEL_3BIT)
void
test_dma_stream_set_channel(void)
{
  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM0', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM1', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM2', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM3', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM4', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM5', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM6', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL0'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL1'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL2'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL3'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL4'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL5'}, self.value='0b101', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL6'}, self.value='0b110', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SCR', self.shift=25, self.mask='0x7', self.varsmap={'stream': 'DMA_STREAM7', 'channel': 'DMA_STREAM_CHANNEL7'}, self.value='0b111', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(DMA1, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_dma_stream_set_items_transfer_count(void)
{
  DMA1->streams[DMA_STREAM0].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM0, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM0, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM0].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM0, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM0, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM0].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM0, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM0].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM0, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA1->streams[DMA_STREAM1].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM1, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM1, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM1, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM1, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM1, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM1].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM1, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA1->streams[DMA_STREAM2].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM2].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM2, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA1->streams[DMA_STREAM3].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM3, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM3, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM3, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM3, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM3, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM3].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM3, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA1->streams[DMA_STREAM4].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM4, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM4, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM4, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM4, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM4, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM4].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM4, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA1->streams[DMA_STREAM5].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM5, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM5, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM5, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM5, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM5, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM5].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM5, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA1->streams[DMA_STREAM6].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM6, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM6, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM6, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM6, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM6, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM6].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM6, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA1->streams[DMA_STREAM7].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM7, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM7, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM7, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM7, 0xffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SNDTR = 0;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM7, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA1->streams[DMA_STREAM7].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(DMA1, DMA_STREAM7, 0x10000);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma_stream_set_periph_address(void)
{
  DMA1->streams[DMA_STREAM0].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM0, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM0, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM0].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM0, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM0, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM1, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM1, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM1, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM1, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM2, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM2, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM2, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM2, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM3, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM3, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM3, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM3, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM4, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM4, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM4, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM4, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM5, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM5, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM5, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM5, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM6, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM6, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM6, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM6, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM7, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM7, 0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SPAR = 0;
  dma_stream_set_periph_address(DMA1, DMA_STREAM7, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SPAR = 0xffffffff;
  dma_stream_set_periph_address(DMA1, DMA_STREAM7, 0xffffffff);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'fn_set_value (TODO)' (dma_stream_set_memory_address)
void
test_dma_stream_set_fifo_threshold(void)
{
  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM0', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM1', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM2', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM3', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM4', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM5', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM6', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over4_FULL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_1over2_FULL'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_3over4_FULL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='streams[{stream}].SFCR', self.shift=0, self.mask='0x3', self.varsmap={'stream': 'DMA_STREAM7', 'threshold': 'DMA_STREAM_FIFO_THRESHOLD_FULL'}, self.value=' 0b11', self.ifdef=[], self.halt=False
  DMA1->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(DMA1, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_direct_mode(void)
{
  DMA1->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM0);
  ASSERT_EQ(DMA1->streams[DMA_STREAM0].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM1);
  ASSERT_EQ(DMA1->streams[DMA_STREAM1].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM2);
  ASSERT_EQ(DMA1->streams[DMA_STREAM2].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM3);
  ASSERT_EQ(DMA1->streams[DMA_STREAM3].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM4);
  ASSERT_EQ(DMA1->streams[DMA_STREAM4].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM5);
  ASSERT_EQ(DMA1->streams[DMA_STREAM5].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM6);
  ASSERT_EQ(DMA1->streams[DMA_STREAM6].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA1->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(DMA1, DMA_STREAM7);
  ASSERT_EQ(DMA1->streams[DMA_STREAM7].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_get_fifo_status(void)
{
  u32 res;

  // read_bits
  DMA1->streams[DMA_STREAM0].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM0].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM0);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DMA1->streams[DMA_STREAM1].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM1].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM1);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DMA1->streams[DMA_STREAM2].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM2].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM2);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DMA1->streams[DMA_STREAM3].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM3].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM3);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DMA1->streams[DMA_STREAM4].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM4].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM4);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DMA1->streams[DMA_STREAM5].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM5].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM5);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DMA1->streams[DMA_STREAM6].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM6].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM6);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DMA1->streams[DMA_STREAM7].SFCR = 0;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA1->streams[DMA_STREAM7].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(DMA1, DMA_STREAM7);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_dma_is_stream_flag_set),
    TEST_FUNC(test_dma_stream_flag_clear),
    TEST_FUNC(test_dma_stream_is_enabled),
    TEST_FUNC(test_dma_stream),
    TEST_FUNC(test_dma_stream_set_flow_controller),
    TEST_FUNC(test_dma_stream_set_data_transfer_direction),
    TEST_FUNC(test_dma_stream_circular_mode),
    TEST_FUNC(test_dma_stream_periph_increment_mode),
    TEST_FUNC(test_dma_stream_memory_increment_mode),
    TEST_FUNC(test_dma_stream_set_periph_data_size),
    TEST_FUNC(test_dma_stream_set_memory_data_size),
    TEST_FUNC(test_dma_stream_set_periph_inc_offset),
    TEST_FUNC(test_dma_stream_set_priority),
    TEST_FUNC(test_dma_stream_set_double_buffer_mode),
    TEST_FUNC(test_dma_stream_set_current_target),
    TEST_FUNC(test_dma_stream_set_periph_burst_transfer),
    TEST_FUNC(test_dma_stream_set_memory_burst_transfer),
#if defined(STM32_DMA_CHSEL_4BIT)
    TEST_FUNC(test_dma_stream_set_channel),
#endif
#if defined(STM32_DMA_CHSEL_3BIT)
    TEST_FUNC(test_dma_stream_set_channel),
#endif
    TEST_FUNC(test_dma_stream_set_items_transfer_count),
    TEST_FUNC(test_dma_stream_set_periph_address),
    TEST_FUNC(test_dma_stream_set_fifo_threshold),
    TEST_FUNC(test_dma_stream_direct_mode),
    TEST_FUNC(test_dma_stream_get_fifo_status),
  };

  return TESTS_RUN(tests);
}
