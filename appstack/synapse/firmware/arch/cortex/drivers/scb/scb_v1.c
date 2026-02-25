#include "synapse/arch/cortex/drivers/scb/scb_v1.h"
#include "synapse/arch/cortex/common/memorymap.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct scb_registers_map scb_periph;
scb_periph* SCB = (scb_periph*) (ARCH_SCB_ADDR);

void
scb_interrupt_multi_cycle_intructions_enable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISMCYCINT;
}

void
scb_interrupt_multi_cycle_intructions_disable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISMCYCINT;
}

void
scb_write_buffer_enable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISDEFWBUF;
}

void
scb_write_buffer_disable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISDEFWBUF;
}

void
scb_folding_it_instructions_enable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISFOLD;
}

void
scb_folding_it_instructions_disable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISFOLD;
}

#if defined(CM_ACTLR_DISFPCA)
void
scb_automatic_fp_context_preservation_enable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISFPCA;
}

void
scb_automatic_fp_context_preservation_disable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISFPCA;
}
#endif

#if defined(CM_ACTLR_DISOOFP)
void
scb_fp_instructions_out_of_order_enable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISOOFP;
}

void
scb_fp_instructions_out_of_order_disable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISOOFP;
}
#endif

u32
scb_get_product_revision(void)
{
  constexpr u32 shift = SCB_CPUID_REVISION_SHIFT;
  constexpr u32 mask = SCB_CPUID_REVISION_MASK;
  volatile u32* reg = &SCB->CPUID;
  return (*reg >> shift) & mask;
}

u32
scb_get_partno(void)
{
  constexpr u32 shift = SCB_CPUID_PARTNO_SHIFT;
  constexpr u32 mask = SCB_CPUID_PARTNO_MASK;
  volatile u32* reg = &SCB->CPUID;
  return (*reg >> shift) & mask;
}

u32
scb_get_constant(void)
{
  constexpr u32 shift = SCB_CPUID_CONSTANT_SHIFT;
  constexpr u32 mask = SCB_CPUID_CONSTANT_MASK;
  volatile u32* reg = &SCB->CPUID;
  return (*reg >> shift) & mask;
}

u32
scb_get_variant(void)
{
  constexpr u32 shift = SCB_CPUID_VARIANT_SHIFT;
  constexpr u32 mask = SCB_CPUID_VARIANT_MASK;
  volatile u32* reg = &SCB->CPUID;
  return (*reg >> shift) & mask;
}

u32
scb_get_implementer_code(void)
{
  constexpr u32 shift = SCB_CPUID_IMPLEMENTER_SHIFT;
  constexpr u32 mask = SCB_CPUID_IMPLEMENTER_MASK;
  volatile u32* reg = &SCB->CPUID;
  return (*reg >> shift) & mask;
}

u32
scb_get_active_exception_number(void)
{
  constexpr u32 shift = SCB_ICSR_VECTACTIVE_SHIFT;
  constexpr u32 mask = SCB_ICSR_VECTACTIVE_MASK;
  volatile u32* reg = &SCB->ICSR;
  return (*reg >> shift) & mask;
}

u32
scb_are_preempted_active_exceptions_present(void)
{
  return SCB->ICSR & SCB_ICSR_RETTOBASE;
}

u32
scb_get_pending_exception_number(void)
{
  constexpr u32 shift = SCB_ICSR_VECTPENDING_SHIFT;
  constexpr u32 mask = SCB_ICSR_VECTPENDING_MASK;
  volatile u32* reg = &SCB->ICSR;
  return (*reg >> shift) & mask;
}

u32
scb_is_isr_pending(void)
{
  return SCB->ICSR & SCB_ICSR_ISRPENDING;
}

// void
// scb_systick_pending_clear(void)
// {
//   SCB->ICSR |= SCB_ICSR_PENDSTCLR;
// }

// void
// scb_systick_set_pending(void)
// {
//   SCB->ICSR |= SCB_ICSR_PENDSTSET;
// }

// u32
// scb_is_systick_pending(void)
// {
//   return SCB->ICSR & SCB_ICSR_PENDSTSET;
// }

void
scb_pendsv_pending_clear(void)
{
  SCB->ICSR |= SCB_ICSR_PENDSVCLR;
}

