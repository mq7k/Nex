#ifndef ARCH_DRIVER_SCB_H
#define ARCH_DRIVER_SCB_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

struct scb_registers_map
{
  u32 ACTLR;
  u32 _reserved0[829];

  u32 CPUID;
  u32 ICSR;
  u32 VTOR;
  u32 AIRCR;
  u32 SCR;
  u32 CCR;
  u32 SHPR1;
  u32 SHPR2;
  u32 SHPR3;
  u32 SHCSR;
  u32 CFSR;
  u32 HFSR;

  u32 _reserved1;

  u32 MMFAR;
  u32 BFAR;
  u32 AFSR;
};

// Core

enum scb_actlr : u32
{
  SCB_ACTLR_DISMCYCINT = (1 << 0),
  SCB_ACTLR_DISDEFWBUF = (1 << 1),
  SCB_ACTLR_DISFOLD = (1 << 2),

#if defined(CM_ACTLR_DISFPCA)
  SCB_ACTLR_DISFPCA = (1 << 3),
#endif

#if defined(CM_ACTLR_DISOOFP)
  SCB_ACTLR_DISOOFP = (1 << 4)
#endif
};

#define SCB_CPUID_REVISION_SHIFT (0)
#define SCB_CPUID_REVISION_MASK (0xf)

#define SCB_CPUID_PARTNO_SHIFT (4)
#define SCB_CPUID_PARTNO_MASK (0xfff)

#define SCB_CPUID_CONSTANT_SHIFT (16)
#define SCB_CPUID_CONSTANT_MASK (0xf)

#define SCB_CPUID_VARIANT_SHIFT (20)
#define SCB_CPUID_VARIANT_MASK (0xf)

#define SCB_CPUID_IMPLEMENTER_SHIFT (24)
#define SCB_CPUID_IMPLEMENTER_MASK (0xff)

enum scb_icsr : u32
{
  SCB_ICSR_RETTOBASE = (1 << 11),
  SCB_ICSR_ISRPENDING = (1 << 22),
  SCB_ICSR_PENDSTCLR = (1 << 25),
  SCB_ICSR_PENDSTSET = (1 << 26),
  SCB_ICSR_PENDSVCLR = (1 << 27),
  SCB_ICSR_PENDSVSET = (1 << 28),
  SCB_ICSR_NMIPENDSET = (1u << 31)
};

#define SCB_ICSR_VECTACTIVE_SHIFT (0)
#define SCB_ICSR_VECTACTIVE_MASK (0x1ff)

#define SCB_ICSR_VECTPENDING_SHIFT (12)
#define SCB_ICSR_VECTPENDING_MASK (0x7f)

#define SCB_VTOR_TBLOFF_SHIFT (9)
#define SCB_VTOR_TBLOFF_MASK (0x1fffff)

enum scb_aircr : u32
{
  SCB_AIRCR_VECTRESET = (1 << 0),
  SCB_AIRCR_VECTCLRACTIVE = (1 << 1),
  SCB_AIRCR_SYSRESETREQ = (1 << 2),
  SCB_AIRCR_ENDIANESS = (1 << 15)
};

#define SCB_AIRCR_PRIGROUP_SHIFT (8)
#define SCB_AIRCR_PRIGROUP_MASK (0x7)

enum scb_aircr_prigroup : u32
{
  SCB_AIRCR_PRIGROUP_G4_S0 = 0b000,
  SCB_AIRCR_PRIGROUP_G3_S1 = 0b100,
  SCB_AIRCR_PRIGROUP_G2_S2 = 0b101,
  SCB_AIRCR_PRIGROUP_G1_S3 = 0b110,
  SCB_AIRCR_PRIGROUP_G0_S4 = 0b111
};

#define SCB_AIRCR_VECTKEY_KEY (0x5fa)
#define SCB_AIRCR_VECTKEY_SHIFT (16)
#define SCB_AIRCR_VECTKEY_MASK (0xffffu)

enum scb_scr : u32
{
  SCB_SCR_SLEEPONEXIT = (1 << 1),
  SCB_SCR_SLEEPDEEP = (1 << 2),
  SCB_SCR_SEVONPEND = (1 << 4)
};

enum scb_ccr : u32
{
  SCB_CCR_NONBASETHRDENA = (1 << 0),
  SCB_CCR_USERSETMPEND = (1 << 1),
  SCB_CCR_UNALIGNTRP = (1 << 3),
  SCB_CCR_DIV0TRP = (1 << 4),
  SCB_CCR_BFHFNMING = (1 << 8),
  SCB_CCR_STKALIGN = (1 << 9)
};

#define SCB_SHPR1_MEMMANAGE_FAULT_SHIFT (0)
#define SCB_SHPR1_MEMMANAGE_FAULT_MASK (0xffu)

#define SCB_SHPR_MAX_PRIORITY (0xff)

#define SCB_SHPR1_BUS_FAULT_SHIFT (8)
#define SCB_SHPR1_BUS_FAULT_MASK (0xffu)

