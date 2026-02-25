#include "synapse/stm32/drivers/ltdc/ltdc_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct ltdc_registers_map ltdc_periph;
typedef volatile struct ltdc_layer_register_map ltdc_layer_v;
ltdc_periph* LTDC = (ltdc_periph*) (LCD_TFT_ADDR);

static ltdc_layer_v*
get_ltdc_layer(
  enum ltdc_layer layer
)
{
  switch (layer)
  {
    case LTDC_LAYER1:
      return &LTDC->layers[0];

    case LTDC_LAYER2:
      return &LTDC->layers[1];

    default:
      devmode_error_invalid_enum(enum ltdc_layer, layer);
      return 0;
  }
}

void
ltdc_set_sync_height(
  u32 sync_height
)
{
  devmode_assert_lower_or_eq(sync_height, LTDC_SSCR_VSH_MASK);
  constexpr u32 shift = LTDC_SSCR_VSH_SHIFT;
  constexpr u32 mask = LTDC_SSCR_VSH_MASK << shift;
  volatile u32* reg = &LTDC->SSCR;
  syn_set_register_bits(reg, mask, sync_height << shift);
}

void
ltdc_set_sync_width(
  u32 sync_width
)
{
  devmode_assert_lower_or_eq(sync_width, LTDC_SSCR_HSW_MASK);
  constexpr u32 shift = LTDC_SSCR_HSW_SHIFT;
  constexpr u32 mask = LTDC_SSCR_HSW_MASK << shift;
  volatile u32* reg = &LTDC->SSCR;
  syn_set_register_bits(reg, mask, sync_width << shift);
}

void
ltdc_set_vertical_back_porch(
  u32 count
)
{
  devmode_assert_lower_or_eq(count, LTDC_BPCR_AVBP_MASK);
  constexpr u32 shift = LTDC_BPCR_AVBP_SHIFT;
  constexpr u32 mask = LTDC_BPCR_AVBP_MASK << shift;
  volatile u32* reg = &LTDC->BPCR;
  syn_set_register_bits(reg, mask, count << shift);
}

void
ltdc_set_horizontal_back_porch(
  u32 count
)
{
  devmode_assert_lower_or_eq(count, LTDC_BPCR_AHBP_MASK);
  constexpr u32 shift = LTDC_BPCR_AHBP_SHIFT;
  constexpr u32 mask = LTDC_BPCR_AHBP_MASK << shift;
  volatile u32* reg = &LTDC->BPCR;
  syn_set_register_bits(reg, mask, count << shift);
}

void
ltdc_set_active_height(
  u32 height
)
{
  devmode_assert_lower_or_eq(height, LTDC_AWCR_AAH_MASK);
  constexpr u32 shift = LTDC_AWCR_AAH_SHIFT;
  constexpr u32 mask = LTDC_AWCR_AAH_MASK << shift;
  volatile u32* reg = &LTDC->AWCR;
  syn_set_register_bits(reg, mask, height << shift);
}

void
ltdc_set_active_width(
  u32 width
)
{
  devmode_assert_lower_or_eq(width, LTDC_AWCR_AAW_MASK);
  constexpr u32 shift = LTDC_AWCR_AAW_SHIFT;
  constexpr u32 mask = LTDC_AWCR_AAW_MASK << shift;
  volatile u32* reg = &LTDC->AWCR;
  syn_set_register_bits(reg, mask, width << shift);
}

void
ltdc_set_total_height(
  u32 height
)
{
  devmode_assert_lower_or_eq(height, LTDC_TWCR_TOTALH_MASK);
  constexpr u32 shift = LTDC_TWCR_TOTALH_SHIFT;
  constexpr u32 mask = LTDC_TWCR_TOTALH_MASK << shift;
  volatile u32* reg = &LTDC->TWCR;
  syn_set_register_bits(reg, mask, height << shift);
}

void
ltdc_set_total_width(
  u32 width
)
{
  devmode_assert_lower_or_eq(width, LTDC_TWCR_TOTALW_MASK);
  constexpr u32 shift = LTDC_TWCR_TOTALW_SHIFT;
  constexpr u32 mask = LTDC_TWCR_TOTALW_MASK << shift;
  volatile u32* reg = &LTDC->TWCR;
  syn_set_register_bits(reg, mask, width << shift);
}

void
ltdc_enable(void)
{
  LTDC->GCR |= LTDC_GCR_LTDCEN;
}

