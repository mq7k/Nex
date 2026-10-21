#ifndef BLACKBIRD_MIXER_H
#define BLACKBIRD_MIXER_H

#include "blackbird/motors/actuator.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

struct motor_stats
{
  u32 max_thrust_idx;
  u32 min_thrust_idx;
  float min_thrust;
  float max_thrust;
};

void
bb_mixer_compute_actuators_output(
  struct nex_vec4f* vec,
  struct bb_actuator* actuators,
  u32 count,
  u16* updated_values,
  struct motor_stats* stats
);

END_DECLARATIONS

#endif
