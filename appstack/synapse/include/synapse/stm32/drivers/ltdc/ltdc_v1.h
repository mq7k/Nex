#ifndef STM32_DRIVER_LTDC_H
#define STM32_DRIVER_LTDC_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct ltdc_layer_register_map
{
  u32 LCR;
  u32 LWHPCR;
  u32 LWVPCR;
  u32 LCKCR;
  u32 LPFCR;
  u32 LCACR;
  u32 LDCCR;
  u32 LBFCR;
  u32 LCFBAR;
  u32 LCFBLR;
  u32 LCFBLNR;
  u32 LCLUTWR;
};

struct ltdc_registers_map
{
  u32 SSCR;
  u32 BPCR;
  u32 AWCR;
  u32 TWCR;
  u32 GCR;
  u32 SRCR;
  u32 BCCR;
  u32 IER;
  u32 ISR;
  u32 ICR;
  u32 LIPCR;
  u32 CPSR;
  u32 CDSR;
  u32 LCR[2];
  struct ltdc_layer_register_map layers[2];
};

// Core
#define LTDC_SSCR_VSH_SHIFT (0)
#define LTDC_SSCR_VSH_MASK (0x7ff)

#define LTDC_SSCR_HSW_SHIFT (16)
#define LTDC_SSCR_HSW_MASK (0xfff)

#define LTDC_BPCR_AVBP_SHIFT (0)
#define LTDC_BPCR_AVBP_MASK (0x7ff)

#define LTDC_BPCR_AHBP_SHIFT (16)
#define LTDC_BPCR_AHBP_MASK (0xfff)

#define LTDC_AWCR_AAH_SHIFT (0)
#define LTDC_AWCR_AAH_MASK (0x7ff)

#define LTDC_AWCR_AAW_SHIFT (16)
#define LTDC_AWCR_AAW_MASK (0xfff)

#define LTDC_TWCR_TOTALH_SHIFT (0)
#define LTDC_TWCR_TOTALH_MASK (0x7ff)

#define LTDC_TWCR_TOTALW_SHIFT (16)
#define LTDC_TWCR_TOTALW_MASK (0xfff)

enum ltdc_gcr : u32
{
  LTDC_GCR_LTDCEN = (1 << 0),
  LTDC_GCR_DEN = (1 << 16),
  LTDC_GCR_PCPOL = (1 << 28),
  LTDC_GCR_DEPOL = (1 << 29),
  LTDC_GCR_VSPOL = (1 << 30),
  LTDC_GCR_HSPOL = (1u << 31)
};

#define LTDC_GCR_DBW_SHIFT (4)
#define LTDC_GCR_DBW_MASK (0x7)

#define LTDC_GCR_DGW_SHIFT (8)
#define LTDC_GCR_DGW_MASK (0x7)

#define LTDC_GCR_DRW_SHIFT (12)
#define LTDC_GCR_DRW_MASK (0x7)

enum ltdc_srcr : u32
{
  LTDC_SRCR_IMR = (1 << 0),
  LTDC_SRCR_VBR = (1 << 1)
};

#define LTDC_BCCR_BCBLUE_SHIFT (0)
#define LTDC_BCCR_BCBLUE_MASK (0xffu)

#define LTDC_BCCR_BCGREEN_SHIFT (8)
#define LTDC_BCCR_BCGREEN_MASK (0xffu)

#define LTDC_BCCR_BCRED_SHIFT (16)
#define LTDC_BCCR_BCRED_MASK (0xffu)

#define LTDC_BCCR_RGB_MASK (0xffffff)

enum ltdc_ier : u32
{
  LTDC_IER_LIE = (1 << 0),
  LTDC_IER_FUIE = (1 << 1),
  LTDC_IER_TERRIE = (1 << 2),
  LTDC_IER_RRIE = (1 << 3)
};

enum ltdc_isr : u32
{
  LTDC_ISR_LIF = (1 << 0),
  LTDC_ISR_FUIF = (1 << 1),
  LTDC_ISR_TERRIF = (1 << 2),
  LTDC_ISR_RRIF = (1 << 3)
};

enum ltdc_icr : u32
{
  LTDC_ICR_CLIF = (1 << 0),
  LTDC_ICR_CFUIF = (1 << 1),
  LTDC_ICR_CTERRIF = (1 << 2),
  LTDC_ICR_CRRIF = (1 << 3)
};

#define LTDC_LIPCR_LIPOS_SHIFT (0)
#define LTDC_LIPCR_LIPOS_MASK (0x7ff)

