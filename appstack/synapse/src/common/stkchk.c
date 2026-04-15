#include "types.h"
#include "util.h"

u32 __stack_chk_guard;

NEX_WEAK
void
__stack_chk_fail(void)
{
  while (1);
}

static u32
mix(
  u32 x
)
{
  x ^= x >> 16;
  x *= 0x7feb352d;
  x ^= x >> 15;
  x *= 0x846ca68b;
  x ^= x >> 16;
  return x;
}

NEX_WEAK
u32
syn_stkchk_guard_generate(void)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

  u32 seed;

  seed ^= *(volatile u32*) 0x20000000;
  seed ^= (u32) &seed;

  u32 noise[16];
  for (u32 i = 0; i < 8; ++i)
  {
    if (noise[i] == 0 || noise[i << 1] == 0)
    {
      continue;
    }

    seed ^= noise[i];
    seed *= noise[i << 1];
    seed *= (~noise[i << 1] & 0xffff);
  }

#pragma GCC diagnostic pop

  seed = mix(seed);
  if (seed == 0)
  {
    seed = 0xa5a5a5a5;
  }

  return seed;
}
