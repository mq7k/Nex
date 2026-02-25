#include "synapse/stm32/drivers/dma/dma_v1.h"
#include "libcom/util.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct dma_registers_map dma_periph;
dma_periph* DMA1 = (dma_periph*) (DMA1_ADDR);
dma_periph* DMA2 = (dma_periph*) (DMA2_ADDR);

typedef volatile struct dma_stream_registers_map dma_stream_vt;

static dma_stream_vt*
get_dma_stream(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  switch (stream)
  {
    case DMA_STREAM0:
      return &dma->streams[0];
      
    case DMA_STREAM1:
      return &dma->streams[1];

    case DMA_STREAM2:
      return &dma->streams[2];
      
    case DMA_STREAM3:
      return &dma->streams[3];

    case DMA_STREAM4:
      return &dma->streams[4];

    case DMA_STREAM5:
      return &dma->streams[5];

    case DMA_STREAM6:
      return &dma->streams[6];

    case DMA_STREAM7:
      return &dma->streams[7];

    default:
      devmode_error_invalid_enum(enum dma_stream, stream);
      return 0;
  }
}

u32
dma_is_stream_flag_set(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_flag flag
)
{
  devmode_assert_lower_or_eq(stream, DMA_STREAM7);
  volatile u32* reg = stream < DMA_STREAM4 ? &dma->LISR : &dma->HISR;
  const u32 stride = stream < DMA_STREAM4 ? DMA_LISR_STRIDE : DMA_HISR_STRIDE;

  constexpr u32 offset = 4;
  constexpr u32 mask = (1 << 2) | (1 << 3) | (1 << 6) | (1 << 7);
  const u32 is_msb = (mask >> stream) & 0x1;
  const u32 shift = stride * FAST_MOD(stream, 4) + is_msb * offset;

  switch (flag)
  {
    case DMA_STREAM_FLAG_FIFO_ERROR:
      return *reg & (DMA_ISR_FEIF << shift);

    case DMA_STREAM_FLAG_DIRECT_MODE_ERROR:
      return *reg & (DMA_ISR_DMEIF << shift);

    case DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR:
      return *reg & (DMA_ISR_TEIF << shift);

    case DMA_STREAM_FLAG_HALF_TRANSFER:
      return *reg & (DMA_ISR_HTIF << shift);

    case DMA_STREAM_FLAG_TRANSFER_COMPLETE:
      return *reg & (DMA_ISR_TCIF << shift);

    default:
      devmode_error_invalid_enum(enum dma_stream_flag, flag);
      return 0;
  }
}

void
dma_stream_flag_clear(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_flag flag
)
{
  devmode_assert_lower_or_eq(stream, DMA_STREAM7);
  volatile u32* reg = stream < DMA_STREAM4 ? &dma->LIFCR : &dma->HIFCR;
  const u32 stride = stream < DMA_STREAM4 ? DMA_LIFCR_STRIDE : DMA_HIFCR_STRIDE;

  constexpr u32 offset = 4;
  constexpr u32 mask = (1 << 2) | (1 << 3) | (1 << 6) | (1 << 7);
  const u32 is_msb = (mask >> stream) & 0x1;
  const u32 shift = stride * FAST_MOD(stream, 4) + is_msb * offset;

  switch (flag)
  {
    case DMA_STREAM_FLAG_FIFO_ERROR:
      *reg |= (DMA_IFCR_CFEIF << shift);
      break;

    case DMA_STREAM_FLAG_DIRECT_MODE_ERROR:
      *reg |= (DMA_IFCR_CDMEIF << shift);
      break;

    case DMA_STREAM_FLAG_DIRECT_TRANSFER_ERROR:
      *reg |= (DMA_IFCR_CTEIF << shift);
      break;

    case DMA_STREAM_FLAG_HALF_TRANSFER:
      *reg |= (DMA_IFCR_CHTIF << shift);
      break;

    case DMA_STREAM_FLAG_TRANSFER_COMPLETE:
      *reg |= (DMA_IFCR_CTCIF << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_flag, flag);
      break;
  }
}

u32
dma_stream_is_enabled(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  return dma_stream->SCR & DMA_SCR_EN;
}

void
dma_stream_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR |= DMA_SCR_EN;
}

void
dma_stream_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR &= ~DMA_SCR_EN;
}

