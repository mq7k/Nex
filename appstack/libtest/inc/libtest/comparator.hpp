#ifndef LIBTEST_COMPARATOR_H
#define LIBTEST_COMPARATOR_H

#include "libcom/types.h"
#include "libtest/testtraits.hpp"

#include <cmath>
#include <cstring>
#include <limits>
#include <type_traits>
#include <utility>

namespace nextest
{
  template <typename T>
  concept is_char_ptr = 
    std::is_pointer_v<T> && 
    std::is_same_v<std::remove_const_t<std::remove_pointer_t<T>>, char>;

  template <typename T, typename S>
  requires (
    std::is_integral_v<T> && std::is_integral_v<S> &&
    !(std::is_same_v<T, bool> || std::is_same_v<S, bool>)
  )
  i32
  compare(
    T t,
    S s
  )
  {
    if constexpr (std::is_same_v<T, char> || std::is_same_v<S, char>)
    {
      i32 tv = static_cast<i32>(t);
      i32 sv = static_cast<i32>(s);

      if (std::cmp_equal(tv, sv))
      {
        return 0;
      }

      return std::cmp_greater(tv, sv) ? 1 : -1;
    }
    else
    {
      if (std::cmp_equal(t, s))
      {
        return 0;
      }

      return std::cmp_greater(t, s) ? 1 : -1;
    }
  }

  template <typename T, typename S>
  requires std::is_same_v<T, bool> || std::is_same_v<S, bool>
  i32
  compare(
    T t,
    S s
  )
  {
    return compare<u32, u32>(static_cast<u32>(t), static_cast<u32>(s));
  }

  template <typename T, typename S>
  requires is_char_ptr<T> && is_char_ptr<S>
  i32
  compare(
    T t,
    S s
  )
  {
    return std::strcmp(t, s);
  }

  template <typename T, typename S>
  requires std::is_enum_v<T> || std::is_enum_v<S>
  i32
  compare(
    T t,
    S s
  )
  {
    using utype = typename std::underlying_type_t<S>;

    utype a = static_cast<utype>(t);
    utype b = static_cast<utype>(s);
    
    if (std::cmp_equal(a, b))
    {
      return 0;
    }

    return a > b ? 1 : -1;
  }

  template <typename T, typename S>
  requires std::is_floating_point_v<T> || std::is_floating_point_v<S>
  i32
  compare(
    T t,
    S s
  )
  {
    using ftype = typename nextest::get_larger_type_of<T, S>::type;

    const ftype eps = std::numeric_limits<ftype>::epsilon();
    const ftype v = static_cast<ftype>(t);
    const ftype e = static_cast<ftype>(s);
    const long double delta = std::fminl(std::fabsl(v), std::fabsl(e)) * eps;
    const long double diff = std::fabsl(v - e);

    if (diff < delta)
    {
      return 0;
    }

    return v > e ? 1 : -1;
  }

  template <typename T, typename S>
  requires (
    std::is_pointer_v<T> && std::is_pointer_v<S> &&
    !nextest::is_char_ptr<T> && nextest::is_char_ptr<S>
  )
  i32
  compare(
    T t,
    S s
  )
  {
    if (t == s)
    {
      return 0;
    }

    return t > s ? 1 : -1;
  }
}

#endif
