#ifndef BLACKBIRD_PROTO_PWM_H
#define BLACKBIRD_PROTO_PWM_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct bb_proto_pwm
{
  u32 freq;

  // Timer CC values.
  u32 min_time;
  u32 max_time;
  u32 cur_value;
};

i32
bb_proto_pwm_init(
  struct bb_proto_pwm* pwm
);

void
bb_proto_pwm_set_value(
  struct bb_proto_pwm* pwm,
  float duty_cycle
);

void
bb_proto_pwm_pack_norm_sequence(
  u16* scaled_values,
  u32 count,
  u16* arr_out
);

END_DECLARATIONS

#endif
