#include "blackbird/vehicle/vehicle.h"
#include "blackbird/modes/acro.h"
#include "blackbird/modes/angle.h"
#include "blackbird/modes/ddrive.h"
#include "blackbird/inputs.h"
#include "libcom/math/nxmath.h"

// Functions declaration
static void
_try_arm(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs
);

// Functions definition
void
bb_vehicle_tick(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs,
  float dt
)
{
  _try_arm(vehicle, inputs);

  const u32 val = inputs->channels[6];
  if (bb_is_channel_low(val))
  {
    vehicle->flight_mode = BB_FLIGHT_MODE_ACRO;
  }
  else if (bb_is_channel_centered(val))
  {
    vehicle->flight_mode = BB_FLIGHT_MODE_ANGLE;
  }
  else if (bb_is_channel_high(val))
  {
    vehicle->flight_mode = BB_FLIGHT_MODE_DDRIVE;
  }

  switch (vehicle->flight_mode)
  {
    case BB_FLIGHT_MODE_ACRO:
      bb_mode_acro_compute(vehicle, inputs, &vehicle->commands, dt);
      break;

    case BB_FLIGHT_MODE_ANGLE:
      bb_mode_angle_compute(vehicle, inputs, &vehicle->commands, dt);
      break;

    case BB_FLIGHT_MODE_DDRIVE:
      bb_mode_ddrive_compute(vehicle, inputs, &vehicle->commands, dt);
      break;
  }
}

static void
_try_arm(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs
)
{
  const u32 arm_channel_value = inputs->channels[BB_ARM_CHANNEL];
  if (bb_is_channel_high(arm_channel_value))
  {
    if (!vehicle->trying_arming)
    {
      vehicle->trying_arming = 1;
      vehicle->armed = inputs->channels[0] <= BB_ARM_CHANNEL_THRESHOLD;
    }
  }
  else
  {
    if (inputs->channels[0] <= BB_ARM_CHANNEL_THRESHOLD)
    {
      vehicle->armed = 0;
    }

    vehicle->trying_arming = 0;
  }
}

void
bb_vehicle_handle_thrust(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs
)
{
  const u32 ch_min = 174;
  const u32 ch_max = 1811;
  struct bb_vehicle_commands* commands = &vehicle->commands;

  switch (vehicle->thrust_mode)
  {
    case BB_VEHICLE_THRUST_RANGE_MODE_CLAMP:
      commands->thrust = nex_lerpf(
        (float) inputs->channels[0],
        (float) ch_min,
        (float) ch_max,
        0.0f,
        1.0f
      );

      commands->thrust = CLAMP(
        commands->thrust,
        0.0f,
        vehicle->config.max_thrust
      );
      break;

    case BB_VEHICLE_THRUST_RANGE_MODE_LERP:
      commands->thrust = nex_lerpf(
        (float) inputs->channels[0],
        (float) ch_min,
        (float) ch_max,
        0.0f,
        vehicle->config.max_thrust
      );

      commands->thrust = CLAMP(
        commands->thrust,
        0.0f,
        vehicle->config.max_thrust
      );
      break;
  }

  commands->thrust *= (float) vehicle->armed;
}
