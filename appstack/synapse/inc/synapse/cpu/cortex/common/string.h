#ifndef SYN_CORTEX_COM_STRING_H
#define SYN_CORTEX_COM_STRING_H

#include "util.h"

BEGIN_DECLARATIONS

size_t
strlen(
  const char* str
);

size_t
strlen8(
  const char* str
);

int
strcmp(
  const char* a,
  const char* b
);

int
strcmp8(
  const char* a,
  const char* b
);

int
strncmp(
  const char* a,
  const char* b,
  u32 len
);

int
strncmp8(
  const char* a,
  const char* b,
  u32 len
);

END_DECLARATIONS

#endif
