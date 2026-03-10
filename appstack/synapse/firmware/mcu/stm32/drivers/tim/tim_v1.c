#include "synapse/stm32/drivers/tim/tim_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"

typedef volatile struct tim_registers_map tim_periph;

#if defined(STM32_TIM1)
tim_periph* TIM1 = (tim_periph*) (TIM1_ADDR);
#endif

#if defined(STM32_TIM2)
tim_periph* TIM2 = (tim_periph*) (TIM2_ADDR);
#endif

#if defined(STM32_TIM3)
tim_periph* TIM3 = (tim_periph*) (TIM3_ADDR);
#endif

#if defined(STM32_TIM4)
tim_periph* TIM4 = (tim_periph*) (TIM4_ADDR);
#endif

#if defined(STM32_TIM5)
tim_periph* TIM5 = (tim_periph*) (TIM5_ADDR);
#endif

#if defined(STM32_TIM6)
tim_periph* TIM6 = (tim_periph*) (TIM6_ADDR);
#endif

#if defined(STM32_TIM7)
tim_periph* TIM7 = (tim_periph*) (TIM7_ADDR);
#endif

#if defined(STM32_TIM8)
tim_periph* TIM8 = (tim_periph*) (TIM8_ADDR);
#endif

#if defined(STM32_TIM9)
tim_periph* TIM9 = (tim_periph*) (TIM9_ADDR);
#endif

#if defined(STM32_TIM10)
tim_periph* TIM10 = (tim_periph*) (TIM10_ADDR);
#endif

#if defined(STM32_TIM11)
tim_periph* TIM11 = (tim_periph*) (TIM11_ADDR);
#endif

#if defined(STM32_TIM12)
tim_periph* TIM12 = (tim_periph*) (TIM12_ADDR);
#endif

#if defined(STM32_TIM13)
tim_periph* TIM13 = (tim_periph*) (TIM13_ADDR);
#endif

#if defined(STM32_TIM14)
tim_periph* TIM14 = (tim_periph*) (TIM14_ADDR);
#endif

#if defined(STM32_TIM15)
tim_periph* TIM15 = (tim_periph*) (TIM15_ADDR);
#endif

#if defined(STM32_TIM16)
tim_periph* TIM16 = (tim_periph*) (TIM16_ADDR);
#endif

#if defined(STM32_TIM17)
tim_periph* TIM17 = (tim_periph*) (TIM17_ADDR);
#endif

static u32
convert_ccs_api_to_impl(
  enum tim_channel channel,
  enum tim_channel_direction direction
)
{
  static constexpr u32 pairs[4][4] = {
    {
      TIM_CCMR1_CC1S_OUTPUT, TIM_CCMR1_CC1S_TI1,
      TIM_CCMR1_CC1S_TI2, TIM_CCMR1_CC1S_TRC
    },
    {
      TIM_CCMR1_CC2S_OUTPUT, TIM_CCMR1_CC2S_TI1,
      TIM_CCMR1_CC2S_TI2, TIM_CCMR1_CC2S_TRC
    },
    {
      TIM_CCMR2_CC3S_OUTPUT, TIM_CCMR2_CC3S_TI3,
      TIM_CCMR2_CC3S_TI4, TIM_CCMR2_CC3S_TRC
    },
    {
      TIM_CCMR2_CC4S_OUTPUT, TIM_CCMR2_CC4S_TI3,
      TIM_CCMR2_CC4S_TI4, TIM_CCMR2_CC4S_TRC
    }
  };

  devmode_assert_lower_or_eq(channel, TIM_CHANNEL4);
  devmode_assert_lower_or_eq(direction, TIM_CHANNEL_DIRECTION_TRC);
  return pairs[channel][direction];
}

static u32 
convert_psc_api_to_impl(
  enum tim_ic_prescaler prescaler
)
{
  switch (prescaler)
  {
    case TIM_IC_PRESCALER_NOSKIP:
      return TIM_CCMR_ICPSC_NOPSC;

    case TIM_IC_PRESCALER_SKIP_2:
      return TIM_CCMR_ICPSC_2EVENTS;

    case TIM_IC_PRESCALER_SKIP_4:
      return TIM_CCMR_ICPSC_4EVENTS;

    case TIM_IC_PRESCALER_SKIP_8:
      return TIM_CCMR_ICPSC_8EVENTS;

    default:
      devmode_error_invalid_enum(enum tim_ic_prescaler, prescaler);
      return 0;
  }
}

static u32
convert_filter_api_to_impl(
  enum tim_ic_filter filter
)
{
  switch (filter)
  {
    case TIM_IC_FILTER_NOFILTER:
      return TIM_CCMR_ICF_NOFILTER;

    case TIM_IC_FILTER_NODIV_N2:
      return TIM_CCMR_ICF_NODIV_N2;

    case TIM_IC_FILTER_NODIV_N4:
      return TIM_CCMR_ICF_NODIV_N4;

    case TIM_IC_FILTER_NODIV_N8:
      return TIM_CCMR_ICF_NODIV_N8;

    case TIM_IC_FILTER_DIV2_N6:
      return TIM_CCMR_ICF_DIV2_N6;

    case TIM_IC_FILTER_DIV2_N8:
      return TIM_CCMR_ICF_DIV2_N8;

    case TIM_IC_FILTER_DIV4_N6:
      return TIM_CCMR_ICF_DIV4_N6;

    case TIM_IC_FILTER_DIV4_N8:
      return TIM_CCMR_ICF_DIV4_N8;

    case TIM_IC_FILTER_DIV8_N6:
      return TIM_CCMR_ICF_DIV8_N6;

    case TIM_IC_FILTER_DIV8_N8:
      return TIM_CCMR_ICF_DIV8_N8;

    case TIM_IC_FILTER_DIV16_N5:
      return TIM_CCMR_ICF_DIV16_N5;

    case TIM_IC_FILTER_DIV16_N6:
      return TIM_CCMR_ICF_DIV16_N6;

    case TIM_IC_FILTER_DIV16_N8:
      return TIM_CCMR_ICF_DIV16_N8;

    case TIM_IC_FILTER_DIV32_N5:
      return TIM_CCMR_ICF_DIV32_N5;

    case TIM_IC_FILTER_DIV32_N6:
      return TIM_CCMR_ICF_DIV32_N6;

    case TIM_IC_FILTER_DIV32_N8:
      return TIM_CCMR_ICF_DIV32_N8;
        
    default:
      devmode_error_invalid_enum(enum tim_ic_filter, filter);
      return 0;
  }
}

