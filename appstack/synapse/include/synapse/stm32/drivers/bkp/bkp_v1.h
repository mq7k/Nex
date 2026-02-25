/**
 * @file bkp.h
 * @brief Backup Registers (BKP) interface.
 *
 * @details This header file provides function prototypes for 
 * accessing and configuring backup registers, tamper detection, 
 * and RTC-related backup features.
 *
 * @note Backup registers retain their values during low-power 
 * modes but may reset after a power loss.
 */
#ifndef STM32_DRIVER_BKP_H
#define STM32_DRIVER_BKP_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"

/**
 * Supports:
 *  - STM32F1
 */

BEGIN_DECLARATIONS

/**
 * @brief Backup registers memory map.
 *
 * @details Represents the memory layout of the backup registers in the 
 * backup domain. These registers are used for storing data that persists 
 * through system resets and low-power modes, provided that the backup 
 * domain remains powered.
 */
struct bkp_registers_map
{
  u32 __padding0;

  /**
   * @brief BKP_DRx - Backup data register x
   *
   * @details
   * Offset: 0x4 ... 0x28
   * <br>
   * Reset: 0x0000 0000
   *
   * @note The BKP_DRx registers are reset ONLY
   * by a backup domain reset or by a tamper pin event
   * (if the tamper pin function is enabled).
   */
  u32 DR0[10];

  /**
   * @brief BKP_RTCCR - RTC clock calibration register
   *
   * @details
   * Offset: 0x2c
   * <br>
   * Reset: 0x0000 0000
   */
  u32 RTCCR;

  /**
   * @brief BKP_CR - Backup control register
   *
   * @details
   * Offset: 0x30
   * <br>
   * Reset: 0x0000 0000
   */
  u32 CR;

  /**
   * @brief BKP_CSR - Backup control/status register
   *
   * @details
   * Offset: 0x34
   * <br>
   * Reset: 0x0000 0000
   */
  u32 CSR;

  u32 __padding1[2];

  /**
   * @brief BKP_DRx - Backup data register x
   *
   * @details
   * Offset: 0x40 ... 0xbc
   * <br>
   * Reset: 0x0000 0000
   *
   * @note The BKP_DRx registers are reset ONLY
   * by a backup domain reset or by a tamper pin event
   * (if the tamper pin function is enabled).
   */
  u32 DR1[32];
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#define BKP_DR_MASK (0xffff)
#define BKP_DR_MAX_IDX (41)

/* Bits[6:0] */
#define BKP_RTCCR_CAL_SHIFT (0)
#define BKP_RTCCR_CAL_MASK (0x3fu)

enum bkp_rtccr : u32
{
  BKP_RTCCR_CCO = (1 << 7),
  BKP_RTCCR_ASOE = (1 << 8),
  BKP_RTCCR_ASOS = (1 << 9)
};

enum bkp_cr : u32
{
  BKP_CR_TPE = (1 << 0),
  BKP_CR_TPAL = (1 << 1)
};

enum bkp_csr : u32
{
  BKP_CSR_CTE = (1 << 0),
  BKP_CSR_CTI = (1 << 1),
  BKP_CSR_TPIE = (1 << 2),
  BKP_CSR_TEF = (1 << 8),
  BKP_CSR_TIF = (1 << 9)
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

/**
 * @brief Available RTC output signals.
 *
 * @details Defines the possible RTC signals 
 * that can be output via the backup domain
 * registers. These signals can be used
 * for external synchronization or event triggering.
 *
 * @see bkp_rtc_signal_output_enable()
 * @see bkp_set_rtc_output_signal()
 */
enum bkp_rtc_signal
{
  /**
   * @brief RTC signal alarm.
   *
   * @details This signal is triggered 
   * when the RTC alarm condition is met. 
   * It can be used to wake up the system 
   * or generate an external event.
   */
  BKP_RTC_SIGNAL_ALARM,

