#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/rcc/rcc_v2.h"
#include "libtest/libtest.h"

void
setup(void)
{
  RCC = (struct rcc_registers_map*) membuf;
}

void
test_rcc_osc(void)
{
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


#if defined(STM32_RCC_OSC_PLLI2S)
  RCC->CR = 0;
  rcc_osc_enable(RCC_OSC_PLLI2S);
  ASSERT_EQ(RCC->CR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 26);
  rcc_osc_enable(RCC_OSC_PLLI2S);
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 26);
  rcc_osc_disable(RCC_OSC_PLLI2S);
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_PLLI2S);
  ASSERT_EQ(RCC->CR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLLSAI)
  RCC->CR = 0;
  rcc_osc_enable(RCC_OSC_PLLSAI);
  ASSERT_EQ(RCC->CR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 28);
  rcc_osc_enable(RCC_OSC_PLLSAI);
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 28);
  rcc_osc_disable(RCC_OSC_PLLSAI);
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_osc_disable(RCC_OSC_PLLSAI);
  ASSERT_EQ(RCC->CR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());

#endif

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
test_rcc_is_osc_ready(void)
{
  u32 res;

  RCC->CR = 0;
  res = rcc_is_osc_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 1);
  res = rcc_is_osc_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 1);
  res = rcc_is_osc_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_is_osc_ready(RCC_OSC_HSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RCC->CR = 0;
  res = rcc_is_osc_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 17);
  res = rcc_is_osc_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 17);
  res = rcc_is_osc_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_is_osc_ready(RCC_OSC_HSE);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_OSC_PLLI2S)
  RCC->CR = 0;
  res = rcc_is_osc_ready(RCC_OSC_PLLI2S);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 27);
  res = rcc_is_osc_ready(RCC_OSC_PLLI2S);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 27);
  res = rcc_is_osc_ready(RCC_OSC_PLLI2S);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_is_osc_ready(RCC_OSC_PLLI2S);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_OSC_PLLSAI)
  RCC->CR = 0;
  res = rcc_is_osc_ready(RCC_OSC_PLLSAI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 29);
  res = rcc_is_osc_ready(RCC_OSC_PLLSAI);
  ASSERT_EQ(res, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 29);
  res = rcc_is_osc_ready(RCC_OSC_PLLSAI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  res = rcc_is_osc_ready(RCC_OSC_PLLSAI);
  ASSERT_EQ(res, (1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CSR = 0;
  res = rcc_is_osc_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 1);
  res = rcc_is_osc_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 1);
  res = rcc_is_osc_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_osc_ready(RCC_OSC_LSI);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RCC->BDCR = 0;
  res = rcc_is_osc_ready(RCC_OSC_LSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = (1u << 1);
  res = rcc_is_osc_ready(RCC_OSC_LSE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(1u << 1);
  res = rcc_is_osc_ready(RCC_OSC_LSE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = 0xffffffff;
  res = rcc_is_osc_ready(RCC_OSC_LSE);
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
test_rcc_css(void)
{
  RCC->CR = 0;
  rcc_css_enable();
  ASSERT_EQ(RCC->CR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->CR = ~(1u << 19);
  rcc_css_enable();
  ASSERT_EQ(RCC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CR = (1u << 19);
  rcc_css_disable();
  ASSERT_EQ(RCC->CR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CR = 0xffffffff;
  rcc_css_disable();
  ASSERT_EQ(RCC->CR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_set_main_pll_factorM(void)
{
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorM(0);
  ASSERT_EQ(RCC->PLLCFGR, 0u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorM(0);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3fu << 0) | (0u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorM(1);
  ASSERT_EQ(RCC->PLLCFGR, 1u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorM(1);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3fu << 0) | (1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorM(2);
  ASSERT_EQ(RCC->PLLCFGR, 2u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorM(2);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3fu << 0) | (2u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorM(63);
  ASSERT_EQ(RCC->PLLCFGR, 63u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorM(63);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3fu << 0) | (63u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorM(64);
  ASSERT_EQ(RCC->PLLCFGR, 64u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorM(64);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3fu << 0) | (64u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rcc_set_main_pll_factorN(void)
{
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorN(0);
  ASSERT_EQ(RCC->PLLCFGR, 0u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorN(0);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x1ffu << 6) | (0u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorN(49);
  ASSERT_EQ(RCC->PLLCFGR, 49u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorN(49);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x1ffu << 6) | (49u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorN(50);
  ASSERT_EQ(RCC->PLLCFGR, 50u << 6);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorN(50);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x1ffu << 6) | (50u << 6));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorN(432);
  ASSERT_EQ(RCC->PLLCFGR, 432u << 6);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorN(432);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x1ffu << 6) | (432u << 6));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorN(433);
  ASSERT_EQ(RCC->PLLCFGR, 433u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorN(433);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x1ffu << 6) | (433u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rcc_set_main_pll_factorP(void)
{
  // scope=self.reg='PLLCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_MAIN_PLL_FACTORP_DIV2'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV2);
  ASSERT_EQ(RCC->PLLCFGR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = ~(0x3u << 16);
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV2);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_MAIN_PLL_FACTORP_DIV4'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV4);
  ASSERT_EQ(RCC->PLLCFGR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = ~(0x3u << 16);
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV4);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_MAIN_PLL_FACTORP_DIV6'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV6);
  ASSERT_EQ(RCC->PLLCFGR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = ~(0x3u << 16);
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV6);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_MAIN_PLL_FACTORP_DIV8'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV8);
  ASSERT_EQ(RCC->PLLCFGR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = ~(0x3u << 16);
  rcc_set_main_pll_factorP(RCC_MAIN_PLL_FACTORP_DIV8);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_set_main_pll_factorQ(void)
{
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorQ(0);
  ASSERT_EQ(RCC->PLLCFGR, 0u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorQ(0);
  ASSERT_EQ(RCC->PLLCFGR, ~(0xfu << 24) | (0u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorQ(1);
  ASSERT_EQ(RCC->PLLCFGR, 1u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorQ(1);
  ASSERT_EQ(RCC->PLLCFGR, ~(0xfu << 24) | (1u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorQ(2);
  ASSERT_EQ(RCC->PLLCFGR, 2u << 24);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorQ(2);
  ASSERT_EQ(RCC->PLLCFGR, ~(0xfu << 24) | (2u << 24));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorQ(15);
  ASSERT_EQ(RCC->PLLCFGR, 15u << 24);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorQ(15);
  ASSERT_EQ(RCC->PLLCFGR, ~(0xfu << 24) | (15u << 24));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorQ(16);
  ASSERT_EQ(RCC->PLLCFGR, 16u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorQ(16);
  ASSERT_EQ(RCC->PLLCFGR, ~(0xfu << 24) | (16u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

#if defined(STM32_RCC_PLLR)
void
test_rcc_set_main_pll_factorR(void)
{
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorR(0);
  ASSERT_EQ(RCC->PLLCFGR, 0u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorR(0);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x7u << 28) | (0u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorR(1);
  ASSERT_EQ(RCC->PLLCFGR, 1u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorR(1);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x7u << 28) | (1u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorR(2);
  ASSERT_EQ(RCC->PLLCFGR, 2u << 28);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorR(2);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x7u << 28) | (2u << 28));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorR(7);
  ASSERT_EQ(RCC->PLLCFGR, 7u << 28);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorR(7);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x7u << 28) | (7u << 28));
  ASSERT_FALSE(execution_halted());


  RCC->PLLCFGR = 0;
  rcc_set_main_pll_factorR(8);
  ASSERT_EQ(RCC->PLLCFGR, 8u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_factorR(8);
  ASSERT_EQ(RCC->PLLCFGR, ~(0x7u << 28) | (8u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

void
test_rcc_set_main_pll_source(void)
{
  RCC->PLLCFGR = 0;
  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSE);
  ASSERT_EQ(RCC->PLLCFGR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = ~(1u << 22);
  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSE);
  ASSERT_EQ(RCC->PLLCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = (1u << 22);
  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSI);
  ASSERT_EQ(RCC->PLLCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLCFGR = 0xffffffff;
  rcc_set_main_pll_source(RCC_MAIN_PLL_SOURCE_HSI);
  ASSERT_EQ(RCC->PLLCFGR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_set_system_clock_source(void)
{
  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'source': 'RCC_SYSTEM_CLOCK_SOURCE_HSI'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR, (0b00u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b00u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'source': 'RCC_SYSTEM_CLOCK_SOURCE_HSE'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_HSE);
  ASSERT_EQ(RCC->CFGR, (0b01u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_HSE);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b01u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_PLLR_SW)
  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'source': 'RCC_SYSTEM_CLOCK_SOURCE_PLLP'}, self.value='0b10', self.ifdef=['STM32_RCC_PLLR_SW'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLLP);
  ASSERT_EQ(RCC->CFGR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLLP);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLR_SW)
  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'source': 'RCC_SYSTEM_CLOCK_SOURCE_PLLR'}, self.value='0b11', self.ifdef=['STM32_RCC_PLLR_SW'], self.halt=False
  RCC->CFGR = 0;
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->CFGR, (0b11u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b11u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if !defined(STM32_RCC_PLLR_SW)
  // scope=self.reg='CFGR', self.shift=0, self.mask='0x3', self.varsmap={'source': 'RCC_SYSTEM_CLOCK_SOURCE_PLL'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLL);
  ASSERT_EQ(RCC->CFGR, (0b10u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 0);
  rcc_set_system_clock_source(RCC_SYSTEM_CLOCK_SOURCE_PLL);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 0) | (0b10u << 0));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rcc_get_system_clock_source(void)
{
  u32 res;

  // read_bits
  RCC->CFGR = 0;
  res = rcc_get_system_clock_source();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 2);
  res = rcc_get_system_clock_source();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0x3u << 2;
  res = rcc_get_system_clock_source();
  ASSERT_EQ(res, 0x3);
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_set_ahb_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_NODIV'}, self.value='0b0000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV2'}, self.value='0b1000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV4'}, self.value='0b1001', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV8'}, self.value='0b1010', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CFGR, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV16'}, self.value='0b1011', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CFGR, (0b1011u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV64'}, self.value='0b1100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV64);
  ASSERT_EQ(RCC->CFGR, (0b1100u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV64);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV128'}, self.value='0b1101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV128);
  ASSERT_EQ(RCC->CFGR, (0b1101u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV128);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV256'}, self.value='0b1110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV256);
  ASSERT_EQ(RCC->CFGR, (0b1110u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV256);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=4, self.mask='0xf', self.varsmap={'prescaler': 'RCC_AHB_PRESCALER_DIV512'}, self.value='0b1111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV512);
  ASSERT_EQ(RCC->CFGR, (0b1111u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0xfu << 4);
  rcc_set_ahb_prescaler(RCC_AHB_PRESCALER_DIV512);
  ASSERT_EQ(RCC->CFGR, ~(0xfu << 4) | (0b1111u << 4));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_RCC_MCOEN)
void
test_rcc_mco(void)
{
  RCC->CFGR = 0;
  rcc_mco_enable(RCC_MCO1);
  ASSERT_EQ(RCC->CFGR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(1u << 8);
  rcc_mco_enable(RCC_MCO1);
  ASSERT_EQ(RCC->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = (1u << 8);
  rcc_mco_disable(RCC_MCO1);
  ASSERT_EQ(RCC->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_mco_disable(RCC_MCO1);
  ASSERT_EQ(RCC->CFGR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  RCC->CFGR = 0;
  rcc_mco_enable(RCC_MCO2);
  ASSERT_EQ(RCC->CFGR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(1u << 9);
  rcc_mco_enable(RCC_MCO2);
  ASSERT_EQ(RCC->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = (1u << 9);
  rcc_mco_disable(RCC_MCO2);
  ASSERT_EQ(RCC->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_mco_disable(RCC_MCO2);
  ASSERT_EQ(RCC->CFGR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_rcc_set_apb1_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=10, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_NODIV'}, self.value='0b000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, (0b000u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 10);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 10) | (0b000u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=10, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_DIV2'}, self.value='0b100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b100u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 10);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 10) | (0b100u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=10, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_DIV4'}, self.value='0b101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, (0b101u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 10);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 10) | (0b101u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=10, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_DIV8'}, self.value='0b110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CFGR, (0b110u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 10);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 10) | (0b110u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=10, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB1_PRESCALER_DIV16'}, self.value='0b111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CFGR, (0b111u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 10);
  rcc_set_apb1_prescaler(RCC_APB1_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 10) | (0b111u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_set_apb2_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=13, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_NODIV'}, self.value='0b000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, (0b000u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 13);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 13) | (0b000u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=13, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_DIV2'}, self.value='0b100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b100u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 13);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 13) | (0b100u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=13, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_DIV4'}, self.value='0b101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, (0b101u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 13);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 13) | (0b101u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=13, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_DIV8'}, self.value='0b110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CFGR, (0b110u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 13);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV8);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 13) | (0b110u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=13, self.mask='0x7', self.varsmap={'prescaler': 'RCC_APB2_PRESCALER_DIV16'}, self.value='0b111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CFGR, (0b111u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 13);
  rcc_set_apb2_prescaler(RCC_APB2_PRESCALER_DIV16);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 13) | (0b111u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_set_rtc_prescaler(void)
{
  RCC->CFGR = 0;
  rcc_set_rtc_prescaler(0);
  ASSERT_EQ(RCC->CFGR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_set_rtc_prescaler(0);
  ASSERT_EQ(RCC->CFGR, ~(0x1fu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  RCC->CFGR = 0;
  rcc_set_rtc_prescaler(0x1f);
  ASSERT_EQ(RCC->CFGR, 0x1fu << 16);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_set_rtc_prescaler(0x1f);
  ASSERT_EQ(RCC->CFGR, ~(0x1fu << 16) | (0x1fu << 16));
  ASSERT_FALSE(execution_halted());


  RCC->CFGR = 0;
  rcc_set_rtc_prescaler(0x20);
  ASSERT_EQ(RCC->CFGR, 0x20u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->CFGR = 0xffffffff;
  rcc_set_rtc_prescaler(0x20);
  ASSERT_EQ(RCC->CFGR, ~(0x1fu << 16) | (0x20u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rcc_set_mco1(void)
{
  // scope=self.reg='CFGR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RCC_MCO1_HSI'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1(RCC_MCO1_HSI);
  ASSERT_EQ(RCC->CFGR, (0b00u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 21);
  rcc_set_mco1(RCC_MCO1_HSI);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 21) | (0b00u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RCC_MCO1_LSE'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1(RCC_MCO1_LSE);
  ASSERT_EQ(RCC->CFGR, (0b01u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 21);
  rcc_set_mco1(RCC_MCO1_LSE);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 21) | (0b01u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RCC_MCO1_HSE'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1(RCC_MCO1_HSE);
  ASSERT_EQ(RCC->CFGR, (0b10u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 21);
  rcc_set_mco1(RCC_MCO1_HSE);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 21) | (0b10u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=21, self.mask='0x3', self.varsmap={'output': 'RCC_MCO1_PLL'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1(RCC_MCO1_PLL);
  ASSERT_EQ(RCC->CFGR, (0b11u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 21);
  rcc_set_mco1(RCC_MCO1_PLL);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 21) | (0b11u << 21));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_RCC_I2S)
void
test_rcc_set_i2s_clock_source(void)
{
  RCC->CFGR = 0;
  rcc_set_i2s_clock_source(RCC_I2S_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->CFGR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(1u << 23);
  rcc_set_i2s_clock_source(RCC_I2S_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = (1u << 23);
  rcc_set_i2s_clock_source(RCC_I2S_CLOCK_SOURCE_PLLI2S);
  ASSERT_EQ(RCC->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = 0xffffffff;
  rcc_set_i2s_clock_source(RCC_I2S_CLOCK_SOURCE_PLLI2S);
  ASSERT_EQ(RCC->CFGR, 0xffffffff & ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_rcc_set_mco1_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_NODIV'}, self.value='0b000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, (0b000u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b000u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV2'}, self.value='0b100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b100u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b100u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV3'}, self.value='0b101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV3);
  ASSERT_EQ(RCC->CFGR, (0b101u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV3);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b101u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV4'}, self.value='0b110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, (0b110u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b110u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=24, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV5'}, self.value='0b111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV5);
  ASSERT_EQ(RCC->CFGR, (0b111u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 24);
  rcc_set_mco1_prescaler(RCC_MCO_PRESCALER_DIV5);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 24) | (0b111u << 24));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_set_mco2_prescaler(void)
{
  // scope=self.reg='CFGR', self.shift=27, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_NODIV'}, self.value='0b000', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, (0b000u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 27);
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_NODIV);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 27) | (0b000u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=27, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV2'}, self.value='0b100', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, (0b100u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 27);
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV2);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 27) | (0b100u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=27, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV3'}, self.value='0b101', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV3);
  ASSERT_EQ(RCC->CFGR, (0b101u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 27);
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV3);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 27) | (0b101u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=27, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV4'}, self.value='0b110', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, (0b110u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 27);
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV4);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 27) | (0b110u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=27, self.mask='0x7', self.varsmap={'prescaler': 'RCC_MCO_PRESCALER_DIV5'}, self.value='0b111', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV5);
  ASSERT_EQ(RCC->CFGR, (0b111u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x7u << 27);
  rcc_set_mco2_prescaler(RCC_MCO_PRESCALER_DIV5);
  ASSERT_EQ(RCC->CFGR, ~(0x7u << 27) | (0b111u << 27));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_set_mco2(void)
{
  // scope=self.reg='CFGR', self.shift=30, self.mask='0x3', self.varsmap={'output': 'RCC_MCO2_SYSCLK'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2(RCC_MCO2_SYSCLK);
  ASSERT_EQ(RCC->CFGR, (0b00u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 30);
  rcc_set_mco2(RCC_MCO2_SYSCLK);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 30) | (0b00u << 30));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=30, self.mask='0x3', self.varsmap={'output': 'RCC_MCO2_PLLI2S'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2(RCC_MCO2_PLLI2S);
  ASSERT_EQ(RCC->CFGR, (0b01u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 30);
  rcc_set_mco2(RCC_MCO2_PLLI2S);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 30) | (0b01u << 30));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=30, self.mask='0x3', self.varsmap={'output': 'RCC_MCO2_HSE'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2(RCC_MCO2_HSE);
  ASSERT_EQ(RCC->CFGR, (0b10u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 30);
  rcc_set_mco2(RCC_MCO2_HSE);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 30) | (0b10u << 30));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CFGR', self.shift=30, self.mask='0x3', self.varsmap={'output': 'RCC_MCO2_PLL'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->CFGR = 0;
  rcc_set_mco2(RCC_MCO2_PLL);
  ASSERT_EQ(RCC->CFGR, (0b11u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->CFGR = ~(0x3u << 30);
  rcc_set_mco2(RCC_MCO2_PLL);
  ASSERT_EQ(RCC->CFGR, ~(0x3u << 30) | (0b11u << 30));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_is_flag_set(void)
{
  u32 res;

  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_LSI_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 0);
  res = rcc_is_flag_set(RCC_FLAG_LSI_READY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 0);
  res = rcc_is_flag_set(RCC_FLAG_LSI_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_LSI_READY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_LSE_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 1);
  res = rcc_is_flag_set(RCC_FLAG_LSE_READY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 1);
  res = rcc_is_flag_set(RCC_FLAG_LSE_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_LSE_READY);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_HSI_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 2);
  res = rcc_is_flag_set(RCC_FLAG_HSI_READY);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 2);
  res = rcc_is_flag_set(RCC_FLAG_HSI_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_HSI_READY);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_HSE_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 3);
  res = rcc_is_flag_set(RCC_FLAG_HSE_READY);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 3);
  res = rcc_is_flag_set(RCC_FLAG_HSE_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_HSE_READY);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_PLL_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 4);
  res = rcc_is_flag_set(RCC_FLAG_PLL_READY);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 4);
  res = rcc_is_flag_set(RCC_FLAG_PLL_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_PLL_READY);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_PLLI2S)
  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_PLLI2S_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 5);
  res = rcc_is_flag_set(RCC_FLAG_PLLI2S_READY);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 5);
  res = rcc_is_flag_set(RCC_FLAG_PLLI2S_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_PLLI2S_READY);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLSAI)
  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_PLLSAI_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 6);
  res = rcc_is_flag_set(RCC_FLAG_PLLSAI_READY);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 6);
  res = rcc_is_flag_set(RCC_FLAG_PLLSAI_READY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_PLLSAI_READY);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CIR = 0;
  res = rcc_is_flag_set(RCC_FLAG_CSS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 7);
  res = rcc_is_flag_set(RCC_FLAG_CSS);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 7);
  res = rcc_is_flag_set(RCC_FLAG_CSS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  res = rcc_is_flag_set(RCC_FLAG_CSS);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_flag_clear(void)
{
  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_LSI_READY);
  ASSERT_EQ(RCC->CIR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 16);
  rcc_flag_clear(RCC_FLAG_LSI_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_LSE_READY);
  ASSERT_EQ(RCC->CIR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 17);
  rcc_flag_clear(RCC_FLAG_LSE_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_HSI_READY);
  ASSERT_EQ(RCC->CIR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 18);
  rcc_flag_clear(RCC_FLAG_HSI_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_HSE_READY);
  ASSERT_EQ(RCC->CIR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 19);
  rcc_flag_clear(RCC_FLAG_HSE_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_PLL_READY);
  ASSERT_EQ(RCC->CIR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 20);
  rcc_flag_clear(RCC_FLAG_PLL_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_PLLI2S)
  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_PLLI2S_READY);
  ASSERT_EQ(RCC->CIR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 21);
  rcc_flag_clear(RCC_FLAG_PLLI2S_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLSAI)
  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_PLLSAI_READY);
  ASSERT_EQ(RCC->CIR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 22);
  rcc_flag_clear(RCC_FLAG_PLLSAI_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

  RCC->CIR = 0;
  rcc_flag_clear(RCC_FLAG_CSS);
  ASSERT_EQ(RCC->CIR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 23);
  rcc_flag_clear(RCC_FLAG_CSS);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_rcc_interrupt(void)
{
  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_LSI_READY);
  ASSERT_EQ(RCC->CIR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 8);
  rcc_interrupt_enable(RCC_INTERRUPT_LSI_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 8);
  rcc_interrupt_disable(RCC_INTERRUPT_LSI_READY);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_LSI_READY);
  ASSERT_EQ(RCC->CIR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_LSE_READY);
  ASSERT_EQ(RCC->CIR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 9);
  rcc_interrupt_enable(RCC_INTERRUPT_LSE_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 9);
  rcc_interrupt_disable(RCC_INTERRUPT_LSE_READY);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_LSE_READY);
  ASSERT_EQ(RCC->CIR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_HSI_READY);
  ASSERT_EQ(RCC->CIR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 10);
  rcc_interrupt_enable(RCC_INTERRUPT_HSI_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 10);
  rcc_interrupt_disable(RCC_INTERRUPT_HSI_READY);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_HSI_READY);
  ASSERT_EQ(RCC->CIR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_HSE_READY);
  ASSERT_EQ(RCC->CIR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 11);
  rcc_interrupt_enable(RCC_INTERRUPT_HSE_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 11);
  rcc_interrupt_disable(RCC_INTERRUPT_HSE_READY);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_HSE_READY);
  ASSERT_EQ(RCC->CIR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_PLL_READY);
  ASSERT_EQ(RCC->CIR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 12);
  rcc_interrupt_enable(RCC_INTERRUPT_PLL_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 12);
  rcc_interrupt_disable(RCC_INTERRUPT_PLL_READY);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_PLL_READY);
  ASSERT_EQ(RCC->CIR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_PLLI2S)
  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_PLLI2S_READY);
  ASSERT_EQ(RCC->CIR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 13);
  rcc_interrupt_enable(RCC_INTERRUPT_PLLI2S_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 13);
  rcc_interrupt_disable(RCC_INTERRUPT_PLLI2S_READY);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_PLLI2S_READY);
  ASSERT_EQ(RCC->CIR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_PLLSAI)
  RCC->CIR = 0;
  rcc_interrupt_enable(RCC_INTERRUPT_PLLSAI_READY);
  ASSERT_EQ(RCC->CIR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->CIR = ~(1u << 14);
  rcc_interrupt_enable(RCC_INTERRUPT_PLLSAI_READY);
  ASSERT_EQ(RCC->CIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = (1u << 14);
  rcc_interrupt_disable(RCC_INTERRUPT_PLLSAI_READY);
  ASSERT_EQ(RCC->CIR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CIR = 0xffffffff;
  rcc_interrupt_disable(RCC_INTERRUPT_PLLSAI_READY);
  ASSERT_EQ(RCC->CIR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rcc_periph_reset(void)
{
#if defined(STM32_GPIOA)
  // scope=self.reg='AHB1RSTR', self.shift=0, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOA'}, self.value=1, self.ifdef=['STM32_GPIOA'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 0);
  rcc_periph_reset(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  // scope=self.reg='AHB1RSTR', self.shift=1, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOB'}, self.value=1, self.ifdef=['STM32_GPIOB'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 1);
  rcc_periph_reset(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  // scope=self.reg='AHB1RSTR', self.shift=2, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOC'}, self.value=1, self.ifdef=['STM32_GPIOC'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 2);
  rcc_periph_reset(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 2) | (1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  // scope=self.reg='AHB1RSTR', self.shift=3, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOD'}, self.value=1, self.ifdef=['STM32_GPIOD'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 3);
  rcc_periph_reset(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 3) | (1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  // scope=self.reg='AHB1RSTR', self.shift=4, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOE'}, self.value=1, self.ifdef=['STM32_GPIOE'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 4);
  rcc_periph_reset(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  // scope=self.reg='AHB1RSTR', self.shift=5, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOF'}, self.value=1, self.ifdef=['STM32_GPIOF'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 5);
  rcc_periph_reset(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 5) | (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  // scope=self.reg='AHB1RSTR', self.shift=6, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOG'}, self.value=1, self.ifdef=['STM32_GPIOG'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 6);
  rcc_periph_reset(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  // scope=self.reg='AHB1RSTR', self.shift=7, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOH'}, self.value=1, self.ifdef=['STM32_GPIOH'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 7);
  rcc_periph_reset(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 7) | (1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  // scope=self.reg='AHB1RSTR', self.shift=8, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOI'}, self.value=1, self.ifdef=['STM32_GPIOI'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 8);
  rcc_periph_reset(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 8) | (1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  // scope=self.reg='AHB1RSTR', self.shift=9, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOJ'}, self.value=1, self.ifdef=['STM32_GPIOJ'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 9);
  rcc_periph_reset(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 9) | (1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  // scope=self.reg='AHB1RSTR', self.shift=10, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_GPIOK'}, self.value=1, self.ifdef=['STM32_GPIOK'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 10);
  rcc_periph_reset(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 10) | (1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='AHB1RSTR', self.shift=12, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_CRC'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 12);
  rcc_periph_reset(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 12) | (1u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='AHB1RSTR', self.shift=21, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DMA1'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 21);
  rcc_periph_reset(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 21) | (1u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='AHB1RSTR', self.shift=22, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DMA2'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 22);
  rcc_periph_reset(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 22) | (1u << 22));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DMA2D)
  // scope=self.reg='AHB1RSTR', self.shift=23, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DMA2D'}, self.value=1, self.ifdef=['STM32_DMA2D'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 23);
  rcc_periph_reset(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 23) | (1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  // scope=self.reg='AHB1RSTR', self.shift=25, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_ETHMAC'}, self.value=1, self.ifdef=['STM32_ETHERNET_MAC'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 25);
  rcc_periph_reset(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 25) | (1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB_OTG_HS)
  // scope=self.reg='AHB1RSTR', self.shift=29, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_OTG_HS'}, self.value=1, self.ifdef=['STM32_USB_OTG_HS'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 29);
  rcc_periph_reset(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 29) | (1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB1)
  // scope=self.reg='AHB1RSTR', self.shift=31, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_RNG'}, self.value=1, self.ifdef=['STM32_RNG', 'STM32_RCC_RNG_AHB1'], self.halt=False
  RCC->AHB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1RSTR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1RSTR = ~(0u << 31);
  rcc_periph_reset(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1RSTR, ~(0u << 31) | (1u << 31));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_DCMI)
  // scope=self.reg='AHB2RSTR', self.shift=0, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DCMI'}, self.value=1, self.ifdef=['STM32_RCC_AHB2', 'STM32_DCMI'], self.halt=False
  RCC->AHB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2RSTR = ~(0u << 0);
  rcc_periph_reset(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2RSTR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_CRYP)
  // scope=self.reg='AHB2RSTR', self.shift=4, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_CRYPTO'}, self.value=1, self.ifdef=['STM32_RCC_AHB2', 'STM32_CRYP'], self.halt=False
  RCC->AHB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2RSTR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2RSTR = ~(0u << 4);
  rcc_periph_reset(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2RSTR, ~(0u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_HASH)
  // scope=self.reg='AHB2RSTR', self.shift=5, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_HASH'}, self.value=1, self.ifdef=['STM32_RCC_AHB2', 'STM32_HASH'], self.halt=False
  RCC->AHB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2RSTR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2RSTR = ~(0u << 5);
  rcc_periph_reset(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2RSTR, ~(0u << 5) | (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB2)
  // scope=self.reg='AHB2RSTR', self.shift=6, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_RNG'}, self.value=1, self.ifdef=['STM32_RCC_AHB2', 'STM32_RNG', 'STM32_RCC_RNG_AHB2'], self.halt=False
  RCC->AHB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2RSTR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2RSTR = ~(0u << 6);
  rcc_periph_reset(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2RSTR, ~(0u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2)
  // scope=self.reg='AHB2RSTR', self.shift=7, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_OTG_FS'}, self.value=1, self.ifdef=['STM32_RCC_AHB2'], self.halt=False
  RCC->AHB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2RSTR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2RSTR = ~(0u << 7);
  rcc_periph_reset(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2RSTR, ~(0u << 7) | (1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FMC)
  // scope=self.reg='AHB3RSTR', self.shift=0, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_FMC'}, self.value=1, self.ifdef=['STM32_FMC'], self.halt=False
  RCC->AHB3RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3RSTR = ~(0u << 0);
  rcc_periph_reset(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3RSTR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FSMC)
  // scope=self.reg='AHB3RSTR', self.shift=0, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_FSMC'}, self.value=1, self.ifdef=['STM32_FSMC'], self.halt=False
  RCC->AHB3RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3RSTR = ~(0u << 0);
  rcc_periph_reset(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3RSTR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_QUADSPI)
  // scope=self.reg='AHB3RSTR', self.shift=1, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_QUADSPI'}, self.value=1, self.ifdef=['STM32_QUADSPI'], self.halt=False
  RCC->AHB3RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3RSTR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3RSTR = ~(0u << 1);
  rcc_periph_reset(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3RSTR, ~(0u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  // scope=self.reg='APB1RSTR', self.shift=0, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM2'}, self.value=1, self.ifdef=['STM32_TIM2'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 0);
  rcc_periph_reset(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  // scope=self.reg='APB1RSTR', self.shift=1, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM3'}, self.value=1, self.ifdef=['STM32_TIM3'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 1);
  rcc_periph_reset(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  // scope=self.reg='APB1RSTR', self.shift=2, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM4'}, self.value=1, self.ifdef=['STM32_TIM4'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 2);
  rcc_periph_reset(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 2) | (1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM5)
  // scope=self.reg='APB1RSTR', self.shift=3, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM5'}, self.value=1, self.ifdef=['STM32_TIM5'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 3);
  rcc_periph_reset(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 3) | (1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM6)
  // scope=self.reg='APB1RSTR', self.shift=4, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM6'}, self.value=1, self.ifdef=['STM32_TIM6'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 4);
  rcc_periph_reset(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM7)
  // scope=self.reg='APB1RSTR', self.shift=5, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM7'}, self.value=1, self.ifdef=['STM32_TIM7'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 5);
  rcc_periph_reset(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 5) | (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM12)
  // scope=self.reg='APB1RSTR', self.shift=6, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM12'}, self.value=1, self.ifdef=['STM32_TIM12'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 6);
  rcc_periph_reset(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM13)
  // scope=self.reg='APB1RSTR', self.shift=7, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM13'}, self.value=1, self.ifdef=['STM32_TIM13'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 7);
  rcc_periph_reset(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 7) | (1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM14)
  // scope=self.reg='APB1RSTR', self.shift=8, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM14'}, self.value=1, self.ifdef=['STM32_TIM14'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 8);
  rcc_periph_reset(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 8) | (1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_LPTIM1)
  // scope=self.reg='APB1RSTR', self.shift=9, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_LPTIMER1'}, self.value=1, self.ifdef=['STM32_LPTIM1'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 9);
  rcc_periph_reset(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 9) | (1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB1RSTR', self.shift=11, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_WWDG'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 11);
  rcc_periph_reset(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 11) | (1u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='APB1RSTR', self.shift=14, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SPI2'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 14);
  rcc_periph_reset(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 14) | (1u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='APB1RSTR', self.shift=15, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SPI3'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 15);
  rcc_periph_reset(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 15) | (1u << 15));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='APB1RSTR', self.shift=17, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_USART2'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 17);
  rcc_periph_reset(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 17) | (1u << 17));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_USART3)
  // scope=self.reg='APB1RSTR', self.shift=18, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_USART3'}, self.value=1, self.ifdef=['STM32_USART3'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 18);
  rcc_periph_reset(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 18) | (1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART4)
  // scope=self.reg='APB1RSTR', self.shift=19, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_UART4'}, self.value=1, self.ifdef=['STM32_UART4'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 19);
  rcc_periph_reset(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 19) | (1u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART5)
  // scope=self.reg='APB1RSTR', self.shift=20, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_UART5'}, self.value=1, self.ifdef=['STM32_UART5'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 20);
  rcc_periph_reset(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 20) | (1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB1RSTR', self.shift=21, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_I2C1'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 21);
  rcc_periph_reset(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 21) | (1u << 21));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='APB1RSTR', self.shift=22, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_I2C2'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 22);
  rcc_periph_reset(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 22) | (1u << 22));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_I2C3)
  // scope=self.reg='APB1RSTR', self.shift=23, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_I2C3'}, self.value=1, self.ifdef=['STM32_I2C3'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 23);
  rcc_periph_reset(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 23) | (1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_I2C4)
  // scope=self.reg='APB1RSTR', self.shift=24, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_I2C4'}, self.value=1, self.ifdef=['STM32_I2C4'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 24);
  rcc_periph_reset(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 24) | (1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FMPI2C1)
  // scope=self.reg='APB1RSTR', self.shift=24, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_I2CFMP1'}, self.value=1, self.ifdef=['STM32_FMPI2C1'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 24);
  rcc_periph_reset(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 24) | (1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN1)
  // scope=self.reg='APB1RSTR', self.shift=25, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_CAN1'}, self.value=1, self.ifdef=['STM32_CAN1'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 25);
  rcc_periph_reset(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 25) | (1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN2)
  // scope=self.reg='APB1RSTR', self.shift=26, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_CAN2'}, self.value=1, self.ifdef=['STM32_CAN2'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 26);
  rcc_periph_reset(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 26) | (1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN3)
  // scope=self.reg='APB1RSTR', self.shift=27, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_CAN3'}, self.value=1, self.ifdef=['STM32_CAN3'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 27);
  rcc_periph_reset(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 27) | (1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CEC)
  // scope=self.reg='APB1RSTR', self.shift=27, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_CEC'}, self.value=1, self.ifdef=['STM32_CEC'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 27);
  rcc_periph_reset(RCC_PERIPH_CEC);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 27) | (1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB1RSTR', self.shift=28, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_PWR'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 28);
  rcc_periph_reset(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 28) | (1u << 28));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC)
  // scope=self.reg='APB1RSTR', self.shift=29, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DAC'}, self.value=1, self.ifdef=['STM32_DAC'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 29);
  rcc_periph_reset(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 29) | (1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART7)
  // scope=self.reg='APB1RSTR', self.shift=30, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_UART7'}, self.value=1, self.ifdef=['STM32_UART7'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 30);
  rcc_periph_reset(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 30) | (1u << 30));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART8)
  // scope=self.reg='APB1RSTR', self.shift=31, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_UART8'}, self.value=1, self.ifdef=['STM32_UART8'], self.halt=False
  RCC->APB1RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1RSTR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->APB1RSTR = ~(0u << 31);
  rcc_periph_reset(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1RSTR, ~(0u << 31) | (1u << 31));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB2RSTR', self.shift=0, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM1'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 0);
  rcc_periph_reset(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM8)
  // scope=self.reg='APB2RSTR', self.shift=1, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM8'}, self.value=1, self.ifdef=['STM32_TIM8'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 1);
  rcc_periph_reset(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 1) | (1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB2RSTR', self.shift=4, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_USART1'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 4);
  rcc_periph_reset(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 4) | (1u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='APB2RSTR', self.shift=5, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_USART6'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 5);
  rcc_periph_reset(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 5) | (1u << 5));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_UART9)
  // scope=self.reg='APB2RSTR', self.shift=6, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_UART9'}, self.value=1, self.ifdef=['STM32_UART9'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 6);
  rcc_periph_reset(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 6) | (1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART10)
  // scope=self.reg='APB2RSTR', self.shift=7, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_UART10'}, self.value=1, self.ifdef=['STM32_UART10'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 7);
  rcc_periph_reset(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 7) | (1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB2RSTR', self.shift=8, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_ADC1'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 8);
  rcc_periph_reset(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 8) | (1u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SDIO)
  // scope=self.reg='APB2RSTR', self.shift=11, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SDIO'}, self.value=1, self.ifdef=['STM32_SDIO'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 11);
  rcc_periph_reset(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 11) | (1u << 11));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB2RSTR', self.shift=12, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SPI1'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 12);
  rcc_periph_reset(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 12) | (1u << 12));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SPI4)
  // scope=self.reg='APB2RSTR', self.shift=13, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SPI4'}, self.value=1, self.ifdef=['STM32_SPI4'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 13);
  rcc_periph_reset(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 13) | (1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='APB2RSTR', self.shift=14, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SYSCFG'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 14);
  rcc_periph_reset(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 14) | (1u << 14));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='APB2RSTR', self.shift=16, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM9'}, self.value=1, self.ifdef=[], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 16);
  rcc_periph_reset(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 16) | (1u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM10)
  // scope=self.reg='APB2RSTR', self.shift=17, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM10'}, self.value=1, self.ifdef=['STM32_TIM10'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 17);
  rcc_periph_reset(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 17) | (1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM11)
  // scope=self.reg='APB2RSTR', self.shift=18, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_TIM11'}, self.value=1, self.ifdef=['STM32_TIM11'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 18);
  rcc_periph_reset(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 18) | (1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI5)
  // scope=self.reg='APB2RSTR', self.shift=20, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SPI5'}, self.value=1, self.ifdef=['STM32_SPI5'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 20);
  rcc_periph_reset(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 20) | (1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI6)
  // scope=self.reg='APB2RSTR', self.shift=21, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SPI6'}, self.value=1, self.ifdef=['STM32_SPI6'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 21);
  rcc_periph_reset(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 21) | (1u << 21));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SAI1)
  // scope=self.reg='APB2RSTR', self.shift=22, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SAI1'}, self.value=1, self.ifdef=['STM32_SAI1'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 22);
  rcc_periph_reset(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 22) | (1u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SAI2)
  // scope=self.reg='APB2RSTR', self.shift=23, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_SAI2'}, self.value=1, self.ifdef=['STM32_SAI2'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 23);
  rcc_periph_reset(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 23) | (1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DFSDM1)
  // scope=self.reg='APB2RSTR', self.shift=24, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DFSDM1'}, self.value=1, self.ifdef=['STM32_DFSDM1'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 24);
  rcc_periph_reset(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 24) | (1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DFSDM2)
  // scope=self.reg='APB2RSTR', self.shift=25, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DFSDM2'}, self.value=1, self.ifdef=['STM32_DFSDM2'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 25);
  rcc_periph_reset(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 25) | (1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_LTDC)
  // scope=self.reg='APB2RSTR', self.shift=26, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_LTDC'}, self.value=1, self.ifdef=['STM32_LTDC'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 26);
  rcc_periph_reset(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 26) | (1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DSI)
  // scope=self.reg='APB2RSTR', self.shift=27, self.mask=None, self.varsmap={'peripheral': 'RCC_PERIPH_DSI'}, self.value=1, self.ifdef=['STM32_DSI'], self.halt=False
  RCC->APB2RSTR = 0;
  rcc_periph_reset(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2RSTR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB2RSTR = ~(0u << 27);
  rcc_periph_reset(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2RSTR, ~(0u << 27) | (1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rcc_periph_clock(void)
{
#if defined(STM32_GPIOA)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 1);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 1);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 2);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 2);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 3);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 3);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 4);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 4);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 5);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 5);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 6);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 6);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 7);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 7);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 8);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 8);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 9);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 9);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 10);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 10);
  rcc_periph_clock_disable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 12);
  rcc_periph_clock_enable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 12);
  rcc_periph_clock_disable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_BKPSRAM)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 18);
  rcc_periph_clock_enable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 18);
  rcc_periph_clock_disable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CCMRAM)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CCMDATARAM);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 20);
  rcc_periph_clock_enable(RCC_PERIPH_CCMDATARAM);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 20);
  rcc_periph_clock_disable(RCC_PERIPH_CCMDATARAM);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CCMDATARAM);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 21);
  rcc_periph_clock_enable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 21);
  rcc_periph_clock_disable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());


  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 22);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 22);
  rcc_periph_clock_disable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DMA2D)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 23);
  rcc_periph_clock_enable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 23);
  rcc_periph_clock_disable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 25);
  rcc_periph_clock_enable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 25);
  rcc_periph_clock_disable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 26);
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 26);
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 27);
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 27);
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 28);
  rcc_periph_clock_enable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 28);
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB_OTG_HS)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 29);
  rcc_periph_clock_enable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 29);
  rcc_periph_clock_disable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB_OTG_HSULPI)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 30);
  rcc_periph_clock_enable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 30);
  rcc_periph_clock_disable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 30));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB1)
  RCC->AHB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1ENR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = ~(1u << 31);
  rcc_periph_clock_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = (1u << 31);
  rcc_periph_clock_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1ENR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_DCMI)
  RCC->AHB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_CRYP)
  RCC->AHB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2ENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = ~(1u << 4);
  rcc_periph_clock_enable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = (1u << 4);
  rcc_periph_clock_disable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2ENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_HASH)
  RCC->AHB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2ENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = ~(1u << 5);
  rcc_periph_clock_enable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = (1u << 5);
  rcc_periph_clock_disable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2ENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB2)
  RCC->AHB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2ENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = ~(1u << 6);
  rcc_periph_clock_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = (1u << 6);
  rcc_periph_clock_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2ENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_USB_OTG_FS)
  RCC->AHB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2ENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = ~(1u << 7);
  rcc_periph_clock_enable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = (1u << 7);
  rcc_periph_clock_disable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2ENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FMC)
  RCC->AHB3ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FSMC)
  RCC->AHB3ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_QUADSPI)
  RCC->AHB3ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3ENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = ~(1u << 1);
  rcc_periph_clock_enable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = (1u << 1);
  rcc_periph_clock_disable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3ENR, ~(1u << 1));
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

