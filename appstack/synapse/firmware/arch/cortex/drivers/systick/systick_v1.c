#include "synapse/arch/cortex/drivers/systick/systick_v1.h"
#include "libcom/sys/devmode.h"
#include "synapse/arch/cortex/common/memorymap.h"

typedef volatile struct systick_registers_map systick_periph;
systick_periph* SYSTICK = (systick_periph*) (ARCH_SYSTICK_ADDR);

void
systick_enable(void)
{
  SYSTICK->CSR |= SYSTICK_CSR_ENABLE;
}

void
systick_disable(void)
{
  SYSTICK->CSR &= ~SYSTICK_CSR_ENABLE;
}

void
systick_interrupt_enable(void)
{
  SYSTICK->CSR |= SYSTICK_CSR_TICKINT;
}

void
systick_interrupt_disable(void)
{
  SYSTICK->CSR &= ~SYSTICK_CSR_TICKINT;
}

void
systick_set_clock_source(
  enum systick_clock_source source
)
{
  volatile u32* reg = &SYSTICK->CSR;
  switch (source)
  {
    case SYSTICK_CLOCK_SOURCE_PROCESSOR:
      *reg |= SYSTICK_CSR_CLKSOURCE;
      break;

    case SYSTICK_CLOCK_SOURCE_EXTERNAL:
      *reg &= ~SYSTICK_CSR_CLKSOURCE;
      break;
  }
}

u32
systick_has_overflowed(void)
{
  return SYSTICK->CSR & SYSTICK_CSR_COUNTFLAG;
}

// RVR
void
systick_set_reload_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, SYSTICK_RVR_MASK);
  SYSTICK->RVR = value;
}

// CVR
void
systick_set_current_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, SYSTICK_CVR_MASK);
  SYSTICK->CVR = value;
}

u32
systick_get_current_value(void)
{
  constexpr u32 shift = SYSTICK_CVR_SHIFT;
  constexpr u32 mask = SYSTICK_CVR_MASK;
  return (SYSTICK->CVR >> shift) & mask;
}

// CALIB
u32
systick_get_calibration_value(void)
{
  constexpr u32 shift = SYSTICK_CALIB_TENMS_SHIFT;
  constexpr u32 mask = SYSTICK_CALIB_TENMS_MASK;
  return (SYSTICK->CALIB >> shift) & mask;
}

u32
systick_is_calibration_value_available(void)
{
  return SYSTICK->CALIB & SYSTICK_CALIB_SKEW;
}

u32
systick_has_reference_clock(void)
{
  return SYSTICK->CALIB & SYSTICK_CALIB_NOREF;
}