static u32
convert_oc_mode_api_to_impl(
  enum tim_oc_mode mode
)
{
  switch (mode)
  {
    case TIM_OC_MODE_FROZEN:
      return TIM_CCMR_OCM_FROZEN;

    case TIM_OC_MODE_FORCED_HIGH:
      return TIM_CCMR_OCM_FORCE_HIGH;

    case TIM_OC_MODE_FORCED_LOW:
      return TIM_CCMR_OCM_FORCE_LOW;

    case TIM_OC_MODE_TOGGLE:
      return TIM_CCMR_OCM_TOGGLE;

    case TIM_OC_MODE_FORCE_INACTIVE:
      return TIM_CCMR_OCM_FORCE_INACTIVE;

    case TIM_OC_MODE_FORCE_ACTIVE:
      return TIM_CCMR_OCM_FORCE_ACTIVE;

    case TIM_OC_MODE_PWM1:
      return TIM_CCMR_OCM_PWM1;

    case TIM_OC_MODE_PWM2:
      return TIM_CCMR_OCM_PWM2;

    default:
      devmode_error_invalid_enum(enum tim_oc_mode, mode);
      return 0;
  }
}

void
tim_counter_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 |= TIM_CR1_CEN;
}

void
tim_counter_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 &= ~TIM_CR1_CEN;
}

void
tim_update_event_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 |= TIM_CR1_UDIS;
}

void
tim_update_event_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 &= ~TIM_CR1_UDIS;
}

void
tim_set_update_request_event_source(
  volatile struct tim_registers_map* tim,
  enum tim_update_request_source source
)
{
  switch (source)
  {
    case TIM_UPDATE_REQUEST_SOURCE_COUNTER_AND_DMA:
      tim->CR1 &= ~TIM_CR1_URS;
      break;

    case TIM_UPDATE_REQUEST_SOURCE_ALL:
      tim->CR1 |= TIM_CR1_URS;
      break;

    default:
      devmode_error_invalid_enum(enum tim_update_request_source, source);
      break;
  }
}

void
tim_one_pulse_mode_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 |= TIM_CR1_OPM;
}

void
tim_one_pulse_mode_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 &= ~TIM_CR1_OPM;
}

void
tim_set_counter_direction(
  volatile struct tim_registers_map* tim,
  enum tim_counter_direction direction
)
{
  switch (direction)
  {
    case TIM_COUNTER_DIRECTION_UP:
      tim->CR1 &= ~TIM_CR1_DIR;
      break;

    case TIM_COUNTER_DIRECTION_DOWN:
      tim->CR1 |= TIM_CR1_DIR;
      break;

    default:
      devmode_error_invalid_enum(enum tim_counter_direction, direction);
      break;
  }
}

u32
tim_get_counter_direction(
  volatile struct tim_registers_map* tim
)
{
  return tim->CR1 & TIM_CR1_DIR;
}

void
tim_set_center_aligned_mode(
  volatile struct tim_registers_map* tim,
  enum tim_center_aligned_mode mode
)
{
  constexpr u32 shift = TIM_CR1_CMS_SHIFT;
  constexpr u32 mask = TIM_CR1_CMS_MASK << shift;
  volatile u32* reg = &tim->CR1;

  switch (mode)
  {
    case TIM_CENTER_ALIGNED_MODE_EDGE:
      *reg &= ~mask;
      break;

    case TIM_CENTER_ALIGNED_MODE_1:
      syn_set_register_bits(reg, mask, TIM_CR1_CMS_CENTER_ALIGNED1 << shift);
      break;

    case TIM_CENTER_ALIGNED_MODE_2:
      syn_set_register_bits(reg, mask, TIM_CR1_CMS_CENTER_ALIGNED2 << shift);
      break;

    case TIM_CENTER_ALIGNED_MODE_3:
      *reg |= (TIM_CR1_CMS_CENTER_ALIGNED3 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_center_aligned_mode, mode);
      break;
  }
}

void
tim_auto_reload_preload_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 |= TIM_CR1_ARPE;
}

void
tim_auto_reload_preload_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR1 &= ~TIM_CR1_ARPE;
}

void
tim_set_clock_division(
  volatile struct tim_registers_map* tim,
  enum tim_clock_division division
)
{
  constexpr u32 shift = TIM_CR1_CKD_SHIFT;
  constexpr u32 mask = TIM_CR1_CKD_MASK << shift;
  volatile u32* reg = &tim->CR1;

  switch (division)
  {
    case TIM_CLOCK_DIVISION_NODIV:
      *reg &= ~mask;
      break;

    case TIM_CLOCK_DIVISION_DIV2:
      syn_set_register_bits(reg, mask, TIM_CR1_CKD_DTS_2CK << shift);
      break;

    case TIM_CLOCK_DIVISION_DIV4:
      syn_set_register_bits(reg, mask, TIM_CR1_CKD_DTS_4CK << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_clock_division, division);
      break;
  }
}

void
tim_cc_preload_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR2 |= TIM_CR2_CCPC;
}

void
tim_cc_preload_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->CR2 &= ~TIM_CR2_CCPC;
}

void
tim_set_cc_update_trigger(
  volatile struct tim_registers_map* tim,
  enum tim_update_trigger trigger
)
{
  switch (trigger)
  {
    case TIM_UPDATE_TRIGGER_COMG_BIT:
      tim->CR2 &= ~TIM_CR2_CCUS;
      break;

    case TIM_UPDATE_TRIGGER_COMG_BIT_OR_TRGI:
      tim->CR2 |= TIM_CR2_CCUS;
      break;

    default:
      devmode_error_invalid_enum(enum tim_update_trigger, trigger);
      break;
  }
}

void
tim_set_cc_dma_request_source(
  volatile struct tim_registers_map* tim,
  enum tim_cc_dma_request_source source
)
{
  switch (source)
  {
    case TIM_CC_DMA_REQUEST_SOURCE_CC_EVENT:
      tim->CR2 &= ~TIM_CR2_CCDS;
      break;

    case TIM_CC_DMA_REQUEST_SOURCE_UPDATE_EVENT:
      tim->CR2 |= TIM_CR2_CCDS;
      break;

    default:
      devmode_error_invalid_enum(enum tim_cc_dma_request_source, source);
      break;
  }
}

void
tim_set_master_mode_trigger(
  volatile struct tim_registers_map* tim,
  enum tim_master_mode_trigger trigger
)
{
  constexpr u32 shift = TIM_CR2_MMS_SHIFT;
  constexpr u32 mask = TIM_CR2_MMS_MASK << shift;
  volatile u32* reg = &tim->CR2;

  switch (trigger)
  {
    case TIM_MASTER_MODE_TRIGGER_RESET:
      *reg &= ~mask;
      break;

    case TIM_MASTER_MODE_TRIGGER_ENABLE:
      syn_set_register_bits(reg, mask, TIM_CR2_MMS_ENABLE << shift);
      break;

    case TIM_MASTER_MODE_TRIGGER_UPDATE:
      syn_set_register_bits(reg, mask, TIM_CR2_MMS_UPDATE << shift);
      break;

    case TIM_MASTER_MODE_TRIGGER_COMPARE_PULSE:
      syn_set_register_bits(reg, mask, TIM_CR2_MMS_COMPARE_PULSE << shift);
      break;

    case TIM_MASTER_MODE_TRIGGER_COMPARE_OC1:
      syn_set_register_bits(reg, mask, TIM_CR2_MMS_COMPARE_OC1 << shift);
      break;

    case TIM_MASTER_MODE_TRIGGER_COMPARE_OC2:
      syn_set_register_bits(reg, mask, TIM_CR2_MMS_COMPARE_OC2 << shift);
      break;

    case TIM_MASTER_MODE_TRIGGER_COMPARE_OC3:
      syn_set_register_bits(reg, mask, TIM_CR2_MMS_COMPARE_OC3 << shift);
      break;

    case TIM_MASTER_MODE_TRIGGER_COMPARE_OC4:
      *reg |= (TIM_CR2_MMS_COMPARE_OC4 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_master_mode_trigger, trigger);
      break;
  }
}

