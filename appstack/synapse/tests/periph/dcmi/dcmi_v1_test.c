#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/dcmi/dcmi_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  DCMI = (struct dcmi_registers_map*) membuf;
}

void
test_dcmi_capture(void)
{
  DCMI->CR = 0;
  dcmi_capture_enable();
  ASSERT_EQ(DCMI->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 0);
  dcmi_capture_enable();
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 0);
  dcmi_capture_disable();
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_capture_disable();
  ASSERT_EQ(DCMI->CR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_capture_mode(void)
{
  DCMI->CR = 0;
  dcmi_set_capture_mode(DCMI_CAPTURE_MODE_SNAPSHOT);
  ASSERT_EQ(DCMI->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 1);
  dcmi_set_capture_mode(DCMI_CAPTURE_MODE_SNAPSHOT);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 1);
  dcmi_set_capture_mode(DCMI_CAPTURE_MODE_CONTINUOUS);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_capture_mode(DCMI_CAPTURE_MODE_CONTINUOUS);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_image_crop(void)
{
  DCMI->CR = 0;
  dcmi_set_image_crop(DCMI_IMAGE_CROP_WINDOW);
  ASSERT_EQ(DCMI->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 2);
  dcmi_set_image_crop(DCMI_IMAGE_CROP_WINDOW);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 2);
  dcmi_set_image_crop(DCMI_IMAGE_CROP_FULL_IMAGE);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_image_crop(DCMI_IMAGE_CROP_FULL_IMAGE);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_jpeg_format(void)
{
  DCMI->CR = 0;
  dcmi_set_jpeg_format(DCMI_JPEG_FORMAT_JPEG);
  ASSERT_EQ(DCMI->CR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 3);
  dcmi_set_jpeg_format(DCMI_JPEG_FORMAT_JPEG);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 3);
  dcmi_set_jpeg_format(DCMI_JPEG_FORMAT_UNCOMPRESSED);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_jpeg_format(DCMI_JPEG_FORMAT_UNCOMPRESSED);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_embedded_sync(void)
{
  DCMI->CR = 0;
  dcmi_set_embedded_sync(DCMI_EMBEDDED_SYNC_DATA_FLOW);
  ASSERT_EQ(DCMI->CR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 4);
  dcmi_set_embedded_sync(DCMI_EMBEDDED_SYNC_DATA_FLOW);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 4);
  dcmi_set_embedded_sync(DCMI_EMBEDDED_SYNC_HARDWARE);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_embedded_sync(DCMI_EMBEDDED_SYNC_HARDWARE);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_pixel_clock_polarity(void)
{
  DCMI->CR = 0;
  dcmi_set_pixel_clock_polarity(DCMI_PIXEL_CLOCK_POLARITY_RISING_EDGE);
  ASSERT_EQ(DCMI->CR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 5);
  dcmi_set_pixel_clock_polarity(DCMI_PIXEL_CLOCK_POLARITY_RISING_EDGE);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 5);
  dcmi_set_pixel_clock_polarity(DCMI_PIXEL_CLOCK_POLARITY_FALLING_EDGE);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_pixel_clock_polarity(DCMI_PIXEL_CLOCK_POLARITY_FALLING_EDGE);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_hsync_polarity(void)
{
  DCMI->CR = 0;
  dcmi_set_hsync_polarity(DCMI_HSYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(DCMI->CR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 6);
  dcmi_set_hsync_polarity(DCMI_HSYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 6);
  dcmi_set_hsync_polarity(DCMI_HSYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_hsync_polarity(DCMI_HSYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_vsync_polarity(void)
{
  DCMI->CR = 0;
  dcmi_set_vsync_polarity(DCMI_VSYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(DCMI->CR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 7);
  dcmi_set_vsync_polarity(DCMI_VSYNC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 7);
  dcmi_set_vsync_polarity(DCMI_VSYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_vsync_polarity(DCMI_VSYNC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_dcmi_set_frame_capture_rate(void)
{
  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'rate': 'DCMI_FRAME_CAPTURE_RATE_ALL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_frame_capture_rate(DCMI_FRAME_CAPTURE_RATE_ALL);
  ASSERT_EQ(DCMI->CR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 8);
  dcmi_set_frame_capture_rate(DCMI_FRAME_CAPTURE_RATE_ALL);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'rate': 'DCMI_FRAME_CAPTURE_RATE_SKIP2'}, self.value='0b01', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_frame_capture_rate(DCMI_FRAME_CAPTURE_RATE_SKIP2);
  ASSERT_EQ(DCMI->CR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 8);
  dcmi_set_frame_capture_rate(DCMI_FRAME_CAPTURE_RATE_SKIP2);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'rate': 'DCMI_FRAME_CAPTURE_RATE_SKIP4'}, self.value='0b10', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_frame_capture_rate(DCMI_FRAME_CAPTURE_RATE_SKIP4);
  ASSERT_EQ(DCMI->CR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 8);
  dcmi_set_frame_capture_rate(DCMI_FRAME_CAPTURE_RATE_SKIP4);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_dcmi_set_extended_data_mode(void)
{
  // scope=self.reg='CR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'DCMI_EXTENDED_DATA_MODE_8BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_8BIT);
  ASSERT_EQ(DCMI->CR, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 10);
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_8BIT);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'DCMI_EXTENDED_DATA_MODE_10BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_10BIT);
  ASSERT_EQ(DCMI->CR, (0b01u << 10));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 10);
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_10BIT);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 10) | (0b01u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'DCMI_EXTENDED_DATA_MODE_12BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_12BIT);
  ASSERT_EQ(DCMI->CR, (0b10u << 10));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 10);
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_12BIT);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 10) | (0b10u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=10, self.mask='0x3', self.varsmap={'mode': 'DCMI_EXTENDED_DATA_MODE_14BIT'}, self.value='0b11', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_14BIT);
  ASSERT_EQ(DCMI->CR, (0b11u << 10));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 10);
  dcmi_set_extended_data_mode(DCMI_EXTENDED_DATA_MODE_14BIT);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 10) | (0b11u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_dcmi(void)
{
  DCMI->CR = 0;
  dcmi_enable();
  ASSERT_EQ(DCMI->CR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 14);
  dcmi_enable();
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 14);
  dcmi_disable();
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_disable();
  ASSERT_EQ(DCMI->CR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_DCMI_CR_EXTENDED)
void
test_dcmi_set_byte_capture_mode(void)
{
  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DCMI_BYTE_CAPTURE_MODE_ALL'}, self.value='0b00', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_ALL);
  ASSERT_EQ(DCMI->CR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 16);
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_ALL);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DCMI_BYTE_CAPTURE_MODE_SKIP1'}, self.value='0b01', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_SKIP1);
  ASSERT_EQ(DCMI->CR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 16);
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_SKIP1);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DCMI_BYTE_CAPTURE_MODE_SKIP3'}, self.value='0b10', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_SKIP3);
  ASSERT_EQ(DCMI->CR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 16);
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_SKIP3);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DCMI_BYTE_CAPTURE_MODE_SKIP2'}, self.value='0b11', self.ifdef=[], self.halt=False
  DCMI->CR = 0;
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_SKIP2);
  ASSERT_EQ(DCMI->CR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(0x3u << 16);
  dcmi_set_byte_capture_mode(DCMI_BYTE_CAPTURE_MODE_SKIP2);
  ASSERT_EQ(DCMI->CR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_DCMI_CR_EXTENDED)
void
test_dcmi_set_byte_capture_start(void)
{
  DCMI->CR = 0;
  dcmi_set_byte_capture_start(DCMI_BYTE_CAPTURE_START_ODD);
  ASSERT_EQ(DCMI->CR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 18);
  dcmi_set_byte_capture_start(DCMI_BYTE_CAPTURE_START_ODD);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 18);
  dcmi_set_byte_capture_start(DCMI_BYTE_CAPTURE_START_EVEN);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_byte_capture_start(DCMI_BYTE_CAPTURE_START_EVEN);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_DCMI_CR_EXTENDED)
