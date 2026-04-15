.syntax unified
.thumb
.thumb_func

.section .text

/*
 * void* memcpy(void* dst, void* src, u32 len)
 * r0 = void* dst
 * r1 = void* src
 * r2 = u32 len
 * No assumptions:
 * - dst and src maybe aligned to 1 byte;
 * - len may be divisible only by 1.
 * We are going to try our best.
 */
.global memcpy
.type memcpy, %function
memcpy:
  push { r5-r9, lr }
  mov r9, r0 

  // Check if len is a multiple of 4.
  ands r5, r2, #0x3
  beq memcpy_loop

  // Doing this now saves us from
  // using one more register, since
  // we are going to modify r5 in align_loop.
  mov r8, r5

  // We copy the number of bytes necessary (< 4) to reach
  // the next 4-bytes aligned address.
memcpy_align_loop:
  ldrb r6, [r1]
  strb r6, [r0]
  add r0, r0, #1
  add r1, r1, #1
  subs r5, r5, #1
  bne memcpy_align_loop

  // Handles cases where len < 4.
  subs r2, r2, r8
  beq memcpy_end

  // Now we can copy 4 bytes on each iteration.
memcpy_loop:
  ldr r6, [r1], #4
  str r6, [r0], #4
  subs r2, r2, #4
  bne memcpy_loop

memcpy_end:
  mov r0, r9
  pop { r5-r9, pc }

/*
 * void* memcpy16(void* dst, void* src, u32 len)
 * r0 = void* dst
 * r1 = void* src
 * r2 = u32 len
 * Assumptions:
 * - dst and src are aligned to 2 bytes;
 * - len is a multiple of 2;
 */
.global memcpy16
.type memcpy16, %function
memcpy16:
  push { r4, lr }
memcpy16_loop:
  ldrh r4, [r1], #2
  strh r4, [r0], #2
  subs r2, r2, #2
  bne memcpy16_loop
memcpy16_end:
  pop { r4, pc }

/*
 * void* memcpy32(void* dst, void* src, u32 len)
 * r0 = void* dst
 * r1 = void* src
 * r2 = u32 len
 * Assumptions:
 * - dst and src are aligned to 4 bytes;
 * - len is a multiple of 4;
 */
.global memcpy32
.type memcpy32, %function
memcpy32:
  push { r4, lr }
memcpy32_loop:
  ldr r4, [r1], #4
  str r4, [r0], #4
  subs r2, r2, #4
  bne memcpy32_loop
memcpy32_end:
  pop { r4, pc }

/*
 * void* memcpy32x2(void* dst, void* src, u32 len)
 * r0 = void* dst
 * r1 = void* src
 * r2 = u32 len
 * Assumptions:
 * - dst and src are aligned to 8 bytes;
 * - len is a multiple of 8;
 */
.global memcpy32x2
.type memcpy32x2, %function
memcpy32x2:
  push { r4-r6, lr }
memcpy32x2_loop:
  ldm r1!, { r4, r5 }
  stm r0!, { r4, r5 }
  add r1, r1, #8
  add r0, r0, #8
  subs r2, r2, #8
  bne memcpy32x2_loop
memcpy32x2_end:
  pop { r4-r6, pc }

/*
 * void* memcpy32x4(void* dst, void* src, u32 len)
 * r0 = void* dst
 * r1 = void* src
 * r2 = u32 len
 * Assumptions:
 * - dst and src are aligned to 16 bytes;
 * - len is a multiple of 16;
 */
.global memcpy32x4
.type memcpy32x4, %function
memcpy32x4:
  push { r4-r8, lr }
memcpy32x4_loop:
  ldm r1!, { r4-r7 }
  stm r0!, { r4-r7 }
  add r1, r1, #16
  add r0, r0, #16
  subs r2, r2, #16
  bne memcpy32x4_loop
memcpy32x4_end:
  pop { r4-r8, pc }

/*
 * void* memcpy32x8(void* dst, void* src, u32 len)
 * r0 = void* dst
 * r1 = void* src
 * r2 = u32 len
 * Assumptions:
 * - dst and src are aligned to 32 bytes;
 * - len is a multiple of 32;
 */
.global memcpy32x8
.type memcpy32x8, %function
memcpy32x8:
  push { r4-r11, lr }
  sub sp, sp, #4
memcpy32x8_loop:
  ldm r1!, { r4-r11 }
  stm r0!, { r4-r11 }
  add r1, r1, #32
  add r0, r0, #32
  subs r2, r2, #32
  bne memcpy32x8_loop
memcpy32x8_end:
  add sp, sp, #4
  pop { r4-r8, pc }