#if defined(STM32_LPTIM1)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1ENR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 9);
  rcc_periph_clock_enable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 9);
  rcc_periph_clock_disable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_RTC_APB)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1ENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 10);
  rcc_periph_clock_enable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 10);
  rcc_periph_clock_disable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 10));
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

#if defined(STM32_UART3)
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

#if defined(STM32_UART3)
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


#if defined(STM32_I2C3)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1ENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 23);
  rcc_periph_clock_enable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 23);
  rcc_periph_clock_disable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FMPI2C1)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1ENR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 24);
  rcc_periph_clock_enable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 24);
  rcc_periph_clock_disable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_I2C4)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1ENR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 24);
  rcc_periph_clock_enable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 24);
  rcc_periph_clock_disable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 24));
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

#if defined(STM32_CAN3)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1ENR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 27);
  rcc_periph_clock_enable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 27);
  rcc_periph_clock_disable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

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

#if defined(STM32_UART7)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1ENR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 30);
  rcc_periph_clock_enable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 30);
  rcc_periph_clock_disable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 30));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART8)
  RCC->APB1ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1ENR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = ~(1u << 31);
  rcc_periph_clock_enable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = (1u << 31);
  rcc_periph_clock_disable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1ENR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 0);
  rcc_periph_clock_enable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 0);
  rcc_periph_clock_disable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM8)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2ENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 1);
  rcc_periph_clock_enable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 1);
  rcc_periph_clock_disable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 4);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 4);
  rcc_periph_clock_disable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2ENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 5);
  rcc_periph_clock_enable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 5);
  rcc_periph_clock_disable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_UART9)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2ENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 6);
  rcc_periph_clock_enable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 6);
  rcc_periph_clock_disable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART10)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2ENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 7);
  rcc_periph_clock_enable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 7);
  rcc_periph_clock_disable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 8);
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 8);
  rcc_periph_clock_disable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC2)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 9);
  rcc_periph_clock_enable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 9);
  rcc_periph_clock_disable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ADC3)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2ENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 10);
  rcc_periph_clock_enable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 10);
  rcc_periph_clock_disable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

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


