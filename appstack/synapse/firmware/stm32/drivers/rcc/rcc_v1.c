#include "synapse/stm32/periph/flash.h"
#include "synapse/stm32/drivers/rcc/rcc_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct rcc_registers_map rcc_periph;
rcc_periph* RCC = (rcc_periph*) (RCC_ADDR);

static u32 apb2_clock = RCC_CLOCK_UNKNOWN;
static u32 apb1_clock = RCC_CLOCK_UNKNOWN;
static u32 ahb_clock = RCC_CLOCK_UNKNOWN;
static u32 sysclock = RCC_CLOCK_UNKNOWN;

struct rcc_clock_config rcc_configs[] = {
  /**
   * Device specs:
   *  - Type: density
   *  - HSE: 8Mhz
   *
   * Configuration:
   *  - HSE: 8Mhz
   *  - AHB: 72Mhz
   *  - APB1: 36Mhz
   *  - APB2: 72Mhz
   *  - ADC: 12Mhz
   *  - Tim2,3,4: 72Mhz
   *  - Tim1: 72Mhz
   */
  {
    .osc = RCC_OSC_HSE,
    .pllxtpre = RCC_PLL_HSE_PRESCALER_1,
    .sysclock = RCC_SYSCLOCK_PLL,
    .pll_source = RCC_PLL_SOURCE_HSE,
    .pllmul = RCC_PLL_MULTIPLICATION_FACTOR_9,
    .ahb_prescaler = RCC_AHB_PRESCALER_1,

#if defined(STM32_RCC_PPRE2)
    .apb2_prescaler = RCC_APB2_PRESCALER_1,
#endif

    .apb1_prescaler = RCC_APB1_PRESCALER_2,

#if defined(STM32_RCC_ADCPRE)
    .adc_prescaler = RCC_ADC_PRESCALER_6,
#endif

    .usb_prescaler = RCC_USB_OTG_FS_PRESCALER_3,
    .mco = RCC_MCO_NO_OUTPUT,
    .flash_wait_state = FLASH_WAIT_STATE2,
    .apb1_clock_freq = 36000000,
    .apb2_clock_freq = 72000000,
    .ahb_clock_freq = 72000000,
    .sysclock_freq = 72000000
  },

  /**
   * Device specs:
   *  - Type: density
   *  - HSE: 8Mhz
   *
   * Configuration:
   *  - HSE: 8Mhz
   *  - AHB: 32Mhz
   *  - APB1: 16Mhz
   *  - APB2: 32Mhz
   *  - ADC: 8Mhz
   *  - Tim2,3,4: 32Mhz
   *  - Tim1: 32Mhz
   */
  {
    .osc = RCC_OSC_HSE,
    .pllxtpre = RCC_PLL_HSE_PRESCALER_1,
    .sysclock = RCC_SYSCLOCK_PLL,
    .pll_source = RCC_PLL_SOURCE_HSE,
    .pllmul = RCC_PLL_MULTIPLICATION_FACTOR_4,
    .ahb_prescaler = RCC_AHB_PRESCALER_1,

#if defined(STM32_RCC_PPRE2)
    .apb2_prescaler = RCC_APB2_PRESCALER_1,
#endif

    .apb1_prescaler = RCC_APB1_PRESCALER_2,

#if defined(STM32_RCC_ADCPRE)
    .adc_prescaler = RCC_ADC_PRESCALER_4,
#endif

    .usb_prescaler = RCC_USB_OTG_FS_PRESCALER_3,
    .mco = RCC_MCO_NO_OUTPUT,
    .flash_wait_state = FLASH_WAIT_STATE1
  },
};

void
rcc_setup_config_type(
  enum rcc_config_type type
)
{
  rcc_setup_clock_configuration(&rcc_configs[type]);
}

void
rcc_setup_clock_configuration(
  struct rcc_clock_config* config
)
{
  // Enable the desired oscillator
  // Wait for it to be ready
  // Set flash wait state (TODO)
  // Enable the prefetch buffer (TODO)
  // Configure AHB prescaler
  // Configure APB1 prescaler
  // Configure APB2 prescaler
  // Configure ADC prescaler
  // Configure PLL (If used)
  // Enable PLL (If used)
  // Set SysClock source (HSI, HSE, PLL)
  // Configure Microcontroller clock output

  rcc_osc_enable(config->osc);

  rcc_osc_ready_wait(config->osc);

#if defined(STM32_RCC_PREDIV1)
  if (config->is_connectivity_device)
  {
    rcc_set_prediv1_source(config->prediv1_source);
    rcc_set_prediv1_prescaler(config->prediv1_prescaler);

#if defined(STM32_RCC_OSC_PLL2)
    rcc_set_pll2_multiplication_factor(config->pll2mul);
    rcc_osc_enable(RCC_OSC_PLL2);
    rcc_osc_ready_wait(RCC_OSC_PLL2);
#endif

#if defined(STM32_RCC_OSC_PLL3)
    rcc_set_pll3_multiplication_factor(config->pll3mul);
    rcc_osc_enable(RCC_OSC_PLL3);
    rcc_osc_ready_wait(RCC_OSC_PLL3);
#endif
  }
#endif

  /*
   * The pretch buffer must be kept on when using a prescaler
   * different from 1 on the AHB clock.
   */
  if (config->ahb_prescaler > RCC_AHB_PRESCALER_1)
  {
    // flash_prefetch_buffer_enable();
  }

  rcc_set_ahb_prescaler(config->ahb_prescaler);
  rcc_set_apb1_prescaler(config->apb1_prescaler);

#if defined(STM32_RCC_PPRE2)
  rcc_set_apb2_prescaler(config->apb2_prescaler);
#endif

#if defined(STM32_RCC_ADCPRE)
  rcc_set_adc_prescaler(config->adc_prescaler);
#endif

  flash_set_wait_state(config->flash_wait_state);

  switch (config->sysclock)
  {
    case RCC_SYSCLOCK_HSI:
      rcc_set_sysclock_source(config->sysclock);
      while (rcc_get_sysclock_status_raw() != RCC_CFGR_SWS_HSI);
      break;

    case RCC_SYSCLOCK_HSE:
      rcc_set_sysclock_source(config->sysclock);
      while (rcc_get_sysclock_status_raw() != RCC_CFGR_SWS_HSE);
      break;

    case RCC_SYSCLOCK_PLL:
      rcc_set_pll_source(config->pll_source);

      rcc_set_pll_multiplication_factor(config->pllmul);

      if (config->is_connectivity_device)
      {
#if defined(STM32_RCC_PREDIV1)
        rcc_set_prediv1_prescaler(config->prediv1_prescaler);
#endif
      }
      else
      {
        rcc_set_pll_hse_prescaler(config->pllxtpre);
      }

      rcc_osc_enable(RCC_OSC_PLL);
      rcc_osc_ready_wait(RCC_OSC_PLL);
      rcc_set_sysclock_source(config->sysclock);

      // Would be stuck forever when running tests.
      #ifndef NEX_BUILD_TESTS
      while (rcc_get_sysclock_status_raw() != RCC_CFGR_SWS_PLL);
      #endif
      break;
  }

  rcc_set_microcontroller_clock_output(config->mco);

  apb2_clock = config->apb2_clock_freq;
  apb1_clock = config->apb1_clock_freq;
  ahb_clock = config->ahb_prescaler;
  sysclock = config->sysclock_freq;
}

