#ifndef STM32_DRIVER_PWR_H
#define STM32_DRIVER_PWR_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct pwr_registers_map
{
  u32 CR;
  u32 CSR;
};

enum pwr_cr : u32
{
  PWR_CR_LPDS = (1 << 0),
  PWR_CR_PDDS = (1 << 1),
  PWR_CR_CWUF = (1 << 2),
  PWR_CR_CSBF = (1 << 3),
  PWR_CR_PVDE = (1 << 4),
  PWR_CR_DBP = (1 << 8),
  PWR_CR_FPDS = (1 << 9),

#if defined(STM32_PWR_UD)
  PWR_CR_LPUDS = (1 << 10),
  PWR_CR_MRUDS = (1 << 11),
#elif defined(STM32_PWR_LVDS)
  PWR_CR_LPLVDS = (1 << 10),
  PWR_CR_MRLVDS = (1 << 11),
#endif

#if defined(STM32_PWR_ADC)
  PWR_CR_ADCDC1 = (1 << 13),
#endif

#if defined(STM32_PWR_VOS_1BIT)
  PWR_CR_VOS = (1 << 14),
#endif

#if defined(STM32_PWR_OD)
  PWR_CR_ODEN = (1 << 16),
  PWR_CR_ODSWEN = (1 << 17),
#endif

#if defined(STM32_PWR_FLASH)
  PWR_CR_FMSSR = (1 << 20),
  PWR_CR_FISSR = (1 << 21)
#endif
};

#define PWR_CR_PLS_SHIFT (5)
#define PWR_CR_PLS_MASK (0x7)

enum pwr_cr_pls : u32
{
  PWR_CR_PLS_2dot0v = 0b000,
  PWR_CR_PLS_2dot1v = 0b001,
  PWR_CR_PLS_2dot3v = 0b010,
  PWR_CR_PLS_2dot5v = 0b011,
  PWR_CR_PLS_2dot6v = 0b100,
  PWR_CR_PLS_2dot7v = 0b101,
  PWR_CR_PLS_2dot8v = 0b110,
  PWR_CR_PLS_2dot9v = 0b111
};
 
#if defined(STM32_PWR_VOS_2BIT)
#define PWR_CR_VOS_SHIFT (14)
#define PWR_CR_VOS_MASK (0x3)

enum pwr_cr_vos : u32
{
  PWR_CR_VOS_SCALE3 = 0b01,
  PWR_CR_VOS_SCALE2 = 0b10,
  PWR_CR_VOS_SCALE1 = 0b11
};
#endif

#if defined(STM32_PWR_UD)
#define PWR_CR_UDEN_SHIFT (18)
#define PWR_CR_UDEN_MASK (0x3)

enum pwr_cr_uden : u32
{
  PWR_CR_UDEN_UNDER_DRIVE_DISABLED = 0b00,
  PWR_CR_UDEN_UNDER_DRIVE_ENABLED = 0b11
};
#endif

enum pwr_csr : u32
{
  PWR_CSR_WUPF = (1 << 0),
  PWR_CSR_SBF = (1 << 1),
  PWR_CSR_PVDO = (1 << 2),
  PWR_CSR_BRR = (1 << 3),

#if defined(STM32_PWR_WAKEUP_PIN3)
  PWR_CSR_EWUP3 = (1 << 6),
#endif

#if defined(STM32_PWR_WAKEUP_PIN2)
  PWR_CSR_EWUP2 = (1 << 7),
#endif

  PWR_CSR_EWUP1 = (1 << 8),
  PWR_CSR_BRE = (1 << 9),
  PWR_CSR_VOSRDY = (1 << 14),

#if defined(STM32_PWR_OD)
  PWR_CSR_ODRDY = (1 << 16),
  PWR_CSR_ODSWRDY = (1 << 17)
#endif
};

#if defined(STM32_PWR_UD)
#define PWR_CSR_UDRDY_SHIFT (18)
#define PWR_CSR_UDRDY_MASK (0x3)

enum pwr_csr_udrdy : u32
{
  PWR_CSR_UDRDY_OFF = 0b00,
  PWR_CSR_UDRDY_ON = 0b11
};
#endif

// API

enum pwr_voltage_regulator_mode
{
  PWR_VOLTAGE_REGULATOR_ON,
  PWR_VOLTAGE_REGULATOR_LOW_POWER
};

enum pwr_deepsleep_mode
{
  PWR_DEEPSLEEP_MODE_STOP_MODE,
  PWR_DEEPSLEEP_MODE_STANDBY_MODE
};

enum pwr_flag
{
  PWR_FLAG_WAKEUP,
  PWR_FLAG_STANDBY
};

enum pwr_wakeup_pin
{
  PWR_WAKEUP_PIN1,

#if defined(STM32_PWR_WAKEUP_PIN2)
  PWR_WAKEUP_PIN2,
#endif

#if defined(STM32_PWR_WAKEUP_PIN3)
  PWR_WAKEUP_PIN3
#endif
};

