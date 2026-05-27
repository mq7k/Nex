#ifndef SYN_CORTEX_COM_MEMORY_H
#define SYN_CORTEX_COM_MEMORY_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

void*
memset(
  void* dst,
  int byte,
  size_t len
);

void*
memset16(
  void* dst,
  u8 byte,
  u32 len
);

void*
memset32(
  void* dst,
  u8 byte,
  u32 len
);

void*
memset32x4(
  void* dst,
  u8 byte,
  u32 len
);

void*
memset32x8(
  void* dst,
  u8 byte,
  u32 len
);

void*
memcpy(
  void* dst,
  const void* src,
  size_t len
);

void*
memcpy16(
  void* dst,
  const void* src,
  u32 len
);

void*
memcpy32(
  void* dst,
  const void* src,
  u32 len
);

void*
memcpy32x2(
  void* dst,
  const void* src,
  u32 len
);

void*
memcpy32x4(
  void* dst,
  const void* src,
  u32 len
);

void*
memcpy32x8(
  void* dst,
  const void* src,
  u32 len
);

END_DECLARATIONS

#endif
