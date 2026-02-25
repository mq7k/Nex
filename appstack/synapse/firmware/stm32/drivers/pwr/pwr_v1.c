#include "synapse/stm32/drivers/pwr/pwr_v1.h"
#include "synapse/stm32/system/specs.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct pwr_registers_map pwr_periph;
pwr_periph* PWR = (pwr_periph*) (PWR_ADDR);

void
pwr_set_voltage_regulator_mode(
  enum pwr_voltage_regulator_mode mode
)
{
  switch (mode)
  {
    case PWR_VOLTAGE_REGULATOR_MODE_DEFAULT:
      PWR->CR &= ~PWR_CR_LPDS;
      break;

    case PWR_VOLTAGE_REGULATOR_MODE_LOW_POWER:
      PWR->CR |= PWR_CR_LPDS;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_set_voltage_regulator_mode, mode);
      break;
  }
}

void
pwr_set_deepsleep_mode(
  enum pwr_deepsleep_mode mode
)
{
  switch (mode)
  {
    case PWR_DEEPSLEEP_MODE_STOP_MODE:
      PWR->CR &= ~PWR_CR_PDDS;
      break;

    case PWR_DEEPSLEEP_MODE_STANDBY_MODE:
      PWR->CR |= PWR_CR_PDDS;
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
  switch (flag)
  {
    case PWR_FLAG_WAKEUP:
      PWR->CR |= PWR_CR_CWUF;
      break;

    case PWR_FLAG_STANDBY:
      PWR->CR |= PWR_CR_CSBF;
      break;

    default:
      devmode_error_invalid_enum(enum pwr_flag, flag);
      break;
  }
}


#if defined(STM32_PWR_PVD)
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
    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot2v:
      *reg &= ~mask;
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot3v << shift);
      break;

    case PWR_VOLTAGE_DETECTOR_LEVEL_2dot4v:
      syn_set_register_bits(reg, mask, PWR_CR_PLS_2dot4v << shift);
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
#endif

void
pwr_backup_domain_protection_enable(void)
{
  // Not a bug, setting the bit disables
  // the backup domain write protection.
  PWR->CR &= ~PWR_CR_DBP;
}

void
pwr_backup_domain_protection_disable(void)
{
  PWR->CR |= PWR_CR_DBP;
}

u32
pwr_is_flag_set(
  enum pwr_flag flag
)
{
  switch (flag)
  {
    case PWR_FLAG_STANDBY:
      return PWR->CSR & PWR_CSR_SBF;

    case PWR_FLAG_WAKEUP:
      return PWR->CSR & PWR_CSR_WUF;

    default:
      devmode_error_invalid_enum(enum pwr_flag, flag);
      return 0;
  }
}

u32
pwr_voltage_detector_level_compare(void)
{
  return PWR->CSR & PWR_CSR_PVDO;
}

void
pwr_wakeup_pin_enable(
  enum pwr_wakeup_pin pin
)
{
  volatile u32* reg = &PWR->CSR;
  switch (pin)
  {
    case PWR_WAKEUP_PIN1:
      *reg |= PWR_CSR_EWUP1;
      break;

#if defined(STM32_PWR_MULTI_WKUP_PIN)
    case PWR_WAKEUP_PIN2:
      *reg |= PWR_CSR_EWUP2;
      break;

    case PWR_WAKEUP_PIN3:
      *reg |= PWR_CSR_EWUP3;
      break;

    case PWR_WAKEUP_PIN4:
      *reg |= PWR_CSR_EWUP4;
      break;

    case PWR_WAKEUP_PIN5:
      *reg |= PWR_CSR_EWUP5;
      break;

    case PWR_WAKEUP_PIN6:
      *reg |= PWR_CSR_EWUP6;
      break;

    case PWR_WAKEUP_PIN7:
      *reg |= PWR_CSR_EWUP7;
      break;

    case PWR_WAKEUP_PIN8:
      *reg |= PWR_CSR_EWUP8;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum pwr_wakeup_pin, pin);
      break;
  }
}

void
pwr_wakeup_pin_disable(
  enum pwr_wakeup_pin pin
)
{
  volatile u32* reg = &PWR->CSR;
  switch (pin)
  {
    case PWR_WAKEUP_PIN1:
      *reg &= ~PWR_CSR_EWUP1;
      break;

#if defined(STM32_PWR_MULTI_WKUP_PIN)
    case PWR_WAKEUP_PIN2:
      *reg &= ~PWR_CSR_EWUP2;
      break;

    case PWR_WAKEUP_PIN3:
      *reg &= ~PWR_CSR_EWUP3;
      break;

    case PWR_WAKEUP_PIN4:
      *reg &= ~PWR_CSR_EWUP4;
      break;

    case PWR_WAKEUP_PIN5:
      *reg &= ~PWR_CSR_EWUP5;
      break;

    case PWR_WAKEUP_PIN6:
      *reg &= ~PWR_CSR_EWUP6;
      break;

    case PWR_WAKEUP_PIN7:
      *reg &= ~PWR_CSR_EWUP7;
      break;

    case PWR_WAKEUP_PIN8:
      *reg &= ~PWR_CSR_EWUP8;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum pwr_wakeup_pin, pin);
      break;
  }
}