enum pwr_wakeup_pin_mode
{
  PWR_WAKEUP_PIN_MODE_GPIO,
  PWR_WAKEUP_PIN_MODE_WAKEUP
};

enum pwr_voltage_detector_level
{
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot0v,
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot1v,
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v,
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot5v,
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot6v,
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot7v,
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot8v,
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot9v
};

enum pwr_powerdown_flash_mode
{
  PWR_POWERDOWN_FLASH_MODE_DEFAULT,
  PWR_POWERDOWN_FLASH_MODE_POWER_DOWN
};

enum pwr_low_power_regulator_mode
{
  PWR_LOW_POWER_REGULATOR_MODE_ON,

#if defined(STM32_PWR_UD)
  PWR_LOW_POWER_REGULATOR_MODE_UNDERDRIVE
#elif defined(STM32_PWR_LVDS)
  PWR_LOW_POWER_REGULATOR_MODE_LOW_VOLTAGE
#endif
};

enum pwr_low_power_main_regulator_mode
{
  PWR_LOW_POWER_MAIN_REGULATOR_MODE_ON,

#if defined(STM32_PWR_UD)
  PWR_LOW_POWER_MAIN_REGULATOR_MODE_UNDERDRIVE
#elif defined(STM32_PWR_LVDS)
  PWR_LOW_POWER_MAIN_REGULATOR_MODE_LOW_VOLTAGE
#endif
};

enum pwr_voltage_regulator_scale
{
  PWR_VOLTAGE_REGULATOR_SCALE1,
  PWR_VOLTAGE_REGULATOR_SCALE2,

#if defined(STM32_PWR_VOS_2BIT)
  PWR_VOLTAGE_REGULATOR_SCALE3
#endif
};

#if defined(STM32_PWR_FLASH)
enum pwr_flash_memory_mode
{
  PWR_FLASH_MEMORY_MODE_DEFAULT,
  PWR_FLASH_MEMORY_MODE_FORCE_STOP
};
#endif

extern volatile struct pwr_registers_map* PWR;

void
pwr_set_low_power_deepsleep_stop_mode(
  enum pwr_voltage_regulator_mode mode
);

void
pwr_set_power_down_deepsleep_mode(
  enum pwr_deepsleep_mode mode
);

void
pwr_flag_clear(
  enum pwr_flag flag
);

void
pwr_voltage_detector_enable(void);

void
pwr_voltage_detector_disable(void);

void
pwr_set_voltage_detector_level(
  enum pwr_voltage_detector_level level
);

void
pwr_backup_domain_protection_enable(void);

void
pwr_backup_domain_protection_disable(void);

void
pwr_set_powerdown_flash_mode(
  enum pwr_powerdown_flash_mode mode
);

#if defined(STM32_PWR_UD)
void
pwr_set_low_power_under_drive_regulator_mode(
  enum pwr_low_power_regulator_mode mode
);

void
pwr_set_main_regulator_mode(
  enum pwr_low_power_main_regulator_mode mode
);
#elif defined(STM32_PWR_LVDS)
void
pwr_set_low_power_low_voltage_deepsleep_stop_mode(
  enum pwr_low_power_regulator_mode mode
);

void
pwr_set_low_power_low_voltage_regulator_mode(
  enum pwr_low_power_main_regulator_mode mode
);
#endif

void
pwr_set_voltage_regulator_scale(
  enum pwr_voltage_regulator_scale scale
);

#if defined(STM32_PWR_OD)
void
pwr_overdrive_enable(void);

void
pwr_overdrive_disable(void);

void
pwr_overdrive_switching_enable(void);

void
pwr_overdrive_switching_disable(void);
#endif

void
pwr_underdrive_in_stop_mode_enable(void);

void
pwr_underdrive_in_stop_mode_disable(void);

#if defined(STM32_PWR_FLASH)
void
pwr_set_flash_memory_mode(
  enum pwr_flash_memory_mode mode
);

void
pwr_flash_clock_enable(void);

void
pwr_flash_clock_disable(void);
#endif

u32
pwr_is_flag_set(
  enum pwr_flag flag
);

u32
pwr_is_vdd_lower_than_pvd_threshold(void);

u32
pwr_is_backup_regulator_ready(void);

void
pwr_set_wakeup_pin_mode(
  enum pwr_wakeup_pin pin,
  enum pwr_wakeup_pin_mode mode
);

void
pwr_backup_regulator_enable(void);

void
pwr_backup_regulator_disable(void);

u32
pwr_is_voltage_regulator_scaling_ready(void);

#if defined(STM32_PWR_OD)
u32
pwr_is_overdrive_mode_ready(void);

u32
pwr_is_overdrive_mode_switching_ready(void);
#endif

#if defined(STM32_PWR_UD)
u32
pwr_is_underdrive_mode_ready(void);
#endif

END_DECLARATIONS

#endif