void
rcc_osc_enable(
  enum rcc_osc osc
)
{
  switch (osc)
  {
    case RCC_OSC_PLL:
      RCC->CR |= RCC_CR_PLLON;
      break;

    case RCC_OSC_HSE:
      RCC->CR |= RCC_CR_HSEON;
      break;

    case RCC_OSC_HSI:
      RCC->CR |= RCC_CR_HSION;
      break;

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_OSC_PLL2:
      RCC->CR |= RCC_CR_PLL2ON;
      break;
#elif defined(STM32_RCC_OSC_HSI14)
    case RCC_OSC_HSI14:
      RCC->CR2 |= RCC_CR2_HSI14ON;
      break;
#endif

#if defined(STM32_RCC_OSC_PLL3)
    case RCC_OSC_PLL3:
      RCC->CR |= RCC_CR_PLL3ON;
      break;
#elif defined(STM32_RCC_OSC_HSI48)
    case RCC_OSC_HSI48:
      RCC->CR2 |= RCC_CR2_HSI48;
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
    case RCC_OSC_PLL:
      RCC->CR &= ~RCC_CR_PLLON; 
      break;

    case RCC_OSC_HSI:
      RCC->CR &= ~RCC_CR_HSION;
      break;

    case RCC_OSC_HSE:
      RCC->CR &= ~RCC_CR_HSEON;
      break;

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_OSC_PLL2:
      RCC->CR &= ~RCC_CR_PLL2ON;
      break;
#endif

#if defined(STM32_RCC_OSC_PLL3)
    case RCC_OSC_PLL3:
      RCC->CR &= ~RCC_CR_PLL3ON;
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
rcc_osc_is_ready(
  enum rcc_osc osc
)
{
  switch (osc)
  {
    case RCC_OSC_PLL:
      return RCC->CR & RCC_CR_PLLRDY;

    case RCC_OSC_HSE:
      return RCC->CR & RCC_CR_HSERDY;

    case RCC_OSC_HSI:
      return RCC->CR & RCC_CR_HSIRDY;

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_OSC_PLL2:
      return RCC->CR & RCC_CR_PLL2RDY;
#elif defined(STM32_RCC_OSC_HSI14)
    case RCC_OSC_HSI14:
      return RCC->CR2 & RCC_CR2_HSI14RDY;
#endif

#if defined(STM32_RCC_OSC_PLL3)
    case RCC_OSC_PLL3:
      return RCC->CR & RCC_CR_PLL3RDY;
#elif defined(STM32_RCC_OSC_HSI48)
    case RCC_OSC_HSI48:
      return RCC->CR2 & RCC_CR2_HSI48RDY;
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
rcc_osc_ready_wait(
  enum rcc_osc osc
)
{
  // Tests would be stucked here.
  #if !defined(NEX_BUILD_TESTS)
  while (rcc_osc_is_ready(osc) == 0);
  #else
  (void) osc;
  #endif
}

void
rcc_set_hsi_trim(
  u32 trim_value
)
{
  devmode_assert_lower_or_eq(trim_value, RCC_CR_HSITRIM_MASK);

  constexpr u32 shift = RCC_CR_HSITRIM_SHIFT;
  constexpr u32 mask = RCC_CR_HSITRIM_MASK << shift;
  volatile u32* reg = &RCC->CR;
  syn_set_register_bits(reg, mask, trim_value << shift);
}

u32
rcc_get_hsi_cal(void)
{
  constexpr u32 shift = RCC_CR_HSICAL_SHIFT;
  constexpr u32 mask = RCC_CR_HSICAL_MASK; 
  volatile u32* reg = &RCC->CR;
  return (*reg >> shift) & mask;
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

u32
rcc_hse_bypass_is_enabled(void)
{
  return RCC->CR & RCC_CR_HSEBYP;
}

void
rcc_clock_security_system_enable(void)
{
  RCC->CR |= RCC_CR_CSSON;
}

void
rcc_clock_security_system_disable(void)
{
  RCC->CR &= ~RCC_CR_CSSON;
}

u32
rcc_clock_security_system_is_enabled(void)
{
  return RCC->CR & RCC_CR_CSSON;
}

void
rcc_set_sysclock_source(
  enum rcc_sysclock clock
)
{
  constexpr u32 shift = RCC_CFGR_SW_SHIFT;
  constexpr u32 mask = RCC_CFGR_SW_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (clock)
  {
    case RCC_SYSCLOCK_HSI:
      *reg &= ~mask;
      break;

    case RCC_SYSCLOCK_HSE:
      syn_set_register_bits(reg, mask, RCC_CFGR_SW_HSE << shift);
      break;

    case RCC_SYSCLOCK_PLL:
      syn_set_register_bits(reg, mask, RCC_CFGR_SW_PLL << shift);
      break;

#if defined(STM32_RCC_OSC_HSI48)
    case RCC_SYSCLOCK_HSI48:
      syn_set_register_bits(reg, mask, RCC_CFGR_SW_HSI48 << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_sysclock, clock);
      return;
  }
}

u32
rcc_get_sysclock_status_raw(void)
{
  constexpr u32 shift = RCC_CFGR_SWS_SHIFT;
  constexpr u32 mask = RCC_CFGR_SWS_MASK; 
  volatile u32* reg = &RCC->CFGR;
  return (*reg >> shift) & mask;
}

u32
rcc_get_sysclock_status(void)
{
  u32 value = rcc_get_sysclock_status_raw();
  switch (value)
  {
    case RCC_CFGR_SW_HSI:
      return RCC_SYSCLOCK_HSI;

    case RCC_CFGR_SW_HSE:
      return RCC_SYSCLOCK_HSE;

    case RCC_CFGR_SW_PLL:
      return RCC_SYSCLOCK_PLL;

    default:
      devmode_error("Invalid value read: %u\n", (ttype) value);
      return 0;
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
    case RCC_AHB_PRESCALER_1:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_NODIV << shift);
      break;

    case RCC_AHB_PRESCALER_2:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV2 << shift);
      break;

    case RCC_AHB_PRESCALER_4:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV4 << shift);
      break;

    case RCC_AHB_PRESCALER_8:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV8 << shift);
      break;

    case RCC_AHB_PRESCALER_16:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV16 << shift);
      break;

    case RCC_AHB_PRESCALER_64:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV64 << shift);
      break;

    case RCC_AHB_PRESCALER_128:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV128 << shift);
      break;

    case RCC_AHB_PRESCALER_256:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV256 << shift);
      break;

    case RCC_AHB_PRESCALER_512:
      syn_set_register_bits(reg, mask, RCC_CFGR_HPRE_DIV512 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_ahb_prescaler, prescaler);
      break;
  }
}

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
    case RCC_APB1_PRESCALER_1:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_NODIV << shift);
      break;

    case RCC_APB1_PRESCALER_2:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV2 << shift);
      break;

    case RCC_APB1_PRESCALER_4:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV4 << shift);
      break;

    case RCC_APB1_PRESCALER_8:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV8 << shift);
      break;

    case RCC_APB1_PRESCALER_16:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE1_DIV16 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_apb1_prescaler, prescaler);
      break;
  }
}

#if defined(STM32_RCC_PPRE2)
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
    case RCC_APB2_PRESCALER_1:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_NODIV << shift);
      break;

    case RCC_APB2_PRESCALER_2:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV2 << shift);
      break;

    case RCC_APB2_PRESCALER_4:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV4 << shift);
      break;

    case RCC_APB2_PRESCALER_8:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV8 << shift);
      break;

    case RCC_APB2_PRESCALER_16:
      syn_set_register_bits(reg, mask, RCC_CFGR_PPRE2_DIV16 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_apb2_prescaler, prescaler);
      break;
  }
}
#endif

#if defined(STM32_RCC_ADCPRE)
void
rcc_set_adc_prescaler(
  enum rcc_adc_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR_ADCPRE_SHIFT;
  constexpr u32 mask = RCC_CFGR_ADCPRE_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (prescaler)
  {
    case RCC_ADC_PRESCALER_2:
      syn_set_register_bits(reg, mask, RCC_CFGR_ADCPRE_DIV2 << shift);
      break;

    case RCC_ADC_PRESCALER_4:
      syn_set_register_bits(reg, mask, RCC_CFGR_ADCPRE_DIV4 << shift);
      break;

    case RCC_ADC_PRESCALER_6:
      syn_set_register_bits(reg, mask, RCC_CFGR_ADCPRE_DIV6 << shift);
      break;

    case RCC_ADC_PRESCALER_8:
      syn_set_register_bits(reg, mask, RCC_CFGR_ADCPRE_DIV8 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_adc_prescaler, prescaler);
      break;
  }
}
#endif

