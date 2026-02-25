/*
 * Sets the entry point (Function) of the program.
 */
ENTRY(_reset)

/*
 * Prevent the compiler from stripping away the `vec_table` symbol.
 */
EXTERN(vec_table)

/* MEMORY */
/* { */
/*   ram (rw) : ORIGIN = 0x20000000, LENGTH = 20K */
/*   flash (rx) : ORIGIN = 0x08000000, LENGTH = 64K */
/* } */

/* INCLUDE "stm32fx.ld" */
