#ifndef LIBTEST_ASSERTIONS_HPP
#define LIBTEST_ASSERTIONS_HPP

#include "libtest/comparator.hpp"
#include "libtest/printutil.hpp"

#include "libcom/types.h"

#include <cstdlib>
#include <source_location>

#define ASSERT_TRUE(value)\
  nextest::assert_true(\
    value,\
    #value " == true",\
    #value\
  )

#define ASSERT_FALSE(value)\
  nextest::assert_false(\
    value,\
    #value " == false",\
    #value\
  )

#define ASSERT_NON_NULL(ptr)\
  nextest::assert_non_null(\
    ptr,\
    #ptr " != NULL",\
    #ptr\
  )

#define ASSERT_NULL(ptr)\
  nextest::assert_null(\
    ptr,\
    #ptr " == NULL",\
    #ptr\
  )

#define ASSERT_EQ(value, expected)\
  nextest::assert_eq(\
    value,\
    expected,\
    #value " == " #expected,\
    #value,\
    #expected\
  )

#define ASSERT_NOT_EQ(value, expected)\
  nextest::assert_not_eq(\
    value,\
    expected,\
    #value " != " #expected,\
    #value,\
    #expected\
  )

#define ASSERT_GT(value, expected)\
  nextest::assert_gt(\
    value,\
    expected,\
    #value " > " #expected,\
    #value,\
    #expected\
  )

#define ASSERT_GT_OR_EQ(value, expected)\
  nextest::assert_gt(\
    value,\
    expected,\
    #value " >= " #expected,\
    #value,\
    #expected\
  )

#define ASSERT_LS(value, expected)\
  nextest::assert_ls(\
    value,\
    expected,\
    #value " < " #expected,\
    #value,\
    #expected\
  )

#define ASSERT_LS_OR_EQ(value, expected)\
  nextest::assert_ls_or_eq(\
    value,\
    expected,\
    #value " <= " #expected,\
    #value,\
    #expected\
  )

#define ASSERT_OFFSET(periph, reg, offset)\
  ASSERT_EQ(offsetof(periph, reg), offset)

#define ABORT(message) nextest::abort(message)

namespace nextest
{
  template <typename T>
  void
  print_test_var(
    const char* varname,
    T t
  )
  {
    std::fprintf(stderr, "%s: ", varname);
    print_var(t);
    std::fprintf(stderr, "\n");
  }

  template <typename T, typename S>
  void
  handle_assert_fail(
    T value,
    S expected,
    const char* condition,
    const char* value_var_name,
    const char* expected_var_name,
    std::source_location loc
  )
  {
    std::fprintf(stderr, "\n===============\n");
    std::fprintf(stderr, "%sAssertion failed.%s\n", term_color::red, term_color::reset);
    std::fprintf(stderr, ">> In function %s (%s:%u)\n", loc.file_name(), loc.file_name(), loc.line());
    std::fprintf(stderr, "Condition: %s\n", condition);

    print_test_var(value_var_name, value);

    if (std::strlen(expected_var_name) > 0)
    {
      print_test_var(expected_var_name, expected);
    }

    if constexpr (std::is_same_v<u32, T> && std::is_same_v<u32, S>)
    {
      nextest::print_bin_compare(stderr, expected, value);
    }

    std::fprintf(stderr, "===============\n");
    std::exit(1);
  }

  template <typename T, typename S>
  void 
  assert_eq(
    T value,
    S expected,
    const char* condition,
    const char* value_var_name,
    const char* expected_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    i32 result = nextest::compare(value, expected);
    if (result != 0)
    {
      handle_assert_fail(value, expected, condition, value_var_name, expected_var_name, loc);
    }
  }

  template <typename T, typename S>
  void
  assert_not_eq(
    T value,
    S expected,
    const char* condition,
    const char* value_var_name,
    const char* expected_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    i32 result = nextest::compare(value, expected);
    if (result == 0)
    {
      handle_assert_fail(value, expected, condition, value_var_name, expected_var_name, loc);
    }
  }

  template <typename T, typename S>
  void
  assert_gt(
    T value,
    S expected,
    const char* condition,
    const char* value_var_name,
    const char* expected_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    i32 result = nextest::compare(value, expected);
    if (!(result > 0))
    {
      handle_assert_fail(value, expected, condition, value_var_name, expected_var_name, loc);
    }
  }

  template <typename T, typename S>
  void
  assert_gt_or_eq(
    T value,
    S expected,
    const char* condition,
    const char* value_var_name,
    const char* expected_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    i32 result = nextest::compare(value, expected);
    if (!(result >= 0))
    {
      handle_assert_fail(value, expected, condition, value_var_name, expected_var_name, loc);
    }
  }

  template <typename T, typename S>
  void
  assert_ls(
    T value,
    S expected,
    const char* condition,
    const char* value_var_name,
    const char* expected_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    i32 result = nextest::compare(value, expected);
    if (!(result < 0))
    {
      handle_assert_fail(value, expected, condition, value_var_name, expected_var_name, loc);
    }
  }

  template <typename T, typename S>
  void
  assert_ls_or_eq(
    T value,
    S expected,
    const char* condition,
    const char* value_var_name,
    const char* expected_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    i32 result = nextest::compare(value, expected);
    if (!(result <= 0))
    {
      handle_assert_fail(value, expected, condition, value_var_name, expected_var_name, loc);
    }
  }

  template <typename T>
  requires std::is_pointer_v<T>
  void
  assert_null(
    T t,
    const char* condition,
    const char* value_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    if (t != nullptr)
    {
      handle_assert_fail(t, NULL, condition, value_var_name, "", loc);
    }
  }

  template <typename T>
  requires std::is_pointer_v<T>
  void
  assert_non_null(
    T t,
    const char* condition,
    const char* value_var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    if (t == nullptr)
    {
      handle_assert_fail(t, NULL, condition, value_var_name, "", loc);
    }
  }

  template <typename T>
  void
  assert_true(
    T t,
    const char* condition,
    const char* var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    if (!t)
    {
      handle_assert_fail(t, true, condition, var_name, "", loc);
    }
  }

  template <typename T>
  void
  assert_false(
    T t,
    const char* condition,
    const char* var_name,
    const std::source_location loc = std::source_location::current()
  )
  {
    if (t)
    {
      handle_assert_fail(t, false, condition, var_name, "", loc);
    }
  }

  inline void
  abort(
    const char* msg,
    const std::source_location loc = std::source_location::current()
  )
  {
    std::fprintf(stderr, "\n===============\n");

    std::fprintf(
      stderr,
      "%sUnexpected condition:%s %s\n",
      term_color::red,
      term_color::reset,
      msg
    );

    std::fprintf(
      stderr,
      ">> In function %s (%s:%u)\n",
      loc.function_name(),
      loc.file_name(),
      loc.line()
    );

    std::fprintf(stderr, "===============\n");
    std::exit(1);
  }
}

#endif
