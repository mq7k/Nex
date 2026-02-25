#include "synapse/stm32/drivers/rtc/rtc_v2.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct rtc_registers_map rtc_periph;
rtc_periph* RTC = (rtc_periph*) (RTC_ADDR);

// static enum rtc_dr_wdu
// convert_rtc_weekday_api_to_impl(
//   enum rtc_weekday day
// )
// {
//   switch (day)
//   {
//     case RTC_WEEKDAY_MONDAY:
//       return RTC_DR_WDU_MONDAY;
//
//     case RTC_WEEKDAY_TUESDAY:
//       return RTC_DR_WDU_TUESDAY;
//
//     case RTC_WEEKDAY_WEDNESDAY:
//       return RTC_DR_WDU_WEDNESDAY;
//
//     case RTC_WEEKDAY_THURSDAY:
//       return RTC_DR_WDU_THURSDAY;
//
//     case RTC_WEEKDAY_FRIDAY:
//       return RTC_DR_WDU_FRIDAY;
//
//     case RTC_WEEKDAY_SATURDAY:
//       return RTC_DR_WDU_SATURDAY;
//
//     case RTC_WEEKDAY_SUNDAY:
//       return RTC_DR_WDU_SUNDAY;
//
//     default:
//       devmode_error_invalid_enum(enum rtc_weekday, day);
//       return 0;
//   }
// }

void
rtc_set_calendar_time(
  struct rtc_calendar_time* time
)
{
  devmode_assert_lower_or_eq(time->seconds, RTC_MAX_SECONDS);
  devmode_assert_lower_or_eq(time->minutes, RTC_MAX_MINUTES);
  devmode_assert_lower_or_eq(time->hours, RTC_MAX_HOURS);

  u32 value = 0;
  value |= (syn_dec_to_bcd(time->seconds) << RTC_TR_SU_SHIFT);
  value |= (syn_dec_to_bcd(time->minutes) << RTC_TR_MNU_SHIFT);
  value |= (syn_dec_to_bcd(time->hours) << RTC_TR_HU_SHIFT);
  RTC->TR = value;
}

void
rtc_set_calendar_date(
  struct rtc_calendar_date* date
)
{
  devmode_assert_lower_or_eq(date->date, RTC_MAX_DATE);
  devmode_assert_lower_or_eq(date->month, RTC_MAX_MONTH);
  devmode_assert_lower_or_eq(date->year - RTC_YEAR_OFFSET, RTC_MAX_YEAR);

  u32 value = 0;
  value |= (syn_dec_to_bcd(date->date) << RTC_DR_DU_SHIFT);
  value |= (syn_dec_to_bcd(date->month) << RTC_DR_MU_SHIFT);
  value |= (date->day << RTC_DR_WDU_SHIFT);
  value |= (syn_dec_to_bcd(date->year - RTC_YEAR_OFFSET) << RTC_DR_YU_SHIFT);
  RTC->DR = value;
}

void
rtc_get_calendar_time(
  struct rtc_calendar_time* time
)
{
  const u32 reg = RTC->TR;
  u32 unit;
  u32 tens;

  unit = (reg >> 0) & 0xf;
  tens = (reg >> 4) & 0x7;
  time->seconds = syn_bcd_to_dec(tens, unit);

  unit = (reg >> 8) & 0xf;
  tens = (reg >> 12) & 0x7;
  time->minutes = syn_bcd_to_dec(tens, unit);

  unit = (reg >> 16) & 0xf;
  tens = (reg >> 20) & 0x3;
  time->hours = syn_bcd_to_dec(tens, unit);
}

void
rtc_get_calendar_date(
  struct rtc_calendar_date* date
)
{
  const u32 reg = RTC->DR;
  u32 unit;
  u32 tens;

  unit = (reg >> 0) & 0xf;
  tens = (reg >> 4) & 0xf;
  date->date = syn_bcd_to_dec(tens, unit);

  unit = (reg >> 8) & 0xf;
  tens = (reg >> 12) & 0x1;
  date->month = syn_bcd_to_dec(tens, unit);

  date->day = (reg >> 13) & 0x7;

  unit = (reg >> 16) & 0xf;
  tens = (reg >> 20) & 0xf;
  date->year = RTC_YEAR_OFFSET + syn_bcd_to_dec(tens, unit);
}

void
rtc_set_calendar_time_format(
  enum rtc_time_format format
)
{
  volatile u32* reg = &RTC->TR;
  switch (format)
  {
    case RTC_TIME_FORMAT_24HOURS:
      *reg &= ~RTC_TR_PM;
      break;

    case RTC_TIME_FORMAT_12HOURS:
      *reg |= RTC_TR_PM;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_time_format, format);
      break;
  }
}

void
rtc_set_wakeup_clock(
  enum rtc_wakeup_clock clock
)
{
  constexpr u32 shift = RTC_CR_WUCKSEL_SHIFT;
  constexpr u32 mask = RTC_CR_WUCKSEL_MASK << shift;
  volatile u32* reg = &RTC->CR;

  switch (clock)
  {
    case RTC_WAKEUP_CLOCK_DIV16:
      *reg &= ~mask;
      break;

    case RTC_WAKEUP_CLOCK_DIV8:
      syn_set_register_bits(reg, mask, RTC_CR_WUCKSEL_DIV8 << shift);
      break;

    case RTC_WAKEUP_CLOCK_DIV4:
      syn_set_register_bits(reg, mask, RTC_CR_WUCKSEL_DIV4 << shift);
      break;

    case RTC_WAKEUP_CLOCK_DIV2:
      syn_set_register_bits(reg, mask, RTC_CR_WUCKSEL_DIV2 << shift);
      break;

    case RTC_WAKEUP_CLOCK_NODIV:
      syn_set_register_bits(reg, mask, RTC_CR_WUCKSEL_NODIV << shift);
      break;

    case RTC_WAKEUP_CLOCK_NODIV_OFFSET:
      syn_set_register_bits(reg, mask, RTC_CR_WUCKSEL_NODIV_OFFSET << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_wakeup_clock, clock);
  }
}

void
rtc_set_timestamp_event_edge(
  enum rtc_event_edge edge
)
{
  volatile u32* reg = &RTC->CR;
  switch (edge)
  {
    case RTC_EVENT_EDGE_RISING:
      *reg &= ~RTC_CR_TSEDGE;
      break;

    case RTC_EVENT_EDGE_FALLING:
      *reg |= RTC_CR_TSEDGE;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_event_edge, edge);
      break;
  }
}

