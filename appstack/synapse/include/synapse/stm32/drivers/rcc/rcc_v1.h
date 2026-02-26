/**
 * @file rcc.h
 * @brief Reset and Clock Control (RCC) interface.
 *
 * @details This header file provides definitions and function 
 * prototypes for configuring the system and peripheral clocks, 
 * managing resets, and controlling clock sources on the MCU.
 *
 * @note Proper RCC configuration is essential for stable system 
 * operation. Incorrect settings may cause malfunctions.
 */
#ifndef STM32_DRIVER_RCC_H
#define STM32_DRIVER_RCC_H

#include "synapse/stm32/periph/flash.h"
#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F0x
 *  - STM32F1x
 */

BEGIN_DECLARATIONS

#define RCC_CLOCK_UNKNOWN (0)

/**
 * @brief Reset and Clock Control (RCC) registers map.
 *
 * @details Represents the memory-mapped structure of
 * the RCC registers, which control system clocks,
 * peripheral resets, and clock gating.
 *
 * @note Modifying RCC registers affects system stability 
 * and peripheral operation. Ensure proper configuration to
 * avoid unintended behavior.
 */
struct rcc_registers_map
{
  /**
   * @brief RCC_CR - Clock control register
   *
   * @details
   * Offset: 0x0
   * <br>
   * Reset: 0x0000 xx83
   */
  u32 CR;

  /**
   * @brief RCC_CFGR - Clock configuration register
   *
   * @details
   * Offset: 0x4
   * <br>
   * Reset: 0x0000 0000
   */
  u32 CFGR;

  /**
   * @brief RCC_CIR - Clock interrupt register
   *
   * @details
   * Offset: 0x8
   * <br>
   * Reset: 0x0000 0000
   */
  u32 CIR;

  /**
   * @brief RCC_APB2RSTR - APB2 peripheral reset register
   *
   * @details
   * Offset: 0xc
   * <br>
   * Reset: 0x0000 0000
   */
  u32 APB2RSTR;

  /**
   * @brief RCC_APB1RSTR - APB2 peripheral reset register
   *
   * @details
   * Offset: 0x10
   * <br>
   * Reset: 0x0000 0000
   */
  u32 APB1RSTR;

  /**
   * @brief RCC_AHBENR - AHB peripheral clock enable register
   *
   * @details
   * Offset: 0x14
   * <br>
   * Reset: 0x0000 0014
   */
  u32 AHBENR;

  /**
   * @brief RCC_APB2ENR - APB2 peripheral clock enable register
   *
   * @details
   * Offset: 0x18
   * <br>
   * Reset: 0x0000 0000
   */
  u32 APB2ENR;

  /**
   * @brief RCC_APB1ENR - APB1 peripheral clock enable register
   *
   * @details
   * Offset: 0x1c
   * <br>
   * Reset: 0x0000 0000
   */
  u32 APB1ENR;

  /**
   * @brief RCC_BDCR - Backup domain control register
   *
   * @details
   * Offset: 0x20
   * <br>
   * Reset: 0x0000 0000
   *
   * @note This register can only be reset
   *       by a backup domain reset.
   */
  u32 BDCR;

  /**
   * @brief RCC_CSR - Control/status register
   *
   * @details
   * Offset: 0x24
   * <br>
   * Reset: 0x0c00 0000
   *
   * @note This register can only be cleared
   * via a system reset. Reset flags are
   * reset only by a power reset.
   */
  u32 CSR;

  /**
   * @brief RCC_AHBRSTR - AHB peripheral clock reset register
   *
   * @details
   * Offset: 0x28
   * <br>
   * Reset: 0x0000 0000
   *
   * @note This register is available only
   * in connectivity devices.
   */
  u32 AHBRSTR;

  /* AHB peripheral clock reset register */
  /**
   * @brief RCC_CFGR2 - Clock configuration register2
   *
   * @details
   * Offset: 0x2c
   * <br>
   * Reset: 0x0000 0000
   *
   * @note This register is available only
   * in connectivity devices.
   */
  u32 CFGR2;

#if defined(STM32_RCC_EXTENDED_REGS)
  u32 CFGR3;
  u32 CR2;
#endif
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

/*
 * Register: RCC_CR - Clock control register
 * Address: 0x00
 * Reset: 0x0000 xx83 (x is undefined)
 */
enum rcc_cr : u32
{
  /* Shared */
  RCC_CR_HSION = (1 << 0),
  RCC_CR_HSIRDY = (1 << 1),
  RCC_CR_HSEON = (1 << 16),
  RCC_CR_HSERDY = (1 << 17),
  RCC_CR_HSEBYP = (1 << 18),
  RCC_CR_CSSON = (1 << 19),
  RCC_CR_PLLON = (1 << 24),
  RCC_CR_PLLRDY = (1 << 25),

#if defined(STM32_RCC_OSC_PLL2)
  RCC_CR_PLL2ON = (1 << 26),
  RCC_CR_PLL2RDY = (1 << 27),
#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC_CR_PLL3ON = (1 << 28),
  RCC_CR_PLL3RDY = (1 << 29)
#endif
};

/* Bits[7:3] */
#define RCC_CR_HSITRIM_SHIFT (3)
#define RCC_CR_HSITRIM_MASK (0x1fu)

/* Bits[15:8] */
#define RCC_CR_HSICAL_SHIFT (8)
#define RCC_CR_HSICAL_MASK (0xffu)

/*
 * Register: RCC_CFGR - Clock configuration register
 * Address: 0x04
 * Reset: 0x0000 0000
 */
enum rcc_cfgr : u32
{
#if !defined(STM32_RCC_PLLSRC_2BIT)
  RCC_CFGR_PLLSRC = (1 << 16),
#endif

  RCC_CFGR_PLLXTPRE = (1 << 17),

#if defined(STM32_RCC_OTGFS)
  RCC_CFGR_OTGFSPRE = (1 << 22),
#endif

#if defined(STM32_RCC_PLLNODIV)
  RCC_CFGR_PLLNODIV = (1u << 31)
#endif
};

/* Bits[1:0] */
#define RCC_CFGR_SW_SHIFT (0)
#define RCC_CFGR_SW_MASK (0x3u)

enum rcc_cfgr_sw : u32
{
  RCC_CFGR_SW_HSI = 0b00,
  RCC_CFGR_SW_HSE = 0b01,
  RCC_CFGR_SW_PLL = 0b10,

#if defined(STM32_RCC_OSC_HSI48)
  RCC_CFGR_SW_HSI48 = 0b11
#endif
};

/* Bits[3:2] */
#define RCC_CFGR_SWS_SHIFT (2)
#define RCC_CFGR_SWS_MASK (0x3u)

enum rcc_cfgr_sws : u32
{
  RCC_CFGR_SWS_HSI = 0b00,
  RCC_CFGR_SWS_HSE = 0b01,
  RCC_CFGR_SWS_PLL = 0b10,

#if defined(STM32_RCC_OSC_HSI48)
  RCC_CFGR_SWS_HSI48 = 0b11
#endif
};

/* Bits[7:4] */
#define RCC_CFGR_HPRE_SHIFT (4)
#define RCC_CFGR_HPRE_MASK (0xfu)

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

/* Bits[10:8] */
#define RCC_CFGR_PPRE1_SHIFT (8)
#define RCC_CFGR_PPRE1_MASK (0x7u)

enum rcc_cfgr_ppre1 : u32
{
  RCC_CFGR_PPRE1_NODIV = 0b000,
  RCC_CFGR_PPRE1_DIV2 = 0b100,
  RCC_CFGR_PPRE1_DIV4 = 0b101,
  RCC_CFGR_PPRE1_DIV8 = 0b110,
  RCC_CFGR_PPRE1_DIV16 = 0b111
};

#if defined(STM32_RCC_PPRE2)
/* Bits[13:11] */
#define RCC_CFGR_PPRE2_SHIFT (11)
#define RCC_CFGR_PPRE2_MASK (0x7u)

enum rcc_cfgr_ppre2 : u32
{
  RCC_CFGR_PPRE2_NODIV = 0b000,
  RCC_CFGR_PPRE2_DIV2 = 0b100,
  RCC_CFGR_PPRE2_DIV4 = 0b101,
  RCC_CFGR_PPRE2_DIV8 = 0b110,
  RCC_CFGR_PPRE2_DIV16 = 0b111
};
#endif

#if defined(STM32_RCC_ADCPRE)
/* Bits[15:14] */
#define RCC_CFGR_ADCPRE_SHIFT (14)
#define RCC_CFGR_ADCPRE_MASK (0x3u)

enum rcc_cfgr_adcpre : u32
{
  RCC_CFGR_ADCPRE_DIV2 = 0b00,
  RCC_CFGR_ADCPRE_DIV4 = 0b01,
  RCC_CFGR_ADCPRE_DIV6 = 0b10,
  RCC_CFGR_ADCPRE_DIV8 = 0b11
};
#endif

#if defined(STM32_RCC_PLLSRC_2BIT)
#define RCC_CFGR_PLLSRC_SHIFT (15)
#define RCC_CFGR_PLLSRC_MASK (0x3)

enum rcc_cfgr_pllsrc : u32
{
  RCC_CFGR_PLLSRC_HSI_DIV2 = 0b00,
  RCC_CFGR_PLLSRC_HSI_PREDIV = 0b01,
  RCC_CFGR_PLLSRC_HSE_PREDIV = 0b10
};
#endif

/* Bits[21:18] */
#define RCC_CFGR_PLLMUL_SHIFT (18)
#define RCC_CFGR_PLLMUL_MASK (0xfu)

enum rcc_cfgr_pllmul : u32
{
#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  RCC_CFGR_PLLMUL2 = 0b0000,
  RCC_CFGR_PLLMUL3 = 0b0001,
#endif

  RCC_CFGR_PLLMUL4 = 0b0010,
  RCC_CFGR_PLLMUL5 = 0b0011,
  RCC_CFGR_PLLMUL6 = 0b0100,

#if defined(STM32_RCC_PLLMUL_LAYOUT1)
  RCC_CFGR_PLLMUL6DOT5 = 0b1101,
#endif

  RCC_CFGR_PLLMUL7 = 0b0101,
  RCC_CFGR_PLLMUL8 = 0b0110,
  RCC_CFGR_PLLMUL9 = 0b0111,

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  RCC_CFGR_PLLMUL10 = 0b1000,
  RCC_CFGR_PLLMUL11 = 0b1001,
  RCC_CFGR_PLLMUL12 = 0b1010,
  RCC_CFGR_PLLMUL13 = 0b1011,
  RCC_CFGR_PLLMUL14 = 0b1100,
  RCC_CFGR_PLLMUL15 = 0b1101,
  RCC_CFGR_PLLMUL16 = 0b1110
#endif
};

/* Bits[26:24] */
#if defined(STM32_RCC_CFGR_MCO_4BIT)
#define RCC_CFGR_MCO_SHIFT (24)
#define RCC_CFGR_MCO_MASK (0xfu)
#elif defined(STM32_RCC_CFGR_MCO_3BIT)
#define RCC_CFGR_MCO_SHIFT (24)
#define RCC_CFGR_MCO_MASK (0x7u)
#endif

enum rcc_cfgr_mco : u32
{
  RCC_CFGR_MCO_NOCLOCK = 0b0000,

#if defined(STM32_RCC_OSC_HSI14)
  RCC_CFGR_MCO_HSI14 = 0b0001,
#endif

#if defined(STM32_RCC_EXTENDED_REGS)
  RCC_CFGR_MCO_LSI = 0b0010,
  RCC_CFGR_MCO_LSE = 0b0011,
#endif

  RCC_CFGR_MCO_SYSCLK = 0b0100,
  RCC_CFGR_MCO_HSICLK = 0b0101,
  RCC_CFGR_MCO_HSECLK = 0b0110,
  RCC_CFGR_MCO_PLLCLK_DIV2 = 0b0111,

#if defined(STM32_RCC_OSC_PLL2)
  RCC_CFGR_MCO_PLL2CLK = 0b1000,
#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC_CFGR_MCO_PLL3CLK_DIV2 = 0b1001,
#endif

