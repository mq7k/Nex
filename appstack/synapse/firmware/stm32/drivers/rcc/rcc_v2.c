#include "synapse/stm32/drivers/rcc/rcc_v2.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct rcc_registers_map rcc_periph;
rcc_periph* RCC = (rcc_periph*) (RCC_ADDR);

void
rcc_osc_enable(
  enum rcc_osc osc
)
{
  switch (osc)
  {
    case RCC_OSC_HSI:
      RCC->CR |= RCC_CR_HSION;
      break;

    case RCC_OSC_HSE:
      RCC->CR |= RCC_CR_HSEON;
      break;

    case RCC_OSC_PLL:
      RCC->CR |= RCC_CR_PLLON;
      break;

#if defined(STM32_RCC_OSC_PLLI2S)
    case RCC_OSC_PLLI2S:
      RCC->CR |= RCC_CR_PLLI2SON;
      break;
#endif

#if defined(STM32_RCC_OSC_PLLSAI)
    case RCC_OSC_PLLSAI:
      RCC->CR |= RCC_CR_PLLSAION;
      break;
#endif

    case RCC_OSC_LSI:
      RCC->CSR |= RCC_CSR_LSION;
      break;

    case RCC_OSC_LSE:
      RCC->BDCR |= RCC_BDCR_LSEON;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_osc, osc);
      break;
  }
}

void
rcc_osc_disable(
  enum rcc_osc osc
)
{
  switch (osc)
  {
    case RCC_OSC_HSI:
      RCC->CR &= ~RCC_CR_HSION;
      break;

    case RCC_OSC_HSE:
      RCC->CR &= ~RCC_CR_HSEON;
      break;

    case RCC_OSC_PLL:
      RCC->CR &= ~RCC_CR_PLLON;
      break;

#if defined(STM32_RCC_OSC_PLLI2S)
    case RCC_OSC_PLLI2S:
      RCC->CR &= ~RCC_CR_PLLI2SON;
      break;
#endif

#if defined(STM32_RCC_OSC_PLLSAI)
    case RCC_OSC_PLLSAI:
      RCC->CR &= ~RCC_CR_PLLSAION;
      break;
#endif

    case RCC_OSC_LSI:
      RCC->CSR &= ~RCC_CSR_LSION;
      break;

    case RCC_OSC_LSE:
      RCC->BDCR &= ~RCC_BDCR_LSEON;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_osc, osc);
      break;
  }
}

u32
rcc_is_osc_ready(
  enum rcc_osc osc
)
{
  switch (osc)
  {
    case RCC_OSC_HSI:
      return RCC->CR & RCC_CR_HSIRDY;

    case RCC_OSC_HSE:
      return RCC->CR & RCC_CR_HSERDY;

    case RCC_OSC_PLL:
      return RCC->CR & RCC_CR_PLLRDY;

#if defined(STM32_RCC_OSC_PLLI2S)
    case RCC_OSC_PLLI2S:
      return RCC->CR & RCC_CR_PLLI2SRDY;
#endif

#if defined(STM32_RCC_OSC_PLLSAI)
    case RCC_OSC_PLLSAI:
      return RCC->CR & RCC_CR_PLLSAIRDY;
#endif

    case RCC_OSC_LSI:
      return RCC->CSR & RCC_CSR_LSIRDY;

    case RCC_OSC_LSE:
      return RCC->BDCR & RCC_BDCR_LSERDY;

    default:
      devmode_error_invalid_enum(enum rcc_osc, osc);
      return 0;
  }
}

void
rcc_set_hsi_trim(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, RCC_CR_HSITRIM_MASK);
  constexpr u32 shift = RCC_CR_HSITRIM_SHIFT;
  constexpr u32 mask = RCC_CR_HSITRIM_MASK << shift;
  volatile u32* reg = &RCC->CR;
  syn_set_register_bits(reg, mask, value << shift);
}

u32
rcc_get_hsi_cal(void)
{
  constexpr u32 shift = RCC_CR_HSICAL_SHIFT;
  constexpr u32 mask = RCC_CR_HSICAL_MASK;
  return (RCC->CR >> shift) & mask;
}

void
rcc_hse_bypass_enable(void)
{
  RCC->CR |= RCC_CR_HSEBYP;
}

void
rcc_hse_bypass_disable(void)
{
  RCC->CR &= ~RCC_CR_HSEBYP;
}

void
rcc_css_enable(void)
{
  RCC->CR |= RCC_CR_CSSON;
}

void
rcc_css_disable(void)
{
  RCC->CR &= ~RCC_CR_CSSON;
}

void
rcc_set_main_pll_factorM(
  u32 value
)
{
  devmode_assert_in_range(
    value,
    RCC_PLLCFGR_PLLM_MIN_VAL,
    RCC_PLLCFGR_PLLM_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLCFGR_PLLM_SHIFT;
  constexpr u32 mask = RCC_PLLCFGR_PLLM_MASK << shift;
  volatile u32* reg = &RCC->PLLCFGR;
  syn_set_register_bits(reg, mask, value << shift);
}

void
rcc_set_main_pll_factorN(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLCFGR_PLLN_MIN_VAL,
    RCC_PLLCFGR_PLLN_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLCFGR_PLLN_SHIFT;
  constexpr u32 mask = RCC_PLLCFGR_PLLN_MASK << shift;
  volatile u32* reg = &RCC->PLLCFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}

void
rcc_set_main_pll_factorP(
  enum rcc_main_pll_factorp factor
)
{
  constexpr u32 shift = RCC_PLLCFGR_PLLP_SHIFT;
  constexpr u32 mask = RCC_PLLCFGR_PLLP_MASK << shift;
  volatile u32* reg = &RCC->PLLCFGR;

  switch (factor)
  {
    case RCC_MAIN_PLL_FACTORP_DIV2:
      *reg &= ~mask;
      break;

    case RCC_MAIN_PLL_FACTORP_DIV4:
      syn_set_register_bits(reg, mask, RCC_PLLCFGR_PLLP_DIV4 << shift);
      break;

    case RCC_MAIN_PLL_FACTORP_DIV6:
      syn_set_register_bits(reg, mask, RCC_PLLCFGR_PLLP_DIV6 << shift);
      break;

    case RCC_MAIN_PLL_FACTORP_DIV8:
      *reg |= (RCC_PLLCFGR_PLLP_DIV8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_main_pll_factorp, factor);
      break;
  }
}

void
rcc_set_main_pll_factorQ(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLCFGR_PLLQ_MIN_VAL,
    RCC_PLLCFGR_PLLQ_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLCFGR_PLLQ_SHIFT;
  constexpr u32 mask = RCC_PLLCFGR_PLLQ_MASK << shift;
  volatile u32* reg = &RCC->PLLCFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}

#if defined(STM32_RCC_PLLR)
void
rcc_set_main_pll_factorR(
  u32 factor
)
{
  devmode_assert_lower_or_eq(value, RCC_PLLCFGR_PLLR_MASK);
  constexpr u32 shift = RCC_PLLCFGR_PLLR_SHIFT;
  constexpr u32 mask = RCC_PLLCFGR_PLLR_MASK << shift;
  volatile u32* reg = &RCC->PLLCFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}
#endif

void
rcc_set_main_pll_source(
  enum rcc_main_pll_source source
)
{
  volatile u32* reg = &RCC->PLLCFGR;
  switch (source)
  {
    case RCC_MAIN_PLL_SOURCE_HSI:
      *reg &= ~RCC_PLLCFGR_PLLSRC;
      break;

    case RCC_MAIN_PLL_SOURCE_HSE:
      *reg |= RCC_PLLCFGR_PLLSRC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_main_pll_source, source);
      break;
  }
}

void
rcc_set_system_clock_source(
  enum rcc_system_clock_source source
)
{
  constexpr u32 shift = RCC_CFGR_SW_SHIFT;
  constexpr u32 mask = RCC_CFGR_SW_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (source)
  {
    case RCC_SYSTEM_CLOCK_SOURCE_HSI:
      *reg &= ~mask;
      break;

    case RCC_SYSTEM_CLOCK_SOURCE_HSE:
      syn_set_register_bits(reg, mask, RCC_CFGR_SW_HSE << shift);
      break;

#if defined(STM32_RCC_PLLR_SW)
    case RCC_SYSTEM_CLOCK_SOURCE_PLLP:
      syn_set_register_bits(reg, mask, RCC_CFGR_SW_PLLR << shift);
      break;

    case RCC_SYSTEM_CLOCK_SOURCE_PLLR:
      syn_set_register_bits(reg, mask, RCC_CFGR_SW_PLLR << shift);
      break;

#else
    case RCC_SYSTEM_CLOCK_SOURCE_PLL:
      syn_set_register_bits(reg, mask, RCC_CFGR_SW_PLL << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_system_clock_source, source);
      break;
  }
}

u32
rcc_get_system_clock_source(void)
{
  constexpr u32 shift = RCC_CFGR_SWS_SHIFT;
  constexpr u32 mask = RCC_CFGR_SWS_MASK;
  volatile u32* reg = &RCC->CFGR;
  return (*reg >> shift) & mask;
}

void
rcc_system_clock_source_ready_wait(
  enum rcc_system_clock_source source
)
{
  constexpr u32 shift = RCC_CFGR_SW_SHIFT;
  constexpr u32 mask = RCC_CFGR_SW_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (source)
  {
    case RCC_SYSTEM_CLOCK_SOURCE_HSI:
      while ((*reg & mask) != (RCC_CFGR_SWS_HSI << shift));
      break;

    case RCC_SYSTEM_CLOCK_SOURCE_HSE:
      while ((*reg & mask) != (RCC_CFGR_SWS_HSE << shift));
      break;

#if defined(STM32_RCC_PLLR_SW)
    case RCC_SYSTEM_CLOCK_SOURCE_PLLP:
      while ((*reg & mask) != (RCC_CFGR_SWS_PLLP << shift));
      break;

    case RCC_SYSTEM_CLOCK_SOURCE_PLLR:
      while ((*reg & mask) != (RCC_CFGR_SWS_PLLR << shift));
      break;

#else
    case RCC_SYSTEM_CLOCK_SOURCE_PLL:
      while ((*reg & mask) != (RCC_CFGR_SWS_PLL << shift));
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_system_clock_source, source);
      break;
  }
}

void
rcc_set_ahb_prescaler(
  enum rcc_ahb_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR_HPRE_SHIFT;
  constexpr u32 mask = RCC_CFGR_HPRE_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (prescaler)
  {
    case RCC_AHB_PRESCALER_NODIV:
      *reg &= ~mask;
      break;

    case RCC_AHB_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV2 << shift);
      break;

    case RCC_AHB_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV4 << shift);
      break;

    case RCC_AHB_PRESCALER_DIV8:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV8 << shift);
      break;

    case RCC_AHB_PRESCALER_DIV16:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV16 << shift);
      break;

    case RCC_AHB_PRESCALER_DIV64:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV64 << shift);
      break;

    case RCC_AHB_PRESCALER_DIV128:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV128 << shift);
      break;

    case RCC_AHB_PRESCALER_DIV256:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV256 << shift);
      break;

    case RCC_AHB_PRESCALER_DIV512:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV512 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_ahb_prescaler, prescaler);
      break;
  }
}

#if defined(STM32_RCC_MCOEN)
void
rcc_mco_enable(
  enum rcc_mco mco
)
{
  switch (mco)
  {
#if defined(STM32_RCC_MCO1EN)
    case RCC_MCO1:
      RCC->CFGR |= RCC_CFGR_MCO1EN;
      break;
#endif

#if defined(STM32_RCC_MCO2EN)
    case RCC_MCO2:
      RCC->CFGR |= RCC_CFGR_MCO2EN;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_mco, mco);
      break;
  }
}

void
rcc_mco_disable(
  enum rcc_mco mco
)
{
  switch (mco)
  {
#if defined(STM32_RCC_MCO2EN)
    case RCC_MCO1:
      RCC->CFGR &= ~RCC_CFGR_MCO1EN;
      break;
#endif

#if defined(STM32_RCC_MCO2EN)
    case RCC_MCO2:
      RCC->CFGR &= ~RCC_CFGR_MCO2EN;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_mco, mco);
      break;
  }
}
#endif

void
rcc_set_apb1_prescaler(
  enum rcc_apb1_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR_PPRE1_SHIFT;
  constexpr u32 mask = RCC_CFGR_PPRE1_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (prescaler)
  {
    case RCC_APB1_PRESCALER_NODIV:
      *reg &= ~mask;
      break;

    case RCC_APB1_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV2 << shift);
      break;

    case RCC_APB1_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV4 << shift);
      break;

    case RCC_APB1_PRESCALER_DIV8:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV8 << shift);
      break;

    case RCC_APB1_PRESCALER_DIV16:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV16 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_apb1_prescaler, prescaler);
      break;
  }
}

void
rcc_set_apb2_prescaler(
  enum rcc_apb2_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR_PPRE2_SHIFT;
  constexpr u32 mask = RCC_CFGR_PPRE2_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (prescaler)
  {
    case RCC_APB2_PRESCALER_NODIV:
      *reg &= ~mask;
      break;

    case RCC_APB2_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV2 << shift);
      break;

    case RCC_APB2_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV4 << shift);
      break;

    case RCC_APB2_PRESCALER_DIV8:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV8 << shift);
      break;

    case RCC_APB2_PRESCALER_DIV16:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV16 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_apb2_prescaler, prescaler);
      break;
  }
}

void
rcc_set_rtc_prescaler(
  u32 prescaler
)
{
  devmode_assert_lower_or_eq(prescaler, RCC_CFGR_RTCPRE_MASK);
  constexpr u32 shift = RCC_CFGR_RTCPRE_SHIFT;
  constexpr u32 mask = RCC_CFGR_RTCPRE_MASK << shift;
  volatile u32* reg = &RCC->CFGR;
  syn_set_register_bits(reg, mask, prescaler << shift);
}

