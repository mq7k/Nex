/**
 * @file gpio.h
 * @brief General-Purpose Input/Output (GPIO) interface.
 *
 * @details This header file provides function prototypes and 
 * definitions for configuring and controlling GPIO ports and pins.
 */
#ifndef STM32_DRIVER_GPIO_H
#define STM32_DRIVER_GPIO_H

#include "synapse/specs.h"
#include "synapse/common/util/common.h"
#include "libcom/types.h"

/**
 * Supports:
 *  - STM32F1x
 */

BEGIN_DECLARATIONS

/**
 * @brief GPIO (General-Purpose Input/Output) registers map.
 *
 * @details Represents the memory-mapped registers of a GPIO port. 
 * Each port (GPIOA, GPIOB, etc.) has a dedicated register set 
 * that controls pin configuration, input/output states, and locking 
 * mechanisms.
 *
 * @note GPIO registers are 32-bit and control up to 16 pins per port.
 */
struct gpio_registers_map
{
  /**
   * @brief GPIO_CRL - Port config register low
   *
   * @details
   * Offset: 0x0
   * <br>
   * Reset: 0x4444 4444
   */
  u32 CRL;

  /**
   * @brief GPIO_CRL - Port config register low
   *
   * @details
   * Offset: 0x4
   * <br>
   * Reset: 0x4444 4444
   */
  u32 CRH;

  /**
   * @brief GPIO_IDR - Port input data register
   *
   * @details
   * Offset: 0x8
   * <br>
   * Reset: 0x0000 xxxx
   */
  u32 IDR;

  /**
   * @brief GPIO_ODR - Port output data register
   *
   * @details
   * Offset: 0xc
   * <br>
   * Reset: 0x0000 0000
   */
  u32 ODR;

  /**
   * @brief GPIO_BSRR - Port set/reset register
   *
   * @details
   * Offset: 0x10
   * <br>
   * Reset: 0x0000 0000
   */
  u32 BSRR;

  /**
   * @brief GPIO_BRR - Port bit reset register
   *
   * @details
   * Offset: 0x14
   * <br>
   * Reset: 0x0000 0000
   */
  u32 BRR;

  /**
   * @brief GPIO_LCKR - Port configuration lock register
   *
   * @details
   * Offset: 0x18
   * <br>
   * Reset: 0x0000 0000
   */
  u32 LCKR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum gpio_cr_mode : u32
{
  GPIO_CR_MODE_INPUT = 0b00,
  GPIO_CR_MODE_OUTPUT_10MHZ = 0b01,
  GPIO_CR_MODE_OUTPUT_2MHZ = 0b10,
  GPIO_CR_MODE_OUTPUT_50MHZ = 0b11
};

enum gpio_cr_cnf : u32
{
  GPIO_CR_CNF_INPUT_ANALOG = 0b00,
  GPIO_CR_CNF_INPUT_FLOATING = 0b01,
  GPIO_CR_CNF_INPUT_PULLUP_PULLDOWN = 0b10,