  RCC_CFGR_MCO_XT1CLK = 0b1010,

#if defined(STM32_RCC_OSC_PLL3)
  RCC_CFGR_MCO_PLL3CLK = 0b1011,
#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC_CFGR_MCO_HSI48 = 0b1000
#endif
};

#if defined(STM32_RCC_MCOPRE)

#define RCC_CFGR_MCOPRE_SHIFT (28)
#define RCC_CFGR_MCOPRE_MASK (0x3)

enum rcc_cfgr_mcopre : u32
{
  RCC_CFGR_MCOPRE_DIV1 = 0b000,
  RCC_CFGR_MCOPRE_DIV2 = 0b001,
  RCC_CFGR_MCOPRE_DIV4 = 0b010,
  RCC_CFGR_MCOPRE_DIV8 = 0b011,
  RCC_CFGR_MCOPRE_DIV16 = 0b100,
  RCC_CFGR_MCOPRE_DIV32 = 0b101,
  RCC_CFGR_MCOPRE_DIV64 = 0b110,
  RCC_CFGR_MCOPRE_DIV128 = 0b111
};
#endif

/*
 * Register: RCC_CIR - Clock interrupt register
 * Address: 0x08
 * Reset: 0x0000 0000
 */
enum rcc_cir : u32
{
  RCC_CIR_LSIRDYF = (1 << 0),
  RCC_CIR_LSERDYF = (1 << 1),
  RCC_CIR_HSIRDYF = (1 << 2),
  RCC_CIR_HSERDYF = (1 << 3),
  RCC_CIR_PLLRDYF = (1 << 4),

#if defined(STM32_RCC_OSC_PLL2)
  RCC_CIR_PLL2RDYF = (1 << 5),
#elif defined(STM32_RCC_OSC_HSI14)
  RCC_CIR_HSI14 = (1 << 5),
#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC_CIR_PLL3RDYF = (1 << 6),
#elif defined(STM32_RCC_OSC_HSI48)
  RCC_CIR_HSI48 = (1 << 6),
#endif

  RCC_CIR_CSSF = (1 << 7),
  RCC_CIR_LSIRDYIE = (1 << 8),
  RCC_CIR_LSERDYIE = (1 << 9),
  RCC_CIR_HSIRDYIE = (1 << 10),
  RCC_CIR_HSERDYIE = (1 << 11),
  RCC_CIR_PLLRDYIE = (1 << 12),

#if defined(STM32_RCC_OSC_PLL2)
  RCC_CIR_PLL2RDYIE = (1 << 13),
#elif defined(STM32_RCC_OSC_HSI14)
  RCC_CIR_HSI14RDYIE = (1 << 13),
#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC_CIR_PLL3RDYIE = (1 << 14),
#elif defined(STM32_RCC_OSC_HSI48)
  RCC_CIR_HSI48RDYIE = (1 << 14),
#endif

  RCC_CIR_LSIRDYC = (1 << 16),
  RCC_CIR_LSERDYC = (1 << 17),
  RCC_CIR_HSIRDYC = (1 << 18),
  RCC_CIR_HSERDYC = (1 << 19),
  RCC_CIR_PLLRDYC = (1 << 20),

#if defined(STM32_RCC_OSC_PLL2)
  RCC_CIR_PLL2RDYC = (1 << 21),
#elif defined(STM32_RCC_OSC_HDI14)
  RCC_CIR_HSI14RDYC = (1 << 21),
#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC_CIR_PLL3RDYC = (1 << 22),
#elif defined(STM32_RCC_OSC_HSI48)
  RCC_CIR_HSI48RDYC = (1 << 22),
#endif

  RCC_CIR_CSSC = (1 << 23)
};

/*
 * Register: RCC_APB2RSTR - APB2 peripheral reset register
 * Address: 0x0c
 * Reset: 0x0000 0000
 */
enum rcc_apb2rstr : u32
{
#if defined(STM32_RCC_SYSCFG)
  RCC_APB2RSTR_SYSCFGRST = (1 << 0),
#elif defined(STM32_RCC_AFIO)
  RCC_APB2RSTR_AFIORST = (1 << 0),
#endif

#if !defined(STM32_GPIO_RST_AHB)

#if defined(STM32_GPIOA)
  RCC_APB2RSTR_IOPARST = (1 << 2),
#endif

#if defined(STM32_GPIOB)
  RCC_APB2RSTR_IOPBRST = (1 << 3),
#endif

#if defined(STM32_GPIOC)
  RCC_APB2RSTR_IOPCRST = (1 << 4),
#endif

#if defined(STM32_GPIOD)
  RCC_APB2RSTR_IOPDRST = (1 << 5),
#endif

#if defined(STM32_GPIOE)
  RCC_APB2RSTR_IOPERST = (1 << 6),
#endif

#if defined(STM32_GPIOF)
  RCC_APB2RSTR_IOPFRST = (1 << 7),
#endif

#if defined(STM32_GPIOG)
  RCC_APB2RSTR_IOPGRST = (1 << 8),
#endif

#else
  RCC_APB2RSTR_USART6RST = (1 << 5),
#endif

#if defined(STM32_USART7)
  RCC_APB2RSTR_USART7 = (1 << 6),
#endif

#if defined(STM32_USART8)
  RCC_APB2RSTR_USART8 = (1 << 7),
#endif

  RCC_APB2RSTR_ADC1RST = (1 << 9),

#if defined(STM32_ADC2)
  RCC_APB2RSTR_ADC2RST = (1 << 10),
#endif

  RCC_APB2RSTR_TIM1RST = (1 << 11),
  RCC_APB2RSTR_SPI1RST = (1 << 12),

#if defined(STM32_TIM8)
  RCC_APB2RSTR_TIM8RST = (1 << 13),
#endif

  RCC_APB2RSTR_USART1RST = (1 << 14),

#if defined(STM32_ADC3)
  RCC_APB2RSTR_ADC3RST = (1 << 15),
#endif

#if defined(STM32_TIM15)
  RCC_APB2RSTR_TIM15RST = (1 << 16),
#endif

#if defined(STM32_TIM16)
  RCC_APB2RSTR_TIM16RST = (1 << 17),
#endif

#if defined(STM32_TIM17)
  RCC_APB2RSTR_TIM17RST = (1 << 18),
#endif

#if defined(STM32_TIM9)
  RCC_APB2RSTR_TIM9RST = (1 << 19),
#endif

#if defined(STM32_TIM10)
  RCC_APB2RSTR_TIM10RST = (1 << 20),
#endif

#if defined(STM32_TIM11)
  RCC_APB2RSTR_TIM11RST = (1 << 21),
#endif

#if defined(STM32_DBGMCU)
  RCC_APB2RSTR_DBGMCURST = (1 << 22)
#endif
};

/*
 * Register: RCC_APB1RSTR - APB1 peripheral reset register
 * Address: 0x10
 * Reset: 0x0000 0000
 */
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

  RCC_APB1RSTR_WWDGRST = (1 << 11),

#if defined(STM32_SPI2)
  RCC_APB1RSTR_SPI2RST = (1 << 14),
#endif

#if defined(STM32_SPI3)
  RCC_APB1RSTR_SPI3RST = (1 << 15),
#endif

#if defined(STM32_USART2)
  RCC_APB1RSTR_USART2RST = (1 << 17),
#endif

#if defined(STM32_USART3)
  RCC_APB1RSTR_USART3RST = (1 << 18),
#endif

#if defined(STM32_UART4)
  RCC_APB1RSTR_UART4RST = (1 << 19),
#endif

#if defined(STM32_UART5)
  RCC_APB1RSTR_UART5RST = (1 << 20),
#endif

#if defined(STM32_I2C1)
  RCC_APB1RSTR_I2C1RST = (1 << 21),
#endif

#if defined(STM32_I2C2)
  RCC_APB1RSTR_I2C2RST = (1 << 22),
#endif

#if defined(STM32_USB)
  RCC_APB1RSTR_USBRST = (1 << 23),
#endif

#if defined(STM32_CAN1)
  RCC_APB1RSTR_CAN1RST = (1 << 25),
#endif

#if defined(STM32_CAN2)
  RCC_APB1RSTR_CAN2RST = (1 << 26),
#endif

#if defined(STM32_BKP)
  RCC_APB1RSTR_BKPRST = (1 << 27),
#endif

#if defined(STM32_CRS)
  RCC_APB1RSTR_CRSRST = (1 << 27),
#endif

  RCC_APB1RSTR_PWRRST = (1 << 28),

#if defined(STM32_DAC)
  RCC_APB1RSTR_DACRST = (1 << 29),
#endif

#if defined(STM32_CEC)
  RCC_APB1RSTR_CECRST = (1 << 30)
#endif
};

/*
 * Register: RCC_AHBENR - AHB peripheral clock enable register
 * Address: 0x14
 * Reset: 0x0000 0014
 */
enum rcc_ahbenr : u32
{
  RCC_AHBENR_DMA1EN = (1 << 0),

#if defined(STM32_DMA2)
  RCC_AHBENR_DMA2EN = (1 << 1),
#endif

  RCC_AHBENR_SRAMEN = (1 << 2),
  RCC_AHBENR_FLITFEN = (1 << 4),
  RCC_AHBENR_CRCEN = (1 << 6),

#if defined(STM32_FSMC)
  RCC_AHBENR_FSMCEN = (1 << 8),
#endif

#if defined(STM32_SDIO)
  RCC_AHBENR_SDIOEN = (1 << 10),
#endif

#if defined(STM32_RCC_OTGFS)
  RCC_AHBENR_OTGFSEN = (1 << 12),
#endif

#if defined(STM32_ETH)
  RCC_AHBENR_ETHMACEN = (1 << 14),
  RCC_AHBENR_ETHMACTXEN = (1 << 15),
  RCC_AHBENR_ETHMACRXEN = (1 << 16),
#endif

#if !defined(STM32_RCC_APB2_GPIO)

#if defined(STM32_GPIOA)
  RCC_AHBENR_IOPAEN = (1 << 17),
#endif

#if defined(STM32_GPIOB)
  RCC_AHBENR_IOPBEN = (1 << 18),
#endif

#if defined(STM32_GPIOC)
  RCC_AHBENR_IOPCEN = (1 << 19),
#endif

#if defined(STM32_GPIOD)
  RCC_AHBENR_IOPDEN = (1 << 20),
#endif

#if defined(STM32_GPIOE)
  RCC_AHBENR_IOPEEN = (1 << 21),
#endif

#if defined(STM32_GPIOF)
  RCC_AHBENR_IOPFEN = (1 << 22),
#endif

#if defined(STM32_GPIOG)
  RCC_AHBENR_IOPGEN = (1 << 23),
#endif
#endif

#if defined(STM32_TSC)
  RCC_AHBENR_TSCEN = (1 << 24)
#endif
};

/*
 * Register: RCC_APB2ENR - APB2 peripheral clock enable register
 * Address: 0x18
 * Reset: 0x0000 0000
 */
enum rcc_apb2enr : u32
{
#if defined(STM32_RCC_SYSCFG)
  RCC_APB22ENR_SYSCFGCOMPEN = (1 << 0),
#else
  RCC_APB2ENR_AFIOEN = (1 << 0),
#endif

#if defined(STM32_RCC_APB2_GPIO)

#if defined(STM32_GPIOA)
  RCC_APB2ENR_IOPAEN = (1 << 2),
#endif

#if defined(STM32_GPIOB)
  RCC_APB2ENR_IOPBEN = (1 << 3),
#endif

#if defined(STM32_GPIOC)
  RCC_APB2ENR_IOPCEN = (1 << 4),
#endif

#if defined(STM32_GPIOD)
  RCC_APB2ENR_IOPDEN = (1 << 5),
#endif

#if defined(STM32_GPIOE)
  RCC_APB2ENR_IOPEEN = (1 << 6),
#endif

#if defined(STM32_GPIOF)
  RCC_APB2ENR_IOPFEN = (1 << 7),
#endif

#if defined(STM32_GPIOG)
  RCC_APB2ENR_IOPGEN = (1 << 8),
#endif
#endif

#if defined(STM32_USART6)
  RCC_APB2ENR_USART6EN = (1 << 5),
#endif

