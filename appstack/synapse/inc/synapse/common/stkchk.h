#ifndef SYN_STKCHK_H
#define SYN_STKCHK_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

extern u32 __stack_chk_guard;

u32
syn_stkchk_guard_generate_def(void);

u32
syn_stkchk_guard_generate(void);

END_DECLARATIONS

#endif
