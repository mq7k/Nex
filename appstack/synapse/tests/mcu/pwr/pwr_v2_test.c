#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/pwr/pwr_v2.h"
#include "libtest/libtest.h"

void
setup(void)
{
  PWR = (struct pwr_registers_map*) membuf;
}

void
test_pwr_set_low_power_deepsleep_stop_mode(void)
{
  PWR->CR = 0;
  pwr_set_low_power_deepsleep_stop_mode(PWR_VOLTAGE_REGULATOR_LOW_POWER);
  ASSERT_EQ(PWR->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 0);
  pwr_set_low_power_deepsleep_stop_mode(PWR_VOLTAGE_REGULATOR_LOW_POWER);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 0);
  pwr_set_low_power_deepsleep_stop_mode(PWR_VOLTAGE_REGULATOR_ON);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_low_power_deepsleep_stop_mode(PWR_VOLTAGE_REGULATOR_ON);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_set_power_down_deepsleep_mode(void)
{
  PWR->CR = 0;
  pwr_set_power_down_deepsleep_mode(PWR_DEEPSLEEP_MODE_STANDBY_MODE);
  ASSERT_EQ(PWR->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 1);
  pwr_set_power_down_deepsleep_mode(PWR_DEEPSLEEP_MODE_STANDBY_MODE);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 1);
  pwr_set_power_down_deepsleep_mode(PWR_DEEPSLEEP_MODE_STOP_MODE);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_power_down_deepsleep_mode(PWR_DEEPSLEEP_MODE_STOP_MODE);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_flag_clear(void)
{
  PWR->CR = 0;
  pwr_flag_clear(PWR_FLAG_WAKEUP);
  ASSERT_EQ(PWR->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 2);
  pwr_flag_clear(PWR_FLAG_WAKEUP);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  PWR->CR = 0;
  pwr_flag_clear(PWR_FLAG_STANDBY);
  ASSERT_EQ(PWR->CR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 3);
  pwr_flag_clear(PWR_FLAG_STANDBY);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

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

void
test_pwr_set_voltage_detector_level(void)
{
  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot0v'}, self.value='0b000', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot0v);
  ASSERT_EQ(PWR->CR, (0b000u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot0v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b000u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot1v'}, self.value='0b001', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot1v);
  ASSERT_EQ(PWR->CR, (0b001u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot1v);
  ASSERT_EQ(PWR->CR, ~(0x7u << 5) | (0b001u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=5, self.mask='0x7', self.varsmap={'level': 'PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v'}, self.value='0b010', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v);
  ASSERT_EQ(PWR->CR, (0b010u << 5));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x7u << 5);
  pwr_set_voltage_detector_level(PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v);
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
test_pwr_set_powerdown_flash_mode(void)
{
  PWR->CR = 0;
  pwr_set_powerdown_flash_mode(PWR_POWERDOWN_FLASH_MODE_POWER_DOWN);
  ASSERT_EQ(PWR->CR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 9);
  pwr_set_powerdown_flash_mode(PWR_POWERDOWN_FLASH_MODE_POWER_DOWN);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 9);
  pwr_set_powerdown_flash_mode(PWR_POWERDOWN_FLASH_MODE_DEFAULT);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_powerdown_flash_mode(PWR_POWERDOWN_FLASH_MODE_DEFAULT);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_PWR_UD)
void
test_pwr_set_low_power_under_drive_regulator_mode(void)
{
  PWR->CR = 0;
  pwr_set_low_power_under_drive_regulator_mode(PWR_LOW_POWER_REGULATOR_MODE_UNDERDRIVE);
  ASSERT_EQ(PWR->CR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 10);
  pwr_set_low_power_under_drive_regulator_mode(PWR_LOW_POWER_REGULATOR_MODE_UNDERDRIVE);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 10);
  pwr_set_low_power_under_drive_regulator_mode(PWR_LOW_POWER_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_low_power_under_drive_regulator_mode(PWR_LOW_POWER_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_LVDS)
void
test_pwr_set_low_power_low_voltage_deepsleep_stop_mode(void)
{
  PWR->CR = 0;
  pwr_set_low_power_low_voltage_deepsleep_stop_mode(PWR_LOW_POWER_REGULATOR_MODE_LOW_VOLTAGE);
  ASSERT_EQ(PWR->CR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 10);
  pwr_set_low_power_low_voltage_deepsleep_stop_mode(PWR_LOW_POWER_REGULATOR_MODE_LOW_VOLTAGE);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 10);
  pwr_set_low_power_low_voltage_deepsleep_stop_mode(PWR_LOW_POWER_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_low_power_low_voltage_deepsleep_stop_mode(PWR_LOW_POWER_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_LVDS)
void
test_pwr_set_low_power_low_voltage_regulator_mode(void)
{
  PWR->CR = 0;
  pwr_set_low_power_low_voltage_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_LOW_VOLTAGE);
  ASSERT_EQ(PWR->CR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 11);
  pwr_set_low_power_low_voltage_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_LOW_VOLTAGE);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 11);
  pwr_set_low_power_low_voltage_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_low_power_low_voltage_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_UD)
void
test_pwr_set_main_regulator_mode(void)
{
  PWR->CR = 0;
  pwr_set_main_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_UNDERDRIVE);
  ASSERT_EQ(PWR->CR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 11);
  pwr_set_main_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_UNDERDRIVE);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 11);
  pwr_set_main_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_main_regulator_mode(PWR_LOW_POWER_MAIN_REGULATOR_MODE_ON);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_VOS_1BIT)
