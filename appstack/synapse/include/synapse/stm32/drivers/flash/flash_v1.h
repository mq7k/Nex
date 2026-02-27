
/**
 * @file flash.h
 * @brief Flash memory interface.
 *
 * @details This header file provides function prototypes and 
 * definitions for configuring and accessing the embedded flash 
 * memory, including read, write, and erase operations.
 *
 * @note Modifying flash memory requires caution, as improper 
 * operations may lead to data corruption.
 */
#ifndef STM32_DRIVER_FLASH_H
#define STM32_DRIVER_FLASH_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F0x
 *  - STM32F1x
 *
 * Available flags:
 * - STM32_FLASH_EXTENDED
 *   Enables extended flash registers layout.
 *   If enabled, register `ACR`, `KEYR`, `OPTKEYR`, `SR`, `CR`, `AR`, `OBR` and
 *   `WRPR` are defined.
 *   If disabled, only `ACR` is defined.
 *
 * - STM32_FLASH_HALF_CYCLE_ACCESS
 *   Enables flash half cycle access.
 *   If enabled, bit 3 (HLFCYA) in register `ACR` is defined.
 *
 * - STM32_FLASH_PREFETCH_BUFFER
 *   Enables prefetch buffer.
 *   If enabled, defines:
 *    - Bit 4, 5 in register `ACR`.
 *    - `flash_prefetch_buffer_enable()`.
 *    - `flash_prefetch_buffer_disable()`.
 *    - `flash_get_prefetch_buffer_status()`.
 *
 * - STM32_FLASH_OBR_BOOT0
 *   Enables boot0.
 *   If enabled, bit 11 in register `OBR` is defined.
 *
 * - STM32_FLASH_SRAM_PE
 *   Enables SRAM parity check.
 *   If enabled, bit 14 in register `OBR` is defined.
 *
 * - STM32_FLASH_OBR_BOOTSEL
 *   Enables bootsel.
 *   If enabled, bit 15 in register `OBR` is defined.
 *   Cannot be used together with STM32_FLASH_OBR_SDADC_VDD_MONITOR.
 *
 * - STM32_FLASH_OBR_SDADC_VDD_MONITOR
 *   Enables ADC VDD monitor.
 *   If enabled, bit 15 in register `OBR` is defined.
 *   Cannot be used together with STM32_FLASH_OBR_BOOTSEL.
 */

BEGIN_DECLARATIONS

/**
 * @brief FLASH memory registers map.
 *
 * @details Represents the memory-mapped registers of the 
 * embedded Flash memory controller. The Flash controller 
 * handles program/erase operations and access control for 
 * the internal Flash memory.
 *
 * @note Flash memory operations, such as erasing and writing, 
 * must follow specific timing and voltage requirements 
 * defined in the MCU reference manual.
 */
struct flash_registers_map
{
  /**
   * @brief FLASH_ACR - Flash access control register
   *
   * @details
   * Offset: 0x0
   * <br>
   * Reset: 0x0000 0030
   */
  u32 ACR;

#if defined(STM32_FLASH_EXTENDED)
  u32 KEYR;
  u32 OPTKEYR;
  u32 SR;
  u32 CR;
  u32 AR;
  u32 OBR;
  u32 WRPR;
#endif
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#if defined(STM32_FLASH_ACR)
enum flash_acr : u32
{
#if defined(STM32_FLASH_HALF_CYCLE_ACCESS)
  FLASH_ACR_HLFCYA = (1 << 3),
#endif

#if defined(STM32_FLASH_PREFETCH_BUFFER)
  FLASH_ACR_PRFTBE = (1 << 4),
  FLASH_ACR_PRFTBS = (1 << 5)
#endif
};
#endif

/* Bits[2:0] */
#define FLASH_ACR_LATENCY_SHIFT (0)
#define FLASH_ACR_LATENCY_MASK (0x7u)

enum flash_acr_latency
{
  FLASH_ACR_LATENCY_WS0 = 0b000,
  FLASH_ACR_LATENCY_WS1 = 0b001,
  FLASH_ACR_LATENCY_WS2 = 0b010
};

#if defined(STM32_FLASH_EXTENDED)
enum flash_sr : u32
{
  FLASH_SR_BSY = (1 << 0),
  FLASH_SR_PGERR = (1 << 2),
  FLASH_SR_WRPRTERR = (1 << 4),
  FLASH_SR_EOP = (1 << 5)
};

enum flash_cr : u32
{
  FLASH_CR_PG = (1 << 0),
  FLASH_CR_PER = (1 << 1),
  FLASH_CR_MER = (1 << 2),
  FLASH_CR_OPTPG = (1 << 4),
  FLASH_CR_OPTER = (1 << 5),
  FLASH_CR_STRT = (1 << 6),
  FLASH_CR_LOCK = (1 << 7),
  FLASH_CR_OPTWRE = (1 << 9),
  FLASH_CR_ERRIE = (1 << 10),
  FLASH_CR_EOPIE = (1 << 12),
  FLASH_CR_OBLLAUNCH = (1 << 13)
};

enum flash_obr : u32
{
  FLASH_OBR_OPTERR = (1 << 0),
  FLASH_OBR_WDGSW = (1 << 8),
  FLASH_OBR_RSTSTOP = (1 << 9),
  FLASH_OBR_RSTSTDBY = (1 << 10),

#if defined(STM32_FLASH_OBR_BOOT0)
  FLASH_OBR_BOOT0 = (1 << 11),
#endif