  RCC_APB2ENR_ADC1EN = (1 << 9),

#if defined(STM32_ADC2)
  RCC_APB2ENR_ADC2EN = (1 << 10),
#endif

  RCC_APB2ENR_TIM1EN = (1 << 11),
  RCC_APB2ENR_SPI1EN = (1 << 12),

#if defined(STM32_TIM8)
  RCC_APB2ENR_TIM8EN = (1 << 13),
#endif

  RCC_APB2ENR_USART1EN = (1 << 14),

#if defined(STM32_ADC3)
  RCC_APB2ENR_ADC3EN = (1 << 15),
#endif

#if defined(STM32_TIM15)
  RCC_APB2ENR_TIM15EN = (1 << 16),
#endif

#if defined(STM32_TIM16)
  RCC_APB2ENR_TIM16EN = (1 << 17),
#endif

#if defined(STM32_TIM17)
  RCC_APB2ENR_TIM17EN = (1 << 18),
#endif

#if defined(STM32_TIM9)
  RCC_APB2ENR_TIM9EN = (1 << 19),
#endif

#if defined(STM32_TIM10)
  RCC_APB2ENR_TIM10EN = (1 << 20),
#endif

#if defined(STM32_TIM11)
  RCC_APB2ENR_TIM11EN = (1 << 21),
#endif

#if defined(STM32_DBGMCU)
  RCC_APB2ENR_DBGMCUEN = (1 << 22)
#endif
};

/*
 * Register: RCC_APB1ENR - APB1 peripheral clock enable register
 * Address: 0x1c
 * Reset: 0x0000 0000
 */
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

#if defined(STM32_TIM5)
  RCC_APB1ENR_TIM5EN = (1 << 3),
#endif

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

  RCC_APB1ENR_WWDGEN = (1 << 11),

#if defined(STM32_SPI2)
  RCC_APB1ENR_SPI2EN = (1 << 14),
#endif

#if defined(STM32_SPI3)
  RCC_APB1ENR_SPI3EN = (1 << 15),
#endif

#if defined(STM32_USART2)
  RCC_APB1ENR_USART2EN = (1 << 17),
#endif

#if defined(STM32_USART3)
  RCC_APB1ENR_USART3EN = (1 << 18),
#endif

#if defined(STM32_UART4)
  RCC_APB1ENR_UART4EN = (1 << 19),
#endif

#if defined(STM32_UART5)
  RCC_APB1ENR_UART5EN = (1 << 20),
#endif

#if defined(STM32_I2C1)
  RCC_APB1ENR_I2C1EN = (1 << 21),
#endif

#if defined(STM32_I2C2)
  RCC_APB1ENR_I2C2EN = (1 << 22),
#endif

#if defined(STM32_USB)
  RCC_APB1ENR_USBEN = (1 << 23),
#endif

#if defined(STM32_CAN1)
  RCC_APB1ENR_CAN1EN = (1 << 25),
#endif

#if defined(STM32_CAN2)
  RCC_APB1ENR_CAN2EN = (1 << 26),
#endif

#if defined(STM32_BKP)
  RCC_APB1ENR_BKPEN = (1 << 27),
#endif

  RCC_APB1ENR_PWREN = (1 << 28),

#if defined(STM32_DAC)
  RCC_APB1ENR_DACEN = (1 << 29),
#endif

#if defined(STM32_CEC)
  RCC_APB1ENR_CECEN = (1 << 30)
#endif
};

/*
 * Register: RCC_BDCR - Backup domain control register  
 * Address: 0x20
 * Reset: 0x0000 0000 (Backup domain reset)
 */
enum rcc_bdcr : u32
{
  RCC_BDCR_LSEON = (1 << 0),
  RCC_BDCR_LSERDY = (1 << 1),
  RCC_BDCR_LSEBYP = (1 << 2),
  RCC_BDCR_RTCEN = (1 << 15),
  RCC_BDCR_BDRST = (1 << 16)
};

#if defined(STM32_RCC_LSE_DRIVE)

#define STM32_BDCR_LSEDRV_SHIFT (3)
#define STM32_BDCR_LSEDRV_MASK (0x3)

enum rcc_bdcr_lsedrv : u32
{
  RCC_BDCR_LSEDRV_LOW = 0b00,
  RCC_BDCR_LSEDRV_MEDIUM_HIGH = 0b01,
  RCC_BDCR_LSEDRV_MEDIUM_LOW = 0b10,
  RCC_BDCR_LSEDRV_HIGH = 0b11
};
#endif

/* Bits[9:8] */
#define RCC_BDCR_RTCSEL_SHIFT (8)
#define RCC_BDCR_RTCSEL_MASK (0x3u)

enum rcc_bdcr_rtcsel : u32
{
  RCC_BDCR_RTCSEL_NOCLK = 0b00,
  RCC_BDCR_RTCSEL_LSE = 0b01,
  RCC_BDCR_RTCSEL_LSI = 0b10,
  RCC_BDCR_RTCSEL_HSE = 0b11
};

/*
 * Register: RCC_CSR - Control/Status register
 * Address: 0x24
 * Reset: 0x0c00 0000 (System reset, reset flags by power reset only)
 */
enum rcc_csr : u32
{
  RCC_CSR_LSION = (1 << 0),
  RCC_CSR_LSIRDY = (1 << 1),

#if defined(STM32_RCC_V1dot8V)
  RCC_CSR_V18PWRRSTF = (1 << 23),
#endif

  RCC_CSR_RMVF = (1 << 24),

#if defined(STM32_OPTION_BYTE_LOADER)
  RCC_CSR_OBLRSTR = (1 << 25),
#endif

  RCC_CSR_PINRSTF = (1 << 26),
  RCC_CSR_PORRSTF = (1 << 27),
  RCC_CSR_SFTRSTF = (1 << 28),
  RCC_CSR_IWDGRSTF = (1 << 29),
  RCC_CSR_WWDGRSTF = (1 << 30),
  RCC_CSR_LPWRRSTF = (1u << 31)
};

#if defined(STM32_RCC_AHBRSTR)
/*
 * Register: RCC_AHBRSTR
 * Address: 0x28
 * Reset: 0x0000 0000
 */
enum rcc_ahbrstr : u32
{
#if defined(STM32_RCC_OTGFS)
  RCC_AHBRSTR_OTGFSRST = (1 << 12),
#endif

#if defined(STM32_ETH)
  RCC_AHBRSTR_ETHMACRST = (1 << 14),
#endif

#if defined(STM32_GPIO_RST_AHB)
#if defined(STM32_GPIOA)
  RCC_AHBRSTR_GPIOARST = (1 << 17),
#endif

#if defined(STM32_GPIOB)
  RCC_AHBRSTR_GPIOBRST = (1 << 18),
#endif

#if defined(STM32_GPIOC)
  RCC_AHBRSTR_GPIOCRST = (1 << 19),
#endif

#if defined(STM32_GPIOD)
  RCC_AHBRSTR_GPIODRST = (1 << 20),
#endif

#if defined(STM32_GPIOE)
  RCC_AHBRSTR_GPIOERST = (1 << 21),
#endif

#if defined(STM32_GPIOF)
  RCC_AHBRSTR_GPIOFRST = (1 << 22),
#endif
#endif

#if defined(STM32_TSC)
  RCC_AHBRSTR_TSCRST = (1 << 24)
#endif
};
#endif

#if defined(STM32_RCC_CFGR2)
#if defined(STM32_RCC_CFGR2_REG)
/*
 * Register: RCC_CFGR2
 * Address: 0x2c
 * Reset: 0x0000 0000
 * **Connectivity devices only**
 */
enum rcc_cfgr2 : u32
{
#if defined(STM32_RCC_PREDIV1SRC)
  RCC_CFGR2_PREDIV1SRC = (1 << 16),
#endif

#if defined(STM32_I2S2)
  RCC_CFGR2_I2S2SRC = (1 << 17),
#endif

#if defined(STM32_I2S3)
  RCC_CFGR2_I2S3SRC = (1 << 18)
#endif
};
#endif

/* Bits[3:0] */
#define RCC_CFGR2_PREDIV1_SHIFT (0)
#define RCC_CFGR2_PREDIV1_MASK (0xfu)

enum rcc_cfgr2_prediv1 : u32
{
  RCC_CFGR2_PREDIV1_NODIV = 0b0000,
  RCC_CFGR2_PREDIV1_DIV2 = 0b0001,
  RCC_CFGR2_PREDIV1_DIV3 = 0b0010,
  RCC_CFGR2_PREDIV1_DIV4 = 0b0011,
  RCC_CFGR2_PREDIV1_DIV5 = 0b0100,
  RCC_CFGR2_PREDIV1_DIV6 = 0b0101,
  RCC_CFGR2_PREDIV1_DIV7 = 0b0110,
  RCC_CFGR2_PREDIV1_DIV8 = 0b0111,
  RCC_CFGR2_PREDIV1_DIV9 = 0b1000,
  RCC_CFGR2_PREDIV1_DIV10 = 0b1001,
  RCC_CFGR2_PREDIV1_DIV11 = 0b1010,
  RCC_CFGR2_PREDIV1_DIV12 = 0b1011,
  RCC_CFGR2_PREDIV1_DIV13 = 0b1100,
  RCC_CFGR2_PREDIV1_DIV14 = 0b1101,
  RCC_CFGR2_PREDIV1_DIV15 = 0b1110,
  RCC_CFGR2_PREDIV1_DIV16 = 0b1111
};

#if defined(STM32_RCC_PREDIV2)
/* Bits[7:4] */
#define RCC_CFGR2_PREDIV2_SHIFT (4)
#define RCC_CFGR2_PREDIV2_MASK (0xfu)

enum rcc_cfgr2_prediv2 : u32
{
  RCC_CFGR2_PREDIV2_NODIV = 0b0000,
  RCC_CFGR2_PREDIV2_DIV2 = 0b0001,
  RCC_CFGR2_PREDIV2_DIV3 = 0b0010,
  RCC_CFGR2_PREDIV2_DIV4 = 0b0011,
  RCC_CFGR2_PREDIV2_DIV5 = 0b0100,
  RCC_CFGR2_PREDIV2_DIV6 = 0b0101,
  RCC_CFGR2_PREDIV2_DIV7 = 0b0110,
  RCC_CFGR2_PREDIV2_DIV8 = 0b0111,
  RCC_CFGR2_PREDIV2_DIV9 = 0b1000,
  RCC_CFGR2_PREDIV2_DIV10 = 0b1001,
  RCC_CFGR2_PREDIV2_DIV11 = 0b1010,
  RCC_CFGR2_PREDIV2_DIV12 = 0b1011,
  RCC_CFGR2_PREDIV2_DIV13 = 0b1100,
  RCC_CFGR2_PREDIV2_DIV14 = 0b1101,
  RCC_CFGR2_PREDIV2_DIV15 = 0b1110,
  RCC_CFGR2_PREDIV2_DIV16 = 0b1111,
};
#endif

#if defined(STM32_RCC_OSC_PLL2)
/* Bits[11:8] */
#define RCC_CFGR2_PLL2MUL_SHIFT (8)
#define RCC_CFGR2_PLL2MUL_MASK (0xfu)

enum rcc_cfgr2_pll2mul : u32
{
  RCC_CFGR2_PLL2MUL8 =  0b0110,
  RCC_CFGR2_PLL2MUL9 =  0b0111,
  RCC_CFGR2_PLL2MUL10 = 0b1000,
  RCC_CFGR2_PLL2MUL11 = 0b1001,
  RCC_CFGR2_PLL2MUL12 = 0b1010,
  RCC_CFGR2_PLL2MUL13 = 0b1011,
  RCC_CFGR2_PLL2MUL14 = 0b1100,
  RCC_CFGR2_PLL2MUL16 = 0b1110,
  RCC_CFGR2_PLL2MUL20 = 0b1111
};
#endif

