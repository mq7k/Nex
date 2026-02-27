#include "synapse/common/util/common.h"
#include "libcom/types.h"

#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/usart.h"

#include "stdarg.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
}

void
gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOA,
    GPIO9,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOA,
    GPIO10,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 apb2_clock = 72000000;
  usart_set_baudrate(USART1, apb2_clock, baudrate);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  usart_transmitter_enable(USART1);
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

  u32 it = 0;
  u32 i = 0;
  const char* str = "Dashwood contempt on mr unlocked resolved provided of of. Stanhill wondered it it welcomed oh. Hundred no prudent he however smiling at an offence. If earnestly extremity he he propriety something admitting convinced ye. Pleasant in to although as if differed horrible. Mirth his quick its set front enjoy hoped had there. Who connection imprudence middletons too but increasing celebrated principles joy. Herself too improve gay winding ask expense are compact.";

  usart_send_str(USART1, "\r\n\n");
  usart_send_strf(USART1, "********* Starting iteration: %u *********\r\n", it);

  while (1)
  {
    usart_send_byte(USART1, str[i++]);

    if (!str[i])
    {
      usart_send_strf(USART1, "\r\n********* Completed iteration: %u *********\r\n\n", it);
      ++it;
      usart_send_strf(USART1, "********* Starting iteration: %u *********\r\n", it);
      i = 0;
    }

    syn_delay_nop(250000);
  }
}
