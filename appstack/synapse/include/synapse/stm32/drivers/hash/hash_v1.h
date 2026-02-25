#ifndef STM32_DRIVER_HASH_H
#define STM32_DRIVER_HASH_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct hash_registers_map
{
  u32 CR;
  u32 DIN;
  u32 STR;
  u32 HRA[5];
  u32 IMR;
  u32 SR;
};

struct hash_digest_registers
{
#if defined(STM32_HASH_HR_8BYTES)
  u32 HR[8];
#elif defined(STM32_HASH_HR_5BYTES)
  u32 HR[4];
#endif
};

#if defined(STM32_HASH_CSR_REG_COUNT)
struct hash_cs_registers
{
  u32 CSR[STM32_HASH_CSR_REG_COUNT];
};
#endif

#if defined(STM32_HASH_CSR_REG_COUNT)
struct hash_periph_registers
{
  u32 buf[STM32_HASH_CSR_REG_COUNT];
};
#endif

// Core
enum hash_cr : u32
{
  HASH_CR_INIT = (1 << 2),
  HASH_CR_DMAE = (1 << 3),
  HASH_CR_MODE = (1 << 6),
  HASH_CR_ALGO1 = (1 << 7),
  HASH_CR_DINNE = (1 << 12),
  HASH_CR_MDMAT = (1 << 13),
  HASH_CR_LKEY = (1 << 16),

#if defined(STM32_HASH_ALGO_EXTENDED)
  HASH_CR_ALGO2 = (1 << 18)
#endif
};

#define HASH_CR_DATATYPE_SHIFT (4)
#define HASH_CR_DATATYPE_MASK (0x3)

enum hash_cr_datatype : u32
{
  HASH_CR_DATATYPE_32BIT = 0b00,
  HASH_CR_DATATYPE_16BIT = 0b01,
  HASH_CR_DATATYPE_8BIT = 0b10,
  HASH_CR_DATATYPE_BITSTR = 0b11
};

#define HASH_CR_NBW_SHIFT (8)
#define HASH_CR_NBW_MASK (0xf)

enum hash_str : u32
{
  HASH_STR_DCAL = (1 << 8)
};

#define HASH_STR_NBLW_SHIFT (0)
#define HASH_STR_NBLW_MASK (0x1f)

enum hash_imr : u32
{
  HASH_IMR_DINIE = (1 << 0),
  HASH_IMR_DCIE = (1 << 1)
};

enum hash_sr : u32
{
  HASH_SR_DINIS = (1 << 0),
  HASH_SR_DCIS = (1 << 1),
  HASH_SR_DMAS = (1 << 2),
  HASH_SR_BUSY = (1 << 3)
};

// API

enum hash_data_type
{
  HASH_DATA_TYPE_32BIT,
  HASH_DATA_TYPE_16BIT,
  HASH_DATA_TYPE_8BIT,
  HASH_DATA_TYPE_BITSTR
};

enum hash_mode
{
  HASH_MODE_HASH,
  HASH_MODE_HMAC
};

enum hash_algorithm
{
  HASH_ALGORITHM_SHA1,
  HASH_ALGORITHM_MD5,

#if defined(STM32_HASH_HR_8BYTES)
  HASH_ALGORITHM_SHA224,
  HASH_ALGORITHM_SHA256
#endif
};

#if defined(STM32_HASH_KEY_TYPE)
enum hash_key_type
{
  HASH_KEY_TYPE_SHORT,
  HASH_KEY_TYPE_LONG
};
#endif

enum hash_interrupt
{
  HASH_INTERRUPT_DATA_INPUT,
  HASH_INTERRUPT_DIGEST_CALC_COMPLETE
};

enum hash_flag
{
  HASH_FLAG_INPUT_FULL,
  HASH_FLAG_DATA_INPUT,
  HASH_FLAG_DATA_OUTPUT,
  HASH_FLAG_DMA,
  HASH_FLAG_BUSY
};

extern volatile struct hash_registers_map* HASH;
extern volatile struct hash_digest_registers* HASHHR;
extern volatile struct hash_cs_registers* HASHCSR;

void
hash_init(void);

void
hash_dma_enable(void);

void
hash_dma_disable(void);

void
hash_set_data_type(
  enum hash_data_type type
);

void
hash_set_mode(
  enum hash_mode mode
);

void
hash_set_algorithm(
  enum hash_algorithm algorithm
);

u32
hash_get_transferred_word_count(void);

#if defined(STM32_HASH_MULTI_DMA_TRANSFERS)
void
hash_multiple_dma_transfers_enable(void);

void
hash_multiple_dma_transfers_disable(void);
#endif

#if defined(STM32_HASH_KEY_TYPE)
void
hash_set_key_type(
  enum hash_key_type type
);
#endif

void
hash_write_data(
  u32 data
);

void
hash_set_input_valid_bits_count(
  u32 count
);

void
hash_digest_calc_start(void);

u32
hash_read_digest(
  u32 idx
);

void
hash_interrupt_enable(
  enum hash_interrupt interrupt
);

void
hash_interrupt_disable(
  enum hash_interrupt interrupt
);

u32
hash_is_flag_set(
  enum hash_flag flag
);

// u32
// hash_has_interrupt_occurred(
//   enum hash_interrupt interrupt
// );

// void
// hash_interrupt_clear(
//   enum hash_interrupt interrupt
// );

void
hash_flag_clear(
  enum hash_flag flag
);

#if defined(STM32_HASH_CSR_REG_COUNT)
void
hash_dump_all(
  struct hash_periph_registers* regs
);
#endif

#if defined(STM32_HASH_CSR_REG_COUNT)
void
hash_restore_all(
  struct hash_periph_registers* regs
);
#endif

END_DECLARATIONS

#endif
