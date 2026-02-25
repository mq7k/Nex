#ifndef NEX_UNIT_H
#define NEX_UNIT_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

enum nex_freq_unit
{
  NEX_FREQ_UNIT_Hz,
  NEX_FREQ_UNIT_KHz,
  NEX_FREQ_UNIT_MHz,
  NEX_FREQ_UNIT_GHz
};

enum nex_byte_unit
{
  NEX_BYTE_UNIT_BYTE,
  NEX_BYTE_UNIT_KB,
  NEX_BYTE_UNIT_MB,
  NEX_BYTE_UNIT_GB
};

enum nex_time_unit
{
  NEX_TIME_UNIT_NANOSECOND,
  NEX_TIME_UNIT_MICROSECOND,
  NEX_TIME_UNIT_MILLISECOND,
  NEX_TIME_UNIT_SECOND
};

u32
nex_convert_freq_unit(
  u32 value,
  enum nex_freq_unit from,
  enum nex_freq_unit to
);

double
nex_convert_freq_unitf(
  double value,
  enum nex_freq_unit from,
  enum nex_freq_unit to
);

u32
nex_convert_freq_to_largest(
  u32 value,
  enum nex_freq_unit unit,
  enum nex_freq_unit *res
);

double
nex_convert_freq_to_largestf(
  double value,
  enum nex_freq_unit unit,
  enum nex_freq_unit* res
);

const char*
nex_freq_unit_to_string(
  enum nex_freq_unit unit
);

u32
nex_convert_bytes_unit(
  u32 value,
  enum nex_byte_unit from,
  enum nex_byte_unit to
);

double
nex_convert_byte_unitf(
  double value,
  enum nex_byte_unit from,
  enum nex_byte_unit to
);

double
nex_convert_byte_to_largestf(
  double value,
  enum nex_byte_unit from,
  enum nex_byte_unit* res
);

u32
nex_convert_byte_to_largest(
  u32 value,
  enum nex_byte_unit unit,
  enum nex_byte_unit* res
);

const char*
nex_byte_unit_to_string(
  enum nex_byte_unit unit
);

u32
nex_convert_time_unit(
  u32 value,
  enum nex_time_unit from,
  enum nex_time_unit to
);

double
nex_convert_time_unitf(
  double value,
  enum nex_time_unit from,
  enum nex_time_unit to
);

double
nex_convert_time_to_largestf(
  double value,
  enum nex_time_unit unit,
  enum nex_time_unit* res
);

u32
nex_convert_time_to_largest(
  u32 value,
  enum nex_time_unit unit,
  enum nex_time_unit* res
);

const char*
nex_time_unit_to_string(
  enum nex_time_unit unit
);

END_DECLARATIONS

#endif
