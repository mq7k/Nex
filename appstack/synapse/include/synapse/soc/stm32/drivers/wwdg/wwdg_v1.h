#ifndef STM32_DRIVER_WWDG_H
#define STM32_DRIVER_WWDG_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F4
 */

BEGIN_DECLARATIONS

struct wwdg_registers_map
{
  u32 CR;
  u32 CFR;
  u32 SR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum wwdg_cr : u32
{
  WWDG_CR_WDGA = (1 << 7)
};

#define WWDG_CR_T_SHIFT (0)
#define WWDG_CR_T_MASK (0x7f)

enum wwdg_cfr : u32
{
  WWDG_CFR_EWI = (1 << 9)
};

#define WWDG_CFR_W_SHIFT (0)
#define WWDG_CFR_W_MASK (0x7f)

#define WWDG_CFR_WDGTB_SHIFT (7)
#define WWDG_CFR_WDGTB_MASK (0x3)

enum wwdg_cfr_wdgtb : u32
{
  WWDG_CFR_WDGTB_DIV1 = 0b00,
  WWDG_CFR_WDGTB_DIV2 = 0b01,
  WWDG_CFR_WDGTB_DIV4 = 0b10,
  WWDG_CFR_WDGTB_DIV8 = 0b11
};

enum wwdg_sr : u32
{
  WWDG_SR_EWIF = (1 << 0)
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum wwdg_prescaler
{
  WWDG_PRESCALER_DIV1,
  WWDG_PRESCALER_DIV2,
  WWDG_PRESCALER_DIV4,
  WWDG_PRESCALER_DIV8
};

extern volatile struct wwdg_registers_map* WWDG;

void
wwdg_set_counter(
  u32 counter
);

u32
wwdg_get_counter(void);

void
wwdg_start(void);

void
wwdg_set_upper_threshold(
  u32 threshold
);

void
wwdg_set_prescaler(
  enum wwdg_prescaler prescaler
);

void
wwdg_early_wakeup_interrupt_enable(void);

void
wwdg_early_wakeup_interrupt_disable(void);

u32
wwdg_is_early_wakeup_interrupt_flag_set(void);

void
wwdg_early_wakeup_interrupt_flag_clear(void);

END_DECLARATIONS

#endif

