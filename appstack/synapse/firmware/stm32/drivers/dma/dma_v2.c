#include "synapse/stm32/drivers/dma/dma_v2.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"

typedef volatile struct dma_registers_map dma_periph;

#if defined(STM32_DMA1)
dma_periph* DMA1 = (dma_periph*) (DMA1_ADDR);
#endif

#if defined(STM32_DMA2)
dma_periph* DMA2 = (dma_periph*) (DMA2_ADDR);
#endif

u32
dma_is_channel_flag_set(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_flag flag
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  const u32 shift = DMA_ISR_CHANNEL_STRIDE * channel;

  switch (flag)
  {
    case DMA_FLAG_GLOBAL_INTERRUPT:
      return dma->ISR & (DMA_ISR_GIF << shift);

    case DMA_FLAG_TRANSER_COMPLETE:
      return dma->ISR & (DMA_ISR_TCIF << shift);

    case DMA_FLAG_HALF_TRANSFER:
      return dma->ISR & (DMA_ISR_HTIF << shift);

    case DMA_FLAG_TRANSFER_ERROR:  
      return dma->ISR & (DMA_ISR_TEIF << shift);

    default:
      devmode_error_invalid_enum(enum dma_flag, flag);
      return 0;
  }
}

void
dma_channel_flag_clear(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_flag flag
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  volatile u32* reg = &dma->IFCR;
  const u32 shift = DMA_ISR_CHANNEL_STRIDE * channel;

  switch (flag)
  {
    case DMA_FLAG_GLOBAL_INTERRUPT:
      *reg |= (DMA_IFCR_CGIF << shift);
      break;

    case DMA_FLAG_TRANSER_COMPLETE:
      *reg |= (DMA_ISR_TCIF << shift);
      break;

    case DMA_FLAG_HALF_TRANSFER:
      *reg |= (DMA_ISR_HTIF << shift);
      break;

    case DMA_FLAG_TRANSFER_ERROR:  
      *reg |= (DMA_ISR_TEIF << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_flag, flag);
      break;
  }
}

void
dma_channel_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR |= DMA_CCR_EN;
}

void
dma_channel_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR &= ~DMA_CCR_EN;
}

void
dma_channel_interrupt_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_interrupt interrupt
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  volatile u32* reg = &dma->channels[channel].CCR;

  switch (interrupt)
  {
    case DMA_INTERRUPT_TRANSFER_COMPLETE:
      *reg |= DMA_CCR_TCIE;
      break;

    case DMA_INTERRUPT_HALF_TRANSFER:
      *reg |= DMA_CCR_HTIE;
      break;

    case DMA_INTERRUPT_TRANSFER_ERROR:
      *reg |= DMA_CCR_TEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dma_interrupt, interrupt);
      break;
  }
}

void
dma_channel_interrupt_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_interrupt interrupt
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  volatile u32* reg = &dma->channels[channel].CCR;

  switch (interrupt)
  {
    case DMA_INTERRUPT_TRANSFER_COMPLETE:
      *reg &= ~DMA_CCR_TCIE;
      break;

    case DMA_INTERRUPT_HALF_TRANSFER:
      *reg &= ~DMA_CCR_HTIE;
      break;

    case DMA_INTERRUPT_TRANSFER_ERROR:
      *reg &= ~DMA_CCR_TEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dma_interrupt, interrupt);
      break;
  }
}

void
dma_channel_set_data_transfer_direction(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_transfer_direction direction
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  volatile u32* reg = &dma->channels[channel].CCR;

  switch (direction)
  {
    case DMA_TRANSFER_DIRECTION_FROM_PERIPH:
      *reg &= ~DMA_CCR_DIR;
      break;

    case DMA_TRANSFER_DIRECTION_FROM_MEMORY:
      *reg |= DMA_CCR_DIR;
      break;

    default:
      devmode_error_invalid_enum(enum dma_transfer_direction, direction);
      break;
  }
}

void
dma_channel_circular_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR |= DMA_CCR_CIRC;
}

void
dma_channel_circular_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR &= ~DMA_CCR_CIRC;
}

void
dma_channel_periph_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR |= DMA_CCR_PINC;
}

