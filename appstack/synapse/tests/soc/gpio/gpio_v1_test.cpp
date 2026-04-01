#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/gpio/gpio_v1.h"
#include "libtest/libtest.hpp"

volatile struct gpio_registers_map* _GPIO;

void
setup(void)
{
  _GPIO = (struct gpio_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_OFFSET(struct gpio_registers_map, CRL, 0x00lu);
  ASSERT_OFFSET(struct gpio_registers_map, CRH, 0x04lu);
  ASSERT_OFFSET(struct gpio_registers_map, IDR, 0x08lu);
  ASSERT_OFFSET(struct gpio_registers_map, ODR, 0x0clu);
  ASSERT_OFFSET(struct gpio_registers_map, BSRR, 0x10lu);
  ASSERT_OFFSET(struct gpio_registers_map, BRR, 0x14lu);
  ASSERT_OFFSET(struct gpio_registers_map, LCKR, 0x18lu);
}

// └─Skipping type 'enum_set (TODO)' (gpio_setup_port)
// └─Skipping type 'enum_set (TODO)' (gpio_setup_port_pin)
void
test_gpio_port_read(void)
{
  u32 res;

  _GPIO->IDR = 0;
  res = gpio_port_read(_GPIO);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _GPIO->IDR = 0xffffffff;
  res = gpio_port_read(_GPIO);
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
    TEST_FUNC(test_reg_addr),
    TEST_FUNC(test_gpio_port_read),
  };

  return TESTS_RUN(tests);
}