#if defined(STM32_SPI4)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2ENR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 13);
  rcc_periph_clock_enable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 13);
  rcc_periph_clock_disable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 14);
  rcc_periph_clock_enable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 14);
  rcc_periph_clock_disable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2ENR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 16);
  rcc_periph_clock_enable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 16);
  rcc_periph_clock_disable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM10)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2ENR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 17);
  rcc_periph_clock_enable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 17);
  rcc_periph_clock_disable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM11)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2ENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 18);
  rcc_periph_clock_enable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 18);
  rcc_periph_clock_disable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI5)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2ENR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 20);
  rcc_periph_clock_enable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 20);
  rcc_periph_clock_disable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI6)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2ENR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 21);
  rcc_periph_clock_enable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 21);
  rcc_periph_clock_disable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SAI1)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 22);
  rcc_periph_clock_enable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 22);
  rcc_periph_clock_disable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SAI2)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2ENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 23);
  rcc_periph_clock_enable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 23);
  rcc_periph_clock_disable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DFSDM1)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2ENR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 24);
  rcc_periph_clock_enable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 24);
  rcc_periph_clock_disable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DFSDM2)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2ENR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 25);
  rcc_periph_clock_enable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 25);
  rcc_periph_clock_disable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_LTDC)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2ENR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 26);
  rcc_periph_clock_enable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 26);
  rcc_periph_clock_disable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DSI)
  RCC->APB2ENR = 0;
  rcc_periph_clock_enable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2ENR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = ~(1u << 27);
  rcc_periph_clock_enable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2ENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = (1u << 27);
  rcc_periph_clock_disable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2ENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2ENR = 0xffffffff;
  rcc_periph_clock_disable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2ENR, ~(1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rcc_periph_clock_low_power(void)
{
#if defined(STM32_GPIOA)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 0);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 0);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOA);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 1);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 1);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOB);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 2);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 2);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOC);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 3);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 3);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOD);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 4);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 4);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOE);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 5);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 5);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOF);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 6);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 6);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOG);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 7);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 7);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOH);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 8);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 8);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOI);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 9);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 9);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOJ);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 10);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 10);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_GPIOK);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 12);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 12);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CRC);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_FLIT);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 15);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_FLIT);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 15);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_FLIT);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_FLIT);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SRAM1);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 16);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SRAM1);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 16);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SRAM1);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SRAM1);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SRAM2)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SRAM2);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 17);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SRAM2);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 17);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SRAM2);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SRAM2);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_BKPSRAM)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 18);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 18);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_BKPSRAM);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SRAM3)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SRAM3);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 19);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SRAM3);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 19);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SRAM3);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SRAM3);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 21);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 21);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DMA1);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());


  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 22);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 22);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DMA2);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DMA2D)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 23);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 23);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DMA2D);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 25);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 25);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMAC);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 26);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 26);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMACTX);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 27);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 27);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMACRX);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ETHERNET_MAC)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 28);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 28);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ETHMACPTP);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB_OTG_HS)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 29);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 29);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_OTG_HS);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB_OTG_HSULPI)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 30);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 30);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_OTG_HS_ULPI);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 30));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB1)
  RCC->AHB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1LPENR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = ~(1u << 31);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = (1u << 31);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB1LPENR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_DCMI)
  RCC->AHB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2LPENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = ~(1u << 0);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = (1u << 0);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DCMI);
  ASSERT_EQ(RCC->AHB2LPENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_CRYP)
  RCC->AHB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2LPENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = ~(1u << 4);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = (1u << 4);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CRYPTO);
  ASSERT_EQ(RCC->AHB2LPENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_HASH)
  RCC->AHB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2LPENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = ~(1u << 5);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = (1u << 5);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_HASH);
  ASSERT_EQ(RCC->AHB2LPENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_AHB2) && defined(STM32_RNG) && defined(STM32_RCC_RNG_AHB2)
  RCC->AHB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2LPENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = ~(1u << 6);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = (1u << 6);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_RNG);
  ASSERT_EQ(RCC->AHB2LPENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_USB_OTG_FS) && defined(STM32_RCC_AHB2)
  RCC->AHB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2LPENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = ~(1u << 7);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = (1u << 7);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_OTG_FS);
  ASSERT_EQ(RCC->AHB2LPENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FMC)
  RCC->AHB3LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3LPENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = ~(1u << 0);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = (1u << 0);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_FMC);
  ASSERT_EQ(RCC->AHB3LPENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FSMC)
  RCC->AHB3LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3LPENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = ~(1u << 0);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = (1u << 0);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_FSMC);
  ASSERT_EQ(RCC->AHB3LPENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_QUADSPI)
  RCC->AHB3LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3LPENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = ~(1u << 1);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = (1u << 1);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->AHB3LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_QUADSPI);
  ASSERT_EQ(RCC->AHB3LPENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 0);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 0);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM2);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 1);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 1);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM3);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 2);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 2);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM4);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM5)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 3);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 3);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM5);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM6)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 4);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 4);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM6);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM7)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 5);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 5);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM7);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM12)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 6);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 6);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM12);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM13)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 7);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 7);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM13);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM14)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 8);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 8);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM14);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_LPTIM1)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 9);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 9);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_LPTIMER1);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_RCC_RTC_APB)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 10);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 10);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_RTCAPB);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 11);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 11);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_WWDG);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 14);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 14);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI2);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_SPI3_LP)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 15);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 15);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI3);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 17);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 17);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART2);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_USART3)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 18);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 18);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART3);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART3)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 19);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 19);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART4);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART3)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 20);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 20);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART5);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 21);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 21);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C1);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());


  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 22);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 22);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C2);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_I2C3)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 23);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 23);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C3);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_FMPI2C1)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 24);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 24);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2CFMP1);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_I2C4)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 24);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 24);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_I2C4);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN1)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 25);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 25);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CAN1);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN2)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 26);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 26);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CAN2);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_CAN3)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 27);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 27);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_CAN3);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 28);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 28);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_PWR);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 29);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 29);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DAC);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 29));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART7)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 30);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 30);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART7);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 30));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART8)
  RCC->APB1LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1LPENR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = ~(1u << 31);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = (1u << 31);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB1LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART8);
  ASSERT_EQ(RCC->APB1LPENR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 0);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 0);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM1);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM8)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 1);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 1);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM8);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 4);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 4);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART1);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 5);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 5);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_USART6);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_UART9)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 6);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 6);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART9);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_UART10)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 7);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 7);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_UART10);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 8);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 8);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ADC1);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC2)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 9);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 9);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ADC2);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ADC3)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 10);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 10);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_ADC3);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SDIO)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 11);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 11);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SDIO);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 12);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 12);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI1);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SPI4)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 13);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 13);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI4);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 14);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 14);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SYSCFG);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 16);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 16);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM9);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM10)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 17);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 17);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM10);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM11)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 18);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 18);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_TIM11);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI5)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 20);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 20);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI5);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SPI6)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 21));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 21);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 21);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SPI6);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SAI1)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 22);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 22);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SAI1);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SAI2)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 23);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 23);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_SAI2);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DFSDM1)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 24);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 24);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DFSDM1);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DFSDM2)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 25);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 25);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DFSDM2);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_LTDC)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 26);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 26);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_LTDC);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DSI)
  RCC->APB2LPENR = 0;
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2LPENR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = ~(1u << 27);
  rcc_periph_clock_low_power_enable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2LPENR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = (1u << 27);
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2LPENR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->APB2LPENR = 0xffffffff;
  rcc_periph_clock_low_power_disable(RCC_PERIPH_DSI);
  ASSERT_EQ(RCC->APB2LPENR, ~(1u << 27));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_rcc_set_rtc_clock_source(void)
{
  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_CLOCK_SOURCE_NOCLOCK'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_NOCLOCK);
  ASSERT_EQ(RCC->BDCR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_NOCLOCK);
  ASSERT_EQ(RCC->BDCR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_CLOCK_SOURCE_LSE'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->BDCR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->BDCR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_CLOCK_SOURCE_LSI'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_LSI);
  ASSERT_EQ(RCC->BDCR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_LSI);
  ASSERT_EQ(RCC->BDCR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDCR', self.shift=8, self.mask='0x3', self.varsmap={'source': 'RCC_RTC_CLOCK_SOURCE_HSE'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->BDCR = 0;
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_HSE);
  ASSERT_EQ(RCC->BDCR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(0x3u << 8);
  rcc_set_rtc_clock_source(RCC_RTC_CLOCK_SOURCE_HSE);
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

#if defined(STM32_RCC_LSEMODE)
void
test_rcc_set_lse_mode(void)
{
  RCC->BDCR = 0;
  rcc_set_lse_mode(RCC_LSE_MODE_HIGH_DRIVE);
  ASSERT_EQ(RCC->BDCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = ~(1u << 3);
  rcc_set_lse_mode(RCC_LSE_MODE_HIGH_DRIVE);
  ASSERT_EQ(RCC->BDCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = (1u << 3);
  rcc_set_lse_mode(RCC_LSE_MODE_LOW_POWER);
  ASSERT_EQ(RCC->BDCR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->BDCR = 0xffffffff;
  rcc_set_lse_mode(RCC_LSE_MODE_LOW_POWER);
  ASSERT_EQ(RCC->BDCR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_rcc_is_reset_flag_set(void)
{
  u32 res;

  RCC->CSR = 0;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_BOR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 25);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_BOR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 25);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_BOR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_BOR);
  ASSERT_EQ(res, (1u << 25));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_PIN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 26);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_PIN);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 26);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_PIN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_PIN);
  ASSERT_EQ(res, (1u << 26));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_POR_PDR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 27);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_POR_PDR);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 27);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_POR_PDR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_POR_PDR);
  ASSERT_EQ(res, (1u << 27));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_SOFTWARE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 28);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_SOFTWARE);
  ASSERT_EQ(res, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 28);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_SOFTWARE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_SOFTWARE);
  ASSERT_EQ(res, (1u << 28));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_INDEPENDENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 29);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_INDEPENDENT);
  ASSERT_EQ(res, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 29);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_INDEPENDENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_INDEPENDENT);
  ASSERT_EQ(res, (1u << 29));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_WINDOW_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 30);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_WINDOW_WATCHDOG);
  ASSERT_EQ(res, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 30);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_WINDOW_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_WINDOW_WATCHDOG);
  ASSERT_EQ(res, (1u << 30));
  ASSERT_FALSE(execution_halted());


  RCC->CSR = 0;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_LOW_POWER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = (1u << 31);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_LOW_POWER);
  ASSERT_EQ(res, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->CSR = ~(1u << 31);
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_LOW_POWER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  RCC->CSR = 0xffffffff;
  res = rcc_is_reset_flag_set(RCC_RESET_FLAG_LOW_POWER);
  ASSERT_EQ(res, (1u << 31));
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

void
test_rcc_set_modulation_period(void)
{
  RCC->SSCGR = 0;
  rcc_set_modulation_period(0);
  ASSERT_EQ(RCC->SSCGR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = 0xffffffff;
  rcc_set_modulation_period(0);
  ASSERT_EQ(RCC->SSCGR, ~(0x1fffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->SSCGR = 0;
  rcc_set_modulation_period(0x1fff);
  ASSERT_EQ(RCC->SSCGR, 0x1fffu << 0);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = 0xffffffff;
  rcc_set_modulation_period(0x1fff);
  ASSERT_EQ(RCC->SSCGR, ~(0x1fffu << 0) | (0x1fffu << 0));
  ASSERT_FALSE(execution_halted());


  RCC->SSCGR = 0;
  rcc_set_modulation_period(0x2000);
  ASSERT_EQ(RCC->SSCGR, 0x2000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->SSCGR = 0xffffffff;
  rcc_set_modulation_period(0x2000);
  ASSERT_EQ(RCC->SSCGR, ~(0x1fffu << 0) | (0x2000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rcc_set_incrementation_step(void)
{
  RCC->SSCGR = 0;
  rcc_set_incrementation_step(0);
  ASSERT_EQ(RCC->SSCGR, 0u << 13);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = 0xffffffff;
  rcc_set_incrementation_step(0);
  ASSERT_EQ(RCC->SSCGR, ~(0x7fffu << 13) | (0u << 13));
  ASSERT_FALSE(execution_halted());


  RCC->SSCGR = 0;
  rcc_set_incrementation_step(0x7fff);
  ASSERT_EQ(RCC->SSCGR, 0x7fffu << 13);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = 0xffffffff;
  rcc_set_incrementation_step(0x7fff);
  ASSERT_EQ(RCC->SSCGR, ~(0x7fffu << 13) | (0x7fffu << 13));
  ASSERT_FALSE(execution_halted());


  RCC->SSCGR = 0;
  rcc_set_incrementation_step(0x8000);
  ASSERT_EQ(RCC->SSCGR, 0x8000u << 13);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->SSCGR = 0xffffffff;
  rcc_set_incrementation_step(0x8000);
  ASSERT_EQ(RCC->SSCGR, ~(0x7fffu << 13) | (0x8000u << 13));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_rcc_set_spread(void)
{
  RCC->SSCGR = 0;
  rcc_set_spread(RCC_SPREAD_DOWN);
  ASSERT_EQ(RCC->SSCGR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = ~(1u << 30);
  rcc_set_spread(RCC_SPREAD_DOWN);
  ASSERT_EQ(RCC->SSCGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = (1u << 30);
  rcc_set_spread(RCC_SPREAD_CENTER);
  ASSERT_EQ(RCC->SSCGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = 0xffffffff;
  rcc_set_spread(RCC_SPREAD_CENTER);
  ASSERT_EQ(RCC->SSCGR, 0xffffffff & ~(1u << 30));
  ASSERT_FALSE(execution_halted());

}

void
test_rcc_spread_spectrum_modulation(void)
{
  RCC->SSCGR = 0;
  rcc_spread_spectrum_modulation_enable();
  ASSERT_EQ(RCC->SSCGR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = ~(1u << 31);
  rcc_spread_spectrum_modulation_enable();
  ASSERT_EQ(RCC->SSCGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = (1u << 31);
  rcc_spread_spectrum_modulation_disable();
  ASSERT_EQ(RCC->SSCGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->SSCGR = 0xffffffff;
  rcc_spread_spectrum_modulation_disable();
  ASSERT_EQ(RCC->SSCGR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_FACTORM)
void
test_rcc_set_plli2s_factorM(void)
{
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorM(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, 0u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorM(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3fu << 0) | (0u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorM(1);
  ASSERT_EQ(RCC->PLLI2SCFGR, 1u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorM(1);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3fu << 0) | (1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorM(2);
  ASSERT_EQ(RCC->PLLI2SCFGR, 2u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorM(2);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3fu << 0) | (2u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorM(63);
  ASSERT_EQ(RCC->PLLI2SCFGR, 63u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorM(63);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3fu << 0) | (63u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorM(64);
  ASSERT_EQ(RCC->PLLI2SCFGR, 64u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorM(64);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3fu << 0) | (64u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLI2S)
void
test_rcc_set_plli2s_factorN(void)
{
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorN(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, 0u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorN(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x1ffu << 6) | (0u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorN(49);
  ASSERT_EQ(RCC->PLLI2SCFGR, 49u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorN(49);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x1ffu << 6) | (49u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorN(50);
  ASSERT_EQ(RCC->PLLI2SCFGR, 50u << 6);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorN(50);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x1ffu << 6) | (50u << 6));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorN(432);
  ASSERT_EQ(RCC->PLLI2SCFGR, 432u << 6);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorN(432);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x1ffu << 6) | (432u << 6));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorN(433);
  ASSERT_EQ(RCC->PLLI2SCFGR, 433u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorN(433);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x1ffu << 6) | (433u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_FACTORP)
void
test_rcc_set_plli2s_factorP(void)
{
  // scope=self.reg='PLLI2SCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLI2S_FACTORP_DIV2'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV2);
  ASSERT_EQ(RCC->PLLI2SCFGR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = ~(0x3u << 16);
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV2);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLI2SCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLI2S_FACTORP_DIV4'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV4);
  ASSERT_EQ(RCC->PLLI2SCFGR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = ~(0x3u << 16);
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV4);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLI2SCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLI2S_FACTORP_DIV6'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV6);
  ASSERT_EQ(RCC->PLLI2SCFGR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = ~(0x3u << 16);
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV6);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLI2SCFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLI2S_FACTORP_DIV8'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV8);
  ASSERT_EQ(RCC->PLLI2SCFGR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = ~(0x3u << 16);
  rcc_set_plli2s_factorP(RCC_PLLI2S_FACTORP_DIV8);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_FACTORQ)
void
test_rcc_set_plli2s_factorQ(void)
{
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorQ(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, 0u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorQ(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0xfu << 24) | (0u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorQ(1);
  ASSERT_EQ(RCC->PLLI2SCFGR, 1u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorQ(1);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0xfu << 24) | (1u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorQ(2);
  ASSERT_EQ(RCC->PLLI2SCFGR, 2u << 24);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorQ(2);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0xfu << 24) | (2u << 24));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorQ(15);
  ASSERT_EQ(RCC->PLLI2SCFGR, 15u << 24);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorQ(15);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0xfu << 24) | (15u << 24));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorQ(16);
  ASSERT_EQ(RCC->PLLI2SCFGR, 16u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorQ(16);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0xfu << 24) | (16u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLI2S)
void
test_rcc_set_plli2s_factorR(void)
{
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorR(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, 0u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorR(0);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x7u << 28) | (0u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorR(1);
  ASSERT_EQ(RCC->PLLI2SCFGR, 1u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorR(1);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x7u << 28) | (1u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorR(2);
  ASSERT_EQ(RCC->PLLI2SCFGR, 2u << 28);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorR(2);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x7u << 28) | (2u << 28));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorR(7);
  ASSERT_EQ(RCC->PLLI2SCFGR, 7u << 28);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorR(7);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x7u << 28) | (7u << 28));
  ASSERT_FALSE(execution_halted());


  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_factorR(8);
  ASSERT_EQ(RCC->PLLI2SCFGR, 8u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_factorR(8);
  ASSERT_EQ(RCC->PLLI2SCFGR, ~(0x7u << 28) | (8u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_CLOCK_SOURCE)
void
test_rcc_set_plli2s_clock_source(void)
{
  RCC->PLLI2SCFGR = 0;
  rcc_set_plli2s_clock_source(RCC_PLLI2S_CLOCK_SOURCE_EXTERNAL_AFI);
  ASSERT_EQ(RCC->PLLI2SCFGR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = ~(1u << 22);
  rcc_set_plli2s_clock_source(RCC_PLLI2S_CLOCK_SOURCE_EXTERNAL_AFI);
  ASSERT_EQ(RCC->PLLI2SCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = (1u << 22);
  rcc_set_plli2s_clock_source(RCC_PLLI2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->PLLI2SCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLI2SCFGR = 0xffffffff;
  rcc_set_plli2s_clock_source(RCC_PLLI2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->PLLI2SCFGR, 0xffffffff & ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_PLLSAI) && defined(STM32_RCC_PLLSAI_FACTORM)
void
test_rcc_set_pllsai_factorM(void)
{
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorM(0);
  ASSERT_EQ(RCC->PLLSAICFGR, 0u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorM(0);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3fu << 0) | (0u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorM(1);
  ASSERT_EQ(RCC->PLLSAICFGR, 1u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorM(1);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3fu << 0) | (1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorM(2);
  ASSERT_EQ(RCC->PLLSAICFGR, 2u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorM(2);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3fu << 0) | (2u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorM(63);
  ASSERT_EQ(RCC->PLLSAICFGR, 63u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorM(63);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3fu << 0) | (63u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorM(64);
  ASSERT_EQ(RCC->PLLSAICFGR, 64u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorM(64);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3fu << 0) | (64u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLSAI)
void
test_rcc_set_pllsai_factorN(void)
{
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorN(0);
  ASSERT_EQ(RCC->PLLSAICFGR, 0u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorN(0);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x1ffu << 6) | (0u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorN(49);
  ASSERT_EQ(RCC->PLLSAICFGR, 49u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorN(49);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x1ffu << 6) | (49u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorN(50);
  ASSERT_EQ(RCC->PLLSAICFGR, 50u << 6);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorN(50);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x1ffu << 6) | (50u << 6));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorN(432);
  ASSERT_EQ(RCC->PLLSAICFGR, 432u << 6);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorN(432);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x1ffu << 6) | (432u << 6));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorN(433);
  ASSERT_EQ(RCC->PLLSAICFGR, 433u << 6);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorN(433);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x1ffu << 6) | (433u << 6));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLSAI) && defined(STM32_RCC_PLLSAI_FACTORP)
void
test_rcc_set_pllsai_factorP(void)
{
  // scope=self.reg='PLLSAICFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLSAI_FACTORP_DIV2'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV2);
  ASSERT_EQ(RCC->PLLSAICFGR, (0b00u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = ~(0x3u << 16);
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV2);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3u << 16) | (0b00u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLSAICFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLSAI_FACTORP_DIV4'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV4);
  ASSERT_EQ(RCC->PLLSAICFGR, (0b01u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = ~(0x3u << 16);
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV4);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3u << 16) | (0b01u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLSAICFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLSAI_FACTORP_DIV6'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV6);
  ASSERT_EQ(RCC->PLLSAICFGR, (0b10u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = ~(0x3u << 16);
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV6);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3u << 16) | (0b10u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='PLLSAICFGR', self.shift=16, self.mask='0x3', self.varsmap={'factor': 'RCC_PLLSAI_FACTORP_DIV8'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV8);
  ASSERT_EQ(RCC->PLLSAICFGR, (0b11u << 16));
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = ~(0x3u << 16);
  rcc_set_pllsai_factorP(RCC_PLLSAI_FACTORP_DIV8);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x3u << 16) | (0b11u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_PLLSAI)
void
test_rcc_set_pllsai_factorQ(void)
{
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorQ(0);
  ASSERT_EQ(RCC->PLLSAICFGR, 0u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorQ(0);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0xfu << 24) | (0u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorQ(1);
  ASSERT_EQ(RCC->PLLSAICFGR, 1u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorQ(1);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0xfu << 24) | (1u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorQ(2);
  ASSERT_EQ(RCC->PLLSAICFGR, 2u << 24);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorQ(2);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0xfu << 24) | (2u << 24));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorQ(15);
  ASSERT_EQ(RCC->PLLSAICFGR, 15u << 24);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorQ(15);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0xfu << 24) | (15u << 24));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorQ(16);
  ASSERT_EQ(RCC->PLLSAICFGR, 16u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorQ(16);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0xfu << 24) | (16u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLSAI) && defined(STM32_RCC_PLLSAI_FACTORR)
void
test_rcc_set_pllsai_factorR(void)
{
  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorR(0);
  ASSERT_EQ(RCC->PLLSAICFGR, 0u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorR(0);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x7u << 28) | (0u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorR(1);
  ASSERT_EQ(RCC->PLLSAICFGR, 1u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorR(1);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x7u << 28) | (1u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorR(2);
  ASSERT_EQ(RCC->PLLSAICFGR, 2u << 28);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorR(2);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x7u << 28) | (2u << 28));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorR(7);
  ASSERT_EQ(RCC->PLLSAICFGR, 7u << 28);
  ASSERT_FALSE(execution_halted());

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorR(7);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x7u << 28) | (7u << 28));
  ASSERT_FALSE(execution_halted());


  RCC->PLLSAICFGR = 0;
  rcc_set_pllsai_factorR(8);
  ASSERT_EQ(RCC->PLLSAICFGR, 8u << 28);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->PLLSAICFGR = 0xffffffff;
  rcc_set_pllsai_factorR(8);
  ASSERT_EQ(RCC->PLLSAICFGR, ~(0x7u << 28) | (8u << 28));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLI2S_DIVQ)
void
test_rcc_set_plli2s_dividerQ(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_plli2s_dividerQ(0);
  ASSERT_EQ(RCC->DCKCFGR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_plli2s_dividerQ(0);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_plli2s_dividerQ(0x1f);
  ASSERT_EQ(RCC->DCKCFGR, 0x1fu << 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_plli2s_dividerQ(0x1f);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 0) | (0x1fu << 0));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_plli2s_dividerQ(0x20);
  ASSERT_EQ(RCC->DCKCFGR, 0x20u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_plli2s_dividerQ(0x20);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 0) | (0x20u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLI2S_DIVR)
void
test_rcc_set_plli2s_dividerR(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_plli2s_dividerR(0);
  ASSERT_EQ(RCC->DCKCFGR, 0u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_plli2s_dividerR(0);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 0) | (0u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  RCC->DCKCFGR = 0;
  rcc_set_plli2s_dividerR(1);
  ASSERT_EQ(RCC->DCKCFGR, 1u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_plli2s_dividerR(1);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_plli2s_dividerR(31);
  ASSERT_EQ(RCC->DCKCFGR, 31u << 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_plli2s_dividerR(31);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 0) | (31u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_plli2s_dividerR(32);
  ASSERT_EQ(RCC->DCKCFGR, 32u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_plli2s_dividerR(32);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 0) | (32u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLLSAI_DIVQ)
void
test_rcc_set_pllsai_dividerQ(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_pllsai_dividerQ(0);
  ASSERT_EQ(RCC->DCKCFGR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pllsai_dividerQ(0);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_pllsai_dividerQ(0x1f);
  ASSERT_EQ(RCC->DCKCFGR, 0x1fu << 8);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pllsai_dividerQ(0x1f);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 8) | (0x1fu << 8));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_pllsai_dividerQ(0x20);
  ASSERT_EQ(RCC->DCKCFGR, 0x20u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pllsai_dividerQ(0x20);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 8) | (0x20u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_PLL_DIVR)
void
test_rcc_set_pll_dividerR(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_pll_dividerR(0);
  ASSERT_EQ(RCC->DCKCFGR, 0u << 9);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pll_dividerR(0);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 9) | (0u << 9));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_pll_dividerR(0x1f);
  ASSERT_EQ(RCC->DCKCFGR, 0x1fu << 9);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pll_dividerR(0x1f);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 9) | (0x1fu << 9));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_pll_dividerR(0x20);
  ASSERT_EQ(RCC->DCKCFGR, 0x20u << 9);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pll_dividerR(0x20);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x1fu << 9) | (0x20u << 9));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_DFSDM2)
void
test_rcc_set_dfsdm2_audio_clock_source(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_dfsdm2_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB2);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 14);
  rcc_set_dfsdm2_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB2);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 14);
  rcc_set_dfsdm2_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB1);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_dfsdm2_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB1);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_DFSDM1)
void
test_rcc_set_dfsdm1_audio_clock_source(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_dfsdm1_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB2);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 15);
  rcc_set_dfsdm1_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB2);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 15);
  rcc_set_dfsdm1_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB1);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_dfsdm1_audio_clock_source(RCC_DFSDM_AUDIO_CLOCK_SOURCE_APB1);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_PLLSAI_DIVR)
void
test_rcc_set_pllsai_dividerR(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_pllsai_dividerR(0);
  ASSERT_EQ(RCC->DCKCFGR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pllsai_dividerR(0);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_pllsai_dividerR(0x3);
  ASSERT_EQ(RCC->DCKCFGR, 0x3u << 16);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pllsai_dividerR(0x3);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 16) | (0x3u << 16));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_set_pllsai_dividerR(0x4);
  ASSERT_EQ(RCC->DCKCFGR, 0x4u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_pllsai_dividerR(0x4);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 16) | (0x4u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_RCC_SAI1)
void
test_rcc_set_sai1_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1_CLOCK_SOURCE_PLLSAIQ'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b00u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1_CLOCK_SOURCE_PLLI2SQ'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b01u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1_CLOCK_SOURCE_PLLR'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b10u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1_CLOCK_SOURCE_ALTIN'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1_clock_source(RCC_SAI1_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b11u << 20));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_SAI1A) && defined(STM32_RCC_SAI1ASRC_LAYOUT1)
void
test_rcc_set_sai1a_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1A_CLOCK_SOURCE_PLLI2SR'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b00u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1A_CLOCK_SOURCE_I2SCLIN'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_I2SCLIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_I2SCLIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b01u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1A_CLOCK_SOURCE_PLLR'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b10u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1A_CLOCK_SOURCE_HSCK'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_HSCK);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_HSCK);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b11u << 20));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_SAI1A) && defined(STM32_RCC_SAI1ASRC_LAYOUT2)
void
test_rcc_set_sai1a_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1A_CLOCK_SOURCE_PLLSAIQ'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b00u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1A_CLOCK_SOURCE_PLLI2SQ'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b01u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=20, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1A_CLOCK_SOURCE_ALTIN'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 20));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 20);
  rcc_set_sai1a_clock_source(RCC_SAI1A_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 20) | (0b10u << 20));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_SAI2)
void
test_rcc_set_sai2_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_PLLSAIQ'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b00u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_PLLI2SQ'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b01u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_PLLR'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b10u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_PLLSRC'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai2_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b11u << 22));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_SAI1B) && defined(STM32_RCC_SAI1BSRC_LAYOUT1)
void
test_rcc_set_sai1b_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_PLLI2SR'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b00u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_I2SCLIN'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_I2SCLIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_I2SCLIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b01u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_PLLR'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b10u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI2_CLOCK_SOURCE_HSCK'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_HSCK);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai1b_clock_source(RCC_SAI2_CLOCK_SOURCE_HSCK);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b11u << 22));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_SAI1B) && defined(STM32_RCC_SAI1BSRC_LAYOUT2)
void
test_rcc_set_sai1b_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1B_CLOCK_SOURCE_PLLSAIQ'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1b_clock_source(RCC_SAI1B_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai1b_clock_source(RCC_SAI1B_CLOCK_SOURCE_PLLSAIQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b00u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1B_CLOCK_SOURCE_PLLI2SQ'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1b_clock_source(RCC_SAI1B_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai1b_clock_source(RCC_SAI1B_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b01u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_SAI1B_CLOCK_SOURCE_ALTIN'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_sai1b_clock_source(RCC_SAI1B_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 22);
  rcc_set_sai1b_clock_source(RCC_SAI1B_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 22) | (0b10u << 22));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_TIMPRE)
void
test_rcc_set_timers_prescaler(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_timers_prescaler(RCC_TIMERS_PRESCALER_x4);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 24);
  rcc_set_timers_prescaler(RCC_TIMERS_PRESCALER_x4);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 24);
  rcc_set_timers_prescaler(RCC_TIMERS_PRESCALER_x2);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_timers_prescaler(RCC_TIMERS_PRESCALER_x2);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff & ~(1u << 24));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_CLOCK_48MHZ) && defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR_LAYOUT1)
