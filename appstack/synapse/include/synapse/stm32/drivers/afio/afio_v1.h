/**
 * @file afio.h
 * @brief Alternate Function I/O (AFIO) interface.
 *
 * @details This header file provides function prototypes and 
 * definitions for configuring alternate pin functions, peripheral 
 * remapping, and system debug interface settings.
 *
 * @note AFIO remapping should be performed before configuring 
 * GPIO pins for the affected peripherals.
 */
#ifndef STM32_DRIVER_AFIO_H
#define STM32_DRIVER_AFIO_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"
#include "synapse/stm32/periph/gpio.h"

BEGIN_DECLARATIONS

/**
 * @brief AFIO (Alternate Function I/O) registers memory map.
 *
 * @details Represents the memory layout of the AFIO peripheral,
 * which is responsible for configuring alternate function
 * remapping, external interrupt sources, and debugging pin
 * configurations.
 *
 * @note The exact structure fields should be defined based 
 * on the MCU's reference manual.
 */
struct afio_registers_map
{
  /**
   * @brief AFIO_EVCR - Event control register
   *
   * @details
   * Offset: 0x0
   * <br>
   * Reset: 0x0000 0000
   */
  u32 EVCR;

  /**
   * @brief AFIO_MAPR - AF remap and debug I/O configuration register
   *
   * @details
   * Offset: 0x4
   * <br>
   * Reset: 0x0000 0000
   */
  u32 MAPR;

  /**
   * @brief AFIO_EXTICRx - External interrupt configuration register
   *
   * @details
   * Offset: 0x8, 0xc, 0x10, 0x14
   * <br>
   * Reset: 0x0000
   */
  u32 EXTICR[4];

  /**
   * @brief AFIO_MAPR2 - AF remap and debug I/O configuration register2
   *
   * @details
   * Offset: 0x1c
   * <br>
   * Reset: 0x0000 0000
   */
  u32 MAPR2;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum afio_evcr : u32
{
  AFIO_EVCR_EVOE = (1 << 7)
};

/* Bits[3:0] */
#define AFIO_EVCR_PIN_SHIFT (0)
#define AFIO_EVCR_PIN_MASK (0xfu)

enum afio_evcr_pin : u32
{
  AFIO_EVCR_PIN_Px0 = 0b0000,
  AFIO_EVCR_PIN_Px1 = 0b0001,
  AFIO_EVCR_PIN_Px2 = 0b0010,
  AFIO_EVCR_PIN_Px3 = 0b0011,
  AFIO_EVCR_PIN_Px4 = 0b0100,
  AFIO_EVCR_PIN_Px5 = 0b0101,
  AFIO_EVCR_PIN_Px6 = 0b0110,
  AFIO_EVCR_PIN_Px7 = 0b0111,
  AFIO_EVCR_PIN_Px8 = 0b1000,
  AFIO_EVCR_PIN_Px9 = 0b1001,
  AFIO_EVCR_PIN_Px10 = 0b1010,
  AFIO_EVCR_PIN_Px11 = 0b1011,
  AFIO_EVCR_PIN_Px12 = 0b1100,
  AFIO_EVCR_PIN_Px13 = 0b1101,
  AFIO_EVCR_PIN_Px14 = 0b1110,
  AFIO_EVCR_PIN_Px15 = 0b1111
};

/* Bits[6:4] */
#define AFIO_EVCR_PORT_SHIFT (4)
#define AFIO_EVCR_PORT_MASK (0x7u)

enum afio_evcr_port : u32
{
  AFIO_EVCR_PORT_PA = 0b000,
  AFIO_EVCR_PORT_PB = 0b001,
  AFIO_EVCR_PORT_PC = 0b010,
  AFIO_EVCR_PORT_PD = 0b011,
  AFIO_EVCR_PORT_PE = 0b100
};

enum afio_mapr : u32
{
  // Shared
  AFIO_MAPR_SPI1_REMAP = (1 << 0),
  AFIO_MAPR_I2C1_REMAP = (1 << 1),
  AFIO_MAPR_USART1_REMAP = (1 << 2),
  AFIO_MAPR_USART2_REMAP = (1 << 3),
  AFIO_MAPR_TIM4_REMAP = (1 << 12),
  AFIO_MAPR_PD01_REMAP = (1 << 15),
  AFIO_MAPR_TIM5CH4_IREMAP = (1 << 16),

