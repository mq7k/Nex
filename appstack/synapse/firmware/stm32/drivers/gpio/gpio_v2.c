#include "synapse/stm32/drivers/gpio/gpio_v2.h"
#include "libcom/sys/devmode.h"

typedef volatile struct gpio_registers_map gpio_periph;


#if defined(STM32_GPIOA)
gpio_periph* GPIOA = (gpio_periph*) (GPIOA_ADDR);
#endif

#if defined(STM32_GPIOB)
gpio_periph* GPIOB = (gpio_periph*) (GPIOB_ADDR);
#endif

#if defined(STM32_GPIOC)
gpio_periph* GPIOC = (gpio_periph*) (GPIOC_ADDR);
#endif

#if defined(STM32_GPIOD)
gpio_periph* GPIOD = (gpio_periph*) (GPIOD_ADDR);
#endif

#if defined(STM32_GPIOE)
gpio_periph* GPIOE = (gpio_periph*) (GPIOE_ADDR);
#endif

#if defined(STM32_GPIOF)
gpio_periph* GPIOF = (gpio_periph*) (GPIOF_ADDR);
#endif

#if defined(STM32_GPIOG)
gpio_periph* GPIOG = (gpio_periph*) (GPIOG_ADDR);
#endif

#if defined(STM32_GPIOH)
gpio_periph* GPIOH = (gpio_periph*) (GPIOH_ADDR);
#endif

#if defined(STM32_GPIOI)
gpio_periph* GPIOI = (gpio_periph*) (GPIOI_ADDR);
#endif

#if defined(STM32_GPIOJ)
gpio_periph* GPIOJ = (gpio_periph*) (GPIOJ_ADDR);
#endif

#if defined(STM32_GPIOK)
gpio_periph* GPIOK = (gpio_periph*) (GPIOK_ADDR);
#endif

static enum gpio_moder
convert_gpio_mode_api_to_impl(
  enum gpio_mode mode
)
{
  switch (mode)
  {
    case GPIO_MODE_INPUT:
      return GPIO_MODER_INPUT;

    case GPIO_MODE_OUTPUT:
      return GPIO_MODER_OUTPUT;

    case GPIO_MODE_ALTFN:
      return GPIO_MODER_ALTFN;

    case GPIO_MODE_ANALOG:
      return GPIO_MODER_ANALOG;

    default:
      devmode_error_invalid_enum(enum gpio_mode, mode);
      return 0;
  }
}

static enum gpio_ospeedr
convert_gpio_speed_api_to_impl(
  enum gpio_speed speed
)
{
  switch (speed)
  {
    case GPIO_SPEED_LOW:
      return GPIO_OSPEEDR_LOW_SPEED;

    case GPIO_SPEED_MEDIUM:
      return GPIO_OSPEEDR_MEDIUM_SPEED;

#if defined(STM32_GPIO_SPEED_HIGH)
    case GPIO_SPEED_HIGH:
      return GPIO_OSPEEDR_HIGH_SPEED;

#if defined(STM32_GPIO_VERY_HIGH_SPEED)
    case GPIO_SPEED_VERY_HIGH:
      return GPIO_OSPEEDR_VERY_HIGH_SPEED;
#endif
#elif defined(STM32_GPIO_SPEED_FAST)
    case GPIO_SPEED_FAST:
      return GPIO_OSPEEDR_FAST_SPEED;
    case GPIO_SPEED_HIGH:
      return GPIO_OSPEEDR_HIGH_SPEED;
#endif

    default:
      devmode_error_invalid_enum(enum gpio_speed, speed);
      return 0;
  }
}

static enum gpio_pupdr
convert_gpio_pupdr_api_to_impl(
  enum gpio_io_resistor resistor
)
{
  switch (resistor)
  {
    case GPIO_IO_RESISTOR_NO_PULLUPDOWN:
      return GPIO_PUPDR_NO_PULLUPDOWN;
      
    case GPIO_IO_RESISTOR_PULLUP:
      return GPIO_PUPDR_PULLUP;

    case GPIO_IO_RESISTOR_PULLDOWN:
      return GPIO_PUPDR_PULLDOWN;

    default:
      devmode_error_invalid_enum(enum gpio_io_resistor, resistor);
      return 0;
  }
}

static enum gpio_afr_altfn
convert_gpio_altfn_api_to_impl(
  enum gpio_altfn fn
)
{
  switch (fn)
  {
    case GPIO_ALTFN0:
      return GPIO_AFR_ALTFN0;

    case GPIO_ALTFN1:
      return GPIO_AFR_ALTFN1;

    case GPIO_ALTFN2:
      return GPIO_AFR_ALTFN2;

    case GPIO_ALTFN3:
      return GPIO_AFR_ALTFN3;

    case GPIO_ALTFN4:
      return GPIO_AFR_ALTFN4;

    case GPIO_ALTFN5:
      return GPIO_AFR_ALTFN5;

    case GPIO_ALTFN6:
      return GPIO_AFR_ALTFN6;

    case GPIO_ALTFN7:
      return GPIO_AFR_ALTFN7;

    case GPIO_ALTFN8:
      return GPIO_AFR_ALTFN8;

    case GPIO_ALTFN9:
      return GPIO_AFR_ALTFN9;

    case GPIO_ALTFN10:
      return GPIO_AFR_ALTFN10;

    case GPIO_ALTFN11:
      return GPIO_AFR_ALTFN11;

    case GPIO_ALTFN12:
      return GPIO_AFR_ALTFN12;

    case GPIO_ALTFN13:
      return GPIO_AFR_ALTFN13;

    case GPIO_ALTFN14:
      return GPIO_AFR_ALTFN14;

    case GPIO_ALTFN15:
      return GPIO_AFR_ALTFN15;

    default:
      devmode_error_invalid_enum(enum gpio_altfn, fn);
      return 0;
  }
}

