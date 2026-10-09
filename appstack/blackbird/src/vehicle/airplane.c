#include "blackbird/vehicle/airplane.h"
#include "blackbird/motors/mixer.h"

void
bb_airplane_mixer_compute(
  struct bb_vehicle* vehicle,
  struct bb_actuator* actuators,
  u16* updated_values,
  u32 count
)
{
  struct bb_vehicle_commands* commands = &vehicle->commands;

  struct nex_vec4f vec = {
    .x = commands->thrust,
    .y = commands->yaw,
    .z = commands->roll,
    .w = commands->pitch
  };

  struct motor_stats stats;
  bb_mixer_compute_actuators_output(
    &vec,
    actuators,
    count,
    updated_values,
    &stats
  );
}
