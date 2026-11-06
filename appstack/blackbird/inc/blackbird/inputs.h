#ifndef BLACKBIRD_INPUTS_H
#define BLACKBIRD_INPUTS_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#define BB_MAX_CHANNELS (16)

#define BB_CHANNEL_LOW_THRESHOLD (250)
#define BB_CHANNEL_CENTER_THRESHOLD_LOW (900)
#define BB_CHANNEL_CENTER_THRESHOLD_HIGH (1050)
#define BB_CHANNEL_HIGH_THRESHOLD (1600)
#define BB_IN2CH(in) ((in) - 1)
#define BB_UNUSED_CH (0)

struct bb_input_channels
{
  u16 channels[BB_MAX_CHANNELS];
};

// Valid channels starts from 1.
// 0 means unused.
struct bb_input_map
{
  u8 channels[BB_MAX_CHANNELS];
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

enum bb_input
{
  BB_IN_THROTTLE = 1,
  BB_IN_YAW = 2,
  BB_IN_PITCH = 3,
  BB_IN_ROLL = 4,
  BB_IN_FLIGHT_MODE = 6,
  BB_IN_ARM = 8,
  BB_IN_BEEP = 10
};

enum bb_input_ch
{
  BB_CH_THROTTLE = BB_IN2CH(BB_IN_THROTTLE),
  BB_CH_YAW = BB_IN2CH(BB_IN_YAW),
  BB_CH_PITCH = BB_IN2CH(BB_IN_PITCH),
  BB_CH_ROLL = BB_IN2CH(BB_IN_ROLL),
  BB_CH_FLIGHT_MODE = BB_IN2CH(BB_IN_FLIGHT_MODE),
  BB_CH_ARM = BB_IN2CH(BB_IN_ARM),
  BB_CH_BEEP = BB_IN2CH(BB_IN_BEEP)
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

void
bb_init_def_ch_mapping(
  struct bb_input_map* map
);

void
bb_map_channels(
  struct bb_input_channels* channels_in,
  struct bb_input_channels* channels_out,
  struct bb_input_map* map
);

u16
bb_get_input_channel(
  struct bb_input_channels* channels,
  enum bb_input input
);

END_DECLARATIONS

#endif
