#include "synapse/stm32/drivers/rng/rng_v1.h"
#include "libcom/sys/devmode.h"
#include "synapse/stm32/system/chips/f4/memorymap.h"

typedef volatile struct rng_registers_map rng_periph;
rng_periph* RNG = (rng_periph*) (RNG_ADDR);

void
rng_enable(void)
{
  RNG->CR |= RNG_CR_RNGEN;
}

void
rng_disable(void)
{
  RNG->CR &= ~RNG_CR_RNGEN;
}

void
rng_interrupt_enable(void)
{
  RNG->CR |= RNG_CR_IE;
}

void
rng_interrupt_disable(void)
{
  RNG->CR &= ~RNG_CR_IE;
}

#if defined(STM32_RNG_CK_ERRDE)
void
rng_clock_error_detection_enable(void)
{
  RNG->CR |= RNG_CR_CED;
}

void
rng_clock_error_detection_disable(void)
{
  RNG->CR &= ~RNG_CR_CED;
}
#endif

u32
rng_is_flag_set(
  enum rng_flag flag
)
{
  volatile u32* reg = &RNG->SR;
  switch (flag)
  {
    case RNG_FLAG_DATA_READY:
      return *reg & RNG_SR_DRDY;

    case RNG_FLAG_CLOCK_ERROR_CURRENT:
      return *reg & RNG_SR_CECS;

    case RNG_FLAG_SEED_ERROR_CURRENT:
      return *reg & RNG_SR_SECS;

    case RNG_FLAG_CLOCK_ERROR:
      return *reg & RNG_SR_CEIS;

    case RNG_FLAG_SEED_ERROR:
      return *reg & RNG_SR_SEIS;

    default:
      devmode_error_invalid_enum(enum rng_flag, flag);
      return 0;
  }
}

void
rng_flag_clear(
  enum rng_flag flag
)
{
  volatile u32* reg = &RNG->SR;
  switch (flag)
  {
    case RNG_FLAG_CLOCK_ERROR:
      *reg &= ~RNG_SR_CEIS;
      break;

    case RNG_FLAG_SEED_ERROR:
      *reg &= ~RNG_SR_SEIS;
      break;

    default:
      devmode_error_invalid_enum(enum rng_interrupt_flag, flag);
      break;
  }
}

u32
rng_get_random_32bit(void)
{
  return RNG->DR;
}