#if defined(STM32_RCC_PLLSRC_2BIT)
void
rcc_set_pll_source(
  enum rcc_pll_source source
)
{
  constexpr u32 shift = RCC_CFGR_PLLSRC_SHIFT;
  constexpr u32 mask = RCC_CFGR_PLLSRC_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (source)
  {
    case RCC_PLL_SOURCE_HSI_DIV2:
      *reg &= ~mask;
      break;

    case RCC_PLL_SOURCE_HSI_PREDIV:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLSRC_HSI_PREDIV << shift);
      break;

    case RCC_PLL_SOURCE_HSE_PREDIV:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLSRC_HSE_PREDIV << shift);
      break;

    case RCC_PLL_SOURCE_HSI48:
      *reg |= (RCC_CFGR_PLLSRC_HSI48 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_pll_source, source);
      break;
  }
}
#else
void
rcc_set_pll_source(
  enum rcc_pll_source source
)
{
  switch (source)
  {
    case RCC_PLL_SOURCE_HSI:
      RCC->CFGR &= ~RCC_CFGR_PLLSRC;
      break;

    /* Connectivity devices only */
    case RCC_PLL_SOURCE_PREDIV1:

    /* Density devices only */
    case RCC_PLL_SOURCE_HSE:
      RCC->CFGR |= RCC_CFGR_PLLSRC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_pll_source, source);
      break;
  }
}
#endif

void
rcc_set_pll_hse_prescaler(
  enum rcc_pll_hse_prescaler prescaler
)
{
  switch (prescaler)
  {
    case RCC_PLL_HSE_PRESCALER_NODIV:
      RCC->CFGR &= ~RCC_CFGR_PLLXTPRE;
      break;

    case RCC_PLL_HSE_PRESCALER_DIV2:
      RCC->CFGR |= RCC_CFGR_PLLXTPRE;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_pll_hse_prescaler, prescaler);
      break;
  }
}

void
rcc_set_pll_multiplication_factor(
  enum rcc_pll_multiplication_factor factor
)
{
  constexpr u32 shift = RCC_CFGR_PLLMUL_SHIFT;
  constexpr u32 mask = RCC_CFGR_PLLMUL_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (factor)
  {
#if defined(STM32_RCC_PLLMUL_LAYOUT2)
    case RCC_PLL_MULTIPLICATION_FACTOR_2:
      *reg &= ~mask;
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_3:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL3 << shift);
      break;
#endif

    case RCC_PLL_MULTIPLICATION_FACTOR_4:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL4 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_5:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL5 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_6:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL6 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_7:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL7 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_8:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL8 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_9:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL9 << shift);
      break;

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
    case RCC_PLL_MULTIPLICATION_FACTOR_10:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL10 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_11:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL11 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_12:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL12 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_13:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL13 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_14:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL14 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_15:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL15 << shift);
      break;

    case RCC_PLL_MULTIPLICATION_FACTOR_16:
      *reg |= (RCC_CFGR_PLLMUL16 << shift);
      break;
#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT1)
    case RCC_PLL_MULTIPLICATION_FACTOR_6dot5:
      syn_set_register_bits(reg, mask, RCC_CFGR_PLLMUL6DOT5 << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_pll_multiplication_factor, factor);
      break;
  }
}

#if defined(STM32_RCC_OTGFS)
void
rcc_set_usb_otg_fs_prescaler(
  enum rcc_usb_otg_fs_prescaler prescaler
)
{
  switch (prescaler)
  {
    case RCC_USB_OTG_FS_PRESCALER_2:
      RCC->CFGR |= RCC_CFGR_OTGFSPRE;
      break;

    case RCC_USB_OTG_FS_PRESCALER_3:
      RCC->CFGR &= ~RCC_CFGR_OTGFSPRE;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_usb_otg_fs_prescaler, prescaler);
      break;
  }
}
#endif

void
rcc_set_microcontroller_clock_output(
  enum rcc_microntroller_clock_output output
)
{
  constexpr u32 shift = RCC_CFGR_MCO_SHIFT;
  constexpr u32 mask = RCC_CFGR_MCO_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (output)
  {
    case RCC_MCO_NO_OUTPUT:
      *reg &= ~mask;
      break;

#if defined(STM32_RCC_EXTENDED_REGS)
    case RCC_MCO_HSI14:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_HSI14 << shift);
      break;

    case RCC_MCO_LSI:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_LSI << shift);
      break;

    case RCC_MCO_LSE:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_LSE << shift);
      break;
#endif

    case RCC_MCO_SYSCLOCK:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_SYSCLK << shift);
      break;

    case RCC_MCO_HSI:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_HSICLK << shift);
      break;

    case RCC_MCO_HSE:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_HSECLK << shift);
      break;

    case RCC_MCO_PLL:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_PLLCLK_DIV2 << shift);
      break;

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_MCO_PLL2:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_PLL2CLK << shift);
      break;
#endif

#if defined(STM32_RCC_OSC_PLL3)
    case RCC_MCO_PLL3_DIV2:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_PLL3CLK_DIV2 << shift);
      break;
#endif

#if defined(STM32_MCO_XT1)
    case RCC_MCO_XT1:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_XT1CLK << shift);
      break;
#endif

#if defined(STM32_RCC_OSC_PLL3)
    case RCC_MCO_PLL3:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCO_PLL3CLK << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_microntroller_clock_output, output);
      break;
  }
}

#if defined(STM32_RCC_MCOPRE)
void
rcc_set_mco_prescaler(
  enum rcc_mco_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR_MCOPRE_SHIFT;
  constexpr u32 mask = RCC_CFGR_MCOPRE_MASK << shift;
  volatile u32* reg = &RCC->CFGR;

  switch (prescaler)
  {
    case RCC_MCO_PRESCALER_DIV1:
      *reg &= ~mask;
      break;

    case RCC_MCO_PRESCALER_DIV2:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCOPRE_DIV2 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV4:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCOPRE_DIV4 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV8:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCOPRE_DIV8 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV16:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCOPRE_DIV16 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV32:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCOPRE_DIV32 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV64:
      syn_set_register_bits(reg, mask, RCC_CFGR_MCOPRE_DIV64 << shift);
      break;

    case RCC_MCO_PRESCALER_DIV128:
      *reg |= (RCC_CFGR_MCOPRE_DIV128 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_mco_prescaler, prescaler);
      break;
  }
}
#endif

#if defined(STM32_RCC_PLLNODIV)
void
rcc_set_mco_pll_prescaler(
  enum mco_pll_prescaler prescaler
)
{
  volatile u32* reg = &RCC->CFGR; 
  switch (prescaler)
  {
    case MCO_PLL_PRESCALER_NODIV:
      *reg &= ~RCC_CFGR_PLLNODIV;
      break;

    case MCO_PLL_PRESCALER_DIV2:
      *reg |= RCC_CFGR_PLLNODIV;
      break;

    default:
      devmode_error_invalid_enum(enum mco_pll_prescaler, prescaler);
      break;
  }
}
#endif