void
test_pwr_set_voltage_regulator_scale(void)
{
  PWR->CR = 0;
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE1);
  ASSERT_EQ(PWR->CR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 14);
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE1);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 14);
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE2);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE2);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_VOS_2BIT)
void
test_pwr_set_voltage_regulator_scale(void)
{
  // scope=self.reg='CR', self.shift=14, self.mask='0x3', self.varsmap={'scale': 'PWR_VOLTAGE_REGULATOR_SCALE1'}, self.value='0b11', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE1);
  ASSERT_EQ(PWR->CR, (0b11u << 14));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x3u << 14);
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE1);
  ASSERT_EQ(PWR->CR, ~(0x3u << 14) | (0b11u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=14, self.mask='0x3', self.varsmap={'scale': 'PWR_VOLTAGE_REGULATOR_SCALE2'}, self.value='0b10', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE2);
  ASSERT_EQ(PWR->CR, (0b10u << 14));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x3u << 14);
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE2);
  ASSERT_EQ(PWR->CR, ~(0x3u << 14) | (0b10u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=14, self.mask='0x3', self.varsmap={'scale': 'PWR_VOLTAGE_REGULATOR_SCALE3'}, self.value='0b01', self.ifdef=[], self.halt=False
  PWR->CR = 0;
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE3);
  ASSERT_EQ(PWR->CR, (0b01u << 14));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(0x3u << 14);
  pwr_set_voltage_regulator_scale(PWR_VOLTAGE_REGULATOR_SCALE3);
  ASSERT_EQ(PWR->CR, ~(0x3u << 14) | (0b01u << 14));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_PWR_OD)
void
test_pwr_overdrive(void)
{
  PWR->CR = 0;
  pwr_overdrive_enable();
  ASSERT_EQ(PWR->CR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 16);
  pwr_overdrive_enable();
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 16);
  pwr_overdrive_disable();
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_overdrive_disable();
  ASSERT_EQ(PWR->CR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_OD)
void
test_pwr_overdrive_switching(void)
{
  PWR->CR = 0;
  pwr_overdrive_switching_enable();
  ASSERT_EQ(PWR->CR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 17);
  pwr_overdrive_switching_enable();
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 17);
  pwr_overdrive_switching_disable();
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_overdrive_switching_disable();
  ASSERT_EQ(PWR->CR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}
#endif

