#ifndef ARCH_DRIVER_NVIC_H
#define ARCH_DRIVER_NVIC_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

// #define NVIC_IRQ_COUNT (68)

struct nvic_registers_map
{
  u32 ISER[8];
  u32 _padding0[24];

  u32 ICER[8];
  u32 _padding1[24];

  u32 ISPR[8];
  u32 _padding2[24];

  u32 ICPR[8];
  u32 _padding3[24];

  u32 IABR[8];
  u32 _padding4[56];

  u32 IPR[60];
  u32 _padding5[644];

  u32 STIR;
};

#define NVIC_IPR_MASK (0xffu)

enum nvic_irq
{
  NVIC_IRQ_WWDG = 0,
  NVIC_IRQ_PVD = 1,
  NVIC_IRQ_TAMP_STAMP = 2,
  NVIC_IRQ_RTC_WAKEUP = 3,
  NVIC_IRQ_FLASH = 4,
  NVIC_IRQ_RCC = 5,
  NVIC_IRQ_EXTI0 = 6,
  NVIC_IRQ_EXTI1 = 7,
  NVIC_IRQ_EXTI2 = 8,
  NVIC_IRQ_EXTI3 = 9,
  NVIC_IRQ_EXTI4 = 10,
  NVIC_IRQ_DMA1_STREAM0 = 11,
  NVIC_IRQ_DMA1_STREAM1 = 12,
  NVIC_IRQ_DMA1_STREAM2 = 13,
  NVIC_IRQ_DMA1_STREAM3 = 14,
  NVIC_IRQ_DMA1_STREAM4 = 15,
  NVIC_IRQ_DMA1_STREAM5 = 16,
  NVIC_IRQ_DMA1_STREAM6 = 17,
  NVIC_IRQ_ADC = 18,

#if defined(STM32_CAN1)
  NVIC_IRQ_CAN1_TX = 19,
  NVIC_IRQ_CAN1_RX0 = 20,
  NVIC_IRQ_CAN1_RX1 = 21,
  NVIC_IRQ_CAN1_SCE = 22,
#endif

  NVIC_IRQ_EXTI9_5 = 23,
  NVIC_IRQ_TIM1_BREAK_TIM9 = 24,
  NVIC_IRQ_TIM1_UPDATE_TIM10 = 25,
  NVIC_IRQ_TIM1_TRIGGER_TIM11 = 26,
  NVIC_IRQ_TIM1_CC = 27,

#if defined(STM32_TIM2)
  NVIC_IRQ_TIM2 = 28,
#endif

#if defined(STM32_TIM3)
  NVIC_IRQ_TIM3 = 29,
#endif

#if defined(STM32_TIM4)
  NVIC_IRQ_TIM4 = 30,
#endif

  NVIC_IRQ_I2C1_EVENT = 31,
  NVIC_IRQ_I2C1_ERROR = 32,
  NVIC_IRQ_I2C2_EVENT = 33,
  NVIC_IRQ_I2C2_ERROR = 34,
  NVIC_IRQ_SPI1 = 35,
  NVIC_IRQ_SPI2 = 36,
  NVIC_IRQ_USART1 = 37,
  NVIC_IRQ_USART2 = 38,

#if defined(STM32_USART3)
  NVIC_IRQ_USART3 = 39,
#endif

  NVIC_IRQ_EXTI15_10 = 40,
  NVIC_IRQ_RTC_ALARM = 41,

#if defined(STM32_USB_OTG_FS)
  NVIC_IRQ_OTG_FS_WAKEUP = 42,
#endif

#if defined(STM32_TIM8)
  NVIC_IRQ_TIM8_BREAK_TIM12 = 43,
  NVIC_IRQ_TIM8_UPDATE_TIM13 = 44,
  NVIC_IRQ_TIM8_TRIGGER_TIM14 = 45,
  NVIC_IRQ_TIM8_CC = 46,
#endif

