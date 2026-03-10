#include "synapse/stm32/drivers/pwr/pwr_v2.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "synapse/specs.h"

typedef volatile struct pwr_registers_map pwr_periph;
pwr_periph* PWR = (pwr_periph*) (PWR_ADDR);

void
pwr_set_low_power_deepsleep_stop_mode(
  enum pwr_voltage_regulator_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_VOLTAGE_REGULATOR_ON:
      *reg &= ~PWR_CR_LPDS;
      break;

    case PWR_VOLTAGE_REGULATOR_LOW_POWER:
      *reg |= PWR_CR_LPDS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_voltage_regulator_mode, mode);
      break;
  }
}

void
pwr_set_power_down_deepsleep_mode(
  enum pwr_deepsleep_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_DEEPSLEEP_MODE_STOP_MODE:
      *reg &= ~PWR_CR_PDDS;
      break;

    case PWR_DEEPSLEEP_MODE_STANDBY_MODE:
      *reg |= PWR_CR_PDDS;
      break;
      
    default:
      devmode_error_invalid_enum(enum pwr_deepsleep_mode, mode);
      break;
  }
}

void
pwr_flag_clear(
  enum pwr_flag flag
)
{
  volatile u32* reg = &PWR->CR;
  switch (flag)
  {
    case PWR_FLAG_WAKEUP:
      *reg |= PWR_CR_CWUF;
      break;

    case PWR_FLAG_STANDBY:
      *reg |= PWR_CR_CSBF;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_flag, flag);
      break;
  }
}

void
pwr_voltage_detector_enable(void)
{
  PWR->CR |= PWR_CR_PVDE;
}

void
pwr_voltage_detector_disable(void)
{
  PWR->CR &= ~PWR_CR_PVDE;
}

void
pwr_set_voltage_detector_level(
  enum pwr_voltage_detector_level level
)
{
  constexpr u32 shift = PWR_CR_PLS_SHIFT;
  constexpr u32 mask = PWR_CR_PLS_MASK << shift;
  volatile u32* reg = &PWR->CR;
  switch (level)
  {
    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot0v:
      *reg &= ~mask;
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot1v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot1v << shift);
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot3v << shift);
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot5v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot5v << shift);
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot6v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot6v << shift);
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot7v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot7v << shift);
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot8v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot8v << shift);
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot9v:
      *reg |= (PWR_CR_PLS_2dot9v << shift);
      break;

    default:
      devmode_error_invalid_enum(enum pwr_voltage_detector_level, level);
      break;
  }
}

void
pwr_backup_domain_protection_enable(void)
{
  PWR->CR &= ~PWR_CR_DBP;
}

void
pwr_backup_domain_protection_disable(void)
{
  PWR->CR |= PWR_CR_DBP;
}

void
pwr_set_powerdown_flash_mode(
  enum pwr_powerdown_flash_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_POWERDOWN_FLASH_MODE_DEFAULT:
      *reg &= ~PWR_CR_FPDS;
      break;

    case PWR_POWERDOWN_FLASH_MODE_POWER_DOWN:
      *reg |= PWR_CR_FPDS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_powerdown_flash_mode, mode);
      break;
  }
}

#if defined(STM32_PWR_UD)
void
pwr_set_low_power_under_drive_regulator_mode(
  enum pwr_low_power_regulator_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_LOW_POWER_REGULATOR_MODE_ON:
      *reg &= ~PWR_CR_LPUDS;
      break;

    case PWR_LOW_POWER_REGULATOR_MODE_UNDERDRIVE:
      *reg |= PWR_CR_LPUDS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_low_power_regulator_mode, mode);
      break;
  }
}

