#include "synapse/stm32/drivers/wwdg/wwdg_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "libcom/sys/devmode.h"

typedef volatile struct wwdg_registers_map wwdg_periph;
wwdg_periph* WWDG = (wwdg_periph*) (WWDG_ADDR);

void
wwdg_set_counter(
  u32 counter
)
{
  devmode_assert_lower_or_eq(counter, WWDG_CR_T_MASK);
  constexpr u32 shift = WWDG_CR_T_SHIFT;
  constexpr u32 mask = WWDG_CR_T_MASK << shift;
  volatile u32* reg = &WWDG->CR;
  syn_set_register_bits(reg, mask, counter << shift);
}

u32
wwdg_get_counter(void)
{
  return WWDG->CR & WWDG_CR_T_MASK;
}

void
wwdg_start(void)
{
  WWDG->CR |= WWDG_CR_WDGA;
}

void
wwdg_set_upper_threshold(
  u32 threshold
)
{
  devmode_assert_lower_or_eq(threshold, WWDG_CFR_W_MASK);
  constexpr u32 shift = WWDG_CFR_W_SHIFT;
  constexpr u32 mask = WWDG_CFR_W_MASK << shift;
  volatile u32* reg = &WWDG->CFR;
  syn_set_register_bits(reg, mask, threshold << shift);
}

void
wwdg_set_prescaler(
  enum wwdg_prescaler prescaler
)
{
  constexpr u32 shift = WWDG_CFR_WDGTB_SHIFT;
  constexpr u32 mask = WWDG_CFR_WDGTB_MASK << shift;
  volatile u32* reg = &WWDG->CFR;

  switch (prescaler)
  {
    case WWDG_PRESCALER_DIV1:
      *reg &= ~mask;
      break;

    case WWDG_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, WWDG_CFR_WDGTB_DIV2 << shift);
      break;

    case WWDG_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, WWDG_CFR_WDGTB_DIV4 << shift);
      break;

    case WWDG_PRESCALER_DIV8:
      *reg |= (WWDG_CFR_WDGTB_DIV8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum wwdg_prescaler, prescaler);
      break;
  }
}

void
wwdg_early_wakeup_interrupt_enable(void)
{
  WWDG->CFR |= WWDG_CFR_EWI;
}

void
wwdg_early_wakeup_interrupt_disable(void)
{
  WWDG->CFR &= ~WWDG_CFR_EWI;
}

u32
wwdg_is_early_wakeup_interrupt_flag_set(void)
{
  return WWDG->SR & WWDG_SR_EWIF;
}

void
wwdg_early_wakeup_interrupt_flag_clear(void)
{
  WWDG->SR &= ~WWDG_SR_EWIF;
}
