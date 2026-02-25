#ifndef NEX_TYPES_H
#define NEX_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef __WORDSIZE
  #define __WORDSIZE 32
#endif

#ifdef __INT64_TYPE__
  typedef int64_t i64;
  typedef uint64_t u64;

  #if __WORDSIZE == 64
    typedef int_fast64_t if64;
    typedef uint_fast64_t uf64;
  #endif

  typedef int_least64_t il64;
  typedef uint_least64_t ul64;
#endif

#ifdef __INT8_TYPE__
  typedef int8_t i8;
  typedef uint8_t u8;
  typedef int_fast8_t if8;
  typedef uint_fast8_t uf8;
  typedef int_least8_t il8;
  typedef uint_least8_t ul8;
#endif

#ifdef __INT16_TYPE__
  typedef int16_t i16;
  typedef uint16_t u16;
  typedef int_fast16_t if16;
  typedef uint_fast16_t uf16;
  typedef int_least16_t il16;
  typedef uint_least16_t ul16;
#endif

#ifdef __INT32_TYPE__
  typedef int32_t i32;
  typedef uint32_t u32;
  typedef int_fast32_t if32;
  typedef uint_fast32_t uf32;
  typedef int_least32_t il32;
  typedef uint_least32_t ul32;
#endif

#if __SIZEOF_LONG_DOUBLE__ == 16
  typedef long double f128;
#endif

#if __SIZEOF_DOUBLE__ == 8
  typedef double f64;
#endif

#if __SIZEOF_FLOAT__ == 4
  typedef float f32;
#endif

typedef uintptr_t uptr;
typedef intptr_t iptr;

typedef void (*function_t)(void);

#endif