void
tim_set_ti1_mode(
  volatile struct tim_registers_map* tim,
  enum tim_ti1_mode mode
)
{
  switch (mode)
  {
    case TIM_TI1_MODE_DEFAULT:
      tim->CR2 &= ~TIM_CR2_TI1S;
      break;

    case TIM_TI1_MODE_XOR:
      tim->CR2 |= TIM_CR2_TI1S;
      break;

    default:
      devmode_error_invalid_enum(enum tim_ti1_mode, mode);
      break;
  }
}

void
tim_set_output_idle_state(
  volatile struct tim_registers_map* tim,
  enum tim_oc_output output,
  enum tim_oc_idle_state state
)
{
  devmode_assert_lower_or_eq(output, TIM_OC_OUTPUT_OIS4);
  constexpr u32 mask = 1 << 8;

  switch (state)
  {
    case TIM_OC_IDLE_STATE_LOW:
      tim->CR2 &= ~(mask << output);
      break;

    case TIM_OC_IDLE_STATE_HIGH:
      tim->CR2 |= (mask << output);
      break;

    default:
      devmode_error_invalid_enum(enum tim_oc_idle_state, state);
      break;
  }
}

void
tim_set_slave_mode(
  volatile struct tim_registers_map* tim,
  enum tim_slave_mode mode
)
{
  constexpr u32 shift = TIM_SMCR_SMS_SHIFT;
  constexpr u32 mask = TIM_SMCR_SMS_MASK << shift;
  volatile u32* reg = &tim->SMCR;

  switch (mode)
  {
    case TIM_SLAVE_MODE_DISABLED:
      *reg &= ~mask;
      break;

    case TIM_SLAVE_MODE_ENCODER_MODE_1:
      syn_set_register_bits(reg, mask, TIM_SLAVE_MODE_ENCODER_MODE_1 << shift);
      break;

    case TIM_SLAVE_MODE_ENCODER_MODE_2:
      syn_set_register_bits(reg, mask, TIM_SLAVE_MODE_ENCODER_MODE_2 << shift);
      break;

    case TIM_SLAVE_MODE_ENCODER_MODE_3:
      syn_set_register_bits(reg, mask, TIM_SLAVE_MODE_ENCODER_MODE_3 << shift);
      break;

    case TIM_SLAVE_MODE_RESET_MODE:
      syn_set_register_bits(reg, mask, TIM_SLAVE_MODE_RESET_MODE << shift);
      break;

    case TIM_SLAVE_MODE_GATED_MODE:
      syn_set_register_bits(reg, mask, TIM_SLAVE_MODE_GATED_MODE << shift);
      break;

    case TIM_SLAVE_MODE_TRIGGER_MODE:
      syn_set_register_bits(reg, mask, TIM_SLAVE_MODE_TRIGGER_MODE << shift);
      break;

    case TIM_SLAVE_MODE_EXTERNAL_CLOCK:
      *reg |= TIM_SMCR_SMS_EXTERNAL_CLOCK_MODE1;
      break;

    default:
      devmode_error_invalid_enum(enum tim_slave_mode, mode);
      break;
  }
}

void
tim_set_input_trigger(
  volatile struct tim_registers_map* tim,
  enum tim_input_trigger trigger
)
{
  constexpr u32 shift = TIM_SMCR_TS_SHIFT;
  constexpr u32 mask = TIM_SMCR_TS_MASK << shift;
  volatile u32* reg = &tim->SMCR;

  switch (trigger)
  {
    case TIM_INPUT_TRIGGER_INTERNAL_0:
      *reg &= ~mask;
      break;

    case TIM_INPUT_TRIGGER_INTERNAL_1:
      syn_set_register_bits(reg, mask, TIM_SMCR_TS_ITR1 << shift);
      break;

    case TIM_INPUT_TRIGGER_INTERNAL_2:
      syn_set_register_bits(reg, mask, TIM_SMCR_TS_ITR2 << shift);
      break;

    case TIM_INPUT_TRIGGER_INTERNAL_3:
      syn_set_register_bits(reg, mask, TIM_SMCR_TS_ITR3 << shift);
      break;

    case TIM_INPUT_TRIGGER_TI1_EDGE:
      syn_set_register_bits(reg, mask, TIM_SMCR_TS_TI1FED << shift);
      break;

    case TIM_INPUT_TRIGGER_FILTERED_INPUT_1:
      syn_set_register_bits(reg, mask, TIM_SMCR_TS_TI1FP1 << shift);
      break;

    case TIM_INPUT_TRIGGER_FILTERED_INPUT_2:
      syn_set_register_bits(reg, mask, TIM_SMCR_TS_TI2FP2 << shift);
      break;

    case TIM_INPUT_TRIGGER_EXTERNAL_TRIGGER:
      *reg |= (TIM_SMCR_TS_ETRF << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_input_trigger, trigger);
      break;
  }
}

void
tim_master_slave_sync_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->SMCR |= TIM_SMCR_MSM;
}

void
tim_master_slave_sync_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->SMCR &= ~TIM_SMCR_MSM;
}

void
tim_set_external_trigger_filter(
  volatile struct tim_registers_map* tim,
  enum tim_external_trigger_filter filter
)
{
  constexpr u32 shift = TIM_SMCR_ETF_SHIFT;
  constexpr u32 mask = TIM_SMCR_ETF_MASK << shift;
  volatile u32* reg = &tim->SMCR;

  switch (filter)
  {
    case TIM_EXTERNAL_TRIGGER_FILTER_DISABLED:
      *reg &= ~mask;
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N2:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_NODIV_N2 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N4:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_NODIV_N4 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N8:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_NODIV_N8 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N6:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV2_N6 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N8:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV2_N8 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N6:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV4_N6 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N8:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV4_N8 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N6:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV8_N6 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N8:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV8_N8 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N5:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV16_N5 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N6:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV16_N6 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N8:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV16_N8 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N5:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV32_N5 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N6:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETF_DIV32_N6 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N8:
      *reg |= (TIM_SMCR_ETF_DIV32_N8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_external_trigger_filter, filter);
      break;
  }
}

