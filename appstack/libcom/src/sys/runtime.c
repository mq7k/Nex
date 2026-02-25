#include "libcom/sys/runtime.h"
#include "libcom/types.h"
#include <stdint.h>

extern u32 _sdata;
extern u32 _edata;
extern u32 _stack;

extern u32 _sbss;
extern u32 _ebss;

extern u32 _stext;
extern u32 _etext;

u32
nex_get_sp(void)
{
  u32 sp;
  __asm__ volatile ("mov %0, r13" : "=r"(sp));
  return sp;
}

u32
nex_get_RAM_usage(void)
{
  u32 sp = nex_get_sp();
  uintptr_t stack_used = ((uintptr_t) &_stack) - sp;
  u32 data_size = (u32) (&_edata - &_sdata);
  u32 bss_size = (u32) (&_ebss - &_sbss);
  return (u32) (data_size + bss_size + stack_used);
}

u32
nex_get_flash_usage(void)
{
  return (u32) (&_etext - &_stext);
}
