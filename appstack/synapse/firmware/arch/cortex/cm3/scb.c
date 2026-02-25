#include "synapse/arch/cortex/cm3/scb.h"
#include "synapse/arch/cortex/common/memorymap.h"
#include "synapse/common/util/common.h"

typedef volatile struct scb_registers_map scb_t;
scb_t* SCB = (scb_t*) (CM3_SCB_ADDR);

void
scb_multi_cycle_instructions_enable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISMCYCINT;
}

void
scb_multi_cycle_instructions_disable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISMCYCINT;
}

void
scb_memory_map_access_write_buffer_enable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISDEFWBUF;
}

void
scb_memory_map_access_write_buffer_disable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISDEFWBUF;
}

void
scb_it_folding_enable(void)
{
  SCB->ACTLR &= ~SCB_ACTLR_DISFOLD;
}

void
scb_it_folding_disable(void)
{
  SCB->ACTLR |= SCB_ACTLR_DISFOLD;
}

u32
scb_get_revision(void)
{
  constexpr u32 shift = SCB_CPUID_REVISION_SHIFT;
  constexpr u32 mask = SCB_CPUID_REVISION_MASK;
  return (SCB->CPUID >> shift) & mask;
}

u32
scb_get_part_number(void)
{
  constexpr u32 shift = SCB_CPUID_PARTNO_SHIFT;
  constexpr u32 mask = SCB_CPUID_PARTNO_MASK;
  return (SCB->CPUID >> shift) & mask;
}

u32
scb_get_variant(void)
{
  constexpr u32 shift = SCB_CPUID_VARIANT_SHIFT;
  constexpr u32 mask = SCB_CPUID_VARIANT_MASK;
  return (SCB->CPUID >> shift) & mask;
}

u32
scb_get_implementer(void)
{
  constexpr u32 shift = SCB_CPUID_IMPLEMENTER_SHIFT;
  constexpr u32 mask = SCB_CPUID_IMPLEMENTER_MASK;
  return (SCB->CPUID >> shift) & mask;
}

u32
scb_get_active_exception_number(void)
{
  constexpr u32 shift = SCB_ICSR_VECTACTIVE_SHIFT;
  constexpr u32 mask = SCB_ICSR_VECTACTIVE_MASK;
  return (SCB->ICSR >> shift) & mask;
}

u32
scb_are_preempted_exception_active(void)
{
  return SCB->ICSR & SCB_ICSR_RETTOBASE;
}

u32
scb_get_highest_pending_exception_priority(void)
{
  constexpr u32 shift = SCB_ICSR_VECTPENDING_SHIFT;
  constexpr u32 mask = SCB_ICSR_VECTACTIVE_MASK;
  return (SCB->ICSR >> shift) & mask;
}

u32
scb_is_interrupt_pending(void)
{
  return SCB->ICSR & SCB_ICSR_ISRPENDING;
}

void
scb_exception_clear(
  enum scb_exception exception
)
{
  volatile u32* reg = &SCB->ICSR;
  switch (exception)
  {
    case SCB_EXCEPTION_SYSTICK:
      *reg |= SCB_ICSR_PENDSTCLR;
      break;

    case SCB_EXCEPTION_PENDSV:
      *reg |= SCB_ICSR_PENDSVCLR;
      break;

    default:
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
    case SCB_EXCEPTION_SYSTICK:
      return SCB->ICSR & SCB_ICSR_PENDSTSET;
        
    case SCB_EXCEPTION_PENDSV:
      return SCB->ICSR & SCB_ICSR_PENDSTSET;

    case SCB_EXCEPTION_NMI:
      return SCB->ICSR & SCB_ICSR_NMIPENDSET;

    case SCB_EXCEPTION_SVCALL:
      return SCB->SHCSR & SCB_SHCSR_SVCALLPENDED;

    case SCB_EXCEPTION_USAGE_FAULT:
      return SCB->SHCSR & SCB_SHCSR_USGFAULTPENDED;

    case SCB_EXCEPTION_BUS_FAULT:
      return SCB->SHCSR & SCB_SHCSR_BUSFAULTPENDED;

    case SCB_EXCEPTION_MEM_FAULT:
      return SCB->SHCSR & SCB_SHCSR_MEMFAULTPENDED;

    default:
      return 0;
  }
}