// └─Skipping type 'fn_toggle (TODO)' (pwr_underdrive_in_stop_mode)
#if defined(STM32_PWR_FLASH)
void
test_pwr_set_flash_memory_mode(void)
{
  PWR->CR = 0;
  pwr_set_flash_memory_mode(PWR_FLASH_MEMORY_MODE_FORCE_STOP);
  ASSERT_EQ(PWR->CR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  PWR->CR = ~(1u << 20);
  pwr_set_flash_memory_mode(PWR_FLASH_MEMORY_MODE_FORCE_STOP);
  ASSERT_EQ(PWR->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CR = (1u << 20);
  pwr_set_flash_memory_mode(PWR_FLASH_MEMORY_MODE_DEFAULT);
  ASSERT_EQ(PWR->CR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CR = 0xffffffff;
  pwr_set_flash_memory_mode(PWR_FLASH_MEMORY_MODE_DEFAULT);
  ASSERT_EQ(PWR->CR, 0xffffffff & ~(1u << 20));
  ASSERT_FALSE(execution_halted());

}
#endif

// └─Skipping type 'fn_toggle (TODO)' (pwr_flash_clock)
void
test_pwr_is_flag_set(void)
{
  u32 res;

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


}

void
test_pwr_is_vdd_lower_than_pvd_threshold(void)
{
  u32 res;

  // read_bit
  PWR->CSR = 0;
  res = pwr_is_vdd_lower_than_pvd_threshold();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(0x1u << 2);
  res = pwr_is_vdd_lower_than_pvd_threshold();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0x1u << 2;
  res = pwr_is_vdd_lower_than_pvd_threshold();
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_is_backup_regulator_ready(void)
{
  u32 res;

  // read_bit
  PWR->CSR = 0;
  res = pwr_is_backup_regulator_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(0x1u << 3);
  res = pwr_is_backup_regulator_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0x1u << 3;
  res = pwr_is_backup_regulator_ready();
  ASSERT_EQ(res, 0x1u << 3);
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'enum_set (TODO)' (pwr_set_wakeup_pin_mode)
void
test_pwr_backup_regulator(void)
{
  PWR->CSR = 0;
  pwr_backup_regulator_enable();
  ASSERT_EQ(PWR->CSR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(1u << 9);
  pwr_backup_regulator_enable();
  ASSERT_EQ(PWR->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = (1u << 9);
  pwr_backup_regulator_disable();
  ASSERT_EQ(PWR->CSR, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0xffffffff;
  pwr_backup_regulator_disable();
  ASSERT_EQ(PWR->CSR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_pwr_is_voltage_regulator_scaling_ready(void)
{
  u32 res;

  // read_bit
  PWR->CSR = 0;
  res = pwr_is_voltage_regulator_scaling_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(0x1u << 14);
  res = pwr_is_voltage_regulator_scaling_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0x1u << 14;
  res = pwr_is_voltage_regulator_scaling_ready();
  ASSERT_EQ(res, 0x1u << 14);
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_PWR_OD)
void
test_pwr_is_overdrive_mode_ready(void)
{
  u32 res;

  // read_bit
  PWR->CSR = 0;
  res = pwr_is_overdrive_mode_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(0x1u << 16);
  res = pwr_is_overdrive_mode_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0x1u << 16;
  res = pwr_is_overdrive_mode_ready();
  ASSERT_EQ(res, 0x1u << 16);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_OD)
void
test_pwr_is_overdrive_mode_switching_ready(void)
{
  u32 res;

  // read_bit
  PWR->CSR = 0;
  res = pwr_is_overdrive_mode_switching_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(0x1u << 17);
  res = pwr_is_overdrive_mode_switching_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0x1u << 17;
  res = pwr_is_overdrive_mode_switching_ready();
  ASSERT_EQ(res, 0x1u << 17);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_PWR_UD)
void
test_pwr_is_underdrive_mode_ready(void)
{
  u32 res;

  // read_bits
  PWR->CSR = 0;
  res = pwr_is_underdrive_mode_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = ~(0x3u << 18);
  res = pwr_is_underdrive_mode_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  PWR->CSR = 0x3u << 18;
  res = pwr_is_underdrive_mode_ready();
  ASSERT_EQ(res, 0x3);
  ASSERT_FALSE(execution_halted());

}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_pwr_set_low_power_deepsleep_stop_mode),
    TEST_FUNC(test_pwr_set_power_down_deepsleep_mode),
    TEST_FUNC(test_pwr_flag_clear),
    TEST_FUNC(test_pwr_voltage_detector),
    TEST_FUNC(test_pwr_set_voltage_detector_level),
    TEST_FUNC(test_pwr_backup_domain_protection),
    TEST_FUNC(test_pwr_set_powerdown_flash_mode),
#if defined(STM32_PWR_UD)
    TEST_FUNC(test_pwr_set_low_power_under_drive_regulator_mode),
#endif
#if defined(STM32_PWR_LVDS)
    TEST_FUNC(test_pwr_set_low_power_low_voltage_deepsleep_stop_mode),
#endif
#if defined(STM32_PWR_LVDS)
    TEST_FUNC(test_pwr_set_low_power_low_voltage_regulator_mode),
#endif
#if defined(STM32_PWR_UD)
    TEST_FUNC(test_pwr_set_main_regulator_mode),
#endif
#if defined(STM32_PWR_VOS_1BIT)
    TEST_FUNC(test_pwr_set_voltage_regulator_scale),
#endif
#if defined(STM32_PWR_VOS_2BIT)
    TEST_FUNC(test_pwr_set_voltage_regulator_scale),
#endif
#if defined(STM32_PWR_OD)
    TEST_FUNC(test_pwr_overdrive),
#endif
#if defined(STM32_PWR_OD)
    TEST_FUNC(test_pwr_overdrive_switching),
#endif
#if defined(STM32_PWR_FLASH)
    TEST_FUNC(test_pwr_set_flash_memory_mode),
#endif
    TEST_FUNC(test_pwr_is_flag_set),
    TEST_FUNC(test_pwr_is_vdd_lower_than_pvd_threshold),
    TEST_FUNC(test_pwr_is_backup_regulator_ready),
    TEST_FUNC(test_pwr_backup_regulator),
    TEST_FUNC(test_pwr_is_voltage_regulator_scaling_ready),
#if defined(STM32_PWR_OD)
    TEST_FUNC(test_pwr_is_overdrive_mode_ready),
#endif
#if defined(STM32_PWR_OD)
    TEST_FUNC(test_pwr_is_overdrive_mode_switching_ready),
#endif
#if defined(STM32_PWR_UD)
    TEST_FUNC(test_pwr_is_underdrive_mode_ready),
#endif
  };

  return TESTS_RUN(tests);
}