  /**
   * @brief RTC signal second.
   *
   * @details This signal outputs a pulse
   * every second, which can be used for
   * periodic time synchronization or clock
   * calibration.
   */
  BKP_RTC_SIGNAL_SECOND
};

/**
 * @brief Tamper pin active level configuration.
 *
 * @details Defines the active logic level that 
 * triggers the tamper detection event. The tamper
 * pin monitors unauthorized access to the backup
 * registers and triggers an event when the configured
 * level is detected.
 *
 * @see bkp_tamper_pin_enable()
 * @see bkp_set_tamper_pin_active_level()
 */
enum bkp_tamper_pin_level
{
  /**
   * @brief Tamper event triggered on low level.
   *
   * @details The tamper detection event occurs
   * when the tamper pin is pulled low.
   */
  BKP_TAMPER_PIN_LEVEL_LOW,

  /**
   * @brief Tamper event triggered on high level.
   *
   * @details The tamper detection event occurs
   * when the tamper pin is pulled high.
   */
  BKP_TAMPER_PIN_LEVEL_HIGH
};

extern volatile struct bkp_registers_map* BKP;

/**
 * @brief Writes data to a backup register.
 *
 * @details Stores a 32-bit value into the 
 * specified backup register. The backup 
 * registers retain their values even during 
 * system resets or low-power modes, as long as
 * power is maintained to the backup domain.
 *
 * @param idx The index of the backup register to write to.
 * @param value The 32-bit value to store in the backup register.
 *
 * @note The backup domain must be unlocked before modifying 
 * backup registers.
 * Use `pwr_backup_domain_write_protection_enable()`
 * before calling this function.
 *
 * @see bkp_data_read()
 * @see pwr_backup_domain_write_protection_enable()
 */
void
bkp_data_write(
  u32 idx,
  u32 value
);

/**
 * @brief Reads data from a backup register.
 *
 * @details Retrieves a 32-bit value from the 
 * specified backup register. The backup registers
 * retain their values across resets and power cycles,
 * provided that backup domain power is maintained.
 *
 * @param idx The index of the backup register to read from.
 * @return The 32-bit value stored in the specified backup register.
 *
 * @note The backup registers may contain invalid data after a power 
 * loss unless explicitly initialized.
 *
 * @see bkp_data_write()
 */
u32
bkp_data_read(
  u32 idx
);

/**
 * @brief Sets the RTC calibration value.
 *
 * @details Adjusts the RTC calibration to compensate 
 * for clock drift. This function sets a calibration
 * value that fine-tunes the RTC clock frequency,
 * ensuring more accurate timekeeping.
 *
 * @param value The RTC calibration value to apply.
 *
 * @note The calibration value is device-specific and 
 * should be determined experimentally or based on
 * manufacturer guidelines.
 *
 * @see bkp_rtc_calib_clock_outout_enable()
 */
void
bkp_set_rtc_calibration_value(
  u32 value
);

/**
 * @brief Enables the RTC calibration clock output.
 *
 * @details Outputs a reference clock signal from the
 * RTC for calibration purposes. This signal can be
 * measured externally to fine-tune and verify
 * RTC accuracy.
 *
 * @note The output frequency depends on the RTC 
 * calibration settings. This feature is useful for
 * adjusting and verifying RTC precision.
 *
 * @see bkp_set_rtc_calibration_value()
 */
void
bkp_rtc_calib_clock_output_enable(void);

/**
 * @brief Enables RTC signal output.
 *
 * @details Configures the RTC to output a selectable
 * signal, such as the RTC alarm or second pulse, through
 * the backup domain. This feature is useful for external
 * synchronization.
 *
 * @note The output signal type must be configured separately.
 *
 * @see bkp_set_rtc_output_signal()
 * @see enum bkp_rtc_signal
 */
void
bkp_rtc_signal_output_enable(void);

/**
 * @brief Configures the RTC output signal.
 *
 * @details Selects the RTC signal to be output 
 * through the backup domain.
 *
 * @param signal The RTC signal to output.
 *
 * @note The RTC signal output must be enabled separately.
 *
 * @see bkp_rtc_signal_output_enable()
 * @see enum bkp_rtc_signal
 */
void
bkp_set_rtc_output_signal(
  enum bkp_rtc_signal signal
);

/**
 * @brief Enables the tamper detection pin.
 *
 * @details Activates the tamper pin, allowing it
 * to monitor for unauthorized access or external
 * events that could compromise the backup registers.
 *
 * @note The tamper detection level should be configured
 * before enabling the tamper pin.
 *
 * @note Tamper pin can only be disabled
 *
 * @see bkp_set_tamper_pin_active_level()
 */
void
bkp_tamper_pin_enable(void);

/**
 * @brief Disables the tamper detection pin.
 *
 * @details Deactivates the tamper pin, preventing
 * it from generating tamper detection events.
 * This function can be used when tamper protection
 * is no longer needed.
 *
 * @see bkp_tamper_pin_enable()
 */
void
bkp_tamper_pin_disable(void);

/**
 * @brief Sets the active level for the tamper pin.
 *
 * @details Configures the logic level (high or low) 
 * that will trigger the tamper detection event.
 *
 * @param level The tamper pin active level.
 *
 * @note Changing this setting does not automatically
 * enable the tamper pin.
 *
 * @see bkp_tamper_pin_enable()
 * @see enum bkp_tamper_pin_level
 */
void
bkp_set_tamper_pin_active_level(
  enum bkp_tamper_pin_level level
);

/**
 * @brief Clears the tamper event flag.
 *
 * @details Resets the flag that indicates a tamper
 * event has occurred. This function should be called
 * after handling a tamper event to acknowledge and 
 * clear the event status.
 *
 * @note Clearing the tamper event flag does not clear 
 * the tamper interrupt flag.
 *
 * @see bkp_is_tamper_event_flag_set()
 * @see bkp_tamper_interrupt_clear()
 */
void
bkp_tamper_event_clear(void);

/**
 * @brief Clears the tamper interrupt flag.
 *
 * @details Resets the flag that indicates a tamper-related 
 * interrupt has occurred. This function should be called
 * after handling the tamper interrupt to acknowledge and
 * clear the interrupt status.
 *
 * @note Clearing the tamper interrupt flag does not clear
 * the tamper event flag.
 *
 * @see bkp_is_tamper_interrupt_flag_set()
 * @see bkp_tamper_event_clear()
 */
void
bkp_tamper_interrupt_clear(void);

/**
 * @brief Enables tamper interrupt.
 *
 * @details Allows the tamper detection system to
 * generate an interrupt when a tamper event occurs.
 * This is useful for handling tamper events in an 
 * interrupt-driven manner.
 *
 * @note Ensure the tamper pin is enabled before enabling 
 * the tamper interrupt.
 *
 * @see bkp_tamper_interrupt_disable()
 * @see bkp_tamper_pin_enable()
 */
void
bkp_tamper_interrupt_enable(void);

/**
 * @brief Disables tamper interrupt.
 *
 * @details Prevents the tamper detection system from generating interrupts. 
 * Tamper events will still be recorded, but no interrupt will be triggered.
 *
 * @see bkp_tamper_interrupt_enable()
 */
void
bkp_tamper_interrupt_disable(void);

/**
 * @brief Checks if a tamper event has occurred.
 *
 * @details Returns whether a tamper event has been 
 * detected. The event flag must be cleared manually
 * after handling the event.
 *
 * @return Non-zero if a tamper event has been detected, 
 * 0 otherwise.
 *
 * @see bkp_tamper_event_clear()
 */
u32
bkp_is_tamper_event_flag_set(void);

/**
 * @brief Checks if a tamper interrupt has occurred.
 *
 * @details Returns whether a tamper-related interrupt 
 * has been triggered. The interrupt flag must be cleared
 * manually after handling the interrupt.
 *
 * @return Non-zero if a tamper interrupt has been triggered, 
 * 0 otherwise.
 *
 * @see bkp_tamper_interrupt_clear()
 */
u32
bkp_is_tamper_interrupt_flag_set(void);

END_DECLARATIONS

#endif
