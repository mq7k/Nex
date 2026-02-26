#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/rcc/rcc_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  RCC = (struct rcc_registers_map*) membuf;
}

void
test_rcc_osc(void)
{
#if defined(STM32_RCC_OSC_PLL2)
  RCC->CR = 0;
  rcc_osc_enable(RCC_OSC_PLL2);
  ASSERT_EQ(RCC->CR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 26);
  rcc_osc_enable(RCC_OSC_PLL2);
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 26);
  rcc_osc_disable(RCC_OSC_PLL2);
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_PLL2);
  ASSERT_EQ(RCC->CR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI14)
  RCC->CR2 = 0;
  rcc_osc_enable(RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = ~(1u << 0);
  rcc_osc_enable(RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = (1u << 0);
  rcc_osc_disable(RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffffffff;
  rcc_osc_disable(RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC->CR = 0;
  rcc_osc_enable(RCC_OSC_PLL3);
  ASSERT_EQ(RCC->CR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 28);
  rcc_osc_enable(RCC_OSC_PLL3);
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 28);
  rcc_osc_disable(RCC_OSC_PLL3);
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_PLL3);
  ASSERT_EQ(RCC->CR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC->CR2 = 0;
  rcc_osc_enable(RCC_OSC_HSI48);
  ASSERT_EQ(RCC->CR2, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = ~(1u << 16);
  rcc_osc_enable(RCC_OSC_HSI48);
  ASSERT_EQ(RCC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = (1u << 16);
  rcc_osc_disable(RCC_OSC_HSI48);
  ASSERT_EQ(RCC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffffffff;
  rcc_osc_disable(RCC_OSC_HSI48);
  ASSERT_EQ(RCC->CR2, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CR = 0;
  rcc_osc_enable(RCC_OSC_PLL);
  ASSERT_EQ(RCC->CR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 24);
  rcc_osc_enable(RCC_OSC_PLL);
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 24);
  rcc_osc_disable(RCC_OSC_PLL);
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_PLL);
  ASSERT_EQ(RCC->CR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());


  RCC->CR = 0;
  rcc_osc_enable(RCC_OSC_HSE);
  ASSERT_EQ(RCC->CR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 16);
  rcc_osc_enable(RCC_OSC_HSE);
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 16);
  rcc_osc_disable(RCC_OSC_HSE);
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_HSE);
  ASSERT_EQ(RCC->CR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());


  RCC->CR = 0;
  rcc_osc_enable(RCC_OSC_HSI);
  ASSERT_EQ(RCC->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 0);
  rcc_osc_enable(RCC_OSC_HSI);
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 0);
  rcc_osc_disable(RCC_OSC_HSI);
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_HSI);
  ASSERT_EQ(RCC->CR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  rcc_osc_enable(RCC_OSC_LSI);
  ASSERT_EQ(RCC->CSR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 0);
  rcc_osc_enable(RCC_OSC_LSI);
  ASSERT_EQ(RCC->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 0);
  rcc_osc_disable(RCC_OSC_LSI);
  ASSERT_EQ(RCC->CSR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_LSI);
  ASSERT_EQ(RCC->CSR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->BDCR = 0;
  rcc_osc_enable(RCC_OSC_LSE);
  ASSERT_EQ(RCC->BDCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(1u << 0);
  rcc_osc_enable(RCC_OSC_LSE);
  ASSERT_EQ(RCC->BDCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = (1u << 0);
  rcc_osc_disable(RCC_OSC_LSE);
  ASSERT_EQ(RCC->BDCR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_LSE);
  ASSERT_EQ(RCC->BDCR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_osc_is_ready(void)
{
  u32 res;

#if defined(STM32_RCC_OSC_PLL2)
  RCC->CR = 0;
  res = rcc_osc_is_ready(RCC_OSC_PLL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 27);
  res = rcc_osc_is_ready(RCC_OSC_PLL2);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 27);
  res = rcc_osc_is_ready(RCC_OSC_PLL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_PLL2);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI14)
  RCC->CR2 = 0;
  res = rcc_osc_is_ready(RCC_OSC_HSI14);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = (1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_HSI14);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = ~(1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_HSI14);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_HSI14);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC->CR = 0;
  res = rcc_osc_is_ready(RCC_OSC_PLL3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 29);
  res = rcc_osc_is_ready(RCC_OSC_PLL3);
  ASSERT_EQ(res, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 29);
  res = rcc_osc_is_ready(RCC_OSC_PLL3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_PLL3);
  ASSERT_EQ(res, (1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC->CR2 = 0;
  res = rcc_osc_is_ready(RCC_OSC_HSI48);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = (1u << 17);
  res = rcc_osc_is_ready(RCC_OSC_HSI48);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = ~(1u << 17);
  res = rcc_osc_is_ready(RCC_OSC_HSI48);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_HSI48);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CR = 0;
  res = rcc_osc_is_ready(RCC_OSC_PLL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 25);
  res = rcc_osc_is_ready(RCC_OSC_PLL);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 25);
  res = rcc_osc_is_ready(RCC_OSC_PLL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_PLL);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());


  RCC->CR = 0;
  res = rcc_osc_is_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 17);
  res = rcc_osc_is_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 17);
  res = rcc_osc_is_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());


  RCC->CR = 0;
  res = rcc_osc_is_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  res = rcc_osc_is_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RCC->BDCR = 0;
  res = rcc_osc_is_ready(RCC_OSC_LSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = (1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_LSE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(1u << 1);
  res = rcc_osc_is_ready(RCC_OSC_LSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = 0xffffffff;
  res = rcc_osc_is_ready(RCC_OSC_LSE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_set_hsi_trim(void)
{
  RCC->CR = 0;
  rcc_set_hsi_trim(0);
  ASSERT_EQ(RCC->CR, 0u << 3);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_set_hsi_trim(0);
  ASSERT_EQ(RCC->CR, ~(0x1fu << 3) | (0u << 3));
  ASSERT_FALSE(execution_halted());


  RCC->CR = 0;
  rcc_set_hsi_trim(0x1f);
  ASSERT_EQ(RCC->CR, 0x1fu << 3);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_set_hsi_trim(0x1f);
  ASSERT_EQ(RCC->CR, ~(0x1fu << 3) | (0x1fu << 3));
  ASSERT_FALSE(execution_halted());


  RCC->CR = 0;
  rcc_set_hsi_trim(0x20);
  ASSERT_EQ(RCC->CR, 0x20u << 3);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->CR = 0xffffffff;
  rcc_set_hsi_trim(0x20);
  ASSERT_EQ(RCC->CR, ~(0x1fu << 3) | (0x20u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rcc_get_hsi_cal(void)
{
  u32 res;

  // read_bits
  RCC->CR = 0;
  res = rcc_get_hsi_cal();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(0xffu << 8);
  res = rcc_get_hsi_cal();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffu << 8;
  res = rcc_get_hsi_cal();
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_hse_bypass(void)
{
  RCC->CR = 0;
  rcc_hse_bypass_enable();
  ASSERT_EQ(RCC->CR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 18);
  rcc_hse_bypass_enable();
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 18);
  rcc_hse_bypass_disable();
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_hse_bypass_disable();
  ASSERT_EQ(RCC->CR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_hse_bypass_is_enabled(void)
{
  u32 res;

  // read_bit
  RCC->CR = 0;
  res = rcc_hse_bypass_is_enabled();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(0x1u << 18);
  res = rcc_hse_bypass_is_enabled();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0x1u << 18;
  res = rcc_hse_bypass_is_enabled();
  ASSERT_EQ(res, 0x1u << 18);
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_clock_security_system(void)
{
  RCC->CR = 0;
  rcc_clock_security_system_enable();
  ASSERT_EQ(RCC->CR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 19);
  rcc_clock_security_system_enable();
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 19);
  rcc_clock_security_system_disable();
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_clock_security_system_disable();
  ASSERT_EQ(RCC->CR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_clock_security_system_is_enabled(void)
{
  u32 res;

  // read_bit
  RCC->CR = 0;
  res = rcc_clock_security_system_is_enabled();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(0x1u << 19);
  res = rcc_clock_security_system_is_enabled();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0x1u << 19;
  res = rcc_clock_security_system_is_enabled();
  ASSERT_EQ(res, 0x1u << 19);
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_set_sysclock_source(void)
{
  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'clock': 'RCC_SYSCLOCK_HSI'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_sysclock_source(RCC_SYSCLOCK_HSI);
  ASSERT_EQ(RCC->CFGR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_sysclock_source(RCC_SYSCLOCK_HSI);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'clock': 'RCC_SYSCLOCK_HSE'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_sysclock_source(RCC_SYSCLOCK_HSE);
  ASSERT_EQ(RCC->CFGR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_sysclock_source(RCC_SYSCLOCK_HSE);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'clock': 'RCC_SYSCLOCK_PLL'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_sysclock_source(RCC_SYSCLOCK_PLL);
  ASSERT_EQ(RCC->CFGR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_sysclock_source(RCC_SYSCLOCK_PLL);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_HSI48)
  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'clock': 'RCC_SYSCLOCK_HSI48'}, self.value='0b11', self.ifdef=['STM32_RCC_OSC_HSI48'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_sysclock_source(RCC_SYSCLOCK_HSI48);
  ASSERT_EQ(RCC->CFGR, (0b11u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_sysclock_source(RCC_SYSCLOCK_HSI48);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b11u << 0));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rcc_get_sysclock_status_raw(void)
{
  u32 res;

  // read_bits
  RCC->CFGR = 0;
  res = rcc_get_sysclock_status_raw();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 2);
  res = rcc_get_sysclock_status_raw();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0x3u << 2;
  res = rcc_get_sysclock_status_raw();
  ASSERT_EQ(res, 0x3);
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_set_ahb_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_1'}, self.value='0b0000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_2'}, self.value='0b1000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_4'}, self.value='0b1001', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_8'}, self.value='0b1010', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_16'}, self.value='0b1011', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR, (0b1011u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_64'}, self.value='0b1100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_64);
  ASSERT_EQ(RCC->CFGR, (0b1100u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_64);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_128'}, self.value='0b1101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_128);
  ASSERT_EQ(RCC->CFGR, (0b1101u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_128);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_256'}, self.value='0b1110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_256);
  ASSERT_EQ(RCC->CFGR, (0b1110u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_256);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_512'}, self.value='0b1111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_512);
  ASSERT_EQ(RCC->CFGR, (0b1111u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_512);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1111u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_set_apb1_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_1'}, self.value='0b000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR, (0b000u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_2'}, self.value='0b100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, (0b100u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_4'}, self.value='0b101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, (0b101u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_8'}, self.value='0b110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, (0b110u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b110u << 8));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_RCC_PPRE2)
void
test_rcc_set_apb2_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_1'}, self.value='0b000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR, (0b000u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_2'}, self.value='0b100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, (0b100u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_4'}, self.value='0b101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, (0b101u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_8'}, self.value='0b110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, (0b110u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=8, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_16'}, self.value='0b111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR, (0b111u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 8);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 8) | (0b111u << 8));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_ADCPRE)
void
test_rcc_set_adc_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=14, self.mask='0x3', self.varsmap={'prescaler': 'RCC_ADC_PRESCALER_2'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, (0b00u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 14);
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 14) | (0b00u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=14, self.mask='0x3', self.varsmap={'prescaler': 'RCC_ADC_PRESCALER_4'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, (0b01u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 14);
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 14) | (0b01u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=14, self.mask='0x3', self.varsmap={'prescaler': 'RCC_ADC_PRESCALER_6'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_6);
  ASSERT_EQ(RCC->CFGR, (0b10u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 14);
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_6);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 14) | (0b10u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=14, self.mask='0x3', self.varsmap={'prescaler': 'RCC_ADC_PRESCALER_8'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, (0b11u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 14);
  rcc_set_adc_prescaler(RCC_ADC_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 14) | (0b11u << 14));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_PLLSRC_2BIT)
void
test_rcc_set_pll_source(void)
{
  // scope=self.reg='CFGR', self.shift=15, self.mask='0x3', self.varsmap={'source': 'RCC_PLL_SOURCE_HSI_DIV2'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b00u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 15);
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 15) | (0b00u << 15));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=15, self.mask='0x3', self.varsmap={'source': 'RCC_PLL_SOURCE_HSI_PREDIV'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI_PREDIV);
  ASSERT_EQ(RCC->CFGR, (0b01u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 15);
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI_PREDIV);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 15) | (0b01u << 15));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=15, self.mask='0x3', self.varsmap={'source': 'RCC_PLL_SOURCE_HSE_PREDIV'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_source(RCC_PLL_SOURCE_HSE_PREDIV);
  ASSERT_EQ(RCC->CFGR, (0b10u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 15);
  rcc_set_pll_source(RCC_PLL_SOURCE_HSE_PREDIV);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 15) | (0b10u << 15));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=15, self.mask='0x3', self.varsmap={'source': 'RCC_PLL_SOURCE_HSI48'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI48);
  ASSERT_EQ(RCC->CFGR, (0b11u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 15);
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI48);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 15) | (0b11u << 15));
  ASSERT_FALSE(execution_halted());


}
#endif

#if !defined(STM32_RCC_PLLSRC_2BIT)
void
test_rcc_set_pll_source(void)
{
  RCC->CFGR = 0;
  rcc_set_pll_source(RCC_PLL_SOURCE_HSE);
  ASSERT_EQ(RCC->CFGR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(1u << 16);
  rcc_set_pll_source(RCC_PLL_SOURCE_HSE);
  ASSERT_EQ(RCC->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = (1u << 16);
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_set_pll_source(RCC_PLL_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR, 0xffffffff & ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_rcc_set_pll_hse_prescaler(void)
{
  RCC->CFGR = 0;
  rcc_set_pll_hse_prescaler(RCC_PLL_HSE_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(1u << 17);
  rcc_set_pll_hse_prescaler(RCC_PLL_HSE_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = (1u << 17);
  rcc_set_pll_hse_prescaler(RCC_PLL_HSE_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_set_pll_hse_prescaler(RCC_PLL_HSE_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, 0xffffffff & ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_set_pll_multiplication_factor(void)
{
#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_2'}, self.value='0b0000', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_2);
  ASSERT_EQ(RCC->CFGR, (0b0000u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_2);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0000u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_3'}, self.value='0b0001', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_3);
  ASSERT_EQ(RCC->CFGR, (0b0001u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_3);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0001u << 18));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_4'}, self.value='0b0010', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_4);
  ASSERT_EQ(RCC->CFGR, (0b0010u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_4);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0010u << 18));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_5'}, self.value='0b0011', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_5);
  ASSERT_EQ(RCC->CFGR, (0b0011u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_5);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0011u << 18));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_6'}, self.value='0b0100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_6);
  ASSERT_EQ(RCC->CFGR, (0b0100u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_6);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0100u << 18));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_PLLMUL_LAYOUT1)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_6dot5'}, self.value='0b1101', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT1'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_6dot5);
  ASSERT_EQ(RCC->CFGR, (0b1101u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_6dot5);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1101u << 18));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_7'}, self.value='0b0101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_7);
  ASSERT_EQ(RCC->CFGR, (0b0101u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_7);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0101u << 18));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_8'}, self.value='0b0110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_8);
  ASSERT_EQ(RCC->CFGR, (0b0110u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_8);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0110u << 18));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_9'}, self.value='0b0111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_9);
  ASSERT_EQ(RCC->CFGR, (0b0111u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_9);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b0111u << 18));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_10'}, self.value='0b1000', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_10);
  ASSERT_EQ(RCC->CFGR, (0b1000u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_10);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1000u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_11'}, self.value='0b1001', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_11);
  ASSERT_EQ(RCC->CFGR, (0b1001u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_11);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1001u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_12'}, self.value='0b1010', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_12);
  ASSERT_EQ(RCC->CFGR, (0b1010u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_12);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1010u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_13'}, self.value='0b1011', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_13);
  ASSERT_EQ(RCC->CFGR, (0b1011u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_13);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1011u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_14'}, self.value='0b1100', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_14);
  ASSERT_EQ(RCC->CFGR, (0b1100u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_14);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1100u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_15'}, self.value='0b1101', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_15);
  ASSERT_EQ(RCC->CFGR, (0b1101u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_15);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1101u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLMUL_LAYOUT2)
  // scope=self.reg='CFGR', self.shift=18, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL_MULTIPLICATION_FACTOR_16'}, self.value='0b1110', self.ifdef=['STM32_RCC_PLLMUL_LAYOUT2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_16);
  ASSERT_EQ(RCC->CFGR, (0b1110u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 18);
  rcc_set_pll_multiplication_factor(RCC_PLL_MULTIPLICATION_FACTOR_16);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 18) | (0b1110u << 18));
  ASSERT_FALSE(execution_halted());

#endif

}

#if defined(STM32_RCC_OTGFS)
void
test_rcc_set_usb_otg_fs_prescaler(void)
{
  RCC->CFGR = 0;
  rcc_set_usb_otg_fs_prescaler(RCC_USB_OTG_FS_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(1u << 22);
  rcc_set_usb_otg_fs_prescaler(RCC_USB_OTG_FS_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = (1u << 22);
  rcc_set_usb_otg_fs_prescaler(RCC_USB_OTG_FS_PRESCALER_3);
  ASSERT_EQ(RCC->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_set_usb_otg_fs_prescaler(RCC_USB_OTG_FS_PRESCALER_3);
  ASSERT_EQ(RCC->CFGR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_CFGR_MCO_3BIT)
void
test_rcc_set_microcontroller_clock_output(void)
{
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_NO_OUTPUT'}, self.value='0b0000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_NO_OUTPUT);
  ASSERT_EQ(RCC->CFGR, (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_NO_OUTPUT);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0000u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_HSI14)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_HSI14'}, self.value='0b0001', self.ifdef=['STM32_RCC_OSC_HSI14'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI14);
  ASSERT_EQ(RCC->CFGR, (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI14);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI12)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_LSI'}, self.value='0b0010', self.ifdef=['STM32_RCC_OSC_HSI12'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_LSI);
  ASSERT_EQ(RCC->CFGR, (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_LSI);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI14)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_LSE'}, self.value='0b0011', self.ifdef=['STM32_RCC_OSC_HSI14'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_LSE);
  ASSERT_EQ(RCC->CFGR, (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_LSE);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_SYSCLOCK'}, self.value='0b0100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR, (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0100u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_HSI'}, self.value='0b0101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI);
  ASSERT_EQ(RCC->CFGR, (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0101u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_HSE'}, self.value='0b0110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSE);
  ASSERT_EQ(RCC->CFGR, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSE);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_PLL'}, self.value='0b0111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL);
  ASSERT_EQ(RCC->CFGR, (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0111u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_PLL2)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_PLL2'}, self.value='0b1000', self.ifdef=['STM32_RCC_OSC_PLL2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL2);
  ASSERT_EQ(RCC->CFGR, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_PLL3_DIV2'}, self.value='0b1001', self.ifdef=['STM32_RCC_OSC_PLL3'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_MCO_XT1)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_XT1'}, self.value='0b1010', self.ifdef=['STM32_MCO_XT1'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_XT1);
  ASSERT_EQ(RCC->CFGR, (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_XT1);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_PLL3'}, self.value='0b0110', self.ifdef=['STM32_RCC_OSC_PLL3'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3);
  ASSERT_EQ(RCC->CFGR, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI48)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'output': 'RCC_MCO_HSI48'}, self.value='0b1000', self.ifdef=['STM32_RCC_OSC_HSI48'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI48);
  ASSERT_EQ(RCC->CFGR, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI48);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_RCC_CFGR_MCO_4BIT)
void
test_rcc_set_microcontroller_clock_output(void)
{
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_NO_OUTPUT'}, self.value='0b0000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_NO_OUTPUT);
  ASSERT_EQ(RCC->CFGR, (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_NO_OUTPUT);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0000u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_HSI14)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_HSI14'}, self.value='0b0001', self.ifdef=['STM32_RCC_OSC_HSI14'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI14);
  ASSERT_EQ(RCC->CFGR, (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI14);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI12)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_LSI'}, self.value='0b0010', self.ifdef=['STM32_RCC_OSC_HSI12'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_LSI);
  ASSERT_EQ(RCC->CFGR, (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_LSI);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI14)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_LSE'}, self.value='0b0011', self.ifdef=['STM32_RCC_OSC_HSI14'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_LSE);
  ASSERT_EQ(RCC->CFGR, (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_LSE);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_SYSCLOCK'}, self.value='0b0100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR, (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0100u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_HSI'}, self.value='0b0101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI);
  ASSERT_EQ(RCC->CFGR, (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0101u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_HSE'}, self.value='0b0110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSE);
  ASSERT_EQ(RCC->CFGR, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSE);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_PLL'}, self.value='0b0111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL);
  ASSERT_EQ(RCC->CFGR, (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0111u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_PLL2)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_PLL2'}, self.value='0b1000', self.ifdef=['STM32_RCC_OSC_PLL2'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL2);
  ASSERT_EQ(RCC->CFGR, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL2);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_PLL3_DIV2'}, self.value='0b1001', self.ifdef=['STM32_RCC_OSC_PLL3'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_XT1'}, self.value='0b1010', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_XT1);
  ASSERT_EQ(RCC->CFGR, (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_XT1);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b1010u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_PLL3)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_PLL3'}, self.value='0b0110', self.ifdef=['STM32_RCC_OSC_PLL3'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3);
  ASSERT_EQ(RCC->CFGR, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_PLL3);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI48)
  // scope=self.reg='CFGR', self.shift=24, self.mask='0xf', self.varsmap={'output': 'RCC_MCO_HSI48'}, self.value='0b1000', self.ifdef=['STM32_RCC_OSC_HSI48'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI48);
  ASSERT_EQ(RCC->CFGR, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 24);
  rcc_set_microcontroller_clock_output(RCC_MCO_HSI48);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_RCC_MCOPRE)
void
test_rcc_set_mco_prescaler(void)
{
  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV1'}, self.value='0b000', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV1);
  ASSERT_EQ(RCC->CIR, (0b000u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV1);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b000u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV2'}, self.value='0b001', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CIR, (0b001u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b001u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV4'}, self.value='0b010', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CIR, (0b010u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b010u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV8'}, self.value='0b011', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CIR, (0b011u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b011u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV16'}, self.value='0b100', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CIR, (0b100u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b100u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV32'}, self.value='0b101', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV32);
  ASSERT_EQ(RCC->CIR, (0b101u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV32);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b101u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV64'}, self.value='0b110', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV64);
  ASSERT_EQ(RCC->CIR, (0b110u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV64);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b110u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CIR', self.shift=28, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV128'}, self.value='0b111', self.ifdef=[], self.halt=False
  RCC->CIR = 0;
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV128);
  ASSERT_EQ(RCC->CIR, (0b111u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(0x7u << 28);
  rcc_set_mco_prescaler(RCC_MCO_PRESCALER_DIV128);
  ASSERT_EQ(RCC->CIR, ~(0x7u << 28) | (0b111u << 28));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_PLLNODIV)
void
test_rcc_set_mco_pll_prescaler(void)
{
  RCC->CFGR = 0;
  rcc_set_mco_pll_prescaler(MCO_PLL_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(1u << 31);
  rcc_set_mco_pll_prescaler(MCO_PLL_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = (1u << 31);
  rcc_set_mco_pll_prescaler(MCO_PLL_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_set_mco_pll_prescaler(MCO_PLL_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, 0xffffffff & ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_rcc_is_interrupt_flag_set(void)
{
  u32 res;

  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 0);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSI);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 0);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSI);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 1);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 1);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_LSE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 2);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 2);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 3);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSE);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 3);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSE);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 4);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 4);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_PLL2)
  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 5);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 5);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI14)
  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI14);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 5);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI14);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 5);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI14);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI14);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 6);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 6);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 6);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 6);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CIR = 0;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_CSS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 7);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_CSS);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 7);
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_CSS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_interrupt_flag_set(RCC_INTERRUPT_CSS);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_interrupt(void)
{
  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_LSI);
  ASSERT_EQ(RCC->CIR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 8);
  rcc_interrupt_enable(RCC_INTERRUPT_LSI);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 8);
  rcc_interrupt_disable(RCC_INTERRUPT_LSI);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_LSI);
  ASSERT_EQ(RCC->CIR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_LSE);
  ASSERT_EQ(RCC->CIR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 9);
  rcc_interrupt_enable(RCC_INTERRUPT_LSE);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 9);
  rcc_interrupt_disable(RCC_INTERRUPT_LSE);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_LSE);
  ASSERT_EQ(RCC->CIR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_HSI);
  ASSERT_EQ(RCC->CIR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 10);
  rcc_interrupt_enable(RCC_INTERRUPT_HSI);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 10);
  rcc_interrupt_disable(RCC_INTERRUPT_HSI);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_HSI);
  ASSERT_EQ(RCC->CIR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_HSE);
  ASSERT_EQ(RCC->CIR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 11);
  rcc_interrupt_enable(RCC_INTERRUPT_HSE);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 11);
  rcc_interrupt_disable(RCC_INTERRUPT_HSE);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_HSE);
  ASSERT_EQ(RCC->CIR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_PLL);
  ASSERT_EQ(RCC->CIR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 12);
  rcc_interrupt_enable(RCC_INTERRUPT_PLL);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 12);
  rcc_interrupt_disable(RCC_INTERRUPT_PLL);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_PLL);
  ASSERT_EQ(RCC->CIR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_PLL2)
  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(RCC->CIR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 13);
  rcc_interrupt_enable(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 13);
  rcc_interrupt_disable(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(RCC->CIR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(RCC_INTERRUPT_HSI14)
  RCC->CIR = 0;
  rcc_interrupt_enable(STM32_RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CIR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 13);
  rcc_interrupt_enable(STM32_RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 13);
  rcc_interrupt_disable(STM32_RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(STM32_RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CIR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(RCC->CIR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 14);
  rcc_interrupt_enable(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 14);
  rcc_interrupt_disable(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(RCC->CIR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(RCC->CIR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 14);
  rcc_interrupt_enable(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 14);
  rcc_interrupt_disable(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(RCC->CIR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_CSS);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->CIR = ~(1u << 15);
  rcc_interrupt_enable(RCC_INTERRUPT_CSS);
  ASSERT_EQ(RCC->CIR, ~(1u << 15));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->CIR = (1u << 15);
  rcc_interrupt_disable(RCC_INTERRUPT_CSS);
  ASSERT_EQ(RCC->CIR, (1u << 15));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_CSS);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rcc_interrupt_flag_clear(void)
{
  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_LSI);
  ASSERT_EQ(RCC->CIR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 16);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_LSI);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_LSE);
  ASSERT_EQ(RCC->CIR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 17);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_LSE);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_HSI);
  ASSERT_EQ(RCC->CIR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 18);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_HSI);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_HSE);
  ASSERT_EQ(RCC->CIR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 19);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_HSE);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_PLL);
  ASSERT_EQ(RCC->CIR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 20);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_PLL);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_PLL2)
  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(RCC->CIR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 21);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_PLL2);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(RCC_INTERRUPT_HSI14)
  RCC->CIR = 0;
  rcc_interrupt_flag_clear(STM32_RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CIR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 21);
  rcc_interrupt_flag_clear(STM32_RCC_OSC_HSI14);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLL3)
  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(RCC->CIR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 22);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_PLL3);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_HSI48)
  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(RCC->CIR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 22);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_HSI48);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CIR = 0;
  rcc_interrupt_flag_clear(RCC_INTERRUPT_CSS);
  ASSERT_EQ(RCC->CIR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 23);
  rcc_interrupt_flag_clear(RCC_INTERRUPT_CSS);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_periph_reset(void)
{
#if defined(STM32_RCC_SYSCFG)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 0);
  rcc_periph_reset(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AFIO)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_AFIO);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 0);
  rcc_periph_reset(RCC_PERIPH_AFIO);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART6)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 5);
  rcc_periph_reset(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART7)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART7);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 6);
  rcc_periph_reset(RCC_PERIPH_USART7);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART8)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART8);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 7);
  rcc_periph_reset(RCC_PERIPH_USART8);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 9);
  rcc_periph_reset(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC2)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 10);
  rcc_periph_reset(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 11);
  rcc_periph_reset(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 12);
  rcc_periph_reset(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 14);
  rcc_periph_reset(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM15)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM15);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 16);
  rcc_periph_reset(RCC_PERIPH_TIM15);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM16)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM16);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 17);
  rcc_periph_reset(RCC_PERIPH_TIM16);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM17)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM17);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 18);
  rcc_periph_reset(RCC_PERIPH_TIM17);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DBGMCU)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DBGMCU);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 22);
  rcc_periph_reset(RCC_PERIPH_DBGMCU);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
