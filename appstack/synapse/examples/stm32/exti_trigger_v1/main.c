#include "synapse/arch/cortex/periph/nvic.h"
#include "synapse/stm32/periph/exti.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/rcc.h"
#include "synapse/stm32/periph/afio.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
}

void
gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOC,
    GPIO13,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOB,
    GPIO0,
    GPIO_MODE_INPUT,
    GPIO_CNF_INPUT_FLOATING
  );

  gpio_set_pin_low(GPIOB, GPIO10);
  gpio_set_pin_low(GPIOB, GPIO0);
}

void
exti_setup(void)
{
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN0);
  exti_trigger_event_line_enable(0, EXTI_TRIGGER_EVENT_RISING);
  exti_trigger_event_line_disable(0, EXTI_TRIGGER_EVENT_FALLING);
  exti_interrupt_line_enable(0);
}

static u32 c = 0;

void exti0_isr(void)
{
  if (++c != 2)
  {
    return;
  }
  c = 0;

  gpio_pin_toggle(GPIOC, GPIO13);
  exti_is_trigger_request_pending(0);
}

int
main(void)
{
  rcc_setup();
  gpio_setup();
  exti_setup();

  nvic_irq_enable(NVIC_IRQ_EXTI0);
  while (1);

  return 0;
}

