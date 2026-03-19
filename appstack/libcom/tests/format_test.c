#include "libcom/format.h"
#include "libtest/libtest.h"
#include <limits.h>

#define BUFSZ (512)
char buf[BUFSZ] = {};
u32 idx = 0;

void
_callback(
  volatile void*,
  char c
)
{
  buf[idx++] = c;
}

void
reset(void)
{
  memset(buf, 0, BUFSZ);
  idx = 0;
}

void
test_format_signed_int_stream(void)
{
  i32 value; 
  u32 written;

  value = 0;
  written = nex_format_signed_int_stream(value, _callback, NULL);
  ASSERT_EQ(written, 1);
  ASSERT_EQ_STR(buf, "0", 1);

  reset();
  value = -1;
  written = nex_format_signed_int_stream(value, _callback, NULL);
  ASSERT_EQ(written, 2);
  ASSERT_EQ_STR(buf, "-1", 2);

  reset();
  value = INT_MIN;
  written = nex_format_signed_int_stream(value, _callback, NULL);
  ASSERT_EQ(written, 11);
  ASSERT_EQ_STR(buf, "-2147483648", 11);

  reset();
  value = INT_MAX;
  written = nex_format_signed_int_stream(value, _callback, NULL);
  ASSERT_EQ(written, 10);
  ASSERT_EQ_STR(buf, "2147483647", 10);
}

void
test_format_unsigned_int_stream(void)
{
  u32 value; 
  u32 written;

  value = 0;
  written = nex_format_unsigned_int_stream(value, _callback, NULL);
  ASSERT_EQ(written, 1);
  ASSERT_EQ_STR(buf, "0", 1);

  reset();
  value = UINT_MAX;
  written = nex_format_unsigned_int_stream(value, _callback, NULL);
  ASSERT_EQ(written, 10);
  ASSERT_EQ_STR(buf, "4294967295", 10);
}

void
test_format_signed_long_stream(void)
{
  i64 value; 
  u32 written;

  value = 0;
  written = nex_format_signed_long_stream(value, _callback, NULL);
  ASSERT_EQ(written, 1);
  ASSERT_EQ_STR(buf, "0", 1);

  reset();
  value = -1;
  written = nex_format_signed_long_stream(value, _callback, NULL);
  ASSERT_EQ(written, 2);
  ASSERT_EQ_STR(buf, "-1", 2);

  reset();
  value = LONG_MIN;
  written = nex_format_signed_long_stream(value, _callback, NULL);
  ASSERT_EQ(written, 20);
  ASSERT_EQ_STR(buf, "-9223372036854775808", 20);

  reset();
  value = LONG_MAX;
  written = nex_format_signed_long_stream(value, _callback, NULL);
  ASSERT_EQ(written, 19);
  ASSERT_EQ_STR(buf, "9223372036854775807", 19);
}

void
test_format_unsigned_long_stream(void)
{
  u64 value; 
  u32 written;

  value = 0;
  written = nex_format_unsigned_long_stream(value, _callback, NULL);
  ASSERT_EQ(written, 1);
  ASSERT_EQ_STR(buf, "0", 1);

  reset();
  value = ULONG_MAX;
  written = nex_format_unsigned_long_stream(value, _callback, NULL);
  ASSERT_EQ(written, 20);
  ASSERT_EQ_STR(buf, "18446744073709551615", 20);
}

void
test_format_double_stream(void)
{
  double value;
  u32 written;

  value = 0.0;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 9);
  ASSERT_EQ_STR(buf, "0.0000000", 9);

  reset();
  value = 1.0;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 9);
  ASSERT_EQ_STR(buf, "1.0000000", 9);

  reset();
  value = -1.0;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 10);
  ASSERT_EQ_STR(buf, "-1.0000000", 10);

  reset();
  value = 0.56;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 9);
  ASSERT_EQ_STR(buf, "0.5600000", 9);

  reset();
  value = -0.56;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 10);
  ASSERT_EQ_STR(buf, "-0.5600000", 10);

  reset();
  value = 15.8;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 10);
  ASSERT_EQ_STR(buf, "15.8000000", 10);

  reset();
  value = -15.85;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 11);
  ASSERT_EQ_STR(buf, "-15.8500000", 11);

  reset();
  value = (double) UINT_MAX + 1;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 18);
  ASSERT_EQ_STR(buf, "4294967296.0000000", 18);

  reset();
  value = (double) INT_MIN;
  written = nex_format_double_stream(value, _callback, NULL);
  ASSERT_EQ(written, 19);
  ASSERT_EQ_STR(buf, "-2147483648.0000000", 19);
}

