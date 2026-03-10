#include "synapse/stm32/drivers/rtc/rtc_v1.h"
#include "synapse/stm32/system/specs.h"
#include "libcom/sys/devmode.h"

typedef volatile struct rtc_registers_map rtc_periph;
rtc_periph* RTC = (rtc_periph*) (RTC_ADDR);

void
rtc_interrupt_enable(
  enum rtc_interrupt interrupt
)
{
  rtc_write_idle_wait();

  switch (interrupt)
  {
    case RTC_INTERRUPT_SECOND:
      RTC->CRH |= RTC_CRH_SECIE;
      break;

    case RTC_INTERRUPT_ALARM:
      RTC->CRH |= RTC_CRH_ALRIE;
      break;

    case RTC_INTERRUPT_OVERFLOW:
      RTC->CRH |= RTC_CRH_OWIE;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_interrupt, interrupt);
      break;
  }
}

void
rtc_interrupt_disable(
  enum rtc_interrupt interrupt
)
{
  switch (interrupt)
  {
    case RTC_INTERRUPT_SECOND:
      RTC->CRH &= ~RTC_CRH_SECIE;
      break;

    case RTC_INTERRUPT_ALARM:
      RTC->CRH &= ~RTC_CRH_ALRIE;
      break;

    case RTC_INTERRUPT_OVERFLOW:
      RTC->CRH &= ~RTC_CRH_OWIE;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_interrupt, interrupt);
      break;
  }
}

u32
rtc_is_flag_set(
  enum rtc_flag flag
)
{
  switch (flag)
  {
    case RTC_FLAG_SECOND:
      return RTC->CRL & RTC_CRL_SECF;

    case RTC_FLAG_ALARM:
      return RTC->CRL & RTC_CRL_ALRF;

    case RTC_FLAG_OVERFLOW:
      return RTC->CRL & RTC_CRL_OWF;

    case RTC_FLAG_SYNC:
      return RTC->CRL & RTC_CRL_RSF;

    case RTC_FLAG_CONFIGURATION:
      return RTC->CRL & RTC_CRL_CNF;

    case RTC_FLAG_WRITE_IDLE:
      return RTC->CRL & RTC_CRL_RTOFF;

    default:
      devmode_error_invalid_enum(enum rtc_flag, flag);
      return 0;
  }
}

void
rtc_flag_clear(
  enum rtc_flag flag
)
{
  rtc_write_idle_wait();

  switch (flag)
  {
    case RTC_FLAG_SECOND:
      RTC->CRL &= ~RTC_CRL_SECF;
      break;

    case RTC_FLAG_ALARM:
      RTC->CRL &= ~RTC_CRL_ALRF;
      break;

    case RTC_FLAG_OVERFLOW:
      RTC->CRL &= ~RTC_CRL_OWF;
      break;

    case RTC_FLAG_SYNC:
      RTC->CRL &= ~RTC_CRL_RSF;
      break;

    case RTC_FLAG_CONFIGURATION:
      RTC->CRL &= ~RTC_CRL_CNF;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_flag, flag);
      break;
  }
}

void
rtc_config_enable(void)
{
  rtc_write_idle_wait();
  RTC->CRL |= RTC_CRL_CNF;
}

void
rtc_config_disable(void)
{
  rtc_write_idle_wait();
  RTC->CRL &= ~RTC_CRL_CNF;
  rtc_write_idle_wait();
}

void
rtc_write_idle_wait(void)
{
  #ifndef NEX_BUILD_TESTS
  WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_WRITE_IDLE));
  #endif
}

void
rtc_set_prescaler(
  u32 prescaler
)
{
  rtc_write_idle_wait();
  RTC->PRLL = prescaler & RTC_PRLL_MASK;
  RTC->PRLH = prescaler >> RTC_PRLH_SHIFT;
}

u32
rtc_get_prescaler_div_low(void)
{
  return RTC->DIVL;
}

u32
rtc_get_prescaler_div_high(void)
{
  return RTC->DIVH;
}

u32
rtc_get_prescaler_divider(void)
{
  const u32 lsb = rtc_get_prescaler_div_low();
  const u32 msb = rtc_get_prescaler_div_high();

  return (msb << RTC_DIVH_SHIFT) | lsb;
}

void
rtc_set_counter(
  u32 counter
)
{
  rtc_write_idle_wait();
  RTC->CNTL = counter & RTC_CNTL_MASK;
  RTC->CNTH = (counter >> RTC_CNTH_SHIFT) & RTC_CNTH_MASK;
}

void
rtc_set_alarm(
  u32 alarm
)
{
  rtc_write_idle_wait();
  RTC->ALRL = alarm & RTC_ALRL_MASK;
  RTC->ALRH = (alarm >> RTC_ALRH_SHIFT) & RTC_ALRH_MASK;
}
