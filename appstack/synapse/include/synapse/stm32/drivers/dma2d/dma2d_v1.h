#ifndef STM32_DRIVER_DMA2D_H
#define STM32_DRIVER_DMA2D_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct dma2d_registers_map
{
  u32 CR;
  u32 ISR;
  u32 IFCR;
  u32 FGMAR;
  u32 FGOR;
  u32 BGMAR;
  u32 BGOR;
  u32 FGPFCCR;
  u32 FGCOLR;
  u32 BGPFCCR;
  u32 BGCOLR;
  u32 FGCMAR;
  u32 BGCMAR;
  u32 OPFCCR;
  u32 OCOLR;
  u32 OMAR;
  u32 OOR;
  u32 NLR;
  u32 LWR;
  u32 AMTCR;
};

enum dma2d_cr : u32
{
  DMA2D_CR_START = (1 << 0),
  DMA2D_CR_SUSP = (1 << 1),
  DMA2D_CR_ABORT = (1 << 2),
  DMA2D_CR_TEIE = (1 << 8),
  DMA2D_CR_TCIE = (1 << 9),
  DMA2D_CR_TWIE = (1 << 10),
  DMA2D_CR_CAEIE = (1 << 11),
  DMA2D_CR_CTCIE = (1 << 12),
  DMA2D_CR_CEIE = (1 << 13)
};

#define DMA2D_CR_MODE_SHIFT (16)
#define DMA2D_CR_MODE_MASK (0x3)

enum dma2d_cr_mode : u32
{
  DMA2D_CR_MODE_MEM2MEM_FG = 0b00,
  DMA2D_CR_MODE_MEM2MEM_PFC = 0b01,
  DMA2D_CR_MODE_MEM2MEM_BLEND = 0b10,
  DMA2D_CR_MODE_REG2MEM = 0b11
};

enum dma2d_isr : u32
{
  DMA2D_ISR_TEIF = (1 << 0),
  DMA2D_ISR_TCIF = (1 << 1),
  DMA2D_ISR_TWIF = (1 << 2),
  DMA2D_ISR_CAEIF = (1 << 3),
  DMA2D_ISR_CTCIF = (1 << 4),
  DMA2D_ISR_CEIF = (1 << 5)
};

enum dma2d_ifcr : u32
{
  DMA2D_IFCR_CTEIF = (1 << 0),
  DMA2D_IFCR_CTCIF = (1 << 1),
  DMA2D_IFCR_CTWIF = (1 << 2),
  DMA2D_IFCR_CAECIF = (1 << 3),
  DMA2D_IFCR_CCTCIF = (1 << 4),
  DMA2D_IFCR_CCEIF = (1 << 5)
};

#define DMA2D_FGOR_LO_SHIFT (0)
#define DMA2D_FGOR_LO_MASK (0x3fffu)

#define DMA2D_BGOR_LO_SHIFT (0)
#define DMA2D_BGOR_LO_MASK (0x3fffu)

enum dma2d_fgpfccr : u32
{
  DMA2D_FGPFCCR_CCM = (1 << 4),
  DMA2D_FGPFCCR_START = (1 << 5)
};

#define DMA2D_FGPFCCR_CM_SHIFT (0)
#define DMA2D_FGPFCCR_CM_MASK (0xf)

enum dma2d_fgpfccr_cm : u32
{
  DMA2D_FGPFCCR_CM_ARGB8888 = 0b0000,
  DMA2D_FGPFCCR_CM_RGB888 = 0b0001,
  DMA2D_FGPFCCR_CM_RGB565 = 0b0010,
  DMA2D_FGPFCCR_CM_ARGB1555 = 0b0011,
  DMA2D_FGPFCCR_CM_ARGB4444 = 0b0100,
  DMA2D_FGPFCCR_CM_L8 = 0b0101,
  DMA2D_FGPFCCR_CM_AL44 = 0b0110,
  DMA2D_FGPFCCR_CM_AL88 = 0b0111,
  DMA2D_FGPFCCR_CM_L4 = 0b1000,
  DMA2D_FGPFCCR_CM_A8 = 0b1001,
  DMA2D_FGPFCCR_CM_A4 = 0b1010
};

