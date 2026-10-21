#ifndef LIBCOM_MATH_VEC4F_H
#define LIBCOM_MATH_VEC4F_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

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