  FLASH_OBR_BOOT1 = (1 << 12),
  FLASH_OBR_VDDAMONITOR = (1 << 13),

#if defined(STM32_FLASH_SRAM_PE)
  FLASH_OBR_RAMPARITYCHECK = (1 << 14),
#endif

#if defined(STM32_FLASH_OBR_BOOTSEL)
  FLASH_OBR_BOOTSEL = (1 << 15)
#elif defined(STM32_FLASH_OBR_SDADC_VDD_MONITOR)
  FLASH_OBR_SDADC12_VDD_MONITOR = (1 << 15)
#endif
};

#define FLASH_OBR_RDPRT_SHIFT (1)
#define FLASH_OBR_RDPRT_MASK (0x3)

enum flash_obr_rdprt : u32
{
  FLASH_OBR_RDPRT_LEVEL0 = 0b00,
  FLASH_OBR_RDPRT_LEVEL1 = 0b01,
  FLASH_OBR_RDPRT_LEVEL2 = 0b11
};

#define FLASH_OBR_DATA0_SHIFT (16)
#define FLASH_OBR_DATA0_MASK (0xff)

#define FLASH_OBR_DATA1_SHIFT (24)
#define FLASH_OBR_DATA1_MASK (0xff)
#endif


// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

/**
 * @brief Available flash wait states.
 *
 * @details If the sysclock has a higher frequency than
 * the flash memory controller (~24Mhz),
 * wait states are inserted to let the memory controller
 * "catch up".
 * The flash access time should be configured according
 * to the sysclock frequency, such as:
 *  - 0Mhz < sysclock <= 24Mhz -> Zero wait state 
 *  - 24Mhz < sysclock <= 48Mhz -> One wait state
 *  - 48Mhz < sysclock <= 72Mhz -> Two wait states
 *
 * @note Wait states should be set according to the
 * current sysclock frequency.
 *
 * @see flash_set_wait_state()
 */
enum flash_wait_state
{
  /**
   * @brief No wait state.
   *
   * @detail No latency is induced.
   * Used when: 0Mhz < sysclock <= 24Mhz.
   */
  FLASH_WAIT_STATE0,

  /**
   * @brief One wait state.
   *
   * @detail One wait state is induced.
   * Used when: 24Mhz < sysclock <= 48Mhz.
   */
  FLASH_WAIT_STATE1,

  /**
   * @brief Two wait states.
   *
   * @detail Two wait states are induced.
   * Used when: 48Mhz < sysclock <= 72Mhz.
   */
  FLASH_WAIT_STATE2
};

// API
#if defined(STM32_FLASH_EXTENDED)
enum flash_flag
{
  FLASH_FLAG_BUSY,
  FLASH_FLAG_PROGRAMMING_ERROR,
  FLASH_FLAG_WRITE_PROTECTION_ERROR,
  FLASH_FLAG_EOP
};

enum flash_interrupt
{
  FLASH_INTERRUPT_ERROR,
  FLASH_INTERRUPT_EOP
};

enum flash_option
{
  FLASH_OPTION_OPTION_BYTE_ERROR,
  FLASH_OPTION_RST_STANDBY,
  FLASH_OPTION_RST_STOP,
  FLASH_OPTION_WDG_SW,
  FLASH_OPTION_RAM_PARITY_CHECK,
  FLASH_OPTION_VDDA_MONITOR,

#if defined(STM32_FLASH_BOOT0)
  FLASH_OPTION_BOOT0,
#endif

