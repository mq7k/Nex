#include "synapse/stm32/drivers/adc/adc_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

#if defined(STM32_ADC_COM)
typedef volatile struct adc_common_registers_map adccom_periph;
adccom_periph* ADCCOM = (adccom_periph*) (ADC_COM_ADDR);
#endif

#if defined(STM32_ADC1)
typedef volatile struct adc_registers_map adc_periph;
adc_periph* ADC1 = (adc_periph*) (ADC1_ADDR);
#endif

#if defined(STM32_ADC2)
typedef volatile struct adc_registers_map adc_periph;
adc_periph* ADC2 = (adc_periph*) (ADC2_ADDR);
#endif

#if defined(STM32_ADC3)
typedef volatile struct adc_registers_map adc_periph;
adc_periph* ADC3 = (adc_periph*) (ADC3_ADDR);
#endif

#if defined(STM32_ADC_SMPR)
enum adc_smpr
adc_convert_sample_rate_api_to_impl(
  enum adc_sample_rate sample_rate
)
{
  switch (sample_rate)
  {
#if defined(STM32_ADC_SMPR_LAYOUT1)
    case ADC_SAMPLE_RATE_1dot5_CYCLES:
      return ADC_SMPR_1dot5_CYCLES;

    case ADC_SAMPLE_RATE_7dot5_CYCLES:
      return ADC_SMPR_7dot5_CYCLES;

    case ADC_SAMPLE_RATE_13dot5_CYCLES:
      return ADC_SMPR_13dot5_CYCLES;

    case ADC_SAMPLE_RATE_28dot5_CYCLES:
      return ADC_SMPR_28dot5_CYCLES;

    case ADC_SAMPLE_RATE_41dot5_CYCLES:
      return ADC_SMPR_41dot5_CYCLES;

    case ADC_SAMPLE_RATE_55dot5_CYCLES:
      return ADC_SMPR_55dot5_CYCLES;

    case ADC_SAMPLE_RATE_71dot5_CYCLES:
      return ADC_SMPR_71dot5_CYCLES;
        
    case ADC_SAMPLE_RATE_239dot5_CYCLES:
      return ADC_SMPR_239dot5_CYCLES;
      
#elif defined(STM32_ADC_SMPR_LAYOUT2)
    case ADC_SAMPLE_RATE_3CYCLES:
      return ADC_SMPR_3CYCLES;

    case ADC_SAMPLE_RATE_15CYCLES:
      return ADC_SMPR_15CYCLES;

    case ADC_SAMPLE_RATE_28CYCLES:
      return ADC_SMPR_28CYCLES;

    case ADC_SAMPLE_RATE_56CYCLES:
      return ADC_SMPR_56CYCLES;

    case ADC_SAMPLE_RATE_84CYCLES:
      return ADC_SMPR_84CYCLES;

    case ADC_SAMPLE_RATE_112CYCLES:
      return ADC_SMPR_112CYCLES;

    case ADC_SAMPLE_RATE_144CYCLES:
      return ADC_SMPR_144CYCLES;

    case ADC_SAMPLE_RATE_480CYCLES:
      return ADC_SMPR_480CYCLES;
#endif

    default:
      devmode_error_invalid_enum(enum adc_sample_rate, sample_rate);
      return 0;
  }
}
#endif

u32
adc_is_flag_set(
  volatile struct adc_registers_map* adc,
  enum adc_flag flag
)
{
  volatile u32* reg = &adc->SR;
  switch (flag)
  {
    case ADC_FLAG_ANALOG_WATCHDOG:
      return *reg & ADC_SR_AWD;

    case ADC_FLAG_EOC:
      return *reg & ADC_SR_EOC;

    case ADC_FLAG_JEOC:
      return *reg & ADC_SR_JEOC;

    case ADC_FLAG_JSTART:
      return *reg & ADC_SR_JSTRT;
        
    case ADC_FLAG_START:
      return *reg & ADC_SR_STRT;

#if defined(STM32_ADC_OVR)
    case ADC_FLAG_OVERRUN:
      return *reg & ADC_SR_OVR;
#endif

    default:
      devmode_error_invalid_enum(enum adc_flag, flag);
      return 0;
  }
}

void
adc_flag_clear(
  volatile struct adc_registers_map* adc,
  enum adc_flag flag
)
{
  volatile u32* reg = &adc->SR;
  switch (flag)
  {
    case ADC_FLAG_ANALOG_WATCHDOG:
      *reg &= ~ADC_SR_AWD;
      break;

    case ADC_FLAG_EOC:
      *reg &= ~ADC_SR_EOC;
      break;

    case ADC_FLAG_JEOC:
      *reg &= ~ADC_SR_JEOC;
      break;

    case ADC_FLAG_JSTART:
      *reg &= ~ADC_SR_JSTRT;
      break;
        
    case ADC_FLAG_START:
      *reg &= ~ADC_SR_STRT;
      break;

#if defined(STM32_ADC_OVR)
    case ADC_FLAG_OVERRUN:
      *reg &= ~ADC_SR_OVR;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum adc_flag, flag);
      break;
  }
}

