#include "libtest/printutil.hpp"
#include "libtest/assertions.hpp"

namespace nextest
{
  void
  print_bitpos(
    FILE* fd
  )
  {
    fprintf(fd, "   ");
    for (u32 i = 0; i < 32; ++i)
    {
      fprintf(fd, "%3u", (32 - i - 1));
    }
    fprintf(fd, "\n");
  }

  void
  print_bin(
    FILE* fd,
    u32 val
  )
  {
    for (u32 i = 0; i < 32; ++i)
    {
      u32 bit = (val >> (32 - i - 1)) & 1;
      const char* color = bit ? term_color::green : term_color::red;
      std::fprintf(fd, "%s%-3u", color, bit);
    }
    std::fprintf(fd, "\033[0m\n");
  }

  void
  print_bin_compare(
    FILE* fd,
    u32 exp,
    u32 val
  )
  {
    constexpr size_t sz = sizeof(u32);

    print_bitpos(fd);
    std::fprintf(fd, "Exp: ");

    for (u32 i = 0; i < sz; ++i)
    {
      u32 exp_bit = (exp >> (sz - i - 1)) & 1;
      u32 val_bit = (val >> (sz - i - 1)) & 1;

      const char* color = exp_bit == val_bit ? term_color::green : term_color::red;
      std::fprintf(fd, "%s%-3u", color, exp_bit);
    }

    std::fprintf(fd, "%s\nVal: ", term_color::reset);

    for (u32 i = 0; i < sz; ++i)
    {
      u32 exp_bit = (exp >> (sz - i - 1)) & 1;
      u32 val_bit = (val >> (sz - i - 1)) & 1;

      const char* color = exp_bit == val_bit ? term_color::green : term_color::red;
      std::fprintf(fd, "%s%-3u", color, val_bit);
    }

    std::fprintf(fd, "%s\n", term_color::reset);
  }
}