void
rtc_reference_clock_enable(void)
{
  RTC->CR |= RTC_CR_REFCKON;
}

void
rtc_reference_clock_disable(void)
{
  RTC->CR &= ~RTC_CR_REFCKON;
}

void
rtc_shadow_register_bypass_enable(void)
{
  RTC->CR |= RTC_CR_BYPSHAD;
}

void
rtc_shadow_register_bypass_disable(void)
{
  RTC->CR &= ~RTC_CR_BYPSHAD;
}

void
rtc_set_time_format(
  enum rtc_time_format format
)
{
  volatile u32* reg = &RTC->CR;
  switch (format)
  {
    case RTC_TIME_FORMAT_24HOURS:
      *reg &= ~RTC_CR_FMT;
      break;

    case RTC_TIME_FORMAT_12HOURS:
      *reg |= RTC_CR_FMT;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_time_format, format);
      break;
  }
}

#if defined(STM32_RTC_COARSE_DIGITAL_CALIB)
void
rtc_coarse_digital_calib_enable(void)
{
  RTC->CR |= RTC_CR_DCE;
}

void
rtc_coarse_digital_calib_disable(void)
{
  RTC->CR &= ~RTC_CR_DCE;
}
#endif

void
rtc_alarm_enable(
  enum rtc_alarm alarm
)
{
  volatile u32* reg = &RTC->CR;
  switch (alarm)
  {
    case RTC_ALARMA:
      *reg |= RTC_CR_ALRAE;
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_ALARMB:
      *reg |= RTC_CR_ALRBE;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_alarm, alarm);
      break;
  }
}

void
rtc_alarm_disable(
  enum rtc_alarm alarm
)
{
  volatile u32* reg = &RTC->CR;
  switch (alarm)
  {
    case RTC_ALARMA:
      *reg &= ~RTC_CR_ALRAE;
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_ALARMB:
      *reg &= ~RTC_CR_ALRBE;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_alarm, alarm);
      break;
  }
}

void
rtc_wakeup_timer_enable(void)
{
  RTC->CR |= RTC_CR_WUTE;
}

void
rtc_wakeup_timer_disable(void)
{
  RTC->CR &= ~RTC_CR_WUTE;
}

void
rtc_timestamp_enable(void)
{
  RTC->CR |= RTC_CR_TSE;
}

void
rtc_timestamp_disable(void)
{
  RTC->CR &= ~RTC_CR_TSE;
}

void
rtc_interrupt_enable(
  enum rtc_interrupt interrupt
)
{
  switch (interrupt)
  {
    case RTC_INTERRUPT_ALARMA:
      RTC->CR |= RTC_CR_ALRAIE;
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_INTERRUPT_ALARMB:
      RTC->CR |= RTC_CR_ALRBIE;
      break;
#endif

    case RTC_INTERRUPT_WAKEUP_TIMER:
      RTC->CR |= RTC_CR_WUTIE;
      break;

    case RTC_INTERRUPT_TIMESTAMP:
      RTC->CR |= RTC_CR_TSIE;
      break;

    case RTC_INTERRUPT_TAMPER1:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR |= RTC_TAMPCR_TAMP1IE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR |= RTC_TAFCR_TAMPIE;
#endif
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_INTERRUPT_TAMPER2:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR |= RTC_TAMPCR_TAMP2IE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR |= RTC_TAFCR_TAMPIE; 
#endif
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_INTERRUPT_TAMPER3:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR |= RTC_TAMPCR_TAMP3IE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR |= RTC_TAFCR_TAMPIE;
#endif
      break;
#endif

    case RTC_INTERRUPT_TAMPER_ALL:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR |= RTC_TAMPCR_TAMPIE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR |= RTC_TAFCR_TAMPIE;
#endif
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
    case RTC_INTERRUPT_ALARMA:
      RTC->CR &= ~RTC_CR_ALRAIE;
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_INTERRUPT_ALARMB:
      RTC->CR &= ~RTC_CR_ALRBIE;
      break;
#endif

    case RTC_INTERRUPT_WAKEUP_TIMER:
      RTC->CR &= ~RTC_CR_WUTIE;
      break;

    case RTC_INTERRUPT_TIMESTAMP:
      RTC->CR &= ~RTC_CR_TSIE;
      break;

    case RTC_INTERRUPT_TAMPER1:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR &= ~RTC_TAMPCR_TAMP1IE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR &= ~RTC_TAFCR_TAMPIE;
#endif
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_INTERRUPT_TAMPER2:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR &= ~RTC_TAMPCR_TAMP2IE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR &= ~RTC_TAFCR_TAMPIE; 
#endif
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_INTERRUPT_TAMPER3:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR &= ~RTC_TAMPCR_TAMP3IE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR &= ~RTC_TAFCR_TAMPIE;
#endif
      break;
#endif

    case RTC_INTERRUPT_TAMPER_ALL:
#if defined(STM32_RTC_TAMPCR_REG)
      RTC->TAMPCR &= ~RTC_TAMPCR_TAMPIE;
#elif defined(STM32_RTC_TAFCR_REG)
      RTC->TAFCR &= ~RTC_TAFCR_TAMPIE;
#endif
      break;

    default:
      devmode_error_invalid_enum(enum rtc_interrupt, interrupt);
      break;
  }
}

void
rtc_set_time_offset(
  enum rtc_time_offset offset
)
{
  volatile u32* reg = &RTC->CR;
  switch (offset)
  {
    case RTC_TIME_OFFSET_ADD_1HOUR:
      *reg |= RTC_CR_ADD1H;
      break;

    case RTC_TIME_OFFSET_SUB_1HOUR:
      *reg |= RTC_CR_SUB1H;
      break;

    case RTC_TIME_OFFSET_OFF:
      *reg &= ~(RTC_CR_ADD1H | RTC_CR_SUB1H);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_time_offset, offset);
      break;
  }
}

void
rtc_daylight_time_change_save(void)
{
  RTC->CR |= RTC_CR_BKP;
}

