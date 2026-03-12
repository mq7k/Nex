/**
 * @file systick.h
 */
#ifndef CM3_SYSTICK_H
#define CM3_SYSTICK_H

#include "libcom/types.h"

/**
 * @brief SYST_CSR - Control and Status Register
 *
 * @details
 * Offset: 0x0
 * <br>
 * Reset:
 *  - 0x0000 0004 if the device do not implement a reference clock,
 *  - 0x0000 0000 otherwise.
 */

/*#define MEMPTR(x) *((u32*) (x))*/
// #define SYSTICK_CSR MEMPTR(CM3_SYSTICK_CSR_ADDR)

/**
 * @brief SYST_RVR - Reload Value Register
 *
 * @details
 * Offset: 0x4
 * <br>
 * Reset: Unpredictable
 */
// #define SYSTICK_RVR MEMPTR(CM3_SYSTICK_RVR_ADDR)

/**
 * @brief SYST_CVR - Current Value Register
 *
 * @details
 * Offset: 0x8
 * <br>
 * Reset: Unpredictable
 */
// #define SYSTICK_CVR MEMPTR(CM3_SYSTICK_CVR_ADDR)

/**
 * @brief SYST_CALIB - Calibration Value Register
 *
 * @details
 * Offset: 0xc
 * <br>
 * Reset: STCALIB
 */
// #define SYSTICK_CALR MEMPTR(CM3_SYSTICK_CALR_ADDR)

struct systick_registers_map
{
  u32 CSR;
  u32 RVR;
  u32 CVR;
  u32 CALIB;
};

// Core

enum systick_csr : u32
{
  SYSTICK_CSR_ENABLE = (1 << 0),
  SYSTICK_CSR_TICKINT = (1 << 1),
  SYSTICK_CSR_CLKSOURCE = (1 << 2),
  SYSTICK_CSR_COUNTFLAG = (1 << 16)
};

/* Bits[23:0] */
#define SYSTICK_RVR_SHIFT (0)
#define SYSTICK_RVR_MASK (0xffffff)

/* Bits[23:0] */
#define SYSTICK_CVR_SHIFT (0)
#define SYSTICK_CVR_MASK (0xffffff)

enum systick_calib : u32
{
  SYSTICK_CALIB_SKEW = (1 << 30),
  SYSTICK_CALIB_NOREF = (1u << 31)
};

/* Bits[23:0] */
#define SYSTICK_CALIB_TENMS_SHIFT (0)
#define SYSTICK_CALIB_TENMS_MASK (0xffffff)

// API

enum systick_clock_source
{
  SYSTICK_CLOCK_SOURCE_PROCESSOR,
  SYSTICK_CLOCK_SOURCE_EXTERNAL
};

extern volatile struct systick_registers_map* SYSTICK;

/**
 * @brief Enables the SysTick.
 *
 * @details When enabled, the will count down from
 * the reload value to zero, then reload and 
 * continue counting.
 *
 * @note The timer must be configured properly before enabling.
 * @see systick_disable()
 */
void
systick_enable(void);

/**
 * @brief Disables the systick tick.
 *
 * @details Stops the systick counter.
 *
 * @note Any pending interrupts from the systick
 * will remain pending until cleared.
 *
 * @see systick_enable()
 */
void
systick_disable(void);

/**
 * @brief Turns on the SysTick interrupts.
 *
 * @detail Enables the generation of interrupt requests 
 * when the SysTick counter reaches zero. The interrupt
 * will trigger the SysTick handler function.
 *
 * @note The timer must be configured properly before enabling.
 * @see systick_interrupt_disable()
 */
void
systick_interrupt_enable(void);

/**
 * @brief Turns off the SysTick interrupt.
 *
 * @details Disables the generation of interrupts requests
 * from the SysTick. The timer will continue to count
 * (if enabled), but no interrupts will be generated when
 * it reaches zero.
 *
 * @see systick_interrupt_enable()
 */
void
systick_interrupt_disable(void);

/**
 * @brief Sets the clock source for the SysTick timer.
 *
 * @details Configures which clock source the SysTick
 * timer will use. Changing the clock source allow to select
 * the best source to generate the desired timer frequency 
 * and period.
 *
 * @param source The clock source to use.
 *
 * @note Changing the clock source might affect the 
 * timer frequency and period.
 *
 * @see systick_clock_source
 */
void
systick_set_clock_source(
  enum systick_clock_source
);

/**
 * @brief Checks if the SysTick timer has overflowed.
 *
 * @details Returns the status of the SysTick timer
 * counter overflow flag. The flag is set when the counter
 * transitions from 1 to 0.
 *
 * @return Non-zero if the timer has overflowed since the last read,
 * 0 otherwise.
 * 
 * @note Reading this flag automatically clears it.
 * @see systick_enable()
 */
u32
systick_has_overflowed(void);

// RVR
/**
 * @brief Sets the reload value for the SysTick timer.
 *
 * @details Configures the value that will be loaded into
 * the SysTick counter when it reaches zero. This 
 * effectively sets the period of the timer.
 *
 * @param value The 24-bit value to load (0 to 0xffffff).
 *
 * @note The effective period of the timer will be (value + 1)
 * clock cycles.
 *
 * @note Writing any value to the reload register clears the
 * current value.
 *
 * @see systick_get_current_value()
 */
void
systick_set_reload_value(
  u32 value
);

// CVR
/**
 * @brief Sets the current value of the SysTick counter.
 *
 * @details Writes a value to the SysTick counter value
 * register. This will immediately replace the current 
 * counter value.
 *
 * @param value The 24-bit value to set (0 to 0xffffff).
 *
 * @note Writing any value to the current value register clears
 * the overflow flag (COUTNFLAG bit in SYST_CSR).
 * 
 * @see systick_get_current_value()
 */
void
systick_set_current_value(
  u32 value
);

/**
 * @brief Gets the current value of the SysTick counter.
 *
 * @return The current 24-bit value of the SysTick counter.
 *
 * @note Reading the current value does not affect the counter operation.
 *
 * @see systick_set_current_value()
 */
u32
systick_get_current_value(void);

// CALIB
/**
 * @brief Gets the calibration value for the SysTick timer.
 *
 * @details Returns the calibration value provided by the 
 * microcontroller. This value tipically represents the number
 * if ticks that correspond to a time interval of 10ms.
 * However, the time span is implementation-defined, refer to
 * the datasheet of your device for more information.
 *
 * @return The calibration value (24-bit).
 *
 * @warning The returned value is hardware-specific and may not
 * be available on all devices.
 *
 * @see systick_is_calibration_value_available()
 */
u32
systick_get_calibration_value(void);

/**
 * @brief Checks if a calibration value is available.
 *
 * @details Determines whether the SysTick calibration
 * value register contains a valid value.
 *
 * @return Non-zero if calibration value is available,
 *         0 otherwise.
 *
 * @see systick_get_calibration_value()
 */
u32
systick_is_calibration_value_available(void);

/**
 * @brief Checks if the SysTick timer has a reference clock.
 *
 * @details Determines whether the SysTick timer has an 
 * external reference clock.
 *
 * @return Non-zero if an external reference clock is available,
 * 0 otherwise.
 *
 * @note The presence of a reference clock allows the timer to
 * operate even when the processor is in a low-power mode.
 * (Implementation-defined, refer to your MCU datasheet).
 *
 * @see systick_set_clock_source()
 */
u32
systick_has_reference_clock(void);

#endif
