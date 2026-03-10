#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/hash/hash_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  HASH = (struct hash_registers_map*) membuf;
}

void
test_hash_init(void)
{
  HASH->CR = 0;
  hash_init();
  ASSERT_EQ(HASH->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(1u << 2);
  hash_init();
  ASSERT_EQ(HASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_hash_dma(void)
{
  HASH->CR = 0;
  hash_dma_enable();
  ASSERT_EQ(HASH->CR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(1u << 3);
  hash_dma_enable();
  ASSERT_EQ(HASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  HASH->CR = (1u << 3);
  hash_dma_disable();
  ASSERT_EQ(HASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = 0xffffffff;
  hash_dma_disable();
  ASSERT_EQ(HASH->CR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_hash_set_data_type(void)
{
  // scope=self.reg='CR', self.shift=4, self.mask='0x3', self.varsmap={'type': 'HASH_DATA_TYPE_32BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  HASH->CR = 0;
  hash_set_data_type(HASH_DATA_TYPE_32BIT);
  ASSERT_EQ(HASH->CR, (0b00u << 4));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(0x3u << 4);
  hash_set_data_type(HASH_DATA_TYPE_32BIT);
  ASSERT_EQ(HASH->CR, ~(0x3u << 4) | (0b00u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=4, self.mask='0x3', self.varsmap={'type': 'HASH_DATA_TYPE_16BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  HASH->CR = 0;
  hash_set_data_type(HASH_DATA_TYPE_16BIT);
  ASSERT_EQ(HASH->CR, (0b01u << 4));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(0x3u << 4);
  hash_set_data_type(HASH_DATA_TYPE_16BIT);
  ASSERT_EQ(HASH->CR, ~(0x3u << 4) | (0b01u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=4, self.mask='0x3', self.varsmap={'type': 'HASH_DATA_TYPE_8BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  HASH->CR = 0;
  hash_set_data_type(HASH_DATA_TYPE_8BIT);
  ASSERT_EQ(HASH->CR, (0b10u << 4));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(0x3u << 4);
  hash_set_data_type(HASH_DATA_TYPE_8BIT);
  ASSERT_EQ(HASH->CR, ~(0x3u << 4) | (0b10u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=4, self.mask='0x3', self.varsmap={'type': 'HASH_DATA_TYPE_BITSTR'}, self.value='0b11', self.ifdef=[], self.halt=False
  HASH->CR = 0;
  hash_set_data_type(HASH_DATA_TYPE_BITSTR);
  ASSERT_EQ(HASH->CR, (0b11u << 4));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(0x3u << 4);
  hash_set_data_type(HASH_DATA_TYPE_BITSTR);
  ASSERT_EQ(HASH->CR, ~(0x3u << 4) | (0b11u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_hash_set_mode(void)
{
  HASH->CR = 0;
  hash_set_mode(HASH_MODE_HMAC);
  ASSERT_EQ(HASH->CR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(1u << 6);
  hash_set_mode(HASH_MODE_HMAC);
  ASSERT_EQ(HASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  HASH->CR = (1u << 6);
  hash_set_mode(HASH_MODE_HASH);
  ASSERT_EQ(HASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = 0xffffffff;
  hash_set_mode(HASH_MODE_HASH);
  ASSERT_EQ(HASH->CR, 0xffffffff & ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'enum_set (TODO: bit 18)' (hash_set_algorithm)
void
test_hash_get_transferred_word_count(void)
{
  u32 res;

  // read_bits
  HASH->CR = 0;
  res = hash_get_transferred_word_count();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(0xfu << 8);
  res = hash_get_transferred_word_count();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = 0xfu << 8;
  res = hash_get_transferred_word_count();
  ASSERT_EQ(res, 0xf);
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_HASH_MULTI_DMA_TRANSFERS)
void
test_hash_multiple_dma_transfers(void)
{
  HASH->CR = 0;
  hash_multiple_dma_transfers_enable();
  ASSERT_EQ(HASH->CR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(1u << 13);
  hash_multiple_dma_transfers_enable();
  ASSERT_EQ(HASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  HASH->CR = (1u << 13);
  hash_multiple_dma_transfers_disable();
  ASSERT_EQ(HASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = 0xffffffff;
  hash_multiple_dma_transfers_disable();
  ASSERT_EQ(HASH->CR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_HASH_KEY_TYPE)
void
test_hash_set_key_type(void)
{
  HASH->CR = 0;
  hash_set_key_type(HASH_KEY_TYPE_LONG);
  ASSERT_EQ(HASH->CR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(1u << 16);
  hash_set_key_type(HASH_KEY_TYPE_LONG);
  ASSERT_EQ(HASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  HASH->CR = (1u << 16);
  hash_set_key_type(HASH_KEY_TYPE_SHORT);
  ASSERT_EQ(HASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = 0xffffffff;
  hash_set_key_type(HASH_KEY_TYPE_SHORT);
  ASSERT_EQ(HASH->CR, 0xffffffff & ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_hash_write_data(void)
{
  HASH->DIN = 0;
  hash_write_data(0);
  ASSERT_EQ(HASH->DIN, 0u << 0);
  ASSERT_FALSE(execution_halted());

  HASH->DIN = 0xffffffff;
  hash_write_data(0);
  ASSERT_EQ(HASH->DIN, 0);
  ASSERT_FALSE(execution_halted());


  HASH->DIN = 0;
  hash_write_data(0xffffffff);
  ASSERT_EQ(HASH->DIN, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  HASH->DIN = 0xffffffff;
  hash_write_data(0xffffffff);
  ASSERT_EQ(HASH->DIN, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_hash_set_input_valid_bits_count(void)
{
  HASH->STR = 0;
  hash_set_input_valid_bits_count(0);
  ASSERT_EQ(HASH->STR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  HASH->STR = 0xffffffff;
  hash_set_input_valid_bits_count(0);
  ASSERT_EQ(HASH->STR, ~(0x1fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  HASH->STR = 0;
  hash_set_input_valid_bits_count(0x1f);
  ASSERT_EQ(HASH->STR, 0x1fu << 0);
  ASSERT_FALSE(execution_halted());

  HASH->STR = 0xffffffff;
  hash_set_input_valid_bits_count(0x1f);
  ASSERT_EQ(HASH->STR, ~(0x1fu << 0) | (0x1fu << 0));
  ASSERT_FALSE(execution_halted());


  HASH->STR = 0;
  hash_set_input_valid_bits_count(0x20);
  ASSERT_EQ(HASH->STR, 0x20u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  HASH->STR = 0xffffffff;
  hash_set_input_valid_bits_count(0x20);
  ASSERT_EQ(HASH->STR, ~(0x1fu << 0) | (0x20u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_hash_digest_calc_start(void)
{
  HASH->STR = 0;
  hash_digest_calc_start();
  ASSERT_EQ(HASH->STR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  HASH->STR = ~(1u << 8);
  hash_digest_calc_start();
  ASSERT_EQ(HASH->STR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'fn_get (TODO)' (hash_read_digest)
#if defined(STM32_HASH_HR_5BYTES)
void
test_hash_read_digest(void)
{
  u32 res;

  // read_reg
  HASH->HRA[0] = 0;
  res = hash_read_digest(0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->HRA[0] = 0xffffffff;
  res = hash_read_digest(0);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  HASH->HRA[1] = 0;
  res = hash_read_digest(1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->HRA[1] = 0xffffffff;
  res = hash_read_digest(1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  HASH->HRA[2] = 0;
  res = hash_read_digest(2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->HRA[2] = 0xffffffff;
  res = hash_read_digest(2);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  HASH->HRA[3] = 0;
  res = hash_read_digest(3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->HRA[3] = 0xffffffff;
  res = hash_read_digest(3);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  HASH->HRA[4] = 0;
  res = hash_read_digest(4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->HRA[4] = 0xffffffff;
  res = hash_read_digest(4);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_hash_interrupt(void)
{
  HASH->IMR = 0;
  hash_interrupt_enable(HASH_INTERRUPT_DATA_INPUT);
  ASSERT_EQ(HASH->IMR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  HASH->IMR = ~(1u << 0);
  hash_interrupt_enable(HASH_INTERRUPT_DATA_INPUT);
  ASSERT_EQ(HASH->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  HASH->IMR = (1u << 0);
  hash_interrupt_disable(HASH_INTERRUPT_DATA_INPUT);
  ASSERT_EQ(HASH->IMR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->IMR = 0xffffffff;
  hash_interrupt_disable(HASH_INTERRUPT_DATA_INPUT);
  ASSERT_EQ(HASH->IMR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  HASH->IMR = 0;
  hash_interrupt_enable(HASH_INTERRUPT_DIGEST_CALC_COMPLETE);
  ASSERT_EQ(HASH->IMR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  HASH->IMR = ~(1u << 1);
  hash_interrupt_enable(HASH_INTERRUPT_DIGEST_CALC_COMPLETE);
  ASSERT_EQ(HASH->IMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  HASH->IMR = (1u << 1);
  hash_interrupt_disable(HASH_INTERRUPT_DIGEST_CALC_COMPLETE);
  ASSERT_EQ(HASH->IMR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->IMR = 0xffffffff;
  hash_interrupt_disable(HASH_INTERRUPT_DIGEST_CALC_COMPLETE);
  ASSERT_EQ(HASH->IMR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_hash_is_flag_set(void)
{
  u32 res;

  HASH->CR = 0;
  res = hash_is_flag_set(HASH_FLAG_INPUT_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = (1u << 12);
  res = hash_is_flag_set(HASH_FLAG_INPUT_FULL);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  HASH->CR = ~(1u << 12);
  res = hash_is_flag_set(HASH_FLAG_INPUT_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->CR = 0xffffffff;
  res = hash_is_flag_set(HASH_FLAG_INPUT_FULL);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


  HASH->SR = 0;
  res = hash_is_flag_set(HASH_FLAG_DATA_INPUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = (1u << 0);
  res = hash_is_flag_set(HASH_FLAG_DATA_INPUT);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  HASH->SR = ~(1u << 0);
  res = hash_is_flag_set(HASH_FLAG_DATA_INPUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = 0xffffffff;
  res = hash_is_flag_set(HASH_FLAG_DATA_INPUT);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  HASH->SR = 0;
  res = hash_is_flag_set(HASH_FLAG_DATA_OUTPUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = (1u << 1);
  res = hash_is_flag_set(HASH_FLAG_DATA_OUTPUT);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  HASH->SR = ~(1u << 1);
  res = hash_is_flag_set(HASH_FLAG_DATA_OUTPUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = 0xffffffff;
  res = hash_is_flag_set(HASH_FLAG_DATA_OUTPUT);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  HASH->SR = 0;
  res = hash_is_flag_set(HASH_FLAG_DMA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = (1u << 2);
  res = hash_is_flag_set(HASH_FLAG_DMA);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  HASH->SR = ~(1u << 2);
  res = hash_is_flag_set(HASH_FLAG_DMA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = 0xffffffff;
  res = hash_is_flag_set(HASH_FLAG_DMA);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  HASH->SR = 0;
  res = hash_is_flag_set(HASH_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = (1u << 3);
  res = hash_is_flag_set(HASH_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  HASH->SR = ~(1u << 3);
  res = hash_is_flag_set(HASH_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = 0xffffffff;
  res = hash_is_flag_set(HASH_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


}

void
test_hash_flag_clear(void)
{
  HASH->CR = (1u << 12);
  hash_flag_clear(HASH_FLAG_INPUT_FULL);
  ASSERT_EQ(HASH->CR, (1u << 12));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  HASH->CR = 0xffffffff;
  hash_flag_clear(HASH_FLAG_INPUT_FULL);
  ASSERT_EQ(HASH->CR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  HASH->SR = (1u << 0);
  hash_flag_clear(HASH_FLAG_DATA_INPUT);
  ASSERT_EQ(HASH->SR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = 0xffffffff;
  hash_flag_clear(HASH_FLAG_DATA_INPUT);
  ASSERT_EQ(HASH->SR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  HASH->SR = (1u << 1);
  hash_flag_clear(HASH_FLAG_DATA_OUTPUT);
  ASSERT_EQ(HASH->SR, 0);
  ASSERT_FALSE(execution_halted());

  HASH->SR = 0xffffffff;
  hash_flag_clear(HASH_FLAG_DATA_OUTPUT);
  ASSERT_EQ(HASH->SR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  HASH->SR = (1u << 2);
  hash_flag_clear(HASH_FLAG_DMA);
  ASSERT_EQ(HASH->SR, (1u << 2));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  HASH->SR = 0xffffffff;
  hash_flag_clear(HASH_FLAG_DMA);
  ASSERT_EQ(HASH->SR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  HASH->SR = (1u << 3);
  hash_flag_clear(HASH_FLAG_BUSY);
  ASSERT_EQ(HASH->SR, (1u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  HASH->SR = 0xffffffff;
  hash_flag_clear(HASH_FLAG_BUSY);
  ASSERT_EQ(HASH->SR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

// └─Skipping type 'fn_call (TODO)' (hash_dump_all)
// └─Skipping type 'fn_call (TODO)' (hash_restore_all)
int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_hash_init),
    TEST_FUNC(test_hash_dma),
    TEST_FUNC(test_hash_set_data_type),
    TEST_FUNC(test_hash_set_mode),
    TEST_FUNC(test_hash_get_transferred_word_count),
#if defined(STM32_HASH_MULTI_DMA_TRANSFERS)
    TEST_FUNC(test_hash_multiple_dma_transfers),
#endif
#if defined(STM32_HASH_KEY_TYPE)
    TEST_FUNC(test_hash_set_key_type),
#endif
    TEST_FUNC(test_hash_write_data),
    TEST_FUNC(test_hash_set_input_valid_bits_count),
    TEST_FUNC(test_hash_digest_calc_start),
#if defined(STM32_HASH_HR_5BYTES)
    TEST_FUNC(test_hash_read_digest),
#endif
    TEST_FUNC(test_hash_interrupt),
    TEST_FUNC(test_hash_is_flag_set),
    TEST_FUNC(test_hash_flag_clear),
  };

  return TESTS_RUN(tests);
}