#if !defined(STM32_GPIO_RST_AHB)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 2);
  rcc_periph_reset(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOB)
#if !defined(STM32_GPIO_RST_AHB)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 3);
  rcc_periph_reset(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOC)
#if !defined(STM32_GPIO_RST_AHB)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 4);
  rcc_periph_reset(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOD)
#if !defined(STM32_GPIO_RST_AHB)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 5);
  rcc_periph_reset(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOE)
#if !defined(STM32_GPIO_RST_AHB)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 6);
  rcc_periph_reset(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOF)
#if !defined(STM32_GPIO_RST_AHB)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 7);
  rcc_periph_reset(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOG)
#if !defined(STM32_GPIO_RST_AHB)
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(1u << 8);
  rcc_periph_reset(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->APB2RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_TIM2)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 0);
  rcc_periph_reset(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 1);
  rcc_periph_reset(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 2);
  rcc_periph_reset(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM5)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 3);
  rcc_periph_reset(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM6)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 4);
  rcc_periph_reset(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM7)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 5);
  rcc_periph_reset(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM12)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 6);
  rcc_periph_reset(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM13)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 7);
  rcc_periph_reset(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM14)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 8);
  rcc_periph_reset(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 11);
  rcc_periph_reset(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SPI2)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 14);
  rcc_periph_reset(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI3)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 15);
  rcc_periph_reset(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART2)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 17);
  rcc_periph_reset(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART3)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 18);
  rcc_periph_reset(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART4)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 19);
  rcc_periph_reset(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART5)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 20);
  rcc_periph_reset(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_I2C1)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 21);
  rcc_periph_reset(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_I2C2)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 22);
  rcc_periph_reset(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USB);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 23);
  rcc_periph_reset(RCC_PERIPH_USB);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN1)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 25);
  rcc_periph_reset(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN2)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 26);
  rcc_periph_reset(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_BKP)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_BKP);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 27);
  rcc_periph_reset(RCC_PERIPH_BKP);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 28);
  rcc_periph_reset(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 29);
  rcc_periph_reset(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CEC)
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(1u << 30);
  rcc_periph_reset(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1RSTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rcc_periph_clock(void)
{
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHBENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DMA2)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHBENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 1);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 1);
  rcc_periph_clock_disable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SRAM);
  ASSERT_EQ(RCC->AHBENR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 2);
  rcc_periph_clock_enable(RCC_PERIPH_SRAM);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 2);
  rcc_periph_clock_disable(RCC_PERIPH_SRAM);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SRAM);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_FLITF);
  ASSERT_EQ(RCC->AHBENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 4);
  rcc_periph_clock_enable(RCC_PERIPH_FLITF);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 4);
  rcc_periph_clock_disable(RCC_PERIPH_FLITF);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_FLITF);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHBENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 6);
  rcc_periph_clock_enable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 6);
  rcc_periph_clock_disable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OTGFS)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_OTGFS);
  ASSERT_EQ(RCC->AHBENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 8);
  rcc_periph_clock_enable(RCC_PERIPH_OTGFS);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 8);
  rcc_periph_clock_disable(RCC_PERIPH_OTGFS);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_OTGFS);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FSMC)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHBENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 8);
  rcc_periph_clock_enable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 8);
  rcc_periph_clock_disable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SDIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->AHBENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 10);
  rcc_periph_clock_enable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 10);
  rcc_periph_clock_disable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETH)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHBENR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 14);
  rcc_periph_clock_enable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 14);
  rcc_periph_clock_disable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETH)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHBENR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 15);
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 15);
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETH)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHBENR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 16);
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 16);
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
#if !defined(STM32_APB2_GPIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHBENR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 17);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 17);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOB)
#if !defined(STM32_APB2_GPIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHBENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 18);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 18);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOC)
#if !defined(STM32_APB2_GPIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHBENR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 19);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 19);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOD)
#if !defined(STM32_APB2_GPIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHBENR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 20);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 20);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOE)
#if !defined(STM32_APB2_GPIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHBENR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 21);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 21);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOF)
#if !defined(STM32_APB2_GPIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHBENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 22);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 22);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_GPIOG)
#if !defined(STM32_APB2_GPIO)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHBENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 23);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 23);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif
#endif