#define DMA2D_FGPFCCR_CS_SHIFT (8)
#define DMA2D_FGPFCCR_CS_MASK (0xffu)

#define DMA2D_FGPFCCR_AM_SHIFT (16)
#define DMA2D_FGPFCCR_AM_MASK (0x3)

enum dma2d_fgpfccr_am : u32
{
  DMA2D_FGPFCCR_AM_NOMOD = 0b00,
  DMA2D_FGPFCCR_AM_REPL_FG_W_ALPHA_CH = 0b01,
  DMA2D_FGPFCCR_AM_REPL_FG_W_ALPHA_CHx_ALPHA = 0b10
};

#define DMA2D_FGPFCCR_ALPHA_SHIFT (24)
#define DMA2D_FGPFCCR_ALPHA_MASK (0xffu)

#define DMA2D_FGCOLR_BLUE_SHIFT (0)
#define DMA2D_FGCOLR_BLUE_MASK (0xffu)

#define DMA2D_FGCOLR_GREEN_SHIFT (8)
#define DMA2D_FGCOLR_GREEN_MASK (0xffu)

#define DMA2D_FGCOLR_RED_SHIFT (16)
#define DMA2D_FGCOLR_RED_MASK (0xffu)

enum dma2d_bgpfccr : u32
{
  DMA2D_BGPFCCR_CCM = (1 << 4),
  DMA2D_BGPFCCR_START = (1 << 5)
};

#define DMA2D_BGPFCCR_CM_SHIFT (0)
#define DMA2D_BGPFCCR_CM_MASK (0xf)

enum dma2d_bgpfccr_cm : u32
{
  DMA2D_BGPFCCR_CM_ARGB8888 = 0b0000,
  DMA2D_BGPFCCR_CM_RGB888 = 0b0001,
  DMA2D_BGPFCCR_CM_RGB565 = 0b0010,
  DMA2D_BGPFCCR_CM_ARGB1555 = 0b0011,
  DMA2D_BGPFCCR_CM_ARGB4444 = 0b0100,
  DMA2D_BGPFCCR_CM_L8 = 0b0101,
  DMA2D_BGPFCCR_CM_AL44 = 0b0110,
  DMA2D_BGPFCCR_CM_AL88 = 0b0111,
  DMA2D_BGPFCCR_CM_L4 = 0b1000,
  DMA2D_BGPFCCR_CM_A8 = 0b1001,
  DMA2D_BGPFCCR_CM_A4 = 0b1010
};

#define DMA2D_BGPFCCR_CS_SHIFT (8)
#define DMA2D_BGPFCCR_CS_MASK (0xffu)

#define DMA2D_BGPFCCR_AM_SHIFT (16)
#define DMA2D_BGPFCCR_AM_MASK (0x3u)

enum dma2d_bgprccr_am : u32
{
  DMA2D_BGPFCCR_AM_NOMOD = 0b00,
  DMA2D_BGPFCCR_AM_REPL_FG_W_ALPHA_CH = 0b01,
  DMA2D_BGPFCCR_AM_REPL_FG_W_ALPHA_CHx_ALPHA = 0b10
};

#define DMA2D_BGPFCCR_ALPHA_SHIFT (24)
#define DMA2D_BGPFCCR_ALPHA_MASK (0xffu)

#define DMA2D_BGCOLR_BLUE_SHIFT (0)
#define DMA2D_BGCOLR_BLUE_MASK (0xffu)

#define DMA2D_BGCOLR_GREEN_SHIFT (8)
#define DMA2D_BGCOLR_GREEN_MASK (0xffu)

