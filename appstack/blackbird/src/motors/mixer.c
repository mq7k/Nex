#include "blackbird/motors/mixer.h"
#include "libcom/math/nxmath.h"
#include "libcom/util.h"

void
bb_mixer_compute_actuators_output(
  struct nex_vec4f* vec,
  struct bb_actuator* actuators,
  u32 count,
  u16* updated_values,
  struct motor_stats* stats
)
{
  u32 max_thrust_idx = count;
  u32 min_thrust_idx = count;
  float max_thrust = 0.0f;
  float min_thrust = (float) count + 1.0f;

  for (u32 i = 0; i < count; ++i)
  {
    struct nex_vec4f* src = &actuators[i].axes_vec;
    float res = nex_vec4f_dot(src, vec);

    actuators[i].cur = res;

    const u32 min = actuators[i].min_speed_v;
    const u32 max = actuators[i].max_speed_v;

    u16 scaled_value = (u16) nex_lerpf(
      res,
      0.0f,
      1.0f,
      (float) actuators[i].min_speed_v,
      (float) actuators[i].max_speed_v
    );
    updated_values[i] = (u16) CLAMP(scaled_value, min, max);

    if (res > max_thrust)
    {
      max_thrust_idx = i;
      max_thrust = res;
    }

    if (res < min_thrust)
    {
      min_thrust_idx = i;
      min_thrust = res;
    }
  }

  stats->min_thrust = min_thrust;
  stats->max_thrust = max_thrust;
  stats->max_thrust_idx = max_thrust_idx;
  stats->min_thrust_idx = min_thrust_idx;
}

