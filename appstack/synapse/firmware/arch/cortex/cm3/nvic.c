#include "synapse/arch/cortex/cm3/nvic.h"
#include "synapse/common/util/common.h"

typedef volatile struct nvic_registers_map nvic_periph;
nvic_periph* NVIC = (nvic_periph*) (0xe000e100);

void
nvic_enable_irq(
  enum nvic_irq interrupt
)
{
  NVIC->ISER[interrupt / 32] = (1 << (interrupt % 32));
}

void
nvic_disable_irq(
  enum nvic_irq interrupt
)
{
  NVIC->ICER[interrupt / 32] = (1 << (interrupt % 32));
}

u32
nvic_is_irq_enabled(
  enum nvic_irq interrupt
)
{
  return NVIC->ISER[interrupt / 32] & (1 << (interrupt % 32));
}

void
nvic_set_pending_irq(
  enum nvic_irq interrupt
)
{
  NVIC->ISPR[interrupt / 32] = (1 << (interrupt % 32));
}

void
nvic_clear_pending_irq(
  enum nvic_irq interrupt
)
{
  NVIC->ICPR[interrupt / 32] = (1 << (interrupt % 32));
}

uintptr_t
nvic_is_irq_being_processed(
  enum nvic_irq interrupt
)
{
  return NVIC->IABR[interrupt / 32] & (1 << (interrupt % 32));
}

void
nvic_set_irq_priority(
  enum nvic_irq interrupt,
  u32 priority
)
{
  const u32 shift = FAST_MOD(interrupt, 4) * 8;
  const u32 mask = NVIC_IPR_MASK << shift;
  syn_set_register_bits(&NVIC->IPR[interrupt / 4], mask, priority << shift);
}

u32
nvic_get_irq_priority(
  enum nvic_irq interrupt
)
{
  constexpr u32 mask = NVIC_IPR_MASK;
  const u32 shift = FAST_MOD(interrupt, 4) * 8;
  u32 reg = NVIC->IPR[interrupt / 4];
  return (reg >> shift) & mask;
}

void
nvic_trigger_irq(
  enum nvic_irq interrupt
)
{
  NVIC->STIR = interrupt;
}

/* Default implementations */
void blocking_handler(void)
{
  while (1);
}

void null_handler(void)
{

}

/* Core exceptions */
void nmi_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void hard_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void memory_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void bus_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void usage_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void debug_monitor_handler(void) NEX_WEAK_NEX_ALIAS("null_handler");
void sv_call_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void pend_sv_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void systick_handler(void) NEX_WEAK_NEX_ALIAS("null_handler");

/* Interrupts service routines */
void wwdg_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void pvd_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tamper_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void rtc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void flash_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void rcc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_ch1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_ch2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_ch3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_ch4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_ch5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_ch6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma1_ch7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void adc1_2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can1_tx_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can1_rx0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can1_rx1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can1_sce_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti9_5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_brk_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_up_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_trg_com_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim1_cc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void i2c1_ev_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void i2c1_er_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void i2c2_ev_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void i2c2_er_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void spi1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void spi2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void usart1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void usart2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void usart3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void exti15_10_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void rtc_alarm_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void otg_fs_wkup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void spi3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void uart4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void uart5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void tim7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_ch1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_ch2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_ch3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_ch4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void dma2_ch5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void eth_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void eth_wkup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can2_tx_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can2_rx0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can2_rx1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void can2_sce_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
void otg_fs_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