void
test_format_hex_stream(void)
{
  u32 value;
  u32 written;

  const char* arr = "0123456789abcdef";
  for (u32 i = 0; i < strlen(arr); ++i)
  {
    reset();
    value = i;
    written = nex_format_hex_stream(value, _callback, NULL);
    ASSERT_EQ(written, 1);
    ASSERT_EQ_STR(buf, &arr[i], 1);
  }

  value = UINT_MAX;
  written = nex_format_hex_stream(value, _callback, NULL);
  ASSERT_EQ(written, 8);
  ASSERT_EQ_STR(buf, "ffffffff", 8);
}

void
test_format_bin_stream(void)
{
  u32 value;
  u32 written;

  value = 0;
  written = nex_format_binary_stream(value, _callback, NULL);
  ASSERT_EQ(written, 1);
  ASSERT_EQ_STR(buf, "0", 1);

  reset();
  value = 1;
  written = nex_format_binary_stream(value, _callback, NULL);
  ASSERT_EQ(written, 1);
  ASSERT_EQ_STR(buf, "1", 1);

  reset();
  value = 170;
  written = nex_format_binary_stream(value, _callback, NULL);
  ASSERT_EQ(written, 8);
  ASSERT_EQ_STR(buf, "10101010", 8);

  reset();
  value = UINT_MAX;
  written = nex_format_binary_stream(value, _callback, NULL);
  ASSERT_EQ(written, 32);
  ASSERT_EQ_STR(buf, "11111111111111111111111111111111", 32);
}

void
test_format_boolean_stream(void)
{
  u32 value;
  u32 written;

  value = 0;
  written = nex_format_boolean_stream(value, _callback, NULL);
  ASSERT_EQ(written, 5);
  ASSERT_EQ_STR(buf, "false", 5);

  reset();
  value = 1;
  written = nex_format_boolean_stream(value, _callback, NULL);
  ASSERT_EQ(written, 4);
  ASSERT_EQ_STR(buf, "true", 4);

  reset();
  value = UINT_MAX;
  written = nex_format_boolean_stream(value, _callback, NULL);
  ASSERT_EQ(written, 4);
  ASSERT_EQ_STR(buf, "true", 4);
}

void
test_format_str_stream(void)
{
  u32 written;

  reset();
  written = nex_format_str_stream(_callback, NULL, "", "First", 25, "Second");
  ASSERT_EQ(written, 1);
  ASSERT_EQ_STR(buf, "", 1);

  reset();
  written = nex_format_str_stream(_callback, NULL, "%s", "Hello");
  ASSERT_EQ(written, 6);
  ASSERT_EQ_STR(buf, "Hello", 6);

  reset();
  written = nex_format_str_stream(_callback, NULL, "Hello %s", "John");
  ASSERT_EQ(written, 11);
  ASSERT_EQ_STR(buf, "Hello John", 11);

  reset();
  written = nex_format_str_stream(_callback, NULL, "Hello %s, I am %u", "John", 25);
  ASSERT_EQ(written, 20);
  ASSERT_EQ_STR(buf, "Hello John, I am 25", 20);

  reset();
  written = nex_format_str_stream(_callback, NULL, "%s%s", "First", "Second");
  ASSERT_EQ(written, 12);
  ASSERT_EQ_STR(buf, "FirstSecond", 12);

  reset();
  written = nex_format_str_stream(_callback, NULL, "%s%u%s", "First", 25, "Second");
  ASSERT_EQ(written, 14);
  ASSERT_EQ_STR(buf, "First25Second", 14);

  reset();
  written = nex_format_str_stream(_callback, NULL, "%", 20);
  ASSERT_EQ(written, 2);
  ASSERT_EQ_STR(buf, "?", 2);

  reset();
  written = nex_format_str_stream(_callback, NULL, "%%", 20);
  ASSERT_EQ(written, 2);
  u32 c = (u32) buf[0];
  u32 e = '%';
  ASSERT_EQ(c, e);
}

int 
main() 
{
  const test_function_t tests[] = {
    TEST_FUNC(test_format_signed_int_stream),
    TEST_FUNC(test_format_unsigned_int_stream),
    TEST_FUNC(test_format_signed_long_stream),
    TEST_FUNC(test_format_unsigned_long_stream),
    TEST_FUNC(test_format_double_stream),
    TEST_FUNC(test_format_hex_stream),
    TEST_FUNC(test_format_bin_stream),
    TEST_FUNC(test_format_boolean_stream),
    TEST_FUNC(test_format_str_stream),
  };

  return TESTS_RUN(tests);
}
