#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "libcom/unit.h"
#include "synapse/stm32/periph/dma.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/tim.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/usart.h"
#include "synapse/arch/cortex/periph/nvic.h"
#include "synapse/arch/cortex/common/sys.h"
#include "synapse/arch/cortex/periph/systick.h"

struct note
{
  u32 frequency;
  u32 duration_ms;
};

constexpr struct note notes[] = {
  { .frequency = 262, .duration_ms = 400 },
  { .frequency = 294, .duration_ms = 400 },
  { .frequency = 330, .duration_ms = 400 },
  { .frequency = 349, .duration_ms = 400 },
  { .frequency = 392, .duration_ms = 400 },
  { .frequency = 440, .duration_ms = 400 },
  { .frequency = 494, .duration_ms = 400 },
  { .frequency = 523, .duration_ms = 600 },

  { .frequency = 523, .duration_ms = 200 },
  { .frequency = 494, .duration_ms = 200 },
  { .frequency = 440, .duration_ms = 200 },
  { .frequency = 392, .duration_ms = 200 },
  { .frequency = 440, .duration_ms = 200 },
  { .frequency = 494, .duration_ms = 200 },
  { .frequency = 523, .duration_ms = 600 },

  { .frequency = 392, .duration_ms = 300 },
  { .frequency = 392, .duration_ms = 300 },
  { .frequency = 392, .duration_ms = 300 },
  { .frequency = 440, .duration_ms = 300 },
  { .frequency = 494, .duration_ms = 300 },
  { .frequency = 440, .duration_ms = 300 },
  { .frequency = 392, .duration_ms = 600 },

  { .frequency = 330, .duration_ms = 300 },
  { .frequency = 330, .duration_ms = 300 },
  { .frequency = 330, .duration_ms = 300 },
  { .frequency = 349, .duration_ms = 300 },
  { .frequency = 392, .duration_ms = 300 },
  { .frequency = 349, .duration_ms = 300 },
  { .frequency = 330, .duration_ms = 600 },
  { .frequency = 262, .duration_ms = 800 }
};

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOA,
    GPIO11,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(
    GPIOA,
    GPIO11,
    GPIO_ALTFN1
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

  gpio_setup_port_pins(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );
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
timer_setup(void)
{
  tim_set_prescaler(TIM1, 63);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM1, 10000-1);
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_set_oc_mode(TIM1, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  tim_set_center_aligned_mode(TIM1, TIM_CENTER_ALIGNED_MODE_EDGE);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_set_cc_value(TIM1, TIM_CHANNEL4, 0);
  tim_counter_enable(TIM1);
  tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
  tim_main_output_enable(TIM1);
}

void
systick_setup(void)
{
  systick_set_clock_source(SYSTICK_CLOCK_SOURCE_PROCESSOR);
  systick_set_reload_value(16000);
  systick_set_current_value(0);
  systick_interrupt_enable();
  systick_enable();
}

u32 delay;
u32 tick;

void
systick_handler(void)
{
  if (delay > 0)
  {
    --delay;
  }

  if (tick++ >= 1000)
  {
    tick = 0;
    gpio_pin_toggle(GPIOC, GPIO13);
  }

  cm_isb();
  cm_dsb();
}

int
main(void)
{
  delay = 0;
  tick = 0;

  rcc_setup();
  gpio_setup();
  usart_setup();
  systick_setup();
  timer_setup();

  constexpr u32 size = ARR_SIZE(notes);
  u32 idx = 0;

  while (1)
  {
    const struct note* note = &notes[idx];
    tim_set_autoreload_value(TIM1, note->frequency);
    tim_set_cc_value(TIM1, TIM_CHANNEL4, note->frequency >> 6);
    usart_send_strfln(USART1, "Playing note frequency=%u for %ums", note->frequency, note->duration_ms);
    delay = note->duration_ms;
    cm_isb();
    cm_dsb();
    while (delay > 0)
    {
      syn_delay_nop(1000);
    }

    syn_delay_nop(10000);
    ++idx;
    if (idx >= size)
    {
      idx = 0;
    }
  }
}
