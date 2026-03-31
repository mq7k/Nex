#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/dma/dma_v1.h"
#include "libtest/libtest.hpp"

#define ASSERT_ADDR(periph, reg, offset)\
	ASSERT_EQ(offsetof(periph, reg), offset)

volatile struct dma_registers_map* _DMA;

void
setup(void)
{
  _DMA = (struct dma_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_ADDR(struct dma_registers_map, LISR, 0x00lu);
  ASSERT_ADDR(struct dma_registers_map, HISR, 0x04lu);
  ASSERT_ADDR(struct dma_registers_map, LIFCR, 0x08lu);
  ASSERT_ADDR(struct dma_registers_map, HIFCR, 0x0clu);
  ASSERT_ADDR(struct dma_registers_map, streams[0].SCR, 0x10lu);
  ASSERT_ADDR(struct dma_registers_map, streams[0].SNDTR, 0x14lu);
  ASSERT_ADDR(struct dma_registers_map, streams[0].SPAR, 0x18lu);
  ASSERT_ADDR(struct dma_registers_map, streams[0].SM0AR, 0x1clu);
  ASSERT_ADDR(struct dma_registers_map, streams[0].SM1AR, 0x20lu);
  ASSERT_ADDR(struct dma_registers_map, streams[0].SFCR, 0x24lu);
  ASSERT_ADDR(struct dma_registers_map, streams[1].SCR, 0x28lu);
  ASSERT_ADDR(struct dma_registers_map, streams[1].SNDTR, 0x2clu);
  ASSERT_ADDR(struct dma_registers_map, streams[1].SPAR, 0x30lu);
  ASSERT_ADDR(struct dma_registers_map, streams[1].SM0AR, 0x34lu);
  ASSERT_ADDR(struct dma_registers_map, streams[1].SM1AR, 0x38lu);
  ASSERT_ADDR(struct dma_registers_map, streams[1].SFCR, 0x3clu);
  ASSERT_ADDR(struct dma_registers_map, streams[2].SCR, 0x40lu);
  ASSERT_ADDR(struct dma_registers_map, streams[2].SNDTR, 0x44lu);
  ASSERT_ADDR(struct dma_registers_map, streams[2].SPAR, 0x48lu);
  ASSERT_ADDR(struct dma_registers_map, streams[2].SM0AR, 0x4clu);
  ASSERT_ADDR(struct dma_registers_map, streams[2].SM1AR, 0x50lu);
  ASSERT_ADDR(struct dma_registers_map, streams[2].SFCR, 0x54lu);
  ASSERT_ADDR(struct dma_registers_map, streams[3].SCR, 0x58lu);
  ASSERT_ADDR(struct dma_registers_map, streams[3].SNDTR, 0x5clu);
  ASSERT_ADDR(struct dma_registers_map, streams[3].SPAR, 0x60lu);
  ASSERT_ADDR(struct dma_registers_map, streams[3].SM0AR, 0x64lu);
  ASSERT_ADDR(struct dma_registers_map, streams[3].SM1AR, 0x68lu);
  ASSERT_ADDR(struct dma_registers_map, streams[3].SFCR, 0x6clu);
  ASSERT_ADDR(struct dma_registers_map, streams[4].SCR, 0x70lu);
  ASSERT_ADDR(struct dma_registers_map, streams[4].SNDTR, 0x74lu);
  ASSERT_ADDR(struct dma_registers_map, streams[4].SPAR, 0x78lu);
  ASSERT_ADDR(struct dma_registers_map, streams[4].SM0AR, 0x7clu);
  ASSERT_ADDR(struct dma_registers_map, streams[4].SM1AR, 0x80lu);
  ASSERT_ADDR(struct dma_registers_map, streams[4].SFCR, 0x84lu);
  ASSERT_ADDR(struct dma_registers_map, streams[5].SCR, 0x88lu);
  ASSERT_ADDR(struct dma_registers_map, streams[5].SNDTR, 0x8clu);
  ASSERT_ADDR(struct dma_registers_map, streams[5].SPAR, 0x90lu);
  ASSERT_ADDR(struct dma_registers_map, streams[5].SM0AR, 0x94lu);
  ASSERT_ADDR(struct dma_registers_map, streams[5].SM1AR, 0x98lu);
  ASSERT_ADDR(struct dma_registers_map, streams[5].SFCR, 0x9clu);
  ASSERT_ADDR(struct dma_registers_map, streams[6].SCR, 0xa0lu);
  ASSERT_ADDR(struct dma_registers_map, streams[6].SNDTR, 0xa4lu);
  ASSERT_ADDR(struct dma_registers_map, streams[6].SPAR, 0xa8lu);
  ASSERT_ADDR(struct dma_registers_map, streams[6].SM0AR, 0xaclu);
  ASSERT_ADDR(struct dma_registers_map, streams[6].SM1AR, 0xb0lu);
  ASSERT_ADDR(struct dma_registers_map, streams[6].SFCR, 0xb4lu);
  ASSERT_ADDR(struct dma_registers_map, streams[7].SCR, 0xb8lu);
  ASSERT_ADDR(struct dma_registers_map, streams[7].SNDTR, 0xbclu);
  ASSERT_ADDR(struct dma_registers_map, streams[7].SPAR, 0xc0lu);
  ASSERT_ADDR(struct dma_registers_map, streams[7].SM0AR, 0xc4lu);
  ASSERT_ADDR(struct dma_registers_map, streams[7].SM1AR, 0xc8lu);
  ASSERT_ADDR(struct dma_registers_map, streams[7].SFCR, 0xcclu);
}

void
test_dma_is_stream_flag_set(void)
{
  u32 res;

  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 0);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 0);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 2);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 2);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 3);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 3);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 4);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 4);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 5);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 5);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 6);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 6);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 8);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 8);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 9);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 9);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 10);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 10);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 11);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 11);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 16);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 16);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 18);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 18);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 19);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 19);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 20);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 20);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 21);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 21);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 22);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 22);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 24);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 24);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 25);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 25);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 26);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 26);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());


  _DMA->LISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = (1u << 27);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = ~(1u << 27);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->LISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 0);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 0);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 2);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 2);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 3);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 3);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 4);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 4);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 5);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 5);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 6);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 6);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 8);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 8);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 9);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 9);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 10);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 10);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 11);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 11);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 16);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 16);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 18);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 18);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 19);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 19);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 20);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 20);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 21);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 21);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 22);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 22);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 24);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 24);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(res, (1u << 24));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 25);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 25);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 26);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 26);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());


  _DMA->HISR = 0;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = (1u << 27);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = ~(1u << 27);
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->HISR = 0xffffffff;
  res = dma_is_stream_flag_set(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_flag_clear(void)
{
  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 0);
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 2);
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 3);
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 4);
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 5);
  dma_stream_flag_clear(_DMA, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 6);
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 8);
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 9);
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 10);
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 11);
  dma_stream_flag_clear(_DMA, DMA_STREAM1, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 16);
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 18);
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 19);
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 20);
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 21);
  dma_stream_flag_clear(_DMA, DMA_STREAM2, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 22);
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 24);
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 25);
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 26);
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->LIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  _DMA->LIFCR = ~(1u << 27);
  dma_stream_flag_clear(_DMA, DMA_STREAM3, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->LIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 0);
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 2);
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 3);
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 4);
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 5);
  dma_stream_flag_clear(_DMA, DMA_STREAM4, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 6);
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 8);
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 9);
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 10);
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 11);
  dma_stream_flag_clear(_DMA, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 16);
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 18);
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 19);
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 20);
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 21);
  dma_stream_flag_clear(_DMA, DMA_STREAM6, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 22);
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_FIFO_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 24);
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_MODE_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 25);
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 26);
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_HALF_TRANSFER);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->HIFCR = 0;
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  _DMA->HIFCR = ~(1u << 27);
  dma_stream_flag_clear(_DMA, DMA_STREAM7, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(_DMA->HIFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_is_enabled(void)
{
  u32 res;

  _DMA->streams[DMA_STREAM0].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM0);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM1);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM2);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM3);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM4);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM5);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM6);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x1u << 0);
  res = dma_stream_is_enabled(_DMA, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0x1u << 0;
  res = dma_stream_is_enabled(_DMA, DMA_STREAM7);
  ASSERT_EQ(res, 0x1u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 0);
  dma_stream_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 0);
  dma_stream_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'fn_toggle (TODO)' (dma_stream_interrupt)
