#ifndef NEX_DEVMODE_H
#define NEX_DEVMODE_H

#include "libcom/types.h"
#include "libcom/util.h"
#include <stdarg.h>

BEGIN_DECLARATIONS

#define FILESRC __FILE_NAME__

// `u32` is defined as `uint32_t` (see types.h).
// `uint32_t` is defined as `unsigned long int`.
// On ARM, an `unsigned long int` is 32bit,
// on x86_64 is a 64bit, so we have to
// define the format specifier accordingly.
#if defined(NEX_PLATFORM_ARM)
#define DEVMODE_UINT32_FMT "%lu"
#else
#define DEVMODE_UINT32_FMT "%u"
#endif

#if defined(NEX_INCLUDE_DEVMODE)

#define devmode_assert(condition, fmt, ...)\
  _devmode_assert((condition), FILESRC, __func__, __LINE__, fmt, ##__VA_ARGS__)

#define devmode_assert_in_range(value, min, max)\
  devmode_assert(\
    (value) >= (min) && (value) < (max),\
    #value " is not within range (min=%u, max=%u, value=%u)",\
    (value), (min), (max)\
  )

#define devmode_assert_lower(value, compare)\
  devmode_assert(\
    (value) < (compare),\
    #value " exceed maximum allowed value (%u >= %u)",\
    (value), (compare)\
  )

#define devmode_assert_lower_or_eq(value, compare)\
  devmode_assert(\
    (value) <= (compare),\
    #value " exceed maximum allowed value (%u > %u)",\
    (value), (compare)\
  )

#define devmode_assert_greater(value, compare)\
  devmode_assert(\
    (value) > (compare),\
    #value " is less than minimum allowed value (%u <= %u)",\
    (value), (compare)\
  )

#define devmode_assert_greater_or_eq(value, compare)\
  devmode_assert(\
    (value) >= (compare),\
    #value " is less than minimum allowed value (%u < %u)",\
    value, compare\
  )

#define devmode_assert_nonzero(value)\
  devmode_assert(\
    (value) != 0,\
    #value " is expected to be non-zero, but it's %d",\
    value\
  )

#define devmode_assert_zero(value)\
  devmode_assert(\
    (value) == 0,\
    #value " is expected to be zero, but it's %d",\
    (value)\
  )

#define devmode_assert_true(condition)\
  devmode_assert(\
    (condition),\
    #condition " is expected to be true, but it's false"\
  )

#define devmode_assert_false(condition)\
  devmode_assert(\
    !(condition),\
    #condition " is expected to be false, but it's true"\
  )

#define devmode_assert_nonnull(ptr)\
  devmode_assert_true(ptr != NULL)

#define devmode_assert_null(ptr)\
  devmode_assert_true(ptr == NULL)

#define devmode_log(fmt, ...)\
  _devmode_log(fmt, ##__VA_ARGS__)

#define devmode_warning(fmt, ...)\
  _devmode_warning(FILESRC, __func__, __LINE__, fmt, ##__VA_ARGS__)

#define devmode_warning_if(condition, fmt, ...)\
  if (condition) _devmode_warning(FILESRC, __func__, __LINE__, fmt, ##__VA_ARGS__)

#define devmode_error(fmt, ...)\
  _devmode_error(FILESRC, __func__, __LINE__, fmt, ##__VA_ARGS__)

#define devmode_error_invalid_enum(type, value)\
  _devmode_error(\
    FILESRC, __func__, __LINE__,\
    "Invalid " #type " value=%u",\
    (value)\
  )

#define devmode_halt(trace) _devmode_halt(trace)

#else
#define devmode_assert(condition, fmt, ...)
#define devmode_assert_in_range(value, min, max)
#define devmode_assert_lower(value, compare)
#define devmode_assert_lower_or_eq(value, compare)
#define devmode_assert_greater(value, compare)
#define devmode_assert_greater_or_eq(value, compare)
#define devmode_assert_nonzero(value)
#define devmode_assert_zero(value)
#define devmode_assert_true(condition)
#define devmode_assert_false(condition)
#define devmode_assert_nonnull(ptr)
#define devmode_assert_null(ptr)
#define devmode_log(fmt, ...)
#define devmode_warning(fmt, ...)
#define devmode_warning_if(condition, fmt, ...)
#define devmode_error(fmt, ...)
#define devmode_error_invalid_enum(type, value)
#define devmode_halt(trace) (void) trace;
#endif

struct devmode_trace
{
  const char* file;
  const char* func;
  u32 line;
};

void
_devmode_warning(
  const char* file,
  const char* func,
  u32 line,
  const char* fmt,
  ...
) __attribute__((format(printf, 4, 5)));

void
_devmode_error(
  const char* file,
  const char* func,
  u32 line,
  const char* fmt,
  ...
) __attribute__((format(printf, 4, 5)));

void
_devmode_assert(
  u32 condition,
  const char* file,
  const char* func,
  u32 line,
  const char* fmt,
  ...
) __attribute__((format(printf, 5, 6)));

void
_devmode_log(
  const char* fmt,
  ...
) __attribute__((format(printf, 1, 2)));

// TODO: User (define)
void
_devmode_logv(
  const char* fmt,
  va_list list
) __attribute__((format(printf, 1, 0)));

// TODO: User (define)
void
_devmode_halt(
  const struct devmode_trace* trace
);

END_DECLARATIONS

#endif
