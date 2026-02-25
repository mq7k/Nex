/**
 * @file pwr.h
 * @brief Power Control (PWR) interface.
 *
 * @details This header file provides definitions and function 
 * prototypes for configuring power management features, 
 * including low-power modes, voltage regulation, and backup 
 * domain control.
 *
 * @note Improper power management settings may cause unexpected 
 * behavior or system instability.
 */
#ifndef STM32_DRIVER_PWR_H
#define STM32_DRIVER_PWR_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F0x
 *  - STM32F1x
 */

BEGIN_DECLARATIONS

/**
 * @brief Power control registers map.
 *
 * @details Represents the memory-mapped structure of 
 * the power control (PWR) registers, which manage low-power 
 * modes, voltage regulator configurations, and backup domain 
 * access.
 *
 * @note This structure is device-specific and should be 
 * used with caution when modifying power-related settings.
 */
struct pwr_registers_map
{
  /**
   * @brief PWR_CR - Power control register
   *
   * @details
   * Offset: 0x0
   * <br>
   * Reset: 0x0000 0000
   *
   * @note This register is reset when
   * waking up from standby mode.
   */
  u32 CR;

  /**
   * @brief PWR_CSR - Power control/status register
   *
   * @details
   * Offset: 0x4
   * <br>
   * Reset: 0x0000 0000
   */
  u32 CSR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum pwr_cr : u32
{
  PWR_CR_LPDS = (1 << 0),
  PWR_CR_PDDS = (1 << 1),
  PWR_CR_CWUF = (1 << 2),
  PWR_CR_CSBF = (1 << 3),

#if defined(STM32_PWR_PVD)
  PWR_CR_PVDE = (1 << 4),
#endif

  PWR_CR_DBP = (1 << 8)
};

#if defined(STM32_PWR_PVD)
/* Bits[7:5] */
#define PWR_CR_PLS_SHIFT (5)
#define PWR_CR_PLS_MASK (0x7u)

enum pwr_cr_pls : u32
{
  PWR_CR_PLS_2dot2v = 0b000,
  PWR_CR_PLS_2dot3v = 0b001,
  PWR_CR_PLS_2dot4v = 0b010,
  PWR_CR_PLS_2dot5v = 0b011,
  PWR_CR_PLS_2dot6v = 0b100,
  PWR_CR_PLS_2dot7v = 0b101,
  PWR_CR_PLS_2dot8v = 0b110,
  PWR_CR_PLS_2dot9v = 0b111
};
#endif

enum pwr_csr : u32
{
  PWR_CSR_WUF = (1 << 0),
  PWR_CSR_SBF = (1 << 1),
  PWR_CSR_PVDO = (1 << 2),

#if defined(STM32_PWR_VREF)
  PWR_CSR_VREFINTRDY = (1 << 3),
#endif

  PWR_CSR_EWUP1 = (1 << 8),

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR_CSR_EWUP2 = (1 << 9),
  PWR_CSR_EWUP3 = (1 << 10),
  PWR_CSR_EWUP4 = (1 << 11),
  PWR_CSR_EWUP5 = (1 << 12),
  PWR_CSR_EWUP6 = (1 << 13),
  PWR_CSR_EWUP7 = (1 << 14),
  PWR_CSR_EWUP8 = (1 << 15)
#endif
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

/**
 * @brief Available voltage regulator modes. 
 *
 * @see pwr_set_voltage_regulator_mode()
 */
enum pwr_voltage_regulator_mode
{
  /**
   * @brief Voltage regulator on during stop mode.
   *
   * @details The voltage regulator operates
   * in normal mode when the devices is in
   * stop mode.
   */
  PWR_VOLTAGE_REGULATOR_MODE_DEFAULT,

  /**
   * @brief Voltage regulator in low-power mode
   * during stop mode.
   *
   * @details The voltage regulator operates
   * in low-power mode when the devices is in
   * stop mode.
   */
  PWR_VOLTAGE_REGULATOR_MODE_LOW_POWER
};

/**
 * @brief Available deepsleep modes.
 *
 * @see pwr_set_deepsleep_mode()
 */
enum pwr_deepsleep_mode
{
  /**
   * @brief Enters stop mode when the CPU
   * enters deepsleep.
   */
  PWR_DEEPSLEEP_MODE_STOP_MODE,

  /**
   * @brief Enters standby mode when the CPU
   * enters deepsleep.
   */
  PWR_DEEPSLEEP_MODE_STANDBY_MODE
};

/**
 * @brief Available pwr flags.
 */
enum pwr_flag
{
  /**
   * @brief Set when the device enters standby mode.
   *
   * @details This flag is set when the device
   * enters standby mode.
   *
   * @note This flag can be cleared either manually
   * or with a POR/PDR ([Power On / Power Down] Reset).
   *
   * @see pwr_is_flag_set()
   * @see pwr_flag_clear()
   */
  PWR_FLAG_STANDBY,