void
rtc_set_calibration_output(
  enum rtc_calibration_output output
)
{
  volatile u32* reg = &RTC->CR;
  switch (output)
  {
    case RTC_CALIBRATION_OUTPUT_512HZ:
      *reg &= ~RTC_CR_COSEL;
      break;

    case RTC_CALIBRATION_OUTPUT_1HZ:
      *reg |= RTC_CR_COSEL;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_calibration_output, output);
      break;
  }
}

void
rtc_set_alarm_output_polarity(
  enum rtc_alarm_output_polarity polarity
)
{
  volatile u32* reg = &RTC->CR;
  switch (polarity)
  {
    case RTC_ALARM_OUTPUT_POLARITY_HIGH:
      *reg &= ~RTC_CR_POL;
      break;

    case RTC_ALARM_OUTPUT_POLARITY_LOW:
      *reg |= RTC_CR_POL;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_alarm_output_polarity, polarity);
      break;
  }
}

void
rtc_set_output(
  enum rtc_output output
)
{
  constexpr u32 shift = RTC_CR_OSEL_SHIFT;
  constexpr u32 mask = RTC_CR_OSEL_MASK << shift;
  volatile u32* reg = &RTC->CR;

  switch (output)
  {
    case RTC_OUTPUT_OFF:
      *reg &= ~mask;
      break;

    case RTC_OUTPUT_ALARMA:
      syn_set_register_bits(reg, mask, RTC_CR_OSEL_ALARMA << shift);
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_OUTPUT_ALARMB:
      syn_set_register_bits(reg, mask, RTC_CR_OSEL_ALARMB << shift);
      break;
#endif

    case RTC_OUTPUT_WAKEUP:
      *reg |= (RTC_CR_OSEL_WAKEUP << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_output, output);
      break;
  }
}

void
rtc_calibration_output_enable(void)
{
  RTC->CR |= RTC_CR_COE;
}

void
rtc_calibration_output_disable(void)
{
  RTC->CR &= ~RTC_CR_COE;
}

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
void
rtc_internal_event_timestamp_enable(void)
{
  RTC->CR |= RTC_CR_ITSE;
}

void
rtc_internal_event_timestamp_disable(void)
{
  RTC->CR &= ~RTC_CR_ITSE;
}
#endif

u32
rtc_is_flag_set(
  enum rtc_flag flag
)
{
  volatile u32* reg = &RTC->ISR;
  switch (flag)
  {
    case RTC_FLAG_ALARMA_WRITE:
      return *reg & RTC_ISR_ALRAWF;

#if defined(STM32_RTC_ALARMB)
    case RTC_FLAG_ALARMB_WRITE:
      return *reg & RTC_ISR_ALRBWF;
#endif

    case RTC_FLAG_WAKEUP_TIMER_WRITE:
      return *reg & RTC_ISR_WUTWF;

    case RTC_FLAG_SHIFT_OP:
      return *reg & RTC_ISR_SHPF;

    case RTC_FLAG_INIT_STATUS:
      return *reg & RTC_ISR_INITS;

    case RTC_FLAG_SYNC:
      return *reg & RTC_ISR_RSF;

    case RTC_FLAG_INIT:
      return *reg & RTC_ISR_INITF;

    case RTC_FLAG_ALARMA:
      return *reg & RTC_ISR_ALRAF;

#if defined(STM32_RTC_ALARMB)
    case RTC_FLAG_ALARMB:
      return *reg & RTC_ISR_ALRBF;
#endif

    case RTC_FLAG_WAKEUP_TIMER:
      return *reg & RTC_ISR_WUTF;

    case RTC_FLAG_TIMESTAMP:
      return *reg & RTC_ISR_TSF;

    case RTC_FLAG_TIMESTAMP_OVERFLOW:
      return *reg & RTC_ISR_TSOVF;

    case RTC_FLAG_TAMPER1:
      return *reg & RTC_ISR_TAMP1F;

#if defined(STM32_RTC_TAMPER2)
    case RTC_FLAG_TAMPER2:
      return *reg & RTC_ISR_TAMP2F;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_FLAG_TAMPER3:
      return *reg & RTC_ISR_TAMP3F;
#endif

    case RTC_FLAG_RECALIB_PENDING:
      return *reg & RTC_ISR_RECALPF;

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
    case RTC_FLAG_INTERNAL_TIMESTAMP_EVENT:
      return *reg & RTC_ISR_ITSF;
#endif

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
  volatile u32* reg = &RTC->ISR;
  switch (flag)
  {
    case RTC_FLAG_SYNC:
      *reg &= ~RTC_ISR_RSF;
      break;

    case RTC_FLAG_ALARMA:
      *reg &= ~RTC_ISR_ALRAF;
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_FLAG_ALARMB:
      *reg &= ~RTC_ISR_ALRBF;
      break;
#endif

    case RTC_FLAG_WAKEUP_TIMER:
      *reg &= ~RTC_ISR_WUTF;
      break;

    case RTC_FLAG_TIMESTAMP:
      *reg &= ~RTC_ISR_TSF;
      break;

    case RTC_FLAG_TIMESTAMP_OVERFLOW:
      *reg &= ~RTC_ISR_TSOVF;
      break;

    case RTC_FLAG_TAMPER1:
      *reg &= ~RTC_ISR_TAMP1F;
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_FLAG_TAMPER2:
      *reg &= ~RTC_ISR_TAMP2F;
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_FLAG_TAMPER3:
      *reg &= ~RTC_ISR_TAMP3F;
      break;
#endif

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
    case RTC_FLAG_INTERNAL_TIMESTAMP_EVENT:
      *reg &= ~RTC_ISR_ITSF;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_flag, flag);
      break;
  }
}

void
rtc_init_mode_enable(void)
{
  RTC->ISR |= RTC_ISR_INIT;
}

void
rtc_init_mode_disable(void)
{
  RTC->ISR &= ~RTC_ISR_INIT;
}

void
rtc_set_prescalers(
  struct rtc_prescalers* prescalers
)
{
  devmode_assert_lower_or_eq(prescalers->sync_prescaler, RTC_PRER_PREDIVS_MASK);
  devmode_assert_lower_or_eq(prescalers->async_prescaler, RTC_PRER_PREDIVA_MASK);
  RTC->PRER = (prescalers->sync_prescaler << RTC_PRER_PREDIVS_SHIFT);
  RTC->PRER |= (prescalers->async_prescaler << RTC_PRER_PREDIVA_SHIFT);
}

