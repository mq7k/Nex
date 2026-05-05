#ifndef LIBTEST_TRAITS_HPP
#define LIBTEST_TRAITS_HPP

#include <type_traits>

namespace nextest 
{
  template <typename T, typename S, typename... Types>
  struct get_larger_type_of
  {
    using type = typename get_larger_type_of<
      std::conditional_t<(sizeof(T) > sizeof(S)), T, S>, 
      Types...
    >::type;
  };

  template <typename T, typename S>
  struct get_larger_type_of<T, S>
  {
    using type = std::conditional_t<(sizeof(T) > sizeof(S)), T, S>;
  };
}

#endif
