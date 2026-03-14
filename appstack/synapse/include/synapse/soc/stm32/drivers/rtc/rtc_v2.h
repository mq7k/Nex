#ifndef STM32_DRIVER_RTC_H
#define STM32_DRIVER_RTC_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

#define RTC_BKP_WORDS 5

/**
 * Supports:
 *  - STM32F0x
 *  - STM32F4x
 *  - STM32F7x
 */

BEGIN_DECLARATIONS

struct rtc_registers_map
{
  u32 TR;
  u32 DR;
  u32 CR;
  u32 ISR;
  u32 PRER;
  u32 WUTR;

#if defined(STM32_RTC_EXTENDED)
  u32 CALIBR;
  u32 ALRMAR;
  u32 ALRMBR;
#else
  u32 __reserved0;
  u32 ALRMAR;
  u32 __reserved1;
#endif

  u32 WPR;
  u32 SSR;
  u32 SHIFTR;
  u32 TSTR;
  u32 TSDR;
  u32 TSSSR;
  u32 CALR;

#if defined(STM32_RTC_TAMPCR_REG)
  u32 TAMPCR;
#elif defined(STM32_RTC_TAFCR_REG)
  u32 TAFCR;
#endif

  u32 ALRMASSR;

#if defined(STM32_RTC_ALARMB)
  u32 ALRMBSSR;
#else
  u32 __reserved2;
#endif

#if defined(STM32_RTC_OPTION_REG)
  u32 OR;
#else
  u32 __reserved3;
#endif

#if defined(STM32_RTC_BKP_WORDS)
  u32 BKPR[STM32_RTC_BKP_WORDS];
#endif
};

// Core
#define RTC_MAX_SECONDS (59)
#define RTC_MAX_MINUTES (59)
#define RTC_MAX_HOURS (23)
#define RTC_MAX_WEEKDAY (7)
#define RTC_MAX_DATE (31)
#define RTC_MAX_MONTH (11)
#define RTC_MAX_YEAR (99)
#define RTC_YEAR_OFFSET (2000)

enum rtc_tr : u32
{
  RTC_TR_PM = (1 << 22)
};


#define RTC_TR_SU_SHIFT (0)
#define RTC_TR_SU_MASK (0xfu)

#define RTC_TR_ST_SHIFT (4)
#define RTC_TR_ST_MASK (0x7u)

#define RTC_TR_MNU_SHIFT (8)
#define RTC_TR_MNU_MASK (0xfu)

#define RTC_TR_MNT_SHIFT (12)
#define RTC_TR_MNT_MASK (0x7u)

#define RTC_TR_HU_SHIFT (16)
#define RTC_TR_HU_MASK (0xfu)

#define RTC_TR_HT_SHIFT (20)
#define RTC_TR_HT_MASK (0x3u)

enum rtc_dr : u32
{
  RTC_DR_MT = (1 << 12)
};

#define RTC_DR_DU_SHIFT (0)
#define RTC_DR_DU_MASK (0xfu)

#define RTC_DR_DT_SHIFT (4)
#define RTC_DR_DT_MASK (0x3u)

#define RTC_DR_MU_SHIFT (8)
#define RTC_DR_MU_MASK (0xfu)

#define RTC_DR_MT_SHIFT (12)
#define RTC_DR_MT_MASK (0x1u)

#define RTC_DR_WDU_SHIFT (13)
#define RTC_DR_WDU_MASK (0x7u)

enum rtc_dr_wdu : u32
{
  RTC_DR_WDU_MONDAY = 0b001,
  RTC_DR_WDU_TUESDAY = 0b010,
  RTC_DR_WDU_WEDNESDAY = 0b011,
  RTC_DR_WDU_THURSDAY = 0b100,
  RTC_DR_WDU_FRIDAY = 0b101,
  RTC_DR_WDU_SATURDAY = 0b110,
  RTC_DR_WDU_SUNDAY = 0b111
};

#define RTC_DR_YU_SHIFT (16)
#define RTC_DR_YU_MASK (0xfu)

#define RTC_DR_YT_SHIFT (20)
#define RTC_DR_YT_MASK (0xfu)

enum rtc_cr : u32
{
  RTC_CR_TSEDGE = (1 << 3),
  RTC_CR_REFCKON = (1 << 4),
  RTC_CR_BYPSHAD = (1 << 5),
  RTC_CR_FMT = (1 << 6),

#if defined(STM32_RTC_COARSE_DIGITAL_CALIB)
  RTC_CR_DCE = (1 << 7),
#endif

  RTC_CR_ALRAE = (1 << 8),

#if defined(STM32_RTC_ALARMB)
  RTC_CR_ALRBE = (1 << 9),
#endif