#define LTDC_CPSR_CYPOS_SHIFT (0)
#define LTDC_CPSR_CYPOS_MASK (0xffff)

#define LTDC_CPSR_CXPOS_SHIFT (16)
#define LTDC_CPSR_CXPOS_MASK (0xffff)

enum ltdc_cdsr : u32
{
  LTDC_CDSR_VDES = (1 << 0),
  LTDC_CDSR_HDES = (1 << 1),
  LTDC_CDSR_VSYNCS = (1 << 2),
  LTDC_CDSR_HSYNCS = (1 << 3)
};

enum ltdc_lcr : u32
{
  LTDC_LCR_LEN = (1 << 0),
  LTDC_LCR_COLKEN = (1 << 1),
  LTDC_LCR_CLUTEN = (1 << 4)
};

#define LTDC_LWHPCR_WHSTPOS_SHIFT (0)
#define LTDC_LWHPCR_WHSTPOS_MASK (0xfff)

#define LTDC_LWHPCR_WHSPPOS_SHIFT (16)
#define LTDC_LWHPCR_WHSPPOS_MASK (0xfff)

#define LTDC_LWVPCR_WVSTPOS_SHIFT (0)
#define LTDC_LWVPCR_WVSTPOS_MASK (0x7ff)

#define LTDC_LWVPCR_WVSPPOS_SHIFT (16)
#define LTDC_LWVPCR_WVSPPOS_MASK (0x7ff)

#define LTDC_LCKCR_CKBLUE_SHIFT (0)
#define LTDC_LCKCR_CKBLUE_MASK (0xffu)

#define LTDC_LCKCR_CKGREEN_SHIFT (8)
#define LTDC_LCKCR_CKGREEN_MASK (0xffu)

#define LTDC_LCKCR_CKRED_SHIFT (16)
#define LTDC_LCKCR_CKRED_MASK (0xff)

#define LTDC_LCKCR_COLOR_MASK (0xffffff)

#define LTDC_LPFCR_PF_SHIFT (0)
#define LTDC_LPFCR_PF_MASK (0x7)

enum ltdc_lpfcr_pf : u32
{
  LTDC_LPFCR_PF_ARGB8888 = 0b000,
  LTDC_LPFCR_PF_RGB888 = 0b001,
  LTDC_LPFCR_PF_RGB565 = 0b010,
  LTDC_LPFCR_PF_ARGB1555 = 0b011,
  LTDC_LPFCR_PF_ARGB4444 = 0b100,
  LTDC_LPFCR_PF_L8 = 0b101,
  LTDC_LPFCR_PF_AL44 = 0b110,
  LTDC_LPFCR_PF_AL88 = 0b111
};

#define LTDC_LCACR_CONSTA_SHIFT (0)
#define LTDC_LCACR_CONSTA_MASK (0xff)

#define LTDC_LDCCR_DCBLUE_SHIFT (0)
#define LTDC_LDCCR_DCBLUE_MASK (0xff)

#define LTDC_LDCCR_DCGREEN_SHIFT (8)
#define LTDC_LDCCR_DCGREEN_MASK (0xff)

#define LTDC_LDCCR_DCRED_SHIFT (16)
#define LTDC_LDCCR_DCRED_MASK (0xff)

#define LTDC_LDCCR_DCALPHA_SHIFT (24)
#define LTDC_LDCCR_DCALPHA_MASK (0xff)

#define LTDC_LBFCR_BF2_SHIFT (0)
#define LTDC_LBFCR_BF2_MASK (0x7)

#define LTDC_LBFCR_BF1_SHIFT (8)
#define LTDC_LBFCR_BF1_MASK (0x7)

enum ltdc_lbfcr_bf2 : u32
{
  LTDC_LBFCR_BF2_CONSTANT_ALPHA = 0b101,
  LTDC_LBFCR_BF2_PIXEL_ALPHA_x_CONST_ALPHA = 0b111
};

enum ltdc_lbfcr_bf1 : u32
{
  LTDC_LBFCR_BF1_CONSTANT_ALPHA = 0b100,
  LTDC_LBFCR_BF1_PIXEL_ALPHA_x_CONST_ALPHA = 0b110
};

#define LTDC_LCFBLR_CFBLL_SHIFT (0)
#define LTDC_LCFBLR_CFBLL_MASK (0x1fff)

#define LTDC_LCFBLR_CFBP_SHIFT (16)
#define LTDC_LCFBLR_CFBP_MASK (0x1fff)

