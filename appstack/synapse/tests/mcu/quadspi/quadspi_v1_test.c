#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/quadspi/quadspi_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  QUADSPI = (struct quadspi_registers_map*) membuf;
}

void
test_quadspi(void)
{
  QUADSPI->CR = 0;
  quadspi_enable();
  ASSERT_EQ(QUADSPI->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 0);
  quadspi_enable();
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 0);
  quadspi_disable();
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_disable();
  ASSERT_EQ(QUADSPI->CR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_abort(void)
{
  QUADSPI->CR = 0;
  quadspi_abort();
  ASSERT_EQ(QUADSPI->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 1);
  quadspi_abort();
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_dma(void)
{
  QUADSPI->CR = 0;
  quadspi_dma_enable();
  ASSERT_EQ(QUADSPI->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 2);
  quadspi_dma_enable();
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 2);
  quadspi_dma_disable();
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_dma_disable();
  ASSERT_EQ(QUADSPI->CR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_timeout_counter(void)
{
  QUADSPI->CR = 0;
  quadspi_timeout_counter_enable();
  ASSERT_EQ(QUADSPI->CR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 3);
  quadspi_timeout_counter_enable();
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 3);
  quadspi_timeout_counter_disable();
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_timeout_counter_disable();
  ASSERT_EQ(QUADSPI->CR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_sample_shift(void)
{
  QUADSPI->CR = 0;
  quadspi_set_sample_shift(QUADSPI_SAMPLE_SHIFT_HALF_SHIFT);
  ASSERT_EQ(QUADSPI->CR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 4);
  quadspi_set_sample_shift(QUADSPI_SAMPLE_SHIFT_HALF_SHIFT);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 4);
  quadspi_set_sample_shift(QUADSPI_SAMPLE_SHIFT_NO_SHIFT);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_set_sample_shift(QUADSPI_SAMPLE_SHIFT_NO_SHIFT);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_dual_flash(void)
{
  QUADSPI->CR = 0;
  quadspi_dual_flash_enable();
  ASSERT_EQ(QUADSPI->CR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 6);
  quadspi_dual_flash_enable();
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 6);
  quadspi_dual_flash_disable();
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_dual_flash_disable();
  ASSERT_EQ(QUADSPI->CR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_select_flash_memory(void)
{
  QUADSPI->CR = 0;
  quadspi_select_flash_memory(QUADSPI_FLASH_MEMORY_FLASH2);
  ASSERT_EQ(QUADSPI->CR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 7);
  quadspi_select_flash_memory(QUADSPI_FLASH_MEMORY_FLASH2);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 7);
  quadspi_select_flash_memory(QUADSPI_FLASH_MEMORY_FLASH1);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_select_flash_memory(QUADSPI_FLASH_MEMORY_FLASH1);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_fifo_threshold_level(void)
{
  QUADSPI->CR = 0;
  quadspi_set_fifo_threshold_level(0);
  ASSERT_EQ(QUADSPI->CR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_set_fifo_threshold_level(0);
  ASSERT_EQ(QUADSPI->CR, ~(0x1fu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_set_fifo_threshold_level(0x1f);
  ASSERT_EQ(QUADSPI->CR, 0x1fu << 8);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_set_fifo_threshold_level(0x1f);
  ASSERT_EQ(QUADSPI->CR, ~(0x1fu << 8) | (0x1fu << 8));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_set_fifo_threshold_level(0x20);
  ASSERT_EQ(QUADSPI->CR, 0x20u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  QUADSPI->CR = 0xffffffff;
  quadspi_set_fifo_threshold_level(0x20);
  ASSERT_EQ(QUADSPI->CR, ~(0x1fu << 8) | (0x20u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_quadspi_interrupt(void)
{
  QUADSPI->CR = 0;
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(QUADSPI->CR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 16);
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 16);
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(QUADSPI->CR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(QUADSPI->CR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 17);
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 17);
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(QUADSPI->CR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_FIFO_THRESHOLD);
  ASSERT_EQ(QUADSPI->CR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 18);
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_FIFO_THRESHOLD);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 18);
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_FIFO_THRESHOLD);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_FIFO_THRESHOLD);
  ASSERT_EQ(QUADSPI->CR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_STATUS_MATCH);
  ASSERT_EQ(QUADSPI->CR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 19);
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_STATUS_MATCH);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 19);
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_STATUS_MATCH);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_STATUS_MATCH);
  ASSERT_EQ(QUADSPI->CR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_TIMEOUT);
  ASSERT_EQ(QUADSPI->CR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 20);
  quadspi_interrupt_enable(QUADSPI_INTERRUPT_TIMEOUT);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 20);
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_TIMEOUT);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_interrupt_disable(QUADSPI_INTERRUPT_TIMEOUT);
  ASSERT_EQ(QUADSPI->CR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_automatic_status_polling_mode(void)
{
  QUADSPI->CR = 0;
  quadspi_set_automatic_status_polling_mode(QUADSPI_POLLING_STOP_MODE_MATCH);
  ASSERT_EQ(QUADSPI->CR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 22);
  quadspi_set_automatic_status_polling_mode(QUADSPI_POLLING_STOP_MODE_MATCH);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 22);
  quadspi_set_automatic_status_polling_mode(QUADSPI_POLLING_STOP_MODE_ONLY_ABORT);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_set_automatic_status_polling_mode(QUADSPI_POLLING_STOP_MODE_ONLY_ABORT);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_polling_match_mode(void)
{
  QUADSPI->CR = 0;
  quadspi_set_polling_match_mode(QUADSPI_POLLING_MATCH_MODE_OR);
  ASSERT_EQ(QUADSPI->CR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = ~(1u << 23);
  quadspi_set_polling_match_mode(QUADSPI_POLLING_MATCH_MODE_OR);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = (1u << 23);
  quadspi_set_polling_match_mode(QUADSPI_POLLING_MATCH_MODE_AND);
  ASSERT_EQ(QUADSPI->CR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_set_polling_match_mode(QUADSPI_POLLING_MATCH_MODE_AND);
  ASSERT_EQ(QUADSPI->CR, 0xffffffff & ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_prescaler(void)
{
  QUADSPI->CR = 0;
  quadspi_set_prescaler(0);
  ASSERT_EQ(QUADSPI->CR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_set_prescaler(0);
  ASSERT_EQ(QUADSPI->CR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_set_prescaler(0xff);
  ASSERT_EQ(QUADSPI->CR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CR = 0xffffffff;
  quadspi_set_prescaler(0xff);
  ASSERT_EQ(QUADSPI->CR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CR = 0;
  quadspi_set_prescaler(0x100);
  ASSERT_EQ(QUADSPI->CR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  QUADSPI->CR = 0xffffffff;
  quadspi_set_prescaler(0x100);
  ASSERT_EQ(QUADSPI->CR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_quadspi_set_clock_mode(void)
{
  QUADSPI->DCR = 0;
  quadspi_set_clock_mode(QUADSPI_CLOCK_MODE_MODE3);
  ASSERT_EQ(QUADSPI->DCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  QUADSPI->DCR = ~(1u << 0);
  quadspi_set_clock_mode(QUADSPI_CLOCK_MODE_MODE3);
  ASSERT_EQ(QUADSPI->DCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->DCR = (1u << 0);
  quadspi_set_clock_mode(QUADSPI_CLOCK_MODE_MODE0);
  ASSERT_EQ(QUADSPI->DCR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->DCR = 0xffffffff;
  quadspi_set_clock_mode(QUADSPI_CLOCK_MODE_MODE0);
  ASSERT_EQ(QUADSPI->DCR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_cs_min_high_cycles_count(void)
{
  QUADSPI->DCR = 0;
  quadspi_set_cs_min_high_cycles_count(0);
  ASSERT_EQ(QUADSPI->DCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  QUADSPI->DCR = 0xffffffff;
  quadspi_set_cs_min_high_cycles_count(0);
  ASSERT_EQ(QUADSPI->DCR, ~(0x7u << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  QUADSPI->DCR = 0;
  quadspi_set_cs_min_high_cycles_count(0x7);
  ASSERT_EQ(QUADSPI->DCR, 0x7u << 8);
  ASSERT_FALSE(execution_halted());

  QUADSPI->DCR = 0xffffffff;
  quadspi_set_cs_min_high_cycles_count(0x7);
  ASSERT_EQ(QUADSPI->DCR, ~(0x7u << 8) | (0x7u << 8));
  ASSERT_FALSE(execution_halted());


  QUADSPI->DCR = 0;
  quadspi_set_cs_min_high_cycles_count(0x8);
  ASSERT_EQ(QUADSPI->DCR, 0x8u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  QUADSPI->DCR = 0xffffffff;
  quadspi_set_cs_min_high_cycles_count(0x8);
  ASSERT_EQ(QUADSPI->DCR, ~(0x7u << 8) | (0x8u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_quadspi_set_address_bits(void)
{
  QUADSPI->DCR = 0;
  quadspi_set_address_bits(0);
  ASSERT_EQ(QUADSPI->DCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  QUADSPI->DCR = 0xffffffff;
  quadspi_set_address_bits(0);
  ASSERT_EQ(QUADSPI->DCR, ~(0x1fu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  QUADSPI->DCR = 0;
  quadspi_set_address_bits(0x1f);
  ASSERT_EQ(QUADSPI->DCR, 0x1fu << 16);
  ASSERT_FALSE(execution_halted());

  QUADSPI->DCR = 0xffffffff;
  quadspi_set_address_bits(0x1f);
  ASSERT_EQ(QUADSPI->DCR, ~(0x1fu << 16) | (0x1fu << 16));
  ASSERT_FALSE(execution_halted());


  QUADSPI->DCR = 0;
  quadspi_set_address_bits(0x20);
  ASSERT_EQ(QUADSPI->DCR, 0x20u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  QUADSPI->DCR = 0xffffffff;
  quadspi_set_address_bits(0x20);
  ASSERT_EQ(QUADSPI->DCR, ~(0x1fu << 16) | (0x20u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_quadspi_is_flag_set(void)
{
  u32 res;

  QUADSPI->SR = 0;
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = (1u << 0);
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = ~(1u << 0);
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = 0xffffffff;
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  QUADSPI->SR = 0;
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = (1u << 1);
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = ~(1u << 1);
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = 0xffffffff;
  res = quadspi_is_flag_set(QUADSPI_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  QUADSPI->SR = 0;
  res = quadspi_is_flag_set(QUADSPI_FLAG_FIFO_THRESHOLD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = (1u << 2);
  res = quadspi_is_flag_set(QUADSPI_FLAG_FIFO_THRESHOLD);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = ~(1u << 2);
  res = quadspi_is_flag_set(QUADSPI_FLAG_FIFO_THRESHOLD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = 0xffffffff;
  res = quadspi_is_flag_set(QUADSPI_FLAG_FIFO_THRESHOLD);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  QUADSPI->SR = 0;
  res = quadspi_is_flag_set(QUADSPI_FLAG_STATUS_MATCH);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = (1u << 3);
  res = quadspi_is_flag_set(QUADSPI_FLAG_STATUS_MATCH);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = ~(1u << 3);
  res = quadspi_is_flag_set(QUADSPI_FLAG_STATUS_MATCH);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = 0xffffffff;
  res = quadspi_is_flag_set(QUADSPI_FLAG_STATUS_MATCH);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  QUADSPI->SR = 0;
  res = quadspi_is_flag_set(QUADSPI_FLAG_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = (1u << 4);
  res = quadspi_is_flag_set(QUADSPI_FLAG_TIMEOUT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = ~(1u << 4);
  res = quadspi_is_flag_set(QUADSPI_FLAG_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = 0xffffffff;
  res = quadspi_is_flag_set(QUADSPI_FLAG_TIMEOUT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  QUADSPI->SR = 0;
  res = quadspi_is_flag_set(QUADSPI_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = (1u << 5);
  res = quadspi_is_flag_set(QUADSPI_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = ~(1u << 5);
  res = quadspi_is_flag_set(QUADSPI_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = 0xffffffff;
  res = quadspi_is_flag_set(QUADSPI_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_get_fifo_bytes_count(void)
{
  u32 res;

  // read_bits
  QUADSPI->SR = 0;
  res = quadspi_get_fifo_bytes_count();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = ~(0x3fu << 8);
  res = quadspi_get_fifo_bytes_count();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->SR = 0x3fu << 8;
  res = quadspi_get_fifo_bytes_count();
  ASSERT_EQ(res, 0x3f);
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_flag_clear(void)
{
  QUADSPI->FCR = 0;
  quadspi_flag_clear(QUADSPI_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(QUADSPI->FCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  QUADSPI->FCR = ~(1u << 0);
  quadspi_flag_clear(QUADSPI_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(QUADSPI->FCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  QUADSPI->FCR = 0;
  quadspi_flag_clear(QUADSPI_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(QUADSPI->FCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  QUADSPI->FCR = ~(1u << 1);
  quadspi_flag_clear(QUADSPI_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(QUADSPI->FCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  QUADSPI->FCR = 0;
  quadspi_flag_clear(QUADSPI_FLAG_STATUS_MATCH);
  ASSERT_EQ(QUADSPI->FCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  QUADSPI->FCR = ~(1u << 3);
  quadspi_flag_clear(QUADSPI_FLAG_STATUS_MATCH);
  ASSERT_EQ(QUADSPI->FCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  QUADSPI->FCR = 0;
  quadspi_flag_clear(QUADSPI_FLAG_TIMEOUT);
  ASSERT_EQ(QUADSPI->FCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  QUADSPI->FCR = ~(1u << 4);
  quadspi_flag_clear(QUADSPI_FLAG_TIMEOUT);
  ASSERT_EQ(QUADSPI->FCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_transfer_bytes_count(void)
{
  QUADSPI->DLR = 0;
  quadspi_set_transfer_bytes_count(0);
  ASSERT_EQ(QUADSPI->DLR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_instruction(void)
{
  QUADSPI->CCR = 0;
  quadspi_set_instruction(0);
  ASSERT_EQ(QUADSPI->CCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_instruction(0);
  ASSERT_EQ(QUADSPI->CCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CCR = 0;
  quadspi_set_instruction(0xff);
  ASSERT_EQ(QUADSPI->CCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_instruction(0xff);
  ASSERT_EQ(QUADSPI->CCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CCR = 0;
  quadspi_set_instruction(0x100);
  ASSERT_EQ(QUADSPI->CCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_instruction(0x100);
  ASSERT_EQ(QUADSPI->CCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_quadspi_set_intruction_mode(void)
{
  // scope=self.reg='CCR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_INTRUCTION_MODE_NO_INSTRUCTION'}, self.value='0b00', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_NO_INSTRUCTION);
  ASSERT_EQ(QUADSPI->CCR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 8);
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_NO_INSTRUCTION);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_INTRUCTION_MODE_1LINE'}, self.value='0b01', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 8);
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_INTRUCTION_MODE_2LINES'}, self.value='0b10', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 8);
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=8, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_INTRUCTION_MODE_4LINES'}, self.value='0b11', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 8);
  quadspi_set_intruction_mode(QUADSPI_INTRUCTION_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_address_mode(void)
{
  // scope=self.reg='CCR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ADDRESS_MODE_NO_ADDRESS'}, self.value='0b00', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_NO_ADDRESS);
  ASSERT_EQ(QUADSPI->CCR, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 10);
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_NO_ADDRESS);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ADDRESS_MODE_1LINE'}, self.value='0b01', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, (0b01u << 10));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 10);
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 10) | (0b01u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ADDRESS_MODE_2LINES'}, self.value='0b10', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b10u << 10));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 10);
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 10) | (0b10u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ADDRESS_MODE_4LINES'}, self.value='0b11', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b11u << 10));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 10);
  quadspi_set_address_mode(QUADSPI_ADDRESS_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 10) | (0b11u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_address_size(void)
{
  // scope=self.reg='CCR', self.shift=12, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ADDRESS_SIZE_8BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_8BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b00u << 12));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 12);
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_8BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 12) | (0b00u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=12, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ADDRESS_SIZE_16BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_16BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b01u << 12));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 12);
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_16BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 12) | (0b01u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=12, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ADDRESS_SIZE_24BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_24BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b10u << 12));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 12);
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_24BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 12) | (0b10u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=12, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ADDRESS_SIZE_32BIT'}, self.value='0b11', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_32BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b11u << 12));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 12);
  quadspi_set_address_size(QUADSPI_ADDRESS_SIZE_32BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 12) | (0b11u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_alternate_byte_mode(void)
{
  // scope=self.reg='CCR', self.shift=14, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ALTERNATE_BYTE_MODE_NO_ALTERNATE'}, self.value='0b00', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_NO_ALTERNATE);
  ASSERT_EQ(QUADSPI->CCR, (0b00u << 14));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 14);
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_NO_ALTERNATE);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 14) | (0b00u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=14, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ALTERNATE_BYTE_MODE_1LINE'}, self.value='0b01', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, (0b01u << 14));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 14);
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 14) | (0b01u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=14, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ALTERNATE_BYTE_MODE_2LINES'}, self.value='0b10', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b10u << 14));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 14);
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 14) | (0b10u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=14, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_ALTERNATE_BYTE_MODE_4LINES'}, self.value='0b11', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b11u << 14));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 14);
  quadspi_set_alternate_byte_mode(QUADSPI_ALTERNATE_BYTE_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 14) | (0b11u << 14));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_alternate_byte_size(void)
{
  // scope=self.reg='CCR', self.shift=16, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ALTERNATE_BYTE_SIZE_8BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_8BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 16);
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_8BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=16, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ALTERNATE_BYTE_SIZE_16BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_16BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 16);
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_16BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=16, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ALTERNATE_BYTE_SIZE_24BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_24BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 16);
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_24BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=16, self.mask='0x3', self.varsmap={'size': 'QUADSPI_ALTERNATE_BYTE_SIZE_32BIT'}, self.value='0b11', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_32BIT);
  ASSERT_EQ(QUADSPI->CCR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 16);
  quadspi_set_alternate_byte_size(QUADSPI_ALTERNATE_BYTE_SIZE_32BIT);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_dummy_cycles_count(void)
{
  QUADSPI->CCR = 0;
  quadspi_set_dummy_cycles_count(0);
  ASSERT_EQ(QUADSPI->CCR, 0u << 18);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_dummy_cycles_count(0);
  ASSERT_EQ(QUADSPI->CCR, ~(0x1fu << 18) | (0u << 18));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CCR = 0;
  quadspi_set_dummy_cycles_count(0x1f);
  ASSERT_EQ(QUADSPI->CCR, 0x1fu << 18);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_dummy_cycles_count(0x1f);
  ASSERT_EQ(QUADSPI->CCR, ~(0x1fu << 18) | (0x1fu << 18));
  ASSERT_FALSE(execution_halted());


  QUADSPI->CCR = 0;
  quadspi_set_dummy_cycles_count(0x20);
  ASSERT_EQ(QUADSPI->CCR, 0x20u << 18);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_dummy_cycles_count(0x20);
  ASSERT_EQ(QUADSPI->CCR, ~(0x1fu << 18) | (0x20u << 18));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_quadspi_set_data_mode(void)
{
  // scope=self.reg='CCR', self.shift=24, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_DATA_MODE_NO_DATA'}, self.value='0b00', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_data_mode(QUADSPI_DATA_MODE_NO_DATA);
  ASSERT_EQ(QUADSPI->CCR, (0b00u << 24));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 24);
  quadspi_set_data_mode(QUADSPI_DATA_MODE_NO_DATA);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 24) | (0b00u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=24, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_DATA_MODE_1LINE'}, self.value='0b01', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_data_mode(QUADSPI_DATA_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, (0b01u << 24));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 24);
  quadspi_set_data_mode(QUADSPI_DATA_MODE_1LINE);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 24) | (0b01u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=24, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_DATA_MODE_2LINES'}, self.value='0b10', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_data_mode(QUADSPI_DATA_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b10u << 24));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 24);
  quadspi_set_data_mode(QUADSPI_DATA_MODE_2LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 24) | (0b10u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=24, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_DATA_MODE_4LINES'}, self.value='0b11', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_data_mode(QUADSPI_DATA_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, (0b11u << 24));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 24);
  quadspi_set_data_mode(QUADSPI_DATA_MODE_4LINES);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 24) | (0b11u << 24));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_functional_mode(void)
{
  // scope=self.reg='CCR', self.shift=26, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_FUNCTIONAL_MODE_INDIRECT_WRITE'}, self.value='0b00', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_INDIRECT_WRITE);
  ASSERT_EQ(QUADSPI->CCR, (0b00u << 26));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 26);
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_INDIRECT_WRITE);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 26) | (0b00u << 26));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=26, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_FUNCTIONAL_MODE_INDIRECT_READ'}, self.value='0b01', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_INDIRECT_READ);
  ASSERT_EQ(QUADSPI->CCR, (0b01u << 26));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 26);
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_INDIRECT_READ);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 26) | (0b01u << 26));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=26, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_FUNCTIONAL_MODE_AUTOMATIC_STATUS_POLLING'}, self.value='0b10', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_AUTOMATIC_STATUS_POLLING);
  ASSERT_EQ(QUADSPI->CCR, (0b10u << 26));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 26);
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_AUTOMATIC_STATUS_POLLING);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 26) | (0b10u << 26));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCR', self.shift=26, self.mask='0x3', self.varsmap={'mode': 'QUADSPI_FUNCTIONAL_MODE_MEMORY_MAPPED'}, self.value='0b11', self.ifdef=[], self.halt=False
  QUADSPI->CCR = 0;
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_MEMORY_MAPPED);
  ASSERT_EQ(QUADSPI->CCR, (0b11u << 26));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(0x3u << 26);
  quadspi_set_functional_mode(QUADSPI_FUNCTIONAL_MODE_MEMORY_MAPPED);
  ASSERT_EQ(QUADSPI->CCR, ~(0x3u << 26) | (0b11u << 26));
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_send_instruction_mode(void)
{
  QUADSPI->CCR = 0;
  quadspi_set_send_instruction_mode(QUADSPI_SEND_INSTRUCTION_MODE_FIRST_CMD_ONLY);
  ASSERT_EQ(QUADSPI->CCR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(1u << 28);
  quadspi_set_send_instruction_mode(QUADSPI_SEND_INSTRUCTION_MODE_FIRST_CMD_ONLY);
  ASSERT_EQ(QUADSPI->CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = (1u << 28);
  quadspi_set_send_instruction_mode(QUADSPI_SEND_INSTRUCTION_MODE_EVERY_TRANSACTION);
  ASSERT_EQ(QUADSPI->CCR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_send_instruction_mode(QUADSPI_SEND_INSTRUCTION_MODE_EVERY_TRANSACTION);
  ASSERT_EQ(QUADSPI->CCR, 0xffffffff & ~(1u << 28));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_double_data_rate_delay_mode(void)
{
  QUADSPI->CCR = 0;
  quadspi_set_double_data_rate_delay_mode(QUADSPI_DATA_DELAY_1over4_CLK_CYCLE);
  ASSERT_EQ(QUADSPI->CCR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(1u << 30);
  quadspi_set_double_data_rate_delay_mode(QUADSPI_DATA_DELAY_1over4_CLK_CYCLE);
  ASSERT_EQ(QUADSPI->CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = (1u << 30);
  quadspi_set_double_data_rate_delay_mode(QUADSPI_DATA_DELAY_ANALOG_DELAY);
  ASSERT_EQ(QUADSPI->CCR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = 0xffffffff;
  quadspi_set_double_data_rate_delay_mode(QUADSPI_DATA_DELAY_ANALOG_DELAY);
  ASSERT_EQ(QUADSPI->CCR, 0xffffffff & ~(1u << 30));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_double_data_rate(void)
{
  QUADSPI->CCR = 0;
  quadspi_double_data_rate_enable();
  ASSERT_EQ(QUADSPI->CCR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = ~(1u << 31);
  quadspi_double_data_rate_enable();
  ASSERT_EQ(QUADSPI->CCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = (1u << 31);
  quadspi_double_data_rate_disable();
  ASSERT_EQ(QUADSPI->CCR, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->CCR = 0xffffffff;
  quadspi_double_data_rate_disable();
  ASSERT_EQ(QUADSPI->CCR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_flash_address(void)
{
  QUADSPI->AR = 0;
  quadspi_set_flash_address(0);
  ASSERT_EQ(QUADSPI->AR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_alternate_bytes(void)
{
  QUADSPI->ABR = 0;
  quadspi_set_alternate_bytes(0);
  ASSERT_EQ(QUADSPI->ABR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_data_write(void)
{
  QUADSPI->DR = 0;
  quadspi_data_write(0);
  ASSERT_EQ(QUADSPI->DR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_data_read(void)
{
  u32 res;

  // read_reg
  QUADSPI->DR = 0;
  res = quadspi_data_read();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  QUADSPI->DR = 0xffffffff;
  res = quadspi_data_read();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_quadspi_set_status_byte_mask(void)
{
  QUADSPI->PSMKR = 0;
  quadspi_set_status_byte_mask(0);
  ASSERT_EQ(QUADSPI->PSMKR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_status_match(void)
{
  QUADSPI->PSMAR = 0;
  quadspi_set_status_match(0);
  ASSERT_EQ(QUADSPI->PSMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_quadspi_set_polling_interval(void)
{
  QUADSPI->PIR = 0;
  quadspi_set_polling_interval(0);
  ASSERT_EQ(QUADSPI->PIR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  QUADSPI->PIR = 0;
  quadspi_set_polling_interval(0xffff);
  ASSERT_EQ(QUADSPI->PIR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  QUADSPI->PIR = 0;
  quadspi_set_polling_interval(0x10000);
  ASSERT_EQ(QUADSPI->PIR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_quadspi_set_timeout_period(void)
{
  QUADSPI->LPTR = 0;
  quadspi_set_timeout_period(0);
  ASSERT_EQ(QUADSPI->LPTR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  QUADSPI->LPTR = 0;
  quadspi_set_timeout_period(0xffff);
  ASSERT_EQ(QUADSPI->LPTR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  QUADSPI->LPTR = 0;
  quadspi_set_timeout_period(0x10000);
  ASSERT_EQ(QUADSPI->LPTR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_quadspi),
    TEST_FUNC(test_quadspi_abort),
    TEST_FUNC(test_quadspi_dma),
    TEST_FUNC(test_quadspi_timeout_counter),
    TEST_FUNC(test_quadspi_set_sample_shift),
    TEST_FUNC(test_quadspi_dual_flash),
    TEST_FUNC(test_quadspi_select_flash_memory),
    TEST_FUNC(test_quadspi_set_fifo_threshold_level),
    TEST_FUNC(test_quadspi_interrupt),
    TEST_FUNC(test_quadspi_set_automatic_status_polling_mode),
    TEST_FUNC(test_quadspi_set_polling_match_mode),
    TEST_FUNC(test_quadspi_set_prescaler),
    TEST_FUNC(test_quadspi_set_clock_mode),
    TEST_FUNC(test_quadspi_set_cs_min_high_cycles_count),
    TEST_FUNC(test_quadspi_set_address_bits),
    TEST_FUNC(test_quadspi_is_flag_set),
    TEST_FUNC(test_quadspi_get_fifo_bytes_count),
    TEST_FUNC(test_quadspi_flag_clear),
    TEST_FUNC(test_quadspi_set_transfer_bytes_count),
    TEST_FUNC(test_quadspi_set_instruction),
    TEST_FUNC(test_quadspi_set_intruction_mode),
    TEST_FUNC(test_quadspi_set_address_mode),
    TEST_FUNC(test_quadspi_set_address_size),
    TEST_FUNC(test_quadspi_set_alternate_byte_mode),
    TEST_FUNC(test_quadspi_set_alternate_byte_size),
    TEST_FUNC(test_quadspi_set_dummy_cycles_count),
    TEST_FUNC(test_quadspi_set_data_mode),
    TEST_FUNC(test_quadspi_set_functional_mode),
    TEST_FUNC(test_quadspi_set_send_instruction_mode),
    TEST_FUNC(test_quadspi_set_double_data_rate_delay_mode),
    TEST_FUNC(test_quadspi_double_data_rate),
    TEST_FUNC(test_quadspi_set_flash_address),
    TEST_FUNC(test_quadspi_set_alternate_bytes),
    TEST_FUNC(test_quadspi_data_write),
    TEST_FUNC(test_quadspi_data_read),
    TEST_FUNC(test_quadspi_set_status_byte_mask),
    TEST_FUNC(test_quadspi_set_status_match),
    TEST_FUNC(test_quadspi_set_polling_interval),
    TEST_FUNC(test_quadspi_set_timeout_period),
  };

  return TESTS_RUN(tests);
}
