#ifndef LIBCOM_MATH_VEC4F_H
#define LIBCOM_MATH_VEC4F_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

/*
 * We follow the column approach.
 * A vector of N elements is conceptually equal to
 * a Nx1 matrix (aka N rows, 1 column).
 * So, the vec2f { .x = 0, .y = 1 }, is threated as
 * a 2x1 matrix:
 * [
 *    0,
 *    1
 * ]
 */

struct nex_vec4f
{
  union
  {
    struct 
    {
      float x;
      float y;
      float z;
      float w;
    };

    struct 
    {
      float arr[4];
    };
  };
};

float
nex_vec4f_dot(
  struct nex_vec4f* a,
  struct nex_vec4f* b
);

END_DECLARATIONS

#endif