  RTC_CR_WUTE = (1 << 10),
  RTC_CR_TSE = (1 << 11),
  RTC_CR_ALRAIE = (1 << 12),

#if defined(STM32_RTC_ALARMB)
  RTC_CR_ALRBIE = (1 << 13),
#endif

  RTC_CR_WUTIE = (1 << 14),
  RTC_CR_TSIE = (1 << 15),
  RTC_CR_ADD1H = (1 << 16),
  RTC_CR_SUB1H = (1 << 17),
  RTC_CR_BKP = (1 << 18),
  RTC_CR_COSEL = (1 << 19),
  RTC_CR_POL = (1 << 20),
  RTC_CR_COE = (1 << 23),

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
  RTC_CR_ITSE = (1 << 24)
#endif
};

#define RTC_CR_WUCKSEL_SHIFT (0)
#define RTC_CR_WUCKSEL_MASK (0x7)

enum rtc_cr_wucksel : u32
{
  RTC_CR_WUCKSEL_DIV16 = 0b000,
  RTC_CR_WUCKSEL_DIV8 = 0b001,
  RTC_CR_WUCKSEL_DIV4 = 0b010,
  RTC_CR_WUCKSEL_DIV2 = 0b011,
  RTC_CR_WUCKSEL_NODIV = 0b100,
  RTC_CR_WUCKSEL_NODIV_OFFSET = 0b110
};

#define RTC_CR_OSEL_SHIFT (21)
#define RTC_CR_OSEL_MASK (0x3)

enum rtc_cr_osel : u32
{
  RTC_CR_OSEL_NOOUTPUT = 0b00,
  RTC_CR_OSEL_ALARMA = 0b01,

#if defined(STM32_RTC_ALARMB)
  RTC_CR_OSEL_ALARMB = 0b10,
#endif

  RTC_CR_OSEL_WAKEUP = 0b11
};

enum rtc_isr : u32
{
  RTC_ISR_ALRAWF = (1 << 0),

#if defined(STM32_RTC_ALARMB)
  RTC_ISR_ALRBWF = (1 << 1),
#endif
  
  RTC_ISR_WUTWF = (1 << 2),
  RTC_ISR_SHPF = (1 << 3),
  RTC_ISR_INITS = (1 << 4),
  RTC_ISR_RSF = (1 << 5),
  RTC_ISR_INITF = (1 << 6),
  RTC_ISR_INIT = (1 << 7),
  RTC_ISR_ALRAF = (1 << 8),

#if defined(STM32_RTC_ALARMB)
  RTC_ISR_ALRBF = (1 << 9),
#endif

  RTC_ISR_WUTF = (1 << 10),
  RTC_ISR_TSF = (1 << 11),
  RTC_ISR_TSOVF = (1 << 12),
  RTC_ISR_TAMP1F = (1 << 13),
  RTC_ISR_TAMP2F = (1 << 14),

#if defined(STM32_RTC_TAMPER3)
  RTC_ISR_TAMP3F = (1 << 15),
#endif

  RTC_ISR_RECALPF = (1 << 16),

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
  RTC_ISR_ITSF = (1 << 17)
#endif
};

#define RTC_PRER_PREDIVS_SHIFT (0)
#define RTC_PRER_PREDIVS_MASK (0x3fff)

#define RTC_PRER_PREDIVA_SHIFT (16)
#define RTC_PRER_PREDIVA_MASK (0x7f)

#define RTC_WUTR_WUT_SHIFT (0)
#define RTC_WUTR_WUT_MASK (0xffff)

#if defined(STM32_RTC_EXTENDED)
enum rtc_calibr : u32
{
  RTC_CALIBR_DCS = (1 << 7)
};

#define RTC_CALIBR_DC_SHIFT (0)
#define RTC_CALIBR_DC_MASK (0x1f)
#endif

enum rtc_alrmar : u32
{
  RTC_ALRMAR_MSK1 = (1 << 7),
  RTC_ALRMAR_MSK2 = (1 << 15),
  RTC_ALRMAR_PM = (1 << 22),
  RTC_ALRMAR_MSK3 = (1 << 23),
  RTC_ALRMAR_WDSEL = (1 << 30),
  RTC_ALRMAR_MSK4 = (1u << 31)
};

#define RTC_ALRMAR_SU_SHIFT (0)
#define RTC_ALRMAR_SU_MASK (0xf)

#define RTC_ALRMAR_ST_SHIFT (4)
#define RTC_ALRMAR_ST_MASK (0x7)

