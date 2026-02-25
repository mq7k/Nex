#ifndef STM32_DMA2D_H
#define STM32_DMA2D_H

#include "synapse/specs.h"

#if defined(STM32_DMA2D_V1)
#include "synapse/stm32/drivers/dma2d/dma2d_v1.h"
#else
#error "No DMA2D version specified."
#endif

#endif