void
ltdc_disable(void)
{
  LTDC->GCR &= ~LTDC_GCR_LTDCEN;
}

u32
ltdc_get_dither_blue_width(void)
{
  constexpr u32 shift = LTDC_GCR_DBW_SHIFT;
  constexpr u32 mask = LTDC_GCR_DBW_MASK;
  volatile u32* reg = &LTDC->GCR;
  return (*reg >> shift) & mask;
}

u32
ltdc_get_dither_green_width(void)
{
  constexpr u32 shift = LTDC_GCR_DGW_SHIFT;
  constexpr u32 mask = LTDC_GCR_DGW_MASK;
  volatile u32* reg = &LTDC->GCR;
  return (*reg >> shift) & mask;
}

u32
ltdc_get_dither_red_width(void)
{
  constexpr u32 shift = LTDC_GCR_DRW_SHIFT;
  constexpr u32 mask = LTDC_GCR_DRW_MASK;
  volatile u32* reg = &LTDC->GCR;
  return (*reg >> shift) & mask;
}

void
ltdc_dither_enable(void)
{
  LTDC->GCR |= LTDC_GCR_DEN;
}

void
ltdc_dither_disable(void)
{
  LTDC->GCR &= ~LTDC_GCR_DEN;
}

void
ltdc_set_pixel_clock_polarity(
  enum ltdc_pixel_clock_polarity polarity
)
{
  volatile u32* reg = &LTDC->GCR;
  switch (polarity)
  {
    case LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_LOW:
      *reg &= ~LTDC_GCR_PCPOL;
      break;

    case LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_HIGH:
      *reg |= LTDC_GCR_PCPOL;
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_pixel_clock_polarity, polarity);
      break;
  }
}

void
ltdc_set_data_enable_polarity(
  enum ltdc_data_enable_polarity polarity
)
{
  volatile u32* reg = &LTDC->GCR;
  switch (polarity)
  {
    case LTDC_DATA_ENABLE_POLARITY_ACTIVE_LOW:
      *reg &= ~LTDC_GCR_DEPOL;
      break;

    case LTDC_DATA_ENABLE_POLARITY_ACTIVE_HIGH:
      *reg |= LTDC_GCR_DEPOL;
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_data_enable_polarity, polarity);
      break;
  }
}

void
ltdc_set_vertical_sync_polarity(
  enum ltdc_vertical_sync_polarity polarity
)
{
  volatile u32* reg = &LTDC->GCR;
  switch (polarity)
  {
    case LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_LOW:
      *reg &= ~LTDC_GCR_VSPOL;
      break;

    case LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_HIGH:
      *reg |= LTDC_GCR_VSPOL;
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_vertical_sync_polarity, polarity);
      break;
  }
}

void
ltdc_set_horizontal_sync_polarity(
  enum ltdc_horizontal_sync_polarity polarity
)
{
  volatile u32* reg = &LTDC->GCR;
  switch (polarity)
  {
    case LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_LOW:
      *reg &= ~LTDC_GCR_HSPOL;
      break;

    case LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_HIGH:
      *reg |= LTDC_GCR_HSPOL;
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_horizontal_sync_polarity, polarity);
      break;
  }
}

void
ltdc_immediate_reload(void)
{
  LTDC->SRCR |= LTDC_SRCR_IMR;
}

void
ltdc_vertical_blanking_reload(void)
{
  LTDC->SRCR |= LTDC_SRCR_VBR;
}

void
ltdc_set_bg_color_value(
  enum ltdc_bg_color color,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &LTDC->BCCR;
  switch (color)
  {
    case LTDC_BG_COLOR_BLUE:
      devmode_assert_lower_or_eq(value, LTDC_BCCR_BCBLUE_MASK);
      shift = LTDC_BCCR_BCBLUE_SHIFT;
      mask = LTDC_BCCR_BCBLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LTDC_BG_COLOR_GREEN:
      devmode_assert_lower_or_eq(value, LTDC_BCCR_BCGREEN_MASK);
      shift = LTDC_BCCR_BCGREEN_SHIFT;
      mask = LTDC_BCCR_BCGREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LTDC_BG_COLOR_RED:
      devmode_assert_lower_or_eq(value, LTDC_BCCR_BCRED_MASK);
      shift = LTDC_BCCR_BCRED_SHIFT;
      mask = LTDC_BCCR_BCRED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_bg_color, color);
      break;
  }
}

void
ltdc_set_bg_color(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, LTDC_BCCR_RGB_MASK);
  LTDC->BCCR = value;
}

