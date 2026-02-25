#include "synapse/common/util/common.h"
#include "libcom/unit.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/dma.h"
#include "synapse/stm32/periph/usart.h"
#include "synapse/stm32/periph/gpio.h"

#include <string.h>

const char* str = "Dashwood contempt on mr unlocked resolved provided of of. Stanhill wondered it it welcomed oh. Hundred no prudent he however smiling at an offence. If earnestly extremity he he propriety something admitting convinced ye. Pleasant in to although as if differed horrible. Mirth his quick its set front enjoy hoped had there. Who connection imprudence middletons too but increasing celebrated principles joy. Herself too improve gay winding ask expense are compact.";

char buf[512];

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 clock = nex_convert_freq_unit(16, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
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
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO9,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO10,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(GPIOA, GPIO9 | GPIO10, GPIO_ALTFN7);
}

void
dma_setup(void)
{
  dma_stream_set_channel(DMA2, DMA_STREAM0, DMA_STREAM_CHANNEL0);
  dma_stream_set_data_transfer_direction(DMA2, DMA_STREAM0, DMA_STREAM_DIRECTION_MEMORY_TO_MEMORY);
  dma_stream_set_periph_address(DMA2, DMA_STREAM0, (u32) str);
  dma_stream_set_memory_address(DMA2, DMA_STREAM0, DMA_STREAM_MEMORY0, (u32) buf);
  dma_stream_set_items_transfer_count(DMA2, DMA_STREAM0, strlen(str));
  dma_stream_memory_increment_mode_enable(DMA2, DMA_STREAM0);
  dma_stream_periph_increment_mode_enable(DMA2, DMA_STREAM0);
  dma_stream_set_priority(DMA2, DMA_STREAM0, DMA_STREAM_PRIORITY_VERY_HIGH);
  dma_stream_set_fifo_threshold(DMA2, DMA_STREAM0, DMA_STREAM_FIFO_THRESHOLD_FULL);
}

int
main()
{
  rcc_setup();
  gpio_setup();
  usart_setup();
  dma_setup();

  usart_send_strln(USART1, "Starting transfer...");
  dma_stream_enable(DMA2, DMA_STREAM0);

  usart_send_strln(USART1, "Waiting for it to complete...");
  WAIT_UNTIL(dma_is_stream_flag_set(DMA2, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE))

  usart_send_strln(USART1, "Transfer complete.");
  usart_send_str(USART1, buf);

  while (1);
}