void
scb_set_exception_pending(
  enum scb_exception exception
)
{
  volatile u32* reg = &SCB->ICSR;
  switch (exception)
  {
    case SCB_EXCEPTION_SYSTICK:
      *reg |= SCB_ICSR_PENDSTSET;
      break;
        
    case SCB_EXCEPTION_PENDSV:
      *reg |= SCB_ICSR_PENDSTSET;
      break;

    case SCB_EXCEPTION_NMI:
      *reg |= SCB_ICSR_NMIPENDSET;
      break;
    
    default:
      break;
  }
}

void
scb_set_vector_table_offset(
  u32 offset
)
{
  constexpr u32 shift = SCB_VTOR_TBLOFF_SHIFT;
  constexpr u32 mask = SCB_VTOR_TBLOFF_MASK << shift;
  volatile u32* reg = &SCB->VTOR;
  syn_set_register_bits(reg, mask, offset << shift);
}

void
scb_vector_table_reset(void)
{

}

// TODO: What's this?
void
scb_vector_table_clear(void)
{

}

void
scb_request_system_reset(void)
{
  SCB->AIRCR |= SCB_AIRCR_SYSRESETREQ;
}

u32
scb_get_interrupt_priority_group(void)
{
  constexpr u32 shift = SCB_AIRCR_PRIGROUP_SHIFT;
  constexpr u32 mask = SCB_AIRCR_PRIGROUP_MASK;
  return (SCB->AIRCR >> shift) & mask;
}

u32
scb_get_endianness(void)
{
  return SCB->AIRCR & SCB_AIRCR_ENDIANNESS;
}

// TODO: VECKEYSTAT

void
scb_set_isr_exit_mode(
  enum scb_isr_exit_mode mode
)
{
  volatile u32* reg = &SCB->SCR;
  switch (mode)
  {
    case SCB_ISR_EXIT_MODE_DEFAULT:
      *reg &= ~SCB_SCR_SLEEPONEXIT;
      break;

    case SCB_ISR_EXIT_MODE_SLEEP:
      *reg |= SCB_SCR_SLEEPONEXIT;
      break;
  }
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
    case SCB_WAKEUP_MODE_ENABLED_ONLY:
      *reg &= ~SCB_SCR_SEVONPEND;
      break;

    case SCB_WAKEUP_MODE_ALL:
      *reg |= SCB_SCR_SEVONPEND;
      break;
  }
}

void
scb_set_thread_mode_enter(
  enum scb_thread_mode_enter mode
)
{
  volatile u32* reg = &SCB->CCR;
  switch (mode)
  {
    case SCB_THREAD_MODE_ENTER_NO_EXCEPTION:
      *reg &= ~SCB_CCR_NONBASETHRDENA;
      break;

    case SCB_THREAD_MODE_ENTER_ANY_LEVEL:
      *reg |= SCB_CCR_NONBASETHRDENA;
      break;
  }
}

void
scb_unprivileged_access_to_sw_trigger_enable(void)
{
  SCB->CCR |= SCB_CCR_USERSETMPEND;
}

void
scb_unprivileged_access_to_sw_trigger_disable(void)
{
  SCB->CCR &= ~SCB_CCR_USERSETMPEND;
}

void
scb_set_unaligned_access_policy(
  enum scb_unaligned_access_policy policy
)
{
  volatile u32* reg = &SCB->CCR;
  switch (policy)
  {
    case SCB_UNALIGNED_ACCESS_POLICY_IGNORE:
      *reg &= ~SCB_CCR_UNALIGN_TRP;
      break;

    case SCB_UNALIGNED_ACCESS_POLICY_USAGEFAULT:
      *reg |= SCB_CCR_UNALIGN_TRP;
      break;
  }
}

