#ifndef LIBCOM_ALGO_PID_H
#define LIBCOM_ALGO_PID_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct nex_pid
{
  float err;
  float i;
  float imin;
  float imax;
  float rawd;
  float filtd;
  float alpha;
  float kp;
  float ki;
  float kd;
};

float
nex_pid_tick(
  struct nex_pid* pid,
  float target,
  float cur,
  float dt
);

END_DECLARATIONS

#endif