void
rcc_set_mco1(
  enum rcc_mco1 output
)
{
  constexpr u32 shift = RCC_CFGR_MCO1_SHIFT;
  constexpr u32 mask = RCC_CFGR_MCO1_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (output)
  {
    case RCC_MCO1_HSI:
      *reg &= ~mask;
      break;

    case RCC_MCO1_LSE:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO1_LSE << shift);
      break;

    case RCC_MCO1_HSE:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO1_HSE << shift);
      break;

    case RCC_MCO1_PLL:
      *reg |= (RCC_CFGR_MCO1_PLL << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_mco1, output);
      break;
  }
}

#if defined(STM32_RCC_I2S)
void
rcc_set_i2s_clock_source(
  enum rcc_i2s_clock_source source
)
{
  volatile u32* reg = &RCC->CFGR;
  switch (source)
  {
    case RCC_I2S_CLOCK_SOURCE_PLLI2S:
      *reg &= ~RCC_CFGR_I2SSRC;
      break;

    case RCC_I2S_CLOCK_SOURCE_ALTIN:
      *reg |= RCC_CFGR_I2SSRC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_i2s_clock_source, source);
      break;
  }
}
#endif

void
rcc_set_mco1_prescaler(
  enum rcc_mco_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR_MCO1PRE_SHIFT;
  constexpr u32 mask = RCC_CFGR_MCO1PRE_MASK << shift;
  volatile u32* reg = &RCC->CFGR;
  
  switch (prescaler)
  {
    case RCC_MCO_PRESCALER_NODIV:
      *reg &= ~mask;
      break;

    case RCC_MCO_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO1PRE_DIV2 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV3:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO1PRE_DIV3 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO1PRE_DIV4 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV5:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO1PRE_DIV5 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_mco_prescaler, prescaler);
      break;
  }
}

void
rcc_set_mco2_prescaler(
  enum rcc_mco_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR_MCO2PRE_SHIFT;
  constexpr u32 mask = RCC_CFGR_MCO2PRE_MASK << shift;
  volatile u32* reg = &RCC->CFGR;
  
  switch (prescaler)
  {
    case RCC_MCO_PRESCALER_NODIV:
      *reg &= ~mask;
      break;

    case RCC_MCO_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO2PRE_DIV2 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV3:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO2PRE_DIV3 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO2PRE_DIV4 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV5:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO2PRE_DIV5 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_mco_prescaler, prescaler);
      break;
  }
}

void
rcc_set_mco2(
  enum rcc_mco2 output
)
{
  constexpr u32 shift = RCC_CFGR_MCO2_SHIFT;
  constexpr u32 mask = RCC_CFGR_MCO2_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (output)
  {
    case RCC_MCO2_SYSCLK:
      *reg &= ~mask;
      break;

    case RCC_MCO2_PLLI2S:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO2_PLLI2S << shift);
      break;

    case RCC_MCO2_HSE:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO2_HSE << shift);
      break;

    case RCC_MCO2_PLL:
      *reg |= (RCC_CFGR_MCO2_PLL << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_mco2, output);
      break;
  }
}

u32
rcc_is_flag_set(
  enum rcc_flag flag
)
{
  volatile u32* reg = &RCC->CIR;
  switch (flag)
  {
    case RCC_FLAG_LSI_READY:
      return *reg & RCC_CIR_LSIRDYF;

    case RCC_FLAG_LSE_READY:
      return *reg & RCC_CIR_LSERDYF;

    case RCC_FLAG_HSI_READY:
      return *reg & RCC_CIR_HSIRDYF;

    case RCC_FLAG_HSE_READY:
      return *reg & RCC_CIR_HSERDYF;

    case RCC_FLAG_PLL_READY:
      return *reg & RCC_CIR_PLLRDYF;

#if defined(STM32_RCC_PLLI2S)
    case RCC_FLAG_PLLI2S_READY:
      return *reg & RCC_CIR_PLLI2SRDYF;
#endif

#if defined(STM32_RCC_PLLSAI)
    case RCC_FLAG_PLLSAI_READY:
      return *reg & RCC_CIR_PLLSAIRDYF;
#endif

    case RCC_FLAG_CSS:
      return *reg & RCC_CIR_CSSF;

    default:
      devmode_error_invalid_enum(enum rcc_flag, flag);
      return 0;
  }
}

void
rcc_flag_clear(
  enum rcc_flag flag
)
{
  volatile u32* reg = &RCC->CIR;
  switch (flag)
  {
    case RCC_FLAG_LSI_READY:
      *reg |= RCC_CIR_LSIRDYC;
      break;

    case RCC_FLAG_LSE_READY:
      *reg |= RCC_CIR_LSERDYC;
      break;

    case RCC_FLAG_HSI_READY:
      *reg |= RCC_CIR_HSIRDYC;
      break;

    case RCC_FLAG_HSE_READY:
      *reg |= RCC_CIR_HSERDYC;
      break;

    case RCC_FLAG_PLL_READY:
      *reg |= RCC_CIR_PLLRDYC;
      break;

#if defined(STM32_RCC_PLLI2S)
    case RCC_FLAG_PLLI2S_READY:
      *reg |= RCC_CIR_PLLI2SRDYC;
      break;
#endif

#if defined(STM32_RCC_PLLSAI)
    case RCC_FLAG_PLLSAI_READY:
      *reg |= RCC_CIR_PLLSAIRDYC;
      break;
#endif

    case RCC_FLAG_CSS:
      *reg |= RCC_CIR_CSSC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_flag, flag);
      break;
  }
}

void
rcc_interrupt_enable(
  enum rcc_interrupt interrupt
)
{
  volatile u32* reg = &RCC->CIR;
  switch (interrupt)
  {
    case RCC_INTERRUPT_LSI_READY:
      *reg |= RCC_CIR_LSIRDYIE;
      break;

    case RCC_INTERRUPT_LSE_READY:
      *reg |= RCC_CIR_LSERDYIE;
      break;

    case RCC_INTERRUPT_HSI_READY:
      *reg |= RCC_CIR_HSIRDYIE;
      break;

    case RCC_INTERRUPT_HSE_READY:
      *reg |= RCC_CIR_HSERDYIE;
      break;

    case RCC_INTERRUPT_PLL_READY:
      *reg |= RCC_CIR_PLLRDYIE;
      break;

#if defined(STM32_RCC_PLLI2S)
    case RCC_INTERRUPT_PLLI2S_READY:
      *reg |= RCC_CIR_PLLI2SRDYIE;
      break;
#endif

#if defined(STM32_RCC_PLLSAI)
    case RCC_INTERRUPT_PLLSAI_READY:
      *reg |= RCC_CIR_PLLSAIRDYIE;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_interrupt, interrupt);
      break;
  }
}

void
rcc_interrupt_disable(
  enum rcc_interrupt interrupt
)
{
  volatile u32* reg = &RCC->CIR;
  switch (interrupt)
  {
    case RCC_INTERRUPT_LSI_READY:
      *reg &= ~RCC_CIR_LSIRDYIE;
      break;

    case RCC_INTERRUPT_LSE_READY:
      *reg &= ~RCC_CIR_LSERDYIE;
      break;

    case RCC_INTERRUPT_HSI_READY:
      *reg &= ~RCC_CIR_HSIRDYIE;
      break;

    case RCC_INTERRUPT_HSE_READY:
      *reg &= ~RCC_CIR_HSERDYIE;
      break;

    case RCC_INTERRUPT_PLL_READY:
      *reg &= ~RCC_CIR_PLLRDYIE;
      break;

#if defined(STM32_RCC_PLLI2S)
    case RCC_INTERRUPT_PLLI2S_READY:
      *reg &= ~RCC_CIR_PLLI2SRDYIE;
      break;
#endif

#if defined(STM32_RCC_PLLSAI)
    case RCC_INTERRUPT_PLLSAI_READY:
      *reg &= ~RCC_CIR_PLLSAIRDYIE;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_interrupt, interrupt);
      break;
  }
}

void
rcc_periph_reset(
  enum rcc_periph periph
)
{
  switch (periph)
  {
#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST;
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOBRST;
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST;
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST;
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST;
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOFRST;
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOGRST;
      break;
#endif

#if defined(STM32_GPIOH)
    case RCC_PERIPH_GPIOH:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOHRST;
      break;
#endif

#if defined(STM32_GPIOI)
    case RCC_PERIPH_GPIOI:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOIRST;
      break;
#endif

#if defined(STM32_GPIOJ)
    case RCC_PERIPH_GPIOJ:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOJRST;
      break;
#endif

#if defined(STM32_GPIOK)
    case RCC_PERIPH_GPIOK:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOKRST;
      break;
#endif

    case RCC_PERIPH_CRC:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_CRCRST;
      break;

    case RCC_PERIPH_DMA1:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA1RST;
      break;

    case RCC_PERIPH_DMA2:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2RST;
      break;

#if defined(STM32_DMA2D)
    case RCC_PERIPH_DMA2D:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2DRST;
      break;
#endif

#if defined(STM32_ETHERNET_MAC)
    case RCC_PERIPH_ETHMAC:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_ETHMACRST;
      break;
#endif

#if defined(STM32_USB_OTG_HS)
    case RCC_PERIPH_OTG_HS:
      RCC->AHB1RSTR |= RCC_AHB1RSTR_OTGHSRST;
      break;
#endif

#if defined(STM32_UART9)
  case RCC_PERIPH_UART9:
    RCC->APB2RSTR |= RCC_APB2RSTR_UART9RST;
    break;
#endif

#if defined(STM32_UART10)
  case RCC_PERIPH_UART10:
    RCC->APB2RSTR |= RCC_APB2RSTR_UART10RST;
    break;
#endif

#if defined(STM32_RNG)
    case RCC_PERIPH_RNG:
#if defined(STM32_RCC_RNG_AHB1)
      RCC->AHB1RSTR |= RCC_AHB1RSTR_RNGRST;
#elif defined(STM32_RCC_RNG_AHB2)
      RCC->AHB2RSTR |= RCC_AHB2RSTR_RNGRST;
#endif
      break;
#endif

#if defined(STM32_DCMI)
    case RCC_PERIPH_DCMI:
      RCC->AHB2RSTR |= RCC_AHB2RSTR_DCMIRST;
      break;
#endif

#if defined(STM32_CRYP)
    case RCC_PERIPH_CRYPTO:
      RCC->AHB2RSTR |= RCC_AHB2RSTR_CRYPRST;
      break;
#endif

#if defined(STM32_HASH)
    case RCC_PERIPH_HASH:
      RCC->AHB2RSTR |= RCC_AHB2RSTR_HASHRST;
      break;
#endif

#if defined(STM32_USB_OTG_FS)
    case RCC_PERIPH_OTG_FS:
      RCC->AHB2RSTR |= RCC_AHB2RSTR_OTGFSRST;
      break;
#endif

#if defined(STM32_FMC)
    case RCC_PERIPH_FMC:
      RCC->AHB3RSTR |= RCC_AHB3RSTR_FMCRST;
      break;
#endif

#if defined(STM32_FSMC)
    case RCC_PERIPH_FSMC:
      RCC->AHB3RSTR |= RCC_AHB3RSTR_FSMCRST;
      break;
#endif

#if defined(STM32_QUADSPI)
    case RCC_PERIPH_QUADSPI:
      RCC->AHB3RSTR |= RCC_AHB3RSTR_QSPIRST;
      break;
#endif

#if defined(STM32_TIM2)
    case RCC_PERIPH_TIM2:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM2RST;
      break;
#endif

#if defined(STM32_TIM3)
    case RCC_PERIPH_TIM3:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM3RST;
      break;
#endif

#if defined(STM32_TIM4)
    case RCC_PERIPH_TIM4:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM4RST;
      break;
#endif

#if defined(STM32_TIM5)
    case RCC_PERIPH_TIM5:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM5RST;
      break;
#endif

#if defined(STM32_TIM6)
    case RCC_PERIPH_TIM6:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST;
      break;
#endif

#if defined(STM32_TIM7)
    case RCC_PERIPH_TIM7:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM7RST;
      break;
#endif

#if defined(STM32_TIM12)
    case RCC_PERIPH_TIM12:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM12RST;
      break;
#endif

#if defined(STM32_TIM13)
    case RCC_PERIPH_TIM13:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM13RST;
      break;
#endif

#if defined(STM32_TIM14)
    case RCC_PERIPH_TIM14:
      RCC->APB1RSTR |= RCC_APB1RSTR_TIM14RST;
      break;
#endif

#if defined(STM32_LPTIM1)
    case RCC_PERIPH_LPTIMER1:
      RCC->APB1RSTR |= RCC_APB1RSTR_LPTIM1RST;
      break;
#endif

    case RCC_PERIPH_WWDG:
      RCC->APB1RSTR |= RCC_APB1RSTR_WWDGRST;
      break;

    case RCC_PERIPH_SPI2:
      RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST;
      break;

#if defined(STM32_SPI3)
    case RCC_PERIPH_SPI3:
      RCC->APB1RSTR |= RCC_APB1RSTR_SPI3RST;
      break;
#endif

#if defined(STM32_SPDIFRX)
    case RCC_PERIPH_SPDIFRX:
      RCC->APB1RSTR |= RCC_APB1RSTR_SPDIFRXRST;
      break;
#endif

    case RCC_PERIPH_USART2:
      RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
      break;

#if defined(STM32_USART3)
    case RCC_PERIPH_USART3:
      RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
      break;
#endif

#if defined(STM32_UART4)
    case RCC_PERIPH_UART4:
      RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST;
      break;

#endif

#if defined(STM32_UART5)
    case RCC_PERIPH_UART5:
      RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST;
      break;

#endif

    case RCC_PERIPH_I2C1:
      RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST;
      break;

    case RCC_PERIPH_I2C2:
      RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST;
      break;

#if defined(STM32_I2C3)
    case RCC_PERIPH_I2C3:
      RCC->APB1RSTR |= RCC_APB1RSTR_I2C3RST;
      break;
#endif

#if defined(STM32_FMPI2C1)
    case RCC_PERIPH_I2CFMP1:
      RCC->APB1RSTR |= RCC_APB1RSTR_FMPI2C1RST;
      break;
#endif

#if defined(STM32_CAN1)
    case RCC_PERIPH_CAN1:
      RCC->APB1RSTR |= RCC_APB1RSTR_CAN1RST;
      break;
#endif

#if defined(STM32_CAN2)
    case RCC_PERIPH_CAN2:
      RCC->APB1RSTR |= RCC_APB1RSTR_CAN2RST;
      break;
#endif

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1RSTR |= RCC_APB1RSTR_CECRST;
      break;
#elif defined(STM32_CAN3)
    case RCC_PERIPH_CAN3:
      RCC->APB1RSTR |= RCC_APB1RSTR_CAN3RST;
      break;
#endif

    case RCC_PERIPH_PWR:
      RCC->APB1RSTR |= RCC_APB1RSTR_PWRRST;
      break;

#if defined(STM32_DAC)
    case RCC_PERIPH_DAC:
      RCC->APB1RSTR |= RCC_APB1RSTR_DACRST;
      break;
#endif

#if defined(STM32_UART7)
    case RCC_PERIPH_UART7:
      RCC->APB1RSTR |= RCC_APB1RSTR_UART7RST;
      break;
#endif

#if defined(STM32_UART8)
    case RCC_PERIPH_UART8:
      RCC->APB1RSTR |= RCC_APB1RSTR_UART8RST;
      break;
#endif

  // Register: APB2RSTR
    case RCC_PERIPH_TIM1:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST;
      break;

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM8RST;
      break;
#endif

    case RCC_PERIPH_USART1:
      RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
      break;

    case RCC_PERIPH_USART6:
      RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST;
      break;

    case RCC_PERIPH_ADC1:

#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
#endif

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
#endif
      RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST;
      break;

#if defined(STM32_SDIO)
    case RCC_PERIPH_SDIO:
      RCC->APB2RSTR |= RCC_APB2RSTR_SDIORST;
      break;
#endif

    case RCC_PERIPH_SPI1:
      RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST;
      break;

#if defined(STM32_SPI4)
    case RCC_PERIPH_SPI4:
      RCC->APB2RSTR |= RCC_APB2RSTR_SPI4RST;
      break;
#endif

    case RCC_PERIPH_SYSCFG:
      RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST;
      break;

    case RCC_PERIPH_TIM9:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM9RST;
      break;

#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM10RST;
      break;
#endif

    case RCC_PERIPH_TIM11:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM11RST;
      break;

#if defined(STM32_SPI5)
    case RCC_PERIPH_SPI5:
      RCC->APB2RSTR |= RCC_APB2RSTR_SPI5RST;
      break;
#endif

#if defined(STM32_SPI6)
    case RCC_PERIPH_SPI6:
      RCC->APB2RSTR |= RCC_APB2RSTR_SPI6RST;
      break;
#endif

#if defined(STM32_SAI1)
    case RCC_PERIPH_SAI1:
      RCC->APB2RSTR |= RCC_APB2RSTR_SAI1RST;
      break;
#endif

#if defined(STM32_SAI2)
    case RCC_PERIPH_SAI2:
      RCC->APB2RSTR |= RCC_APB2RSTR_SAI2RST;
      break;
#endif

#if defined(STM32_DFSDM1)
    case RCC_PERIPH_DFSDM1:
      RCC->APB2RSTR |= RCC_APB2RSTR_DFSDM1RST;
      break;
#endif

#if defined(STM32_DFSDM2)
    case RCC_PERIPH_DFSDM2:
      RCC->APB2RSTR |= RCC_APB2RSTR_DFSDM2RST;
      break;
#endif

#if defined(STM32_LTDC)
    case RCC_PERIPH_LTDC:
      RCC->APB2RSTR |= RCC_APB2RSTR_LTDCRST;
      break;
#endif

#if defined(STM32_DSI)
    case RCC_PERIPH_DSI:
      RCC->APB2RSTR |= RCC_APB2RSTR_DSIRST;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_periph, periph);
      break;
  }
}

