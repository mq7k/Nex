#ifndef BB_CONF_H
#define BB_CONF_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

#if !defined(BB_DEVICE_NAME)
#define BB_DEVICE_NAME ("Generic FC")
#endif

#if !defined(BB_SERIAL_NUMBER)
#define BB_SERIAL_NUMBER (0)
#endif

#if !defined(BB_HARDWARE_ID)
#define BB_HARDWARE_ID (0)
#endif

#if !defined(BB_FIRMWARE_ID)
#define BB_FIRMWARE_ID (0)
#endif

END_DECLARATIONS

#endif
