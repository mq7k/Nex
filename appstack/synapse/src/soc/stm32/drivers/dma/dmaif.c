#include "synapse/soc/stm32/drivers/dma/dmaif.h"
#include "libcom/util.h"

// static u32
// _are_buffers_contiguous(
//   u8* pbuf,
//   u8* sbuf,
//   u32 len
// )
// {
//   return pbuf + len == sbuf;
// }

static u32
_get_periph_data_size(
  enum dmaif_periph periph
)
{
  switch (periph)
  {
    case DMAIF_PERIPH_USART:
      return 1u << DMAIF_DATA_8bit;

    case DMAIF_PERIPH_SPI:
      return (1u << DMAIF_DATA_8bit) | (1u << DMAIF_DATA_16bit);

    default:
      return 0;
  }
}

static u32
_get_periph_burst(
  enum dmaif_periph periph
)
{
  switch (periph)
  {
    case DMAIF_PERIPH_USART:
    case DMAIF_PERIPH_SPI:
      return 1u << DMAIF_PERIPH_BURST1;

    default:
      return 0;
  }
}

enum dmaif_code
dmaif_auto_config(
  struct dmaif_config* config,
  u32 enabled_caps
)
{
  constexpr u32 fifo_max_len = 16;

  // The user hasn't specified any configuration.
  // We are going to configure the peripheral
  // to the best possible state, exploiting
  // hardware features as much as we can,
  // unless they were explicitly disabled
  // by the user.
  // Note: config must have (at least)
  // a valid pbuf value.
  if (!config)
  {
    return DMAIF_CODE_INVALID_CFG;
  }

  if (!config->pbuf || !config->buf_len)
  {
    return DMAIF_CODE_INVALID_PBUF;
  }

  // TODO: Handle PINCOS bit.

  // We cannot make blind assumptions
  // about what the peripheral hardware
  // supports.
  if (
    config->periph == DMAIF_PERIPH_UNKNOWN &&
    config->direction != DMAIF_DIR_MEM2MEM
  )
  {
    return DMAIF_CODE_UNSUPPORTED_PERIPH;
  }

  // If the user hasn't specified a bytes count,
  // we assume the entire buffer is our workbench.
  if (config->bytes_count == 0)
  {
    config->bytes_count = config->buf_len;
  }

  // Supported capabilities by the current
  // DMA hardware.
  const u32 supported_caps = dmaif_get_capabilities();
  const u32 active_caps = supported_caps & enabled_caps;

  if (active_caps & DMAIF_CAP_DB)
  {
    if (config->sbuf)
    {
      // Feature not disabled, capability available
      // and the user has provided a secondary buffer.
      // We can use double buffer.
      config->options |= DMAIF_CAP_DB;

      if (active_caps & DMAIF_CAP_DB_HW_SWAP)
      {
        // stm32 circular mode is forced on
        // if double buffering (hardware) is enabled.
        // TODO: Handle this constrain on other MCUs.
        config->options |= DMAIF_CAP_CIRCULAR;
        config->options |= DMAIF_CAP_DB_HW_SWAP;
      }

      config->items_count = config->buf_len;
    }
    else
    {
      // The user hasn't specified a sbuf.
      // However, if we really want to, we could
      // split pbuf into two smaller buffers.
      // We achieve the same result.

      // If the buffer is too small, the manual split
      // is just not worth it.
      constexpr u32 min_buffer_len = 64;
      if (config->buf_len >= min_buffer_len)
      {
        const u32 split_size = (config->buf_len & ~1u) >> 1;
        config->sbuf = &config->pbuf[split_size];
        config->items_count = split_size;
        config->buf_len = split_size;
        config->options |= DMAIF_CAP_DB;

        if (active_caps & DMAIF_CAP_DB_HW_SWAP)
        {
          config->options |= DMAIF_CAP_DB_HW_SWAP;
        }
      }
    }
  }

  if (active_caps & DMAIF_CAP_CIRCULAR)
  {
    config->options |= DMAIF_CAP_CIRCULAR;
    config->items_count = config->buf_len;
  }

  if (active_caps & DMAIF_CAP_INC_OFFSET_32bit)
  {
    config->options |= DMAIF_CAP_INC_OFFSET_32bit;
  }

  if (active_caps & DMAIF_CAP_EXT_FLOW_CONTROLLER)
  {
    config->options |= DMAIF_CAP_EXT_FLOW_CONTROLLER;
  }

  u32 msize_width;
  u32 psize_width;

  // Periph data size.
  // The hardware can handle mismatches between
  // MSIZE and PSIZE, so, unless explicitly disabled,
  // we use the largest possible values to
  // reduce AHB usage.
  // For example:
  // - If PSIZE = 8bit and MSIZE = 32bit -> AHB usage is 75% less.
  // - If PSIZE = 16bit and MSIZE = 32bit -> AHB usage is 50% less.
  // Same concept applies if MSIZE = 8bit and PSIZE = 32bit.
  if (
    config->direction == DMAIF_DIR_MEM2PERIPH || 
    config->direction == DMAIF_DIR_PERIPH2MEM
  )
  {
    const u32 is_32bit_aligned = nex_is_addr_aligned(config->pbuf, sizeof(u32));
    const u32 is_16bit_aligned = nex_is_addr_aligned(config->pbuf, sizeof(u16));

    const u32 cap_periph32bit_bus = active_caps & DMAIF_CAP_PERIPH_32bit_WIDE;
    const u32 cap_periph16bit_bus = active_caps & DMAIF_CAP_PERIPH_16bit_WIDE;

    // This returns the access size
    // supported by the peripheral.
    const u32 supported_psize = 
      config->supported_psize ?
      config->supported_psize :
      _get_periph_data_size(config->periph);

    if (
      is_32bit_aligned && 
      cap_periph32bit_bus && 
      supported_psize & (1u << DMAIF_DATA_32bit)
    )
    {
      config->psize = DMAIF_DATA_32bit;
      psize_width = sizeof(u32);
    }
    else if (
      is_16bit_aligned &&
      cap_periph16bit_bus &&
      supported_psize & (1u << DMAIF_DATA_16bit)
    )
    {
      config->psize = DMAIF_DATA_16bit;
      psize_width = sizeof(u16);
    }
    else if (supported_psize & (1u << DMAIF_DATA_8bit))
    {
      config->psize = DMAIF_DATA_8bit;
      psize_width = sizeof(u8);
    }
    else
    {
      return DMAIF_CODE_UNSUPPORTED_PSIZE;
    }

    // We cannot transfer N bytes if N is not
    // a multiple of the peripheral natively supported
    // data size.
    // Manually adding padding would introduce
    // hidden behavior.
    if (FAST_MOD(config->bytes_count, psize_width) != 0)
    {
      return DMAIF_CODE_UNALIGNED_BYTES_COUNT;
    }

    // We have to make sure the buf_len is a multiple
    // of the basic data type we are attempting to transfer.
    // We may end up not using up to 3 bytes, but it's a price
    // we are willing to pay.
    config->buf_len = nex_align_addr(config->buf_len, psize_width);
  }

  // Memory data size.
  const u32 cap_mem32bit_bus = active_caps & DMAIF_CAP_MEM_32bit_WIDE;
  const u32 cap_mem16bit_bus = active_caps & DMAIF_CAP_MEM_16bit_WIDE;

  const u32 is_pbuf_32bit_aligned = nex_is_addr_aligned(config->pbuf, sizeof(u32));
  const u32 is_pbuf_16bit_aligned = nex_is_addr_aligned(config->pbuf, sizeof(u16));

  if (
    is_pbuf_32bit_aligned && cap_mem32bit_bus &&
    FAST_MOD(config->bytes_count, sizeof(u32)) == 0 &&
    (!(active_caps & DMAIF_CAP_DB) || nex_is_addr_aligned(config->sbuf, sizeof(u32)))
  )
  {
    config->msize = DMAIF_DATA_32bit;
    msize_width = 4;
  }
  else if (
    is_pbuf_16bit_aligned && cap_mem16bit_bus &&
    FAST_MOD(config->bytes_count, sizeof(u16)) == 0 &&
    (!(active_caps & DMAIF_CAP_DB) || nex_is_addr_aligned(config->sbuf, sizeof(u16)))
  )
  {
    config->msize = DMAIF_DATA_16bit;
    msize_width = 2;
  }
  else
  {
    config->msize = DMAIF_DATA_8bit;
    msize_width = 1;
  }

  if (config->direction == DMAIF_DIR_MEM2MEM)
  {
    // The name is misleading.
    // In mem2mem mode, psize is the source address.
    // We match what msize is, since the memory
    // can produce data as fast as it can consume it.
    config->psize = config->msize;
    psize_width = msize_width;
  }
  else if (msize_width != psize_width)
  {
    if (active_caps & DMAIF_CAP_FIFO)
    {
      // The FIFO must be enabled in case
      // of a data width mismatch to allow
      // the hardware to perform data
      // packing/unpacking.
      config->options |= DMAIF_CAP_FIFO;
    }
    else
    {
      // If the FIFO cap is disabled,
      // we revert back to matching
      // msize and psize. We don't require
      // the FIFO anymore.
      config->msize = config->psize;
      msize_width = psize_width;
    }
  }

  // Now we can calculate items_count.
  enum dmaif_data src_size;
  enum dmaif_data dst_size;
  if (config->direction == DMAIF_DIR_MEM2PERIPH)
  {
    src_size = config->msize;
    dst_size = config->psize;
  }
  else
  {
    // PSIZE is the source address in any other direction.
    src_size = config->psize;
    dst_size = config->msize;
  }

  if (!(active_caps & DMAIF_CAP_CIRCULAR))
  {
    switch (src_size)
    {
      case DMAIF_DATA_8bit:
        config->items_count = config->bytes_count;
        break;
        
      case DMAIF_DATA_16bit:
        config->items_count = config->bytes_count >> 1;
        break;

      case DMAIF_DATA_32bit:
        config->items_count = config->bytes_count >> 2;
        break;
    }
  }

  // Lastly, we make sure the formula:
  // (src::size * items_count) % dst::size
  // is valid.
  // bytes_count = src::size * items_count.
  // This should technically be always 0,
  // since we have already checked those conditions.
  u32 res = config->bytes_count % dst_size;
  if (res != 0)
  {
    return DMAIF_CODE_UNALIGNED_BYTES_COUNT;
  }

  // Memory burst configuration.
  // Constrains:
  // - psize_width * burst >= config->bytes_count.
  //   - There must be enough bytes to transfer.
  // - psize_width (bytes) * bursts <= FIFO size (16 bytes).
  //   - The FIFO must have enough space for the entire burst.
  u32 mburst;

  if (
    active_caps & DMAIF_CAP_MEM_BURST16 &&
    FAST_MOD(config->bytes_count, 16) == 0 &&
    msize_width * 16 <= config->bytes_count &&
    msize_width * 16 <= fifo_max_len
  )
  {
    config->mem_burst = DMAIF_MEM_BURST16;
    mburst = 16;
  }
  else if (
    active_caps & DMAIF_CAP_MEM_BURST8 &&
    FAST_MOD(config->bytes_count, 8) == 0 &&
    msize_width * 8 <= config->bytes_count &&
    msize_width * 8 <= fifo_max_len
  )
  {
    config->mem_burst = DMAIF_MEM_BURST8;
    mburst = 8;
  }
  else if (
    active_caps & DMAIF_CAP_MEM_BURST4 &&
    FAST_MOD(config->bytes_count, 4) == 0 &&
    msize_width * 4 <= config->bytes_count &&
    msize_width * 4 <= fifo_max_len
  )
  {
    config->mem_burst = DMAIF_MEM_BURST4;
    mburst = 4;
  }
  else if (active_caps & DMAIF_CAP_MEM_BURST1)
  {
    config->mem_burst = DMAIF_MEM_BURST1;
    mburst = 1;
  }
  else
  {
    return DMAIF_CODE_UNSUPPORTED_MSIZE;
  }

  // Periph burst configuration.
  u32 pburst;
  const u32 supported_burst = 
    config->supported_pburst ?
    config->supported_pburst :
    _get_periph_burst(config->periph);

  if (
    active_caps & DMAIF_CAP_PERIPH_BURST16 &&
    supported_burst & (1u << DMAIF_PERIPH_BURST16) &&
    psize_width * 16 <= fifo_max_len &&
    FAST_MOD(psize_width * 16, fifo_max_len) == 0 
  )
  {
    config->periph_burst = DMAIF_PERIPH_BURST16;
    pburst = 16;
  }
  else if (
    active_caps & DMAIF_CAP_PERIPH_BURST8 &&
    supported_burst & (1u << DMAIF_PERIPH_BURST8) &&
    psize_width * 8 <= fifo_max_len &&
    FAST_MOD(psize_width * 8, fifo_max_len) == 0
  )
  {
    config->periph_burst = DMAIF_PERIPH_BURST8;
    pburst = 8;
  }
  else if (
    active_caps & DMAIF_CAP_PERIPH_BURST4 &&
    supported_burst & (1u << DMAIF_PERIPH_BURST4) &&
    psize_width * 4 <= fifo_max_len &&
    FAST_MOD(psize_width * 4, fifo_max_len) == 0
  )
  {
    config->periph_burst = DMAIF_PERIPH_BURST4;
    pburst = 4;
  }
  else if (
    active_caps & DMAIF_CAP_PERIPH_BURST1 &&
    supported_burst & (1u << DMAIF_PERIPH_BURST1)
  )
  {
    config->periph_burst = DMAIF_PERIPH_BURST1;
    pburst = 1;
  }
  else
  {
    return DMAIF_CODE_UNSUPPORTED_PBURST;
  }

  // FIFO threshold.
  // We have to configure the threshold
  // to make sure the FIFO has enough data
  // to perform at least one burst.
  // The threshold must satisfy:
  // (burst * size) % threshold == 0
  // where `burst` and `size` are mburst/pburst
  // and msize/psize, according to the draining side.

  const enum dmaif_capability supported_thresholds[] = {
    DMAIF_CAP_FIFO_THRS_FULL,
    DMAIF_CAP_FIFO_THRS_3over4,
    DMAIF_CAP_FIFO_THRS_1over2,
    DMAIF_CAP_FIFO_THRS_1over4
  };
  constexpr u32 st_len = ARR_SIZE(supported_thresholds);
  u32 burst;
  u32 size_width;

  if (config->direction == DMAIF_DIR_PERIPH2MEM)
  {
    burst = mburst;
    size_width = psize_width;
  }
  else
  {
    burst = pburst;
    size_width = psize_width;
  }

  if (
    burst * size_width >= fifo_max_len ||
    FAST_MOD(fifo_max_len, burst * size_width) != 0
  )
  {
    return DMAIF_CODE_UNSUPPORTED_FIFO_THRESHOLD;
  }

  // We start from the largest possible threshold
  // and proceed to the lowest.
  u32 found = 0;
  for (u32 i = 0; i < st_len; ++i)
  {
    if (active_caps & supported_thresholds[i])
    {
      config->fifo_threshold = supported_thresholds[i];
      found = 1;
      break;
    }
  }

  if (!found)
  {
    return DMAIF_CODE_UNSUPPORTED_FIFO_THRESHOLD;
  }

  // Memory increment.
  if (active_caps & DMAIF_CAP_MEM_INC_MODE && config->bytes_count > 1)
  {
    config->options |= DMAIF_CAP_MEM_INC_MODE;
  }

  if (active_caps & DMAIF_CAP_PERIPH_INC_MODE)
  {
    config->options |= DMAIF_CAP_PERIPH_INC_MODE;
  }

  if (active_caps & DMAIF_CAP_PRIORITY)
  {
    if (config->priority)
    {
      config->priority = config->priority;
    }
    else
    {
      config->priority = DMAIF_PRIORITY_VERY_HIGH;
    }
  }

  return dmaif_configure(config);
}