void
ltdc_interrupt_enable(
  enum ltdc_interrupt interrupt
)
{
  volatile u32* reg = &LTDC->IER; 
  switch (interrupt)
  {
    case LTDC_INTERRUPT_LINE:
      *reg |= LTDC_IER_LIE;
      break;

    case LTDC_INTERRUPT_FIFO_UNDERRUN:
      *reg |= LTDC_IER_FUIE;
      break;

    case LTDC_INTERRUPT_TRANSFER_ERROR:
      *reg |= LTDC_IER_TERRIE;
      break;

    case LTDC_INTERRUPT_REGISTER_RELOAD:
      *reg |= LTDC_IER_RRIE;
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_interrupt, interrupt);
      break;
  }
}

void
ltdc_interrupt_disable(
  enum ltdc_interrupt interrupt
)
{
  volatile u32* reg = &LTDC->IER; 
  switch (interrupt)
  {
    case LTDC_INTERRUPT_LINE:
      *reg &= ~LTDC_IER_LIE;
      break;

    case LTDC_INTERRUPT_FIFO_UNDERRUN:
      *reg &= ~LTDC_IER_FUIE;
      break;

    case LTDC_INTERRUPT_TRANSFER_ERROR:
      *reg &= ~LTDC_IER_TERRIE;
      break;

    case LTDC_INTERRUPT_REGISTER_RELOAD:
      *reg &= ~LTDC_IER_RRIE;
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_interrupt, interrupt);
      break;
  }
}

u32
ltdc_is_interrupt_occurred(
  enum ltdc_interrupt interrupt
)
{
  volatile u32* reg = &LTDC->ISR;
  switch (interrupt)
  {
    case LTDC_INTERRUPT_LINE:
      return *reg & LTDC_ISR_LIF;

    case LTDC_INTERRUPT_FIFO_UNDERRUN:
      return *reg & LTDC_ISR_FUIF;

    case LTDC_INTERRUPT_TRANSFER_ERROR:
      return *reg & LTDC_ISR_TERRIF;

    case LTDC_INTERRUPT_REGISTER_RELOAD:
      return *reg & LTDC_ISR_RRIF;

    default:
      devmode_error_invalid_enum(enum ltdc_interrupt, interrupt);
      return 0;
  }
}

void
ltdc_interrupt_clear(
  enum ltdc_interrupt interrupt
)
{
  volatile u32* reg = &LTDC->ICR;
  switch (interrupt)
  {
    case LTDC_INTERRUPT_LINE:
      *reg |= LTDC_ICR_CLIF;
      break;

    case LTDC_INTERRUPT_FIFO_UNDERRUN:
      *reg |= LTDC_ICR_CFUIF;
      break;

    case LTDC_INTERRUPT_TRANSFER_ERROR:
      *reg |= LTDC_ICR_CTERRIF;
      break;

    case LTDC_INTERRUPT_REGISTER_RELOAD:
      *reg |= LTDC_ICR_CRRIF;
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_interrupt, interrupt);
      break;
  }
}

void
ltdc_set_line_interrupt_position(
  u32 position
)
{
  devmode_assert_lower_or_eq(position, LTDC_LIPCR_LIPOS_MASK);
  LTDC->LIPCR = position;
}

u32
ltdc_get_current_position_y(void)
{
  constexpr u32 shift = LTDC_CPSR_CYPOS_SHIFT;
  constexpr u32 mask = LTDC_CPSR_CYPOS_MASK;
  volatile u32* reg = &LTDC->CPSR;
  return (*reg >> shift) & mask;
}

u32
ltdc_get_current_position_x(void)
{
  constexpr u32 shift = LTDC_CPSR_CXPOS_SHIFT;
  constexpr u32 mask = LTDC_CPSR_CXPOS_MASK;
  volatile u32* reg = &LTDC->CPSR;
  return (*reg >> shift) & mask;
}

u32
ltdc_is_flag_set(
  enum ltdc_flag flag
)
{
  volatile u32* reg = &LTDC->CDSR;
  switch (flag)
  {
    case LTDC_FLAG_VERTICAL_DATA:
      return *reg & LTDC_CDSR_VDES;

    case LTDC_FLAG_HORIZONTAL_DATA:
      return *reg & LTDC_CDSR_HDES;

    case LTDC_FLAG_VERTICAL_SYNC:
      return *reg & LTDC_CDSR_VSYNCS;

    case LTDC_FLAG_HORIZONTAL_SYNC:
      return *reg & LTDC_CDSR_HSYNCS;

    default:
      devmode_error_invalid_enum(enum ltdc_flag, flag);
      return 0;
  }
}

