#include "synapse/common/stkchk.h"
#include "synapse/soc/stm32/system/specs.h"

#if defined(STM32_RNG)
#include "synapse/soc/stm32/periph/rng.h"
#endif

#include "synapse/soc/stm32/periph/rcc.h"
#include "libcom/util.h"
#include "libcom/types.h"

u32
syn_stkchk_guard_generate(void)
{
#if !defined(STM32_RNG)
  return syn_stkchk_guard_generate_def();
#else

  rcc_periph_clock_enable(RCC_PERIPH_RNG);

  // The RNG requires a clock source <= 48MHz.
  // It uses the Q output of the main PLL.
  // 16 HSI / 8 = VCO input frequency (The result must be between 1 and 2 MHz)
  // VCO output frequency = VCO input frequency * 50 (The result must be between 100 and 432 MHz)
  // RNG clock = VCO output frequency / 4 = 20 MHz
  rcc_set_main_pll_factorM(8);
  rcc_set_main_pll_factorN(50);
  rcc_set_main_pll_factorQ(4);
  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSI);

  rcc_osc_enable(RCC_OSC_PLL);
  while (!rcc_is_osc_ready(RCC_OSC_PLL));

  rng_enable();

  u32 random;
  do {
    while (!rng_is_flag_set(RNG_FLAG_DATA_READY));
    random = rng_get_random_32bit();
  } while (random == 0);

  rcc_periph_reset(RCC_PERIPH_RNG);
  rcc_periph_clock_disable(RCC_PERIPH_RNG);

  rcc_osc_disable(RCC_OSC_PLL);

  return random;
#endif
}
