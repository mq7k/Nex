#ifndef STM32_DMA_H
#define STM32_DMA_H

#include "synapse/specs.h"

#if defined(STM32_DMA_V1)
#include "synapse/stm32/drivers/dma/dma_v1.h"
#elif defined(STM32_DMA_V2)
#include "synapse/stm32/drivers/dma/dma_v2.h"
#else
#error "No DMA version specified."
#endif

#endif