u32
rcc_is_interrupt_flag_set(
  enum rcc_interrupt interrupt
)
{
  switch (interrupt)
  {
    case RCC_INTERRUPT_LSI:
      return RCC->CIR & RCC_CIR_LSIRDYF;

    case RCC_INTERRUPT_LSE:
      return RCC->CIR & RCC_CIR_LSERDYF;

    case RCC_INTERRUPT_HSI:
      return RCC->CIR & RCC_CIR_HSIRDYF;

    case RCC_INTERRUPT_HSE:
      return RCC->CIR & RCC_CIR_HSERDYF;

    case RCC_INTERRUPT_PLL:
      return RCC->CIR & RCC_CIR_PLLRDYF;

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_INTERRUPT_PLL2:
      return RCC->CIR & RCC_CIR_PLL2RDYF;
#endif

#if defined(STM32_RCC_OSC_HSI14)
    case RCC_INTERRUPT_HSI14:
      return RCC->CIR & RCC_CIR_HSI14RDYF;
#endif
    
#if defined(STM32_RCC_OSC_PLL2)
    case RCC_INTERRUPT_PLL3:
      return RCC->CIR & RCC_CIR_PLL3RDYF;
#endif

#if defined(STM32_RCC_OSC_HSI48)
    case RCC_INTRRUPT_HSI48:
      return RCC->CIR & RCC_CIR_HSI48RDYF;
#endif

    case RCC_INTERRUPT_CSS:
      return RCC->CIR & RCC_CIR_CSSF;

    default:
      devmode_error_invalid_enum(enum rcc_interrupt, interrupt);
      return 0;
  }
}

void
rcc_interrupt_enable(
  enum rcc_interrupt interrupt
)
{
  switch (interrupt)
  {
    case RCC_INTERRUPT_LSI:
      RCC->CIR |= RCC_CIR_LSIRDYIE;
      break;

    case RCC_INTERRUPT_LSE:
      RCC->CIR |= RCC_CIR_LSERDYIE;
      break;

    case RCC_INTERRUPT_HSI:
      RCC->CIR |= RCC_CIR_HSIRDYIE;
      break;

    case RCC_INTERRUPT_HSE:
      RCC->CIR |= RCC_CIR_HSERDYIE;
      break;

    case RCC_INTERRUPT_PLL:
      RCC->CIR |= RCC_CIR_PLLRDYIE;
      break;

#if defined(STM32_RCC_OSC_HSI14)
    CASE RCC_INTERRUPT_HSI14:
      RCC->CIR |= RCC_CIR_HSI14RDYIE;
      break;
#endif

#if defined(STM32_RCC_OSC_HSI48)
    case RCC_INTERRUPT_HSI48:
      RCC->CIR |= RCC_CIR_HSI48RDYIE;
      break;
#endif

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_INTERRUPT_PLL2:
      RCC->CIR |= RCC_CIR_PLL2RDYIE;
      break;
#endif
    
#if defined(STM32_RCC_OSC_PLL3)
    case RCC_INTERRUPT_PLL3:
      RCC->CIR |= RCC_CIR_PLL3RDYIE;
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
  switch (interrupt)
  {
    case RCC_INTERRUPT_LSI:
      RCC->CIR &= ~RCC_CIR_LSIRDYIE;
      break;

    case RCC_INTERRUPT_LSE:
      RCC->CIR &= ~RCC_CIR_LSERDYIE;
      break;

    case RCC_INTERRUPT_HSI:
      RCC->CIR &= ~RCC_CIR_HSIRDYIE;
      break;

    case RCC_INTERRUPT_HSE:
      RCC->CIR &= ~RCC_CIR_HSERDYIE;
      break;

    case RCC_INTERRUPT_PLL:
      RCC->CIR &= ~RCC_CIR_PLLRDYIE;
      break;

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_INTERRUPT_PLL2:
      RCC->CIR &= ~RCC_CIR_PLL2RDYIE;
      break;
#elif defined(STM32_RCC_OSC_HSI14)
    case RCC_INTERRUPT_HSI14:
      RCC->CIR &= ~RCC_CIR_HSI14RDYIE;
      break;
#endif
    
#if defined(STM32_RCC_OSC_PLL3)
    case RCC_INTERRUPT_PLL3:
      RCC->CIR &= ~RCC_CIR_PLL3RDYIE;
      break;
#elif defined(STM32_RCC_OSC_HSI48)
    case RCC_INTERRUPT_HSI48:
      RCC->CIR &= ~RCC_CIR_HSI48RDYIE;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum rcc_interrupt, interrupt);
      break;
  }
}

