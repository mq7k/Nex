#include "blackbird/proto/pwm.h"
#include "libcom/errcodes.h"

i32
bb_proto_pwm_init(
  struct bb_proto_pwm* pwm
)
{
  if (pwm->min_time == 0)
  {
    pwm->min_time = 1000;
  }

  if (pwm->max_time == 0)
  {
    pwm->max_time = 2000;
  }

  if (pwm->max_time < pwm->min_time)
  {
    return -NERR_RANGE;
  }

  return NOK;
}

void
bb_proto_pwm_set_value(
  struct bb_proto_pwm* pwm,
  float duty_cycle
)
{
  float range = (float) (pwm->max_time - pwm->min_time);
  u32 cc = (u32) (range * duty_cycle) + pwm->min_time;
  pwm->cur_value = cc;
}

void
bb_proto_pwm_pack_norm_sequence(
  u16* scaled_values,
  u32 count,
  u16* arr_out
)
{
  (void) scaled_values;
  (void) count;
  (void) arr_out;
}
