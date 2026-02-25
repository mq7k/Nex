#ifndef NEX_DEVMODE_H
#define NEX_DEVMODE_H

#include "libcom/types.h"
#include <stdarg.h>

#define FILESRC __FILE_NAME__

#ifdef BUILD_TESTS
typedef u32 ttype;
#else
typedef u16 ttype;
#endif

#if defined(NEX_INCLUDE_DEVMODE)

#define devmode_assert(condition, fmt, ...)\
  _devmode_assert((condition), FILESRC, __func__, __LINE__, fmt, ##__VA_ARGS__)

#define devmode_assert_in_range(value, min, max)\
  devmode_assert(\
    (value) >= (min) && (value) < (max),\
    #value " is not within range (min=%u, max=%u, value=%u)",\
    (ttype) (value), (ttype) (min), (ttype) (max)\
  )

#define devmode_assert_lower(value, compare)\
  devmode_assert(\
    (value) < (compare),\
    #value " exceed maximum allowed value (%u >= %u)",\
    (ttype) (value), (ttype) (compare)\
  )

#define devmode_assert_lower_or_eq(value, compare)\
  devmode_assert(\
    (value) <= (compare),\
    #value " exceed maximum allowed value (%u > %u)",\
    (ttype) (value), (ttype) (compare)\
  )

#define devmode_assert_greater(value, compare)\
  devmode_assert(\
    (value) > (compare),\
    #value " is less than minimum allowed value (%u <= %u)",\
    (ttype) (value), (ttype) (compare)\
  )

#define devmode_assert_greater_or_eq(value, compare)\
  devmode_assert(\
    (value) >= (compare),\
    #value " is less than minimum allowed value (%u < %u)",\
    (ttype) value, (ttype) compare\
  )

#define devmode_assert_nonzero(value)\
  devmode_assert(\
    (value) != 0,\
    #value " is expected to be non-zero, but it's %d",\
    (ttype) value\
  )

#define devmode_assert_zero(value)\
  devmode_assert(\
    (value) == 0,\
    #value " is expected to be zero, but it's %d",\
    (ttype) (condition)\
  )

#define devmode_assert_true(condition)\
  devmode_assert(\
    (condition),\
    #condition " is expected to be true, but it's false",\
  )

#define devmode_assert_false(condition)\
  devmode_assert(\
    !(condition),\
    #condition " is expected to be false, but it's true",\
  )

#define devmode_log(fmt, ...)\
  _devmode_log(fmt, ##__VA_ARGS__)

#define devmode_warning(fmt, ...)\
  _devmode_warning(FILESRC, __func__, __LINE__, fmt, ##__VA_ARGS__)

#define devmode_error(fmt, ...)\
  _devmode_error(FILESRC, __func__, __LINE__, fmt, ##__VA_ARGS__)

#define devmode_error_invalid_enum(type, value)\
  _devmode_error(\
    FILESRC, __func__, __LINE__,\
    "Invalid " #type " value=%u",\
    (ttype) (value)\
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
#define devmode_log(fmt, ...)
#define devmode_warning(fmt, ...)
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

#endif
