#include "synapse/arch/cortex/drivers/fpu/fpu_v1.h"
#include "libcom/sys/devmode.h"
#include "synapse/arch/cortex/common/memorymap.h"
#include "synapse/arch/cortex/common/sys.h"
#include "synapse/common/util/common.h"

typedef volatile struct fpu_registers_map fpu_periph;
volatile fpu_periph* FPU = (fpu_periph*) (ARCH_FPU_ADDR);

void
fpu_set_access_level(
  enum fpu_access_level level
)
{
  volatile u32* reg = &FPU->CPACR;
  constexpr u32 shift_cp10 = FPU_CPACR_CP10_SHIFT;
  constexpr u32 shift_cp11 = FPU_CPACR_CP11_SHIFT;
  constexpr u32 mask = FPU_CPACR_CP_MASK;
  u32 level_bits;

  switch (level)
  {
    case FPU_ACCESS_LEVEL_DENIED:
      level_bits = mask << shift_cp10;
      level_bits |= (mask << shift_cp11);
      *reg |= level_bits;
      break;

    case FPU_ACCESS_LEVEL_PRIVILEGED_ONLY:
      level_bits = FPU_CPACR_CP_PRIVILEGED_ONLY << shift_cp10;
      level_bits |= (FPU_CPACR_CP_PRIVILEGED_ONLY << shift_cp11);
      syn_set_register_bits(
        reg,
        (mask << shift_cp10) | (mask << shift_cp11),
        level_bits
      );
      break;

    case FPU_ACCESS_LEVEL_FULL:
      level_bits = FPU_CPACR_CP_FULL_ACCESS << shift_cp10;
      level_bits |= (FPU_CPACR_CP_FULL_ACCESS << shift_cp11);
      *reg |= level_bits;
      break;

    default:
      devmode_error_invalid_enum(enum fpu_access_level, level);
      break;
  }
}

u32
fpu_is_lazy_state_preservation_active(void)
{
  return FPU->FPCCR & FPU_FPCCR_LSPACT;
}

u32
fpu_unprivileged_stack_frame(void)
{
  return FPU->FPCCR & FPU_FPCCR_USER;
}

u32
fpu_thread_mode_stack_frame(void)
{
  return FPU->FPCCR & FPU_FPCCR_THREAD;
}

u32
fpu_is_hard_fault_ready(void)
{
  return FPU->FPCCR & FPU_FPCCR_HFRDY;
}

u32
fpu_is_memmanage_ready(void)
{
  return FPU->FPCCR & FPU_FPCCR_MMRDY;
}

u32
fpu_is_busfault_ready(void)
{
  return FPU->FPCCR & FPU_FPCCR_BFRDY;
}

u32
fpu_is_debug_monitor_ready(void)
{
  return FPU->FPCCR & FPU_FPCCR_MONRDY;
}

void
fpu_auto_lazy_state_preserve_enable(void)
{
  FPU->FPCCR |= FPU_FPCCR_LSPEN;
}

void
fpu_auto_lazy_state_preserve_disable(void)
{
  FPU->FPCCR &= ~FPU_FPCCR_LSPEN;
}

void
fpu_auto_hardware_state_preserve_enable(void)
{
  FPU->FPCCR |= FPU_FPCCR_ASPEN;
}

void
fpu_auto_hardware_state_preserve_disable(void)
{
  FPU->FPCCR &= ~FPU_FPCCR_ASPEN;
}

u32
fpu_is_exception_bit_set(
  enum fpu_exception_bit bit
)
{
  const u32 reg = cm_get_fpu_fpscr();
  switch (bit)
  {
    case FPU_EXCEPTION_BIT_IDC:
      return reg & FPU_FPSCR_IDC;

    case FPU_EXCEPTION_BIT_IXC:
      return reg & FPU_FPSCR_IXC;

    case FPU_EXCEPTION_BIT_UFC:
      return reg & FPU_FPSCR_UFC;

    case FPU_EXCEPTION_BIT_OFC:
      return reg & FPU_FPSCR_OFC;

    case FPU_EXCEPTION_BIT_DZC:
      return reg & FPU_FPSCR_DZC;

    case FPU_EXCEPTION_BIT_IOC:
      return reg & FPU_FPSCR_IOC;

    default:
      devmode_error_invalid_enum(enum fpu_exception_bit, bit);
      return 0;
  }
}

