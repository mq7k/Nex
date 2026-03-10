#include "synapse/stm32/drivers/dma2d/dma2d_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct dma2d_registers_map dma2d_periph;
dma2d_periph* DMA2D = (dma2d_periph*) (DMA2D_ADDR);

void
dma2d_start(void)
{
  DMA2D->CR |= DMA2D_CR_START;
}

void
dma2d_suspend(void)
{
  DMA2D->CR |= DMA2D_CR_SUSP;
}

void
dma2d_abort(void)
{
  DMA2D->CR |= DMA2D_CR_ABORT;
}

void
dma2d_interrupt_enable(
  enum dma2d_interrupt interrupt
)
{
  volatile u32* reg = &DMA2D->CR;
  switch (interrupt)
  {
    case DMA2D_INTERRUPT_TRANSFER_ERROR:
      *reg |= DMA2D_CR_TEIE;
      break;

    case DMA2D_INTERRUPT_TRANSFER_COMPLETE:
      *reg |= DMA2D_CR_TCIE;
      break;

    case DMA2D_INTERRUPT_TRANSFER_WATERMARK:
      *reg |= DMA2D_CR_TWIE;
      break;

    case DMA2D_INTERRUPT_CLUT_ACCESS_ERROR:
      *reg |= DMA2D_CR_CAEIE;
      break;

    case DMA2D_INTERRUPT_CLUT_TRANSFER_COMPLETE:
      *reg |= DMA2D_CR_CTCIE;
      break;

    case DMA2D_INTERRUPT_CONFIGURATION_ERROR:
      *reg |= DMA2D_CR_CEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_interrupt, interrupt);
      break;
  }
}

void
dma2d_interrupt_disable(
  enum dma2d_interrupt interrupt
)
{
  volatile u32* reg = &DMA2D->CR;
  switch (interrupt)
  {
    case DMA2D_INTERRUPT_TRANSFER_ERROR:
      *reg &= ~DMA2D_CR_TEIE;
      break;

    case DMA2D_INTERRUPT_TRANSFER_COMPLETE:
      *reg &= ~DMA2D_CR_TCIE;
      break;

    case DMA2D_INTERRUPT_TRANSFER_WATERMARK:
      *reg &= ~DMA2D_CR_TWIE;
      break;

    case DMA2D_INTERRUPT_CLUT_ACCESS_ERROR:
      *reg &= ~DMA2D_CR_CAEIE;
      break;

    case DMA2D_INTERRUPT_CLUT_TRANSFER_COMPLETE:
      *reg &= ~DMA2D_CR_CTCIE;
      break;

    case DMA2D_INTERRUPT_CONFIGURATION_ERROR:
      *reg &= ~DMA2D_CR_CEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_interrupt, interrupt);
      break;
  }
}

void
dma2d_set_mode(
  enum dma2d_mode mode
)
{
  constexpr u32 shift = DMA2D_CR_MODE_SHIFT;
  constexpr u32 mask = DMA2D_CR_MODE_MASK << shift;
  volatile u32* reg = &DMA2D->CR;

  switch (mode)
  {
    case DMA2D_MODE_MEMORY_TO_MEMORY_FG:
      *reg &= ~mask;
      break;

    case DMA2D_MODE_MEMORY_TO_MEMORY_PFC:
      syn_set_register_bits(reg, mask, DMA2D_CR_MODE_MEM2MEM_PFC << shift);
      break;

    case DMA2D_MODE_MEMORY_TO_MEMORY_BLENDING:
      syn_set_register_bits(reg, mask, DMA2D_CR_MODE_MEM2MEM_BLEND << shift);
      break;

    case DMA2D_MODE_REGISTER_TO_MEMORY:
      *reg |= (DMA2D_CR_MODE_REG2MEM << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_mode, mode);
      break;
  }
}