#if defined(STM32_RCC_OSC_PLL3)
/* Bits[15:12] */
#define RCC_CFGR2_PLL3MUL_SHIFT (12)
#define RCC_CFGR2_PLL3MUL_MASK (0xfu)

enum rcc_cfgr2_pll3mul : u32
{
  RCC_CFGR2_PLL3MUL8 =  0b0110,
  RCC_CFGR2_PLL3MUL9 =  0b0111,
  RCC_CFGR2_PLL3MUL10 = 0b1000,
  RCC_CFGR2_PLL3MUL11 = 0b1001,
  RCC_CFGR2_PLL3MUL12 = 0b1010,
  RCC_CFGR2_PLL3MUL13 = 0b1011,
  RCC_CFGR2_PLL3MUL14 = 0b1100,
  RCC_CFGR2_PLL3MUL16 = 0b1110,
  RCC_CFGR2_PLL3MUL20 = 0b1111
};
#endif
#endif

#if defined(STM32_RCC_EXTENDED_REGS)
enum rcc_cfgr3 : u32
{
#if defined(STM32_I2C1)
  RCC_CFGR3_I2C1SW = (1 << 4),
#endif

#if defined(STM32_CEC)
  RCC_CFGR3_CECSW = (1 << 6),
#endif

#if defined(STM32_USB)
  RCC_CFGR_USBSW = (1 << 7),
#endif

#if defined(STM32_ADC)
  RCC_CFGR_ADCSW = (1 << 8),
#endif
}

#if defined(STM32_USART1)
#define RCC_CFGR3_USART1SW_SHIFT (0)
#define RCC_CFGR3_USART1SW_MASK (0x3)

enum rcc_cfgr3_usart1sw : u32
{
  RCC_CFGR3_USART1SW_PCLK = 0b00,
  RCC_CFGR3_USART1SW_SYSCLK = 0b01,
  RCC_CFGR3_USART1SW_LSE = 0b10,
  RCC_CFGR3_USART1SW_HSI = 0b11
};
#endif

#if defined(STM32_USART2)

#define RCC_CFGR3_USART2SW_SHIFT (16)
#define RCC_CFGR3_USART2SW_MASK (0x3)

enum rcc_cfgr3_usart2sw : u32
{
  RCC_CFGR3_USART2SW_PCLK = 0b00,
  RCC_CFGR3_USART2SW_SYSCLK = 0b01,
  RCC_CFGR3_USART2SW_LSE = 0b10,
  RCC_CFGR3_USART2SW_HSI = 0b11
};

#if defined(STM32_USART3)

#define RCC_CFGR3_USART3SW_SHIFT (18)
#define RCC_CFGR3_USART3SW_MASK (0x3)

enum rcc_cfgr_usart3sw : u32
{
  RCC_CFGR_USART3SW_PCLK = 0b00,
  RCC_CFGR_USART3SW_SYSCLK = 0b01,
  RCC_CFGR_USART3SW_LSE = 0b10,
  RCC_CFGR_USART3SW_HSI = 0b11
};
#endif
#endif

enum rcc_cr2 : u32
{
#if defined(STM32_RCC_OSC_HSI14)
  RCC_CR2_HSI14ON = (1 << 0),
  RCC_CR2_HSI14RDY = (1 << 1),
  RCC_CR2_HSI14DIS = (1 << 2),
#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC_CR2_HSI48ON = (1 << 16),
  RCC_cR2_HSI48RDY = (1 << 17)
#endif
};

#define RCC_CR2_HSI14TRIM_SHIFT (3)
#define RCC_CR2_HSI14TRIM_MASK (0x1f)

#define RCC_CR2_HSI14CAL_SHIFT (8)
#define RCC_CR2_HSI14CAL_MASK (0xff)
#endif

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

/**
 * @brief Available oscillators and PLL clock sources.
 *
 * @note Some oscillators are only available on 
 * specific device families.
 */
enum rcc_osc
{
#if defined(STM32_RCC_OSC_PLL2)
  RCC_OSC_PLL2,
#elif defined(STM32_RCC_OSC_HSI14)
  RCC_OSC_HSI14,
#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC_OSC_PLL3,
#elif defined(STM32_RCC_OSC_HSI48)
  RCC_OSC_HSI48,
#endif

  RCC_OSC_PLL,
  RCC_OSC_HSE,
  RCC_OSC_HSI,
  RCC_OSC_LSI,
  RCC_OSC_LSE
};

/**
 * @brief Available system clock sources.
 */
enum rcc_sysclock
{
  RCC_SYSCLOCK_HSI,
  RCC_SYSCLOCK_HSE,
  RCC_SYSCLOCK_PLL,

#if defined(STM32_RCC_OSC_HSI48)
  RCC_SYSCLOCK_HSI48
#endif
};

/**
 * @brief Available AHB prescalers.
 *
 * @warning AHB frequency should not
 * exceed 72Mhz.
 */
enum rcc_ahb_prescaler
{
  RCC_AHB_PRESCALER_1,
  RCC_AHB_PRESCALER_2,
  RCC_AHB_PRESCALER_4,
  RCC_AHB_PRESCALER_8,
  RCC_AHB_PRESCALER_16,
  RCC_AHB_PRESCALER_64,
  RCC_AHB_PRESCALER_128,
  RCC_AHB_PRESCALER_256,
  RCC_AHB_PRESCALER_512
};

/**
 * @brief Available APB1 prescalers.
 *
 * @warning APB1 bus frequency should not
 * exceed 36Mhz.
 */
enum rcc_apb1_prescaler
{
  RCC_APB1_PRESCALER_1,
  RCC_APB1_PRESCALER_2,
  RCC_APB1_PRESCALER_4,
  RCC_APB1_PRESCALER_8,
  RCC_APB1_PRESCALER_16
};

#if defined(STM32_RCC_PPRE2)
/**
 * @brief Available APB2 prescalers.
 *
 * @warning APB2 bus frequency should not
 * exceed 72Mhz.
 */
enum rcc_apb2_prescaler
{
  RCC_APB2_PRESCALER_1,
  RCC_APB2_PRESCALER_2,
  RCC_APB2_PRESCALER_4,
  RCC_APB2_PRESCALER_8,
  RCC_APB2_PRESCALER_16
};
#endif

#if defined(STM32_RCC_ADCPRE)
/**
 * @brief Available ADC prescalers.
 *
 * @warning ADC clock frequency should not
 * exceed 14Mhz.
 */
enum rcc_adc_prescaler
{
  RCC_ADC_PRESCALER_2,
  RCC_ADC_PRESCALER_4,
  RCC_ADC_PRESCALER_6,
  RCC_ADC_PRESCALER_8
};
#endif

#if defined(STM32_RCC_PLLSRC_2BIT)

enum rcc_pll_source
{
  RCC_PLL_SOURCE_HSI_DIV2,
  RCC_PLL_SOURCE_HSI_PREDIV,
  RCC_PLL_SOURCE_HSE_PREDIV,
  RCC_PLL_SOURCE_HSI48
};

#else

/**
 * @brief Available PLL sources.
 *
 * @note Some source(s) are only available on 
 * specific device families.
 */
enum rcc_pll_source
{
  /**
   * @brief HSI as PLL source.
   *
   * @details Available on every devices.
   */
  RCC_PLL_SOURCE_HSI,

  /**
   * @brief HSE as PLL source.
   *
   * @details Available only on density devices.
   */
  RCC_PLL_SOURCE_HSE,

  /* Connectivity devices only */
  /**
   * @brief PREDIV1 as PLL source.
   * 
   * @details Available only on connectivity devices. 
   */
  RCC_PLL_SOURCE_PREDIV1
};
#endif

/**
 * @brief Available HSE prescalers.
 */
enum rcc_pll_hse_prescaler
{
  RCC_PLL_HSE_PRESCALER_NODIV,
  RCC_PLL_HSE_PRESCALER_DIV2
};

/**
 * @brief Available PLL multiplication factors.
 */
enum rcc_pll_multiplication_factor
{
#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  RCC_PLL_MULTIPLICATION_FACTOR_2,
  RCC_PLL_MULTIPLICATION_FACTOR_3,
#endif

  RCC_PLL_MULTIPLICATION_FACTOR_4,
  RCC_PLL_MULTIPLICATION_FACTOR_5,
  RCC_PLL_MULTIPLICATION_FACTOR_6,

#if defined(STM32_RCC_PLLMUL_LAYOUT1)
  RCC_PLL_MULTIPLICATION_FACTOR_6dot5,
#endif

  RCC_PLL_MULTIPLICATION_FACTOR_7,
  RCC_PLL_MULTIPLICATION_FACTOR_8,
  RCC_PLL_MULTIPLICATION_FACTOR_9,

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  RCC_PLL_MULTIPLICATION_FACTOR_10,
  RCC_PLL_MULTIPLICATION_FACTOR_11,
  RCC_PLL_MULTIPLICATION_FACTOR_12,
  RCC_PLL_MULTIPLICATION_FACTOR_13,
  RCC_PLL_MULTIPLICATION_FACTOR_14,
  RCC_PLL_MULTIPLICATION_FACTOR_15,
  RCC_PLL_MULTIPLICATION_FACTOR_16,
#endif
};

/**
 * @brief Available USB OTG FS prescalers.
 */
enum rcc_usb_otg_fs_prescaler
{
  RCC_USB_OTG_FS_PRESCALER_2,
  RCC_USB_OTG_FS_PRESCALER_3
};

/**
 * @brief Available MCO.
 *
 * @note Some output(s) are available only
 * on specific devices families.
 *
 * @warning The clock source configured
 * to output its clock should not exceed
 * the maximum allowed pin frequency (50Mhz).
 */
enum rcc_microntroller_clock_output
{
  RCC_MCO_NO_OUTPUT,

#if defined(STM32_RCC_OSC_HSI14)
  RCC_MCO_HSI14,
  RCC_MCO_LSI,
  RCC_MCO_LSE,
#endif

  RCC_MCO_SYSCLOCK,
  RCC_MCO_HSI,
  RCC_MCO_HSE,
  RCC_MCO_PLL,

#if defined(STM32_RCC_OSC_PLL2)
  /**
   * @note Available only on connectivity devices.
   */
  RCC_MCO_PLL2,
#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC_MCO_PLL3_DIV2,
#endif
  RCC_MCO_XT1,

#if defined(STM32_RCC_OSC_PLL3)
  /**
   * @note Available only on connectivity devices.
   */
  RCC_MCO_PLL3,
#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC_MCO_HSI48
#endif
};

#if defined(STM32_RCC_MCOPRE)
enum rcc_mco_prescaler
{
  RCC_MCO_PRESCALER_DIV1,
  RCC_MCO_PRESCALER_DIV2,
  RCC_MCO_PRESCALER_DIV4,
  RCC_MCO_PRESCALER_DIV8,
  RCC_MCO_PRESCALER_DIV16,
  RCC_MCO_PRESCALER_DIV32,
  RCC_MCO_PRESCALER_DIV64,
  RCC_MCO_PRESCALER_DIV128
};
#endif

#if defined(STM32_RCC_PLLNODIV)
enum mco_pll_prescaler
{
  MCO_PLL_PRESCALER_NODIV,
  MCO_PLL_PRESCALER_DIV2
};
#endif

/**
 * @brief Available RCC interrupts.
 */
enum rcc_interrupt
{
  /**
   * @brief Generates an interrupt when LSI is ready.
   */
  RCC_INTERRUPT_LSI,

  /**
   * @brief Generates an interrupt when LSE is ready.
   */
  RCC_INTERRUPT_LSE,

  /**
   * @brief Generates an interrupt when HSI is ready.
   */
  RCC_INTERRUPT_HSI,

