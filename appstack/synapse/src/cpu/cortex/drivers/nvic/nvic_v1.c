#include "synapse/cpu/cortex/drivers/nvic/nvic_v1.h"
#include "synapse/common/handlers.h"
#include "synapse/cpu/cortex/common/memorymap.h"
#include "util.h"

typedef volatile struct nvic_registers_map nvic_periph;
nvic_periph* NVIC = (nvic_periph*) (ARCH_NVIC_ADDR);

void
nvic_irq_enable(
  enum nvic_irq interrupt
)
{
  const u32 idx = interrupt >> 5;
  const u32 bitshift = FAST_MOD(interrupt, 32);
  NVIC->ISER[idx] = 1u << bitshift;
}

void
nvic_irq_disable(
  enum nvic_irq interrupt
)
{
  const u32 idx = interrupt >> 5;
  const u32 bitshift = FAST_MOD(interrupt, 32);
  NVIC->ICER[idx] = 1u << bitshift;
}

u32
nvic_is_irq_enabled(
  enum nvic_irq interrupt
)
{
  const u32 idx = interrupt >> 5;
  const u32 bitshift = FAST_MOD(interrupt, 32);
  return NVIC->ISER[idx] & (1u << bitshift);
}

void
nvic_set_irq_pending(
  enum nvic_irq interrupt
)
{
  const u32 idx = interrupt >> 5;
  const u32 bitshift = FAST_MOD(interrupt, 32);
  NVIC->ISPR[idx] = (1u << bitshift);
}

void
nvic_clear_pending_irq(
  enum nvic_irq interrupt
)
{
  const u32 idx = interrupt >> 5;
  const u32 bitshift = FAST_MOD(interrupt, 32);
  NVIC->ICPR[idx] = (1u << bitshift);
}

u32
nvic_is_irq_being_processed(
  enum nvic_irq interrupt
)
{
  const u32 idx = interrupt >> 5;
  const u32 bitshift = FAST_MOD(interrupt, 32);
  return NVIC->IABR[idx] & (1u << bitshift);
}

void
nvic_set_irq_priority(
  enum nvic_irq interrupt,
  u32 priority
)
{
  const u32 shift = FAST_MOD(interrupt, 4) << 3;
  const u32 mask = NVIC_IPR_MASK << shift;
  const u32 idx = interrupt >> 2;
  volatile u32* reg = &NVIC->IPR[idx];
  syn_set_register_bits(reg, mask, priority << shift);
}

u32
nvic_get_irq_priority(
  enum nvic_irq interrupt
)
{
  constexpr u32 mask = NVIC_IPR_MASK;
  const u32 shift = FAST_MOD(interrupt, 4) << 3;
  const u32 idx = interrupt >> 2;
  volatile u32* reg = &NVIC->IPR[idx];
  return (*reg >> shift) & mask;
}

void
nvic_trigger_irq(
  enum nvic_irq interrupt
)
{
  NVIC->STIR = interrupt;
}

// Core exceptions.
NEX_WEAK
void 
nmi_handler(void)
{
  while (1);
}

NEX_WEAK
void 
hard_fault_handler(void)
{
  while (1);
}

NEX_WEAK
void
memory_fault_handler(void)
{
  while (1);
}

NEX_WEAK
void
bus_fault_handler(void)
{
  while (1);
}

NEX_WEAK
void
usage_fault_handler(void)
{
  while (1);
}

NEX_WEAK
void
debug_monitor_handler(void)
{
  while (1);
}

NEX_WEAK
void
sv_call_handler(void)
{
  while (1);
}

NEX_WEAK
void
pend_sv_handler(void)
{
  while (1);
}

NEX_WEAK
void
systick_handler(void)
{
  while (1);
}