void
rcc_periph_clock_enable(
  enum rcc_periph periph
)
{
  switch (periph)
  {
  // Register: AHB1RSTR
#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
      break;
#endif

#if defined(STM32_GPIOH)
    case RCC_PERIPH_GPIOH:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
      break;
#endif

#if defined(STM32_GPIOI)
    case RCC_PERIPH_GPIOI:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;
      break;
#endif

#if defined(STM32_GPIOJ)
    case RCC_PERIPH_GPIOJ:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;
      break;
#endif

#if defined(STM32_GPIOK)
    case RCC_PERIPH_GPIOK:
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN;
      break;
#endif

    case RCC_PERIPH_CRC:
      RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN;
      break;

#if defined(STM32_BKPSRAM)
    case RCC_PERIPH_BKPSRAM:
      RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN;
      break;
#endif

#if defined(STM32_CCMRAM)
    case RCC_PERIPH_CCMDATARAM:
      RCC->AHB1ENR |= RCC_AHB1ENR_CCMDATARAMEN;
      break;
#endif

    case RCC_PERIPH_DMA1:
      RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
      break;
  
    case RCC_PERIPH_DMA2:
      RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
      break;

#if defined(STM32_DMA2D)
    case RCC_PERIPH_DMA2D:
      RCC->AHB1ENR |= RCC_AHB1ENR_DMA2DEN;
      break;
#endif

#if defined(STM32_ETHERNET_MAC)
    case RCC_PERIPH_ETHMAC:
      RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACEN;
      break;

    case RCC_PERIPH_ETHMACTX:
      RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACTXEN;
      break;

    case RCC_PERIPH_ETHMACRX:
      RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACRXEN;
      break;

    case RCC_PERIPH_ETHMACPTP:
      RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACPTPEN;
      break;
#endif

#if defined(STM32_USB_OTG_HS)
    case RCC_PERIPH_OTG_HS:
      RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSEN;
      break;
#endif

#if defined(STM32_USB_OTG_HSULPI)
    case RCC_PERIPH_OTG_HS_ULPI:
      RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSULPIEN;
      break;
#endif

#if defined(STM32_RNG)
    case RCC_PERIPH_RNG:
#if defined(STM32_RCC_RNG_AHB1)
      RCC->AHB1ENR |= RCC_AHB1ENR_RNGEN;
#elif defined(STM32_RCC_RNG_AHB2)
      RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;
#endif
      break;
#endif

  // Register: AHB2RSTR
#if defined(STM32_RCC_AHB2)
#if defined(STM32_DCMI)
    case RCC_PERIPH_DCMI:
      RCC->AHB2ENR |= RCC_AHB2ENR_DCMIEN;
      break;
#endif

#if defined(STM32_CRYP)
    case RCC_PERIPH_CRYPTO:
      RCC->AHB2ENR |= RCC_AHB2ENR_CRYPEN;
      break;
#endif

#if defined(STM32_HASH)
    case RCC_PERIPH_HASH:
      RCC->AHB2ENR |= RCC_AHB2ENR_HASHEN;
      break;
#endif

    case RCC_PERIPH_OTG_FS:
      RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN;
      break;
#endif

  // Register: AHB3RSTR
#if defined(STM32_RCC_AHB3)
#if defined(STM32_FMC)
    case RCC_PERIPH_FMC:
      RCC->AHB3ENR |= RCC_AHB3ENR_FMCEN;
      break;
#endif

#if defined(STM32_FSMC)
    case RCC_PERIPH_FSMC:
      RCC->AHB3ENR |= RCC_AHB3ENR_FSMCEN;
      break;
#endif

#if defined(STM32_QUADSPI)
    case RCC_PERIPH_QUADSPI:
      RCC->AHB3ENR |= RCC_AHB3ENR_QSPIEN;
      break;
#endif
#endif

  // Register: APB1RSTR

#if defined(STM32_TIM2)
    case RCC_PERIPH_TIM2:
      RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
      break;
#endif

#if defined(STM32_TIM3)
    case RCC_PERIPH_TIM3:
      RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
      break;
#endif

#if defined(STM32_TIM4)
    case RCC_PERIPH_TIM4:
      RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
      break;
#endif

#if defined(STM32_TIM5)
    case RCC_PERIPH_TIM5:
      RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
      break;
#endif

#if defined(STM32_TIM6)
    case RCC_PERIPH_TIM6:
      RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
      break;
#endif

#if defined(STM32_TIM7)
    case RCC_PERIPH_TIM7:
      RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
      break;
#endif

#if defined(STM32_TIM12)
    case RCC_PERIPH_TIM12:
      RCC->APB1ENR |= RCC_APB1ENR_TIM12EN;
      break;
#endif

#if defined(STM32_TIM13)
    case RCC_PERIPH_TIM13:
      RCC->APB1ENR |= RCC_APB1ENR_TIM13EN;
      break;
#endif

#if defined(STM32_TIM14)
    case RCC_PERIPH_TIM14:
      RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
      break;
#endif

#if defined(STM32_LPTIM1)
    case RCC_PERIPH_LPTIMER1:
      RCC->APB1ENR |= RCC_APB1ENR_LPTIMER1EN;
      break;
#endif

#if defined(STM32_RCC_RTC_APB)
    case RCC_PERIPH_RTCAPB:
      RCC->APB1ENR |= RCC_APB1ENR_RTCAPBEN;
      break;
#endif

    case RCC_PERIPH_WWDG:
      RCC->APB1ENR |= RCC_APB1ENR_WWDGEN;
      break;

    case RCC_PERIPH_SPI2:
      RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
      break;

    case RCC_PERIPH_SPI3:
      RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
      break;

    case RCC_PERIPH_USART2:
      RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
      break;

#if defined(STM32_USART3)
    case RCC_PERIPH_USART3:
      RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
      break;
#endif

#if defined(STM32_UART4)
    case RCC_PERIPH_UART4:
      RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
      break;
#endif

#if defined(STM32_UART5)
    case RCC_PERIPH_UART5:
      RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
      break;
#endif

    case RCC_PERIPH_I2C1:
      RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
      break;

    case RCC_PERIPH_I2C2:
      RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
      break;

#if defined(STM32_I2C3)
    case RCC_PERIPH_I2C3:
      RCC->APB1ENR |= RCC_APB1ENR_I2C3EN;
      break;
#endif

#if defined(STM32_FMPI2C1)
    case RCC_PERIPH_I2CFMP1:
      RCC->APB1ENR |= RCC_APB1ENR_FMPI2C1EN;
      break;
#endif

#if defined(STM32_CAN1)
    case RCC_PERIPH_CAN1:
      RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;
      break;
#endif

#if defined(STM32_CAN2)
    case RCC_PERIPH_CAN2:
      RCC->APB1ENR |= RCC_APB1ENR_CAN2EN;
      break;
#endif

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1ENR |= RCC_APB1ENR_CECEN;
      break;
#elif defined(STM32_CAN3)
    case RCC_PERIPH_CAN3:
      RCC->APB1ENR |= RCC_APB1ENR_CAN3EN;
      break;
#endif

    case RCC_PERIPH_PWR:
      RCC->APB1ENR |= RCC_APB1ENR_PWREN;
      break;

#if defined(STM32_DAC)
    case RCC_PERIPH_DAC:
      RCC->APB1ENR |= RCC_APB1ENR_DACEN;
      break;
#endif

#if defined(STM32_UART7)
    case RCC_PERIPH_UART7:
      RCC->APB1ENR |= RCC_APB1ENR_UART7EN;
      break;
#endif

#if defined(STM32_UART8)
    case RCC_PERIPH_UART8:
      RCC->APB1ENR |= RCC_APB1ENR_UART8EN;
      break;
#endif

  // Register: APB2RSTR
    case RCC_PERIPH_TIM1:
      RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
      break;

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
      break;
#endif

    case RCC_PERIPH_USART1:
      RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
      break;

    case RCC_PERIPH_USART6:
      RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
      break;

#if defined(STM32_UART9)
    case RCC_PERIPH_UART9:
      RCC->APB2ENR |= RCC_APB2ENR_UART9EN;
      break;
#endif

#if defined(STM32_UART10)
    case RCC_PERIPH_UART10:
      RCC->APB2ENR |= RCC_APB2ENR_UART10EN;
      break;
#endif

    case RCC_PERIPH_ADC1:
      RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
      break;

#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
      RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
      break;
#endif

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
      RCC->APB2ENR |= RCC_APB2ENR_ADC3EN;
      break;
#endif

#if defined(STM32_SDIO)
    case RCC_PERIPH_SDIO:
      RCC->APB2ENR |= RCC_APB2ENR_SDIOEN;
      break;
#endif

    case RCC_PERIPH_SPI1:
      RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
      break;

#if defined(STM32_SPI4)
    case RCC_PERIPH_SPI4:
      RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;
      break;
#endif

    case RCC_PERIPH_SYSCFG:
      RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
      break;

#if defined(STM32_EXTIT)
    case RCC_PERIPH_EXTIT:
      RCC->APB2ENR |= RCC_APB2ENR_EXTITEN;
      break;
#endif

    case RCC_PERIPH_TIM9:
      RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
      break;

#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
      break;
#endif

    case RCC_PERIPH_TIM11:
      RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
      break;

#if defined(STM32_SPI5)
    case RCC_PERIPH_SPI5:
      RCC->APB2ENR |= RCC_APB2ENR_SPI5EN;
      break;
#endif

#if defined(STM32_SPI6)
    case RCC_PERIPH_SPI6:
      RCC->APB2ENR |= RCC_APB2ENR_SPI6EN;
      break;
#endif

#if defined(STM32_SAI1)
    case RCC_PERIPH_SAI1:
      RCC->APB2ENR |= RCC_APB2ENR_SAI1EN;
      break;
#endif

#if defined(STM32_SAI2)
    case RCC_PERIPH_SAI2:
      RCC->APB2ENR |= RCC_APB2ENR_SAI2EN;
      break;
#endif

#if defined(STM32_DFSDM1)
    case RCC_PERIPH_DFSDM1:
      RCC->APB2ENR |= RCC_APB2ENR_DFSDM1EN;
      break;
#endif

#if defined(STM32_DFSDM2)
    case RCC_PERIPH_DFSDM2:
      RCC->APB2ENR |= RCC_APB2ENR_DFSDM2EN;
      break;
#endif

#if defined(STM32_LTDC)
    case RCC_PERIPH_LTDC:
      RCC->APB2ENR |= RCC_APB2ENR_LTDCEN;
      break;
#endif

#if defined(STM32_DSI)
    case RCC_PERIPH_DSI:
      RCC->APB2ENR |= RCC_APB2ENR_DSIEN;
      break;
#endif

  case RCC_PERIPH_RTC:
      RCC->BDCR |= RCC_BDCR_RTCEN;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_periph, periph);
      break;
  }
}

