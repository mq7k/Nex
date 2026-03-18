#ifndef SYN_DMAIF_H
#define SYN_DMAIF_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct dmaif_config
{
  // Hardware peripheral configuration values.
  volatile void* dma;
  u32 stream;
  u32 channel;

  u32 mem_burst;
  u32 periph_burst;
  u32 priority;
  u32 msize;
  u32 psize;
  u32 direction;
  u32 flow_controller;
  u32 items_count;
  uptr periph_addr;
  u32 fifo_threshold;

  // Single-bit configuration field.
  u32 options;

  // Buffers.
  u8* pbuf;
  u8* sbuf;
  u32 buf_len;

  // User-provided hints.
  u32 periph;
  u32 bytes_count;
  // u32 priority;
  u32 supported_psize;
  u32 supported_pburst;
};

enum dmaif_capability : u32
{
  DMAIF_CAP_DB = BIT(0),
  DMAIF_CAP_DB_HW_SWAP = BIT(1),
  DMAIF_CAP_CIRCULAR = BIT(2),
  DMAIF_CAP_MEM_INC_MODE = BIT(3),
  DMAIF_CAP_PERIPH_INC_MODE = BIT(4),
  DMAIF_CAP_INC_OFFSET_32bit = BIT(5),
  DMAIF_CAP_EXT_FLOW_CONTROLLER = BIT(6),

  DMAIF_CAP_MEM_16bit_WIDE = BIT(7),
  DMAIF_CAP_MEM_32bit_WIDE = BIT(8),

  DMAIF_CAP_PERIPH_16bit_WIDE = BIT(9),
  DMAIF_CAP_PERIPH_32bit_WIDE = BIT(10),

  DMAIF_CAP_MEM_BURST16 = BIT(11),
  DMAIF_CAP_MEM_BURST8 = BIT(12),
  DMAIF_CAP_MEM_BURST4 = BIT(13),
  DMAIF_CAP_MEM_BURST1 = BIT(14),

  DMAIF_CAP_PERIPH_BURST16 = BIT(15),
  DMAIF_CAP_PERIPH_BURST8 = BIT(16),
  DMAIF_CAP_PERIPH_BURST4 = BIT(17),
  DMAIF_CAP_PERIPH_BURST1 = BIT(18),

  DMAIF_CAP_FIFO = BIT(19),
  DMAIF_CAP_FIFO_THRS_1over4 = BIT(20),
  DMAIF_CAP_FIFO_THRS_1over2 = BIT(21),
  DMAIF_CAP_FIFO_THRS_3over4 = BIT(22),
  DMAIF_CAP_FIFO_THRS_FULL = BIT(23),

  DMAIF_CAP_PRIORITY = BIT(24)
};

enum dmaif_code
{
  DMAIF_CODE_OK,

  DMAIF_CODE_UNSUPPORTED_CAP_DBUF,
  DMAIF_CODE_UNSUPPORTED_CAP_CIRCULAR,

  DMAIF_CODE_INVALID_CFG,
  DMAIF_CODE_INVALID_HW,
  DMAIF_CODE_INVALID_STREAM,
  DMAIF_CODE_INVALID_CHANNEL,
  DMAIF_CODE_UNSUPPORTED_PERIPH,
  DMAIF_CODE_INVALID_PBUF,
  DMAIF_CODE_INVALID_SBUF,
  DMAIF_CODE_INVALID_BUF_LEN,
  DMAIF_CODE_INVALID_DB_MODE,
  DMAIF_CODE_INVALID_PRIORITY,
  DMAIF_CODE_INVALID_INC_OFFSET,
  DMAIF_CODE_INVALID_MEM_DATA_SIZE,
  DMAIF_CODE_INVALID_PERIPH_MEM_DATA_SIZE,
  DMAIF_CODE_INVALID_DIR,
  DMAIF_CODE_INVALID_FC,
  DMAIF_CODE_INVALID_ITEMS_COUNT,
  DMAIF_CODE_INVALID_PERIPH_ADDR,
  DMAIF_CODE_UNSUPPORTED_PSIZE,
  DMAIF_CODE_UNALIGNED_BYTES_COUNT,
  DMAIF_CODE_UNSUPPORTED_PBURST,
  DMAIF_CODE_UNSUPPORTED_MSIZE,
  DMAIF_CODE_UNSUPPORTED_FIFO_THRESHOLD,
  DMAIF_CODE_INVALID_MEM_BURST,
  DMAIF_CODE_INVALID_PERIPH_BURST
};

enum dmaif_stream
{
  DMAIF_STREAM0,
};

enum dmaif_channel
{
  DMAIF_CHANNEL0,
};

enum dmaif_dir
{
  DMAIF_DIR_MEM2PERIPH,
  DMAIF_DIR_PERIPH2MEM,
  DMAIF_DIR_MEM2MEM
};

enum dmaif_data
{
  DMAIF_DATA_8bit,
  DMAIF_DATA_16bit,
  DMAIF_DATA_32bit
};

enum dmaif_priority
{
  DMAIF_PRIORITY_LOW,
  DMAIF_PRIORITY_MEDIUM,
  DMAIF_PRIORITY_HIGH,
  DMAIF_PRIORITY_VERY_HIGH
};

enum dmaif_mem_burst
{
  DMAIF_MEM_BURST1,
  DMAIF_MEM_BURST4,
  DMAIF_MEM_BURST8,
  DMAIF_MEM_BURST16
};

enum dmaif_periph_burst
{
  DMAIF_PERIPH_BURST1,
  DMAIF_PERIPH_BURST4,
  DMAIF_PERIPH_BURST8,
  DMAIF_PERIPH_BURST16
};

enum dmaif_memory
{
  DMAIF_MEMORY0,
  DMAIF_MEMORY1
};

enum dmaif_periph
{
  DMAIF_PERIPH_UNKNOWN,
  DMAIF_PERIPH_USART,
  DMAIF_PERIPH_SPI
};

u32
dmaif_get_capabilities(void);

u32
dmaif_is_capability_supported(
  enum dmaif_capability cap
);

enum dmaif_code
dmaif_auto_config(
  struct dmaif_config* config,
  u32 enabled_caps
);

// void
// dmaif_populate_def_config(
//   struct dmaif_config* config
// );

enum dmaif_code
dmaif_configure(
  struct dmaif_config* config
);

u32
dmaif_query(
  struct dmaif_config* config
);

void
dmaif_set_mem_addr(
  struct dmaif_config* config,
  enum dmaif_memory mem,
  uptr addr
);

void
dmaif_set_items_count(
  struct dmaif_config* config,
  u32 count
);

u32
dmaif_get_items_count(
  struct dmaif_config* config
);

void
dmaif_start_transfer(
  struct dmaif_config* config
);

u32
dmaif_get_current_db_target(
  struct dmaif_config* config
);

END_DECLARATIONS

#endif

