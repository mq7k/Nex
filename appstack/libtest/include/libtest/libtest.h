#ifndef LIBTEST_H
#define LIBTEST_H

#include "libcom/types.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define handle_assert_fail(condition, value, exp, format)\
  fprintf(stderr, "\n===============\n");\
  fprintf(stderr, "\033[31mAssertion failed.\033[0m\n");\
  fprintf(stderr, ">> %s() at %s:%d\nCondition: " #condition ".\n", __func__, __FILE__, __LINE__);\
  fprintf(stderr, #value " = " #format "\n", value);\
  fprintf(stderr, #exp " = " #format "\n", exp);\
  print_bin_compare(stderr, exp, value);\
  fprintf(stderr, "===============\n")

#define ABORT(message, ...)\
  fprintf(stderr, "Unexpected condition reached.\n>>%s() at %s:%d\nCause: " #message "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__)

#define ASSERT_CONDITION(a, b, op)\
  do {\
    if (!((a) op (b)))\
    {\
      handle_assert_fail(a op b, a, b, "%u");\
      exit(1);\
    }\
  } while (0)

#define ASSERT_TRUE(value) ASSERT_CONDITION(value, 0, !=)
#define ASSERT_FALSE(value) ASSERT_CONDITION(value, 0, ==)
#define ASSERT_EQ(value, expected) ASSERT_CONDITION(value, expected, ==)
#define ASSERT_NOT_EQ(value, expected) ASSERT_CONDITION(value, expected, !=)
#define ASSERT_GT(value, expected) ASSERT_CONDITION(value, expected, >)
#define ASSERT_GT_OR_EQ(value, expected) ASSERT_CONDITION(value, expected, >=)
#define ASSERT_LS(value, expected) ASSERT_CONDITION(value, expected, <)
#define ASSERT_LS_OR_EQ(value, expected) ASSERT_CONDITION(value, expected, <=)
#define ASSERT_NONZERO(value) ASSERT_NOT_EQ(value, 0)
#define ASSERT_ZERO(value) ASSERT_EQ(value, 0)

#define TESTS_RUN(arr) do_tests_run(arr, sizeof(arr) / sizeof(arr[0]))
#define TEST_FUNC(func_name) { .func = func_name, .test_name = #func_name }

#define OFFSET_OF(type, field) ((u32)((u64)(&((type*)0)->field)))

#define MEM_BUF_SIZE 4096
extern u32 membuf[MEM_BUF_SIZE];

extern i32 fail;
typedef void (*function_t)(void);

typedef struct
{
  function_t func;
  const char* test_name;
} test_function_t;

struct test_enum_value_pair
{
  u32 value;
  u32 expected;
};

struct test_enum_value_triplet
{
  u32 key;
  u32 value;
  u32 expected;
};

struct register_bits
{
  const char* name;
  u32 pos;
  u32 count;
};

int 
do_tests_run(
  const test_function_t* arr,
  size_t count
);

void
reset_membuf(void);

void
setup(void);

void
reset(void);

void
print_bin_compare(
  FILE* fd,
  u32 exp,
  u32 value
);

void
print_bitpos(
  FILE* fd
);

void
print_bin(
  FILE* fd,
  u32 val
);

void
print_register(
  u32 reg,
  struct register_bits* bits,
  u32 bits_count
);

u32
execution_halted(void);

void
execution_resume(void);

const char*
get_last_error_message(void);

#endif
