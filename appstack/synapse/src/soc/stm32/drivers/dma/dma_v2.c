#include "synapse/soc/stm32/drivers/dma/dma_v2.h"
#include "libcom/util.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"
#include "synapse/soc/stm32/drivers/dma/dmaif.h"

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

  syn_set_register_bits(reg, mask, bytes_count);
}

u32
dma_get_channel_transfer_items_left(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  return dma->channels[channel].CNDTR;
}

void
dma_channel_set_periph_address(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  uptr periph_address
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CPAR = (u32) periph_address;
}

void
dma_channel_set_memory_address(
  volatile struct dma_registers_map* dma,
  enum dma_channel channel,
  uptr memory_address
)
{
  devmode_assert_lower_or_eq(channel, DMA_CHANNEL7);
  dma->channels[channel].CMAR = (u32) memory_address;
}

 /*
 * Driver interface implementation.
 */

u32
dmaif_get_capabilities(void)
{
  u32 caps = 0;
  caps |= DMAIF_CAP_CIRCULAR;
  caps |= DMAIF_CAP_MEM_INC_MODE;
  caps |= DMAIF_CAP_PERIPH_INC_MODE;

  caps |= DMAIF_CAP_MEM_16bit_WIDE;
  caps |= DMAIF_CAP_MEM_32bit_WIDE;

  caps |= DMAIF_CAP_PERIPH_16bit_WIDE;
  caps |= DMAIF_CAP_PERIPH_32bit_WIDE;
  
  caps |= DMAIF_CAP_MEM_BURST1;
  caps |= DMAIF_CAP_PERIPH_BURST1;

  caps |= DMAIF_CAP_PRIORITY;
  return caps;
}

u32
dmaif_is_capability_supported(
  enum dmaif_capability cap
)
{
  return dmaif_get_capabilities() & cap;
} 