void
dma_stream_interrupt_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_interrupt interrupt
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  switch (interrupt)
  {
    case DMA_STREAM_INTERRUPT_DIRECT_MODE_ERROR:
      dma_stream->SCR |= DMA_SCR_DMEIE;
      break;

    case DMA_STREAM_INTERRUPT_TRANSFER_ERROR:
      dma_stream->SCR |= DMA_SCR_TEIE;
      break;

    case DMA_STREAM_INTERRUPT_HALF_TRANSFER:
      dma_stream->SCR |= DMA_SCR_HTIE;
      break;

    case DMA_STREAM_INTERRUPT_TRANSFER_COMPLETE:
      dma_stream->SCR |= DMA_SCR_TCIE;
      break;

    case DMA_STREAM_INTERRUPT_FIFO_ERROR:
      dma_stream->SFCR |= DMA_SFCR_FEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_interrupt, interrupt);
      break;
  }
}

void
dma_stream_interrupt_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_interrupt interrupt
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  switch (interrupt)
  {
    case DMA_STREAM_INTERRUPT_DIRECT_MODE_ERROR:
      dma_stream->SCR &= ~DMA_SCR_DMEIE;
      break;

    case DMA_STREAM_INTERRUPT_TRANSFER_ERROR:
      dma_stream->SCR &= ~DMA_SCR_TEIE;
      break;

    case DMA_STREAM_INTERRUPT_HALF_TRANSFER:
      dma_stream->SCR &= ~DMA_SCR_HTIE;
      break;

    case DMA_STREAM_INTERRUPT_TRANSFER_COMPLETE:
      dma_stream->SCR &= ~DMA_SCR_TCIE;
      break;

    case DMA_STREAM_INTERRUPT_FIFO_ERROR:
      dma_stream->SFCR &= ~DMA_SFCR_FEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_interrupt, interrupt);
      break;
  }
}

void
dma_stream_set_flow_controller(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_flow_controller controller
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  volatile u32* reg = &dma_stream->SCR;
  switch (controller)
  {
    case DMA_STREAM_FLOW_CONTROLLER_DMA:
      *reg &= ~DMA_SCR_PFCTRL;
      break;

    case DMA_STREAM_FLOW_CONTROLLER_PERIPH:
      *reg |= DMA_SCR_PFCTRL;
      break;

    default:
      devmode_error_invalid_enum(enum data_strem_flow_controller, controller);
      break;
  }
}

void
dma_stream_set_data_transfer_direction(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_direction direction
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SCR_DIR_SHIFT;
  constexpr u32 mask = DMA_SCR_DIR_MASK << shift;
  volatile u32* reg = &dma_stream->SCR;

  switch (direction)
  {
    case DMA_STREAM_DIRECTION_PERIPH_TO_MEMORY:
      *reg &= ~mask;
      break;

    case DMA_STREAM_DIRECTION_MEMORY_TO_PERIPH:
      syn_set_register_bits(reg, mask, DMA_SCR_DIR_MEMORY_TO_PERIPH << shift);
      break;

    case DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY:
      syn_set_register_bits(reg, mask, DMA_SCR_DIR_MEMORY_TO_MEMORY << shift);
      break;
  }
}

void
dma_stream_circular_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR |= DMA_SCR_CIRC;
}

void
dma_stream_circular_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR &= ~DMA_SCR_CIRC;
}

void
dma_stream_periph_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR |= DMA_SCR_PINC;
}

void
dma_stream_periph_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR &= ~DMA_SCR_PINC;
}

void
dma_stream_memory_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR |= DMA_SCR_MINC;
}

void
dma_stream_memory_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SCR &= ~DMA_SCR_MINC;
}

void
dma_stream_set_periph_data_size(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_periph_data_size size
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SCR_PSIZE_SHIFT;
  constexpr u32 mask = DMA_SCR_PSIZE_MASK << shift;
  volatile u32* reg = &dma_stream->SCR;

  switch (size)
  {
    case DMA_STREAM_PERIPH_SIZE_BYTE:
      *reg &= ~mask;
      break;

    case DMA_STREAM_PERIPH_SIZE_HALF_WORD:
      syn_set_register_bits(reg, mask, DMA_SCR_PSIZE_HALF_WORD << shift);
      break;

    case DMA_STREAM_PERIPH_SIZE_WORD:
      syn_set_register_bits(reg, mask, DMA_SCR_PSIZE_WORD << shift);
      break;
  }
}

void
dma_stream_set_memory_data_size(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_memory_data_size size
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SCR_MSIZE_SHIFT;
  constexpr u32 mask = DMA_SCR_MSIZE_MASK << shift;
  volatile u32* reg = &dma_stream->SCR;

  switch (size)
  {
    case DMA_STREAM_MEMORY_SIZE_BYTE:
      *reg &= ~mask;
      break;

    case DMA_STREAM_MEMORY_SIZE_HALF_WORD:
      syn_set_register_bits(reg, mask, DMA_SCR_MSIZE_HALF_WORD << shift);
      break;

    case DMA_STREAM_MEMORY_SIZE_WORD:
      syn_set_register_bits(reg, mask, DMA_SCR_MSIZE_WORD << shift);
      break;
  }
}

