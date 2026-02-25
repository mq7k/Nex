#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/gpio/gpio_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  GPIOA = (struct gpio_registers_map*) membuf;
}

// └─Skipping type 'enum_set (TODO)' (gpio_setup_port)
// └─Skipping type 'enum_set (TODO)' (gpio_setup_port_pin)
void
test_gpio_port_read(void)
{
  u32 res;

  // read_reg
  GPIOA->IDR = 0;
  res = gpio_port_read(GPIOA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  GPIOA->IDR = 0xffffffff;
  res = gpio_port_read(GPIOA);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'fn_get (TODO)' (gpio_pin_read)
// └─Skipping type 'fn_get (TODO)' (gpio_is_pin_set_high)
int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_gpio_port_read),
  };

  return TESTS_RUN(tests);
}
