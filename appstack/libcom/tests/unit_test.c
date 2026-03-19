#include "libcom/unit.h"
#include "libtest/libtest.h"

void
test_convert_freq_unit_i(void)
{
  u32 res;
  u32 value;
  enum nex_freq_unit from;

  /*
   * From Hz
   */
  value = 0;
  from = NEX_FREQ_UNIT_Hz;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQ(res, value);

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQ(res, value);

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQ(res, value);

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, value);

  value = 1'000'000'000;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQ(res, value);

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQ(res, 1'000'000);

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQ(res, 1'000);

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, 1);

  /*
   * From KHz
   */
  value = 0;
  from = NEX_FREQ_UNIT_KHz;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1'000'000'000;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQ(res, 1'000'000);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, 1'000);
  ASSERT_FALSE(execution_halted());

  /*
   * From MHz
   */
  value = 0;
  from = NEX_FREQ_UNIT_MHz;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1'000'000'000;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, 1'000'000);
  ASSERT_FALSE(execution_halted());

  /*
   * From GHz
   */
  value = 0;
  from = NEX_FREQ_UNIT_GHz;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1'000'000'000;
  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unit(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());
}

void
test_convert_freq_unit_f(void)
{
  float res;
  float value;
  enum nex_freq_unit from;

  /*
   * From Hz
   */
  value = 0;
  from = NEX_FREQ_UNIT_Hz;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, value);

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, value);

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, value);

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, value);

  value = 1e9f;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, 1e9f);

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, 1e6f);

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, 1e3f);

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, 1.0f);

  /*
   * From KHz
   */
  value = 0;
  from = NEX_FREQ_UNIT_KHz;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1e9f;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, 1e12f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, 1e9f);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, 1e6f);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, 1e3f);
  ASSERT_FALSE(execution_halted());

  /*
   * From MHz
   */
  value = 0;
  from = NEX_FREQ_UNIT_MHz;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1e9f;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, 1e15f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, 1e12f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, 1e9f);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, 1e6f);
  ASSERT_FALSE(execution_halted());

  /*
   * From GHz
   */
  value = 0;
  from = NEX_FREQ_UNIT_GHz;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1e9;
  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_Hz);
  ASSERT_EQF(res, 1e18f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_KHz);
  ASSERT_EQF(res, 1e15f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_MHz);
  ASSERT_EQF(res, 1e12f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_freq_unitf(value, from, NEX_FREQ_UNIT_GHz);
  ASSERT_EQF(res, 1e9f);
  ASSERT_FALSE(execution_halted());
}

