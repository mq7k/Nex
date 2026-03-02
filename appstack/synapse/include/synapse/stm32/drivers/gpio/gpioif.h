#ifndef SYN_GPIOIF_H
#define SYN_GPIOIF_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct gpioif_config
{
  volatile void* gpio;
  u16 pins;
  u32 mode;
  u32 type;
  u32 speed;
  u32 pupd;
};

enum gpioif_code
{
  GPIOIF_CODE_OK,
  GPIOIF_CODE_INVALID_MODE,
  GPIOIF_CODE_INVALID_TYPE,
  GPIOIF_CODE_INVALID_SPEED,
  GPIOIF_CODE_INVALID_PUPD
};

enum gpioif_mode
{
  GPIOIF_MODE_INPUT,
  GPIOIF_MODE_OUTPUT,
  GPIOIF_MODE_ALTFN,
  GPIOIF_MODE_ANALOG
};

enum gpioif_type
{
  GPIOIF_TYPE_PUSHPULL,
  GPIOIF_TYPE_OPEN_DRAIN
};

enum gpioif_speed
{
  GPIOIF_SPEED_LOW,
  GPIOIF_SPEED_MEDIUM,
  GPIOIF_SPEED_FAST,
  GPIOIF_SPEED_HIGH
};

enum gpioif_pupd
{
  GPIOIF_PUPD_FLOATING,
  GPIOIF_PUPD_PULLUP,
  GPIOIF_PUPD_PULLDOWN
};

u32
gpioif_get_capabilities(void);

// u32
// gpioif_is_capability_supported(
//   enum gpioif_cap cap
// );

enum gpioif_code
gpioif_configure(
  struct gpioif_config* config
);

void
gpioif_pin_toggle(
  volatile void* gpio,
  u32 pins
);

void
gpioif_pin_set_low(
  volatile void* gpio,
  u32 pins
);

void
gpioif_pin_set_high(
  volatile void* gpio,
  u32 pins
);

END_DECLARATIONS

#endif
