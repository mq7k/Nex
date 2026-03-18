#ifndef STM32_DRIVER_QUADSPI_H
#define STM32_DRIVER_QUADSPI_H

#include "libcom/util.h"
#include "libcom/types.h"

/**
 * Supports:
 *  - STM32F4x
 */

BEGIN_DECLARATIONS

struct quadspi_registers_map
{
  u32 CR;
  u32 DCR;
  u32 SR;
  u32 FCR;
  u32 DLR;
  u32 CCR;
  u32 AR;
  u32 ABR;
  u32 DR;
  u32 PSMKR;
  u32 PSMAR;
  u32 PIR;
  u32 LPTR;
};

// Core

enum quadspi_cr : u32
{
  QUADSPI_CR_EN = (1 << 0),
  QUADSPI_CR_ABORT = (1 << 1),
  QUADSPI_CR_DMAEN = (1 << 2),
  QUADSPI_CR_TCEN = (1 << 3),
  QUADSPI_CR_SSHIFT = (1 << 4),
  QUADSPI_CR_DFM = (1 << 6),
  QUADSPI_CR_FSEL = (1 << 7),
  QUADSPI_CR_TEIE = (1 << 16),
  QUADSPI_CR_TCIE = (1 << 17),
  QUADSPI_CR_FTIE = (1 << 18),
  QUADSPI_CR_SMIE = (1 << 19),
  QUADSPI_CR_TOIE = (1 << 20),
  QUADSPI_CR_APMS = (1 << 22),
  QUADSPI_CR_PMM = (1 << 23)
};

#define QUADSPI_CR_FTHRES_SHIFT (8)
#define QUADSPI_CR_FTHRES_MASK (0x1f)

#define QUADSPI_CR_PRESCALER_SHIFT (24)
#define QUADSPI_CR_PRESCALER_MASK (0xffu)

enum quadspi_dcr : u32
{
  QUADSPI_DCR_CKMODE = (1 << 0)
};

#define QUADSPI_DCR_CSHT_SHIFT (8)
#define QUADSPI_DCR_CSHT_MASK (0x7)

#define QUADSPI_DCR_FSIZE_SHIFT (16)
#define QUADSPI_DCR_FSIZE_MASK (0x1f)

enum quadspi_sr : u32
{
  QUADSPI_SR_TEF = (1 << 0),
  QUADSPI_SR_TCF = (1 << 1),
  QUADSPI_SR_FTF = (1 << 2),
  QUADSPI_SR_SMF = (1 << 3),
  QUADSPI_SR_TOF = (1 << 4),
  QUADSPI_SR_BUSY = (1 << 5)
};

#define QUADSPI_SR_FLEVEL_SHIFT (8)
#define QUADSPI_SR_FLEVEL_MASK (0x3f)

enum quadspi_fcr : u32
{
  QUADSPI_FCR_CTEF = (1 << 0),
  QUADSPI_FCR_CTCF = (1 << 1),
  QUADSPI_FCR_CSMF = (1 << 3),
  QUADSPI_FCR_CTOF = (1 << 4)
};

enum quadspi_ccr : u32
{
  QUADSPI_CCR_SIOO = (1 << 28),
  QUADSPI_CCR_DHHC = (1 << 30),
  QUADSPI_CCR_DDRM = (1u << 31)
};

#define QUADSPI_CCR_INSTRUCTION_SHIFT (0)
#define QUADSPI_CCR_INSTRUCTION_MASK (0xff)

#define QUADSPI_CCR_IMODE_SHIFT (8)
#define QUADSPI_CCR_IMODE_MASK (0x3)

enum quadspi_ccr_imode : u32
{
  QUADSPI_CCR_IMODE_NO_INSTRUCTION = 0b00,
  QUADSPI_CCR_IMODE_INSTRUCTION_1LINE = 0b01,
  QUADSPI_CCR_IMODE_INSTRUCTION_2LINES = 0b10,
  QUADSPI_CCR_IMODE_INSTRUCTION_4LINES = 0b11
};

#define QUADSPI_CCR_ADMODE_SHIFT (10)
#define QUADSPI_CCR_ADMODE_MASK (0x3)

enum quadspi_ccr_admode : u32
{
  QUADSPI_CCR_ADMODE_NO_ADDRESS = 0b00,
  QUADSPI_CCR_ADMODE_ADDRESS_1LINE = 0b01,
  QUADSPI_CCR_ADMODE_ADDRESS_2LINES = 0b10,
  QUADSPI_CCR_ADMODE_ADDRESS_4LINES = 0b11
};

#define QUADSPI_CCR_ADSIZE_SHIFT (12)
#define QUADSPI_CCR_ADSIZE_MASK (0x3)

enum quadspi_ccr_adsize : u32
{
  QUADSPI_CCR_ADSIZE_8BIT = 0b00,
  QUADSPI_CCR_ADSIZE_16BIT = 0b01,
  QUADSPI_CCR_ADSIZE_24BIT = 0b10,
  QUADSPI_CCR_ADSIZE_32BIT = 0b11
};

