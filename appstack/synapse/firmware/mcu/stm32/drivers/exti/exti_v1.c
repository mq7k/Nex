#include "synapse/stm32/drivers/exti/exti_v1.h"
#include "libcom/sys/devmode.h"

typedef volatile struct exti_registers_map exti_periph;
exti_periph* EXTI = (exti_periph*) (EXTI_ADDR);

void
exti_interrupt_line_enable(
  u32 line
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  EXTI->IMR |= (1u << line);
}

void
exti_interrupt_line_disable(
  u32 line
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  EXTI->IMR &= ~(1u << line);
}

void
exti_event_request_enable(
  u32 line
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  EXTI->EMR |= (1u << line);
}

void
exti_event_request_disable(
  u32 line
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  EXTI->EMR &= ~(1u << line);
}

void
exti_trigger_event_line_enable(
  u32 line,
  enum exti_trigger_event event
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  switch (event)
  {
    case EXTI_TRIGGER_EVENT_RISING:
      EXTI->RTSR |= (1u << line);
      break;

    case EXTI_TRIGGER_EVENT_FALLING:
      EXTI->FTSR |= (1u << line);
      break;

    default:
      devmode_error_invalid_enum(enum exti_trigger_event, event);
      break;
  }
}

void
exti_trigger_event_line_disable(
  u32 line,
  enum exti_trigger_event event
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  switch (event)
  {
    case EXTI_TRIGGER_EVENT_RISING:
      EXTI->RTSR &= ~(1u << line);
      break;

    case EXTI_TRIGGER_EVENT_FALLING:
      EXTI->FTSR &= ~(1u << line);
      break;

    default:
      devmode_error_invalid_enum(enum exti_trigger_event, event);
      break;
  }
}

void
exti_trigger_software_interrupt_line(
  u32 line
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  EXTI->SWIER |= (1u << line);
}

u32
exti_is_trigger_request_pending(
  u32 line
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  return EXTI->PR & (1u << line);
}

void
exti_trigger_update_event_clear(
  u32 line
)
{
  devmode_assert_nonzero(STM32_EXTI_ALLOWED_LINES_BITMASK & (1u << line));
  EXTI->PR |= (1u << line);
}
