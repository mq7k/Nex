#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/dma2d/dma2d_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  DMA2D = (struct dma2d_registers_map*) membuf;
}

void
test_dma2d_start(void)
{
  DMA2D->CR = 0;
  dma2d_start();
  ASSERT_EQ(DMA2D->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 0);
  dma2d_start();
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_suspend(void)
{
  DMA2D->CR = 0;
  dma2d_suspend();
  ASSERT_EQ(DMA2D->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 1);
  dma2d_suspend();
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_abort(void)
{
  DMA2D->CR = 0;
  dma2d_abort();
  ASSERT_EQ(DMA2D->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 2);
  dma2d_abort();
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_interrupt(void)
{
  DMA2D->CR = 0;
  dma2d_interrupt_enable(DMA2D_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA2D->CR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 8);
  dma2d_interrupt_enable(DMA2D_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = (1u << 8);
  dma2d_interrupt_disable(DMA2D_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA2D->CR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = 0xffffffff;
  dma2d_interrupt_disable(DMA2D_INTERRUPT_TRANSFER_ERROR);
  ASSERT_EQ(DMA2D->CR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->CR = 0;
  dma2d_interrupt_enable(DMA2D_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 9);
  dma2d_interrupt_enable(DMA2D_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = (1u << 9);
  dma2d_interrupt_disable(DMA2D_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = 0xffffffff;
  dma2d_interrupt_disable(DMA2D_INTERRUPT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  DMA2D->CR = 0;
  dma2d_interrupt_enable(DMA2D_INTERRUPT_TRANSFER_WATERMARK);
  ASSERT_EQ(DMA2D->CR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 10);
  dma2d_interrupt_enable(DMA2D_INTERRUPT_TRANSFER_WATERMARK);
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = (1u << 10);
  dma2d_interrupt_disable(DMA2D_INTERRUPT_TRANSFER_WATERMARK);
  ASSERT_EQ(DMA2D->CR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = 0xffffffff;
  dma2d_interrupt_disable(DMA2D_INTERRUPT_TRANSFER_WATERMARK);
  ASSERT_EQ(DMA2D->CR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  DMA2D->CR = 0;
  dma2d_interrupt_enable(DMA2D_INTERRUPT_CLUT_ACCESS_ERROR);
  ASSERT_EQ(DMA2D->CR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 11);
  dma2d_interrupt_enable(DMA2D_INTERRUPT_CLUT_ACCESS_ERROR);
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = (1u << 11);
  dma2d_interrupt_disable(DMA2D_INTERRUPT_CLUT_ACCESS_ERROR);
  ASSERT_EQ(DMA2D->CR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = 0xffffffff;
  dma2d_interrupt_disable(DMA2D_INTERRUPT_CLUT_ACCESS_ERROR);
  ASSERT_EQ(DMA2D->CR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  DMA2D->CR = 0;
  dma2d_interrupt_enable(DMA2D_INTERRUPT_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 12);
  dma2d_interrupt_enable(DMA2D_INTERRUPT_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = (1u << 12);
  dma2d_interrupt_disable(DMA2D_INTERRUPT_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = 0xffffffff;
  dma2d_interrupt_disable(DMA2D_INTERRUPT_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->CR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  DMA2D->CR = 0;
  dma2d_interrupt_enable(DMA2D_INTERRUPT_CONFIGURATION_ERROR);
  ASSERT_EQ(DMA2D->CR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(1u << 13);
  dma2d_interrupt_enable(DMA2D_INTERRUPT_CONFIGURATION_ERROR);
  ASSERT_EQ(DMA2D->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = (1u << 13);
  dma2d_interrupt_disable(DMA2D_INTERRUPT_CONFIGURATION_ERROR);
  ASSERT_EQ(DMA2D->CR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = 0xffffffff;
  dma2d_interrupt_disable(DMA2D_INTERRUPT_CONFIGURATION_ERROR);
  ASSERT_EQ(DMA2D->CR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_mode(void)
{
  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_MODE_MEMORY_TO_MEMORY_FG'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA2D->CR = 0;
  dma2d_set_mode(DMA2D_MODE_MEMORY_TO_MEMORY_FG);
  ASSERT_EQ(DMA2D->CR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(0x3u << 16);
  dma2d_set_mode(DMA2D_MODE_MEMORY_TO_MEMORY_FG);
  ASSERT_EQ(DMA2D->CR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_MODE_MEMORY_TO_MEMORY_PFC'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA2D->CR = 0;
  dma2d_set_mode(DMA2D_MODE_MEMORY_TO_MEMORY_PFC);
  ASSERT_EQ(DMA2D->CR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(0x3u << 16);
  dma2d_set_mode(DMA2D_MODE_MEMORY_TO_MEMORY_PFC);
  ASSERT_EQ(DMA2D->CR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_MODE_MEMORY_TO_MEMORY_BLENDING'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA2D->CR = 0;
  dma2d_set_mode(DMA2D_MODE_MEMORY_TO_MEMORY_BLENDING);
  ASSERT_EQ(DMA2D->CR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(0x3u << 16);
  dma2d_set_mode(DMA2D_MODE_MEMORY_TO_MEMORY_BLENDING);
  ASSERT_EQ(DMA2D->CR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_MODE_REGISTER_TO_MEMORY'}, self.value='0b11', self.ifdef=[], self.halt=False
  DMA2D->CR = 0;
  dma2d_set_mode(DMA2D_MODE_REGISTER_TO_MEMORY);
  ASSERT_EQ(DMA2D->CR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->CR = ~(0x3u << 16);
  dma2d_set_mode(DMA2D_MODE_REGISTER_TO_MEMORY);
  ASSERT_EQ(DMA2D->CR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_is_flag_set(void)
{
  u32 res;

  DMA2D->ISR = 0;
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = (1u << 0);
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = ~(1u << 0);
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = 0xffffffff;
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->ISR = 0;
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = (1u << 1);
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = ~(1u << 1);
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = 0xffffffff;
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  DMA2D->ISR = 0;
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_WATERMARK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = (1u << 2);
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_WATERMARK);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = ~(1u << 2);
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_WATERMARK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = 0xffffffff;
  res = dma2d_is_flag_set(DMA2D_FLAG_TRANSFER_WATERMARK);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  DMA2D->ISR = 0;
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_ACCESS_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = (1u << 3);
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_ACCESS_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = ~(1u << 3);
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_ACCESS_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = 0xffffffff;
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_ACCESS_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  DMA2D->ISR = 0;
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = (1u << 4);
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = ~(1u << 4);
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = 0xffffffff;
  res = dma2d_is_flag_set(DMA2D_FLAG_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  DMA2D->ISR = 0;
  res = dma2d_is_flag_set(DMA2D_FLAG_CONFIGURATION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = (1u << 5);
  res = dma2d_is_flag_set(DMA2D_FLAG_CONFIGURATION_ERROR);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = ~(1u << 5);
  res = dma2d_is_flag_set(DMA2D_FLAG_CONFIGURATION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->ISR = 0xffffffff;
  res = dma2d_is_flag_set(DMA2D_FLAG_CONFIGURATION_ERROR);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_flag_clear(void)
{
  DMA2D->IFCR = 0;
  dma2d_flag_clear(DMA2D_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA2D->IFCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->IFCR = ~(1u << 0);
  dma2d_flag_clear(DMA2D_FLAG_TRANSFER_ERROR);
  ASSERT_EQ(DMA2D->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA2D->IFCR = 0;
  dma2d_flag_clear(DMA2D_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->IFCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DMA2D->IFCR = ~(1u << 1);
  dma2d_flag_clear(DMA2D_FLAG_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA2D->IFCR = 0;
  dma2d_flag_clear(DMA2D_FLAG_TRANSFER_WATERMARK);
  ASSERT_EQ(DMA2D->IFCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DMA2D->IFCR = ~(1u << 2);
  dma2d_flag_clear(DMA2D_FLAG_TRANSFER_WATERMARK);
  ASSERT_EQ(DMA2D->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA2D->IFCR = 0;
  dma2d_flag_clear(DMA2D_FLAG_CLUT_ACCESS_ERROR);
  ASSERT_EQ(DMA2D->IFCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  DMA2D->IFCR = ~(1u << 3);
  dma2d_flag_clear(DMA2D_FLAG_CLUT_ACCESS_ERROR);
  ASSERT_EQ(DMA2D->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA2D->IFCR = 0;
  dma2d_flag_clear(DMA2D_FLAG_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->IFCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA2D->IFCR = ~(1u << 4);
  dma2d_flag_clear(DMA2D_FLAG_CLUT_TRANSFER_COMPLETE);
  ASSERT_EQ(DMA2D->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  DMA2D->IFCR = 0;
  dma2d_flag_clear(DMA2D_FLAG_CONFIGURATION_ERROR);
  ASSERT_EQ(DMA2D->IFCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA2D->IFCR = ~(1u << 5);
  dma2d_flag_clear(DMA2D_FLAG_CONFIGURATION_ERROR);
  ASSERT_EQ(DMA2D->IFCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_fg_memory_address(void)
{
  DMA2D->FGMAR = 0;
  dma2d_set_fg_memory_address(0);
  ASSERT_EQ(DMA2D->FGMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGMAR = 0xffffffff;
  dma2d_set_fg_memory_address(0);
  ASSERT_EQ(DMA2D->FGMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->FGMAR = 0;
  dma2d_set_fg_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->FGMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGMAR = 0xffffffff;
  dma2d_set_fg_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->FGMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_fg_line_offset(void)
{
  DMA2D->FGOR = 0;
  dma2d_set_fg_line_offset(0);
  ASSERT_EQ(DMA2D->FGOR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGOR = 0xffffffff;
  dma2d_set_fg_line_offset(0);
  ASSERT_EQ(DMA2D->FGOR, ~(0x3fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->FGOR = 0;
  dma2d_set_fg_line_offset(0x3fff);
  ASSERT_EQ(DMA2D->FGOR, 0x3fffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGOR = 0xffffffff;
  dma2d_set_fg_line_offset(0x3fff);
  ASSERT_EQ(DMA2D->FGOR, ~(0x3fffu << 0) | (0x3fffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->FGOR = 0;
  dma2d_set_fg_line_offset(0x4000);
  ASSERT_EQ(DMA2D->FGOR, 0x4000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->FGOR = 0xffffffff;
  dma2d_set_fg_line_offset(0x4000);
  ASSERT_EQ(DMA2D->FGOR, ~(0x3fffu << 0) | (0x4000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_bg_memory_address(void)
{
  DMA2D->BGMAR = 0;
  dma2d_set_bg_memory_address(0);
  ASSERT_EQ(DMA2D->BGMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGMAR = 0xffffffff;
  dma2d_set_bg_memory_address(0);
  ASSERT_EQ(DMA2D->BGMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->BGMAR = 0;
  dma2d_set_bg_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->BGMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGMAR = 0xffffffff;
  dma2d_set_bg_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->BGMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_bg_img_offset(void)
{
  DMA2D->BGOR = 0;
  dma2d_set_bg_img_offset(0);
  ASSERT_EQ(DMA2D->BGOR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGOR = 0xffffffff;
  dma2d_set_bg_img_offset(0);
  ASSERT_EQ(DMA2D->BGOR, ~(0x3fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->BGOR = 0;
  dma2d_set_bg_img_offset(0x3fff);
  ASSERT_EQ(DMA2D->BGOR, 0x3fffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGOR = 0xffffffff;
  dma2d_set_bg_img_offset(0x3fff);
  ASSERT_EQ(DMA2D->BGOR, ~(0x3fffu << 0) | (0x3fffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->BGOR = 0;
  dma2d_set_bg_img_offset(0x4000);
  ASSERT_EQ(DMA2D->BGOR, 0x4000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->BGOR = 0xffffffff;
  dma2d_set_bg_img_offset(0x4000);
  ASSERT_EQ(DMA2D->BGOR, ~(0x3fffu << 0) | (0x4000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_fg_color_mode(void)
{
  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_ARGB8888'}, self.value='0b0000', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_RGB888'}, self.value='0b0001', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_RGB565'}, self.value='0b0010', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_RGB565);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_RGB565);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_ARGB1555'}, self.value='0b0011', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_ARGB1555);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_ARGB1555);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_ARGB4444'}, self.value='0b0100', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_ARGB4444);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_ARGB4444);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_L8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_L8);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_L8);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_AL44'}, self.value='0b0110', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_AL44);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_AL44);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_AL88'}, self.value='0b0111', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_AL88);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_AL88);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_L4'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_L4);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_L4);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_A8'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_A8);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_A8);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_FG_COLOR_MODE_A4'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_A4);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0xfu << 0);
  dma2d_set_fg_color_mode(DMA2D_FG_COLOR_MODE_A4);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_fg_clut_color_mode(void)
{
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_clut_color_mode(DMA2D_FG_CLUT_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->FGPFCCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(1u << 4);
  dma2d_set_fg_clut_color_mode(DMA2D_FG_CLUT_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->FGPFCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = (1u << 4);
  dma2d_set_fg_clut_color_mode(DMA2D_FG_CLUT_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->FGPFCCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = 0xffffffff;
  dma2d_set_fg_clut_color_mode(DMA2D_FG_CLUT_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->FGPFCCR, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_fg_start(void)
{
  DMA2D->FGPFCCR = 0;
  dma2d_fg_start();
  ASSERT_EQ(DMA2D->FGPFCCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(1u << 5);
  dma2d_fg_start();
  ASSERT_EQ(DMA2D->FGPFCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_set_fg_clut_size(void)
{
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_clut_size(0);
  ASSERT_EQ(DMA2D->FGPFCCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = 0xffffffff;
  dma2d_set_fg_clut_size(0);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_clut_size(0xff);
  ASSERT_EQ(DMA2D->FGPFCCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = 0xffffffff;
  dma2d_set_fg_clut_size(0xff);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_clut_size(0x100);
  ASSERT_EQ(DMA2D->FGPFCCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->FGPFCCR = 0xffffffff;
  dma2d_set_fg_clut_size(0x100);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_fg_alpha_mode(void)
{
  // scope=self.reg='FGPFCCR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_FG_ALPHA_MODE_NOMOD'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_alpha_mode(DMA2D_FG_ALPHA_MODE_NOMOD);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0x3u << 16);
  dma2d_set_fg_alpha_mode(DMA2D_FG_ALPHA_MODE_NOMOD);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_alpha_mode(DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0x3u << 16);
  dma2d_set_fg_alpha_mode(DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGPFCCR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA_MUL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_alpha_mode(DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA_MUL);
  ASSERT_EQ(DMA2D->FGPFCCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = ~(0x3u << 16);
  dma2d_set_fg_alpha_mode(DMA2D_FG_ALPHA_MODE_REPLACE_ALPHA_MUL);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_fg_pfc_alpha_value(void)
{
  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_pfc_alpha_value(0);
  ASSERT_EQ(DMA2D->FGPFCCR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = 0xffffffff;
  dma2d_set_fg_pfc_alpha_value(0);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_pfc_alpha_value(0xff);
  ASSERT_EQ(DMA2D->FGPFCCR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGPFCCR = 0xffffffff;
  dma2d_set_fg_pfc_alpha_value(0xff);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  DMA2D->FGPFCCR = 0;
  dma2d_set_fg_pfc_alpha_value(0x100);
  ASSERT_EQ(DMA2D->FGPFCCR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->FGPFCCR = 0xffffffff;
  dma2d_set_fg_pfc_alpha_value(0x100);
  ASSERT_EQ(DMA2D->FGPFCCR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_fg_color_channel_value(void)
{
  // scope=self.reg='FGCOLR', self.shift=16, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_RED', 'val': 0}, self.value=0, self.ifdef=[], self.halt=False
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->FGCOLR, (0u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCOLR = ~(0xffu << 16);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGCOLR', self.shift=16, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_RED', 'val': '0xff'}, self.value='0xff', self.ifdef=[], self.halt=False
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->FGCOLR, (0xffu << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCOLR = ~(0xffu << 16);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGCOLR', self.shift=16, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_RED', 'val': '0x100'}, self.value='0x100', self.ifdef=[], self.halt=True
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->FGCOLR, (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->FGCOLR = ~(0xffu << 16);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // scope=self.reg='FGCOLR', self.shift=8, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_GREEN', 'val': 0}, self.value=0, self.ifdef=[], self.halt=False
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->FGCOLR, (0u << 8));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCOLR = ~(0xffu << 8);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGCOLR', self.shift=8, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_GREEN', 'val': '0xff'}, self.value='0xff', self.ifdef=[], self.halt=False
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->FGCOLR, (0xffu << 8));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCOLR = ~(0xffu << 8);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGCOLR', self.shift=8, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_GREEN', 'val': '0x100'}, self.value='0x100', self.ifdef=[], self.halt=True
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->FGCOLR, (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->FGCOLR = ~(0xffu << 8);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // scope=self.reg='FGCOLR', self.shift=0, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_BLUE', 'val': 0}, self.value=0, self.ifdef=[], self.halt=False
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->FGCOLR, (0u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCOLR = ~(0xffu << 0);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGCOLR', self.shift=0, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_BLUE', 'val': '0xff'}, self.value='0xff', self.ifdef=[], self.halt=False
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->FGCOLR, (0xffu << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCOLR = ~(0xffu << 0);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='FGCOLR', self.shift=0, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_BLUE', 'val': '0x100'}, self.value='0x100', self.ifdef=[], self.halt=True
  DMA2D->FGCOLR = 0;
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->FGCOLR, (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->FGCOLR = ~(0xffu << 0);
  dma2d_set_fg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->FGCOLR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_bg_color_mode(void)
{
  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_ARGB8888'}, self.value='0b0000', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_RGB888'}, self.value='0b0001', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_RGB565'}, self.value='0b0010', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_RGB565);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_RGB565);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_ARGB1555'}, self.value='0b0011', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_ARGB1555);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_ARGB1555);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_ARGB4444'}, self.value='0b0100', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_ARGB4444);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_ARGB4444);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_L8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_L8);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_L8);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_AL44'}, self.value='0b0110', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_AL44);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_AL44);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_AL88'}, self.value='0b0111', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_AL88);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_AL88);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_L4'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_L4);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_L4);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_A8'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_A8);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_A8);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=0, self.mask='0xf', self.varsmap={'mode': 'DMA2D_BG_COLOR_MODE_A4'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_A4);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0xfu << 0);
  dma2d_set_bg_color_mode(DMA2D_BG_COLOR_MODE_A4);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_bg_clut_color_mode(void)
{
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_clut_color_mode(DMA2D_BG_CLUT_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->BGPFCCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(1u << 4);
  dma2d_set_bg_clut_color_mode(DMA2D_BG_CLUT_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->BGPFCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = (1u << 4);
  dma2d_set_bg_clut_color_mode(DMA2D_BG_CLUT_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->BGPFCCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = 0xffffffff;
  dma2d_set_bg_clut_color_mode(DMA2D_BG_CLUT_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->BGPFCCR, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_bg_start(void)
{
  DMA2D->BGPFCCR = 0;
  dma2d_bg_start();
  ASSERT_EQ(DMA2D->BGPFCCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(1u << 5);
  dma2d_bg_start();
  ASSERT_EQ(DMA2D->BGPFCCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_set_bg_clut_size(void)
{
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_clut_size(0);
  ASSERT_EQ(DMA2D->BGPFCCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = 0xffffffff;
  dma2d_set_bg_clut_size(0);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_clut_size(0xff);
  ASSERT_EQ(DMA2D->BGPFCCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = 0xffffffff;
  dma2d_set_bg_clut_size(0xff);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_clut_size(0x100);
  ASSERT_EQ(DMA2D->BGPFCCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->BGPFCCR = 0xffffffff;
  dma2d_set_bg_clut_size(0x100);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_bg_pfc_alpha_mode(void)
{
  // scope=self.reg='BGPFCCR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_BG_ALPHA_MODE_NOMOD'}, self.value='0b00', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_pfc_alpha_mode(DMA2D_BG_ALPHA_MODE_NOMOD);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0x3u << 16);
  dma2d_set_bg_pfc_alpha_mode(DMA2D_BG_ALPHA_MODE_NOMOD);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA'}, self.value='0b01', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_pfc_alpha_mode(DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0x3u << 16);
  dma2d_set_bg_pfc_alpha_mode(DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGPFCCR', self.shift=16, self.mask='0x3', self.varsmap={'mode': 'DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA_MUL'}, self.value='0b10', self.ifdef=[], self.halt=False
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_pfc_alpha_mode(DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA_MUL);
  ASSERT_EQ(DMA2D->BGPFCCR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = ~(0x3u << 16);
  dma2d_set_bg_pfc_alpha_mode(DMA2D_BG_ALPHA_MODE_REPLACE_ALPHA_MUL);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_bg_pfc_alpha_value(void)
{
  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_pfc_alpha_value(0);
  ASSERT_EQ(DMA2D->BGPFCCR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = 0xffffffff;
  dma2d_set_bg_pfc_alpha_value(0);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_pfc_alpha_value(0xff);
  ASSERT_EQ(DMA2D->BGPFCCR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGPFCCR = 0xffffffff;
  dma2d_set_bg_pfc_alpha_value(0xff);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  DMA2D->BGPFCCR = 0;
  dma2d_set_bg_pfc_alpha_value(0x100);
  ASSERT_EQ(DMA2D->BGPFCCR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->BGPFCCR = 0xffffffff;
  dma2d_set_bg_pfc_alpha_value(0x100);
  ASSERT_EQ(DMA2D->BGPFCCR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_bg_color_channel_value(void)
{
  // scope=self.reg='BGCOLR', self.shift=16, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_RED', 'val': 0}, self.value=0, self.ifdef=[], self.halt=False
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->BGCOLR, (0u << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCOLR = ~(0xffu << 16);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGCOLR', self.shift=16, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_RED', 'val': '0xff'}, self.value='0xff', self.ifdef=[], self.halt=False
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->BGCOLR, (0xffu << 16));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCOLR = ~(0xffu << 16);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGCOLR', self.shift=16, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_RED', 'val': '0x100'}, self.value='0x100', self.ifdef=[], self.halt=True
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->BGCOLR, (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->BGCOLR = ~(0xffu << 16);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // scope=self.reg='BGCOLR', self.shift=8, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_GREEN', 'val': 0}, self.value=0, self.ifdef=[], self.halt=False
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->BGCOLR, (0u << 8));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCOLR = ~(0xffu << 8);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGCOLR', self.shift=8, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_GREEN', 'val': '0xff'}, self.value='0xff', self.ifdef=[], self.halt=False
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->BGCOLR, (0xffu << 8));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCOLR = ~(0xffu << 8);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGCOLR', self.shift=8, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_GREEN', 'val': '0x100'}, self.value='0x100', self.ifdef=[], self.halt=True
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->BGCOLR, (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->BGCOLR = ~(0xffu << 8);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // scope=self.reg='BGCOLR', self.shift=0, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_BLUE', 'val': 0}, self.value=0, self.ifdef=[], self.halt=False
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->BGCOLR, (0u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCOLR = ~(0xffu << 0);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGCOLR', self.shift=0, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_BLUE', 'val': '0xff'}, self.value='0xff', self.ifdef=[], self.halt=False
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->BGCOLR, (0xffu << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCOLR = ~(0xffu << 0);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BGCOLR', self.shift=0, self.mask='0xff', self.varsmap={'channel': 'DMA2D_RGB888_COLOR_CHANNEL_BLUE', 'val': '0x100'}, self.value='0x100', self.ifdef=[], self.halt=True
  DMA2D->BGCOLR = 0;
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->BGCOLR, (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->BGCOLR = ~(0xffu << 0);
  dma2d_set_bg_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->BGCOLR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_fg_clut_memory_address(void)
{
  DMA2D->FGCMAR = 0;
  dma2d_set_fg_clut_memory_address(0);
  ASSERT_EQ(DMA2D->FGCMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCMAR = 0xffffffff;
  dma2d_set_fg_clut_memory_address(0);
  ASSERT_EQ(DMA2D->FGCMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->FGCMAR = 0;
  dma2d_set_fg_clut_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->FGCMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->FGCMAR = 0xffffffff;
  dma2d_set_fg_clut_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->FGCMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_bg_clut_memory_address(void)
{
  DMA2D->BGCMAR = 0;
  dma2d_set_bg_clut_memory_address(0);
  ASSERT_EQ(DMA2D->BGCMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCMAR = 0xffffffff;
  dma2d_set_bg_clut_memory_address(0);
  ASSERT_EQ(DMA2D->BGCMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->BGCMAR = 0;
  dma2d_set_bg_clut_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->BGCMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->BGCMAR = 0xffffffff;
  dma2d_set_bg_clut_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->BGCMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_output_color_mode(void)
{
  // scope=self.reg='OPFCCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'DMA2D_OUTPUT_COLOR_MODE_ARGB8888'}, self.value='0b000', self.ifdef=[], self.halt=False
  DMA2D->OPFCCR = 0;
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->OPFCCR, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->OPFCCR = ~(0x7u << 0);
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_ARGB8888);
  ASSERT_EQ(DMA2D->OPFCCR, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPFCCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'DMA2D_OUTPUT_COLOR_MODE_RGB888'}, self.value='0b001', self.ifdef=[], self.halt=False
  DMA2D->OPFCCR = 0;
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->OPFCCR, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->OPFCCR = ~(0x7u << 0);
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_RGB888);
  ASSERT_EQ(DMA2D->OPFCCR, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPFCCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'DMA2D_OUTPUT_COLOR_MODE_RGB565'}, self.value='0b010', self.ifdef=[], self.halt=False
  DMA2D->OPFCCR = 0;
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_RGB565);
  ASSERT_EQ(DMA2D->OPFCCR, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->OPFCCR = ~(0x7u << 0);
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_RGB565);
  ASSERT_EQ(DMA2D->OPFCCR, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPFCCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'DMA2D_OUTPUT_COLOR_MODE_ARGB1555'}, self.value='0b011', self.ifdef=[], self.halt=False
  DMA2D->OPFCCR = 0;
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_ARGB1555);
  ASSERT_EQ(DMA2D->OPFCCR, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->OPFCCR = ~(0x7u << 0);
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_ARGB1555);
  ASSERT_EQ(DMA2D->OPFCCR, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPFCCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'DMA2D_OUTPUT_COLOR_MODE_ARGB4444'}, self.value='0b100', self.ifdef=[], self.halt=False
  DMA2D->OPFCCR = 0;
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_ARGB4444);
  ASSERT_EQ(DMA2D->OPFCCR, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->OPFCCR = ~(0x7u << 0);
  dma2d_set_output_color_mode(DMA2D_OUTPUT_COLOR_MODE_ARGB4444);
  ASSERT_EQ(DMA2D->OPFCCR, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_argb8888_output_color(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color(0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color(0);
  ASSERT_EQ(DMA2D->OCOLR, 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color(0xffffffff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color(0xffffffff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_argb8888_output_color_channel_value(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffu << 24);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 24) | (0xffu << 24));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, 0x100u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb8888_output_color_channel_value(DMA2D_ARGB8888_COLOR_CHANNEL_ALPHA, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 24) | (0x100u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_rgb8888_output_color(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_rgb8888_output_color(0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb8888_output_color(0);
  ASSERT_EQ(DMA2D->OCOLR, 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb8888_output_color(0xffffff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb8888_output_color(0xffffff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffffff);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb8888_output_color(0x1000000);
  ASSERT_EQ(DMA2D->OCOLR, 0x1000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb8888_output_color(0x1000000);
  ASSERT_EQ(DMA2D->OCOLR, 0x1000000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_rgb888_output_color_channel_value(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffu << 16);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 16) | (0xffu << 16));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, 0x100u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_RED, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 16) | (0x100u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_GREEN, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0xff);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_rgb888_output_color_channel_value(DMA2D_RGB888_COLOR_CHANNEL_BLUE, 0x100);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_rgb565_output_color(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_rgb565_output_color(0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'fn_set_value (TODO)' (dma2d_set_rgb565_output_color_channel_value)
void
test_dma2d_set_argb1555_output_color(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_argb1555_output_color(0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb1555_output_color(0xffff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb1555_output_color(0x10000);
  ASSERT_EQ(DMA2D->OCOLR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_argb1555_output_color_channel_value(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_argb1555_output_color_channel_value(DMA2D_ARGB1555_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb1555_output_color_channel_value(DMA2D_ARGB1555_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 5);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb1555_output_color_channel_value(DMA2D_ARGB1555_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 10);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb1555_output_color_channel_value(DMA2D_ARGB1555_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 15);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_argb4444_output_color(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color(0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color(0xffff);
  ASSERT_EQ(DMA2D->OCOLR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color(0x10000);
  ASSERT_EQ(DMA2D->OCOLR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_argb4444_output_color_channel_value(void)
{
  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_BLUE, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_BLUE, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, 0xfu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_BLUE, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 0) | (0xfu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_BLUE, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, 0x10u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_BLUE, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 0) | (0x10u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 4);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_GREEN, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 4) | (0u << 4));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_GREEN, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, 0xfu << 4);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_GREEN, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 4) | (0xfu << 4));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_GREEN, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, 0x10u << 4);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_GREEN, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 4) | (0x10u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_RED, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_RED, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, 0xfu << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_RED, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 8) | (0xfu << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_RED, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, 0x10u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_RED, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 8) | (0x10u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(DMA2D->OCOLR, 0u << 12);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA, 0);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 12) | (0u << 12));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, 0xfu << 12);
  ASSERT_FALSE(execution_halted());

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA, 0xf);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 12) | (0xfu << 12));
  ASSERT_FALSE(execution_halted());


  DMA2D->OCOLR = 0;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, 0x10u << 12);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OCOLR = 0xffffffff;
  dma2d_set_argb4444_output_color_channel_value(DMA2D_ARGB4444_COLOR_CHANNEL_ALPHA, 0x10);
  ASSERT_EQ(DMA2D->OCOLR, ~(0xfu << 12) | (0x10u << 12));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_output_memory_address(void)
{
  DMA2D->OMAR = 0;
  dma2d_set_output_memory_address(0);
  ASSERT_EQ(DMA2D->OMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OMAR = 0xffffffff;
  dma2d_set_output_memory_address(0);
  ASSERT_EQ(DMA2D->OMAR, 0);
  ASSERT_FALSE(execution_halted());


  DMA2D->OMAR = 0;
  dma2d_set_output_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->OMAR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OMAR = 0xffffffff;
  dma2d_set_output_memory_address(0xffffffff);
  ASSERT_EQ(DMA2D->OMAR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_dma2d_set_output_line_offset(void)
{
  DMA2D->OOR = 0;
  dma2d_set_output_line_offset(0);
  ASSERT_EQ(DMA2D->OOR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OOR = 0xffffffff;
  dma2d_set_output_line_offset(0);
  ASSERT_EQ(DMA2D->OOR, ~(0x3fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OOR = 0;
  dma2d_set_output_line_offset(0x3fff);
  ASSERT_EQ(DMA2D->OOR, 0x3fffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->OOR = 0xffffffff;
  dma2d_set_output_line_offset(0x3fff);
  ASSERT_EQ(DMA2D->OOR, ~(0x3fffu << 0) | (0x3fffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->OOR = 0;
  dma2d_set_output_line_offset(0x4000);
  ASSERT_EQ(DMA2D->OOR, 0x4000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->OOR = 0xffffffff;
  dma2d_set_output_line_offset(0x4000);
  ASSERT_EQ(DMA2D->OOR, ~(0x3fffu << 0) | (0x4000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_number_of_lines(void)
{
  DMA2D->NLR = 0;
  dma2d_set_number_of_lines(0);
  ASSERT_EQ(DMA2D->NLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->NLR = 0xffffffff;
  dma2d_set_number_of_lines(0);
  ASSERT_EQ(DMA2D->NLR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->NLR = 0;
  dma2d_set_number_of_lines(0xffff);
  ASSERT_EQ(DMA2D->NLR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->NLR = 0xffffffff;
  dma2d_set_number_of_lines(0xffff);
  ASSERT_EQ(DMA2D->NLR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->NLR = 0;
  dma2d_set_number_of_lines(0x10000);
  ASSERT_EQ(DMA2D->NLR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->NLR = 0xffffffff;
  dma2d_set_number_of_lines(0x10000);
  ASSERT_EQ(DMA2D->NLR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_pixel_per_lines(void)
{
  DMA2D->NLR = 0;
  dma2d_set_pixel_per_lines(0);
  ASSERT_EQ(DMA2D->NLR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  DMA2D->NLR = 0xffffffff;
  dma2d_set_pixel_per_lines(0);
  ASSERT_EQ(DMA2D->NLR, ~(0x3fffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  DMA2D->NLR = 0;
  dma2d_set_pixel_per_lines(0x3fff);
  ASSERT_EQ(DMA2D->NLR, 0x3fffu << 16);
  ASSERT_FALSE(execution_halted());

  DMA2D->NLR = 0xffffffff;
  dma2d_set_pixel_per_lines(0x3fff);
  ASSERT_EQ(DMA2D->NLR, ~(0x3fffu << 16) | (0x3fffu << 16));
  ASSERT_FALSE(execution_halted());


  DMA2D->NLR = 0;
  dma2d_set_pixel_per_lines(0x4000);
  ASSERT_EQ(DMA2D->NLR, 0x4000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->NLR = 0xffffffff;
  dma2d_set_pixel_per_lines(0x4000);
  ASSERT_EQ(DMA2D->NLR, ~(0x3fffu << 16) | (0x4000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_set_line_watermark(void)
{
  DMA2D->LWR = 0;
  dma2d_set_line_watermark(0);
  ASSERT_EQ(DMA2D->LWR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->LWR = 0xffffffff;
  dma2d_set_line_watermark(0);
  ASSERT_EQ(DMA2D->LWR, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->LWR = 0;
  dma2d_set_line_watermark(0xffff);
  ASSERT_EQ(DMA2D->LWR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->LWR = 0xffffffff;
  dma2d_set_line_watermark(0xffff);
  ASSERT_EQ(DMA2D->LWR, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  DMA2D->LWR = 0;
  dma2d_set_line_watermark(0x10000);
  ASSERT_EQ(DMA2D->LWR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->LWR = 0xffffffff;
  dma2d_set_line_watermark(0x10000);
  ASSERT_EQ(DMA2D->LWR, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_dma2d_deadtime(void)
{
  DMA2D->AMTCR = 0;
  dma2d_deadtime_enable();
  ASSERT_EQ(DMA2D->AMTCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DMA2D->AMTCR = ~(1u << 0);
  dma2d_deadtime_enable();
  ASSERT_EQ(DMA2D->AMTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DMA2D->AMTCR = (1u << 0);
  dma2d_deadtime_disable();
  ASSERT_EQ(DMA2D->AMTCR, 0);
  ASSERT_FALSE(execution_halted());

  DMA2D->AMTCR = 0xffffffff;
  dma2d_deadtime_disable();
  ASSERT_EQ(DMA2D->AMTCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_dma2d_set_deadtime(void)
{
  DMA2D->AMTCR = 0;
  dma2d_set_deadtime(0);
  ASSERT_EQ(DMA2D->AMTCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->AMTCR = 0xffffffff;
  dma2d_set_deadtime(0);
  ASSERT_EQ(DMA2D->AMTCR, ~(0xffu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->AMTCR = 0;
  dma2d_set_deadtime(0xff);
  ASSERT_EQ(DMA2D->AMTCR, 0xffu << 8);
  ASSERT_FALSE(execution_halted());

  DMA2D->AMTCR = 0xffffffff;
  dma2d_set_deadtime(0xff);
  ASSERT_EQ(DMA2D->AMTCR, ~(0xffu << 8) | (0xffu << 8));
  ASSERT_FALSE(execution_halted());


  DMA2D->AMTCR = 0;
  dma2d_set_deadtime(0x100);
  ASSERT_EQ(DMA2D->AMTCR, 0x100u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DMA2D->AMTCR = 0xffffffff;
  dma2d_set_deadtime(0x100);
  ASSERT_EQ(DMA2D->AMTCR, ~(0xffu << 8) | (0x100u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_dma2d_start),
    TEST_FUNC(test_dma2d_suspend),
    TEST_FUNC(test_dma2d_abort),
    TEST_FUNC(test_dma2d_interrupt),
    TEST_FUNC(test_dma2d_set_mode),
    TEST_FUNC(test_dma2d_is_flag_set),
    TEST_FUNC(test_dma2d_flag_clear),
    TEST_FUNC(test_dma2d_set_fg_memory_address),
    TEST_FUNC(test_dma2d_set_fg_line_offset),
    TEST_FUNC(test_dma2d_set_bg_memory_address),
    TEST_FUNC(test_dma2d_set_bg_img_offset),
    TEST_FUNC(test_dma2d_set_fg_color_mode),
    TEST_FUNC(test_dma2d_set_fg_clut_color_mode),
    TEST_FUNC(test_dma2d_fg_start),
    TEST_FUNC(test_dma2d_set_fg_clut_size),
    TEST_FUNC(test_dma2d_set_fg_alpha_mode),
    TEST_FUNC(test_dma2d_set_fg_pfc_alpha_value),
    TEST_FUNC(test_dma2d_set_fg_color_channel_value),
    TEST_FUNC(test_dma2d_set_bg_color_mode),
    TEST_FUNC(test_dma2d_set_bg_clut_color_mode),
    TEST_FUNC(test_dma2d_bg_start),
    TEST_FUNC(test_dma2d_set_bg_clut_size),
    TEST_FUNC(test_dma2d_set_bg_pfc_alpha_mode),
    TEST_FUNC(test_dma2d_set_bg_pfc_alpha_value),
    TEST_FUNC(test_dma2d_set_bg_color_channel_value),
    TEST_FUNC(test_dma2d_set_fg_clut_memory_address),
    TEST_FUNC(test_dma2d_set_bg_clut_memory_address),
    TEST_FUNC(test_dma2d_set_output_color_mode),
    TEST_FUNC(test_dma2d_set_argb8888_output_color),
    TEST_FUNC(test_dma2d_set_argb8888_output_color_channel_value),
    TEST_FUNC(test_dma2d_set_rgb8888_output_color),
    TEST_FUNC(test_dma2d_set_rgb888_output_color_channel_value),
    TEST_FUNC(test_dma2d_set_rgb565_output_color),
    TEST_FUNC(test_dma2d_set_argb1555_output_color),
    TEST_FUNC(test_dma2d_set_argb1555_output_color_channel_value),
    TEST_FUNC(test_dma2d_set_argb4444_output_color),
    TEST_FUNC(test_dma2d_set_argb4444_output_color_channel_value),
    TEST_FUNC(test_dma2d_set_output_memory_address),
    TEST_FUNC(test_dma2d_set_output_line_offset),
    TEST_FUNC(test_dma2d_set_number_of_lines),
    TEST_FUNC(test_dma2d_set_pixel_per_lines),
    TEST_FUNC(test_dma2d_set_line_watermark),
    TEST_FUNC(test_dma2d_deadtime),
    TEST_FUNC(test_dma2d_set_deadtime),
  };

  return TESTS_RUN(tests);
}
