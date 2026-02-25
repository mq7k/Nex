#ifndef STM32_DRIVER_RTC_H
#define STM32_DRIVER_RTC_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

/**
 * Supports:
 *  - STM32F1x
 */

struct rtc_registers_map
{
  u32 CRH;
  u32 CRL;
  u32 PRLH;
  u32 PRLL;
  u32 DIVH;
  u32 DIVL;
  u32 CNTH;
  u32 CNTL;
  u32 ALRH;
  u32 ALRL;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum rtc_crh : u32
{
  RTC_CRH_SECIE = (1 << 0),
  RTC_CRH_ALRIE = (1 << 1),
  RTC_CRH_OWIE = (1 << 2)
};

enum rtc_crl : u32
{
  RTC_CRL_SECF = (1 << 0),
  RTC_CRL_ALRF = (1 << 1),
  RTC_CRL_OWF = (1 << 2),
  RTC_CRL_RSF = (1 << 3),
  RTC_CRL_CNF = (1 << 4),
  RTC_CRL_RTOFF = (1 << 5)
};

#define RTC_PRLH_MASK (0xf)
#define RTC_PRLL_MASK (0xffff)
#define RTC_PRLH_SHIFT (16)

#define RTC_DIVH_MASK (0xf)
#define RTC_DIVL_MASK (0xffff)
#define RTC_DIVH_SHIFT (16)

#define RTC_CNTH_MASK (0xffff)
#define RTC_CNTL_MASK (0xffff)
#define RTC_CNTH_SHIFT (16)

#define RTC_ALRH_MASK (0xffff)
#define RTC_ALRL_MASK (0xffff)
#define RTC_ALRH_SHIFT (16)

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum rtc_interrupt
{
  RTC_INTERRUPT_SECOND,
  RTC_INTERRUPT_ALARM,
  RTC_INTERRUPT_OVERFLOW
};

enum rtc_flag
{
  RTC_FLAG_SECOND,
  RTC_FLAG_ALARM,
  RTC_FLAG_OVERFLOW,
  RTC_FLAG_SYNC,
  RTC_FLAG_CONFIGURATION,
  RTC_FLAG_WRITE_IDLE
};

extern volatile struct rtc_registers_map* RTC;

void
rtc_interrupt_enable(
  enum rtc_interrupt flag
);

void
rtc_interrupt_disable(
  enum rtc_interrupt flag
);

u32
rtc_is_flag_set(
  enum rtc_flag flag
);

void
rtc_flag_clear(
  enum rtc_flag flag
);

void
rtc_config_enable(void);

void
rtc_config_disable(void);

void
rtc_write_idle_wait(void);

void
rtc_set_prescaler(
  u32 prescaler
);

u32
rtc_get_prescaler_div_low(void);

u32
rtc_get_prescaler_div_high(void);

u32
rtc_get_prescaler_divider(void);

void
rtc_set_counter(
  u32 counter
);

void
rtc_set_alarm(
  u32 alarm
);

END_DECLARATIONS

#endif
