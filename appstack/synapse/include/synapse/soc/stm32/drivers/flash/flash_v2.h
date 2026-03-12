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

/**
 * Supports:
 *  - STM32F4x
 *  - STM32F7x
 */

#include "synapse/specs.h"
#include "synapse/common/util/common.h"
#include "libcom/types.h"

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
  u32 KEYR;
  u32 OPTKEYR;
  u32 SR;
  u32 CR;
  u32 OPTCR;
  u32 OPTCR1;
  u32 WRPR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#if defined(STM32_FLASH_ACR)
enum flash_acr : u32
{
#if defined(STM32_FLASH_PREFETCH)
  FLASH_ACR_PRFTEN = (1 << 8),
#endif

#if defined(STM32_FLASH_CACHE)
  FLASH_ACR_ICEN = (1 << 9),
  FLASH_ACR_DCEN = (1 << 10),
  FLASH_ACR_ICRST = (1 << 11),
  FLASH_ACR_DCRST = (1 << 12)
#endif

#if defined(STM32_FLASH_ART)
  FLASH_ACR_ARTEN = (1 << 9),
  FLASH_ACR_ARTRST = (1 << 11)
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
  FLASH_ACR_LATENCY_WS2 = 0b010,
  FLASH_ACR_LATENCY_WS3 = 0b011,
  FLASH_ACR_LATENCY_WS4 = 0b100,
  FLASH_ACR_LATENCY_WS5 = 0b101,
  FLASH_ACR_LATENCY_WS6 = 0b110,
  FLASH_ACR_LATENCY_WS7 = 0b111,
  FLASH_ACR_LATENCY_WS8 = 0b1000,
  FLASH_ACR_LATENCY_WS9 = 0b1001,
  FLASH_ACR_LATENCY_WS10 = 0b1010,
  FLASH_ACR_LATENCY_WS11 = 0b1011,
  FLASH_ACR_LATENCY_WS12 = 0b1100,
  FLASH_ACR_LATENCY_WS13 = 0b1101,
  FLASH_ACR_LATENCY_WS14 = 0b1110,
  FLASH_ACR_LATENCY_WS15 = 0b1111
};

#define FLASH_KEYR_KEY1 (0x45670123)
#define FLASH_KEYR_KEY2 (0xcdef89ab)

#define FLASH_OPTKEYR_KEY1 (0x08192a3b)
#define FLASH_OPTKEYR_KEY2 (0x4c5d6e7f)

#if defined(STM32_FLASH_SR_LAYOUT1)
enum flash_sr : u32
{
  FLASH_SR_EOP = (1 << 0),
  FLASH_SR_OPERR = (1 << 1),
  FLASH_SR_WRPERR = (1 << 4),
  FLASH_SR_PGAERR = (1 << 5),
  FLASH_SR_PGPERR = (1 << 6),
  FLASH_SR_PGSERR = (1 << 7),

#if defined(STM32_FLASH_PCROP)
  FLASH_SR_RDERR = (1 << 8),
#endif

  FLASH_SR_BSY = (1 << 16)

};
#elif defined(STM32_FLASH_SR_LAYOUT2)
#endif

enum flash_cr : u32
{
  FLASH_CR_PG = (1 << 0),
  FLASH_CR_SER = (1 << 1),
  FLASH_CR_MER = (1 << 2),

#if defined(STM32_FLASH_MASS_ERASE_BANK2)
  FLASH_CR_MER1 = (1 << 15),
#endif

  FLASH_CR_STRT = (1 << 16),
  FLASH_CR_EOPIE = (1 << 24),
  FLASH_CR_ERRIE = (1 << 25),
  FLASH_CR_LOCK = (1u << 31)
};

#define FLASH_CR_SNB_SHIFT (3)

#if defined(STM32_FLASH_SNB_5BIT)
#define FLASH_CR_SNB_MASK (0x1f)
#elif defined(STM32_FLASH_SNB_4BIT)
#define FLASH_CR_SNB_MASK (0xf)
#endif

#define FLASH_CR_PSIZE_SHIFT (8)
#define FLASH_CR_PSIZE_MASK (0x3)

enum flash_cr_psize : u32
{
  FLASH_CR_PSIZE_x8 = 0b00,
  FLASH_CR_PSIZE_x16 = 0b01,
  FLASH_CR_PSIZE_x32 = 0b10,
  FLASH_CR_PSIZE_x64 = 0b11
};

