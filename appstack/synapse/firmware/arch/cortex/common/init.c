#include "libcom/types.h"

// Defined in the linker script.
extern u32 _data_lma_addr;
extern u32 _sdata;
extern u32 _edata;
extern u32 _sbss;
extern u32 _ebss;

extern function_t __preinit_array_start;
extern function_t __preinit_array_end;

extern function_t __init_array_start;
extern function_t __init_array_end;

extern function_t __fini_array_start;
extern function_t __fini_array_end;

int
main(void);

static void
invoke_all(function_t start, function_t end)
{
  for (function_t* func = &start; func < &end; ++func)
  {
    (*func)();
  }
}

void /*__attribute__((used, noinline, section(".text.startup")))*/
_reset(void)
{ 
  /*
   * - Copy .data into RAM (from data_loadaddr to data_vma);
   * -  Set .bss to 0;
   * - Call .preinit_array functions;
   * - Call .init_array functions;
   * - Call main()
   * - Call .fini_array;
   */

  u32* src;
  u32* dest;

  (void) src;
  (void) dest;

  // Copies `.data` content from flash to RAM.
  /*sn_memcpy(&_sdata, &_data_lma_addr, (u32) (&_edata - &_sdata));*/
  for (src = &_data_lma_addr, dest = &_sdata;
       dest < &_edata;
       src++, dest++)
  {
    *dest = *src;
  }

  // Sets `.bss` content to 0.
  /*sn_memset(&_sbss, 0, (u32) (&_ebss - _sbss));*/
  while (dest < &_ebss)
  {
    *dest++ = 0;
  }

  // Executes preinit array functions.
  invoke_all(__preinit_array_start, __preinit_array_end);

  // Executes init array functions.
  invoke_all(__init_array_start, __init_array_end);

  // Calls the main function.
  (void)main();

  // Executes fini array functions. 
  invoke_all(__fini_array_start, __fini_array_end);

  // Never returns.
  while (1);
}