void
rcc_interrupt_flag_clear(
  enum rcc_interrupt interrupt
)
{
  switch (interrupt)
  {
    case RCC_INTERRUPT_LSI:
      RCC->CIR |= RCC_CIR_LSIRDYC;
      break;

    case RCC_INTERRUPT_LSE:
      RCC->CIR |= RCC_CIR_LSERDYC;
      break;

    case RCC_INTERRUPT_HSI:
      RCC->CIR |= RCC_CIR_HSIRDYC;
      break;

    case RCC_INTERRUPT_HSE:
      RCC->CIR |= RCC_CIR_HSERDYC;
      break;

    case RCC_INTERRUPT_PLL:
      RCC->CIR |= RCC_CIR_PLLRDYC;
      break;

#if defined(STM32_RCC_OSC_HSI14)
    case RCC_INTERRUPT_HSI14:
      RCC->CIR |= RCC_CIR_HSI14RDYC;
      break;
#endif

#if defined(STM32_RCC_OSC_PLL2)
    case RCC_INTERRUPT_PLL2:
      RCC->CIR |= RCC_CIR_PLL2RDYC;
      break;
#elif defined(STM32_RCC_OSC_HSI14)
    case RCC_INTERRUPT_HSI14:
      RCC->CIR |= RCC_CIR_HSI14RDYC;
      break;
#endif
    
#if defined(STM32_RCC_OSC_PLL3)
    case RCC_INTERRUPT_PLL3:
      RCC->CIR |= RCC_CIR_PLL3RDYC;
      break;
#elif defined(STM32_RCC_OSC_HSI48)
    case RCC_INTERRUPT_HSI48:
      RCC->CIR |= RCC_CIR_HSI48RDYC;
      break;
#endif

    case RCC_INTERRUPT_CSS:
      RCC->CIR |= RCC_CIR_CSSC;
      break;

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
#if defined(STM32_RCC_OTGFS)
    case RCC_PERIPH_OTGFS:
      RCC->AHBRSTR |= RCC_AHBRSTR_OTGFSRST;
      break;
#endif

#if defined(STM32_ETH)
    case RCC_PERIPH_ETHMAC:
      RCC->AHBRSTR |= RCC_AHBRSTR_ETHMACRST;
      break;
#endif

#if defined(STM32_RCC_SYSCFG)
    case RCC_PERIPH_SYSCFG:
      RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST;
      break;
#elif defined(STM32_RCC_AFIO)
    case RCC_PERIPH_AFIO:
      RCC->APB2RSTR |= RCC_APB2RSTR_AFIORST;
      break;
#endif

#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
#if defined(STM32_GPIO_RST_AHB)
      RCC->AHBRSTR |= RCC_AHBRSTR_GPIOARST;
#else
      RCC->APB2RSTR |= RCC_APB2RSTR_IOPARST;
#endif
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
#if defined(STM32_GPIO_RST_AHB)
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOBRST;
#else
      RCC->APB2RSTR |= RCC_APB2RSTR_IOPBRST;
#endif
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
#if defined(STM32_GPIO_RST_AHB)
      RCC->AHBENR |= RCC_AHBENR_GPIOCRST;
#else
      RCC->APB2RSTR |= RCC_APB2RSTR_IOPCRST;
#endif
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
#if defined(STM32_GPIO_RST_AHB)
      RCC->AHBENR |= RCC_AHBENR_GPIODRST;
#else
      RCC->APB2RSTR |= RCC_APB2RSTR_IOPDRST;
#endif
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
#if defined(STM32_GPIO_RST_AHB)
      RCC->AHBENR |= RCC_AHBENR_GPIOERST;
#else
      RCC->APB2RSTR |= RCC_APB2RSTR_IOPERST;
#endif
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
#if defined(STM32_GPIO_RST_AHB)
      RCC->AHBENR |= RCC_AHBENR_GPIOFRST;
#else
      RCC->APB2RSTR |= RCC_APB2RSTR_IOPFRST;
#endif
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
#if defined(STM32_GPIO_RST_AHB)
      RCC->AHBENR |= RCC_AHBENR_GPIOGRST;
#else
      RCC->APB2RSTR |= RCC_APB2RSTR_IOPFRST;
#endif
      break;
#endif

#if defined(STM32_TSC)
    case RCC_PERIPH_TSC:
      RCC->AHBRSTR |= RCC_AHBRSTR_TSCRST;
      break;
#endif

#if defined(STM32_USART6)
    case RCC_PERIPH_USART6:
      RCC->APB2RSTR |= RCC_APB2RSTR_USART6;
      break;
#endif

#if defined(STM32_USART7)
    case RCC_PERIPH_USART7:
      RCC->APB2RSTR |= RCC_APB2RSTR_USART7;
      break;
#endif

#if defined(STM32_USART8)
    case RCC_PERIPH_USART8:
      RCC->APB2RSTR |= RCC_APB2RSTR_USART8;
      break;
#endif

    case RCC_PERIPH_ADC1:
      RCC->APB2RSTR |= RCC_APB2RSTR_ADC1RST;
      break;

#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
      RCC->APB2RSTR |= RCC_APB2RSTR_ADC2RST;
      break;
#endif

    case RCC_PERIPH_TIM1:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST;
      break;

    case RCC_PERIPH_SPI1:
      RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST;
      break;

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM8RST;
      break;
#endif

    case RCC_PERIPH_USART1:
      RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
      break;

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
      RCC->APB2RSTR |= RCC_APB2RSTR_ADC3RST;
      break;
#endif

#if defined(STM32_TIM9)
    case RCC_PERIPH_TIM9:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM9RST;
      break;
#endif

#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM10RST;
      break;
#endif

#if defined(STM32_TIM11)
    case RCC_PERIPH_TIM11:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM11RST;
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

#if defined(STM32_TIM15)
    case RCC_PERIPH_TIM15:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM15RST;
      break;
#endif

#if defined(STM32_TIM16)
    case RCC_PERIPH_TIM16:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM16RST;
      break;
#endif

#if defined(STM32_TIM17)
    case RCC_PERIPH_TIM17:
      RCC->APB2RSTR |= RCC_APB2RSTR_TIM17RST;
      break;
#endif

#if defined(STM32_DBGMCU)
    case RCC_PERIPH_DBGMCU:
      RCC->APB2RSTR |= RCC_APB2RSTR_DBGMCURSTR;
      break;
#endif

    case RCC_PERIPH_WWDG:
      RCC->APB1RSTR |= RCC_APB1RSTR_WWDGRST;
      break;

#if defined(STM32_SPI2)
    case RCC_PERIPH_SPI2:
      RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST;
      break;
#endif

#if defined(STM32_SPI3)
    case RCC_PERIPH_SPI3:
      RCC->APB1RSTR |= RCC_APB1RSTR_SPI3RST;
      break;
#endif

#if defined(STM32_USART2)
    case RCC_PERIPH_USART2:
      RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
      break;
#endif

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

#if defined(STM32_UART4)
    case RCC_PERIPH_UART5:
      RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST;
      break;
#endif

#if defined(STM32_I2C1)
    case RCC_PERIPH_I2C1:
      RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST;
      break;
#endif

#if defined(STM32_I2C2)
    case RCC_PERIPH_I2C2:
      RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST;
      break;
#endif

#if defined(STM32_USB)
    case RCC_PERIPH_USB:
      RCC->APB2RSTR |= RCC_APB1RSTR_USBRST;
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

#if defined(STM32_BKP)
    case RCC_PERIPH_BKP:
      RCC->APB1RSTR |= RCC_APB1RSTR_BKPRST;
      break;
#endif

#if defined(STM32_CRS)
    case RCC_PERIPH_CRS:
      RCC->APB1RSTR |= RCC_APB1RSTR_CRSRST;
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

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1RSTR |= RCC_APB1RSTR_CECRST;
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
    case RCC_PERIPH_DMA1:
      RCC->AHBENR |= RCC_AHBENR_DMA1EN;
      break;

#if defined(STM32_DMA2)
    case RCC_PERIPH_DMA2:
      RCC->AHBENR |= RCC_AHBENR_DMA2EN;
      break;
#endif

    case RCC_PERIPH_SRAM:
      RCC->AHBENR |= RCC_AHBENR_SRAMEN;
      break;

    case RCC_PERIPH_FLITF:
      RCC->AHBENR |= RCC_AHBENR_FLITFEN;
      break;

    case RCC_PERIPH_CRC:
      RCC->AHBENR |= RCC_AHBENR_CRCEN;
      break;

#if defined(STM32_TSC)
    case RCC_PERIPH_TSC:
      RCC->AHBENR |= RCC_AHBENR_TSCEN;
      break;
#endif

#if defined(STM32_FSMC)
    case RCC_PERIPH_FSMC:
      RCC->AHBENR |= RCC_AHBENR_FSMCEN;
      break;
#endif

#if defined(STM32_SDIO)
    case RCC_PERIPH_SDIO:
      RCC->AHBENR |= RCC_AHBENR_SDIOEN;
      break;
#endif

#if defined(STM32_RCC_OTGFS)
    case RCC_PERIPH_OTGFS:
      RCC->AHBENR |= RCC_AHBENR_OTGFSEN;
      break;
#endif

#if defined(STM32_ETH)
    case RCC_PERIPH_ETHMAC:
      RCC->AHBENR |= RCC_AHBENR_ETHMACEN;
      break;

    case RCC_PERIPH_ETHMACTX:
      RCC->AHBENR |= RCC_AHBENR_ETHMACTXEN;
      break;

    case RCC_PERIPH_ETHMACRX:
      RCC->AHBENR |= RCC_AHBENR_ETHMACRXEN;
      break;
#endif

#if defined(STM32_RCC_SYSCFG)
    case RCC_PERIPH_SYSCFG:
      RCC->APB2ENR |= RCC_APB22ENR_SYSCFGCOMPEN;
      break;
#elif defined(STM32_RCC_AFIO)
    case RCC_PERIPH_AFIO:
      RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
      break;
#endif

#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
#else
      RCC->AHBENR |= RCC_AHBENR_IOPAEN;
#endif
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
#else
      RCC->AHBENR |= RCC_AHBENR_IOPBEN;
#endif
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
#else
      RCC->AHBENR |= RCC_AHBENR_IOPCEN;
#endif
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
#else
      RCC->AHBENR |= RCC_AHBENR_IOPDEN;
#endif
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
#else
      RCC->AHBENR |= RCC_AHBENR_IOPEEN;
#endif
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
#else
      RCC->AHBENR |= RCC_AHBENR_IOPFEN;
#endif
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR |= RCC_APB2ENR_IOPGEN;
#else
      RCC->AHBENR |= RCC_AHBENR_IOPGEN;
#endif
      break;
#endif

#if defined(STM32_ADC1)
    case RCC_PERIPH_ADC1:
      RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
      break;
#endif

#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
      RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
      break;
#endif

#if defined(STM32_TIM1)
    case RCC_PERIPH_TIM1:
      RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
      break;
#endif

#if defined(STM32_SPI1)
    case RCC_PERIPH_SPI1:
      RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
      break;
#endif

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
      break;
#endif

#if defined(STM32_USART1)
    case RCC_PERIPH_USART1:
      RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
      break;
#endif

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
      RCC->APB2ENR |= RCC_APB2ENR_ADC3EN;
      break;
#endif

#if defined(STM32_TIM9)
    case RCC_PERIPH_TIM9:
      RCC->APB2ENR |= RCC_APB2ENR_TIM9EN; 
      break;
#endif

#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2ENR |= RCC_APB2ENR_TIM10EN; 
      break;
#endif

#if defined(STM32_TIM11)
    case RCC_PERIPH_TIM11:
      RCC->APB2ENR |= RCC_APB2ENR_TIM11EN; 
      break;
#endif

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

#if defined(STM32_TIM15)
    case RCC_PERIPH_TIM15:
      RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;
      break;
#endif

#if defined(STM32_TIM16)
    case RCC_PERIPH_TIM16:
      RCC->APB2ENR |= RCC_APB2ENR_TIM16EN;
      break;
#endif

#if defined(STM32_TIM17)
    case RCC_PERIPH_TIM17:
      RCC->APB2ENR |= RCC_APB2ENR_TIM17EN;
      break;
#endif

#if defined(STM32_DBGMCU)
    case RCC_PERIPH_DBGMCU:
      RCC->APB2ENR |= RCC_APB2ENR_DBGMCUENR;
      break;
#endif

    case RCC_PERIPH_WWDG:
      RCC->APB1ENR |= RCC_APB1ENR_WWDGEN;
      break;

#if defined(STM32_SPI2)
    case RCC_PERIPH_SPI2:
      RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
      break;
#endif

#if defined(STM32_SPI3)
    case RCC_PERIPH_SPI3:
      RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
      break;
#endif

#if defined(STM32_USART2)
    case RCC_PERIPH_USART2:
      RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
      break;
#endif

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

#if defined(STM32_I2C1)
    case RCC_PERIPH_I2C1:
      RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
      break;
#endif

#if defined(STM32_I2C2)
    case RCC_PERIPH_I2C2:
      RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
      break;
#endif

#if defined(STM32_USB)
    case RCC_PERIPH_USB:
      RCC->APB1ENR |= RCC_APB1ENR_USBEN;
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

#if defined(STM32_CRS)
    case RCC_PERIPH_CRS:
      RCC->APB1ENR |= RCC_APB1ENR_CRSEN;
      break;
#endif

#if defined(STM32_BKP)
    case RCC_PERIPH_BKP:
      RCC->APB1ENR |= RCC_APB1ENR_BKPEN;
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

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1ENR |= RCC_APB1ENR_CECEN;
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
    case RCC_PERIPH_DMA1:
      RCC->AHBENR &= ~RCC_AHBENR_DMA1EN;
      break;

#if defined(STM32_DMA2)
    case RCC_PERIPH_DMA2:
      RCC->AHBENR &= ~RCC_AHBENR_DMA2EN;
      break;
#endif

    case RCC_PERIPH_SRAM:
      RCC->AHBENR &= ~RCC_AHBENR_SRAMEN;
      break;

    case RCC_PERIPH_FLITF:
      RCC->AHBENR &= ~RCC_AHBENR_FLITFEN;
      break;

    case RCC_PERIPH_CRC:
      RCC->AHBENR &= ~RCC_AHBENR_CRCEN;
      break;

#if defined(STM32_RCC_OTGFS)
    case RCC_PERIPH_OTGFS:
      RCC->AHBENR &= ~RCC_AHBENR_OTGFSEN;
      break;
#endif

#if defined(STM32_ETH)
    case RCC_PERIPH_ETHMAC:
      RCC->AHBENR &= ~RCC_AHBENR_ETHMACEN;
      break;

    case RCC_PERIPH_ETHMACTX:
      RCC->AHBENR &= ~RCC_AHBENR_ETHMACTXEN;
      break;

    case RCC_PERIPH_ETHMACRX:
      RCC->AHBENR &= ~RCC_AHBENR_ETHMACRXEN;
      break;
#endif

    case RCC_PERIPH_AFIO:
      RCC->APB2ENR &= ~RCC_APB2ENR_AFIOEN;
      break;

#if defined(STM32_GPIOA)
    case RCC_PERIPH_GPIOA:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR &= ~RCC_APB2ENR_IOPAEN;
#else
      RCC->AHBENR &= ~RCC_AHBENR_IOPAEN;
#endif
      break;
#endif

#if defined(STM32_GPIOB)
    case RCC_PERIPH_GPIOB:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR &= ~RCC_APB2ENR_IOPBEN;
#else
      RCC->AHBENR &= ~RCC_AHBENR_IOPBEN;
#endif
      break;
#endif

#if defined(STM32_GPIOC)
    case RCC_PERIPH_GPIOC:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR &= ~RCC_APB2ENR_IOPCEN;
#else
      RCC->AHBENR &= ~RCC_AHBENR_IOPAEN;
#endif
      break;
#endif

#if defined(STM32_GPIOD)
    case RCC_PERIPH_GPIOD:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR &= ~RCC_APB2ENR_IOPDEN;
#else
      RCC->AHBENR &= ~RCC_AHBENR_IOPDEN;
#endif
      break;
#endif

#if defined(STM32_GPIOE)
    case RCC_PERIPH_GPIOE:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR &= ~RCC_APB2ENR_IOPEEN;
#else
      RCC->AHBENR &= ~RCC_AHBENR_IOPEEN;
#endif
      break;
#endif

#if defined(STM32_GPIOF)
    case RCC_PERIPH_GPIOF:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR &= ~RCC_APB2ENR_IOPFEN;
#else
      RCC->AHBENR &= ~RCC_AHBENR_IOPFEN;
#endif
      break;
#endif

#if defined(STM32_GPIOG)
    case RCC_PERIPH_GPIOG:
#if defined(STM32_RCC_APB2_GPIO)
      RCC->APB2ENR &= ~RCC_APB2ENR_IOPGEN;
#else
      RCC->AHBENR &= ~RCC_AHBENR_IOPGEN;
#endif
      break;
#endif

#if defined(STM32_USART6)
    case RCC_PERIPH_USART6:
      RCC->APB1ENR &= ~RCC_PERIPH_USART6;
      break;
#endif

#if defined(STM32_USART7)
    case RCC_PERIPH_USART7:
      RCC->APB1ENR &= ~RCC_PERIPH_USART7;
      break;
#endif

#if defined(STM32_USART8)
    case RCC_PERIPH_USART8:
      RCC->APB1ENR &= ~RCC_PERIPH_USART8;
      break;
#endif

#if defined(STM32_ADC1)
    case RCC_PERIPH_ADC1:
      RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN;
      break;
#endif

#if defined(STM32_ADC2)
    case RCC_PERIPH_ADC2:
      RCC->APB2ENR &= ~RCC_APB2ENR_ADC2EN;
      break;
#endif

#if defined(STM32_TIM1)
    case RCC_PERIPH_TIM1:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN;
      break;
#endif

#if defined(STM32_SPI1)
    case RCC_PERIPH_SPI1:
      RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN;
      break;
#endif

#if defined(STM32_TIM8)
    case RCC_PERIPH_TIM8:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN;
      break;
#endif

#if defined(STM32_USART1)
    case RCC_PERIPH_USART1:
      RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN;
      break;
#endif

#if defined(STM32_ADC3)
    case RCC_PERIPH_ADC3:
      RCC->APB2ENR &= ~RCC_APB2ENR_ADC3EN;
      break;
#endif

#if defined(STM32_TIM9)
    case RCC_PERIPH_TIM9:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM9EN;
      break;
#endif
      
#if defined(STM32_TIM10)
    case RCC_PERIPH_TIM10:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM10EN;
      break;
#endif

#if defined(STM32_TIM11)
    case RCC_PERIPH_TIM11:
      RCC->APB2ENR &= ~RCC_APB2ENR_TIM11EN;
      break;
#endif

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

    case RCC_PERIPH_WWDG:
      RCC->APB1ENR &= ~RCC_APB1ENR_WWDGEN;
      break;

#if defined(STM32_SPI2)
    case RCC_PERIPH_SPI2:
      RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN;
      break;
#endif

#if defined(STM32_SPI3)
    case RCC_PERIPH_SPI3:
      RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN;
      break;
#endif

#if defined(STM32_USART2)
    case RCC_PERIPH_USART2:
      RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN;
      break;
#endif

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

#if defined(STM32_I2C1)
    case RCC_PERIPH_I2C1:
      RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN;
      break;
#endif

#if defined(STM32_I2C2)
    case RCC_PERIPH_I2C2:
      RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN;
      break;
#endif

#if defined(STM32_USB)
    case RCC_PERIPH_USB:
      RCC->APB1ENR &= ~RCC_APB1ENR_USBEN;
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

#if defined(STM32_CRS)
    case RCC_PERIPH_CRS:
      RCC->APB1ENR &= ~RCC_APB1ENR_CRSEN;
      break;
#endif

#if defined(STM32_BKP)
    case RCC_PERIPH_BKP:
      RCC->APB1ENR &= ~RCC_APB1ENR_BKPEN;
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

#if defined(STM32_CEC)
    case RCC_PERIPH_CEC:
      RCC->APB1ENR &= ~RCC_PERIPH_CECEN;
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
rcc_backup_domain_reset(void)
{
  RCC->BDCR |= RCC_BDCR_BDRST;
  RCC->BDCR &= ~RCC_BDCR_BDRST;
}

void
rcc_set_rtc_source(
  enum rcc_rtc_source source
)
{
  constexpr u32 shift = RCC_BDCR_RTCSEL_SHIFT;
  constexpr u32 mask = RCC_BDCR_RTCSEL_MASK << shift;
  volatile u32* reg = &RCC->BDCR;

  switch (source)
  {
    case RCC_RTC_SOURCE_NOCLOCK:
      // RCC->BDCR |= (RCC_BDCR_RTCSEL_NOCLK << shift);
      syn_set_register_bits(reg, mask, RCC_BDCR_RTCSEL_NOCLK << shift);
      break;

    case RCC_RTC_SOURCE_LSE:
      // RCC->BDCR |= (RCC_BDCR_RTCSEL_LSE << shift);
      syn_set_register_bits(reg, mask, RCC_BDCR_RTCSEL_LSE << shift);
      break;

    case RCC_RTC_SOURCE_LSI:
      // RCC->BDCR |= (RCC_BDCR_RTCSEL_LSI << shift);
      syn_set_register_bits(reg, mask, RCC_BDCR_RTCSEL_LSI << shift);
      break;

    case RCC_RTC_SOURCE_HSE:
      // RCC->BDCR |= (RCC_BDCR_RTCSEL_HSE << shift);
      syn_set_register_bits(reg, mask, RCC_BDCR_RTCSEL_HSE << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_rtc_source, source);
      break;
  }
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

u32
rcc_lse_bypass_is_enabled(void)
{
  return RCC->BDCR & RCC_BDCR_LSEBYP;
}

u32
rcc_reset_is_flag_set(
  enum rcc_reset_flag flag
)
{
  switch (flag)
  {
#if defined(STM32_RCC_V1dot8V)
    case RCC_RESET_FLAG_V1dot8:
      return RCC->CSR & RCC_CSR_V18PWRRSTF;
#endif

#if defined(STM32_OPTION_BYTE_LOADER)
    case RCC_RESET_FLAG_OPTION_BYTE_LOADER:
      return RCC->CSR & RCC_CSR_OBLRSTF;
#endif

    case RCC_RESET_FLAG_PIN:
      return RCC->CSR & RCC_CSR_PINRSTF;

    case RCC_RESET_FLAG_POR_PDR:
      return RCC->CSR & RCC_CSR_PORRSTF;

    case RCC_RESET_FLAG_SOFTWARE:
      return RCC->CSR & RCC_CSR_SFTRSTF;

    case RCC_RESET_FLAG_INDEPENDENT_WATCHDOG:
      return RCC->CSR & RCC_CSR_IWDGRSTF;

    case RCC_RESET_FLAG_WINDOW_WATCHDOG:
      return RCC->CSR & RCC_CSR_WWDGRSTF;

    case RCC_RESET_FLAG_LOW_POWER:
      return RCC->CSR & RCC_CSR_LPWRRSTF;

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

#if defined(STM32_RCC_CFGR2)
void
rcc_set_prediv1_prescaler(
  enum rcc_prediv1_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR2_PREDIV1_SHIFT;
  constexpr u32 mask = RCC_CFGR2_PREDIV1_MASK << shift;
  volatile u32* reg = &RCC->CFGR2;

  switch (prescaler)
  {
    case RCC_PREDIV1_PRESCALER_1:
      *reg &= ~mask;
      break;

    case RCC_PREDIV1_PRESCALER_2:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV2 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_3:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV3 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_4:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV4 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_5:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV5 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_6:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV6 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_7:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV7 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_8:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV8 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_9:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV9 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_10:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV10 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_11:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV11 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_12:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV12 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_13:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV13 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_14:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV14 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_15:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV15 << shift);
      break;

    case RCC_PREDIV1_PRESCALER_16:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV1_DIV16 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_prediv1_prescaler, prescaler);
      break;
  }
}

#if defined(STM32_RCC_PREDIV2)
void
rcc_set_prediv2_prescaler(
enum rcc_prediv2_prescaler prescaler
)
{
  constexpr u32 shift = RCC_CFGR2_PREDIV2_SHIFT;
  constexpr u32 mask = RCC_CFGR2_PREDIV2_MASK << shift;
  volatile u32* reg = &RCC->CFGR2;

  switch (prescaler)
  {
    case RCC_PREDIV2_PRESCALER_1:
      *reg &= ~mask;
      break;

    case RCC_PREDIV2_PRESCALER_2:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV2 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_3:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV3 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_4:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV4 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_5:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV5 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_6:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV6 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_7:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV7 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_8:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV8 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_9:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV9 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_10:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV10 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_11:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV11 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_12:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV12 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_13:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV13 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_14:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV14 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_15:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PREDIV2_DIV15 << shift);
      break;

    case RCC_PREDIV2_PRESCALER_16:
      *reg |= (RCC_CFGR_PREDIV2_DIV16 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_prediv2_prescaler, prescaler);
      break;
  }
}
#endif

#if defined(STM32_RCC_OSC_PLL2)
void
rcc_set_pll2_multiplication_factor(
  enum rcc_pll2_multiplication_factor factor
)
{
  constexpr u32 shift = RCC_CFGR2_PLL2MUL_SHIFT;
  constexpr u32 mask = RCC_CFGR2_PLL2MUL_MASK << shift;
  volatile u32* reg = &RCC->CFGR2;

  switch (factor)
  {
    case RCC_PLL2_MULTIPLICATION_FACTOR_8:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL8 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_9:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL9 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_10:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL10 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_11:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL11 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_12:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL12 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_13:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL13 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_14:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL14 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_16:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL16 << shift);
      break;

    case RCC_PLL2_MULTIPLICATION_FACTOR_20:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL2MUL20 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_pll2_multiplication_factor, factor);
      break;
  }
}
#endif