  GPIO_CR_CNF_OUTPUT_PUSHPULL = 0b00,
  GPIO_CR_CNF_OUTPUT_OPEN_DRAIN = 0b01,
  GPIO_CR_CNF_ALTFN_PUSHPULL = 0b10,
  GPIO_CR_CNF_ALTFN_OPEN_DRAIN = 0b11
};

#define GPIO_ODR_MASK (0xffffu)

enum gpio_lckr : u32
{
  GPIO_LCKR_LCKK = (1 << 16)
};

enum gpio_pin : u32
{
  GPIO0 = (1 << 0),
  GPIO1 = (1 << 1),
  GPIO2 = (1 << 2),
  GPIO3 = (1 << 3),
  GPIO4 = (1 << 4),
  GPIO5 = (1 << 5),
  GPIO6 = (1 << 6),
  GPIO7 = (1 << 7),
  GPIO8 = (1 << 8),
  GPIO9 = (1 << 9),
  GPIO10 = (1 << 10),
  GPIO11 = (1 << 11),
  GPIO12 = (1 << 12),
  GPIO13 = (1 << 13),
  GPIO14 = (1 << 14),
  GPIO15 = (1 << 15)
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

/**
 * @brief GPIO port operating modes.
 *
 * @details Defines the mode of operation for GPIO pins. The mode 
 * determines whether a pin functions as an input or output, as well 
 * as the maximum output speed for digital output configurations.
 *
 * @note The mode must be combined with a configuration value 
 * (`gpio_port_config`) to fully define a pin's behavior.
 *
 * @see gpio_set_mode()
 * @see enum gpio_port_config
 */
enum gpio_port_mode
{
  GPIO_MODE_INPUT,
  GPIO_MODE_OUTPUT_10MHZ,
  GPIO_MODE_OUTPUT_2MHZ,
  GPIO_MODE_OUTPUT_50MHZ
};

/**
 * @brief GPIO port configuration options.
 *
 * @details Defines the electrical behavior of GPIO pins, such as 
 * analog input, floating input, pull-up/pull-down resistors, and 
 * push-pull or open-drain output modes.
 *
 * @note The configuration value must be combined with a mode 
 * (`gpio_port_mode`) to fully define a pin's function.
 *
 * @see gpio_set_mode()
 * @see gpio_port_mode
 */
enum gpio_port_config
{
  GPIO_CNF_INPUT_ANALOG,
  GPIO_CNF_INPUT_FLOATING,
  GPIO_CNF_INPUT_PULL_UPDOWN,
  
