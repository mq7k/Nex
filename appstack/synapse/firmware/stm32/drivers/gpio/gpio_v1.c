#include "synapse/stm32/drivers/gpio/gpio_v1.h"
#include "libcom/sys/devmode.h"
#include "synapse/stm32/system/specs.h"

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

u32
convert_gpio_pin_api_to_pin_idx(
  enum gpio_pin pin
)
{
  switch (pin)
  {
    case GPIO0:
      return 0;

    case GPIO1:
      return 1;

    case GPIO2:
      return 2;

    case GPIO3:
      return 3;

    case GPIO4:
      return 4;

    case GPIO5:
      return 5;

    case GPIO6:
      return 6;

    case GPIO7:
      return 7;

    case GPIO8:
      return 8;

    case GPIO9:
      return 9;

    case GPIO10:
      return 10;

    case GPIO11:
      return 11;

    case GPIO12:
      return 12;

    case GPIO13:
      return 13;

    case GPIO14:
      return 14;

    case GPIO15:
      return 15;

    default:
      devmode_error_invalid_enum(enum gpio_pin, pin);
      return 0;
  }
}
/*
 * Converts the API enum into the core enum.
 * This function does not exist in runtime if
 * compiled with at least -O2.
 */
static enum gpio_cr_mode
convert_gpio_mode_api_to_impl(
  enum gpio_port_mode mode
)
{
  switch (mode)
  {
    case GPIO_MODE_INPUT:
      return GPIO_CR_MODE_INPUT;

    case GPIO_MODE_OUTPUT_10MHZ:
      return GPIO_CR_MODE_OUTPUT_10MHZ;

    case GPIO_MODE_OUTPUT_2MHZ:
      return GPIO_CR_MODE_OUTPUT_2MHZ;

    case GPIO_MODE_OUTPUT_50MHZ:
      return GPIO_CR_MODE_OUTPUT_50MHZ;

    default:
      devmode_error_invalid_enum(enum gpio_port_mode, mode);
      return 0;
  }
}

/*
 *
 * Converts the API enum into the core enum.
 * This function does not exist in runtime if
 * compiled with at least -O2.
 */
static enum gpio_cr_cnf
convert_gpio_config_api_to_impl(
  enum gpio_port_config config
)
{
  switch (config)
  {
    case GPIO_CNF_INPUT_ANALOG:
      return GPIO_CR_CNF_INPUT_ANALOG;

    case GPIO_CNF_INPUT_FLOATING:
      return GPIO_CR_CNF_INPUT_FLOATING;

    case GPIO_CNF_INPUT_PULL_UPDOWN:
      return GPIO_CR_CNF_INPUT_PULLUP_PULLDOWN;

    case GPIO_CNF_OUTPUT_PUSHPULL:
      return GPIO_CR_CNF_OUTPUT_PUSHPULL;

    case GPIO_CNF_OUTPUT_OPEN_DRAIN:
      return GPIO_CR_CNF_OUTPUT_OPEN_DRAIN;

    case GPIO_CNF_ALTFN_PUSHPULL:
      return GPIO_CR_CNF_ALTFN_PUSHPULL;

    case GPIO_CNF_ALTFN_OPEN_DRAIN:
      return GPIO_CR_CNF_ALTFN_OPEN_DRAIN;

    default:
      devmode_error_invalid_enum(enum gpio_port_config, config);
      return 0;
  }
}

void
gpio_setup_port(
  volatile struct gpio_registers_map* gpio,
  u32 pins,
  enum gpio_port_mode mode,
  enum gpio_port_config config
)
{
  devmode_assert_lower_or_eq(pins, 0xffff);
  devmode_assert_lower_or_eq(mode, GPIO_MODE_OUTPUT_50MHZ);
  devmode_assert_lower_or_eq(config, GPIO_CNF_ALTFN_OPEN_DRAIN);

  // TODO: Benchmark this
  /*enum gpio_cr_mode mode_impl = convert_gpio_mode_api_to_impl(mode);*/
  /*enum gpio_cr_cnf cnf_impl = convert_gpio_config_api_to_impl(config);*/
  /*const u32 pin_idx = convert_gpio_pin_api_to_pin_idx(pin);*/
  /**/
  /*volatile u32* regs[2] = { &gpio->CRL, &gpio->CRH };*/
  /*volatile u32* reg = regs[pin_idx > 7];*/
  /**/
  /*const u32 shift = (pin_idx % 8) * 4;*/
  /*const u32 mask = 0b1111u << shift;*/
  /*const u32 setup = (cnf_impl << 2) | mode_impl;*/
  /**/
  /**reg = (*reg & ~mask) | (setup << shift);*/

  enum gpio_cr_mode mode_bits = convert_gpio_mode_api_to_impl(mode);
  enum gpio_cr_cnf config_bits = convert_gpio_config_api_to_impl(config);
  const u32 pin_config = mode_bits | (config_bits << 2);

  /*
   * These masks allow to check if at least
   * one pin of a register (CRL and CRH)
   * should be modified before doing any
   * operation on them. `volatile` reads/writes
   * are expensive...
   */
  const u32 reg_crl_mask = 0xffu << 0;
  const u32 reg_crh_mask = 0xffu << 8;

  // GPIO_CRL
  if (pins & reg_crl_mask)
  {
    u32 reg_crl = gpio->CRL;

    for (u32 i = 0; i < 8; ++i)
    {
      if ((pins & (1 << i)) == 0)
      {
        continue;
      }

      const u32 shift = i * 4;
      const u32 mask = 0xfu << shift;

      /*reg_crl &= ~mask;*/
      /*reg_crl |= (pin_config << shift);*/
      reg_crl = (reg_crl & ~mask) | (pin_config << shift);
    }

    gpio->CRL = reg_crl;
  }

  // GPIO_CRH
  if (pins & reg_crh_mask)
  {
    u32 reg_crh = gpio->CRH;

    for (u32 i = 0; i < 8; ++i)
    {
      if ((pins & (1 << (i + 8))) == 0)
      {
        continue;
      }

      const u32 shift = i * 4;
      const u32 mask = 0xfu << shift;

      /*reg_crh &= ~mask;*/
      /*reg_crh |= pin_config << shift;*/
      reg_crh = (reg_crh & ~mask) | (pin_config << shift);
    }

    gpio->CRH = reg_crh;
  }
}