#define LTDC_LCFBLNR_CFBLNBR_SHIFT (0)
#define LTDC_LCFBLNR_CFBLNBR_MASK (0x7ff)

#define LTDC_LCLUTWR_BLUE_SHIFT (0)
#define LTDC_LCLUTWR_BLUE_MASK (0xff)

#define LTDC_LCLUTWR_GREEN_SHIFT (8)
#define LTDC_LCLUTWR_GREEN_MASK (0xff)

#define LTDC_LCLUTWR_RED_SHIFT (16)
#define LTDC_LCLUTWR_RED_MASK (0xff)

#define LTDC_LCLUTWR_COLOR_SHIFT (0)
#define LTDC_LCLUTWR_COLOR_MASK (0xffffff)

#define LTDC_LCLUTWR_CLUTADD_SHIFT (24)
#define LTDC_LCLUTWR_CLUTADD_MASK (0xffu)

// API

enum ltdc_pixel_clock_polarity
{
  LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_LOW,
  LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_HIGH
};

enum ltdc_data_enable_polarity
{
  LTDC_DATA_ENABLE_POLARITY_ACTIVE_LOW,
  LTDC_DATA_ENABLE_POLARITY_ACTIVE_HIGH
};

enum ltdc_vertical_sync_polarity
{
  LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_LOW,
  LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_HIGH
};

enum ltdc_horizontal_sync_polarity
{
  LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_LOW,
  LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_HIGH
};

enum ltdc_bg_color
{
  LTDC_BG_COLOR_BLUE,
  LTDC_BG_COLOR_GREEN,
  LTDC_BG_COLOR_RED
};

enum ltdc_interrupt
{
  LTDC_INTERRUPT_LINE,
  LTDC_INTERRUPT_FIFO_UNDERRUN,
  LTDC_INTERRUPT_TRANSFER_ERROR,
  LTDC_INTERRUPT_REGISTER_RELOAD
};

enum ltdc_flag
{
  LTDC_FLAG_VERTICAL_DATA,
  LTDC_FLAG_HORIZONTAL_DATA,
  LTDC_FLAG_VERTICAL_SYNC,
  LTDC_FLAG_HORIZONTAL_SYNC
};

enum ltdc_layer
{
  LTDC_LAYER1,
  LTDC_LAYER2
};

enum ltdc_keyring_color
{
  LTDC_KEYRING_COLOR_BLUE,
  LTDC_KEYRING_COLOR_GREEN,
  LTDC_KEYRING_COLOR_RED
};

enum ltdc_pixel_format
{
  LTDC_PIXEL_FORMAT_ARGB8888,
  LTDC_PIXEL_FORMAT_RGB888,
  LTDC_PIXEL_FORMAT_RGB565,
  LTDC_PIXEL_FORMAT_ARGB1555,
  LTDC_PIXEL_FORMAT_ARGB4444,
  LTDC_PIXEL_FORMAT_L8,
  LTDC_PIXEL_FORMAT_AL44,
  LTDC_PIXEL_FORMAT_AL88
};

enum ltdc_layer_def_color_channel
{
  LAYER_DEF_COLOR_CHANNEL_BLUE,
  LAYER_DEF_COLOR_CHANNEL_GREEN,
  LAYER_DEF_COLOR_CHANNEL_RED,
  LAYER_DEF_COLOR_CHANNEL_ALPHA
};

enum ltdc_blend_factor2
{
  LTDC_BLEND_FACTOR2_CONST_ALPHA,
  LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA
};

enum ltdc_blend_factor1
{
  LTDC_BLEND_FACTOR1_CONST_ALPHA,
  LTDC_BLEND_FACTOR1_PIXEL_ALPHA_x_CONST_ALPHA
};

enum ltdc_clut_color_channel
{
  LTDC_CLUT_COLOR_CHANNEL_BLUE,
  LTDC_CLUT_COLOR_CHANNEL_GREEN,
  LTDC_CLUT_COLOR_CHANNEL_RED
};

extern volatile struct ltdc_registers_map* LTDC;

void
ltdc_set_sync_height(
  u32 sync_height
);

void
ltdc_set_sync_width(
  u32 sync_width
);

void
ltdc_set_vertical_back_porch(
  u32 count
);

void
ltdc_set_horizontal_back_porch(
  u32 count
);

void
ltdc_set_active_height(
  u32 height
);

void
ltdc_set_active_width(
  u32 width
);

void
ltdc_set_total_height(
  u32 height
);