#define RTC_ALRMAR_MNU_SHIFT (8)
#define RTC_ALRMAR_MNU_MASK (0xf)

#define RTC_ALRMAR_MNT_SHIFT (12)
#define RTC_ALRMAR_MNT_MASK (0x7)

#define RTC_ALRMAR_HU_SHIFT (16)
#define RTC_ALRMAR_HU_MASK (0xf)

#define RTC_ALRMAR_HT_SHIFT (20)
#define RTC_ALRMAR_HT_MASK (0x3)

#define RTC_ALRMAR_DU_SHIFT (24)
#define RTC_ALRMAR_DU_MASK (0xf)

#define RTC_ALRMAR_DT_SHIFT (28)
#define RTC_ALRMAR_DT_MASK (0x7)

#if defined(STM32_RTC_ALARMB)
enum rtc_alrmbr : u32
{
  RTC_ALRMBR_MSK1 = (1 << 7),
  RTC_ALRMBR_MSK2 = (1 << 15),
  RTC_ALRMBR_PM = (1 << 22),
  RTC_ALRMBR_MSK3 = (1 << 23),
  RTC_ALRMBR_WDSEL = (1 << 30),
  RTC_ALRMBR_MSK4 = (1u << 31)
};

#define RTC_ALRMBR_SU_SHIFT (0)
#define RTC_ALRMBR_SU_MASK (0xf)

#define RTC_ALRMBR_ST_SHIFT (4)
#define RTC_ALRMBR_ST_MASK (0x7)

#define RTC_ALRMBR_MNU_SHIFT (8)
#define RTC_ALRMBR_MNU_MASK (0xf)

#define RTC_ALRMBR_MNT_SHIFT (12)
#define RTC_ALRMBR_MNT_MASK (0x7)

#define RTC_ALRMBR_HU_SHIFT (16)
#define RTC_ALRMBR_HU_MASK (0xf)

#define RTC_ALRMBR_HT_SHIFT (20)
#define RTC_ALRMBR_HT_MASK (0x3)

#define RTC_ALRMBR_DU_SHIFT (24)
#define RTC_ALRMBR_DU_MASK (0xf)

#define RTC_ALRMBR_DT_SHIFT (28)
#define RTC_ALRMBR_DT_MASK (0x7)
#endif

#define RTC_WPR_KEY1 (0xca)
#define RTC_WPR_KEY2 (0x53)

#define RTC_SSR_SS_SHIFT (0)
#define RTC_SSR_SS_MASK (0xffff)

enum rtc_shiftr : u32
{
  RTC_SHIFTR_ADD1S = (1u << 31)
};

#define RTC_SHIFTR_SUBFS_SHIFT (0)
#define RTC_SHIFTR_SUBFS_MASK (0x3fff)

enum rtc_tstr : u32
{
  RTC_TSTR_PM = (1 << 22)
};

#define RTC_TSTR_SU_SHIFT (0)
#define RTC_TSTR_SU_MASK (0xf)

#define RTC_TSTR_ST_SHIFT (4)
#define RTC_TSTR_ST_MASK (0x7)

#define RTC_TSTR_MNU_SHIFT (8)
#define RTC_TSTR_MNU_MASK (0xf)

#define RTC_TSTR_MNT_SHIFT (12)
#define RTC_TSTR_MNT_MASK (0x7)

#define RTC_TSTR_HU_SHIFT (16)
#define RTC_TSTR_HU_MASK (0xf)

#define RTC_TSTR_HT_SHIFT (20)
#define RTC_TSTR_HT_MASK (0x3)

enum rtc_tsdr : u32
{
  RTC_TSDR_MT = (1 << 12)
};

#define RTC_TSDR_DU_SHIFT (0)
#define RTC_TSDR_DU_MASK (0xf)

#define RTC_TSDR_DT_SHIFT (3)
#define RTC_TSDR_DT_MASK (0x3)

#define RTC_TSDR_MU_SHIFT (8)
#define RTC_TSDR_MU_MASK (0xf)

#define RTC_TSDR_MT_SHIFT (12)

#define RTC_TSDR_WDU_SHIFT (13)
#define RTC_TSDR_WDU_MASK (0x7)

#define RTC_TSSSR_SS_SHIFT (0)
#define RTC_TSSSR_SS_MASK (0xffff)

enum rtc_calr : u32
{
  RTC_CALR_CALW16 = (1 << 13),
  RTC_CALR_CALW8 = (1 << 14),
  RTC_CALR_CALP = (1 << 15)
};

#define RTC_CALR_CALM_SHIFT (0)
#define RTC_CALR_CALM_MASK (0x1ff)

