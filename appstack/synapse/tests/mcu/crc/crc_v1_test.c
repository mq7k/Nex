#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/crc/crc_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  CRC = (struct crc_registers_map*) membuf;
}

void
test_crc_data_read(void)
{
  u32 res;

  // read_reg
  CRC->DR = 0;
  res = crc_data_read();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRC->DR = 0xffffffff;
  res = crc_data_read();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_crc_data_write(void)
{
  CRC->DR = 0;
  crc_data_write(0);
  ASSERT_EQ(CRC->DR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  CRC->DR = 0xffffffff;
  crc_data_write(0);
  ASSERT_EQ(CRC->DR, 0);
  ASSERT_FALSE(execution_halted());


  CRC->DR = 0;
  crc_data_write(0xffffffff);
  ASSERT_EQ(CRC->DR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  CRC->DR = 0xffffffff;
  crc_data_write(0xffffffff);
  ASSERT_EQ(CRC->DR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_crc_independent_data_read(void)
{
  u32 res;

  // read_bits
  CRC->IDR = 0;
  res = crc_independent_data_read();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRC->IDR = ~(0xffu << 0);
  res = crc_independent_data_read();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  CRC->IDR = 0xffu << 0;
  res = crc_independent_data_read();
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_crc_independent_data_write(void)
{
  CRC->IDR = 0;
  crc_independent_data_write(0);
  ASSERT_EQ(CRC->IDR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  CRC->IDR = 0xffffffff;
  crc_independent_data_write(0);
  ASSERT_EQ(CRC->IDR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  CRC->IDR = 0;
  crc_independent_data_write(0xff);
  ASSERT_EQ(CRC->IDR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  CRC->IDR = 0xffffffff;
  crc_independent_data_write(0xff);
  ASSERT_EQ(CRC->IDR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  CRC->IDR = 0;
  crc_independent_data_write(0x100);
  ASSERT_EQ(CRC->IDR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  CRC->IDR = 0xffffffff;
  crc_independent_data_write(0x100);
  ASSERT_EQ(CRC->IDR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_crc_reset(void)
{
  CRC->CR = 0;
  crc_reset();
  ASSERT_EQ(CRC->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  CRC->CR = ~(1u << 0);
  crc_reset();
  ASSERT_EQ(CRC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_CRC_REVERSE_DATA)
void
test_crc_set_input_data_reverse(void)
{
  // scope=self.reg='CR', self.shift=5, self.mask='0x3', self.varsmap={'reverse': 'CRC_INPUT_DATA_REVERSE_OFF'}, self.value='0b00', self.ifdef=[], self.halt=False
  CRC->CR = 0;
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_OFF);
  ASSERT_EQ(CRC->CR, (0b00u << 5));
  ASSERT_FALSE(execution_halted());

  CRC->CR = ~(0x3u << 5);
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_OFF);
  ASSERT_EQ(CRC->CR, ~(0x3u << 5) | (0b00u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x3', self.varsmap={'reverse': 'CRC_INPUT_DATA_REVERSE_BYTE'}, self.value='0b01', self.ifdef=[], self.halt=False
  CRC->CR = 0;
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_BYTE);
  ASSERT_EQ(CRC->CR, (0b01u << 5));
  ASSERT_FALSE(execution_halted());

  CRC->CR = ~(0x3u << 5);
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_BYTE);
  ASSERT_EQ(CRC->CR, ~(0x3u << 5) | (0b01u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x3', self.varsmap={'reverse': 'CRC_INPUT_DATA_REVERSE_HALF_WORD'}, self.value='0b10', self.ifdef=[], self.halt=False
  CRC->CR = 0;
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_HALF_WORD);
  ASSERT_EQ(CRC->CR, (0b10u << 5));
  ASSERT_FALSE(execution_halted());

  CRC->CR = ~(0x3u << 5);
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_HALF_WORD);
  ASSERT_EQ(CRC->CR, ~(0x3u << 5) | (0b10u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x3', self.varsmap={'reverse': 'CRC_INPUT_DATA_REVERSE_WORD'}, self.value='0b11', self.ifdef=[], self.halt=False
  CRC->CR = 0;
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_WORD);
  ASSERT_EQ(CRC->CR, (0b11u << 5));
  ASSERT_FALSE(execution_halted());

  CRC->CR = ~(0x3u << 5);
  crc_set_input_data_reverse(CRC, CRC_INPUT_DATA_REVERSE_WORD);
  ASSERT_EQ(CRC->CR, ~(0x3u << 5) | (0b11u << 5));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_CRC_REVERSE_DATA)
void
test_crc_output_data_reverse_enable(void)
{
  CRC->CR = 0;
  crc_output_data_reverse_enable_enable(CRC);
  ASSERT_EQ(CRC->CR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  CRC->CR = ~(1u << 7);
  crc_output_data_reverse_enable_enable(CRC);
  ASSERT_EQ(CRC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  CRC->CR = (1u << 7);
  crc_output_data_reverse_enable_disable(CRC);
  ASSERT_EQ(CRC->CR, 0);
  ASSERT_FALSE(execution_halted());

  CRC->CR = 0xffffffff;
  crc_output_data_reverse_enable_disable(CRC);
  ASSERT_EQ(CRC->CR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_CRC_EXTENDED)
void
test_crc_set_initial_value(void)
{
  CRC->INIT = 0;
  crc_set_initial_value(0);
  ASSERT_EQ(CRC->INIT, 0u << 0);
  ASSERT_FALSE(execution_halted());

  CRC->INIT = 0xffffffff;
  crc_set_initial_value(0);
  ASSERT_EQ(CRC->INIT, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  CRC->INIT = 0;
  crc_set_initial_value(0xffffffff);
  ASSERT_EQ(CRC->INIT, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  CRC->INIT = 0xffffffff;
  crc_set_initial_value(0xffffffff);
  ASSERT_EQ(CRC->INIT, ~(0xffffffffu << 0) | (0xffffffffu << 0));
  ASSERT_FALSE(execution_halted());


}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_crc_data_read),
    TEST_FUNC(test_crc_data_write),
    TEST_FUNC(test_crc_independent_data_read),
    TEST_FUNC(test_crc_independent_data_write),
    TEST_FUNC(test_crc_reset),
#if defined(STM32_CRC_REVERSE_DATA)
    TEST_FUNC(test_crc_set_input_data_reverse),
#endif
#if defined(STM32_CRC_REVERSE_DATA)
    TEST_FUNC(test_crc_output_data_reverse_enable),
#endif
#if defined(STM32_CRC_EXTENDED)
    TEST_FUNC(test_crc_set_initial_value),
#endif
  };

  return TESTS_RUN(tests);
}