void
dma_stream_set_periph_inc_offset(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_periph_inc_offset offset
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  volatile u32* reg = &dma_stream->SCR;
  switch (offset)
  {
    case DMA_STREAM_PERIPH_INC_OFFSET_FIXED:
      *reg &= ~DMA_SCR_PINCOS;
      break;

    case DMA_STREAM_PERIPH_INC_OFFSET_32BIT:
      *reg |= DMA_SCR_PINCOS;
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_periph_inc_offset, offset);
      break;
  }
}

void
dma_stream_set_priority(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_priority priority
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SCR_PL_SHIFT;
  constexpr u32 mask = DMA_SCR_PL_MASK << shift;
  volatile u32* reg = &dma_stream->SCR;

  switch (priority)
  {
    case DMA_STREAM_PRIORITY_LOW:
      *reg &= ~mask;
      break;

    case DMA_STREAM_PRIORITY_MEDIUM:
      syn_set_register_bits(reg, mask, DMA_SCR_PL_MEDIUM << shift);
      break;

    case DMA_STREAM_PRIORITY_HIGH:
      syn_set_register_bits(reg, mask, DMA_SCR_PL_HIGH << shift);
      break;

    case DMA_STREAM_PRIORITY_VERY_HIGH:
      *reg |= (DMA_SCR_PL_VERY_HIGH << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_priority, priority);
      break;
  }
}

void
dma_stream_set_double_buffer_mode(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_double_buffer_mode mode
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  volatile u32* reg = &dma_stream->SCR;
  switch (mode)
  {
    case DMA_STREAM_DOUBLE_BUFFER_MODE_NOSWITCH:
      *reg &= ~DMA_SCR_DBM;
      break;

    case DMA_STREAM_DOUBLE_BUFFER_MODE_SWITCH:
      *reg |= DMA_SCR_DBM;
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_double_buffer_mode, mode);
      break;
  }
}

void
dma_stream_set_current_target(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_target target
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  volatile u32* reg = &dma_stream->SCR;
  switch (target)
  {
    case DMA_STREAM_TARGET_MEMORY0:
      *reg &= ~DMA_SCR_CT;
      break;

    case DMA_STREAM_TARGET_MEMORY1:
      *reg |= DMA_SCR_CT;
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_target, target);
      break;
  }
}

u32
dma_stream_get_current_target(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  return dma_stream->SCR & DMA_SCR_CT;
}

void
dma_stream_set_periph_burst_transfer(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_periph_burst burst
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SCR_PBURST_SHIFT;
  constexpr u32 mask = DMA_SCR_PBURST_MASK << shift;
  volatile u32* reg = &dma_stream->SCR;

  switch (burst)
  {
    case DMA_STREAM_PERIPH_BURST_SINGLE_TRANSFER:
      *reg &= ~mask;
      break;

    case DMA_STREAM_PERIPH_BURST_INCR4:
      syn_set_register_bits(reg, mask, DMA_SCR_PBURST_INCR4_BURST << shift);
      break;

    case DMA_STREAM_PERIPH_BURST_INCR8:
      syn_set_register_bits(reg, mask, DMA_SCR_PBURST_INCR8_BURST << shift);
      break;

    case DMA_STREAM_PERIPH_BURST_INCR16:
      *reg |= (DMA_SCR_MBURST_INCR16_BURST << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_periph_burst, burst);
      break;
  }
}

void
dma_stream_set_memory_burst_transfer(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_memory_burst burst
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SCR_MBURST_SHIFT;
  constexpr u32 mask = DMA_SCR_MBURST_MASK << shift;
  volatile u32* reg = &dma_stream->SCR;

  switch (burst)
  {
    case DMA_STREAM_MEMORY_BURST_SINGLE_TRANSFER:
      *reg &= ~mask;
      break;

    case DMA_STREAM_MEMORY_BURST_INCR4:
      syn_set_register_bits(reg, mask, DMA_SCR_MBURST_INCR4_BURST << shift);
      break;

    case DMA_STREAM_MEMORY_BURST_INCR8:
      syn_set_register_bits(reg, mask, DMA_SCR_MBURST_INCR8_BURST << shift);
      break;

    case DMA_STREAM_MEMORY_BURST_INCR16:
      *reg |= (DMA_SCR_MBURST_INCR16_BURST << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_memory_burst, burst);
      break;
  }
}

