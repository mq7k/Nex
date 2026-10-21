#include "libcom/algo/pid.h"

float
nex_pid_tick(
  struct nex_pid* pid,
  float target,
  float cur,
  float dt
)
{
  float err = target - cur;

  float d = (err - pid->err) / dt;

  // Option 1
  pid->filtd = pid->alpha * d + (1 - pid->alpha) * pid->filtd;

  // Option 2
  // pid->filtd = d;

  pid->i += err * dt;
  if (pid->i < pid->imin)
  {
    pid->i = pid->imin;
  }
  else if (pid->i > pid->imax)
  {
    pid->i = pid->imax;
  }

  pid->err = err;
  float out = (pid->kp * err) + (pid->ki * pid->i) + (pid->kd * pid->filtd);
  return out;
}
