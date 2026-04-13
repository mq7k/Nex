#include "synapse/cpu/cortex/drivers/nvic/nvic_v2.h"
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
void 
nmi_handler(void)
{
  while (1);
}

void 
hard_fault_handler(void)
{
  while (1);
}

void
memory_fault_handler(void)
{
  while (1);
}

void
bus_fault_handler(void)
{
  while (1);
}

void
usage_fault_handler(void)
{
  while (1);
}

void
debug_monitor_handler(void)
{
  while (1);
}

void
sv_call_handler(void)
{
  while (1);
}

void
pend_sv_handler(void)
{
  while (1);
}

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
dma1_channel1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_channel2_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_channel3_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_channel4_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_channel5_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_channel6_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma1_channel7_isr(void)
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
tim8_brk_tim12_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim8_up_tim13_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
tim8_trg_tim14_isr(void)
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

#if defined(STM32_ADC3)
NEX_WEAK
void
adc3_isr(void)
{
  default_isr_handler();
}
#endif

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
dma2_channel1_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_channel2_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_channel3_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_channel4_isr(void)
{
  default_isr_handler();
}

NEX_WEAK
void
dma2_channel5_isr(void)
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

