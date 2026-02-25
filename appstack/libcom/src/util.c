#include "libcom/util.h"
#include "libcom/types.h"

u32
nex_is_power_of_two(
  u32 value
)
{
  return (value & (value - 1)) == 0;
}

u32
nex_align_addr(
  u32 addr,
  u32 alignment
)
{
  const u32 not_align = ~(alignment - 1);
  const u32 offset = addr & (alignment - 1);
  return (addr + alignment * !!offset) & not_align;
}

u32
nex_is_addr_aligned(
  void* addr,
  u32 alignment
)
{
  const uptr addr_ptr = (uptr) addr;
  return addr_ptr == (addr_ptr & (alignment - 1));
}
