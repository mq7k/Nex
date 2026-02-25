#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/pwr/pwr_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  PWR = (struct pwr_registers_map*) membuf;
}

void
test_pwr_set_voltage_regulator_mode(void)
{
  PWR->CR = 0;
  pwr_set_voltage_regulator_mode(PWR_VOLTAGE_REGULATOR_MODE_LOW_POWER);
  ASSERT_EQ(PWR->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 0);
  pwr_set_voltage_regulator_mode(PWR_VOLTAGE_REGULATOR_MODE_LOW_POWER);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 0);
  pwr_set_voltage_regulator_mode(PWR_VOLTAGE_REGULATOR_MODE_DEFAULT);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_voltage_regulator_mode(PWR_VOLTAGE_REGULATOR_MODE_DEFAULT);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_set_deepsleep_mode(void)
{
  PWR->CR = 0;
  pwr_set_deepsleep_mode(PWR_DEEPSLEEP_MODE_STANDBY_MODE);
  ASSERT_EQ(PWR->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 0);
  pwr_set_deepsleep_mode(PWR_DEEPSLEEP_MODE_STANDBY_MODE);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 0);
  pwr_set_deepsleep_mode(PWR_DEEPSLEEP_MODE_STOP_MODE);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_deepsleep_mode(PWR_DEEPSLEEP_MODE_STOP_MODE);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_flag_clear(void)
{
  Missing 'clear_mode' properties
  Source: pwr_flag_clear

  Missing 'clear_mode' properties
  Source: pwr_flag_clear

}

#if defined(STM32_PWR_PVD)
void
test_pwr_voltage_detector(void)
{
  PWR->CR = 0;
  pwr_voltage_detector_enable();
  ASSERT_EQ(PWR->CR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 4);
  pwr_voltage_detector_enable();
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 4);
  pwr_voltage_detector_disable();
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_voltage_detector_disable();
  ASSERT_EQ(PWR->CR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_PVD)
void
test_pwr_set_voltage_detector_level(void)
{
  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot2v'}, self.value='0b000', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot2v);
  ASSERT_EQ(PWR->CR, (0b000u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot2v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b000u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v'}, self.value='0b001', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v);
  ASSERT_EQ(PWR->CR, (0b001u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b001u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot4v'}, self.value='0b010', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot4v);
  ASSERT_EQ(PWR->CR, (0b010u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot4v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b010u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot5v'}, self.value='0b011', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot5v);
  ASSERT_EQ(PWR->CR, (0b011u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot5v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b011u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot6v'}, self.value='0b100', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot6v);
  ASSERT_EQ(PWR->CR, (0b100u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot6v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b100u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot7v'}, self.value='0b101', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot7v);
  ASSERT_EQ(PWR->CR, (0b101u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot7v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b101u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot8v'}, self.value='0b110', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot8v);
  ASSERT_EQ(PWR->CR, (0b110u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot8v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b110u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot9v'}, self.value='0b111', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot9v);
  ASSERT_EQ(PWR->CR, (0b111u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot9v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b111u << 5));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_pwr_backup_domain_protection(void)
{
  PWR->CR = 0;
  pwr_backup_domain_protection_disable();
  ASSERT_EQ(PWR->CR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 8);
  pwr_backup_domain_protection_disable();
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 8);
  pwr_backup_domain_protection_enable();
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_backup_domain_protection_enable();
  ASSERT_EQ(PWR->CR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_is_flag_set(void)
{
  u32 res;

  PWR->CSR = 0;
  res = pwr_is_flag_set(PWR_FLAG_STANDBY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 1);
  res = pwr_is_flag_set(PWR_FLAG_STANDBY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 1);
  res = pwr_is_flag_set(PWR_FLAG_STANDBY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  res = pwr_is_flag_set(PWR_FLAG_STANDBY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  PWR->CSR = 0;
  res = pwr_is_flag_set(PWR_FLAG_WAKEUP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 0);
  res = pwr_is_flag_set(PWR_FLAG_WAKEUP);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 0);
  res = pwr_is_flag_set(PWR_FLAG_WAKEUP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  res = pwr_is_flag_set(PWR_FLAG_WAKEUP);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_pwr_voltage_detector_level_compare(void)
{
  u32 res;

  // read_bits
  PWR->CSR = 0;
  res = pwr_voltage_detector_level_compare();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(0u << 2);
  res = pwr_voltage_detector_level_compare();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0u << 2;
  res = pwr_voltage_detector_level_compare();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_wakeup_pin(void)
{
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN1);
  ASSERT_EQ(PWR->CSR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 8);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN1);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 8);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN1);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN1);
  ASSERT_EQ(PWR->CSR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN2);
  ASSERT_EQ(PWR->CSR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 9);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN2);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 9);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN2);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN2);
  ASSERT_EQ(PWR->CSR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN3);
  ASSERT_EQ(PWR->CSR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 10);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN3);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 10);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN3);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN3);
  ASSERT_EQ(PWR->CSR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN4);
  ASSERT_EQ(PWR->CSR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 11);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN4);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 11);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN4);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN4);
  ASSERT_EQ(PWR->CSR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN5);
  ASSERT_EQ(PWR->CSR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 12);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN5);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 12);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN5);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN5);
  ASSERT_EQ(PWR->CSR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN6);
  ASSERT_EQ(PWR->CSR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 13);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN6);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 13);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN6);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN6);
  ASSERT_EQ(PWR->CSR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN7);
  ASSERT_EQ(PWR->CSR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 14);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN7);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 14);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN7);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN7);
  ASSERT_EQ(PWR->CSR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR->CSR = 0;
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN8);
  ASSERT_EQ(PWR->CSR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 15);
  pwr_wakeup_pin_enable(PWR_WAKEUP_PIN8);
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 15);
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN8);
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_wakeup_pin_disable(PWR_WAKEUP_PIN8);
  ASSERT_EQ(PWR->CSR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_pwr_set_voltage_regulator_mode),
    TEST_FUNC(test_pwr_set_deepsleep_mode),
    TEST_FUNC(test_pwr_flag_clear),
#if defined(STM32_PWR_PVD)
    TEST_FUNC(test_pwr_voltage_detector),
#endif
#if defined(STM32_PWR_PVD)
    TEST_FUNC(test_pwr_set_voltage_detector_level),
#endif
    TEST_FUNC(test_pwr_backup_domain_protection),
    TEST_FUNC(test_pwr_is_flag_set),
    TEST_FUNC(test_pwr_voltage_detector_level_compare),
    TEST_FUNC(test_pwr_wakeup_pin),
  };

  return TESTS_RUN(tests);
}