  NVIC_IRQ_DMA1_STREAM7 = 47,

#if defined(STM32_FSMC)
  NVIC_IRQ_FSMC = 48,
#elif defined(STM32_FMC)
  NVIC_IRQ_FMC = 48,
#endif

#if defined(STM32_SDIO)
  NVIC_IRQ_SDIO = 49,
#endif

  NVIC_IRQ_TIM5 = 50,

#if defined(STM32_SPI3)
  NVIC_IRQ_SPI3 = 51,
#endif

#if defined(STM32_UART4)
  NVIC_IRQ_UART4 = 52,
#endif

#if defined(STM32_UART5)
  NVIC_IRQ_UART5 = 53,
#endif

  NVIC_IRQ_TIM6_DAC = 54,

#if defined(STM32_TIM7)
  NVIC_IRQ_TIM7 = 55,
#endif

  NVIC_IRQ_DMA2_STREAM0 = 56,
  NVIC_IRQ_DMA2_STREAM1 = 57,
  NVIC_IRQ_DMA2_STREAM2 = 58,
  NVIC_IRQ_DMA2_STREAM3 = 59,
  NVIC_IRQ_DMA2_STREAM4 = 60,

#if defined(STM32_ETH)
  NVIC_IRQ_ETH = 61,
  NVIC_IRQ_ETH_WAKEUP = 62,
#else
  // TODO: Check this
  NVIC_IRQ_EXTI19 = 62,
#endif

#if defined(STM32_CAN2)
  NVIC_IRQ_CAN2_TX = 63,
  NVIC_IRQ_CAN2_RX0 = 64,
  NVIC_IRQ_CAN2_RX1 = 65,
  NVIC_IRQ_CAN2_SCE = 66,
#endif

#if defined(STM32_USB_OTG_FS)
  NVIC_IRQ_OTG_FS = 67,
#endif

  NVIC_IRQ_DMA2_STREAM5 = 68,
  NVIC_IRQ_DMA2_STREAM6 = 69,
  NVIC_IRQ_DMA2_STREAM7 = 70,
  NVIC_IRQ_USART6 = 71,

#if defined(STM32_I2C3)
  NVIC_IRQ_I2C3_EVENT = 72,
  NVIC_IRQ_I2C3_ERROR = 73,
#endif

#if defined(STM32_USB_OTG_HS)
  NVIC_IRQ_OTG_HS_EP1_OUTPUT = 74,
  NVIC_IRQ_OTG_HS_EP1_INPUT = 75,
  NVIC_IRQ_OTG_HS_WAKEUP = 76,
  NVIC_IRQ_OTG_HS = 77,
#else
  // TODO: Check this
  NVIC_IRQ_EXTI20 = 76,
#endif

#if defined(STM32_DCMI)
  NVIC_IRQ_DCMI = 78,
#endif

#if defined(STM32_CRYP)
  NVIC_IRQ_CRYPTO = 79,
#endif

#if defined(STM32_HASH) || defined(STM32_RNG)
  NVIC_IRQ_HASH_RNG = 80,
#endif