#if defined(STM32_TSC)
  RCC->AHBENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TSC);
  ASSERT_EQ(RCC->AHBENR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = ~(1u << 24);
  rcc_periph_clock_enable(RCC_PERIPH_TSC);
  ASSERT_EQ(RCC->AHBENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = (1u << 24);
  rcc_periph_clock_disable(RCC_PERIPH_TSC);
  ASSERT_EQ(RCC->AHBENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHBENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TSC);
  ASSERT_EQ(RCC->AHBENR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_SYSCFG)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_AFIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
  ASSERT_EQ(RCC->APB2ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_AFIO);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_AFIO);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA) && defined(STM32_APB2_GPIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->APB2ENR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 2);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 2);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB) && defined(STM32_APB2_GPIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->APB2ENR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 3);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 3);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC) && defined(STM32_APB2_GPIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->APB2ENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 4);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 4);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD) && defined(STM32_APB2_GPIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->APB2ENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 5);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 5);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE) && defined(STM32_APB2_GPIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->APB2ENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 6);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 6);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF) && defined(STM32_APB2_GPIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->APB2ENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 7);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 7);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG) && defined(STM32_APB2_GPIO)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->APB2ENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 8);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 8);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART7)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USART7);
  ASSERT_EQ(RCC->APB2ENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 6);
  rcc_periph_clock_enable(RCC_PERIPH_USART7);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 6);
  rcc_periph_clock_disable(RCC_PERIPH_USART7);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USART7);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART8)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USART8);
  ASSERT_EQ(RCC->APB2ENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 7);
  rcc_periph_clock_enable(RCC_PERIPH_USART8);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 7);
  rcc_periph_clock_disable(RCC_PERIPH_USART8);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USART8);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 9);
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 9);
  rcc_periph_clock_disable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC2)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 10);
  rcc_periph_clock_enable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 10);
  rcc_periph_clock_disable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 11);
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 11);
  rcc_periph_clock_disable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 12);
  rcc_periph_clock_enable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 12);
  rcc_periph_clock_disable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 14);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 14);
  rcc_periph_clock_disable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM15)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM15);
  ASSERT_EQ(RCC->APB2ENR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 16);
  rcc_periph_clock_enable(RCC_PERIPH_TIM15);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 16);
  rcc_periph_clock_disable(RCC_PERIPH_TIM15);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM15);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM16)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM16);
  ASSERT_EQ(RCC->APB2ENR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 17);
  rcc_periph_clock_enable(RCC_PERIPH_TIM16);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 17);
  rcc_periph_clock_disable(RCC_PERIPH_TIM16);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM16);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM17)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM17);
  ASSERT_EQ(RCC->APB2ENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 18);
  rcc_periph_clock_enable(RCC_PERIPH_TIM17);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 18);
  rcc_periph_clock_disable(RCC_PERIPH_TIM17);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM17);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DBGMCU)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DBGMCU);
  ASSERT_EQ(RCC->APB2ENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 22);
  rcc_periph_clock_enable(RCC_PERIPH_DBGMCU);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 22);
  rcc_periph_clock_disable(RCC_PERIPH_DBGMCU);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DBGMCU);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1ENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 1);
  rcc_periph_clock_enable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 1);
  rcc_periph_clock_disable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1ENR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 2);
  rcc_periph_clock_enable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 2);
  rcc_periph_clock_disable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM5)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1ENR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 3);
  rcc_periph_clock_enable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 3);
  rcc_periph_clock_disable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM6)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1ENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 4);
  rcc_periph_clock_enable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 4);
  rcc_periph_clock_disable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM7)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1ENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 5);
  rcc_periph_clock_enable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 5);
  rcc_periph_clock_disable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM12)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1ENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 6);
  rcc_periph_clock_enable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 6);
  rcc_periph_clock_disable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM13)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1ENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 7);
  rcc_periph_clock_enable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 7);
  rcc_periph_clock_disable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM14)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1ENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 8);
  rcc_periph_clock_enable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 8);
  rcc_periph_clock_disable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1ENR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 11);
  rcc_periph_clock_enable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 11);
  rcc_periph_clock_disable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SPI2)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1ENR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 14);
  rcc_periph_clock_enable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 14);
  rcc_periph_clock_disable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI3)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1ENR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 15);
  rcc_periph_clock_enable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 15);
  rcc_periph_clock_disable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART2)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1ENR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 17);
  rcc_periph_clock_enable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 17);
  rcc_periph_clock_disable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USART3)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1ENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 18);
  rcc_periph_clock_enable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 18);
  rcc_periph_clock_disable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART4)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1ENR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 19);
  rcc_periph_clock_enable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 19);
  rcc_periph_clock_disable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART5)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1ENR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 20);
  rcc_periph_clock_enable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 20);
  rcc_periph_clock_disable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_I2C1)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1ENR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 21);
  rcc_periph_clock_enable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 21);
  rcc_periph_clock_disable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_I2C2)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1ENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 22);
  rcc_periph_clock_enable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 22);
  rcc_periph_clock_disable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USB);
  ASSERT_EQ(RCC->APB1ENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 23);
  rcc_periph_clock_enable(RCC_PERIPH_USB);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 23);
  rcc_periph_clock_disable(RCC_PERIPH_USB);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USB);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN1)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1ENR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 25);
  rcc_periph_clock_enable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 25);
  rcc_periph_clock_disable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN2)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1ENR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 26);
  rcc_periph_clock_enable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 26);
  rcc_periph_clock_disable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_BKP)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_BKP);
  ASSERT_EQ(RCC->APB1ENR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 27);
  rcc_periph_clock_enable(RCC_PERIPH_BKP);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 27);
  rcc_periph_clock_disable(RCC_PERIPH_BKP);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_BKP);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_PWR)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1ENR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 28);
  rcc_periph_clock_enable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 28);
  rcc_periph_clock_disable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1ENR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 29);
  rcc_periph_clock_enable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 29);
  rcc_periph_clock_disable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CEC)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1ENR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 30);
  rcc_periph_clock_enable(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 30);
  rcc_periph_clock_disable(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 30));
  ASSERT_FALSE(execution_halted());

