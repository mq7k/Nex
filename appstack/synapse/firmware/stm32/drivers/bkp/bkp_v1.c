#include "synapse/stm32/system/specs.h"
#include "synapse/stm32/drivers/bkp/bkp_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct bkp_registers_map bkp_periph;
bkp_periph* BKP = (bkp_periph*) (BKP_ADDR);

void
bkp_data_write(
  u32 idx,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, BKP_DR_MAX_IDX);
  volatile u32* reg = idx < 10 ? &BKP->DR0[idx] : &BKP->DR1[idx - 10];
  *reg = value;
}

u32
bkp_data_read(
  u32 idx
)
{
  return idx < 10 ? BKP->DR0[idx] : BKP->DR1[idx - 10];
}

void
bkp_set_rtc_calibration_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, BKP_RTCCR_CAL_MASK);
  constexpr u32 mask = BKP_RTCCR_CAL_MASK; 
  syn_set_register_bits(&BKP->RTCCR, mask, value);
}

void
bkp_rtc_calib_clock_output_enable(void)
{
  BKP->RTCCR |= BKP_RTCCR_CCO;
}

void
bkp_rtc_signal_output_enable(void)
{
  BKP->RTCCR |= BKP_RTCCR_ASOE;
}

void
bkp_set_rtc_output_signal(
  enum bkp_rtc_signal signal
)
{
  volatile u32* reg = &BKP->RTCCR;

  switch (signal)
  {
    case BKP_RTC_SIGNAL_ALARM:
      *reg &= ~BKP_RTCCR_ASOS;
      break;

    case BKP_RTC_SIGNAL_SECOND:
      *reg |= BKP_RTCCR_ASOS;
      break;

    default:
      devmode_error_invalid_enum(enum bkp_rtc_signal, signal);
      break;
  }
}

void
bkp_tamper_pin_enable(void)
{
  BKP->CR |= BKP_CR_TPE;
}

void
bkp_tamper_pin_disable(void)
{
  BKP->CR &= ~BKP_CR_TPE;
}

void
bkp_set_tamper_pin_active_level(
  enum bkp_tamper_pin_level level
)
{
  volatile u32* reg = &BKP->CR;

  switch (level)
  {
    case BKP_TAMPER_PIN_LEVEL_LOW:
      *reg |= BKP_CR_TPAL;
      break;

    case BKP_TAMPER_PIN_LEVEL_HIGH:
      *reg &= ~BKP_CR_TPAL;
      break;

    default:
      devmode_error_invalid_enum(enum bkp_tamper_pin_level, level);
      break;
  }
}

void
bkp_tamper_event_clear(void)
{
  BKP->CSR |= BKP_CSR_CTE;
}

void
bkp_tamper_interrupt_clear(void)
{
  BKP->CSR |= BKP_CSR_CTI;
}

void
bkp_tamper_interrupt_enable(void)
{
  BKP->CSR |= BKP_CSR_TPIE;
}

void
bkp_tamper_interrupt_disable(void)
{
  BKP->CSR &= ~BKP_CSR_TPIE;
}

u32
bkp_is_tamper_event_flag_set(void)
{
  return BKP->CSR & BKP_CSR_TEF;
}

u32
bkp_is_tamper_interrupt_flag_set(void)
{
  return BKP->CSR & BKP_CSR_TIF;
}