enum flash_optcr : u32
{
  FLASH_OPTCR_OPTLOCK = (1 << 0),
  FLASH_OPTCR_OPTSTRT = (1 << 1),

#if defined(STM32_FLASH_DUALBANK_BOOT_OPTION)
  FLASH_OPTCR_BFB2 = (1 << 4),
#elif defined(STM32_FLASH_WWDG)
  FLASH_OPTCR_WWDGSW = (1 << 4)
#endif

  FLASH_OPTCR_WDGSW = (1 << 5),
  FLASH_OPTCR_RSTSTOP = (1 << 6),
  FLASH_OPTCR_RSTSTDBY = (1 << 7),

#if defined(STM32_FLASH_DUALBANK)
  FLASH_OPTCR_DB1M = (1 << 30),
#elif defined(STM32_FLASH_IWDG_CONFIG)
  FLASH_OPTCR_IWDG_STDBY = (1 << 30),
#endif

#if defined(STM32_FLASH_PROTECTION_MODE)
  FLASH_OPTCR_SPRMOD = (1u << 31)
#elif defined(STM32_FLASH_IWDG_CONFIG)
  FLASH_OPTCR_IWDG_STOP = (1u << 31)
#endif
};

#define FLASH_OPTCR_BORLEV_SHIFT (2)
#define FLASH_OPTCR_BORLEV_MASK (0x3)

enum flash_optcr_borlev : u32
{
  FLASH_OPTCR_BORLEV_LEVEL3 = 0b00,
  FLASH_OPTCR_BORLEV_LEVEL2 = 0b01,
  FLASH_OPTCR_BORLEV_LEVEL1 = 0b10,
  FLASH_OPTCR_BORLEV_OFF = 0b11
};

#define FLASH_OPTCR_WRP_SHIFT (16)
#define FLASH_OPTCR_WRP_SECTOR_MAX (11)

#if defined(STM32_FLASH_OPTCR1_WRP)

#define FLASH_OPTCR1_WRP_SHIFT (16)
#define FLASH_OPTCR1_WRP_SECTOR_MAX (11)

#else

#define FLASH_OPTCR1_BOOTADD0_SHIFT (0)
#define FLASH_OPTCR1_BOOTADD0_MASK (0xffff)

#define FLASH_OPTCR1_BOOTADD1_SHIFT (16)
#define FLASH_OPTCR1_BOOTADD1_MASK (0xffff)

#endif

#define FLASH_OPTCR_RDP_SHIFT (8)
#define FLASH_OPTCR_RDP_MASK (0xff)

enum flash_optcr_rdp : u32
{
  FLASH_OPTCR_RDP_LEVEL0 = 0xaa,
  FLASH_OPTCR_RDP_LEVEL1 = 0xbb,
  FLASH_OPTCR_RDP_LEVEL2 = 0xcc
};

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
 * @see flash_set_wait_state()
 */
enum flash_wait_state
{
  FLASH_WAIT_STATE0,
  FLASH_WAIT_STATE1,
  FLASH_WAIT_STATE2,
  FLASH_WAIT_STATE3,
  FLASH_WAIT_STATE4,
  FLASH_WAIT_STATE5,
  FLASH_WAIT_STATE6,
  FLASH_WAIT_STATE7,
  FLASH_WAIT_STATE8,
  FLASH_WAIT_STATE9,
  FLASH_WAIT_STATE10,
  FLASH_WAIT_STATE11,
  FLASH_WAIT_STATE12,
  FLASH_WAIT_STATE13,
  FLASH_WAIT_STATE14,
  FLASH_WAIT_STATE15
};

#if defined(STM32_FLASH_CACHE)
enum flash_cache
{
  FLASH_CACHE_INSTRUCTION,
  FLASH_CACHE_DATA
};
#endif

enum flash_flag
{
  FLASH_FLAG_EOP,
  FLASH_FLAG_OPERATION_ERROR,
  FLASH_FLAG_WRITE_PROTECTION_ERROR,
  FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR,
  FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR,
  FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR,

#if defined(STM32_FLASH_PCROP)
  FLASH_FLAG_PCROP_ERROR,
#endif

  FLASH_FLAG_BUSY
};

enum flash_interrupt
{
  FLASH_INTERRUPT_ERROR,
  FLASH_INTERRUPT_EOP
};

enum flash_program_size
{
  FLASH_PROGRAM_SIZE_x8,
  FLASH_PROGRAM_SIZE_x16,
  FLASH_PROGRAM_SIZE_x32,
  FLASH_PROGRAM_SIZE_x64
};

enum flash_bor_level
{
  FLASH_BOR_LEVEL_OFF,
  FLASH_BOR_LEVEL1,
  FLASH_BOR_LEVEL2,
  FLASH_BOR_LEVEL3
};