#endif

}

// └─Skipping type 'fn_call (TODO)' (rcc_backup_domain_reset)
void
test_rcc_set_rtc_source(void)
{
  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_SOURCE_NOCLOCK'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_source(RCC_RTC_SOURCE_NOCLOCK);
  ASSERT_EQ(RCC->BDCR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_source(RCC_RTC_SOURCE_NOCLOCK);
  ASSERT_EQ(RCC->BDCR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_SOURCE_LSE'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_source(RCC_RTC_SOURCE_LSE);
  ASSERT_EQ(RCC->BDCR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_source(RCC_RTC_SOURCE_LSE);
  ASSERT_EQ(RCC->BDCR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_SOURCE_LSI'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_source(RCC_RTC_SOURCE_LSI);
  ASSERT_EQ(RCC->BDCR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_source(RCC_RTC_SOURCE_LSI);
  ASSERT_EQ(RCC->BDCR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_SOURCE_HSE'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_source(RCC_RTC_SOURCE_HSE);
  ASSERT_EQ(RCC->BDCR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_source(RCC_RTC_SOURCE_HSE);
  ASSERT_EQ(RCC->BDCR, ~(0x3u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_lse_bypass(void)
{
  RCC->BDCR = 0;
  rcc_lse_bypass_enable();
  ASSERT_EQ(RCC->BDCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(1u << 2);
  rcc_lse_bypass_enable();
  ASSERT_EQ(RCC->BDCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = (1u << 2);
  rcc_lse_bypass_disable();
  ASSERT_EQ(RCC->BDCR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = 0xffffffff;
  rcc_lse_bypass_disable();
  ASSERT_EQ(RCC->BDCR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_lse_bypass_is_enabled(void)
{
  u32 res;

  // read_bit
  RCC->BDCR = 0;
  res = rcc_lse_bypass_is_enabled();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x1u << 2);
  res = rcc_lse_bypass_is_enabled();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = 0x1u << 2;
  res = rcc_lse_bypass_is_enabled();
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_reset_is_flag_set(void)
{
  u32 res;

#if defined(STM32_RCC_V1dot8V)
  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_V1dot8);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 23);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_V1dot8);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 23;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_V1dot8);
  ASSERT_EQ(res, 0x1u << 23);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_OPTION_BYTE_LOADER)
  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_OPTION_BYTE_LOADER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 25);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_OPTION_BYTE_LOADER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 25;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_OPTION_BYTE_LOADER);
  ASSERT_EQ(res, 0x1u << 25);
  ASSERT_FALSE(execution_halted());

#endif

  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_PIN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 26);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_PIN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 26;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_PIN);
  ASSERT_EQ(res, 0x1u << 26);
  ASSERT_FALSE(execution_halted());


  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_POR_PDR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 27);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_POR_PDR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 27;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_POR_PDR);
  ASSERT_EQ(res, 0x1u << 27);
  ASSERT_FALSE(execution_halted());


  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_SOFTWARE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 28);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_SOFTWARE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 28;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_SOFTWARE);
  ASSERT_EQ(res, 0x1u << 28);
  ASSERT_FALSE(execution_halted());


  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_INDEPENDENT_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 29);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_INDEPENDENT_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 29;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_INDEPENDENT_WATCHDOG);
  ASSERT_EQ(res, 0x1u << 29);
  ASSERT_FALSE(execution_halted());


  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_WINDOW_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 30);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_WINDOW_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 30;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_WINDOW_WATCHDOG);
  ASSERT_EQ(res, 0x1u << 30);
  ASSERT_FALSE(execution_halted());


  // read_bit
  RCC->CSR = 0;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_LOW_POWER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(0x1u << 31);
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_LOW_POWER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0x1u << 31;
  res = rcc_reset_is_flag_set(RCC_RESET_FLAG_LOW_POWER);
  ASSERT_EQ(res, 0x1u << 31);
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_reset_flags_clear(void)
{
  RCC->CSR = 0;
  rcc_reset_flags_clear();
  ASSERT_EQ(RCC->CSR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 24);
  rcc_reset_flags_clear();
  ASSERT_EQ(RCC->CSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_RCC_CFGR2)
void
test_rcc_set_prediv1_prescaler(void)
{
  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_1'}, self.value='0b0000', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR2, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR2, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_3'}, self.value='0b0010', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_3);
  ASSERT_EQ(RCC->CFGR2, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_3);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_4'}, self.value='0b0011', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR2, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_5'}, self.value='0b0100', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_5);
  ASSERT_EQ(RCC->CFGR2, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_5);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_6'}, self.value='0b0101', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_6);
  ASSERT_EQ(RCC->CFGR2, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_6);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_7'}, self.value='0b0110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_7);
  ASSERT_EQ(RCC->CFGR2, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_7);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_8'}, self.value='0b0111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR2, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_9'}, self.value='0b1000', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_9);
  ASSERT_EQ(RCC->CFGR2, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_9);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_10'}, self.value='0b1001', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_10);
  ASSERT_EQ(RCC->CFGR2, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_10);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_11'}, self.value='0b1010', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_11);
  ASSERT_EQ(RCC->CFGR2, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_11);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_12'}, self.value='0b1011', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_12);
  ASSERT_EQ(RCC->CFGR2, (0b1011u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_12);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_13'}, self.value='0b1100', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_13);
  ASSERT_EQ(RCC->CFGR2, (0b1100u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_13);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_14'}, self.value='0b1101', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_14);
  ASSERT_EQ(RCC->CFGR2, (0b1101u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_14);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_15'}, self.value='0b1110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_15);
  ASSERT_EQ(RCC->CFGR2, (0b1110u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_15);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=0, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV1_PRESCALER_16'}, self.value='0b1111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR2, (0b1111u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 0);
  rcc_set_prediv1_prescaler(RCC_PREDIV1_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 0) | (0b1111u << 0));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_PREDIV2)
void
test_rcc_set_prediv2_prescaler(void)
{
  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_1'}, self.value='0b0000', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR2, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_1);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR2, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_2);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_3'}, self.value='0b0010', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_3);
  ASSERT_EQ(RCC->CFGR2, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_3);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_4'}, self.value='0b0011', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR2, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_4);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_5'}, self.value='0b0100', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_5);
  ASSERT_EQ(RCC->CFGR2, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_5);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_6'}, self.value='0b0101', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_6);
  ASSERT_EQ(RCC->CFGR2, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_6);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_7'}, self.value='0b0110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_7);
  ASSERT_EQ(RCC->CFGR2, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_7);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_8'}, self.value='0b0111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR2, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_8);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_9'}, self.value='0b1000', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_9);
  ASSERT_EQ(RCC->CFGR2, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_9);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_10'}, self.value='0b1001', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_10);
  ASSERT_EQ(RCC->CFGR2, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_10);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_11'}, self.value='0b1010', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_11);
  ASSERT_EQ(RCC->CFGR2, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_11);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_12'}, self.value='0b1011', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_12);
  ASSERT_EQ(RCC->CFGR2, (0b1011u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_12);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_13'}, self.value='0b1100', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_13);
  ASSERT_EQ(RCC->CFGR2, (0b1100u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_13);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_14'}, self.value='0b1101', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_14);
  ASSERT_EQ(RCC->CFGR2, (0b1101u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_14);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_15'}, self.value='0b1110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_15);
  ASSERT_EQ(RCC->CFGR2, (0b1110u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_15);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_PREDIV2_PRESCALER_16'}, self.value='0b1111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR2, (0b1111u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 4);
  rcc_set_prediv2_prescaler(RCC_PREDIV2_PRESCALER_16);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 4) | (0b1111u << 4));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_CFGR2) && defined(STM32_RCC_OSC_PLL2)
