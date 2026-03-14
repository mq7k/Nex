#ifndef STM32_DRIVER_RCC_H
#define STM32_DRIVER_RCC_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F4x
 */

BEGIN_DECLARATIONS

struct rcc_registers_map
{
  u32 CR;
  u32 PLLCFGR;
  u32 CFGR;
  u32 CIR;
  u32 AHB1RSTR;

#if defined(STM32_RCC_AHB2)
  u32 AHB2RSTR;
#else
  u32 _reserved0;
#endif

#if defined(STM32_RCC_AHB3)
  u32 AHB3RSTR;
#else
  u32 _reserved1;
#endif

  u32 _reserved2; // 28

  u32 APB1RSTR;
  u32 APB2RSTR;

  u32 _reserved3[2];

  u32 AHB1ENR;

#if defined(STM32_RCC_AHB2)
  u32 AHB2ENR;
#else
  u32 _reserved4;
#endif

#if defined(STM32_RCC_AHB3)
  u32 AHB3ENR;
#else
  u32 _reserved5;
#endif

  u32 _reserved6;

  u32 APB1ENR;
  u32 APB2ENR;

  u32 _reserved7[2];

  u32 AHB1LPENR;

#if defined(STM32_RCC_AHB2)
  u32 AHB2LPENR;
#else
  u32 _reserved8;
#endif

#if defined(STM32_RCC_AHB3)
  u32 AHB3LPENR;
#else
  u32 _reserved9;
#endif

  u32 _reserved10;

  u32 APB1LPENR;
  u32 APB2LPENR;

  u32 _reserved11[2];

  u32 BDCR;
  u32 CSR;

  u32 _reserved12[2];

  u32 SSCGR;

#if defined(STM32_RCC_PLLI2S)
  u32 PLLI2SCFGR;
#else
  u32 _reserved13;
#endif

#if defined(STM32_RCC_PLLSAI)
  u32 PLLSAICFGR;
#else
  u32 _reserved14;
#endif

  u32 DCKCFGR;

#if defined(STM32_RCC_CKGATE)
  u32 CKGATENR;
#else
  u32 _reserved15;
#endif

#if defined(STM32_RCC_DCKCFGR2)
  u32 DCKCFGR2;
#endif
};

END_DECLARATIONS

// Core
enum rcc_cr : u32
{
  RCC_CR_HSION = (1 << 0),
  RCC_CR_HSIRDY = (1 << 1),
  RCC_CR_HSEON = (1 << 16),
  RCC_CR_HSERDY = (1 << 17),
  RCC_CR_HSEBYP = (1 << 18),
  RCC_CR_CSSON = (1 << 19),
  RCC_CR_PLLON = (1 << 24),
  RCC_CR_PLLRDY = (1 << 25),

#if defined(STM32_RCC_OSC_PLLI2S)
  RCC_CR_PLLI2SON = (1 << 26),
  RCC_CR_PLLI2SRDY = (1 << 27),
#endif

#if defined(STM32_RCC_OSC_PLLSAI)
  RCC_CR_PLLSAION = (1 << 28),
  RCC_CR_PLLSAIRDY = (1 << 29)
#endif
};

#define RCC_CR_HSITRIM_SHIFT (3)
#define RCC_CR_HSITRIM_MASK (0x1f)

#define RCC_CR_HSICAL_SHIFT (8)
#define RCC_CR_HSICAL_MASK (0xff)

enum rcc_pllcfgr : u32
{
  RCC_PLLCFGR_PLLSRC = (1 << 22)
};

#define RCC_PLLCFGR_PLLM_SHIFT (0)
#define RCC_PLLCFGR_PLLM_MASK (0x3fu)
#define RCC_PLLCFGR_PLLM_MIN_VAL (2)
#define RCC_PLLCFGR_PLLM_MAX_VAL (63)

#define RCC_PLLCFGR_PLLN_SHIFT (6)
#define RCC_PLLCFGR_PLLN_MASK (0x1ffu)
#define RCC_PLLCFGR_PLLN_MIN_VAL (50)
#define RCC_PLLCFGR_PLLN_MAX_VAL (432)

#define RCC_PLLCFGR_PLLP_SHIFT (16)
#define RCC_PLLCFGR_PLLP_MASK (0x3u)

enum rcc_pllcfgr_pllp : u32
{
  RCC_PLLCFGR_PLLP_DIV2 = 0b00,
  RCC_PLLCFGR_PLLP_DIV4 = 0b01,
  RCC_PLLCFGR_PLLP_DIV6 = 0b10,
  RCC_PLLCFGR_PLLP_DIV8 = 0b11
};

#define RCC_PLLCFGR_PLLQ_SHIFT (24)
#define RCC_PLLCFGR_PLLQ_MASK (0xfu)
#define RCC_PLLCFGR_PLLQ_MIN_VAL (2)
#define RCC_PLLCFGR_PLLQ_MAX_VAL (15)

#if defined(STM32_RCC_PLLR)
#define RCC_PLLCFGR_PLLR_SHIFT (28)
#define RCC_PLLCFGR_PLLR_MASK (0x7)
#endif

#if defined(STM32_RCC_CFGR)
enum rcc_cfgr : u32
{
#if defined(STM32_RCC_MCOEN)
#if defined(STM32_RCC_MCO1EN)
  RCC_CFGR_MCO1EN = (1 << 8),
#endif

#if defined(STM32_RCC_MCO2EN)
  RCC_CFGR_MCO2EN = (1 << 9),
#endif
#endif

#if defined(STM32_RCC_I2S)
  RCC_CFGR_I2SSRC = (1 << 23)
#endif
};
#endif

#define RCC_CFGR_SW_SHIFT (0)
#define RCC_CFGR_SW_MASK (0x3)

enum rcc_cfgr_sw : u32
{
  RCC_CFGR_SW_HSI = 0b00,
  RCC_CFGR_SW_HSE = 0b01,

#if defined(STM32_RCC_PLLR_SW)
  RCC_CFGR_SW_PLLP = 0b10,
  RCC_CFGR_SW_PLLR = 0b10
#else
  RCC_CFGR_SW_PLL = 0b10
#endif
};

#define RCC_CFGR_SWS_SHIFT (2)
#define RCC_CFGR_SWS_MASK (0x3)

enum rcc_cfgr_sws : u32
{
  RCC_CFGR_SWS_HSI = 0b00,
  RCC_CFGR_SWS_HSE = 0b01,

#if defined(STM32_RCC_PLLR_SW)
  RCC_CFGR_SWS_PLLP = 0b10,
  RCC_CFGR_SWS_PLLR = 0b10
#else
  RCC_CFGR_SWS_PLL = 0b10
#endif
};

#define RCC_CFGR_HPRE_SHIFT (4)
#define RCC_CFGR_HPRE_MASK (0xf)

enum rcc_cfgr_hpre : u32
{
  RCC_CFGR_HPRE_NODIV = 0b0000,
  RCC_CFGR_HPRE_DIV2 = 0b1000,
  RCC_CFGR_HPRE_DIV4 = 0b1001,
  RCC_CFGR_HPRE_DIV8 = 0b1010,
  RCC_CFGR_HPRE_DIV16 = 0b1011,
  RCC_CFGR_HPRE_DIV64 = 0b1100,
  RCC_CFGR_HPRE_DIV128 = 0b1101,
  RCC_CFGR_HPRE_DIV256 = 0b1110,
  RCC_CFGR_HPRE_DIV512 = 0b1111
};

#define RCC_CFGR_PPRE1_SHIFT (10)
#define RCC_CFGR_PPRE1_MASK (0x7)

enum rcc_cfgr_ppre1 : u32
{
  RCC_CFGR_PPRE1_NODIV = 0b000,
  RCC_CFGR_PPRE1_DIV2 = 0b100,
  RCC_CFGR_PPRE1_DIV4 = 0b101,
  RCC_CFGR_PPRE1_DIV8 = 0b110,
  RCC_CFGR_PPRE1_DIV16 = 0b111
};

#define RCC_CFGR_PPRE2_SHIFT (13)
#define RCC_CFGR_PPRE2_MASK (0x7)

enum rcc_cfgr_ppre2 : u32
{
  RCC_CFGR_PPRE2_NODIV = 0b000,
  RCC_CFGR_PPRE2_DIV2 = 0b100,
  RCC_CFGR_PPRE2_DIV4 = 0b101,
  RCC_CFGR_PPRE2_DIV8 = 0b110,
  RCC_CFGR_PPRE2_DIV16 = 0b111
};

#define RCC_CFGR_RTCPRE_SHIFT (16)
#define RCC_CFGR_RTCPRE_MASK (0x1f)

#define RCC_CFGR_MCO1_SHIFT (21)
#define RCC_CFGR_MCO1_MASK (0x3)

enum rcc_cfgr_mco1 : u32
{
  RCC_CFGR_MCO1_HSI = 0b00,
  RCC_CFGR_MCO1_LSE = 0b01,
  RCC_CFGR_MCO1_HSE = 0b10,
  RCC_CFGR_MCO1_PLL = 0b11
};

#define RCC_CFGR_MCO1PRE_SHIFT (24)
#define RCC_CFGR_MCO1PRE_MASK (0x7)

enum rcc_cfgr_mco1pre : u32
{
  RCC_CFGR_MCO1PRE_NODIV = 0b000,
  RCC_CFGR_MCO1PRE_DIV2 = 0b100,
  RCC_CFGR_MCO1PRE_DIV3 = 0b101,
  RCC_CFGR_MCO1PRE_DIV4 = 0b110,
  RCC_CFGR_MCO1PRE_DIV5 = 0b111
};

#define RCC_CFGR_MCO2PRE_SHIFT (27)
#define RCC_CFGR_MCO2PRE_MASK (0x7)

enum rcc_cfgr_mco2pre : u32
{
  RCC_CFGR_MCO2PRE_NODIV = 0b000,
  RCC_CFGR_MCO2PRE_DIV2 = 0b100,
  RCC_CFGR_MCO2PRE_DIV3 = 0b101,
  RCC_CFGR_MCO2PRE_DIV4 = 0b110,
  RCC_CFGR_MCO2PRE_DIV5 = 0b111
};

#define RCC_CFGR_MCO2_SHIFT (30)
#define RCC_CFGR_MCO2_MASK (0x3u)

enum rcc_cfgr_mco2 : u32
{
  RCC_CFGR_MCO2_SYSCLK = 0b00,
  RCC_CFGR_MCO2_PLLI2S = 0b01,
  RCC_CFGR_MCO2_HSE = 0b10,
  RCC_CFGR_MCO2_PLL = 0b11
};

enum rcc_cir : u32
{
  RCC_CIR_LSIRDYF = (1 << 0),
  RCC_CIR_LSERDYF = (1 << 1),
  RCC_CIR_HSIRDYF = (1 << 2),
  RCC_CIR_HSERDYF = (1 << 3),
  RCC_CIR_PLLRDYF = (1 << 4),

#if defined(STM32_RCC_PLLI2S)
  RCC_CIR_PLLI2SRDYF = (1 << 5),
#endif

#if defined(STM32_RCC_PLLSAI)
  RCC_CIR_PLLSAIRDYF = (1 << 6),
#endif

