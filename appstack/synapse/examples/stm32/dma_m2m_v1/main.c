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
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_DMA1);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 apb2_clock = nex_convert_freq_unit(72, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, apb2_clock, baudrate);
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
dma_setup(void)
{
  dma_channel_disable(DMA1, DMA_CHANNEL1);
  dma_channel_mem2mem_mode_enable(DMA1, DMA_CHANNEL1);
  dma_channel_set_periph_address(DMA1, DMA_CHANNEL1, (u32) str);
  dma_channel_set_memory_address(DMA1, DMA_CHANNEL1, (u32) buf);
  dma_channel_memory_increment_mode_enable(DMA1, DMA_CHANNEL1);
  dma_channel_periph_increment_mode_enable(DMA1, DMA_CHANNEL1);
  dma_channel_set_data_transfer_direction(DMA1, DMA_CHANNEL1, DMA_TRANSFER_DIRECTION_FROM_PERIPH);
  dma_channel_set_memory_size(DMA1, DMA_CHANNEL1, DMA_MEMORY_SIZE_8BITS);
  dma_channel_set_periph_size(DMA1, DMA_CHANNEL1, DMA_PERIPH_SIZE_8BITS);
  dma_set_channel_transfer_items_count(DMA1, DMA_CHANNEL1, strlen(str));
}

int
main()
{
  rcc_setup();
  gpio_setup();
  usart_setup();
  dma_setup();

  usart_send_strln(USART1, "Starting transfer...");

  dma_channel_enable(DMA1, DMA_CHANNEL1);
  usart_send_strln(USART1, "Waiting for it to complete...");
  WAIT_UNTIL(dma_is_channel_flag_set(DMA1, DMA_CHANNEL1, DMA_FLAG_TRANSER_COMPLETE));

  usart_send_strln(USART1, "Transfer complete.");
  usart_send_strln(USART1, buf);

  while (1);
}
