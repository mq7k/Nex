/**
 * @file crc.h
 * @brief Cyclic Redundancy Check (CRC) interface.
 *
 * @details This header file provides function prototypes for 
 * calculating CRC values, which are commonly used for data 
 * integrity verification.
 *
 * @note CRC calculations are hardware-accelerated in many MCUs, 
 * making them efficient for error checking.
 */
#ifndef STM32_DRIVER_CRC_H
#define STM32_DRIVER_CRC_H

#include "libcom/util.h"
#include "libcom/types.h"

/**
 * Supports:
 *  - STM32F0x
 *  - STM32F1x
 *  - STM32F4x
 */

BEGIN_DECLARATIONS

/**
 * @brief CRC (Cyclic Redundancy Check) registers memory map.
 *
 * @details Represents the memory layout of the CRC peripheral
 * registers. The CRC unit is used for generating and verifying
 * CRC values, commonly for data integrity checks in communication 
 * protocols and memory validation.
 *
 * @note The CRC peripheral operates on a fixed polynomial and is primarily 
 * designed for 32-bit data integrity validation.
 */
struct crc_registers_map
{
  u32 DR;
  u32 IDR;
  u32 CR;

#if defined(STM32_CRC_EXTENDED)
  u32 INIT;
#endif
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#define CRC_IDR_SHIFT (0)
#define CRC_IDR_MASK (0xffu)

enum crc_cr : u32
{
  CRC_CR_RESET = (1 << 0),

#if defined(STM32_CRC_REVERSE_DATA)
  CRC_CR_REVOUT = (1 << 7)
#endif
};

#if defined(STM32_CRC_REVERSE_DATA)

#define CRC_CR_REVIN_SHIFT (5)
#define CRC_CR_REVIN_MASK (0x3)

enum crc_cr_revin : u32
{
  CRC_CR_REVIN_NOREVERSE = 0b00,
  CRC_CR_REVIN_BY_BYTE = 0b01,
  CRC_CR_REVIN_BY_HALF_WORD = 0b10,
  CRC_CR_REVIN_BY_WORD = 0b11
};
#endif

extern volatile struct crc_registers_map* CRC;

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#if defined(STM32_CRC_REVERSE_DATA)
enum crc_input_data_reverse
{
  CRC_INPUT_DATA_REVERSE_OFF,
  CRC_INPUT_DATA_REVERSE_BYTE,
  CRC_INPUT_DATA_REVERSE_HALF_WORD,
  CRC_INPUT_DATA_REVERSE_WORD
};
#endif

/**
 * @brief Reads the computed CRC value.
 *
 * @details Returns the result of the CRC calculation 
 * from the data register. The value is updated automatically
 * when new data is written to the CRC unit.
 *
 * @return Computed CRC value.
 *
 * @see crc_data_write()
 */
u32
crc_data_read(void);

/**
 * @brief Writes data to the CRC calculation unit.
 *
 * @details Feeds a 32-bit data value into the CRC peripheral, which 
 * updates the CRC computation based on the pre-configured polynomial.
 *
 * @param data The 32-bit data to be included in the CRC computation.
 *
 * @see crc_data_read()
 * @see crc_reset()
 */
void
crc_data_write(u32 data);

/**
 * @brief Reads the independent data register.
 *
 * @details Retrieves the value stored in the independent 
 * data register (IDR). This register does not affect CRC
 * computation and can be used for custom application-specific
 * storage.
 *
 * @return Value stored in the independent data register.
 *
 * @note This register is not affecte by CRC resets.
 *
 * @see crc_independent_data_write()
 */
u32
crc_independent_data_read(void);

/**
 * @brief Writes a value to the independent data register.
 *
 * @details Stores a user-defined 8-bit value into the independent 
 * data register (IDR). This register is separate from the CRC
 * computation logic.
 *
 * @param data The 32-bit value to store in the independent register.
 *
 * @note The `data` argument can only store values up to 255.
 *
 * @note This register is not affecte by CRC resets.
 *
 * @see crc_independent_data_read()
 */
void
crc_independent_data_write(u32 data);

/**
 * @brief Resets the CRC calculation unit.
 *
 * @details Clears the CRC data register and resets 
 * the CRC computation. This must be called before
 * starting a new CRC calculation.
 *
 * @note This function must be called before processing a new data stream
 * to ensure previous CRC results do not affect new computations.
 *
 * @see crc_data_write()
 * @see crc_data_read()
 */
void
crc_reset(void);

#if defined(STM32_CRC_REVERSE_DATA)
void
crc_set_input_data_reverse(
  enum crc_input_data_reverse reverse
);

void
crc_output_data_reverse_enable(void);

void
crc_output_data_reverse_disable(void);
#endif

#if defined(STM32_CRC_EXTENDED)
void
crc_set_initial_value(
  u32 value
);
#endif

BEGIN_DECLARATIONS

#endif