void
rcc_periph_clock_disable(
  enum rcc_periph periph
)
{
  switch (periph)
  {
  // Register: AHB1RSTR
#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN;
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN;
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN;
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN;
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN;
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN;
      break;
#endif

#if defined(STM32_GPIOH)
    case RCC_PERIPH_GPIOH:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN;
      break;
#endif

#if defined(STM32_GPIOI)
    case RCC_PERIPH_GPIOI:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN;
      break;
#endif

#if defined(STM32_GPIOJ)
    case RCC_PERIPH_GPIOJ:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOJEN;
      break;
#endif

#if defined(STM32_GPIOK)
    case RCC_PERIPH_GPIOK:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOKEN;
      break;
#endif

    case RCC_PERIPH_CRC:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_CRCEN;
      break;

#if defined(STM32_BKPSRAM)
    case RCC_PERIPH_BKPSRAM:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_BKPSRAMEN;
      break;
#endif

#if defined(STM32_CCMRAM)
    case RCC_PERIPH_CCMDATARAM:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_CCMDATARAMEN;
      break;
#endif

    case RCC_PERIPH_DMA1:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA1EN;
      break;
  
    case RCC_PERIPH_DMA2:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN;
      break;

#if defined(STM32_DMA2D)
    case RCC_PERIPH_DMA2D:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2DEN;
      break;
#endif

#if defined(STM32_ETHERNET_MAC)
    case RCC_PERIPH_ETHMAC:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACEN;
      break;

    case RCC_PERIPH_ETHMACTX:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACTXEN;
      break;

    case RCC_PERIPH_ETHMACRX:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACRXEN;
      break;

    case RCC_PERIPH_ETHMACPTP:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACPTPEN;
      break;
#endif

#if defined(STM32_USB_OTG_HS)
    case RCC_PERIPH_OTG_HS:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSEN;
      break;
#endif

#if defined(STM32_USB_OTG_HSULPI)
    case RCC_PERIPH_OTG_HS_ULPI:
      RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSULPIEN;
      break;
#endif

#if defined(STM32_RNG)
    case RCC_PERIPH_RNG:
#if defined(STM32_RCC_RNG_AHB1)
      RCC->AHB1ENR &= ~RCC_AHB1ENR_RNGEN;
#elif defined(STM32_RCC_RNG_AHB2)
      RCC->AHB2ENR &= ~RCC_AHB2ENR_RNGEN;
#endif
      break;
#endif

  // Register: AHB2RSTR
#if defined(STM32_DCMI)
    case RCC_PERIPH_DCMI:
      RCC->AHB2ENR &= ~RCC_AHB2ENR_DCMIEN;
      break;
#endif

#if defined(STM32_CRYP)
    case RCC_PERIPH_CRYPTO:
      RCC->AHB2ENR &= ~RCC_AHB2ENR_CRYPEN;
      break;
#endif

#if defined(STM32_HASH)
    case RCC_PERIPH_HASH:
      RCC->AHB2ENR &= ~RCC_AHB2ENR_HASHEN;
      break;
#endif

#if defined(STM32_USB_OTG_FS)
    case RCC_PERIPH_OTG_FS:
      RCC->AHB2ENR &= ~RCC_AHB2ENR_OTGFSEN;
      break;
#endif

  // Register: AHB3RSTR
#if defined(STM32_RCC_AHB3)
#if defined(STM32_FMC)
    case RCC_PERIPH_FMC:
      RCC->AHB3ENR &= ~RCC_AHB3ENR_FMCEN;
      break;
#endif

#if defined(STM32_FSMC)
    case RCC_PERIPH_FSMC:
      RCC->AHB3ENR &= ~RCC_AHB3ENR_FSMCEN;
      break;
#endif

#if defined(STM32_QUADSPI)
    case RCC_PERIPH_QUADSPI:
      RCC->AHB3ENR &= ~RCC_AHB3ENR_QSPIEN;
      break;
#endif
#endif

  // Register: APB1RSTR

#if defined(STM32_TIM2)
    case RCC_PERIPH_TIM2:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN;
      break;
#endif

#if defined(STM32_TIM3)
    case RCC_PERIPH_TIM3:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN;
      break;
#endif

#if defined(STM32_TIM4)
    case RCC_PERIPH_TIM4:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN;
      break;
#endif

#if defined(STM32_TIM5)
    case RCC_PERIPH_TIM5:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN;
      break;
#endif

#if defined(STM32_TIM6)
    case RCC_PERIPH_TIM6:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN;
      break;
#endif

#if defined(STM32_TIM7)
    case RCC_PERIPH_TIM7:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN;
      break;
#endif

#if defined(STM32_TIM12)
    case RCC_PERIPH_TIM12:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN;
      break;
#endif

#if defined(STM32_TIM13)
    case RCC_PERIPH_TIM13:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN;
      break;
#endif

#if defined(STM32_TIM14)
    case RCC_PERIPH_TIM14:
      RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN;
      break;
#endif

#if defined(STM32_LPTIM1)
    case RCC_PERIPH_LPTIMER1:
      RCC->APB1ENR &= ~RCC_APB1ENR_LPTIMER1EN;
      break;
#endif

#if defined(STM32_RCC_RTC_APB)
    case RCC_PERIPH_RTCAPB:
      RCC->APB1ENR &= ~RCC_APB1ENR_RTCAPBEN;
      break;
#endif

    case RCC_PERIPH_WWDG:
      RCC->APB1ENR &= ~RCC_APB1ENR_WWDGEN;
      break;

    case RCC_PERIPH_SPI2:
      RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN;
      break;

    case RCC_PERIPH_SPI3:
      RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN;
      break;

    case RCC_PERIPH_USART2:
      RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN;
      break;

#if defined(STM32_USART3)
    case RCC_PERIPH_USART3:
      RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN;
      break;
#endif

#if defined(STM32_UART4)
    case RCC_PERIPH_UART4:
      RCC->APB1ENR &= ~RCC_APB1ENR_UART4EN;
      break;
#endif

#if defined(STM32_UART5)
    case RCC_PERIPH_UART5:
      RCC->APB1ENR &= ~RCC_APB1ENR_UART5EN;
      break;
#endif

    case RCC_PERIPH_I2C1:
      RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN;
      break;

    case RCC_PERIPH_I2C2:
      RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN;
      break;

#if defined(STM32_I2C3)
    case RCC_PERIPH_I2C3:
      RCC->APB1ENR &= ~RCC_APB1ENR_I2C3EN;
      break;
#endif

#if defined(STM32_FMPI2C1)
    case RCC_PERIPH_I2CFMP1:
      RCC->APB1ENR &= ~RCC_APB1ENR_FMPI2C1EN;
      break;
#endif

#if defined(STM32_CAN1)
    case RCC_PERIPH_CAN1:
      RCC->APB1ENR &= ~RCC_APB1ENR_CAN1EN;
      break;
#endif

#if defined(STM32_CAN2)
    case RCC_PERIPH_CAN2:
      RCC->APB1ENR &= ~RCC_APB1ENR_CAN2EN;
      break;
#endif

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1ENR &= ~RCC_APB1ENR_CECEN;
      break;
#elif defined(STM32_CAN3)
    case RCC_PERIPH_CAN3:
      RCC->APB1ENR &= ~RCC_APB1ENR_CAN3EN;
      break;
#endif

    case RCC_PERIPH_PWR:
      RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;
      break;

#if defined(STM32_DAC)
    case RCC_PERIPH_DAC:
      RCC->APB1ENR &= ~RCC_APB1ENR_DACEN;
      break;
#endif

#if defined(STM32_UART7)
    case RCC_PERIPH_UART7:
      RCC->APB1ENR &= ~RCC_APB1ENR_UART7EN;
      break;
#endif

#if defined(STM32_UART8)
    case RCC_PERIPH_UART8:
      RCC->APB1ENR &= ~RCC_APB1ENR_UART8EN;
      break;
#endif

  // Register: APB2RSTR
    case RCC_PERIPH_TIM1:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN;
      break;

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN;
      break;
#endif

    case RCC_PERIPH_USART1:
      RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN;
      break;

    case RCC_PERIPH_USART6:
      RCC->APB2ENR &= ~RCC_APB2ENR_USART6EN;
      break;

#if defined(STM32_UART9)
    case RCC_PERIPH_UART9:
      RCC->APB2ENR &= ~RCC_APB2ENR_UART9EN;
      break;
#endif

#if defined(STM32_UART10)
    case RCC_PERIPH_UART10:
      RCC->APB2ENR &= ~RCC_APB2ENR_UART10EN;
      break;
#endif

    case RCC_PERIPH_ADC1:
      RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN;
      break;

#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
      RCC->APB2ENR &= ~RCC_APB2ENR_ADC2EN;
      break;
#endif

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
      RCC->APB2ENR &= ~RCC_APB2ENR_ADC3EN;
      break;
#endif

#if defined(STM32_SDIO)
    case RCC_PERIPH_SDIO:
      RCC->APB2ENR &= ~RCC_APB2ENR_SDIOEN;
      break;
#endif

    case RCC_PERIPH_SPI1:
      RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN;
      break;

#if defined(STM32_SPI4)
    case RCC_PERIPH_SPI4:
      RCC->APB2ENR &= ~RCC_APB2ENR_SPI4EN;
      break;
#endif

    case RCC_PERIPH_SYSCFG:
      RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN;
      break;

#if defined(STM32_EXTIT)
    case RCC_PERIPH_EXTIT:
      RCC->APB2ENR &= ~RCC_APB2ENR_EXTITEN;
      break;
#endif

    case RCC_PERIPH_TIM9:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM9EN;
      break;

#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM10EN;
      break;
#endif

    case RCC_PERIPH_TIM11:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM11EN;
      break;

#if defined(STM32_SPI5)
    case RCC_PERIPH_SPI5:
      RCC->APB2ENR &= ~RCC_APB2ENR_SPI5EN;
      break;
#endif

#if defined(STM32_SPI6)
    case RCC_PERIPH_SPI6:
      RCC->APB2ENR &= ~RCC_APB2ENR_SPI6EN;
      break;
#endif

#if defined(STM32_SAI1)
    case RCC_PERIPH_SAI1:
      RCC->APB2ENR &= ~RCC_APB2ENR_SAI1EN;
      break;
#endif

#if defined(STM32_SAI2)
    case RCC_PERIPH_SAI2:
      RCC->APB2ENR &= ~RCC_APB2ENR_SAI2EN;
      break;
#endif

#if defined(STM32_DFSDM1)
    case RCC_PERIPH_DFSDM1:
      RCC->APB2ENR &= ~RCC_APB2ENR_DFSDM1EN;
      break;
#endif

#if defined(STM32_DFSDM2)
    case RCC_PERIPH_DFSDM2:
      RCC->APB2ENR &= ~RCC_APB2ENR_DFSDM2EN;
      break;
#endif

#if defined(STM32_LTDC)
    case RCC_PERIPH_LTDC:
      RCC->APB2ENR &= ~RCC_APB2ENR_LTDCEN;
      break;
#endif

#if defined(STM32_DSI)
    case RCC_PERIPH_DSI:
      RCC->APB2ENR &= ~RCC_APB2ENR_DSIEN;
      break;
#endif

  case RCC_PERIPH_RTC:
      RCC->BDCR &= ~RCC_BDCR_RTCEN;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_periph, periph);
      break;
  }
}

