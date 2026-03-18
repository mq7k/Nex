#ifndef SYN_COMMON_H
#define SYN_COMMON_H

#include "libcom/types.h"

/**
 * @brief Sets specific bits in a register.
 *
 * @details Modifies a register by applying a bit mask to clear specific 
 * bits and then setting them to the provided value.
 *
 * @param preg Pointer to the register to modify.
 * @param mask Bit mask specifying which bits to modify.
 * @param value New value to set for the specified bits.
 *
 * @note This function performs a read-modify-write operation, ensuring 
 * only the specified bits are changed.
 */
static inline void
syn_set_register_bits(
  volatile u32* preg,
  const u32 mask,
  const u32 value
)
{
  u32 reg = *preg;
  reg = (reg & ~mask) | value;
  *preg = reg;
}

static inline u32
syn_get_register_bits(
  volatile u32* preg,
  const u32 mask,
  const u32 shift
)
{
  return (*preg >> shift) & mask;
}

/**
 * @brief Inserts a delay using NOP instructions.
 *
 * @details Executes a simple loop with NOP instructions to create 
 * a delay based on the provided loop count.
 *
 * @param count Number of NOP instructions to execute.
 *
 * @note The delay duration depends on the CPU clock speed. This 
 * method is imprecise and should not be used for critical timing.
 */
static inline void
syn_delay_nop(
  u32 count
)
{
  for (u32 i = 0; i < count; ++i)
  {
    __asm__("nop");
  }
}

static inline
u32
syn_dec_to_bcd(
  u32 value
)
{
  return ((value / 10) << 4) + (value % 10);
}

static inline
u32
syn_bcd_to_dec(
  u32 tens, u32 unit
)
{
  return tens * 10 + unit;
}

#endif