void
scb_pendsv_set_pending(void)
{
  SCB->ICSR |= SCB_ICSR_PENDSVSET;
}

u32
scb_is_pendsv_pending(void)
{
  return SCB->ICSR & SCB_ICSR_PENDSVSET;
}

void
scb_nmi_set_pending(void)
{
  SCB->ICSR |= SCB_ICSR_NMIPENDSET;
}

u32
scb_is_nmi_pending(void)
{
  return SCB->ICSR & SCB_ICSR_NMIPENDSET;
}

void
scb_set_vector_table_address_offset(
  u32 offset
)
{
  SCB->VTOR = offset;
}

void
scb_vector_reset(void)
{
  SCB->AIRCR &= ~SCB_AIRCR_VECTRESET;
}

void
scb_vector_clear_active(void)
{
  SCB->AIRCR &= ~SCB_AIRCR_VECTRESET;
}

void
scb_system_reset(void)
{
  SCB->AIRCR |= SCB_AIRCR_SYSRESETREQ;
}

void
scb_set_interrupt_group_priority_format(
  enum scb_interrupt_priority_groups_format format
)
{
  constexpr u32 shift = SCB_AIRCR_PRIGROUP_SHIFT;
  constexpr u32 mask = SCB_AIRCR_PRIGROUP_MASK << shift;
  volatile u32* reg = &SCB->AIRCR;

  switch (format)
  {
    case SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G4_S0:
      syn_set_register_bits(reg, mask, SCB_AIRCR_PRIGROUP_G4_S0 << shift);
      break;

    case SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G3_S1:
      syn_set_register_bits(reg, mask, SCB_AIRCR_PRIGROUP_G3_S1 << shift);
      break;

    case SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G2_S2:
      syn_set_register_bits(reg, mask, SCB_AIRCR_PRIGROUP_G2_S2 << shift);
      break;

    case SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G1_S3:
      syn_set_register_bits(reg, mask, SCB_AIRCR_PRIGROUP_G1_S3 << shift);
      break;

    case SCB_INTERRUPT_PRIORITY_GROUPS_FORMAT_G0_S4:
      syn_set_register_bits(reg, mask, SCB_AIRCR_PRIGROUP_G0_S4 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum scb_interrupt_priority_groups_format, format);
      break;
  }
}

u32
scb_is_big_endian(void)
{
  return SCB->AIRCR & SCB_AIRCR_ENDIANESS;
}

void
scb_unlock_aircr_register(void)
{
  constexpr u32 shift = SCB_AIRCR_VECTKEY_SHIFT;
  constexpr u32 mask = SCB_AIRCR_VECTKEY_MASK << shift;
  volatile u32* reg = &SCB->AIRCR;
  syn_set_register_bits(reg, mask, SCB_AIRCR_VECTKEY_KEY);
}

void
scb_sleep_on_exit_enable(void)
{
  SCB->SCR |= SCB_SCR_SLEEPONEXIT;
}

void
scb_sleep_on_exit_disable(void)
{
  SCB->SCR &= ~SCB_SCR_SLEEPONEXIT;
}

void
scb_set_sleep_mode(
  enum scb_sleep_mode mode
)
{
  volatile u32* reg = &SCB->SCR;
  switch (mode)
  {
    case SCB_SLEEP_MODE_SLEEP:
      *reg &= ~SCB_SCR_SLEEPDEEP;
      break;

    case SCB_SLEEP_MODE_DEEPSLEEP:
      *reg |= SCB_SCR_SLEEPDEEP;
      break;

    default:
      devmode_error_invalid_enum(enum scb_sleep_mode, mode);
      break;
  }
}

void
scb_set_wakeup_mode(
  enum scb_wakeup_mode mode
)
{
  volatile u32* reg = &SCB->SCR;
  switch (mode)
  {
    case SCB_WAKEUP_MODE_ONLY_ENABLED:
      *reg &= ~SCB_SCR_SEVONPEND;
      break;

    case SCB_WAKEUP_MODE_ALL:
      *reg |= SCB_SCR_SEVONPEND;
      break;

    default:
      devmode_error_invalid_enum(enum scb_wakeup_mode, mode);
      break;
  }
}

