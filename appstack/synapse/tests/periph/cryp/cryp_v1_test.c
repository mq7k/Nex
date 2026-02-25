#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/cryp/cryp_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  CRYP = (struct cryp_registers_map*) membuf;
}

void
test_cryp_set_algorithm_direction(void)
{
  CRYP->CR = 0;
  cryp_set_algorithm_direction(CRYP_ALGORITHM_DIRECTION_DECRYPT);
  ASSERT_EQ(CRYP->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(1u << 2);
  cryp_set_algorithm_direction(CRYP_ALGORITHM_DIRECTION_DECRYPT);
  ASSERT_EQ(CRYP->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  CRYP->CR = (1u << 2);
  cryp_set_algorithm_direction(CRYP_ALGORITHM_DIRECTION_ENCRYPT);
  ASSERT_EQ(CRYP->CR, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->CR = 0xffffffff;
  cryp_set_algorithm_direction(CRYP_ALGORITHM_DIRECTION_ENCRYPT);
  ASSERT_EQ(CRYP->CR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'enum_set (TODO)' (cryp_set_algorithm_mode)
void
test_cryp_set_data_type(void)
{
  // scope=self.reg='CR', self.shift=6, self.mask='0x3', self.varsmap={'type': 'CRYP_DATA_TYPE_32BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_data_type(CRYP_DATA_TYPE_32BIT);
  ASSERT_EQ(CRYP->CR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 6);
  cryp_set_data_type(CRYP_DATA_TYPE_32BIT);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=6, self.mask='0x3', self.varsmap={'type': 'CRYP_DATA_TYPE_16BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_data_type(CRYP_DATA_TYPE_16BIT);
  ASSERT_EQ(CRYP->CR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 6);
  cryp_set_data_type(CRYP_DATA_TYPE_16BIT);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=6, self.mask='0x3', self.varsmap={'type': 'CRYP_DATA_TYPE_8BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_data_type(CRYP_DATA_TYPE_8BIT);
  ASSERT_EQ(CRYP->CR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 6);
  cryp_set_data_type(CRYP_DATA_TYPE_8BIT);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=6, self.mask='0x3', self.varsmap={'type': 'CRYP_DATA_TYPE_BITSTR'}, self.value='0b11', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_data_type(CRYP_DATA_TYPE_BITSTR);
  ASSERT_EQ(CRYP->CR, (0b11u << 6));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 6);
  cryp_set_data_type(CRYP_DATA_TYPE_BITSTR);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 6) | (0b11u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_cryp_set_key_size(void)
{
  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'size': 'CRYP_KEY_SIZE_128BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_key_size(CRYP_KEY_SIZE_128BIT);
  ASSERT_EQ(CRYP->CR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 8);
  cryp_set_key_size(CRYP_KEY_SIZE_128BIT);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'size': 'CRYP_KEY_SIZE_192BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_key_size(CRYP_KEY_SIZE_192BIT);
  ASSERT_EQ(CRYP->CR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 8);
  cryp_set_key_size(CRYP_KEY_SIZE_192BIT);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'size': 'CRYP_KEY_SIZE_256BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_key_size(CRYP_KEY_SIZE_256BIT);
  ASSERT_EQ(CRYP->CR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 8);
  cryp_set_key_size(CRYP_KEY_SIZE_256BIT);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_cryp_fifo_flush(void)
{
  CRYP->CR = 0;
  cryp_fifo_flush();
  ASSERT_EQ(CRYP->CR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(1u << 14);
  cryp_fifo_flush();
  ASSERT_EQ(CRYP->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_cryp(void)
{
  CRYP->CR = 0;
  cryp_enable();
  ASSERT_EQ(CRYP->CR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(1u << 15);
  cryp_enable();
  ASSERT_EQ(CRYP->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  CRYP->CR = (1u << 15);
  cryp_disable();
  ASSERT_EQ(CRYP->CR, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->CR = 0xffffffff;
  cryp_disable();
  ASSERT_EQ(CRYP->CR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_CRYP_ALGO_EXTENDED)
void
test_cryp_set_gcm_phase(void)
{
  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'phase': 'CRYP_GCM_PHASE_INIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_gcm_phase(CRYP_GCM_PHASE_INIT);
  ASSERT_EQ(CRYP->CR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 16);
  cryp_set_gcm_phase(CRYP_GCM_PHASE_INIT);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'phase': 'CRYP_GCM_PHASE_HEADER'}, self.value='0b01', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_gcm_phase(CRYP_GCM_PHASE_HEADER);
  ASSERT_EQ(CRYP->CR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 16);
  cryp_set_gcm_phase(CRYP_GCM_PHASE_HEADER);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'phase': 'CRYP_GCM_PHASE_PAYLOAD'}, self.value='0b10', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_gcm_phase(CRYP_GCM_PHASE_PAYLOAD);
  ASSERT_EQ(CRYP->CR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 16);
  cryp_set_gcm_phase(CRYP_GCM_PHASE_PAYLOAD);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'phase': 'CRYP_GCM_PHASE_FINAL'}, self.value='0b11', self.ifdef=[], self.halt=False
  CRYP->CR = 0;
  cryp_set_gcm_phase(CRYP_GCM_PHASE_FINAL);
  ASSERT_EQ(CRYP->CR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  CRYP->CR = ~(0x3u << 16);
  cryp_set_gcm_phase(CRYP_GCM_PHASE_FINAL);
  ASSERT_EQ(CRYP->CR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_cryp_is_flag_set(void)
{
  u32 res;

  CRYP->SR = 0;
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = (1u << 0);
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_EMPTY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  CRYP->SR = ~(1u << 0);
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = 0xffffffff;
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_EMPTY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  CRYP->SR = 0;
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_NOT_NULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = (1u << 1);
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_NOT_NULL);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  CRYP->SR = ~(1u << 1);
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_NOT_NULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = 0xffffffff;
  res = cryp_is_flag_set(CRYP_FLAG_INPUT_FIFO_NOT_NULL);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  CRYP->SR = 0;
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = (1u << 2);
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  CRYP->SR = ~(1u << 2);
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = 0xffffffff;
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  CRYP->SR = 0;
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = (1u << 3);
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_FULL);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  CRYP->SR = ~(1u << 3);
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = 0xffffffff;
  res = cryp_is_flag_set(CRYP_FLAG_OUTPUT_FIFO_FULL);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  CRYP->SR = 0;
  res = cryp_is_flag_set(CRYP_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = (1u << 4);
  res = cryp_is_flag_set(CRYP_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  CRYP->SR = ~(1u << 4);
  res = cryp_is_flag_set(CRYP_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->SR = 0xffffffff;
  res = cryp_is_flag_set(CRYP_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_cryp_write_input_data(void)
{
  CRYP->DIN = 0;
  cryp_write_input_data(0);
  ASSERT_EQ(CRYP->DIN, 0u << 0);
  ASSERT_FALSE(execution_halted());

  CRYP->DIN = 0xffffffff;
  cryp_write_input_data(0);
  ASSERT_EQ(CRYP->DIN, 0);
  ASSERT_FALSE(execution_halted());


  CRYP->DIN = 0;
  cryp_write_input_data(0xffffffff);
  ASSERT_EQ(CRYP->DIN, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  CRYP->DIN = 0xffffffff;
  cryp_write_input_data(0xffffffff);
  ASSERT_EQ(CRYP->DIN, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_cryp_read_output_data(void)
{
  u32 res;

  // read_reg
  CRYP->DOUT = 0;
  res = cryp_read_output_data();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->DOUT = 0xffffffff;
  res = cryp_read_output_data();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_cryp_dma(void)
{
  CRYP->DMACR = 0;
  cryp_dma_enable(CRYP_DMA_INPUT);
  ASSERT_EQ(CRYP->DMACR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  CRYP->DMACR = ~(1u << 0);
  cryp_dma_enable(CRYP_DMA_INPUT);
  ASSERT_EQ(CRYP->DMACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  CRYP->DMACR = (1u << 0);
  cryp_dma_disable(CRYP_DMA_INPUT);
  ASSERT_EQ(CRYP->DMACR, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->DMACR = 0xffffffff;
  cryp_dma_disable(CRYP_DMA_INPUT);
  ASSERT_EQ(CRYP->DMACR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  CRYP->DMACR = 0;
  cryp_dma_enable(CRYP_DMA_OUTPUT);
  ASSERT_EQ(CRYP->DMACR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  CRYP->DMACR = ~(1u << 1);
  cryp_dma_enable(CRYP_DMA_OUTPUT);
  ASSERT_EQ(CRYP->DMACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  CRYP->DMACR = (1u << 1);
  cryp_dma_disable(CRYP_DMA_OUTPUT);
  ASSERT_EQ(CRYP->DMACR, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->DMACR = 0xffffffff;
  cryp_dma_disable(CRYP_DMA_OUTPUT);
  ASSERT_EQ(CRYP->DMACR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_cryp_interrupt(void)
{
  CRYP->IMSCR = 0;
  cryp_interrupt_enable(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  CRYP->IMSCR = ~(1u << 0);
  cryp_interrupt_enable(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  CRYP->IMSCR = (1u << 0);
  cryp_interrupt_disable(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->IMSCR = 0xffffffff;
  cryp_interrupt_disable(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  CRYP->IMSCR = 0;
  cryp_interrupt_enable(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  CRYP->IMSCR = ~(1u << 1);
  cryp_interrupt_enable(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  CRYP->IMSCR = (1u << 1);
  cryp_interrupt_disable(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->IMSCR = 0xffffffff;
  cryp_interrupt_disable(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(CRYP->IMSCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_cryp_has_interrupt_occurred(void)
{
  u32 res;

  CRYP->RISR = 0;
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->RISR = (1u << 0);
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  CRYP->RISR = ~(1u << 0);
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->RISR = 0xffffffff;
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  CRYP->RISR = 0;
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->RISR = (1u << 1);
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  CRYP->RISR = ~(1u << 1);
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->RISR = 0xffffffff;
  res = cryp_has_interrupt_occurred(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_cryp_is_interrupt_pending(void)
{
  u32 res;

  CRYP->MISR = 0;
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->MISR = (1u << 0);
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  CRYP->MISR = ~(1u << 0);
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->MISR = 0xffffffff;
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_INPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  CRYP->MISR = 0;
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->MISR = (1u << 1);
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  CRYP->MISR = ~(1u << 1);
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRYP->MISR = 0xffffffff;
  res = cryp_is_interrupt_pending(CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type '(TODO)' (cryp_write_key_128bit)
// └─Skipping type '(TODO)' (cryp_write_key_192bit)
// └─Skipping type '(TODO)' (cryp_write_key_256bit)
// └─Skipping type '(TODO)' (cryp_write_iv_64bit)
// └─Skipping type '(TODO)' (cryp_write_iv_128bit)
// └─Skipping type '(TODO)' (cryp_dump_all)
// └─Skipping type '(TODO)' (cryp_restore_all)
int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_cryp_set_algorithm_direction),
    TEST_FUNC(test_cryp_set_data_type),
    TEST_FUNC(test_cryp_set_key_size),
    TEST_FUNC(test_cryp_fifo_flush),
    TEST_FUNC(test_cryp),
#if defined(STM32_CRYP_ALGO_EXTENDED)
    TEST_FUNC(test_cryp_set_gcm_phase),
#endif
    TEST_FUNC(test_cryp_is_flag_set),
    TEST_FUNC(test_cryp_write_input_data),
    TEST_FUNC(test_cryp_read_output_data),
    TEST_FUNC(test_cryp_dma),
    TEST_FUNC(test_cryp_interrupt),
    TEST_FUNC(test_cryp_has_interrupt_occurred),
    TEST_FUNC(test_cryp_is_interrupt_pending),
  };

  return TESTS_RUN(tests);
}
