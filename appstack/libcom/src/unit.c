#include "libcom/unit.h"
#include "sys/devmode.h"

#include <limits.h>

static constexpr float byte_factors[4][4] = {
  { 1.0f, 1.0f / 1024.0f, 1.0f / 1024.0f / 1024.0f, 1.0f / 1024.0f / 1024.0f / 1024.0f },
  { 1024.0f, 1.0f, 1.0f / 1024.0f, 1.0f / 1024.0f / 1024.0f },
  { 1024.0f * 1024.0f, 1024.0f, 1.0f, 1.0f / 1024.0f },
  { 1024.0f * 1024.0f * 1024.0f, 1024.0f * 1024.0f, 1024.0f, 1.0f }
};

static constexpr u32 factors1000i[] = {
  1, 1000, 1000000, 1000000000
};

static constexpr float factors1000f[] = {
  1.0f, 1e3, 1e6, 1e9
};

static u32
_convert_unit_factor1000i(
  u32 value,
  u32 from,
  u32 to
)
{
  if (to > from)
  {
    const u32 diff = to - from;
    return value / factors1000i[diff];
  }

  if (to < from)
  {
    const u32 diff = from - to;
    const u32 factor = factors1000i[diff];
    u32 val;
    u32 overflow __attribute__((unused));
    overflow = __builtin_mul_overflow(value, factor, &val);
    devmode_assert_false(overflow);
    return val;
  }

  return value;
}

static float
_convert_unit_factor1000f(
  float value,
  u32 from,
  u32 to
)
{
  if (to > from)
  {
    const u32 diff = to - from;
    return value / factors1000f[diff];
  }

  if (to < from)
  {
    const u32 diff = from - to;
    const float factor = factors1000f[diff];
    return value * factor;
  }

  return value;
}

static u32
_convert_unit_factor1000i_to_largest(
  u32 value,
  u32 unit,
  u32 max_unit,
  u32* res
)
{
  while (value >= 1000 && unit < max_unit)
  {
    value /= 1000;
    ++unit;
  }

  *res = unit;
  return value;
}

static float
_convert_unit_factor1000f_to_largest(
  float value,
  u32 unit,
  u32 max_unit,
  u32* res
)
{
  while (value >= 1000.0f && unit < max_unit)
  {
    value /= 1000.0f;
    ++unit;
  }

  *res = unit;
  return value;
}

u32
nex_convert_freq_unit(
  u32 value,
  enum nex_freq_unit from,
  enum nex_freq_unit to
)
{
  devmode_assert_lower_or_eq(from, NEX_FREQ_UNIT_GHz);
  devmode_assert_lower_or_eq(to, NEX_FREQ_UNIT_GHz);

  return _convert_unit_factor1000i(value, from, to);
}

float
nex_convert_freq_unitf(
  float value,
  enum nex_freq_unit from,
  enum nex_freq_unit to
)
{
  devmode_assert_lower_or_eq(from, NEX_FREQ_UNIT_GHz);
  devmode_assert_lower_or_eq(to, NEX_FREQ_UNIT_GHz);

  return _convert_unit_factor1000f(value, from, to);
}

u32
nex_convert_freq_to_largest(
  u32 value,
  enum nex_freq_unit unit,
  enum nex_freq_unit* res
)
{
  devmode_assert_lower_or_eq(unit, NEX_FREQ_UNIT_GHz);

  return _convert_unit_factor1000i_to_largest(
    value,
    unit,
    NEX_FREQ_UNIT_GHz,
    (u32*) res
  );
}

float
nex_convert_freq_to_largestf(
  float value,
  enum nex_freq_unit unit,
  enum nex_freq_unit* res
)
{
  devmode_assert_lower_or_eq(unit, NEX_FREQ_UNIT_GHz);

  return _convert_unit_factor1000f_to_largest(
    value,
    unit,
    NEX_FREQ_UNIT_GHz,
    (u32*) res
  );
}

const char*
nex_freq_unit_to_string(
  enum nex_freq_unit unit
)
{
  switch (unit)
  {
    case NEX_FREQ_UNIT_Hz:
      return "Hz";

    case NEX_FREQ_UNIT_KHz:
      return "KHz";

    case NEX_FREQ_UNIT_MHz:
      return "MHz";

    case NEX_FREQ_UNIT_GHz:
      return "GHz";

    default:
      devmode_error_invalid_enum(enum nex_time_unit, unit);
      return "Unknown";
  }
}