void
adc_set_analog_watchdog_channel(
  volatile struct adc_registers_map* adc,
  enum adc_reg_channel channel
)
{
  constexpr u32 shift = ADC_CR1_AWDCH_SHIFT;
  constexpr u32 mask = ADC_CR1_AWDCH_MASK << shift;
  volatile u32* reg = &adc->CR1;

  switch (channel)
  {
    case ADC_REG_CHANNEL0:
      *reg &= ~mask;
      break;

    case ADC_REG_CHANNEL1:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH1 << shift);
      break;

    case ADC_REG_CHANNEL2:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH2 << shift);
      break;

    case ADC_REG_CHANNEL3:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH3 << shift);
      break;

    case ADC_REG_CHANNEL4:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH4 << shift);
      break;

    case ADC_REG_CHANNEL5:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH5 << shift);
      break;

    case ADC_REG_CHANNEL6:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH6 << shift);
      break;

    case ADC_REG_CHANNEL7:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH7 << shift);
      break;

    case ADC_REG_CHANNEL8:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH8 << shift);
      break;

    case ADC_REG_CHANNEL9:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH9 << shift);
      break;

    case ADC_REG_CHANNEL10:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH10 << shift);
      break;

    case ADC_REG_CHANNEL11:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH11 << shift);
      break;

    case ADC_REG_CHANNEL12:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH12 << shift);
      break;

    case ADC_REG_CHANNEL13:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH13 << shift);
      break;

    case ADC_REG_CHANNEL14:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH14 << shift);
      break;

    case ADC_REG_CHANNEL15:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH15 << shift);
      break;

    case ADC_REG_CHANNEL16:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH16 << shift);
      break;

#if defined(STM32_ADC_AWDCH17)
    case ADC_REG_CHANNEL17:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH17 << shift);
      break;
#endif

#if defined(STM32_ADC_MAX_CHANNELS18) && defined(STM32_ADC_AWDCH18)
    case ADC_REG_CHANNEL18:
      syn_set_register_bits(reg, mask, ADC_CR1_AWDCH_CH18 << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum adc_watchdog_channel, channel);
      break;
  }
}

void
adc_interrupt_enable(
  volatile struct adc_registers_map* adc,
  enum adc_interrupt interrupt
)
{
  switch (interrupt)
  {
    case ADC_INTERRUPT_EOC:
      adc->CR1 |= ADC_CR1_EOCIE;
      break;

    case ADC_INTERRUPT_ANALOG_WATCHDOG:
      adc->CR1 |= ADC_CR1_AWDIE;
      break;

    case ADC_INTERRUPT_JEOC:
      adc->CR1 |= ADC_CR1_JEOCIE;
      break;

#if defined(STM32_ADC_OVR)
    case ADC_INTERRUPT_OVERRUN:
      adc->CR1 |= ADC_CR1_OVRIE;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum adc_interrupt, interrupt);
      break;
  }
}

void
adc_interrupt_disable(
  volatile struct adc_registers_map* adc,
  enum adc_interrupt interrupt
)
{
  switch (interrupt)
  {
    case ADC_INTERRUPT_EOC:
      adc->CR1 &= ~ADC_CR1_EOCIE;
      break;

    case ADC_INTERRUPT_ANALOG_WATCHDOG:
      adc->CR1 &= ~ADC_CR1_AWDIE;
      break;

    case ADC_INTERRUPT_JEOC:
      adc->CR1 &= ~ADC_CR1_JEOCIE;
      break;

#if defined(STM32_ADC_OVR)
    case ADC_INTERRUPT_OVERRUN:
      adc->CR1 &= ~ADC_CR1_OVRIE;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum adc_interrupt, interrupt);
      break;
  }
}

void
adc_scan_mode_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 |= ADC_CR1_SCAN;
}

void
adc_scan_mode_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 &= ~ADC_CR1_SCAN;
}

void
adc_set_watchdog_mode(
  volatile struct adc_registers_map* adc,
  enum adc_watchdog_mode mode
)
{
  volatile u32* reg = &adc->CR1;
  switch (mode)
  {
    case ADC_WATCHDOG_MODE_ALL_CHANNELS:
      *reg &= ~ADC_CR1_AWDSGL;
      break;

    case ADC_WATCHDOG_MODE_SINGLE_CHANNEL:
      *reg |= ADC_CR1_AWDSGL;
      break;

    default:
      devmode_error_invalid_enum(enum adc_watchdog_mode, mode);
      break;
  }
}

void
adc_automatic_inj_group_conversion_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 |= ADC_CR1_JAUTO;
}

void
adc_automatic_inj_group_conversion_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 &= ~ADC_CR1_JAUTO;
}

void
adc_discontinuous_mode_reg_channels_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 |= ADC_CR1_DISCEN;
}

void
adc_discontinuous_mode_reg_channels_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 &= ~ADC_CR1_DISCEN;
}

void
adc_discontinuous_mode_inj_channels_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 |= ADC_CR1_JDISCEN;
}

void
adc_discontinuous_mode_inj_channels_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 &= ~ADC_CR1_JDISCEN;
}