  NVIC_IRQ_FPU = 81,

#if defined(STM32_UART7)
  NVIC_IRQ_UART7 = 82,
#endif

#if defined(STM32_UART7)
  NVIC_IRQ_UART8 = 83,
#endif

#if defined(STM32_SPI4)
  NVIC_IRQ_SPI4 = 84,
#endif

#if defined(STM32_SPI5)
  NVIC_IRQ_SPI5 = 85,
#endif

#if defined(STM32_SPI6)
  NVIC_IRQ_SPI6 = 86,
#endif

#if defined(STM32_SAI1)
  NVIC_IRQ_SAI1 = 87,
#endif

#if defined(STM32_LCD_TFT)
  NVIC_IRQ_LCD_TFT = 88,
  NVIC_IRQ_LCD_TFT_ERROR = 89,
#endif

#if defined(STM32_DMA2D)
  NVIC_IRQ_DMA2D = 90,
#endif

#if defined(STM32_SAI2)
  NVIC_IRQ_SAI2 = 91,
#endif

#if defined(STM32_QUADSPI)
#if defined(STM32_NVIC_QUADSPI_OFFSET)
  NVIC_IRQ_QUADSPI = 92,
#else
  NVIC_IRQ_QUADSPI = 91,
#endif
#endif

#if defined(STM32_HDMI_CEC)
  NVIC_IRQ_HDMI_CEC = 93,
#endif

#if defined(STM32_SPDIFRX)
  NVIC_IRQ_SPDIFRX = 94,
#endif

#if defined(STM32_FMPI2C1)
  NVIC_IRQ_FMPI2C1_EVENT = 95,
  NVIC_IRQ_FMPI2C1_ERR = 96,
#endif

#if defined(STM32_DSI)
  NVIC_IRQ_DSI = 92,
#endif

#if defined(STM32_I2C4)
  NVIC_IRQ_I2C4_ERROR = 96,
#endif

#if defined(STM32_LPTIM1)
  NVIC_IRQ_LPTIM1 = 97,
#endif

#if defined(STM32_DFSDM2)
  NVIC_IRQ_DFSDM2_FLT0 = 98,
  NVIC_IRQ_DFSDM2_FLT1 = 99,
  NVIC_IRQ_DFSDM2_FLT2 = 100,
  NVIC_IRQ_DFSDM2_FLT3 = 101
#endif
};

extern volatile struct nvic_registers_map* NVIC;

void
nvic_irq_enable(
  enum nvic_irq interrupt
);

void
nvic_irq_disable(
  enum nvic_irq interrupt
);

u32
nvic_is_irq_enabled(
  enum nvic_irq interrupt
);

void
nvic_set_irq_pending(
  enum nvic_irq interrupt
);

void
nvic_clear_pending_irq(
  enum nvic_irq interrupt
);

u32
nvic_is_irq_being_processed(
  enum nvic_irq interrupt
);

void
nvic_set_irq_priority(
  enum nvic_irq interrupt,
  u32 priority
);

u32
nvic_get_irq_priority(
  enum nvic_irq interrupt
);

void
nvic_trigger_irq(
  enum nvic_irq interrupt
);

/* Default implementations */
void blocking_handler(void);
void null_handler(void);

/* Core exceptions */
void nmi_handler();
void hard_fault_handler(void);
void memory_fault_handler(void);
void bus_fault_handler(void);
void usage_fault_handler(void);
void debug_monitor_handler(void);
void sv_call_handler(void);
void pend_sv_handler(void);
void systick_handler(void);

/* Interrupts service routines */
void wwdg_isr(void);
void pvd_isr(void);
void tamper_isr(void);
void rtc_wakeup_isr(void);
void flash_isr(void);
void rcc_isr(void);
void exti0_isr(void);
void exti1_isr(void);
void exti2_isr(void);
void exti3_isr(void);
void exti4_isr(void);
void dma1_stream0_isr(void);
void dma1_stream1_isr(void);
void dma1_stream2_isr(void);
void dma1_stream3_isr(void);
void dma1_stream4_isr(void);
void dma1_stream5_isr(void);
void dma1_stream6_isr(void);
void adc_isr(void);

#if defined(STM32_CAN1)
void can1_tx_isr(void);
void can1_rx0_isr(void);
void can1_rx1_isr(void);
void can1_sce_isr(void);
#endif

void exti9_5_isr(void);
void tim1_brk_isr(void);
void tim1_up_isr(void);
void tim1_trg_com_isr(void);
void tim1_cc_isr(void);

#if defined(STM32_TIM2)
void tim2_isr(void);
#endif

#if defined(STM32_TIM3)
void tim3_isr(void);
#endif

#if defined(STM32_TIM4)
void tim4_isr(void);
#endif

void i2c1_ev_isr(void);
void i2c1_er_isr(void);

void i2c2_ev_isr(void);
void i2c2_er_isr(void);

void spi1_isr(void);
void spi2_isr(void);

void usart1_isr(void);
void usart2_isr(void);

#if defined(STM32_USART3)
void usart3_isr(void);
#endif