void
rtc_set_wakeup_auto_reload_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, RTC_WUTR_WUT_MASK);
  constexpr u32 shift = RTC_WUTR_WUT_SHIFT;
  constexpr u32 mask = RTC_WUTR_WUT_MASK << shift;
  volatile u32* reg = &RTC->WUTR;
  syn_set_register_bits(reg, mask, value << shift);
}

#if defined(STM32_RTC_EXTENDED)
void
rtc_set_digital_calib(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, RTC_CALIBR_DC_MASK);
  constexpr u32 shift = RTC_CALIBR_DC_SHIFT;
  constexpr u32 mask = RTC_CALIBR_DC_MASK << shift;
  volatile u32* reg = &RTC->CALIBR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
rtc_set_digital_calib_sign(
  enum rtc_digital_calib_sign sign
)
{
  volatile u32* reg = &RTC->CALIBR;
  switch (sign)
  {
    case RTC_DIGITAL_CALIB_SIGN_POSITIVE:
      *reg &= ~RTC_CALIBR_DCS;
      break;

    case RTC_DIGITAL_CALIB_SIGN_NEGATIVE:
      *reg |= RTC_CALIBR_DCS;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_digital_calib_sign, sign);
      break;
  }
}
#endif

void
rtc_set_alarm_time(
  enum rtc_alarm alarm,
  struct rtc_alarm_datetime* datetime
)
{
  devmode_assert_lower_or_eq(datetime->seconds, RTC_MAX_SECONDS);
  devmode_assert_lower_or_eq(datetime->minutes, RTC_MAX_MINUTES);
  devmode_assert_lower_or_eq(datetime->hours, RTC_MAX_HOURS);

  if (datetime->use_weekdays)
  {
    devmode_assert_lower_or_eq(datetime->date, RTC_MAX_WEEKDAY);
  }
  else
  {
    devmode_assert_lower_or_eq(datetime->date, RTC_MAX_DATE);
  }

  devmode_assert_lower_or_eq(datetime->alarm_masks, RTC_ALARM_MASK);
  devmode_assert_lower_or_eq(datetime->time_format, RTC_TIME_FORMAT_12HOURS);
  devmode_assert_lower_or_eq(datetime->use_weekdays, 1);

  u32 value = 0;
  value |= (syn_dec_to_bcd(datetime->seconds) << RTC_ALRMAR_SU_SHIFT);
  value |= (syn_dec_to_bcd(datetime->minutes) << RTC_ALRMAR_MNU_SHIFT);
  value |= (syn_dec_to_bcd(datetime->hours) << RTC_ALRMAR_HU_SHIFT);
  value |= (syn_dec_to_bcd(datetime->date) << RTC_ALRMAR_DU_SHIFT);
  value |= ((u32) datetime->use_weekdays * (u32) RTC_ALRMAR_WDSEL);

  value |= ((datetime->alarm_masks >> 0) & 0x1) << 7;
  value |= ((datetime->alarm_masks >> 1) & 0x1) << 15;
  value |= ((datetime->alarm_masks >> 2) & 0x1) << 23;
  value |= ((datetime->alarm_masks >> 3) & 0x1) << 31;

  value |= (datetime->time_format * RTC_TIME_FORMAT_12HOURS);

  switch (alarm)
  {
    case RTC_ALARMA:
      // while ((RTC->ISR & (1u << 1)) == 0);
      WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE));
      RTC->ALRMAR = value;
      break;
    
#if defined(STM32_RTC_ALARMB)
    case RTC_ALARMB:
      // while ((RTC->ISR & (1u << 2)) == 0);
      WAIT_UNTIL(rtc_is_flag_set(RTC_FLAG_ALARMA_WRITE));
      RTC->ALRMBR = value;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_alarm, alarm);
      break;
  }
}

void
rtc_set_alarm_time_format(
  enum rtc_alarm alarm,
  enum rtc_time_format format
)
{
#if defined(STM32_RTC_ALARMB)
  devmode_assert_lower_or_eq(alarm, RTC_ALARMB);
  volatile u32* reg = alarm == RTC_ALARMA ? &RTC->ALRMAR : &RTC->ALRMBR;
#else
  devmode_assert_lower_or_eq(alarm, RTC_ALARMA);
  volatile u32* reg = &RTC->ALRMAR;
  (void) alarm;
#endif

  switch (format)
  {
    case RTC_TIME_FORMAT_24HOURS:
      *reg &= ~RTC_ALRMAR_PM;
      break;

    case RTC_TIME_FORMAT_12HOURS:
      *reg |= RTC_ALRMAR_PM;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_time_format, format);
      break;
  }
}

void
rtc_alarm_compare_enable(
  enum rtc_alarm alarm,
  enum rtc_alarm_compare compare
)
{
#if defined(STM32_RTC_ALARMB)
  devmode_assert_lower_or_eq(alarm, RTC_ALARMB);
  volatile u32* reg = alarm == RTC_ALARMA ? &RTC->ALRMAR : &RTC->ALRMBR;
#else
  devmode_assert_lower_or_eq(alarm, RTC_ALARMA);
  volatile u32* reg = &RTC->ALRMAR;
  (void) alarm;
#endif

  switch (compare)
  {
    case RTC_ALARM_COMPARE_SECONDS:
      *reg |= RTC_ALRMAR_MSK1;
      break;

    case RTC_ALARM_COMPARE_MINUTES:
      *reg |= RTC_ALRMAR_MSK2;
      break;

    case RTC_ALARM_COMPARE_HOURS:
      *reg |= RTC_ALRMAR_MSK3;
      break;

    case RTC_ALARM_COMPARE_DATE:
      *reg |= RTC_ALRMAR_MSK4;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_alarm_compare, compare);
      break;
  }
}

void
rtc_alarm_compare_disable(
  enum rtc_alarm alarm,
  enum rtc_alarm_compare compare
)
{
#if defined(STM32_RTC_ALARMB)
  devmode_assert_lower_or_eq(alarm, RTC_ALARMB);
  volatile u32* reg = alarm == RTC_ALARMA ? &RTC->ALRMAR : &RTC->ALRMBR;
#else
  devmode_assert_lower_or_eq(alarm, RTC_ALARMA);
  volatile u32* reg = &RTC->ALRMAR;
  (void) alarm;
#endif

  switch (compare)
  {
    case RTC_ALARM_COMPARE_SECONDS:
      *reg &= ~RTC_ALRMAR_MSK1;
      break;

    case RTC_ALARM_COMPARE_MINUTES:
      *reg &= ~RTC_ALRMAR_MSK2;
      break;

    case RTC_ALARM_COMPARE_HOURS:
      *reg &= ~RTC_ALRMAR_MSK3;
      break;

    case RTC_ALARM_COMPARE_DATE:
      *reg &= ~RTC_ALRMAR_MSK4;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_alarm_compare, compare);
      break;
  }
}

