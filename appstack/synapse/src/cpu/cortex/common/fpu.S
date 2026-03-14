.section .text

#if defined(NEX_PLATFORM_ARM)

#if defined(NEX_FPU)
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

// We don't define them if '--float=soft'.
// This should prevent silent bugs from happening.
// A compile-time error is better than a runtime crash.

#endif

#else

// x84_64 implementation (adapter).
.global cm_get_fpu_fpscr
.type cm_get_fpu_fpscr, %function
cm_get_fpu_fpscr:
  mov $0, %eax
  ret

.global cm_set_fpu_fpscr
.type cm_set_fpu_fpscr, %function
cm_set_fpu_fpscr:
  ret

#endif
