#ifndef STM32_DRIVER_DMA_H
#define STM32_DRIVER_DMA_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct dma_stream_registers_map
{
  u32 SCR;
  u32 SNDTR;
  u32 SPAR;
  u32 SM0AR;
  u32 SM1AR;
  u32 SFCR;
};

struct dma_registers_map
{
  u32 LISR;
  u32 HISR;
  u32 LIFCR;
  u32 HIFCR;
  struct dma_stream_registers_map streams[8];
};

#define DMA_LISR_STRIDE (6)
#define DMA_HISR_STRIDE (6)

enum dma_isr : u32
{
  DMA_ISR_FEIF = (1 << 0),
  DMA_ISR_DMEIF = (1 << 2),
  DMA_ISR_TEIF = (1 << 3),
  DMA_ISR_HTIF = (1 << 4),
  DMA_ISR_TCIF = (1 << 5)
};

#define DMA_LIFCR_STRIDE (6)
#define DMA_HIFCR_STRIDE (6)

enum dma_ifcr : u32
{
  DMA_IFCR_CFEIF = (1 << 0),
  DMA_IFCR_CDMEIF = (1 << 2),
  DMA_IFCR_CTEIF = (1 << 3),
  DMA_IFCR_CHTIF = (1 << 4),
  DMA_IFCR_CTCIF = (1 << 5)
};

enum dma_scr : u32
{
  DMA_SCR_EN = (1 << 0),
  DMA_SCR_DMEIE = (1 << 1),
  DMA_SCR_TEIE = (1 << 2),
  DMA_SCR_HTIE = (1 << 3),
  DMA_SCR_TCIE = (1 << 4),
  DMA_SCR_PFCTRL = (1 << 5),
  DMA_SCR_CIRC = (1 << 8),
  DMA_SCR_PINC = (1 << 9),
  DMA_SCR_MINC = (1 << 10),
  DMA_SCR_PINCOS = (1 << 15),
  DMA_SCR_DBM = (1 << 18),
  DMA_SCR_CT = (1 << 19)
};

#define DMA_SCR_DIR_SHIFT (6)
#define DMA_SCR_DIR_MASK (0x3)

enum dma_scr_dir : u32
{
  DMA_SCR_DIR_PERIPH_TO_MEMORY = 0b00,
  DMA_SCR_DIR_MEMORY_TO_PERIPH = 0b01,
  DMA_SCR_DIR_MEMORY_TO_MEMORY = 0b10
};

#define DMA_SCR_PSIZE_SHIFT (11)
#define DMA_SCR_PSIZE_MASK (0x3)

enum dma_scr_psize : u32
{
  DMA_SCR_PSIZE_BYTE = 0b00,
  DMA_SCR_PSIZE_HALF_WORD = 0b01,
  DMA_SCR_PSIZE_WORD = 0b10
};

#define DMA_SCR_MSIZE_SHIFT (13)
#define DMA_SCR_MSIZE_MASK (0x3)

enum dma_scr_msize : u32
{
  DMA_SCR_MSIZE_BYTE = 0b00,
  DMA_SCR_MSIZE_HALF_WORD = 0b01,
  DMA_SCR_MSIZE_WORD = 0b10
};

#define DMA_SCR_PL_SHIFT (16)
#define DMA_SCR_PL_MASK (0x3)

enum dma_scr_pl : u32
{
  DMA_SCR_PL_LOW = 0b00,
  DMA_SCR_PL_MEDIUM = 0b01,
  DMA_SCR_PL_HIGH = 0b10,
  DMA_SCR_PL_VERY_HIGH = 0b11
};

#define DMA_SCR_PBURST_SHIFT (21)
#define DMA_SCR_PBURST_MASK (0x3)

enum dma_scr_pburst : u32
{
  DMA_SCR_PBURST_SINGLE_TRANSFER = 0b00,
  DMA_SCR_PBURST_INCR4_BURST = 0b01,
  DMA_SCR_PBURST_INCR8_BURST = 0b10,
  DMA_SCR_PBURST_INCR16_BURST = 0b11
};

#define DMA_SCR_MBURST_SHIFT (23)
#define DMA_SCR_MBURST_MASK (0x3)

enum dma_scr_mburst : u32
{
  DMA_SCR_MBURST_SINGLE_TRANSFER = 0b00,
  DMA_SCR_MBURST_INCR4_BURST = 0b01,
  DMA_SCR_MBURST_INCR8_BURST = 0b10,
  DMA_SCR_MBURST_INCR16_BURST = 0b11
};

#define DMA_SCR_CHSEL_SHIFT (25)

#if defined(STM32_DMA_CHSEL_4BIT)
#define DMA_SCR_CHSEL_MASK (0xf)
#endif

#if defined(STM32_DMA_CHSEL_3BIT)
#define DMA_SCR_CHSEL_MASK (0x7)
#endif