void
adc_set_discontinuous_mode_channel_count(
  volatile struct adc_registers_map* adc,
  u32 count
)
{
  devmode_assert_lower_or_eq(count, ADC_CR1_DISCNUM_MASK);
  constexpr u32 shift = ADC_CR1_DISCNUM_SHIFT;
  constexpr u32 mask = ADC_CR1_DISCNUM_MASK << shift;
  volatile u32* reg = &adc->CR1;
  syn_set_register_bits(reg, mask, count << shift);
}

#if defined(STM32_ADC_DUALMODE)
void
adc_set_dualmode(
  volatile struct adc_registers_map* adc,
  enum adc_dualmode mode
)
{
  constexpr u32 shift = ADC_CR1_DUALMOD_SHIFT;
  constexpr u32 mask = ADC_CR1_DUALMOD_MASK << shift;
  volatile u32* reg = &adc->CR1;

  switch (mode)
  {
    case ADC_DUALMODE_INDEPENDENT:
      *reg &= ~mask;
      break;

    case ADC_DUALMODE_REG_SIM_AND_INJ_SIM:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_REG_SIM_INJ_SIM << shift);
      break;

    case ADC_DUALMODE_REG_SIM_AND_ALT_TRG:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_REG_SIM_ALT_TRG << shift);
      break;

    case ADC_DUALMODE_INJ_SIM_AND_FAST_INTERLEAVED:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_INJ_SIM_FST_INLV << shift);
      break;

    case ADC_DUALMODE_INJ_SIM_AND_SLOW_INTERLEAVED:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_INJ_SIM_SLW_INLV << shift);
      break;

    case ADC_DUALMODE_INJ_SIM:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_INJ_SIM << shift);
      break;

    case ADC_DUALMODE_REG_SIM:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_REG_SIM << shift);
      break;

    case ADC_DUALMODE_FAST_INTERLEAVED:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_FST_INLV << shift);
      break;

    case ADC_DUALMODE_SLOW_INTERLEAVED:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_SLW_INLV << shift);
      break;

    case ADC_DUALMODE_ALT_TRG:
      syn_set_register_bits(reg, mask, ADC_CR1_DUALMOD_ALT_TRG << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_dual_mode, mode);
      break;
  }
}
#endif

void
adc_watchdog_inj_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 |= ADC_CR1_JAWDEN;
}

void
adc_watchdog_inj_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 &= ~ADC_CR1_JAWDEN;
}

void
adc_watchdog_reg_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 |= ADC_CR1_AWDEN;
}

void
adc_watchdog_reg_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR1 &= ~ADC_CR1_AWDEN;
}

#if defined(STM32_ADC_RESOLUTION)
void
adc_set_resolution(
  volatile struct adc_registers_map* adc,
  enum adc_resolution resolution
)
{
  constexpr u32 shift = ADC_CR1_RES_SHIFT;
  constexpr u32 mask = ADC_CR1_RES_MASK << shift;
  volatile u32* reg = &adc->CR1;

  switch (resolution)
  {
    case ADC_RESOLUTION_12BIT:
      *reg &= ~mask;
      break;

    case ADC_RESOLUTION_10BIT:
      syn_set_register_bits(reg, mask, ADC_CR1_RES_10BIT << shift);
      break;

    case ADC_RESOLUTION_8BIT:
      syn_set_register_bits(reg, mask, ADC_CR1_RES_8BIT << shift);
      break;

    case ADC_RESOLUTION_6BIT:
      syn_set_register_bits(reg, mask, ADC_CR1_RES_6BIT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_resolution, resolution);
      break;
  }
}
#endif

void
adc_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_ADON;
}

void
adc_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 &= ~ADC_CR2_ADON;
}

void
adc_set_conversion_method(
  volatile struct adc_registers_map* adc,
  enum adc_conversion_method method
)
{
  volatile u32* reg = &adc->CR2;
  switch (method)
  {
    case ADC_CONVERSION_METHOD_SINGLE:
      *reg &= ~ADC_CR2_CONT;
      break;

    case ADC_CONVERSION_METHOD_CONTINUOUS:
      *reg |= ADC_CR2_CONT;
      break;

    default:
      devmode_error_invalid_enum(enum adc_conversion_method, method);
      break;
  }
}

#if defined(STM32_ADC_CALIBRATION)
void
adc_calibration_begin(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_CAL;
}

u32
adc_is_calibration_in_progress(
  volatile struct adc_registers_map* adc
)
{
  return adc->CR2 & ADC_CR2_CAL;
}

void
adc_calibration_ready_wait(
  volatile struct adc_registers_map* adc
)
{
  while (adc_is_calibration_in_progress(adc));
}

void
adc_calibration_reset(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_RSTCAL;
}
#endif

void
adc_dma_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_DMA;
}

void
adc_dma_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 &= ~ADC_CR2_DMA;
}

#if defined(STM32_ADC_CR2_LAYOUT2)
void
adc_dma_requests_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_DDS;
}

void
adc_dma_requests_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 &= ~ADC_CR2_DDS;
}

