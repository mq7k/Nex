#ifndef NEX_UTIL_FORMAT_H
#define NEX_UTIL_FORMAT_H

#include "libcom/util.h"
#include "libcom/types.h"

#include <stdarg.h>

BEGIN_DECLARATIONS

typedef void (*formatter_callback)(volatile void* ctx, char c);

u32
nex_format_str(
  char* buf,
  u32 len,
  const char* fmt,
  ...
);

u32
nex_format_va_args(
  char* buf,
  u32 len,
  const char* fmt,
  va_list args
);

u32
nex_format_signed_int_stream(
  i32 value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_unsigned_int_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_signed_long_stream(
  i64 value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_unsigned_long_stream(
  u64 value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_double_stream(
  double value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_hex_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_binary_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_boolean_stream(
  u32 value,
  formatter_callback callback,
  volatile void* ctx
);

u32
nex_format_str_stream(
  formatter_callback callback,
  volatile void* ctx,
  const char* fmt,
  ...
);

u32
nex_format_va_args_stream(
  formatter_callback callback,
  volatile void* ctx,
  const char* fmt,
  va_list args
);

END_DECLARATIONS

#endif