// SoC exceptions.
NEX_WEAK
void
wwdg_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
pvd_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tamper_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
rtc_wakeup_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
flash_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
rcc_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
exti0_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
exti1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
exti2_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
exti3_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
exti4_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_stream0_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_stream1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_stream2_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_stream3_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_stream4_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_stream5_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_stream6_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
adc_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_CAN1)
NEX_WEAK
void
can1_tx_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
can1_rx0_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
can1_rx1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
can1_sce_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
exti9_5_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim1_brk_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim1_up_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim1_trg_com_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim1_cc_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_TIM2)
NEX_WEAK
void
tim2_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_TIM3)
NEX_WEAK
void
tim3_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_TIM4)
NEX_WEAK
void
tim4_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
i2c1_ev_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
i2c1_er_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
i2c2_ev_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
i2c2_er_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
spi1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
spi2_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
usart1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
usart2_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_USART3)
NEX_WEAK
void
usart3_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
exti15_10_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
rtc_alarm_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_USB_OTG_FS)
NEX_WEAK
void
otg_fs_wkup_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_TIM8)
NEX_WEAK
void
tim8_brk_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim8_up_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim8_trg_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim8_cc_isr(void)
{
  default_isr_handler();
}
#endif

void
dma1_stream7_isr(void);

#if defined(STM32_FSMC)
NEX_WEAK
void
fsmc_isr(void)
{
  default_isr_handler();
}
#elif defined(STM32_FMC)
NEX_WEAK
void
fmc_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_SDIO)
NEX_WEAK
void
sdio_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
tim5_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_SPI3)
NEX_WEAK
void
spi3_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_UART4)
NEX_WEAK
void
uart4_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_UART4)
NEX_WEAK
void
uart5_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
tim6_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_TIM7)
NEX_WEAK
void
tim7_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
dma2_stream0_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_stream1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_stream2_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_stream3_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_stream4_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_ETH)
NEX_WEAK
void
eth_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
eth_wkup_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_CAN2)
NEX_WEAK
void
can2_tx_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
can2_rx0_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
can2_rx1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
can2_sce_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_USB_OTG_FS)
NEX_WEAK
void
otg_fs_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
dma2_stream5_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_stream6_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_stream7_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
usart6_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_I2C3)
NEX_WEAK
void
i2c3_event_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
i2c3_error_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_USB_OTG_HS)
NEX_WEAK
void
otg_hs_ep1_out_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
otg_hs_ep1_in_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
otg_hs_wakeup_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
otg_hs_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_DCMI)
NEX_WEAK
void
dcmi_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_CRYP)
NEX_WEAK
void
cryp_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_HASH) || defined(STM32_RNG)
NEX_WEAK
void
hash_rng_isr(void)
{
  default_isr_handler();
}
#endif

NEX_WEAK
void
fpu_isr(void)
{
  default_isr_handler();
}

#if defined(STM32_UART7)
NEX_WEAK
void
usart7_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_UART8)
NEX_WEAK
void
usart8_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_SPI4)
NEX_WEAK
void
spi4_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_SPI5)
NEX_WEAK
void
spi5_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_SPI6)
NEX_WEAK
void
spi6_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_SAI1)
NEX_WEAK
void
sai1_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_LCD_TFT)
NEX_WEAK
void
lcd_tft_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
lcd_tft_error_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_DMA2D)
NEX_WEAK
void
dma2d_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_SAI2)
NEX_WEAK
void
sai2_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_QUADSPI)
NEX_WEAK
void
quadspi_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_HDMI_CEC)
NEX_WEAK
void
hdmi_cec_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_SPDIFRX)
NEX_WEAK
void
spdifrx_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_FMPI2C1)
NEX_WEAK
void
fmpi2c1_event_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
fmpi2c1_error_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_DSI)
NEX_WEAK
void
dsi_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_I2C4)
NEX_WEAK
void
i2c4_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_LPTIM1)
NEX_WEAK
void
lptim1_isr(void)
{
  default_isr_handler();
}
#endif

#if defined(STM32_DFSDM2)
NEX_WEAK
void
dfsdm2_flt0_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dfsdm2_flt1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dfsdm2_flt2_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dfsdm2_flt3_isr(void)
{
  default_isr_handler();
}
#endif