void
pwr_set_main_regulator_mode(
  enum pwr_low_power_main_regulator_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_LOW_POWER_MAIN_REGULATOR_MODE_ON:
      *reg &= ~PWR_CR_MRUDS;
      break;

    case PWR_LOW_POWER_MAIN_REGULATOR_MODE_UNDERDRIVE:
      *reg |= PWR_CR_MRUDS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_low_power_regulator_mode, mode);
      break;
  }
}
#elif defined(STM32_PWR_LVDS)
void
pwr_set_low_power_low_voltage_deepsleep_stop_mode(
  enum pwr_low_power_regulator_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_LOW_POWER_REGULATOR_MODE_ON:
      *reg &= ~PWR_CR_LPLVDS;
      break;

    case PWR_LOW_POWER_REGULATOR_MODE_LOW_VOLTAGE:
      *reg |= PWR_CR_LPLVDS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_voltage_regular_mode, mode);
      break;
  }
}

void
pwr_set_low_power_low_voltage_regulator_mode(
  enum pwr_low_power_main_regulator_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_LOW_POWER_MAIN_REGULATOR_MODE_ON:
      *reg &= ~PWR_CR_MRLVDS;
      break;

    case PWR_LOW_POWER_MAIN_REGULATOR_MODE_LOW_VOLTAGE:
      *reg |= PWR_CR_MRLVDS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_low_power_main_regulator_mode, mode);
      break;
  }
}
#endif

#if defined(STM32_PWR_VOS_1BIT)
void
pwr_set_voltage_regulator_scale(
  enum pwr_voltage_regulator_scale scale
)
{
  volatile u32* reg = &PWR->CR;
  switch (scale)
  {
    case PWR_VOLTAGE_REGULATOR_SCALE1:
      *reg |= PWR_CR_VOS;
      break;

    case PWR_VOLTAGE_REGULATOR_SCALE2:
      *reg &= ~PWR_CR_VOS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_voltage_regulator_scale, scale);
      break;
  }
}
#elif defined(STM32_PWR_VOS_2BIT)
void
pwr_set_voltage_regulator_scale(
  enum pwr_voltage_regulator_scale scale
)
{
  constexpr u32 shift = PWR_CR_VOS_SHIFT;
  constexpr u32 mask = PWR_CR_VOS_MASK << shift;
  volatile u32* reg = &PWR->CR;
  switch (scale)
  {
    case PWR_VOLTAGE_REGULATOR_SCALE1:
      *reg |= (PWR_CR_VOS_SCALE1 << shift);
      break;

    case PWR_VOLTAGE_REGULATOR_SCALE2:
      syn_set_register_bits(reg, mask, PWR_CR_VOS_SCALE2 << shift);
      break;

    case PWR_VOLTAGE_REGULATOR_SCALE3:
      syn_set_register_bits(reg, mask, PWR_CR_VOS_SCALE3 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum pwr_voltage_regulator_scale, scale);
      break;
  }
}
#endif

#if defined(STM32_PWR_OD)
void
pwr_overdrive_enable(void)
{
  PWR->CR |= PWR_CR_ODEN;
}

void
pwr_overdrive_disable(void)
{
  PWR->CR &= ~PWR_CR_ODEN;
}

void
pwr_overdrive_switching_enable(void)
{
  PWR->CR |= PWR_CR_ODSWEN;
}

void
pwr_overdrive_switching_disable(void)
{
  PWR->CR &= ~PWR_CR_ODSWEN;
}
#endif

#if defined(STM32_PWR_UD)
void
pwr_underdrive_in_stop_mode_enable(void)
{
  constexpr u32 shift = PWR_CR_UDEN_SHIFT;
  PWR->CR |= (PWR_CR_UDEN_UNDER_DRIVE_ENABLED << shift);
}

void
pwr_underdrive_in_stop_mode_disable(void)
{
  constexpr u32 shift = PWR_CR_UDEN_SHIFT;
  PWR->CR &= ~(PWR_CR_UDEN_UNDER_DRIVE_ENABLED << shift);
}
#endif

