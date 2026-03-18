#ifndef SYSL_TIMEIF_H
#define SYSL_TIMEIF_H

#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

struct sys_time_vtable
{
  u64 (*now)(void*);
  void (*on_overflow)(void*);
};

END_DECLARATIONS

#endif
