.section .text

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
