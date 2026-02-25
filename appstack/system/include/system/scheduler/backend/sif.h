#ifndef SYSL_SCHIF_H
#define SYSL_SCHIF_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct scheduler_backend_ctx;

struct scheduler_ts_backend_vtable
{
  void (*start)(void*);
  void (*stop)(void*);
};

struct scheduler_arch_backend_vtable
{
  void (*irq_disable)(void);
  void (*irq_enable)(void);
  void (*sleep)(void);
};

END_DECLARATIONS

#endif
