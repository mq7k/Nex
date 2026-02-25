#include "synapse/arch/cortex/cm4/nvic.h"
#include "synapse/common/util/common.h"

typedef volatile struct nvic_registers_map nvic_periph;
nvic_periph* NVIC = (nvic_periph*) (0xe000e100);

// Core exceptions

void
blocking_handler(void)
{
  while (1);
}

void
empty_handler(void)
{
}

void
nmi_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
hard_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
mem_manager_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
bus_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
usage_fault_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
sv_call_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
debug_monitor_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
pend_sv_handler(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
systick_handler(void) NEX_WEAK_NEX_ALIAS("empty_handler");

// ISR

void 
wwdg_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
pvd_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tamp_stamp_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
rtc_wakeup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
flash_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
rcc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
exti0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
exti1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
exti2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
exti3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
exti4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
adc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
can1_tx_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
can1_rx0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
can1_rx1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void 
can1_sce_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
exti9_5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim1_break_tim9_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim1_update_tim10_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim1_trigger_tim11_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim1_cc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
i2c1_event_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
i2c1_error_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
i2c2_event_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
i2c2_error_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
spi1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
spi2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
usart1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
usart2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
usart3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
exti15_10_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
rtc_alarm_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
otg_fs_wakeup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim8_break_tim12_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim8_update_tim13_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim8_trigger_tim14_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim8_cc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma1_stream7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
fsmc_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
sdio_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
spi3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
uart4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
uart5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim6_dac_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
tim7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream2_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream3_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
eth_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
eth_wakeup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
can2_tx_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
can2_rx0_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
can2_rx1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
can2_sce_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
otg_fs_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2_stream7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
usart6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
i2c3_event_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
i2c3_error_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
otg_hs_ep1_output_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
otg_hs_ep1_input_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
otg_hs_wakeup_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
otg_hs_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dcmi_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
crypto_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
hash_rng_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
fpu_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
uart7_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
uart8_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
spi4_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
spi5_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
spi6_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
sai1_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
lcd_tft_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
lcd_tft_error_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");

void
dma2d_isr(void) NEX_WEAK_NEX_ALIAS("blocking_handler");