void
scb_set_thread_mode_enter_mode(
  enum scb_thread_mode_enter_mode mode
)
{
  volatile u32* reg = &SCB->CCR;
  switch (mode)
  {
    case SCB_THREAD_MODE_ENTER_MODE_NO_EXCEPTION:
      *reg &= ~SCB_CCR_NONBASETHRDENA;
      break;

    case SCB_THREAD_MODE_ENTER_MODE_ANY_LEVEL:
      *reg |= SCB_CCR_NONBASETHRDENA;
      break;

    default:
      devmode_error_invalid_enum(enum scb_thread_mode_enter_mode, mode);
      break;
  }
}

void
scb_unprivileged_software_stir_access_enable(void)
{
  SCB->CCR |= SCB_CCR_USERSETMPEND;
}

void
scb_unprivileged_software_stir_access_disable(void)
{
  SCB->CCR &= ~SCB_CCR_USERSETMPEND;
}

void
scb_unaligned_access_trap_enable(void)
{
  SCB->CCR |= SCB_CCR_UNALIGNTRP;
}

void
scb_unaligned_access_trap_disable(void)
{
  SCB->CCR &= ~SCB_CCR_UNALIGNTRP;
}

void
scb_div0_trap_enable(void)
{
  SCB->CCR |= SCB_CCR_DIV0TRP;
}

void
scb_div0_trap_disable(void)
{
  SCB->CCR &= ~SCB_CCR_DIV0TRP;
}

void
scb_neg_priority_handler_ignores_bus_faults_enable(void)
{
  SCB->CCR |= SCB_CCR_BFHFNMING;
}

void
scb_neg_priority_handler_ignores_bus_faults_disable(void)
{
  SCB->CCR &= ~SCB_CCR_BFHFNMING;
}

void
scb_set_stack_alignement_on_exception_entry(
  enum scb_stack_alignment alignment
)
{
  volatile u32* reg = &SCB->CCR;
  switch (alignment)
  {
    case SCB_STACK_ALIGNMENT_4BYTE:
      *reg &= ~SCB_CCR_STKALIGN;
      break;

    case SCB_STACK_ALIGNMENT_8BYTE:
      *reg |= SCB_CCR_STKALIGN;
      break;

    default:
      devmode_error_invalid_enum(enum scb_stack_alignment, alignment);
      break;
  }
}

void
scb_set_exception_priority(
  enum scb_exception exception,
  u32 priority
)
{
  devmode_assert_lower_or_eq(priority, SCB_SHPR_MAX_PRIORITY);

  u32 shift;
  u32 mask;
  volatile u32* reg;

  switch (exception)
  {
    case SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT:
      shift = SCB_SHPR1_MEMMANAGE_FAULT_SHIFT;
      mask = SCB_SHPR1_MEMMANAGE_FAULT_MASK << shift;
      reg = &SCB->SHPR1;
      syn_set_register_bits(reg, mask, priority << shift);
      break;

    case SCB_EXCEPTION_BUS_FAULT:
      shift = SCB_SHPR1_BUS_FAULT_SHIFT;
      mask = SCB_SHPR1_BUS_FAULT_MASK << shift;
      reg = &SCB->SHPR1;
      syn_set_register_bits(reg, mask, priority << shift);
      break;

    case SCB_EXCEPTION_USAGE_FAULT:
      shift = SCB_SHPR1_USAGE_FAULT_SHIFT;
      mask = SCB_SHPR1_BUS_FAULT_MASK << shift;
      reg = &SCB->SHPR1;
      syn_set_register_bits(reg, mask, priority << shift);
      break;

    case SCB_EXCEPTION_SVCALL:
      shift = SCB_SHPR2_SVCALL_SHIFT;
      mask = SCB_SHPR2_SVCALL_MASK << shift;
      reg = &SCB->SHPR2;
      syn_set_register_bits(reg, mask, priority << shift);
      break;

    case SCB_EXCEPTION_PENDSV:
      shift = SCB_SHPR3_PENDSV_SHIFT;
      mask = SCB_SHPR3_PENDSV_MASK << shift;
      reg = &SCB->SHPR3;
      syn_set_register_bits(reg, mask, priority << shift);
      break;

    case SCB_EXCEPTION_SYSTICK:
      shift = SCB_SHPR3_SYSTICK_SHIFT;
      mask = SCB_SHPR3_SYSTICK_MASK << shift;
      reg = &SCB->SHPR3;
      syn_set_register_bits(reg, mask, priority << shift);
      break;

    default:
      devmode_error_invalid_enum(enum scb_exception, exception);
      break;
  }
}