  RCC_CIR_CSSF = (1 << 7),
  RCC_CIR_LSIRDYIE = (1 << 8),
  RCC_CIR_LSERDYIE = (1 << 9),
  RCC_CIR_HSIRDYIE = (1 << 10),
  RCC_CIR_HSERDYIE = (1 << 11),
  RCC_CIR_PLLRDYIE = (1 << 12),

#if defined(STM32_RCC_PLLI2S)
  RCC_CIR_PLLI2SRDYIE = (1 << 13),
#endif

#if defined(STM32_RCC_PLLSAI)
  RCC_CIR_PLLSAIRDYIE = (1 << 14),
#endif

  RCC_CIR_LSIRDYC = (1 << 16),
  RCC_CIR_LSERDYC = (1 << 17),
  RCC_CIR_HSIRDYC = (1 << 18),
  RCC_CIR_HSERDYC = (1 << 19),
  RCC_CIR_PLLRDYC = (1 << 20),

#if defined(STM32_RCC_PLLI2S)
  RCC_CIR_PLLI2SRDYC = (1 << 21),
#endif

#if defined(STM32_RCC_PLLSAI)
  RCC_CIR_PLLSAIRDYC = (1 << 22),
#endif

  RCC_CIR_CSSC = (1 << 23)
};

enum rcc_ahb1rstr : u32
{
#if defined(STM32_GPIOA)
  RCC_AHB1RSTR_GPIOARST = (1 << 0),
#endif

#if defined(STM32_GPIOB)
  RCC_AHB1RSTR_GPIOBRST = (1 << 1),
#endif

#if defined(STM32_GPIOC)
  RCC_AHB1RSTR_GPIOCRST = (1 << 2),
#endif

#if defined(STM32_GPIOD)
  RCC_AHB1RSTR_GPIODRST = (1 << 3),
#endif

#if defined(STM32_GPIOE)
  RCC_AHB1RSTR_GPIOERST = (1 << 4),
#endif

#if defined(STM32_GPIOF)
  RCC_AHB1RSTR_GPIOFRST = (1 << 5),
#endif

#if defined(STM32_GPIOG)
  RCC_AHB1RSTR_GPIOGRST = (1 << 6),
#endif

#if defined(STM32_GPIOH)
  RCC_AHB1RSTR_GPIOHRST = (1 << 7),
#endif

#if defined(STM32_GPIOI)
  RCC_AHB1RSTR_GPIOIRST = (1 << 8),
#endif

#if defined(STM32_GPIOJ)
  RCC_AHB1RSTR_GPIOJRST = (1 << 9),
#endif

#if defined(STM32_GPIOK)
  RCC_AHB1RSTR_GPIOKRST = (1 << 10),
#endif

  RCC_AHB1RSTR_CRCRST = (1 << 12),
  RCC_AHB1RSTR_DMA1RST = (1 << 21),
  RCC_AHB1RSTR_DMA2RST = (1 << 22),

#if defined(STM32_DMA2D)
  RCC_AHB1RSTR_DMA2DRST = (1 << 23),
#endif

#if defined(STM32_ETHERNET_MAC)
  RCC_AHB1RSTR_ETHMACRST = (1 << 25),
#endif

#if defined(STM32_USB_OTG_HS)
  RCC_AHB1RSTR_OTGHSRST = (1 << 29),
#endif

#if defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB1)
  RCC_AHB1RSTR_RNGRST = (1u << 31)
#endif
};

#if defined(STM32_RCC_AHB2_REG)
enum rcc_ahb2rstr : u32
{
#if defined(STM32_DCMI)
  RCC_AHB2RSTR_DCMIRST = (1 << 0),
#endif

#if defined(STM32_CRYP)
  RCC_AHB2RSTR_CRYPRST = (1 << 4),
#endif

#if defined(STM32_HASH)
  RCC_AHB2RSTR_HASHRST = (1 << 5),
#endif

#if defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB2)
  RCC_AHB2RSTR_RNGRST = (1 << 6),
#endif

#if defined(STM32_USB_OTG_FS)
  RCC_AHB2RSTR_OTGFSRST = (1 << 7)
#endif
};
#endif

#if defined(STM32_RCC_AHB3)
enum rcc_ahb3rstr : u32
{
#if defined(STM32_FMC)
  RCC_AHB3RSTR_FMCRST = (1 << 0),
#elif defined(STM32_FSMC)
  RCC_AHB3RSTR_FSMCRST = (1 << 0),
#endif

#if defined(STM32_QUADSPI)
  RCC_AHB3RSTR_QSPIRST = (1 << 1),
#endif
};
#endif

enum rcc_apb1rstr : u32
{

#if defined(STM32_TIM2)
  RCC_APB1RSTR_TIM2RST = (1 << 0),
#endif

#if defined(STM32_TIM3)
  RCC_APB1RSTR_TIM3RST = (1 << 1),
#endif

#if defined(STM32_TIM4)
  RCC_APB1RSTR_TIM4RST = (1 << 2),
#endif

#if defined(STM32_TIM5)
  RCC_APB1RSTR_TIM5RST = (1 << 3),
#endif

#if defined(STM32_TIM6)
  RCC_APB1RSTR_TIM6RST = (1 << 4),
#endif

#if defined(STM32_TIM7)
  RCC_APB1RSTR_TIM7RST = (1 << 5),
#endif

#if defined(STM32_TIM12)
  RCC_APB1RSTR_TIM12RST = (1 << 6),
#endif

#if defined(STM32_TIM13)
  RCC_APB1RSTR_TIM13RST = (1 << 7),
#endif

#if defined(STM32_TIM14)
  RCC_APB1RSTR_TIM14RST = (1 << 8),
#endif

#if defined(STM32_LPTIM1)
  RCC_APB1RSTR_LPTIM1RST = (1 << 9),
#endif

  RCC_APB1RSTR_WWDGRST = (1 << 11),
  RCC_APB1RSTR_SPI2RST = (1 << 14),

#if defined(STM32_SPI3)
  RCC_APB1RSTR_SPI3RST = (1 << 15),
#endif

#if defined(STM32_SPDIFRX)
  RCC_APB1RSTR_SPDIFRXRST = (1 << 16),
#endif

  RCC_APB1RSTR_USART2RST = (1 << 17),

#if defined(STM32_USART3)
  RCC_APB1RSTR_USART3RST = (1 << 18),
#endif

#if defined(STM32_UART4)
  RCC_APB1RSTR_UART4RST = (1 << 19),
#endif

#if defined(STM32_UART5)
  RCC_APB1RSTR_UART5RST = (1 << 20),
#endif

  RCC_APB1RSTR_I2C1RST = (1 << 21),
  RCC_APB1RSTR_I2C2RST = (1 << 22),

#if defined(STM32_I2C3)
  RCC_APB1RSTR_I2C3RST = (1 << 23),
#endif

#if defined(STM32_FMPI2C1)
  RCC_APB1RSTR_FMPI2C1RST = (1 << 24),
#endif

#if defined(STM32_CAN1)
  RCC_APB1RSTR_CAN1RST = (1 << 25),
#endif

#if defined(STM32_CAN2)
  RCC_APB1RSTR_CAN2RST = (1 << 26),
#endif

#if defined(STM32_CEC)
  RCC_APB1RSTR_CECRST = (1 << 27),
#elif defined(STM32_CAN3)
  RCC_APB1RSTR_CAN3RST = (1 << 27),
#endif

  RCC_APB1RSTR_PWRRST = (1 << 28),

#if defined(STM32_DAC)
  RCC_APB1RSTR_DACRST = (1 << 29),
#endif

#if defined(STM32_UART7)
  RCC_APB1RSTR_UART7RST = (1 << 30),
#endif

#if defined(STM32_UART8)
  RCC_APB1RSTR_UART8RST = (1u << 31)
#endif
};

enum rcc_apb2rstr : u32
{
  RCC_APB2RSTR_TIM1RST = (1 << 0),

#if defined(STM32_TIM8)
  RCC_APB2RSTR_TIM8RST = (1 << 1),
#endif

  RCC_APB2RSTR_USART1RST = (1 << 4),
  RCC_APB2RSTR_USART6RST = (1 << 5),

#if defined(STM32_UART9)
  RCC_APB2RSTR_UART9RST = (1 << 6),
#endif

#if defined(STM32_UART10)
  RCC_APB2RSTR_UART10RST = (1 << 7),
#endif

  RCC_APB2RSTR_ADCRST = (1 << 8),

#if defined(STM32_SDIO)
  RCC_APB2RSTR_SDIORST = (1 << 11),
#endif

  RCC_APB2RSTR_SPI1RST = (1 << 12),

#if defined(STM32_SPI4)
  RCC_APB2RSTR_SPI4RST = (1 << 13),
#endif

  RCC_APB2RSTR_SYSCFGRST = (1 << 14),
  RCC_APB2RSTR_TIM9RST = (1 << 16),

#if defined(STM32_TIM10)
  RCC_APB2RSTR_TIM10RST = (1 << 17),
#endif

  RCC_APB2RSTR_TIM11RST = (1 << 18),

#if defined(STM32_SPI5)
  RCC_APB2RSTR_SPI5RST = (1 << 20),
#endif

#if defined(STM32_SPI6)
  RCC_APB2RSTR_SPI6RST = (1 << 21),
#endif

#if defined(STM32_SAI1)
  RCC_APB2RSTR_SAI1RST = (1 << 22),
#endif

#if defined(STM32_SAI1)
  RCC_APB2RSTR_SAI2RST = (1 << 23),
#endif

#if defined(STM32_DFSDM1)
  RCC_APB2RSTR_DFSDM1RST = (1 << 24),
#endif

#if defined(STM32_DFSDM2)
  RCC_APB2RSTR_DFSDM2RST = (1 << 25),
#endif

#if defined(STM32_LTDC)
  RCC_APB2RSTR_LTDCRST = (1 << 26),
#endif

#if defined(STM32_DSI_HOST)
  RCC_APB2RSTR_DSIRST = (1 << 27)
#endif
};

enum rcc_ahb1enr : u32
{

#if defined(STM32_GPIOA)
  RCC_AHB1ENR_GPIOAEN = (1 << 0),
#endif

#if defined(STM32_GPIOB)
  RCC_AHB1ENR_GPIOBEN = (1 << 1),
#endif

#if defined(STM32_GPIOC)
  RCC_AHB1ENR_GPIOCEN = (1 << 2),
#endif

#if defined(STM32_GPIOD)
  RCC_AHB1ENR_GPIODEN = (1 << 3),
#endif

#if defined(STM32_GPIOE)
  RCC_AHB1ENR_GPIOEEN = (1 << 4),
#endif

#if defined(STM32_GPIOF)
  RCC_AHB1ENR_GPIOFEN = (1 << 5),
#endif

#if defined(STM32_GPIOG)
  RCC_AHB1ENR_GPIOGEN = (1 << 6),
#endif

#if defined(STM32_GPIOH)
  RCC_AHB1ENR_GPIOHEN = (1 << 7),
#endif

#if defined(STM32_GPIOI)
  RCC_AHB1ENR_GPIOIEN = (1 << 8),
#endif

#if defined(STM32_GPIOJ)
  RCC_AHB1ENR_GPIOJEN = (1 << 9),
#endif

#if defined(STM32_GPIOK)
  RCC_AHB1ENR_GPIOKEN = (1 << 10),
#endif