#define SCB_SHPR1_USAGE_FAULT_SHIFT (16)
#define SCB_SHPR1_USAGE_FAULT_MASK (0xff)

#define SCB_SHPR2_SVCALL_SHIFT (24)
#define SCB_SHPR2_SVCALL_MASK (0xffu)

#define SCB_SHPR3_PENDSV_SHIFT (16)
#define SCB_SHPR3_PENDSV_MASK (0xffu)

#define SCB_SHPR3_SYSTICK_SHIFT (24)
#define SCB_SHPR3_SYSTICK_MASK (0xffu)

enum scb_shcsr : u32
{
  SCB_SHCSR_MEMFAULTACT = (1 << 0),
  SCB_SHCSR_BUSFAULTACT = (1 << 1),
  SCB_SHCSR_USGFAULTACT = (1 << 3),
  SCB_SHCSR_SVCALLACT = (1 << 7),
  SCB_SHCSR_MONITORACT = (1 << 8),
  SCB_SHCSR_PENDSVACT = (1 << 10),
  SCB_SHCSR_SYSTICKACT = (1 << 11),
  SCB_SHCSR_USGFAULTPENDED = (1 << 12),
  SCB_SHCSR_MEMFAULTPENDED = (1 << 13),
  SCB_SHCSR_BUSFAULTPENDED = (1 << 14),
  SCB_SHCSR_SVCALLPENDED = (1 << 15),
  SCB_SHCSR_MEMFAULTENA = (1 << 16),
  SCB_SHCSR_BUSFAULTENA = (1 << 17),
  SCB_SHCSR_USGFAULTENA = (1 << 18)
};

enum scb_cfsr : u32
{
  SCB_CFSR_IACCVIOL = (1 << 0),
  SCB_CFSR_DACCVIOL = (1 << 1),
  SCB_CFSR_MUNSTKERR = (1 << 3),
  SCB_CFSR_MSTKERR = (1 << 4),

#if defined(CM_CFSR_MLSPERR)
  SCB_CFSR_MLSPERR = (1 << 5),
#endif

  SCB_CFSR_MMARVALID = (1 << 7),
  SCB_CFSR_IBUSERR = (1 << 8),
  SCB_CFSR_PRECISERR = (1 << 9),
  SCB_CFSR_IMPRECISERR = (1 << 10),
  SCB_CFSR_UNSTKERR = (1 << 11),
  SCB_CFSR_STKERR = (1 << 12),

#if defined(CM_CFSR_LSPERR)
  SCB_CFSR_LSPERR = (1 << 13),
#endif

  SCB_CFSR_BFARVALID = (1 << 14),
  SCB_CFSR_UNDEFINSTR = (1 << 15),
  SCB_CFSR_INVSTATE = (1 << 17),
  SCB_CFSR_INVPC = (1 << 18),
  SCB_CFSR_NOCP = (1 << 19),
  SCB_CFSR_UNALIGNED = (1 << 24),
  SCB_CFSR_DIVBYZERO = (1 << 25)
};

enum scb_hfsr : u32
{
  SCB_HFSR_VECTTBL = (1 << 1),
  SCB_HFSR_FORCED = (1 << 30),
  SCB_HFSR_DEBUGVT = (1u << 31)
};

// API

enum scb_interrupt_priority_groups_format
{
  SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G4_S0,
  SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G3_S1,
  SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G2_S2,
  SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G1_S3,
  SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G0_S4
};

enum scb_sleep_mode
{
  SCB_SLEEP_MODE_SLEEP,
  SCB_SLEEP_MODE_DEEPSLEEP
};

enum scb_wakeup_mode
{
  SCB_WAKEUP_MODE_ONLY_ENABLED,
  SCB_WAKEUP_MODE_ALL
};

enum scb_thread_mode_enter_mode
{
  SCB_THREAD_MODE_ENTER_MODE_NO_EXCEPTION,
  SCB_THREAD_MODE_ENTER_MODE_ANY_LEVEL
};

enum scb_stack_alignment
{
  SCB_STACK_ALIGNMENT_4BYTE,
  SCB_STACK_ALIGNMENT_8BYTE
};

enum scb_exception
{
  SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT,
  SCB_EXCEPTION_BUS_FAULT,
  SCB_EXCEPTION_USAGE_FAULT,
  SCB_EXCEPTION_SVCALL,
  SCB_EXCEPTION_MONITOR,
  SCB_EXCEPTION_PENDSV,
  SCB_EXCEPTION_SYSTICK
};

enum scb_flag
{
  SCB_FLAG_MEM_INSTRUCTION_ACCESS_VIOLATION,
  SCB_FLAG_MEM_DATA_ACCESS_VIOLATION,
  SCB_FLAG_MEM_FAULT_ON_UNSTACKING,
  SCB_FLAG_MEM_FAULT_ON_STACKING,
  SCB_FLAG_MEM_VALID_FAULT_ADDR,

#if defined(CM_CFSR_MLSPERR)
  SCB_FLAG_MEM_FAULT_FP_LAZY_STATE_PRESERVATION,
#endif