void
scb_set_div0_policy(
  enum scb_div0_policy policy
)
{
  volatile u32* reg = &SCB->CCR;
  switch (policy)
  {
    case SCB_DIV0_POLICY_IGNORE:
      *reg &= ~SCB_CCR_DIV_0_TRP; 
      break;

    case SCB_DIV0_POLICY_TRAP:
      *reg |= SCB_CCR_DIV_0_TRP;
      break;
  }
}

void
scb_set_handlers_ignore_busfault_enable(void)
{
  SCB->CCR |= SCB_CCR_BFHFNMIGN;
}

void
scb_set_handlers_ignore_busfault_disable(void)
{
  SCB->CCR &= ~SCB_CCR_BFHFNMIGN;
}

void
scb_set_stack_alignment(
  enum scb_stack_alignment alignment
)
{
  volatile u32* reg = &SCB->CCR;
  switch (alignment)
  {
    case SCB_STACK_ALIGNEMENT_4BYTES:
      *reg &= ~SCB_CCR_STKALIGN;  
      break;

    case SCB_STACK_ALIGNEMENT_8BYTES:
      *reg |= SCB_CCR_STKALIGN;  
      break;
  }
}

void
scb_set_system_handler_priority(
  enum scb_system_handler handler,
  u32 priority
)
{
  volatile u32* reg;
  u32 shift;
  constexpr u32 mask = SCB_SHPR_MASK;

  switch (handler)
  {
    case SCB_SYSTEM_HANDLER_MEMMANAGE:
      reg = &SCB->SHPR1;
      shift = 0;
      syn_set_register_bits(reg, mask << shift, priority << shift);
      break;

    case SCB_SYSTEM_HANDLER_BUS_FAULT:
      reg = &SCB->SHPR1;
      shift = 8;
      syn_set_register_bits(reg, mask << shift, priority << shift);
      break;

    case SCB_SYSTEM_HANDLER_USAGE_FAULT:
      reg = &SCB->SHPR1;
      shift = 16;
      syn_set_register_bits(reg, mask << shift, priority << shift);
      break;

    case SCB_SYSTEM_HANDLER_SV_CALL:
      reg = &SCB->SHPR2;
      shift = 0;
      syn_set_register_bits(reg, mask << shift, priority << shift);
      break;

    case SCB_SYSTEM_HANDLER_PEND_SV:
      reg = &SCB->SHPR3;
      shift = 16;
      syn_set_register_bits(reg, mask << shift, priority << shift);
      break;

    case SCB_SYSTEM_HANDLER_SYSTICK_EXCEPTION:
      reg = &SCB->SHPR3;
      shift = 24;
      syn_set_register_bits(reg, mask << shift, priority << shift);
      break;
  }
}

u32
scb_is_exception_active(
  enum scb_exception exception
)
{
  const volatile u32* reg = &SCB->SHCSR;
  switch (exception)
  {
    case SCB_EXCEPTION_SYSTICK:
      return *reg & SCB_SHCSR_SYSTICKACT;

    case SCB_EXCEPTION_PENDSV:
      return *reg & SCB_SHCSR_PENDSVACT;

    case SCB_EXCEPTION_MONITOR:
      return *reg & SCB_SHCSR_MONITORACT;

    case SCB_EXCEPTION_SVCALL:
      return *reg & SCB_SHCSR_SVCALLACT;

    case SCB_EXCEPTION_USAGE_FAULT:
      return *reg & SCB_SHCSR_USGFAULTACT;

    case SCB_EXCEPTION_BUS_FAULT:
      return *reg & SCB_SHCSR_BUSFAULTACT;

    case SCB_EXCEPTION_MEM_FAULT:
      return *reg & SCB_SHCSR_MEMFAULTACT;

    default:
      return 0;
  }
}

