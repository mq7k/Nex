#ifndef BLACKBIRD_INPUTS_H
#define BLACKBIRD_INPUTS_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#define BB_MAX_CHANNELS (16)

struct bb_input_channels
{
  u16 channels[BB_MAX_CHANNELS];
};

struct bb_vehicle_commands
{
  // Thrust, yaw, roll, pitch
  float thrust;
  float yaw;
  float roll;
  float pitch;

  float pot[2];

  u32 switches;
};

END_DECLARATIONS

#endif
