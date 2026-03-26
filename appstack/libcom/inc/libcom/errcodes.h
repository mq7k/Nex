#ifndef LIBCOM_ERRCODES_H
#define LIBCOM_ERRCODES_H

#include "libcom/util.h"

BEGIN_DECLARATIONS

enum nex_code : i32
{
  NOK = 0,
  NERR_INV_ARG = 1,
  NERR_RANGE = 2,
  NERR_FULL = 3,
  NERR_NOT_FOUND = 4,
  NERR_EMPTY = 5,
};

END_DECLARATIONS

#endif