#if defined(STM32_RTC_TAFCR_REG)

enum rtc_tafcr : u32
{
  RTC_TAFCR_TAMP1E = (1 << 0),
  RTC_TAFCR_TAMP1TRG = (1 << 1),
  RTC_TAFCR_TAMPIE = (1 << 2),

#if defined(STM32_RTC_TAMPER2)
  RTC_TAFCR_TAMP2E = (1 << 3),
  RTC_TAFCR_TAMP2TRG = (1 << 4),
#endif

#if defined(STM32_RTC_TAMPER3)
  RTC_TAFCR_TAMP3E = (1 << 5),
  RTC_TAFCR_TAMP3TRG = (1 << 6),
#endif

  RTC_TAFCR_TAMPTS = (1 << 7),
  RTC_TAFCR_TAMPPUDIS = (1 << 15),

#if defined(STM32_RTC_TAMPER1_MAPPING)
  RTC_TAFCR_TAMP1INSEL = (1 << 16),
  RTC_TAFCR_TSINSEL = (1 << 17),
#endif

#if defined(STM32_RTC_GPIO_CONTROL)
  RTC_TAFCR_PC13VALUE = (1 << 18),
  RTC_TAFCR_PC13MODE = (1 << 19),
  RTC_TAFCR_PC14VALUE = (1 << 20),
  RTC_TAFCR_PC14MODE = (1 << 21),
  RTC_TAFCR_PC15VALUE = (1 << 22),
  RTC_TAFCR_PC15MODE = (1 << 23)
#elif defined(STM32_RTC_ALARM_TYPE)
  RTC_TAFCR_ALARMOUTTYPE = (1 << 18)
#endif
};

#define RTC_TAFCR_TAMPFREQ_SHIFT (8)
#define RTC_TAFCR_TAMPFREQ_MASK (0x7)

enum rtc_tafcr_tampfreq : u32
{
  RTC_TAFCR_TAMPFREQ_DIV32768 = 0b000,
  RTC_TAFCR_TAMPFREQ_DIV16384 = 0b001,
  RTC_TAFCR_TAMPFREQ_DIV8192 = 0b010,
  RTC_TAFCR_TAMPFREQ_DIV4096 = 0b011,
  RTC_TAFCR_TAMPFREQ_DIV2048 = 0b100,
  RTC_TAFCR_TAMPFREQ_DIV1024 = 0b101,
  RTC_TAFCR_TAMPFREQ_DIV512 = 0b110,
  RTC_TAFCR_TAMPFREQ_DIV256 = 0b111
};

#define RTC_TAFCR_TAMPFLT_SHIFT (11)
#define RTC_TAFCR_TAMPFLT_MASK (0x3)

enum rtc_tafcr_tampflt : u32
{
  RTC_TAFCR_TAMPFLT_COUNT1 = 0b00,
  RTC_TAFCR_TAMPFLT_COUNT2 = 0b01,
  RTC_TAFCR_TAMPFLT_COUNT4 = 0b10,
  RTC_TAFCR_TAMPFLT_COUNT8 = 0b11
};

#define RTC_TAFCR_TAMPPRCH_SHIFT (13)
#define RTC_TAFCR_TAMPPRCH_MASK (0x3)

enum rtc_tafcr_tampprch : u32
{
  RTC_TAFCR_TAMPPRCH_1CYCLE = 0b00,
  RTC_TAFCR_TAMPPRCH_2CYCLES = 0b01,
  RTC_TAFCR_TAMPPRCH_4CYCLES = 0b10,
  RTC_TAFCR_TAMPPRCH_8CYCLES = 0b11
};

#elif defined(STM32_RTC_TAMPCR_REG)

enum rtc_tampcr : u32
{
  RTC_TAMPCR_TAMP1E = (1 << 0),
  RTC_TAMPCR_TAMP1TRG = (1 << 1),
  RTC_TAMPCR_TAMPIE = (1 << 2),
  RTC_TAMPCR_TAMP2E = (1 << 3),
  RTC_TAMPCR_TAMP2TRG = (1 << 4),
  RTC_TAMPCR_TAMP3E = (1 << 5),
  RTC_TAMPCR_TAMP3TRG = (1 << 6),
  RTC_TAMPCR_TAMPTS = (1 << 7),
  RTC_TAMPCR_TAMPPUDIS = (1 << 15),
  RTC_TAMPCR_TAMP1IE = (1 << 16),
  RTC_TAMPCR_TAMP1NOERASE = (1 << 17),
  RTC_TAMPCR_TAMP1MF = (1 << 18),
  RTC_TAMPCR_TAMP2IE = (1 << 19),
  RTC_TAMPCR_TAMP2NOERASE = (1 << 20),
  RTC_TAMPCR_TAMP2MF = (1 << 21),
  RTC_TAMPCR_TAMP3IE = (1 << 22),
  RTC_TAMPCR_TAMP3NOERASE = (1 << 23),
  RTC_TAMPCR_TAMP3MF = (1 << 24)
};
#endif

