#include "blackbird/modes/acro.h"
#include "blackbird/vehicle/vehicle.h"
#include "blackbird/inputs.h"
#include "libcom/math/nxmath.h"

void
bb_mode_acro_compute(
  struct bb_vehicle* vehicle, 
  struct bb_input_channels* inputs,
  struct bb_vehicle_commands* commands,
  float dt
)
{
  const float yaw_rate_min = vehicle->config.yaw_range_min;
  const float yaw_rate_max = vehicle->config.yaw_range_max;

  const float roll_rate_min = vehicle->config.roll_range_min;
  const float roll_rate_max = vehicle->config.roll_range_max;

  const float pitch_rate_min = vehicle->config.yaw_range_min;
  const float pitch_rate_max = vehicle->config.yaw_range_max;

  const u32 ch_min = 174;
  const u32 ch_max = 1811;
  float target;

  // Thrust
  bb_vehicle_handle_thrust(vehicle, inputs);

  // Yaw (rate setpoint)
  target = nex_lerpf(
    (float) inputs->channels[1],
    (float) ch_min,
    (float) ch_max,
    yaw_rate_min,
    yaw_rate_max
  );

  commands->yaw = nex_pid_tick(
    &vehicle->yaw_pid,
    target,
    vehicle->sensors.gyro.z,
    dt
  );

  // Roll (rate setpoint)
  target = nex_lerpf(
    (float) inputs->channels[2],
    (float) ch_min,
    (float) ch_max,
    roll_rate_min,
    roll_rate_max
  );

  commands->roll = nex_pid_tick(
    &vehicle->roll_pid,
    target,
    vehicle->sensors.gyro.x,
    dt
  );

  // Pitch (rate setpoint)
  target = nex_lerpf(
    (float) inputs->channels[3],
    (float) ch_min,
    (float) ch_max,
    pitch_rate_min,
    pitch_rate_max
  );

  commands->pitch = nex_pid_tick(
    &vehicle->pitch_pid,
    target,
    vehicle->sensors.gyro.y,
    dt
  );
}