void
test_dcmi_set_line_capture_mode(void)
{
  DCMI->CR = 0;
  dcmi_set_line_capture_mode(DCMI_LINE_CAPTURE_MODE_ALTERNATE);
  ASSERT_EQ(DCMI->CR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 19);
  dcmi_set_line_capture_mode(DCMI_LINE_CAPTURE_MODE_ALTERNATE);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 19);
  dcmi_set_line_capture_mode(DCMI_LINE_CAPTURE_MODE_ALL);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_line_capture_mode(DCMI_LINE_CAPTURE_MODE_ALL);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 19));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_DCMI_CR_EXTENDED)
void
test_dcmi_set_line_capture_start(void)
{
  DCMI->CR = 0;
  dcmi_set_line_capture_start(DCMI_LINE_CAPTURE_START_ODD);
  ASSERT_EQ(DCMI->CR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  DCMI->CR = ~(1u << 20);
  dcmi_set_line_capture_start(DCMI_LINE_CAPTURE_START_ODD);
  ASSERT_EQ(DCMI->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = (1u << 20);
  dcmi_set_line_capture_start(DCMI_LINE_CAPTURE_START_EVEN);
  ASSERT_EQ(DCMI->CR, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CR = 0xffffffff;
  dcmi_set_line_capture_start(DCMI_LINE_CAPTURE_START_EVEN);
  ASSERT_EQ(DCMI->CR, 0xffffffff & ~(1u << 20));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_dcmi_is_flag_set(void)
{
  u32 res;

  DCMI->SR = 0;
  res = dcmi_is_flag_set(DCMI_FLAG_HSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->SR = (1u << 0);
  res = dcmi_is_flag_set(DCMI_FLAG_HSYNC);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DCMI->SR = ~(1u << 0);
  res = dcmi_is_flag_set(DCMI_FLAG_HSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->SR = 0xffffffff;
  res = dcmi_is_flag_set(DCMI_FLAG_HSYNC);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->SR = 0;
  res = dcmi_is_flag_set(DCMI_FLAG_VSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->SR = (1u << 1);
  res = dcmi_is_flag_set(DCMI_FLAG_VSYNC);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DCMI->SR = ~(1u << 1);
  res = dcmi_is_flag_set(DCMI_FLAG_VSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->SR = 0xffffffff;
  res = dcmi_is_flag_set(DCMI_FLAG_VSYNC);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  DCMI->SR = 0;
  res = dcmi_is_flag_set(DCMI_FLAG_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->SR = (1u << 2);
  res = dcmi_is_flag_set(DCMI_FLAG_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DCMI->SR = ~(1u << 2);
  res = dcmi_is_flag_set(DCMI_FLAG_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->SR = 0xffffffff;
  res = dcmi_is_flag_set(DCMI_FLAG_FIFO_NOT_EMPTY);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


}

void
test_dcmi_is_interrupt_event_occurred(void)
{
  u32 res;

  DCMI->RIS = 0;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = (1u << 0);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = ~(1u << 0);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = 0xffffffff;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->RIS = 0;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = (1u << 1);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = ~(1u << 1);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = 0xffffffff;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  DCMI->RIS = 0;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = (1u << 2);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = ~(1u << 2);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = 0xffffffff;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  DCMI->RIS = 0;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = (1u << 3);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = ~(1u << 3);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = 0xffffffff;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  DCMI->RIS = 0;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = (1u << 4);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = ~(1u << 4);
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->RIS = 0xffffffff;
  res = dcmi_is_interrupt_event_occurred(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_dcmi_interrupt(void)
{
  DCMI->IER = 0;
  dcmi_interrupt_enable(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(DCMI->IER, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DCMI->IER = ~(1u << 0);
  dcmi_interrupt_enable(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(DCMI->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = (1u << 0);
  dcmi_interrupt_disable(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(DCMI->IER, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = 0xffffffff;
  dcmi_interrupt_disable(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(DCMI->IER, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->IER = 0;
  dcmi_interrupt_enable(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(DCMI->IER, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DCMI->IER = ~(1u << 1);
  dcmi_interrupt_enable(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(DCMI->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = (1u << 1);
  dcmi_interrupt_disable(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(DCMI->IER, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = 0xffffffff;
  dcmi_interrupt_disable(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(DCMI->IER, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  DCMI->IER = 0;
  dcmi_interrupt_enable(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(DCMI->IER, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DCMI->IER = ~(1u << 2);
  dcmi_interrupt_enable(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(DCMI->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = (1u << 2);
  dcmi_interrupt_disable(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(DCMI->IER, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = 0xffffffff;
  dcmi_interrupt_disable(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(DCMI->IER, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  DCMI->IER = 0;
  dcmi_interrupt_enable(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(DCMI->IER, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DCMI->IER = ~(1u << 3);
  dcmi_interrupt_enable(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(DCMI->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = (1u << 3);
  dcmi_interrupt_disable(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(DCMI->IER, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = 0xffffffff;
  dcmi_interrupt_disable(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(DCMI->IER, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  DCMI->IER = 0;
  dcmi_interrupt_enable(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(DCMI->IER, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DCMI->IER = ~(1u << 4);
  dcmi_interrupt_enable(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(DCMI->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = (1u << 4);
  dcmi_interrupt_disable(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(DCMI->IER, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->IER = 0xffffffff;
  dcmi_interrupt_disable(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(DCMI->IER, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_dcmi_is_interrupt_pending(void)
{
  u32 res;

  DCMI->MIS = 0;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = (1u << 0);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = ~(1u << 0);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = 0xffffffff;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->MIS = 0;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = (1u << 1);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = ~(1u << 1);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = 0xffffffff;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  DCMI->MIS = 0;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = (1u << 2);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = ~(1u << 2);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = 0xffffffff;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  DCMI->MIS = 0;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = (1u << 3);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = ~(1u << 3);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = 0xffffffff;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  DCMI->MIS = 0;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = (1u << 4);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = ~(1u << 4);
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->MIS = 0xffffffff;
  res = dcmi_is_interrupt_pending(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_dcmi_interrupt_pending_clear(void)
{
  DCMI->ICR = 0;
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(DCMI->ICR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DCMI->ICR = ~(1u << 0);
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_CAPTURE_COMPLETE);
  ASSERT_EQ(DCMI->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DCMI->ICR = 0;
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(DCMI->ICR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DCMI->ICR = ~(1u << 1);
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_OVERRUN);
  ASSERT_EQ(DCMI->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DCMI->ICR = 0;
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(DCMI->ICR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DCMI->ICR = ~(1u << 2);
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_SYNC_ERROR);
  ASSERT_EQ(DCMI->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DCMI->ICR = 0;
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(DCMI->ICR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DCMI->ICR = ~(1u << 3);
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_VSYNC);
  ASSERT_EQ(DCMI->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DCMI->ICR = 0;
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(DCMI->ICR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DCMI->ICR = ~(1u << 4);
  dcmi_interrupt_pending_clear(DCMI_INTERRUPT_LINE);
  ASSERT_EQ(DCMI->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dcmi_set_delimiter(void)
{
  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_START, 0);
  ASSERT_EQ(DCMI->ESCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_START, 0);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_START, 0xff);
  ASSERT_EQ(DCMI->ESCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_START, 0xff);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_START, 0x100);
  ASSERT_EQ(DCMI->ESCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_START, 0x100);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_START, 0);
  ASSERT_EQ(DCMI->ESCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_START, 0);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_START, 0xff);
  ASSERT_EQ(DCMI->ESCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_START, 0xff);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_START, 0x100);
  ASSERT_EQ(DCMI->ESCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_START, 0x100);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_END, 0);
  ASSERT_EQ(DCMI->ESCR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_END, 0);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_END, 0xff);
  ASSERT_EQ(DCMI->ESCR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_END, 0xff);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_END, 0x100);
  ASSERT_EQ(DCMI->ESCR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_LINE_END, 0x100);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_END, 0);
  ASSERT_EQ(DCMI->ESCR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_END, 0);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_END, 0xff);
  ASSERT_EQ(DCMI->ESCR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_END, 0xff);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  DCMI->ESCR = 0;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_END, 0x100);
  ASSERT_EQ(DCMI->ESCR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESCR = 0xffffffff;
  dcmi_set_delimiter(DCMI_DELIMITER_FRAME_END, 0x100);
  ASSERT_EQ(DCMI->ESCR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dcmi_set_delimiter_unmask(void)
{
  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_START, 0);
  ASSERT_EQ(DCMI->ESUR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_START, 0);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_START, 0xff);
  ASSERT_EQ(DCMI->ESUR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_START, 0xff);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_START, 0x100);
  ASSERT_EQ(DCMI->ESUR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_START, 0x100);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_START, 0);
  ASSERT_EQ(DCMI->ESUR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_START, 0);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_START, 0xff);
  ASSERT_EQ(DCMI->ESUR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_START, 0xff);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_START, 0x100);
  ASSERT_EQ(DCMI->ESUR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_START, 0x100);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_END, 0);
  ASSERT_EQ(DCMI->ESUR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_END, 0);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_END, 0xff);
  ASSERT_EQ(DCMI->ESUR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_END, 0xff);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_END, 0x100);
  ASSERT_EQ(DCMI->ESUR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_LINE_END, 0x100);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_END, 0);
  ASSERT_EQ(DCMI->ESUR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_END, 0);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_END, 0xff);
  ASSERT_EQ(DCMI->ESUR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_END, 0xff);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  DCMI->ESUR = 0;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_END, 0x100);
  ASSERT_EQ(DCMI->ESUR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->ESUR = 0xffffffff;
  dcmi_set_delimiter_unmask(DCMI_DELIMITER_FRAME_END, 0x100);
  ASSERT_EQ(DCMI->ESUR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dcmi_set_horizontal_offset(void)
{
  DCMI->CWSTRT = 0;
  dcmi_set_horizontal_offset(0);
  ASSERT_EQ(DCMI->CWSTRT, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSTRT = 0xffffffff;
  dcmi_set_horizontal_offset(0);
  ASSERT_EQ(DCMI->CWSTRT, ~(0x3fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSTRT = 0;
  dcmi_set_horizontal_offset(0x3fff);
  ASSERT_EQ(DCMI->CWSTRT, 0x3fffu << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSTRT = 0xffffffff;
  dcmi_set_horizontal_offset(0x3fff);
  ASSERT_EQ(DCMI->CWSTRT, ~(0x3fffu << 0) | (0x3fffu << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSTRT = 0;
  dcmi_set_horizontal_offset(0x4000);
  ASSERT_EQ(DCMI->CWSTRT, 0x4000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->CWSTRT = 0xffffffff;
  dcmi_set_horizontal_offset(0x4000);
  ASSERT_EQ(DCMI->CWSTRT, ~(0x3fffu << 0) | (0x4000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dcmi_set_vertical_start_line(void)
{
  DCMI->CWSTRT = 0;
  dcmi_set_vertical_start_line(0);
  ASSERT_EQ(DCMI->CWSTRT, 0u << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSTRT = 0xffffffff;
  dcmi_set_vertical_start_line(0);
  ASSERT_EQ(DCMI->CWSTRT, ~(0x1fffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSTRT = 0;
  dcmi_set_vertical_start_line(0x1fff);
  ASSERT_EQ(DCMI->CWSTRT, 0x1fffu << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSTRT = 0xffffffff;
  dcmi_set_vertical_start_line(0x1fff);
  ASSERT_EQ(DCMI->CWSTRT, ~(0x1fffu << 16) | (0x1fffu << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSTRT = 0;
  dcmi_set_vertical_start_line(0x2000);
  ASSERT_EQ(DCMI->CWSTRT, 0x2000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->CWSTRT = 0xffffffff;
  dcmi_set_vertical_start_line(0x2000);
  ASSERT_EQ(DCMI->CWSTRT, ~(0x1fffu << 16) | (0x2000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dcmi_set_capture_count(void)
{
  DCMI->CWSIZE = 0;
  dcmi_set_capture_count(0);
  ASSERT_EQ(DCMI->CWSIZE, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSIZE = 0xffffffff;
  dcmi_set_capture_count(0);
  ASSERT_EQ(DCMI->CWSIZE, ~(0x3fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSIZE = 0;
  dcmi_set_capture_count(0x3fff);
  ASSERT_EQ(DCMI->CWSIZE, 0x3fffu << 0);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSIZE = 0xffffffff;
  dcmi_set_capture_count(0x3fff);
  ASSERT_EQ(DCMI->CWSIZE, ~(0x3fffu << 0) | (0x3fffu << 0));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSIZE = 0;
  dcmi_set_capture_count(0x4000);
  ASSERT_EQ(DCMI->CWSIZE, 0x4000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->CWSIZE = 0xffffffff;
  dcmi_set_capture_count(0x4000);
  ASSERT_EQ(DCMI->CWSIZE, ~(0x3fffu << 0) | (0x4000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dcmi_set_vertical_line_count(void)
{
  DCMI->CWSIZE = 0;
  dcmi_set_vertical_line_count(0);
  ASSERT_EQ(DCMI->CWSIZE, 0u << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSIZE = 0xffffffff;
  dcmi_set_vertical_line_count(0);
  ASSERT_EQ(DCMI->CWSIZE, ~(0x3fffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSIZE = 0;
  dcmi_set_vertical_line_count(0x3fff);
  ASSERT_EQ(DCMI->CWSIZE, 0x3fffu << 16);
  ASSERT_FALSE(execution_halted());

  DCMI->CWSIZE = 0xffffffff;
  dcmi_set_vertical_line_count(0x3fff);
  ASSERT_EQ(DCMI->CWSIZE, ~(0x3fffu << 16) | (0x3fffu << 16));
  ASSERT_FALSE(execution_halted());


  DCMI->CWSIZE = 0;
  dcmi_set_vertical_line_count(0x4000);
  ASSERT_EQ(DCMI->CWSIZE, 0x4000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DCMI->CWSIZE = 0xffffffff;
  dcmi_set_vertical_line_count(0x4000);
  ASSERT_EQ(DCMI->CWSIZE, ~(0x3fffu << 16) | (0x4000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dcmi_data_read(void)
{
  u32 res;

  // read_reg
  DCMI->DR = 0;
  res = dcmi_data_read();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DCMI->DR = 0xffffffff;
  res = dcmi_data_read();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_dcmi_capture),
    TEST_FUNC(test_dcmi_set_capture_mode),
    TEST_FUNC(test_dcmi_set_image_crop),
    TEST_FUNC(test_dcmi_set_jpeg_format),
    TEST_FUNC(test_dcmi_set_embedded_sync),
    TEST_FUNC(test_dcmi_set_pixel_clock_polarity),
    TEST_FUNC(test_dcmi_set_hsync_polarity),
    TEST_FUNC(test_dcmi_set_vsync_polarity),
    TEST_FUNC(test_dcmi_set_frame_capture_rate),
    TEST_FUNC(test_dcmi_set_extended_data_mode),
    TEST_FUNC(test_dcmi),
#if defined(STM32_DCMI_CR_EXTENDED)
    TEST_FUNC(test_dcmi_set_byte_capture_mode),
#endif
#if defined(STM32_DCMI_CR_EXTENDED)
    TEST_FUNC(test_dcmi_set_byte_capture_start),
#endif
#if defined(STM32_DCMI_CR_EXTENDED)
    TEST_FUNC(test_dcmi_set_line_capture_mode),
#endif
#if defined(STM32_DCMI_CR_EXTENDED)
    TEST_FUNC(test_dcmi_set_line_capture_start),
#endif
    TEST_FUNC(test_dcmi_is_flag_set),
    TEST_FUNC(test_dcmi_is_interrupt_event_occurred),
    TEST_FUNC(test_dcmi_interrupt),
    TEST_FUNC(test_dcmi_is_interrupt_pending),
    TEST_FUNC(test_dcmi_interrupt_pending_clear),
    TEST_FUNC(test_dcmi_set_delimiter),
    TEST_FUNC(test_dcmi_set_delimiter_unmask),
    TEST_FUNC(test_dcmi_set_horizontal_offset),
    TEST_FUNC(test_dcmi_set_vertical_start_line),
    TEST_FUNC(test_dcmi_set_capture_count),
    TEST_FUNC(test_dcmi_set_vertical_line_count),
    TEST_FUNC(test_dcmi_data_read),
  };

  return TESTS_RUN(tests);
}
