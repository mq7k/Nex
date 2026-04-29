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

  // TODO: Not tested due to lack of physical hardware.
  rcc_periph_clock_enable(RCC_PERIPH_RNG);
  rng_enable();

  u32 random;
  do {
    while (!rng_is_flag_set(RNG_FLAG_DATA_READY));
    random = rng_get_random_32bit();
  } while (random == 0);

  rcc_periph_reset(RCC_PERIPH_RNG);
  rcc_periph_clock_disable(RCC_PERIPH_RNG);

  return random;
#endif
}
