#include "synapse/stm32/drivers/iwdg/iwdg_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct iwdg_registers_map iwdg_periph;
iwdg_periph* IWDG = (iwdg_periph*) (IWDG_ADDR);

void
iwdg_reset(void)
{
  // TODO: Is it safe to override bits 31:16?
  IWDG->KR = IWDG_KR_KEY_RESET;
}

void
iwdg_write_unlock(void)
{
  // TODO: Is it safe to override bits 31:16?
  IWDG->KR = IWDG_KR_KEY_WRITE_UNLOCK;
}

void
iwdg_start(void)
{
  // TODO: Is it safe to override bits 31:16?
  IWDG->KR = IWDG_KR_KEY_START;
}

void
iwdg_set_prescaler(
  enum iwdg_prescaler prescaler
)
{
  constexpr u32 shift = IWDG_PR_PSC_SHIFT;
  constexpr u32 mask = IWDG_PR_PSC_MASK << shift;
  volatile u32* reg = &IWDG->PR;
  switch (prescaler)
  {
    case IWDG_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, IWDG_PR_PSC_DIV4 << shift);
      break;

    case IWDG_PRESCALER_DIV8:
      syn_set_register_bits(reg, mask, IWDG_PR_PSC_DIV8 << shift);
      break;

    case IWDG_PRESCALER_DIV16:
      syn_set_register_bits(reg, mask, IWDG_PR_PSC_DIV16 << shift);
      break;

    case IWDG_PRESCALER_DIV32:
      syn_set_register_bits(reg, mask, IWDG_PR_PSC_DIV32 << shift);
      break;

    case IWDG_PRESCALER_DIV64:
      syn_set_register_bits(reg, mask, IWDG_PR_PSC_DIV64 << shift);
      break;

    case IWDG_PRESCALER_DIV128:
      syn_set_register_bits(reg, mask, IWDG_PR_PSC_DIV128 << shift);
      break;

    case IWDG_PRESCALER_DIV256:
      syn_set_register_bits(reg, mask, IWDG_PR_PSC_DIV256 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum iwdg_prescaler, prescaler);
      break;
  }
}

void
iwdg_set_reload_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, IWDG_RLR_RL_MASK);

  constexpr u32 shift = IWDG_RLR_RL_SHIFT;
  constexpr u32 mask = IWDG_RLR_RL_MASK << shift;
  volatile u32* reg = &IWDG->RLR;
  syn_set_register_bits(reg, mask, value << shift);
}

u32
iwdg_is_flag_set(
  enum iwdg_flag flag
)
{
  switch (flag)
  {
    case IWDG_FLAG_PRESCALER_UPDATE:
      return IWDG->SR & IWDG_SR_PVU;

    case IWDG_FLAG_COUNTER_UPDATE:
      return IWDG->SR & IWDG_SR_RVU;

    default:
      devmode_error_invalid_enum(enum iwdg_flag, flag);
      return 0;
  }
}