#if defined(STM32_RCC_OSC_PLL3)
void
rcc_set_pll3_multiplication_factor(
  enum rcc_pll3_multiplication_factor factor
)
{
  constexpr u32 shift = RCC_CFGR2_PLL3MUL_SHIFT;
  constexpr u32 mask = RCC_CFGR2_PLL3MUL_MASK << shift;
  volatile u32* reg = &RCC->CFGR2;

  switch (factor)
  {
    case RCC_PLL3_MULTIPLICATION_FACTOR_8:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL8 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_9:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL9 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_10:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL10 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_11:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL11 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_12:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL12 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_13:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL13 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_14:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL14 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_16:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL16 << shift);
      break;

    case RCC_PLL3_MULTIPLICATION_FACTOR_20:
      syn_set_register_bits(reg, mask, RCC_CFGR2_PLL3MUL20 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_pll3_multiplication_factor, factor);
      break;
  }
}
#endif

#if defined(STM32_RCC_PREDIV1)
void
rcc_set_prediv1_source(
  enum rcc_prediv1_source source
)
{
  switch (source)
  {
    case RCC_PREDIV1_SOURCE_HSE:
      RCC->CFGR2 &= ~RCC_CFGR2_PREDIV1SRC;
      break;

    case RCC_PREDIV1_SOURCE_PLL2:
      RCC->CFGR2 |= RCC_CFGR2_PREDIV1SRC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_prediv1_source, source);
      break;
  }
}
#endif

