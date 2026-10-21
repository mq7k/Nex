#ifndef BLACKBIRD_MODES_ACRO_H
#define BLACKBIRD_MODES_ACRO_H

#include "blackbird/vehicle/vehicle.h"
#include "blackbird/inputs.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

void
bb_mode_acro_compute(
  struct bb_vehicle* vehicle,
  struct bb_input_channels* inputs,
  struct bb_vehicle_commands* commands,
  float dt
);

END_DECLARATIONS

#endif