#define DMA2D_BGCOLR_RED_SHIFT (16)
#define DMA2D_BGCOLR_RED_MASK (0xffu)

#define DMA2D_OPFCCR_CM_SHIFT (0)
#define DMA2D_OPFCCR_CM_MASK (0x7)

enum dma2d_opfccr : u32
{
  DMA2D_OPFCCR_CM_ARGB8888 = 0b000,
  DMA2D_OPFCCR_CM_RGB888 = 0b001,
  DMA2D_OPFCCR_CM_RGB565 = 0b010,
  DMA2D_OPFCCR_CM_ARGB1555 = 0b011,
  DMA2D_OPFCCR_CM_ARGB4444 = 0b100
};

// OCOLR register changes format based on the current color mode.
// ARG8888 mode.
#define DMA2D_OCOLR_ARGB8888_BLUE_SHIFT (0)
#define DMA2D_OCOLR_ARGB8888_BLUE_MASK (0xffu)

#define DMA2D_OCOLR_ARGB8888_GREEN_SHIFT (8)
#define DMA2D_OCOLR_ARGB8888_GREEN_MASK (0xffu)

#define DMA2D_OCOLR_ARGB8888_RED_SHIFT (16)
#define DMA2D_OCOLR_ARGB8888_RED_MASK (0xffu)

#define DMA2D_OCOLR_ARGB8888_ALPHA_SHIFT (24)
#define DMA2D_OCOLR_ARGB8888_ALPHA_MASK (0xffu)

// RGB8888 mode.
#define DMA2D_OCOLR_RGB888_COLOR_MAX_VAL (0xff)

#define DMA2D_OCOLR_RGB888_MASK (0xffffff)
#define DMA2D_OCOLR_RGB888_SHIFT (0)

#define DMA2D_OCOLR_RGB888_BLUE_SHIFT (0)
#define DMA2D_OCOLR_RGB888_BLUE_MASK (0xffu)

#define DMA2D_OCOLR_RGB888_GREEN_SHIFT (8)
#define DMA2D_OCOLR_RGB888_GREEN_MASK (0xffu)

#define DMA2D_OCOLR_RGB888_RED_SHIFT (16)
#define DMA2D_OCOLR_RGB888_RED_MASK (0xffu)

// RGB565 mode.
#define DMA2D_OCOLR_RGB565_SHIFT (0)
#define DMA2D_OCOLR_RGB565_MASK (0xffff)

#define DMA2D_OCOLR_RGB565_BLUE_SHIFT (0)
#define DMA2D_OCOLR_RGB565_BLUE_MASK (0x1fu)

#define DMA2D_OCOLR_RGB565_GREEN_SHIFT (5)
#define DMA2D_OCOLR_RGB565_GREEN_MASK (0x3fu)

#define DMA2D_OCOLR_RGB565_RED_SHIFT (11)
#define DMA2D_OCOLR_RGB565_RED_MASK (0x1f)

// ARGB1555 mode.
#define DMA2D_OCOLR_ARGB1555_SHIFT (0)
#define DMA2D_OCOLR_ARGB1555_MASK (0xffff)

#define DMA2D_OCOLR_ARGB1555_BLUE_SHIFT (0)
#define DMA2D_OCOLR_ARGB1555_BLUE_MASK (0x1f)

#define DMA2D_OCOLR_ARGB1555_GREEN_SHIFT (5)
#define DMA2D_OCOLR_ARGB1555_GREEN_MASK (0x1f)

#define DMA2D_OCOLR_ARGB1555_RED_SHIFT (10)
#define DMA2D_OCOLR_ARGB1555_RED_MASK (0x1f)

#define DMA2D_OCOLR_ARGB1555_A_SHIFT (15)
#define DMA2D_OCOLR_ARGB1555_A_MASK (0x1)

