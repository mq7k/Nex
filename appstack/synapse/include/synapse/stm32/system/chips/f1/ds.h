#ifndef STM32F1DS_H
#define STM32F1DS_H

#if defined(STM32F100xC) || defined(STM32F100xD) || defined(STM32F100xE)
#include "ds/ds5944.h"
#elif defined(STM32F100x4) || defined(STM32F100x6) || defined(STM32F100x8) || defined(STM32F100xB)
#include "ds/ds6517.h"
#elif defined(STM32F101x4) || defined(STM32F101x6)
#include "ds/ds5935.h"
#elif defined(STM32F101x8) || defined(STM32F101xB)
#include "ds/ds5318.h"
#elif defined(STM32F101xC) || defined(STM32F101xD) || defined(STM32F101xE)
#include "ds/ds5791.h"
#elif defined(STM32F101xF) || defined(STM32F101xG)
#include "ds/ds6557.h"
#elif defined(STM32F102x4) || defined(STM32F102x6)
#include "ds/ds5934.h"
#elif defined(STM32F102x8) || defined(STM32F102xB)
#include "ds/ds5933.h"
#elif defined(STM32F103x4) || defined(STM32F103x6)
#include "ds/ds5936.h"
#elif defined(STM32F103x8) || defined(STM32F103xB)
#include "ds/ds5319.h"
#elif defined(STM32F103xC) || defined(STM32F103xD) || defined(STM32F103xE)
#include "ds/ds5792.h"
#elif defined(STM32F103xF) || defined(STM32F103xG)
#include "ds/ds6558.h"
#elif defined(STM32F105xx) || defined(STM32F107xx)
#include "ds/ds6014.h"
#else
#error "No matching device specs found."
#endif

#endif
