.syntax unified
.thumb
.thumb_func

.section .text

// (x - 0x01010101) & ~x & 0x80808080
// is non-zero if any byte in x is zero.

/*
 * size_t strlen(const char* str)
 */
.global strlen
.type strlen, %function
strlen:
  push { r4-r8, lr } 
  mov r5, #0

  ands r4, r0, #0x3
  beq strlen_loop

strlen_align_loop:
  add r5, #1
  ldrb r6, [r0]
  cmp r6, #0
  beq strlen_end
  add r0, r0, #1
  subs r4, r4, #1
  bne strlen_align_loop

strlen_loop:
  ldr r6, [r0]
  sub r7, r6, #0x01010101
  mvn r6, r6
  and r6, #0x80808080
  and r8, r7, r6
  cmp r8, #0
  bne strlen_scan_word
  add r5, #4
  add r0, #4
  b strlen_loop

strlen_scan_word:
  lsr r7, r8, #24
  cmp r7, #0
  beq strlen_end

  add r5, #1
  lsr r7, r8, #16
  cmp r7, #0
  beq strlen_end

  add r5, #1
  lsr r7, r8, #8
  cmp r7, #0
  beq strlen_end

  add r5, #1
  
strlen_end:
  mov r0, r5
  pop { r4-r8, lr }

/*
 * size_t strlen8(const char* str)
 */
.global strlen8
.type strlen8, %function
strlen8:
  push { r4-r6, lr }
  mov r4, #0
  mov r5, #0
strlen8_loop:
  ldrb r4, [r0]
  cmp r4, #0
  beq strlen8_end
  add r5, #1
  add r0, #1
  b strlen8_loop
strlen8_end:
  mov r0, r5
  pop { r4-r6, pc }

/*
 * int strcmp(const char* a, const char* b)
 */
.global strcmp
.type strcmp, %function
strcmp:
  push { r4-r6, lr }

strcmp_loop:
  ldr r4, [r0]
  ldr r5, [r1]
  subs r6, r4, r5
  bne strcmp_end
  orrs r4, r5
  beq strcmp_end
  add r0, #4
  add r1, #4
  b strcmp_loop
strcmp_end:
  mov r0, r6
  pop { r4-r6, pc }

/*
 * int strcmp8(const char* a, const char* b)
 */
.global strcmp8
.type strcmp, %function
strcmp8:
  push { r4-r8, lr }
  mov r7, #0

strcmp8_loop:
  ldrb r4, [r0]
  ldrb r5, [r1]
  subs r6, r4, r5
  bne strcmp8_end
  orrs r8, r4, r5
  beq strcmp8_end
  add r0, #1
  add r1, #1
  add r7, #1
  b strcmp8_loop

strcmp8_end:
  mov r0, r6
  pop { r4-r8, pc }

/*
 * int strncmp(const char* a, const char* b, u32 len)
 */
.global strncmp
.type strncmp, %function
strncmp:
  push { r4-r10, lr }
  mov r7, #0

  ands r9, r2, #0x3
  mov r10, r9
  beq strncmp_loop

strncmp_align_loop:
  ldrb r4, [r0]
  ldrb r5, [r1]
  subs r6, r4, r5
  bne strncmp_end
  orrs r8, r4, r5
  beq strncmp_end
  add r0, #1
  add r1, #1
  add r7, #1
  subs r9, #1
  bne strncmp_align_loop

  subs r2, r2, r10
  beq strncmp_end

strncmp_loop:
  ldr r4, [r0]
  ldr r5, [r1]
  rev r4, r4
  rev r5, r5
  subs r6, r4, r5
  bne strncmp_end
  orrs r8, r4, r5
  beq strncmp_end
  add r0, #4
  add r1, #4
  add r7, #4
  subs r2, #4
  beq strncmp_end
  b strncmp_loop

strncmp_end:
  mov r0, r6
  pop { r4-r10, pc }

/*
 * int strncmp8(const char* a, const char* b, u32 len)
 */
.global strncmp8
.type strncmp8, %function
strncmp8:
  push { r4-r6, lr }
strncmp8_loop:
  ldrb r4, [r0]
  ldrb r5, [r1]
  subs r6, r4, r5
  bne strncmp8_end
  orrs r6, r4, r5
  beq strncmp8_end
  add r0, #1
  add r1, #1
  b strncmp8_loop
strncmp8_end:
  mov r0, r6
  pop { r4-r6, pc }