void
rcc_periph_clock_low_power_enable(
  enum rcc_periph periph
)
{
  switch (periph)
  {
  // Register: AHB1RSTR
#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOALPEN;
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOBLPEN;
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOCLPEN;
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIODLPEN;
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOELPEN;
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOFLPEN;
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOGLPEN;
      break;
#endif

#if defined(STM32_GPIOH)
    case RCC_PERIPH_GPIOH:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOHLPEN;
      break;
#endif

#if defined(STM32_GPIOI)
    case RCC_PERIPH_GPIOI:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOILPEN;
      break;
#endif

#if defined(STM32_GPIOJ)
    case RCC_PERIPH_GPIOJ:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOJLPEN;
      break;
#endif

#if defined(STM32_GPIOK)
    case RCC_PERIPH_GPIOK:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_GPIOKLPEN;
      break;
#endif

    case RCC_PERIPH_CRC:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_CRCLPEN;
      break;

#if defined(STM32_BKPSRAM)
    case RCC_PERIPH_BKPSRAM:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_BKPSRAMLPEN;
      break;
#endif

    case RCC_PERIPH_DMA1:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_DMA1LPEN;
      break;

    case RCC_PERIPH_DMA2:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_DMA2LPEN;
      break;

#if defined(STM32_DMA2D)
    case RCC_PERIPH_DMA2D:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_DMA2DLPEN;
      break;
#endif

#if defined(STM32_ETHERNET_MAC)
    case RCC_PERIPH_ETHMAC:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_ETHMACLPEN;
      break;

    case RCC_PERIPH_ETHMACTX:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_ETHTXLPEN;
      break;

    case RCC_PERIPH_ETHMACRX:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_ETHRXLPEN;
      break;

    case RCC_PERIPH_ETHMACPTP:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_ETHPTPLPEN;
      break;
#endif

#if defined(STM32_USB_OTG_HS)
    case RCC_PERIPH_OTG_HS:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_OTGHSLPEN;
      break;
#endif

#if defined(STM32_USB_OTG_HSULPI)
    case RCC_PERIPH_OTG_HS_ULPI:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_OTGHSULPILPEN;
      break;
#endif

#if defined(STM32_RNG)
    case RCC_PERIPH_RNG:
#if defined(STM32_RCC_RNG_AHB1)
      RCC->AHB1LPENR |= RCC_AHB1LPENR_RNGLPEN;
#elif defined(STM32_RCC_RNG_AHB2)
    RCC->AHB2LPENR |= RCC_AHB2LPENR_RNGLPEN;
#endif
      break;
#endif

  // Register: AHB2RSTR
#if defined(STM32_RCC_AHB2)
#if defined(STM32_DCMI)
    case RCC_PERIPH_DCMI:
      RCC->AHB2LPENR |= RCC_AHB2LPENR_DCMILPEN;
      break;
#endif

#if defined(STM32_CRYP)
    case RCC_PERIPH_CRYPTO:
      RCC->AHB2LPENR |= RCC_AHB2LPENR_CRYPLPEN;
      break;
#endif

#if defined(STM32_HASH)
    case RCC_PERIPH_HASH:
      RCC->AHB2LPENR |= RCC_AHB2LPENR_HASHLPEN;
      break;
#endif

    case RCC_PERIPH_OTG_FS:
      RCC->AHB2LPENR |= RCC_AHB2LPENR_OTGFSLPEN;
      break;
#endif

#if defined(STM32_RCC_AHB3)
  // Register: AHB3RSTR
#if defined(STM32_FMC)
    case RCC_PERIPH_FMC:
      RCC->AHB3LPENR |= RCC_AHB3LPENR_FMCLPEN;
      break;
#endif

#if defined(STM32_FSMC)
    case RCC_PERIPH_FSMC:
      RCC->AHB3LPENR |= RCC_AHB3LPENR_FSMCLPEN;
      break;
#endif

#if defined(STM32_QUADSPI)
    case RCC_PERIPH_QUADSPI:
      RCC->AHB3LPENR |= RCC_AHB3LPENR_QSPILPEN;
      break;
#endif
#endif

  // Register: APB1RSTR
#if defined(STM32_TIM2)
    case RCC_PERIPH_TIM2:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM2LPEN;
      break;
#endif

#if defined(STM32_TIM3)
    case RCC_PERIPH_TIM3:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM3LPEN;
      break;
#endif

#if defined(STM32_TIM4)
    case RCC_PERIPH_TIM4:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM4LPEN;
      break;
#endif

#if defined(STM32_TIM5)
    case RCC_PERIPH_TIM5:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM5LPEN;
      break;
#endif

#if defined(STM32_TIM6)
    case RCC_PERIPH_TIM6:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM6LPEN;
      break;
#endif

#if defined(STM32_TIM7)
    case RCC_PERIPH_TIM7:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM7LPEN;
      break;
#endif

#if defined(STM32_TIM12)
    case RCC_PERIPH_TIM12:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM12LPEN;
      break;
#endif

#if defined(STM32_TIM13)
    case RCC_PERIPH_TIM13:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM13LPEN;
      break;
#endif

#if defined(STM32_TIM14)
    case RCC_PERIPH_TIM14:
      RCC->APB1LPENR |= RCC_APB1LPENR_TIM14LPEN;
      break;
#endif

#if defined(STM32_LPTIM1)
    case RCC_PERIPH_LPTIMER1:
      RCC->APB1LPENR |= RCC_APB1LPENR_LPTIM1LPEN;
      break;
#endif

#if defined(STM32_RCC_RTC_APB)
    case RCC_PERIPH_RTCAPB:
      RCC->APB1LPENR |= RCC_APB1LPENR_RTCAPBLPEN;
      break;
#endif

    case RCC_PERIPH_WWDG:
      RCC->APB1LPENR |= RCC_APB1LPENR_WWDGLPEN;
      break;

    case RCC_PERIPH_SPI2:
      RCC->APB1LPENR |= RCC_APB1LPENR_SPI2LPEN;
      break;

#if defined(STM32_SPI3)
    case RCC_PERIPH_SPI3:
      RCC->APB1LPENR |= RCC_APB1LPENR_SPI3LPEN;
      break;
#endif

#if defined(STM32_SPDIFRX)
    case RCC_PERIPH_SPDIFRX:
      RCC->APB1LPENR |= RCC_APB1LPENR_SPDIFRXLPEN;
      break;
#endif

    case RCC_PERIPH_USART2:
      RCC->APB1LPENR |= RCC_APB1LPENR_USART2LPEN;
      break;

#if defined(STM32_USART3)
    case RCC_PERIPH_USART3:
      RCC->APB1LPENR |= RCC_APB1LPENR_USART3LPEN;
      break;
#endif

#if defined(STM32_UART4)
    case RCC_PERIPH_UART4:
      RCC->APB1LPENR |= RCC_APB1LPENR_UART4LPEN;
      break;
#endif

#if defined(STM32_UART5)
    case RCC_PERIPH_UART5:
      RCC->APB1LPENR |= RCC_APB1LPENR_UART5LPEN;
      break;
#endif

    case RCC_PERIPH_I2C1:
      RCC->APB1LPENR |= RCC_APB1LPENR_I2C1LPEN;
      break;

    case RCC_PERIPH_I2C2:
      RCC->APB1LPENR |= RCC_APB1LPENR_I2C2LPEN;
      break;
  
#if defined(STM32_I2C3)
    case RCC_PERIPH_I2C3:
      RCC->APB1LPENR |= RCC_APB1LPENR_I2C3LPEN;
      break;
#endif

#if defined(STM32_FMPI2C1)
    case RCC_PERIPH_I2CFMP1:
      RCC->APB1LPENR |= RCC_APB1LPENR_FMPI2C1LPEN;
      break;
#endif

#if defined(STM32_CAN1)
    case RCC_PERIPH_CAN1:
      RCC->APB1LPENR |= RCC_APB1LPENR_CAN1LPEN;
      break;
#endif

#if defined(STM32_CAN2)
    case RCC_PERIPH_CAN2:
      RCC->APB1LPENR |= RCC_APB1LPENR_CAN2LPEN;
      break;
#endif

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1LPENR |= RCC_APB1LPENR_CECLPEN;
      break;
#elif defined(STM32_CAN3)
    case RCC_PERIPH_CAN3:
      RCC->APB1LPENR |= RCC_APB1LPENR_CAN3LPEN;
      break;
#endif

    case RCC_PERIPH_PWR:
      RCC->APB1LPENR |= RCC_APB1LPENR_PWRLPEN;
      break;

#if defined(STM32_DAC)
    case RCC_PERIPH_DAC:
      RCC->APB1LPENR |= RCC_APB1LPENR_DACLPEN;
      break;
#endif

#if defined(STM32_UART7)
    case RCC_PERIPH_UART7:
      RCC->APB1LPENR |= RCC_APB1LPENR_UART7LPEN;
      break;
#endif

#if defined(STM32_UART8)
    case RCC_PERIPH_UART8:
      RCC->APB1LPENR |= RCC_APB1LPENR_UART8LPEN;
      break;
#endif

  // Register: APB2RSTR
    case RCC_PERIPH_TIM1:
      RCC->APB2LPENR |= RCC_APB2LPENR_TIM1LPEN;
      break;

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2LPENR |= RCC_APB2LPENR_TIM8LPEN;
      break;
#endif

    case RCC_PERIPH_USART1:
      RCC->APB2LPENR |= RCC_APB2LPENR_USART1LPEN;
      break;

    case RCC_PERIPH_USART6:
      RCC->APB2LPENR |= RCC_APB2LPENR_USART6LPEN;
      break;

#if defined(STM32_UART9)
    case RCC_PERIPH_UART9:
      RCC->APB2LPENR |= RCC_APB2LPENR_UART9LPEN;
      break;
#endif

#if defined(STM32_UART10)
    case RCC_PERIPH_UART10:
      RCC->APB2LPENR |= RCC_APB2LPENR_UART10LPEN;
      break;
#endif

    case RCC_PERIPH_ADC1:
      RCC->APB2LPENR |= RCC_APB2LPENR_ADC1LPEN;
      break;
  
#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
      RCC->APB2LPENR |= RCC_APB2LPENR_ADC2LPEN;
      break;
#endif

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
      RCC->APB2LPENR |= RCC_APB2LPENR_ADC3LPEN;
      break;
#endif

#if defined(STM32_SDIO)
    case RCC_PERIPH_SDIO:
      RCC->APB2LPENR |= RCC_APB2LPENR_SDIOLPEN;
      break;
#endif

    case RCC_PERIPH_SPI1:
      RCC->APB2LPENR |= RCC_APB2LPENR_SPI1LPEN;
      break;

#if defined(STM32_SPI4)
    case RCC_PERIPH_SPI4:
      RCC->APB2LPENR |= RCC_APB2LPENR_SPI4LPEN;
      break;
#endif

    case RCC_PERIPH_SYSCFG:
      RCC->APB2LPENR |= RCC_APB2LPENR_SYSCFGLPEN;
      break;

#if defined(STM32_EXTIT)
    case RCC_PERIPH_EXTIT:
      RCC->APB2LPENR |= RCC_APB2LPENR_EXTITLPEN;
      break;
#endif

    case RCC_PERIPH_TIM9:
      RCC->APB2LPENR |= RCC_APB2LPENR_TIM9LPEN;
      break;

#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2LPENR |= RCC_APB2LPENR_TIM10LPEN;
      break;
#endif

#if defined(STM32_TIM11)
    case RCC_PERIPH_TIM11:
      RCC->APB2LPENR |= RCC_APB2LPENR_TIM11LPEN;
      break;
#endif

#if defined(STM32_SPI5)
    case RCC_PERIPH_SPI5:
      RCC->APB2LPENR |= RCC_APB2LPENR_SPI5LPEN;
      break;
#endif

#if defined(STM32_SPI6)
    case RCC_PERIPH_SPI6:
      RCC->APB2LPENR |= RCC_APB2LPENR_SPI6LPEN;
      break;
#endif

#if defined(STM32_SAI1)
    case RCC_PERIPH_SAI1:
      RCC->APB2LPENR |= RCC_APB2LPENR_SAI1LPEN;
      break;
#endif

#if defined(STM32_SAI2)
    case RCC_PERIPH_SAI2:
      RCC->APB2LPENR |= RCC_APB2LPENR_SAI2LPEN;
      break;
#endif

#if defined(STM32_DFSDM1)
    case RCC_PERIPH_DFSDM1:
      RCC->APB2LPENR |= RCC_APB2LPENR_DFSDM1LPEN;
      break;
#endif

#if defined(STM32_DFSDM2)
    case RCC_PERIPH_DFSDM2:
      RCC->APB2LPENR |= RCC_APB2LPENR_DFSDM2LPEN;
      break;
#endif

#if defined(STM32_LTDC)
    case RCC_PERIPH_LTDC:
      RCC->APB2LPENR |= RCC_APB2LPENR_LTDCLPEN;
      break;
#endif

#if defined(STM32_DSI)
    case RCC_PERIPH_DSI:
      RCC->APB2LPENR |= RCC_APB2LPENR_DSILPEN;
      break;
#endif

  // Register: AHB1LPENR
    case RCC_PERIPH_FLIT:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_FLITFLPEN;
      break;

    case RCC_PERIPH_SRAM1:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_SRAM1LPEN;
      break;

#if defined(STM32_SRAM2)
    case RCC_PERIPH_SRAM2:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_SRAM2LPEN;
      break;
#endif

#if defined(STM32_SRAM3)
    case RCC_PERIPH_SRAM3:
      RCC->AHB1LPENR |= RCC_AHB1LPENR_SRAM3LPEN;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_periph, periph);
      break;
  }
}