#define QUADSPI_CCR_ABMODE_SHIFT (14)
#define QUADSPI_CCR_ABMODE_MASK (0x3)

enum quadspi_ccr_abmode : u32
{
  QUADSPI_CCR_ABMODE_NO_ALT_BYTES = 0b00,
  QUADSPI_CCR_ABMODE_ALT_BYTES_1LINE = 0b01,
  QUADSPI_CCR_ABMODE_ALT_BYTES_2LINES = 0b10,
  QUADSPI_CCR_ABMODE_ALT_BYTES_4LINES = 0b11
};

#define QUADSPI_CCR_ABSIZE_SHIFT (16)
#define QUADSPI_CCR_ABSIZE_MASK (0x3)

enum quadspi_ccr_absize : u32
{
  QUADSPI_CCR_ABSIZE_ALT_BYTES_8BIT = 0b00,
  QUADSPI_CCR_ABSIZE_ALT_BYTES_16BIT = 0b01,
  QUADSPI_CCR_ABSIZE_ALT_BYTES_24BIT = 0b10,
  QUADSPI_CCR_ABSIZE_ALT_BYTES_32BIT = 0b11
};

#define QUADSPI_CCR_DCYC_SHIFT (18)
#define QUADSPI_CCR_DCYC_MASK (0x1f)

#define QUADSPI_CCR_DMODE_SHIFT (24)
#define QUADSPI_CCR_DMODE_MASK (0x3)

enum quadspi_ccr_dmode : u32
{
  QUADSPI_CCR_DMODE_NO_DATA = 0b00,
  QUADSPI_CCR_DMODE_DATA_1LINE = 0b01,
  QUADSPI_CCR_DMODE_DATA_2LINES = 0b10,
  QUADSPI_CCR_DMODE_DATA_4LINES = 0b11
};

#define QUADSPI_CCR_FMODE_SHIFT (26)
#define QUADSPI_CCR_FMODE_MASK (0x3)

enum quadspi_ccr_fmode : u32
{
  QUADSPI_CCR_FMODE_INDIRECT_WRITE = 0b00,
  QUADSPI_CCR_FMODE_INDIRECT_READ = 0b01,
  QUADSPI_CCR_FMODE_AUTO_STATUS_POLLING = 0b10,
  QUADSPI_CCR_FMODE_MEMORY_MAPPED = 0b11
};

#define QUADSPI_PIR_INTERVAL_SHIFT (0)
#define QUADSPI_PIR_INTERVAL_MASK (0xffff)

#define QUADSPI_LPTR_TIMEOUT_SHIFT (0)
#define QUADSPI_LPTR_TIMEOUT_MASK (0xffff)

// API

enum quadspi_sample_shift
{
  QUADSPI_SAMPLE_SHIFT_NO_SHIFT,
  QUADSPI_SAMPLE_SHIFT_HALF_SHIFT
};

enum quadspi_flash_memory
{
  QUADSPI_FLASH_MEMORY_FLASH1,
  QUADSPI_FLASH_MEMORY_FLASH2
};

enum quadspi_interrupt
{
  QUADSPI_INTERRUPT_TRANSFER_ERROR,
  QUADSPI_INTERRUPT_TRANSFER_COMPLETE,
  QUADSPI_INTERRUPT_FIFO_THRESHOLD,
  QUADSPI_INTERRUPT_STATUS_MATCH,
  QUADSPI_INTERRUPT_TIMEOUT
};

enum quadspi_polling_stop_mode
{
  QUADSPI_POLLING_STOP_MODE_ONLY_ABORT,
  QUADSPI_POLLING_STOP_MODE_MATCH
};

enum quadspi_polling_match_mode
{
  QUADSPI_POLLING_MATCH_MODE_AND,
  QUADSPI_POLLING_MATCH_MODE_OR
};

enum quadspi_clock_mode
{
  QUADSPI_CLOCK_MODE_MODE0,
  QUADSPI_CLOCK_MODE_MODE3
};

enum quadspi_flag
{
  QUADSPI_FLAG_TRANSFER_ERROR,
  QUADSPI_FLAG_TRANSFER_COMPLETE,
  QUADSPI_FLAG_FIFO_THRESHOLD,
  QUADSPI_FLAG_STATUS_MATCH,
  QUADSPI_FLAG_TIMEOUT,
  QUADSPI_FLAG_BUSY
};

enum quadspi_intruction_mode
{
  QUADSPI_INTRUCTION_MODE_NO_INSTRUCTION,
  QUADSPI_INTRUCTION_MODE_1LINE,
  QUADSPI_INTRUCTION_MODE_2LINES,
  QUADSPI_INTRUCTION_MODE_4LINES
};

enum quadspi_address_mode
{
  QUADSPI_ADDRESS_MODE_NO_ADDRESS,
  QUADSPI_ADDRESS_MODE_1LINE,
  QUADSPI_ADDRESS_MODE_2LINES,
  QUADSPI_ADDRESS_MODE_4LINES
};

enum quadspi_address_size
{
  QUADSPI_ADDRESS_SIZE_8BIT,
  QUADSPI_ADDRESS_SIZE_16BIT,
  QUADSPI_ADDRESS_SIZE_24BIT,
  QUADSPI_ADDRESS_SIZE_32BIT
};

