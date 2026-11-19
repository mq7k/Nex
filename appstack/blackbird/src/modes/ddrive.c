#include "blackbird/modes/ddrive.h"
#include "libcom/math/nxmath.h"

void
bb_mode_ddrive_compute(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs,
  struct bb_vehicle_commands* commands,
  float dt
)
{
  (void) dt;

  const u32 ch_min = 174;
  const u32 ch_max = 1811;
  float target;

  const u32 yaw_channel = bb_get_input_channel(inputs, BB_IN_YAW);
  const u32 pitch_channel = bb_get_input_channel(inputs, BB_IN_PITCH);
  const u32 roll_channel = bb_get_input_channel(inputs, BB_IN_ROLL);

  // Thrust
  bb_vehicle_handle_thrust(vehicle, inputs);

  // Yaw
  target = nex_lerpf(
    (float) yaw_channel,
    (float) ch_min,
    (float) ch_max,
    0.0f,
    1.0f
  );

  target = CLAMP(target, 0.0f, 1.0f);
  commands->yaw = target;

  // Roll
  target = nex_lerpf(
    (float) roll_channel,
    (float) ch_min,
    (float) ch_max,
    0.0f,
    1.0f
  );

  target = CLAMP(target, 0.0f, 1.0f);
  commands->roll = target;

  // Pitch
  target = nex_lerpf(
    (float) pitch_channel,
    (float) ch_min,
    (float) ch_max,
    0.0f,
    1.0f
  );

  target = CLAMP(target, 0.0f, 1.0f);
  commands->pitch = target;
}
