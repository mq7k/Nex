#ifndef STM32_RTC_H
#define STM32_RTC_H

#include "synapse/specs.h"

#if defined(STM32_RTC_V1)
#include "synapse/stm32/drivers/rtc/rtc_v1.h"
#elif defined(STM32_RTC_V2)
#include "synapse/stm32/drivers/rtc/rtc_v2.h"
#else
#error "No RTC version specified."
#endif

#endif