  /**
   * @brief Generates an interrupt when HSE is ready.
   */
  RCC_INTERRUPT_HSE,

  /**
   * @brief Generates an interrupt when PLL is ready.
   */
  RCC_INTERRUPT_PLL,

#if defined(STM32_RCC_OSC_PLL2)
  /**
   * @brief Generates an interrupt when PLL2 is ready.
   *
   * @note Available only on connectivity devices.
   */
  RCC_INTERRUPT_PLL2,
#elif defined(STM32_RCC_OSC_HSI14)
  RCC_INTERRUPT_HSI14,
#endif

#if defined(STM32_RCC_OSC_PLL3)
  /**
   * @brief Generates an interrupt when PLL3 is ready.
   *
   * @note Available only on connectivity devices.
   */
  RCC_INTERRUPT_PLL3,
#elif defined(STM32_RCC_OSC_HSI48)
  RCC_INTERRUPT_HSI48,
#endif

  /**
   * @brief Generates an interrupt when a failure is detected
   * in the external oscillator (HSE).
   */
  RCC_INTERRUPT_CSS
};

/**
 * @brief Available peripherals.
 */
enum rcc_periph
{
  RCC_PERIPH_DMA1,

#if defined(STM32_DMA2)
  RCC_PERIPH_DMA2,
#endif

  RCC_PERIPH_SRAM,
  RCC_PERIPH_FLITF,
  RCC_PERIPH_CRC,

#if defined(STM32_TSC)
  RCC_PERIPH_TSC,
#endif

#if defined(STM32_FSMC)
  RCC_PERIPH_FSMC,
#endif

#if defined(STM32_SDIO)
  RCC_PERIPH_SDIO,
#endif

#if defined(STM32_RCC_OTGFS)
  RCC_PERIPH_OTGFS,
#endif

#if defined(STM32_ETH)
  RCC_PERIPH_ETHMAC,
  RCC_PERIPH_ETHMACTX,
  RCC_PERIPH_ETHMACRX,
#endif

#if defined(STM32_RCC_SYSCFG)
  RCC_PERIPH_SYSCFG,
#elif defined(STM32_RCC_AFIO)
  RCC_PERIPH_AFIO,
#endif

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

  RCC_PERIPH_ADC1,

#if defined(STM32_ADC2)
  RCC_PERIPH_ADC2,
#endif

  RCC_PERIPH_TIM1,
  RCC_PERIPH_SPI1,

#if defined(STM32_TIM8)
  RCC_PERIPH_TIM8,
#endif

  RCC_PERIPH_USART1,

#if defined(STM32_ADC3)
  RCC_PERIPH_ADC3,
#endif

#if defined(STM32_TIM9)
  RCC_PERIPH_TIM9,
#endif

#if defined(STM32_TIM10)
  RCC_PERIPH_TIM10,
#endif

#if defined(STM32_TIM11)
  RCC_PERIPH_TIM11,
#endif

#if defined(STM32_DBGMCU)
  RCC_PERIPH_DBGMCU,
#endif

#if defined(STM32_TIM2)
  RCC_PERIPH_TIM2,
#endif

#if defined(STM32_TIM3)
  RCC_PERIPH_TIM3,
#endif

#if defined(STM32_TIM4)
  RCC_PERIPH_TIM4,
#endif

#if defined(STM32_TIM5)
  RCC_PERIPH_TIM5,
#endif

#if defined(STM32_TIM6)
  RCC_PERIPH_TIM6,
#endif

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

#if defined(STM32_TIM15)
  RCC_PERIPH_TIM15,
#endif

#if defined(STM32_TIM16)
  RCC_PERIPH_TIM16,
#endif

#if defined(STM32_TIM17)
  RCC_PERIPH_TIM17,
#endif

  RCC_PERIPH_WWDG,

#if defined(STM32_SPI2)
  RCC_PERIPH_SPI2,
#endif

#if defined(STM32_SPI3)
  RCC_PERIPH_SPI3,
#endif

#if defined(STM32_USART2)
  RCC_PERIPH_USART2,
#endif

#if defined(STM32_USART3)
  RCC_PERIPH_USART3,
#endif

#if defined(STM32_UART4)
  RCC_PERIPH_UART4,
#endif

#if defined(STM32_UART4)
  RCC_PERIPH_UART5,
#endif

#if defined(STM32_USART6)
  RCC_PERIPH_USART6,
#endif

#if defined(STM32_USART7)
  RCC_PERIPH_USART7,
#endif

#if defined(STM32_USART8)
  RCC_PERIPH_USART8,
#endif

#if defined(STM32_I2C1)
  RCC_PERIPH_I2C1,
#endif

#if defined(STM32_I2C2)
  RCC_PERIPH_I2C2,
#endif

#if defined(STM32_USB)
  RCC_PERIPH_USB,
#endif

#if defined(STM32_CAN1)
  RCC_PERIPH_CAN1,
#endif

#if defined(STM32_CAN2)
  RCC_PERIPH_CAN2,
#endif

#if defined(STM32_BKP)
  RCC_PERIPH_BKP,
#endif

#if defined(STM32_CRS)
  RCC_PERIPH_CRS,
#endif

  RCC_PERIPH_PWR,

#if defined(STM32_DAC)
  RCC_PERIPH_DAC,
#endif

#if defined(STM32_CEC)
  RCC_PERIPH_CEC,
#endif

  RCC_PERIPH_RTC
};

/**
 * @brief Available RTC sources.
 */
enum rcc_rtc_source
{
  RCC_RTC_SOURCE_NOCLOCK,
  RCC_RTC_SOURCE_LSE,
  RCC_RTC_SOURCE_LSI,
  RCC_RTC_SOURCE_HSE
};

/**
 * @brief Available RCC reset flags.
 *
 * @details These flags are all set by hardware
 * when a specific event occurs.
 *
 * @note They have to be manually cleared
 * by calling rcc_reset_flags_clear().
 *
 * @see rcc_reset_flags_clear()
 */
enum rcc_reset_flag
{
#if defined(STM32_RCC_V1dot8V)
  RCC_RESET_FLAG_V1dot8,
#endif

#if defined(STM32_OPTION_BYTE_LOADER)
  RCC_RESET_FLAG_OPTION_BYTE_LOADER,
#endif

  /**
   * @brief Set when a reset from NRST pin occurs.
   */
  RCC_RESET_FLAG_PIN,

  /**
   * @brief Set when a POR/PDR reset occurs
   */
  RCC_RESET_FLAG_POR_PDR,

  /**
   * @brief Set when a software reset occurs.
   */
  RCC_RESET_FLAG_SOFTWARE,

  /**
   * @brief Set when an indipendent watchdog reset occurs.
   */
  RCC_RESET_FLAG_INDEPENDENT_WATCHDOG,

  /**
   * @brief Set when a window watchdog reset occurs.
   */
  RCC_RESET_FLAG_WINDOW_WATCHDOG,

  /**
   * @brief Set when a low-power management reset occurs.
   */
  RCC_RESET_FLAG_LOW_POWER
};

/**
 * @brief Available PREDIV1 prescalers.
 *
 * @note Available only on connectivity devices.
 */
enum rcc_prediv1_prescaler
{
  RCC_PREDIV1_PRESCALER_1,
  RCC_PREDIV1_PRESCALER_2,
  RCC_PREDIV1_PRESCALER_3,
  RCC_PREDIV1_PRESCALER_4,
  RCC_PREDIV1_PRESCALER_5,
  RCC_PREDIV1_PRESCALER_6,
  RCC_PREDIV1_PRESCALER_7,
  RCC_PREDIV1_PRESCALER_8,
  RCC_PREDIV1_PRESCALER_9,
  RCC_PREDIV1_PRESCALER_10,
  RCC_PREDIV1_PRESCALER_11,
  RCC_PREDIV1_PRESCALER_12,
  RCC_PREDIV1_PRESCALER_13,
  RCC_PREDIV1_PRESCALER_14,
  RCC_PREDIV1_PRESCALER_15,
  RCC_PREDIV1_PRESCALER_16
};

#if defined(STM32_RCC_PREDIV2)
/**
 * @brief Available PREDIV2 prescalers.
 *
 * @note Available only on connectivity devices.
 */
enum rcc_prediv2_prescaler
{
  RCC_PREDIV2_PRESCALER_1,
  RCC_PREDIV2_PRESCALER_2,
  RCC_PREDIV2_PRESCALER_3,
  RCC_PREDIV2_PRESCALER_4,
  RCC_PREDIV2_PRESCALER_5,
  RCC_PREDIV2_PRESCALER_6,
  RCC_PREDIV2_PRESCALER_7,
  RCC_PREDIV2_PRESCALER_8,
  RCC_PREDIV2_PRESCALER_9,
  RCC_PREDIV2_PRESCALER_10,
  RCC_PREDIV2_PRESCALER_11,
  RCC_PREDIV2_PRESCALER_12,
  RCC_PREDIV2_PRESCALER_13,
  RCC_PREDIV2_PRESCALER_14,
  RCC_PREDIV2_PRESCALER_15,
  RCC_PREDIV2_PRESCALER_16
};
#endif

#if defined(STM32_RCC_OSC_PLL2)
/**
 * @brief Available PLL2 multiplication factors.
 *
 * @note Available only on connectivity devices.
 */
enum rcc_pll2_multiplication_factor
{
  RCC_PLL2_MULTIPLICATION_FACTOR_8,
  RCC_PLL2_MULTIPLICATION_FACTOR_9,
  RCC_PLL2_MULTIPLICATION_FACTOR_10,
  RCC_PLL2_MULTIPLICATION_FACTOR_11,
  RCC_PLL2_MULTIPLICATION_FACTOR_12,
  RCC_PLL2_MULTIPLICATION_FACTOR_13,
  RCC_PLL2_MULTIPLICATION_FACTOR_14,
  RCC_PLL2_MULTIPLICATION_FACTOR_16,
  RCC_PLL2_MULTIPLICATION_FACTOR_20,
};
#endif

/**
 * @brief Available PLL3 multiplication factors.
 *
 * @note Available only on connectivity devices.
 */
enum rcc_pll3_multiplication_factor
{
  RCC_PLL3_MULTIPLICATION_FACTOR_8,
  RCC_PLL3_MULTIPLICATION_FACTOR_9,
  RCC_PLL3_MULTIPLICATION_FACTOR_10,
  RCC_PLL3_MULTIPLICATION_FACTOR_11,
  RCC_PLL3_MULTIPLICATION_FACTOR_12,
  RCC_PLL3_MULTIPLICATION_FACTOR_13,
  RCC_PLL3_MULTIPLICATION_FACTOR_14,
  RCC_PLL3_MULTIPLICATION_FACTOR_16,
  RCC_PLL3_MULTIPLICATION_FACTOR_20,
};

/**
 * @brief Available PREDIV1 sources.
 *
 * @note Available only on connectivity devices.
 */
enum rcc_prediv1_source
{
  RCC_PREDIV1_SOURCE_HSE,
  RCC_PREDIV1_SOURCE_PLL2
};

#if defined(STM32_I2S2)

/**
 * @brief Available I2S2 sources.
 *
 * @note Available only on connectivity devices.
 */
enum rcc_i2s2_source
{
  RCC_I2S2_SOURCE_SYSCLOCK,
  RCC_I2S2_SOURCE_PLL3
};

#endif

#if defined(STM32_I2S3)

/**
 * @brief Available I2S3 sources.
 *
 * @note Available only on connectivity devices.
 */
enum rcc_i2s3_source
{
  RCC_I2S3_SOURCE_SYSCLOCK,
  RCC_I2S3_SOURCE_PLL3
};
#endif

#if defined(STM32_USART1) || defined(STM32_USART2) || defined(STM32_USART3)
enum rcc_usart_clock_source
{
  RCC_USART_CLOCK_SOURCE_PCLK,
  RCC_USART_CLOCK_SOURCE_SYSCLK,
  RCC_USART_CLOCK_SOURCE_LSE,
  RCC_USART_CLOCK_SOURCE_HSI
};
#endif