void
scb_exception_enable(
  enum scb_exception exception
)
{
  volatile u32* reg = &SCB->SHCSR;

  switch (exception)
  {
    case SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT:
      *reg |= SCB_SHCSR_MEMFAULTENA;
      break;

    case SCB_EXCEPTION_BUS_FAULT:
      *reg |= SCB_SHCSR_BUSFAULTENA;
      break;

    case SCB_EXCEPTION_USAGE_FAULT:
      *reg |= SCB_SHCSR_USGFAULTENA;
      break;

    default:
      devmode_error_invalid_enum(enum scb_exception, exception);
      break;
  }
}

void
scb_exception_disable(
  enum scb_exception exception
)
{
  volatile u32* reg = &SCB->SHCSR;

  switch (exception)
  {
    case SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT:
      *reg &= ~SCB_SHCSR_MEMFAULTENA;
      break;

    case SCB_EXCEPTION_BUS_FAULT:
      *reg &= ~SCB_SHCSR_BUSFAULTENA;
      break;

    case SCB_EXCEPTION_USAGE_FAULT:
      *reg &= ~SCB_SHCSR_USGFAULTENA;
      break;

    default:
      devmode_error_invalid_enum(enum scb_exception, exception);
      break;
  }
}

u32
scb_is_exception_pending(
  enum scb_exception exception
)
{
  switch (exception)
  {
    case SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT:
      return SCB->SHCSR & SCB_SHCSR_MEMFAULTPENDED;

    case SCB_EXCEPTION_BUS_FAULT:
      return SCB->SHCSR & SCB_SHCSR_BUSFAULTPENDED;

    case SCB_EXCEPTION_USAGE_FAULT:
      return SCB->SHCSR & SCB_SHCSR_USGFAULTPENDED;

    case SCB_EXCEPTION_SVCALL:
      return SCB->SHCSR & SCB_SHCSR_SVCALLPENDED;

    case SCB_EXCEPTION_SYSTICK:
      return SCB->ICSR & SCB_ICSR_PENDSTSET;

    default:
      devmode_error_invalid_enum(enum scb_exception, exception);
      return 0;
  }
}

void
scb_set_exception_pending(
  enum scb_exception exception
)
{
  switch (exception)
  {
    case SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT:
      SCB->SHCSR |= SCB_SHCSR_MEMFAULTPENDED;
      break;

    case SCB_EXCEPTION_BUS_FAULT:
      SCB->SHCSR |= SCB_SHCSR_BUSFAULTPENDED;
      break;

    case SCB_EXCEPTION_USAGE_FAULT:
      SCB->SHCSR |= SCB_SHCSR_USGFAULTPENDED;
      break;

    case SCB_EXCEPTION_SVCALL:
      SCB->SHCSR |= SCB_SHCSR_SVCALLPENDED;
      break;

    case SCB_EXCEPTION_SYSTICK:
      SCB->ICSR |= SCB_ICSR_PENDSTSET;
      break;

    default:
      devmode_error_invalid_enum(enum scb_exception, exception);
      break;
  }
}

void
scb_exception_pending_clear(
  enum scb_exception exception
)
{
  switch (exception)
  {
    case SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT:
      SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTPENDED;
      break;

    case SCB_EXCEPTION_BUS_FAULT:
      SCB->SHCSR &= ~SCB_SHCSR_BUSFAULTPENDED;
      break;

    case SCB_EXCEPTION_USAGE_FAULT:
      SCB->SHCSR &= ~SCB_SHCSR_USGFAULTPENDED;
      break;

    case SCB_EXCEPTION_SVCALL:
      SCB->SHCSR &= ~SCB_SHCSR_SVCALLPENDED;
      break;

    case SCB_EXCEPTION_SYSTICK:
      SCB->ICSR &= ~SCB_ICSR_PENDSTSET;
      break;

    default:
      devmode_error_invalid_enum(enum scb_exception, exception);
      break;
  }
}