void
rtc_set_datetime_type(
  enum rtc_alarm alarm,
  enum rtc_datetime_type type
)
{
#if defined(STM32_RTC_ALARMB)
  devmode_assert_lower_or_eq(alarm, RTC_ALARMB);
  volatile u32* reg = alarm == RTC_ALARMA ? &RTC->ALRMAR : &RTC->ALRMBR;
#else
  devmode_assert_lower_or_eq(alarm, RTC_ALARMA);
  volatile u32* reg = &RTC->ALRMAR;
  (void) alarm;
#endif

  switch (type)
  {
    case RTC_DATETIME_TYPE_DATE:
      *reg &= ~RTC_ALRMAR_WDSEL;
      break;

    case RTC_DATETIME_TYPE_WEEKDAY:
      *reg |= RTC_ALRMAR_WDSEL;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_datetime_type, type);
      break;
  }
}

void
rtc_unlock_write_protection(void)
{
  RTC->WPR = RTC_WPR_KEY1;
  RTC->WPR = RTC_WPR_KEY2;
}

u32
rtc_get_async_prescaler_subsecond_value(void)
{
  constexpr u32 shift = RTC_SSR_SS_SHIFT;
  constexpr u32 mask = RTC_SSR_SS_MASK;
  volatile u32* reg = &RTC->SSR;
  return (*reg >> shift) & mask;
}

void
rtc_set_subsecond_value(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, RTC_SHIFTR_SUBFS_MASK);
  constexpr u32 shift = RTC_SHIFTR_SUBFS_SHIFT;
  constexpr u32 mask = RTC_SHIFTR_SUBFS_MASK << shift;
  volatile u32* reg = &RTC->SHIFTR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
rtc_set_seconds_offset(
  u32 fraction,
  u32 add_1second
)
{
  devmode_assert_lower_or_eq(fraction, RTC_SHIFTR_SUBFS_MASK);
  devmode_assert_lower_or_eq(add_1second, 1);
  constexpr u32 shift = RTC_SHIFTR_SUBFS_SHIFT;
  constexpr u32 mask = RTC_SHIFTR_SUBFS_MASK << shift;
  volatile u32* reg = &RTC->SHIFTR;
  u32 res = fraction | (add_1second * RTC_SHIFTR_ADD1S);
  syn_set_register_bits(reg, mask, res << shift);
}

void
rtc_get_tamper_time(
  struct rtc_calendar_time* time
)
{
  const u32 reg = RTC->TSTR;
  u32 unit;
  u32 tens;

  unit = (reg >> 0) & 0xf;
  tens = (reg >> 4) & 0x7;
  time->seconds = syn_bcd_to_dec(tens, unit);

  unit = (reg >> 8) & 0xf;
  tens = (reg >> 12) & 0x7;
  time->minutes = syn_bcd_to_dec(tens, unit);

  unit = (reg >> 16) & 0xf;
  tens = (reg >> 20) & 0x3;
  time->hours = syn_bcd_to_dec(tens, unit);
}

void
rtc_get_tamper_date(
  struct rtc_calendar_date* date
)
{
  const u32 reg = RTC->DR;
  u32 unit;
  u32 tens;

  unit = (reg >> 0) & 0xf;
  tens = (reg >> 4) & 0xf;
  date->date = syn_bcd_to_dec(tens, unit);

  unit = (reg >> 8) & 0xf;
  tens = (reg >> 12) & 0x1;
  date->month = syn_bcd_to_dec(tens, unit);

  date->day = (reg >> 13) & 0x7;

  unit = (reg >> 16) & 0xf;
  tens = (reg >> 20) & 0xf;
  date->year = RTC_YEAR_OFFSET + syn_bcd_to_dec(tens, unit);
}

u32
rtc_get_timestamp_format(void)
{
  return RTC->TSTR & RTC_TSTR_PM;
}

u32
rtc_get_timestamp_subsecond(void)
{
  constexpr u32 shift = RTC_TSSSR_SS_SHIFT;
  constexpr u32 mask = RTC_TSSSR_SS_MASK << shift;
  volatile u32* reg = &RTC->TSSSR;
  return (*reg >> shift) & mask;
}

void
rtc_set_calibration_minus(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, RTC_CALR_CALM_MASK);
  constexpr u32 shift = RTC_CALR_CALM_SHIFT;
  constexpr u32 mask = RTC_CALR_CALM_MASK << shift;
  volatile u32* reg = &RTC->CALR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
rtc_set_calibration_cycle_period(
  enum rtc_calibration_cycle_period period
)
{
  volatile u32* reg = &RTC->CALR;
  switch (period)
  {
    case RTC_CALIBRATION_CYCLE_PERIOD_16SECONDS:
      *reg |= RTC_CALR_CALW16;
      break;

    case RTC_CALIBRATION_CYCLE_PERIOD_8SECODNS:
      *reg |= RTC_CALR_CALW8;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_calibration_cycle_period, period);
      break;
  }
}

void
rtc_increase_frequency_enable(void)
{
  RTC->CALR |= RTC_CALR_CALP;
}

void
rtc_increase_frequency_disable(void)
{
  RTC->CALR &= ~RTC_CALR_CALP;
}

#if defined(STM32_RTC_TAFCR_REG)

void
rtc_tamper_enable(
  enum rtc_tamper tamper
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (tamper)
  {
    case RTC_TAMPER1:
      *reg |= RTC_TAFCR_TAMP1E;
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      *reg |= RTC_TAFCR_TAMP2E;
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      *reg |= RTC_TAFCR_TAMP3E;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_tamper, tamper);
      break;
  }
}

void
rtc_tamper_disable(
  enum rtc_tamper tamper
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (tamper)
  {
    case RTC_TAMPER1:
      *reg &= ~RTC_TAFCR_TAMP1E;
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      *reg &= ~RTC_TAFCR_TAMP2E;
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      *reg &= ~RTC_TAFCR_TAMP3E;
      break;

#endif

    default:
      devmode_error_invalid_enum(enum rtc_tamper, tamper);
      break;
  }
}

