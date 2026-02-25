#ifndef STM32_ADC_H
#define STM32_ADC_H

#include "synapse/specs.h"

#if defined(STM32_ADC_V1)
#include "synapse/stm32/drivers/adc/adc_v1.h"
#elif defined(STM32_ADC_V2)
#include "synapse/stm32/drivers/adc/adc_v2.h"
#else
#error "No ADC version specified."
#endif

#endif
