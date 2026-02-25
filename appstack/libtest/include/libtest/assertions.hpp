#ifndef ASSERTION_HPP
#define ASSERTION_HPP

#include "common/types.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

#define ASSERT_EQ(value, expected) \
  assertion(value, #value, expected, #expected, __FILE__, __func__, __LINE__)\
  .assert_eq()

#define ASSERT_NOT_EQ(value, expected) \
  assertion(value, #value, expected, #expected, __FILE__, __func__, __LINE__)\
  .assert_not_eq()

#define ASSERT_GT(value, expected) \
  assertion(value, #value, expected, #expected, __FILE__, __func__, __LINE__)\
  .assert_gt()

#define ASSERT_GT_OR_EQ(value, expected) \
  assertion(value, #value, expected, #expected, __FILE__, __func__, __LINE__)\
  .assert_gt_or_eq()

#define ASSERT_LS(value, expected) \
  assertion(value, #value, expected, #expected, __FILE__, __func__, __LINE__)\
  .assert_ls()

#define ASSERT_LS_OR_EQ(value, expected) \
  assertion(value, #value, expected, #expected, __FILE__, __func__, __LINE__)\
  .assert_ls_or_eq()

#define ASSERT_TRUE(value) \
  assertion(value, #value, 0, "<int> 0", __FILE__, __func__, __LINE__)\
  .assert_gt()

#define ASSERT_FALSE(value) \
  assertion(value, #value, 0, "<int> 0", __FILE__, __func__, __LINE__)\
  .assert_eq()

#define ABORT(message, ...)\
  fprintf(stderr, "Unexpected condition reached.\n");\
  fprintf(stderr, ">>%s() at %s:%d\n", __func__, __FILE__, __LINE__);\
  fprintf(stderr, "Cause: " #message "\n", ##__VA_ARGS__)

template <class T>
class assertion
{
  public:
    assertion(const T& value) : value(value) {}

    void
    assert_eq()
    {
      if (value != expected)
      {
        do_fail("==");
      }
    }
    
    void
    assert_not_eq()
    {
      if (value == expected)
      {
        do_fail("!=");
      }
    }

    void
    assert_gt()
    {
      if (value <= expected)
      {
        do_fail(">");
      }
    }

    void
    assert_gt_or_eq()
    {
      if (value < expected)
      {
        do_fail(">=");
      }
    }

    void
    assert_ls()
    {
      if (value >= expected)
      {
        do_fail("<");
      }
    }

    void
    assert_ls_or_eq()
    {
      if (value > expected)
      {
        do_fail("<=");
      }
    }

    void
    do_fail(const char* op)
    {
      std::cerr << "\n===============\n";
      std::cerr << "\033[31mAssertion failed.\033[0m\n";
      std::cerr << ">> " << function << "() at " << file << ":" << line << "\n";
      std::cerr << "Condition: " << value_var_name << " " << op << " " << expected_var_name << "\n"; 
      std::cerr << value_var_name << " = " << value << "\n";
      std::cerr << expected_var_name << " = " << expected << "\n";
      std::cerr << "===============\n";

      throw std::runtime_error("Assertion failed.");
    }

  private:
    T value;
    T expected;
    const char* file;
    const char* function;
    u32 line;
    const char* value_var_name;
    const char* expected_var_name;
};

template <class... Args>
void
fail(const char* message, Args&&... args)
{
  std::cerr << "Unexpected condition reached.\n";
  std::cerr << ">>" << __func__ << "() at " << __FILE__ << ":" << __LINE__ << "\n";
  std::cerr << "Cause: ";
  std::fprintf(stderr, message, std::forward<Args...>(args...));
}

#endif
