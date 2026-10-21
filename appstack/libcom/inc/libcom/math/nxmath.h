#ifndef NEX_NXMATH_H
#define NEX_NXMATH_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

float
nex_lerpf(
  float value,
  float min_value,
  float max_value,
  float min_range,
  float max_range
);

END_DECLARATIONS

#endif