void exti15_10_isr(void);

void rtc_alarm_isr(void);

#if defined(STM32_USB_OTG_FS)
void otg_fs_wkup_isr(void);
#endif

#if defined(STM32_TIM8)
void tim8_brk_isr(void);
void tim8_up_isr(void);
void tim8_trg_isr(void);
void tim8_cc_isr(void);
#endif

void dma1_stream7_isr(void);

#if defined(STM32_FSMC)
void fsmc_isr(void);
#elif defined(STM32_FMC)
void fmc_isr(void);
#endif

#if defined(STM32_SDIO)
void sdio_isr(void);
#endif

void tim5_isr(void);

#if defined(STM32_SPI3)
void spi3_isr(void);
#endif

#if defined(STM32_UART4)
void uart4_isr(void);
#endif

#if defined(STM32_UART4)
void uart5_isr(void);
#endif

void tim6_isr(void);

#if defined(STM32_TIM7)
void tim7_isr(void);
#endif

void dma2_stream0_isr(void);
void dma2_stream1_isr(void);
void dma2_stream2_isr(void);
void dma2_stream3_isr(void);
void dma2_stream4_isr(void);

#if defined(STM32_ETH)
void eth_isr(void);
void eth_wkup_isr(void);
#endif

#if defined(STM32_CAN2)
void can2_tx_isr(void);
void can2_rx0_isr(void);
void can2_rx1_isr(void);
void can2_sce_isr(void);
#endif

#if defined(STM32_USB_OTG_FS)
void otg_fs_isr(void);
#endif

void dma2_stream5_isr(void);
void dma2_stream6_isr(void);
void dma2_stream7_isr(void);

void usart6_isr(void);

#if defined(STM32_I2C3)
void i2c3_event_isr(void);
void i2c3_error_isr(void);
#endif

#if defined(STM32_USB_OTG_HS)
void otg_hs_ep1_out_isr(void);
void otg_hs_ep1_in_isr(void);
void otg_hs_wakeup_isr(void);
void otg_hs_isr(void);
#endif

#if defined(STM32_DCMI)
void dcmi_isr(void);
#endif

#if defined(STM32_CRYP)
void cryp_isr(void);
#endif

#if defined(STM32_HASH) || defined(STM32_RNG)
void hash_rng_isr(void);
#endif

void fpu_isr(void);

#if defined(STM32_UART7)
void usart7_isr(void);
#endif

#if defined(STM32_UART8)
void usart8_isr(void);
#endif

#if defined(STM32_SPI4)
void spi4_isr(void);
#endif

#if defined(STM32_SPI5)
void spi5_isr(void);
#endif

#if defined(STM32_SPI6)
void spi6_isr(void);
#endif

#if defined(STM32_SAI1)
void sai1_isr(void);
#endif

#if defined(STM32_LCD_TFT)
void lcd_tft_isr(void);
void lcd_tft_error_isr(void);
#endif

#if defined(STM32_DMA2D)
void dma2d_isr(void);
#endif

#if defined(STM32_SAI2)
void sai2_isr(void);
#endif

#if defined(STM32_QUADSPI)
void quadspi_isr(void);
#endif

#if defined(STM32_HDMI_CEC)
void hdmi_cec_isr(void);
#endif

#if defined(STM32_SPDIFRX)
void spdifrx_isr(void);
#endif

#if defined(STM32_FMPI2C1)
void fmpi2c1_event_isr(void);
void fmpi2c1_error_isr(void);
#endif

#if defined(STM32_DSI)
void dsi_isr(void);
#endif

#if defined(STM32_I2C4)
void i2c4_isr(void);
#endif

#if defined(STM32_LPTIM1)
void lptim1_isr(void);
#endif

#if defined(STM32_DFSDM2)
void dfsdm2_flt0_isr(void);
void dfsdm2_flt1_isr(void);
void dfsdm2_flt2_isr(void);
void dfsdm2_flt3_isr(void);
#endif

END_DECLARATIONS

#endif