void
test_convert_time_unit_f(void)
{
  float res;
  float value;
  enum nex_time_unit from;

  /*
   * From nanosecond
   */
  value = 0;
  from = NEX_TIME_UNIT_NANOSECOND;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, value);

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, value);

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, value);

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, value);

  value = 1e9f;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, 1e9f);

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, 1e6f);

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, 1e3f);

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, 1.0f);

  /*
   * From microsecond
   */
  value = 0;
  from = NEX_TIME_UNIT_MICROSECOND;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1e9f;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, 1e12f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, 1e9f);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, 1e6f);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, 1e3f);
  ASSERT_FALSE(execution_halted());

  /*
   * From millisecond
   */
  value = 0;
  from = NEX_TIME_UNIT_MILLISECOND;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1e9f;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, 1e15f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, 1e12f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, 1e9f);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, 1e6f);
  ASSERT_FALSE(execution_halted());

  /*
   * From second
   */
  value = 0;
  from = NEX_TIME_UNIT_SECOND;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1e9;
  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQF(res, 1e18f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQF(res, 1e15f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQF(res, 1e12f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_time_unitf(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQF(res, 1e9f);
  ASSERT_FALSE(execution_halted());
}

void
test_convert_freq_unit_to_largest_i(void)
{
  u32 invalue;
  u32 outvalue;
  enum nex_freq_unit inunit;
  enum nex_freq_unit outunit;

  /*
   * From Hz
   */
  invalue = 0;
  inunit = NEX_FREQ_UNIT_Hz;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_KHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_MHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  /*
   * From KHz
   */
  invalue = 0;
  inunit = NEX_FREQ_UNIT_KHz;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_MHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1'000);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  /*
   * From MHz
   */
  invalue = 0;
  inunit = NEX_FREQ_UNIT_MHz;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1'000);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1'000'000);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  /*
   * From GHz
   */
  invalue = 0;
  inunit = NEX_FREQ_UNIT_GHz;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_freq_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, NEX_FREQ_UNIT_GHz);
  ASSERT_FALSE(execution_halted());
}

void
test_convert_byte_unit_i(void)
{
  u32 value;
  enum nex_byte_unit from;
  u32 res;

  /*
   * From byte
   */
  from = NEX_BYTE_UNIT_BYTE;
  value = 0;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  value = 1024 * 1024 * 1024;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQ(res, 1024 * 1024);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQ(res, 1024);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 1);
  ASSERT_FALSE(execution_halted());

  /*
   * From KB
   */
  from = NEX_BYTE_UNIT_KB;
  value = 0;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  value = 1024 * 1024 * 1024;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  // ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQ(res, 1024 * 1024 * 1024);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQ(res, 1024 * 1024);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 1024);
  ASSERT_FALSE(execution_halted());

  /*
   * From MB
   */
  from = NEX_BYTE_UNIT_MB;
  value = 0;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  value = 1024 * 1024 * 1024;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  // ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  // ASSERT_EQ(res, 1024 * 1024 * 1024);
  // ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQ(res, 1024 * 1024 * 1024);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 1024 * 1024);
  ASSERT_FALSE(execution_halted());

  /*
   * From GB
   */
  from = NEX_BYTE_UNIT_GB;
  value = 0;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  value = 1024 * 1024 * 1024;
  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_BYTE);
  // ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_KB);
  // ASSERT_EQ(res, 1024 * 1024 * 1024);
  // ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_MB);
  // ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unit(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQ(res, 1024 * 1024 * 1024);
  ASSERT_FALSE(execution_halted());
}

void
test_convert_byte_unit_f(void)
{
  float res;
  float value;
  enum nex_byte_unit from;

  /*
   * From byte
   */
  value = 0;
  from = NEX_BYTE_UNIT_BYTE;
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, value);

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, value);

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, value);

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, value);

  value = (float) (1u << 30);
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, value);

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, (float) (1u << 20));

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, (float) (1u << 10));

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, 1.0f);

  /*
   * From KB
   */
  value = 0;
  from = NEX_BYTE_UNIT_KB;
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1024*1024*1024;
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, value * 1024.0f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, 1024.0f * 1024.0f);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, 1024.0f);
  ASSERT_FALSE(execution_halted());

  /*
   * From MB
   */
  value = 0;
  from = NEX_BYTE_UNIT_MB;
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1024*1024*1024;
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, 1024.0f*1024.0f*1024.0f*1024.0f*1024.0f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, 1024.0f*1024.0f*1024.0f*1024.0f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, 1024.0f*1024.0f);
  ASSERT_FALSE(execution_halted());

  /*
   * From GB
   */
  value = 0;
  from = NEX_BYTE_UNIT_GB;
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1024*1024*1024;
  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_BYTE);
  ASSERT_EQF(res, value*value);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_KB);
  ASSERT_EQF(res, 1024.0f*1024.0f*1024.0f*1024.0f*1024.0f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_MB);
  ASSERT_EQF(res, 1024.0f*1024.0f*1024.0f*1024.0f);
  ASSERT_FALSE(execution_halted());
  execution_resume();

  res = nex_convert_byte_unitf(value, from, NEX_BYTE_UNIT_GB);
  ASSERT_EQF(res, value);
  ASSERT_FALSE(execution_halted());
}

