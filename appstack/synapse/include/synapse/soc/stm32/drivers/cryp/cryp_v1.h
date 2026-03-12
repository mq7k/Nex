#ifndef STM32_DRIVER_CRYP_H
#define STM32_DRIVER_CRYP_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F4
 */

BEGIN_DECLARATIONS

struct cryp_registers_map
{
  u32 CR;
  u32 SR;
  u32 DIN;
  u32 DOUT;
  u32 DMACR;
  u32 IMSCR;
  u32 RISR;
  u32 MISR;
  u32 KR[8];
  u32 IV[4];

#if defined(STM32_CRYP_CS)
  u32 CSGCMCCMR[8];
  u32 CSGCMR[8];
#endif
};

struct cryp_key
{
  u32 key[8];
};

struct cryp_iv
{
  u32 iv[4];
};

#if defined(STM32_CRYP_CS)
struct cryp_periph_registers
{
  u32 buf[16];
};
#endif

// Core
enum cryp_cr : u32
{
  CRYP_CR_ALGODIR = (1 << 2),
  CRYP_CR_FFLUSH = (1 << 14),
  CRYP_CR_CRYPEN = (1 << 15),

#if defined(STM32_CRYP_ALGO_EXTENDED)
  CRYP_CR_ALGOMODE3 = (1 << 19)
#endif
};

#define CRYP_CR_ALGOMODE_SHIFT (3)
#define CRYP_CR_ALGOMODE_MASK (0x7)

enum cryp_cr_algomode : u32
{
  CRYP_CR_ALGOMODE_TDES_ECB = 0b0000,
  CRYP_CR_ALGOMODE_TDES_CBC = 0b0001,
  CRYP_CR_ALGOMODE_DES_ECB = 0b0010,
  CRYP_CR_ALGOMODE_DES_CBC = 0b0011,
  CRYP_CR_ALGOMODE_AES_ECB = 0b0100,
  CRYP_CR_ALGOMODE_AES_CBC = 0b0101,
  CRYP_CR_ALGOMODE_AES_CTR = 0b0110,
  CRYP_CR_ALGOMODE_AES_KEY_DEC = 0b0111,
  CRYP_CR_ALGOMODE_AES_GCM_GMAC = 0b000,
  CRYP_CR_ALGOMODE_AES_CCM = 0b0001
};

#define CRYP_CR_DATATYPE_SHIFT (6)
#define CRYP_CR_DATATYPE_MASK (0x3)

enum cryp_cr_datatype : u32
{
  CRYP_CR_DATATYPE_32BIT = 0b00,
  CRYP_CR_DATATYPE_16BIT = 0b01,
  CRYP_CR_DATATYPE_8BIT = 0b10,
  CRYP_CR_DATATYPE_BITSTR = 0b11
};

#define CRYP_CR_KEYSIZE_SHIFT (8)
#define CRYP_CR_KEYSIZE_MASK (0x3)

enum cryp_cr_keysize : u32
{
  CRYP_CR_KEYSIZE_128BIT = 0b00,
  CRYP_CR_KEYSIZE_192BIT = 0b01,
  CRYP_CR_KEYSIZE_256BIT = 0b10
};

#if defined(STM32_CRYP_ALGO_EXTENDED)
#define CRYP_CR_GCMCCMPH_SHIFT (16)
#define CRYP_CR_GCMCCMPH_MASK (0x3)

enum cryp_cr_gcmccmph : u32
{
  CRYP_CR_GCMCCMPH_INIT_PHASE = 0b00,
  CRYP_CR_GCMCCMPH_HEADER_PHASE = 0b01,
  CRYP_CR_GCMCCMPH_PAYLOAD_PHASE = 0b10,
  CRYP_CR_GCMCCMPH_FINAL_PHASE = 0b11
};
#endif

enum cryp_sr : u32
{
  CRYP_SR_IFEM = (1 << 0),
  CRYP_SR_IFNF = (1 << 1),
  CRYP_SR_OFNE = (1 << 2),
  CRYP_SR_OFFU = (1 << 3),
  CRYP_SR_BUSY = (1 << 4)
};

enum cryp_dmacr : u32
{
  CRYP_DMACR_DIEN = (1 << 0),
  CRYP_DMACR_DOEN = (1 << 1)
};

enum cryp_imscr : u32
{
  CRYP_IMSCR_INIM = (1 << 0),
  CRYP_IMSCR_OUTIM = (1 << 1)
};

enum cryp_risr : u32
{
  CRYP_RISR_INRIS = (1 << 0),
  CRYP_RISR_OUTRIS = (1 << 1)
};

enum cryp_misr : u32
{
  CRYP_MISR_INMIS = (1 << 0),
  CRYP_MISR_OUTMIS = (1 << 1)
};