  // Density only
  AFIO_MAPR_ADC1_ETRGINJ_REMAP = (1 << 17),
  AFIO_MAPR_ADC1_ETRGREG_REMAP = (1 << 18),
  AFIO_MAPR_ADC2_ETRGINJ_REMAP = (1 << 19),
  AFIO_MAPR_ADC2_ETRGREG_REMAP = (1 << 20),

  // Connectivity only
  AFIO_MAPR_ETH_REMAP = (1 << 21),
  AFIO_MAPR_CAN2_REMAP = (1 << 22),
  AFIO_MAPR_MII_RMII_SEL = (1 << 23),
  AFIO_MAPR_SPI3_REMAP = (1 << 28),
  AFIO_MAPR_TIM2ITR1_IREMAP = (1 << 29),
  AFIO_MAPR_PTP_PPS_REMAP = (1 << 30)
};

/* Bits[5:4] */
#define AFIO_MAPR_USART3_REMAP_SHIFT (4)
#define AFIO_MAPR_USART3_REMAP_MASK (0x3u)

enum afio_mapr_usart3_remap : u32
{
  AFIO_MAPR_USART3_REMAP_NOREMAP = 0b00,
  AFIO_MAPR_USART3_REMAP_PARTIAL_REMAP = 0b01,
  AFIO_MAPR_USART3_REMAP_FULL_REMAP = 0b11
};

/* Bits[7:6] */
#define AFIO_MAPR_TIM1_REMAP_SHIFT (6)
#define AFIO_MAPR_TIM1_REMAP_MASK (0x3u)

enum afio_mapr_tim1_remap : u32
{
  AFIO_MAPR_TIM1_REMAP_NOREMAP = 0b00,
  AFIO_MAPR_TIM1_REMAP_PARTIAL_REMAP = 0b01,
  AFIO_MAPR_TIM1_REMAP_FULL_REMAP = 0b11
};

/* Bits[9:8] */
#define AFIO_MAPR_TIM2_REMAP_SHIFT (8)
#define AFIO_MAPR_TIM2_REMAP_MASK (0x3u)

enum afio_mapr_tim2_remap : u32
{
  AFIO_MAPR_TIM2_REMAP_NOREMAP = 0b00,
  AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP1 = 0b01,
  AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP2 = 0b10,
  AFIO_MAPR_TIM2_REMAP_FULL_REMAP = 0b11
};

/* Bits[11:10] */
#define AFIO_MAPR_TIM3_REMAP_SHIFT (10)
#define AFIO_MAPR_TIM3_REMAP_MASK (0x3u)

enum afio_mapr_tim3_remap : u32
{
  AFIO_MAPR_TIM3_REMAP_NOREMAP = 0b00,
  AFIO_MAPR_TIM3_REMAP_PARTIAL_REMAP = 0b10,
  AFIO_MAPR_TIM3_REMAP_FULL_REMAP = 0b11
};

/* Bits[14:13] */
#define AFIO_MAPR_CAN1_REMAP_SHIFT (13)
#define AFIO_MAPR_CAN1_REMAP_MASK (0x3u)

enum afio_mapr_can1_remap : u32
{
  AFIO_MAPR_CAN1_REMAP_1 = 0b00,
  AFIO_MAPR_CAN1_REMAP_2 = 0b10,
  AFIO_MAPR_CAN1_REMAP_3 = 0b11,
};

/* Bits[26:24] */
#define AFIO_MAPR_SWJ_CFG_SHIFT (24)
#define AFIO_MAPR_SWJ_CFG_MASK (0x7u)

enum afio_mapr_swj_cfg : u32
{
  AFIO_MAPR_SWJ_CFG_FULL_SWJ = 0b000,
  AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_NJTRST = 0b001,
  AFIO_MAPR_SWJ_CFG_NOJTAG = 0b010,
  AFIO_MAPR_SWJ_CFG_NOJTAG_NOSWDP = 0b100
};

enum afio_mapr2 : u32
{
  AFIO_MAPR2_TIM9_REMAP = (1 << 5),
  AFIO_MAPR2_TIM10_REMAP = (1 << 6),
  AFIO_MAPR2_TIM11_REMAP = (1 << 7),
  AFIO_MAPR2_TIM13_REMAP = (1 << 8),
  AFIO_MAPR2_TIM14_REMAP = (1 << 9),
  AFIO_MAPR2_FSMC_NADV = (1 << 10)
};

#define AFIO_EXTICR_EXTI_MASK (0xfu)

enum afio_exticr_exti : u32
{
  AFIO_EXTICR_EXTI_PA = 0b0000,
  AFIO_EXTICR_EXTI_PB = 0b0001,
  AFIO_EXTICR_EXTI_PC = 0b0010,
  AFIO_EXTICR_EXTI_PD = 0b0011,
  AFIO_EXTICR_EXTI_PE = 0b0100
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

/**
 * @brief Available AFIO (Alternate Function I/O) pins.
 *
 * @details Represents the GPIO pins that can be configured for 
 * alternate functions using the AFIO peripheral. These pins 
 * allow remapping of peripheral functions such as USART, SPI, 
 * I2C, timers, and external interrupts.
 *
 * @note The specific remapping and functionality of each pin 
 * depends on the MCU model and its AFIO configuration.
 */
enum afio_pin
{
  AFIO_PIN0,
  AFIO_PIN1,
  AFIO_PIN2,
  AFIO_PIN3,
  AFIO_PIN4,
  AFIO_PIN5,
  AFIO_PIN6,
  AFIO_PIN7,
  AFIO_PIN8,
  AFIO_PIN9,
  AFIO_PIN10,
  AFIO_PIN11,
  AFIO_PIN12,
  AFIO_PIN13,
  AFIO_PIN14,
  AFIO_PIN15
};

/**
 * @brief Available AFIO (Alternate Function I/O) ports.
 *
 * @details Represents the GPIO ports that can be used for 
 * alternate function remapping through the AFIO peripheral.
 * Each port consists of multiple pins that can be configured 
 * for different peripheral functions such as USART, SPI, I2C, 
 * timers, and external interrupts.
 *
 * @note The availability of these ports depends on the specific 
 * MCU model. Some MCUs may not support all ports.
 *
 * @note The EVENTOUT signal output capability is not extended 
 * to ports PF and PG.
 */
enum afio_port
{
  AFIO_PORTA,
  AFIO_PORTB,
  AFIO_PORTC,
  AFIO_PORTD,
  AFIO_PORTE
};

/**
 * @brief Available remapping configurations for peripheral functions.
 *
 * @details Defines the alternate function remapping options 
 * available through the AFIO (Alternate Function I/O) peripheral.
 * These configurations allow flexible pin assignments for various 
 * peripherals, helping to optimize PCB layout and prevent conflicts 
 * with other peripherals.
 *
 * @note Some remapping options may not be available on all MCU models.
 * Connectivity line devices provide additional remapping options.
 */
enum afio_remap
{
  AFIO_REMAP_SPI1,
  AFIO_REMAP_I2C1,
  AFIO_REMAP_USART1,
  AFIO_REMAP_USART2,
  AFIO_REMAP_TIM4,
  AFIO_REMAP_PD01,
  AFIO_REMAP_TIM5_CH4,
  AFIO_REMAP_ADC1_ETRGINJ,
  AFIO_REMAP_ADC1_ETRGREG,
  AFIO_REMAP_ADC2_ETRGINJ,
  AFIO_REMAP_ADC2_ETRGREG,

