#ifndef STM32_RNG_DRIVER_H
#define STM32_RNG_DRIVER_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct rng_registers_map
{
  u32 CR;
  u32 SR;
  u32 DR;
};

// Core
enum rng_cr : u32
{
  RNG_CR_RNGEN = (1 << 2),
  RNG_CR_IE = (1 << 3),

#if defined(STM32_RNG_CK_ERRDE)
  RNG_CR_CED = (1 << 5)
#endif
};

enum rng_sr : u32
{
  RNG_SR_DRDY = (1 << 0),
  RNG_SR_CECS = (1 << 1),
  RNG_SR_SECS = (1 << 2),
  RNG_SR_CEIS = (1 << 5),
  RNG_SR_SEIS = (1 << 6)
};

// API
enum rng_flag
{
  RNG_FLAG_DATA_READY,
  RNG_FLAG_CLOCK_ERROR_CURRENT,
  RNG_FLAG_SEED_ERROR_CURRENT,
  RNG_FLAG_CLOCK_ERROR,
  RNG_FLAG_SEED_ERROR
};

extern volatile struct rng_registers_map* RNG;

void
rng_enable(void);

void
rng_disable(void);

void
rng_interrupt_enable(void);

void
rng_interrupt_disable(void);

#if defined(STM32_RNG_CK_ERRDE)
void
rng_clock_error_detection_enable(void);

void
rng_clock_error_detection_disable(void);
#endif

u32
rng_is_flag_set(
  enum rng_flag flag
);

void
rng_flag_clear(
  enum rng_flag flag
);

u32
rng_get_random_32bit(void);

END_DECLARATIONS

#endif
