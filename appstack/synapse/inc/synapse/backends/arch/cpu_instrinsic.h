#ifndef SYN_BACKENDS_CPU_H
#define SYN_BACKENDS_CPU_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

void
syn_irq_enable(void);

void
syn_irq_disable(void);

void
syn_wait_for_interrupt(void);

END_DECLARATIONS

#endif
