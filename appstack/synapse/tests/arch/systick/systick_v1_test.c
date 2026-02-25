#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/arch/cortex/drivers/systick/systick_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  SYSTICK = (struct systick_registers_map*) membuf;
}

void
test_systick(void)
{
  SYSTICK->CSR = 0;
  systick_enable();
  ASSERT_EQ(SYSTICK->CSR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = ~(1u << 0);
  systick_enable();
  ASSERT_EQ(SYSTICK->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = (1u << 0);
  systick_disable();
  ASSERT_EQ(SYSTICK->CSR, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = 0xffffffff;
  systick_disable();
  ASSERT_EQ(SYSTICK->CSR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_systick_interrupt(void)
{
  SYSTICK->CSR = 0;
  systick_interrupt_enable();
  ASSERT_EQ(SYSTICK->CSR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = ~(1u << 1);
  systick_interrupt_enable();
  ASSERT_EQ(SYSTICK->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = (1u << 1);
  systick_interrupt_disable();
  ASSERT_EQ(SYSTICK->CSR, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = 0xffffffff;
  systick_interrupt_disable();
  ASSERT_EQ(SYSTICK->CSR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_systick_set_clock_source(void)
{
  SYSTICK->CSR = 0;
  systick_set_clock_source(SYSTICK_CLOCK_SOURCE_PROCESSOR);
  ASSERT_EQ(SYSTICK->CSR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = ~(1u << 2);
  systick_set_clock_source(SYSTICK_CLOCK_SOURCE_PROCESSOR);
  ASSERT_EQ(SYSTICK->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = (1u << 2);
  systick_set_clock_source(SYSTICK_CLOCK_SOURCE_EXTERNAL);
  ASSERT_EQ(SYSTICK->CSR, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = 0xffffffff;
  systick_set_clock_source(SYSTICK_CLOCK_SOURCE_EXTERNAL);
  ASSERT_EQ(SYSTICK->CSR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_systick_has_overflowed(void)
{
  u32 res;

  // read_bit
  SYSTICK->CSR = 0;
  res = systick_has_overflowed();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = ~(0x1u << 16);
  res = systick_has_overflowed();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CSR = 0x1u << 16;
  res = systick_has_overflowed();
  ASSERT_EQ(res, 0x1u << 16);
  ASSERT_FALSE(execution_halted());

}

void
test_systick_set_reload_value(void)
{
  SYSTICK->RVR = 0;
  systick_set_reload_value(0);
  ASSERT_EQ(SYSTICK->RVR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  SYSTICK->RVR = 0;
  systick_set_reload_value(0xffffff);
  ASSERT_EQ(SYSTICK->RVR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());


  SYSTICK->RVR = 0;
  systick_set_reload_value(0x1000000);
  ASSERT_EQ(SYSTICK->RVR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_systick_set_current_value(void)
{
  SYSTICK->CVR = 0;
  systick_set_current_value(0);
  ASSERT_EQ(SYSTICK->CVR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  SYSTICK->CVR = 0;
  systick_set_current_value(0xffffff);
  ASSERT_EQ(SYSTICK->CVR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());


  SYSTICK->CVR = 0;
  systick_set_current_value(0x1000000);
  ASSERT_EQ(SYSTICK->CVR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_systick_get_current_value(void)
{
  u32 res;

  // read_bits
  SYSTICK->CVR = 0;
  res = systick_get_current_value();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CVR = ~(0xffffffu << 0);
  res = systick_get_current_value();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CVR = 0xffffffu << 0;
  res = systick_get_current_value();
  ASSERT_EQ(res, 0xffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_systick_get_calibration_value(void)
{
  u32 res;

  // read_bits
  SYSTICK->CALIB = 0;
  res = systick_get_calibration_value();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CALIB = ~(0xffffffu << 0);
  res = systick_get_calibration_value();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CALIB = 0xffffffu << 0;
  res = systick_get_calibration_value();
  ASSERT_EQ(res, 0xffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_systick_is_calibration_value_available(void)
{
  u32 res;

  // read_bit
  SYSTICK->CALIB = 0;
  res = systick_is_calibration_value_available();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CALIB = ~(0x1u << 30);
  res = systick_is_calibration_value_available();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CALIB = 0x1u << 30;
  res = systick_is_calibration_value_available();
  ASSERT_EQ(res, 0x1u << 30);
  ASSERT_FALSE(execution_halted());

}

void
test_systick_has_reference_clock(void)
{
  u32 res;

  // read_bit
  SYSTICK->CALIB = 0;
  res = systick_has_reference_clock();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CALIB = ~(0x1u << 31);
  res = systick_has_reference_clock();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSTICK->CALIB = 0x1u << 31;
  res = systick_has_reference_clock();
  ASSERT_EQ(res, 0x1u << 31);
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_systick),
    TEST_FUNC(test_systick_interrupt),
    TEST_FUNC(test_systick_set_clock_source),
    TEST_FUNC(test_systick_has_overflowed),
    TEST_FUNC(test_systick_set_reload_value),
    TEST_FUNC(test_systick_set_current_value),
    TEST_FUNC(test_systick_get_current_value),
    TEST_FUNC(test_systick_get_calibration_value),
    TEST_FUNC(test_systick_is_calibration_value_available),
    TEST_FUNC(test_systick_has_reference_clock),
  };

  return TESTS_RUN(tests);
}
