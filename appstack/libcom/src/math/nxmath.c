#include "libcom/math/nxmath.h"

float
nex_lerpf(
  float value,
  float min_value,
  float max_value,
  float min_range,
  float max_range
)
{
  const float range = max_range - min_range;
  return ((value - min_value) / (max_value - min_value)) * range + min_range;
}