  FLASH_OPTION_BOOT1,

#if defined(STM32_FLASH_BOOTSEL)
  FLASH_OPTION_BOOTSEL
#elif defined(FLASH_OPTION_SDADC12_VDD_MONITOR)
  FLASH_OPTION_SDADC12_VDD_MONITOR
#endif
};
#endif

extern volatile struct flash_registers_map* FLASH;

/**
 * @brief Sets the flash memory latency.
 *
 * @details If the sysclock has a higher frequency than
 * the flash memory controller (~24Mhz),
 * wait states are inserted to let the memory controller
 * "catch up".
 * The flash access time should be configured according
 * to the sysclock frequency, such as:
 *  - 0Mhz < sysclock <= 24Mhz -> Zero wait state 
 *  - 24Mhz < sysclock <= 48Mhz -> One wait state
 *  - 48Mhz < sysclock <= 72Mhz -> Two wait states
 *
 * @param wait_state The latency to set.
 *
 * @see flash_wait_state
 */
void
flash_set_wait_state(
  enum flash_wait_state wait_state
);

#if defined(STM32_FLASH_HALF_CYCLE_ACCESS)
/**
 * @brief Enables half cycle memory access.
 *
 * @details Half cycle access allows the memory to be accessed
 * in half a system clock cycle instead of a full cycle.
 * This could potentially (almost) double the access speed
 * to the flash memory.
 * But, enabling this would also increase the power usage,
 * and making the memory controller operating at higher temperature.
 * Also, this could cause instabilities if
 * the controller would not be able to operate at this frequency.
 *
 * @see flash_prefetch_buffer_disable()
 */
void
flash_half_cycle_access_enable(void);

/**
 * @brief Disables half cycle memory access.
 *
 * @see flash_half_cycle_access_enable()
 */
void
flash_half_cycle_access_disable(void);
#endif

#if defined(STM32_FLASH_PREFETCH_BUFFER)
/**
 * @brief Enables the prefetch buffer.
 *
 * @details Enabling the prefetch buffer allows
 * fetching instructions from the flash
 * ahead of time to reduce latency.
 * This is especially useful when executing
 * sequential code, since the instruction flow
 * is predictable.
 * Conversely, when the execution is not linear,
 * enabling the prefetch could potentially lead to
 * worse performance.
 *
 * @see flash_prefetch_buffer_disable()
 * @see flash_get_prefetch_buffer_status()
 */
void
flash_prefetch_buffer_enable(void);

/**
 * @brief Disables the prefetch buffer.
 *
 * @see flash_prefetch_buffer_enable()
 * @see flash_get_prefetch_buffer_status()
 */
void
flash_prefetch_buffer_disable(void);

/**
 * @brief Gets the current prefetch buffer status.
 *
 * @return Non-zero if the prefetch is enabled, 
 * 0 otherwise.
 *
 * @see flash_prefetch_buffer_enable()
 * @see flash_prefetch_buffer_disable()
 */
u32
flash_get_prefetch_buffer_status(void);
#endif

#if defined(STM32_FLASH_EXTENDED)
void
flash_unlock(void);

void
flash_option_unlock(void);

u32
flash_is_flag_set(
  enum flash_flag flag
);

void
flash_flag_clear(
  enum flash_flag flag
);

void
flash_programming_enable(void);

void
flash_programming_disable(void);

void
flash_page_erase_enable(void);

void
flash_page_erase_disable(void);

void
flash_mass_erase_enable(void);

void
flash_mass_erase_disable(void);

void
flash_option_byte_programming_enable(void);

void
flash_option_byte_programming_disable(void);

void
flash_option_byte_erase_enable(void);

void
flash_option_byte_erase_disable(void);

void
flash_erase_start(void);

void
flash_lock(void);

void
flash_option_byte_write_enable(void);

void
flash_option_byte_write_disable(void);

void
flash_interrupt_enable(
  enum flash_interrupt interrupt
);

void
flash_interrupt_disable(
  enum flash_interrupt interrupt
);

void
flash_force_option_byte_reload(void);

void
flash_set_address(
  u32 address
);

u32
flash_get_current_address(void);

u32
flash_is_option_set(
  enum flash_option option
);

u32
flash_get_read_protection_level(void);

u32
flash_get_option_data0(void);

u32
flash_get_option_data1(void);

u32
flash_get_reloaded_option_byte(void);

#endif

END_DECLARATIONS

#endif
