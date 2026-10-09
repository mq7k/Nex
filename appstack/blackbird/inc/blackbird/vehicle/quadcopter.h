#ifndef BLACKBIRD_VEHICLE_QUADCOPTER_H
#define BLACKBIRD_VEHICLE_QUADCOPTER_H

#include "blackbird/motors/actuator.h"
#include "blackbird/vehicle/vehicle.h"
#include "blackbird/inputs.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

void
bb_quadcopter_mixer_compute(
  struct bb_vehicle* vehicle,
  struct bb_vehicle_commands* commands,
  struct bb_actuator* actuators,
  u16* updated_values,
  u32 count
);

END_DECLARATIONS

#endif
