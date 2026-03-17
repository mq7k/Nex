#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "libcom/unit.h"
#include "synapse/soc/stm32/periph/rcc.h"
#include "synapse/soc/stm32/periph/tim.h"
#include "synapse/soc/stm32/periph/gpio.h"
#include "synapse/cpu/cortex/periph/nvic.h"
#include "synapse/cpu/cortex/common/sys.h"
#include "synapse/cpu/cortex/periph/systick.h"

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS4 415
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_FS4 370
#define NOTE_CS4 277
#define REST 0

struct note
{
  u32 frequency;
  u32 duration_ms;
};

constexpr struct note notes_tetris[] = {
  {.frequency = NOTE_E5, .duration_ms = 400 }, 
  {.frequency = NOTE_B4, .duration_ms = 200 }, 
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_D5, .duration_ms = 400 },
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_B4, .duration_ms = 200 },
  {.frequency = NOTE_A4, .duration_ms = 400 },
  {.frequency = NOTE_A4, .duration_ms = 200 },
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_E5, .duration_ms = 400 },
  {.frequency = NOTE_D5, .duration_ms = 200 },
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_B4, .duration_ms = 600 },
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_D5, .duration_ms = 400 },
  {.frequency = NOTE_E5, .duration_ms = 400 },
  {.frequency = NOTE_C5, .duration_ms = 400 },
  {.frequency = NOTE_A4, .duration_ms = 400 },
  {.frequency = NOTE_A4, .duration_ms = 400 },
  {.frequency = REST, .duration_ms    = 200 },
  {.frequency = NOTE_D5, .duration_ms = 400 },
  {.frequency = NOTE_F5, .duration_ms = 200 },
  {.frequency = NOTE_A5, .duration_ms = 400 },
  {.frequency = NOTE_G5, .duration_ms = 200 },
  {.frequency = NOTE_F5, .duration_ms = 200 },
  {.frequency = NOTE_E5, .duration_ms = 600 },
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_E5, .duration_ms = 400 },
  {.frequency = NOTE_D5, .duration_ms = 200 },
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_B4, .duration_ms = 400 },
  {.frequency = NOTE_B4, .duration_ms = 200 },
  {.frequency = NOTE_C5, .duration_ms = 200 },
  {.frequency = NOTE_D5, .duration_ms = 400 },
  {.frequency = NOTE_E5, .duration_ms = 400 },
  {.frequency = NOTE_C5, .duration_ms = 400 },
  {.frequency = NOTE_A4, .duration_ms = 400 },
  {.frequency = NOTE_A4, .duration_ms = 400 },
  {.frequency = REST, .duration_ms    = 400 }
};

const struct note notes_happy_birthday[] = {
  { .frequency = NOTE_C4, .duration_ms = 300 },
  { .frequency = NOTE_C4, .duration_ms = 150 },
  { .frequency = NOTE_D4, .duration_ms = 400 },
  { .frequency = NOTE_C4, .duration_ms = 400 },
  { .frequency = NOTE_F4, .duration_ms = 400 },
  { .frequency = NOTE_E4, .duration_ms = 800 },
  { .frequency = NOTE_C4, .duration_ms = 300 },
  { .frequency = NOTE_C4, .duration_ms = 150 },
  { .frequency = NOTE_D4, .duration_ms = 400 },
  { .frequency = NOTE_C4, .duration_ms = 400 },
  { .frequency = NOTE_G4, .duration_ms = 400 },
  { .frequency = NOTE_F4, .duration_ms = 800 },
  { .frequency = NOTE_C4, .duration_ms = 300 },
  { .frequency = NOTE_C4, .duration_ms = 150 },
  { .frequency = NOTE_C5, .duration_ms = 400 },
  { .frequency = NOTE_A4, .duration_ms = 400 },
  { .frequency = NOTE_F4, .duration_ms = 400 },
  { .frequency = NOTE_E4, .duration_ms = 400 },
  { .frequency = NOTE_D4, .duration_ms = 800 },
  { .frequency = NOTE_AS4, .duration_ms = 300 },
  { .frequency = NOTE_AS4, .duration_ms = 150 },
  { .frequency = NOTE_A4, .duration_ms = 400 },
  { .frequency = NOTE_F4, .duration_ms = 400 },
  { .frequency = NOTE_G4, .duration_ms = 400 },
  { .frequency = NOTE_F4, .duration_ms = 800 },
  { .frequency = REST, .duration_ms = 1000 },
};