void
test_rcc_set_48Mhz_clock_source(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLSAI);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 27);
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLSAI);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 27);
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLL);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLL);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff & ~(1u << 27));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_CLOCK_48MHZ) && defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT1)
void
test_rcc_set_48Mhz_clock_source(void)
{
  RCC->DCKCFGR2 = 0;
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR2, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(1u << 27);
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLI2SQ);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = (1u << 27);
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLQ);
  ASSERT_EQ(RCC->DCKCFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = 0xffffffff;
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLQ);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff & ~(1u << 27));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_CLOCK_48MHZ) && defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT2)
void
test_rcc_set_48Mhz_clock_source(void)
{
  RCC->DCKCFGR2 = 0;
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLSAIP);
  ASSERT_EQ(RCC->DCKCFGR2, (1u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(1u << 27);
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLSAIP);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = (1u << 27);
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLQ);
  ASSERT_EQ(RCC->DCKCFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = 0xffffffff;
  rcc_set_48Mhz_clock_source(RCC_48MHZ_CLOCK_SOURCE_PLLQ);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff & ~(1u << 27));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SDIO) && defined(STM32_RCC_SDIOCK_DCKCFGR)
void
test_rcc_set_sdio_clock_source(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 28);
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 28);
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_48MHZ);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_48MHZ);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff & ~(1u << 28));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SDIO) && defined(STM32_RCC_SDIOCK_DCKCFGR2)
void
test_rcc_set_sdio_clock_source(void)
{
  RCC->DCKCFGR2 = 0;
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->DCKCFGR2, (1u << 28));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(1u << 28);
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = (1u << 28);
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_48MHZ);
  ASSERT_EQ(RCC->DCKCFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = 0xffffffff;
  rcc_set_sdio_clock_source(RCC_SDIO_CLOCK_SOURCE_48MHZ);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff & ~(1u << 28));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_DSI_HOST)