void
rtc_set_tamper_active_level(
  enum rtc_tamper tamper,
  enum rtc_tamper_active_level level
)
{
  const u32 bit = level == RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH ||
            level == RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE;

  volatile u32* reg = &RTC->TAFCR;
  switch (tamper)
  {
    case RTC_TAMPER1:
      if (bit)
      {
        *reg |= RTC_TAFCR_TAMP1TRG;
      }
      else
      {
        *reg &= ~RTC_TAFCR_TAMP1TRG;
      }
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      if (bit)
      {
        *reg |= RTC_TAFCR_TAMP2TRG;
      }
      else
      {
        *reg &= ~RTC_TAFCR_TAMP2TRG;
      }
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      if (bit)
      {
        *reg |= RTC_TAFCR_TAMP3TRG;
      }
      else
      {
        *reg &= ~RTC_TAFCR_TAMP3TRG;
      }
      break;

#endif
    default:
      devmode_error_invalid_enum(enum rtc_tamper, tamper);
      break;
  }
}

void
rtc_timestamp_on_tamper_event_enable(void)
{
  RTC->TAFCR |= RTC_TAFCR_TAMPTS;
}

void
rtc_timestamp_on_tamper_event_disable(void)
{
  RTC->TAFCR &= ~RTC_TAFCR_TAMPTS;
}

void
rtc_set_tamper_sampling_frequency(
  enum rtc_tamper_sampling_frequency frequency
)
{
  constexpr u32 shift = RTC_TAFCR_TAMPFREQ_SHIFT;
  constexpr u32 mask = RTC_TAFCR_TAMPFREQ_MASK << shift;
  volatile u32* reg = &RTC->TAFCR;

  switch (frequency)
  {
    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768:
      *reg &= ~mask;
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFREQ_DIV16384 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFREQ_DIV8192 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFREQ_DIV4096 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFREQ_DIV2048 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFREQ_DIV1024 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV512:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFREQ_DIV512 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV256:
      *reg |= (RTC_TAFCR_TAMPFREQ_DIV256 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_tamper_sampling_frequency, frequency);
      break;
  }
}

void
rtc_set_tamper_filter_count(
  enum rtc_tamper_filter_count count
)
{
  constexpr u32 shift = RTC_TAFCR_TAMPFLT_SHIFT;
  constexpr u32 mask = RTC_TAFCR_TAMPFLT_MASK << shift;
  volatile u32* reg = &RTC->TAFCR;

  switch (count)
  {
    case RTC_TAMPER_FILTER_COUNT_NOSKIP:
      *reg &= ~mask;
      break;

    case RTC_TAMPER_FILTER_COUNT_SKIP2:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFLT_COUNT2 << shift);
      break;

    case RTC_TAMPER_FILTER_COUNT_SKIP4:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFLT_COUNT4 << shift);
      break;

    case RTC_TAMPER_FILTER_COUNT_SKIP8:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPFLT_COUNT8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_tamper_filter_count, count);
      break;
  }
}

void
rtc_set_tamper_precharge_duration(
  enum rtc_tamper_precharge_duration duration
)
{
  constexpr u32 shift = RTC_TAFCR_TAMPPRCH_SHIFT;
  constexpr u32 mask = RTC_TAFCR_TAMPPRCH_MASK << shift;
  volatile u32* reg = &RTC->TAFCR;
  switch (duration)
  {
    case RTC_TAMPER_PRECHARGE_DURATION_1CYCLE:
      *reg &= ~mask;
      break;

    case RTC_TAMPER_PRECHARGE_DURATION_2CYCLES:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPPRCH_2CYCLES << shift);
      break;

    case RTC_TAMPER_PRECHARGE_DURATION_4CYCLES:
      syn_set_register_bits(reg, mask, RTC_TAFCR_TAMPPRCH_4CYCLES << shift);
      break;

    case RTC_TAMPER_PRECHARGE_DURATION_8CYCLES:
      *reg |= (RTC_TAFCR_TAMPPRCH_8CYCLES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_tamper_precharge_duration, duration);
      break;
  }
}

void
rtc_tamper_pullup_enable(void)
{
  RTC->TAFCR &= ~RTC_TAFCR_TAMPPUDIS;
}

void
rtc_tamper_pullup_disable(void)
{
  RTC->TAFCR |= RTC_TAFCR_TAMPPUDIS;
}

#if defined(STM32_RTC_TAMPER1_MAPPING)
void
rtc_set_tamper_mapping(
  enum rtc_tamper_mapping mapping
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (mapping)
  {
    case RTC_TAMPER_MAPPING_AF1:
      *reg &= ~RTC_TAFCR_TAMP1INSEL;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_tamper_mapping, mapping);
      break;
  }
}
#endif

#if defined(STM32_RTC_TIMESTAMP_MAPPING)
void
rtc_set_timestamp_mapping(
  enum rtc_timestamp_mapping mapping
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (mapping)
  {
    case RTC_TIMESTAMP_MAPPING_AF1:
      *reg &= ~RTC_TAFCR_TSINSEL;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_timestamp_mapping, mapping);
      break;
  }
}
#endif

#if defined(STM32_RTC_GPIO_CONTROL)
void
rtc_set_alarm_output_pin_configuration(
  enum rtc_output_pin pin,
  enum rtc_output_pin_config config
)
{
  const u32 clear = config == RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN;
  volatile u32* reg = &RTC->TAFCR;

  switch (pin)
  {
    case RTC_OUTPUT_PIN_PC13:
      if (clear)
      {
        *reg &= ~RTC_TAFCR_PC13VALUE;
      }
      else
      {
        *reg |= RTC_TAFCR_PC13VALUE;
      }
      break;

    case RTC_OUTPUT_PIN_PC14:
      if (clear)
      {
        *reg &= ~RTC_TAFCR_PC14VALUE;
      }
      else
      {
        *reg |= RTC_TAFCR_PC14VALUE;
      }
      break;

    case RTC_OUTPUT_PIN_PC15:
      if (clear)
      {
        *reg &= ~RTC_TAFCR_PC15VALUE;
      }
      else
      {
        *reg |= RTC_TAFCR_PC15VALUE;
      }
      break;

    default:
      devmode_error_invalid_enum(enum rtc_output_pin, pin);
      break;
  }
}

