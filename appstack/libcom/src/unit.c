#include "libcom/unit.h"

static const double freq_factors[4][4] = {
  { 1, 0.001, 0.000001, 0.0000000001 },
  { 1000, 1, 0.001, 0.000001 },
  { 1000000, 1000, 1, 0.001 },
  { 1000000000, 1000000, 1000, 1 }
};

static constexpr double byte_factors[4][4] = {
  { 1, 1 / 1024.0f, 1 / 1024.0f / 1024.0f, 1 / 1024.0f / 1024.0f / 1024.0f },
  { 1024, 1, 1 / 1024.0f, 1 / 1024.0f / 1024.0f },
  { 1024 * 1024, 1024, 1, 1 / 1024.0f },
  { 1024 * 1024 * 1024, 1024 * 1024, 1024, 1 }
};

static constexpr double time_factors[4][4] = {
  { 1.0, 0.001, 0.000001, 0.0000000001 },
  { 1000.0, 1.0, 0.000001, 0.0000000001 },
  { 1000000.0, 1000.0, 1.0, 0.000001 },
  { 1000000000.0, 1000000.0, 1000.0, 1.0 }
};

u32
nex_convert_freq_unit(
  u32 value,
  enum nex_freq_unit from,
  enum nex_freq_unit to
)
{
  return (u32) nex_convert_freq_unitf(value, from, to);
}

double
nex_convert_freq_unitf(
  double value,
  enum nex_freq_unit from,
  enum nex_freq_unit to
)
{
  return freq_factors[from][to] * value;
}

u32
nex_convert_freq_to_largest(
  u32 value,
  enum nex_freq_unit unit,
  enum nex_freq_unit *res
)
{
  return (u32) nex_convert_freq_to_largestf(value, unit, res);
}

double
nex_convert_freq_to_largestf(
  double value,
  enum nex_freq_unit unit,
  enum nex_freq_unit* res
)
{
  while (value >= 1000.0f && unit < NEX_FREQ_UNIT_GHz)
  {
    value /= 1000.0f;
    ++unit;
  }

  *res = unit;
  return value;
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
      return "Unknown";
  }
}

u32
syn_convert_byte_unit(
  u32 value,
  enum nex_byte_unit from,
  enum nex_byte_unit to
)
{
  return from > to ? 
         (value << ((from - to) * 10)) :
         (value >> ((to - from) * 10));
}

double
nex_convert_byte_unitf(
  double value,
  enum nex_byte_unit from,
  enum nex_byte_unit to
)
{
  return byte_factors[from][to] * value;
}

double
nex_convert_byte_to_largestf(
  double value,
  enum nex_byte_unit unit,
  enum nex_byte_unit* res
)
{
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
  return (u32) nex_convert_time_unitf(value, from, to);
}

double
nex_convert_time_unitf(
  double value,
  enum nex_time_unit from,
  enum nex_time_unit to
)
{
  return value * time_factors[from][to];
}

double
nex_convert_time_to_largestf(
  double value,
  enum nex_time_unit unit,
  enum nex_time_unit* res
)
{
  while (value >= 1000.0f && unit < NEX_TIME_UNIT_SECOND)
  {
    value /= 1000.0f;
    ++unit;
  }

  *res = unit;
  return value;
}

u32
nex_convert_time_to_largest(
  u32 value,
  enum nex_time_unit unit,
  enum nex_time_unit* res
)
{
  return (u32) nex_convert_time_to_largestf(value, unit, res);
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
      return "Unknown";
  }
}