u32
scb_is_exception_active(
  enum scb_exception exception
)
{
  volatile u32* reg = &SCB->SHCSR;
  switch (exception)
  {
    case SCB_EXCEPTION_MEMORY_MANAGEMENT_FAULT:
      return *reg & SCB_SHCSR_MEMFAULTACT;

    case SCB_EXCEPTION_BUS_FAULT:
      return *reg & SCB_SHCSR_BUSFAULTACT;

    case SCB_EXCEPTION_USAGE_FAULT:
      return *reg & SCB_SHCSR_USGFAULTACT;

    case SCB_EXCEPTION_SVCALL:
      return *reg & SCB_SHCSR_SVCALLACT;

    case SCB_EXCEPTION_MONITOR:
      return *reg & SCB_SHCSR_MONITORACT;

    case SCB_EXCEPTION_PENDSV:
      return *reg & SCB_SHCSR_PENDSVACT;

    case SCB_EXCEPTION_SYSTICK:
      return *reg & SCB_SHCSR_SYSTICKACT;

    default:
      devmode_error_invalid_enum(enum scb_exception, exception);
      return 0;
  }
}

u32
scb_is_flag_set(
  enum scb_flag flag
)
{
  switch (flag)
  {
    case SCB_FLAG_MEM_INSTRUCTION_ACCESS_VIOLATION:
      return SCB->CFSR & SCB_CFSR_IACCVIOL;

    case SCB_FLAG_MEM_DATA_ACCESS_VIOLATION:
      return SCB->CFSR & SCB_CFSR_DACCVIOL;

    case SCB_FLAG_MEM_FAULT_ON_UNSTACKING:
      return SCB->CFSR & SCB_CFSR_MUNSTKERR;

    case SCB_FLAG_MEM_FAULT_ON_STACKING:
      return SCB->CFSR & SCB_CFSR_MSTKERR;

#if defined(CM_CFSR_MLSPERR)
    case SCB_FLAG_MEM_FAULT_FP_LAZY_STATE_PRESERVATION:
      return SCB->CFSR & SCB_CFSR_MLSPERR;
#endif

    case SCB_FLAG_MEM_VALID_FAULT_ADDR:
      return SCB->CFSR & SCB_CFSR_MMARVALID;

    case SCB_FLAG_BUS_INSTRUCTION_ERROR:
      return SCB->CFSR & SCB_CFSR_IBUSERR;

    case SCB_FLAG_BUS_PRECISE_DATA_ERROR:
      return SCB->CFSR & SCB_CFSR_PRECISERR;

    case SCB_FLAG_BUS_IMPRECISE_DATA_ERROR:
      return SCB->CFSR & SCB_CFSR_IMPRECISERR;

    case SCB_FLAG_BUS_FAULT_ON_UNSTACKING:
      return SCB->CFSR & SCB_CFSR_UNSTKERR;

    case SCB_FLAG_BUS_FAULT_ON_STACKING:
      return SCB->CFSR & SCB_CFSR_STKERR;

#if defined(CM_CFSR_LSPERR)
    case SCB_FLAG_BUS_FAULT_ON_FLOATING_POINT_PRESERVATION:
      return SCB->CFSR & SCB_CFSR_LSPERR;
#endif

    case SCB_FLAG_BUS_VALID_FAULT_ADDR:
      return SCB->CFSR & SCB_CFSR_BFARVALID;

    case SCB_FLAG_USAGE_UNDEFINED_INSTRUCTION:
      return SCB->CFSR & SCB_CFSR_UNDEFINSTR;

    case SCB_FLAG_USAGE_INVALID_STATE:
      return SCB->CFSR & SCB_CFSR_INVSTATE;

    case SCB_FLAG_USAGE_INVALID_PC:
      return SCB->CFSR & SCB_CFSR_INVPC;

    case SCB_FLAG_USAGE_NO_COPROCESSOR:
      return SCB->CFSR & SCB_CFSR_NOCP;

    case SCB_FLAG_USAGE_UNALIGNED_ACCESS:
      return SCB->CFSR & SCB_CFSR_UNALIGNED;

    case SCB_FLAG_USAGE_DIV_BY_ZERO:
      return SCB->CFSR & SCB_CFSR_DIVBYZERO;

    case SCB_FLAG_HARD_BUS_FAULT_ON_VTABLE_READ:
      return SCB->HFSR & SCB_HFSR_VECTTBL;

    case SCB_FLAG_HARD_FORCED:
      return SCB->HFSR & SCB_HFSR_FORCED;

    default:
      devmode_error_invalid_enum(enum scb_flag, flag);
      return 0;
  }
}