#if defined(STM32_I2S2)
void
rcc_set_i2s2_source(
  enum rcc_i2s2_source source
)
{
  switch (source)
  {
    case RCC_I2S2_SOURCE_SYSCLOCK:
      RCC->CFGR2 &= ~RCC_CFGR2_I2S2SRC;
      break;

    case RCC_I2S2_SOURCE_PLL3:
      RCC->CFGR2 |= RCC_CFGR2_I2S2SRC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_i2s2_source, source);
      break;
  }
}
#endif

#if defined(STM32_I2S3)
void
rcc_set_i2s3_source(
  enum rcc_i2s3_source source
)
{
  switch (source)
  {
    case RCC_I2S3_SOURCE_SYSCLOCK:
      RCC->CFGR2 &= ~RCC_CFGR2_I2S3SRC;
      break;

    case RCC_I2S3_SOURCE_PLL3:
      RCC->CFGR2 |= RCC_CFGR2_I2S3SRC;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_i2s3_source, source);
      break;
  }
}
#endif
#endif

#if defined(STM32_RCC_EXTENDED_REGS)

#if defined(STM32_USART1)
void
rcc_set_usart1_clock_source(
  enum rcc_usart_clock_source source
)
{
  constexpr u32 shift = RCC_CFGR3_USART1SW_SHIFT;
  constexpr u32 mask = RCC_CFGR3_USART1SW_MASK << shift;
  volatile u32* reg = &RCC->CFGR3;

  switch (source)
  {
    case RCC_USART_CLOCK_SOURCE_PCLK:
      *reg &= ~mask;
      break;

    case RCC_USART_CLOCK_SOURCE_SYSCLK:
      syn_set_register_bits(reg, mask, RCC_CFGR3_USART1SW_SYSCLK << shift);
      break;

    case RCC_USART_CLOCK_SOURCE_LSE:
      syn_set_register_bits(reg, mask, RCC_CFGR3_USART1SW_LSE << shift);
      break;

    case RCC_USART_CLOCK_SOURCE_HSI:
      *reg |= (RCC_CFGR3_USART1SW_HSI << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_usart_clock_source, source);
      break;
  }
}
#endif

