#ifndef LIBCOM_COMMON_H
#define LIBCOM_COMMON_H


// Clang defines both.
// GCC defines only __GNUC__.
// Unfortunately, we have to drop support for MSVC.
// Since it doesn't support __attribute__((weak)),
// and __pragma(comment(linker, "/alternatename")) isn't as
// handy to use, because macros cannot expand to a preprocessor
// directive, these is no way to achieve the same result.
#if !defined(__clang__) && !defined(__GNUC__)
#error "Unsupported compiler. Please use either GCC or Clang."
#endif

// 201103 = C++11
// 201112 = C11
#if (defined(__cplusplus) && __cplusplus < 201103) ||\
  (!defined(__cplusplus) && __STDC_VERSION__ < 201112)
#error "Unsupported language standard. Please use C11 / C++11 or newer."
#endif

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
#define NEX_WEAK_ALIAS(name) __attribute__((weak, alias(name)))
#define NEX_SECTION(name) __attribute__((section(name)))

#define FAST_MOD(a, b) ((a) & ((b) - 1))
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define MEMPTR(x) *((volatile uintptr_t*) (x))

#define NEX_SUCCESS (0)
#define NEX_FAILURE (1)

#define BIT(pos) (1u << (pos))

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

u32
nex_murmur_hash3_fmix32(
  u32 value
);

END_DECLARATIONS

#endif
