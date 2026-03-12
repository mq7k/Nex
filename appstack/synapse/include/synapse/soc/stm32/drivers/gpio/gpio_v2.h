#ifndef STM32_DRIVER_GPIO_H
#define STM32_DRIVER_GPIO_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F4x
 */

BEGIN_DECLARATIONS

struct gpio_registers_map
{
  u32 MODER;
  u32 OTYPER;
  u32 OSPEEDR;
  u32 PUPDR;
  u32 IDR;
  u32 ODR;
  u32 BSRR;
  u32 LCKR;
  u32 AFRL;
  u32 AFRH;
};

// Core
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

#define GPIO_MODER_MASK (0x3)
#define GPIO_MODER_STRIDE (2)

enum gpio_moder : u32
{
  GPIO_MODER_INPUT = 0b00,
  GPIO_MODER_OUTPUT = 0b01,
  GPIO_MODER_ALTFN = 0b10,
  GPIO_MODER_ANALOG = 0b11
};

enum gpio_otyper : u32
{
  GPIO_OTYPER_OT0 = (1 << 0),
  GPIO_OTYPER_OT1 = (1 << 1),
  GPIO_OTYPER_OT2 = (1 << 2),
  GPIO_OTYPER_OT3 = (1 << 3),
  GPIO_OTYPER_OT4 = (1 << 4),
  GPIO_OTYPER_OT5 = (1 << 5),
  GPIO_OTYPER_OT6 = (1 << 6),
  GPIO_OTYPER_OT7 = (1 << 7),
  GPIO_OTYPER_OT8 = (1 << 8),
  GPIO_OTYPER_OT9 = (1 << 9),
  GPIO_OTYPER_OT10 = (1 << 10),
  GPIO_OTYPER_OT11 = (1 << 11),
  GPIO_OTYPER_OT12 = (1 << 12),
  GPIO_OTYPER_OT13 = (1 << 13),
  GPIO_OTYPER_OT14 = (1 << 14),
  GPIO_OTYPER_OT15 = (1 << 15)
};

#define GPIO_OSPEEDR_MASK (0x3) 
#define GPIO_OSPEEDR_STRIDE (2)

enum gpio_ospeedr : u32
{
  GPIO_OSPEEDR_LOW_SPEED = 0b00,
  GPIO_OSPEEDR_MEDIUM_SPEED = 0b01,

#if defined(STM32_GPIO_SPEED_HIGH)
  GPIO_OSPEEDR_HIGH_SPEED = 0b10,

#if defined(STM32_GPIO_VERY_HIGH_SPEED)
  GPIO_OSPEEDR_VERY_HIGH_SPEED = 0b11
#endif

#elif defined(STM32_GPIO_SPEED_FAST)
  GPIO_OSPEEDR_FAST_SPEED = 0b10,
  GPIO_OSPEEDR_HIGH_SPEED = 0b11
#endif
};

#define GPIO_PUPDR_MASK (0x3)
#define GPIO_PUPDR_STRIDE (2)

enum gpio_pupdr : u32
{
  GPIO_PUPDR_NO_PULLUPDOWN = 0b00,
  GPIO_PUPDR_PULLUP = 0b01,
  GPIO_PUPDR_PULLDOWN = 0b010
};

enum gpio_lckr : u32
{
  GPIO_LCKR_LCKK = (1 << 16)
};

enum gpio_afr_altfn : u32
{
  GPIO_AFR_ALTFN0 = 0b0000,
  GPIO_AFR_ALTFN1 = 0b0001, 
  GPIO_AFR_ALTFN2 = 0b0010,
  GPIO_AFR_ALTFN3 = 0b0011,
  GPIO_AFR_ALTFN4 = 0b0100,
  GPIO_AFR_ALTFN5 = 0b0101,
  GPIO_AFR_ALTFN6 = 0b0110,
  GPIO_AFR_ALTFN7 = 0b0111,
  GPIO_AFR_ALTFN8 = 0b1000,
  GPIO_AFR_ALTFN9 = 0b1001,
  GPIO_AFR_ALTFN10 = 0b1010,
  GPIO_AFR_ALTFN11 = 0b1011,
  GPIO_AFR_ALTFN12 = 0b1100,
  GPIO_AFR_ALTFN13 = 0b1101,
  GPIO_AFR_ALTFN14 = 0b1110,
  GPIO_AFR_ALTFN15 = 0b1111
};

#define GPIO_AFRL_MASK (0xf)
#define GPIO_AFRL_STRIDE (4)

#define GPIO_AFRH_MASK (0xf)
#define GPIO_AFRH_STRIDE (4)

// API

enum gpio_mode
{
  GPIO_MODE_INPUT,
  GPIO_MODE_OUTPUT,
  GPIO_MODE_ALTFN,
  GPIO_MODE_ANALOG
};

enum gpio_speed
{
  GPIO_SPEED_LOW,
  GPIO_SPEED_MEDIUM,

#if defined(STM32_GPIO_SPEED_HIGH)
  GPIO_SPEED_HIGH,

#if defined(STM32_GPIO_VERY_HIGH_SPEED)
  GPIO_SPEED_VERY_HIGH
#endif
#elif defined(STM32_GPIO_SPEED_FAST)
  GPIO_SPEED_FAST,
  GPIO_SPEED_HIGH
#endif
};

enum gpio_output_type
{
  GPIO_OUTPUT_TYPE_PUSHPULL,
  GPIO_OUTPUT_TYPE_OPEN_DRAIN
};

enum gpio_io_resistor
{
  GPIO_IO_RESISTOR_NO_PULLUPDOWN,
  GPIO_IO_RESISTOR_PULLUP,
  GPIO_IO_RESISTOR_PULLDOWN
};

enum gpio_altfn
{
  GPIO_ALTFN0,
  GPIO_ALTFN1,
  GPIO_ALTFN2,
  GPIO_ALTFN3,
  GPIO_ALTFN4,
  GPIO_ALTFN5,
  GPIO_ALTFN6,
  GPIO_ALTFN7,
  GPIO_ALTFN8,
  GPIO_ALTFN9,
  GPIO_ALTFN10,
  GPIO_ALTFN11,
  GPIO_ALTFN12,
  GPIO_ALTFN13,
  GPIO_ALTFN14,
  GPIO_ALTFN15
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

#if defined(STM32_GPIOH)
extern volatile struct gpio_registers_map* GPIOH;
#endif

#if defined(STM32_GPIOH)
extern volatile struct gpio_registers_map* GPIOI;
#endif

#if defined(STM32_GPIOJ)
extern volatile struct gpio_registers_map* GPIOJ;
#endif

#if defined(STM32_GPIOK)
extern volatile struct gpio_registers_map* GPIOK;
#endif

void
gpio_setup_port_pins(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_mode mode,
  enum gpio_speed speed
);

void
gpio_set_port_pins_output_type(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_output_type type
);

void
gpio_set_port_pins_io_resistor(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_io_resistor resistor
);

u32
gpio_port_read(
  volatile struct gpio_registers_map* gpio
);

u32
gpio_pin_read(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

void
gpio_set_port_state(
  volatile struct gpio_registers_map* gpio,
  u32 state
);

u32
gpio_is_pin_set_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

void
gpio_set_pin_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

void
gpio_set_pin_low(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

void
gpio_pin_toggle(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

u32
gpio_pin_lock(
  volatile struct gpio_registers_map* gpio,
  u32 pins
);

void
gpio_set_pin_alternate_function(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_altfn fn
);

END_DECLARATIONS

#endif