// ARGB4444 mode.
#define DMA2D_OCOLR_ARGB4444_SHIFT (0)
#define DMA2D_OCOLR_ARGB4444_MASK (0xffff)

#define DMA2D_OCOLR_ARGB4444_BLUE_SHIFT (0)
#define DMA2D_OCOLR_ARGB4444_BLUE_MASK (0xf)

#define DMA2D_OCOLR_ARGB4444_GREEN_SHIFT (4)
#define DMA2D_OCOLR_ARGB4444_GREEN_MASK (0xf)

#define DMA2D_OCOLR_ARGB4444_RED_SHIFT (8)
#define DMA2D_OCOLR_ARGB4444_RED_MASK (0xf)

#define DMA2D_OCOLR_ARGB4444_ALPHA_SHIFT (12)
#define DMA2D_OCOLR_ARGB4444_ALPHA_MASK (0xf)

#define DMA2D_OOR_LO_SHIFT (0)
#define DMA2D_OOR_LO_MASK (0x3fff)

#define DMA2D_NLR_NL_SHIFT (0)
#define DMA2D_NLR_NL_MASK (0xffff)

#define DMA2D_NLR_PL_SHIFT (16)
#define DMA2D_NLR_PL_MASK (0x3fff)

#define DMA2D_LWR_LW_SHIFT (0)
#define DMA2D_LWR_LW_MASK (0xffff)

enum dma2d_amtcr : u32
{
  DMA2D_AMTCR_EN = (1 << 0)
};

#define DMA2D_AMTCR_DT_SHIFT (8)
#define DMA2D_AMTCR_DT_MASK (0xff)

// API

enum dma2d_interrupt
{
  DMA2D_INTERRUPT_TRANSFER_ERROR,
  DMA2D_INTERRUPT_TRANSFER_COMPLETE,
  DMA2D_INTERRUPT_TRANSFER_WATERMARK,
  DMA2D_INTERRUPT_CLUT_ACCESS_ERROR,
  DMA2D_INTERRUPT_CLUT_TRANSFER_COMPLETE,
  DMA2D_INTERRUPT_CONFIGURATION_ERROR
};

enum dma2d_mode
{
  DMA2D_MODE_MEMORY_TO_MEMORY_FG,
  DMA2D_MODE_MEMORY_TO_MEMORY_PFC,
  DMA2D_MODE_MEMORY_TO_MEMORY_BLENDING,
  DMA2D_MODE_REGISTER_TO_MEMORY
};

enum dma2d_flag
{
  DMA2D_FLAG_TRANSFER_ERROR,
  DMA2D_FLAG_TRANSFER_COMPLETE,
  DMA2D_FLAG_TRANSFER_WATERMARK,
  DMA2D_FLAG_CLUT_ACCESS_ERROR,
  DMA2D_FLAG_CLUT_TRANSFER_COMPLETE,
  DMA2D_FLAG_CONFIGURATION_ERROR
};

enum dma2d_image_layer
{
  DMA2D_IMAGE_LAYER_FOREGROUND,
  DMA2D_IMAGE_LAYER_BACKGROUND
};

enum dma2d_fg_color_mode
{
  DMA2D_FG_COLOR_MODE_ARGB8888,
  DMA2D_FG_COLOR_MODE_RGB888,
  DMA2D_FG_COLOR_MODE_RGB565,
  DMA2D_FG_COLOR_MODE_ARGB1555,
  DMA2D_FG_COLOR_MODE_ARGB4444,
  DMA2D_FG_COLOR_MODE_L8,
  DMA2D_FG_COLOR_MODE_AL44,
  DMA2D_FG_COLOR_MODE_AL88,
  DMA2D_FG_COLOR_MODE_L4,
  DMA2D_FG_COLOR_MODE_A8,
  DMA2D_FG_COLOR_MODE_A4
};

enum dma2d_fg_clut_color_mode
{
  DMA2D_FG_CLUT_COLOR_MODE_ARGB8888,
  DMA2D_FG_CLUT_COLOR_MODE_RGB888
};