void
test_dma_stream_set_flow_controller(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM0, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM1, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM2, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM3, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM4, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM5, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM6, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 5);
  dma_stream_set_flow_controller(_DMA, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_flow_controller(_DMA, DMA_STREAM7, DMA_STREAM_FLOW_CONTROLLER_DMA);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_data_transfer_direction(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM0, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM0, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM1, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM1, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM1, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM2, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM2, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM2, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM3, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM3, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM3, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM4, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM4, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM4, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM5, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM5, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM5, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM6, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM6, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM6, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM7, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM7, DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 6);
  dma_stream_set_data_transfer_direction(_DMA, DMA_STREAM7, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_circular_mode(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 8);
  dma_stream_circular_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 8);
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_circular_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_periph_increment_mode(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 9);
  dma_stream_periph_increment_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 9);
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_periph_increment_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_memory_increment_mode(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 10);
  dma_stream_memory_increment_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 10);
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_memory_increment_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_periph_data_size(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 11);
  dma_stream_set_periph_data_size(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_memory_data_size(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_BYTE);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_HALF_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 13);
  dma_stream_set_memory_data_size(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_SIZE_WORD);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_periph_inc_offset(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_32BIT);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 15);
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_periph_inc_offset(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_INC_OFFSET_FIXED);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_priority(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM0, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM1, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM2, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM3, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM4, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM5, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM6, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_LOW);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_MEDIUM);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 16);
  dma_stream_set_priority(_DMA, DMA_STREAM7, DMA_STREAM_PRIORITY_VERY_HIGH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_double_buffer_mode(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM0, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM1, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM2, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM3, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM4, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM5, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM6, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 18);
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_double_buffer_mode(_DMA, DMA_STREAM7, DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_current_target(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM0, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM1, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM2, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM3, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM4, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM5, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM6, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_current_target(_DMA, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = (1u << 19);
  dma_stream_set_current_target(_DMA, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = 0xffffffff;
  dma_stream_set_current_target(_DMA, DMA_STREAM7, DMA_STREAM_TARGET_MEMORY0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_periph_burst_transfer(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 21);
  dma_stream_set_periph_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_PERIPH_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_set_memory_burst_transfer(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM0, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM1, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM2, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM3, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM4, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM5, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM6, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b00u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b00u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b01u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b01u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b10u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b10u << 23));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b11u << 23));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x3u << 23);
  dma_stream_set_memory_burst_transfer(_DMA, DMA_STREAM7, DMA_STREAM_MEMORY_BURST_INCR16);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x3u << 23) | (0b11u << 23));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_DMA_CHSEL_4BIT)
