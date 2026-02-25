#ifndef NEX_RUNTIME_H
#define NEX_RUNTIME_H

#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

u32
nex_get_sp(void);

u32
nex_get_RAM_usage(void);

u32
nex_get_flash_usage(void);

END_DECLARATIONS

#endif