void
test_rcc_set_dsi_clock_source(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_dsi_clock_source(RCC_DSI_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 29);
  rcc_set_dsi_clock_source(RCC_DSI_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 29);
  rcc_set_dsi_clock_source(RCC_DSI_CLOCK_SOURCE_DSI_PHY);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_dsi_clock_source(RCC_DSI_CLOCK_SOURCE_DSI_PHY);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff & ~(1u << 29));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_I2S1) && defined(STM32_RCC_I2SSRC_LAYOUT1)
void
test_rcc_set_i2s1_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=25, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLR'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 25);
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 25) | (0b00u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=25, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_ALTIN'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 25);
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 25) | (0b01u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=25, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLSRC'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 25);
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 25) | (0b11u << 25));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_I2S1) && defined(STM32_RCC_I2SSRC_LAYOUT2)
void
test_rcc_set_i2s1_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=25, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLI2SR'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 25);
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 25) | (0b00u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=25, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_I2CCKIN'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_I2CCKIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 25);
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_I2CCKIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 25) | (0b01u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=25, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLR'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 25);
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 25) | (0b10u << 25));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=25, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLSR'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSR);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 25));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 25);
  rcc_set_i2s1_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 25) | (0b11u << 25));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_I2S2) && defined(STM32_RCC_I2SSRC_LAYOUT1)
