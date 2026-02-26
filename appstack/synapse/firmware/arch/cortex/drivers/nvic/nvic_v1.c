#include "synapse/arch/cortex/drivers/nvic/nvic_v1.h"
#include "synapse/arch/cortex/common/memorymap.h"

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

void blocking_handler(void)
{
  while (1);
}

void null_handler(void)
{

}

/* Core exceptions */
void nmi_handler(void)
{
  while (1);
}

void hard_fault_handler(void)
{
  while (1);
}
void memory_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void bus_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void usage_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void debug_monitor_handler(void) NEX_WEAK_NEX_ALIAS("null_handler");
void sv_call_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void pend_sv_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void systick_handler(void) NEX_WEAK_NEX_ALIAS("null_handler");

void wwdg_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void pvd_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tamper_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void rtc_wakeup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void flash_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void rcc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_stream0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_stream1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_stream2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_stream3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_stream4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_stream5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_stream6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void adc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_CAN1)
void can1_tx_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can1_rx0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can1_rx1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can1_sce_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void exti9_5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_brk_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_up_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_trg_com_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_cc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_TIM2)
void tim2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_TIM3)
void tim3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_TIM4)
void tim4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void i2c1_ev_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void i2c1_er_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void i2c2_ev_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void i2c2_er_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void spi1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void spi2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void usart1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void usart2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_USART3)
void usart3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void exti15_10_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void rtc_alarm_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_USB_OTG_FS)
void otg_fs_wkup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_TIM8)
void tim8_brk_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim8_up_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim8_trg_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim8_cc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void dma1_stream7_isr(void);

#if defined(STM32_FSMC)
void fsmc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#elif defined(STM32_FMC)
void fmc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_SDIO)
void sdio_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void tim5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_SPI3)
void spi3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_UART4)
void uart4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_UART4)
void uart5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void tim6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_TIM7)
void tim7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void dma2_stream0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_stream1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_stream2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_stream3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_stream4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_ETH)
void eth_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void eth_wkup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_CAN2)
void can2_tx_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can2_rx0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can2_rx1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can2_sce_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_USB_OTG_FS)
void otg_fs_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void dma2_stream5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_stream6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_stream7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void usart6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_I2C3)
void i2c3_event_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void i2c3_error_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_USB_OTG_HS)
void otg_hs_ep1_out_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void otg_hs_ep1_in_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void otg_hs_wakeup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void otg_hs_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_DCMI)
void dcmi_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_CRYP)
void cryp_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_HASH) || defined(STM32_RNG)
void hash_rng_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

void fpu_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

#if defined(STM32_UART7)
void usart7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_UART8)
void usart8_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_SPI4)
void spi4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_SPI5)
void spi5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_SPI6)
void spi6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_SAI1)
void sai1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_LCD_TFT)
void lcd_tft_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void lcd_tft_error_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_DMA2D)
void dma2d_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_SAI2)
void sai2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_QUADSPI)
void quadspi_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_HDMI_CEC)
void hdmi_cec_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_SPDIFRX)
void spdifrx_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_FMPI2C1)
void fmpi2c1_event_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void fmpi2c1_error_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_DSI)
void dsi_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_I2C4)
void i2c4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_LPTIM1)
void lptim1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif

#if defined(STM32_DFSDM2)
void dfsm2_flt0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dfsm2_flt1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dfsm2_flt2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dfsm2_flt3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
#endif
