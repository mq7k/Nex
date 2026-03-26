#ifndef LIBTEST_PRINTUTIL_H
#define LIBTEST_PRINTUTIL_H

#include "libtest/comparator.hpp"
#include <cstdio>
#include <type_traits>
#include "types.h"

namespace term_color
{
  constexpr const char* reset = "\033[0m";
  constexpr const char* red = "\033[31m";
  constexpr const char* green = "\033[32m";
};

namespace nextest
{
  void
  print_bitpos(
    FILE* fd
  );

  void
  print_bin_compare(
    FILE* fd,
    u32 exp,
    u32 value
  );

  void
  print_bin(
    FILE* fd,
    u32 val
  );

  template <typename T>
  requires (std::is_integral_v<T> && std::is_signed_v<T>)
  void 
  _print(
    T t
  )
  {
    std::fprintf(stderr, "%ld", static_cast<i64>(t));
  }

  template <typename T>
  requires (std::is_integral_v<T> && std::is_unsigned_v<T>)
  void 
  _print(
    T t
  )
  {
    std::fprintf(stderr, "%lu", static_cast<u64>(t));
  }

  template <typename T>
  requires (std::is_floating_point_v<T>)
  void 
  _print(
    T t
  )
  {
    std::fprintf(stderr, "%Lf", static_cast<long double>(t));
  }

  template <typename T>
  requires nextest::is_char_ptr<T>
  void _print(
    T t
  )
  {
    std::fprintf(stderr, "\"%s\"", t);
  }

  template <typename T>
  requires (std::is_pointer_v<T> && !nextest::is_char_ptr<T>)
  void 
  _print(
    T t
  )
  {
    std::fprintf(stderr, "%p", static_cast<void*>(t));
  }

  template <typename T>
  requires std::is_enum_v<T>
  void 
  _print(
    T t
  )
  {
    using utype = typename std::underlying_type_t<T>;

    if constexpr (std::is_signed_v<utype>)
    {
      std::fprintf(stderr, "%ld", static_cast<i64>(t));
    }
    else
    {
      std::fprintf(stderr, "%lu", static_cast<u64>(t));
    }
  }
}

#endif