enum quadspi_alternate_byte_mode
{
  QUADSPI_ALTERNATE_BYTE_MODE_NO_ALTERNATE,
  QUADSPI_ALTERNATE_BYTE_MODE_1LINE,
  QUADSPI_ALTERNATE_BYTE_MODE_2LINES,
  QUADSPI_ALTERNATE_BYTE_MODE_4LINES
};

enum quadspi_alternate_byte_size
{
  QUADSPI_ALTERNATE_BYTE_SIZE_8BIT,
  QUADSPI_ALTERNATE_BYTE_SIZE_16BIT,
  QUADSPI_ALTERNATE_BYTE_SIZE_24BIT,
  QUADSPI_ALTERNATE_BYTE_SIZE_32BIT
};

enum quadspi_data_mode
{
  QUADSPI_DATA_MODE_NO_DATA,
  QUADSPI_DATA_MODE_1LINE,
  QUADSPI_DATA_MODE_2LINES,
  QUADSPI_DATA_MODE_4LINES
};

enum quadspi_functional_mode
{
  QUADSPI_FUNCTIONAL_MODE_INDIRECT_WRITE,
  QUADSPI_FUNCTIONAL_MODE_INDIRECT_READ,
  QUADSPI_FUNCTIONAL_MODE_AUTOMATIC_STATUS_POLLING,
  QUADSPI_FUNCTIONAL_MODE_MEMORY_MAPPED
};

enum quadspi_send_instruction_mode
{
  QUADSPI_SEND_INSTRUCTION_MODE_EVERY_TRANSACTION,
  QUADSPI_SEND_INSTRUCTION_MODE_FIRST_CMD_ONLY
};

enum quadspi_data_delay
{
  QUADSPI_DATA_DELAY_ANALOG_DELAY,
  QUADSPI_DATA_DELAY_1over4_CLK_CYCLE
};

extern volatile struct quadspi_registers_map* QUADSPI;

void
quadspi_enable(void);

void
quadspi_disable(void);

void
quadspi_abort(void);

void
quadspi_dma_enable(void);

void
quadspi_dma_disable(void);

void
quadspi_timeout_counter_enable(void);

void
quadspi_timeout_counter_disable(void);

void
quadspi_set_sample_shift(
  enum quadspi_sample_shift shift
);

void
quadspi_dual_flash_enable(void);

void
quadspi_dual_flash_disable(void);

void
quadspi_select_flash_memory(
  enum quadspi_flash_memory memory
);

void
quadspi_set_fifo_threshold_level(
  u32 level
);

void
quadspi_interrupt_enable(
  enum quadspi_interrupt interrupt
);

void
quadspi_interrupt_disable(
  enum quadspi_interrupt interrupt
);

void
quadspi_set_automatic_status_polling_mode(
  enum quadspi_polling_stop_mode mode
);

void
quadspi_set_polling_match_mode(
  enum quadspi_polling_match_mode mode
);

void
quadspi_set_prescaler(
  u32 prescaler
);

void
quadspi_set_clock_mode(
  enum quadspi_clock_mode mode
);

void
quadspi_set_cs_min_high_cycles_count(
  u32 count
);

void
quadspi_set_address_bits(
  u32 bits
);

u32
quadspi_is_flag_set(
  enum quadspi_flag flag
);

u32
quadspi_get_fifo_bytes_count(void);

void
quadspi_flag_clear(
  enum quadspi_flag flag
);

void
quadspi_set_transfer_bytes_count(
  u32 count
);

void
quadspi_set_instruction(
  u32 instruction
);

void
quadspi_set_intruction_mode(
  enum quadspi_intruction_mode mode
);

void
quadspi_set_address_mode(
  enum quadspi_address_mode mode
);

void
quadspi_set_address_size(
  enum quadspi_address_size size
);

void
quadspi_set_alternate_byte_mode(
  enum quadspi_alternate_byte_mode mode
);

void
quadspi_set_alternate_byte_size(
  enum quadspi_alternate_byte_size size
);

void
quadspi_set_dummy_cycles_count(
  u32 count
);

void
quadspi_set_data_mode(
  enum quadspi_data_mode mode
);

void
quadspi_set_functional_mode(
  enum quadspi_functional_mode mode
);

void
quadspi_set_send_instruction_mode(
  enum quadspi_send_instruction_mode mode
);

void
quadspi_set_double_data_rate_delay_mode(
  enum quadspi_data_delay delay
);

void
quadspi_double_data_rate_enable(void);

void
quadspi_double_data_rate_disable(void);

void
quadspi_set_flash_address(
  u32 address
);

void
quadspi_set_alternate_bytes(
  u32 bytes
);

void
quadspi_data_write(
  u32 data
);

u32
quadspi_data_read(void);

void
quadspi_set_status_byte_mask(
  u32 mask
);

void
quadspi_set_status_match(
  u32 value
);

void
quadspi_set_polling_interval(
  u32 interval
);

void
quadspi_set_timeout_period(
  u32 period
);

END_DECLARATIONS

#endif
