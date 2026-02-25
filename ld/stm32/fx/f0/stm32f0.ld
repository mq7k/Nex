/*
 * Sets the entry point (Function) of the program.
 */
ENTRY(_reset)

/*
 * Prevent the compiler from stripping away the `vec_table` symbol.
 */
EXTERN(vec_table)