#define RTC_ALRMxSSR_SS_SHIFT (0)
#define RTC_ALRMxSSR_SS_MASK (0x7fffu)

#define RTC_ALRMxSSR_MASKSS_SHIFT (24)
#define RTC_ALRMxSSR_MASKSS_MASK (0xfu)

#if defined(STM32_RTC_OR)
enum rtc_or : u32
{
  RTC_OR_RTCALARMTYPE = (1 << 3)
};

#define RTC_OR_TSINSEL_SHIFT (1)
#define RTC_OR_TSINSEL_MASK (0x3)

enum rtc_or_tsinsel : u32
{
  RTC_OR_TSINSEL_PC13 = 0b00,
  RTC_OR_TSINSEL_PI8 = 0b01,
  RTC_OR_TSINSEL_PC1 = 0b10
};
#endif

// API
enum rtc_calendar
{
  RTC_CALENDAR_SECONDS,
  RTC_CALENDAR_SECONDS_UNIT,
  RTC_CALENDAR_SECONDS_TENS,
  RTC_CALENDAR_MINUTES,
  RTC_CALENDAR_MINUTES_UNIT,
  RTC_CALENDAR_MINUTES_TENS,
  RTC_CALENDAR_HOURS,
  RTC_CALENDAR_HOURS_UNIT,
  RTC_CALENDAR_HOURS_TENS,
  RTC_CALENDAR_DATE,
  RTC_CALENDAR_DATE_UNIT,
  RTC_CALENDAR_DATE_TENS,
  RTC_CALENDAR_MONTH,
  RTC_CALENDAR_MONTH_UNIT,
  RTC_CALENDAR_MONTH_TENS,
  RTC_CALENDAR_WEEK_DAY,
  RTC_CALENDAR_YEAR,
  RTC_CALENDAR_YEAR_UNIT,
  RTC_CALENDAR_YEAR_TENS
};

enum rtc_weekday
{
  RTC_WEEKDAY_MONDAY,
  RTC_WEEKDAY_TUESDAY,
  RTC_WEEKDAY_WEDNESDAY,
  RTC_WEEKDAY_THURSDAY,
  RTC_WEEKDAY_FRIDAY,
  RTC_WEEKDAY_SATURDAY,
  RTC_WEEKDAY_SUNDAY
};

enum rtc_wakeup_clock
{
  RTC_WAKEUP_CLOCK_DIV16,
  RTC_WAKEUP_CLOCK_DIV8,
  RTC_WAKEUP_CLOCK_DIV4,
  RTC_WAKEUP_CLOCK_DIV2,
  RTC_WAKEUP_CLOCK_NODIV,
  RTC_WAKEUP_CLOCK_NODIV_OFFSET
};

enum rtc_event_edge
{
  RTC_EVENT_EDGE_RISING,
  RTC_EVENT_EDGE_FALLING
};

enum rtc_time_format
{
  RTC_TIME_FORMAT_24HOURS,
  RTC_TIME_FORMAT_12HOURS
};

enum rtc_alarm
{
  RTC_ALARMA,

#if defined(STM32_RTC_ALARMB)
  RTC_ALARMB
#endif
};

enum rtc_interrupt
{
  RTC_INTERRUPT_ALARMA,

#if defined(STM32_RTC_ALARMB)
  RTC_INTERRUPT_ALARMB,
#endif

  RTC_INTERRUPT_WAKEUP_TIMER,
  RTC_INTERRUPT_TIMESTAMP,
  RTC_INTERRUPT_TAMPER1,

#if defined(STM32_RTC_TAMPER2)
  RTC_INTERRUPT_TAMPER2,
#endif

#if defined(STM32_RTC_TAMPER3)
  RTC_INTERRUPT_TAMPER3
#endif

  RTC_INTERRUPT_TAMPER_ALL
};

enum rtc_time_offset
{
  RTC_TIME_OFFSET_ADD_1HOUR,
  RTC_TIME_OFFSET_SUB_1HOUR,
  RTC_TIME_OFFSET_OFF
};

enum rtc_calibration_output
{
  RTC_CALIBRATION_OUTPUT_512HZ,
  RTC_CALIBRATION_OUTPUT_1HZ
};