  /**
   * @brief Set when a wakeup event occurs.
   *
   * @details This flag is set when a wakeup event
   * is detected from the wakeup pin or the RTC alarm.
   *
   * @note This flag can be cleared either manually
   * or by a system reset.
   *
   * @see pwr_is_flag_set()
   * @see pwr_flag_clear()
   */
  PWR_FLAG_WAKEUP
};

#if defined(STM32_PWR_PVD)
/**
 * @brief Available voltage detector levels.
 *
 * @see pwr_set_voltage_detector_level()
 */
enum pwr_voltage_detector_level
{
  /**
   * @brief 2.2v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot2v,

  /**
   * @brief 2.3v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot3v,

  /**
   * @brief 2.4v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot4v,

  /**
   * @brief 2.5v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot5v,

  /**
   * @brief 2.6v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot6v,

  /**
   * @brief 2.7v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot7v,

  /**
   * @brief 2.8v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot8v,

  /**
   * @brief 2.9v threshold.
   */
  PWR_VOLTAGE_DETECTOR_LEVEL_2dot9v
};
#endif

enum pwr_wakeup_pin
{
  PWR_WAKEUP_PIN1,

#if defined(STM32_PWR_MULTI_WKUP_PIN)
  PWR_WAKEUP_PIN2,
  PWR_WAKEUP_PIN3,
  PWR_WAKEUP_PIN4,
  PWR_WAKEUP_PIN5,
  PWR_WAKEUP_PIN6,
  PWR_WAKEUP_PIN7,
  PWR_WAKEUP_PIN8
#endif
};

extern volatile struct pwr_registers_map* PWR;


#if defined(STM32_PWR_PVD)
/**
 * @brief Sets the voltage regulator mode.
 *
 * @details Configures how the voltage regulator
 * operates when the device enters stop mode.
 * 
 * @param mode The mode to configure.
 *
 * @see enum pwr_voltage_regulator_mode
 */
void
pwr_set_voltage_regulator_mode(
  enum pwr_voltage_regulator_mode mode
);
#endif

/**
 * @brief Sets the deepsleep mode.
 *
 * @details Configures how the system
 * operates when the device enters
 * deepsleep mode.
 *
 * @param mode The mode to configure.
 *
 * @see enum pwr_deepsleep_mode
 * @see scb_enter_deepsleep() // TODO
 */
void
pwr_set_deepsleep_mode(
  enum pwr_deepsleep_mode mode
);

/**
 * @brief Clears a specific pwr flag.
 *
 * @param flag The flag to clear.
 *
 * @note PWR_FLAG_WAKEUP is cleared after 2 system clock cycles.
 *
 * @see enum pwr_flag
 * @see pwr_is_flag_set()
 */
void
pwr_flag_clear(
  enum pwr_flag flag
);


#if defined(STM32_PWR_PVD)
/**
 * @brief Enables the voltage detector.
 *
 * @see pwr_set_voltage_detector_level()
 */
void
pwr_voltage_detector_enable(void);

/**
 * @brief Disables the voltage detector.
 *
 * @see pwr_set_voltage_detector_level()
 */
void
pwr_voltage_detector_disable(void);

/**
 * @brief Sets the voltage detector level.
 *
 * @details Configures the voltage threshold
 * level of the voltage detector.
 *
 * @param level The level to configure.
 *
 * @see enum pwr_voltage_detector_level
 * @see pwr_voltage_detector_enable()
 * @see pwr_voltage_detector_disable()
 */
void
pwr_set_voltage_detector_level(
  enum pwr_voltage_detector_level level
);
#endif

/**
 * @brief Enables the backup domain write protection.
 *
 * @details Enabling this protects RTC and 
 * backup registers against parasitic and/or
 * accidental software write access.
 *
 * @see pwr_backup_domain_protection_disable()
 */
void
pwr_backup_domain_protection_enable(void);

/**
 * @brief Disables the backup domain write protection.
 *
 * @see pwr_backup_domain_protection_enable()
 */
void
pwr_backup_domain_protection_disable(void);

/**
 * @brief Checks if a given flag is set.
 *
 * @param flag The flag to check.
 *
 * @return Non-zero if the flag is set,
 * 0 otherwise.
 *
 * @see enum pwr_flag
 * @see pwr_flag_clear()
 */
u32
pwr_is_flag_set(
  enum pwr_flag flag
);

/**
 * @brief Checks the voltage detector status.
 *
 * @details Reads the current voltage detector
 * status to determine if VDD has fallen below
 * the programmed threshold level.
 *
 * @return Non-zero if VDD is lower than the configured threshold,
 * 0 otherwise.
 *
 * @see pwr_set_voltage_detector_level()
 * @see pwr_voltage_detector_enable()
 */
u32
pwr_voltage_detector_level_compare(void);

/**
 * @brief Enables the wakeup pin.
 *
 * @details Configures the dedicated wakeup pin
 * to wake up the device from standby mode when 
 * a rising edge is detected.
 *
 * @note This function is only relevant in Standby mode.
 *
 * @note Ensure to clear the wakeup flag before entering
 * standby mode to avoid unintended immediate wakeup.
 *
 * @see pwr_wakeup_pin_disable()
 * @see pwr_flag_clear()
 */
void
pwr_wakeup_pin_enable(
  enum pwr_wakeup_pin pin
);

/**
 * @brief Disables the wakeup pin.
 *
 * @details Configures the dedicated wakeup pin
 * as a general purpose I/O.
 *
 * @see pwr_wakeup_pin_enable()
 */
void
pwr_wakeup_pin_disable(
  enum pwr_wakeup_pin pin
);

END_DECLARATIONS

#endif