void
adc_set_eoc_policy(
  volatile struct adc_registers_map* adc,
  enum adc_eoc_policy policy
)
{
  volatile u32* reg = &adc->CR2;
  switch (policy)
  {
    case ADC_EOC_POLICY_EACH_SEQUENCE:
      *reg &= ~ADC_CR2_EOCS;
      break;

    case ADC_EOC_POLICY_EACH_CONVERSION:
      *reg |= ADC_CR2_EOCS;
      break;

    default:
      devmode_error_invalid_enum(enum adc_eoc_policy, policy);
      break;
  }
}
#endif

void
adc_set_data_alignment(
  volatile struct adc_registers_map* adc,
  enum adc_data_alignment alignment
)
{
  volatile u32* reg = &adc->CR2;
  switch (alignment)
  {
    case ADC_DATA_ALIGNMENT_RIGHT:
      *reg &= ~ADC_CR2_ALIGN;
      break;

    case ADC_DATA_ALIGNMENT_LEFT:
      *reg |= ADC_CR2_ALIGN;
      break;

    default:
      devmode_error_invalid_enum(enum adc_data_alignment, alignment);
      break;
  }
}

#if defined(STM32_ADC_xEXTSEL_LAYOUT1) || defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
adc_set_inj_external_event(
  volatile struct adc_registers_map* adc,
  enum adc_inj_trigger_event event
)
{
  constexpr u32 shift = ADC_CR2_JEXTSEL_SHIFT;
  constexpr u32 mask = ADC_CR2_JEXTSEL_MASK << shift;
  volatile u32* reg = &adc->CR2;

  switch (event)
  {
#if defined(STM32_ADC_xEXTSEL_LAYOUT1)

    case ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_TRGO:
      *reg &= ~mask;
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_CC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC12_TIM1_CC4 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC12_TIM2_TRGO << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_CC1:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC12_TIM2_CC1 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC12_TIM3_CC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC12_TIM3_CC4 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC12_TIM4_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC12_TIM4_TRGO << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC12_EXTI:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC12_EXTI15 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_TIM1_TRGO << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_CC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_TIM1_CC4 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC3_TIM4_CC3:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_TIM4_CC3 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC2:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_TIM8_CC2 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_TIM8_CC4 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_TIM5_TRGO << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_CC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_TIM5_CC4 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_JSWSTART:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_ADC3_JSWSTART << shift);
      break;

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)

    case ADC_INJ_TRIGGER_EVENT_TIM1_OC4:
      *reg &= ~mask;
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM1_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM1_TRGO << shift);
      break;

#if defined(STM32_TIM2)
    case ADC_INJ_TRIGGER_EVENT_TIM2_OC1:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM2_OC1 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM2_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM2_TRGO << shift);
      break;
#endif

#if defined(STM32_TIM3)
    case ADC_INJ_TRIGGER_EVENT_TIM3_OC2:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM3_OC2 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM3_OC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM3_OC4 << shift);
      break;
#endif

#if defined(STM32_TIM4)
    case ADC_INJ_TRIGGER_EVENT_TIM4_OC1:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM4_OC1 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM4_OC2:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM4_OC2 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM4_OC3:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM4_OC3 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM4_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM4_TRGO << shift);
      break;
#endif

    case ADC_INJ_TRIGGER_EVENT_TIM5_OC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM5_OC4 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM5_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM5_TRGO << shift);
      break;

#if defined(STM32_TIM8)
    case ADC_INJ_TRIGGER_EVENT_TIM8_OC2:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM8_OC2 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM8_OC3:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM8_OC3 << shift);
      break;

    case ADC_INJ_TRIGGER_EVENT_TIM8_OC4:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_TIM8_OC4 << shift);
      break;
#endif

    case ADC_INJ_TRIGGER_EVENT_EXTI15:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTSEL_EXTI15 << shift);
      break;

#endif

    default:
      devmode_error_invalid_enum(enum adc_reg_trigger_event, event);
      break;
  }
}
#endif

void
adc_inj_start(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_JSWSTART;
}

#if defined(STM32_ADC_xEXTSEL_LAYOUT1) || defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
adc_set_reg_external_event(
  volatile struct adc_registers_map* adc,
  enum adc_reg_trigger_event event
)
{
  constexpr u32 shift = ADC_CR2_EXTSEL_SHIFT;
  constexpr u32 mask = ADC_CR2_EXTSEL_MASK << shift;
  volatile u32* reg = &adc->CR2;

  switch (event)
  {
#if defined(STM32_ADC_xEXTSEL_LAYOUT1)

    case ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC1:
      *reg &= ~mask;
      break;

    case ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC2:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC12_EXTSEL_TIM1_CC2 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC3:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC12_EXTSEL_TIM1_CC3 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC12_TIM2_CC2:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC12_EXTSEL_TIM2_CC2 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC12_TIM3_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC12_EXTSEL_TIM3_TRGO << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC12_TIM4_CC4:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC12_EXTSEL_TIM4_CC4 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC12_EXTI11:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC12_EXTSEL_EXTI11 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC3_TIM3_CC1:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_TIM3_CC1 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC3_TIM2_CC3:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_TIM2_CC3 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC3_TIM1_CC3:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_TIM1_CC3 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC3_TIM8_CC1:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_TIM8_CC1 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC3_TIM8_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_TIM8_TRGO << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC1:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_TIM5_CC1 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC3:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_TIM5_CC3 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_SWSTART:
      syn_set_register_bits(reg, mask, ADC_CR2_ADC3_EXTSEL_SWSTART << shift);
      break;

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)

    case ADC_REG_TRIGGER_EVENT_TIM1_OC1:
      *reg &= ~mask;
      break;

    case ADC_REG_TRIGGER_EVENT_TIM1_OC2:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM1_OC2 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM1_OC3:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM1_OC3 << shift);
      break;

