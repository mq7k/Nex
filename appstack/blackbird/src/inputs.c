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