u32
dma2d_is_flag_set(
  enum dma2d_flag flag
)
{
  volatile u32* reg = &DMA2D->ISR;
  switch (flag)
  {
    case DMA2D_FLAG_TRANSFER_ERROR:
      return *reg & DMA2D_ISR_TEIF;
      
    case DMA2D_FLAG_TRANSFER_COMPLETE:
      return *reg & DMA2D_ISR_TCIF;

    case DMA2D_FLAG_TRANSFER_WATERMARK:
      return *reg & DMA2D_ISR_TWIF;

    case DMA2D_FLAG_CLUT_ACCESS_ERROR:
      return *reg & DMA2D_ISR_CAEIF;

    case DMA2D_FLAG_CLUT_TRANSFER_COMPLETE:
      return *reg & DMA2D_ISR_CTCIF;

    case DMA2D_FLAG_CONFIGURATION_ERROR:
      return *reg & DMA2D_ISR_CEIF;

    default:
      devmode_error_invalid_enum(enum dma2d_flag, flag);
      return 0;
  }
}

void
dma2d_flag_clear(
  enum dma2d_flag flag
)
{
  volatile u32* reg = &DMA2D->IFCR;
  switch (flag)
  {
    case DMA2D_FLAG_TRANSFER_ERROR:
      *reg |= DMA2D_IFCR_CTEIF;
      break;

    case DMA2D_FLAG_TRANSFER_COMPLETE:
      *reg |= DMA2D_IFCR_CTCIF;
      break;

    case DMA2D_FLAG_TRANSFER_WATERMARK:
      *reg |= DMA2D_IFCR_CTWIF;
      break;

    case DMA2D_FLAG_CLUT_ACCESS_ERROR:
      *reg |= DMA2D_IFCR_CAECIF;
      break;

    case DMA2D_FLAG_CLUT_TRANSFER_COMPLETE:
      *reg |= DMA2D_IFCR_CCTCIF;
      break;

    case DMA2D_FLAG_CONFIGURATION_ERROR:
      *reg |= DMA2D_IFCR_CCEIF;
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_flag, flag);
      break;
  }
}

void
dma2d_set_fg_memory_address(
  u32 address
)
{
  DMA2D->FGMAR = address;
}

void
dma2d_set_fg_line_offset(
  u32 offset
)
{
  devmode_assert_lower_or_eq(offset, DMA2D_FGOR_LO_MASK);
  constexpr u32 shift = DMA2D_FGOR_LO_SHIFT;
  constexpr u32 mask = DMA2D_FGOR_LO_MASK << shift;
  volatile u32* reg = &DMA2D->FGOR;
  syn_set_register_bits(reg, mask, offset << shift);
}

void
dma2d_set_bg_memory_address(
  u32 address
)
{
  DMA2D->BGMAR = address;
}

void
dma2d_set_bg_img_offset(
  u32 offset
)
{
  devmode_assert_lower_or_eq(offset, DMA2D_BGOR_LO_MASK);
  constexpr u32 shift = DMA2D_BGOR_LO_SHIFT;
  constexpr u32 mask = DMA2D_BGOR_LO_MASK << shift;
  volatile u32* reg = &DMA2D->BGOR;
  syn_set_register_bits(reg, mask, offset);
}

void
dma2d_set_fg_color_mode(
  enum dma2d_fg_color_mode mode
)
{
  constexpr u32 shift = DMA2D_FGPFCCR_CM_SHIFT;
  constexpr u32 mask = DMA2D_FGPFCCR_CM_MASK << shift;
  volatile u32* reg = &DMA2D->FGPFCCR;

  switch (mode)
  {
    case DMA2D_FG_COLOR_MODE_ARGB8888:
      *reg &= ~mask;
      break;

    case DMA2D_FG_COLOR_MODE_RGB888:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_RGB888 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_RGB565:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_RGB565 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_ARGB1555:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_ARGB1555 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_ARGB4444:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_ARGB4444 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_L8:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_L8 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_AL44:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_AL44 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_AL88:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_AL88 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_L4:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_L4 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_A8:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_A8 << shift);
      break;

    case DMA2D_FG_COLOR_MODE_A4:
      syn_set_register_bits(reg, mask, DMA2D_FGPFCCR_CM_A4 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_fg_color_mode, mode);
      break;
  }
}