  GPIO_CNF_OUTPUT_PUSHPULL,
  GPIO_CNF_OUTPUT_OPEN_DRAIN,
  GPIO_CNF_ALTFN_PUSHPULL,
  GPIO_CNF_ALTFN_OPEN_DRAIN
};

#if defined(STM32_GPIOA)
  extern volatile struct gpio_registers_map* GPIOA;
#endif

#if defined(STM32_GPIOB)
  extern volatile struct gpio_registers_map* GPIOB;
#endif

#if defined(STM32_GPIOC)
  extern volatile struct gpio_registers_map* GPIOC;
#endif

#if defined(STM32_GPIOD)
  extern volatile struct gpio_registers_map* GPIOD;
#endif

#if defined(STM32_GPIOE)
  extern volatile struct gpio_registers_map* GPIOE;
#endif

#if defined(STM32_GPIOF)
  extern volatile struct gpio_registers_map* GPIOF;
#endif

#if defined(STM32_GPIOG)
  extern volatile struct gpio_registers_map* GPIOG;
#endif

/**
 * @brief Configures multiple GPIO pins on a port.
 *
 * @details Sets the mode and configuration for the specified 
 * pins of a given GPIO port. This function allows bulk 
 * configuration of multiple pins simultaneously.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of pins to configure (use bitwise OR for multiple pins).
 * @param mode The GPIO mode (input/output with max speed).
 * @param config The GPIO configuration (push-pull, open-drain, etc.).
 *
 * @note The mode and configuration must be chosen carefully based 
 * on the intended function of the pins.
 *
 * @see gpio_setup_port_pin()
 * @see enum gpio_port_mode
 * @see enum gpio_port_config
 */
void
gpio_setup_port(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_port_mode mode,
  enum gpio_port_config config
);

/**
 * @brief Configures a single GPIO pin.
 *
 * @details Sets the mode and configuration for a specific pin 
 * on a given GPIO port.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pin The pin number to configure.
 * @param mode The GPIO mode (input/output with max speed).
 * @param config The GPIO configuration (push-pull, open-drain, etc.).
 *
 * @note This function is useful for configuring individual pins when 
 * bulk configuration is not required.
 *
 * @note This function is more efficient for setting a single pin compared
 * to gpio_setup_port().
 *
 * @warning Using multiple pins as input to this function would result
 * in unwanted behaviors.
 *
 * @see gpio_setup_port()
 * @see enum gpio_port_mode
 * @see enum gpio_port_config
 */
void
gpio_setup_port_pin(
  volatile struct gpio_registers_map* gpio,
  enum gpio_pin pin,
  enum gpio_port_mode mode,
  enum gpio_port_config config
);

/**
 * @brief Reads the current state of all pins in a GPIO port.
 *
 * @details Returns the 16-bit value representing the state of 
 * all GPIO pins in the specified port. Each bit corresponds to 
 * the logical level (0 or 1) of a pin.
 *
 * @param gpio Pointer to the GPIO port registers.
 *
 * @return 16-bit value representing the state of all pins.
 *
 * @see gpio_pin_read()
 */
u32
gpio_port_read(
  volatile struct gpio_registers_map* gpio
);

/**
 * @brief Reads the state of specific GPIO pins.
 *
 * @details Returns the logical state of the specified pins 
 * in a GPIO port. This function allows selective reading 
 * of individual or multiple pins.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of the pins to read (bitwise OR for multiple pins).
 *
 * @return A bitmask indicating the state of the selected pins.
 *
 * @note Use bitwise operations to extract the state of individual pins.
 *
 * @see gpio_port_read()
 */
u32
gpio_pin_read(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

/**
 * @brief Checks if specified GPIO pins are set high.
 *
 * @details Reads the current state of the specified pins and 
 * returns a bitmask indicating whether they are set to a high 
 * logic level (1).
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of the pins to check.
 *
 * @return A bitmask where set bits (1) indicate that the 
 * corresponding pins are high.
 *
 * @note Use bitwise operations to extract the state of individual pins.
 *
 * @see gpio_pin_read()
 */
u32
gpio_is_pin_set_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

/**
 * @brief Sets the entire port output status.
 *
 * @details Writes a 16-bit value to the GPIO port output 
 * register, setting all pin states at once.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param port_status 16-bit value representing the desired 
 * pin states (1 for high, 0 for low).
 *
 * @note This function affects all pins in the port. Use with caution.
 *
 * @see gpio_set_pin_high()
 * @see gpio_set_pin_low()
 */
void
gpio_set_port_status(
  volatile struct gpio_registers_map* gpio,
  u32 port_status
);

/**
 * @brief Sets the specified GPIO pins high.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of the pins to set high.
 *
 * @see gpio_set_pin_low()
 * @see gpio_pin_toggle()
 */
void
gpio_set_pin_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

/**
 * @brief Sets the specified GPIO pins low.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of the pins to set low.
 *
 * @see gpio_set_pin_high()
 * @see gpio_pin_toggle()
 */
void
gpio_set_pin_low(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

/**
 * @brief Toggles the state of the specified GPIO pins.
 *
 * @details Reads the current state of the selected pins and 
 * inverts them (high → low, low → high).
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of the pins to toggle.
 *
 * @see gpio_set_pin_high()
 * @see gpio_set_pin_low()
 */
void
gpio_pin_toggle(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

/**
 * @brief Resets the specified GPIO pins.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of the pins to reset.
 *
 * @note This function is equivalent to gpio_set_pin_low().
 *
 * @see gpio_set_pin_low()
 */
void
gpio_pin_reset(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

/**
 * @brief Locks the configuration of specified GPIO pins.
 *
 * @details Prevents further modification of the selected pins' 
 * mode and configuration registers until the next reset.
 *
 * @param gpio Pointer to the GPIO port registers.
 * @param pins Bitmask of the pins to lock.
 *
 * @return Returns 1 if the lock was successful, otherwise 0.
 *
 * @note Once locked, the pin configuration cannot be changed until 
 * a system reset or power cycle occurs.
 *
 * @see gpio_setup_port_pin()
 */
u32
gpio_port_lock_pins(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

void
bar(void);

END_DECLARATIONS

#endif