void
fpu_exception_bit_clear(
  enum fpu_exception_bit bit
)
{
  u32 reg = cm_get_fpu_fpscr();
  switch (bit)
  {
    case FPU_EXCEPTION_BIT_IDC:
      cm_set_fpu_fpscr(reg & ~FPU_FPSCR_IDC);
      break;

    case FPU_EXCEPTION_BIT_IXC:
      cm_set_fpu_fpscr(reg & ~FPU_FPSCR_IXC);
      break;

    case FPU_EXCEPTION_BIT_UFC:
      cm_set_fpu_fpscr(reg & ~FPU_FPSCR_UFC);
      break;

    case FPU_EXCEPTION_BIT_OFC:
      cm_set_fpu_fpscr(reg & ~FPU_FPSCR_OFC);
      break;

    case FPU_EXCEPTION_BIT_DZC:
      cm_set_fpu_fpscr(reg & ~FPU_FPSCR_DZC);
      break;

    case FPU_EXCEPTION_BIT_IOC:
      cm_set_fpu_fpscr(reg & ~FPU_FPSCR_IOC);
      break;

    default:
      devmode_error_invalid_enum(enum fpu_exception_bit, bit);
      break;
  }
}

void
fpu_set_rounding_mode(
  enum fpu_rounding_mode mode
)
{
  u32 reg = cm_get_fpu_fpscr();
  constexpr u32 shift = FPU_FPSCR_RMODE_SHIFT;
  constexpr u32 mask = FPU_FPSCR_RMODE_MASK << shift;

  switch (mode)
  {
    case FPU_ROUNDING_MODE_NEAREST:
      cm_set_fpu_fpscr(reg & ~mask);
      break;

    case FPU_ROUNDING_MODE_PLUS_INF:
      reg &= ~mask;
      reg |= (FPU_FPSCR_RMODE_RP << shift);
      cm_set_fpu_fpscr(reg);
      break;

    case FPU_ROUNDING_MODE_MINUS_INF:
      reg &= ~mask;
      reg |= (FPU_FPSCR_RMODE_RM << shift);
      cm_set_fpu_fpscr(reg);
      break;

    case FPU_ROUNDING_MODE_ZERO:
      reg |= (FPU_FPSCR_RMODE_RZ << shift);
      cm_set_fpu_fpscr(reg);
      break;

    default:
      devmode_error_invalid_enum(enum fpu_rounding_mode, mode);
      break;
  }
}

void
fpu_flush_to_zero_mode_enable(void)
{
  const u32 reg = cm_get_fpu_fpscr();
  cm_set_fpu_fpscr(reg | FPU_FPSCR_FZ);
}

void
fpu_flush_to_zero_mode_disable(void)
{
  const u32 reg = cm_get_fpu_fpscr();
  cm_set_fpu_fpscr(reg & ~FPU_FPSCR_FZ);
}

void
fpu_default_nan_enable(void)
{
  const u32 reg = cm_get_fpu_fpscr();
  cm_set_fpu_fpscr(reg | FPU_FPSCR_DN);
}

void
fpu_default_nan_disable(void)
{
  const u32 reg = cm_get_fpu_fpscr();
  cm_set_fpu_fpscr(reg & ~FPU_FPSCR_DN);
}

void
fpu_set_half_precision(
  enum fpu_half_precision precision
)
{
  const u32 reg = cm_get_fpu_fpscr();
  switch (precision)
  {
    case FPU_HALF_PRECISION_IEEE:
      cm_set_fpu_fpscr(reg & ~FPU_FPSCR_AHP);
      break;

    case FPU_HALF_PRECISION_ALTERNATIVE:
      cm_set_fpu_fpscr(reg | FPU_FPSCR_AHP);
      break;

    default:
      devmode_error_invalid_enum(enum fpu_half_precision, precision);
      break;
  }
}

u32
fpu_is_condition_flag_set(
  enum fpu_condition_flag flag
)
{
  const u32 reg = cm_get_fpu_fpscr();
  switch (flag)
  {
    case FPU_CONDITION_FLAG_NEG:
      return reg & FPU_FPSCR_N;
      break;

    case FPU_CONDITION_FLAG_ZERO:
      return reg & FPU_FPSCR_Z;
      break;

    case FPU_CONDITION_FLAG_CARRY:
      return reg & FPU_FPSCR_C;
      break;

    case FPU_CONDITION_FLAG_OVERFLOW:
      return reg & FPU_FPSCR_V;
      break;

    default:
      devmode_error_invalid_enum(enum fpu_condition_flag, flag);
      return 0;
  }
}

u32
fpu_get_rmode_default(void)
{
  volatile u32* reg = &FPU->FPDSCR;
  constexpr u32 mask = FPU_FPDSCR_RMODE_MASK;
  constexpr u32 shift = FPU_FPDSCR_RMODE_SHIFT;
  return syn_get_register_bits(reg, mask, shift);
}

u32
fpu_get_flush_to_zero_mode_default(void)
{
  return FPU->FPDSCR & FPU_FPDSCR_FZ;
}

u32
fpu_get_default_nan_default(void)
{
  return FPU->FPDSCR & FPU_FPDSCR_DN;
}

u32
fpu_get_half_precision_default(void)
{
  return FPU->FPDSCR & FPU_FPDSCR_AHP;
}