void
rcc_periph_clock_low_power_disable(
  enum rcc_periph periph
)
{
  switch (periph)
  {
  // Register: AHB1RSTR
#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOALPEN;
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOBLPEN;
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOCLPEN;
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIODLPEN;
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOELPEN;
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOFLPEN;
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOGLPEN;
      break;
#endif

#if defined(STM32_GPIOH)
    case RCC_PERIPH_GPIOH:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOHLPEN;
      break;
#endif

#if defined(STM32_GPIOI)
    case RCC_PERIPH_GPIOI:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOILPEN;
      break;
#endif

#if defined(STM32_GPIOJ)
    case RCC_PERIPH_GPIOJ:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOJLPEN;
      break;
#endif

#if defined(STM32_GPIOK)
    case RCC_PERIPH_GPIOK:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_GPIOKLPEN;
      break;
#endif

    case RCC_PERIPH_CRC:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_CRCLPEN;
      break;

#if defined(STM32_BKPSRAM)
    case RCC_PERIPH_BKPSRAM:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_BKPSRAMLPEN;
      break;
#endif

    case RCC_PERIPH_DMA1:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_DMA1LPEN;
      break;

    case RCC_PERIPH_DMA2:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_DMA2LPEN;
      break;

#if defined(STM32_DMA2D)
    case RCC_PERIPH_DMA2D:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_DMA2DLPEN;
      break;
#endif

#if defined(STM32_ETHERNET_MAC)
    case RCC_PERIPH_ETHMAC:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_ETHMACLPEN;
      break;

    case RCC_PERIPH_ETHMACTX:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_ETHTXLPEN;
      break;

    case RCC_PERIPH_ETHMACRX:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_ETHRXLPEN;
      break;

    case RCC_PERIPH_ETHMACPTP:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_ETHPTPLPEN;
      break;
#endif

#if defined(STM32_USB_OTG_HS)
    case RCC_PERIPH_OTG_HS:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_OTGHSLPEN;
      break;
#endif

#if defined(STM32_USB_OTG_HSULPI)
    case RCC_PERIPH_OTG_HS_ULPI:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_OTGHSULPILPEN;
      break;
#endif

#if defined(STM32_RNG)
    case RCC_PERIPH_RNG:
#if defined(STM32_RCC_RNG_AHB1)
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_RNGLPEN;
#elif defined(STM32_RCC_RNG_AHB2)
    RCC->AHB2LPENR &= ~RCC_AHB2LPENR_RNGLPEN;
#endif
      break;
#endif

  // Register: AHB2RSTR
#if defined(STM32_RCC_AHB2)
#if defined(STM32_DCMI)
    case RCC_PERIPH_DCMI:
      RCC->AHB2LPENR &= ~RCC_AHB2LPENR_DCMILPEN;
      break;
#endif

#if defined(STM32_CRYP)
    case RCC_PERIPH_CRYPTO:
      RCC->AHB2LPENR &= ~RCC_AHB2LPENR_CRYPLPEN;
      break;
#endif

#if defined(STM32_HASH)
    case RCC_PERIPH_HASH:
      RCC->AHB2LPENR &= ~RCC_AHB2LPENR_HASHLPEN;
      break;
#endif

    case RCC_PERIPH_OTG_FS:
      RCC->AHB2LPENR &= ~RCC_AHB2LPENR_OTGFSLPEN;
      break;
#endif

  // Register: AHB3RSTR
#if defined(STM32_RCC_AHB2)
#if defined(STM32_FMC)
    case RCC_PERIPH_FMC:
      RCC->AHB3LPENR &= ~RCC_AHB3LPENR_FMCLPEN;
      break;
#endif

#if defined(STM32_FSMC)
    case RCC_PERIPH_FSMC:
      RCC->AHB3LPENR &= ~RCC_AHB3LPENR_FSMCLPEN;
      break;
#endif

#if defined(STM32_QUADSPI)
    case RCC_PERIPH_QUADSPI:
      RCC->AHB3LPENR &= ~RCC_AHB3LPENR_QSPILPEN;
      break;
#endif
#endif

  // Register: APB1RSTR
#if defined(STM32_TIM2)
    case RCC_PERIPH_TIM2:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM2LPEN;
      break;
#endif

#if defined(STM32_TIM3)
    case RCC_PERIPH_TIM3:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM3LPEN;
      break;
#endif

#if defined(STM32_TIM4)
    case RCC_PERIPH_TIM4:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM4LPEN;
      break;
#endif

#if defined(STM32_TIM5)
    case RCC_PERIPH_TIM5:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM5LPEN;
      break;
#endif

#if defined(STM32_TIM6)
    case RCC_PERIPH_TIM6:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM6LPEN;
      break;
#endif

#if defined(STM32_TIM7)
    case RCC_PERIPH_TIM7:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM7LPEN;
      break;
#endif

#if defined(STM32_TIM12)
    case RCC_PERIPH_TIM12:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM12LPEN;
      break;
#endif

#if defined(STM32_TIM13)
    case RCC_PERIPH_TIM13:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM13LPEN;
      break;
#endif

#if defined(STM32_TIM14)
    case RCC_PERIPH_TIM14:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_TIM14LPEN;
      break;
#endif

#if defined(STM32_LPTIM1)
    case RCC_PERIPH_LPTIMER1:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_LPTIM1LPEN;
      break;
#endif

#if defined(STM32_RCC_RTC_APB)
    case RCC_PERIPH_RTCAPB:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_RTCAPBLPEN;
      break;
#endif

    case RCC_PERIPH_WWDG:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_WWDGLPEN;
      break;

    case RCC_PERIPH_SPI2:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_SPI2LPEN;
      break;

#if defined(STM32_SPI3)
    case RCC_PERIPH_SPI3:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_SPI3LPEN;
      break;
#endif

#if defined(STM32_SPDIFRX)
    case RCC_PERIPH_SPDIFRX:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_SPDIFRXLPEN;
      break;
#endif

    case RCC_PERIPH_USART2:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_USART2LPEN;
      break;

#if defined(STM32_USART3)
    case RCC_PERIPH_USART3:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_USART3LPEN;
      break;
#endif

#if defined(STM32_UART4)
    case RCC_PERIPH_UART4:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_UART4LPEN;
      break;
#endif

#if defined(STM32_UART5)
    case RCC_PERIPH_UART5:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_UART5LPEN;
      break;
#endif

    case RCC_PERIPH_I2C1:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_I2C1LPEN;
      break;

    case RCC_PERIPH_I2C2:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_I2C2LPEN;
      break;
  
#if defined(STM32_I2C3)
    case RCC_PERIPH_I2C3:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_I2C3LPEN;
      break;
#endif

#if defined(STM32_FMPI2C1)
    case RCC_PERIPH_I2CFMP1:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_FMPI2C1LPEN;
      break;
#endif

#if defined(STM32_CAN1)
    case RCC_PERIPH_CAN1:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_CAN1LPEN;
      break;
#endif

#if defined(STM32_CAN2)
    case RCC_PERIPH_CAN2:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_CAN2LPEN;
      break;
#endif

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_CECLPEN;
      break;
#elif defined(STM32_CAN3)
    case RCC_PERIPH_CAN3:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_CAN3LPEN;
      break;
#endif

    case RCC_PERIPH_PWR:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_PWRLPEN;
      break;

#if defined(STM32_DAC)
    case RCC_PERIPH_DAC:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_DACLPEN;
      break;
#endif

#if defined(STM32_UART7)
    case RCC_PERIPH_UART7:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_UART7LPEN;
      break;
#endif

#if defined(STM32_UART8)
    case RCC_PERIPH_UART8:
      RCC->APB1LPENR &= ~RCC_APB1LPENR_UART8LPEN;
      break;
#endif

  // Register: APB2RSTR
    case RCC_PERIPH_TIM1:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_TIM1LPEN;
      break;

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_TIM8LPEN;
      break;
#endif

    case RCC_PERIPH_USART1:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_USART1LPEN;
      break;

    case RCC_PERIPH_USART6:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_USART6LPEN;
      break;

#if defined(STM32_UART9)
    case RCC_PERIPH_UART9:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_UART9LPEN;
      break;
#endif

#if defined(STM32_UART10)
    case RCC_PERIPH_UART10:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_UART10LPEN;
      break;
#endif

    case RCC_PERIPH_ADC1:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_ADC1LPEN;
      break;
  
#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_ADC2LPEN;
      break;
#endif

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_ADC3LPEN;
      break;
#endif

#if defined(STM32_SDIO)
    case RCC_PERIPH_SDIO:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SDIOLPEN;
      break;
#endif

    case RCC_PERIPH_SPI1:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SPI1LPEN;
      break;

#if defined(STM32_SPI4)
    case RCC_PERIPH_SPI4:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SPI4LPEN;
      break;
#endif

    case RCC_PERIPH_SYSCFG:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SYSCFGLPEN;
      break;

#if defined(STM32_EXTIT)
    case RCC_PERIPH_EXTIT:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_EXTITLPEN;
      break;
#endif

    case RCC_PERIPH_TIM9:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_TIM9LPEN;
      break;

#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_TIM10LPEN;
      break;
#endif

#if defined(STM32_TIM11)
    case RCC_PERIPH_TIM11:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_TIM11LPEN;
      break;
#endif

#if defined(STM32_SPI5)
    case RCC_PERIPH_SPI5:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SPI5LPEN;
      break;
#endif

#if defined(STM32_SPI6)
    case RCC_PERIPH_SPI6:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SPI6LPEN;
      break;
#endif

#if defined(STM32_SAI1)
    case RCC_PERIPH_SAI1:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SAI1LPEN;
      break;
#endif

#if defined(STM32_SAI2)
    case RCC_PERIPH_SAI2:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_SAI2LPEN;
      break;
#endif

#if defined(STM32_DFSDM1)
    case RCC_PERIPH_DFSDM1:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_DFSDM1LPEN;
      break;
#endif

#if defined(STM32_DFSDM2)
    case RCC_PERIPH_DFSDM2:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_DFSDM2LPEN;
      break;
#endif

#if defined(STM32_LTDC)
    case RCC_PERIPH_LTDC:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_LTDCLPEN;
      break;
#endif

#if defined(STM32_DSI)
    case RCC_PERIPH_DSI:
      RCC->APB2LPENR &= ~RCC_APB2LPENR_DSILPEN;
      break;
#endif

  // Register: AHB1LPENR
    case RCC_PERIPH_FLIT:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_FLITFLPEN;
      break;

    case RCC_PERIPH_SRAM1:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_SRAM1LPEN;
      break;

#if defined(STM32_SRAM2)
    case RCC_PERIPH_SRAM2:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_SRAM2LPEN;
      break;
#endif

#if defined(STM32_SRAM3)
    case RCC_PERIPH_SRAM3:
      RCC->AHB1LPENR &= ~RCC_AHB1LPENR_SRAM3LPEN;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_periph, periph);
      break;
  }
}

void
rcc_set_rtc_clock_source(
  enum rcc_rtc_clock_source source
)
{
  constexpr u32 shift = RCC_BDCR_RTCSEL_SHIFT;
  constexpr u32 mask = RCC_BDCR_RTCSEL_MASK << shift;
  volatile u32* reg = &RCC->BDCR;
  switch (source)
  {
    case RCC_RTC_CLOCK_SOURCE_NOCLOCK:
      *reg &= ~mask;
      break;

    case RCC_RTC_CLOCK_SOURCE_LSE:
      syn_set_register_bits(reg, mask, RCC_BDCR_RTCSEL_LSE << shift);
      break;

    case RCC_RTC_CLOCK_SOURCE_LSI:
      syn_set_register_bits(reg, mask, RCC_BDCR_RTCSEL_LSI << shift);
      break;

    case RCC_RTC_CLOCK_SOURCE_HSE:
      *reg |= (RCC_BDCR_RTCSEL_HSE << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_rtc_clock_source, source);
      break;
  }
}

void
rcc_backup_domain_reset(void)
{
  RCC->BDCR |= RCC_BDCR_BDRST;
  RCC->BDCR &= ~RCC_BDCR_BDRST;
}

void
rcc_lse_bypass_enable(void)
{
  RCC->BDCR |= RCC_BDCR_LSEBYP;
}

void
rcc_lse_bypass_disable(void)
{
  RCC->BDCR &= ~RCC_BDCR_LSEBYP;
}

#if defined(STM32_RCC_LSEMODE)
void
rcc_set_lse_mode(
  enum rcc_lse_mode mode
)
{
  volatile u32* reg = &RCC->BDCR;
  switch (mode)
  {
    case RCC_LSE_MODE_LOW_POWER:
      *reg &= ~RCC_BDCR_LSEMOD;
      break;

    case RCC_LSE_MODE_HIGH_DRIVE:
      *reg |= RCC_BDCR_LSEMOD;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_lse_mode, mode);
      break;
  }
}
#endif

u32
rcc_is_reset_flag_set(
  enum rcc_reset_flag flag
)
{
  volatile u32* reg = &RCC->CSR;
  switch (flag)
  {
    case RCC_RESET_FLAG_BOR:
      return *reg & RCC_CSR_BORRSTF;

    case RCC_RESET_FLAG_PIN:
      return *reg & RCC_CSR_PINRSTF;

    case RCC_RESET_FLAG_POR_PDR:
      return *reg & RCC_CSR_PORRSTF;

    case RCC_RESET_FLAG_SOFTWARE:
      return *reg & RCC_CSR_SFTRSTF;

    case RCC_RESET_FLAG_INDEPENDENT:
      return *reg & RCC_CSR_IWDGRSTF;

    case RCC_RESET_FLAG_WINDOW_WATCHDOG:
      return *reg & RCC_CSR_WWDGRSTF;

    case RCC_RESET_FLAG_LOW_POWER:
      return *reg & RCC_CSR_LPWRRSTF;

    default:
      devmode_error_invalid_enum(enum rcc_reset_flag, flag);
      return 0;
  }
}

void
rcc_reset_flags_clear(void)
{
  RCC->CSR |= RCC_CSR_RMVF;
}

void
rcc_set_modulation_period(
  u32 period
)
{
  devmode_assert_lower_or_eq(period, RCC_SSCGR_MODPER_MASK);
  constexpr u32 shift = RCC_SSCGR_MODPER_SHIFT;
  constexpr u32 mask = RCC_SSCGR_MODPER_MASK << shift;
  volatile u32* reg = &RCC->SSCGR;
  syn_set_register_bits(reg, mask, period << shift);
}

