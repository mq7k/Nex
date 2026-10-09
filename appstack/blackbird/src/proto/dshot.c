#include "blackbird/proto/dshot.h"
#include "libcom/errcodes.h"

// Bit time in ns.
// Order is as follow:
// - total bit time,
// - bit period 1,
// - bit period 0.
constexpr u32 bit_periods_table[4][4] = {
  [BB_DSHOT150] = {
    6670,
    5000,
    2500
  },
  [BB_DSHOT300] = {
    3340,
    2505,
    1252
  },
  [BB_DSHOT600] = {
    1670,
    1252,
    626
  },
  [BB_DSHOT1200] = {
    830,
    622,
    311
  }
};

u32
bb_proto_dshot_calc_crc(
  u32 frame
)
{
  return ((frame >> 8) ^ (frame >> 4) ^ (frame)) & 0xf;
}

u32
bb_proto_dshot_create_frame(
  u32 speed,
  u32 telemetry
)
{
  u32 frame = 0;
  // frame |= ((speed & 2047) << 1);
  // frame |= ((telemetry & 1) << 0);
  frame |= (speed << 1);
  frame |= (telemetry << 0);
  const u32 crc = bb_proto_dshot_calc_crc(frame);
  frame = (frame << 4) | crc;
  return frame;
}

i32
bb_dshot_get_bit_periods(
  enum bb_dshot_variant variant,
  struct bb_dshot_periods* periods,
  u32 dt_ns
)
{
  const u32* arr;
  switch (variant)
  {
    case BB_DSHOT150:
    case BB_DSHOT300:
    case BB_DSHOT600:
    case BB_DSHOT1200:
      arr = bit_periods_table[variant];
      break;

    default:
      return -NERR_INV_ARG;
  }

  periods->total_bit_period = arr[0] / dt_ns;
  periods->bit_1_period = arr[1] / dt_ns;
  periods->bit_0_period = arr[2] / dt_ns;
  return NOK;
}

void
bb_proto_dshot_pack_norm_sequence(
  struct bb_dshot_periods* periods,
  u16* speed_arr,
  u32 len,
  u16* arr_out
)
{
  for (u32 i = 0; i < len; ++i)
  {
    u32 frame = bb_proto_dshot_create_frame(speed_arr[i], 0);

    for (u32 j = 0; j < 16; ++j)
    {
      const u32 idx = j * len + i;
      if (frame & (1u << (16 - 1 - j)))
      {
        arr_out[idx] = (u16) periods->bit_1_period;
      }
      else
      {
        arr_out[idx] = (u16) periods->bit_0_period;
      }
    }

    arr_out[16 * len + i] = 0;
  }
}
