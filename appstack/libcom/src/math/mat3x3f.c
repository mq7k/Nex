#include "libcom/math/mat3x3.h"

void 
nex_mat3x3f_mul_vec3f(
  struct nex_vec3f* res,
  struct nex_mat3x3f* src,
  struct nex_vec3f* vec
)
{
  for (u32 i = 0; i < 3; ++i)
  {
    float acc = 0.0f;
    const u32 off = i << 2;
    for (u32 j = 0; j < 3; ++j)
    {
      acc += (src->arr[j + off] * vec->arr[j]);
    }
    res->arr[i] = acc;
  }
}
