#include "libtest/libtest.hpp"
#include "libtest/assertions.hpp"

#include "libcom/types.h"
#include "libcom/sys/devmode.h"
#include "util.h"

#include <cstdio>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

// Temporary buffer.
// It's reset after each test function.
u32 membuf[MEM_BUF_SIZE];

// Keeps track of devmode_halt() state.
u32 halted = 0;

// Temporary storage for devmode messages. 
std::vector<std::string> logs;

int 
do_tests_run(
  const test_function_t* arr,
  size_t count
)
{
  setup();

  size_t fails = 0;
  for (size_t i = 0; i < count; ++i)
  {
    reset_membuf();
    reset();

    test_function_t test_func = arr[i];
    std::printf("Running test: '%s'...", test_func.test_name);
    std::fflush(stdout);

    test_func.func();

    if (!logs.empty())
    {
      std::fprintf(stderr, "Unexpected devmode assertion failed.");
      for (const auto& str : logs)
      {
        std::fprintf(stderr, ">> %s", str.c_str());
      }

      std::exit(1);
    }

    std::printf(" %spassed!%s", term_color::green, term_color::reset);
    std::fflush(stdout);
  }

  std::printf("================================\n");
  std::printf("Total tests executed: %lu\n", count);
  std::printf("Tests passed: %lu\n", (count - fails));
  std::printf("Tests failed: %lu\n", fails);
  std::printf("================================\n");

  return 0;
}

void
reset_membuf(void)
{
  memset(membuf, 0, MEM_BUF_SIZE * sizeof(u32));
}

void NEX_WEAK
setup(void)
{
}

void NEX_WEAK
reset(void)
{
}

// Override default weak symbol.
void
_devmode_logv(
  const char* fmt,
  va_list args
)
{
  char buf[512];
  std::vsprintf(buf, fmt, args);

  // Log messages are split:
  // - [Error] Assertion in file ... in function ... :
  // - {Assertion message}
  // This is a stupid 'trick' to merge them together.
  if (logs.size() & 1)
  {
    logs.at(logs.size() - 1).append(buf);
  }
  else
  {
    logs.push_back(buf);
  }
}

// Override default weak symbol.
void
_devmode_halt(
  const struct devmode_trace*
)
{
  halted = 1;
}

u32
execution_halted(void)
{
  return halted;
}

void
execution_resume(void)
{
  halted = 0;

  // Clears stored logs.
  // They would abort the testing process
  // if still present after the test function 
  // has returned.
  logs.clear();
}