u32
scb_is_flag_set(
  enum scb_flag flag
)
{
  const volatile u32* reg = &SCB->CFSR;
  switch (flag)
  {
    case SCB_FLAG_INSTRUCTION_ACCESS_VIOLATION:
      return *reg & SCB_CFSR_MMFSR_IACCVIOL;

    case SCB_FLAG_DATA_ACCESS_VIOLATION:
      return *reg & SCB_CFSR_MMFSR_DACCVIOL;

    case SCB_FLAG_UNSTACKING_MEMMANAGE_FAULT:
      return *reg & SCB_CFSR_MMFSR_MUNSTKERR;

    case SCB_FLAG_STACKING_MEMMANAGE_FAULT:
      return *reg & SCB_CFSR_MMFSR_MSTKERR;

    case SCB_FLAG_MEMMANAGE_FAULT_ADDRESS_REGISTER:
      return *reg & SCB_CFSR_MMFSR_MMARVALID;

    case SCB_FLAG_INSTRUCTION_BUS_ERROR:
      return *reg & SCB_CFSR_BFSR_IBUSERR;

    case SCB_FLAG_PRECISE_DATA_BUS_ERROR:
      return *reg & SCB_CFSR_BFSR_PRECISERR;

    case SCB_FLAG_IMPRECISE_DATA_BUS_ERROR:
      return *reg & SCB_CFSR_BFSR_IMPRECISERR;

    case SCB_FLAG_UNSTACKING_BUS_FAULT:
      return *reg & SCB_CFSR_BFSR_UNSTKERR;

    case SCB_FLAG_STACKING_BUS_FAULT:
      return *reg & SCB_CFSR_BFSR_STKERR;

    case SCB_FLAG_BUS_FAULT_ADDRESS_REGISTER:
      return *reg & SCB_CFSR_BFSR_BFARVALID;

    case SCB_FLAG_UNDEFINED_INSTRUCTION:
      return *reg & SCB_CFSR_UFSR_UNDEFINSTR;

    case SCB_FLAG_INVALID_STATE:
      return *reg & SCB_CFSR_UFSR_INVSTATE;

    case SCB_FLAG_NO_COPROCESSOR:
      return *reg & SCB_CFSR_UFSR_NOCP;

    case SCB_FLAG_UNALIGNED_ACCESS:
      return *reg & SCB_CFSR_UFSR_UNALIGNED;

    case SCB_FLAG_DIVIDE_BY_ZERO:
      return *reg & SCB_CFSR_UFSR_DIVBYZERO;

    case SCB_FLAG_VECTOR_TABLE_READ_BUS_FAULT:
      return SCB->HFSR & SCB_HFSR_VECTTBL;

    case SCB_FLAG_FORCED_HARD_FAULT:
      return SCB->HFSR & SCB_HFSR_FORCED;

    default:
      return 0;
  }
}

void
scb_flag_clear(
  enum scb_flag flag
)
{
  volatile u32* reg = &SCB->CFSR;
  switch (flag)
  {
    case SCB_FLAG_UNDEFINED_INSTRUCTION:
      *reg |= SCB_CFSR_UFSR_UNDEFINSTR;
      break;

    case SCB_FLAG_INVALID_STATE:
      *reg |= SCB_CFSR_UFSR_INVSTATE;
      break;

    case SCB_FLAG_NO_COPROCESSOR:
      *reg |= SCB_CFSR_UFSR_NOCP;
      break;

    case SCB_FLAG_UNALIGNED_ACCESS:
      *reg |= SCB_CFSR_UFSR_UNALIGNED;
      break;

    case SCB_FLAG_DIVIDE_BY_ZERO:
      *reg |= SCB_CFSR_UFSR_DIVBYZERO;
      break;

    case SCB_FLAG_VECTOR_TABLE_READ_BUS_FAULT:
      SCB->HFSR |= SCB_HFSR_VECTTBL;
      break;

    case SCB_FLAG_FORCED_HARD_FAULT:
      SCB->HFSR |= SCB_HFSR_FORCED;
      break;

    default:
      break;
  }
}

u32
scb_get_memmanage_fault_address(void)
{
  return SCB->MMAR;
}

u32
scb_get_busfault_address(void)
{
  return SCB->BFAR;
}

u32
scb_get_auxiliary_fault(void)
{
  return SCB->AFSR;
}

void
scb_auxiliary_fault_clear(void)
{
  SCB->AFSR |= SCB_AFSR_MASK;
}
