#ifndef STM32_DRIVER_EXTI_H
#define STM32_DRIVER_EXTI_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct exti_registers_map
{
  u32 IMR;
  u32 EMR;
  u32 RTSR;
  u32 FTSR;
  u32 SWIER;
  u32 PR;
};

// API
enum exti_trigger_event
{
  EXTI_TRIGGER_EVENT_RISING,
  EXTI_TRIGGER_EVENT_FALLING
};

extern volatile struct exti_registers_map* EXTI;

void
exti_interrupt_line_enable(
  u32 line
);

void
exti_interrupt_line_disable(
  u32 line
);

void
exti_event_request_enable(
  u32 line
);

void
exti_event_request_disable(
  u32 line
);

void
exti_trigger_event_line_enable(
  u32 line,
  enum exti_trigger_event event
);

void
exti_trigger_event_line_disable(
  u32 line,
  enum exti_trigger_event event
);

void
exti_trigger_software_interrupt_line(
  u32 line
);

u32
exti_is_trigger_request_pending(
  u32 line
);

void
exti_trigger_update_event_clear(
  u32 line
);

END_DECLARATIONS

#endif
