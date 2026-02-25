#ifndef ARCH_CORTEX_SYS_H
#define ARCH_CORTEX_SYS_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

extern void
cm_irq_enable(void);

extern void
cm_irq_disable(void);

extern void
cm_faults_enable(void);

extern void
cm_faults_disable(void);

extern void
cm_wfe(void);

extern void
cm_wfi(void);

extern u32
cm_get_primask(void);

extern u32
cm_get_faultmask(void);

extern u32
cm_get_basepri(void);

extern void
cm_set_basepri(u32 basepri);

extern u32
cm_get_msp(void);

extern void
cm_set_msp(u32 msp);

extern u32
cm_get_psp(void);

extern void
cm_set_psp(u32 psp);

extern u32
cm_get_control(void);

extern void
cm_set_control(u32 control);

extern void 
cm_isb(void);

extern void
cm_dsb(void);

extern void
cm_dmb(void);

extern void
cm_bkpt(void);

extern void
cm_ldrex(u32* addr);

extern u32
cm_strex(u32* addr, u32 value);

extern u32
cm_get_fpu_fpscr(void);

extern void
cm_set_fpu_fpscr(u32 value);

END_DECLARATIONS

#endif