void
dma2d_set_fg_clut_color_mode(
  enum dma2d_fg_clut_color_mode mode
)
{
  volatile u32* reg = &DMA2D->FGPFCCR;
  switch (mode)
  {
    case DMA2D_FG_CLUT_COLOR_MODE_ARGB8888:
      *reg &= ~DMA2D_FGPFCCR_CCM;
      break;

    case DMA2D_FG_CLUT_COLOR_MODE_RGB888:
      *reg |= DMA2D_FGPFCCR_CCM;
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_fg_clut_color_mode, mode);
      break;
  }
}

void
dma2d_fg_start(void)
{
  DMA2D->FGPFCCR |= DMA2D_FGPFCCR_START;
}

void
dma2d_set_fg_clut_size(
  u32 size
)
{
  devmode_assert_lower_or_eq(size, DMA2D_FGPFCCR_CS_MASK);
  constexpr u32 shift = DMA2D_FGPFCCR_CS_SHIFT;
  constexpr u32 mask = DMA2D_FGPFCCR_CS_MASK << shift;
  volatile u32* reg = &DMA2D->FGPFCCR;
  syn_set_register_bits(reg, mask, size << shift);
}

void
dma2d_set_fg_alpha_mode(
  enum dma2d_fg_alpha_mode mode
)
{
  constexpr u32 shift = DMA2D_FGPFCCR_AM_SHIFT;
  constexpr u32 mask = DMA2D_FGPFCCR_AM_MASK << shift;
  volatile u32* reg = &DMA2D->FGPFCCR;

  switch (mode)
  {
    case DMA2D_FG_ALPHA_MODE_NOMOD:
      *reg &= ~mask;
      break;

    case DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA:
      syn_set_register_bits(
        reg,
        mask,
        DMA2D_FGPFCCR_AM_REPL_FG_W_ALPHA_CH << shift
      );
      break;

    case DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA_MUL:
      syn_set_register_bits(
        reg,
        mask,
        DMA2D_FGPFCCR_AM_REPL_FG_W_ALPHA_CHx_ALPHA << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_fg_alpha_mode, mode);
      break;
  }
}

void
dma2d_set_fg_pfc_alpha_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, DMA2D_FGPFCCR_ALPHA_MASK);
  constexpr u32 shift = DMA2D_FGPFCCR_ALPHA_SHIFT;
  constexpr u32 mask = DMA2D_FGPFCCR_ALPHA_MASK << shift;
  volatile u32* reg = &DMA2D->FGPFCCR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
dma2d_set_fg_color_channel_value(
  enum dma2d_rgb888_color_channel channel,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg;

  switch (channel)
  {
    case DMA2D_RGB888_COLOR_CHANNEL_RED:
      shift = DMA2D_FGCOLR_RED_SHIFT;
      mask = DMA2D_FGCOLR_RED_MASK << shift;
      reg = &DMA2D->FGCOLR;
      devmode_assert_lower_or_eq(value, DMA2D_FGCOLR_RED_MASK);
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB888_COLOR_CHANNEL_GREEN:
      shift = DMA2D_FGCOLR_GREEN_SHIFT;
      mask = DMA2D_FGCOLR_GREEN_MASK << shift;
      reg = &DMA2D->FGCOLR;
      devmode_assert_lower_or_eq(value, DMA2D_FGCOLR_GREEN_MASK);
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB888_COLOR_CHANNEL_BLUE:
      shift = DMA2D_FGCOLR_BLUE_SHIFT;
      mask = DMA2D_FGCOLR_BLUE_MASK << shift;
      reg = &DMA2D->FGCOLR;
      devmode_assert_lower_or_eq(value, DMA2D_FGCOLR_BLUE_MASK);
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_color_channel, channel);
      break;
  }
}

