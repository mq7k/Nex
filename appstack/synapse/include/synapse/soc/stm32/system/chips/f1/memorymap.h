/**
 * This files defines the memory map of stm32 mcu(s).
 * The layout is the same across all fx versions.
 */
#ifndef STM32_MEMORYMAP_H
#define STM32_MEMORYMAP_H

#if !defined(STM32_MEMORYMAP)
  #define STM32_MEMORYMAP
#else
  #error "Cannot define stm32 memory map twice."
#endif

#define PERIPHERALS_BASE_ADDR (0x40000000L)

#define APB1_BASE_ADDR (PERIPHERALS_BASE_ADDR + 0x0)
#define APB2_BASE_ADDR (PERIPHERALS_BASE_ADDR + 0x10000)
#define AHB_BASE_ADDR  (PERIPHERALS_BASE_ADDR + 0x20000)

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                  APB1 peripherals                    │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#define TIM2_ADDR (APB1_BASE_ADDR + 0)
#define TIM3_ADDR (APB1_BASE_ADDR + 0x0400)
#define TIM4_ADDR (APB1_BASE_ADDR + 0x0800)
#define TIM5_ADDR (APB1_BASE_ADDR + 0x0c00)
#define TIM6_ADDR (APB1_BASE_ADDR + 0x1000)
#define TIM7_ADDR (APB1_BASE_ADDR + 0x1400)
#define TIM12_ADDR (APB1_BASE_ADDR + 0x1800)
#define TIM13_ADDR (APB1_BASE_ADDR + 0x1c00)
#define TIM14_ADDR (APB1_BASE_ADDR + 0x2000)

// Memory region from 0x4000 1800 to 0x4000 27ff is reserved.

#define RTC_ADDR (APB1_BASE_ADDR + 0x2800)
#define WWDG_ADDR (APB1_BASE_ADDR + 0x2c00)
#define IWDG_ADDR (APB1_BASE_ADDR + 0x3000)

// Memory region from 0x4000 3400 to 0x4000 37ff is reserved.

#define SPI2_ADDR (APB1_BASE_ADDR + 0x3800)
#define SPI3_ADDR (APB1_BASE_ADDR + 0x3c00)

// Memory region from 0x4000 0000 to 0x4000 43ff is reserved.

#define USART2_ADDR (APB1_BASE_ADDR + 0x4400)
#define USART3_ADDR (APB1_BASE_ADDR + 0x4800)
#define UART4_ADDR (APB1_BASE_ADDR + 0x4c00)
#define UART5_ADDR (APB1_BASE_ADDR + 0x5000)
#define I2C1_ADDR (APB1_BASE_ADDR + 0x5400)
#define I2C2_ADDR (APB1_BASE_ADDR + 0x5800)

// Memory region from 0x4000 5c00 to 0x4000 63ff is reserved.

#define CAN1_ADDR (APB1_BASE_ADDR + 0x6400)
#define CAN2_ADDR (APB1_BASE_ADDR + 0x6800)
#define BKP_ADDR (APB1_BASE_ADDR + 0x6c00)
#define PWR_ADDR (APB1_BASE_ADDR + 0x7000)
#define DAC_ADDR (APB1_BASE_ADDR + 0x7400)

// Memory region from 0x4000 7800 to 0x4000 ffff is reserved.

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                  APB2 peripherals                    │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#define AFIO_ADDR (APB2_BASE_ADDR + 0)
#define EXTI_ADDR (APB2_BASE_ADDR + 0x0400)
#define GPIOA_ADDR (APB2_BASE_ADDR + 0x0800)
#define GPIOB_ADDR (APB2_BASE_ADDR + 0x0c00)
#define GPIOC_ADDR (APB2_BASE_ADDR + 0x1000)
#define GPIOD_ADDR (APB2_BASE_ADDR + 0x1400)
#define GPIOE_ADDR (APB2_BASE_ADDR + 0x1800)
#define GPIOF_ADDR (APB2_BASE_ADDR + 0x1c00)
#define GPIOG_ADDR (APB2_BASE_ADDR + 0x2000)

// Memory region from 0x4001 1c00 to 0x4001 23ff is reserved.

#define ADC1_ADDR (APB2_BASE_ADDR + 0x2400)
#define ADC2_ADDR (APB2_BASE_ADDR + 0x2800)
#define TIM1_ADDR (APB2_BASE_ADDR + 0x2c00)
#define SPI1_ADDR (APB2_BASE_ADDR + 0x3000)
#define TIM8_ADDR (APB2_BASE_ADDR + 0x3400)

// Memory region from 0x4001 3400 to 0x4001 37ff is reserved.

#define USART1_ADDR (APB2_BASE_ADDR + 0x3800)
#define ADC3_ADDR (APB2_BASE_ADDR + 0x3c00)
#define TIM15_ADDR (APB2_BASE_ADDR + 0x4000)
#define TIM16_ADDR (APB2_BASE_ADDR + 0x4400)
#define TIM17_ADDR (APB2_BASE_ADDR + 0x4800)
#define TIM9_ADDR (APB2_BASE_ADDR + 0x4c00)
#define TIM10_ADDR (APB2_BASE_ADDR + 0x5000)
#define TIM11_ADDR (APB2_BASE_ADDR + 0x5400)
#define SDIO_ADDR (APB2_BASE_ADDR + 0x8000)

// Memory region from 0x4001 3c00 to 0x4001 ffff is reserved.

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                   AHB peripherals                    │
// │                                                      │
// └──────────────────────────────────────────────────────┘

#define DMA1_ADDR (AHB_BASE_ADDR + 0)
#define DMA2_ADDR (AHB_BASE_ADDR + 0x0400)

// Memory region from 0x4002 0800 to 0x4002 0fff is reserved.

#define RCC_ADDR (AHB_BASE_ADDR + 0x1000)

// Memory region from 0x4002 1000 to 0x4002 13ff is reserved.

#define FLASH_INTERFACE_ADDR (AHB_BASE_ADDR + 0x2000)

// Memory region from 0x4002 2400 to 0x4002 2fff is reserved.

#define CRC_ADDR (AHB_BASE_ADDR + 0x3000)

// Memory region from 0x4002 3400 to 0x4002 7fff is reserved.

#define ETHERNET_ADDR (AHB_BASE_ADDR + 0x8000)

// Memory region from 0x4003 0000 to 0x4fff ffff is reserved.

#define USB_FS_ADDR (0x50000000)

// Memory region from 0x5000 0400 to 0x5fff ffffis reserved.

#endif