void
ltdc_set_total_width(
  u32 width
);

void
ltdc_enable(void);

void
ltdc_disable(void);

u32
ltdc_get_dither_blue_width(void);

u32
ltdc_get_dither_green_width(void);

u32
ltdc_get_dither_red_width(void);

void
ltdc_dither_enable(void);

void
ltdc_dither_disable(void);

void
ltdc_set_pixel_clock_polarity(
  enum ltdc_pixel_clock_polarity polarity
);

void
ltdc_set_data_enable_polarity(
  enum ltdc_data_enable_polarity polarity
);

void
ltdc_set_vertical_sync_polarity(
  enum ltdc_vertical_sync_polarity polarity
);

void
ltdc_set_horizontal_sync_polarity(
  enum ltdc_horizontal_sync_polarity polarity
);

void
ltdc_immediate_reload(void);

void
ltdc_vertical_blanking_reload(void);

void
ltdc_set_bg_color_value(
  enum ltdc_bg_color color,
  u32 value
);

void
ltdc_set_bg_color(
  u32 value
);

void
ltdc_interrupt_enable(
  enum ltdc_interrupt interrupt
);

void
ltdc_interrupt_disable(
  enum ltdc_interrupt interrupt
);

u32
ltdc_is_interrupt_occurred(
  enum ltdc_interrupt interrupt
);

void
ltdc_interrupt_clear(
  enum ltdc_interrupt interrupt
);

void
ltdc_set_line_interrupt_position(
  u32 position
);

u32
ltdc_get_current_position_y(void);

u32
ltdc_get_current_position_x(void);

u32
ltdc_is_flag_set(
  enum ltdc_flag flag
);

void
ltdc_layer_enable(
  enum ltdc_layer layer
);

void
ltdc_layer_disable(
  enum ltdc_layer layer
);

void
ltdc_layer_color_keying_enable(
  enum ltdc_layer layer
);

void
ltdc_layer_color_keying_disable(
  enum ltdc_layer layer
);

void
ltdc_layer_color_lookup_table_enable(
  enum ltdc_layer layer
);

void
ltdc_layer_color_lookup_table_disable(
  enum ltdc_layer layer
);

void
ltdc_layer_set_window_horizontal_start_position(
  enum ltdc_layer layer,
  u32 value
);

void
ltdc_layer_set_window_horizontal_stop_position(
  enum ltdc_layer layer,
  u32 value
);

void
ltdc_layer_set_window_vertical_start_position(
  enum ltdc_layer layer,
  u32 value
);

void
ltdc_layer_set_window_vertical_stop_position(
  enum ltdc_layer layer,
  u32 value
);

void
ltdc_set_layer_keyring_color_value(
  enum ltdc_layer layer,
  enum ltdc_keyring_color color,
  u32 value
);

void
ltdc_set_layer_keyring_color(
  enum ltdc_layer layer,
  u32 value
);

void
ltdc_set_layer_pixel_format(
  enum ltdc_layer layer,
  enum ltdc_pixel_format format
);

void
ltdc_set_layer_constant_alpha(
  enum ltdc_layer layer,
  u32 alpha
);

void
ltdc_set_layer_def_color_value(
  enum ltdc_layer layer,
  enum ltdc_layer_def_color_channel color,
  u32 value
);

void
ltdc_set_layer_def_color(
  enum ltdc_layer layer,
  u32 value
);

void
ltdc_set_layer_blend_factor2(
  enum ltdc_layer layer,
  enum ltdc_blend_factor2 factor
);

void
ltdc_set_layer_blend_factor1(
  enum ltdc_layer layer,
  enum ltdc_blend_factor1 factor
);

void
ltdc_set_layer_color_frame_buffer_start_address(
  enum ltdc_layer layer,
  u32 address
);

void
ltdc_set_layer_color_frame_buffer_length(
  enum ltdc_layer layer,
  u32 length
);

void
ltdc_set_layer_color_frame_buffer_pitch(
  enum ltdc_layer layer,
  u32 bytes
);

void
ltdc_set_layer_frame_buffer_line_number(
  enum ltdc_layer layer,
  u32 number
);

void
ltdc_set_layer_clut_color_value(
  enum ltdc_layer layer,
  enum ltdc_clut_color_channel channel,
  u32 value
);

void
ltdc_set_layer_clut_color(
  enum ltdc_layer layer,
  u32 value
);

void
ltdc_set_layer_clut_address(
  enum ltdc_layer layer,
  u32 address
);

END_DECLARATIONS

#endif
