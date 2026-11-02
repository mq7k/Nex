#ifndef LIBCOM_MATH_VECI3F_H
#define LIBCOM_MATH_VECI3F_H

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

struct nex_vec3f
{
  union
  {
    struct
    {
      float x;
      float y;
      float z;
    };

    struct
    {
      float arr[3];
    };
  };
};

END_DECLARATIONS

#endif