#if defined(STM32_TIM2)
    case ADC_REG_TRIGGER_EVENT_TIM2_OC2:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM2_OC2 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM2_OC3:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM2_OC3 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM2_OC4:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM2_OC4 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM2_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM2_TRGO << shift);
      break;
#endif

#if defined(STM32_TIM3)
    case ADC_REG_TRIGGER_EVENT_TIM3_OC1:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM3_OC1 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM3_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM3_TRGO << shift);
      break;
#endif

#if defined(STM32_TIM4)
    case ADC_REG_TRIGGER_EVENT_TIM4_OC4:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM4_OC4 << shift);
      break;
#endif

    case ADC_REG_TRIGGER_EVENT_TIM5_OC1:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM5_OC1 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM5_OC2:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM5_OC2 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM5_OC3:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM5_OC3 << shift);
      break;

#if defined(STM32_TIM8)
    case ADC_REG_TRIGGER_EVENT_TIM8_OC1:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM8_OC1 << shift);
      break;

    case ADC_REG_TRIGGER_EVENT_TIM8_TRGO:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_TIM8_TRGO << shift);
      break;
#endif

    case ADC_REG_TRIGGER_EVENT_EXTI11:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTSEL_EXTI11 << shift);
      break;

#endif

    default:
      devmode_error_invalid_enum(enum adc_reg_trigger_event, event);
      break;
  }
}
#endif

void
adc_reg_start(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_SWSTART;
}

#if defined(STM32_ADC_CR2_LAYOUT1)
void
adc_temperature_sensor_enable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 |= ADC_CR2_TSVREFE;
}

void
adc_temperature_sensor_disable(
  volatile struct adc_registers_map* adc
)
{
  adc->CR2 &= ~ADC_CR2_TSVREFE;
}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
adc_set_inj_external_trigger_edge(
  volatile struct adc_registers_map* adc,
  enum adc_external_trigger_edge edge
)
{
  constexpr u32 shift = ADC_CR2_JEXTEN_SHIFT;
  constexpr u32 mask = ADC_CR2_JEXTEN_MASK << shift;
  volatile u32* reg = &adc->CR2;

  switch (edge)
  {
    case ADC_EXTERNAL_TRIGGER_EDGE_OFF:
      *reg &= ~mask;
      break;

    case ADC_EXTERNAL_TRIGGER_EDGE_RISING:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTEN_RISING_EDGE << shift);
      break;

    case ADC_EXTERNAL_TRIGGER_EDGE_FALLING:
      syn_set_register_bits(reg, mask, ADC_CR2_JEXTEN_FALLING_EDGE << shift);
      break;

    case ADC_EXTERNAL_TRIGGER_EDGE_BOTH:
      *reg |= (ADC_CR2_JEXTEN_BOTH << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_external_trigger_edge, edge);
      break;
  }
}

void
adc_set_reg_external_trigger_edge(
  volatile struct adc_registers_map* adc,
  enum adc_external_trigger_edge edge
)
{
  constexpr u32 shift = ADC_CR2_EXTEN_SHIFT;
  constexpr u32 mask = ADC_CR2_EXTEN_MASK << shift;
  volatile u32* reg = &adc->CR2;

  switch (edge)
  {
    case ADC_EXTERNAL_TRIGGER_EDGE_OFF:
      *reg &= ~mask;
      break;

    case ADC_EXTERNAL_TRIGGER_EDGE_RISING:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTEN_RISING_EDGE << shift);
      break;

    case ADC_EXTERNAL_TRIGGER_EDGE_FALLING:
      syn_set_register_bits(reg, mask, ADC_CR2_EXTEN_FALLING_EDGE << shift);
      break;

    case ADC_EXTERNAL_TRIGGER_EDGE_BOTH:
      *reg |= (ADC_CR2_EXTEN_BOTH << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_external_trigger_edge, edge);
      break;
  }
}
#endif

