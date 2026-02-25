#ifndef LIBTEST_HPP
#define LIBTEST_HPP

#include "common/types.h"

#include <iostream>
#include <string_view>
#include <vector>

#define TESTS_RUN(arr) do_tests_run(arr, sizeof(arr) / sizeof(arr[0]))
// #define TEST_FUNC(func_name) { .func = func_name, .test_name = #func_name }
#define TEST_FUNC(func_name) test_function(func_name, #func_name)

#define add_test_case(tc, func) tc.add(func, #func)

#define MEM_BUF_SIZE 4096
extern u32 membuf[MEM_BUF_SIZE];

typedef void (*function_t)(void);

void
setup(void);

void
reset_membuf(void);

class test_function
{
  public:
    test_function(
      function_t func,
      const char* test_name
    ) :
      func(func),
      test_name(test_name)
  {
  }

  void
  operator()() const
  {
    func();
  }

  std::string_view
  name() const
  {
    return test_name;
  }

  private:
    function_t func;
    std::string_view test_name;
};

class test_cases
{
  public:
    u32
    run()
    {
      setup();

      size_t fails = 0;
      for (auto& func : functions)
      {
        reset_membuf();

        std::printf("Running test: '%s'...", func.name().data());
        std::cout.flush();

        try {
          func();
        }
        catch (std::runtime_error& e)
        {
          std::cout << e.what() << "\n";
          return 1;
        }

        std::printf(" \x1b[32mpassed!\n\x1b[0m");
      }

      std::printf("================================\n");
      std::printf("Total tests executed: %lu\n", functions.size());
      std::printf("Tests passed: %lu\n", (functions.size() - fails));
      std::printf("Tests failed: %lu\n", fails);
      std::printf("================================\n");

      return 0;
    }

    void
    add(const char* name, function_t func)
    {
      functions.emplace_back(name, func);
    }

  private:
    std::vector<test_function> functions;
};

int 
do_tests_run(
  const test_function* arr,
  u32 count
);

#endif
