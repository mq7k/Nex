#include "libcom/types.h"
#include "synapse/common/util/unit.h"

#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/usart.h"

#include "synapse/common/runtime.h"

#define FOO_ARRAY_ELEMENTS_COUNT (2048)
volatile u32 foo[FOO_ARRAY_ELEMENTS_COUNT];

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
}

void
gpio_setup(void)
{
  gpio_setup_port(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );

  gpio_setup_port(
    GPIOA,
    GPIO9 | GPIO10,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 clock = syn_convert_freq_unit(16, FREQ_UNIT_MHz, FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, clock, baudrate);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  usart_transmitter_enable(USART1);
  usart_parity_control_disable(USART1);
  usart_cts_disable(USART1);
  usart_rts_disable(USART1);
  usart_enable(USART1);
}

void
recursive_fn(
  u32 depth,
  const u32 max_depth
)
{
  if (depth < max_depth)
  {
    recursive_fn(depth + 1, max_depth);
    return;
  }

  u32 ram_used = syn_get_RAM_usage();
  u32 flash_used = syn_get_flash_usage();

  enum byte_unit ram_used_unit;
  enum byte_unit flash_used_unit;
  ram_used = syn_convert_byte_to_largest(ram_used, BYTE_UNIT_BYTE, &ram_used_unit);
  flash_used = syn_convert_byte_to_largest(flash_used, BYTE_UNIT_BYTE, &flash_used_unit);

  usart_send_strln(USART1, "Runtime system resources (Recursive):");
  usart_send_strfln(USART1, "RAM usage: %u %s", ram_used, syn_byte_unit_to_string(ram_used_unit));
  usart_send_strfln(USART1, "Flash usage: %u %s", flash_used, syn_byte_unit_to_string(flash_used_unit));
  usart_send_strfln(USART1, "");
}

int 
main(void)
{
  rcc_setup();
  gpio_setup();
  usart_setup();

  gpio_pin_toggle(GPIOC, GPIO13);

  u32 ram_used = syn_get_RAM_usage();
  u32 flash_used = syn_get_flash_usage();

  enum byte_unit ram_used_unit;
  enum byte_unit flash_used_unit;
  ram_used = syn_convert_byte_to_largest(ram_used, BYTE_UNIT_BYTE, &ram_used_unit);
  flash_used = syn_convert_byte_to_largest(flash_used, BYTE_UNIT_BYTE, &flash_used_unit);

  usart_send_strln(USART1, "Runtime system resources (Idle):");
  usart_send_strfln(USART1, "RAM usage: %u %s", ram_used, syn_byte_unit_to_string(ram_used_unit));
  usart_send_strfln(USART1, "Flash usage: %u %s", flash_used, syn_byte_unit_to_string(flash_used_unit));
  usart_send_strfln(USART1, "");

  recursive_fn(0, 256);

  while (1);
}