enum rtc_alarm_output_polarity
{
  RTC_ALARM_OUTPUT_POLARITY_HIGH,
  RTC_ALARM_OUTPUT_POLARITY_LOW
};

enum rtc_output
{
  RTC_OUTPUT_OFF,
  RTC_OUTPUT_ALARMA,

#if defined(STM32_RTC_ALARMB)
  RTC_OUTPUT_ALARMB,
#endif

  RTC_OUTPUT_WAKEUP
};

enum rtc_flag
{
  RTC_FLAG_ALARMA_WRITE,

#if defined(STM32_RTC_ALARMB)
  RTC_FLAG_ALARMB_WRITE,
#endif

  RTC_FLAG_WAKEUP_TIMER_WRITE,
  RTC_FLAG_SHIFT_OP,
  RTC_FLAG_INIT_STATUS,
  RTC_FLAG_SYNC,
  RTC_FLAG_INIT,
  RTC_FLAG_ALARMA,

#if defined(STM32_RTC_ALARMB)
  RTC_FLAG_ALARMB,
#endif

  RTC_FLAG_WAKEUP_TIMER,
  RTC_FLAG_TIMESTAMP,
  RTC_FLAG_TIMESTAMP_OVERFLOW,
  RTC_FLAG_TAMPER1,

#if defined(STM32_RTC_TAMPER2)
  RTC_FLAG_TAMPER2,
#endif

#if defined(STM32_RTC_TAMPER3)
  RTC_FLAG_TAMPER3,
#endif

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
  RTC_FLAG_INTERNAL_TIMESTAMP_EVENT,
#endif

  RTC_FLAG_RECALIB_PENDING
};

#if defined(STM32_RTC_EXTENDED)
enum rtc_digital_calib_sign
{
  RTC_DIGITAL_CALIB_SIGN_POSITIVE,
  RTC_DIGITAL_CALIB_SIGN_NEGATIVE
};
#endif

enum rtc_alarm_compare
{
  RTC_ALARM_COMPARE_SECONDS,
  RTC_ALARM_COMPARE_MINUTES,
  RTC_ALARM_COMPARE_HOURS,
  RTC_ALARM_COMPARE_DATE
};

enum rtc_datetime_type
{
  RTC_DATETIME_TYPE_DATE,
  RTC_DATETIME_TYPE_WEEKDAY
};

enum rtc_calibration_cycle_period
{
  RTC_CALIBRATION_CYCLE_PERIOD_16SECONDS,
  RTC_CALIBRATION_CYCLE_PERIOD_8SECODNS
};

enum rtc_tamper
{
  RTC_TAMPER1,

#if defined(STM32_RTC_TAMPER2)
  RTC_TAMPER2,
#endif

#if defined(STM32_RTC_TAMPER3)
  RTC_TAMPER3
#endif
};

enum rtc_tamper_active_level
{
  RTC_TAMPER_ACTIVE_LEVEL_STAY_LOW,
  RTC_TAMPER_ACTIVE_LEVEL_STAY_HIGH,
  RTC_TAMPER_ACTIVE_LEVEL_RISING_EDGE,
  RTC_TAMPER_ACTIVE_LEVEL_FALLING_EDGE
};

enum rtc_tamper_sampling_frequency
{
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV32768,
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV16384,
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV8192,
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV4096,
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV2048,
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV1024,
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV512,
  RTC_TAMPER_SAMPLING_FREQUENCY_DIV256
};

enum rtc_tamper_filter_count
{
  RTC_TAMPER_FILTER_COUNT_NOSKIP,
  RTC_TAMPER_FILTER_COUNT_SKIP2,
  RTC_TAMPER_FILTER_COUNT_SKIP4,
  RTC_TAMPER_FILTER_COUNT_SKIP8
};

enum rtc_tamper_precharge_duration
{
  RTC_TAMPER_PRECHARGE_DURATION_1CYCLE,
  RTC_TAMPER_PRECHARGE_DURATION_2CYCLES,
  RTC_TAMPER_PRECHARGE_DURATION_4CYCLES,
  RTC_TAMPER_PRECHARGE_DURATION_8CYCLES
};

#if defined(STM32_RTC_TAFCR_REG)

#if defined(STM32_RTC_TAMPER1_MAPPING)
enum rtc_tamper_mapping
{
  RTC_TAMPER_MAPPING_AF1
};
#endif

#if defined(STM32_RTC_TIMESTAMP_MAPPING)
enum rtc_timestamp_mapping
{
  RTC_TIMESTAMP_MAPPING_AF1
};
#endif

#if defined(STM32_RTC_GPIO_CONTROL)