enum dma2d_clut_color_mode
{
  DMA2D_CLUT_COLOR_MODE_ARGB8888,
  DMA2D_CLUT_COLOR_MODE_RGB888
};

enum dma2d_fg_alpha_mode
{
  DMA2D_FG_ALPHA_MODE_NOMOD,
  DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA,
  DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA_MUL
};

enum dma2d_alpha_mode
{
  DMA2D_ALPHA_MODE_NOMOD,
  DMA2D_ALPHA_MODE_REPLACE_ALPHA,
  DMA2D_ALPHA_MODE_REPLACE_ALPHA_MUL
};

enum dma2d_argb8888_color_channel
{
  DMA2D_ARGB8888_COLOR_CHANNEL_RED,
  DMA2D_ARGB8888_COLOR_CHANNEL_GREEN,
  DMA2D_ARGB8888_COLOR_CHANNEL_BLUE,
  DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA
};

enum dma2d_rgb888_color_channel
{
  DMA2D_RGB888_COLOR_CHANNEL_RED,
  DMA2D_RGB888_COLOR_CHANNEL_GREEN,
  DMA2D_RGB888_COLOR_CHANNEL_BLUE
};

enum dma2d_rgb565_color_channel
{
  DMA2D_RGB565_COLOR_CHANNEL_BLUE,
  DMA2D_RGB565_COLOR_CHANNEL_GREEN,
  DMA2D_RGB565_COLOR_CHANNEL_RED
};

enum dma2d_argb1555_color_channel
{
  DMA2D_ARGB1555_COLOR_CHANNEL_BLUE,
  DMA2D_ARGB1555_COLOR_CHANNEL_GREEN,
  DMA2D_ARGB1555_COLOR_CHANNEL_RED,
  DMA2D_ARGB1555_COLOR_CHANNEL_ALPHA
};

enum dma2d_argb4444_color_channel
{
  DMA2D_ARGB4444_COLOR_CHANNEL_BLUE,
  DMA2D_ARGB4444_COLOR_CHANNEL_GREEN,
  DMA2D_ARGB4444_COLOR_CHANNEL_RED,
  DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA
};

enum dma2d_bg_color_mode
{
  DMA2D_BG_COLOR_MODE_ARGB8888,
  DMA2D_BG_COLOR_MODE_RGB888,
  DMA2D_BG_COLOR_MODE_RGB565,
  DMA2D_BG_COLOR_MODE_ARGB1555,
  DMA2D_BG_COLOR_MODE_ARGB4444,
  DMA2D_BG_COLOR_MODE_L8,
  DMA2D_BG_COLOR_MODE_AL44,
  DMA2D_BG_COLOR_MODE_AL88,
  DMA2D_BG_COLOR_MODE_L4,
  DMA2D_BG_COLOR_MODE_A8,
  DMA2D_BG_COLOR_MODE_A4
};

enum dma2d_bg_clut_color_mode
{
  DMA2D_BG_CLUT_COLOR_MODE_ARGB8888,
  DMA2D_BG_CLUT_COLOR_MODE_RGB888
};

enum dma2d_bg_alpha_mode
{
  DMA2D_BG_ALPHA_MODE_NOMOD,
  DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA,
  DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA_MUL
};

enum dma2d_output_color_mode
{
  DMA2D_OUTPUT_COLOR_MODE_ARGB8888,
  DMA2D_OUTPUT_COLOR_MODE_RGB888,
  DMA2D_OUTPUT_COLOR_MODE_RGB565,
  DMA2D_OUTPUT_COLOR_MODE_ARGB1555,
  DMA2D_OUTPUT_COLOR_MODE_ARGB4444
};

extern volatile struct dma2d_registers_map* DMA2D;

void
dma2d_start(void);

void
dma2d_suspend(void);

void
dma2d_abort(void);

