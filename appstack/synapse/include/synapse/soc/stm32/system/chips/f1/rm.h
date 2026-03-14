#ifndef STM32F1RM_H
#define STM32F1RM_H

#include "rm/rmcom.h"

#if defined(STM32F100xx)
#include "rm/rm0041.h"
#elif defined(STM32F101xx) || defined(STM32F102xx) ||\
    defined(STM32F103xx) || defined(STM32F105xx) ||\
    defined(STM32F107xx)
#include "rm/rm0008.h"
#else
#error "No matching register model found."
#endif

#endif