#if defined(STM32_ADC_SMPR)
void
adc_set_channel_sample_rate(
  volatile struct adc_registers_map* adc,
  enum adc_reg_channel channel,
  enum adc_sample_rate rate
)
{
  const enum adc_smpr sample_rate_bits = adc_convert_sample_rate_api_to_impl(rate);
  u32 shift;
  u32 mask;
  volatile u32* reg;

  // u32 offset = channel < ADC_REG_CHANNEL10 ? 0 : 10;
  // reg = channel < ADC_REG_CHANNEL10 ? &adc->SMPR2 : &adc->SMPR1;
  // shift = (ADC_SMPR_STRIDE * (channel - offset));
  // mask = ADC_SMPR_MASK << shift;
  // syn_set_register_bits(reg, mask, sample_rate_bits << shift);

  switch (channel)
  {
    case ADC_REG_CHANNEL0:
      shift = 0;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL1:
      shift = 3;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL2:
      shift = 6;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL3:
      shift = 9;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL4:
      shift = 12;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL5:
      shift = 15;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL6:
      shift = 18;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL7:
      shift = 21;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL8:
      shift = 24;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL9:
      shift = 27;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR2;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL10:
      shift = 0;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL11:
      shift = 3;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL12:
      shift = 6;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL13:
      shift = 9;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL14:
      shift = 12;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL15:
      shift = 15;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL16:
      shift = 18;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

    case ADC_REG_CHANNEL17:
      shift = 21;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;


#if defined(STM32_ADC_MAX_CHANNELS18)
    case ADC_REG_CHANNEL18:
      shift = 24;
      mask = ADC_SMPR_MASK << shift;
      reg = &adc->SMPR1;
      syn_set_register_bits(reg, mask, sample_rate_bits << shift);
      break;

#endif

    default:
      devmode_error_invalid_enum(enum adc_sample_rate, rate);
      break;
  }
}

void
adc_set_sample_time_all_channels(
  volatile struct adc_registers_map* adc,
  enum adc_sample_rate rate
)
{
  enum adc_smpr sample_rate_bits = adc_convert_sample_rate_api_to_impl(rate);

  u32 smpr1 = 0;
  u32 smpr2 = 0;

  smpr1 |= (sample_rate_bits << 0);
  smpr1 |= (sample_rate_bits << 3);
  smpr1 |= (sample_rate_bits << 6);
  smpr1 |= (sample_rate_bits << 9);
  smpr1 |= (sample_rate_bits << 12);
  smpr1 |= (sample_rate_bits << 15);
  smpr1 |= (sample_rate_bits << 18);
  smpr1 |= (sample_rate_bits << 21);

#if defined(STM32_ADC_MAX_CHANNELS18)
  smpr1 |= (sample_rate_bits << 24);
#endif

  smpr2 |= (sample_rate_bits << 0);
  smpr2 |= (sample_rate_bits << 3);
  smpr2 |= (sample_rate_bits << 6);
  smpr2 |= (sample_rate_bits << 9);
  smpr2 |= (sample_rate_bits << 12);
  smpr2 |= (sample_rate_bits << 15);
  smpr2 |= (sample_rate_bits << 18);
  smpr2 |= (sample_rate_bits << 21);
  smpr2 |= (sample_rate_bits << 24);
  smpr2 |= (sample_rate_bits << 27);

  adc->SMPR1 = smpr1;
  adc->SMPR2 = smpr2;
}
#endif

void
adc_set_inj_offset(
  volatile struct adc_registers_map* adc,
  enum adc_inj_channel channel,
  u32 offset
)
{
  devmode_assert_lower_or_eq(offset, ADC_JOFR_JOFFSET_MASK);
  constexpr u32 shift = ADC_JOFR_JOFFSET_SHIFT;
  constexpr u32 mask = ADC_JOFR_JOFFSET_MASK << shift;
  volatile u32* reg;

  switch (channel)
  {
    case ADC_INJ_CHANNEL0:
      reg = &adc->JOFR1;
      syn_set_register_bits(reg, mask, offset << shift);
      break;

    case ADC_INJ_CHANNEL1:
      reg = &adc->JOFR2;
      syn_set_register_bits(reg, mask, offset << shift);
      break;

    case ADC_INJ_CHANNEL2:
      reg = &adc->JOFR3;
      syn_set_register_bits(reg, mask, offset << shift);
      break;

    case ADC_INJ_CHANNEL3:
      reg = &adc->JOFR4;
      syn_set_register_bits(reg, mask, offset << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_inj_channel, channel);
      break;
  }
}

void
adc_set_watchdog_high_threshold(
  volatile struct adc_registers_map* adc,
  u32 threshold
)
{
  devmode_assert_lower_or_eq(threshold, ADC_HTR_MASK);
  constexpr u32 shift = ADC_HTR_SHIFT;
  constexpr u32 mask = ADC_HTR_MASK << shift;
  volatile u32* reg = &adc->HTR;
  syn_set_register_bits(reg, mask, threshold << shift);
}


void
adc_set_watchdog_low_threshold(
  volatile struct adc_registers_map* adc,
  u32 threshold
)
{
  devmode_assert_lower_or_eq(threshold, ADC_LTR_MASK);
  constexpr u32 shift = ADC_LTR_SHIFT;
  constexpr u32 mask = ADC_LTR_MASK << shift;
  volatile u32* reg = &adc->LTR;
  syn_set_register_bits(reg, mask, threshold << shift);
}