void
tim_set_external_trigger_prescaler(
  volatile struct tim_registers_map* tim,
  enum tim_external_trigger_prescaler prescaler
)
{
  constexpr u32 shift = TIM_SMCR_ETPS_SHIFT;
  constexpr u32 mask = TIM_SMCR_ETPS_MASK << shift;
  volatile u32* reg = &tim->SMCR;

  switch (prescaler)
  {
    case TIM_EXTERNAL_TRIGGER_PRESCALER_OFF:
      *reg &= ~mask;
      break;

    case TIM_EXTERNAL_TRIGGER_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETPS_ETRP_DIV2 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, TIM_SMCR_ETPS_ETRP_DIV4 << shift);
      break;

    case TIM_EXTERNAL_TRIGGER_PRESCALER_DIV8:
      *reg |= (TIM_SMCR_ETPS_ETRP_DIV8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_external_trigger_prescaler, prescaler);
      break;
  }
}

void
tim_external_clock_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->SMCR |= TIM_SMCR_ECE;
}

void
tim_external_clock_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->SMCR &= ~TIM_SMCR_ECE;
}

void
tim_set_external_trigger_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_external_trigger_polarity polarity
)
{
  switch (polarity)
  {
    case TIM_EXTERNAL_TRIGGER_POLARITY_NON_INVERTED:
      tim->SMCR &= ~TIM_SMCR_ETP;
      break;

    case TIM_EXTERNAL_TRIGGER_POLARITY_INVERTED:
      tim->SMCR |= TIM_SMCR_ETP;
      break;

    default:
      devmode_error_invalid_enum(enum tim_external_trigger_polarity, polarity);
      break;
  }
}

void
tim_interrupt_enable(
  volatile struct tim_registers_map* tim,
  enum tim_interrupt interrupt
)
{
  volatile u32* reg = &tim->DIER;

  switch (interrupt)
  {
    case TIM_INTERRUPT_UPDATE:
      *reg |= TIM_DIER_UIE;
      break;

    case TIM_INTERRUPT_CC1:
      *reg |= TIM_DIER_CC1IE;
      break;

    case TIM_INTERRUPT_CC2:
      *reg |= TIM_DIER_CC2IE;
      break;

    case TIM_INTERRUPT_CC3:
      *reg |= TIM_DIER_CC3IE;
      break;

    case TIM_INTERRUPT_CC4:
      *reg |= TIM_DIER_CC4IE;
      break;

    case TIM_INTERRUPT_COM:
      *reg |= TIM_DIER_COMIE;
      break;

    case TIM_INTERRUPT_TRIGGER:
      *reg |= TIM_DIER_TIE;
      break;

    case TIM_INTERRUPT_BREAK:
      *reg |= TIM_DIER_BIE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_interrupt, interrupt);
      break;
  }
}

void
tim_interrupt_disable(
  volatile struct tim_registers_map* tim,
  enum tim_interrupt interrupt
)
{
  volatile u32* reg = &tim->DIER;

  switch (interrupt)
  {
    case TIM_INTERRUPT_UPDATE:
      *reg &= ~TIM_DIER_UIE;
      break;

    case TIM_INTERRUPT_CC1:
      *reg &= ~TIM_DIER_CC1IE;
      break;

    case TIM_INTERRUPT_CC2:
      *reg &= ~TIM_DIER_CC2IE;
      break;

    case TIM_INTERRUPT_CC3:
      *reg &= ~TIM_DIER_CC3IE;
      break;

    case TIM_INTERRUPT_CC4:
      *reg &= ~TIM_DIER_CC4IE;
      break;

    case TIM_INTERRUPT_COM:
      *reg &= ~TIM_DIER_COMIE;
      break;

    case TIM_INTERRUPT_TRIGGER:
      *reg &= ~TIM_DIER_TIE;
      break;

    case TIM_INTERRUPT_BREAK:
      *reg &= ~TIM_DIER_BIE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_interrupt, interrupt);
      break;
  }
}

void
tim_dma_request_enable(
  volatile struct tim_registers_map* tim,
  enum tim_dma_request request
)
{
  volatile u32* reg = &tim->DIER;

  switch (request)
  {
    case TIM_DMA_MODE_UPDATE:
      *reg |= TIM_DIER_UDE;
      break;

    case TIM_DMA_MODE_CC1:
      *reg |= TIM_DIER_CC1DE;
      break;

    case TIM_DMA_MODE_CC2:
      *reg |= TIM_DIER_CC2DE;
      break;

    case TIM_DMA_MODE_CC3:
      *reg |= TIM_DIER_CC3DE;
      break;

    case TIM_DMA_MODE_CC4:
      *reg |= TIM_DIER_CC4DE;
      break;

    case TIM_DMA_MODE_COM:
      *reg |= TIM_DIER_COMDE;
      break;

    case TIM_DMA_MODE_TRIGGER:
      *reg |= TIM_DIER_TDE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_dma_request, request);
      break;
  }
}

void
tim_dma_request_disable(
  volatile struct tim_registers_map* tim,
  enum tim_dma_request request
)
{
  volatile u32* reg = &tim->DIER;

  switch (request)
  {
    case TIM_DMA_MODE_UPDATE:
      *reg &= ~TIM_DIER_UDE;
      break;

    case TIM_DMA_MODE_CC1:
      *reg &= ~TIM_DIER_CC1DE;
      break;

    case TIM_DMA_MODE_CC2:
      *reg &= ~TIM_DIER_CC2DE;
      break;

    case TIM_DMA_MODE_CC3:
      *reg &= ~TIM_DIER_CC3DE;
      break;

    case TIM_DMA_MODE_CC4:
      *reg &= ~TIM_DIER_CC4DE;
      break;

    case TIM_DMA_MODE_COM:
      *reg &= ~TIM_DIER_COMDE;
      break;

    case TIM_DMA_MODE_TRIGGER:
      *reg &= ~TIM_DIER_TDE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_dma_request, request);
      break;
  }
}

u32
tim_is_flag_set(
  volatile struct tim_registers_map* tim,
  enum tim_flag flag
)
{
  volatile u32* reg = &tim->SR;

  switch (flag)
  {
    case TIM_FLAG_UPDATE:
      return *reg & TIM_SR_UIF;
      
    case TIM_FLAG_CC1_INTERRUPT:
      return *reg & TIM_SR_CC1IF;

    case TIM_FLAG_CC2_INTERRUPT:
      return *reg & TIM_SR_CC2IF;

    case TIM_FLAG_CC3_INTERRUPT:
      return *reg & TIM_SR_CC3IF;

    case TIM_FLAG_CC4_INTERRUPT:
      return *reg & TIM_SR_CC4IF;

    case TIM_FLAG_COM:
      return *reg & TIM_SR_COMIF;

    case TIM_FLAG_TRIGGER:
      return *reg & TIM_SR_TIF;

    case TIM_FLAG_BREAK:
      return *reg & TIM_SR_BIF;

    case TIM_FLAG_CC1_OVERCAPTURE:
      return *reg & TIM_SR_CC1OF;

    case TIM_FLAG_CC2_OVERCAPTURE:
      return *reg & TIM_SR_CC2OF;

    case TIM_FLAG_CC3_OVERCAPTURE:
      return *reg & TIM_SR_CC3OF;

    case TIM_FLAG_CC4_OVERCAPTURE:
      return *reg & TIM_SR_CC4OF;

    default:
      devmode_error_invalid_enum(enum tim_flag, flag);
      return 0;
  }
}

