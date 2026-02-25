#ifndef LIBCOM_COMMON_H
#define LIBCOM_COMMON_H

#include "libcom/types.h"

#ifdef __cplusplus
  #define BEGIN_DECLARATIONS extern "C" { 
  #define END_DECLARATIONS  }
#else
  #define BEGIN_DECLARATIONS
  #define END_DECLARATIONS
#endif

BEGIN_DECLARATIONS

#define NEX_WEAK __attribute__((weak))
#define NEX_ALIAS(name) __attribute__((alias(name)))
#define NEX_WEAK_NEX_ALIAS(name) __attribute__((weak, alias(name)))

#if __STDC_VERSION__ >= 202000
// C23 or newer.
#define NEX_ALIGN_AS(value) alignas(value)
#else
// Older than C23.
#define NEX_ALIGN_AS(value) _Alignas(value)
#endif
// #define NEX_ALIGN(align) __attribute__((aligned(align)))
// #define NEX_ALIGN_AS(type) __attribute__((aligned(sizeof(type))))

#define FAST_MOD(a, b) ((a) & ((b) - 1))
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define MEMPTR(x) *((volatile uintptr_t*) (x))

#define NEX_SUCCESS (0)
#define NEX_FAILURE (1)

#define BIT(pos) (1u << (pos))

#define WAIT_UNTIL(condition) while ((condition) == 0)

u32
nex_is_power_of_two(
  u32 value
);

u32
nex_align_addr(
  u32 addr,
  u32 alignment
);

u32
nex_is_addr_aligned(
  void* addr,
  u32 alignment
);

END_DECLARATIONS

#endif