void
dma2d_set_bg_color_mode(
  enum dma2d_bg_color_mode mode
)
{
  constexpr u32 shift = DMA2D_BGPFCCR_CM_SHIFT;
  constexpr u32 mask = DMA2D_BGPFCCR_CM_MASK << shift;
  volatile u32* reg = &DMA2D->BGPFCCR;

  switch (mode)
  {
    case DMA2D_BG_COLOR_MODE_ARGB8888:
      *reg &= ~mask;
      break;

    case DMA2D_BG_COLOR_MODE_RGB888:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_RGB888 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_RGB565:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_RGB565 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_ARGB1555:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_ARGB1555 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_ARGB4444:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_ARGB4444 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_L8:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_L8 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_AL44:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_AL44 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_AL88:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_AL88 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_L4:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_L4 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_A8:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_A8 << shift);
      break;

    case DMA2D_BG_COLOR_MODE_A4:
      syn_set_register_bits(reg, mask, DMA2D_BGPFCCR_CM_A4 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_bg_color_mode, mode);
      break;
  }
}

void
dma2d_set_bg_clut_color_mode(
  enum dma2d_bg_clut_color_mode mode
)
{
  volatile u32* reg = &DMA2D->BGPFCCR;
  switch (mode)
  {
    case DMA2D_BG_CLUT_COLOR_MODE_ARGB8888:
      *reg &= ~DMA2D_BGPFCCR_CCM;
      break;

    case DMA2D_BG_CLUT_COLOR_MODE_RGB888:
      *reg |= DMA2D_BGPFCCR_CCM;
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_bg_clut_color_mode, mode);
      break;
  }
}

void
dma2d_bg_start(void)
{
  DMA2D->BGPFCCR |= DMA2D_BGPFCCR_START;
}

void
dma2d_set_bg_clut_size(
  u32 size
)
{
  devmode_assert_lower_or_eq(size, DMA2D_BGPFCCR_CS_MASK);
  constexpr u32 shift = DMA2D_BGPFCCR_CS_SHIFT;
  constexpr u32 mask = DMA2D_BGPFCCR_CS_MASK << shift;
  volatile u32* reg = &DMA2D->BGPFCCR;
  syn_set_register_bits(reg, mask, size << shift);
}

void
dma2d_set_bg_pfc_alpha_mode(
  enum dma2d_bg_alpha_mode mode
)
{
  constexpr u32 shift = DMA2D_BGPFCCR_AM_SHIFT;
  constexpr u32 mask = DMA2D_BGPFCCR_AM_MASK << shift;
  volatile u32* reg = &DMA2D->BGPFCCR;

  switch (mode)
  {
    case DMA2D_BG_ALPHA_MODE_NOMOD:
      *reg &= ~mask;
      break;

    case DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA:
      syn_set_register_bits(
        reg,
        mask,
        DMA2D_BGPFCCR_AM_REPL_FG_W_ALPHA_CH << shift
      );
      break;

    case DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA_MUL:
      syn_set_register_bits(
        reg,
        mask,
        DMA2D_BGPFCCR_AM_REPL_FG_W_ALPHA_CHx_ALPHA << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_bg_alpha_mode, mode);
      break;
  }
}

void
dma2d_set_bg_pfc_alpha_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, DMA2D_BGPFCCR_ALPHA_MASK);
  constexpr u32 shift = DMA2D_BGPFCCR_ALPHA_SHIFT;
  constexpr u32 mask = DMA2D_BGPFCCR_ALPHA_MASK << shift;
  volatile u32* reg = &DMA2D->BGPFCCR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
dma2d_set_bg_color_channel_value(
  enum dma2d_rgb888_color_channel channel,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg;

  switch (channel)
  {
    case DMA2D_RGB888_COLOR_CHANNEL_RED:
      devmode_assert_lower_or_eq(value, DMA2D_BGCOLR_RED_MASK);
      shift = DMA2D_BGCOLR_RED_SHIFT;
      mask = DMA2D_BGCOLR_RED_MASK << shift;
      reg = &DMA2D->BGCOLR;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB888_COLOR_CHANNEL_GREEN:
      devmode_assert_lower_or_eq(value, DMA2D_BGCOLR_GREEN_MASK);
      shift = DMA2D_BGCOLR_GREEN_SHIFT;
      mask = DMA2D_BGCOLR_GREEN_MASK << shift;
      reg = &DMA2D->BGCOLR;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB888_COLOR_CHANNEL_BLUE:
      devmode_assert_lower_or_eq(value, DMA2D_BGCOLR_BLUE_MASK);
      shift = DMA2D_BGCOLR_BLUE_SHIFT;
      mask = DMA2D_BGCOLR_BLUE_MASK << shift;
      reg = &DMA2D->BGCOLR;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_color_channel, channel);
      break;
  }
}

