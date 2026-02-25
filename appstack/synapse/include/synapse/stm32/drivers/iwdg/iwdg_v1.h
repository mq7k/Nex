#ifndef STM32_DRIVER_IWDG_H
#define STM32_DRIVER_IWDG_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F4
 */

BEGIN_DECLARATIONS

struct iwdg_registers_map
{
  u32 KR;
  u32 PR;
  u32 RLR;
  u32 SR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum iwdg_kr : u32
{
  IWDG_KR_KEY_RESET = 0xaaaa,
  IWDG_KR_KEY_WRITE_UNLOCK = 0x5555,
  IWDG_KR_KEY_START = 0xcccc
};

#define IWDG_PR_PSC_SHIFT (0)
#define IWDG_PR_PSC_MASK (0x7)

enum iwdg_pr_psc : u32
{
  IWDG_PR_PSC_DIV4 = 0b000,
  IWDG_PR_PSC_DIV8 = 0b001,
  IWDG_PR_PSC_DIV16 = 0b010,
  IWDG_PR_PSC_DIV32 = 0b011,
  IWDG_PR_PSC_DIV64 = 0b100,
  IWDG_PR_PSC_DIV128 = 0b101,
  IWDG_PR_PSC_DIV256 = 0b110
};

#define IWDG_RLR_RL_SHIFT (0)
#define IWDG_RLR_RL_MASK (0xfff)

enum iwdg_sr : u32
{
  IWDG_SR_PVU = (1 << 0),
  IWDG_SR_RVU = (1 << 1)
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum iwdg_prescaler
{
  IWDG_PRESCALER_DIV4,
  IWDG_PRESCALER_DIV8,
  IWDG_PRESCALER_DIV16,
  IWDG_PRESCALER_DIV32,
  IWDG_PRESCALER_DIV64,
  IWDG_PRESCALER_DIV128,
  IWDG_PRESCALER_DIV256
};

enum iwdg_flag
{
  IWDG_FLAG_PRESCALER_UPDATE,
  IWDG_FLAG_COUNTER_UPDATE
};

extern volatile struct iwdg_registers_map* IWDG;

void
iwdg_reset(void);

void
iwdg_write_unlock(void);

void
iwdg_start(void);

void
iwdg_set_prescaler(
  enum iwdg_prescaler prescaler
);

void
iwdg_set_reload_value(
  u32 value
);

u32
iwdg_is_flag_set(
  enum iwdg_flag flag
);

END_DECLARATIONS

#endif