void
dma_channel_periph_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR &= ~DMA_CCR_PINC;
}

void
dma_channel_memory_increment_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR |= DMA_CCR_MINC;
}

void
dma_channel_memory_increment_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR &= ~DMA_CCR_MINC;
}

void
dma_channel_set_periph_size(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_periph_size size
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);

  constexpr u32 shift = DMA_CCR_PSIZE_SHIFT;
  constexpr u32 mask = DMA_CCR_PSIZE_MASK << shift;
  volatile u32* reg = &dma->channels[channel].CCR;

  switch (size)
  {
    case DMA_PERIPH_SIZE_8BITS:
      syn_set_register_bits(reg, mask, DMA_CCR_PSIZE_8BITS << shift);
      break;

    case DMA_PERIPH_SIZE_16BITS:
      syn_set_register_bits(reg, mask, DMA_CCR_PSIZE_16BITS << shift);
      break;

    case DMA_PERIPH_SIZE_32BITS:
      syn_set_register_bits(reg, mask, DMA_CCR_PSIZE_32BITS << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_periph_size, size);
      break;
  }
}

void
dma_channel_set_memory_size(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_memory_size size
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);

  constexpr u32 shift = DMA_CCR_MSIZE_SHIFT;
  constexpr u32 mask = DMA_CCR_MSIZE_MASK << shift;
  volatile u32* reg = &dma->channels[channel].CCR;

  switch (size)
  {
    case DMA_MEMORY_SIZE_8BITS:
      syn_set_register_bits(reg, mask, DMA_CCR_MSIZE_8BITS << shift);
      break;

    case DMA_MEMORY_SIZE_16BITS:
      syn_set_register_bits(reg, mask, DMA_CCR_MSIZE_16BITS << shift);
      break;

    case DMA_MEMORY_SIZE_32BITS:
      syn_set_register_bits(reg, mask, DMA_CCR_MSIZE_32BITS << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_memory_size, size);
      break;
  }
}

void
dma_channel_set_priority_level(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  enum dma_channel_priority priority
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);

  constexpr u32 shift = DMA_CCR_PL_SHIFT;
  constexpr u32 mask = DMA_CCR_PL_MASK << shift;
  volatile u32* reg = &dma->channels[channel].CCR;

  switch (priority)
  {
    case DMA_CHANNEL_PRIORITY_LOW:
      syn_set_register_bits(reg, mask, DMA_CCR_PL_LOW << shift);
      break;

    case DMA_CHANNEL_PRIORITY_MEDIUM:
      syn_set_register_bits(reg, mask, DMA_CCR_PL_MEDIUM << shift);
      break;

    case DMA_CHANNEL_PRIORITY_HIGH:
      syn_set_register_bits(reg, mask, DMA_CCR_PL_HIGH << shift);
      break;

    case DMA_CHANNEL_PRIORITY_VERY_HIGH:
      syn_set_register_bits(reg, mask, DMA_CCR_PL_VERY_HIGH << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma_channel_priority, priority);
      break;
  }
}

void
dma_channel_mem2mem_mode_enable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR |= DMA_CCR_MEM2MEM;
}

void
dma_channel_mem2mem_mode_disable(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CCR &= ~DMA_CCR_MEM2MEM;
}

void
dma_set_channel_transfer_items_count(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  u32 bytes_count
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  devmode_assert_lower_or_eq(bytes_count, DMA_CNDTR_NDT_MASK);

  constexpr u32 shift = DMA_CNDTR_NDT_SHIFT;
  constexpr u32 mask = DMA_CNDTR_NDT_MASK << shift;
  volatile u32* reg = &dma->channels[channel].CNDTR;

  syn_set_register_bits(reg, mask, bytes_count & mask);
}

u32
dma_get_channel_transfer_items_left(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  devmode_assert_lower_or_eq(bytes_count, DMA_CNDTR_NDT_MASK);
  return dma->channels[channel].CNDTR;
}

void
dma_channel_set_periph_address(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  u32 periph_address
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CPAR = periph_address;
}

void
dma_channel_set_memory_address(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  u32 memory_address
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CMAR = memory_address;
}
