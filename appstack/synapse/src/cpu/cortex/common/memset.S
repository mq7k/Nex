.syntax unified
.thumb
.thumb_func

.section .text

/*
 * void* memset(void* dst, u8 byte, u32 len)
 * r0 = void* dst
 * r1 = u8 byte
 * r2 = u32 len
 * No assumptions:
 * - dst maybe aligned to 1 byte;
 * - len may be divisible only by 1.
 * We are going to try our best.
 */
.global memset
.type memset, %function
memset:
  push { r4-r11, lr }
  sub sp, sp, #4
  str r0, [sp, #0]

  // Repeating the provided byte 4 times.
  orr r3, r1, r1, lsl #8
  orr r3, r3, r3, lsl #16

  // Check if len is a multiple of 4.
  ands r5, r2, #0x3
  mov r8, r5
  beq memset_loop_entry
memset_align_loop:
  strb r1, [r0]
  add r0, r0, #1
  subs r5, r5, #1
  bne memset_align_loop

  // Handles cases where len < 4.
  subs r2, r2, r8
  beq memset_end
memset_loop_entry:
  mov r4, r3
  mov r5, r3
  mov r6, r3
  mov r7, r3
memset_loop:
  stm r0!, { r4 }
  subs r2, r2, #4
  bne memset_loop
memset_end:
  ldr r0, [sp, #0]
  add sp, sp, #4
  mvn r6, r6
  pop { r4-r11, pc }

/*
 * void* memset16(void* dst, u8 byte, u32 len)
 * r0 = void* dst
 * r1 = u8 byte
 * r2 = u32 len
 * Assumptions:
 * - dst is aligned at 2 bytes;
 * - len is a multiple of 2;
 * We can copy 2 bytes per iteration.
 */
.global memset16
.type memset16, %function
memset16:
  push { r4, lr }
  orr r1, r1, r1, lsl #8

memset16_loop:
  strh r1, [r0]
  add r0, #2
  subs r2, #2
  bne memset16_loop

memset16_end:
  pop { r4, pc }

/*
 * void* memset32(void* dst, u8 byte, u32 len)
 * r0 = void* dst
 * r1 = u8 byte
 * r2 = u32 len
 * Assumptions:
 * - dst is aligned at 4 bytes;
 * - len is a multiple of 4;
 * We can copy 4 bytes per iteration.
 */
.global memset32
.type memset32, %function
memset32:
  push { r4, lr }
  orr r1, r1, r1, lsl #8
  orr r1, r1, r1, lsl #16

memset32_loop:
  str r1, [r0]
  add r0, #4
  subs r2, #4
  bne memset32_loop

memset32_end:
  pop { r4, pc }

/*
 * void* memset32x2(void* dst, u8 byte, u32 len)
 * r0 = void* dst
 * r1 = u8 byte
 * r2 = u32 len
 * Assumptions:
 * - dst is aligned at 8 bytes;
 * - len is a multiple of 8;
 * We can copy 8 bytes per iteration.
 */
.global memset32x2
.type memset32x2, %function
memset32x2:
  push { r4-r6, lr }

  orr r1, r1, r1, lsl #8
  orr r1, r1, r1, lsl #16
  mov r4, r1
  mov r5, r1

memset32x2_loop:
  stm r0!, { r4, r5 }
  subs r2, #8
  bne memset32x2_loop

memset32x2_end:
  pop { r4-r6, pc }

/*
 * void* memset32x4(void* dst, u8 byte, u32 len)
 * r0 = void* dst
 * r1 = u8 byte
 * r2 = u32 len
 * Assumptions:
 * - dst is aligned at 16 bytes;
 * - len is a multiple of 16;
 * We can copy 16 bytes per iteration.
 */
.global memset32x4
.type memset32x4, %function
memset32x4:
  push { r4-r8, lr }
  orr r1, r1, r1, lsl #8
  orr r1, r1, r1, lsl #16
  mov r4, r1
  mov r5, r1
  mov r6, r1
  mov r7, r1

memset32x4_loop:
  stm r0!, { r4-r8 }
  subs r2, #16
  bne memset32x4_loop

memset32x4_end:
  pop { r4-r8, pc }

/*
 * void* memset32x8(void* dst, u8 byte, u32 len)
 * r0 = void* dst
 * r1 = u8 byte
 * r2 = u32 len
 * Assumptions:
 * - dst is aligned at 32 bytes;
 * - len is a multiple of 32;
 * We can copy 32 bytes per iteration.
 */
.global memset32x8
.type memset32x8, %function
memset32x8:
  push { r4-r11, lr }
  sub sp, sp, #4
  orr r1, r1, r1, lsl #8
  orr r1, r1, r1, lsl #16
  mov r4, r1
  mov r5, r1
  mov r6, r1
  mov r7, r1
  mov r8, r1
  mov r9, r1
  mov r10, r1
  mov r11, r1

memset32x8_loop:
  stm r0!, { r4-r11 }
  subs r2, #32
  bne memset32x8_loop

memset32x8_end:
  add sp, sp, #4
  pop { r4-r11, pc }


