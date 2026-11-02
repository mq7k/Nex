#ifndef LIBCOM_MATH_MAT4X4_H
#define LIBCOM_MATH_MAT4X4_H

#include "libcom/math/vec4f.h"
#include "libcom/util.h"

/*
 * We follow the column approach.
 * If we take the following 2x2 matrix as an example:
 * [
 *    0, 1,
 *    2, 3
 * ]
 *
 * arr[0] = 0,
 * arr[1] = 2,
 * arr[2] = 1,
 * arr[3] = 3
 *
 * This also makes it easier to define rotation matrices,
 * since unit vectors are contiguous.
 * A 45deg rotation matrix is therefor:
 *
 * // X unit vector
 * arr[0] = cos(45deg)
 * arr[1] = sin(45deg)
 *
 * // Y unit vector
 * arr[2] = -sin(45deg)
 * arr[3] = cos(45deg)
 */

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