void
tim_flag_clear(
  volatile struct tim_registers_map* tim,
  enum tim_flag flag
)
{
  volatile u32* reg = &tim->SR;

  switch (flag)
  {
    case TIM_FLAG_UPDATE:
      *reg &= ~TIM_SR_UIF;
      break;

    case TIM_FLAG_CC1_INTERRUPT:
      *reg &= ~TIM_SR_CC1IF;
      break;

    case TIM_FLAG_CC2_INTERRUPT:
      *reg &= ~TIM_SR_CC2IF;
      break;

    case TIM_FLAG_CC3_INTERRUPT:
      *reg &= ~TIM_SR_CC3IF;
      break;

    case TIM_FLAG_CC4_INTERRUPT:
      *reg &= ~TIM_SR_CC4IF;
      break;

    case TIM_FLAG_COM:
      *reg &= ~TIM_SR_COMIF;
      break;

    case TIM_FLAG_TRIGGER:
      *reg &= ~TIM_SR_TIF;
      break;

    case TIM_FLAG_BREAK:
      *reg &= ~TIM_SR_BIF;
      break;

    case TIM_FLAG_CC1_OVERCAPTURE:
      *reg &= ~TIM_SR_CC1OF;
      break;

    case TIM_FLAG_CC2_OVERCAPTURE:
      *reg &= ~TIM_SR_CC2OF;
      break;

    case TIM_FLAG_CC3_OVERCAPTURE:
      *reg &= ~TIM_SR_CC3OF;
      break;
      
    case TIM_FLAG_CC4_OVERCAPTURE:
      *reg &= ~TIM_SR_CC4OF;
      break;

    default:
      devmode_error_invalid_enum(enum tim_flag, flag);
      break;
  }
}

void
tim_trigger_event_generation(
  volatile struct tim_registers_map* tim,
  enum tim_event event
)
{
  volatile u32* reg = &tim->EGR;

  switch (event)
  {
    case TIM_EVENT_UPDATE:
      *reg |= TIM_EGR_UG;
      break;

    case TIM_EVENT_CC1:
      *reg |= TIM_EGR_CC1G;
      break;

    case TIM_EVENT_CC2:
      *reg |= TIM_EGR_CC2G;
      break;

    case TIM_EVENT_CC3:
      *reg |= TIM_EGR_CC3G;
      break;

    case TIM_EVENT_CC4:
      *reg |= TIM_EGR_CC4G;
      break;

    case TIM_EVENT_COM:
      *reg |= TIM_EGR_COMG;
      break;

    case TIM_EVENT_TRIGGER:
      *reg |= TIM_EGR_TG;
      break;

    case TIM_EVENT_BREAK:
      *reg |= TIM_EGR_BG;
      break;

    default:
      devmode_error_invalid_enum(enum tim_event, event);
      break;
  }
}