enum dma_scr_chsel : u32
{
#if defined(STM32_DMA_CHSEL_4BIT)
  DMA_SCR_CHSEL_CHANNEL0 = 0b0000,
  DMA_SCR_CHSEL_CHANNEL1 = 0b0001,
  DMA_SCR_CHSEL_CHANNEL2 = 0b0010,
  DMA_SCR_CHSEL_CHANNEL3 = 0b0011,
  DMA_SCR_CHSEL_CHANNEL4 = 0b0100,
  DMA_SCR_CHSEL_CHANNEL5 = 0b0101,
  DMA_SCR_CHSEL_CHANNEL6 = 0b0110,
  DMA_SCR_CHSEL_CHANNEL7 = 0b0111,
  DMA_SCR_CHSEL_CHANNEL8 = 0b1000,
  DMA_SCR_CHSEL_CHANNEL9 = 0b1001,
  DMA_SCR_CHSEL_CHANNEL10 = 0b1010,
  DMA_SCR_CHSEL_CHANNEL11 = 0b1011,
  DMA_SCR_CHSEL_CHANNEL12 = 0b1100,
  DMA_SCR_CHSEL_CHANNEL13 = 0b1101,
  DMA_SCR_CHSEL_CHANNEL14 = 0b1110,
  DMA_SCR_CHSEL_CHANNEL15 = 0b1111
#endif

#if defined(STM32_DMA_CHSEL_3BIT)
  DMA_SCR_CHSEL_CHANNEL0 = 0b000,
  DMA_SCR_CHSEL_CHANNEL1 = 0b001,
  DMA_SCR_CHSEL_CHANNEL2 = 0b010,
  DMA_SCR_CHSEL_CHANNEL3 = 0b011,
  DMA_SCR_CHSEL_CHANNEL4 = 0b100,
  DMA_SCR_CHSEL_CHANNEL5 = 0b101,
  DMA_SCR_CHSEL_CHANNEL6 = 0b110,
  DMA_SCR_CHSEL_CHANNEL7 = 0b111
#endif
};

#define DMA_SNDTR_NDT_SHIFT (0)
#define DMA_SNDTR_NDT_MASK (0xffff)

enum dma_sfcr : u32
{
  DMA_SFCR_DMDIS = (1 << 2),
  DMA_SFCR_FEIE = (1 << 7)
};

#define DMA_SFCR_FTH_SHIFT (0)
#define DMA_SFCR_FTH_MASK (0x3)

enum dma_sfcr_fth : u32
{
  DMA_SFCR_FTH_1over4_FULL_FIFO = 0b00,
  DMA_SFCR_FTH_1over2_FULL_FIFO = 0b01,
  DMA_SFCR_FTH_3over4_FULL_FIFO = 0b10,
  DMA_SFCR_FTH_FULL_FIFO = 0b11
};

#define DMA_SFCR_FS_SHIFT (3)
#define DMA_SFCR_FS_MASK (0x7)

enum dma_sfcr_fs : u32
{
  DMA_SFCR_FS_LESS_1over4 = 0b000,
  DMA_SFCR_FS_LESS_1over2 = 0b001,
  DMA_SFCR_FS_LESS_3over4 = 0b010,
  DMA_SFCR_FS_GREATER_3over4 = 0b011,
  DMA_SFCR_FS_FIFO_EMPTY = 0b100,
  DMA_SFCR_FS_FIFO_FULL = 0b101
};

// API
enum dma_stream
{
  DMA_STREAM0,
  DMA_STREAM1,
  DMA_STREAM2,
  DMA_STREAM3,
  DMA_STREAM4,
  DMA_STREAM5,
  DMA_STREAM6,
  DMA_STREAM7
};

enum dma_stream_flag
{
  DMA_STREAM_FLAG_FIFO_ERROR,
  DMA_STREAM_FLAG_DIRECT_MODE_ERROR,
  DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR,
  DMA_STREAM_FLAG_HALF_TRANSFER,
  DMA_STREAM_FLAG_TRANSFER_COMPLETE
};

enum dma_stream_interrupt
{
  DMA_STREAM_INTERRUPT_DIRECT_MODE_ERROR,
  DMA_STREAM_INTERRUPT_TRANSFER_ERROR,
  DMA_STREAM_INTERRUPT_HALF_TRANSFER,
  DMA_STREAM_INTERRUPT_TRANSFER_COMPLETE,
  DMA_STREAM_INTERRUPT_FIFO_ERROR
};

enum dma_stream_flow_controller
{
  DMA_STREAM_FLOW_CONTROLLER_DMA,
  DMA_STREAM_FLOW_CONTROLLER_PERIPH
};

enum dma_stream_direction
{
  DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY,
  DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH,
  DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY
};

