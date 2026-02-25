.section .text

.global cm_irq_enable
.type cm_irq_enable, %function
cm_irq_enable:
  cpsie i // Clears `PRIMASK` 
  isb
  bx lr

.global cm_irq_disable
.type cm_irq_disable, %function
cm_irq_disable:
  cpsid i // Sets `PRIMASK`
  isb
  bx lr

.global cm_faults_enable
.type cm_faults_enable, %function
cm_faults_enable:
  cpsie f // Clears register `FAULTMASK`
  isb
  bx lr

.global cm_faults_disable
.type cm_faults_disable, %function
cm_faults_disable:
  cpsid f // Sets `FAULTMASK`
  isb // Instruction Synchronization Barrier
  bx lr

.global cm_wfe
.type cm_wf3, %function
cm_wfe:
  wfe // Waits for event
  isb
  bx lr

.global cm_wfi
.type cm_wfi, %function
cm_wfi:
  wfi // Waits for interrupt
  isb
  bx lr

.global cm_get_primask
.type cm_get_primask, %function
cm_get_primask:
  mrs r0, PRIMASK // Reads `PRIMASK` and stores its value to r0
  bx lr

.global cm_get_faultmask
.type cm_get_faultmask, %function
cm_get_faultmask:
  mrs r0, FAULTMASK
  bx lr

.global cm_get_basepri
.type cm_get_basepri, %function
cm_get_basepri:
  mrs r0, BASEPRI
  bx lr

.global cm_set_basepri
.type cm_set_basepri, %function
cm_set_basepri:
  msr BASEPRI, r0 // Reads `r0` and stores its value to BASEPRI
  bx lr

.global cm_get_msp
.type cm_get_msp, %function
cm_get_msp:
  mrs r0, MSP
  bx lr

.global cm_set_msp
.type cm_set_msp, %function
cm_set_msp:
  msr MSP, r0
  bx lr

.global cm_get_psp
.type cm_get_psp, %function
cm_get_psp:
  mrs r0, PSP
  bx lr

.global cm_set_psp
.type cm_set_psp, %function
cm_set_psp:
  msr PSP, r0
  bx lr

.global cm_get_control
.type cm_get_control, %function
cm_get_control:
  mrs r0, CONTROL
  bx lr

.global cm_set_control
.type cm_set_control, %function
cm_set_control:
  msr CONTROL, r0
  bx lr

.global cm_isb
.type cm_isb, %function
cm_isb:
  isb
  bx lr

.global cm_dsb
.type cm_dsb, %function
cm_dsb:
  dsb
  bx lr

.global cm_dmb
.type cm_dmb, %function
cm_dmb:
  dmb
  bx lr

.global cm_bkpt
.type cm_bkpt, %function
cm_bkpt:
  bkpt
  bx lr

.global cm_ldrex
.type cm_ldrex, %function
cm_ldrex:
  ldrex r0, [r0]
  bx lr

.global cm_strex
.type cm_strex, %function
cm_strex:
  strex r2, r1, [r0]
  mov r0, r2
  bx lr

.global cm_get_fpu_fpscr
.type cm_get_fpu_fpscr, %function
cm_get_fpu_fpscr:
  vmrs r0, FPSCR
  bx lr

.global cm_set_fpu_fpscr
.type cm_set_fpu_fpscr, %function
cm_set_fpu_fpscr:
  vmsr FPSCR, r0
  bx lr