#if defined(STM32_I2C1)
enum rcc_i2c1_clock_source
{
  RCC_I2C1_CLOCK_SOURCE_HSI,
  RCC_I2C1_CLOCK_SOURCE_SYSCLK
};
#endif

#if defined(STM32_CEC)
enum rcc_cec_clock_source
{
  RCC_CEC_CLOCK_SOURCE_HSI_DIV244,
  RCC_CEC_CLOCK_SOURCE_LSE
};
#endif

#if defined(STM32_USB)
enum rcc_usb_clock_source
{
  RCC_USB_CLOCK_SOURCE_HSI48,
  RCC_USB_CLOCK_SOURCE_PLLCLK
};
#endif

/**
 * @brief Complete clock configuration structure.
 *
 * @details Contains all parameters needed to configure the entire
 * clock tree, including oscillator selection, PLL settings, 
 * bus prescalers and peripheral clock settings.
 */
struct rcc_clock_config
{
  /**
   * @brief Primary clock source to use.
   *
   * @warning Only HSE and HSI should be 
   * used for this purpose.
   *
   * @see rcc_osc
   */
  enum rcc_osc osc;

  /**
   * @brief HSE prescaler for PLL input.
   *
   * @details Sets the HSE prescaler before feeding the PLL.
   *
   * @note If is_connectivity_device != 0, this value is ignored.
   * In that case, use prediv1_prescaler and/or prediv2_prescaler
   * to set the hse prescaler before reaching the PLL. 
   *
   * @see prediv1_prescaler
   * @see prediv2_prescaler
   * @see rcc_pll_hse_prescaler
   */
  enum rcc_pll_hse_prescaler pllxtpre;

  /**
   * @brief Sysclock source selection.
   *
   * @details Sets the sysclock source.
   * Max allowed value is 72Mhz.
   *
   * @note If sysclock is set to HSE or HSI,
   * PLL would be disabled.
   * Therefor, the USB interface would be unavailable.
   * In that case, it's necessary to manually
   * configure and enable the PLL, by:
   * - Configure PLLSRC
   * - Optionally, if PLLSRC = HSE, configure PLLXTPRE
   * - Configure PLLMUL
   * - Configure USB prescaler (Requires a 48Mhz clock)
   * - Enable PLL
   * - Wait for it to be ready
   *
   * @see rcc_sysclock
   */
  enum rcc_sysclock sysclock;

  /**
   * @brief PLL input clock source.
   *
   * @see rcc_pll_source
   */
  enum rcc_pll_source pll_source;

  /**
   * @brief Main PLL multiplication factor.
   *
   * @details Sets the multiplication factor
   * used to generate the PLL output.
   *
   * @see rcc_pll_multiplication_factor
   */
  enum rcc_pll_multiplication_factor pllmul;

#if defined(STM32_RCC_OSC_PLL2)
  /**
   * @brief PLL2 multiplication factor.
   *
   * @details Sets the multiplication factor
   * used to generate the PLL2 output.
   *
   * @note If is_connectivity_device == 0, this value is ignored.
   *
   * @note Available only in connectivity devices.
   *
   * @see rcc_pll2_multiplication_factor
   */
  enum rcc_pll2_multiplication_factor pll2mul;
#endif

#if defined(STM32_RCC_OSC_PLL3)
  /**
   * @brief PLL3 multiplication factor.
   *
   * @details Sets the multiplication factor
   * used to generate the PLL3 output.
   *
   * @note If is_connectivity_device == 0, this value is ignored.
   *
   * @note Available only in connectivity devices.
   *
   * @see rcc_pll3_multiplication_factor
   */
  enum rcc_pll3_multiplication_factor pll3mul;
#endif

#if defined(STM32_RCC_PREDIV1)
  /**
   * @brief PREDIV1 clock source.
   *
   * @details Sets the prediv1 clock source.
   *
   * @note If is_connectivity_device == 0, this value is ignored.
   *
   * @see rcc_prediv1_source
   */
  enum rcc_prediv1_source prediv1_source;

  /**
   * @brief PREDIV1 prescaler.
   *
   * @details Sets the prediv1 prescaler.
   *
   * @note If is_connectivity_device == 0, this value is ignored.
   *
   * @see rcc_prediv1_prescaler
   */
  enum rcc_prediv1_prescaler prediv1_prescaler;
#endif

  /**
   * @brief AHB prescaler.
   *
   * @details Sets the AHB prescaler.
   * This bus drives CPU, memory and DMA.
   *
   * @warning The AHB bus frequency should not
   * exceed 72Mhz.
   *
   * @see rcc_ahb_prescaler
   */
  enum rcc_ahb_prescaler ahb_prescaler;

#if defined(STM32_RCC_PPRE2)
  /**
   * @brief APB2 prescaler.
   *
   * @details Sets the APB2 prescaler.
   *
   * @warning The APB2 frequency should not
   * exceed 72Mhz.
   *
   * @see rcc_apb2_prescaler
   */
  enum rcc_apb2_prescaler apb2_prescaler;
#endif

  /**
   * @brief APB1 prescaler.
   *
   * @details Sets the APB1 prescaler.
   *
   * @warning The APB1 frequency should not
   * exceed 36Mhz.
   *
   * @see rcc_apb1_prescaler
   */
  enum rcc_apb1_prescaler apb1_prescaler;

#if defined(STM32_RCC_ADCPRE)
  /**
   * @brief ADC clock prescaler.
   *
   * @details Sets the ADC prescaler.
   *
   * @warning The ADC frequency should not
   * exceed 14Mhz.
   *
   * @see rcc_adc_prescaler
   */
  enum rcc_adc_prescaler adc_prescaler;
#endif

  /**
   * @brief USB OTG FS clock prescaler.
   *
   * @note The frequency must be exactly 48Mhz.
   *
   * @ßee rcc_usb_otg_fs_prescaler
   */
  enum rcc_usb_otg_fs_prescaler usb_prescaler;

  /**
   * @brief Microcontroller clock output (MCO) source.
   *
   * @details Sets the clock source to output on the MCO pin.
   *
   * @warning The MCO output source should not
   * exceed the maximum allowed output pin frequency (50Mhz).
   *
   * @see rcc_microntroller_clock_output
   */
  enum rcc_microntroller_clock_output mco;

  /**
   * @brief Flash memory wait states.
   *
   * @details Sets the flash memory access latency.
   *
   * @note Must be configured according to the system clock
   * frequency to ensure proper flash memory access timing.
   *
   * @see flash_wait_state
   */
  enum flash_wait_state flash_wait_state;

  /**
   * @brief Device family.
   *
   * @note Affects which clock configuration parameters are available.
   */
  u32 is_connectivity_device;

  u32 apb2_clock_freq;
  u32 apb1_clock_freq;
  u32 ahb_clock_freq;
  u32 sysclock_freq;
};

extern volatile struct rcc_registers_map* RCC;

/**
 * @brief Enables a specific oscillator.
 *
 * @details Turns on the specified oscillator by setting 
 * the appropriate bit in the RCC control register.
 * This function only starts the oscillator;
 * it does not wait for it to stabilize.
 *
 * @param osc The oscillator to enable.
 *
 * @note After enabling an oscillator,
 * you should verify it's ready using rcc_osc_is_ready()
 * or wait for it using rcc_osc_ready_wait()
 * before using it as a clock source.
 *
 * @see rcc_osc for available oscillators.
 * @see rcc_osc_disable()
 * @see rcc_osc_is_ready()
 * @see rcc_osc_ready_wait()
 */
void
rcc_osc_enable(
  enum rcc_osc osc
);

/**
 * @brief Disables a specific oscillator.
 *
 * @details Turns off the specified oscillator by clearing 
 * the appropriate bit in the RCC control register.
 *
 * @param osc The oscillator to disable (HSI, HSE, PLL, etc.).
 *
 * @warning Do not disable an oscillator that is currently being used as
 * the system clock source or as input to the PLL.
 *
 * @see rcc_osc for available oscillators.
 * @see rcc_osc_enable()
 */
void
rcc_osc_disable(
  enum rcc_osc osc
);

/**
 * @brief Checks if a specific oscillator is stable and ready.
 *
 * @details Reads the ready flag for the specified oscillator from the
 * RCC clock control register.
 *
 * @param osc The oscillator to check (HSI, HSE, PLL, etc.).
 *
 * @return Non-zero if the oscillator is ready, 0 if not ready or still
 *  stabilizing.
 *
 * @see rcc_osc for available oscillators.
 * @see rcc_osc_ready_wait()
 */
u32
rcc_osc_is_ready(
  enum rcc_osc osc
);

/**
 * @brief Blocks until a specific oscillator is stable.
 *
 * @details Polls the ready flag for the specified
 * oscillator until it indicates the oscillator is
 * stable and ready to use.
 *
 * @param osc The oscillator to wait for.
 *
 * @note This function blocks indefinitely if the oscillator never
 * stabilizes. For safety-critical applications, consider using
 * rcc_osc_is_ready() with a timeout instead.
 *
 * @see rcc_osc for available oscillators.
 * @see rcc_osc_is_ready()
 */
void
rcc_osc_ready_wait(
  enum rcc_osc osc
);

/**
 * @brief Sets the HSI oscillator trim value.
 *
 * @details Adjusts the internal high-speed oscillator (HSI)
 * frequency by setting the trim value in the RCC_CR register.
 * This allows fine-tuning the HSI frequency to compensate for
 * manufacturing variations.
 *
 * @param trim_value The trim value to set (typically 0-31,
 * depending on device). Higher values increase the frequency,
 * lower values decrease it.
 *
 * @note The factory-calibrated trim value
 * can be read using rcc_get_hsi_cal().
 * @note Changes to the trim value take effect immediately.
 *
 * @see rcc_get_hsi_cal()
 */
void
rcc_set_hsi_trim(
  u32 trim_value
);

/**
 * @brief Gets the factory-calibrated HSI oscillator value.
 *
 * @details Reads the factory-programmed calibration value 
 * for the internal high-speed oscillator (HSI)
 * from the RCC_CR register.
 *
 * @return The factory-calibrated HSI trim value.
 *
 * @note This value is unique to each device and is programmed 
 * during manufacturing to produce the nominal 8MHz frequency.
 *
 * @see rcc_set_hsi_trim()
 */
u32
rcc_get_hsi_cal(void);

/**
 * @brief Enables HSE bypass mode for external clock input.
 *
 * @details Configures the external high-speed oscillator 
 * (HSE) in bypass mode, allowing an external clock signal 
 * to be used instead of a crystal/ceramic resonator.
 * This mode should be used when the device is driven by an 
 * external clock source connected to the OSC_IN pin.
 *
 * @note HSE must be disabled before changing the bypass setting.
 * @note This function does not enable the HSE - use
 * @code
 * rcc_osc_enable(RCC_OSC_HSE);
 * @endcode
 * after setting the bypass mode.
 *
 * @see rcc_hse_bypass_disable()
 * @see rcc_hse_bypass_is_enabled()
 * @see rcc_osc_enable()
 */
void
rcc_hse_bypass_enable(void);

/**
 * @brief Disables HSE bypass mode.
 *
 * @details Configures the external high-speed oscillator 
 * (HSE) to use a crystal or ceramic resonator connected 
 * between the OSC_IN and OSC_OUT pins.
 *
 * @note HSE must be disabled before changing the bypass setting.
 *
 * @see rcc_hse_bypass_enable()
 * @see rcc_hse_bypass_is_enabled()
 */
void
rcc_hse_bypass_disable(void);

/**
 * @brief Checks if HSE bypass mode is enabled.
 *
 * @details Reads the HSE bypass bit from the RCC 
 * control register to determine if the external high-speed 
 * oscillator is configured in bypass mode.
 *
 * @return Non-zero if HSE bypass is enabled,
 * 0 if bypass is disabled.
 *
 * @see rcc_hse_bypass_enable()
 * @see rcc_hse_bypass_disable()
 */