void
test_rcc_set_i2s2_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=27, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLR'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 27);
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 27) | (0b00u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=27, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_ALTIN'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 27);
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_ALTIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 27) | (0b01u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=27, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLSRC'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 27);
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 27) | (0b11u << 27));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_RCC_I2S2) && defined(STM32_RCC_I2SSRC_LAYOUT2)
void
test_rcc_set_i2s2_clock_source(void)
{
  // scope=self.reg='DCKCFGR', self.shift=27, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLI2SR'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, (0b00u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 27);
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLI2SR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 27) | (0b00u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=27, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_I2CCKIN'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_I2CCKIN);
  ASSERT_EQ(RCC->DCKCFGR, (0b01u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 27);
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_I2CCKIN);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 27) | (0b01u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=27, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLR'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, (0b10u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 27);
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 27) | (0b10u << 27));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR', self.shift=27, self.mask='0x3', self.varsmap={'source': 'RCC_I2S_CLOCK_SOURCE_PLLSRC'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR = 0;
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, (0b11u << 27));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(0x3u << 27);
  rcc_set_i2s2_clock_source(RCC_I2S_CLOCK_SOURCE_PLLSRC);
  ASSERT_EQ(RCC->DCKCFGR, ~(0x3u << 27) | (0b11u << 27));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_DFSDM_KERNEL_CKSRC)
