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

  // Thrust
  bb_vehicle_handle_thrust(vehicle, inputs);

  // Yaw
  target = nex_lerpf(
    (float) inputs->channels[1],
    (float) ch_min,
    (float) ch_max,
    0.0f,
    1.0f
  );

  target = CLAMP(target, 0.0f, 1.0f);
  commands->yaw = target;

  // Roll
  target = nex_lerpf(
    (float) inputs->channels[2],
    (float) ch_min,
    (float) ch_max,
    0.0f,
    1.0f
  );

  target = CLAMP(target, 0.0f, 1.0f);
  commands->roll = target;

  // Pitch
  target = nex_lerpf(
    (float) inputs->channels[3],
    (float) ch_min,
    (float) ch_max,
    0.0f,
    1.0f
  );

  target = CLAMP(target, 0.0f, 1.0f);
  commands->pitch = target;
}