const struct note notes_nokia[] = {
  { .frequency = NOTE_E5, .duration_ms = 125 },
  { .frequency = NOTE_D5, .duration_ms = 125 },
  { .frequency = NOTE_FS4, .duration_ms = 250 },
  { .frequency = NOTE_GS4, .duration_ms = 250 },
  { .frequency = NOTE_CS5, .duration_ms = 125 },
  { .frequency = NOTE_B4, .duration_ms = 125 },
  { .frequency = NOTE_D4, .duration_ms =  250 },
  { .frequency = NOTE_E4, .duration_ms =  250 },
  { .frequency = NOTE_B4, .duration_ms =  125 },
  { .frequency = NOTE_A4, .duration_ms = 125 },
  { .frequency = NOTE_CS4, .duration_ms = 250 },
  { .frequency = NOTE_E4, .duration_ms =  250 },
  { .frequency = NOTE_A4, .duration_ms =  500 },
  { .frequency = REST, .duration_ms =  1000 }
};

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
}

void
gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOA,
    GPIO11,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );
}

void
timer_setup(void)
{
  tim_set_prescaler(TIM1, 7);
  tim_set_clock_division(TIM1, TIM_CLOCK_DIVISION_NODIV);
  tim_set_autoreload_value(TIM1, 999);
  tim_oc_preload_enable(TIM1, TIM_CHANNEL4);
  tim_set_oc_mode(TIM1, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  tim_set_center_aligned_mode(TIM1, TIM_CENTER_ALIGNED_MODE_EDGE);
  tim_set_counter_direction(TIM1, TIM_COUNTER_DIRECTION_UP);
  tim_set_cc_value(TIM1, TIM_CHANNEL4, 0);
  tim_counter_enable(TIM1);
  tim_main_output_enable(TIM1);
}

void
systick_setup(void)
{
  systick_set_clock_source(SYSTICK_CLOCK_SOURCE_PROCESSOR);
  systick_set_reload_value(7999);
  systick_set_current_value(0);
  systick_interrupt_enable();
  systick_enable();
}

volatile u32 delay;

void
systick_handler(void)
{
  if (delay > 0)
  {
    --delay;
  }
}

static void
_delay_ms(
  u32 ms
)
{
  delay = ms;
  while (delay > 0);
}

int
main(void)
{
  delay = 0;

  rcc_setup();
  gpio_setup();
  systick_setup();
  timer_setup();

  // Change `notes_tetris` to `notes_nokia` or `notes_happy_birthday`
  // to play a different melody.
  constexpr u32 size = ARR_SIZE(notes_tetris);
  u32 idx = 0;

  while (1)
  {
    const struct note* note = &notes_tetris[idx];
    if (note->frequency == REST)
    {
      tim_cc_channel_disable(TIM1, TIM_CHANNEL4);
    }
    else
    {
      u32 val = (1000000 / note->frequency) - 1;
      tim_set_autoreload_value(TIM1, val);
      tim_set_cc_value(TIM1, TIM_CHANNEL4, val >> 1);
      tim_trigger_event_generation(TIM1, TIM_EVENT_UPDATE);
      tim_cc_channel_enable(TIM1, TIM_CHANNEL4);
    }
    
    _delay_ms(note->duration_ms);
    tim_cc_channel_disable(TIM1, TIM_CHANNEL4);
    _delay_ms(30);
    
    if (++idx >= size)
    {
      idx = 0;
    }
  }
}
