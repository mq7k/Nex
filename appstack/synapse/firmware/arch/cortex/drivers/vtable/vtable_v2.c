#include "synapse/arch/cortex/drivers/vtable/vtable_v2.h"
#include "synapse/arch/cortex/drivers/nvic/nvic_v2.h"
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
    [NVIC_IRQ_DMA1_CHANNEL1]  = dma1_channel1_isr,
    [NVIC_IRQ_DMA1_CHANNEL2]  = dma1_channel2_isr,
    [NVIC_IRQ_DMA1_CHANNEL3]  = dma1_channel3_isr,
    [NVIC_IRQ_DMA1_CHANNEL4]  = dma1_channel4_isr,
    [NVIC_IRQ_DMA1_CHANNEL5]  = dma1_channel5_isr,
    [NVIC_IRQ_DMA1_CHANNEL6]  = dma1_channel6_isr,
    [NVIC_IRQ_DMA1_CHANNEL7]  = dma1_channel7_isr,
    [NVIC_IRQ_ADC]           = adc_isr,

#if defined(STM32_CAN1)
    [NVIC_IRQ_CAN1_TX]       = can1_tx_isr,
    [NVIC_IRQ_CAN1_RX0]      = can1_rx0_isr,
    [NVIC_IRQ_CAN1_RX1]      = can1_rx1_isr,
    [NVIC_IRQ_CAN1_SCE]      = can1_sce_isr,
#endif

    [NVIC_IRQ_EXTI9_5]       = exti9_5_isr,
    [NVIC_IRQ_TIM1_BREAK]      = tim1_brk_isr,
    [NVIC_IRQ_TIM1_UPDATE]       = tim1_up_isr,
    [NVIC_IRQ_TIM1_TRIGGER]  = tim1_trg_com_isr,
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

// #if defined(STM32_TIM8)
//     [NVIC_IRQ_TIM8_BREAK_TIM12] = tim8_brk_isr,
//     [NVIC_IRQ_TIM8_UPDATE_TIM13] = tim8_up_isr,
//     [NVIC_IRQ_TIM8_TRIGGER_TIM14] = tim8_trg_isr,
//     [NVIC_IRQ_TIM8_CC] = tim8_cc_isr,
// #endif
//
//     [NVIC_IRQ_DMA1_STREAM7] = dma2_stream7_isr,
//
// #if defined(STM32_FSMC)
//     [NVIC_IRQ_FSMC] = fsmc_isr,
// #elif defined(STM32_FMC)
//     [NVIC_IRQ_FMC] = fmc_isr,
// #endif
//
// #if defined(STM32_SDIO)
//     [NVIC_IRQ_SDIO] = sdio_isr,
// #endif

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

    [NVIC_IRQ_TIM6]          = tim6_isr,

#if defined(STM32_TIM7)
    [NVIC_IRQ_TIM7]          = tim7_isr,
#endif

    [NVIC_IRQ_DMA2_CHANNEL1] = dma2_channel1_isr,
    [NVIC_IRQ_DMA2_CHANNEL2] = dma2_channel2_isr,
    [NVIC_IRQ_DMA2_CHANNEL3] = dma2_channel3_isr,
    [NVIC_IRQ_DMA2_CHANNEL4] = dma2_channel4_isr,
    [NVIC_IRQ_DMA2_CHANNEL5] = dma2_channel5_isr,

#if defined(STM32_ETH)
    [NVIC_IRQ_ETH]           = eth_isr,
    [NVIC_IRQ_ETH_WAKEUP]      = eth_wkup_isr,
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
  }
};