void
rcc_set_incrementation_step(
  u32 step
)
{
  devmode_assert_lower_or_eq(step, RCC_SSCGR_INCSTEP_MASK);
  constexpr u32 shift = RCC_SSCGR_INCSTEP_SHIFT;
  constexpr u32 mask = RCC_SSCGR_INCSTEP_MASK << shift;
  volatile u32* reg = &RCC->SSCGR;
  syn_set_register_bits(reg, mask, step << shift);
}

void
rcc_set_spread(
  enum rcc_spread spread
)
{
  volatile u32* reg = &RCC->SSCGR;
  switch (spread)
  {
    case RCC_SPREAD_CENTER:
      *reg &= ~RCC_SSCGR_SPREADSEL;
      break;

    case RCC_SPREAD_DOWN:
      *reg |= RCC_SSCGR_SPREADSEL;
      break;

    default:
      devmode_error_invalid_enum(eum rcc_spread, spread);
      break;
  }
}

void
rcc_spread_spectrum_modulation_enable(void)
{
  RCC->SSCGR |= RCC_SSCGR_SSCGEN;
}

void
rcc_spread_spectrum_modulation_disable(void)
{
  RCC->SSCGR &= ~RCC_SSCGR_SSCGEN;
}

#if defined(STM32_RCC_PLLI2S)
#if defined(STM32_RCC_PLLI2S_FACTORM)
void
rcc_set_plli2s_factorM(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLI2SCFGR_PLLI2SM_MIN_VAL,
    RCC_PLLI2SCFGR_PLLI2SM_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLI2SCFGR_PLLI2SM_SHIFT;
  constexpr u32 mask = RCC_PLLI2SCFGR_PLLI2SM_MASK << shift;
  volatile u32* reg = &RCC->PLLI2SCFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}
#endif

void
rcc_set_plli2s_factorN(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLI2SCFGR_PLLI2SN_MIN_VAL,
    RCC_PLLI2SCFGR_PLLI2SN_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLI2SCFGR_PLLI2SN_SHIFT;
  constexpr u32 mask = RCC_PLLI2SCFGR_PLLI2SN_MASK << shift;
  volatile u32* reg = &RCC->PLLI2SCFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}

#if defined(STM32_RCC_PLLI2S_FACTORP)
void
rcc_set_plli2s_factorP(
  enum rcc_plli2s_factorp factor
)
{
  constexpr u32 shift = RCC_PLLI2SCFGR_PLLI2SP_SHIFT; 
  constexpr u32 mask = RCC_PLLI2SCFGR_PLLI2SP_MASK << shift; 
  volatile u32* reg = &RCC->PLLI2SCFGR;

  switch (factor)
  {
    case RCC_PLLI2S_FACTORP_DIV2:
      *reg &= ~mask;
      break;

    case RCC_PLLI2S_FACTORP_DIV4:
      syn_set_register_bits(reg, mask, RCC_PLLI2S_FACTORP_DIV4 << shift);
      break;

    case RCC_PLLI2S_FACTORP_DIV6:
      syn_set_register_bits(reg, mask, RCC_PLLI2S_FACTORP_DIV6 << shift);
      break;

    case RCC_PLLI2S_FACTORP_DIV8:
      *reg |= (RCC_PLLI2S_FACTORP_DIV8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_plli2s_factorp, factor);
      break;
  }
}
#endif

#if defined(STM32_RCC_PLLI2S_FACTORQ)
void
rcc_set_plli2s_factorQ(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLI2SCFGR_PLLI2SQ_MIN_VAL,
    RCC_PLLI2SCFGR_PLLI2SQ_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLI2SCFGR_PLLI2SQ_SHIFT;
  constexpr u32 mask = RCC_PLLI2SCFGR_PLLI2SQ_MASK << shift;
  volatile u32* reg = &RCC->PLLI2SCFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}
#endif

void
rcc_set_plli2s_factorR(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLI2SCFGR_PLLI2SR_MIN_VAL,
    RCC_PLLI2SCFGR_PLLI2SR_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLI2SCFGR_PLLI2SR_SHIFT;
  constexpr u32 mask = RCC_PLLI2SCFGR_PLLI2SR_MASK << shift;
  volatile u32* reg = &RCC->PLLI2SCFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}

#if defined(STM32_RCC_PLLI2S_CLOCK_SOURCE)
void
rcc_set_plli2s_clock_source(
  enum rcc_plli2s_clock_source source
)
{
  volatile u32* reg = &RCC->PLLI2SCFGR;
  switch (source)
  {
    case RCC_PLLI2S_CLOCK_SOURCE_PLLSRC:
      *reg &= ~RCC_PLLI2SCFGR_PLLI2SSRC;
      break;

    case RCC_PLLI2S_CLOCK_SOURCE_EXTERNAL_AFI:
      *reg |= RCC_PLLI2SCFGR_PLLI2SSRC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_plli2s_clock_source, source);
      break;
  }
}
#endif
#endif

#if defined(STM32_RCC_PLLSAI)
#if defined(STM32_RCC_PLLSAI_FACTORM)
void
rcc_set_pllsai_factorM(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLSAICFGR_PLLSAIM_MIN_VAL,
    RCC_PLLSAICFGR_PLLSAIM_MAX_VAL + 1
  );
  constexpr u32 shift = RCC_PLLSAICFGR_PLLSAIM_SHIFT;
  constexpr u32 mask = RCC_PLLSAICFGR_PLLSAIM_MASK << shift;
  volatile u32* reg = &RCC->PLLSAICFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}
#endif

void
rcc_set_pllsai_factorN(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLSAICFGR_PLLSAIN_MIN_VAL,
    RCC_PLLSAICFGR_PLLSAIN_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLSAICFGR_PLLSAIN_SHIFT;
  constexpr u32 mask = RCC_PLLSAICFGR_PLLSAIN_MASK << shift;
  volatile u32* reg = &RCC->PLLSAICFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}

#if defined(STM32_RCC_PLLSAI_FACTORP)
void
rcc_set_pllsai_factorP(
  enum rcc_pllsai_factorp factor
)
{
  constexpr u32 shift = RCC_PLLSAICFGR_PLLSAIP_SHIFT;
  constexpr u32 mask = RCC_PLLSAICFGR_PLLSAIP_MASK << shift;
  volatile u32* reg = &RCC->PLLSAICFGR;

  switch (factor)
  {
    case RCC_PLLSAI_FACTORP_DIV2:
      *reg &= ~mask;
      break;

    case RCC_PLLSAI_FACTORP_DIV4:
      syn_set_register_bits(reg, mask, RCC_PLLSAICFGR_PLLSAIP_DIV4 << shift);
      break;

    case RCC_PLLSAI_FACTORP_DIV6:
      syn_set_register_bits(reg, mask, RCC_PLLSAICFGR_PLLSAIP_DIV6 << shift);
      break;

    case RCC_PLLSAI_FACTORP_DIV8:
      *reg |= (RCC_PLLSAICFGR_PLLSAIP_DIV8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_pllsai_factorp, factor);
      break;
  }
}
#endif

void
rcc_set_pllsai_factorQ(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLSAICFGR_PLLSAIQ_MIN_VAL,
    RCC_PLLSAICFGR_PLLSAIQ_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLSAICFGR_PLLSAIQ_SHIFT;
  constexpr u32 mask = RCC_PLLSAICFGR_PLLSAIQ_MASK << shift;
  volatile u32* reg = &RCC->PLLSAICFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}

#if defined(STM32_RCC_PLLSAI_FACTORR)
void
rcc_set_pllsai_factorR(
  u32 factor
)
{
  devmode_assert_in_range(
    factor,
    RCC_PLLSAICFGR_PLLSAIR_MIN_VAL,
    RCC_PLLSAICFGR_PLLSAIR_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_PLLSAICFGR_PLLSAIR_SHIFT;
  constexpr u32 mask = RCC_PLLSAICFGR_PLLSAIR_MASK << shift;
  volatile u32* reg = &RCC->PLLSAICFGR;
  syn_set_register_bits(reg, mask, factor << shift);
}
#endif
#endif

#if defined(STM32_RCC_PLLI2S_DIVQ)
void
rcc_set_plli2s_dividerQ(
  u32 divider
)
{
  devmode_assert_lower_or_eq(divider, RCC_DCKCFGR_PLLI2SDIVQ_MASK);
  constexpr u32 shift = RCC_DCKCFGR_PLLI2SDIVQ_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_PLLI2SDIVQ_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;
  syn_set_register_bits(reg, mask, divider << shift);
}
#elif defined(STM32_RCC_PLLI2S_DIVR)
void
rcc_set_plli2s_dividerR(
  u32 divider
)
{
  devmode_assert_in_range(
    divider,
    RCC_DCKCFGR_PLLI2SDIVR_MIN_VAL,
    RCC_DCKCFGR_PLLI2SDIVR_MAX_VAL + 1
  );

  constexpr u32 shift = RCC_DCKCFGR_PLLI2SDIVR_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_PLLI2SDIVR_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;
  syn_set_register_bits(reg, mask, divider << shift);
}
#endif

#if defined(STM32_RCC_PLLSAI_DIVQ)
void
rcc_set_pllsai_dividerQ(
  u32 divider
)
{
  devmode_assert_lower_or_eq(divider, RCC_DCKCFGR_PLLSAIDIVQ_MASK);
  constexpr u32 shift = RCC_DCKCFGR_PLLSAIDIVQ_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_PLLSAIDIVQ_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;
  syn_set_register_bits(reg, mask, divider << shift);
}
#elif defined(STM32_RCC_PLL_DIVR)
void
rcc_set_pll_dividerR(
  u32 divider
)
{
  devmode_assert_lower_or_eq(divider, RCC_DCKCFGR_PLLDIVR_MASK);
  constexpr u32 shift = RCC_DCKCFGR_PLLDIVR_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_PLLDIVR_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;
  syn_set_register_bits(reg, mask, divider << shift);
}
#endif

#if defined(STM32_DFSDM2)
void
rcc_set_dfsdm2_audio_clock_source(
  enum rcc_dfsdm_audio_clock_source source
)
{
  volatile u32* reg = &RCC->DCKCFGR;
  switch (source)
  {
    case RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB1:
      *reg &= ~RCC_DCKCFGR_CKDFSDM2ASEL;
      break;

    case RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB2:   
      *reg |= RCC_DCKCFGR_CKDFSDM2ASEL;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_dfsdm_audio_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_DFSDM1)
void
rcc_set_dfsdm1_audio_clock_source(
  enum rcc_dfsdm_audio_clock_source source
)
{
  volatile u32* reg = &RCC->DCKCFGR;
  switch (source)
  {
    case RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB1:
      *reg &= ~RCC_DCKCFGR_CKDFSDM1ASEL;
      break;

    case RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB2:   
      *reg |= RCC_DCKCFGR_CKDFSDM1ASEL;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_dfsdm_audio_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_RCC_PLLSAI_DIVR)
void
rcc_set_pllsai_dividerR(
  u32 divider
)
{
  devmode_assert_lower_or_eq(divider, RCC_DCKCFGR_PLLSAIDIVR_MASK);
  constexpr u32 shift = RCC_DCKCFGR_PLLSAIDIVR_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_PLLSAIDIVR_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;
  syn_set_register_bits(reg, mask, divider << shift);
}
#endif

#if defined(STM32_RCC_SAI1)
void
rcc_set_sai1_clock_source(
  enum rcc_sai1_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR_SAI1SRC_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_SAI1SRC_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;

  switch (source)
  {
    case RCC_SAI1_CLOCK_SOURCE_PLLSAIQ:
      *reg &= ~mask;
      break;

    case RCC_SAI1_CLOCK_SOURCE_PLLI2SQ:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1SRC_PLLI2SQ << shift);
      break;

    case RCC_SAI1_CLOCK_SOURCE_PLLR:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1SRC_PLLR << shift);
      break;

    case RCC_SAI1_CLOCK_SOURCE_ALTIN:
      *reg |= (RCC_DCKCFGR_SAI1SRC_I2SCKIN << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_sai1_clock_source, source);
      break;
  }
}
#elif defined(STM32_RCC_SAI1A)
void
rcc_set_sai1a_clock_source(
  enum rcc_sai1a_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR_SAI1ASRC_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_SAI1ASRC_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;

  switch (source)
  {
#if defined(STM32_RCC_SAI1ASRC_LAYOUT1)
    case RCC_SAI1A_CLOCK_SOURCE_PLLI2SR:
      *reg &= ~mask;
      break;

    case RCC_SAI1A_CLOCK_SOURCE_I2SCLIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1ASRC_I2SCLIN << shift);
      break;

    case RCC_SAI1A_CLOCK_SOURCE_PLLR:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1ASRC_PLLR << shift);
      break;

    case RCC_SAI1A_CLOCK_SOURCE_HSCK:
      *reg |= (RCC_DCKCFGR_SAI1ASRC_HSCK << shift);
      break;

#elif defined(STM32_RCC_SAI1ASRC_LAYOUT2)
    case RCC_SAI1A_CLOCK_SOURCE_PLLSAIQ:
      *reg &= ~mask;
      break;

    case RCC_SAI1A_CLOCK_SOURCE_PLLI2SQ:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1ASRC_PLLI2SQ << shift);
      break;

    case RCC_SAI1A_CLOCK_SOURCE_ALTIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1ASRC_ALTIN << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_sai1a_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_SAI2)
