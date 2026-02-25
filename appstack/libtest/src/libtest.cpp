#ifndef LIBTEST_CPP
#define LIBTEST_CPP

#include "libtest/libtest.hpp"
#include "common/types.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdexcept>

int 
do_tests_run(
  const test_function* arr,
  u32 count
)
{
  setup();

  size_t fails = 0;
  for (size_t i = 0; i < count; ++i)
  {
    reset_membuf();

    test_function test_func = arr[i];
    std::printf("Running test: '%s'...", test_func.name().data());
    std::cout.flush();

    try {
      test_func();
    }
    catch (std::runtime_error& e)
    {
      std::cout << e.what() << "\n";
      return 1;
    }

    std::printf(" \x1b[32mpassed!\n\x1b[0m");
  }

  std::printf("================================\n");
  std::printf("Total tests executed: %u\n", count);
  std::printf("Tests passed: %lu\n", (count - fails));
  std::printf("Tests failed: %lu\n", fails);
  std::printf("================================\n");

  return 0;
}

void
reset_membuf(void)
{
  std::memset(membuf, 0, MEM_BUF_SIZE * sizeof(u32));
}

void __attribute__((weak))
setup(void)
{
}

#endif