void
scb_flag_clear(
  enum scb_flag flag
)
{
  switch (flag)
  {
    case SCB_FLAG_MEM_INSTRUCTION_ACCESS_VIOLATION:
      SCB->CFSR |= SCB_CFSR_IACCVIOL;
			break;

    case SCB_FLAG_MEM_DATA_ACCESS_VIOLATION:
      SCB->CFSR |= SCB_CFSR_DACCVIOL;
			break;

    case SCB_FLAG_MEM_FAULT_ON_UNSTACKING:
      SCB->CFSR |= SCB_CFSR_MUNSTKERR;
			break;

    case SCB_FLAG_MEM_FAULT_ON_STACKING:
      SCB->CFSR |= SCB_CFSR_MSTKERR;
			break;

#if defined(CM_CFSR_MLSPERR)
    case SCB_FLAG_MEM_FAULT_FP_LAZY_STATE_PRESERVATION:
      SCB->CFSR |= SCB_CFSR_MLSPERR;
      break;
#endif

    case SCB_FLAG_MEM_VALID_FAULT_ADDR:
      SCB->CFSR |= SCB_CFSR_MMARVALID;
			break;

    case SCB_FLAG_BUS_INSTRUCTION_ERROR:
      SCB->CFSR |= SCB_CFSR_IBUSERR;
			break;

    case SCB_FLAG_BUS_PRECISE_DATA_ERROR:
      SCB->CFSR |= SCB_CFSR_PRECISERR;
			break;

    case SCB_FLAG_BUS_IMPRECISE_DATA_ERROR:
      SCB->CFSR |= SCB_CFSR_IMPRECISERR;
			break;

    case SCB_FLAG_BUS_FAULT_ON_UNSTACKING:
      SCB->CFSR |= SCB_CFSR_UNSTKERR;
			break;

    case SCB_FLAG_BUS_FAULT_ON_STACKING:
      SCB->CFSR |= SCB_CFSR_STKERR;
			break;

#if defined(CM_CFSR_LSPERR)
    case SCB_FLAG_BUS_FAULT_ON_FLOATING_POINT_PRESERVATION:
      SCB->CFSR |= SCB_CFSR_LSPERR;
			break;
#endif

    case SCB_FLAG_BUS_VALID_FAULT_ADDR:
      SCB->CFSR |= SCB_CFSR_BFARVALID;
			break;

    case SCB_FLAG_USAGE_UNDEFINED_INSTRUCTION:
      SCB->CFSR |= SCB_CFSR_UNDEFINSTR;
			break;

    case SCB_FLAG_USAGE_INVALID_STATE:
      SCB->CFSR |= SCB_CFSR_INVSTATE;
			break;

    case SCB_FLAG_USAGE_INVALID_PC:
      SCB->CFSR |= SCB_CFSR_INVPC;
			break;

    case SCB_FLAG_USAGE_NO_COPROCESSOR:
      SCB->CFSR |= SCB_CFSR_NOCP;
			break;

    case SCB_FLAG_USAGE_UNALIGNED_ACCESS:
      SCB->CFSR |= SCB_CFSR_UNALIGNED;
			break;

    case SCB_FLAG_USAGE_DIV_BY_ZERO:
      SCB->CFSR |= SCB_CFSR_DIVBYZERO;
			break;

    case SCB_FLAG_HARD_BUS_FAULT_ON_VTABLE_READ:
      SCB->HFSR |= SCB_HFSR_VECTTBL;
			break;

    case SCB_FLAG_HARD_FORCED:
      SCB->HFSR |= SCB_HFSR_FORCED;
			break;

    default:
      devmode_error_invalid_enum(enum scb_flag, flag);
			break;
  }
}

u32
scb_get_mem_manage_fault_addr(void)
{
  return SCB->MMFAR;
}

u32
scb_get_bus_fault_addr(void)
{
  return SCB->BFAR;
}
