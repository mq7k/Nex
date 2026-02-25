#ifndef ARCH_DRIVERS_FPU_H
#define ARCH_DRIVERS_FPU_H

#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

struct fpu_registers_map
{
  u32 CPACR;
  u32 FPCCR;
  u32 FPCAR;
  u32 FPDSCR;
};

#define FPU_CPACR_CP10_SHIFT (20)
#define FPU_CPACR_CP11_SHIFT (22)
#define FPU_CPACR_CP_MASK (0x3)

enum fpu_cpacr_cp : u32
{
  FPU_CPACR_CP_ACCESS_DENIED = 0b00,
  FPU_CPACR_CP_PRIVILEGED_ONLY = 0b01,
  FPU_CPACR_CP_FULL_ACCESS = 0b11
};

enum fpu_fpccr
{
  FPU_FPCCR_LSPACT = (1u << 0),
  FPU_FPCCR_USER = (1u << 1),
  FPU_FPCCR_THREAD = (1u << 3),
  FPU_FPCCR_HFRDY = (1u << 4),
  FPU_FPCCR_MMRDY = (1u << 5),
  FPU_FPCCR_BFRDY = (1u << 6),
  FPU_FPCCR_MONRDY = (1u << 7),
  FPU_FPCCR_LSPEN = (1u << 30),
  FPU_FPCCR_ASPEN = (1u << 31)
};

#define FPU_FPCAR_ADDRESS_SHIFT (3)
#define FPU_FPCAR_ADDRESS_MASK (0x1fffffff)

enum fpu_fpscr : u32
{
  FPU_FPSCR_IOC = (1u << 0),
  FPU_FPSCR_DZC = (1u << 1),
  FPU_FPSCR_OFC = (1u << 2),
  FPU_FPSCR_UFC = (1u << 3),
  FPU_FPSCR_IXC = (1u << 4),
  FPU_FPSCR_IDC = (1u << 7),
  FPU_FPSCR_FZ = (1u << 24),
  FPU_FPSCR_DN = (1u << 25),
  FPU_FPSCR_AHP = (1u << 26),
  FPU_FPSCR_V = (1u << 28),
  FPU_FPSCR_C = (1u << 29),
  FPU_FPSCR_Z = (1u << 30),
  FPU_FPSCR_N = (1u << 31)
};

#define FPU_FPSCR_RMODE_SHIFT (22)
#define FPU_FPSCR_RMODE_MASK (0x3)

enum fpu_fpscr_rmode : u32
{
  FPU_FPSCR_RMODE_RN = 0b00,
  FPU_FPSCR_RMODE_RP = 0b01,
  FPU_FPSCR_RMODE_RM = 0b10,
  FPU_FPSCR_RMODE_RZ = 0b11
};

enum fpu_fpdscr : u32
{
  FPU_FPDSCR_FZ = (1u << 24),
  FPU_FPDSCR_DN = (1u << 25),
  FPU_FPDSCR_AHP = (1u << 26)
};

#define FPU_FPDSCR_RMODE_SHIFT (22)
#define FPU_FPDSCR_RMODE_MASK (0x3)

// API
enum fpu_access_level
{
  FPU_ACCESS_LEVEL_DENIED,
  FPU_ACCESS_LEVEL_PRIVILEGED_ONLY,
  FPU_ACCESS_LEVEL_FULL
};

enum fpu_exception_bit
{
  FPU_EXCEPTION_BIT_IDC,
  FPU_EXCEPTION_BIT_IXC,
  FPU_EXCEPTION_BIT_UFC,
  FPU_EXCEPTION_BIT_OFC,
  FPU_EXCEPTION_BIT_DZC,
  FPU_EXCEPTION_BIT_IOC
};

enum fpu_rounding_mode
{
  FPU_ROUNDING_MODE_NEAREST,
  FPU_ROUNDING_MODE_PLUS_INF,
  FPU_ROUNDING_MODE_MINUS_INF,
  FPU_ROUNDING_MODE_ZERO
};

enum fpu_half_precision
{
  FPU_HALF_PRECISION_IEEE,
  FPU_HALF_PRECISION_ALTERNATIVE
};

enum fpu_condition_flag 
{
  FPU_CONDITION_FLAG_NEG,
  FPU_CONDITION_FLAG_ZERO,
  FPU_CONDITION_FLAG_CARRY,
  FPU_CONDITION_FLAG_OVERFLOW
};

extern volatile struct fpu_registers_map* FPU;

void
fpu_set_access_level(
  enum fpu_access_level level
);

u32
fpu_is_lazy_state_preservation_active(void);

u32
fpu_unprivileged_stack_frame(void);

u32
fpu_thread_mode_stack_frame(void);

u32
fpu_is_hard_fault_ready(void);

u32
fpu_is_memmanage_ready(void);

u32
fpu_is_busfault_ready(void);

u32
fpu_is_debug_monitor_ready(void);

void
fpu_auto_lazy_state_preserve_enable(void);

void
fpu_auto_lazy_state_preserve_disable(void);

void
fpu_auto_hardware_state_preserve_enable(void);

void
fpu_auto_hardware_state_preserve_disable(void);

u32
fpu_is_exception_bit_set(
  enum fpu_exception_bit bit
);

void
fpu_exception_bit_clear(
  enum fpu_exception_bit bit
);

void
fpu_set_rounding_mode(
  enum fpu_rounding_mode mode
);

void
fpu_flush_to_zero_mode_enable(void);

void
fpu_flush_to_zero_mode_disable(void);

void
fpu_default_nan_enable(void);

void
fpu_default_nan_disable(void);

void
fpu_set_half_precision(
  enum fpu_half_precision precision
);

u32
fpu_is_condition_flag_set(
  enum fpu_condition_flag flag
);

u32
fpu_get_rmode_default(void);

u32
fpu_get_flush_to_zero_mode_default(void);

u32
fpu_get_default_nan_default(void);

u32
fpu_get_half_precision_default(void);

END_DECLARATIONS

#endif