void
rtc_force_pushpull_output_enable(
  enum rtc_output_pin pin
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (pin)
  {
    case RTC_OUTPUT_PIN_PC13:
      *reg |= RTC_TAFCR_PC13MODE;
      break;

    case RTC_OUTPUT_PIN_PC14:
      *reg |= RTC_TAFCR_PC14MODE;
      break;

    case RTC_OUTPUT_PIN_PC15:
      *reg |= RTC_TAFCR_PC15MODE;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_output_pin, pin);
      break;
  }
}

void
rtc_force_pushpull_output_disable(
  enum rtc_output_pin pin
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (pin)
  {
    case RTC_OUTPUT_PIN_PC13:
      *reg &= ~RTC_TAFCR_PC13MODE;
      break;

    case RTC_OUTPUT_PIN_PC14:
      *reg &= ~RTC_TAFCR_PC14MODE;
      break;

    case RTC_OUTPUT_PIN_PC15:
      *reg &= ~RTC_TAFCR_PC15MODE;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_output_pin, pin);
      break;
  }
}

#elif defined(STM32_RTC_ALARM_TYPE)

void
rtc_set_alarm_output_type(
  enum rtc_alarm_output_type type
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (type)
  {
    case RTC_ALARM_OUTPUT_TYPE_OPEN_DRAIN:
      *reg &= ~RTC_TAFCR_ALARMOUTTYPE;
      break;

    case RTC_ALARM_OUTPUT_TYPE_PUSH_PULL:
      *reg |= RTC_TAFCR_ALARMOUTTYPE;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_alarm_output_type, type);
      break;
  }
}
#endif

#elif defined(STM32_RTC_TAMPCR_REG)
void
rtc_tamper_enable(
  enum rtc_tamper tamper
)
{
  volatile u32* reg = &RTC->TAMPCR;
  switch (tamper)
  {
    case RTC_TAMPER1:
      *reg |= RTC_TAMPCR_TAMP1E;
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      *reg |= RTC_TAMPCR_TAMP2E;
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      *reg |= RTC_TAMPCR_TAMP3E;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_tamper, tamper);
      break;
  }
}

void
rtc_tamper_disable(
  enum rtc_tamper tamper
)
{
  volatile u32* reg = &RTC->TAFCR;
  switch (tamper)
  {
    case RTC_TAMPER1:
      *reg &= ~RTC_TAMPCR_TAMP1E;
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      *reg &= ~RTC_TAMPCR_TAMP2E;
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      *reg &= ~RTC_TAMPCR_TAMP3E;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_tamper, tamper);
      break;
  }
}

void
rtc_set_tamper_active_level(
  enum rtc_tamper tamper,
  enum rtc_tamper_active_level level
)
{
  const u32 bit = level == RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH ||
            level == RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE;

  volatile u32* reg = &RTC->TAMPCR;
  switch (tamper)
  {
    case RTC_TAMPER1:
      if (bit)
      {
        *reg |= RTC_TAMPCR_TAMP1TRG;
      }
      else
      {
        *reg &= ~RTC_TAMPCR_TAMP1TRG;
      }
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      if (bit)
      {
        *reg |= RTC_TAMPCR_TAMP2TRG;
      }
      else
      {
        *reg &= ~RTC_TAMPCR_TAMP2TRG;
      }
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      if (bit)
      {
        *reg |= RTC_TAMPCR_TAMP3TRG;
      }
      else
      {
        *reg &= ~RTC_TAMPCR_TAMP3TRG;
      }
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_tamper, tamper);
      break;
  }
}

void
rtc_timestamp_on_tamper_event_enable(void)
{
  RTC->TAMPCR |= RTC_TAMPCR_TAMPTS;
}

void
rtc_timestamp_on_tamper_event_disable(void)
{
  RTC->TAMPCR &= ~RTC_TAMPCR_TAMPTS;
}

void
rtc_set_tamper_sampling_frequency(
  enum rtc_tamper_sampling_frequency frequency
)
{
  constexpr u32 shift = RTC_TAMPCR_TAMPFREQ_SHIFT;
  constexpr u32 mask = RTC_TAMPCR_TAMPFREQ_MASK << shift;
  volatile u32* reg = &RTC->TAMPCR;

  switch (frequency)
  {
    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768:
      *reg &= ~mask;
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFREQ_DIV16384 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFREQ_DIV8192 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFREQ_DIV4096 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFREQ_DIV2048 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFREQ_DIV1024 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV512:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFREQ_DIV512 << shift);
      break;

    case RTC_TAMPER_SAMPLING_FREQUENCY_DIV256:
      *reg |= (RTC_TAMPCR_TAMPFREQ_DIV256 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_tamper_sampling_frequency, frequency);
      break;
  }
}

void
rtc_set_tamper_filter_count(
  enum rtc_tamper_filter_count count
)
{
  constexpr u32 shift = RTC_TAMPCR_TAMPFLT_SHIFT;
  constexpr u32 mask = RTC_TAMPCR_TAMPFLT_MASK << shift;
  volatile u32* reg = &RTC->TAMPCR;

  switch (count)
  {
    case RTC_TAMPER_FILTER_COUNT_NOSKIP:
      *reg &= ~mask;
      break;

    case RTC_TAMPER_FILTER_COUNT_SKIP2:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFLT_COUNT2 << shift);
      break;

    case RTC_TAMPER_FILTER_COUNT_SKIP4:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFLT_COUNT4 << shift);
      break;

    case RTC_TAMPER_FILTER_COUNT_SKIP8:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPFLT_COUNT8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_tamper_filter_count, count);
      break;
  }
}

void
rtc_set_tamper_precharge_duration(
  enum rtc_tamper_precharge_duration duration
)
{
  constexpr u32 shift = RTC_TAMPCR_TAMPPRCH_SHIFT;
  constexpr u32 mask = RTC_TAMPCR_TAMPPRCH_MASK << shift;
  volatile u32* reg = &RTC->TAMPCR;
  switch (duration)
  {
    case RTC_TAMPER_PRECHARGE_DURATION_1CYCLE:
      *reg &= ~mask;
      break;

    case RTC_TAMPER_PRECHARGE_DURATION_2CYCLES:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPPRCH_2CYCLES << shift);
      break;

    case RTC_TAMPER_PRECHARGE_DURATION_4CYCLES:
      syn_set_register_bits(reg, mask, RTC_TAMPCR_TAMPPRCH_4CYCLES << shift);
      break;

    case RTC_TAMPER_PRECHARGE_DURATION_8CYCLES:
      *reg |= (RTC_TAMPCR_TAMPPRCH_8CYCLES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_tamper_precharge_duration, duration);
      break;
  }
}