static u32
_map_priorityif(
  enum dmaif_priority priorityif,
  enum dma_channel_priority* priority
)
{
  switch (priorityif)
  {
    case DMAIF_PRIORITY_LOW:
      *priority = DMA_CHANNEL_PRIORITY_LOW;
      break;

    case DMAIF_PRIORITY_MEDIUM:
      *priority = DMA_CHANNEL_PRIORITY_MEDIUM;
      break;

    case DMAIF_PRIORITY_HIGH:
      *priority = DMA_CHANNEL_PRIORITY_HIGH;
      break;

    case DMAIF_PRIORITY_VERY_HIGH:
      *priority = DMA_CHANNEL_PRIORITY_VERY_HIGH;
      break;

    default:
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

static u32
_map_msizeif(
  enum dmaif_data dataif,
  enum dma_memory_size* msize
)
{
  switch (dataif)
  {
    case DMAIF_DATA_8bit:
      *msize = DMA_MEMORY_SIZE_8BITS;
      break;

    case DMAIF_DATA_16bit:
      *msize = DMA_MEMORY_SIZE_16BITS;
      break;

    case DMAIF_DATA_32bit:
      *msize = DMA_MEMORY_SIZE_32BITS;
      break;

    default:
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

static u32
_map_psizeif(
  enum dmaif_data dataif,
  enum dma_periph_size* psize
)
{
  switch (dataif)
  {
    case DMAIF_DATA_8bit:
      *psize = DMA_PERIPH_SIZE_8BITS;
      break;

    case DMAIF_DATA_16bit:
      *psize = DMA_PERIPH_SIZE_16BITS;
      break;

    case DMAIF_DATA_32bit:
      *psize = DMA_PERIPH_SIZE_32BITS;
      break;

    default:
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}


enum dmaif_code
dmaif_configure(
  struct dmaif_config* config
)
{
  if (!config->dma)
  {
    return DMAIF_CODE_INVALID_HW;
  }

  enum dma_channel_priority priority;
  if (_map_priorityif(config->priority, &priority) != NEX_SUCCESS)
  {
    return DMAIF_CODE_INVALID_PRIORITY;
  }

  dma_channel_set_priority_level(config->dma, config->channel, priority);

  enum dma_memory_size msize;
  if (_map_msizeif(config->msize, &msize) != NEX_SUCCESS)
  {
    return DMAIF_CODE_INVALID_MEM_DATA_SIZE;
  }

  dma_channel_set_memory_size(config->dma, config->channel, msize);

  enum dma_periph_size psize;
  if (_map_psizeif(config->psize, &psize) != NEX_SUCCESS)
  {
    return DMAIF_CODE_INVALID_PERIPH_MEM_DATA_SIZE;
  }

  dma_channel_set_periph_size(config->dma, config->channel, psize);

  if (config->options & DMAIF_CAP_MEM_INC_MODE)
  {
    dma_channel_memory_increment_mode_enable(config->dma, config->channel);
  }
  else
  {
    dma_channel_memory_increment_mode_disable(config->dma, config->channel);
  }

  if (config->options & DMAIF_CAP_PERIPH_INC_MODE)
  {
    dma_channel_periph_increment_mode_enable(config->dma, config->channel);
  }
  else
  {
    dma_channel_periph_increment_mode_disable(config->dma, config->channel);
  }

  if (config->options & DMAIF_CAP_CIRCULAR)
  {
    dma_channel_circular_mode_enable(config->dma, config->channel);
  }
  else
  {
    dma_channel_circular_mode_disable(config->dma, config->channel);
  }

  switch (config->direction)
  {
    case DMAIF_DIR_MEM2PERIPH:
      dma_channel_set_data_transfer_direction(
        config->dma,
        config->channel,
        DMA_TRANSFER_DIRECTION_FROM_MEMORY
      );
      dma_channel_mem2mem_mode_disable(config->dma, config->channel);
      break;

    case DMAIF_DIR_PERIPH2MEM:
      dma_channel_set_data_transfer_direction(
        config->dma,
        config->channel,
        DMA_TRANSFER_DIRECTION_FROM_PERIPH
      );
      dma_channel_mem2mem_mode_disable(config->dma, config->channel);
      break;

    case DMAIF_DIR_MEM2MEM:
      dma_channel_set_data_transfer_direction(
        config->dma,
        config->channel,
        DMA_TRANSFER_DIRECTION_FROM_MEMORY
      );
      dma_channel_mem2mem_mode_enable(config->dma, config->channel);
      break;

    default:
      return DMAIF_CODE_INVALID_DIR;
  }

  dma_set_channel_transfer_items_count(
    config->dma,
    config->channel,
    config->items_count
  );

  if (!config->periph_addr)
  {
    return DMAIF_CODE_INVALID_PERIPH_ADDR;
  }

  dma_channel_set_periph_address(
    config->dma,
    config->channel,
    config->periph_addr
  );

  if (!config->pbuf)
  {
    return DMAIF_CODE_INVALID_PBUF;
  }

  dma_channel_set_memory_address(
    config->dma,
    config->channel,
    (uptr) config->pbuf
  );

  return DMAIF_CODE_OK;
}

void
dmaif_set_mem_addr(
  struct dmaif_config* config,
  enum dmaif_memory mem,
  uptr addr
)
{
  if (mem != DMAIF_MEMORY0)
  {
    devmode_error_invalid_enum(enum dmaif_memory, mem);
    return;
  }

  dma_channel_set_memory_address(config->dma, config->channel, addr);
}

void
dmaif_set_items_count(
  struct dmaif_config* config,
  u32 count
)
{
  dma_set_channel_transfer_items_count(config->dma, config->channel, count);
}

u32
dmaif_get_items_count(
  struct dmaif_config* config
)
{
  return dma_get_channel_transfer_items_left(config->dma, config->channel);
}

void
dmaif_start_transfer(
  struct dmaif_config* config
)
{
  dma_channel_enable(config->dma, config->channel);
}

u32
dmaif_get_current_db_target(
  struct dmaif_config*
)
{
  return 0;
}