  RCC_AHB1ENR_CRCEN = (1 << 12),

#if defined(STM32_BKPSRAM)
  RCC_AHB1ENR_BKPSRAMEN = (1 << 18),
#endif

#if defined(STM32_CCMRAM)
  RCC_AHB1ENR_CCMDATARAMEN = (1 << 20),
#endif

  RCC_AHB1ENR_DMA1EN = (1 << 21),
  RCC_AHB1ENR_DMA2EN = (1 << 22),

#if defined(STM32_DMA2D)
  RCC_AHB1ENR_DMA2DEN = (1 << 23),
#endif

#if defined(STM32_ETHERNET_MAC)
  RCC_AHB1ENR_ETHMACEN = (1 << 25),
  RCC_AHB1ENR_ETHMACTXEN = (1 << 26),
  RCC_AHB1ENR_ETHMACRXEN = (1 << 27),
  RCC_AHB1ENR_ETHMACPTPEN = (1 << 28),
#endif

#if defined(STM32_USB_OTG_HS)
  RCC_AHB1ENR_OTGHSEN = (1 << 29),
#endif

#if defined(STM32_USB_OTG_HSULPI)
  RCC_AHB1ENR_OTGHSULPIEN = (1 << 30),
#endif

#if defined(STM32_RNG)
  RCC_AHB1ENR_RNGEN = (1u << 31)
#endif
};

#if defined(STM32_RCC_AHB2)
enum rcc_ahb2enr : u32
{
#if defined(STM32_DCMI)
  RCC_AHB2ENR_DCMIEN = (1 << 0),
#endif

#if defined(STM32_CRYP)
  RCC_AHB2ENR_CRYPEN = (1 << 4),
#endif

#if defined(STM32_HASH)
  RCC_AHB2ENR_HASHEN = (1 << 5),
#endif

#if defined(STM32_RNG)
  RCC_AHB2ENR_RNGEN = (1 << 6),
#endif

  RCC_AHB2ENR_OTGFSEN = (1 << 7)
};
#endif

#if defined(STM32_RCC_AHB3)
enum rcc_ahb3enr : u32
{
#if defined(STM32_FMC)
  RCC_AHB3ENR_FMCEN = (1 << 0),
#elif defined(STM32_FSMC)
  RCC_AHB3ENR_FSMCEN = (1 << 0),
#endif

#if defined(STM32_QUADSPI)
  RCC_AHB3ENR_QSPIEN = (1 << 1)
#endif
};
#endif

enum rcc_apb1enr : u32
{
#if defined(STM32_TIM2)
  RCC_APB1ENR_TIM2EN = (1 << 0),
#endif

#if defined(STM32_TIM3)
  RCC_APB1ENR_TIM3EN = (1 << 1),
#endif

#if defined(STM32_TIM4)
  RCC_APB1ENR_TIM4EN = (1 << 2),
#endif

  RCC_APB1ENR_TIM5EN = (1 << 3),

#if defined(STM32_TIM6)
  RCC_APB1ENR_TIM6EN = (1 << 4),
#endif
  
#if defined(STM32_TIM7)
  RCC_APB1ENR_TIM7EN = (1 << 5),
#endif

#if defined(STM32_TIM12)
  RCC_APB1ENR_TIM12EN = (1 << 6),
#endif

#if defined(STM32_TIM13)
  RCC_APB1ENR_TIM13EN = (1 << 7),
#endif

#if defined(STM32_TIM14)
  RCC_APB1ENR_TIM14EN = (1 << 8),
#endif

#if defined(STM32_LPTIM1)
  RCC_APB1ENR_LPTIMER1EN = (1 << 9),
#endif

#if defined(STM32_RCC_RTC_APB)
  RCC_APB1ENR_RTCAPBEN = (1 << 10),
#endif

  RCC_APB1ENR_WWDGEN = (1 << 11),
  RCC_APB1ENR_SPI2EN = (1 << 14),
  RCC_APB1ENR_SPI3EN = (1 << 15),

#if defined(STM32_SPDIFRX)
  RCC_APB1ENR_SPDIFRXEN = (1 << 16),
#endif

  RCC_APB1ENR_USART2EN = (1 << 17),

#if defined(STM32_USART3)
  RCC_APB1ENR_USART3EN = (1 << 18),
#endif

#if defined(STM32_UART4)
  RCC_APB1ENR_UART4EN = (1 << 19),
#endif

#if defined(STM32_UART5)
  RCC_APB1ENR_UART5EN = (1 << 20),
#endif

  RCC_APB1ENR_I2C1EN = (1 << 21),
  RCC_APB1ENR_I2C2EN = (1 << 22),

#if defined(STM32_I2C3)
  RCC_APB1ENR_I2C3EN = (1 << 23),
#endif

#if defined(STM32_FMPI2C1)
  RCC_APB1ENR_FMPI2C1EN = (1 << 24),
#endif

#if defined(STM32_CAN1)
  RCC_APB1ENR_CAN1EN = (1 << 25),
#endif

#if defined(STM32_CAN2)
  RCC_APB1ENR_CAN2EN = (1 << 26),
#endif

#if defined(STM32_CEC)
  RCC_APB1ENR_CECEN = (1 << 27),
#elif defined(STM32_CAN3)
  RCC_APB1ENR_CAN3EN = (1 << 27),
#endif

  RCC_APB1ENR_PWREN = (1 << 28),

#if defined(STM32_DAC)
  RCC_APB1ENR_DACEN = (1 << 29),
#endif

#if defined(STM32_UART7)
  RCC_APB1ENR_UART7EN = (1 << 30),
#endif

#if defined(STM32_UART8)
  RCC_APB1ENR_UART8EN = (1u << 31)
#endif
};

enum rcc_apb2enr : u32
{
  RCC_APB2ENR_TIM1EN = (1 << 0),

#if defined(STM32_TIM8)
  RCC_APB2ENR_TIM8EN = (1 << 1),
#endif

  RCC_APB2ENR_USART1EN = (1 << 4),
  RCC_APB2ENR_USART6EN = (1 << 5),

#if defined(STM32_UART9)
  RCC_APB2ENR_UART9EN = (1 << 6),
#endif

#if defined(STM32_UART10)
  RCC_APB2ENR_UART10EN = (1 << 7),
#endif

  RCC_APB2ENR_ADC1EN = (1 << 8),

#if defined(STM32_ADC2)
  RCC_APB2ENR_ADC2EN = (1 << 9),
#endif

#if defined(STM32_ADC3)
  RCC_APB2ENR_ADC3EN = (1 << 10),
#endif

  RCC_APB2ENR_SDIOEN = (1 << 11),
  RCC_APB2ENR_SPI1EN = (1 << 12),
  RCC_APB2ENR_SPI4EN = (1 << 13),
  RCC_APB2ENR_SYSCFGEN = (1 << 14),

#if defined(STM32_EXTIT)
  RCC_APB2ENR_EXTITEN = (1 << 15),
#endif

  RCC_APB2ENR_TIM9EN = (1 << 16),

#if defined(STM32_TIM10)
  RCC_APB2ENR_TIM10EN = (1 << 17),
#endif

  RCC_APB2ENR_TIM11EN = (1 << 18),

#if defined(STM32_SPI5)
  RCC_APB2ENR_SPI5EN = (1 << 20),
#endif

#if defined(STM32_SPI6)
  RCC_APB2ENR_SPI6EN = (1 << 21),
#endif

#if defined(STM32_SAI1)
  RCC_APB2ENR_SAI1EN = (1 << 22),
#endif

#if defined(STM32_SAI2)
  RCC_APB2ENR_SAI2EN = (1 << 23),
#endif

#if defined(STM32_DFSDM1)
  RCC_APB2ENR_DFSDM1EN = (1 << 24),
#endif

#if defined(STM32_DFSDM1)
  RCC_APB2ENR_DFSDM2EN = (1 << 25),
#endif

#if defined(STM32_LTDC)
  RCC_APB2ENR_LTDCEN = (1 << 26),
#endif
  
#if defined(STM32_DSI_HOST)
  RCC_APB2ENR_DSIEN = (1 << 27)
#endif
};

enum rcc_ahb1lpenr : u32
{
#if defined(STM32_GPIOA)
  RCC_AHB1LPENR_GPIOALPEN = (1 << 0),
#endif

#if defined(STM32_GPIOB)
  RCC_AHB1LPENR_GPIOBLPEN = (1 << 1),
#endif

#if defined(STM32_GPIOC)
  RCC_AHB1LPENR_GPIOCLPEN = (1 << 2),
#endif

#if defined(STM32_GPIOD)
  RCC_AHB1LPENR_GPIODLPEN = (1 << 3),
#endif

#if defined(STM32_GPIOE)
  RCC_AHB1LPENR_GPIOELPEN = (1 << 4),
#endif

#if defined(STM32_GPIOF)
  RCC_AHB1LPENR_GPIOFLPEN = (1 << 5),
#endif

#if defined(STM32_GPIOG)
  RCC_AHB1LPENR_GPIOGLPEN = (1 << 6),
#endif

#if defined(STM32_GPIOH)
  RCC_AHB1LPENR_GPIOHLPEN = (1 << 7),
#endif

#if defined(STM32_GPIOI)
  RCC_AHB1LPENR_GPIOILPEN = (1 << 8),
#endif

#if defined(STM32_GPIOJ)
  RCC_AHB1LPENR_GPIOJLPEN = (1 << 9),
#endif

#if defined(STM32_GPIOK)
  RCC_AHB1LPENR_GPIOKLPEN = (1 << 10),
#endif

  RCC_AHB1LPENR_CRCLPEN = (1 << 12),
  RCC_AHB1LPENR_FLITFLPEN = (1 << 15),
  RCC_AHB1LPENR_SRAM1LPEN = (1 << 16),

#if defined(STM32_SRAM2)
  RCC_AHB1LPENR_SRAM2LPEN = (1 << 17),
#endif

#if defined(STM32_BKPSRAM)
  RCC_AHB1LPENR_BKPSRAMLPEN = (1 << 18),
#endif

#if defined(STM32_SRAM3)
  RCC_AHB1LPENR_SRAM3LPEN = (1 << 19),
#endif

  RCC_AHB1LPENR_DMA1LPEN = (1 << 21),
  RCC_AHB1LPENR_DMA2LPEN = (1 << 22),

#if defined(STM32_DMA2D)
  RCC_AHB1LPENR_DMA2DLPEN = (1 << 23),
#endif

#if defined(STM32_ETHERNET_MAC)
  RCC_AHB1LPENR_ETHMACLPEN = (1 << 25),
  RCC_AHB1LPENR_ETHTXLPEN = (1 << 26),
  RCC_AHB1LPENR_ETHRXLPEN = (1 << 27),
  RCC_AHB1LPENR_ETHPTPLPEN = (1 << 28),
#endif

#if defined(STM32_USB_OTG_HS)
  RCC_AHB1LPENR_OTGHSLPEN = (1 << 29),
#endif

#if defined(STM32_USB_OTG_HSULPI)
  RCC_AHB1LPENR_OTGHSULPILPEN = (1 << 30),
#endif

#if defined(STM32_RNG)
  RCC_AHB1LPENR_RNGLPEN = (1u << 31)
#endif
};