void
ltdc_layer_enable(
  enum ltdc_layer layer
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCR |= LTDC_LCR_LEN;
}

void
ltdc_layer_disable(
  enum ltdc_layer layer
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCR &= ~LTDC_LCR_LEN;
}

void
ltdc_layer_color_keying_enable(
  enum ltdc_layer layer
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCR |= LTDC_LCR_COLKEN;
}

void
ltdc_layer_color_keying_disable(
  enum ltdc_layer layer
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCR &= ~LTDC_LCR_COLKEN;
}

void
ltdc_layer_color_lookup_table_enable(
  enum ltdc_layer layer
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCR |= LTDC_LCR_CLUTEN;
}

void
ltdc_layer_color_lookup_table_disable(
  enum ltdc_layer layer
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCR &= ~LTDC_LCR_CLUTEN;
}

void
ltdc_layer_set_window_horizontal_start_position(
  enum ltdc_layer layer,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, LTDC_LWHPCR_WHSTPOS_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LWHPCR_WHSTPOS_SHIFT;
  constexpr u32 mask = LTDC_LWHPCR_WHSTPOS_MASK << shift;
  volatile u32* reg = &ltdc_layer->LWHPCR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
ltdc_layer_set_window_horizontal_stop_position(
  enum ltdc_layer layer,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, LTDC_LWHPCR_WHSPPOS_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LWHPCR_WHSPPOS_SHIFT;
  constexpr u32 mask = LTDC_LWHPCR_WHSPPOS_MASK << shift;
  volatile u32* reg = &ltdc_layer->LWHPCR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
ltdc_layer_set_window_vertical_start_position(
  enum ltdc_layer layer,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, LTDC_LWVPCR_WVSTPOS_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LWVPCR_WVSTPOS_SHIFT;
  constexpr u32 mask = LTDC_LWVPCR_WVSTPOS_MASK << shift;
  volatile u32* reg = &ltdc_layer->LWVPCR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
ltdc_layer_set_window_vertical_stop_position(
  enum ltdc_layer layer,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, LTDC_LWVPCR_WVSPPOS_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LWVPCR_WVSPPOS_SHIFT;
  constexpr u32 mask = LTDC_LWVPCR_WVSPPOS_MASK << shift;
  volatile u32* reg = &ltdc_layer->LWVPCR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
ltdc_set_layer_keyring_color_value(
  enum ltdc_layer layer,
  enum ltdc_keyring_color color,
  u32 value
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  u32 shift;
  u32 mask;
  volatile u32* reg = &ltdc_layer->LCKCR;
  switch (color)
  {
    case LTDC_KEYRING_COLOR_BLUE:
      devmode_assert_lower_or_eq(value, LTDC_LCKCR_CKBLUE_MASK);
      shift = LTDC_LCKCR_CKBLUE_SHIFT;
      mask = LTDC_LCKCR_CKBLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LTDC_KEYRING_COLOR_GREEN:
      devmode_assert_lower_or_eq(value, LTDC_LCKCR_CKGREEN_MASK);
      shift = LTDC_LCKCR_CKGREEN_SHIFT;
      mask = LTDC_LCKCR_CKGREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LTDC_KEYRING_COLOR_RED:
      devmode_assert_lower_or_eq(value, LTDC_LCKCR_CKRED_MASK);
      shift = LTDC_LCKCR_CKRED_SHIFT;
      mask = LTDC_LCKCR_CKRED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_keyring_color, color);
      break;
  }
}

void
ltdc_set_layer_keyring_color(
  enum ltdc_layer layer,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, LTDC_LCKCR_COLOR_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCKCR = value;
}

void
ltdc_set_layer_pixel_format(
  enum ltdc_layer layer,
  enum ltdc_pixel_format format
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LPFCR_PF_SHIFT;
  constexpr u32 mask = LTDC_LPFCR_PF_MASK << shift;
  volatile u32* reg = &ltdc_layer->LPFCR;

  switch (format)
  {
    case LTDC_PIXEL_FORMAT_ARGB8888:
      *reg &= ~mask;
      break;

    case LTDC_PIXEL_FORMAT_RGB888:
        syn_set_register_bits(reg, mask, LTDC_LPFCR_PF_RGB888 << shift);
        break;

    case LTDC_PIXEL_FORMAT_RGB565:
        syn_set_register_bits(reg, mask, LTDC_LPFCR_PF_RGB565 << shift);
        break;

    case LTDC_PIXEL_FORMAT_ARGB1555:
        syn_set_register_bits(reg, mask, LTDC_LPFCR_PF_ARGB1555 << shift);
        break;

    case LTDC_PIXEL_FORMAT_ARGB4444:
        syn_set_register_bits(reg, mask, LTDC_LPFCR_PF_ARGB4444 << shift);
        break;

    case LTDC_PIXEL_FORMAT_L8:
        syn_set_register_bits(reg, mask, LTDC_LPFCR_PF_L8 << shift);
        break;

    case LTDC_PIXEL_FORMAT_AL44:
        syn_set_register_bits(reg, mask, LTDC_LPFCR_PF_AL44 << shift);
        break;

    case LTDC_PIXEL_FORMAT_AL88:
        syn_set_register_bits(reg, mask, LTDC_LPFCR_PF_AL88 << shift);
        break;

    default:
      devmode_error_invalid_enum(enum ltdc_layer, layer);
      break;
  }
}

void
ltdc_set_layer_constant_alpha(
  enum ltdc_layer layer,
  u32 alpha
)
{
  devmode_assert_lower_or_eq(alpha, LTDC_LCACR_CONSTA_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LCACR_CONSTA_SHIFT;
  constexpr u32 mask = LTDC_LCACR_CONSTA_MASK << shift;
  volatile u32* reg = &ltdc_layer->LCACR;
  syn_set_register_bits(reg, mask, alpha << shift);
}

void
ltdc_set_layer_def_color_value(
  enum ltdc_layer layer,
  enum ltdc_layer_def_color_channel color,
  u32 value
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  u32 shift;
  u32 mask;
  volatile u32* reg = &ltdc_layer->LDCCR;

  switch (color)
  {
    case LAYER_DEF_COLOR_CHANNEL_BLUE:
      devmode_assert_lower_or_eq(value, LTDC_LDCCR_DCBLUE_MASK);
      shift = LTDC_LDCCR_DCBLUE_SHIFT;
      mask = LTDC_LDCCR_DCBLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LAYER_DEF_COLOR_CHANNEL_GREEN:
      devmode_assert_lower_or_eq(value, LTDC_LDCCR_DCGREEN_MASK);
      shift = LTDC_LDCCR_DCGREEN_SHIFT;
      mask = LTDC_LDCCR_DCGREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LAYER_DEF_COLOR_CHANNEL_RED:
      devmode_assert_lower_or_eq(value, LTDC_LDCCR_DCRED_MASK);
      shift = LTDC_LDCCR_DCRED_SHIFT;
      mask = LTDC_LDCCR_DCRED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LAYER_DEF_COLOR_CHANNEL_ALPHA:
      devmode_assert_lower_or_eq(value, LTDC_LDCCR_DCALPHA_MASK);
      shift = LTDC_LDCCR_DCALPHA_SHIFT;
      mask = LTDC_LDCCR_DCALPHA_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum layer_def_color_channel, color);
      break;
  }
}

void
ltdc_set_layer_def_color(
  enum ltdc_layer layer,
  u32 value
)
{
  // No bounds check, allowed goes from 0 to 0xffffffff (32 bit)
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LDCCR = value;
}

void
ltdc_set_layer_blend_factor2(
  enum ltdc_layer layer,
  enum ltdc_blend_factor2 factor
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LBFCR_BF2_SHIFT;
  constexpr u32 mask = LTDC_LBFCR_BF2_MASK << shift;
  volatile u32* reg = &ltdc_layer->LBFCR;

  switch (factor)
  {
    case LTDC_BLEND_FACTOR2_CONST_ALPHA:
      syn_set_register_bits(
        reg,
        mask,
        LTDC_LBFCR_BF2_CONSTANT_ALPHA << shift
      );
      break;

    case LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA:
      syn_set_register_bits(
        reg,
        mask,
        LTDC_LBFCR_BF2_PIXEL_ALPHA_x_CONST_ALPHA << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_blend_factor2, factor);
      break;
  }
}

void
ltdc_set_layer_blend_factor1(
  enum ltdc_layer layer,
  enum ltdc_blend_factor1 factor
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LBFCR_BF1_SHIFT;
  constexpr u32 mask = LTDC_LBFCR_BF1_MASK << shift;
  volatile u32* reg = &ltdc_layer->LBFCR;

  switch (factor)
  {
    case LTDC_BLEND_FACTOR2_CONST_ALPHA:
      syn_set_register_bits(
        reg,
        mask,
        LTDC_LBFCR_BF1_CONSTANT_ALPHA << shift
      );
      break;

    case LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA:
      syn_set_register_bits(
        reg,
        mask,
        LTDC_LBFCR_BF1_PIXEL_ALPHA_x_CONST_ALPHA << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_blend_factor2, factor);
      break;
  }
}

void
ltdc_set_layer_color_frame_buffer_start_address(
  enum ltdc_layer layer,
  u32 address
)
{
  // No bounds check, allowed goes from 0 to 0xffffffff (32 bit)
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  ltdc_layer->LCFBAR = address;
}

void
ltdc_set_layer_color_frame_buffer_length(
  enum ltdc_layer layer,
  u32 length
)
{
  devmode_assert_lower_or_eq(length, LTDC_LCFBLR_CFBLL_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LCFBLR_CFBLL_SHIFT;
  constexpr u32 mask = LTDC_LCFBLR_CFBP_MASK << shift;
  volatile u32* reg = &ltdc_layer->LCFBLR;
  syn_set_register_bits(reg, mask, length << shift);
}

void
ltdc_set_layer_color_frame_buffer_pitch(
  enum ltdc_layer layer,
  u32 bytes
)
{
  devmode_assert_lower_or_eq(bytes, LTDC_LCFBLR_CFBP_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LCFBLR_CFBP_SHIFT;
  constexpr u32 mask = LTDC_LCFBLR_CFBP_MASK << shift;
  volatile u32* reg = &ltdc_layer->LCFBLR;
  syn_set_register_bits(reg, mask, bytes << shift);
}

void
ltdc_set_layer_frame_buffer_line_number(
  enum ltdc_layer layer,
  u32 number
)
{
  devmode_assert_lower_or_eq(number, LTDC_LCFBLNR_CFBLNBR_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LCFBLNR_CFBLNBR_SHIFT;
  constexpr u32 mask = LTDC_LCFBLNR_CFBLNBR_MASK << shift;
  volatile u32* reg = &ltdc_layer->LCFBLNR;
  syn_set_register_bits(reg, mask, number << shift);
}

void
ltdc_set_layer_clut_color_value(
  enum ltdc_layer layer,
  enum ltdc_clut_color_channel channel,
  u32 value
)
{
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  u32 shift;
  u32 mask;
  volatile u32* reg = &ltdc_layer->LCLUTWR;

  switch (channel)
  {
    case LTDC_CLUT_COLOR_CHANNEL_BLUE:
      devmode_assert_lower_or_eq(value, LTDC_LCLUTWR_BLUE_MASK);
      shift = LTDC_LCLUTWR_BLUE_SHIFT;
      mask = LTDC_LCLUTWR_BLUE_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LTDC_CLUT_COLOR_CHANNEL_GREEN:
      devmode_assert_lower_or_eq(value, LTDC_LCLUTWR_GREEN_MASK);
      shift = LTDC_LCLUTWR_GREEN_SHIFT;
      mask = LTDC_LCLUTWR_GREEN_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case LTDC_CLUT_COLOR_CHANNEL_RED:
      devmode_assert_lower_or_eq(value, LTDC_LCLUTWR_RED_MASK);
      shift = LTDC_LCLUTWR_RED_SHIFT;
      mask = LTDC_LCLUTWR_RED_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum ltdc_clut_color_channel, channel);
      break;
  }
}

void
ltdc_set_layer_clut_color(
  enum ltdc_layer layer,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, LTDC_LCLUTWR_COLOR_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LCLUTWR_COLOR_SHIFT;
  constexpr u32 mask = LTDC_LCLUTWR_COLOR_MASK << shift;
  volatile u32* reg = &ltdc_layer->LCLUTWR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
ltdc_set_layer_clut_address(
  enum ltdc_layer layer,
  u32 address
)
{
  devmode_assert_lower_or_eq(address, LTDC_LCLUTWR_CLUTADD_MASK);
  ltdc_layer_v* ltdc_layer = get_ltdc_layer(layer);
  constexpr u32 shift = LTDC_LCLUTWR_CLUTADD_SHIFT;
  constexpr u32 mask = LTDC_LCLUTWR_CLUTADD_MASK << shift;
  volatile u32* reg = &ltdc_layer->LCLUTWR;
  syn_set_register_bits(reg, mask, address << shift);
}
