#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/ltdc/ltdc_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  LTDC = (struct ltdc_registers_map*) membuf;
}

void
test_ltdc_set_sync_height(void)
{
  LTDC->SSCR = 0;
  ltdc_set_sync_height(0);
  ASSERT_EQ(LTDC->SSCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->SSCR = 0xffffffff;
  ltdc_set_sync_height(0);
  ASSERT_EQ(LTDC->SSCR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->SSCR = 0;
  ltdc_set_sync_height(0x7ff);
  ASSERT_EQ(LTDC->SSCR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->SSCR = 0xffffffff;
  ltdc_set_sync_height(0x7ff);
  ASSERT_EQ(LTDC->SSCR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->SSCR = 0;
  ltdc_set_sync_height(0x800);
  ASSERT_EQ(LTDC->SSCR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->SSCR = 0xffffffff;
  ltdc_set_sync_height(0x800);
  ASSERT_EQ(LTDC->SSCR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_sync_width(void)
{
  LTDC->SSCR = 0;
  ltdc_set_sync_width(0);
  ASSERT_EQ(LTDC->SSCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->SSCR = 0xffffffff;
  ltdc_set_sync_width(0);
  ASSERT_EQ(LTDC->SSCR, ~(0xfffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->SSCR = 0;
  ltdc_set_sync_width(0xfff);
  ASSERT_EQ(LTDC->SSCR, 0xfffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->SSCR = 0xffffffff;
  ltdc_set_sync_width(0xfff);
  ASSERT_EQ(LTDC->SSCR, ~(0xfffu << 16) | (0xfffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->SSCR = 0;
  ltdc_set_sync_width(0x1000);
  ASSERT_EQ(LTDC->SSCR, 0x1000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->SSCR = 0xffffffff;
  ltdc_set_sync_width(0x1000);
  ASSERT_EQ(LTDC->SSCR, ~(0xfffu << 16) | (0x1000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_vertical_back_porch(void)
{
  LTDC->BPCR = 0;
  ltdc_set_vertical_back_porch(0);
  ASSERT_EQ(LTDC->BPCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->BPCR = 0xffffffff;
  ltdc_set_vertical_back_porch(0);
  ASSERT_EQ(LTDC->BPCR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->BPCR = 0;
  ltdc_set_vertical_back_porch(0x7ff);
  ASSERT_EQ(LTDC->BPCR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->BPCR = 0xffffffff;
  ltdc_set_vertical_back_porch(0x7ff);
  ASSERT_EQ(LTDC->BPCR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->BPCR = 0;
  ltdc_set_vertical_back_porch(0x800);
  ASSERT_EQ(LTDC->BPCR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->BPCR = 0xffffffff;
  ltdc_set_vertical_back_porch(0x800);
  ASSERT_EQ(LTDC->BPCR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_horizontal_back_porch(void)
{
  LTDC->BPCR = 0;
  ltdc_set_horizontal_back_porch(0);
  ASSERT_EQ(LTDC->BPCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->BPCR = 0xffffffff;
  ltdc_set_horizontal_back_porch(0);
  ASSERT_EQ(LTDC->BPCR, ~(0xfffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->BPCR = 0;
  ltdc_set_horizontal_back_porch(0xfff);
  ASSERT_EQ(LTDC->BPCR, 0xfffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->BPCR = 0xffffffff;
  ltdc_set_horizontal_back_porch(0xfff);
  ASSERT_EQ(LTDC->BPCR, ~(0xfffu << 16) | (0xfffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->BPCR = 0;
  ltdc_set_horizontal_back_porch(0x1000);
  ASSERT_EQ(LTDC->BPCR, 0x1000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->BPCR = 0xffffffff;
  ltdc_set_horizontal_back_porch(0x1000);
  ASSERT_EQ(LTDC->BPCR, ~(0xfffu << 16) | (0x1000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_active_height(void)
{
  LTDC->AWCR = 0;
  ltdc_set_active_height(0);
  ASSERT_EQ(LTDC->AWCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->AWCR = 0xffffffff;
  ltdc_set_active_height(0);
  ASSERT_EQ(LTDC->AWCR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->AWCR = 0;
  ltdc_set_active_height(0x7ff);
  ASSERT_EQ(LTDC->AWCR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->AWCR = 0xffffffff;
  ltdc_set_active_height(0x7ff);
  ASSERT_EQ(LTDC->AWCR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->AWCR = 0;
  ltdc_set_active_height(0x800);
  ASSERT_EQ(LTDC->AWCR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->AWCR = 0xffffffff;
  ltdc_set_active_height(0x800);
  ASSERT_EQ(LTDC->AWCR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_active_width(void)
{
  LTDC->AWCR = 0;
  ltdc_set_active_width(0);
  ASSERT_EQ(LTDC->AWCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->AWCR = 0xffffffff;
  ltdc_set_active_width(0);
  ASSERT_EQ(LTDC->AWCR, ~(0xfffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->AWCR = 0;
  ltdc_set_active_width(0xfff);
  ASSERT_EQ(LTDC->AWCR, 0xfffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->AWCR = 0xffffffff;
  ltdc_set_active_width(0xfff);
  ASSERT_EQ(LTDC->AWCR, ~(0xfffu << 16) | (0xfffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->AWCR = 0;
  ltdc_set_active_width(0x1000);
  ASSERT_EQ(LTDC->AWCR, 0x1000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->AWCR = 0xffffffff;
  ltdc_set_active_width(0x1000);
  ASSERT_EQ(LTDC->AWCR, ~(0xfffu << 16) | (0x1000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_total_height(void)
{
  LTDC->TWCR = 0;
  ltdc_set_total_height(0);
  ASSERT_EQ(LTDC->TWCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->TWCR = 0xffffffff;
  ltdc_set_total_height(0);
  ASSERT_EQ(LTDC->TWCR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->TWCR = 0;
  ltdc_set_total_height(0x7ff);
  ASSERT_EQ(LTDC->TWCR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->TWCR = 0xffffffff;
  ltdc_set_total_height(0x7ff);
  ASSERT_EQ(LTDC->TWCR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->TWCR = 0;
  ltdc_set_total_height(0x800);
  ASSERT_EQ(LTDC->TWCR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->TWCR = 0xffffffff;
  ltdc_set_total_height(0x800);
  ASSERT_EQ(LTDC->TWCR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_total_width(void)
{
  LTDC->TWCR = 0;
  ltdc_set_total_width(0);
  ASSERT_EQ(LTDC->TWCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->TWCR = 0xffffffff;
  ltdc_set_total_width(0);
  ASSERT_EQ(LTDC->TWCR, ~(0xfffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->TWCR = 0;
  ltdc_set_total_width(0xfff);
  ASSERT_EQ(LTDC->TWCR, 0xfffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->TWCR = 0xffffffff;
  ltdc_set_total_width(0xfff);
  ASSERT_EQ(LTDC->TWCR, ~(0xfffu << 16) | (0xfffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->TWCR = 0;
  ltdc_set_total_width(0x1000);
  ASSERT_EQ(LTDC->TWCR, 0x1000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->TWCR = 0xffffffff;
  ltdc_set_total_width(0x1000);
  ASSERT_EQ(LTDC->TWCR, ~(0xfffu << 16) | (0x1000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc(void)
{
  LTDC->GCR = 0;
  ltdc_enable();
  ASSERT_EQ(LTDC->GCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(1u << 0);
  ltdc_enable();
  ASSERT_EQ(LTDC->GCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = (1u << 0);
  ltdc_disable();
  ASSERT_EQ(LTDC->GCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0xffffffff;
  ltdc_disable();
  ASSERT_EQ(LTDC->GCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_get_dither_blue_width(void)
{
  u32 res;

  // read_bits
  LTDC->GCR = 0;
  res = ltdc_get_dither_blue_width();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(0x7u << 4);
  res = ltdc_get_dither_blue_width();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0x7u << 4;
  res = ltdc_get_dither_blue_width();
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_get_dither_green_width(void)
{
  u32 res;

  // read_bits
  LTDC->GCR = 0;
  res = ltdc_get_dither_green_width();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(0x7u << 8);
  res = ltdc_get_dither_green_width();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0x7u << 8;
  res = ltdc_get_dither_green_width();
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_get_dither_red_width(void)
{
  u32 res;

  // read_bits
  LTDC->GCR = 0;
  res = ltdc_get_dither_red_width();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(0x7u << 12);
  res = ltdc_get_dither_red_width();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0x7u << 12;
  res = ltdc_get_dither_red_width();
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_dither(void)
{
  LTDC->GCR = 0;
  ltdc_dither_enable();
  ASSERT_EQ(LTDC->GCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(1u << 16);
  ltdc_dither_enable();
  ASSERT_EQ(LTDC->GCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = (1u << 16);
  ltdc_dither_disable();
  ASSERT_EQ(LTDC->GCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0xffffffff;
  ltdc_dither_disable();
  ASSERT_EQ(LTDC->GCR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_set_pixel_clock_polarity(void)
{
  LTDC->GCR = 0;
  ltdc_set_pixel_clock_polarity(LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(1u << 28);
  ltdc_set_pixel_clock_polarity(LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = (1u << 28);
  ltdc_set_pixel_clock_polarity(LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0xffffffff;
  ltdc_set_pixel_clock_polarity(LTDC_PIXEL_CLOCK_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0xffffffff & ~(1u << 28));
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_set_data_enable_polarity(void)
{
  LTDC->GCR = 0;
  ltdc_set_data_enable_polarity(LTDC_DATA_ENABLE_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(1u << 29);
  ltdc_set_data_enable_polarity(LTDC_DATA_ENABLE_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = (1u << 29);
  ltdc_set_data_enable_polarity(LTDC_DATA_ENABLE_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0xffffffff;
  ltdc_set_data_enable_polarity(LTDC_DATA_ENABLE_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0xffffffff & ~(1u << 29));
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_set_vertical_sync_polarity(void)
{
  LTDC->GCR = 0;
  ltdc_set_vertical_sync_polarity(LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(1u << 30);
  ltdc_set_vertical_sync_polarity(LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = (1u << 30);
  ltdc_set_vertical_sync_polarity(LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0xffffffff;
  ltdc_set_vertical_sync_polarity(LTDC_VERTICAL_SYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0xffffffff & ~(1u << 30));
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_set_horizontal_sync_polarity(void)
{
  LTDC->GCR = 0;
  ltdc_set_horizontal_sync_polarity(LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = ~(1u << 31);
  ltdc_set_horizontal_sync_polarity(LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(LTDC->GCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = (1u << 31);
  ltdc_set_horizontal_sync_polarity(LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->GCR = 0xffffffff;
  ltdc_set_horizontal_sync_polarity(LTDC_HORIZONTAL_SYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(LTDC->GCR, 0xffffffff & ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_immediate_reload(void)
{
  LTDC->SRCR = 0;
  ltdc_immediate_reload();
  ASSERT_EQ(LTDC->SRCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->SRCR = ~(1u << 0);
  ltdc_immediate_reload();
  ASSERT_EQ(LTDC->SRCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_vertical_blanking_reload(void)
{
  LTDC->SRCR = 0;
  ltdc_vertical_blanking_reload();
  ASSERT_EQ(LTDC->SRCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  LTDC->SRCR = ~(1u << 1);
  ltdc_vertical_blanking_reload();
  ASSERT_EQ(LTDC->SRCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_set_bg_color_value(void)
{
  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_BLUE, 0);
  ASSERT_EQ(LTDC->BCCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_BLUE, 0);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_BLUE, 0xff);
  ASSERT_EQ(LTDC->BCCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_BLUE, 0xff);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_BLUE, 0x100);
  ASSERT_EQ(LTDC->BCCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_BLUE, 0x100);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_GREEN, 0);
  ASSERT_EQ(LTDC->BCCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_GREEN, 0);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_GREEN, 0xff);
  ASSERT_EQ(LTDC->BCCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_GREEN, 0xff);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_GREEN, 0x100);
  ASSERT_EQ(LTDC->BCCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_GREEN, 0x100);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_RED, 0);
  ASSERT_EQ(LTDC->BCCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_RED, 0);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_RED, 0xff);
  ASSERT_EQ(LTDC->BCCR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_RED, 0xff);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_RED, 0x100);
  ASSERT_EQ(LTDC->BCCR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->BCCR = 0xffffffff;
  ltdc_set_bg_color_value(LTDC_BG_COLOR_RED, 0x100);
  ASSERT_EQ(LTDC->BCCR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_bg_color(void)
{
  LTDC->BCCR = 0;
  ltdc_set_bg_color(0);
  ASSERT_EQ(LTDC->BCCR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color(0xffffff);
  ASSERT_EQ(LTDC->BCCR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->BCCR = 0;
  ltdc_set_bg_color(0x1000000);
  ASSERT_EQ(LTDC->BCCR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_interrupt(void)
{
  LTDC->IER = 0;
  ltdc_interrupt_enable(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(LTDC->IER, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->IER = ~(1u << 0);
  ltdc_interrupt_enable(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(LTDC->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = (1u << 0);
  ltdc_interrupt_disable(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(LTDC->IER, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = 0xffffffff;
  ltdc_interrupt_disable(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(LTDC->IER, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->IER = 0;
  ltdc_interrupt_enable(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(LTDC->IER, (1u << 1));
  ASSERT_FALSE(execution_halted());

  LTDC->IER = ~(1u << 1);
  ltdc_interrupt_enable(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(LTDC->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = (1u << 1);
  ltdc_interrupt_disable(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(LTDC->IER, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = 0xffffffff;
  ltdc_interrupt_disable(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(LTDC->IER, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  LTDC->IER = 0;
  ltdc_interrupt_enable(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(LTDC->IER, (1u << 2));
  ASSERT_FALSE(execution_halted());

  LTDC->IER = ~(1u << 2);
  ltdc_interrupt_enable(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(LTDC->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = (1u << 2);
  ltdc_interrupt_disable(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(LTDC->IER, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = 0xffffffff;
  ltdc_interrupt_disable(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(LTDC->IER, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  LTDC->IER = 0;
  ltdc_interrupt_enable(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(LTDC->IER, (1u << 3));
  ASSERT_FALSE(execution_halted());

  LTDC->IER = ~(1u << 3);
  ltdc_interrupt_enable(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(LTDC->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = (1u << 3);
  ltdc_interrupt_disable(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(LTDC->IER, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->IER = 0xffffffff;
  ltdc_interrupt_disable(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(LTDC->IER, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_is_interrupt_occurred(void)
{
  u32 res;

  LTDC->ISR = 0;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = (1u << 0);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = ~(1u << 0);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = 0xffffffff;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->ISR = 0;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = (1u << 1);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = ~(1u << 1);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = 0xffffffff;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  LTDC->ISR = 0;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = (1u << 2);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = ~(1u << 2);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = 0xffffffff;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  LTDC->ISR = 0;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = (1u << 3);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = ~(1u << 3);
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->ISR = 0xffffffff;
  res = ltdc_is_interrupt_occurred(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_interrupt_clear(void)
{
  LTDC->ICR = 0;
  ltdc_interrupt_clear(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(LTDC->ICR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->ICR = ~(1u << 0);
  ltdc_interrupt_clear(LTDC_INTERRUPT_LINE);
  ASSERT_EQ(LTDC->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  LTDC->ICR = 0;
  ltdc_interrupt_clear(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(LTDC->ICR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  LTDC->ICR = ~(1u << 1);
  ltdc_interrupt_clear(LTDC_INTERRUPT_FIFO_UNDERRUN);
  ASSERT_EQ(LTDC->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  LTDC->ICR = 0;
  ltdc_interrupt_clear(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(LTDC->ICR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  LTDC->ICR = ~(1u << 2);
  ltdc_interrupt_clear(LTDC_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(LTDC->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  LTDC->ICR = 0;
  ltdc_interrupt_clear(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(LTDC->ICR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  LTDC->ICR = ~(1u << 3);
  ltdc_interrupt_clear(LTDC_INTERRUPT_REGISTER_RELOAD);
  ASSERT_EQ(LTDC->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_set_line_interrupt_position(void)
{
  LTDC->LIPCR = 0;
  ltdc_set_line_interrupt_position(0);
  ASSERT_EQ(LTDC->LIPCR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->LIPCR = 0;
  ltdc_set_line_interrupt_position(0x7ff);
  ASSERT_EQ(LTDC->LIPCR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->LIPCR = 0;
  ltdc_set_line_interrupt_position(0x800);
  ASSERT_EQ(LTDC->LIPCR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_get_current_position_y(void)
{
  u32 res;

  // read_bits
  LTDC->CPSR = 0;
  res = ltdc_get_current_position_y();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CPSR = ~(0xffffu << 0);
  res = ltdc_get_current_position_y();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CPSR = 0xffffu << 0;
  res = ltdc_get_current_position_y();
  ASSERT_EQ(res, 0xffff);
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_get_current_position_x(void)
{
  u32 res;

  // read_bits
  LTDC->CPSR = 0;
  res = ltdc_get_current_position_x();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CPSR = ~(0xffffu << 16);
  res = ltdc_get_current_position_x();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CPSR = 0xffffu << 16;
  res = ltdc_get_current_position_x();
  ASSERT_EQ(res, 0xffff);
  ASSERT_FALSE(execution_halted());

}

void
test_ltdc_is_flag_set(void)
{
  u32 res;

  LTDC->CDSR = 0;
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_DATA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = (1u << 0);
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_DATA);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = ~(1u << 0);
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_DATA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = 0xffffffff;
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_DATA);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->CDSR = 0;
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_DATA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = (1u << 1);
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_DATA);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = ~(1u << 1);
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_DATA);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = 0xffffffff;
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_DATA);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  LTDC->CDSR = 0;
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = (1u << 2);
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_SYNC);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = ~(1u << 2);
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = 0xffffffff;
  res = ltdc_is_flag_set(LTDC_FLAG_VERTICAL_SYNC);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  LTDC->CDSR = 0;
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = (1u << 3);
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_SYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = ~(1u << 3);
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_SYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->CDSR = 0xffffffff;
  res = ltdc_is_flag_set(LTDC_FLAG_HORIZONTAL_SYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_layer(void)
{
  LTDC->layers[LTDC_LAYER1].LCR = 0;
  ltdc_layer_enable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = ~(1u << 0);
  ltdc_layer_enable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = (1u << 0);
  ltdc_layer_disable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = 0xffffffff;
  ltdc_layer_disable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCR = 0;
  ltdc_layer_enable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = ~(1u << 0);
  ltdc_layer_enable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = (1u << 0);
  ltdc_layer_disable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = 0xffffffff;
  ltdc_layer_disable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_layer_color_keying(void)
{
  LTDC->layers[LTDC_LAYER1].LCR = 0;
  ltdc_layer_color_keying_enable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = ~(1u << 1);
  ltdc_layer_color_keying_enable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = (1u << 1);
  ltdc_layer_color_keying_disable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = 0xffffffff;
  ltdc_layer_color_keying_disable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCR = 0;
  ltdc_layer_color_keying_enable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = ~(1u << 1);
  ltdc_layer_color_keying_enable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = (1u << 1);
  ltdc_layer_color_keying_disable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = 0xffffffff;
  ltdc_layer_color_keying_disable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_layer_color_lookup_table(void)
{
  LTDC->layers[LTDC_LAYER1].LCR = 0;
  ltdc_layer_color_lookup_table_enable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = ~(1u << 4);
  ltdc_layer_color_lookup_table_enable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = (1u << 4);
  ltdc_layer_color_lookup_table_disable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCR = 0xffffffff;
  ltdc_layer_color_lookup_table_disable(LTDC_LAYER1);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCR = 0;
  ltdc_layer_color_lookup_table_enable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = ~(1u << 4);
  ltdc_layer_color_lookup_table_enable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = (1u << 4);
  ltdc_layer_color_lookup_table_disable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCR = 0xffffffff;
  ltdc_layer_color_lookup_table_disable(LTDC_LAYER2);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_layer_set_window_horizontal_start_position(void)
{
  LTDC->layers[LTDC_LAYER1].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER1, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER1, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER1, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER1, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, ~(0xfffu << 0) | (0x1000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER2, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER2, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER2, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_start_position(LTDC_LAYER2, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, ~(0xfffu << 0) | (0x1000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_layer_set_window_horizontal_stop_position(void)
{
  LTDC->layers[LTDC_LAYER1].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, ~(0xfffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER1, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, 0xfffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER1, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, ~(0xfffu << 16) | (0xfffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER1, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, 0x1000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER1, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWHPCR, ~(0xfffu << 16) | (0x1000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, ~(0xfffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER2, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, 0xfffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER2, 0xfff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, ~(0xfffu << 16) | (0xfffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWHPCR = 0;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER2, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, 0x1000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LWHPCR = 0xffffffff;
  ltdc_layer_set_window_horizontal_stop_position(LTDC_LAYER2, 0x1000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWHPCR, ~(0xfffu << 16) | (0x1000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_layer_set_window_vertical_start_position(void)
{
  LTDC->layers[LTDC_LAYER1].LWVPCR = 0;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWVPCR = 0;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER1, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER1, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWVPCR = 0;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER1, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER1, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LWVPCR = 0;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWVPCR = 0;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER2, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER2, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWVPCR = 0;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER2, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_start_position(LTDC_LAYER2, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_layer_set_window_vertical_stop_position(void)
{
  LTDC->layers[LTDC_LAYER1].LWVPCR = 0;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, ~(0x7ffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWVPCR = 0;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER1, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, 0x7ffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER1, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, ~(0x7ffu << 16) | (0x7ffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LWVPCR = 0;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER1, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, 0x800u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER1, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LWVPCR, ~(0x7ffu << 16) | (0x800u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LWVPCR = 0;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, ~(0x7ffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWVPCR = 0;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER2, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, 0x7ffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER2, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, ~(0x7ffu << 16) | (0x7ffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LWVPCR = 0;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER2, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, 0x800u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LWVPCR = 0xffffffff;
  ltdc_layer_set_window_vertical_stop_position(LTDC_LAYER2, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LWVPCR, ~(0x7ffu << 16) | (0x800u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_keyring_color_value(void)
{
  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER1, LTDC_KEYRING_COLOR_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCKCR = 0xffffffff;
  ltdc_set_layer_keyring_color_value(LTDC_LAYER2, LTDC_KEYRING_COLOR_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_keyring_color(void)
{
  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color(LTDC_LAYER1, 0xffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCKCR = 0;
  ltdc_set_layer_keyring_color(LTDC_LAYER1, 0x1000000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCKCR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color(LTDC_LAYER2, 0xffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCKCR = 0;
  ltdc_set_layer_keyring_color(LTDC_LAYER2, 0x1000000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCKCR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_pixel_format(void)
{
  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_ARGB8888'}, self.value='0b000', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_ARGB8888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_ARGB8888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_RGB888'}, self.value='0b001', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_RGB888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_RGB888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_RGB565'}, self.value='0b010', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_RGB565);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_RGB565);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_ARGB1555'}, self.value='0b011', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_ARGB1555);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_ARGB1555);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_ARGB4444'}, self.value='0b100', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_ARGB4444);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_ARGB4444);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_L8'}, self.value='0b101', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_L8);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b101u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_L8);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_AL44'}, self.value='0b110', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_AL44);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b110u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_AL44);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'format': 'LTDC_PIXEL_FORMAT_AL88'}, self.value='0b111', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_AL88);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, (0b111u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER1, LTDC_PIXEL_FORMAT_AL88);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LPFCR, ~(0x7u << 0) | (0b111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_ARGB8888'}, self.value='0b000', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_ARGB8888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_ARGB8888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_RGB888'}, self.value='0b001', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_RGB888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_RGB888);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_RGB565'}, self.value='0b010', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_RGB565);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_RGB565);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_ARGB1555'}, self.value='0b011', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_ARGB1555);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_ARGB1555);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_ARGB4444'}, self.value='0b100', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_ARGB4444);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_ARGB4444);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_L8'}, self.value='0b101', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_L8);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b101u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_L8);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_AL44'}, self.value='0b110', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_AL44);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b110u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_AL44);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LPFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'format': 'LTDC_PIXEL_FORMAT_AL88'}, self.value='0b111', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LPFCR = 0;
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_AL88);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, (0b111u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LPFCR = ~(0x7u << 0);
  ltdc_set_layer_pixel_format(LTDC_LAYER2, LTDC_PIXEL_FORMAT_AL88);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LPFCR, ~(0x7u << 0) | (0b111u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_set_layer_constant_alpha(void)
{
  LTDC->layers[LTDC_LAYER1].LCACR = 0;
  ltdc_set_layer_constant_alpha(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCACR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCACR = 0xffffffff;
  ltdc_set_layer_constant_alpha(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCACR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCACR = 0;
  ltdc_set_layer_constant_alpha(LTDC_LAYER1, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCACR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCACR = 0xffffffff;
  ltdc_set_layer_constant_alpha(LTDC_LAYER1, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCACR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCACR = 0;
  ltdc_set_layer_constant_alpha(LTDC_LAYER1, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCACR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCACR = 0xffffffff;
  ltdc_set_layer_constant_alpha(LTDC_LAYER1, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCACR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCACR = 0;
  ltdc_set_layer_constant_alpha(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCACR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCACR = 0xffffffff;
  ltdc_set_layer_constant_alpha(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCACR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCACR = 0;
  ltdc_set_layer_constant_alpha(LTDC_LAYER2, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCACR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCACR = 0xffffffff;
  ltdc_set_layer_constant_alpha(LTDC_LAYER2, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCACR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCACR = 0;
  ltdc_set_layer_constant_alpha(LTDC_LAYER2, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCACR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCACR = 0xffffffff;
  ltdc_set_layer_constant_alpha(LTDC_LAYER2, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCACR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_def_color_value(void)
{
  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER1, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color_value(LTDC_LAYER2, LAYER_DEF_COLOR_CHANNEL_ALPHA, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_def_color(void)
{
  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LDCCR = 0;
  ltdc_set_layer_def_color(LTDC_LAYER1, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color(LTDC_LAYER1, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LDCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LDCCR = 0;
  ltdc_set_layer_def_color(LTDC_LAYER2, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LDCCR = 0xffffffff;
  ltdc_set_layer_def_color(LTDC_LAYER2, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LDCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_set_layer_blend_factor2(void)
{
  // scope=self.reg='layers[{layer}].LBFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'factor': 'LTDC_BLEND_FACTOR2_CONST_ALPHA'}, self.value='0b101', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LBFCR = 0;
  ltdc_set_layer_blend_factor2(LTDC_LAYER1, LTDC_BLEND_FACTOR2_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, (0b101u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LBFCR = ~(0x7u << 0);
  ltdc_set_layer_blend_factor2(LTDC_LAYER1, LTDC_BLEND_FACTOR2_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, ~(0x7u << 0) | (0b101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LBFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'factor': 'LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA'}, self.value='0b111', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LBFCR = 0;
  ltdc_set_layer_blend_factor2(LTDC_LAYER1, LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, (0b111u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LBFCR = ~(0x7u << 0);
  ltdc_set_layer_blend_factor2(LTDC_LAYER1, LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, ~(0x7u << 0) | (0b111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LBFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'factor': 'LTDC_BLEND_FACTOR2_CONST_ALPHA'}, self.value='0b101', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LBFCR = 0;
  ltdc_set_layer_blend_factor2(LTDC_LAYER2, LTDC_BLEND_FACTOR2_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, (0b101u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LBFCR = ~(0x7u << 0);
  ltdc_set_layer_blend_factor2(LTDC_LAYER2, LTDC_BLEND_FACTOR2_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, ~(0x7u << 0) | (0b101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LBFCR', self.shift=0, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'factor': 'LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA'}, self.value='0b111', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LBFCR = 0;
  ltdc_set_layer_blend_factor2(LTDC_LAYER2, LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, (0b111u << 0));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LBFCR = ~(0x7u << 0);
  ltdc_set_layer_blend_factor2(LTDC_LAYER2, LTDC_BLEND_FACTOR2_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, ~(0x7u << 0) | (0b111u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_set_layer_blend_factor1(void)
{
  // scope=self.reg='layers[{layer}].LBFCR', self.shift=8, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'factor': 'LTDC_BLEND_FACTOR1_CONST_ALPHA'}, self.value='0b100', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LBFCR = 0;
  ltdc_set_layer_blend_factor1(LTDC_LAYER1, LTDC_BLEND_FACTOR1_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, (0b100u << 8));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LBFCR = ~(0x7u << 8);
  ltdc_set_layer_blend_factor1(LTDC_LAYER1, LTDC_BLEND_FACTOR1_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, ~(0x7u << 8) | (0b100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LBFCR', self.shift=8, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER1', 'factor': 'LTDC_BLEND_FACTOR1_PIXEL_ALPHA_x_CONST_ALPHA'}, self.value='0b110', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER1].LBFCR = 0;
  ltdc_set_layer_blend_factor1(LTDC_LAYER1, LTDC_BLEND_FACTOR1_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, (0b110u << 8));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LBFCR = ~(0x7u << 8);
  ltdc_set_layer_blend_factor1(LTDC_LAYER1, LTDC_BLEND_FACTOR1_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LBFCR, ~(0x7u << 8) | (0b110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LBFCR', self.shift=8, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'factor': 'LTDC_BLEND_FACTOR1_CONST_ALPHA'}, self.value='0b100', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LBFCR = 0;
  ltdc_set_layer_blend_factor1(LTDC_LAYER2, LTDC_BLEND_FACTOR1_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, (0b100u << 8));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LBFCR = ~(0x7u << 8);
  ltdc_set_layer_blend_factor1(LTDC_LAYER2, LTDC_BLEND_FACTOR1_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, ~(0x7u << 8) | (0b100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='layers[{layer}].LBFCR', self.shift=8, self.mask='0x7', self.varsmap={'layer': 'LTDC_LAYER2', 'factor': 'LTDC_BLEND_FACTOR1_PIXEL_ALPHA_x_CONST_ALPHA'}, self.value='0b110', self.ifdef=[], self.halt=False
  LTDC->layers[LTDC_LAYER2].LBFCR = 0;
  ltdc_set_layer_blend_factor1(LTDC_LAYER2, LTDC_BLEND_FACTOR1_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, (0b110u << 8));
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LBFCR = ~(0x7u << 8);
  ltdc_set_layer_blend_factor1(LTDC_LAYER2, LTDC_BLEND_FACTOR1_PIXEL_ALPHA_x_CONST_ALPHA);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LBFCR, ~(0x7u << 8) | (0b110u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_set_layer_color_frame_buffer_start_address(void)
{
  LTDC->layers[LTDC_LAYER1].LCFBAR = 0;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBAR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBAR, 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCFBAR = 0;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER1, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBAR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER1, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBAR = 0;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBAR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBAR, 0);
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBAR = 0;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER2, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBAR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_start_address(LTDC_LAYER2, 0xffffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_ltdc_set_layer_color_frame_buffer_length(void)
{
  LTDC->layers[LTDC_LAYER1].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, ~(0x1fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER1, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, 0x1fffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER1, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, ~(0x1fffu << 0) | (0x1fffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER1, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, 0x2000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER1, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, ~(0x1fffu << 0) | (0x2000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, ~(0x1fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER2, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, 0x1fffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER2, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, ~(0x1fffu << 0) | (0x1fffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER2, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, 0x2000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_length(LTDC_LAYER2, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, ~(0x1fffu << 0) | (0x2000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_color_frame_buffer_pitch(void)
{
  LTDC->layers[LTDC_LAYER1].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, ~(0x1fffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER1, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, 0x1fffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER1, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, ~(0x1fffu << 16) | (0x1fffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER1, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, 0x2000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER1, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLR, ~(0x1fffu << 16) | (0x2000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, ~(0x1fffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER2, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, 0x1fffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER2, 0x1fff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, ~(0x1fffu << 16) | (0x1fffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBLR = 0;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER2, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, 0x2000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCFBLR = 0xffffffff;
  ltdc_set_layer_color_frame_buffer_pitch(LTDC_LAYER2, 0x2000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLR, ~(0x1fffu << 16) | (0x2000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_frame_buffer_line_number(void)
{
  LTDC->layers[LTDC_LAYER1].LCFBLNR = 0;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLNR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBLNR = 0xffffffff;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLNR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCFBLNR = 0;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER1, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLNR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCFBLNR = 0xffffffff;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER1, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLNR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCFBLNR = 0;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER1, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLNR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCFBLNR = 0xffffffff;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER1, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCFBLNR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCFBLNR = 0;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLNR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBLNR = 0xffffffff;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLNR, ~(0x7ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBLNR = 0;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER2, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLNR, 0x7ffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCFBLNR = 0xffffffff;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER2, 0x7ff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLNR, ~(0x7ffu << 0) | (0x7ffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCFBLNR = 0;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER2, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLNR, 0x800u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCFBLNR = 0xffffffff;
  ltdc_set_layer_frame_buffer_line_number(LTDC_LAYER2, 0x800);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCFBLNR, ~(0x7ffu << 0) | (0x800u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_clut_color_value(void)
{
  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER1, LTDC_CLUT_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color_value(LTDC_LAYER2, LTDC_CLUT_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_clut_color(void)
{
  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color(LTDC_LAYER1, 0xffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color(LTDC_LAYER1, 0xffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffffffu << 0) | (0xffffffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_color(LTDC_LAYER1, 0x1000000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color(LTDC_LAYER1, 0x1000000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffffffu << 0) | (0x1000000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color(LTDC_LAYER2, 0xffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color(LTDC_LAYER2, 0xffffff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffffffu << 0) | (0xffffffu << 0));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_color(LTDC_LAYER2, 0x1000000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_color(LTDC_LAYER2, 0x1000000);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffffffu << 0) | (0x1000000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_ltdc_set_layer_clut_address(void)
{
  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_address(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_address(LTDC_LAYER1, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_address(LTDC_LAYER1, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_address(LTDC_LAYER1, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0;
  ltdc_set_layer_clut_address(LTDC_LAYER1, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER1].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_address(LTDC_LAYER1, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER1].LCLUTWR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_address(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_address(LTDC_LAYER2, 0);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_address(LTDC_LAYER2, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_address(LTDC_LAYER2, 0xff);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0;
  ltdc_set_layer_clut_address(LTDC_LAYER2, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  LTDC->layers[LTDC_LAYER2].LCLUTWR = 0xffffffff;
  ltdc_set_layer_clut_address(LTDC_LAYER2, 0x100);
  ASSERT_EQ(LTDC->layers[LTDC_LAYER2].LCLUTWR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_ltdc_set_sync_height),
    TEST_FUNC(test_ltdc_set_sync_width),
    TEST_FUNC(test_ltdc_set_vertical_back_porch),
    TEST_FUNC(test_ltdc_set_horizontal_back_porch),
    TEST_FUNC(test_ltdc_set_active_height),
    TEST_FUNC(test_ltdc_set_active_width),
    TEST_FUNC(test_ltdc_set_total_height),
    TEST_FUNC(test_ltdc_set_total_width),
    TEST_FUNC(test_ltdc),
    TEST_FUNC(test_ltdc_get_dither_blue_width),
    TEST_FUNC(test_ltdc_get_dither_green_width),
    TEST_FUNC(test_ltdc_get_dither_red_width),
    TEST_FUNC(test_ltdc_dither),
    TEST_FUNC(test_ltdc_set_pixel_clock_polarity),
    TEST_FUNC(test_ltdc_set_data_enable_polarity),
    TEST_FUNC(test_ltdc_set_vertical_sync_polarity),
    TEST_FUNC(test_ltdc_set_horizontal_sync_polarity),
    TEST_FUNC(test_ltdc_immediate_reload),
    TEST_FUNC(test_ltdc_vertical_blanking_reload),
    TEST_FUNC(test_ltdc_set_bg_color_value),
    TEST_FUNC(test_ltdc_set_bg_color),
    TEST_FUNC(test_ltdc_interrupt),
    TEST_FUNC(test_ltdc_is_interrupt_occurred),
    TEST_FUNC(test_ltdc_interrupt_clear),
    TEST_FUNC(test_ltdc_set_line_interrupt_position),
    TEST_FUNC(test_ltdc_get_current_position_y),
    TEST_FUNC(test_ltdc_get_current_position_x),
    TEST_FUNC(test_ltdc_is_flag_set),
    TEST_FUNC(test_ltdc_layer),
    TEST_FUNC(test_ltdc_layer_color_keying),
    TEST_FUNC(test_ltdc_layer_color_lookup_table),
    TEST_FUNC(test_ltdc_layer_set_window_horizontal_start_position),
    TEST_FUNC(test_ltdc_layer_set_window_horizontal_stop_position),
    TEST_FUNC(test_ltdc_layer_set_window_vertical_start_position),
    TEST_FUNC(test_ltdc_layer_set_window_vertical_stop_position),
    TEST_FUNC(test_ltdc_set_layer_keyring_color_value),
    TEST_FUNC(test_ltdc_set_layer_keyring_color),
    TEST_FUNC(test_ltdc_set_layer_pixel_format),
    TEST_FUNC(test_ltdc_set_layer_constant_alpha),
    TEST_FUNC(test_ltdc_set_layer_def_color_value),
    TEST_FUNC(test_ltdc_set_layer_def_color),
    TEST_FUNC(test_ltdc_set_layer_blend_factor2),
    TEST_FUNC(test_ltdc_set_layer_blend_factor1),
    TEST_FUNC(test_ltdc_set_layer_color_frame_buffer_start_address),
    TEST_FUNC(test_ltdc_set_layer_color_frame_buffer_length),
    TEST_FUNC(test_ltdc_set_layer_color_frame_buffer_pitch),
    TEST_FUNC(test_ltdc_set_layer_frame_buffer_line_number),
    TEST_FUNC(test_ltdc_set_layer_clut_color_value),
    TEST_FUNC(test_ltdc_set_layer_clut_color),
    TEST_FUNC(test_ltdc_set_layer_clut_address),
  };

  return TESTS_RUN(tests);
}