#if defined(STM32_RCC_AHB2)
enum rcc_ahb2lpenr : u32
{
#if defined(STM32_DCMI)
  RCC_AHB2LPENR_DCMILPEN = (1 << 0),
#endif

#if defined(STM32_CRYP)
  RCC_AHB2LPENR_CRYPLPEN = (1 << 4),
#endif

#if defined(STM32_HASH)
  RCC_AHB2LPENR_HASHLPEN = (1 << 5),
#endif

#if defined(STM32_RNG)
  RCC_AHB2LPENR_RNGLPEN = (1 << 6),
#endif

  RCC_AHB2LPENR_OTGFSLPEN = (1 << 7)
};
#endif

#if defined(STM32_RCC_AHB3)
enum rcc_ahb3lpenr : u32
{
#if defined(STM32_FMC)
  RCC_AHB3LPENR_FMCLPEN = (1 << 0),
#elif defined(STM32_FSMC)
  RCC_AHB3LPENR_FSMCLPEN = (1 << 0),
#endif

#if defined(STM32_QUADSPI)
  RCC_AHB3LPENR_QSPILPEN = (1 << 1)
#endif
};
#endif

enum rcc_apb1lpenr : u32
{
#if defined(STM32_TIM2)
  RCC_APB1LPENR_TIM2LPEN = (1 << 0),
#endif

#if defined(STM32_TIM3)
  RCC_APB1LPENR_TIM3LPEN = (1 << 1),
#endif

#if defined(STM32_TIM4)
  RCC_APB1LPENR_TIM4LPEN = (1 << 2),
#endif

#if defined(STM32_TIM5)
  RCC_APB1LPENR_TIM5LPEN = (1 << 3),
#endif

#if defined(STM32_TIM6)
  RCC_APB1LPENR_TIM6LPEN = (1 << 4),
#endif

#if defined(STM32_TIM7)
  RCC_APB1LPENR_TIM7LPEN = (1 << 5),
#endif

#if defined(STM32_TIM12)
  RCC_APB1LPENR_TIM12LPEN = (1 << 6),
#endif

#if defined(STM32_TIM13)
  RCC_APB1LPENR_TIM13LPEN = (1 << 7),
#endif

#if defined(STM32_TIM14)
  RCC_APB1LPENR_TIM14LPEN = (1 << 8),
#endif

#if defined(STM32_LPTIM1)
  RCC_APB1LPENR_LPTIM1LPEN = (1 << 9),
#endif

#if defined(STM32_RCC_RTC_APB)
  RCC_APB1LPENR_RTCAPBLPEN = (1 << 10),
#endif

  RCC_APB1LPENR_WWDGLPEN = (1 << 11),
  RCC_APB1LPENR_SPI2LPEN = (1 << 14),

#if defined(STM32_SPI3)
  RCC_APB1LPENR_SPI3LPEN = (1 << 15),
#endif

#if defined(STM32_SPDIFRX)
  RCC_APB1LPENR_SPDIFRXLPEN = (1 << 16),
#endif

  RCC_APB1LPENR_USART2LPEN = (1 << 17),

#if defined(STM32_USART3)
  RCC_APB1LPENR_USART3LPEN = (1 << 18),
#endif

#if defined(STM32_UART4)
  RCC_APB1LPENR_UART4LPEN = (1 << 19),
#endif

#if defined(STM32_UART5)
  RCC_APB1LPENR_UART5LPEN = (1 << 20),
#endif

  RCC_APB1LPENR_I2C1LPEN = (1 << 21),
  RCC_APB1LPENR_I2C2LPEN = (1 << 22),

#if defined(STM32_I2C3)
  RCC_APB1LPENR_I2C3LPEN = (1 << 23),
#endif

#if defined(STM32_FMPI2C1)
  RCC_APB1LPENR_FMPI2C1LPEN = (1 << 24),
#endif

#if defined(STM32_CAN1)
  RCC_APB1LPENR_CAN1LPEN = (1 << 25),
#endif

#if defined(STM32_CAN2)
  RCC_APB1LPENR_CAN2LPEN = (1 << 26),
#endif

#if defined(STM32_CEC)
  RCC_APB1LPENR_CECLPEN = (1 << 27),
#elif defined(STM32_CAN3)
  RCC_APB1LPENR_CAN3LPEN = (1 << 27),
#endif

  RCC_APB1LPENR_PWRLPEN = (1 << 28),

#if defined(STM32_DAC)
  RCC_APB1LPENR_DACLPEN = (1 << 29),
#endif

#if defined(STM32_UART7)
  RCC_APB1LPENR_UART7LPEN = (1 << 30),
#endif

#if defined(STM32_UART8)
  RCC_APB1LPENR_UART8LPEN = (1u << 31)
#endif
};

enum rcc_apb2lpenr : u32
{
  RCC_APB2LPENR_TIM1LPEN = (1 << 0),

#if defined(STM32_TIM8)
  RCC_APB2LPENR_TIM8LPEN = (1 << 1),
#endif

  RCC_APB2LPENR_USART1LPEN = (1 << 4),
  RCC_APB2LPENR_USART6LPEN = (1 << 5),

#if defined(STM32_UART9)
  RCC_APB2LPENR_UART9LPEN = (1 << 6),
#endif

#if defined(STM32_UART10)
  RCC_APB2LPENR_UART10LPEN = (1 << 7),
#endif

  RCC_APB2LPENR_ADC1LPEN = (1 << 8),

#if defined(STM32_ADC2)
  RCC_APB2LPENR_ADC2LPEN = (1 << 9),
#endif

#if defined(STM32_ADC3)
  RCC_APB2LPENR_ADC3LPEN = (1 << 10),
#endif

#if defined(STM32_SDIO)
  RCC_APB2LPENR_SDIOLPEN = (1 << 11),
#endif

  RCC_APB2LPENR_SPI1LPEN = (1 << 12),

#if defined(STM32_SPI4)
  RCC_APB2LPENR_SPI4LPEN = (1 << 13),
#endif

  RCC_APB2LPENR_SYSCFGLPEN = (1 << 14),

#if defined(STM32_EXTIT) 
  RCC_APB2LPENR_EXTITLPEN = (1 << 15),
#endif

  RCC_APB2LPENR_TIM9LPEN = (1 << 16),

#if defined(STM32_TIM10)
  RCC_APB2LPENR_TIM10LPEN = (1 << 17),
#endif

#if defined(STM32_TIM11)
  RCC_APB2LPENR_TIM11LPEN = (1 << 18),
#endif

#if defined(STM32_SPI5)
  RCC_APB2LPENR_SPI5LPEN = (1 << 20),
#endif

#if defined(STM32_SPI6)
  RCC_APB2LPENR_SPI6LPEN = (1 << 21),
#endif

#if defined(STM32_SAI1)
  RCC_APB2LPENR_SAI1LPEN = (1 << 22),
#endif

#if defined(STM32_SAI2)
  RCC_APB2LPENR_SAI2LPEN = (1 << 23),
#endif

#if defined(STM32_DFSDM1)
  RCC_APB2LPENR_DFSDM1LPEN = (1 << 24),
#endif

#if defined(STM32_DFSDM2)
  RCC_APB2LPENR_DFSDM2LPEN = (1 << 25),
#endif

#if defined(STM32_LTDC)
  RCC_APB2LPENR_LTDCLPEN = (1 << 26),
#endif

#if defined(STM32_DSI_HOST)
  RCC_APB2LPENR_DSILPEN = (1 << 27)
#endif
};

enum rcc_bdcr : u32
{
  RCC_BDCR_LSEON = (1 << 0),
  RCC_BDCR_LSERDY = (1 << 1),
  RCC_BDCR_LSEBYP = (1 << 2),

#if defined(STM32_RCC_LSEMODE)
  RCC_BDCR_LSEMOD = (1 << 3),
#endif

  RCC_BDCR_RTCEN = (1 << 15),
  RCC_BDCR_BDRST = (1 << 16)
};

#define RCC_BDCR_RTCSEL_SHIFT (8)
#define RCC_BDCR_RTCSEL_MASK (0x3)

enum rcc_bdcr_rtcsel : u32
{
  RCC_BDCR_RTCSEL_NOCLOCK = 0b00,
  RCC_BDCR_RTCSEL_LSE = 0b01,
  RCC_BDCR_RTCSEL_LSI = 0b10,
  RCC_BDCR_RTCSEL_HSE = 0b11,
};

enum rcc_csr : u32
{
  RCC_CSR_LSION = (1 << 0),
  RCC_CSR_LSIRDY = (1 << 1),
  RCC_CSR_RMVF = (1 << 24),
  RCC_CSR_BORRSTF = (1 << 25),
  RCC_CSR_PINRSTF = (1 << 26),
  RCC_CSR_PORRSTF = (1 << 27),
  RCC_CSR_SFTRSTF = (1 << 28),
  RCC_CSR_IWDGRSTF = (1 << 29),
  RCC_CSR_WWDGRSTF = (1 << 30),
  RCC_CSR_LPWRRSTF = (1u << 31)
};

enum rcc_sscgr : u32
{
  RCC_SSCGR_SPREADSEL = (1 << 30),
  RCC_SSCGR_SSCGEN = (1u << 31)
};

#define RCC_SSCGR_MODPER_SHIFT (0)
#define RCC_SSCGR_MODPER_MASK (0x1fff)

#define RCC_SSCGR_INCSTEP_SHIFT (13)
#define RCC_SSCGR_INCSTEP_MASK (0x7fff)

#if defined(STM32_RCC_PLLI2S)

// Prevent defining an empty enum.
#if defined(STM32_RCC_PLLI2S_CLOCK_SOURCE)
enum rcc_plli2scfgr : u32
{
  RCC_PLLI2SCFGR_PLLI2SSRC = (1 << 22)
};
#endif

#if defined(STM32_RCC_PLLI2S_FACTORM)
#define RCC_PLLI2SCFGR_PLLI2SM_SHIFT (0)
#define RCC_PLLI2SCFGR_PLLI2SM_MASK (0x3fu)
#define RCC_PLLI2SCFGR_PLLI2SM_MIN_VAL (2)
#define RCC_PLLI2SCFGR_PLLI2SM_MAX_VAL (63)
#endif

#if defined(STM32_RCC_PLLI2S_FACTORN)
#define RCC_PLLI2SCFGR_PLLI2SN_SHIFT (6)
#define RCC_PLLI2SCFGR_PLLI2SN_MASK (0x1ffu)
#define RCC_PLLI2SCFGR_PLLI2SN_MIN_VAL (50)
#define RCC_PLLI2SCFGR_PLLI2SN_MAX_VAL (432)
#endif

#if defined(STM32_RCC_PLLI2S_FACTORP)
#define RCC_PLLI2SCFGR_PLLI2SP_SHIFT (16)
#define RCC_PLLI2SCFGR_PLLI2SP_MASK (0x3)
#define RCC_PLLI2SCFGR_PLLI2SP_MIN_VAL (3)
#define RCC_PLLI2SCFGR_PLLI2SP_MAX_VAL (63)