void
gpio_setup_port_pins(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_mode mode,
  enum gpio_speed speed
)
{
  enum gpio_moder moder = convert_gpio_mode_api_to_impl(mode);
  enum gpio_ospeedr ospeedr = convert_gpio_speed_api_to_impl(speed);

  u32 moder_reg = gpio->MODER;
  u32 ospeedr_reg = gpio->OSPEEDR;

  constexpr u32 moder_reg_mask = GPIO_MODER_MASK;
  constexpr u32 ospeedr_reg_mask = GPIO_OSPEEDR_MASK;

  constexpr u32 moder_reg_stride = GPIO_MODER_STRIDE;
  constexpr u32 ospeedr_reg_stride = GPIO_OSPEEDR_STRIDE;

  for (u32 i = 0; i < 15; ++i)
  {
    if (pins & (1 << i))
    {
      const u32 moder_reg_shift = moder_reg_stride * i;
      const u32 ospeedr_reg_shift = ospeedr_reg_stride * i;

      moder_reg &= ~(moder_reg_mask << moder_reg_shift);
      ospeedr_reg &= ~(ospeedr_reg_mask << ospeedr_reg_shift);

      moder_reg |= (moder << moder_reg_shift);
      ospeedr_reg |= (ospeedr << ospeedr_reg_shift);
    }
  }

  gpio->MODER = moder_reg;
  gpio->OSPEEDR = ospeedr_reg;
}

void
gpio_set_port_pins_output_type(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_output_type type
)
{
  volatile u32* reg = &gpio->OTYPER;
  switch (type)
  {
    case GPIO_OUTPUT_TYPE_PUSHPULL:
      *reg &= ~pins;
      break;

    case GPIO_OUTPUT_TYPE_OPEN_DRAIN:
      *reg |= pins;
      break;

    default:
      devmode_error_invalid_enum(enum gpio_output_type, type);
      break;
  }
}

void
gpio_set_port_pins_io_resistor(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_io_resistor resistor
)
{
  constexpr u32 mask = GPIO_PUPDR_MASK;
  constexpr u32 stride = GPIO_PUPDR_STRIDE;

  const enum gpio_pupdr pupdr_val = convert_gpio_pupdr_api_to_impl(resistor);
  u32 reg = gpio->PUPDR;

  for (u32 i = 0; i < 15; ++i)
  {
    if (pins & (1 << i))
    {
      const u32 shift = stride * i;

      reg &= ~(mask << shift);
      reg |= (pupdr_val << shift);
    }
  }

  gpio->PUPDR = reg;
}

u32
gpio_port_read(
  volatile struct gpio_registers_map* gpio
)
{
  return gpio->IDR;
}

u32
gpio_pin_read(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  return gpio->IDR & pins;
}

void
gpio_set_port_state(
  volatile struct gpio_registers_map* gpio,
  u32 state
)
{
  gpio->ODR = state;
}

u32
gpio_is_pin_set_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  return gpio->ODR & pins;
}

void
gpio_set_pin_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  gpio->BSRR |= pins;
}

void
gpio_set_pin_low(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  gpio->BSRR |= (pins << 16);
}

void
gpio_pin_toggle(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  const u32 odr = gpio->ODR;
  gpio->BSRR = ((odr & pins) << 16) | (~odr & pins);
}

u32
gpio_pin_lock(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  gpio->LCKR |= pins;

  gpio->LCKR |= GPIO_LCKR_LCKK;
  gpio->LCKR &= ~GPIO_LCKR_LCKK;
  gpio->LCKR |= GPIO_LCKR_LCKK;
  (void) gpio->LCKR;

  return gpio->LCKR & GPIO_LCKR_LCKK;
}

void
gpio_set_pin_alternate_function(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_altfn fn
)
{
  constexpr u32 afrl_stride = GPIO_AFRL_STRIDE;
  constexpr u32 afrl_mask = GPIO_AFRL_MASK;

  constexpr u32 afrh_stride = GPIO_AFRH_STRIDE;
  constexpr u32 afrh_mask = GPIO_AFRH_MASK;

  enum gpio_afr_altfn altfn_val = convert_gpio_altfn_api_to_impl(fn);

  u32 afrl_reg = gpio->AFRL;
  u32 afrh_reg = gpio->AFRH;

  for (u32 i = 0; i < 8; ++i)
  {
    if (pins & (1 << i))
    {
      const u32 afrl_shift = afrl_stride * i;
      afrl_reg &= ~(afrl_mask << afrl_shift);
      afrl_reg |= (altfn_val << afrl_shift);
    }
  }

  for (u32 i = 0; i < 8; ++i)
  {
    if (pins & (1 << (i + 8)))
    {
      const u32 afrh_shift = afrh_stride * i;
      afrh_reg &= ~(afrh_mask << afrh_shift);
      afrh_reg |= (altfn_val << afrh_shift);
    }
  }

  gpio->AFRL = afrl_reg;
  gpio->AFRH = afrh_reg;
}
