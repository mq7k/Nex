#ifndef STM32F4DS_H
#define STM32F4DS_H

#include "ds/dscom.h"

#if defined(STM32F401xD) || defined(STM32F401xE)
#include "ds/ds100086.h"
#elif defined(STM32F401xB) || defined(STM32F401xC)
#include "ds/ds9716.h"
#elif defined(STM32F405xx) || defined(STM32F407xx)
#include "ds/ds8626.h"
#elif defined(STM32F410x8) || defined(STM32F410xB)
#include "ds/ds11144.h"
#elif defined(STM32F411xC) || defined(STM32F411xE)
#include "ds/ds10314.h"
#elif defined(STM32F412xE) || defined(STM32F412xG)
#include "ds/ds11139.h"
#elif defined(STM32F413xG) || defined(STM32F413xH)
#include "ds/ds11581.h"
#elif defined(STM32F415xx) || defined(STM32F417xx)
#include "ds/ds8597.h"
#elif defined(STM32F423xH)
#include "ds/ds11580.h"
#elif defined(STM32F427xx) || defined(STM32F429xx)
#include "ds/ds9405.h"
#elif defined(STM32F437xx) || defined(STM32F439xx)
#include "ds/ds9484.h"
#elif defined(STM32F446xC) || defined(STM32F446xE)
#include "ds/ds10693.h"
#elif defined(STM32F469xx)
#include "ds/ds11189.h"
#elif defined(STM32F479xx)
#include "ds/ds11118.h"
#else
#error "No matching device specs found."
#endif

#endif
