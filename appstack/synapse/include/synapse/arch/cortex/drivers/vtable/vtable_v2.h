#ifndef ARCH_DRIVER_VTABLE_H
#define ARCH_DRIVER_VTABLE_H

#include "libcom/types.h"
#include "synapse/arch/cortex/periph/nvic.h"

#if !defined(ARCH_NVIC_IRQ_COUNT)
#error "NVIC table entries count not defined."
#endif

// Defined in the linker script.
extern u32 _stack;

// Entry point function declaration.
void _reset(void);

struct vector_table
{
  u32* sp;
  function_t reset;
  function_t nmi;
  function_t hard_fault;
  function_t memory_manage_fault;
  function_t bus_fault;
  function_t usage_fault;

  u32 _reserved0[4];

  function_t sv_call;
  function_t debug_monitor;

  u32 _reserved1;

  function_t pend_sv;
  function_t systick;
  function_t irq[ARCH_NVIC_IRQ_COUNT];
};

extern struct vector_table vec_table;

#endif