enum rcc_plli2scfgr_plli2sp : u32
{
  RCC_PLLI2SCFGR_PLLI2SP_DIV2 = 0b00,
  RCC_PLLI2SCFGR_PLLI2SP_DIV4 = 0b01,
  RCC_PLLI2SCFGR_PLLI2SP_DIV6 = 0b10,
  RCC_PLLI2SCFGR_PLLI2SP_DIV8 = 0b11
};
#endif

#if defined(STM32_RCC_PLLI2S_FACTORQ)
#define RCC_PLLI2SCFGR_PLLI2SQ_SHIFT (24)
#define RCC_PLLI2SCFGR_PLLI2SQ_MASK (0xfu)
#define RCC_PLLI2SCFGR_PLLI2SQ_MIN_VAL (2)
#define RCC_PLLI2SCFGR_PLLI2SQ_MAX_VAL (15)
#endif

#if defined(STM32_RCC_PLLI2S_FACTORR)
#define RCC_PLLI2SCFGR_PLLI2SR_SHIFT (28)
#define RCC_PLLI2SCFGR_PLLI2SR_MASK (0x7u)
#define RCC_PLLI2SCFGR_PLLI2SR_MIN_VAL (2)
#define RCC_PLLI2SCFGR_PLLI2SR_MAX_VAL (7)
#endif
#endif

#if defined(STM32_RCC_PLLSAI)
#if defined(STM32_RCC_PLLSAI_FACTORM)
#define RCC_PLLSAICFGR_PLLSAIM_SHIFT (0)
#define RCC_PLLSAICFGR_PLLSAIM_MASK (0x3f)
#define RCC_PLLSAICFGR_PLLSAIM_MIN_VAL (2)
#define RCC_PLLSAICFGR_PLLSAIM_MAX_VAL (63)
#endif

#define RCC_PLLSAICFGR_PLLSAIN_SHIFT (6)
#define RCC_PLLSAICFGR_PLLSAIN_MASK (0x1ffu)
#define RCC_PLLSAICFGR_PLLSAIN_MIN_VAL (50)
#define RCC_PLLSAICFGR_PLLSAIN_MAX_VAL (432)

#if defined(STM32_RCC_PLLSAI_FACTORP)
#define RCC_PLLSAICFGR_PLLSAIP_SHIFT (16)
#define RCC_PLLSAICFGR_PLLSAIP_MASK (0x3)

enum rcc_pllsaicfgr_pllsaip : u32
{
  RCC_PLLSAICFGR_PLLSAIP_DIV2 = 0b00,
  RCC_PLLSAICFGR_PLLSAIP_DIV4 = 0b01,
  RCC_PLLSAICFGR_PLLSAIP_DIV6 = 0b10,
  RCC_PLLSAICFGR_PLLSAIP_DIV8 = 0b11
};
#endif

#define RCC_PLLSAICFGR_PLLSAIQ_SHIFT (24)
#define RCC_PLLSAICFGR_PLLSAIQ_MASK (0xfu)
#define RCC_PLLSAICFGR_PLLSAIQ_MIN_VAL (2)
#define RCC_PLLSAICFGR_PLLSAIQ_MAX_VAL (15)

#if defined(STM32_RCC_PLLSAI_FACTORR)
#define RCC_PLLSAICFGR_PLLSAIR_SHIFT (28)
#define RCC_PLLSAICFGR_PLLSAIR_MASK (0x7u)
#define RCC_PLLSAICFGR_PLLSAIR_MIN_VAL (2)
#define RCC_PLLSAICFGR_PLLSAIR_MAX_VAL (7)
#endif
#endif

enum rcc_dckcfgr : u32
{
#if defined(STM32_DFSDM2)
  RCC_DCKCFGR_CKDFSDM2ASEL = (1 << 14),
#endif

#if defined(STM32_DFSDM1)
  RCC_DCKCFGR_CKDFSDM1ASEL = (1 << 15),
#endif

#if defined(STM32_RCC_TIMPRE)
  RCC_DCKCFGR_TIMPRE = (1 << 24),
#endif

#if defined(STM32_RCC_CLOCK_48MHZ) && defined(STM32_RCC_CK48SEL_DCKCFGR)
  RCC_DCKCFGR_48MSEL = (1 << 27),
#endif

#if defined(STM32_SDIO) && defined(STM32_RCC_SDIOCK_DCKCFGR)
  RCC_DCKCFGR_SDIOSEL = (1 << 28),
#endif

#if defined(STM32_DSI_HOST)
  RCC_DCKCFGR_DSISEL = (1 << 29),
#endif

#if defined(STM32_DFSDM1) || defined(STM32_DFSDM2)
  RCC_DCKCFGR_CKDFSDM1SEL = (1u << 31)
#endif
};

#if defined(STM32_RCC_PLLI2S_DIVQ)
#define RCC_DCKCFGR_PLLI2SDIVQ_SHIFT (0)
#define RCC_DCKCFGR_PLLI2SDIVQ_MASK (0x1f)
#elif defined(STM32_RCC_PLLI2S_DIVR)
#define RCC_DCKCFGR_PLLI2SDIVR_SHIFT (0)
#define RCC_DCKCFGR_PLLI2SDIVR_MASK (0x1f)
#define RCC_DCKCFGR_PLLI2SDIVR_MIN_VAL (1)
#define RCC_DCKCFGR_PLLI2SDIVR_MAX_VAL (0x1f)
#endif

#if defined(STM32_RCC_PLLSAI_DIVQ)
#define RCC_DCKCFGR_PLLSAIDIVQ_SHIFT (8)
#define RCC_DCKCFGR_PLLSAIDIVQ_MASK (0x1f)
#endif

#if defined(STM32_RCC_PLL_DIVR)
#define RCC_DCKCFGR_PLLDIVR_SHIFT (9)
#define RCC_DCKCFGR_PLLDIVR_MASK (0x1f)
#endif

#if defined(STM32_RCC_PLLSAI_DIVR)
#define RCC_DCKCFGR_PLLSAIDIVR_SHIFT (16)
#define RCC_DCKCFGR_PLLSAIDIVR_MASK (0x3)
#endif

#if defined(STM32_RCC_SAI1A)

#define RCC_DCKCFGR_SAI1ASRC_SHIFT (20)
#define RCC_DCKCFGR_SAI1ASRC_MASK (0x3)

enum rcc_dckcfgr_sai1asrc : u32
{
#if defined(STM32_RCC_SAI1ASRC_LAYOUT1)
  RCC_DCKCFGR_SAI1ASRC_PLLI2SR = 0b00,
  RCC_DCKCFGR_SAI1ASRC_I2SCLIN = 0b01,
  RCC_DCKCFGR_SAI1ASRC_PLLR = 0b10,
  RCC_DCKCFGR_SAI1ASRC_HSCK = 0b11
#elif defined(STM32_RCC_SAI1ASRC_LAYOUT2)
  RCC_DCKCFGR_SAI1ASRC_PLLSAIQ = 0b00,
  RCC_DCKCFGR_SAI1ASRC_PLLI2SQ = 0b01,
  RCC_DCKCFGR_SAI1ASRC_ALTIN = 0b10
#endif
};

#elif defined(STM32_RCC_SAI1)

#define RCC_DCKCFGR_SAI1SRC_SHIFT (20)
#define RCC_DCKCFGR_SAI1SRC_MASK (0x3)

enum rcc_dckcfgr_sai1src : u32
{
  RCC_DCKCFGR_SAI1SRC_PLLSAIQ = 0b00,
  RCC_DCKCFGR_SAI1SRC_PLLI2SQ = 0b01,
  RCC_DCKCFGR_SAI1SRC_PLLR = 0b10,
  RCC_DCKCFGR_SAI1SRC_I2SCKIN = 0b11
};
#endif

#if defined(STM32_RCC_SAI1B)
#define RCC_DCKCFGR_SAI1BSRC_SHIFT (22)
#define RCC_DCKCFGR_SAI1BSRC_MASK (0x3)

enum rcc_dckcfgr_sai1bsrc : u32
{
#if defined(STM32_RCC_SAI1BSRC_LAYOUT1)
  RCC_DCKCFGR_SAI1BSRC_PLLI2SR = 0b00,
  RCC_DCKCFGR_SAI1BSRC_I2SCLIN = 0b01,
  RCC_DCKCFGR_SAI1BSRC_PLLR = 0b10,
  RCC_DCKCFGR_SAI1BSRC_HSCK = 0b11
#elif defined(STM32_RCC_SAI1BSRC_LAYOUT2)
  RCC_DCKCFGR_SAI1BSRC_PLLSAIQ = 0b00,
  RCC_DCKCFGR_SAI1BSRC_PLLI2SQ = 0b01,
  RCC_DCKCFGR_SAI1BSRC_ALTIN = 0b10
#endif
};

#elif defined(STM32_RCC_SAI2)

#define RCC_DCKCFGR_SAI2SRC_SHIFT (22)
#define RCC_DCKCFGR_SAI2SRC_MASK (0x3)

enum rcc_dckcfgr_sai2src : u32
{
  RCC_DCKCFGR_SAI2SRC_PLLSAIQ = 0b00,
  RCC_DCKCFGR_SAI2SRC_PLLI2SQ = 0b01,
  RCC_DCKCFGR_SAI2SRC_PLLR = 0b10,
  RCC_DCKCFGR_SAI2SRC_PLLSRC = 0b11
};
#endif


#if defined(STM32_RCC_I2S1) || defined(STM32_RCC_I2S2)
#if defined(STM32_RCC_I2S2)
#define RCC_DCKCFGR_I2S2SRC_SHIFT (27)
#define RCC_DCKCFGR_I2S2SRC_MASK (0x3u)
#endif

#if defined(STM32_RCC_I2S1)
#define RCC_DCKCFGR_I2S1SRC_SHIFT (25)
#define RCC_DCKCFGR_I2S1SRC_MASK (0x3u)
#endif

enum rcc_dckcfgr_i2ssrc : u32
{
#if defined(STM32_RCC_I2SSRC_LAYOUT1)
  RCC_DCKCFGR_I2SSRC_PLLR = 0b00,
  RCC_DCKCFGR_I2SSRC_ALTIN = 0b01,
  RCC_DCKCFGR_I2SSRC_PLLSRC = 0b11
#elif defined(STM32_RCC_I2SSRC_LAYOUT2)
  RCC_DCKCFGR_I2SSRC_PLLI2SR = 0b00,
  RCC_DCKCFGR_I2SSRC_I2SCKIN = 0b01,
  RCC_DCKCFGR_I2SSRC_PLLR = 0b10,
  RCC_DCKCFGR_I2SSRC_PLLSRC = 0b11
#endif
};
#endif

#if defined(STM32_RCC_CKGATE)
enum rcc_ckgatenr : u32
{
  RCC_CKGATENR_AHB2APB1CKEN = (1 << 0),
  RCC_CKGATENR_AHB2APB2CKEN = (1 << 1),
  RCC_CKGATENR_CM4DBGCKEN = (1 << 2),
  RCC_CKGATENR_SPARECKEN = (1 << 3),
  RCC_CKGATENR_SRAMCKEN = (1 << 4),
  RCC_CKGATENR_FLITFCKEN = (1 << 5),
  RCC_CKGATENR_RCCCKEN = (1 << 6),

#if defined(STM32_RCC_EVTCLCK)
  RCC_CKGATENR_EVTCLCKEN = (1 << 7)
#endif
};
#endif

