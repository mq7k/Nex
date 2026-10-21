#ifndef BLACKBIRD_ACTUATOR_H
#define BLACKBIRD_ACTUATOR_H

#include "libcom/math/vec4f.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

struct bb_actuator
{
  float cur;
  struct nex_vec4f axes_vec;

  u32 min_speed_v;
  u32 max_speed_v;
};

END_DECLARATIONS

#endif