void
dma2d_set_fg_clut_memory_address(
  u32 address
)
{
  DMA2D->FGCMAR = address;
}

void
dma2d_set_bg_clut_memory_address(
  u32 address
)
{
  DMA2D->BGCMAR = address;
}

void
dma2d_set_output_color_mode(
  enum dma2d_output_color_mode mode
)
{
  constexpr u32 shift = DMA2D_OPFCCR_CM_SHIFT;
  constexpr u32 mask = DMA2D_OPFCCR_CM_MASK << shift;
  volatile u32* reg = &DMA2D->OPFCCR;
  switch (mode)
  {
    case DMA2D_OUTPUT_COLOR_MODE_ARGB8888:
      *reg &= ~mask;
      break;

    case DMA2D_OUTPUT_COLOR_MODE_RGB888:
      syn_set_register_bits(reg, mask, DMA2D_OPFCCR_CM_RGB888 << shift);
      break;

    case DMA2D_OUTPUT_COLOR_MODE_RGB565:
      syn_set_register_bits(reg, mask, DMA2D_OPFCCR_CM_RGB565 << shift);
      break;

    case DMA2D_OUTPUT_COLOR_MODE_ARGB1555:
      syn_set_register_bits(reg, mask, DMA2D_OPFCCR_CM_ARGB1555 << shift);
      break;

    case DMA2D_OUTPUT_COLOR_MODE_ARGB4444:
      syn_set_register_bits(reg, mask, DMA2D_OPFCCR_CM_ARGB4444 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_output_color_mode, mode);
      break;
  }
}

void
dma2d_set_argb8888_output_color(
  u32 color
)
{
  DMA2D->OCOLR = color;
}

void
dma2d_set_argb8888_output_color_channel_value(
  enum dma2d_argb8888_color_channel channel,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DMA2D->OCOLR;

  switch (channel)
  {
    case DMA2D_ARGB8888_COLOR_CHANNEL_RED:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB8888_RED_MASK);
      shift = DMA2D_OCOLR_ARGB8888_RED_SHIFT;
      mask = DMA2D_OCOLR_ARGB8888_RED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB8888_COLOR_CHANNEL_GREEN:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB8888_GREEN_MASK);
      shift = DMA2D_OCOLR_ARGB8888_GREEN_SHIFT;
      mask = DMA2D_OCOLR_ARGB8888_GREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB8888_COLOR_CHANNEL_BLUE:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB8888_BLUE_MASK);
      shift = DMA2D_OCOLR_ARGB8888_BLUE_SHIFT;
      mask = DMA2D_OCOLR_ARGB8888_BLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB8888_ALPHA_MASK);
      shift = DMA2D_OCOLR_ARGB8888_ALPHA_SHIFT;
      mask = DMA2D_OCOLR_ARGB8888_ALPHA_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_color_channel, channel);
      break;
  }
}

void
dma2d_set_rgb8888_output_color(
  u32 color
)
{
  devmode_assert_lower_or_eq(color, DMA2D_OCOLR_RGB888_MASK);
  constexpr u32 shift = DMA2D_OCOLR_RGB888_SHIFT;
  DMA2D->OCOLR = color << shift;
}

