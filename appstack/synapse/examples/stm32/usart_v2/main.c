#include "synapse/common/util/common.h"
#include "libcom/format.h"
#include "libcom/types.h"
#include "libcom/unit.h"

#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/usart.h"

#include "stdarg.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOA,
    GPIO9 | GPIO10,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(GPIOA, GPIO9 | GPIO10, GPIO_ALTFN7);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 apb2_clock = nex_convert_freq_unit(16, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, apb2_clock, baudrate);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  usart_transmitter_enable(USART1);
  usart_receiver_enable(USART1);
  usart_parity_control_disable(USART1);
  usart_cts_disable(USART1);
  usart_rts_disable(USART1);
  usart_enable(USART1);
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  usart_setup();

  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);

  u32 i = 0;
  const char* str = "Dashwood contempt on mr unlocked resolved provided of of. Stanhill wondered it it welcomed oh. Hundred no prudent he however smiling at an offence. If earnestly extremity he he propriety something admitting convinced ye. Pleasant in to although as if differed horrible. Mirth his quick its set front enjoy hoped had there. Who connection imprudence middletons too but increasing celebrated principles joy. Herself too improve gay winding ask expense are compact.";

  u32 echo_mode = 0;

  char buf[256];
  u32 idx = 0;

  usart_send_strln(USART1, "Waiting for commands...");

  while (1)
  {
    WAIT_UNTIL(usart_is_flag_set(USART1, USART_FLAG_READ_REG_NOT_EMPTY));
    u32 c = usart_data_read(USART1);

    if (echo_mode)
    {
      if (c == '\n' || c == '\r')
      {
        for (u32 j = 0; j < idx; ++j)
        {
          usart_send_byte(USART1, buf[j]);
        }

        usart_send_str(USART1, "\r\n");

        syn_delay_nop(1000000);
        idx = 0;
        echo_mode = 0;
        usart_send_strln(USART1, "Echo mode disabled");
        continue;
      }

      buf[idx++] = (char) c;
      continue;
    }

    switch (c)
    {
      case 't':
        i = 0;
        while (str[i])
        {
          usart_send_byte(USART1, str[i++]);
          syn_delay_nop(50000);
        }

        usart_send_str(USART1, "\r\n");

        break;

      case 'e':
        idx = 0;
        echo_mode = 1;
        usart_send_strln(USART1, "Echo mode enabled");
        break;

      case 'f':
        usart_send_strln(USART1, "Test formatting types...");
        usart_send_strfln(USART1, "Printing a string: '%s'", "Hello world");
        usart_send_strfln(USART1, "Printing a char: '%c'", 'A');
        usart_send_strfln(USART1, "Printing a u32: %u", 3125483940);
        usart_send_strfln(USART1, "Printing a u64: %L", 288230376151711808L);
        usart_send_strfln(USART1, "Printing a hex: 0x%x", 0xdeadbeef);
        usart_send_strfln(USART1, "Printing a binary: 0b%b", 0xdeadbeef);
        usart_send_strfln(USART1, "Printing a boolean (true): %B", 1);
        usart_send_strfln(USART1, "Printing a boolean (false): %B", 0);
        usart_send_strfln(USART1, "Printing a i32: %d", -410935446);
        usart_send_strfln(USART1, "Printing a double: %f", -3.002176);
        break;
    }
  }
}
