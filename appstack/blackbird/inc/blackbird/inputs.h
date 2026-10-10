#ifndef BLACKBIRD_INPUTS_H
#define BLACKBIRD_INPUTS_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#define BB_MAX_CHANNELS (16)

#define BB_CHANNEL_LOW_THRESHOLD (250)
#define BB_CHANNEL_CENTER_THRESHOLD_LOW (900)
#define BB_CHANNEL_CENTER_THRESHOLD_HIGH (1050)
#define BB_CHANNEL_HIGH_THRESHOLD (1600)

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

u32
bb_is_channel_low(
  u32 value
);

u32
bb_is_channel_centered(
  u32 value
);

u32
bb_is_channel_high(
  u32 value
);

END_DECLARATIONS

#endif
