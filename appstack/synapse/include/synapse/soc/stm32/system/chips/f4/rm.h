#ifndef STM32F4RM_H
#define STM32F4RM_H

#include "rm/rmcom.h"

#if defined(STM32F401xB) || defined(STM32F401xC) ||\
    defined(STM32F401xD) || defined(STM32F401xE)
#include "rm/rm0368.h"
#elif defined(STM32F411xC) || defined(STM32F411xE)
#include "rm/rm0383.h"
#elif defined(STM32F405xx) || defined(STM32F415xx) ||\
      defined(STM32F407xx) || defined(STM32F417xx) ||\
      defined(STM32F427xx) || defined(STM32F437xx) ||\
      defined(STM32F429xx) || defined(STM32F439xx)
#include "rm/rm0090.h"
#elif defined(STM32F410xx)
#include "rm/rm0401.h"
#elif defined(STM32F412xx)
#include "rm/rm0402.h"
#elif defined(STM32F413xx) || defined(STM32F423xx)
#include "rm/rm0430.h"
#elif defined(STM32F446xx)
#include "rm/rm0390.h"
#elif defined(STM32F469xx) || defined(STM32F479xx)
#include "rm/rm0386.h"
#else
#error "No matching register model found."
#endif

#endif