void
test_convert_byte_unit_to_largest_i(void)
{
  u32 value_in;
  u32 value_out;
  enum nex_byte_unit unit_in;
  enum nex_byte_unit unit_out;

  /*
   * From byte
   */
  value_in = 0;
  unit_in = NEX_BYTE_UNIT_BYTE;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, value_in);
  ASSERT_EQ(unit_out, unit_in);

  value_in = 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_KB);

  value_in = 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_MB);

  value_in = 1024 * 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  /*
   * From KB
   */
  value_in = 0;
  unit_in = NEX_BYTE_UNIT_KB;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, value_in);
  ASSERT_EQ(unit_out, unit_in);

  value_in = 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_MB);

  value_in = 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  value_in = 1024 * 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1024);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  /*
   * From MB
   */
  value_in = 0;
  unit_in = NEX_BYTE_UNIT_MB;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, value_in);
  ASSERT_EQ(unit_out, unit_in);

  value_in = 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  value_in = 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1024);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  value_in = 1024 * 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, 1024 * 1024);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  /*
   * From GB
   */
  value_in = 0;
  unit_in = NEX_BYTE_UNIT_GB;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, value_in);
  ASSERT_EQ(unit_out, unit_in);

  value_in = 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, value_in);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  value_in = 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, value_in);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);

  value_in = 1024 * 1024 * 1024;
  value_out = nex_convert_byte_to_largest(value_in, unit_in, &unit_out);
  ASSERT_EQ(value_out, value_in);
  ASSERT_EQ(unit_out, NEX_BYTE_UNIT_GB);
}

void
test_convert_time_unit_i(void)
{
  u32 res;
  u32 value;
  enum nex_time_unit from;

  /*
   * From nanosecond
   */
  value = 0;
  from = NEX_TIME_UNIT_NANOSECOND;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQ(res, value);

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQ(res, value);

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQ(res, value);

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, value);

  value = 1'000'000'000;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQ(res, value);

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQ(res, 1'000'000);

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQ(res, 1'000);

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, 1);

  /*
   * From microsecond
   */
  value = 0;
  from = NEX_TIME_UNIT_MICROSECOND;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1'000'000'000;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQ(res, 1'000'000);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, 1'000);
  ASSERT_FALSE(execution_halted());

  /*
   * From millisecond
   */
  value = 0;
  from = NEX_TIME_UNIT_MILLISECOND;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1'000'000'000;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, 1'000'000);
  ASSERT_FALSE(execution_halted());

  /*
   * From second
   */
  value = 0;
  from = NEX_TIME_UNIT_SECOND;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());

  value = 1'000'000'000;
  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_NANOSECOND);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  res = nex_convert_time_unit(value, from, NEX_TIME_UNIT_SECOND);
  ASSERT_EQ(res, value);
  ASSERT_FALSE(execution_halted());
}

void
test_convert_time_unit_to_largest_i(void)
{
  u32 invalue;
  u32 outvalue;
  enum nex_time_unit inunit;
  enum nex_time_unit outunit;

  /*
   * From nanosecond
   */
  invalue = 0;
  inunit = NEX_TIME_UNIT_NANOSECOND;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_MICROSECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  /*
   * From microsecond
   */
  invalue = 0;
  inunit = NEX_TIME_UNIT_MICROSECOND;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_MILLISECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1'000);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  /*
   * From millisecond
   */
  invalue = 0;
  inunit = NEX_TIME_UNIT_MILLISECOND;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1'000);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, 1'000'000);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  /*
   * From second
   */
  invalue = 0;
  inunit = NEX_TIME_UNIT_SECOND;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, inunit);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());

  invalue = 1'000'000'000;
  outvalue = nex_convert_time_to_largest(invalue, inunit, &outunit);
  ASSERT_EQ(outvalue, invalue);
  ASSERT_EQ(outunit, NEX_TIME_UNIT_SECOND);
  ASSERT_FALSE(execution_halted());
}

int 
main() 
{
  const test_function_t tests[] = {
    TEST_FUNC(test_convert_freq_unit_i),
    TEST_FUNC(test_convert_freq_unit_f),
    TEST_FUNC(test_convert_freq_unit_to_largest_i),
    TEST_FUNC(test_convert_byte_unit_i),
    TEST_FUNC(test_convert_byte_unit_f),
    TEST_FUNC(test_convert_byte_unit_to_largest_i),
    TEST_FUNC(test_convert_time_unit_i),
    TEST_FUNC(test_convert_time_unit_f),
    TEST_FUNC(test_convert_time_unit_to_largest_i)
  };

  return TESTS_RUN(tests);
}