#if defined(STM32_RCC_DCKCFGR2) 
#if defined(STM32_RCC_DCKCFGR2_BITS)
enum rcc_dckcfgr2 : u32
{
#if defined(STM32_RCC_CECCKSEL)
  RCC_DCKCFGR2_CECSEL = (1 << 26),
#endif

#if defined(STM32_RCC_CK48SEL_DCKCFGR2)
  RCC_DCKCFGR2_CK48MSEL = (1 << 27),
#endif

#if defined(STM32_RCC_SDIOCK_DCKCFGR2)
  RCC_DCKCFGR2_SDIOSEL = (1 << 28),
#endif

#if defined(STM32_SPDIFRX)
  RCC_DCKCFGR2_SPDIFRXSEL = (1 << 29)
#endif
};
#endif

#if defined(STM32_FMPI2C1)
#define RCC_DCKCFGR2_FMPI2C1SEL_SHIFT (22)
#define RCC_DCKCFGR2_FMPI2C1SEL_MASK (0x3)

enum rcc_dckcfgr2_i2c4sel : u32
{
  RCC_DCKCFGR2_FMPI2C1SEL_APB_CLOCK = 0b00,
  RCC_DCKCFGR2_FMPI2C1SEL_SYSCLK = 0b01,
  RCC_DCKCFGR2_FMPI2C1SEL_HSI = 0b10
};

#elif defined(STM32_FMPI2C1)
#define RCC_DCKCFGR2_FMPI2C1SEL_SHIFT (22) 
#define RCC_DCKCFGR2_FMPI2C1SEL_MASK (0x3)

enum rcc_dckcfgr_fmpi2c1sel : u32
{
  RCC_DCKCFGR_FMPI2C1SEL_APB = 0b00,
  RCC_DCKCFGR_FMPI2C1SEL_SYSCLK = 0b01,
  RCC_DCKCFGR_FMPI2C1SEL_HSI = 0b10
};
#endif

#define RCC_DCKCFGR2_LPTIMER1SEL_SHIFT (30)
#define RCC_DCKCFGR2_LPTIMER1SEL_MASK (0x3u)

enum rcc_dckcfgr2_lptimer1sel : u32
{
  RCC_DCKCFGR2_LPTIMER1SEL_APB_CLOCK = 0b00,
  RCC_DCKCFGR2_LPTIMER1SEL_HSI_CLOCK = 0b01,
  RCC_DCKCFGR2_LPTIMER1SEL_LSI_CLOCK = 0b10,
  RCC_DCKCFGR2_LPTIMER1SEL_LSE_CLOCK = 0b11
};
#endif

// API
enum rcc_osc
{
  RCC_OSC_HSI,
  RCC_OSC_HSE,
  RCC_OSC_PLL,

#if defined(STM32_RCC_OSC_PLLI2S)
  RCC_OSC_PLLI2S,
#endif

#if defined(STM32_RCC_OSC_PLLSAI)
  RCC_OSC_PLLSAI,
#endif

  RCC_OSC_LSI,
  RCC_OSC_LSE
};

enum rcc_main_pll_factorp
{
  RCC_MAIN_PLL_FACTORP_DIV2,
  RCC_MAIN_PLL_FACTORP_DIV4,
  RCC_MAIN_PLL_FACTORP_DIV6,
  RCC_MAIN_PLL_FACTORP_DIV8
};

// enum rcc_pll_factor
// {
//   RCC_PLL_FACTORP = 0,
//
// #if defined(STM32_RCC_PLLR)
//   RCC_PLL_FACTORR = 1,
// #endif
//
//   RCC_PLL_FACTORQ = 2,
//   RCC_PLL_FACTORN = 3
// };

enum rcc_main_pll_source
{
  RCC_MAIN_PLL_SOURCE_HSI,
  RCC_MAIN_PLL_SOURCE_HSE
};

enum rcc_system_clock_source
{
  RCC_SYSTEM_CLOCK_SOURCE_HSI,
  RCC_SYSTEM_CLOCK_SOURCE_HSE,

#if defined(STM32_RCC_PLLR_SW)
  RCC_SYSTEM_CLOCK_SOURCE_PLLP,
  RCC_SYSTEM_CLOCK_SOURCE_PLLR
#else
  RCC_SYSTEM_CLOCK_SOURCE_PLL
#endif
};

enum rcc_ahb_prescaler
{
  RCC_AHB_PRESCALER_NODIV,
  RCC_AHB_PRESCALER_DIV2,
  RCC_AHB_PRESCALER_DIV4,
  RCC_AHB_PRESCALER_DIV8,
  RCC_AHB_PRESCALER_DIV16,
  RCC_AHB_PRESCALER_DIV64,
  RCC_AHB_PRESCALER_DIV128,
  RCC_AHB_PRESCALER_DIV256,
  RCC_AHB_PRESCALER_DIV512
};

enum rcc_mco
{
  RCC_MCO1,
  RCC_MCO2
};

enum rcc_mco1
{
  RCC_MCO1_HSI,
  RCC_MCO1_LSE,
  RCC_MCO1_HSE,
  RCC_MCO1_PLL
};

enum rcc_mco2
{
  RCC_MCO2_SYSCLK,
  RCC_MCO2_PLLI2S,
  RCC_MCO2_HSE,
  RCC_MCO2_PLL
};

enum rcc_apb1_prescaler
{
  RCC_APB1_PRESCALER_NODIV,
  RCC_APB1_PRESCALER_DIV2,
  RCC_APB1_PRESCALER_DIV4,
  RCC_APB1_PRESCALER_DIV8,
  RCC_APB1_PRESCALER_DIV16
};

enum rcc_apb2_prescaler
{
  RCC_APB2_PRESCALER_NODIV,
  RCC_APB2_PRESCALER_DIV2,
  RCC_APB2_PRESCALER_DIV4,
  RCC_APB2_PRESCALER_DIV8,
  RCC_APB2_PRESCALER_DIV16
};

#if defined(STM32_RCC_I2S)
enum rcc_i2s_clock_source
{
  RCC_I2S_CLOCK_SOURCE_PLLI2S,
  RCC_I2S_CLOCK_SOURCE_ALTIN
};
#endif

enum rcc_mco_prescaler
{
  RCC_MCO_PRESCALER_NODIV,
  RCC_MCO_PRESCALER_DIV2,
  RCC_MCO_PRESCALER_DIV3,
  RCC_MCO_PRESCALER_DIV4,
  RCC_MCO_PRESCALER_DIV5
};

enum rcc_flag
{
  RCC_FLAG_LSI_READY,
  RCC_FLAG_LSE_READY,
  RCC_FLAG_HSI_READY,
  RCC_FLAG_HSE_READY,
  RCC_FLAG_PLL_READY,

#if defined(STM32_RCC_PLLI2S)
  RCC_FLAG_PLLI2S_READY,
#endif

#if defined(STM32_RCC_PLLSAI)
  RCC_FLAG_PLLSAI_READY,
#endif

  RCC_FLAG_CSS
};

enum rcc_interrupt
{
  RCC_INTERRUPT_LSI_READY,
  RCC_INTERRUPT_LSE_READY,
  RCC_INTERRUPT_HSI_READY,
  RCC_INTERRUPT_HSE_READY,
  RCC_INTERRUPT_PLL_READY,

#if defined(STM32_RCC_PLLI2S)
  RCC_INTERRUPT_PLLI2S_READY,
#endif

#if defined(STM32_RCC_PLLSAI)
  RCC_INTERRUPT_PLLSAI_READY
#endif
};

enum rcc_periph
{
  // Register: AHB1RSTR
#if defined(STM32_GPIOA)
  RCC_PERIPH_GPIOA,
#endif

#if defined(STM32_GPIOB)
  RCC_PERIPH_GPIOB,
#endif

#if defined(STM32_GPIOC)
  RCC_PERIPH_GPIOC,
#endif

#if defined(STM32_GPIOD)
  RCC_PERIPH_GPIOD,
#endif

#if defined(STM32_GPIOE)
  RCC_PERIPH_GPIOE,
#endif

#if defined(STM32_GPIOF)
  RCC_PERIPH_GPIOF,
#endif

#if defined(STM32_GPIOG)
  RCC_PERIPH_GPIOG,
#endif

#if defined(STM32_GPIOH)
  RCC_PERIPH_GPIOH,
#endif

#if defined(STM32_GPIOI)
  RCC_PERIPH_GPIOI,
#endif

#if defined(STM32_GPIOJ)
  RCC_PERIPH_GPIOJ,
#endif

#if defined(STM32_GPIOK)
  RCC_PERIPH_GPIOK,
#endif

  RCC_PERIPH_CRC,

#if defined(STM32_BKPSRAM)
  RCC_PERIPH_BKPSRAM,
#endif

#if defined(STM32_CCMRAM)
  RCC_PERIPH_CCMDATARAM,
#endif

  RCC_PERIPH_DMA1,
  RCC_PERIPH_DMA2,

#if defined(STM32_DMA2D)
  RCC_PERIPH_DMA2D,
#endif

#if defined(STM32_ETHERNET_MAC)
  RCC_PERIPH_ETHMAC,
  RCC_PERIPH_ETHMACTX,
  RCC_PERIPH_ETHMACRX,
  RCC_PERIPH_ETHMACPTP,
#endif

#if defined(STM32_USB_OTG_HS)
  RCC_PERIPH_OTG_HS,
#endif

#if defined(STM32_USB_OTG_HSULPI)
  RCC_PERIPH_OTG_HS_ULPI,
#endif

#if defined(STM32_RNG)
  RCC_PERIPH_RNG,
#endif

  // Register: AHB2RSTR
#if defined(STM32_DCMI)
  RCC_PERIPH_DCMI,
#endif

#if defined(STM32_CRYP)
  RCC_PERIPH_CRYPTO,
#endif

#if defined(STM32_HASH)
  RCC_PERIPH_HASH,
#endif

#if defined(STM32_USB_OTG_FS)
  RCC_PERIPH_OTG_FS,
#endif

  // Register: AHB3RSTR
#if defined(STM32_FMC)
  RCC_PERIPH_FMC,
#endif

#if defined(STM32_FSMC)
  RCC_PERIPH_FSMC,
#endif

#if defined(STM32_QUADSPI)
  RCC_PERIPH_QUADSPI,
#endif

  // Register: APB1RSTR

#if defined(STM32_TIM2)
  RCC_PERIPH_TIM2,
#endif

#if defined(STM32_TIM3)
  RCC_PERIPH_TIM3,
#endif

#if defined(STM32_TIM4)
  RCC_PERIPH_TIM4,
#endif

  RCC_PERIPH_TIM5,
  RCC_PERIPH_TIM6,

#if defined(STM32_TIM7)
  RCC_PERIPH_TIM7,
#endif

#if defined(STM32_TIM12)
  RCC_PERIPH_TIM12,
#endif

#if defined(STM32_TIM13)
  RCC_PERIPH_TIM13,
#endif

#if defined(STM32_TIM14)
  RCC_PERIPH_TIM14,
#endif

#if defined(STM32_LPTIM1)
  RCC_PERIPH_LPTIMER1,
#endif

#if defined(STM32_RCC_RTC_APB)
  RCC_PERIPH_RTCAPB,
#endif

