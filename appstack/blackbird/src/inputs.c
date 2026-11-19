#include "blackbird/inputs.h"

u32
bb_is_channel_low(
  u32 value
)
{
  return value <= BB_CHANNEL_LOW_THRESHOLD;
}

u32
bb_is_channel_centered(
  u32 value
)
{
  return value >= BB_CHANNEL_CENTER_THRESHOLD_LOW &&
         value <= BB_CHANNEL_CENTER_THRESHOLD_HIGH;
}

u32
bb_is_channel_high(
  u32 value
)
{
  return value >= BB_CHANNEL_HIGH_THRESHOLD;
}

void
bb_init_def_ch_mapping(
  struct bb_input_map* map
)
{
  for (u32 i = 0; i < BB_MAX_CHANNELS; ++i)
  {
    map->channels[i] = (u8) (i + 1);
  }
}

void
bb_map_channels(
  struct bb_input_channels* channels_in,
  struct bb_input_channels* channels_out,
  struct bb_input_map* map
)
{
  for (u32 i = 0; i < BB_MAX_CHANNELS; ++i)
  {
    const u32 src_channel = map->channels[i];
    if (src_channel == BB_UNUSED_CH)
    {
      // Unconfigured, ignore it.
      channels_out->channels[i] = 0;
      continue;
    }

    channels_out->channels[i] = channels_in->channels[src_channel - 1];
  }
}

u16
bb_get_input_channel(
  struct bb_input_channels* channels,
  enum bb_input input
)
{
  return channels->channels[input - 1];
}