void
rtc_tamper_pullup_enable(void)
{
  RTC->TAMPCR &= ~RTC_TAMPCR_TAMPPUDIS;
}

void
rtc_tamper_pullup_disable(void)
{
  RTC->TAMPCR |= RTC_TAMPCR_TAMPPUDIS;
}

void
rtc_set_tamper_erase(
  enum rtc_tamper tamper,
  enum rtc_tamper_erase erase
)
{
  const u32 clear = erase == RTC_TAMPER_ERASE_ON;
  volatile u32* reg = &RTC->TAMPCR;

  switch (tamper)
  {
    case RTC_TAMPER1:
      if (clear)
      {
        *reg &= ~RTC_TAMPCR_TAMP1NOERASE;
      }
      else
      {
        *reg |= RTC_TAMPCR_TAMP1NOERASE;
      }
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      if (clear)
      {
        *reg &= ~RTC_TAMPCR_TAMP2NOERASE;
      }
      else
      {
        *reg |= RTC_TAMPCR_TAMP2NOERASE;
      }
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      if (clear)
      {
        *reg &= ~RTC_TAMPCR_TAMP3NOERASE;
      }
      else
      {
        *reg |= RTC_TAMPCR_TAMP3NOERASE;
      }
      break;

#endif

    default:
      devmode_error_invalid_enum(enum rtc_tamper, tamper);
      break;
  }
}

void
rtc_set_tamper_mask(
  enum rtc_tamper tamper,
  enum rtc_tamper_mask mask
)
{
  const u32 clear = mask == RTC_TAMPCR_MASK_MANUAL;
  volatile u32* reg = &RTC->TAMPCR;

  switch (tamper)
  {
    case RTC_TAMPER1:
      if (clear)
      {
        *reg &= ~RTC_TAMPCR_TAMP1MF;
      }
      else
      {
        *reg |= RTC_TAMPCR_TAMP1MF;
      }
      break;

#if defined(STM32_RTC_TAMPER2)
    case RTC_TAMPER2:
      if (clear)
      {
        *reg &= ~RTC_TAMPCR_TAMP2MF;
      }
      else
      {
        *reg |= RTC_TAMPCR_TAMP2MF;
      }
      break;
#endif

#if defined(STM32_RTC_TAMPER3)
    case RTC_TAMPER3:
      if (clear)
      {
        *reg &= ~RTC_TAMPCR_TAMP3MF;
      }
      else
      {
        *reg |= RTC_TAMPCR_TAMP3MF;
      }
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_tamper_mask, mask);
      break;
  }
}
#endif

void
rtc_set_alarm_subsecond_value(
  enum rtc_alarm alarm,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, RTC_ALRMxSSR_SS_MASK);

  constexpr u32 shift = RTC_ALRMxSSR_SS_SHIFT;
  constexpr u32 mask = RTC_ALRMxSSR_SS_MASK << shift;
  volatile u32* reg;

  switch (alarm)
  {
    case RTC_ALARMA:
      reg = &RTC->ALRMASSR;
      syn_set_register_bits(reg, mask, value << shift);
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_ALARMB:
      reg = &RTC->ALRMBSSR;
      syn_set_register_bits(reg, mask, value << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_alarm, alarm);
      break;
  }
}

void
rtc_set_alarm_mask_bits(
  enum rtc_alarm alarm,
  u32 bits_count
)
{
  devmode_assert_lower_or_eq(bits_count, RTC_ALRMxSSR_MASKSS_MASK);

  constexpr u32 shift = RTC_ALRMxSSR_MASKSS_SHIFT;
  constexpr u32 mask = RTC_ALRMxSSR_MASKSS_MASK << shift;
  volatile u32* reg;

  switch (alarm)
  {
    case RTC_ALARMA:
      reg = &RTC->ALRMASSR;
      syn_set_register_bits(reg, mask, bits_count << shift);
      break;

#if defined(STM32_RTC_ALARMB)
    case RTC_ALARMB:
      reg = &RTC->ALRMBSSR;
      syn_set_register_bits(reg, mask, bits_count << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rtc_alarm, alarm);
      break;
  }
}

#if defined(STM32_RTC_OR)
void
rtc_set_timestamp_mapping(
  enum rtc_timestamp_mapping mapping
)
{
  constexpr u32 shift = RTC_OR_TSINSEL_SHIFT;
  constexpr u32 mask = RTC_OR_TSINSEL_MASK << shift;
  volatile u32* reg = &RTC-OR;

  switch (mapping)
  {
    case RTC_TIMESTAMP_MAPPING_PC13:
      *reg &= ~mask;
      break;

    case RTC_TIMESTAMP_MAPPING_PI8:
      syn_set_register_bits(reg, mask, RTC_OR_TSINSEL_PI8 << shift);
      break;

    case RTC_TIMESTAMP_MAPPING_PC1:
      *reg |= (RTC_OR_TSINSEL_PC1 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rtc_timestamp_mapping, mapping);
      break;
  }
}

void
rtc_set_alarm_type(
  enum rtc_alarm_type type
)
{
  volatile u32* reg = &RTC->OR;
  switch (type)
  {
    case RTC_ALARM_TYPE_OPEN_DRAIN:
      *reg &= ~RTC_OR_RTCALARMTYPE;
      break;

    case RTC_ALARM_TYPE_PUSH_PULL:
      *reg |= RTC_OR_RTCALARMTYPE;
      break;

    default:
      devmode_error_invalid_enum(enum rtc_alarm_type, type);
      break;
  }
}
#endif

#if defined(STM32_RTC_BKP)
void
rtc_backup_data_write(
  u32 idx,
  u32 data
)
{
  devmode_assert_lower_or_eq(idx, RTC_BKP_WORDS);
  RTC->BKPR[idx] = data;
}

u32
rtc_backup_data_read(
  u32 idx
)
{
  devmode_assert_lower_or_eq(idx, RTC_BKP_WORDS);
  return RTC->BKPR[idx];
}
#endif