void
test_rcc_set_dfsdm_kernel_clock_source(void)
{
  RCC->DCKCFGR = 0;
  rcc_set_dfsdm_kernel_clock_source(RCC_DFSDM_KERNEL_CLOCK_SOURCE_SYSCLOCK);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 31);
  rcc_set_dfsdm_kernel_clock_source(RCC_DFSDM_KERNEL_CLOCK_SOURCE_SYSCLOCK);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 31);
  rcc_set_dfsdm_kernel_clock_source(RCC_DFSDM_KERNEL_CLOCK_SOURCE_APB2);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_set_dfsdm_kernel_clock_source(RCC_DFSDM_KERNEL_CLOCK_SOURCE_APB2);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff & ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_RCC_CKGATE)
void
test_rcc_gate_clock(void)
{
  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_AHB_to_APB1);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 0);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_AHB_to_APB1);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 0);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_AHB_to_APB1);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_AHB_to_APB1);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_AHB_to_APB2);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 1);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_AHB_to_APB2);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 1);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_AHB_to_APB2);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_AHB_to_APB2);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_CM4);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 2);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_CM4);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 2);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_CM4);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_CM4);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_SPARE);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 3);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_SPARE);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 3);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_SPARE);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_SPARE);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_SRAM);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 4);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_SRAM);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 4);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_SRAM);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_SRAM);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_FLASH);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 5);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_FLASH);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 5);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_FLASH);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_FLASH);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_RCC);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 6);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_RCC);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 6);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_RCC);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_RCC);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_RCC_CKGATE_EVT)
  RCC->DCKCFGR = 0;
  rcc_gate_clock_enable(RCC_GATE_CLOCK_EVENT);
  ASSERT_EQ(RCC->DCKCFGR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = ~(1u << 7);
  rcc_gate_clock_enable(RCC_GATE_CLOCK_EVENT);
  ASSERT_EQ(RCC->DCKCFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = (1u << 7);
  rcc_gate_clock_disable(RCC_GATE_CLOCK_EVENT);
  ASSERT_EQ(RCC->DCKCFGR, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR = 0xffffffff;
  rcc_gate_clock_disable(RCC_GATE_CLOCK_EVENT);
  ASSERT_EQ(RCC->DCKCFGR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_FMPI2C1)
void
test_rcc_set_i2c_fmp1_clock_source(void)
{
  // scope=self.reg='DCKCFGR2', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_I2CFMP_CLOCK_SOURCE_APB1'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR2 = 0;
  rcc_set_i2c_fmp1_clock_source(RCC_I2CFMP_CLOCK_SOURCE_APB1);
  ASSERT_EQ(RCC->DCKCFGR2, (0b00u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(0x3u << 22);
  rcc_set_i2c_fmp1_clock_source(RCC_I2CFMP_CLOCK_SOURCE_APB1);
  ASSERT_EQ(RCC->DCKCFGR2, ~(0x3u << 22) | (0b00u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR2', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_I2CFMP_CLOCK_SOURCE_SYSCLK'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR2 = 0;
  rcc_set_i2c_fmp1_clock_source(RCC_I2CFMP_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->DCKCFGR2, (0b01u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(0x3u << 22);
  rcc_set_i2c_fmp1_clock_source(RCC_I2CFMP_CLOCK_SOURCE_SYSCLK);
  ASSERT_EQ(RCC->DCKCFGR2, ~(0x3u << 22) | (0b01u << 22));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR2', self.shift=22, self.mask='0x3', self.varsmap={'source': 'RCC_I2CFMP_CLOCK_SOURCE_HSI'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR2 = 0;
  rcc_set_i2c_fmp1_clock_source(RCC_I2CFMP_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->DCKCFGR2, (0b10u << 22));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(0x3u << 22);
  rcc_set_i2c_fmp1_clock_source(RCC_I2CFMP_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->DCKCFGR2, ~(0x3u << 22) | (0b10u << 22));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_CEC)
void
test_rcc_set_cec_clock_source(void)
{
  RCC->DCKCFGR2 = 0;
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->DCKCFGR2, (1u << 26));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(1u << 26);
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = (1u << 26);
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->DCKCFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = 0xffffffff;
  rcc_set_cec_clock_source(RCC_CEC_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff & ~(1u << 26));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SPDIFRX)
void
test_rcc_set_spdifrx_clock_source(void)
{
  RCC->DCKCFGR2 = 0;
  rcc_set_spdifrx_clock_source(RCC_SPDIFRX_CLOCK_SOURCE_PLLI2SP);
  ASSERT_EQ(RCC->DCKCFGR2, (1u << 29));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(1u << 29);
  rcc_set_spdifrx_clock_source(RCC_SPDIFRX_CLOCK_SOURCE_PLLI2SP);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = (1u << 29);
  rcc_set_spdifrx_clock_source(RCC_SPDIFRX_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR2, 0);
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = 0xffffffff;
  rcc_set_spdifrx_clock_source(RCC_SPDIFRX_CLOCK_SOURCE_PLLR);
  ASSERT_EQ(RCC->DCKCFGR2, 0xffffffff & ~(1u << 29));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_LPTIM1)
void
test_rcc_set_lptimer1_clock_source(void)
{
  // scope=self.reg='DCKCFGR2', self.shift=30, self.mask='0x3', self.varsmap={'source': 'RCC_LPTIMER1_CLOCK_SOURCE_APB'}, self.value='0b00', self.ifdef=[], self.halt=False
  RCC->DCKCFGR2 = 0;
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_APB);
  ASSERT_EQ(RCC->DCKCFGR2, (0b00u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(0x3u << 30);
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_APB);
  ASSERT_EQ(RCC->DCKCFGR2, ~(0x3u << 30) | (0b00u << 30));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR2', self.shift=30, self.mask='0x3', self.varsmap={'source': 'RCC_LPTIMER1_CLOCK_SOURCE_HSI'}, self.value='0b01', self.ifdef=[], self.halt=False
  RCC->DCKCFGR2 = 0;
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->DCKCFGR2, (0b01u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(0x3u << 30);
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_HSI);
  ASSERT_EQ(RCC->DCKCFGR2, ~(0x3u << 30) | (0b01u << 30));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR2', self.shift=30, self.mask='0x3', self.varsmap={'source': 'RCC_LPTIMER1_CLOCK_SOURCE_LSI'}, self.value='0b10', self.ifdef=[], self.halt=False
  RCC->DCKCFGR2 = 0;
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_LSI);
  ASSERT_EQ(RCC->DCKCFGR2, (0b10u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(0x3u << 30);
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_LSI);
  ASSERT_EQ(RCC->DCKCFGR2, ~(0x3u << 30) | (0b10u << 30));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCKCFGR2', self.shift=30, self.mask='0x3', self.varsmap={'source': 'RCC_LPTIMER1_CLOCK_SOURCE_LSE'}, self.value='0b11', self.ifdef=[], self.halt=False
  RCC->DCKCFGR2 = 0;
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->DCKCFGR2, (0b11u << 30));
  ASSERT_FALSE(execution_halted());

  RCC->DCKCFGR2 = ~(0x3u << 30);
  rcc_set_lptimer1_clock_source(RCC_LPTIMER1_CLOCK_SOURCE_LSE);
  ASSERT_EQ(RCC->DCKCFGR2, ~(0x3u << 30) | (0b11u << 30));
  ASSERT_FALSE(execution_halted());


}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_rcc_osc),
    TEST_FUNC(test_rcc_is_osc_ready),
    TEST_FUNC(test_rcc_set_hsi_trim),
    TEST_FUNC(test_rcc_get_hsi_cal),
    TEST_FUNC(test_rcc_hse_bypass),
    TEST_FUNC(test_rcc_css),
    TEST_FUNC(test_rcc_set_main_pll_factorM),
    TEST_FUNC(test_rcc_set_main_pll_factorN),
    TEST_FUNC(test_rcc_set_main_pll_factorP),
    TEST_FUNC(test_rcc_set_main_pll_factorQ),
#if defined(STM32_RCC_PLLR)
    TEST_FUNC(test_rcc_set_main_pll_factorR),
#endif
    TEST_FUNC(test_rcc_set_main_pll_source),
    TEST_FUNC(test_rcc_set_system_clock_source),
    TEST_FUNC(test_rcc_get_system_clock_source),
    TEST_FUNC(test_rcc_set_ahb_prescaler),
#if defined(STM32_RCC_MCOEN)
    TEST_FUNC(test_rcc_mco),
#endif
    TEST_FUNC(test_rcc_set_apb1_prescaler),
    TEST_FUNC(test_rcc_set_apb2_prescaler),
    TEST_FUNC(test_rcc_set_rtc_prescaler),
    TEST_FUNC(test_rcc_set_mco1),
#if defined(STM32_RCC_I2S)
    TEST_FUNC(test_rcc_set_i2s_clock_source),
#endif
    TEST_FUNC(test_rcc_set_mco1_prescaler),
    TEST_FUNC(test_rcc_set_mco2_prescaler),
    TEST_FUNC(test_rcc_set_mco2),
    TEST_FUNC(test_rcc_is_flag_set),
    TEST_FUNC(test_rcc_flag_clear),
    TEST_FUNC(test_rcc_interrupt),
    TEST_FUNC(test_rcc_periph_reset),
    TEST_FUNC(test_rcc_periph_clock),
    TEST_FUNC(test_rcc_periph_clock_low_power),
    TEST_FUNC(test_rcc_set_rtc_clock_source),
    TEST_FUNC(test_rcc_lse_bypass),
#if defined(STM32_RCC_LSEMODE)
    TEST_FUNC(test_rcc_set_lse_mode),
#endif
    TEST_FUNC(test_rcc_is_reset_flag_set),
    TEST_FUNC(test_rcc_reset_flags_clear),
    TEST_FUNC(test_rcc_set_modulation_period),
    TEST_FUNC(test_rcc_set_incrementation_step),
    TEST_FUNC(test_rcc_set_spread),
    TEST_FUNC(test_rcc_spread_spectrum_modulation),
#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_FACTORM)
    TEST_FUNC(test_rcc_set_plli2s_factorM),
#endif
#if defined(STM32_RCC_PLLI2S)
    TEST_FUNC(test_rcc_set_plli2s_factorN),
#endif
#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_FACTORP)
    TEST_FUNC(test_rcc_set_plli2s_factorP),
#endif
#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_FACTORQ)
    TEST_FUNC(test_rcc_set_plli2s_factorQ),
#endif
#if defined(STM32_RCC_PLLI2S)
    TEST_FUNC(test_rcc_set_plli2s_factorR),
#endif
#if defined(STM32_RCC_PLLI2S) && defined(STM32_RCC_PLLI2S_CLOCK_SOURCE)
    TEST_FUNC(test_rcc_set_plli2s_clock_source),
#endif
#if defined(STM32_RCC_PLLSAI) && defined(STM32_RCC_PLLSAI_FACTORM)
    TEST_FUNC(test_rcc_set_pllsai_factorM),
#endif
#if defined(STM32_RCC_PLLSAI)
    TEST_FUNC(test_rcc_set_pllsai_factorN),
#endif
#if defined(STM32_RCC_PLLSAI) && defined(STM32_RCC_PLLSAI_FACTORP)
    TEST_FUNC(test_rcc_set_pllsai_factorP),
#endif
#if defined(STM32_RCC_PLLSAI)
    TEST_FUNC(test_rcc_set_pllsai_factorQ),
#endif
#if defined(STM32_RCC_PLLSAI) && defined(STM32_RCC_PLLSAI_FACTORR)
    TEST_FUNC(test_rcc_set_pllsai_factorR),
#endif
#if defined(STM32_RCC_PLLI2S_DIVQ)
    TEST_FUNC(test_rcc_set_plli2s_dividerQ),
#endif
#if defined(STM32_RCC_PLLI2S_DIVR)
    TEST_FUNC(test_rcc_set_plli2s_dividerR),
#endif
#if defined(STM32_RCC_PLLSAI_DIVQ)
    TEST_FUNC(test_rcc_set_pllsai_dividerQ),
#endif
#if defined(STM32_RCC_PLL_DIVR)
    TEST_FUNC(test_rcc_set_pll_dividerR),
#endif
#if defined(STM32_DFSDM2)
    TEST_FUNC(test_rcc_set_dfsdm2_audio_clock_source),
#endif
#if defined(STM32_DFSDM1)
    TEST_FUNC(test_rcc_set_dfsdm1_audio_clock_source),
#endif
#if defined(STM32_RCC_PLLSAI_DIVR)
    TEST_FUNC(test_rcc_set_pllsai_dividerR),
#endif
#if defined(STM32_RCC_SAI1)
    TEST_FUNC(test_rcc_set_sai1_clock_source),
#endif
#if defined(STM32_RCC_SAI1A) && defined(STM32_RCC_SAI1ASRC_LAYOUT1)
    TEST_FUNC(test_rcc_set_sai1a_clock_source),
#endif
#if defined(STM32_RCC_SAI1A) && defined(STM32_RCC_SAI1ASRC_LAYOUT2)
    TEST_FUNC(test_rcc_set_sai1a_clock_source),
#endif
#if defined(STM32_SAI2)
    TEST_FUNC(test_rcc_set_sai2_clock_source),
#endif
#if defined(STM32_RCC_SAI1B) && defined(STM32_RCC_SAI1BSRC_LAYOUT1)
    TEST_FUNC(test_rcc_set_sai1b_clock_source),
#endif
#if defined(STM32_RCC_SAI1B) && defined(STM32_RCC_SAI1BSRC_LAYOUT2)
    TEST_FUNC(test_rcc_set_sai1b_clock_source),
#endif
#if defined(STM32_RCC_TIMPRE)
    TEST_FUNC(test_rcc_set_timers_prescaler),
#endif
#if defined(STM32_RCC_CLOCK_48MHZ) && defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR_LAYOUT1)
    TEST_FUNC(test_rcc_set_48Mhz_clock_source),
#endif
#if defined(STM32_RCC_CLOCK_48MHZ) && defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT1)
    TEST_FUNC(test_rcc_set_48Mhz_clock_source),
#endif
#if defined(STM32_RCC_CLOCK_48MHZ) && defined(STM32_RCC_CLOCK_48MHZ_DCKCFGR2_LAYOUT2)
    TEST_FUNC(test_rcc_set_48Mhz_clock_source),
#endif
#if defined(STM32_SDIO) && defined(STM32_RCC_SDIOCK_DCKCFGR)
    TEST_FUNC(test_rcc_set_sdio_clock_source),
#endif
#if defined(STM32_SDIO) && defined(STM32_RCC_SDIOCK_DCKCFGR2)
    TEST_FUNC(test_rcc_set_sdio_clock_source),
#endif
#if defined(STM32_DSI_HOST)
    TEST_FUNC(test_rcc_set_dsi_clock_source),
#endif
#if defined(STM32_RCC_I2S1) && defined(STM32_RCC_I2SSRC_LAYOUT1)
    TEST_FUNC(test_rcc_set_i2s1_clock_source),
#endif
#if defined(STM32_RCC_I2S1) && defined(STM32_RCC_I2SSRC_LAYOUT2)
    TEST_FUNC(test_rcc_set_i2s1_clock_source),
#endif
#if defined(STM32_RCC_I2S2) && defined(STM32_RCC_I2SSRC_LAYOUT1)
    TEST_FUNC(test_rcc_set_i2s2_clock_source),
#endif
#if defined(STM32_RCC_I2S2) && defined(STM32_RCC_I2SSRC_LAYOUT2)
    TEST_FUNC(test_rcc_set_i2s2_clock_source),
#endif
#if defined(STM32_DFSDM_KERNEL_CKSRC)
    TEST_FUNC(test_rcc_set_dfsdm_kernel_clock_source),
#endif
#if defined(STM32_RCC_CKGATE)
    TEST_FUNC(test_rcc_gate_clock),
#endif
#if defined(STM32_FMPI2C1)
    TEST_FUNC(test_rcc_set_i2c_fmp1_clock_source),
#endif
#if defined(STM32_CEC)
    TEST_FUNC(test_rcc_set_cec_clock_source),
#endif
#if defined(STM32_SPDIFRX)
    TEST_FUNC(test_rcc_set_spdifrx_clock_source),
#endif
#if defined(STM32_LPTIM1)
    TEST_FUNC(test_rcc_set_lptimer1_clock_source),
#endif
  };

  return TESTS_RUN(tests);
}