u32
rcc_hse_bypass_is_enabled(void);

/**
 * @brief Enables the Clock Security System (CSS).
 *
 * @details Activates the Clock Security System,
 * which automatically switches to the internal high-speed
 * oscillator (HSI) if the external oscillator (HSE)
 * fails when it's being used as the system clock 
 * or PLL source. This provides fail-safe operation 
 * in case of crystal failure.
 *
 * @note CSS generates an NMI interrupt when HSE failure is detected.
 * @note Once enabled, CSS can be disabled until no failure 
 * events have happened.
 *
 * @see rcc_clock_security_system_disable()
 * @see rcc_clock_security_system_is_enabled()
 */
void
rcc_clock_security_system_enable(void);

/**
 * @brief Disables the Clock Security System (CSS).
 *
 * @details Deactivates the Clock Security System 
 * by clearing the CSSON bit in the RCC control register.
 *
 * @note This function only works before CSS has 
 * detected a failure. After CSS activation due to 
 * HSE failure, only a system reset can disable it.
 *
 * @see rcc_clock_security_system_enable()
 * @see rcc_clock_security_system_is_enabled()
 */
void
rcc_clock_security_system_disable(void);

/**
 * @brief Checks if the Clock Security System (CSS) is enabled.
 *
 * @details Reads the CSS enable bit from the RCC control register.
 *
 * @return Non-zero if CSS is enabled, 0 if CSS is disabled.
 *
 * @see rcc_clock_security_system_enable()
 * @see rcc_clock_security_system_disable()
 */
u32
rcc_clock_security_system_is_enabled(void);

/**
 * @brief Sets the system clock source.
 *
 * @details Configures which clock source drives 
 * the system clock (SYSCLK) by writing to the SW bits 
 * in the RCC_CFGR register. This function only requests
 * the clock switch; you should verify the switch completed 
 * using rcc_get_sysclock_status().
 *
 * @param clock The clock source to use as system clock.
 *
 * @warning The selected clock source must be enabled and stable 
 * before calling this function, or the system may become unstable.
 *
 * @see rcc_sysclock
 * @see rcc_get_sysclock_status()
 * @see rcc_osc_enable()
 * @see rcc_osc_ready_wait()
 */
void
rcc_set_sysclock_source(
  enum rcc_sysclock clock
);

u32
rcc_get_sysclock_status_raw(void);

/**
 * @brief Gets the current active system clock source.
 *
 * @details Reads the system clock status (SWS) bits 
 * from the RCC_CFGR register to determine which clock source 
 * is currently driving the system.
 *
 * @return The currently active system clock source.
 *
 * @note This function is useful to verify that a requested clock switch has
 * completed successfully by comparing the return value with the value
 * previously passed to rcc_set_sysclock_source().
 *
 * @see rcc_set_sysclock_source()
 */
u32
rcc_get_sysclock_status(void);

/**
 * @brief Sets the AHB bus clock prescaler.
 *
 * @details Configures the division factor between 
 * the system clock (SYSCLK) and the AHB bus clock 
 * (HCLK) by writing to the HPRE bits in the RCC_CFGR
 * register. The AHB bus drives the CPU, memory, and DMA.
 *
 * @param prescaler The division factor to apply.
 *
 * @note Changes to the AHB prescaler take effect immediately and affect
 * the core and peripheral timing.
 *
 * @see rcc_ahb_prescaler
 */
void
rcc_set_ahb_prescaler(
  enum rcc_ahb_prescaler prescaler
);

/**
 * @brief Sets the APB1 (low-speed) peripheral bus clock prescaler.
 *
 * @details Configures the division factor between the 
 * AHB clock (HCLK) and the APB1 peripheral bus clock (PCLK1)
 * by writing to the PPRE1 bits in the RCC_CFGR register.
 * The APB1 clock drives the low-speed peripherals.
 *
 * @param prescaler The division factor to apply.
 *
 * @note The APB1 clock frequency must not exceed the maximum specified
 * in the device datasheet (typically 36MHz for STM32F10x).
 *
 * @note Timers on APB1 use a clock frequency of (PCLK1 × 2) when APB1
 * prescaler is not 1.
 *
 * @see rcc_apb1_prescaler
 */
void
rcc_set_apb1_prescaler(
  enum rcc_apb1_prescaler prescaler
);

#if defined(STM32_RCC_PPRE2)
/**
 * @brief Sets the APB2 (high-speed) peripheral bus clock prescaler.
 *
 * @details Configures the division factor between the 
 * AHB clock (HCLK) and the APB2 peripheral bus clock (PCLK2)
 * by writing to the PPRE2 bits in the RCC_CFGR register.
 * The APB2 clock drives the high-speed peripherals.
 *
 * @param prescaler The division factor to apply.
 *
 * @note The APB2 clock frequency must not exceed the maximum specified
 * in the device datasheet (typically 72MHz for STM32F10x).
 *
 * @note Timers on APB2 use a clock frequency of (PCLK2 × 2) when APB2
 * prescaler is not 1.
 *
 * @see rcc_apb2_prescaler
 */
void
rcc_set_apb2_prescaler(
  enum rcc_apb2_prescaler prescaler
);
#endif

#if defined(STM32_RCC_ADCPRE)
/**
 * @brief Sets the ADC clock prescaler.
 *
 * @details Configures the division factor between the APB2 clock (PCLK2)
 * and the ADC clock by writing to the ADCPRE bits in the RCC_CFGR register.
 *
 * @param prescaler The division factor to apply.
 *
 * @note The ADC clock frequency must not exceed the maximum specified
 * in the device datasheet (typically 14MHz for STM32F10x).
 *
 * @note ADC prescaler changes take effect immediately and affect ongoing
 * ADC conversions.
 *
 * @see rcc_adc_prescaler
 */
void
rcc_set_adc_prescaler(
  enum rcc_adc_prescaler prescaler
);
#endif

/**
 * @brief Sets the PLL clock source.
 *
 * @details Configures which clock source is used as 
 * input to the Phase-Locked Loop (PLL) by writing to 
 * the PLLSRC bit in the RCC_CFGR register.
 *
 * @param source The clock source to use as PLL input.
 *
 * @warning The PLL must be disabled (using rcc_osc_disable(RCC_PLL)) before
 * changing its source.
 *
 * @note When using HSE as PLL source, 
 * ensure HSE is stable before configuring the PLL.
 *
 * @see rcc_pll_source
 * @see rcc_osc_disable()
 * @see rcc_set_pll_hse_prescaler()
 * @see rcc_set_pll_multiplication_factor()
 */
void
rcc_set_pll_source(
  enum rcc_pll_source source
);

/**
 * @brief Sets the HSE divider for PLL input.
 *
 * @details Configures the division factor applied 
 * to the HSE clock before it's used as PLL input by 
 * setting the PLLXTPRE bit in the RCC_CFGR register.
 * This is only applicable when HSE is selected as the PLL source.
 *
 * @param prescaler The division factor to apply to HSE.
 *
 * @warning The PLL must be disabled before changing this prescaler.
 * @note This setting has no effect when HSI is selected as PLL source.
 *
 * @see rcc_pll_hse_prescaler
 * @see rcc_set_pll_source()
 */
void
rcc_set_pll_hse_prescaler(
  enum rcc_pll_hse_prescaler prescaler
);

/**
 * @brief Sets the PLL multiplication factor.
 *
 * @details Configures the multiplication factor applied 
 * to the PLL input clock by writing to the PLLMUL bits 
 * in the RCC_CFGR register. This determines
 * the PLL output frequency.
 *
 * @param factor The multiplication factor to apply.
 *
 * @warning The PLL must be disabled before changing its 
 * multiplication factor.
 *
 * @warning The resulting PLL output frequency must 
 * not exceed the maximum system frequency 
 * specified in the device datasheet 
 * (typically 72MHz for STM32F10x devices).
 *
 * @see rcc_pll_multiplication_factor
 * @see rcc_set_pll_source()
 * @see rcc_set_pll_hse_prescaler()
 */
void
rcc_set_pll_multiplication_factor(
  enum rcc_pll_multiplication_factor factor
);

#if defined(STM32_RCC_OTGFS)
/**
 * @brief Sets the USB OTG FS clock prescaler.
 *
 * @details Configures the division factor applied to PLL 
 * output before it's used as the USB OTG FS clock by 
 * setting the OTGFSPRE bit in the RCC_CFGR register.
 * This is used to derive the required 48MHz USB clock
 * from the PLL output.
 *
 * @param prescaler The division factor to apply.
 *
 * @note To obtain the required 48MHz USB clock, configure 
 * the PLL output to either 96MHz (for /2) or 144MHz (for /3).
 *
 * @note This setting is only available on connectivity line devices 
 * (STM32F105/107).
 *
 * @see rcc_usb_otg_fs_prescaler
 * @see rcc_set_pll_multiplication_factor()
 */
void
rcc_set_usb_otg_fs_prescaler(
  enum rcc_usb_otg_fs_prescaler prescaler
);
#endif

/**
 * @brief Sets the microcontroller clock output (MCO) source.
 *
 * @details Configures which internal clock is output 
 * on the MCO pin by writing to the MCO bits in the 
 * RCC_CFGR register. This feature allows monitoring of 
 * internal clocks or providing a clock to external components.
 *
 * @param output The clock source to output on MCO pin.
 * @note The MCO pin must be configured as an alternate
 * function output before using this function.
 *
 * @note The maximum frequency on the MCO pin is limited by the 
 * GPIO speed and should not exceed 50MHz.
 *
 * @note Some options are only available on specific device families.
 *
 * @see rcc_microntroller_clock_output
 */
void
rcc_set_microcontroller_clock_output(
  enum rcc_microntroller_clock_output output
);

#if defined(STM32_RCC_MCOPRE)
void
rcc_set_mco_prescaler(
  enum rcc_mco_prescaler prescaler
);
#endif

#if defined(STM32_RCC_PLLNODIV)
void
rcc_set_mco_pll_prescaler(
  enum mco_pll_prescaler prescaler
)
#endif

/**
 * @brief Checks if a specific RCC interrupt flag is set.
 *
 * @details Reads the specified interrupt flag bit from
 * the RCC_CIR register to determine if the associated 
 * interrupt event has occurred.
 *
 * @param interrupt The interrupt flag to check.
 *
 * @return Non-zero if the interrupt flag is set,
 * 0 if the flag is not set.
 *
 * @note Interrupt flags can be set regardless of whether
 * the corresponding interrupt is enabled.
 *
 * @see rcc_interrupt
 * @see rcc_interrupt_flag_clear()
 * @see rcc_interrupt_enable()
 */
u32
rcc_is_interrupt_flag_set(
  enum rcc_interrupt interrupt
);

/**
 * @brief Enables a specific RCC interrupt.
 *
 * @details Enables generation of an interrupt when the 
 * specified clock event occurs by setting the corresponding
 * bit in the RCC_CIR register.
 *
 * @param interrupt The interrupt to enable.
 *
 * @note The Clock Security System (CSS) interrupt cannot 
 * be enabled using this function. It is automatically
 * enabled when CSS is activated.
 *
 * @note When enabled, these interrupts will trigger when the
 * corresponding oscillator or PLL becomes ready.
 *
 * @see rcc_interrupt
 * @see rcc_interrupt_disable()
 * @see rcc_is_interrupt_flag_set()
 */
void
rcc_interrupt_enable(
  enum rcc_interrupt interrupt
);

/**
 * @brief Disables a specific RCC interrupt.
 *
 * @details Disables generation of an interrupt for the 
 * specified clock event by clearing the corresponding bit 
 * in the RCC_CIR register.
 *
 * @param interrupt The interrupt to disable.
 *
 * @note The Clock Security System (CSS) interrupt cannot be
 * disabled using this function. It is automatically
 * disabled when CSS is deactivated.
 *
 * @note Disabling an interrupt does not clear any pending 
 * interrupt flags.
 *
 * @see rcc_interrupt
 * @see rcc_interrupt_enable()
 * @see rcc_interrupt_flag_clear()
 */