void
tim_set_channel_direction(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_channel_direction direction
)
{
  devmode_assert_lower_or_eq(direction, TIM_CHANNEL_DIRECTION_TRC);

  switch (channel)
  {
    case TIM_CHANNEL1:
    {
      constexpr u32 shift = TIM_CCMR1_CC1S_SHIFT;
      constexpr u32 mask = TIM_CCMR1_CCS_MASK << shift;
      const u32 value = convert_ccs_api_to_impl(channel, direction);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL2:
    {
      constexpr u32 shift = TIM_CCMR1_CC2S_SHIFT;
      constexpr u32 mask = TIM_CCMR1_CCS_MASK << shift;
      const u32 value = convert_ccs_api_to_impl(channel, direction);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL3:
    {
      constexpr u32 shift = TIM_CCMR2_CC3S_SHIFT;
      constexpr u32 mask = TIM_CCMR2_CCS_MASK << shift;
      const u32 value = convert_ccs_api_to_impl(channel, direction);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }

    case TIM_CHANNEL4:
    {
      constexpr u32 shift = TIM_CCMR2_CC4S_SHIFT;
      constexpr u32 mask = TIM_CCMR2_CCS_MASK << shift;
      const u32 value = convert_ccs_api_to_impl(channel, direction);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }
    
    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_set_channel_ic_prescaler(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_prescaler prescaler
)
{
  devmode_assert_lower_or_eq(prescaler, TIM_IC_PRESCALER_SKIP_8);

  switch (channel)
  {
    case TIM_CHANNEL1:
    {
      constexpr u32 shift = TIM_CCMR1_IC1PSC_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICPSC_MASK << shift;
      const u32 value = convert_psc_api_to_impl(prescaler);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL2:
    {
      constexpr u32 shift = TIM_CCMR1_IC2PSC_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICPSC_MASK << shift;
      const u32 value = convert_psc_api_to_impl(prescaler);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL3:
    {
      constexpr u32 shift = TIM_CCMR2_IC3PSC_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICPSC_MASK << shift;
      const u32 value = convert_psc_api_to_impl(prescaler);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }

    case TIM_CHANNEL4:
    {
      constexpr u32 shift = TIM_CCMR2_IC4PSC_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICPSC_MASK << shift;
      const u32 value = convert_psc_api_to_impl(prescaler);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_set_ic_filter(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_filter filter
)
{
  devmode_assert_lower_or_eq(filter, TIM_IC_FILTER_DIV32_N8);
  switch (channel)
  {
    case TIM_CHANNEL1:
    {
      constexpr u32 shift = TIM_CCMR1_IC1F_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICF_MASK << shift;
      const u32 value = convert_filter_api_to_impl(filter);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL2:
    {
      constexpr u32 shift = TIM_CCMR1_IC2F_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICF_MASK << shift;
      const u32 value = convert_filter_api_to_impl(filter);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL3:
    {
      constexpr u32 shift = TIM_CCMR2_IC3F_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICF_MASK << shift;
      const u32 value = convert_filter_api_to_impl(filter);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }

    case TIM_CHANNEL4:
    {
      constexpr u32 shift = TIM_CCMR2_IC4F_SHIFT;
      constexpr u32 mask = TIM_CCMR_ICF_MASK << shift;
      const u32 value = convert_filter_api_to_impl(filter);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_oc_fast_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCMR1 |= TIM_CCMR1_OC1FE;
      break;

    case TIM_CHANNEL2:
      tim->CCMR1 |= TIM_CCMR1_OC2FE;
      break;

    case TIM_CHANNEL3:
      tim->CCMR2 |= TIM_CCMR2_OC3FE;
      break;

    case TIM_CHANNEL4:
      tim->CCMR2 |= TIM_CCMR2_OC4FE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_oc_fast_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCMR1 &= ~TIM_CCMR1_OC1FE;
      break;

    case TIM_CHANNEL2:
      tim->CCMR1 &= ~TIM_CCMR1_OC2FE;
      break;

    case TIM_CHANNEL3:
      tim->CCMR2 &= ~TIM_CCMR2_OC3FE;
      break;

    case TIM_CHANNEL4:
      tim->CCMR2 &= ~TIM_CCMR2_OC4FE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_oc_preload_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCMR1 |= TIM_CCMR1_OC1PE;
      break;

    case TIM_CHANNEL2:
      tim->CCMR1 |= TIM_CCMR1_OC2PE;
      break;

    case TIM_CHANNEL3:
      tim->CCMR2 |= TIM_CCMR2_OC3PE;
      break;

    case TIM_CHANNEL4:
      tim->CCMR2 |= TIM_CCMR2_OC4PE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_oc_preload_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCMR1 &= ~TIM_CCMR1_OC1PE;
      break;

    case TIM_CHANNEL2:
      tim->CCMR1 &= ~TIM_CCMR1_OC2PE;
      break;

    case TIM_CHANNEL3:
      tim->CCMR2 &= ~TIM_CCMR2_OC3PE;
      break;

    case TIM_CHANNEL4:
      tim->CCMR2 &= ~TIM_CCMR2_OC4PE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_set_oc_mode(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_oc_mode mode
)
{
  devmode_assert_lower_or_eq(mode, TIM_OC_MODE_PWM2);
  switch (channel)
  {
    case TIM_CHANNEL1:
    {
      constexpr u32 shift = TIM_CCMR1_OC1M_SHIFT;
      constexpr u32 mask = TIM_CCMR1_OCM_MASK << shift;
      const u32 value = convert_oc_mode_api_to_impl(mode);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL2:
    {
      constexpr u32 shift = TIM_CCMR1_OC2M_SHIFT;
      constexpr u32 mask = TIM_CCMR1_OCM_MASK << shift;
      const u32 value = convert_oc_mode_api_to_impl(mode);
      syn_set_register_bits(&tim->CCMR1, mask, value << shift);
      break;
    }

    case TIM_CHANNEL3:
    {
      constexpr u32 shift = TIM_CCMR2_OC3M_SHIFT;
      constexpr u32 mask = TIM_CCMR2_OCM_MASK << shift;
      const u32 value = convert_oc_mode_api_to_impl(mode);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }

    case TIM_CHANNEL4:
    {
      constexpr u32 shift = TIM_CCMR2_OC4M_SHIFT;
      constexpr u32 mask = TIM_CCMR2_OCM_MASK << shift;
      const u32 value = convert_oc_mode_api_to_impl(mode);
      syn_set_register_bits(&tim->CCMR2, mask, value << shift);
      break;
    }

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_oc_clear_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCMR1 |= TIM_CCMR1_OC1CE;
      break;

    case TIM_CHANNEL2:
      tim->CCMR1 |= TIM_CCMR1_OC2CE;
      break;

    case TIM_CHANNEL3:
      tim->CCMR2 |= TIM_CCMR2_OC3CE;
      break;

    case TIM_CHANNEL4:
      tim->CCMR2 |= TIM_CCMR2_OC4CE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_oc_clear_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCMR1 &= ~TIM_CCMR1_OC1CE;
      break;

    case TIM_CHANNEL2:
      tim->CCMR1 &= ~TIM_CCMR1_OC2CE;
      break;

    case TIM_CHANNEL3:
      tim->CCMR2 &= ~TIM_CCMR2_OC3CE;
      break;

    case TIM_CHANNEL4:
      tim->CCMR2 &= ~TIM_CCMR2_OC4CE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_cc_channel_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCER |= TIM_CCER_CC1E;
      break;

    case TIM_CHANNEL2:
      tim->CCER |= TIM_CCER_CC2E;
      break;

    case TIM_CHANNEL3:
      tim->CCER |= TIM_CCER_CC3E;
      break;

    case TIM_CHANNEL4:
      tim->CCER |= TIM_CCER_CC4E;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_cc_channel_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCER &= ~TIM_CCER_CC1E;
      break;

    case TIM_CHANNEL2:
      tim->CCER &= ~TIM_CCER_CC2E;
      break;

    case TIM_CHANNEL3:
      tim->CCER &= ~TIM_CCER_CC3E;
      break;

    case TIM_CHANNEL4:
      tim->CCER &= ~TIM_CCER_CC4E;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

static inline void
set_channel_ic_polarity(
  volatile u32* reg,
  u32 mask,
  u32 shift,
  enum tim_ic_polarity polarity
)
{
  mask <<= shift;

  switch (polarity)
  {
    case TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE:
      syn_set_register_bits(reg, mask, TIM_CCER_CCP_NONINV_RISING_EDGE << shift);
      break;

    case TIM_IC_POLARITY_INVERTED_FALLING_EDGE:
      syn_set_register_bits(reg, mask, TIM_CCER_CCP_INV_FALLING_EDGE << shift);
      break;

    case TIM_IC_POLARITY_NON_INVERTED_BOTH:
      syn_set_register_bits(reg, mask, TIM_CCER_CCP_NONINV_BOTH_EDGES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_ic_polarity, polarity);
      break;
  }
}

void
tim_set_ic_channel_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_polarity polarity
)
{
  constexpr u32 mask = TIM_CCER_CCP_MASK;
  volatile u32* reg = &tim->CCER;

  switch (channel)
  {
    case TIM_CHANNEL1:
      set_channel_ic_polarity(reg, mask, TIM_CCER_CC1P_SHIFT, polarity);
      break;

    case TIM_CHANNEL2:
      set_channel_ic_polarity(reg, mask, TIM_CCER_CC2P_SHIFT, polarity);
      break;

    case TIM_CHANNEL3:
      set_channel_ic_polarity(reg, mask, TIM_CCER_CC3P_SHIFT, polarity);
      break;

    case TIM_CHANNEL4:
      set_channel_ic_polarity(reg, mask, TIM_CCER_CC4P_SHIFT, polarity);
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

static void
set_channel_oc_polarity(
  volatile u32* reg,
  u32 bit,
  enum tim_oc_polarity polarity
)
{
  switch (polarity)
  {
    case TIM_OC_POLARITY_ACTIVE_HIGH:
      *reg &= ~bit;
      break;

    case TIM_OC_POLARITY_ACTIVE_LOW:
      *reg |= bit;
      break;

    default:
      devmode_error_invalid_enum(enum tim_oc_polarity, polarity);
      break;
  }
}

void
tim_set_oc_channel_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_oc_polarity polarity
)
{
  volatile u32* reg = &tim->CCER;
  switch (channel)
  {
    case TIM_CHANNEL1:
      set_channel_oc_polarity(reg, TIM_CCER_CC1P, polarity);
      break;

    case TIM_CHANNEL2:
      set_channel_oc_polarity(reg, TIM_CCER_CC2P, polarity);
      break;

    case TIM_CHANNEL3:
      set_channel_oc_polarity(reg, TIM_CCER_CC3P, polarity);
      break;

    case TIM_CHANNEL4:
      set_channel_oc_polarity(reg, TIM_CCER_CC4P, polarity);
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;

  }
}

void
tim_cc_channel_complementary_output_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCER |= TIM_CCER_CC1NE;
      break;

    case TIM_CHANNEL2:
      tim->CCER |= TIM_CCER_CC2NE;
      break;

    case TIM_CHANNEL3:
      tim->CCER |= TIM_CCER_CC3NE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_cc_channel_complementary_output_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCER &= ~TIM_CCER_CC1NE;
      break;

    case TIM_CHANNEL2:
      tim->CCER &= ~TIM_CCER_CC2NE;
      break;

    case TIM_CHANNEL3:
      tim->CCER &= ~TIM_CCER_CC3NE;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

static void
set_complementary_oc_output_polarity(
  volatile u32* reg,
  u32 bit,
  enum tim_oc_polarity polarity
)
{
  switch (polarity)
  {
    case TIM_OC_POLARITY_ACTIVE_HIGH:
      *reg &= bit;
      break;

    case TIM_OC_POLARITY_ACTIVE_LOW:
      *reg |= bit;
      break;

    default:
      devmode_error_invalid_enum(enum tim_cc_polarity, polarity);
      break;
  }
}

void
tim_cc_channel_complementary_oc_output_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_oc_polarity polarity
)
{
  volatile u32* reg = &tim->CCER;
  switch (channel)
  {
    case TIM_CHANNEL1:
      set_complementary_oc_output_polarity(reg, TIM_CCER_CC1NP, polarity);
      break;

    case TIM_CHANNEL2:
      set_complementary_oc_output_polarity(reg, TIM_CCER_CC2NP, polarity);
      break;

    case TIM_CHANNEL3:
      set_complementary_oc_output_polarity(reg, TIM_CCER_CC3NP, polarity);
      break;

#if defined(STM32_TIM_CC4NP)
    case TIM_CHANNEL4:
      set_complementary_oc_output_polarity(reg, TIM_CCER_CC4NP, polarity);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
set_complementary_ic_output_polarity(
  volatile u32* reg,
  u32 shift,
  enum tim_ic_polarity polarity
)
{
  constexpr u32 mask = TIM_CCER_CCNP_MASK;
  switch (polarity)
  {
    case TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE:
      syn_set_register_bits(reg, mask, TIM_CCER_CCP_NONINV_RISING_EDGE << shift);
      break;

    case TIM_IC_POLARITY_INVERTED_FALLING_EDGE:
      syn_set_register_bits(reg, mask, TIM_CCER_CCP_INV_FALLING_EDGE << shift);
      break;

    case TIM_IC_POLARITY_NON_INVERTED_BOTH:
      syn_set_register_bits(reg, mask, TIM_CCER_CCP_NONINV_BOTH_EDGES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_ic_polarity, polarity);
      break;
  }
}

void
tim_cc_channel_complementary_ic_output_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_polarity polarity
)
{
  volatile u32* reg = &tim->CCER;
  switch (channel)
  {
    case TIM_CHANNEL1:
      set_complementary_ic_output_polarity(reg, TIM_CCER_CC1NP_SHIFT, polarity);
      break;

    case TIM_CHANNEL2:
      set_complementary_ic_output_polarity(reg, TIM_CCER_CC2NP_SHIFT, polarity);
      break;

    case TIM_CHANNEL3:
      set_complementary_ic_output_polarity(reg, TIM_CCER_CC3NP_SHIFT, polarity);
      break;

#if defined(STM32_TIM_CC4NP)
    case TIM_CHANNEL4:
      set_complementary_ic_output_polarity(reg, TIM_CCER_CC4NP, polarity);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

void
tim_set_counter_value(
  volatile struct tim_registers_map* tim,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, TIM_CNT_MASK);
  tim->CNT = value;
}

u32
tim_get_counter_value(
  volatile struct tim_registers_map* tim
)
{
  return tim->CNT;
}

void
tim_set_prescaler(
  volatile struct tim_registers_map* tim,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, TIM_PSC_MASK);
  tim->PSC = value;
}

u32
tim_get_prescaler(
  volatile struct tim_registers_map* tim
)
{
  return tim->PSC;
}

void
tim_set_autoreload_value(
  volatile struct tim_registers_map* tim,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, TIM_ARR_MASK);
  tim->ARR = value;
}

u32
tim_get_autoreload_value(
  volatile struct tim_registers_map* tim
)
{
  return tim->ARR;
}

void
tim_set_repetition_counter(
  volatile struct tim_registers_map* tim,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, TIM_RCR_MASK);
  tim->RCR = value;
}

u32
tim_get_repetition_counter(
  volatile struct tim_registers_map* tim
)
{
  return tim->RCR;
}

void
tim_set_cc_value(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, TIM_CCR_MASK);
  switch (channel)
  {
    case TIM_CHANNEL1:
      tim->CCR1 = value;
      break;

    case TIM_CHANNEL2:
      tim->CCR2 = value;
      break;

    case TIM_CHANNEL3:
      tim->CCR3 = value;
      break;

    case TIM_CHANNEL4:
      tim->CCR4 = value;
      break;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      break;
  }
}

u32
tim_get_cc_value(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
)
{
  switch (channel)
  {
    case TIM_CHANNEL1:
      return tim->CCR1;

    case TIM_CHANNEL2:
      return tim->CCR2;

    case TIM_CHANNEL3:
      return tim->CCR3;

    case TIM_CHANNEL4:
      return tim->CCR4;

    default:
      devmode_error_invalid_enum(enum tim_channel, channel);
      return 0;
  }
}

void
tim_set_deadtime_generator(
  volatile struct tim_registers_map* tim,
  enum tim_deadtime_formula prescaler,
  u32 ticks
)
{
  constexpr u32 shift = TIM_BDTR_DTG_SHIFT;
  constexpr u32 formula_shift = TIM_BDTR_DTG_FORMULA_SHIFT;
  constexpr u32 mask = TIM_BDTR_DTG_MASK << shift;
  volatile u32* reg = &tim->BDTR;
  u32 prescaler_val;

  switch (prescaler)
  {
    case TIM_DEADTIME_FORMULA1:
      devmode_assert_lower_or_eq(ticks, TIM_BDTR_DTG_FORMULA1_VALUE_MASK);
      prescaler_val = TIM_BDTR_DTG_FORMULA1 << formula_shift;
      syn_set_register_bits(reg, mask, prescaler_val | (ticks << shift));
      break;

    case TIM_DEADTIME_FORMULA2:
      devmode_assert_lower_or_eq(ticks, TIM_BDTR_DTG_FORMULA2_VALUE_MASK);
      prescaler_val = TIM_BDTR_DTG_FORMULA2 << formula_shift;
      syn_set_register_bits(reg, mask, prescaler_val | (ticks << shift));
      break;

    case TIM_DEADTIME_FORMULA3:
      devmode_assert_lower_or_eq(ticks, TIM_BDTR_DTG_FORMULA3_VALUE_MASK);
      prescaler_val = TIM_BDTR_DTG_FORMULA3 << formula_shift;
      syn_set_register_bits(reg, mask, prescaler_val | (ticks << shift));
      break;

    case TIM_DEADTIME_FORMULA4:
      devmode_assert_lower_or_eq(ticks, TIM_BDTR_DTG_FORMULA4_VALUE_MASK);
      prescaler_val = TIM_BDTR_DTG_FORMULA4 << formula_shift;
      syn_set_register_bits(reg, mask, prescaler_val | (ticks << shift));
      break;

    default:
      devmode_error_invalid_enum(enum tim_dead_time_prescaler, prescaler);
      break;
  }
}

void
tim_set_dead_time_generator_value(
  volatile struct tim_registers_map* tim,
  u32 value
)
{
  devmode_assert_lower_or_eq(value, TIM_BDTR_DTG_MASK);
  constexpr u32 shift = TIM_BDTR_DTG_SHIFT;
  constexpr u32 mask = TIM_BDTR_DTG_MASK << shift;
  volatile u32* reg = &tim->BDTR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
tim_set_lock_configuration(
  volatile struct tim_registers_map* tim,
  enum tim_lock_configuration config
)
{
  constexpr u32 shift = TIM_BDTR_LOCK_SHIFT;
  constexpr u32 mask = TIM_BDTR_LOCK_MASK << shift;
  volatile u32* reg = &tim->BDTR;

  switch (config)
  {
    case TIM_LOCK_CONFIGURATION_OFF:
      syn_set_register_bits(reg, mask, TIM_BDTR_LOCK_OFF << shift);
      break;

    case TIM_LOCK_CONFIGURATION_LVL1:
      syn_set_register_bits(reg, mask, TIM_BDTR_LOCK_LEVEL1 << shift);
      break;

    case TIM_LOCK_CONFIGURATION_LVL2:
      syn_set_register_bits(reg, mask, TIM_BDTR_LOCK_LEVEL2 << shift);
      break;

    case TIM_LOCK_CONFIGURATION_LVL3:
      syn_set_register_bits(reg, mask, TIM_BDTR_LOCK_LEVEL3 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_lock_configuration, config);
      break;
  }
}

void
tim_set_idle_mode_off_state(
  volatile struct tim_registers_map* tim,
  enum tim_idle_mode_off_state state
)
{
  volatile u32* reg = &tim->BDTR;

  switch (state)
  {
    case TIM_IDLE_MODE_OFF_STATE_OFF:
      *reg &= ~TIM_BDTR_OSSI;
      break;

    case TIM_IDLE_MODE_OFF_STATE_FORCED:
      *reg |= TIM_BDTR_OSSI;
      break;

    default:
      devmode_error_invalid_enum(enum tim_idle_mode_off_state, state);
      break;
  }
}

void
tim_set_run_mode_off_state(
  volatile struct tim_registers_map* tim,
  enum tim_run_mode_off_state state
)
{
  volatile u32* reg = &tim->BDTR;

  switch (state)
  {
    case TIM_RUN_MODE_OFF_STATE_OFF:
      *reg &= ~TIM_BDTR_OSSR;
      break;

    case TIM_RUN_MODE_OFF_STATE_FORCED:
      *reg |= TIM_BDTR_OSSR;
      break;

    default:
      devmode_error_invalid_enum(enum tim_run_mode_off_state, state);
      break;
  }
}

void
tim_break_input_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->BDTR |= TIM_BDTR_BKE;
}

void
tim_break_input_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->BDTR &= ~TIM_BDTR_BKE;
}

void
tim_set_break_pin_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_break_pin_polarity polarity
)
{
  volatile u32* reg = &tim->BDTR;

  switch (polarity)
  {
    case TIM_BREAK_PIN_POLARITY_OFF:
      *reg &= ~TIM_BDTR_BKP;
      break;

    case TIM_BREAK_PIN_POLARITY_ON:
      *reg |= TIM_BDTR_BKP;
      break;

    default:
      devmode_error_invalid_enum(enum tim_break_pin_polarity, polarity);
      break;
  }
}

void
tim_automatic_output_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->BDTR |= TIM_BDTR_AOE;
}

void
tim_automatic_output_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->BDTR &= ~TIM_BDTR_AOE;
}

void
tim_main_output_enable(
  volatile struct tim_registers_map* tim
)
{
  tim->BDTR |= TIM_BDTR_MOE;
}

void
tim_main_output_disable(
  volatile struct tim_registers_map* tim
)
{
  tim->BDTR &= ~TIM_BDTR_MOE;
}

void
tim_set_dma_base_address(
  volatile struct tim_registers_map* tim,
  enum tim_register treg
)
{
  constexpr u32 shift = TIM_DCR_DBA_SHIFT;
  constexpr u32 mask = TIM_DCR_DBA_MASK << shift;
  volatile u32* reg = &tim->DCR;

  switch (treg)
  {
    case TIM_REGISTER_CR1:
      *reg &= ~mask;
      break;

    case TIM_REGISTER_CR2:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CR2 << shift);
      break;

    case TIM_REGISTER_SMCR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_SMCR << shift);
      break;

    case TIM_REGISTER_DIER:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_DIER << shift);
      break;

    case TIM_REGISTER_SR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_SR << shift);
      break;

    case TIM_REGISTER_EGR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_EGR << shift);
      break;

    case TIM_REGISTER_CCMR1:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CCMR1 << shift);
      break;

    case TIM_REGISTER_CCMR2:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CCMR2 << shift);
      break;

    case TIM_REGISTER_CCER:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CCER << shift);
      break;

    case TIM_REGISTER_CNT:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CNT << shift);
      break;

    case TIM_REGISTER_PSC:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_PSC << shift);
      break;

    case TIM_REGISTER_ARR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_ARR << shift);
      break;

    case TIM_REGISTER_RCR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_RCR << shift);
      break;

    case TIM_REGISTER_CCR1:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CCR1 << shift);
      break;

    case TIM_REGISTER_CCR2:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CCR2 << shift);
      break;

    case TIM_REGISTER_CCR3:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CCR3 << shift);
      break;

    case TIM_REGISTER_CCR4:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_CCR4 << shift);
      break;

    case TIM_REGISTER_BDTR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_BDTR << shift);
      break;

    case TIM_REGISTER_DCR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_DCR << shift);
      break;

    case TIM_REGISTER_DMAR:
      syn_set_register_bits(reg, mask, TIM_DCR_DBA_DMAR << shift);
      break;

    default:
      devmode_error_invalid_enum(enum tim_register, treg);
      break;
  }
}

void
tim_set_dma_burst_length(
  volatile struct tim_registers_map* tim,
  u32 length
)
{
  devmode_assert_lower_or_eq(length, TIM_DCR_DBL_MASK);
  constexpr u32 shift = TIM_DCR_DBL_SHIFT;
  constexpr u32 mask = TIM_DCR_DBL_MASK << shift;
  volatile u32* reg = &tim->DCR;
  syn_set_register_bits(reg, mask, length << shift);
}

void
tim_dma_burst_access_reg_write(
  volatile struct tim_registers_map* tim,
  u32 val
)
{
  devmode_assert_lower_or_eq(val, TIM_DMAR_MASK);
  tim->DMAR = val;
}

u32
tma_dma_burst_access_reg_read(
  volatile struct tim_registers_map* tim
)
{
  return tim->DMAR;
}