// API

enum cryp_algorithm_direction
{
  CRYP_ALGORITHM_DIRECTION_ENCRYPT,
  CRYP_ALGORITHM_DIRECTION_DECRYPT
};

enum cryp_algorithm_mode
{
  CRYP_ALGORITHM_MODE_TDES_ECB,
  CRYP_ALGORITHM_MODE_TDES_CBC,
  CRYP_ALGORITHM_MODE_DES_ECB,
  CRYP_ALGORITHM_MODE_DES_CBC,
  CRYP_ALGORITHM_MODE_AES_ECB,
  CRYP_ALGORITHM_MODE_AES_CBC,
  CRYP_ALGORITHM_MODE_AES_CTR,
  CRYP_ALGORITHM_MODE_AES_KEY_DEC,

#if defined(STM32_CRYP_ALGO_EXTENDED)
  CRYP_ALGORITHM_MODE_AES_GCM_GMAC,
  CRYP_ALGORITHM_MODE_AES_CCM
#endif
};

enum cryp_data_type
{
  CRYP_DATA_TYPE_32BIT,
  CRYP_DATA_TYPE_16BIT,
  CRYP_DATA_TYPE_8BIT,
  CRYP_DATA_TYPE_BITSTR
};

enum cryp_key_size
{
  CRYP_KEY_SIZE_128BIT,
  CRYP_KEY_SIZE_192BIT,
  CRYP_KEY_SIZE_256BIT
};

#if defined(STM32_CRYP_ALGO_EXTENDED)
enum cryp_gcm_phase
{
  CRYP_GCM_PHASE_INIT,
  CRYP_GCM_PHASE_HEADER,
  CRYP_GCM_PHASE_PAYLOAD,
  CRYP_GCM_PHASE_FINAL
};
#endif

enum cryp_flag
{
  CRYP_FLAG_INPUT_FIFO_EMPTY,
  CRYP_FLAG_INPUT_FIFO_NOT_NULL,
  CRYP_FLAG_OUTPUT_FIFO_NOT_EMPTY,
  CRYP_FLAG_OUTPUT_FIFO_FULL,
  CRYP_FLAG_BUSY
};

enum cryp_dma
{
  CRYP_DMA_INPUT,
  CRYP_DMA_OUTPUT
};

enum cryp_interrupt
{
  CRYP_INTERRUPT_INPUT_FIFO_SERVICE,
  CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE
};

enum cryp_iv_size
{
  CRYP_IV_SIZE_64BIT,
  CRYP_IV_SIZE_128BIT
};

extern volatile struct cryp_registers_map* CRYP;

void
cryp_set_algorithm_direction(
  enum cryp_algorithm_direction direction
);

void
cryp_set_algorithm_mode(
  enum cryp_algorithm_mode mode
);

void
cryp_set_data_type(
  enum cryp_data_type type
);

void
cryp_set_key_size(
  enum cryp_key_size size
);

void
cryp_fifo_flush(void);

void
cryp_enable(void);

void
cryp_disable(void);

#if defined(STM32_CRYP_ALGO_EXTENDED)
void
cryp_set_gcm_phase(
  enum cryp_gcm_phase phase
);
#endif

u32
cryp_is_flag_set(
  enum cryp_flag flag
);

void
cryp_write_input_data(
  u32 data
);

u32
cryp_read_output_data(void);

void
cryp_dma_enable(
  enum cryp_dma dma
);

void
cryp_dma_disable(
  enum cryp_dma dma
);

void
cryp_interrupt_enable(
  enum cryp_interrupt interrupt
);

void
cryp_interrupt_disable(
  enum cryp_interrupt interrupt
);

u32
cryp_has_interrupt_occurred(
  enum cryp_interrupt interrupt
);

u32
cryp_is_interrupt_pending(
  enum cryp_interrupt interrupt
);

void
cryp_write_key_128bit(
  struct cryp_key* key
);

void
cryp_write_key_192bit(
  struct cryp_key* key
);

void
cryp_write_key_256bit(
  struct cryp_key* key
);

void
cryp_write_key(
  struct cryp_key* key,
  enum cryp_key_size size
);

void
cryp_write_iv_64bit(
  struct cryp_iv* iv
);

void
cryp_write_iv_128bit(
  struct cryp_iv* iv
);

void
cryp_write_iv(
  struct cryp_iv* iv,
  enum cryp_iv_size size
);

#if defined(STM32_CRYP_CS)
void
cryp_dump_all(
  struct cryp_periph_registers* regs
);

void
cryp_restore_all(
  struct cryp_periph_registers* regs
);
#endif

END_DECLARATIONS

#endif