enum rtc_output_pin
{
  RTC_OUTPUT_PIN_PC13,
  RTC_OUTPUT_PIN_PC14,
  RTC_OUTPUT_PIN_PC15
};

enum rtc_output_pin_config
{
  RTC_OUTPUT_PIN_CONFIG_OPEN_DRAIN,
  RTC_OUTPUT_PIN_CONFIG_PUSHPULL
};

#else

enum rtc_alarm_output_type
{
  RTC_ALARM_OUTPUT_TYPE_OPEN_DRAIN,
  RTC_ALARM_OUTPUT_TYPE_PUSH_PULL
};

#endif

#elif defined(STM32_RTC_TAMPCR_REG)

enum rtc_tamper_erase
{
  RTC_TAMPER_ERASE_ON,
  RTC_TAMPER_ERASE_OFF
};

enum rtc_tamper_mask
{
  RTC_TAMPER_MASK_MANUAL,
  RTC_TAMPER_MASK_AUTO
};

#endif

#if defined(STM32_RTC_OR)
enum rtc_timestamp_mapping
{
  RTC_TIMESTAMP_MAPPING_PC13,
  RTC_TIMESTAMP_MAPPING_PI8,
  RTC_TIMESTAMP_MAPPING_PC1
};

enum rtc_alarm_type 
{
  RTC_ALARM_TYPE_OPEN_DRAIN,
  RTC_ALARM_TYPE_PUSH_PULL
};
#endif

struct rtc_calendar_time
{
  u32 seconds;
  u32 minutes;
  u32 hours;
};

struct rtc_calendar_date
{
  u32 date;
  u32 month;
  u32 year;
  enum rtc_weekday day;
};

struct rtc_prescalers
{
  u32 async_prescaler;
  u32 sync_prescaler;
};

#define RTC_ALARM_MASK (0xf)

enum rtc_alarm_mask
{
  RTC_ALARM_MASK_SECONDS = (1u << 0),
  RTC_ALARM_MASK_MINUTES = (1u << 1),
  RTC_ALARM_MASK_HOURS = (1u << 2),
  RTC_ALARM_MASK_DATE = (1u << 3)
};

struct rtc_alarm_datetime
{
  u32 seconds;
  u32 minutes;
  u32 hours;
  u32 date;
  u32 alarm_masks;
  enum rtc_time_format time_format;
  u32 use_weekdays;
};

extern volatile struct rtc_registers_map* RTC;

void
rtc_set_calendar_time(
  struct rtc_calendar_time* time
);

void
rtc_set_calendar_date(
  struct rtc_calendar_date* date
);

void
rtc_get_calendar_time(
  struct rtc_calendar_time* time
);

void
rtc_get_calendar_date(
  struct rtc_calendar_date* date
);

void
rtc_set_calendar_time_format(
  enum rtc_time_format format
);

void
rtc_set_wakeup_clock(
  enum rtc_wakeup_clock clock
);

void
rtc_set_timestamp_event_edge(
  enum rtc_event_edge edge
);

void
rtc_reference_clock_enable(void);

void
rtc_reference_clock_disable(void);

void
rtc_shadow_register_bypass_enable(void);

void
rtc_shadow_register_bypass_disable(void);

void
rtc_set_time_format(
  enum rtc_time_format format
);

#if defined(STM32_RTC_COARSE_DIGITAL_CALIB)
void
rtc_coarse_digital_calib_enable(void);

void
rtc_coarse_digital_calib_disable(void);
#endif

void
rtc_alarm_enable(
  enum rtc_alarm alarm
);

void
rtc_alarm_disable(
  enum rtc_alarm alarm
);

void
rtc_wakeup_timer_enable(void);

void
rtc_wakeup_timer_disable(void);

void
rtc_timestamp_enable(void);

void
rtc_timestamp_disable(void);

void
rtc_interrupt_enable(
  enum rtc_interrupt interrupt
);

void
rtc_interrupt_disable(
  enum rtc_interrupt interrupt
);

void
rtc_set_time_offset(
  enum rtc_time_offset offset
);

void
rtc_daylight_time_change_save(void);

void
rtc_set_calibration_output(
  enum rtc_calibration_output output
);

void
rtc_set_alarm_output_polarity(
  enum rtc_alarm_output_polarity polarity
);

void
rtc_set_output(
  enum rtc_output output
);

void
rtc_calibration_output_enable(void);

void
rtc_calibration_output_disable(void);

#if defined(STM32_RTC_TIMESTAMP_INTERNAL_EVENT)
void
rtc_internal_event_timestamp_enable(void);

void
rtc_internal_event_timestamp_disable(void);
#endif

