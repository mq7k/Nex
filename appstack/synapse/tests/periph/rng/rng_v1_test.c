#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/rng/rng_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  RNG = (struct rng_registers_map*) membuf;
}

void
test_rng(void)
{
  RNG->CR = 0;
  rng_enable();
  ASSERT_EQ(RNG->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RNG->CR = ~(1u << 2);
  rng_enable();
  ASSERT_EQ(RNG->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RNG->CR = (1u << 2);
  rng_disable();
  ASSERT_EQ(RNG->CR, 0);
  ASSERT_FALSE(execution_halted());

  RNG->CR = 0xffffffff;
  rng_disable();
  ASSERT_EQ(RNG->CR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_rng_interrupt_toggle(void)
{
  RNG->CR = 0;
  rng_interrupt_enable();
  ASSERT_EQ(RNG->CR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RNG->CR = ~(1u << 3);
  rng_interrupt_enable();
  ASSERT_EQ(RNG->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RNG->CR = (1u << 3);
  rng_interrupt_disable();
  ASSERT_EQ(RNG->CR, 0);
  ASSERT_FALSE(execution_halted());

  RNG->CR = 0xffffffff;
  rng_interrupt_disable();
  ASSERT_EQ(RNG->CR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_RNG_CK_ERRDE)
void
test_rng_clock_error_detection(void)
{
  RNG->CR = 0;
  rng_clock_error_detection_enable();
  ASSERT_EQ(RNG->CR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RNG->CR = ~(1u << 5);
  rng_clock_error_detection_enable();
  ASSERT_EQ(RNG->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RNG->CR = (1u << 5);
  rng_clock_error_detection_disable();
  ASSERT_EQ(RNG->CR, 0);
  ASSERT_FALSE(execution_halted());

  RNG->CR = 0xffffffff;
  rng_clock_error_detection_disable();
  ASSERT_EQ(RNG->CR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_rng_is_flag_set(void)
{
  u32 res;

  RNG->SR = 0;
  res = rng_is_flag_set(RNG_FLAG_DATA_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = (1u << 0);
  res = rng_is_flag_set(RNG_FLAG_DATA_READY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RNG->SR = ~(1u << 0);
  res = rng_is_flag_set(RNG_FLAG_DATA_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = 0xffffffff;
  res = rng_is_flag_set(RNG_FLAG_DATA_READY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  RNG->SR = 0;
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR_CURRENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = (1u << 1);
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR_CURRENT);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RNG->SR = ~(1u << 1);
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR_CURRENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = 0xffffffff;
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR_CURRENT);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RNG->SR = 0;
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR_CURRENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = (1u << 2);
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR_CURRENT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RNG->SR = ~(1u << 2);
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR_CURRENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = 0xffffffff;
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR_CURRENT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  RNG->SR = 0;
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = (1u << 5);
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RNG->SR = ~(1u << 5);
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = 0xffffffff;
  res = rng_is_flag_set(RNG_FLAG_CLOCK_ERROR);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  RNG->SR = 0;
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = (1u << 6);
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RNG->SR = ~(1u << 6);
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = 0xffffffff;
  res = rng_is_flag_set(RNG_FLAG_SEED_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_rng_flag_clear(void)
{
  RNG->SR = (1u << 0);
  rng_flag_clear(RNG_FLAG_DATA_READY);
  ASSERT_EQ(RNG->SR, (1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RNG->SR = 0xffffffff;
  rng_flag_clear(RNG_FLAG_DATA_READY);
  ASSERT_EQ(RNG->SR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RNG->SR = (1u << 1);
  rng_flag_clear(RNG_FLAG_CLOCK_ERROR_CURRENT);
  ASSERT_EQ(RNG->SR, (1u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RNG->SR = 0xffffffff;
  rng_flag_clear(RNG_FLAG_CLOCK_ERROR_CURRENT);
  ASSERT_EQ(RNG->SR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RNG->SR = (1u << 2);
  rng_flag_clear(RNG_FLAG_SEED_ERROR_CURRENT);
  ASSERT_EQ(RNG->SR, (1u << 2));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RNG->SR = 0xffffffff;
  rng_flag_clear(RNG_FLAG_SEED_ERROR_CURRENT);
  ASSERT_EQ(RNG->SR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RNG->SR = (1u << 5);
  rng_flag_clear(RNG_FLAG_CLOCK_ERROR);
  ASSERT_EQ(RNG->SR, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = 0xffffffff;
  rng_flag_clear(RNG_FLAG_CLOCK_ERROR);
  ASSERT_EQ(RNG->SR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  RNG->SR = (1u << 6);
  rng_flag_clear(RNG_FLAG_SEED_ERROR);
  ASSERT_EQ(RNG->SR, 0);
  ASSERT_FALSE(execution_halted());

  RNG->SR = 0xffffffff;
  rng_flag_clear(RNG_FLAG_SEED_ERROR);
  ASSERT_EQ(RNG->SR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_rng_get_random_32bit(void)
{
  u32 res;

  // read_reg
  RNG->DR = 0;
  res = rng_get_random_32bit();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RNG->DR = 0xffffffff;
  res = rng_get_random_32bit();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_rng),
    TEST_FUNC(test_rng_interrupt_toggle),
#if defined(STM32_RNG_CK_ERRDE)
    TEST_FUNC(test_rng_clock_error_detection),
#endif
    TEST_FUNC(test_rng_is_flag_set),
    TEST_FUNC(test_rng_flag_clear),
    TEST_FUNC(test_rng_get_random_32bit),
  };

  return TESTS_RUN(tests);
}