void
dma2d_set_rgb888_output_color_channel_value(
  enum dma2d_rgb888_color_channel channel,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, DMA2D_OCOLR_RGB888_COLOR_MAX_VAL);
  u32 shift;
  u32 mask;
  volatile u32* reg = &DMA2D->OCOLR;

  switch (channel)
  {
    case DMA2D_RGB888_COLOR_CHANNEL_RED:
      shift = DMA2D_OCOLR_RGB888_RED_SHIFT;
      mask = DMA2D_OCOLR_RGB888_RED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB888_COLOR_CHANNEL_GREEN:
      shift = DMA2D_OCOLR_RGB888_GREEN_SHIFT;
      mask = DMA2D_OCOLR_RGB888_GREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB888_COLOR_CHANNEL_BLUE:
      shift = DMA2D_OCOLR_RGB888_BLUE_SHIFT;
      mask = DMA2D_OCOLR_RGB888_BLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_rgb888_color_channel, channel);
      break;
  }
}

void
dma2d_set_rgb565_output_color(
  u32 color
)
{
  devmode_assert_lower_or_eq(color, DMA2D_OCOLR_RGB565_MASK);
  constexpr u32 shift = DMA2D_OCOLR_RGB565_SHIFT;
  constexpr u32 mask = DMA2D_OCOLR_RGB565_MASK << shift;
  volatile u32* reg = &DMA2D->OCOLR;
  syn_set_register_bits(reg, mask, color << shift);
}

void
dma2d_set_rgb565_output_color_channel_value(
  enum dma2d_rgb565_color_channel channel,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DMA2D->OCOLR;

  switch (channel)
  {
    case DMA2D_RGB565_COLOR_CHANNEL_BLUE:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_RGB565_BLUE_MASK);
      shift = DMA2D_OCOLR_RGB565_BLUE_SHIFT;
      mask = DMA2D_OCOLR_RGB565_BLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB565_COLOR_CHANNEL_GREEN:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_RGB565_GREEN_MASK);
      shift = DMA2D_OCOLR_RGB565_GREEN_SHIFT;
      mask = DMA2D_OCOLR_RGB565_GREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_RGB565_COLOR_CHANNEL_RED:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_RGB565_RED_MASK);
      shift = DMA2D_OCOLR_RGB565_GREEN_SHIFT;
      mask = DMA2D_OCOLR_RGB565_GREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_rgb565_color_channel, channel);
      break;
  }
}

void
dma2d_set_argb1555_output_color(
  u32 color
)
{
  devmode_assert_lower_or_eq(color, DMA2D_OCOLR_ARGB1555_MASK);
  constexpr u32 shift = DMA2D_OCOLR_ARGB1555_SHIFT;
  constexpr u32 mask = DMA2D_OCOLR_ARGB1555_MASK << shift;
  volatile u32* reg = &DMA2D->OCOLR;
  syn_set_register_bits(reg, mask, color << shift);
}

void
dma2d_set_argb1555_output_color_channel_value(
  enum dma2d_argb1555_color_channel channel,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DMA2D->OCOLR;

  switch (channel)
  {
    case DMA2D_ARGB1555_COLOR_CHANNEL_BLUE:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB1555_BLUE_MASK);
      shift = DMA2D_OCOLR_ARGB1555_BLUE_SHIFT;
      mask = DMA2D_OCOLR_ARGB1555_BLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB1555_COLOR_CHANNEL_GREEN:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB1555_GREEN_MASK);
      shift = DMA2D_OCOLR_ARGB1555_GREEN_SHIFT;
      mask = DMA2D_OCOLR_ARGB1555_GREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB1555_COLOR_CHANNEL_RED:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB1555_RED_MASK);
      shift = DMA2D_OCOLR_ARGB1555_RED_SHIFT;
      mask = DMA2D_OCOLR_ARGB1555_RED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB1555_COLOR_CHANNEL_ALPHA:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB1555_A_MASK);
      shift = DMA2D_OCOLR_ARGB1555_A_SHIFT;
      mask = DMA2D_OCOLR_ARGB1555_A_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_argb1555_color_channel, channel);
      break;
  }
}

void
dma2d_set_argb4444_output_color(
  u32 color
)
{
  devmode_assert_lower_or_eq(color, DMA2D_OCOLR_ARGB4444_MASK);
  constexpr u32 shift = DMA2D_OCOLR_ARGB4444_SHIFT;
  constexpr u32 mask = DMA2D_OCOLR_ARGB4444_MASK << shift;
  volatile u32* reg = &DMA2D->OCOLR;
  syn_set_register_bits(reg, mask, color << shift);
}

