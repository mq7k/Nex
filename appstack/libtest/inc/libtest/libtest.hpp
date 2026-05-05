#ifndef LIBTEST_H
#define LIBTEST_H

#include "libcom/types.h"
#include "libcom/util.h"
#include "libtest/assertions.hpp"

#include <cstdio>
#include <cstring>

#define TESTS_RUN(arr) do_tests_run(arr, sizeof(arr) / sizeof(arr[0]))
#define TEST_FUNC(func_name) { .func = func_name, .test_name = #func_name }

#define MEM_BUF_SIZE (4096)
extern u32 membuf[MEM_BUF_SIZE];

typedef struct
{
  function_t func;
  const char* test_name;
} test_function_t;

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

u32
execution_halted(void);

void
execution_resume(void);

#endif

