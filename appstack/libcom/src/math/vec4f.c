#include "libcom/math/vec4f.h"

float
nex_vec4f_dot(
  struct nex_vec4f* a,
  struct nex_vec4f* b
)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
}

