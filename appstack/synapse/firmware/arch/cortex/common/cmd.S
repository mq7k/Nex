.section .text

.global cm_irq_enable
.type cm_irq_enable, %function
cm_irq_enable:
  ret

.global cm_irq_disable
.type cm_irq_disable, %function
cm_irq_disable:
  ret

.global cm_faults_enable
.type cm_faults_enable, %function
cm_faults_enable:
  ret

.global cm_faults_disable
.type cm_faults_disable, %function
cm_faults_disable:
  ret

.global cm_wfe
.type cm_wf3, %function
cm_wfe:
  ret

.global cm_wfi
.type cm_wfi, %function
cm_wfi:
  ret

.global cm_get_primask
.type cm_get_primask, %function
cm_get_primask:
  mov $0, %eax
  ret

.global cm_get_faultmask
.type cm_get_faultmask, %function
cm_get_faultmask:
  mov $0, %eax
  ret

.global cm_get_basepri
.type cm_get_basepri, %function
cm_get_basepri:
  mov $0, %eax
  ret

.global cm_set_basepri
.type cm_set_basepri, %function
cm_set_basepri:
  mov $0, %eax
  ret

.global cm_get_msp
.type cm_get_msp, %function
cm_get_msp:
  mov $0, %eax
  ret

.global cm_set_msp
.type cm_set_msp, %function
cm_set_msp:
  ret

.global cm_get_psp
.type cm_get_psp, %function
cm_get_psp:
  mov $0, %eax
  ret

.global cm_set_psp
.type cm_set_psp, %function
cm_set_psp:
  ret

.global cm_get_control
.type cm_get_control, %function
cm_get_control:
  mov $0, %eax
  ret

.global cm_set_control
.type cm_set_control, %function
cm_set_control:
  ret

.global cm_isb
.type cm_isb, %function
cm_isb:
  ret

.global cm_dsb
.type cm_dsb, %function
cm_dsb:
  ret

.global cm_dmb
.type cm_dmb, %function
cm_dmb:
  ret

.global cm_bkpt
.type cm_bkpt, %function
cm_bkpt:
  ret

.global cm_ldrex
.type cm_ldrex, %function
cm_ldrex:
  ret

.global cm_strex
.type cm_strex, %function
cm_strex:
  ret

.global cm_get_fpu_fpscr
.type cm_get_fpu_fpscr, %function
cm_get_fpu_fpscr:
  mov $0, %eax
  ret

.global cm_set_fpu_fpscr
.type cm_set_fpu_fpscr, %function
cm_set_fpu_fpscr:
  ret