  SCB_FLAG_BUS_INSTRUCTION_ERROR,
  SCB_FLAG_BUS_PRECISE_DATA_ERROR,
  SCB_FLAG_BUS_IMPRECISE_DATA_ERROR,
  SCB_FLAG_BUS_FAULT_ON_UNSTACKING,
  SCB_FLAG_BUS_FAULT_ON_STACKING,

#if defined(CM_CFSR_LSPERR)
  SCB_FLAG_BUS_FAULT_ON_FLOATING_POINT_PRESERVATION,
#endif

  SCB_FLAG_BUS_VALID_FAULT_ADDR,

  SCB_FLAG_USAGE_UNDEFINED_INSTRUCTION,
  SCB_FLAG_USAGE_INVALID_STATE,
  SCB_FLAG_USAGE_INVALID_PC,
  SCB_FLAG_USAGE_NO_COPROCESSOR,
  SCB_FLAG_USAGE_UNALIGNED_ACCESS,
  SCB_FLAG_USAGE_DIV_BY_ZERO,

  SCB_FLAG_HARD_BUS_FAULT_ON_VTABLE_READ,
  SCB_FLAG_HARD_FORCED
};

extern volatile struct scb_registers_map* SCB;

void
scb_interrupt_multi_cycle_intructions_enable(void);

void
scb_interrupt_multi_cycle_intructions_disable(void);

void
scb_write_buffer_enable(void);

void
scb_write_buffer_disable(void);

void
scb_folding_it_instructions_enable(void);

void
scb_folding_it_instructions_disable(void);

#if defined(CM_ACTLR_DISFPCA)
void
scb_automatic_fp_context_preservation_enable(void);

void
scb_automatic_fp_context_preservation_disable(void);
#endif

#if defined(CM_ACTLR_DISOOFP)
void
scb_fp_instructions_out_of_order_enable(void);

void
scb_fp_instructions_out_of_order_disable(void);
#endif

u32
scb_get_product_revision(void);

u32
scb_get_partno(void);

u32
scb_get_constant(void);

u32
scb_get_variant(void);

u32
scb_get_implementer_code(void);

u32
scb_get_active_exception_number(void);

u32
scb_are_preempted_active_exceptions_present(void);

u32
scb_get_pending_exception_number(void);

u32
scb_is_isr_pending(void);

// void
// scb_systick_pending_clear(void);

// void
// scb_systick_set_pending(void);

// u32
// scb_is_systick_pending(void);

void
scb_pendsv_pending_clear(void);

void
scb_pendsv_set_pending(void);

u32
scb_is_pendsv_pending(void);

void
scb_nmi_set_pending(void);

u32
scb_is_nmi_pending(void);

void
scb_set_vector_table_address_offset(
  u32 offset
);

void
scb_vector_reset(void);

void
scb_vector_clear_active(void);

void
scb_system_reset(void);

void
scb_set_interrupt_group_priority_format(
  enum scb_interrupt_priority_groups_format format
);

u32
scb_is_big_endian(void);

void
scb_unlock_aircr_register(void);

void
scb_sleep_on_exit_enable(void);

void
scb_sleep_on_exit_disable(void);

void
scb_set_sleep_mode(
  enum scb_sleep_mode mode
);

void
scb_set_wakeup_mode(
  enum scb_wakeup_mode mode
);

void
scb_set_thread_mode_enter_mode(
  enum scb_thread_mode_enter_mode mode
);

void
scb_unprivileged_software_stir_access_enable(void);

void
scb_unprivileged_software_stir_access_disable(void);

void
scb_unaligned_access_trap_enable(void);

void
scb_unaligned_access_trap_disable(void);

void
scb_div0_trap_enable(void);

void
scb_div0_trap_disable(void);

void
scb_neg_priority_handler_ignores_bus_faults_enable(void);

void
scb_neg_priority_handler_ignores_bus_faults_disable(void);

void
scb_set_stack_alignement_on_exception_entry(
  enum scb_stack_alignment alignment
);

void
scb_set_exception_priority(
  enum scb_exception exception,
  u32 priority
);

void
scb_exception_enable(
  enum scb_exception exception
);

void
scb_exception_disable(
  enum scb_exception exception
);

u32
scb_is_exception_pending(
  enum scb_exception exception
);

void
scb_set_exception_pending(
  enum scb_exception exception
);

void
scb_exception_pending_clear(
  enum scb_exception exception
);

u32
scb_is_exception_active(
  enum scb_exception exception
);

u32
scb_is_flag_set(
  enum scb_flag flag
);

void
scb_flag_clear(
  enum scb_flag flag
);

u32
scb_get_mem_manage_fault_addr(void);

u32
scb_get_bus_fault_addr(void);

END_DECLARATIONS

#endif
