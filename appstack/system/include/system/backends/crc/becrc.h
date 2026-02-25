#ifndef SYSTEM_BACKEND_CRC_H
#define SYSTEM_BACKEND_CRC_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

struct becrc_vtable
{
  u32 (*lock)(void);
  void (*release)(void);
  void (*reset)(void);
  void (*compute)(u8* data, u32 len);
  u32 (*ready)(void);
  u32 (*read)(void);
};

END_DECLARATIONS

#endif