void
test_rcc_set_pll2_multiplication_factor(void)
{
  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_8'}, self.value='0b0110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_8);
  ASSERT_EQ(RCC->CFGR2, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_8);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_9'}, self.value='0b0111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_9);
  ASSERT_EQ(RCC->CFGR2, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_9);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_10'}, self.value='0b1000', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_10);
  ASSERT_EQ(RCC->CFGR2, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_10);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_11'}, self.value='0b1001', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_11);
  ASSERT_EQ(RCC->CFGR2, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_11);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_12'}, self.value='0b1010', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_12);
  ASSERT_EQ(RCC->CFGR2, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_12);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_13'}, self.value='0b1011', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_13);
  ASSERT_EQ(RCC->CFGR2, (0b1011u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_13);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b1011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_14'}, self.value='0b1100', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_14);
  ASSERT_EQ(RCC->CFGR2, (0b1100u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_14);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b1100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_16'}, self.value='0b1110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_16);
  ASSERT_EQ(RCC->CFGR2, (0b1110u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_16);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b1110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=8, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL2_MULTIPLICATION_FACTOR_20'}, self.value='0b1111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_20);
  ASSERT_EQ(RCC->CFGR2, (0b1111u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 8);
  rcc_set_pll2_multiplication_factor(RCC_PLL2_MULTIPLICATION_FACTOR_20);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 8) | (0b1111u << 8));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_CFGR2) && defined(STM32_RCC_OSC_PLL3)