enum flash_user_option_byte
{
  FLASH_USER_OPTION_BYTE_RST_STANDBY,
  FLASH_USER_OPTION_BYTE_RST_STOP,
  FLASH_USER_OPTION_BYTE_IWDG_SW,
  FLASH_USER_OPTION_BYTE_WWDG_SW
};

enum flash_read_protection_level
{
  FLASH_READ_PROTECTION_LEVEL0,
  FLASH_READ_PROTECTION_LEVEL1,
  FLASH_READ_PROTECTION_LEVEL2
};

#if defined(STM32_FLASH_DUALBANK)
enum flash_dual_bank
{
  FLASH_DUAL_BANK_CONTINUOUS,
  FLASH_DUAL_BANK_SPLIT
};
#endif

#if defined(STM32_FLASH_PROTECTION_MODE)
enum flash_protection_mode
{
  FLASH_PROTECTION_MODE_WRITE,
  FLASH_PROTECTION_MODE_PCROP
};
#endif

#if defined(STM32_FLASH_IWDG_CONFIG)
enum flash_iwdg_standby_mode
{
  FLASH_IWDG_STANDBY_MODE_FREEZE,
  FLASH_IWDG_STANDBY_MODE_RUNNING
};

enum flash_iwdg_stop_mode
{
  FLASH_IWDG_STOP_MODE_FREEZE,
  FLASH_IWDG_STOP_MODE_RUNNING
};
#endif

extern volatile struct flash_registers_map* FLASH;

void
flash_set_wait_state(
  enum flash_wait_state wait_state
);

#if defined(STM32_FLASH_PREFETCH_BUFFER)
void
flash_prefetch_buffer_enable(void);

void
flash_prefetch_buffer_disable(void);

u32
flash_get_prefetch_buffer_status(void);
#endif

#if defined(STM32_FLASH_PREFETCH)
void
flash_prefetch_enable(void);

void
flash_prefetch_disable(void);
#endif

#if defined(STM32_FLASH_CACHE)
void
flash_cache_enable(
  enum flash_cache cache
);

void
flash_cache_disable(
  enum flash_cache cache
);

void
flash_cache_reset(
  enum flash_cache cache
);
#endif

#if defined(STM32_FLASH_ART)
void
flash_art_acceleration_enable(void);

void
flash_art_acceleration_disable(void);

void
flash_art_acceleration_reset(void);
#endif

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
flash_sector_erase_enable(void);

void
flash_sector_erase_disable(void);

void
flash_mass_erase_bank1_enable(void);

void
flash_mass_erase_bank1_disable(void);

void
flash_set_sector_number(
  u32 sector_number
);

void
flash_set_program_size(
  enum flash_program_size size
);

#if defined(STM32_FLASH_MASS_ERASE_BANK2)
void
flash_mass_erase_bank2_enable(void);

void
flash_mass_erase_bank2_disable(void);
#endif

void
flash_erase_start(void);

void
flash_interrupt_enable(
  enum flash_interrupt interrupt
);

void
flash_interrupt_disable(
  enum flash_interrupt interrupt
);

void
flash_lock(void);

void
flash_option_lock(void);

void
flash_option_start(void);

void
flash_set_bor_level(
  enum flash_bor_level level
);

#if defined(STM32_FLASH_DUALBANK)
void
flash_set_dual_bank_boot_option_enable(void);

void
flash_set_dual_bank_boot_option_disable(void);
#endif

void
flash_user_option_byte_enable(
  enum flash_user_option_byte option
);

void
flash_user_option_byte_disable(
  enum flash_user_option_byte option
);

void
flash_set_read_protection_level(
  enum flash_read_protection_level level
);

u32
flash_get_read_protection_level(void);

void
flash_write_protection_enable(
  u32 sector
);

void
flash_write_protection_disable(
  u32 sector
);

u32
flash_is_write_protection_enabled(
  u32 sector
);

#if defined(STM32_FLASH_DUALBANK)
void
flash_dual_bank_enable(void);

void
flash_dual_bank_disable(void);
#endif

#if defined(STM32_FLASH_PROTECTION_MODE)
void
flash_set_protection_mode(
  enum flash_protection_mode mode
);
#endif

#if defined(STM32_FLASH_IWDG_CONFIG)
void
flash_set_iwdg_standby_mode(
  enum flash_iwdg_standby_mode mode
);

void
flash_set_iwdg_stop_mode(
  enum flash_iwdg_stop_mode mode
);
#endif

#if defined(STM32_FLASH_BOOTADD)
void
flash_set_boot_address0(
  u32 address
);

void
flash_set_boot_address1(
  u32 address
);
#endif

END_DECLARATIONS

#endif