  RCC_PERIPH_WWDG,
  RCC_PERIPH_SPI2,
  RCC_PERIPH_SPI3,

#if defined(STM32_SPDIFRX)
  RCC_PERIPH_SPDIFRX,
#endif

  RCC_PERIPH_USART2,

#if defined(STM32_USART3)
  RCC_PERIPH_USART3,
#endif

#if defined(STM32_UART4)
  RCC_PERIPH_UART4,
#endif

#if defined(STM32_UART5)
  RCC_PERIPH_UART5,
#endif

  RCC_PERIPH_I2C1,
  RCC_PERIPH_I2C2,
  
#if defined(STM32_I2C3)
  RCC_PERIPH_I2C3,
#endif

#if defined(STM32_FMPI2C1)
  RCC_PERIPH_I2CFMP1,
#endif

#if defined(STM32_CAN1)
  RCC_PERIPH_CAN1,
#endif

#if defined(STM32_CAN2)
  RCC_PERIPH_CAN2,
#endif

#if defined(STM32_CEC)
  RCC_PERIPH_CEC,
#elif defined(STM32_CAN3)
  RCC_PERIPH_CAN3,
#endif

  RCC_PERIPH_PWR,

#if defined(STM32_DAC)
  RCC_PERIPH_DAC,
#endif

#if defined(STM32_UART7)
  RCC_PERIPH_UART7,
#endif

#if defined(STM32_UART8)
  RCC_PERIPH_UART8,
#endif

  // Register: APB2RSTR
  RCC_PERIPH_TIM1,

#if defined(STM32_TIM8)
  RCC_PERIPH_TIM8,
#endif

  RCC_PERIPH_USART1,
  RCC_PERIPH_USART6,

#if defined(STM32_UART9)
  RCC_PERIPH_UART9,
#endif

#if defined(STM32_UART10)
  RCC_PERIPH_UART10,
#endif

  RCC_PERIPH_ADC1,
  
#if defined(STM32_ADC2)
  RCC_PERIPH_ADC2,
#endif

#if defined(STM32_ADC2)
  RCC_PERIPH_ADC3,
#endif

#if defined(STM32_SDIO)
  RCC_PERIPH_SDIO,
#endif

  RCC_PERIPH_SPI1,

#if defined(STM32_SPI4)
  RCC_PERIPH_SPI4,
#endif

  RCC_PERIPH_SYSCFG,

#if defined(STM32_EXTIT)
  RCC_PERIPH_EXTIT,
#endif

  RCC_PERIPH_TIM9,

#if defined(STM32_TIM10)
  RCC_PERIPH_TIM10,
#endif

  RCC_PERIPH_TIM11,

#if defined(STM32_SPI5)
  RCC_PERIPH_SPI5,
#endif

#if defined(STM32_SPI6)
  RCC_PERIPH_SPI6,
#endif

#if defined(STM32_SAI1)
  RCC_PERIPH_SAI1,
#endif

#if defined(STM32_SAI2)
  RCC_PERIPH_SAI2,
#endif

#if defined(STM32_DFSDM1)
  RCC_PERIPH_DFSDM1,
#endif

#if defined(STM32_DFSDM2)
  RCC_PERIPH_DFSDM2,
#endif

#if defined(STM32_LTDC)
  RCC_PERIPH_LTDC,
#endif

#if defined(STM32_DSI)
  RCC_PERIPH_DSI,
#endif

  // Register: AHB1LPENR
  RCC_PERIPH_FLIT,
  RCC_PERIPH_SRAM1,

#if defined(STM32_SRAM2)
  RCC_PERIPH_SRAM2,
#endif

#if defined(STM32_SRAM3)
  RCC_PERIPH_SRAM3,
#endif

  RCC_PERIPH_RTC
};

enum rcc_rtc_clock_source
{
  RCC_RTC_CLOCK_SOURCE_NOCLOCK,
  RCC_RTC_CLOCK_SOURCE_LSE,
  RCC_RTC_CLOCK_SOURCE_LSI,
  RCC_RTC_CLOCK_SOURCE_HSE
};

#if defined(STM32_RCC_LSEMODE)
enum rcc_lse_mode
{
  RCC_LSE_MODE_LOW_POWER,
  RCC_LSE_MODE_HIGH_DRIVE
};
#endif

enum rcc_reset_flag
{
  RCC_RESET_FLAG_BOR,
  RCC_RESET_FLAG_PIN,
  RCC_RESET_FLAG_POR_PDR,
  RCC_RESET_FLAG_SOFTWARE,
  RCC_RESET_FLAG_INDEPENDENT,
  RCC_RESET_FLAG_WINDOW_WATCHDOG,
  RCC_RESET_FLAG_LOW_POWER
};

enum rcc_spread
{
  RCC_SPREAD_CENTER,
  RCC_SPREAD_DOWN
};

#if defined(STM32_RCC_PLLI2S)
enum rcc_plli2s_factorp
{
  RCC_PLLI2S_FACTORP_DIV2,
  RCC_PLLI2S_FACTORP_DIV4,
  RCC_PLLI2S_FACTORP_DIV6,
  RCC_PLLI2S_FACTORP_DIV8
};

#if defined(STM32_RCC_PLLI2S_CLOCK_SOURCE)
enum rcc_plli2s_clock_source
{
  RCC_PLLI2S_CLOCK_SOURCE_PLLSRC,
  RCC_PLLI2S_CLOCK_SOURCE_EXTERNAL_AFI
};
#endif
#endif

#if defined(STM32_RCC_PLLSAI_FACTORP)
enum rcc_pllsai_factorp
{
  RCC_PLLSAI_FACTORP_DIV2,
  RCC_PLLSAI_FACTORP_DIV4,
  RCC_PLLSAI_FACTORP_DIV6,
  RCC_PLLSAI_FACTORP_DIV8
};
#endif

#if defined(STM32_DFSDM1) || defined(STM32_DFSDM2)
enum rcc_dfsdm_audio_clock_source
{
  RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB1,
  RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB2
};
#endif

#if defined(STM32_RCC_SAI1)
enum rcc_sai1_clock_source
{
  RCC_SAI1_CLOCK_SOURCE_PLLSAIQ,
  RCC_SAI1_CLOCK_SOURCE_PLLI2SQ,
  RCC_SAI1_CLOCK_SOURCE_PLLR,
  RCC_SAI1_CLOCK_SOURCE_ALTIN
};
#elif defined(STM32_RCC_SAI1A)
enum rcc_sai1a_clock_source
{
#if defined(STM32_RCC_SAI1ASRC_LAYOUT1)
  RCC_SAI1A_CLOCK_SOURCE_PLLI2SR,
  RCC_SAI1A_CLOCK_SOURCE_I2SCLIN,
  RCC_SAI1A_CLOCK_SOURCE_PLLR,
  RCC_SAI1A_CLOCK_SOURCE_HSCK
#elif defined(STM32_RCC_SAI1ASRC_LAYOUT2)
  RCC_SAI1A_CLOCK_SOURCE_PLLSAIQ,
  RCC_SAI1A_CLOCK_SOURCE_PLLI2SQ,
  RCC_SAI1A_CLOCK_SOURCE_ALTIN
#elif defined(STM32_RCC_SAI1ASRC_LAYOUT2)
  RCC_SAI1A_CLOCK_SOURCE_PLLSAIQ,
  RCC_SAI1A_CLOCK_SOURCE_PLLI2SQ,
  RCC_SAI1A_CLOCK_SOURCE_PLLR,
  RCC_SAI1A_CLOCK_SOURCE_I2SCKIN
#endif
};
#endif

#if defined(STM32_SAI2)
enum rcc_sai2_clock_source
{
  RCC_SAI2_CLOCK_SOURCE_PLLSAIQ,
  RCC_SAI2_CLOCK_SOURCE_PLLI2SQ,
  RCC_SAI2_CLOCK_SOURCE_PLLR,
  RCC_SAI2_CLOCK_SOURCE_PLLSRC
};
#elif defined(STM32_RCC_SAI1B)
enum rcc_sai1b_clock_source
{
#if defined(STM32_RCC_SAI1BSRC_LAYOUT1)
  RCC_SAI2_CLOCK_SOURCE_PLLI2SR,
  RCC_SAI2_CLOCK_SOURCE_I2SCLIN,
  RCC_SAI2_CLOCK_SOURCE_PLLR,
  RCC_SAI2_CLOCK_SOURCE_HSCK
#elif defined(STM32_RCC_SAI1BSRC_LAYOUT2)
  RCC_SAI1B_CLOCK_SOURCE_PLLSAIQ,
  RCC_SAI1B_CLOCK_SOURCE_PLLI2SQ,
  RCC_SAI1B_CLOCK_SOURCE_ALTIN
#endif
};
#endif

enum rcc_timers_prescaler
{
  RCC_TIMERS_PRESCALER_x2,
  RCC_TIMERS_PRESCALER_x4
};

#if defined(STM32_RCC_CLOCK_48MHZ)
enum rcc_48Mhz_clock_source
{
#if defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR_LAYOUT1)
  RCC_48MHZ_CLOCK_SOURCE_PLL,
  RCC_48MHZ_CLOCK_SOURCE_PLLSAI
#elif defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT1)
  RCC_48MHZ_CLOCK_SOURCE_PLLQ,
  RCC_48MHZ_CLOCK_SOURCE_PLLI2SQ
#elif defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT2)
  RCC_48MHZ_CLOCK_SOURCE_PLLSAIP,
  RCC_48MHZ_CLOCK_SOURCE_PLLQ
#endif
};
#endif

#if defined(STM32_SDIO)
enum rcc_sdio_clock_source
{
  RCC_SDIO_CLOCK_SOURCE_48MHZ,
  RCC_SDIO_CLOCK_SOURCE_SYSCLK
};
#endif

#if defined(STM32_DSI_HOST)
enum rcc_dsi_clock_source
{
  RCC_DSI_CLOCK_SOURCE_DSI_PHY,
  RCC_DSI_CLOCK_SOURCE_PLLR
};
#endif

#if defined(STM32_RCC_I2S1) || defined(STM32_RCC_I2S2)
enum rcc_i2s_clock_source
{
#if defined(STM32_RCC_I2SSRC_LAYOUT1)
  RCC_I2S_CLOCK_SOURCE_PLLR,
  RCC_I2S_CLOCK_SOURCE_ALTIN,
  RCC_I2S_CLOCK_SOURCE_PLLSRC
#elif defined(STM32_RCC_I2SSRC_LAYOUT2)
  RCC_I2S_CLOCK_SOURCE_PLLI2SR,
  RCC_I2S_CLOCK_SOURCE_I2CCKIN,
  RCC_I2S_CLOCK_SOURCE_PLLR,
  RCC_I2S_CLOCK_SOURCE_PLLSRC
#endif
};
#endif

#if defined(STM32_DFSDM_KERNEL_CKSRC)
enum rcc_dfsdm_kernel_clock_source
{
  RCC_DFSDM_KERNEL_CLOCK_SOURCE_APB2,
  RCC_DFSDM_KERNEL_CLOCK_SOURCE_SYSCLOCK
};
#endif