void
test_dma_stream_set_channel(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL8);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL9);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL10);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL11);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL12);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL13);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL14);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b1111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0xfu << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL15);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0xfu << 25) | (0b1111u << 25));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_DMA_CHSEL_3BIT)
void
test_dma_stream_set_channel(void)
{
  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM0, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM1, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM2, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM3, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM4, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM5, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM6, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b000u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b000u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b001u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b001u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b010u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b010u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b011u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b011u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b100u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b100u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b101u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b101u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b110u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b110u << 25));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SCR = 0;
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, (0b111u << 25));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SCR = ~(0x7u << 25);
  dma_stream_set_channel(_DMA, DMA_STREAM7, DMA_STREAM_CHANNEL7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SCR, ~(0x7u << 25) | (0b111u << 25));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_dma_stream_set_items_transfer_count(void)
{
  _DMA->streams[DMA_STREAM0].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM0, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM0, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM0, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM0, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM0, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM0].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM0, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _DMA->streams[DMA_STREAM1].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM1, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM1, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM1, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM1, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM1, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM1].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM1, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _DMA->streams[DMA_STREAM2].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM2, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM2, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM2, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM2, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM2, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM2].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM2, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _DMA->streams[DMA_STREAM3].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM3, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM3, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM3, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM3, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM3, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM3].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM3, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _DMA->streams[DMA_STREAM4].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM4, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM4, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM4, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM4, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM4, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM4].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM4, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _DMA->streams[DMA_STREAM5].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM5, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM5, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM5, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM5, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM5, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM5].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM5, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _DMA->streams[DMA_STREAM6].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM6, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM6, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM6, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM6, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM6, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM6].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM6, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _DMA->streams[DMA_STREAM7].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM7, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SNDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM7, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SNDTR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM7, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SNDTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM7, 0xffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SNDTR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SNDTR = 0;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM7, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SNDTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _DMA->streams[DMA_STREAM7].SNDTR = 0xffffffff;
  dma_stream_set_items_transfer_count(_DMA, DMA_STREAM7, 0x10000);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SNDTR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma_stream_set_periph_address(void)
{
  _DMA->streams[DMA_STREAM0].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM0, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM0, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM0, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM0, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM1, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM1, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM1, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM1, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM2, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM2, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM2, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM2, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM3, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM3, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM3, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM3, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM4, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM4, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM4, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM4, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM5, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM5, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM5, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM5, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM6, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM6, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM6, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM6, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM7, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SPAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM7, 0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SPAR, 0);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SPAR = 0;
  dma_stream_set_periph_address(_DMA, DMA_STREAM7, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SPAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SPAR = 0xffffffff;
  dma_stream_set_periph_address(_DMA, DMA_STREAM7, 0xffffffff);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SPAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'fn_set_value (TODO)' (dma_stream_set_memory_address)
void
test_dma_stream_set_fifo_threshold(void)
{
  _DMA->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM1, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM2, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM3, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM4, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM5, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM6, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_1over2_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_3over4_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = ~(0x3u << 0);
  dma_stream_set_fifo_threshold(_DMA, DMA_STREAM7, DMA_STREAM_FIFO_THRESHOLD_FULL);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, ~(0x3u << 0) | ( 0b11u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_direct_mode(void)
{
  _DMA->streams[DMA_STREAM0].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM0);
  ASSERT_EQ(_DMA->streams[DMA_STREAM0].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM1);
  ASSERT_EQ(_DMA->streams[DMA_STREAM1].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM2);
  ASSERT_EQ(_DMA->streams[DMA_STREAM2].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM3);
  ASSERT_EQ(_DMA->streams[DMA_STREAM3].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM4);
  ASSERT_EQ(_DMA->streams[DMA_STREAM4].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM5);
  ASSERT_EQ(_DMA->streams[DMA_STREAM5].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM6);
  ASSERT_EQ(_DMA->streams[DMA_STREAM6].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SFCR = 0;
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = ~(1u << 2);
  dma_stream_direct_mode_enable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = (1u << 2);
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = 0xffffffff;
  dma_stream_direct_mode_disable(_DMA, DMA_STREAM7);
  ASSERT_EQ(_DMA->streams[DMA_STREAM7].SFCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


}

void
test_dma_stream_get_fifo_status(void)
{
  u32 res;

  _DMA->streams[DMA_STREAM0].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM0].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM0);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM1].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM1].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM1);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM2].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM2].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM2);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM3].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM3].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM3);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM4].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM4].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM4);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM5].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM5);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM5].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM5);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM6].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM6);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM6].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM6);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


  _DMA->streams[DMA_STREAM7].SFCR = 0;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = ~(0x7u << 3);
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM7);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _DMA->streams[DMA_STREAM7].SFCR = 0x7u << 3;
  res = dma_stream_get_fifo_status(_DMA, DMA_STREAM7);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
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
