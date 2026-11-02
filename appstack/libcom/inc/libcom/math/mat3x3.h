#ifndef LIBCOM_MATH_MAT3X3_H
#define LIBCOM_MATH_MAT3X3_H

#include "libcom/math/vec3f.h"
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

struct nex_mat3x3f
{
  float arr[9];
};

void 
nex_mat3x3f_mul_vec3f(
  struct nex_vec3f* res,
  struct nex_mat3x3f* src,
  struct nex_vec3f* vec
);

END_DECLARATIONS

#endif
