#include "libcom/math/mat4x4.h"

/*
 * 1, 3, 9, 4
 * 6, 7, 2, 9
 * 2, 8, 5, 1,
 * 7, 4, 2, 6
 *
 * 5,
 * 1,
 * 2,
 * 0
 */
void 
nex_mat4x4f_mul_vec4f(
  struct nex_vec4f* res,
  struct nex_mat4x4f* src,
  struct nex_vec4f* vec
)
{
  for (u32 i = 0; i < 4; ++i)
  {
    float acc = 0.0f;
    const u32 off = i << 2;
    for (u32 j = 0; j < 4; ++j)
    {
      acc += (src->arr[j + off] * vec->arr[j]);
    }
    res->arr[i] = acc;
  }
}