u32
nex_convert_byte_unit(
  u32 value,
  enum nex_byte_unit from,
  enum nex_byte_unit to
)
{
  devmode_assert_lower_or_eq(from, NEX_BYTE_UNIT_GB);
  devmode_assert_lower_or_eq(to, NEX_BYTE_UNIT_GB);

  return from > to ? 
         (value << ((from - to) * 10)) :
         (value >> ((to - from) * 10));
}

float
nex_convert_byte_unitf(
  float value,
  enum nex_byte_unit from,
  enum nex_byte_unit to
)
{
  devmode_assert_lower_or_eq(from, NEX_BYTE_UNIT_GB);
  devmode_assert_lower_or_eq(to, NEX_BYTE_UNIT_GB);

  return byte_factors[from][to] * value;
}

float
nex_convert_byte_to_largestf(
  float value,
  enum nex_byte_unit unit,
  enum nex_byte_unit* res
)
{
  devmode_assert_lower_or_eq(unit, NEX_BYTE_UNIT_GB);

  while (value >= 1024.0f && unit < NEX_BYTE_UNIT_GB)
  {
    value /= 1024.0f;
    ++unit;
  }

  *res = unit;
  return value;
}

u32
nex_convert_byte_to_largest(
  u32 value,
  enum nex_byte_unit unit,
  enum nex_byte_unit* res
)
{
  devmode_assert_lower_or_eq(unit, NEX_BYTE_UNIT_GB);

  while (value >= 1024 && unit < NEX_BYTE_UNIT_GB)
  {
    value >>= 10;
    ++unit;
  }

  *res = unit;
  return value;
}

const char*
nex_byte_unit_to_string(
  enum nex_byte_unit unit
)
{
  switch (unit)
  {
    case NEX_BYTE_UNIT_BYTE:
      return "byte";

    case NEX_BYTE_UNIT_KB:
      return "KB";

    case NEX_BYTE_UNIT_MB:
      return "MB";

    case NEX_BYTE_UNIT_GB:
      return "GB";

    default:
      devmode_error_invalid_enum(enum nex_byte_unit, unit);
      return "Unknown";
  }
}

u32
nex_convert_time_unit(
  u32 value,
  enum nex_time_unit from,
  enum nex_time_unit to
)
{
  devmode_assert_lower_or_eq(from, NEX_TIME_UNIT_SECOND);
  devmode_assert_lower_or_eq(to, NEX_TIME_UNIT_SECOND);

  return _convert_unit_factor1000i(value, from, to);
}

float
nex_convert_time_unitf(
  float value,
  enum nex_time_unit from,
  enum nex_time_unit to
)
{
  devmode_assert_lower_or_eq(from, NEX_TIME_UNIT_SECOND);
  devmode_assert_lower_or_eq(to, NEX_TIME_UNIT_SECOND);

  return _convert_unit_factor1000f(value, from, to);
}

float
nex_convert_time_to_largestf(
  float value,
  enum nex_time_unit unit,
  enum nex_time_unit* res
)
{
  devmode_assert_lower_or_eq(unit, NEX_TIME_UNIT_SECOND);

  return _convert_unit_factor1000f_to_largest(
    value,
    unit,
    NEX_TIME_UNIT_SECOND,
    (u32*) res
  );
}

u32
nex_convert_time_to_largest(
  u32 value,
  enum nex_time_unit unit,
  enum nex_time_unit* res
)
{
  devmode_assert_lower_or_eq(unit, NEX_TIME_UNIT_SECOND);
  return _convert_unit_factor1000i_to_largest(
    value,
    unit,
    NEX_TIME_UNIT_SECOND,
    (u32*) res
  );
}

const char*
nex_time_unit_to_string(
  enum nex_time_unit unit
)
{
  switch (unit)
  {
    case NEX_TIME_UNIT_SECOND:
      return "s";

    case NEX_TIME_UNIT_MILLISECOND:
      return "ms";

    case NEX_TIME_UNIT_MICROSECOND:
      return "us";

    case NEX_TIME_UNIT_NANOSECOND:
      return "ns";

    default:
      devmode_error_invalid_enum(enum nex_time_unit, unit);
      return "Unknown";
  }
}
