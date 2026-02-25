#include "libtest/libtest.h"
#include "libcom/types.h"
#include "libcom/sys/devmode.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

static void
print_binary(
  u32 n,
  u32 c
); 

u32 membuf[MEM_BUF_SIZE];
i32 fail = 0;
u32 halted = 0;
char err_msg[4095] = {};
i32 errmsg_idx = 0;

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
    printf("Running test: '%s'...", test_func.test_name);
    fflush(stdout);

    test_func.func();

    if (fail)
    {
      ++fails;
      return 1;
    }

    if (halted)
    {
      puts(err_msg);
      exit(1);
    }

    printf(" \x1b[32mpassed!\n\x1b[0m");
  }

  printf("================================\n");
  printf("Total tests executed: %lu\n", count);
  printf("Tests passed: %lu\n", (count - fails));
  printf("Tests failed: %lu\n", fails);
  printf("================================\n");

  return 0;
}

void
reset_membuf(void)
{
  memset(membuf, 0, MEM_BUF_SIZE * sizeof(u32));
}

void __attribute__((weak))
setup(void)
{
}

void __attribute__((weak))
reset(void)
{
}

void
print_bin_compare(
  FILE* fd,
  u32 exp,
  u32 val
)
{
  print_bitpos(fd);

  fprintf(fd, "Exp: ");

  for (u32 i = 0; i < 32; ++i)
  {
    u32 exp_bit = (exp >> (32 - i - 1)) & 1;
    u32 val_bit = (val >> (32 - i - 1)) & 1;

    const char* color = exp_bit == val_bit ? "\033[32m" : "\033[31m";
    fprintf(fd, "%s%-3u", color, exp_bit);
  }

  fprintf(fd, "\033[0m\n");
  fprintf(fd, "Val: ");

  for (u32 i = 0; i < 32; ++i)
  {
    u32 exp_bit = (exp >> (32 - i - 1)) & 1;
    u32 val_bit = (val >> (32 - i - 1)) & 1;

    const char* color = exp_bit == val_bit ? "\033[32m" : "\033[31m";
    fprintf(fd, "%s%-3u", color, val_bit);
  }

  fprintf(fd, "\033[0m\n");
}

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
    const char* color = bit ? "\033[32m" : "\033[31m";
    fprintf(fd, "%s%-3u", color, bit);
  }
  fprintf(fd, "\033[0m\n");
}

void
print_register(
  u32 reg,
  struct register_bits* bits,
  u32 bits_count
)
{
  for (u32 i = 0; i < bits_count; ++i)
  {
    struct register_bits* bit = &bits[i];

    if (bit->count > 1)
    {
      printf("%s [%u:%u] = ", bit->name, bit->pos + bit->count - 1, bit->pos);
    }
    else
    {
      printf("%s [%u] = ", bit->name, bit->pos + bit->count - 1);
    }

    const u32 mask = (1u << bit->count) - 1;
    print_binary((reg >> bit->pos) & mask, bit->count);
    putchar('\n');
  }
}

static void
print_binary(
  u32 n,
  u32 c
) {
  printf("0b");
  for (u32 i = 0; i < c; ++i) {
      u32 k = c - i - 1;
      printf("%d", (n >> k) & 1);
      if (k % 8 == 0) putchar(' ');
  }
}

void
_devmode_logv(
  const char* fmt,
  va_list args
)
{
  errmsg_idx += vsprintf(
    &err_msg[errmsg_idx],
    fmt,
    args
  );
}

void
_devmode_halt(
  const struct devmode_trace* trace
)
{
  errmsg_idx += sprintf(
    &err_msg[errmsg_idx],
    "Halt at function: %s in file %s:%d\n",
    trace->func,
    trace->file,
    trace->line
  );

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
  err_msg[0] = 0;
  errmsg_idx = 0;
  halted = 0;
}

const char*
get_last_error_message(void)
{
  return err_msg;
}
