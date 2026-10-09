#include "blackbird/vehicle/quadcopter.h"
#include "blackbird/motors/mixer.h"
#include "blackbird/inputs.h"
#include "libcom/math/vec4f.h"

void
bb_quadcopter_mixer_compute_priority_trpy(
  struct bb_vehicle* vehicle,
  struct bb_vehicle_commands* commands,
  struct bb_actuator* actuators,
  u16* updated_values,
  u32 count
)
{
  float min_allowed_thrust = vehicle->config.min_thrust;
  float max_allowed_thrust = vehicle->config.max_thrust;

  struct nex_vec4f rp_vec = {
    .z = commands->roll,
    .w = commands->pitch 
  };

  struct nex_vec4f t_vec = { 
    .x = commands->thrust 
  };

  struct nex_vec4f y_vec = { 
    .y = commands->yaw 
  };

  struct motor_stats stats; 
  bb_mixer_compute_actuators_output(&t_vec, actuators, count, updated_values, &stats);

  float rp_scale = 1.0f;
  float yaw_scale = 1.0f;

  for (u32 i = 0; i < count; ++i)
  {
    // thrust_n + rp * scale = bound
    // rp * scale = (bound - thrust_n)
    // scale = (bound - thrust_n) / rp
    struct nex_vec4f* motor_vec = &actuators[i].axes_vec;
    float rp = nex_vec4f_dot(motor_vec, &rp_vec);
    float bound = rp < 0.0f ? min_allowed_thrust : max_allowed_thrust;
    float scale = (bound - actuators[i].cur) / rp;
    rp_scale = MIN(rp_scale, scale);
  }

  rp_scale = CLAMP(rp_scale, 0.0f, 1.0f);

  for (u32 i = 0; i < count; ++i)
  {
    // thrust_n + rp * scale + yaw * scale_yaw = bound
    // rp * scale + yaw * scale_yaw = bound - thrust_n
    // scaled_rp + scaled_yaw = bound - thrust_n
    // scaled_yaw = bound - thrust_n - scaled_rp
    // scale_yaw * yaw = bound - thrust_n - scaled_rp
    // scale_yaw = (bound - thrust_n - scaled_rp) / yaw
    struct nex_vec4f* motor_vec = &actuators[i].axes_vec;
    float rp = nex_vec4f_dot(motor_vec, &rp_vec);
    float yaw = nex_vec4f_dot(motor_vec, &y_vec);
    float bound = yaw < 0.0f ? min_allowed_thrust : max_allowed_thrust;
    float scale = (bound - actuators[i].cur - rp_scale * rp) / yaw;
    yaw_scale = MIN(yaw_scale, scale);
  }

  yaw_scale = CLAMP(yaw_scale, 0.0f, 1.0f);

  for (u32 i = 0; i < count; ++i)
  {
    struct nex_vec4f* motor_vec = &actuators[i].axes_vec;
    float rp = nex_vec4f_dot(motor_vec, &rp_vec);
    float yaw = nex_vec4f_dot(motor_vec, &y_vec);
    float cur = actuators[i].cur;
    cur = cur + rp * rp_scale + yaw * yaw_scale;
    cur = CLAMP(cur, min_allowed_thrust, max_allowed_thrust);
    actuators[i].cur = cur;
  }
}

void
bb_quadcopter_mixer_compute(
  struct bb_vehicle* vehicle,
  struct bb_vehicle_commands* commands,
  struct bb_actuator* actuators,
  u16* updated_values,
  u32 count
)
{
  bb_quadcopter_mixer_compute_priority_trpy(vehicle, commands, actuators, updated_values, count);
}