void
dma_stream_set_channel(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_channel channel
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SCR_CHSEL_SHIFT;
  constexpr u32 mask = DMA_SCR_CHSEL_MASK << shift;
  volatile u32* reg = &dma_stream->SCR;

  switch (channel)
  {
    case DMA_STREAM_CHANNEL0:
      *reg &= ~mask;
      break;

    case DMA_STREAM_CHANNEL1:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL1 << shift);
      break;

    case DMA_STREAM_CHANNEL2:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL2 << shift);
      break;

    case DMA_STREAM_CHANNEL3:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL3 << shift);
      break;

    case DMA_STREAM_CHANNEL4:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL4 << shift);
      break;

    case DMA_STREAM_CHANNEL5:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL5 << shift);
      break;

    case DMA_STREAM_CHANNEL6:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL6 << shift);
      break;

    case DMA_STREAM_CHANNEL7:
#if defined(STM32_DMA_CHSEL_3BIT)
      *reg |= (DMA_SCR_CHSEL_CHANNEL7 << shift);
#endif

#if defined(STM32_DMA_CHSEL_4BIT)
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL7 << shift);
#endif
      break;

#if defined(STM32_DMA_CHSEL_4BIT)
    case DMA_STREAM_CHANNEL8:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL8 << shift);
      break;

    case DMA_STREAM_CHANNEL9:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL9 << shift);
      break;

    case DMA_STREAM_CHANNEL10:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL10 << shift);
      break;

    case DMA_STREAM_CHANNEL11:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL11 << shift);
      break;

    case DMA_STREAM_CHANNEL12:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL12 << shift);
      break;

    case DMA_STREAM_CHANNEL13:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL13 << shift);
      break;

    case DMA_STREAM_CHANNEL14:
      syn_set_register_bits(reg, mask, DMA_SCR_CHSEL_CHANNEL14 << shift);
      break;

    case DMA_STREAM_CHANNEL15:
      *reg |= (DMA_SCR_CHSEL_CHANNEL15 << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum dma_stream_channel, channel);
      break;
  }
}

void
dma_stream_set_items_transfer_count(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  u32 count
)
{
  devmode_assert_lower_or_eq(count, DMA_SNDTR_NDT_MASK);
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SNDTR_NDT_SHIFT;
  constexpr u32 mask = DMA_SNDTR_NDT_MASK << shift;
  volatile u32* reg = &dma_stream->SNDTR;
  syn_set_register_bits(reg, mask, count << shift);
}

u32
dma_stream_get_items_transfer_count(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  return dma_stream->SNDTR;
}

void
dma_stream_set_periph_address(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  uptr address
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SPAR = (u32) address;
}

void
dma_stream_set_memory_address(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_memory memory,
  uptr address
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);

  switch (memory)
  {
    case DMA_STREAM_MEMORY0:
      dma_stream->SM0AR = (u32) address;
      break;

    case DMA_STREAM_MEMORY1:
      dma_stream->SM1AR = (u32) address;
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_memory, memory);
      break;
  }
}

void
dma_stream_set_fifo_threshold(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream,
  enum dma_stream_fifo_threshold threshold
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SFCR_FTH_SHIFT;
  constexpr u32 mask = DMA_SFCR_FTH_MASK << shift;
  volatile u32* reg = &dma_stream->SFCR;
  
  switch (threshold)
  {
    case DMA_STREAM_FIFO_THRESHOLD_1over4_FULL:
      *reg &= ~mask;
      break;

    case DMA_STREAM_FIFO_THRESHOLD_1over2_FULL:
      syn_set_register_bits(reg, mask, DMA_SFCR_FTH_1over2_FULL_FIFO << shift);
      break;

    case DMA_STREAM_FIFO_THRESHOLD_3over4_FULL:
      syn_set_register_bits(reg, mask, DMA_SFCR_FTH_3over4_FULL_FIFO << shift);
      break;

    case DMA_STREAM_FIFO_THRESHOLD_FULL:
      *reg |= (DMA_SFCR_FTH_FULL_FIFO << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_stream_fifo_threshold, threshold);
      break;
  }
}

void
dma_stream_direct_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SFCR |= DMA_SFCR_DMDIS;
}

void
dma_stream_direct_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  dma_stream->SFCR &= ~DMA_SFCR_DMDIS;
}

u32
dma_stream_get_fifo_status(
  volatile struct dma_registers_map* dma,
  enum dma_stream stream
)
{
  dma_stream_vt* dma_stream = get_dma_stream(dma, stream);
  constexpr u32 shift = DMA_SFCR_FS_SHIFT;
  constexpr u32 mask = DMA_SFCR_FS_MASK;
  volatile u32* reg = &dma_stream->SFCR;
  return (*reg >> shift) & mask;
}

