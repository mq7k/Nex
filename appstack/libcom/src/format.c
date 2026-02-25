#include "libcom/format.h"
#include "libcom/types.h"

static u32
_stream_str(
  const char* str,
  formatter_callback callback,
  volatile void* ctx
)
{
  u32 count = 0;
  while (*str)
  {
    callback(ctx, *str);
    ++count;
    ++str;
  }

  return count;
}

u32
nex_format_str_stream(
  formatter_callback callback,
  volatile void* ctx,
  const char* fmt,
  ...
)
{
  va_list args;
  va_start(args, fmt);
  u32 chars_written = nex_format_va_args_stream(callback, ctx, fmt, args);
  va_end(args);
  return chars_written;
}

u32
nex_format_va_args_stream(
  formatter_callback callback,
  volatile void* ctx,
  const char* fmt,
  va_list args
)
{
  u32 found_perc = 0;
  u32 chars_written = 0;
  while (*fmt)
  {
    char c = *fmt++;
    if (found_perc)
    {
      switch (c)
      {
        case 'd':
          chars_written += nex_format_signed_int_stream(va_arg(args, i32), callback, ctx);
          break;

        case 'u':
          chars_written += nex_format_unsigned_int_stream(va_arg(args, u32), callback, ctx);
          break;

        case 'l':
          chars_written += nex_format_signed_long_stream(va_arg(args, i64), callback, ctx);
          break;

        case 'L':
          chars_written += nex_format_unsigned_long_stream(va_arg(args, u64), callback, ctx);
          break;

        case 'f':
          chars_written += nex_format_double_stream(va_arg(args, double), callback, ctx);
          break;

        case 's':
          chars_written += _stream_str(va_arg(args, const char*), callback, ctx);
          break;

        case 'c':
          callback(ctx, (char) va_arg(args, u32));
          ++chars_written;
          break;

        case 'x':
          chars_written += nex_format_hex_stream(va_arg(args, u32), callback, ctx);
          break;

        case 'b':
          chars_written += nex_format_binary_stream(va_arg(args, u32), callback, ctx);
          break;

        case 'B':
          chars_written += nex_format_boolean_stream(va_arg(args, u32), callback, ctx);
          break;
          
        case '%':
          callback(ctx, '%');
          ++chars_written;
          break;

        default:
          callback(ctx, '?');
          ++chars_written;
          break;
      }

      found_perc = 0;
      continue;
    }

    if (c == '%')
    {
      found_perc = 1;
      continue;
    }

    callback(ctx, c);
  }

  callback(ctx, '\0');
  return chars_written;
}

u32
nex_format_signed_int_stream(
  i32 value,
  formatter_callback callback,
  volatile void* ctx
)
{
  if (value == 0)
  {
    callback(ctx, '0');
    return 1;
  }

  char buf[12];
  u32 count = 0;
  const u8 neg = (value & (1 << 31)) != 0;

  if (neg)
  {
    value = -value;
  }

  while (value > 0)
  {
    buf[count++] = (char) (value % 10);
    value /= 10;
  }

  if (neg)
  {
    callback(ctx, '-');
  }

  for (u8 i = 0; i < count; ++i)
  {
    char c = buf[count - i - 1] + '0';
    callback(ctx, c);
  }

  return count;
}

u32
nex_format_unsigned_int_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
)
{
  if (value == 0)
  {
    callback(ctx, '0');
    return 1;
  }

  char buf[12];
  u32 count = 0;

  while (value > 0)
  {
    buf[count++] = (char) (value % 10);
    value /= 10;
  }

  for (u8 i = 0; i < count; ++i)
  {
    char c = buf[count - i - 1] + '0';
    callback(ctx, c);
  }

  return count;
}

u32
nex_format_signed_long_stream(
  i64 value,
  formatter_callback callback,
  volatile void* ctx
)
{
  if (value == 0)
  {
    callback(ctx, '0');
    return 1;
  }

  char buf[20];
  u32 count = 0;
  const u8 neg = (value & (1 << 31)) != 0;

  if (neg)
  {
    value = -value;
  }

  while (value > 0)
  {
    buf[count++] = (char) (value % 10);
    value /= 10;
  }

  if (neg)
  {
    callback(ctx, '-');
  }

  for (u8 i = 0; i < count; ++i)
  {
    char c = buf[count - i - 1] + '0';
    callback(ctx, c);
  }

  return count;
}

u32
nex_format_unsigned_long_stream(
  u64 value,
  formatter_callback callback,
  volatile void* ctx
)
{
  if (value == 0)
  {
    callback(ctx, '0');
    return 1;
  }

  char buf[20];
  u32 count = 0;

  while (value > 0)
  {
    buf[count++] = (char) (value % 10);
    value /= 10;
  }

  for (u8 i = 0; i < count; ++i)
  {
    char c = buf[count - i - 1] + '0';
    callback(ctx, c);
  }

  return count;
}

u32
nex_format_double_stream(
  double value,
  formatter_callback callback,
  volatile void* ctx
)
{
  u32 count = 0;
  u32 int_part;

  if (value < 0)
  {
    callback(ctx, '-');
    int_part = (u32) (-value);
  }
  else
  {
    int_part = (u32) value;
  }

  count += nex_format_unsigned_int_stream(int_part, callback, ctx);

  callback(ctx, '.');
  ++count;

  u32 d = (u32) ((value - (double) ((u32) value)) * 1000000.0);
  u32 c = d;
  u32 digits = 0;
  while (c > 0)
  {
    c /= 10;
    ++digits;
  }

  for (u32 i = 0; i < (6 - digits); ++i)
  {
    callback(ctx, '0');
    ++count;
  }

  count += nex_format_unsigned_int_stream(d, callback, ctx);
  return count;
}

u32
nex_format_hex_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
)
{
  if (value == 0)
  {
    callback(ctx, '0');
    return 1;
  }

  const char* map = "0123456789abcdef";
  char buf[64];
  u32 count = 0;

  while (value > 0)
  {
    u32 idx = value & 0xf;
    value >>= 4;
    buf[count++] = map[idx];
  }

  for (u32 i = 0; i < count; ++i)
  {
    char c = buf[count - i - 1];
    callback(ctx, c);
  }

  return count;
}

u32
nex_format_binary_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
)
{
  if (value == 0)
  {
    callback(ctx, '0');
    return 1;
  }

  char buf[64];
  u32 count = 0;
  while (value > 0)
  {
    u32 bit = value & 1;
    value >>= 1;
    buf[count++] = bit ? '1' : '0';
  }

  for (u32 i = 0; i < count; ++i)
  {
    char c = buf[count - i - 1];
    callback(ctx, c);
  }

  return count;
}

u32
nex_format_boolean_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
)
{
  return _stream_str(value ? "true" : "false", callback, ctx);
}
