#include "types.h"
#include "util.h"

u32 __stack_chk_guard;

NEX_WEAK
void
__stack_chk_fail(void)
{
  while (1);
}

u32
syn_stkchk_guard_generate_def(void)
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

  seed = nex_murmur_hash3_fmix32(seed);
  if (seed == 0)
  {
    seed = 0xa5a5a5a5;
  }

  return seed;
}

NEX_WEAK
u32
syn_stkchk_guard_generate(void)
{
  return syn_stkchk_guard_generate_def();
}
