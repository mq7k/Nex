#ifndef STM32_DRIVER_DMA_H
#define STM32_DRIVER_DMA_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F1x
 */

BEGIN_DECLARATIONS

struct dma_channel_registers_map
{
  u32 CCR;
  u32 CNDTR;
  u32 CPAR;
  u32 CMAR;
  u32 __padding[4];
};

struct dma_registers_map
{
  u32 ISR;
  u32 IFCR;
  struct dma_channel_registers_map channels[7];
};


// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#define DMA_ISR_CHANNEL_STRIDE (4)

enum dma_isr : u32
{
  DMA_ISR_GIF = (1 << 0),
  DMA_ISR_TCIF = (1 << 1),
  DMA_ISR_HTIF = (1 << 2),
  DMA_ISR_TEIF = (1 << 3)
};

#define DMA_IFCR_CHANNEL_STRIDE (4)

enum dma_ifcr : u32
{
  DMA_IFCR_CGIF = (1 << 0),
  DMA_IFCR_CTCIF = (1 << 1),
  DMA_IFCR_CHTIF = (1 << 2),
  DMA_IFCR_CTEIF = (1 << 3)
};

enum dma_ccr : u32
{
  DMA_CCR_EN = (1 << 0),
  DMA_CCR_TCIE = (1 << 1),
  DMA_CCR_HTIE = (1 << 2),
  DMA_CCR_TEIE = (1 << 3),
  DMA_CCR_DIR = (1 << 4),
  DMA_CCR_CIRC = (1 << 5),
  DMA_CCR_PINC = (1 << 6),
  DMA_CCR_MINC = (1 << 7),
  DMA_CCR_MEM2MEM = (1 << 14)
};

/* Bits[9:8] */
#define DMA_CCR_PSIZE_SHIFT (8)
#define DMA_CCR_PSIZE_MASK (0x3u)

enum dma_ccr_psize : u32
{
  DMA_CCR_PSIZE_8BITS = 0b00,
  DMA_CCR_PSIZE_16BITS = 0b01,
  DMA_CCR_PSIZE_32BITS = 0b10
};

/* Bits[11:10] */
#define DMA_CCR_MSIZE_SHIFT (10)
#define DMA_CCR_MSIZE_MASK (0x3u)

enum dma_ccr_msize : u32
{
  DMA_CCR_MSIZE_8BITS = 0b00,
  DMA_CCR_MSIZE_16BITS = 0b01,
  DMA_CCR_MSIZE_32BITS = 0b10
};

/* Bits[13:12] */
#define DMA_CCR_PL_SHIFT (12)
#define DMA_CCR_PL_MASK (0x3u)

enum dma_ccr_pl : u32
{
  DMA_CCR_PL_LOW = 0b00,
  DMA_CCR_PL_MEDIUM = 0b01,
  DMA_CCR_PL_HIGH = 0b10,
  DMA_CCR_PL_VERY_HIGH = 0b11
};

/* Bits[15:0] */
#define DMA_CNDTR_NDT_SHIFT (0)
#define DMA_CNDTR_NDT_MASK (0xffffu)

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum dma_channel
{
  DMA_CHANNEL1,
  DMA_CHANNEL2,
  DMA_CHANNEL3,
  DMA_CHANNEL4,
  DMA_CHANNEL5,
  DMA_CHANNEL6,
  DMA_CHANNEL7
};

enum dma_flag
{
  DMA_FLAG_GLOBAL_INTERRUPT,
  DMA_FLAG_TRANSER_COMPLETE,
  DMA_FLAG_HALF_TRANSFER,
  DMA_FLAG_TRANSFER_ERROR
};

enum dma_interrupt
{
  DMA_INTERRUPT_TRANSFER_COMPLETE,
  DMA_INTERRUPT_HALF_TRANSFER,
  DMA_INTERRUPT_TRANSFER_ERROR
};

enum dma_transfer_direction
{
  DMA_TRANSFER_DIRECTION_FROM_PERIPH,
  DMA_TRANSFER_DIRECTION_FROM_MEMORY
};

enum dma_memory_size
{
  DMA_MEMORY_SIZE_8BITS,
  DMA_MEMORY_SIZE_16BITS,
  DMA_MEMORY_SIZE_32BITS
};

enum dma_periph_size
{
  DMA_PERIPH_SIZE_8BITS,
  DMA_PERIPH_SIZE_16BITS,
  DMA_PERIPH_SIZE_32BITS
};

enum dma_channel_priority
{
  DMA_CHANNEL_PRIORITY_LOW,
  DMA_CHANNEL_PRIORITY_MEDIUM,
  DMA_CHANNEL_PRIORITY_HIGH,
  DMA_CHANNEL_PRIORITY_VERY_HIGH
};

#if defined(STM32_DMA1)
extern volatile struct dma_registers_map* DMA1;
#endif

#if defined(STM32_DMA2)
extern volatile struct dma_registers_map* DMA2;
#endif

u32
dma_is_channel_flag_set(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_flag flag
);

void
dma_channel_flag_clear(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_flag flag
);

void
dma_channel_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_interrupt_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_interrupt interrupt
);

void
dma_channel_interrupt_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_interrupt interrupt
);

void
dma_channel_set_data_transfer_direction(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_transfer_direction direction
);

void
dma_channel_circular_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_circular_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_periph_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_periph_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_memory_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_memory_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_set_periph_size(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_periph_size size
);

void
dma_channel_set_memory_size(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_memory_size size
);

void
dma_channel_set_priority_level(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_channel_priority priority
);

void
dma_channel_mem2mem_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_mem2mem_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_set_channel_transfer_items_count(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  u32 bytes_count
);

u32
dma_get_channel_transfer_items_left(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
);

void
dma_channel_set_periph_address(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  u32 periph_address
);

void
dma_channel_set_memory_address(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  u32 memory_address
);

END_DECLARATIONS

#endif
