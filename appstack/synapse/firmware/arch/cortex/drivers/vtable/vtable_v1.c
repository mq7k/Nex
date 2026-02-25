#include "synapse/arch/cortex/drivers/vtable/vtable_v1.h"
#include "synapse/arch/cortex/drivers/nvic/nvic_v1.h"
#include "synapse/specs.h"

#if defined(NEX_PLATFORM_DESKTOP)
u32 _stack = 0;
void _reset(void) {}
#endif

__attribute__((section(".isr_vector")))
struct vector_table vec_table = {
  .sp = (u32*) &_stack,
  .reset = _reset,
  .nmi = nmi_handler,
  .hard_fault = hard_fault_handler,
  .memory_manage_fault = memory_fault_handler,
  .bus_fault = bus_fault_handler,
  .usage_fault = usage_fault_handler,
  .sv_call = sv_call_handler,
  .debug_monitor = debug_monitor_handler,
  .pend_sv = pend_sv_handler,
  .systick = systick_handler,
  .irq = {
    [NVIC_IRQ_WWDG]          = wwdg_isr,
    [NVIC_IRQ_PVD]           = pvd_isr,
    [NVIC_IRQ_TAMP_STAMP]    = tamper_isr,
    [NVIC_IRQ_RTC_WAKEUP]    = rtc_wakeup_isr,
    [NVIC_IRQ_FLASH]         = flash_isr,
    [NVIC_IRQ_RCC]           = rcc_isr,
    [NVIC_IRQ_EXTI0]         = exti0_isr,
    [NVIC_IRQ_EXTI1]         = exti1_isr,
    [NVIC_IRQ_EXTI2]         = exti2_isr,
    [NVIC_IRQ_EXTI3]         = exti3_isr,
    [NVIC_IRQ_EXTI4]         = exti4_isr,
    [NVIC_IRQ_DMA1_STREAM0]  = dma1_stream0_isr,
    [NVIC_IRQ_DMA1_STREAM1]  = dma1_stream1_isr,
    [NVIC_IRQ_DMA1_STREAM2]  = dma1_stream2_isr,
    [NVIC_IRQ_DMA1_STREAM3]  = dma1_stream3_isr,
    [NVIC_IRQ_DMA1_STREAM4]  = dma1_stream4_isr,
    [NVIC_IRQ_DMA1_STREAM5]  = dma1_stream5_isr,
    [NVIC_IRQ_DMA1_STREAM6]  = dma1_stream6_isr,
    [NVIC_IRQ_ADC]           = adc_isr,

#if defined(STM32_CAN1)
    [NVIC_IRQ_CAN1_TX]       = can1_tx_isr,
    [NVIC_IRQ_CAN1_RX0]      = can1_rx0_isr,
    [NVIC_IRQ_CAN1_RX1]      = can1_rx1_isr,
    [NVIC_IRQ_CAN1_SCE]      = can1_sce_isr,
#endif

    [NVIC_IRQ_EXTI9_5]       = exti9_5_isr,
    [NVIC_IRQ_TIM1_BREAK_TIM9]      = tim1_brk_isr,
    [NVIC_IRQ_TIM1_UPDATE_TIM10]       = tim1_up_isr,
    [NVIC_IRQ_TIM1_TRIGGER_TIM11]  = tim1_trg_com_isr,
    [NVIC_IRQ_TIM1_CC]       = tim1_cc_isr,

#if defined(STM32_TIM2)
    [NVIC_IRQ_TIM2]          = tim2_isr,
#endif

#if defined(STM32_TIM3)
    [NVIC_IRQ_TIM3]          = tim3_isr,
#endif

#if defined(STM32_TIM4)
    [NVIC_IRQ_TIM4]          = tim4_isr,
#endif

    [NVIC_IRQ_I2C1_EVENT]       = i2c1_ev_isr,
    [NVIC_IRQ_I2C1_ERROR]       = i2c1_er_isr,
    [NVIC_IRQ_I2C2_EVENT]       = i2c2_ev_isr,
    [NVIC_IRQ_I2C2_ERROR]       = i2c2_er_isr,
    [NVIC_IRQ_SPI1]          = spi1_isr,
    [NVIC_IRQ_SPI2]          = spi2_isr,
    [NVIC_IRQ_USART1]        = usart1_isr,
    [NVIC_IRQ_USART2]        = usart2_isr,

#if defined(STM32_USART3)
    [NVIC_IRQ_USART3]        = usart3_isr,
#endif

    [NVIC_IRQ_EXTI15_10]     = exti15_10_isr,
    [NVIC_IRQ_RTC_ALARM]     = rtc_alarm_isr,

#if defined(STM32_USB_OTG_FS)
    [NVIC_IRQ_OTG_FS_WAKEUP]   = otg_fs_wkup_isr,
#endif

#if defined(STM32_TIM8)
    [NVIC_IRQ_TIM8_BREAK_TIM12] = tim8_brk_isr,
    [NVIC_IRQ_TIM8_UPDATE_TIM13] = tim8_up_isr,
    [NVIC_IRQ_TIM8_TRIGGER_TIM14] = tim8_trg_isr,
    [NVIC_IRQ_TIM8_CC] = tim8_cc_isr,
#endif

    [NVIC_IRQ_DMA1_STREAM7] = dma2_stream7_isr,

#if defined(STM32_FSMC)
    [NVIC_IRQ_FSMC] = fsmc_isr,
#elif defined(STM32_FMC)
    [NVIC_IRQ_FMC] = fmc_isr,
#endif

#if defined(STM32_SDIO)
    [NVIC_IRQ_SDIO] = sdio_isr,
#endif

    [NVIC_IRQ_TIM5]          = tim5_isr,

#if defined(STM32_SPI3)
    [NVIC_IRQ_SPI3]          = spi3_isr,
#endif

#if defined(STM32_UART4)
    [NVIC_IRQ_UART4]         = uart4_isr,
#endif

#if defined(STM32_UART5)
    [NVIC_IRQ_UART5]         = uart5_isr,
#endif

    [NVIC_IRQ_TIM6_DAC]          = tim6_isr,

#if defined(STM32_TIM7)
    [NVIC_IRQ_TIM7]          = tim7_isr,
#endif

    [NVIC_IRQ_DMA2_STREAM0] = dma2_stream0_isr,
    [NVIC_IRQ_DMA2_STREAM1] = dma2_stream1_isr,
    [NVIC_IRQ_DMA2_STREAM2] = dma2_stream2_isr,
    [NVIC_IRQ_DMA2_STREAM3] = dma2_stream3_isr,
    [NVIC_IRQ_DMA2_STREAM4] = dma2_stream4_isr,

#if defined(STM32_ETH)
    [NVIC_IRQ_ETH]           = eth_isr,
    [NVIC_IRQ_ETH_WKUP]      = eth_wkup_isr,
#endif

#if defined(STM32_CAN2)
    [NVIC_IRQ_CAN2_TX]       = can2_tx_isr,
    [NVIC_IRQ_CAN2_RX0]      = can2_rx0_isr,
    [NVIC_IRQ_CAN2_RX1]      = can2_rx1_isr,
    [NVIC_IRQ_CAN2_SCE]      = can2_sce_isr,
#endif

#if defined(STM32_USB_OTG_FS)
    [NVIC_IRQ_OTG_FS]        = otg_fs_isr,
#endif

    [NVIC_IRQ_DMA2_STREAM5] = dma2_stream5_isr,
    [NVIC_IRQ_DMA2_STREAM6] = dma2_stream6_isr,
    [NVIC_IRQ_DMA2_STREAM7] = dma2_stream7_isr,
    [NVIC_IRQ_USART6] = usart6_isr,

#if defined(STM32_I2C3)
    [NVIC_IRQ_I2C3_EVENT] = i2c3_event_isr,
    [NVIC_IRQ_I2C3_ERROR] = i2c3_error_isr,
#endif

#if defined(STM32_USB_OTG_HS)
    [NVIC_IRQ_OTG_HS_EP1_OUTPUT] = otg_hs_ep1_out_isr,
    [NVIC_IRQ_OTG_HS_EP1_INPUT] = otg_hs_ep1_in_isr,
    [NVIC_IRQ_OTG_HS_WAKEUP] = otg_hs_wakeup_isr,
    [NVIC_IRQ_OTG_HS] = otg_hs_isr,
#endif

#if defined(STM32_DCMI)
    [NVIC_IRQ_DCMI] = dcmi_isr,
#endif

#if defined(STM32_CRYP)
    [NVIC_IRQ_CRYPTO] = cryp_isr,
#endif

#if defined(STM32_HASH) || defined(STM32_RNG)
    [NVIC_IRQ_HASH_RNG] = hash_rng_isr,
#endif

    [NVIC_IRQ_FPU] = fpu_isr,

#if defined(STM32_UART7)
    [NVIC_IRQ_UART7] = usart7_isr,
#endif

#if defined(STM32_UART8)
    [NVIC_IRQ_UART8] = usart8_isr,
#endif

#if defined(STM32_SPI4)
    [NVIC_IRQ_SPI4] = spi4_isr,
#endif

#if defined(STM32_SPI5)
    [NVIC_IRQ_SPI5] = spi5_isr,
#endif

#if defined(STM32_SPI6)
    [NVIC_IRQ_SPI6] = spi6_isr,
#endif

#if defined(STM32_SAI1)
    [NVIC_IRQ_SAI1] = sai1_isr,
#endif

#if defined(STM32_LCD_TFT)
    [NVIC_IRQ_LCD_TFT] = lcd_tft_isr,
    [NVIC_IRQ_LCD_TFT_ERROR] = lcd_tft_error_isr,
#endif

#if defined(STM32_DMA2D)
    [NVIC_IRQ_DMA2D] = dma2d_isr,
#endif

#if defined(STM32_SAI2)
    [NVIC_IRQ_SAI2] = sai2_isr,
#endif

#if defined(STM32_QUADSPI)
    [NVIC_IRQ_QUADSPI] = quadspi_isr,
#endif

#if defined(STM32_HDMI_CEC)
    [NVIC_IRQ_HDMI_CEC] = hdmi_cec_isr,
#endif

#if defined(STM32_SPDIFRX)
    [NVIC_IRQ_SPDIFRX] = spdifrx_isr,
#endif

#if defined(STM32_FMPI2C1)
    [NVIC_IRQ_FMPI2C1_EVENT] = fmpi2c1_event_isr,
    [NVIC_IRQ_FMPI2C1_ERR] = fmpi2c1_error_isr,
#endif

#if defined(STM32_DSI)
    [NVIC_IRQ_DSI] = dsi_isr,
#endif

#if defined(STM32_I2C4)
    [NVIC_IRQ_I2C4_ERROR] = i2c4_error_isr,
#endif

#if defined(STM32_LPTIM1)
    [NVIC_IRQ_LPTIM1] = lptim1_isr,
#endif

#if defined(STM32_DFSDM2)
    [NVIC_IRQ_DFSDM2_FLT0] = dfsdm2_flt0_isr,
    [NVIC_IRQ_DFSDM2_FLT1] = dfsdm2_flt1_isr,
    [NVIC_IRQ_DFSDM2_FLT2] = dfsdm2_flt2_isr,
    [NVIC_IRQ_DFSDM2_FLT3] = dfsdm2_flt3_isr,
#endif
  }
};

