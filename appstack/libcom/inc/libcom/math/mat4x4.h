#ifndef LIBCOM_MATH_MAT4X4_H
#define LIBCOM_MATH_MAT4X4_H

#include "libcom/math/vec4f.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

struct nex_mat4x4f
{
  float arr[16];
};

void 
nex_mat4x4f_mul_vec4f(
  struct nex_vec4f* res,
  struct nex_mat4x4f* src,
  struct nex_vec4f* vec
);

END_DECLARATIONS

#endif