void
rcc_set_sai2_clock_source(
  enum rcc_sai2_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR_SAI2SRC_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_SAI2SRC_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;

  switch (source)
  {
    case RCC_SAI2_CLOCK_SOURCE_PLLSAIQ:
      *reg &= ~mask;
      break;

    case RCC_SAI2_CLOCK_SOURCE_PLLI2SQ:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI2SRC_PLLI2SQ << shift);
      break;

    case RCC_SAI2_CLOCK_SOURCE_PLLR:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI2SRC_PLLR << shift);
      break;

    case RCC_SAI2_CLOCK_SOURCE_PLLSRC:
      *reg |= (RCC_DCKCFGR_SAI2SRC_PLLSRC << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_sai2_clock_source, source);
      break;
  }
}
#elif defined(STM32_RCC_SAI1B)
void
rcc_set_sai1b_clock_source(
  enum rcc_sai1b_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR_SAI1BSRC_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_SAI1BSRC_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;

  switch (source)
  {
#if defined(STM32_RCC_SAI1BSRC_LAYOUT1)
    case RCC_SAI2_CLOCK_SOURCE_PLLI2SR:
      *reg &= ~mask;
      break;

    case RCC_SAI2_CLOCK_SOURCE_I2SCLIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1BSRC_I2SCLIN << shift);
      break;

    case RCC_SAI2_CLOCK_SOURCE_PLLR:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1BSRC_PLLR << shift);
      break;

    case RCC_SAI2_CLOCK_SOURCE_HSCK:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1BSRC_HSCK << shift);
      break;

#elif defined(STM32_RCC_SAI1BSRC_LAYOUT2)
    case RCC_SAI1B_CLOCK_SOURCE_PLLSAIQ:
      *reg &= ~mask;
      break;

    case RCC_SAI1B_CLOCK_SOURCE_PLLI2SQ:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1BSRC_PLLI2SQ << shift);
      break;

    case RCC_SAI1B_CLOCK_SOURCE_ALTIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_SAI1BSRC_ALTIN << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_sai1b_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_RCC_TIMPRE)
void
rcc_set_timers_prescaler(
  enum rcc_timers_prescaler prescaler
)
{
  volatile u32* reg = &RCC->DCKCFGR;
  switch (prescaler)
  {
    case RCC_TIMERS_PRESCALER_x2:
      *reg &= ~RCC_DCKCFGR_TIMPRE;
      break;

    case RCC_TIMERS_PRESCALER_x4:
      *reg |= RCC_DCKCFGR_TIMPRE;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_timers_prescaler, prescaler);
      break;
  }
}
#endif

#if defined(STM32_RCC_CLOCK_48MHZ)
// DCKCFGR or DCKCFGR2
void
rcc_set_48Mhz_clock_source(
  enum rcc_48Mhz_clock_source source
)
{
  switch (source)
  {
#if defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR_LAYOUT1)
    case RCC_48MHZ_CLOCK_SOURCE_PLL:
      RCC->DCKCFGR &= ~RCC_DCKCFGR_48MSEL;
      break;

    case RCC_48MHZ_CLOCK_SOURCE_PLLSAI:
      RCC->DCKCFGR |= RCC_DCKCFGR_48MSEL;
      break;

#elif defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT1)
    case RCC_48MHZ_CLOCK_SOURCE_PLLQ:
      RCC->DCKCFGR2 &= ~RCC_DCKCFGR2_CK48MSEL;
      break;

    case RCC_48MHZ_CLOCK_SOURCE_PLLI2SQ:
      RCC->DCKCFGR2 |= RCC_DCKCFGR2_CK48MSEL;
      break;
#elif defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT2)
    case RCC_48MHZ_CLOCK_SOURCE_PLLSAIP:
      RCC->DCKCFGR2 |= RCC_DCKCFGR2_CK48MSEL;
      break;

    case RCC_48MHZ_CLOCK_SOURCE_PLLQ:
      RCC->DCKCFGR2 &= ~RCC_DCKCFGR2_CK48MSEL;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_48Mhz_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_SDIO)
// DCKCFGR or DCLCFGR2
void
rcc_set_sdio_clock_source(
  enum rcc_sdio_clock_source source
)
{
  switch (source)
  {
#if defined(STM32_RCC_SDIOCK_DCKCFGR)
    case RCC_SDIO_CLOCK_SOURCE_48MHZ:
      RCC->DCKCFGR &= ~RCC_DCKCFGR_SDIOSEL;
      break;

    case RCC_SDIO_CLOCK_SOURCE_SYSCLK:
      RCC->DCKCFGR |= RCC_DCKCFGR_SDIOSEL;
      break;
#elif defined(STM32_RCC_SDIOCK_DCKCFGR2)
    case RCC_SDIO_CLOCK_SOURCE_48MHZ:
      RCC->DCKCFGR2 &= ~RCC_DCKCFGR2_SDIOSEL;
      break;

    case RCC_SDIO_CLOCK_SOURCE_SYSCLK:
      RCC->DCKCFGR2 |= RCC_DCKCFGR2_SDIOSEL;
      break;
#endif
    default:
      devmode_error_invalid_enum(enum rcc_sdio_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_DSI_HOST)
void
rcc_set_dsi_clock_source(
  enum rcc_dsi_clock_source source
)
{
  volatile u32* reg = &RCC->DCKCFGR;
  switch (source)
  {
    case RCC_DSI_CLOCK_SOURCE_DSI_PHY:
      *reg &= ~RCC_DCKCFGR_DSISEL;
      break;

    case RCC_DSI_CLOCK_SOURCE_PLLR:
      *reg |= RCC_DCKCFGR_DSISEL;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_dsi_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_RCC_I2S1)
void
rcc_set_i2s1_clock_source(
  enum rcc_i2s_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR_I2S1SRC_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_I2S1SRC_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;

  switch (source)
  {
#if defined(STM32_RCC_I2SSRC_LAYOUT1)
    case RCC_I2S_CLOCK_SOURCE_PLLR:
      *reg &= ~mask;
      break;

    case RCC_I2S_CLOCK_SOURCE_ALTIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2SSRC_ALTIN << shift);
      break;

    case RCC_I2S_CLOCK_SOURCE_PLLSRC:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2SSRC_PLLSRC << shift);
      break;

#elif defined(STM32_RCC_I2SSRC_LAYOUT2)
    case RCC_I2S1_CLOCK_SOURCE_PLLI2SR:
      *reg &= ~mask;
      break;

    case RCC_I2S1_CLOCK_SOURCE_I2CCKIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2S1SRC_I2SCKIN << shift);
      break;

    case RCC_I2S1_CLOCK_SOURCE_PLLR:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2S1SRC_PLLR << shift);
      break;

    case RCC_I2S1_CLOCK_SOURCE_PLLSRC:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2S1SRC_PLLSRC << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_i2s_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_RCC_I2S2)
void
rcc_set_i2s2_clock_source(
  enum rcc_i2s_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR_I2S2SRC_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR_I2S2SRC_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR;

  switch (source)
  {
#if defined(STM32_RCC_I2SSRC_LAYOUT1)
    case RCC_I2S_CLOCK_SOURCE_PLLR:
      *reg &= ~mask;
      break;

    case RCC_I2S_CLOCK_SOURCE_ALTIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2SSRC_ALTIN << shift);
      break;

    case RCC_I2S_CLOCK_SOURCE_PLLSRC:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2SSRC_PLLSRC << shift);
      break;

#elif defined(STM32_RCC_I2SSRC_LAYOUT2)
    case RCC_I2S_CLOCK_SOURCE_PLLI2SR:
      *reg &= ~mask;
      break;

    case RCC_I2S_CLOCK_SOURCE_I2CCKIN:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2SSRC_I2SCKIN << shift);
      break;

    case RCC_I2S_CLOCK_SOURCE_PLLR:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2SSRC_PLLR << shift);
      break;

    case RCC_I2S_CLOCK_SOURCE_PLLSRC:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR_I2SSRC_PLLSRC << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_i2s_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_DFSDM_KERNEL_CKSRC)
void
rcc_set_dfsdm_kernel_clock_source(
  enum rcc_dfsdm_kernel_clock_source source
)
{
  volatile u32* reg = &RCC->DCKCFGR;
  switch (source)
  {
    case RCC_DFSDM_KERNEL_CLOCK_SOURCE_APB2:
      *reg &= ~RCC_DCKCFGR_CKDFSDM1SEL;
      break;

    case RCC_DFSDM_KERNEL_CLOCK_SOURCE_SYSCLOCK:
      *reg |= RCC_DCKCFGR_CKDFSDM1SEL;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_dfsdm_kernel_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_RCC_CKGATE)
void
rcc_gate_clock_enable(
  enum rcc_gate_clock clock
)
{
  volatile u32* reg = &RCC->CKGATENR;
  switch (clock)
  {
    case RCC_GATE_CLOCK_AHB_to_APB1:
      *reg |= RCC_CKGATENR_AHB2APB1CKEN;
      break;

    case RCC_GATE_CLOCK_AHB_to_APB2:
      *reg |= RCC_CKGATENR_AHB2APB2CKEN;
      break;

    case RCC_GATE_CLOCK_CM4:
      *reg |= RCC_CKGATENR_CM4DBGCKEN;
      break;

    case RCC_GATE_CLOCK_SPARE:
      *reg |= RCC_CKGATENR_SPARECKEN;
      break;

    case RCC_GATE_CLOCK_SRAM:
      *reg |= RCC_CKGATENR_SRAMCKEN;
      break;

    case RCC_GATE_CLOCK_FLASH:
      *reg |= RCC_CKGATENR_FLITFCKEN;
      break;

    case RCC_GATE_CLOCK_RCC:
      *reg |= RCC_CKGATENR_RCCCKEN;
      break;

#if defined(STM32_RCC_CKGATE_EVT)
    case RCC_GATE_CLOCK_EVENT:
      *reg |= RCC_CKGATENR_EVTCLCKEN;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_gate_clock, clock);
      break;
  }
}

void
rcc_gate_clock_disable(
  enum rcc_gate_clock clock
)
{
  volatile u32* reg = &RCC->CKGATENR;
  switch (clock)
  {
    case RCC_GATE_CLOCK_AHB_to_APB1:
      *reg &= ~RCC_CKGATENR_AHB2APB1CKEN;
      break;

    case RCC_GATE_CLOCK_AHB_to_APB2:
      *reg &= ~RCC_CKGATENR_AHB2APB2CKEN;
      break;

    case RCC_GATE_CLOCK_CM4:
      *reg &= ~RCC_CKGATENR_CM4DBGCKEN;
      break;

    case RCC_GATE_CLOCK_SPARE:
      *reg &= ~RCC_CKGATENR_SPARECKEN;
      break;

    case RCC_GATE_CLOCK_SRAM:
      *reg &= ~RCC_CKGATENR_SRAMCKEN;
      break;

    case RCC_GATE_CLOCK_FLASH:
      *reg &= ~RCC_CKGATENR_FLITFCKEN;
      break;

    case RCC_GATE_CLOCK_RCC:
      *reg &= ~RCC_CKGATENR_RCCCKEN;
      break;

    case RCC_GATE_CLOCK_EVENT:
      *reg &= ~RCC_CKGATENR_EVTCLCKEN;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_gate_clock, clock);
      break;
  }
}
#endif

#if defined(STM32_FMPI2C1)
void
rcc_set_i2c_fmp1_clock_source(
  enum rcc_i2cfmp_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR2_FMPI2C1SEL_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR2_FMPI2C1SEL_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR2;

  switch (source)
  {
    case RCC_I2CFMP_CLOCK_SOURCE_APB1:
      *reg &= ~mask;
      break;

    case RCC_I2CFMP_CLOCK_SOURCE_SYSCLK:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR2_FMPI2C1SEL_SYSCLK << shift);
      break;

    case RCC_I2CFMP_CLOCK_SOURCE_HSI:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR2_FMPI2C1SEL_HSI << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_i2c_fmp1_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_CEC)
void
rcc_set_cec_clock_source(
  enum rcc_cec_clock_source source
)
{
  volatile u32* reg = &RCC->DCKCFGR2;
  switch (source)
  {
    case RCC_CEC_CLOCK_SOURCE_LSE:
      RCC->DCKCFGR2 &= ~RCC_DCKCFGR2_CECSEL;
      break;

    case RCC_CEC_CLOCK_SOURCE_HSI:
      RCC->DCKCFGR2 |= RCC_CFGR2_CECSEL;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_cec_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_SPDIFRX)
void
rcc_set_spdifrx_clock_source(
  enum rcc_spdifrx_clock_source source
)
{
  volatile u32* reg = &RCC->DCKCFGR2;
  switch (source)
  {
    case RCC_SPDIFRX_CLOCK_SOURCE_PLLR:
      *reg &= ~RCC_DCKCFGR2_SPDIFRXSEL;
      break;

    case RCC_SPDIFRX_CLOCK_SOURCE_PLLI2SP:
      *reg |= RCC_DCKCFGR2_SPDIFRXSEL;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_spdifrx_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_LPTIM1)
void
rcc_set_lptimer1_clock_source(
  enum rcc_lptimer1_clock_source source
)
{
  constexpr u32 shift = RCC_DCKCFGR2_LPTIMER1SEL_SHIFT;
  constexpr u32 mask = RCC_DCKCFGR2_LPTIMER1SEL_MASK << shift;
  volatile u32* reg = &RCC->DCKCFGR2;

  switch (source)
  {
    case RCC_LPTIMER1_CLOCK_SOURCE_APB:
      *reg &= ~mask;
      break;

    case RCC_LPTIMER1_CLOCK_SOURCE_HSI:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR2_LPTIMER1SEL_HSI_CLOCK << shift);
      break;

    case RCC_LPTIMER1_CLOCK_SOURCE_LSI:
      syn_set_register_bits(reg, mask, RCC_DCKCFGR2_LPTIMER1SEL_LSI_CLOCK << shift);
      break;

    case RCC_LPTIMER1_CLOCK_SOURCE_LSE:
      *reg |= (RCC_DCKCFGR2_LPTIMER1SEL_LSE_CLOCK << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_lptimer1_clock_source, source);
      break;
  }
}
#endif
