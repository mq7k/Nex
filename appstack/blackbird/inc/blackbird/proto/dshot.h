#ifndef BLACKBIRD_PROTO_DSHOT_H
#define BLACKBIRD_PROTO_DSHOT_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

enum bb_dshot_variant
{
  BB_DSHOT150,
  BB_DSHOT300,
  BB_DSHOT600,
  BB_DSHOT1200
};

struct bb_dshot_periods
{
  u32 total_bit_period;
  u32 bit_1_period;
  u32 bit_0_period;
};

u32
bb_proto_dshot_create_frame(
  u32 speed,
  u32 telemetry
);

i32
bb_dshot_get_bit_periods(
  enum bb_dshot_variant variant,
  struct bb_dshot_periods* periods,
  u32 dt_ns
);

void
bb_proto_dshot_pack_norm_sequence(
  struct bb_dshot_periods* periods,
  u16* speed_arr,
  u32 len,
  u16* arr_out
);

END_DECLARATIONS

#endif