/*static void*/
/*gpio_set_pin(*/
/*  volatile u32* reg,*/
/*  u32 pin_config,*/
/*  u32 shift*/
/*)*/
/*{*/
/*  const u32 mask = 0xfu << shift;*/
/**/
/*  u32 val = *reg;*/
/*  val &= ~mask;*/
/*  val |= (pin_config << shift);*/
/**/
/*  *reg = val;*/
/*}*/

void
gpio_setup_port_pin(
  volatile struct gpio_registers_map* gpio,
  enum gpio_pin pin,
  enum gpio_port_mode mode,
  enum gpio_port_config config
)
{
  devmode_assert_lower_or_eq(pin, GPIO15);
  devmode_assert_lower_or_eq(mode, GPIO_MODE_OUTPUT_50MHZ);
  devmode_assert_lower_or_eq(config, GPIO_CNF_ALTFN_OPEN_DRAIN);
  /*enum gpio_cr_mode mode_bits = convert_gpio_mode_api_to_impl(mode);*/
  /*enum gpio_cr_cnf config_bits = convert_gpio_config_api_to_impl(config);*/
  /*const u32 pin_config = (config_bits << 2) | mode_bits;*/
  /**/
  /*volatile u32* reg = pin < 8 ? &gpio->CRL : &gpio->CRH;*/
  /*gpio_set_pin(reg, pin_config, (pin % 8) * 4);*/

  /*const u32 shift = (pin % 8) * 4;*/
  /*const u32 mask = 0xfu << shift;*/
  /**/
  /*u32 val = *reg;*/
  /*val &= ~mask;*/
  /*val |= (pin_config << shift);*/
  /**/
  /*val = (val & ~mask) | (pin_config << shift);*/
  /**/
  /**reg = val;*/
  enum gpio_cr_mode mode_impl = convert_gpio_mode_api_to_impl(mode);
  enum gpio_cr_cnf cnf_impl = convert_gpio_config_api_to_impl(config);
  const u32 pin_idx = convert_gpio_pin_api_to_pin_idx(pin);

  volatile u32* regs[2] = { &gpio->CRL, &gpio->CRH };
  volatile u32* reg = regs[pin_idx > 7];

  const u32 bit_pos = (pin_idx % 8) * 4;
  const u32 mask = 0b1111u << bit_pos;
  const u32 setup = (cnf_impl << 2) | mode_impl;

  *reg = (*reg & ~mask) | (setup << bit_pos);
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
  devmode_assert_lower_or_eq(pins, 0xffff);
  return gpio_port_read(gpio) & pins;
}

u32
gpio_is_pin_set_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  devmode_assert_lower_or_eq(pins, 0xffff);
  return gpio->ODR & pins;
}

// Sets the state of each pin
// with a single write.
void
gpio_set_port_status(
  volatile struct gpio_registers_map* gpio,
  u32 port_status
)
{
  devmode_assert_lower_or_eq(port_status, 0xffff);
  const u32 reg = gpio->ODR;
  gpio->ODR = (reg & ~GPIO_ODR_MASK) | (port_status & GPIO_ODR_MASK);
}

void
gpio_set_pin_high(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  devmode_assert_lower_or_eq(pins, 0xffff);
  gpio->BSRR |= pins;
}

void
gpio_set_pin_low(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  devmode_assert_lower_or_eq(pins, 0xffff);
  gpio->BSRR |= (pins << 16);
}

void
gpio_pin_toggle(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  devmode_assert_lower_or_eq(pins, 0xffff);
  const u32 reg = gpio->ODR;
  gpio->BSRR = ((reg & pins) << 16) | (~reg & pins);
}

void
gpio_pin_reset(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  devmode_assert_lower_or_eq(pins, 0xffff);
  gpio->BRR |= (pins & 0xffff);
}

u32
gpio_port_lock_pins(
  volatile struct gpio_registers_map* gpio,
  u32 pins
)
{
  devmode_assert_lower_or_eq(pins, 0xffff);
  gpio->LCKR |= pins;

  gpio->LCKR |= GPIO_LCKR_LCKK;
  gpio->LCKR &= ~GPIO_LCKR_LCKK;
  gpio->LCKR |= GPIO_LCKR_LCKK;
  (void) gpio->LCKR;

  return gpio->LCKR & GPIO_LCKR_LCKK;
}

void
bar(void)
{

}