void
adc_set_reg_sequence(
  volatile struct adc_registers_map* adc,
  u32* sequence,
  u32 count
)
{
  constexpr u32 shift = ADC_SQR_STRIDE;

  u32 sqr1 = adc->SQR1;
  u32 sqr3 = adc->SQR3;
  sqr3 &= (0b11u << 30);

  for (u32 i = 0; i < count && i < 6; ++i)
  {
    sqr3 |= (sequence[i] << (shift * i));
  }

  adc->SQR3 = sqr3;

  if (count > 6)
  {
    u32 sqr2 = adc->SQR2;
    sqr2 &= (0b11u << 30);

    for (u32 i = 0; i < count - 6 && i < 6; ++i)
    {
      sqr2 |= (sequence[i + 6] << (shift * i));
    }

    adc->SQR2 = sqr2;

    if (count > 12)
    {
      sqr1 &= (0xfffu << 24);

      for (u32 i = 0; i < count - 12 && i < 6; ++i)
      {
        sqr1 |= (sequence[i + 12] << (shift * i));
      }
    }
  }

  sqr1 &= ~((ADC_SQR_L_MASK << ADC_SQR_L_SHIFT) | (0xffu << 24));
  sqr1 |= ((count - 1) << ADC_SQR_L_SHIFT);

  adc->SQR1 = sqr1;
}

void
adc_set_inj_sequence(
  volatile struct adc_registers_map* adc,
  u32* sequence,
  u32 count
)
{
  constexpr u32 shift = ADC_JSQR_STRIDE;
  u32 reg = adc->JSQR;
  reg &= (0x3ffu << 22);

  for (u32 i = 0; i < count && i < 4; ++i)
  {
    reg |= (sequence[i] << (i * shift));
  }

  reg |= ((count - 1) << ADC_JSQR_JL_SHIFT);
  adc->JSQR = reg;
}

u32
adc_inj_data_read(
  volatile struct adc_registers_map* adc,
  enum adc_inj_channel channel
)
{
  constexpr u32 shift = ADC_JDR_JDATA_SHIFT;
  constexpr u32 mask = ADC_JDR_JDATA_MASK;
  switch (channel)
  {
    case ADC_INJ_CHANNEL0:
      return (adc->JDR1 >> shift) & mask;

    case ADC_INJ_CHANNEL1:
      return (adc->JDR2 >> shift) & mask;

    case ADC_INJ_CHANNEL2:
      return (adc->JDR3 >> shift) & mask;

    case ADC_INJ_CHANNEL3:
      return (adc->JDR4 >> shift) & mask;

    default:
      devmode_error_invalid_enum(enum adc_inj_channel, channel);
      return 0;
  }
}

u32
adc_reg_data_read(
  volatile struct adc_registers_map* adc
)
{
  return adc->DR;
}

#if defined(STM32_ADC_COM)

#if defined(STM32_ADC_CCR_REG)

#if defined(STM32_ADC_COM_MULTI_MODE)
void
adc_set_multi_adc_mode(
  enum adc_multi_adc_config config,
  enum adc_multi_adc_mode mode
)
{
  devmode_assert_lower_or_eq(config, ADC_MULTI_ADC_CONFIG_TRIPLE_MODE);

  constexpr u32 shift = ADC_CCR_MULTI_SHIFT;
  constexpr u32 mask = ADC_CCR_MULTI_MASK << shift;
  volatile u32* reg = &ADCCOM->CSR;
  const u32 cnfbit = (1 << 5) * config;

  switch (mode)
  {
    case ADC_MULTI_ADC_MODE_REG_SIM_AND_INJ_SIM:
      syn_set_register_bits(
        reg,
        mask,
        (ADC_CCR_MULTI_REG_SIM_AND_INJ_SIM | cnfbit) << shift
      );
      break;

    case ADC_MULTI_ADC_MODE_REG_SIM_AND_ALT_TRG:
      syn_set_register_bits(
        reg,
        mask,
        (ADC_CCR_MULTI_REG_SIM_AND_ALT_TRG | cnfbit) << shift 
      );
      break;

    case ADC_MULTI_ADC_MODE_INJ_SIM:
      syn_set_register_bits(
        reg,
        mask,
        (ADC_CCR_MULTI_INJ_SIM | cnfbit) << shift
      );
      break;

    case ADC_MULTI_ADC_MODE_REG_SIM:
      syn_set_register_bits(
        reg,
        mask,
        (ADC_CCR_MULTI_REG_SIM | cnfbit) << shift
      );
      break;

    case ADC_MULTI_ADC_MODE_INTERLEAVED:
      syn_set_register_bits(
        reg,
        mask,
        (ADC_CCR_MULTI_INTERLEAVED | cnfbit) << shift
      );
      break;
        
    case ADC_MULTI_ADC_MODE_ALT_TRG:
      syn_set_register_bits(
        reg,
        mask,
        (ADC_CCR_MULTI_ALT_TRG | cnfbit) << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum adc_multi_adc_mode, mode);
      break;
  }
}
#endif