#if defined(STM32_RCC_CKGATE)
enum rcc_gate_clock
{
  RCC_GATE_CLOCK_AHB_to_APB1,
  RCC_GATE_CLOCK_AHB_to_APB2,
  RCC_GATE_CLOCK_CM4,
  RCC_GATE_CLOCK_SPARE,
  RCC_GATE_CLOCK_SRAM,
  RCC_GATE_CLOCK_FLASH,
  RCC_GATE_CLOCK_RCC,

#if defined(STM32_RCC_CKGATE_EVT)
  RCC_GATE_CLOCK_EVENT
#endif
};
#endif

#if defined(STM32_FMPI2C1)
enum rcc_i2cfmp_clock_source
{
  RCC_I2CFMP_CLOCK_SOURCE_APB1,
  RCC_I2CFMP_CLOCK_SOURCE_SYSCLK,
  RCC_I2CFMP_CLOCK_SOURCE_HSI
};
#endif

#if defined(STM32_CEC)
enum rcc_cec_clock_source
{
  RCC_CEC_CLOCK_SOURCE_LSE,
  RCC_CEC_CLOCK_SOURCE_HSI
};
#endif

#if defined(STM32_SPDIFRX)
enum rcc_spdifrx_clock_source
{
  RCC_SPDIFRX_CLOCK_SOURCE_PLLR,
  RCC_SPDIFRX_CLOCK_SOURCE_PLLI2SP
};
#endif

#if defined(STM32_LPTIM1)
enum rcc_lptimer1_clock_source
{
  RCC_LPTIMER1_CLOCK_SOURCE_APB,
  RCC_LPTIMER1_CLOCK_SOURCE_HSI,
  RCC_LPTIMER1_CLOCK_SOURCE_LSI,
  RCC_LPTIMER1_CLOCK_SOURCE_LSE
};
#endif

extern volatile struct rcc_registers_map* RCC;

void
rcc_osc_enable(
  enum rcc_osc osc
);

void
rcc_osc_disable(
  enum rcc_osc osc
);

u32
rcc_is_osc_ready(
  enum rcc_osc osc
);

void
rcc_set_hsi_trim(
  u32 value
);

u32
rcc_get_hsi_cal(void);

void
rcc_hse_bypass_enable(void);

void
rcc_hse_bypass_disable(void);

void
rcc_css_enable(void);

void
rcc_css_disable(void);

void
rcc_set_main_pll_factorM(
  u32 factor
);

void
rcc_set_main_pll_factorN(
  u32 factor
);

void
rcc_set_main_pll_factorP(
  enum rcc_main_pll_factorp factor
);

void
rcc_set_main_pll_factorQ(
  u32 factor
);

#if defined(STM32_RCC_PLLR)
void
rcc_set_main_pll_factorR(
  u32 factor
);
#endif

// void
// rcc_set_main_pll_factor_value(
//   enum rcc_pll_factor factor,
//   u32 value
// );

void
rcc_set_main_pll_source(
  enum rcc_main_pll_source source
);

void
rcc_set_system_clock_source(
  enum rcc_system_clock_source source
);

u32
rcc_get_system_clock_source(void);

void
rcc_system_clock_source_ready_wait(
  enum rcc_system_clock_source source
);

void
rcc_set_ahb_prescaler(
  enum rcc_ahb_prescaler prescaler
);

#if defined(STM32_RCC_MCOEN)
void
rcc_mco_enable(
  enum rcc_mco mco
);

void
rcc_mco_disable(
  enum rcc_mco mco
);
#endif

void
rcc_set_apb1_prescaler(
  enum rcc_apb1_prescaler prescaler
);

void
rcc_set_apb2_prescaler(
  enum rcc_apb2_prescaler prescaler
);

void
rcc_set_rtc_prescaler(
  u32 prescaler
);

void
rcc_set_mco1(
  enum rcc_mco1 output
);

#if defined(STM32_RCC_I2S)
void
rcc_set_i2s_clock_source(
  enum rcc_i2s_clock_source source
);
#endif

void
rcc_set_mco1_prescaler(
  enum rcc_mco_prescaler prescaler
);

void
rcc_set_mco2_prescaler(
  enum rcc_mco_prescaler prescaler
);

void
rcc_set_mco2(
  enum rcc_mco2 output
);

u32
rcc_is_flag_set(
  enum rcc_flag flag
);

void
rcc_flag_clear(
  enum rcc_flag flag
);

void
rcc_interrupt_enable(
  enum rcc_interrupt interrupt
);

void
rcc_interrupt_disable(
  enum rcc_interrupt interrupt
);

void
rcc_periph_reset(
  enum rcc_periph periph
);

void
rcc_periph_clock_enable(
  enum rcc_periph periph
);

void
rcc_periph_clock_disable(
  enum rcc_periph periph
);

void
rcc_periph_clock_low_power_enable(
  enum rcc_periph periph
);

void
rcc_periph_clock_low_power_disable(
  enum rcc_periph periph
);

void
rcc_set_rtc_clock_source(
  enum rcc_rtc_clock_source source
);

void
rcc_backup_domain_reset(void);

void
rcc_lse_bypass_enable(void);

void
rcc_lse_bypass_disable(void);

#if defined(STM32_RCC_LSEMODE)
void
rcc_set_lse_mode(
  enum rcc_lse_mode mode
);
#endif

u32
rcc_is_reset_flag_set(
  enum rcc_reset_flag flag
);

void
rcc_reset_flags_clear(void);

void
rcc_set_modulation_period(
  u32 period
);

void
rcc_set_incrementation_step(
  u32 step
);

void
rcc_set_spread(
  enum rcc_spread spread
);

void
rcc_spread_spectrum_modulation_enable(void);

void
rcc_spread_spectrum_modulation_disable(void);

#if defined(STM32_RCC_PLLI2S)
#if defined(STM32_RCC_PLLI2S_FACTORM)
void
rcc_set_plli2s_factorM(
  u32 factor
);
#endif

void
rcc_set_plli2s_factorN(
  u32 factor
);

#if defined(STM32_RCC_PLLI2S_FACTORP)
void
rcc_set_plli2s_factorP(
  enum rcc_plli2s_factorp factor
);
#endif

#if defined(STM32_RCC_PLLI2S_FACTORQ)
void
rcc_set_plli2s_factorQ(
  u32 factor
);
#endif

void
rcc_set_plli2s_factorR(
  u32 factor
);

#if defined(STM32_RCC_PLLI2S_CLOCK_SOURCE)
void
rcc_set_plli2s_clock_source(
  enum rcc_plli2s_clock_source source
);
#endif
#endif

#if defined(STM32_RCC_PLLSAI)
#if defined(STM32_RCC_PLLSAI_FACTORM)
void
rcc_set_pllsai_factorM(
  u32 factor
);
#endif

void
rcc_set_pllsai_factorN(
  u32 factor
);

#if defined(STM32_RCC_PLLSAI_FACTORP)
void
rcc_set_pllsai_factorP(
  enum rcc_pllsai_factorp factor
);
#endif

void
rcc_set_pllsai_factorQ(
  u32 factor
);

#if defined(STM32_RCC_PLLSAI_FACTORR)
void
rcc_set_pllsai_factorR(
  u32 factor
);
#endif
#endif

#if defined(STM32_RCC_PLLI2S_DIVQ)
void
rcc_set_plli2s_dividerQ(
  u32 divider
);
#elif defined(STM32_RCC_PLLI2S_DIVR)
void
rcc_set_plli2s_dividerR(
  u32 divider
);
#endif

#if defined(STM32_RCC_PLLSAI_DIVQ)
void
rcc_set_pllsai_dividerQ(
  u32 divider
);
#elif defined(STM32_RCC_PLL_DIVR)
void
rcc_set_pll_dividerR(
  u32 divider
);
#endif

#if defined(STM32_DFSDM2)
void
rcc_set_dfsdm2_audio_clock_source(
  enum rcc_dfsdm_audio_clock_source source
);
#endif

#if defined(STM32_DFSDM1)
void
rcc_set_dfsdm1_audio_clock_source(
  enum rcc_dfsdm_audio_clock_source source
);
#endif

#if defined(STM32_RCC_PLLSAI_DIVR)
void
rcc_set_pllsai_dividerR(
  u32 divider
);
#endif

#if defined(STM32_RCC_SAI1)
void
rcc_set_sai1_clock_source(
  enum rcc_sai1_clock_source source
);
#elif defined(STM32_RCC_SAI1A)
void
rcc_set_sai1a_clock_source(
  enum rcc_sai1a_clock_source source
);
#endif

#if defined(STM32_SAI2)
void
rcc_set_sai2_clock_source(
  enum rcc_sai2_clock_source source
);
#elif defined(STM32_RCC_SAI1B)
void
rcc_set_sai1b_clock_source(
  enum rcc_sai1b_clock_source source
);
#endif

void
rcc_set_timers_prescaler(
  enum rcc_timers_prescaler prescaler
);

#if defined(STM32_RCC_CLOCK_48MHZ)
// DCKCFGR or DCKCFGR2
void
rcc_set_48Mhz_clock_source(
  enum rcc_48Mhz_clock_source source
);
#endif

#if defined(STM32_SDIO)
// DCKCFGR or DCLCFGR2
void
rcc_set_sdio_clock_source(
  enum rcc_sdio_clock_source source
);
#endif

#if defined(STM32_DSI_HOST)
void
rcc_set_dsi_clock_source(
  enum rcc_dsi_clock_source source
);
#endif

#if defined(STM32_RCC_I2S1)
void
rcc_set_i2s1_clock_source(
  enum rcc_i2s_clock_source source
);
#endif

#if defined(STM32_RCC_I2S2)
void
rcc_set_i2s2_clock_source(
  enum rcc_i2s_clock_source source
);
#endif

#if defined(STM32_RCC_I2S_SHARED_CKSRC)
void
rcc_set_i2s_apb_clock_source(
  enum rcc_i2s_apb_clock_source source
);
#elif defined(STM32_RCC_I2S_CKSRC)
void
rcc_set_i2s1_clock_source(
  enum rcc_i2s1_clock_source source
);

void
rcc_set_i2s2_clock_source(
  enum rcc_i2s2_clock_source source
);
#endif

#if defined(STM32_DFSDM_KERNEL_CKSRC)
void
rcc_set_dfsdm_kernel_clock_source(
  enum rcc_dfsdm_kernel_clock_source source
);
#endif

#if defined(STM32_RCC_CKGATE)
void
rcc_gate_clock_enable(
  enum rcc_gate_clock clock
);

void
rcc_gate_clock_disable(
  enum rcc_gate_clock clock
);
#endif

#if defined(STM32_FMPI2C1)
void
rcc_set_i2c_fmp1_clock_source(
  enum rcc_i2cfmp_clock_source source
);
#endif

#if defined(STM32_CEC)
void
rcc_set_cec_clock_source(
  enum rcc_cec_clock_source source
);
#endif

#if defined(STM32_SPDIFRX)
void
rcc_set_spdifrx_clock_source(
  enum rcc_spdifrx_clock_source source
);
#endif

#if defined(STM32_LPTIM1)
void
rcc_set_lptimer1_clock_source(
  enum rcc_lptimer1_clock_source source
);
#endif

#endif
