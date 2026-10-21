#ifndef BLACKBIRD_VEHICLE_H
#define BLACKBIRD_VEHICLE_H

#include "blackbird/inputs.h"
#include "libcom/algo/pid.h"
#include "libcom/math/vec3f.h"
#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

#define BB_ARM_CHANNEL (5)
#define BB_ARM_CHANNEL_THRESHOLD (200)

struct bb_sensors
{
  struct nex_vec3f accel;
  struct nex_vec3f gyro;
};

struct vehicle_config
{
  float max_thrust;
  float min_thrust;

  float yaw_range_min;
  float yaw_range_max;

  float roll_range_min;
  float roll_range_max;

  float pitch_range_min;
  float pitch_range_max;
};

enum bb_flight_mode
{
  BB_FLIGHT_MODE_DDRIVE,
  BB_FLIGHT_MODE_ACRO,
  BB_FLIGHT_MODE_ANGLE,
};

enum bb_vehicle_thrust_range_mode
{
  BB_VEHICLE_THRUST_RANGE_MODE_CLAMP,
  BB_VEHICLE_THRUST_RANGE_MODE_LERP
};

struct bb_vehicle
{
  struct nex_pid roll_pid;
  struct nex_pid pitch_pid;
  struct nex_pid yaw_pid;

  struct bb_sensors sensors;

  struct vehicle_config config;

  enum bb_flight_mode flight_mode;

  u32 armed;
  u32 trying_arming;

  enum bb_vehicle_thrust_range_mode thrust_mode;

  struct bb_vehicle_commands commands;
};

void
bb_vehicle_tick(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs,
  float dt
);

void
bb_vehicle_handle_thrust(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs
);

END_DECLARATIONS

#endif