void
rcc_interrupt_disable(
  enum rcc_interrupt interrupt
);

/**
 * @brief Clears a specific RCC interrupt flag.
 *
 * @details Clears the specified interrupt flag by writing 
 * to the corresponding bit in the RCC_CIR register. 
 * This function should be called after handling an interrupt
 * to prevent it from triggering again immediately.
 *
 * @param interrupt The interrupt flag to clear.
 *
 * @note Clearing an interrupt flag is necessary before the
 * interrupt handler can be triggered again by the same event.
 *
 * @see rcc_interrupt
 * @see rcc_is_interrupt_flag_set()
 */
void
rcc_interrupt_flag_clear(
  enum rcc_interrupt interrupt
);

/**
 * @brief Resets a specific peripheral.
 *
 * @details Performs a software reset of the specified 
 * peripheral by setting and then clearing the appropriate 
 * bit in the RCC reset register. This returns the peripheral
 * to its post-reset state without affecting the clock enable status.
 *
 * @param periph The peripheral to reset.
 *
 * @note The reset is performed by first setting the reset bit, then
 * clearing it to ensure the peripheral completes its reset cycle.
 *
 * @note Resetting a peripheral does not disable its clock.
 *
 * @see rcc_periph
 * @see rcc_periph_clock_enable()
 * @see rcc_periph_clock_disable()
 */
void
rcc_periph_reset(
  enum rcc_periph periph
);


/**
 * @brief Enables the clock for a specific peripheral.
 *
 * @details Enables the clock signal to the specified 
 * peripheral by setting the appropriate bit in one of
 * the RCC clock enable registers. Peripherals cannot
 * function without their clock enabled.
 *
 * @param periph The peripheral whose clock should be enabled.
 *
 * @note Enabling a peripheral clock increases power consumption.
 * Only enable clocks for peripherals that are actively being used.
 *
 * @note Accessing a peripheral while its clock is disabled
 * may cause a hard fault.
 *
 * @see rcc_periph
 * @see rcc_periph_clock_disable()
 * @see rcc_periph_reset()
 */
void
rcc_periph_clock_enable(
  enum rcc_periph periph
);

/**
 * @brief Disables the clock for a specific peripheral.
 *
 * @details Disables the clock signal to the specified 
 * peripheral by clearing the appropriate bit in one of 
 * the RCC clock enable registers. This places the peripheral
 * in a low-power state.
 *
 * @param periph The peripheral whose clock should be disabled.
 *
 * @warning Disabling a peripheral clock while the peripheral is still active
 * may cause unexpected behavior or data loss. Ensure the peripheral
 * is properly deactivated before disabling its clock.
 *
 * @note Disabling unused peripheral clocks is a key method for reducing
 * power consumption in low-power applications.
 *
 * @see rcc_periph
 * @see rcc_periph_clock_enable()
 * @see rcc_periph_reset()
 */
void
rcc_periph_clock_disable(
  enum rcc_periph periph
);

void
rcc_backup_domain_reset(void);

/**
 * @brief Sets the clock source for the Real-Time Clock (RTC).
 *
 * @details Configures which clock source drives the RTC 
 * by writing to the RTCSEL bits in the RCC_BDCR register.
 * The RTC requires a low-speed clock source for accurate timekeeping.
 *
 * @param source The clock source to use for the RTC.
 *
 * @note The RTC clock source can only be changed when the backup domain
 * is reset. This function does not handle the backup domain reset.
 *
 * @note LSE provides the most accurate clock source for RTC applications,
 * while LSI is suitable for applications where absolute accuracy
 * is not critical.
 *
 * @see rcc_rtc_source
 * @see rcc_backup_domain_reset()
 */
void
rcc_set_rtc_source(
  enum rcc_rtc_source source
);

/**
 * @brief Enables the LSE bypass mode.
 *
 * @details Configures the low-speed external oscillator
 * (LSE) in bypass mode, allowing an external clock signal
 * to be used instead of a crystal. This mode should be used
 * when the device is driven by an external 32.768 kHz clock
 * source connected to the OSC32_IN pin.
 *
 * @note LSE must be disabled before changing the bypass setting.
 *
 * @note This function does not enable the LSE - use rcc_osc_enable(RCC_LSE)
 * after setting the bypass mode.
 *
 * @see rcc_lse_bypass_disable()
 * @see rcc_lse_bypass_is_enabled()
 */
void
rcc_lse_bypass_enable(void);

/**
 * @brief Disables the LSE bypass mode.
 *
 * @details Configures the low-speed external oscillator 
 * (LSE) to use a crystal resonator connected between the
 * OSC32_IN and OSC32_OUT pins.
 *
 * @note LSE must be disabled before changing the bypass setting.
 *
 * @see rcc_lse_bypass_enable()
 * @see rcc_lse_bypass_is_enabled()
 */
void
rcc_lse_bypass_disable(void);

/**
 * @brief Checks if LSE bypass mode is enabled.
 *
 * @details Reads the LSE bypass bit from the RCC 
 * backup domain control register (BDCR) to determine
 * if the low-speed external oscillator is configured
 * in bypass mode.
 *
 * @return Non-zero if LSE bypass is enabled, 0 if bypass is disabled.
 *
 * @see rcc_lse_bypass_enable()
 * @see rcc_lse_bypass_disable()
 */
u32
rcc_lse_bypass_is_enabled(void);

/**
 * @brief Checks if a specific reset flag is set.
 *
 * @details Reads the specified reset flag from the RCC 
 * Clock Control & Status Register (CSR) to determine what
 * caused the last system reset.
 *
 * @param flag The reset flag to check.
 *
 * @return Non-zero if the reset flag is set, 0 if the flag is not set.
 *
 * @note These flags indicate the source of the most recent reset event.
 * Multiple flags may be set if various reset sources occurred
 * simultaneously.
 *
 * @see rcc_reset_flag
 * @see rcc_reset_flags_clear()
 */
u32
rcc_reset_is_flag_set(
  enum rcc_reset_flag flag
);

/**
 * @brief Clears all reset flags.
 *
 * @details Clears all reset flags in the RCC Clock Control & Status
 * Register (CSR) by setting the RMVF bit. This should be done after
 * processing the reset source information.
 *
 * @note All reset flags are cleared simultaneously; it is not possible
 * to clear individual reset flags.
 *
 * @note Reset flags are preserved across system resets until explicitly
 * cleared using this function.
 *
 * @see rcc_reset_is_flag_set()
 */
void
rcc_reset_flags_clear(void);

/**
 * @brief Sets the PREDIV1 clock divider.
 * 
 * @details Configures the PREDIV1 clock divider that scales the 
 * input clock (HSE or PLL2) before it enters the PLL1.
 * 
 * @param prescaler Division factor to apply.
 * 
 * @note This setting affects the PLL input frequency and
 * should be configured before enabling the PLL.
 *
 * @note Changing this value while PLL is active may lead
 * to system instability.
 * 
 * @see rcc_prediv1_prescaler
 * @see rcc_set_prediv1_source()
 */
void
rcc_set_prediv1_prescaler(
  enum rcc_prediv1_prescaler prescaler
);

#if defined(STM32_RCC_PREDIV2)
/**
 * @brief Sets the PREDIV1 prescaler value.
 *
 * @details Configures the PREDIV1 division factor
 * which is used to divide the PLL input clock before 
 * it's fed into the main PLL.
 *
 * @param prescaler The division factor to apply.
 *
 * @note Changing this value affects all clock domains 
 * derived from the main PLL.
 *
 * @see rcc_prediv2_prescaler
 */
void
rcc_set_prediv2_prescaler(
  enum rcc_prediv2_prescaler prescaler
);
#endif

#if defined(STM32_RCC_OSC_PLL2)
/**
 * @brief Sets the PREDIV2 prescaler value.
 *
 * @details Configures the PREDIV2 division factor 
 * which is used to divide the input clock (typically HSE)
 * before it's fed into PLL2 and PLL3.
 *
 * @param prescaler The division factor to apply.
 *
 * @note Changing this value affects all clock domains 
 * derived from PLL2 and PLL3.
 *
 * @see rcc_set_pll2_multiplication_factor
 */
void
rcc_set_pll2_multiplication_factor(
  enum rcc_pll2_multiplication_factor factor
);
#endif

#if defined(STM32_RCC_OSC_PLL3)
/**
 * @brief Sets the PLL3 multiplication factor.
 *
 * @details Configures the multiplication factor 
 * for PLL3, which determines how much the PREDIV2 output
 * clock is multiplied to generate the PLL2 output clock.
 *
 * @param factor The multiplication factor to apply.
 *
 * @note PLL3 output is used in various peripheral clocks 
 * and can be selected as the PREDIV1 input clock
 * source for the main PLL.
 *
 * @see rcc_pll3_multiplication_factor
 * @see rcc_set_prediv2_prescaler
 */
void
rcc_set_pll3_multiplication_factor(
  enum rcc_pll3_multiplication_factor factor
);
#endif

#if defined(STM32_I2S2)
/**
 * @brief Sets the PREDIV1 clock source.
 * 
 * @details Configures the input clock source for 
 * the PREDIV1 divider, which can be either HSE or PLL2.
 *
 * @param source The clock source to use.
 *
 * @note The selected source is divided by the PREDIV1 prescaler 
 * before feeding into the main PLL.
 *
 * @see rcc_prediv1_source
 * @see rcc_set_prediv1_prescaler()
 */
void
rcc_set_prediv1_source(
  enum rcc_prediv1_source source
);
#endif

#if defined(STM32_I2S2)
/**
 * @brief Sets the I2S2 clock source.
 *
 * @details Configures the clock source for the I2S2 peripheral.
 *
 * @param source The clock source to use.
 *
 * @note Changing the I2S2 clock source may affect audio timing 
 * and should be done when the I2S2 peripheral is disabled.
 *
 * @see rcc_set_i2s3_source
 */
void
rcc_set_i2s2_source(
  enum rcc_i2s2_source source
);
#endif

#if defined(STM32_I2S3)
/**
 * @brief Sets the I2S3 clock source
 *
 * This function selects the clock source for the I2S3 peripheral.
 *
 * @param source The clock source to use.
 *
 * @note Changing the I2S3 clock source may affect audio timing
 * and should be done when the I2S3 peripheral is disabled.
 *
 * @see rcc_set_i2s2_source
 */
void
rcc_set_i2s3_source(
  enum rcc_i2s3_source source
);
#endif

#if defined(STM32_RCC_EXTENDED_REGS)

// TODO: Continue here -> Defines those enums.
// RM0091 stm32f0x1 / stm32f0x2 / stm32f0x8

#if defined(STM32_USART1)
void
rcc_set_usart1_clock_source(
  enum rcc_usart_clock_source source
);
#endif

#if defined(STM32_I2C1)
void
rcc_set_i2c1_clock_source(
  enum rcc_i2c1_clock_source source
);
#endif

#if defined(STM32_CEC)
void
rcc_set_cec_clock_source(
  enum rcc_hdmi_cec_clock_source source
);
#endif

#if defined(STM32_USB)
void
rcc_set_usb_clock_source(
  enum rcc_usb_clock_source source
);
#endif

#if defined(STM32_USART2)
void
rcc_set_usart2_clock_source(
  enum rcc_usart_clock_source source
);
#endif

#if defined(STM32_USART3)
void
rcc_set_usart3_clock_source(
  enum rcc_usart_clock_source source
);
#endif

#if defined(STM32_RCC_OSC_HSI14)
void
rcc_set_hsi14_trim(
  u32 value
);

u32
rcc_get_hsi14_calibration(void);
#endif

#if defined(STM32_RCC_OSC_HSI48)
u32
rcc_get_hsi48_calibration(void);
#endif

#endif

u32
rcc_get_apb2_clock(void);

u32
rcc_get_apb1_clock(void);

u32
rcc_get_ahb_clock(void);

u32
rcc_get_sysclock(void);

END_DECLARATIONS

#endif