#if defined(STM32_PWR_FLASH)
void
pwr_set_flash_memory_mode(
  enum pwr_flash_memory_mode mode
)
{
  volatile u32* reg = &PWR->CR;
  switch (mode)
  {
    case PWR_FLASH_MEMORY_MODE_DEFAULT:
      *reg &= ~PWR_CR_FMSSR;
      break;

    case PWR_FLASH_MEMORY_MODE_FORCE_STOP:
      *reg |= PWR_CR_FMSSR;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_flash_memory_mode, mode);
      break;
  }
}

void
pwr_flash_clock_enable(void)
{
  PWR->CR &= ~PWR_CR_FISSR;
}

void
pwr_flash_clock_disable(void)
{
  PWR->CR |= PWR_CR_FISSR;
}
#endif

u32
pwr_is_flag_set(
  enum pwr_flag flag
)
{
  volatile u32* reg = &PWR->CSR;
  switch (flag)
  {
    case PWR_FLAG_WAKEUP:
      return *reg & PWR_CSR_WUPF;

    case PWR_FLAG_STANDBY:
      return *reg & PWR_CSR_SBF;

    default:
      devmode_error_invalid_enum(enum pwr_flag, flag);
      return 0;
  }
}

u32
pwr_is_vdd_lower_than_pvd_threshold(void)
{
  return PWR->CSR & PWR_CSR_PVDO;
}

u32
pwr_is_backup_regulator_ready(void)
{
  return PWR->CSR & PWR_CSR_BRR;
}

void
pwr_set_wakeup_pin_mode(
  enum pwr_wakeup_pin pin,
  enum pwr_wakeup_pin_mode mode
)
{
  devmode_assert_lower_or_eq(mode, PWR_WAKEUP_PIN_MODE_WAKEUP);
  volatile u32* reg = &PWR->CSR;
  const u32 clear = mode == PWR_WAKEUP_PIN_MODE_GPIO;

  switch (pin)
  {
    case PWR_WAKEUP_PIN1:
      if (clear)
      {
        *reg &= ~PWR_CSR_EWUP1;
      }
      else
      {
        *reg |= PWR_CSR_EWUP1;
      }
      break;

#if defined(STM32_PWR_WAKEUP_PIN2)
    case PWR_WAKEUP_PIN2:
      if (clear)
      {
        *reg &= ~PWR_CSR_EWUP2;
      }
      else
      {
        *reg |= PWR_CSR_EWUP2;
      }
      break;
#endif

#if defined(STM32_PWR_WAKEUP_PIN3)
    case PWR_WAKEUP_PIN3:
      if (clear)
      {
        *reg &= ~PWR_CSR_EWUP3;
      }
      else
      {
        *reg |= PWR_CSR_EWUP3;
      }
      break;
#endif

    default:
      devmode_error_invalid_enum(enum pwr_wakeup_pin, pin);
      break;
  }
}

void
pwr_backup_regulator_enable(void)
{
  PWR->CSR |= PWR_CSR_BRE;
}

void
pwr_backup_regulator_disable(void)
{
  PWR->CSR &= ~PWR_CSR_BRE;
}

u32
pwr_is_voltage_regulator_scaling_ready(void)
{
  return PWR->CSR & PWR_CSR_VOSRDY;
}

#if defined(STM32_PWR_OD)
u32
pwr_is_overdrive_mode_ready(void)
{
  return PWR->CSR & PWR_CSR_ODRDY;
}

u32
pwr_is_overdrive_mode_switching_ready(void)
{
  return PWR->CSR & PWR_CSR_ODSWRDY;
}
#endif

#if defined(STM32_PWR_UD)
u32
pwr_is_underdrive_mode_ready(void)
{
  constexpr u32 shift = PWR_CSR_UDRDY_SHIFT;
  constexpr u32 mask = PWR_CSR_UDRDY_MASK;
  volatile u32* reg = &PWR->CSR;
  return (*reg >> shift) & mask;
}
#endif
