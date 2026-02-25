/**
 * This linker script defines the sections layout for any
 * stm32fx mcu.
 * Memory layout are defined per-mcu.
 */

/*
 * The '.' character is a special directive referring to the current address.
 * It's possibile to jump forward and backward, but going back it's not recommended
 * since you might accidentally override sections.
 *
 *
 * KEEP:
 *    Tells the linker to always keep that section,
 *    even if it's not referenced by any other section.
 *    Otherwise, it would be stripped out from the final binary.
 *
 * ALIGN: 
 *    Aligns the current address ('.') to the byte boundary specified by the parameter.
 *
 * LOADADDR:
 *    Returns the section's LMA.
 *
 * LMA represents the physical address where a section is stored in memory.
 * VMA represents the address where the section is actually used/executed.
 *
 * If a section's VMA != LMA, it means the section is relocated at startup.
 * Notations:
 *  .section : { ... } > flash
 *    - The section exists in the flash and executed directly from there.
 *    - LMA == VMA.
 *    Examples:
 *      - `.text` -> Contains program code;
 *      - `.rodata` -> Contains read-only data.
 *
 *  .section : { ... } > ram
 *    - The section only exists in RAM and is NOT stored in flash memory.
 *    - LMA == VMA.
 *    Examples:
 *      - `.heap_start` and `.heap_end` -> Defines heap memory region;
 *      - `.bss` -> Contains uninitialized data and it's zeroed at startup.
 *
 *  .section : { ... } > ram AT> flash
 *    - The section exists in the flash and it's copied into RAM at startup.
 *    - LMA != VMA.
 *    Examples:
 *      - `.data` -> Contains pre-initialized global variables.
 */

PHDRS
{
  seg_rx PT_LOAD FLAGS(5);
  seg_rw PT_LOAD FLAGS(6);
}

SECTIONS
{
  /*
   * First section to be placed in the flash memory.
   * The name of this section MUST match the one in the (C/C++) source file
   * containing the vector table.
   */
  .isr_vector :
  {
    KEEP(*(.isr_vector));
    . = ALIGN(4);
  } > flash : seg_rx

  .text :
  {
    _stext = .;
    /*
     * These 4 lines tell the linker to include each section matching these names
     * in the .text section of the final binary file.
     */
    *(.text)
    *(.text.*)
    . = ALIGN(4);
    *(.rodata)
    *(.rodata.*)
    . = ALIGN(4);

    /*
     * Defines a variable at the end of the text section.
     */
    _etext = .;
  } > flash : seg_rx

    /**
     * This section contains an array on function pointers that are executed
     * before the main initialization functions.
     * In embedded systems, these functions might:
     *  - Setting up critical hardware before other initialization;
     *  - Performing safety checks before regular initialization;
     *  - Setting up debugging infrastructure.
     */
  .preinit_array : {
     . = ALIGN(4);
     __preinit_array_start = .;
     KEEP(*(.preinit_array))
     __preinit_array_end = .;
  } > flash : seg_rx

   /**
    * This section contains function pointers to initialization routines
    * that run before main().
    * In C++ programs, this includes global constructors.
    * The compiler automatically places C++ constructors in this section.
    * It also possible to manually add functions using:
    * __attribute__((constructor))
    *
    * For C programs, it might contain:
    *   - Library initialization routines;
    *   - Runtime setup functions;
    *   - Explicitly registered initialization functions.
    */
   .init_array : {
     . = ALIGN(4);
     __init_array_start = .;
     KEEP(*(SORT(.init_array.*)))
     KEEP(*(.init_array))
     __init_array_end = .;
   } > flash : seg_rx

   /**
    * The is the counterpart to .init_array. It contains function pointers
    * that run during program termination, after main() returns.
    * In C++ programs, this includes destructors for global objects.
    *
    * In embedded systems, this section might be less commonly used
    * since manu embedded applications never "exit" in the traditional sense.
    * However, they can be useful for:
    *   - Cleanup functions if your program can restart;
    *   - Safe shutdown procedures;
    *   - Resource release in more complex applications.
    *
    * C++ destructors are automatically placed here.
    * It's possible to manually add functions with:
    * __attribute__((destructor))
    */
   .fini_array : {
     . = ALIGN(4);
     __fini_array_start = .;
     KEEP(*(.fini_array))
     KEEP(*(SORT(.fini_array.*)))
     __fini_array_end = .;
   } > flash : seg_rx

    /**
     * This section contains exception unwinding information.
     * It contains tables that describe how stack unwinding should
     * be performed for C++ exceptions and stack backtraces.
     * This section is always empty for C projects, but may
     * be used by C++ applications.
     */
   .ARM.extab : {
     *(.ARM.extab*)
   } > flash : seg_rx

   /**
    * This section contains index table for exception unwinding.
    * It contains pointers to entries in `.ARM.extab`, providing
    * fast lookup for stack unwinding.
    * This is required for ARM EABI systems that use unwinding.
    * This section is always empty for C projects, but may
    * be used by C++ applications.
    */
   .ARM.exidx : {
     __exidx_start = .;
     *(.ARM.exidx*)
     __exidx_end = .;
   } > flash : seg_rx

  /*
   * Data section contains pre-initialized global variables.
   * The content is stored in the flash, but should be loaded in ram
   * when linking. We took care of the relocation on the "init.c" file.
   *
   * LOADADDR provides the LMA (Load Memory Address).
   * _sdata provides the VMA (Virtual Memory Address).
   */
  _data_lma_addr = LOADADDR(.data);
  .data :
  {
    _sdata = .;
    *(.data)
    *(.data.*)
    . = ALIGN(4);
    _edata = .;
  }> ram AT> flash : seg_rw

  /*
   * The .bss section is initialized directly in ram.
   * Again, _sbss is set to the starting address of the section.
   */
  .bss :
  {
    _sbss = .;
    /* __bss_start__ = _sbss; */
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > ram : seg_rw
}

_stack = ORIGIN(ram) + LENGTH(ram);