void
dma2d_set_argb4444_output_color_channel_value(
  enum dma2d_argb4444_color_channel channel,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DMA2D->OCOLR;
  switch (channel)
  {
    case DMA2D_ARGB4444_COLOR_CHANNEL_BLUE:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB4444_BLUE_MASK);
      shift = DMA2D_OCOLR_ARGB4444_BLUE_SHIFT;
      mask = DMA2D_OCOLR_ARGB4444_BLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB4444_COLOR_CHANNEL_GREEN:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB4444_GREEN_MASK);
      shift = DMA2D_OCOLR_ARGB4444_GREEN_SHIFT;
      mask = DMA2D_OCOLR_ARGB4444_GREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB4444_COLOR_CHANNEL_RED:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB4444_RED_MASK);
      shift = DMA2D_OCOLR_ARGB4444_RED_SHIFT;
      mask = DMA2D_OCOLR_ARGB4444_RED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA:
      devmode_assert_lower_or_eq(value, DMA2D_OCOLR_ARGB4444_ALPHA_MASK);
      shift = DMA2D_OCOLR_ARGB4444_ALPHA_SHIFT;
      mask = DMA2D_OCOLR_ARGB4444_ALPHA_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dma2d_argb4444_color_channel, channel);
      break;
  }
}

void
dma2d_set_output_memory_address(
  u32 address
)
{
  DMA2D->OMAR = address;
}

void
dma2d_set_output_line_offset(
  u32 offset
)
{
  devmode_assert_lower_or_eq(offset, DMA2D_OOR_LO_MASK);
  constexpr u32 shift = DMA2D_OOR_LO_SHIFT;
  constexpr u32 mask = DMA2D_OOR_LO_MASK << shift;
  volatile u32* reg = &DMA2D->OOR;
  syn_set_register_bits(reg, mask, offset << shift);
}

void
dma2d_set_number_of_lines(
  u32 lines
)
{
  devmode_assert_lower_or_eq(lines, DMA2D_NLR_NL_MASK);
  constexpr u32 shift = DMA2D_NLR_NL_SHIFT;
  constexpr u32 mask = DMA2D_NLR_NL_MASK << shift;
  volatile u32* reg = &DMA2D->NLR;
  syn_set_register_bits(reg, mask, lines << shift);
}

void
dma2d_set_pixel_per_lines(
  u32 pixels
)
{
  devmode_assert_lower_or_eq(pixels, DMA2D_NLR_PL_MASK);
  constexpr u32 shift = DMA2D_NLR_PL_SHIFT;
  constexpr u32 mask = DMA2D_NLR_PL_MASK << shift;
  volatile u32* reg = &DMA2D->NLR;
  syn_set_register_bits(reg, mask, pixels << shift);
}

void
dma2d_set_line_watermark(
  u32 line
)
{
  devmode_assert_lower_or_eq(line, DMA2D_LWR_LW_MASK);
  constexpr u32 shift = DMA2D_LWR_LW_SHIFT;
  constexpr u32 mask = DMA2D_LWR_LW_MASK << shift;
  volatile u32* reg = &DMA2D->LWR;
  syn_set_register_bits(reg, mask, line << shift);
}

void
dma2d_deadtime_enable(void)
{
  DMA2D->AMTCR |= DMA2D_AMTCR_EN;
}

void
dma2d_deadtime_disable(void)
{
  DMA2D->AMTCR &= ~DMA2D_AMTCR_EN;
}

void
dma2d_set_deadtime(
  u32 deadtime
)
{
  devmode_assert_lower_or_eq(deadtime, DMA2D_AMTCR_DT_MASK);
  constexpr u32 shift = DMA2D_AMTCR_DT_SHIFT;
  constexpr u32 mask = DMA2D_AMTCR_DT_MASK << shift;
  volatile u32* reg = &DMA2D->AMTCR;
  syn_set_register_bits(reg, mask, deadtime << shift);
}