void
dma2d_interrupt_enable(
  enum dma2d_interrupt interrupt
);

void
dma2d_interrupt_disable(
  enum dma2d_interrupt interrupt
);

void
dma2d_set_mode(
  enum dma2d_mode mode
);

u32
dma2d_is_flag_set(
  enum dma2d_flag flag
);

void
dma2d_flag_clear(
  enum dma2d_flag flag
);

void
dma2d_set_fg_memory_address(
  u32 address
);

void
dma2d_set_fg_line_offset(
  u32 offset
);

void
dma2d_set_bg_memory_address(
  u32 address
);

void
dma2d_set_bg_img_offset(
  u32 offset
);

void
dma2d_set_bg_line_offset(
  u32 offset
);

void
dma2d_set_fg_color_mode(
  enum dma2d_fg_color_mode mode
);

void
dma2d_set_fg_clut_color_mode(
  enum dma2d_fg_clut_color_mode mode
);

void
dma2d_fg_start(void);

void
dma2d_set_fg_clut_size(
  u32 size
);

void
dma2d_set_fg_alpha_mode(
  enum dma2d_fg_alpha_mode mode
);

void
dma2d_set_fg_pfc_alpha_mode(
  enum dma2d_fg_alpha_mode mode
);

void
dma2d_set_fg_pfc_alpha_value(
  u32 value
);

void
dma2d_set_fg_color_channel_value(
  enum dma2d_rgb888_color_channel channel,
  u32 value
);

void
dma2d_set_bg_color_mode(
  enum dma2d_bg_color_mode mode
);

void
dma2d_set_bg_clut_color_mode(
  enum dma2d_bg_clut_color_mode mode
);

void
dma2d_bg_start(void);

void
dma2d_set_bg_clut_size(
  u32 size
);

void
dma2d_set_bg_pfc_alpha_mode(
  enum dma2d_bg_alpha_mode mode
);

void
dma2d_set_bg_pfc_alpha_value(
  u32 value
);

void
dma2d_set_bg_color_channel_value(
  enum dma2d_rgb888_color_channel channel,
  u32 value
);

void
dma2d_set_fg_clut_memory_address(
  u32 address
);

void
dma2d_set_bg_clut_memory_address(
  u32 address
);

void
dma2d_set_output_color_mode(
  enum dma2d_output_color_mode mode
);

void
dma2d_set_argb8888_output_color(
  u32 color
);

void
dma2d_set_argb8888_output_color_channel_value(
  enum dma2d_argb8888_color_channel channel,
  u32 value
);

void
dma2d_set_rgb8888_output_color(
  u32 color
);

void
dma2d_set_rgb888_output_color_channel_value(
  enum dma2d_rgb888_color_channel channel,
  u32 value
);

void
dma2d_set_rgb565_output_color(
  u32 color
);

void
dma2d_set_rgb565_output_color_channel_value(
  enum dma2d_rgb565_color_channel channel,
  u32 value
);

void
dma2d_set_argb1555_output_color(
  u32 color
);

void
dma2d_set_argb1555_output_color_channel_value(
  enum dma2d_argb1555_color_channel channel,
  u32 value
);

void
dma2d_set_argb4444_output_color(
  u32 color
);

void
dma2d_set_argb4444_output_color_channel_value(
  enum dma2d_argb4444_color_channel channel,
  u32 value
);

void
dma2d_set_output_memory_address(
  u32 address
);

void
dma2d_set_output_line_offset(
  u32 offset
);

void
dma2d_set_number_of_lines(
  u32 lines
);

void
dma2d_set_pixel_per_lines(
  u32 pixels
);

void
dma2d_set_line_watermark(
  u32 line
);

void
dma2d_deadtime_enable(void);

void
dma2d_deadtime_disable(void);

void
dma2d_set_deadtime(
  u32 deadtime
);

END_DECLARATIONS

#endif