#if defined(STM32_ADC_COM_DELAY)
void
adc_set_delay(
  enum adc_sampling_delay delay
)
{
  constexpr u32 shift = ADC_CCR_DELAY_SHIFT;
  constexpr u32 mask = ADC_CCR_DELAY_MASK << shift;
  volatile u32* reg = &ADCCOM->CCR;
  switch (delay)
  {
    case ADC_SAMPLING_DELAY5:
      *reg &= ~mask;
      break;

    case ADC_SAMPLING_DELAY6:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY6 << shift);
      break;

    case ADC_SAMPLING_DELAY7:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY7 << shift);
      break;

    case ADC_SAMPLING_DELAY8:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY8 << shift);
      break;

    case ADC_SAMPLING_DELAY9:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY9 << shift);
      break;

    case ADC_SAMPLING_DELAY10:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY10 << shift);
      break;

    case ADC_SAMPLING_DELAY11:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY11 << shift);
      break;

    case ADC_SAMPLING_DELAY12:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY12 << shift);
      break;

    case ADC_SAMPLING_DELAY13:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY13 << shift);
      break;

    case ADC_SAMPLING_DELAY14:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY14 << shift);
      break;

    case ADC_SAMPLING_DELAY15:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY15 << shift);
      break;

    case ADC_SAMPLING_DELAY16:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY16 << shift);
      break;

    case ADC_SAMPLING_DELAY17:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY17 << shift);
      break;

    case ADC_SAMPLING_DELAY18:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY18 << shift);
      break;

    case ADC_SAMPLING_DELAY19:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY19 << shift);
      break;

    case ADC_SAMPLING_DELAY20:
      syn_set_register_bits(reg, mask, ADC_CCR_DELAY20 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_sampling_delay, delay);
      break;
  }
}
#endif

#if defined(STM32_ADC_COM_DMA)
void
adc_set_multi_adc_dma_policy(
  enum adc_multi_adc_dma_policy policy
)
{
  volatile u32* reg = &ADCCOM->CCR;
  switch (policy)
  {
    case ADC_MULTI_ADC_DMA_POLICY_LAST_TRANSFER:
      *reg &= ~ADC_CCR_DDS;
      break;

    case ADC_MULTI_ADC_DMA_POLICY_REPEAT:
      *reg |= ADC_CCR_DDS;
      break;

    default:
      devmode_error_invalid_enum(enum adc_multi_adc_dma_policy, policy);
      break;
  }
}

void
adc_set_multi_adc_dma_mode(
  enum adc_multi_adc_dma_mode mode
)
{
  constexpr u32 shift = ADC_CCR_DMA_SHIFT;
  constexpr u32 mask = ADC_CCR_DMA_MASK << shift;
  volatile u32* reg = &ADCCOM->CCR;

  switch (mode)
  {
    case ADC_MULTI_ADC_DMA_MODE_OFF:
      *reg &= ~mask;
      break;

    case ADC_MULTI_ADC_DMA_MODE1:
      syn_set_register_bits(reg, mask, ADC_CCR_DMA_DMA_MODE1 << shift);
      break;

    case ADC_MULTI_ADC_DMA_MODE2:
      syn_set_register_bits(reg, mask, ADC_CCR_DMA_DMA_MODE2 << shift);
      break;

    case ADC_MULTI_ADC_DMA_MODE3:
      syn_set_register_bits(reg, mask, ADC_CCR_DMA_DMA_MODE3 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_multi_adc_dma_mode, mode);
      break;
  }
}
#endif

#if defined(STM32_ADC_COM_PRE)
void
adc_set_multi_adc_adc_prescaler(
  enum adc_multi_adc_prescaler prescaler
)
{
  constexpr u32 shift = ADC_CCR_ADCPRE_SHIFT;
  constexpr u32 mask = ADC_CCR_ADCPRE_MASK << shift;
  volatile u32* reg = &ADCCOM->CCR;

  switch (prescaler)
  {
    case ADC_MULTI_ADC_PRESCALER_DIV2:
      *reg &= ~mask;
      break;

    case ADC_MULTI_ADC_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, ADC_CCR_ADCPRE_DIV4 << shift);
      break;

    case ADC_MULTI_ADC_PRESCALER_DIV6:
      syn_set_register_bits(reg, mask, ADC_CCR_ADCPRE_DIV6 << shift);
      break;

    case ADC_MULTI_ADC_PRESCALER_DIV8:
      syn_set_register_bits(reg, mask, ADC_CCR_ADCPRE_DIV8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum adc_multi_adc_prescaler, prescaler);
      break;
  }
}
#endif

void
adc_multi_adc_vbat_enable(void)
{
  ADCCOM->CCR |= ADC_CCR_VBATE;
}

void
adc_multi_adc_vbat_disable(void)
{
  ADCCOM->CCR &= ~ADC_CCR_VBATE;
}

void
adc_multi_adc_temperature_sensor_enable(void)
{
  ADCCOM->CCR |= ADC_CCR_TSVREFE;
}

void
adc_multi_adc_temperature_sensor_disable(void)
{
  ADCCOM->CCR &= ~ADC_CCR_TSVREFE;
}
#endif

#if defined(STM32_ADC_CDR_REG)

u32
adc_get_reg_conversion_data1(void)
{
  constexpr u32 shift = ADC_CDR_DATA1_SHIFT;
  constexpr u32 mask = ADC_CDR_DATA1_MASK;
  volatile u32* reg = &ADCCOM->CDR;
  return (*reg >> shift) & mask;
}

u32
adc_get_reg_conversion_data2(void)
{
  constexpr u32 shift = ADC_CDR_DATA2_SHIFT;
  constexpr u32 mask = ADC_CDR_DATA2_MASK;
  volatile u32* reg = &ADCCOM->CDR;
  return (*reg >> shift) & mask;
}

#endif

#endif
