#ifndef NEX_SEMVER_H
#define NEX_SEMVER_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

#define NEX_SEMVER_MAJOR_SHIFT (22)
#define NEX_SEMVER_MAJOR_MASK (0x3ff)

#define NEX_SEMVER_MINOR_SHIFT (12)
#define NEX_SEMVER_MINOR_MASK (0x3ff)

#define NEX_SEMVER_PATCH_SHIFT (0)
#define NEX_SEMVER_PATCH_MASK (0xfff)

struct nex_semver
{
  u32 major;
  u32 minor;
  u32 patch;
};

u32
nex_encode_version(
  struct nex_semver* ver
);

void
nex_decode_version(
  struct nex_semver* ver,
  u32 version
);

END_DECLARATIONS

#endif
