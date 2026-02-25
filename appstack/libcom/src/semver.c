#include "libcom/semver.h"

u32
nex_encode_version(
  struct nex_semver* ver
)
{
  u32 value = 0;
  value |= (ver->major << NEX_SEMVER_MAJOR_SHIFT);
  value |= (ver->minor << NEX_SEMVER_MINOR_SHIFT);
  value |= (ver->patch << NEX_SEMVER_PATCH_SHIFT);
  return value;
}

void
nex_decode_version(
  struct nex_semver* ver,
  u32 version
)
{
  ver->major = (version >> NEX_SEMVER_MAJOR_SHIFT) & NEX_SEMVER_MAJOR_MASK;
  ver->minor = (version >> NEX_SEMVER_MINOR_SHIFT) & NEX_SEMVER_MINOR_MASK;
  ver->patch = (version >> NEX_SEMVER_PATCH_SHIFT) & NEX_SEMVER_PATCH_MASK;
}