void
rcc_set_i2c1_clock_source(
  enum rcc_i2c1_clock_source source
)
{
  volatile u32* reg = &RCC->CFGR3;
  switch (source)
  {
    case RCC_I2C1_CLOCK_SOURCE_HSI:
      *reg &= ~RCC_CFGR3_I2C1SW;
      break;

    case RCC_I2C1_CLOCK_SOURCE_SYSCLK:
      *reg |= RCC_CFGR3_I2C1SW;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_i2c1_clock_source, source);
      break;
  }
}

#if defined(STM32_CEC)
void
rcc_set_cec_clock_source(
  enum rcc_cec_clock_source source
)
{
  volatile u32* reg = &RCC->CFGR3;
  switch (source)
  {
    case RCC_CEC_CLOCK_SOURCE_HSI_DIV244:
      *reg &= ~RCC_CFGR3_USBSW;
      break;

    case RCC_CEC_CLOCK_SOURCE_LSE:
      *reg |= RCC-CFGR3_USBSW;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_cec_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_USB)
void
rcc_set_usb_clock_source(
  enum rcc_usb_clock_source source
)
{
  volatile u32* reg = &RCC->CFGR3;
  switch (source)
  {
    case RCC_USB_CLOCK_SOURCE_HSI48:
      *reg &= ~RCC_CFGR3_USBSW;
      break;

    case RCC_USB_CLOCK_SOURCE_PLLCLK:
      *reg |= RCC_CFGR3_USBSW;
      break;

    default:
      devmode_error_invalid_enum(enum rcc_usb_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_USART2)
void
rcc_set_usart2_clock_source(
  enum rcc_usart_clock_source source
)
{
  constexpr u32 shift = RCC_CFGR3_USART2SW_SHIFT;
  constexpr u32 mask = RCC_CFGR3_USART2SW_MASK << shift;
  volatile u32* reg = &RCC->CFGR3;

  switch (source)
  {
    case RCC_USART_CLOCK_SOURCE_PCLK:
      *reg &= ~mask;
      break;

    case RCC_USART_CLOCK_SOURCE_SYSCLK:
      syn_set_register_bits(reg, mask, RCC_CFGR3_USART2SW_SYSCLK << shift);
      break;

    case RCC_USART_CLOCK_SOURCE_LSE:
      syn_set_register_bits(reg, mask, RCC_CFGR3_USART2SW_LSE << shift);
      break;

    case RCC_USART_CLOCK_SOURCE_HSI:
      *reg |= (RCC_CFGR3_USART2SW_HSI << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_usart_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_USART3)
void
rcc_set_usart3_clock_source(
  enum rcc_usart_clock_source source
)
{
  constexpr u32 shift = RCC_CFGR3_USART3SW_SHIFT;
  constexpr u32 mask = RCC_CFGR3_USART3SW_MASK << shift;
  volatile u32* reg = &RCC->CFGR3;

  switch (source)
  {
    case RCC_USART_CLOCK_SOURCE_PCLK:
      *reg &= ~mask;
      break;

    case RCC_USART_CLOCK_SOURCE_SYSCLK:
      syn_set_register_bits(reg, mask, RCC_CFGR3_USART3SW_SYSCLK << shift);
      break;

    case RCC_USART_CLOCK_SOURCE_LSE:
      syn_set_register_bits(reg, mask, RCC_CFGR3_USART3SW_LSE << shift);
      break;

    case RCC_USART_CLOCK_SOURCE_HSI:
      *reg |= (RCC_CFGR3_USART3SW_HSI << shift);
      break;

    default:
      devmode_error_invalid_enum(enum rcc_usart_clock_source, source);
      break;
  }
}
#endif

#if defined(STM32_RCC_OSC_HSI14)
void
rcc_set_hsi14_trim(
  u32 value
)
{
  devmode_assert_lower_or_eq(value, RCC_CR2_HSI14TRIM_MASK);
  constexpr u32 shift = RCC_CR2_HSI14TRIM_SHIFT;
  constexpr u32 mask = RCC_CR2_HSI14TRIM_MASK << shift;
  volatile u32* reg = &RCC->CR2;
  syn_set_register_bits(reg, mask, value << shift);
}

u32
rcc_get_hsi14_calibration(void)
{
  constexpr u32 shift = RCC_CR2_HSI14TRIM_SHIFT;
  constexpr u32 mask = RCC_CR2_HSI14TRIM_MASK;
  volatile u32* reg = &RCC->CR2;
  return (*reg >> shift) & mask;
}
#endif

#if defined(STM32_RCC_OSC_HSI48)
u32
rcc_get_hsi48_calibration(void)
{
  constexpr u32 shift = RCC_CR2_HSI48CAL_SHIFT;
  constexpr u32 mask = RCC_CR2_HSI48CAL_MASK;
  volatile u32* reg = &RCC->CR2;
  return (*reg >> shift) & mask;
}
#endif
#endif

u32
rcc_get_apb2_clock(void)
{
  return apb2_clock;
}

u32
rcc_get_apb1_clock(void)
{
  return apb1_clock;
}

u32
rcc_get_ahb_clock(void)
{
  return ahb_clock;
}

u32
rcc_get_sysclock(void)
{
  return sysclock;
}