void
test_rcc_set_pll3_multiplication_factor(void)
{
  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_8'}, self.value='0b0110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_8);
  ASSERT_EQ(RCC->CFGR2, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_8);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_9'}, self.value='0b0111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_9);
  ASSERT_EQ(RCC->CFGR2, (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_9);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b0111u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_10'}, self.value='0b1000', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_10);
  ASSERT_EQ(RCC->CFGR2, (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_10);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b1000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_11'}, self.value='0b1001', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_11);
  ASSERT_EQ(RCC->CFGR2, (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_11);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b1001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_12'}, self.value='0b1010', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_12);
  ASSERT_EQ(RCC->CFGR2, (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_12);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b1010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_13'}, self.value='0b1011', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_13);
  ASSERT_EQ(RCC->CFGR2, (0b1011u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_13);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b1011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_14'}, self.value='0b1100', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_14);
  ASSERT_EQ(RCC->CFGR2, (0b1100u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_14);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b1100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_16'}, self.value='0b1110', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_16);
  ASSERT_EQ(RCC->CFGR2, (0b1110u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_16);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b1110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR2', self.shift=12, self.mask='0xf', self.varsmap={'factor': 'RCC_PLL3_MULTIPLICATION_FACTOR_20'}, self.value='0b1111', self.ifdef=[], self.halt=False
  RCC->CFGR2 = 0;
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_20);
  ASSERT_EQ(RCC->CFGR2, (0b1111u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(0xfu << 12);
  rcc_set_pll3_multiplication_factor(RCC_PLL3_MULTIPLICATION_FACTOR_20);
  ASSERT_EQ(RCC->CFGR2, ~(0xfu << 12) | (0b1111u << 12));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_CFGR2) && defined(STM32_RCC_PREDIV1)
void
test_rcc_set_prediv1_source(void)
{
  RCC->CFGR2 = 0;
  rcc_set_prediv1_source(RCC_PREDIV1_SOURCE_PLL2);
  ASSERT_EQ(RCC->CFGR2, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(1u << 16);
  rcc_set_prediv1_source(RCC_PREDIV1_SOURCE_PLL2);
  ASSERT_EQ(RCC->CFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = (1u << 16);
  rcc_set_prediv1_source(RCC_PREDIV1_SOURCE_HSE);
  ASSERT_EQ(RCC->CFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = 0xffffffff;
  rcc_set_prediv1_source(RCC_PREDIV1_SOURCE_HSE);
  ASSERT_EQ(RCC->CFGR2, 0xffffffff & ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_CFGR2) && defined(STM32_I2S2)
void
test_rcc_set_i2s2_source(void)
{
  RCC->CFGR2 = 0;
  rcc_set_i2s2_source(RCC_I2S2_SOURCE_PLL3);
  ASSERT_EQ(RCC->CFGR2, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(1u << 17);
  rcc_set_i2s2_source(RCC_I2S2_SOURCE_PLL3);
  ASSERT_EQ(RCC->CFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = (1u << 17);
  rcc_set_i2s2_source(RCC_I2S2_SOURCE_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = 0xffffffff;
  rcc_set_i2s2_source(RCC_I2S2_SOURCE_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR2, 0xffffffff & ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_CFGR2) && defined(STM32_I2S3)
void
test_rcc_set_i2s3_source(void)
{
  RCC->CFGR2 = 0;
  rcc_set_i2s3_source(RCC_I2S3_SOURCE_PLL3);
  ASSERT_EQ(RCC->CFGR2, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = ~(1u << 18);
  rcc_set_i2s3_source(RCC_I2S3_SOURCE_PLL3);
  ASSERT_EQ(RCC->CFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = (1u << 18);
  rcc_set_i2s3_source(RCC_I2S3_SOURCE_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR2 = 0xffffffff;
  rcc_set_i2s3_source(RCC_I2S3_SOURCE_SYSCLOCK);
  ASSERT_EQ(RCC->CFGR2, 0xffffffff & ~(1u << 18));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART1)
void
test_rcc_set_usart1_clock_source(void)
{
  // scope=self.reg='CFGR3', self.shift=0, self.mask='0x3', self.varsmap={'prescaler': 'RCC_USART_CLOCK_SOURCE_PCLK'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_PCLK);
  ASSERT_EQ(RCC->CFGR3, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 0);
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_PCLK);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=0, self.mask='0x3', self.varsmap={'prescaler': 'RCC_USART_CLOCK_SOURCE_SYSCL'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_SYSCL);
  ASSERT_EQ(RCC->CFGR3, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 0);
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_SYSCL);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=0, self.mask='0x3', self.varsmap={'prescaler': 'RCC_USART_CLOCK_SOURCE_LSE'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 0);
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=0, self.mask='0x3', self.varsmap={'prescaler': 'RCC_USART_CLOCK_SOURCE_HSI'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, (0b11u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 0);
  rcc_set_usart1_clock_source(RCC_USART_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 0) | (0b11u << 0));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_I2C1)
void
test_rcc_set_i2c1_clock_source(void)
{
  RCC->CFGR3 = 0;
  rcc_set_i2c1_clock_source(RCC_I2C1_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->CFGR3, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(1u << 4);
  rcc_set_i2c1_clock_source(RCC_I2C1_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->CFGR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = (1u << 4);
  rcc_set_i2c1_clock_source(RCC_I2C1_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = 0xffffffff;
  rcc_set_i2c1_clock_source(RCC_I2C1_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART1)
void
test_rcc_set_cec_clock_source(void)
{
  RCC->CFGR3 = 0;
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(1u << 6);
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = (1u << 6);
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_HSI_DIV244);
  ASSERT_EQ(RCC->CFGR3, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = 0xffffffff;
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_HSI_DIV244);
  ASSERT_EQ(RCC->CFGR3, 0xffffffff & ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USB)
void
test_rcc_set_usb_clock_source(void)
{
  RCC->CFGR3 = 0;
  rcc_set_usb_clock_source(RCC_USB_CLOCK_SOURCE_PLLCLK);
  ASSERT_EQ(RCC->CFGR3, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(1u << 7);
  rcc_set_usb_clock_source(RCC_USB_CLOCK_SOURCE_PLLCLK);
  ASSERT_EQ(RCC->CFGR3, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = (1u << 7);
  rcc_set_usb_clock_source(RCC_USB_CLOCK_SOURCE_HSI48);
  ASSERT_EQ(RCC->CFGR3, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = 0xffffffff;
  rcc_set_usb_clock_source(RCC_USB_CLOCK_SOURCE_HSI48);
  ASSERT_EQ(RCC->CFGR3, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART2)
void
test_rcc_set_usart2_clock_source(void)
{
  // scope=self.reg='CFGR3', self.shift=16, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_PCLK'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_PCLK);
  ASSERT_EQ(RCC->CFGR3, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 16);
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_PCLK);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=16, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_SYSCL'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_SYSCL);
  ASSERT_EQ(RCC->CFGR3, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 16);
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_SYSCL);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=16, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_LSE'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 16);
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=16, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_HSI'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 16);
  rcc_set_usart2_clock_source(RCC_USART_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART3)
void
test_rcc_set_usart3_clock_source(void)
{
  // scope=self.reg='CFGR3', self.shift=18, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_PCLK'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_PCLK);
  ASSERT_EQ(RCC->CFGR3, (0b00u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 18);
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_PCLK);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 18) | (0b00u << 18));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=18, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_SYSCL'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_SYSCL);
  ASSERT_EQ(RCC->CFGR3, (0b01u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 18);
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_SYSCL);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 18) | (0b01u << 18));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=18, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_LSE'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, (0b10u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 18);
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 18) | (0b10u << 18));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR3', self.shift=18, self.mask='0x3', self.varsmap={'source': 'RCC_USART_CLOCK_SOURCE_HSI'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->CFGR3 = 0;
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, (0b11u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR3 = ~(0x3u << 18);
  rcc_set_usart3_clock_source(RCC_USART_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR3, ~(0x3u << 18) | (0b11u << 18));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_RCC_OSC_HSI14)
void
test_rcc_set_hsi14_trim(void)
{
  RCC->CR2 = 0;
  rcc_set_hsi14_trim(0);
  ASSERT_EQ(RCC->CR2, 0u << 3);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffffffff;
  rcc_set_hsi14_trim(0);
  ASSERT_EQ(RCC->CR2, ~(0x1fu << 3) | (0u << 3));
  ASSERT_FALSE(execution_halted());


  RCC->CR2 = 0;
  rcc_set_hsi14_trim(0x1f);
  ASSERT_EQ(RCC->CR2, 0x1fu << 3);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffffffff;
  rcc_set_hsi14_trim(0x1f);
  ASSERT_EQ(RCC->CR2, ~(0x1fu << 3) | (0x1fu << 3));
  ASSERT_FALSE(execution_halted());


  RCC->CR2 = 0;
  rcc_set_hsi14_trim(0x20);
  ASSERT_EQ(RCC->CR2, 0x20u << 3);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->CR2 = 0xffffffff;
  rcc_set_hsi14_trim(0x20);
  ASSERT_EQ(RCC->CR2, ~(0x1fu << 3) | (0x20u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_RCC_OSC_HSI14)
void
test_rcc_get_hsi14_calibration(void)
{
  u32 res;

  // read_bits
  RCC->CR2 = 0;
  res = rcc_get_hsi14_calibration();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = ~(0xffu << 8);
  res = rcc_get_hsi14_calibration();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffu << 8;
  res = rcc_get_hsi14_calibration();
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_RCC_OSC_HSI14)
void
test_rcc_get_hsi48_calibration(void)
{
  u32 res;

  // read_bits
  RCC->CR2 = 0;
  res = rcc_get_hsi48_calibration();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = ~(0xffu << 24);
  res = rcc_get_hsi48_calibration();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR2 = 0xffu << 24;
  res = rcc_get_hsi48_calibration();
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_rcc_osc),
    TEST_FUNC(test_rcc_osc_is_ready),
    TEST_FUNC(test_rcc_set_hsi_trim),
    TEST_FUNC(test_rcc_get_hsi_cal),
    TEST_FUNC(test_rcc_hse_bypass),
    TEST_FUNC(test_rcc_hse_bypass_is_enabled),
    TEST_FUNC(test_rcc_clock_security_system),
    TEST_FUNC(test_rcc_clock_security_system_is_enabled),
    TEST_FUNC(test_rcc_set_sysclock_source),
    TEST_FUNC(test_rcc_get_sysclock_status_raw),
    TEST_FUNC(test_rcc_set_ahb_prescaler),
    TEST_FUNC(test_rcc_set_apb1_prescaler),
#if defined(STM32_RCC_PPRE2)
    TEST_FUNC(test_rcc_set_apb2_prescaler),
#endif
#if defined(STM32_RCC_ADCPRE)
    TEST_FUNC(test_rcc_set_adc_prescaler),
#endif
#if defined(STM32_RCC_PLLSRC_2BIT)
    TEST_FUNC(test_rcc_set_pll_source),
#endif
#if !defined(STM32_RCC_PLLSRC_2BIT)
    TEST_FUNC(test_rcc_set_pll_source),
#endif
    TEST_FUNC(test_rcc_set_pll_hse_prescaler),
    TEST_FUNC(test_rcc_set_pll_multiplication_factor),
#if defined(STM32_RCC_OTGFS)
    TEST_FUNC(test_rcc_set_usb_otg_fs_prescaler),
#endif
#if defined(STM32_RCC_CFGR_MCO_3BIT)
    TEST_FUNC(test_rcc_set_microcontroller_clock_output),
#endif
#if defined(STM32_RCC_CFGR_MCO_4BIT)
    TEST_FUNC(test_rcc_set_microcontroller_clock_output),
#endif
#if defined(STM32_RCC_MCOPRE)
    TEST_FUNC(test_rcc_set_mco_prescaler),
#endif
#if defined(STM32_RCC_PLLNODIV)
    TEST_FUNC(test_rcc_set_mco_pll_prescaler),
#endif
    TEST_FUNC(test_rcc_is_interrupt_flag_set),
    TEST_FUNC(test_rcc_interrupt),
    TEST_FUNC(test_rcc_interrupt_flag_clear),
    TEST_FUNC(test_rcc_periph_reset),
    TEST_FUNC(test_rcc_periph_clock),
    TEST_FUNC(test_rcc_set_rtc_source),
    TEST_FUNC(test_rcc_lse_bypass),
    TEST_FUNC(test_rcc_lse_bypass_is_enabled),
    TEST_FUNC(test_rcc_reset_is_flag_set),
    TEST_FUNC(test_rcc_reset_flags_clear),
#if defined(STM32_RCC_CFGR2)
    TEST_FUNC(test_rcc_set_prediv1_prescaler),
#endif
#if defined(STM32_RCC_PREDIV2)
    TEST_FUNC(test_rcc_set_prediv2_prescaler),
#endif
#if defined(STM32_RCC_CFGR2) && defined(STM32_RCC_OSC_PLL2)
    TEST_FUNC(test_rcc_set_pll2_multiplication_factor),
#endif
#if defined(STM32_RCC_CFGR2) && defined(STM32_RCC_OSC_PLL3)
    TEST_FUNC(test_rcc_set_pll3_multiplication_factor),
#endif
#if defined(STM32_RCC_CFGR2) && defined(STM32_RCC_PREDIV1)
    TEST_FUNC(test_rcc_set_prediv1_source),
#endif
#if defined(STM32_RCC_CFGR2) && defined(STM32_I2S2)
    TEST_FUNC(test_rcc_set_i2s2_source),
#endif
#if defined(STM32_RCC_CFGR2) && defined(STM32_I2S3)
    TEST_FUNC(test_rcc_set_i2s3_source),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART1)
    TEST_FUNC(test_rcc_set_usart1_clock_source),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_I2C1)
    TEST_FUNC(test_rcc_set_i2c1_clock_source),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART1)
    TEST_FUNC(test_rcc_set_cec_clock_source),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USB)
    TEST_FUNC(test_rcc_set_usb_clock_source),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART2)
    TEST_FUNC(test_rcc_set_usart2_clock_source),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_USART3)
    TEST_FUNC(test_rcc_set_usart3_clock_source),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_RCC_OSC_HSI14)
    TEST_FUNC(test_rcc_set_hsi14_trim),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_RCC_OSC_HSI14)
    TEST_FUNC(test_rcc_get_hsi14_calibration),
#endif
#if defined(STM32_RCC_EXTENDED_REGS) && defined(STM32_RCC_OSC_HSI14)
    TEST_FUNC(test_rcc_get_hsi48_calibration),
#endif
  };

  return TESTS_RUN(tests);
}