  /**
   * @note Available only in connectivity devices.
   */
  AFIO_REMAP_TIM9,

  /**
   * @note Available only in connectivity devices.
   */
  AFIO_REMAP_TIM10,

  /**
   * @note Available only in connectivity devices.
   */
  AFIO_REMAP_TIM11,

  /**
   * @note Available only in connectivity devices.
   */
  AFIO_REMAP_TIM13,

  /**
   * @note Available only in connectivity devices.
   */
  AFIO_REMAP_TIM14,

  /**
   * @note Available only in connectivity devices.
   */
  AFIO_REMAP_FSMC_NADV
};

/**
 * @brief Available usart3 remap configuration.
 */
enum afio_remap_usart3
{
  AFIO_REMAP_USART3_NOREMAP,
  AFIO_REMAP_USART3_PARTIAL,
  AFIO_REMAP_USART3_FULL
};

/**
 * @brief Available tim1 remap configuration.
 */
enum afio_remap_tim1
{
  AFIO_REMAP_TIM1_NOREMAP,
  AFIO_REMAP_TIM1_PARTIAL,
  AFIO_REMAP_TIM1_FULL
};

/**
 * @brief Available tim2 remap configuration.
 */
enum afio_remap_tim2
{
  AFIO_REMAP_TIM2_NOREMAP,
  AFIO_REMAP_TIM2_PARTIAL1,
  AFIO_REMAP_TIM2_PARTIAL2,
  AFIO_REMAP_TIM2_FULL
};

/**
 * @brief Available tim3 remap configuration.
 */
enum afio_remap_tim3
{
  AFIO_REMAP_TIM3_NOREMAP,
  AFIO_REMAP_TIM3_PARTIAL,
  AFIO_REMAP_TIM3_FULL
};

/**
 * @brief Available can remap configuration.
 */
enum afio_remap_can
{
  AFIO_REMAP_CAN_1,
  AFIO_REMAP_CAN_2,
  AFIO_REMAP_CAN_3
};

/**
 * @brief Available swj remap configuration.
 */
enum afio_remap_swj
{
  AFIO_REMAP_SWJ_FULL,
  AFIO_REMAP_SWJ_FULL_NO_NJTRST,
  AFIO_REMAP_SWJ_NOJTAG,
  AFIO_REMAP_SWJ_NOJTAG_NOSWDP
};

extern volatile struct afio_registers_map* AFIO;

void
afio_set_eventout_port(
  enum afio_port port
);

void
afio_set_eventout_pin(
  enum afio_pin pin
);

/**
 * @brief Configures a GPIO pin to output
 * the EVENTOUT signal.
 *
 * @details Routes the EVENTOUT signal to a specific
 * GPIO pin through the Alternate Function I/O (AFIO)
 * controller. The EVENTOUT signal can be used to trigger
 * external devices or for debugging purposes when specific
 * internal events occur.
 *
 * @param port The GPIO port to output the EVENTOUT signal.
 * @param pin The specific pin on the selected port.
 *
 * @see enum afio_port
 * @see enum afio_pin
 */
void
afio_set_eventout_gpio(
  enum afio_port port,
  enum afio_pin pin
);

/**
 * @brief Enables the EVENTOUT signal output.
 *
 * @details Activates the EVENTOUT functionality 
 * in the Alternate Function I/O (AFIO) controller.
 * When enabled, the system will output the configured 
 * event signal on the previously selected GPIO pin.
 *
 * @note The EVENTOUT signal remains disabled until this
 * function is called, even if an output pin and event source
 * have been configured. This allows for complete setup before 
 * activating the output.
 *
 * @see afio_set_eventout_gpio()
 * @see afio_eventout_disable()
 */
void
afio_eventout_enable(void);

/**
 * @brief Disables the EVENTOUT signal output.
 *
 * @see afio_eventout_enable()
 */
void
afio_eventout_disable(void);

/**
 * @brief Enables a specific GPIO pin remapping configuration.
 *
 * @details Activates an alternate function mapping for GPIO pins through the AFIO
 * controller. Pin remapping allows peripherals to use alternate sets of GPIO pins,
 * providing flexibility in PCB layout and enabling multiple peripherals to coexist
 * on a single device.
 *
 * @param remap The remapping configuration to enable
 *
 * @see afio_remap_disable()
 * @see enum afio_remap
 */
void
afio_remap_enable(
  enum afio_remap remap
);

/**
 * @brief Disables a specific GPIO pin remapping configuration.
 *
 * @see afio_remap_disable()
 * @see enum afio_remap
 */
void
afio_remap_disable(
  enum afio_remap remap
);

/**
 * @brief Configures the pin remapping for USART3.
 *
 * @details Configures the alternate pin mapping for the
 * USART3 peripheral. USART3 supports multiple pin mapping 
 * options, providing flexibility in PCB layout and enabling
 * GPIO pin sharing among different peripherals.
 *
 * @param remap The USART3 remapping configuration to apply.
 *
 * @note The remapping must be configured before enabling USART3
 * to take effect. After remapping, the corresponding GPIO 
 * pins must be configured in alternate function mode before
 * enabling USART3.
 *
 * @see afio_remap_enable()
 * @see enum afio_remap_usart3
 */
void
afio_set_usart3_remap(
  enum afio_remap_usart3 remap
);

/**
 * @brief Configures the pin remapping for TIM1.
 *
 * @details Sets the alternate pin mapping for the TIM1 peripheral.
 * This allows for flexible PCB routing and enables shared use of GPIO 
 * pins with other peripherals.
 *
 * @param remap The TIM1 remapping configuration to apply.
 *
 * @note The remapping must be configured before enabling TIM1.
 * After remapping, the corresponding GPIO pins must be configured 
 * in alternate function mode.
 *
 * @see afio_remap_enable()
 * @see enum afio_remap_tim1
 */
void
afio_set_tim1_remap(
  enum afio_remap_tim1 remap
);

/**
 * @brief Configures the pin remapping for TIM2.
 *
 * @details Sets the alternate pin mapping for the TIM2 peripheral.
 * This allows TIM2 to use different GPIO pin configurations, providing 
 * flexibility in PCB design.
 *
 * @param remap The TIM2 remapping configuration to apply.
 *
 * @note The remapping must be configured before enabling TIM2.
 * GPIO pins must be set to alternate function mode after remapping.
 *
 * @see afio_remap_enable()
 * @see enum afio_remap_tim2
 */
void
afio_set_tim2_remap(
  enum afio_remap_tim2 remap
);

/**
 * @brief Configures the pin remapping for TIM3.
 *
 * @details Sets the alternate pin mapping for the TIM3 peripheral.
 * Different remapping options allow the use of various GPIO pins
 * to accommodate different board layouts.
 *
 * @param remap The TIM3 remapping configuration to apply.
 *
 * @note The remapping must be configured before enabling TIM3.
 * GPIO pins must be set to alternate function mode after remapping.
 *
 * @see afio_remap_enable()
 * @see enum afio_remap_tim3
 */
void
afio_set_tim3_remap(
  enum afio_remap_tim3 remap
);

/**
 * @brief Configures the pin remapping for CAN1.
 *
 * @details Sets the alternate pin mapping for the CAN1 peripheral.
 * CAN1 has multiple possible pin configurations, allowing for flexible
 * hardware design.
 *
 * @param remap The CAN1 remapping configuration to apply.
 *
 * @note The remapping must be set before enabling CAN1.
 * GPIO pins used for CAN1 should be set to alternate function mode.
 *
 * @see afio_remap_enable()
 * @see enum afio_remap_can
 */
void
afio_set_can1_remap(
  enum afio_remap_can remap
);

/**
 * @brief Configures the Serial Wire JTAG (SWJ) remapping.
 *
 * @details Modifies the debug interface configuration by remapping
 * Serial Wire (SW) and JTAG pins. This allows freeing up debug pins 
 * for general-purpose use when full JTAG functionality is not needed.
 *
 * @param remap The SWJ remapping configuration to apply.
 *
 * @note Disabling JTAG or SWD can make debugging impossible.
 * Use caution when remapping these pins.
 *
 * @see afio_remap_enable()
 * @see enum afio_remap_swj
 */
void
afio_set_swj_remap(
  enum afio_remap_swj remap
);

/**
 * @brief Configures the external interrupt source.
 *
 * @details Maps an external GPIO pin to an EXTI line,
 * allowing it to be used as an interrupt source.
 *
 * @param port The GPIO port that contains the external interrupt source.
 * @param pin The GPIO pin to be used as an external interrupt source.
 *
 * @note Only one pin per EXTI line can be assigned at a time.
 * Changing the mapping may require clearing pending EXTI flags.
 *
 * @see enum afio_port
 * @see enum afio_pin
 */
void
afio_set_external_interrupt_source(
  enum afio_port port,
  enum afio_pin pin
);

BEGIN_DECLARATIONS

#endif