u32
rtc_is_flag_set(
  enum rtc_flag flag
);

void
rtc_flag_clear(
  enum rtc_flag flag
);

void
rtc_init_mode_enable(void);

void
rtc_init_mode_disable(void);

void
rtc_set_prescalers(
  struct rtc_prescalers* prescalers
);

void
rtc_set_wakeup_auto_reload_value(
  u32 value
);

#if defined(STM32_RTC_EXTENDED)
void
rtc_set_digital_calib(
  u32 value
);

void
rtc_set_digital_calib_sign(
  enum rtc_digital_calib_sign sign
);
#endif

void
rtc_set_alarm_time(
  enum rtc_alarm alarm,
  struct rtc_alarm_datetime* datetime
);

void
rtc_set_alarm_time_format(
  enum rtc_alarm alarm,
  enum rtc_time_format format
);

void
rtc_alarm_compare_enable(
  enum rtc_alarm alarm,
  enum rtc_alarm_compare compare
);

void
rtc_alarm_compare_disable(
  enum rtc_alarm alarm,
  enum rtc_alarm_compare compare
);

void
rtc_set_datetime_type(
  enum rtc_alarm alarm,
  enum rtc_datetime_type type
);

void
rtc_unlock_write_protection(void);

u32
rtc_get_async_prescaler_subsecond_value(void);

void
rtc_set_subsecond_value(
  u32 value
);

void
rtc_set_seconds_offset(
  u32 fraction,
  u32 add_1second
);

void
rtc_get_tamper_time(
  struct rtc_calendar_time* time
);

u32
rtc_get_timestamp_format(void);

u32
rtc_get_timestamp_subsecond(void);

void
rtc_set_calibration_minus(
  u32 value
);

void
rtc_set_calibration_cycle_period(
  enum rtc_calibration_cycle_period period
);

void
rtc_increase_frequency_enable(void);

void
rtc_increase_frequency_disable(void);

void
rtc_tamper_enable(
  enum rtc_tamper tamper
);

void
rtc_tamper_disable(
  enum rtc_tamper tamper
);

void
rtc_set_tamper_active_level(
  enum rtc_tamper tamper,
  enum rtc_tamper_active_level level
);

void
rtc_timestamp_on_tamper_event_enable(void);

void
rtc_timestamp_on_tamper_event_disable(void);

void
rtc_set_tamper_sampling_frequency(
  enum rtc_tamper_sampling_frequency frequency
);

void
rtc_set_tamper_filter_count(
  enum rtc_tamper_filter_count count
);

void
rtc_set_tamper_precharge_duration(
  enum rtc_tamper_precharge_duration duration
);

void
rtc_tamper_pullup_enable(void);

void
rtc_tamper_pullup_disable(void);

#if defined(STM32_RTC_TAFCR_REG)

#if defined(STM32_RTC_TAMPER_MAPPING)
void
rtc_set_tamper_mapping(
  enum rtc_tamper_mapping mapping
);
#endif

#if defined(STM32_RTC_TIMESTAMP_MAPPING)
void
rtc_set_timestamp_mapping(
  enum rtc_timestamp_mapping mapping
);
#endif

#if defined(STM32_RTC_GPIO_CONTROL)
void
rtc_set_alarm_output_pin_configuration(
  enum rtc_output_pin pin,
  enum rtc_output_pin_config config
);

void
rtc_force_pushpull_output_enable(
  enum rtc_output_pin pin
);

void
rtc_force_pushpull_output_disable(
  enum rtc_output_pin pin
);

#else

void
rtc_set_alarm_output_type(
  enum rtc_alarm_output_type type
);
#endif

#elif defined(STM32_RTC_TAMPCR_REG)

void
rtc_set_tamper_erase(
  enum rtc_tamper tamper,
  enum rtc_tamper_erase erase
);

void
rtc_set_tamper_mask(
  enum rtc_tamper tamper,
  enum rtc_tamper_mask mask
);

#endif

void
rtc_set_alarm_subsecond_value(
  enum rtc_alarm alarm,
  u32 value
);

void
rtc_set_alarm_mask_bits(
  enum rtc_alarm alarm,
  u32 bits_count
);

#if defined(STM32_RTC_OR)
void
rtc_set_timestamp_mapping(
  enum rtc_timestamp_mapping mapping
);

void
rtc_set_alarm_type(
  enum rtc_alarm_type type
);
#endif

#if defined(STM32_RTC_BKP)
void
rtc_backup_data_write(
  u32 idx,
  u32 data
);

u32
rtc_backup_data_read(
  u32 idx
);
#endif

END_DECLARATIONS

#endif