enum dma_stream_periph_inc_offset
{
  DMA_STREAM_PERIPH_INC_OFFSET_FIXED,
  DMA_STREAM_PERIPH_INC_OFFSET_32BIT
};

enum dma_stream_periph_data_size
{
  DMA_STREAM_PERIPH_SIZE_BYTE,
  DMA_STREAM_PERIPH_SIZE_HALF_WORD,
  DMA_STREAM_PERIPH_SIZE_WORD
};

enum dma_stream_memory_data_size
{
  DMA_STREAM_MEMORY_SIZE_BYTE,
  DMA_STREAM_MEMORY_SIZE_HALF_WORD,
  DMA_STREAM_MEMORY_SIZE_WORD
};

enum dma_stream_priority
{
  DMA_STREAM_PRIORITY_LOW,
  DMA_STREAM_PRIORITY_MEDIUM,
  DMA_STREAM_PRIORITY_HIGH,
  DMA_STREAM_PRIORITY_VERY_HIGH
};

enum dma_stream_double_buffer_mode
{
  DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH,
  DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH
};

enum dma_stream_target
{
  DMA_STREAM_TARGET_MEMORY0,
  DMA_STREAM_TARGET_MEMORY1
};

enum dma_stream_periph_burst
{
  DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER,
  DMA_STREAM_PERIPH_BURST_INCR4,
  DMA_STREAM_PERIPH_BURST_INCR8,
  DMA_STREAM_PERIPH_BURST_INCR16
};

enum dma_stream_memory_burst
{
  DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER,
  DMA_STREAM_MEMORY_BURST_INCR4,
  DMA_STREAM_MEMORY_BURST_INCR8,
  DMA_STREAM_MEMORY_BURST_INCR16
};

enum dma_stream_channel
{
  DMA_STREAM_CHANNEL0,
  DMA_STREAM_CHANNEL1,
  DMA_STREAM_CHANNEL2,
  DMA_STREAM_CHANNEL3,
  DMA_STREAM_CHANNEL4,
  DMA_STREAM_CHANNEL5,
  DMA_STREAM_CHANNEL6,
  DMA_STREAM_CHANNEL7,

#if defined(STM32_DMA_CHSEL_4BIT)
  DMA_STREAM_CHANNEL8,
  DMA_STREAM_CHANNEL9,
  DMA_STREAM_CHANNEL10,
  DMA_STREAM_CHANNEL11,
  DMA_STREAM_CHANNEL12,
  DMA_STREAM_CHANNEL13,
  DMA_STREAM_CHANNEL14,
  DMA_STREAM_CHANNEL15
#endif
};

enum dma_stream_memory
{
  DMA_STREAM_MEMORY0,
  DMA_STREAM_MEMORY1
};

enum dma_stream_fifo_threshold
{
  DMA_STREAM_FIFO_THRESHOLD_1over4_FULL,
  DMA_STREAM_FIFO_THRESHOLD_1over2_FULL,
  DMA_STREAM_FIFO_THRESHOLD_3over4_FULL,
  DMA_STREAM_FIFO_THRESHOLD_FULL
};

extern volatile struct dma_registers_map* DMA1;
extern volatile struct dma_registers_map* DMA2;

u32
dma_is_stream_flag_set(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_flag flag
);

void
dma_stream_flag_clear(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_flag flag
);

u32
dma_stream_is_enabled(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_interrupt_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_interrupt interrupt
);

void
dma_stream_interrupt_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_interrupt interrupt
);

void
dma_stream_set_flow_controller(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_flow_controller controller
);

void
dma_stream_set_data_transfer_direction(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_direction direction
);

void
dma_stream_circular_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_circular_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_periph_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_periph_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_memory_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_memory_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_set_periph_data_size(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_periph_data_size size
);

void
dma_stream_set_memory_data_size(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_memory_data_size size
);

void
dma_stream_set_periph_inc_offset(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_periph_inc_offset offset
);

void
dma_stream_set_priority(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_priority priority
);

void
dma_stream_set_double_buffer_mode(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_double_buffer_mode mode
);

void
dma_stream_set_current_target(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_target target
);

u32
dma_stream_get_current_target(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_set_periph_burst_transfer(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_periph_burst burst
);

void
dma_stream_set_memory_burst_transfer(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_memory_burst burst
);

void
dma_stream_set_channel(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_channel channel
);

void
dma_stream_set_items_transfer_count(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  u32 count
);

u32
dma_stream_get_items_transfer_count(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_set_periph_address(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  uptr address
);

void
dma_stream_set_memory_address(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_memory memory,
  uptr address
);

void
dma_stream_set_fifo_threshold(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_fifo_threshold threshold
);

void
dma_stream_direct_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

void
dma_stream_direct_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

u32
dma_stream_get_fifo_status(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
);

END_DECLARATIONS

#endif
