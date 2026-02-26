#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/adc/adc_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  ADC1 = (struct adc_registers_map*) membuf;
}

void
test_adc_is_flag_set(void)
{
  u32 res;

  ADC1->SR = 0;
  res = adc_is_flag_set(ADC1, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = (1u << 0);
  res = adc_is_flag_set(ADC1, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->SR = ~(1u << 0);
  res = adc_is_flag_set(ADC1, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  res = adc_is_flag_set(ADC1, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = 0;
  res = adc_is_flag_set(ADC1, ADC_FLAG_EOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = (1u << 1);
  res = adc_is_flag_set(ADC1, ADC_FLAG_EOC);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  ADC1->SR = ~(1u << 1);
  res = adc_is_flag_set(ADC1, ADC_FLAG_EOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  res = adc_is_flag_set(ADC1, ADC_FLAG_EOC);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = 0;
  res = adc_is_flag_set(ADC1, ADC_FLAG_JEOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = (1u << 2);
  res = adc_is_flag_set(ADC1, ADC_FLAG_JEOC);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  ADC1->SR = ~(1u << 2);
  res = adc_is_flag_set(ADC1, ADC_FLAG_JEOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  res = adc_is_flag_set(ADC1, ADC_FLAG_JEOC);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = 0;
  res = adc_is_flag_set(ADC1, ADC_FLAG_JSTART);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = (1u << 3);
  res = adc_is_flag_set(ADC1, ADC_FLAG_JSTART);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  ADC1->SR = ~(1u << 3);
  res = adc_is_flag_set(ADC1, ADC_FLAG_JSTART);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  res = adc_is_flag_set(ADC1, ADC_FLAG_JSTART);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = 0;
  res = adc_is_flag_set(ADC1, ADC_FLAG_START);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = (1u << 4);
  res = adc_is_flag_set(ADC1, ADC_FLAG_START);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  ADC1->SR = ~(1u << 4);
  res = adc_is_flag_set(ADC1, ADC_FLAG_START);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  res = adc_is_flag_set(ADC1, ADC_FLAG_START);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_OVR)
  ADC1->SR = 0;
  res = adc_is_flag_set(ADC1, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = (1u << 5);
  res = adc_is_flag_set(ADC1, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  ADC1->SR = ~(1u << 5);
  res = adc_is_flag_set(ADC1, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  res = adc_is_flag_set(ADC1, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_flag_clear(void)
{
  ADC1->SR = (1u << 0);
  adc_flag_clear(ADC1, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(ADC1->SR, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  adc_flag_clear(ADC1, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(ADC1->SR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = (1u << 1);
  adc_flag_clear(ADC1, ADC_FLAG_EOC);
  ASSERT_EQ(ADC1->SR, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  adc_flag_clear(ADC1, ADC_FLAG_EOC);
  ASSERT_EQ(ADC1->SR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = (1u << 2);
  adc_flag_clear(ADC1, ADC_FLAG_JEOC);
  ASSERT_EQ(ADC1->SR, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  adc_flag_clear(ADC1, ADC_FLAG_JEOC);
  ASSERT_EQ(ADC1->SR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = (1u << 3);
  adc_flag_clear(ADC1, ADC_FLAG_JSTART);
  ASSERT_EQ(ADC1->SR, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  adc_flag_clear(ADC1, ADC_FLAG_JSTART);
  ASSERT_EQ(ADC1->SR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  ADC1->SR = (1u << 4);
  adc_flag_clear(ADC1, ADC_FLAG_START);
  ASSERT_EQ(ADC1->SR, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  adc_flag_clear(ADC1, ADC_FLAG_START);
  ASSERT_EQ(ADC1->SR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_OVR)
  ADC1->SR = (1u << 5);
  adc_flag_clear(ADC1, ADC_FLAG_OVERRUN);
  ASSERT_EQ(ADC1->SR, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->SR = 0xffffffff;
  adc_flag_clear(ADC1, ADC_FLAG_OVERRUN);
  ASSERT_EQ(ADC1->SR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_set_analog_watchdog_channel(void)
{
  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL0'}, self.value='0', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL0);
  ASSERT_EQ(ADC1->CR1, (0u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL0);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL1'}, self.value='1', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL1);
  ASSERT_EQ(ADC1->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL1);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL2'}, self.value='2', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL2);
  ASSERT_EQ(ADC1->CR1, (2u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL2);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (2u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL3'}, self.value='3', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL3);
  ASSERT_EQ(ADC1->CR1, (3u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL3);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (3u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL4'}, self.value='4', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL4);
  ASSERT_EQ(ADC1->CR1, (4u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL4);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (4u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL5'}, self.value='5', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL5);
  ASSERT_EQ(ADC1->CR1, (5u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL5);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (5u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL6'}, self.value='6', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL6);
  ASSERT_EQ(ADC1->CR1, (6u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL6);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (6u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL7'}, self.value='7', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL7);
  ASSERT_EQ(ADC1->CR1, (7u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL7);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (7u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL8'}, self.value='8', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL8);
  ASSERT_EQ(ADC1->CR1, (8u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL8);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (8u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL9'}, self.value='9', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL9);
  ASSERT_EQ(ADC1->CR1, (9u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL9);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (9u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL10'}, self.value='10', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL10);
  ASSERT_EQ(ADC1->CR1, (10u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL10);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL11'}, self.value='11', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL11);
  ASSERT_EQ(ADC1->CR1, (11u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL11);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL12'}, self.value='12', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL12);
  ASSERT_EQ(ADC1->CR1, (12u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL12);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (12u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL13'}, self.value='13', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL13);
  ASSERT_EQ(ADC1->CR1, (13u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL13);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (13u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL14'}, self.value='14', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL14);
  ASSERT_EQ(ADC1->CR1, (14u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL14);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (14u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL15'}, self.value='15', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL15);
  ASSERT_EQ(ADC1->CR1, (15u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL15);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (15u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL16'}, self.value='16', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL16);
  ASSERT_EQ(ADC1->CR1, (16u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL16);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (16u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_AWDCH17)
  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL17'}, self.value='17', self.ifdef=['STM32_ADC_AWDCH17'], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL17);
  ASSERT_EQ(ADC1->CR1, (17u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL17);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (17u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ADC_MAX_CHANNELS18) && defined(STM32_ADC_AWDCH18)
  // scope=self.reg='CR1', self.shift='0', self.mask='0x1f', self.varsmap={'channel': 'ADC_REG_CHANNEL18'}, self.value='18', self.ifdef=['STM32_ADC_MAX_CHANNELS18', 'STM32_ADC_AWDCH18'], self.halt=False
  ADC1->CR1 = 0;
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL18);
  ASSERT_EQ(ADC1->CR1, (18u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(ADC1, ADC_REG_CHANNEL18);
  ASSERT_EQ(ADC1->CR1, ~(0x1fu << 0) | (18u << 0));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_interrupt(void)
{
  ADC1->CR1 = 0;
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_EOC);
  ASSERT_EQ(ADC1->CR1, (1u << 5));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 5);
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_EOC);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_EOC);
  ASSERT_EQ(ADC1->CR1, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 5);
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_EOC);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());


  ADC1->CR1 = 0;
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(ADC1->CR1, (1u << 6));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 6);
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(ADC1->CR1, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 6);
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());


  ADC1->CR1 = 0;
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(ADC1->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 7);
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(ADC1->CR1, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 7);
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_OVR)
  ADC1->CR1 = 0;
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(ADC1->CR1, (1u << 26));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 26);
  adc_interrupt_enable(ADC1, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(ADC1->CR1, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 26);
  adc_interrupt_disable(ADC1, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_scan_mode(void)
{
  ADC1->CR1 = 0;
  adc_scan_mode_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, (1u << 8));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 8);
  adc_scan_mode_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 8);
  adc_scan_mode_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_scan_mode_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_set_watchdog_mode(void)
{
  ADC1->CR1 = 0;
  adc_set_watchdog_mode(ADC1, ADC_WATCHDOG_MODE_SINGLE_CHANNEL);
  ASSERT_EQ(ADC1->CR1, (1u << 9));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 9);
  adc_set_watchdog_mode(ADC1, ADC_WATCHDOG_MODE_SINGLE_CHANNEL);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 9);
  adc_set_watchdog_mode(ADC1, ADC_WATCHDOG_MODE_ALL_CHANNELS);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_set_watchdog_mode(ADC1, ADC_WATCHDOG_MODE_ALL_CHANNELS);
  ASSERT_EQ(ADC1->CR1, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_automatic_inj_group_conversion(void)
{
  ADC1->CR1 = 0;
  adc_automatic_inj_group_conversion_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 10);
  adc_automatic_inj_group_conversion_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 10);
  adc_automatic_inj_group_conversion_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_automatic_inj_group_conversion_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_discontinuous_mode_reg_channels(void)
{
  ADC1->CR1 = 0;
  adc_discontinuous_mode_reg_channels_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, (1u << 11));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 11);
  adc_discontinuous_mode_reg_channels_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 11);
  adc_discontinuous_mode_reg_channels_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_discontinuous_mode_reg_channels_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_discontinuous_mode_inj_channels(void)
{
  ADC1->CR1 = 0;
  adc_discontinuous_mode_inj_channels_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 12);
  adc_discontinuous_mode_inj_channels_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 12);
  adc_discontinuous_mode_inj_channels_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_discontinuous_mode_inj_channels_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_set_discontinuous_mode_channel_count(void)
{
  ADC1->CR1 = 0;
  adc_set_discontinuous_mode_channel_count(ADC1, 0);
  ASSERT_EQ(ADC1->CR1, 0u << 13);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_set_discontinuous_mode_channel_count(ADC1, 0);
  ASSERT_EQ(ADC1->CR1, ~(0x7u << 13) | (0u << 13));
  ASSERT_FALSE(execution_halted());


  ADC1->CR1 = 0;
  adc_set_discontinuous_mode_channel_count(ADC1, 7);
  ASSERT_EQ(ADC1->CR1, 7u << 13);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_set_discontinuous_mode_channel_count(ADC1, 7);
  ASSERT_EQ(ADC1->CR1, ~(0x7u << 13) | (7u << 13));
  ASSERT_FALSE(execution_halted());


  ADC1->CR1 = 0;
  adc_set_discontinuous_mode_channel_count(ADC1, 8);
  ASSERT_EQ(ADC1->CR1, 8u << 13);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  ADC1->CR1 = 0xffffffff;
  adc_set_discontinuous_mode_channel_count(ADC1, 8);
  ASSERT_EQ(ADC1->CR1, ~(0x7u << 13) | (8u << 13));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

#if defined(STM32_ADC_DUALMODE)
void
test_adc_set_dualmode(void)
{
  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_INDEPENDENT'}, self.value='0b0000', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_INDEPENDENT);
  ASSERT_EQ(ADC1->CR1, (0b0000u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_INDEPENDENT);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0000u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_REG_SIM_AND_INJ_SIM'}, self.value='0b0001', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_REG_SIM_AND_INJ_SIM);
  ASSERT_EQ(ADC1->CR1, (0b0001u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_REG_SIM_AND_INJ_SIM);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0001u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_REG_SIM_AND_ALT_TRG'}, self.value='0b0010', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_REG_SIM_AND_ALT_TRG);
  ASSERT_EQ(ADC1->CR1, (0b0010u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_REG_SIM_AND_ALT_TRG);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0010u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_INJ_SIM_AND_FAST_INTERLEAVED'}, self.value='0b0011', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_INJ_SIM_AND_FAST_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, (0b0011u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_INJ_SIM_AND_FAST_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0011u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_INJ_SIM_AND_SLOW_INTERLEAVED'}, self.value='0b0100', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_INJ_SIM_AND_SLOW_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, (0b0100u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_INJ_SIM_AND_SLOW_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0100u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_INJ_SIM'}, self.value='0b0101', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_INJ_SIM);
  ASSERT_EQ(ADC1->CR1, (0b0101u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_INJ_SIM);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0101u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_REG_SIM'}, self.value='0b0110', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_REG_SIM);
  ASSERT_EQ(ADC1->CR1, (0b0110u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_REG_SIM);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0110u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_FAST_INTERLEAVED'}, self.value='0b0111', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_FAST_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, (0b0111u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_FAST_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b0111u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_SLOW_INTERLEAVED'}, self.value='0b1000', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_SLOW_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, (0b1000u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_SLOW_INTERLEAVED);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b1000u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='16', self.mask='0xf', self.varsmap={'mode': 'ADC_DUALMODE_ALT_TRG'}, self.value='0b1001', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_dualmode(ADC1, ADC_DUALMODE_ALT_TRG);
  ASSERT_EQ(ADC1->CR1, (0b1001u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0xfu << 16);
  adc_set_dualmode(ADC1, ADC_DUALMODE_ALT_TRG);
  ASSERT_EQ(ADC1->CR1, ~(0xfu << 16) | (0b1001u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_adc_watchdog_inj(void)
{
  ADC1->CR1 = 0;
  adc_watchdog_inj_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, (1u << 22));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 22);
  adc_watchdog_inj_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 22);
  adc_watchdog_inj_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_watchdog_inj_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_watchdog_reg(void)
{
  ADC1->CR1 = 0;
  adc_watchdog_reg_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, (1u << 23));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(1u << 23);
  adc_watchdog_reg_enable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = (1u << 23);
  adc_watchdog_reg_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = 0xffffffff;
  adc_watchdog_reg_disable(ADC1);
  ASSERT_EQ(ADC1->CR1, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_RESOLUTION)
void
test_adc_set_resolution(void)
{
  // scope=self.reg='CR1', self.shift='24', self.mask='0x3', self.varsmap={'resolution': 'ADC_RESOLUTION_12BIT'}, self.value='0b00', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_resolution(ADC1, ADC_RESOLUTION_12BIT);
  ASSERT_EQ(ADC1->CR1, (0b00u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x3u << 24);
  adc_set_resolution(ADC1, ADC_RESOLUTION_12BIT);
  ASSERT_EQ(ADC1->CR1, ~(0x3u << 24) | (0b00u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='24', self.mask='0x3', self.varsmap={'resolution': 'ADC_RESOLUTION_10BIT'}, self.value='0b01', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_resolution(ADC1, ADC_RESOLUTION_10BIT);
  ASSERT_EQ(ADC1->CR1, (0b01u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x3u << 24);
  adc_set_resolution(ADC1, ADC_RESOLUTION_10BIT);
  ASSERT_EQ(ADC1->CR1, ~(0x3u << 24) | (0b01u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='24', self.mask='0x3', self.varsmap={'resolution': 'ADC_RESOLUTION_8BIT'}, self.value='0b10', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_resolution(ADC1, ADC_RESOLUTION_8BIT);
  ASSERT_EQ(ADC1->CR1, (0b10u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x3u << 24);
  adc_set_resolution(ADC1, ADC_RESOLUTION_8BIT);
  ASSERT_EQ(ADC1->CR1, ~(0x3u << 24) | (0b10u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift='24', self.mask='0x3', self.varsmap={'resolution': 'ADC_RESOLUTION_6BIT'}, self.value='0b11', self.ifdef=[], self.halt=False
  ADC1->CR1 = 0;
  adc_set_resolution(ADC1, ADC_RESOLUTION_6BIT);
  ASSERT_EQ(ADC1->CR1, (0b11u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR1 = ~(0x3u << 24);
  adc_set_resolution(ADC1, ADC_RESOLUTION_6BIT);
  ASSERT_EQ(ADC1->CR1, ~(0x3u << 24) | (0b11u << 24));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_adc(void)
{
  ADC1->CR2 = 0;
  adc_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 0);
  adc_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = (1u << 0);
  adc_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0xffffffff;
  adc_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_set_conversion_method(void)
{
  ADC1->CR2 = 0;
  adc_set_conversion_method(ADC1, ADC_CONVERSION_METHOD_CONTINUOUS);
  ASSERT_EQ(ADC1->CR2, (1u << 1));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 1);
  adc_set_conversion_method(ADC1, ADC_CONVERSION_METHOD_CONTINUOUS);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = (1u << 1);
  adc_set_conversion_method(ADC1, ADC_CONVERSION_METHOD_SINGLE);
  ASSERT_EQ(ADC1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0xffffffff;
  adc_set_conversion_method(ADC1, ADC_CONVERSION_METHOD_SINGLE);
  ASSERT_EQ(ADC1->CR2, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_CALIBRATION)
void
test_adc_calibration_begin(void)
{
  ADC1->CR2 = 0;
  adc_calibration_begin(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 2));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 2);
  adc_calibration_begin(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CALIBRATION)
void
test_adc_is_calibration_in_progress(void)
{
  u32 res;

  // read_bit
  ADC1->CR2 = 0;
  res = adc_is_calibration_in_progress(ADC1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x1u << 2);
  res = adc_is_calibration_in_progress(ADC1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0x1u << 2;
  res = adc_is_calibration_in_progress(ADC1);
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CALIBRATION)
void
test_adc_calibration_reset(void)
{
  ADC1->CR2 = 0;
  adc_calibration_reset(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 3));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 3);
  adc_calibration_reset(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_adc_dma(void)
{
  ADC1->CR2 = 0;
  adc_dma_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 8));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 8);
  adc_dma_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = (1u << 8);
  adc_dma_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0xffffffff;
  adc_dma_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_dma_requests(void)
{
  ADC1->CR2 = 0;
  adc_dma_requests_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 9));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 9);
  adc_dma_requests_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = (1u << 9);
  adc_dma_requests_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0xffffffff;
  adc_dma_requests_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_set_eoc_policy(void)
{
  ADC1->CR2 = 0;
  adc_set_eoc_policy(ADC1, ADC_EOC_POLICY_EACH_CONVERSION);
  ASSERT_EQ(ADC1->CR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 10);
  adc_set_eoc_policy(ADC1, ADC_EOC_POLICY_EACH_CONVERSION);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = (1u << 10);
  adc_set_eoc_policy(ADC1, ADC_EOC_POLICY_EACH_SEQUENCE);
  ASSERT_EQ(ADC1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0xffffffff;
  adc_set_eoc_policy(ADC1, ADC_EOC_POLICY_EACH_SEQUENCE);
  ASSERT_EQ(ADC1->CR2, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_adc_set_data_alignment(void)
{
  ADC1->CR2 = 0;
  adc_set_data_alignment(ADC1, ADC_DATA_ALIGNMENT_LEFT);
  ASSERT_EQ(ADC1->CR2, (1u << 11));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 11);
  adc_set_data_alignment(ADC1, ADC_DATA_ALIGNMENT_LEFT);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = (1u << 11);
  adc_set_data_alignment(ADC1, ADC_DATA_ALIGNMENT_RIGHT);
  ASSERT_EQ(ADC1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0xffffffff;
  adc_set_data_alignment(ADC1, ADC_DATA_ALIGNMENT_RIGHT);
  ASSERT_EQ(ADC1->CR2, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
void
test_adc_set_inj_external_event(void)
{
  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_TRGO'}, self.value='0b000', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b000u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_CC4'}, self.value='0b001', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_CC4);
  ASSERT_EQ(ADC1->CR2, (0b001u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_CC4);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_TRGO'}, self.value='0b010', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b010u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_CC1'}, self.value='0b011', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_CC1);
  ASSERT_EQ(ADC1->CR2, (0b011u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_CC1);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC12_TIM3_CC4'}, self.value='0b100', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM3_CC4);
  ASSERT_EQ(ADC1->CR2, (0b100u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM3_CC4);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC12_TIM4_TRGO'}, self.value='0b101', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM4_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b101u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_TIM4_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC12_EXTI'}, self.value='0b110', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_EXTI);
  ASSERT_EQ(ADC1->CR2, (0b110u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC12_EXTI);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_TRGO'}, self.value='0b000', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b000u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_CC4'}, self.value='0b001', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_CC4);
  ASSERT_EQ(ADC1->CR2, (0b001u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_CC4);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC3_TIM4_CC3'}, self.value='0b010', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM4_CC3);
  ASSERT_EQ(ADC1->CR2, (0b010u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM4_CC3);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC2'}, self.value='0b011', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC2);
  ASSERT_EQ(ADC1->CR2, (0b011u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC2);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC4'}, self.value='0b100', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC4);
  ASSERT_EQ(ADC1->CR2, (0b100u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC4);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_TRGO'}, self.value='0b101', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b101u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_CC4'}, self.value='0b110', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_CC4);
  ASSERT_EQ(ADC1->CR2, (0b110u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_CC4);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='12', self.mask='0x7', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_JSWSTART'}, self.value='0b111', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_JSWSTART);
  ASSERT_EQ(ADC1->CR2, (0b111u << 12));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_JSWSTART);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 12) | (0b111u << 12));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
test_adc_set_inj_external_event(void)
{
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM1_OC4'}, self.value='0b0000', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM1_OC4);
  ASSERT_EQ(ADC1->CR2, (0b0000u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM1_OC4);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0000u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM1_TRGO'}, self.value='0b0001', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM1_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b0001u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM1_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0001u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM2)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM2_OC1'}, self.value='0b0010', self.ifdef=['STM32_TIM2'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM2_OC1);
  ASSERT_EQ(ADC1->CR2, (0b0010u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM2_OC1);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0010u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM2_TRGO'}, self.value='0b0011', self.ifdef=['STM32_TIM2'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b0011u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0011u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM3_OC2'}, self.value='0b0100', self.ifdef=['STM32_TIM3'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM3_OC2);
  ASSERT_EQ(ADC1->CR2, (0b0100u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM3_OC2);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0100u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM3_OC4'}, self.value='0b0101', self.ifdef=['STM32_TIM3'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM3_OC4);
  ASSERT_EQ(ADC1->CR2, (0b0101u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM3_OC4);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0101u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM4_OC1'}, self.value='0b0110', self.ifdef=['STM32_TIM4'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_OC1);
  ASSERT_EQ(ADC1->CR2, (0b0110u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_OC1);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0110u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM4_OC2'}, self.value='0b0111', self.ifdef=['STM32_TIM4'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_OC2);
  ASSERT_EQ(ADC1->CR2, (0b0111u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_OC2);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b0111u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM4_OC3'}, self.value='0b1000', self.ifdef=['STM32_TIM4'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_OC3);
  ASSERT_EQ(ADC1->CR2, (0b1000u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_OC3);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1000u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM4_TRGO'}, self.value='0b1001', self.ifdef=['STM32_TIM4'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b1001u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM4_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1001u << 16));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM5_OC4'}, self.value='0b1010', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM5_OC4);
  ASSERT_EQ(ADC1->CR2, (0b1010u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM5_OC4);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1010u << 16));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM5_TRGO'}, self.value='0b1011', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM5_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b1011u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM5_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1011u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM8)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM8_OC2'}, self.value='0b1100', self.ifdef=['STM32_TIM8'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM8_OC2);
  ASSERT_EQ(ADC1->CR2, (0b1100u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM8_OC2);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1100u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM8)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM8_OC3'}, self.value='0b1101', self.ifdef=['STM32_TIM8'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM8_OC3);
  ASSERT_EQ(ADC1->CR2, (0b1101u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM8_OC3);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1101u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM8)
  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_TIM8_OC4'}, self.value='0b1110', self.ifdef=['STM32_TIM8'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM8_OC4);
  ASSERT_EQ(ADC1->CR2, (0b1110u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_TIM8_OC4);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1110u << 16));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CR2', self.shift='16', self.mask='0xf', self.varsmap={'event': 'ADC_INJ_TRIGGER_EVENT_EXTI15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_EXTI15);
  ASSERT_EQ(ADC1->CR2, (0b1111u << 16));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(ADC1, ADC_INJ_TRIGGER_EVENT_EXTI15);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 16) | (0b1111u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_inj_start(void)
{
  ADC1->CR2 = 0;
  adc_inj_start(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 22));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 22);
  adc_inj_start(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT1)
void
test_adc_inj_start(void)
{
  ADC1->CR2 = 0;
  adc_inj_start(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 21));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 21);
  adc_inj_start(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
void
test_adc_set_reg_external_event(void)
{
  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC1'}, self.value='0b000', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC1);
  ASSERT_EQ(ADC1->CR2, (0b000u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC1);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b000u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC2'}, self.value='0b001', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC2);
  ASSERT_EQ(ADC1->CR2, (0b001u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC2);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b001u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC3'}, self.value='0b010', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC3);
  ASSERT_EQ(ADC1->CR2, (0b010u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC3);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b010u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC12_TIM2_CC2'}, self.value='0b011', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM2_CC2);
  ASSERT_EQ(ADC1->CR2, (0b011u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM2_CC2);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b011u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC12_TIM3_TRGO'}, self.value='0b100', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM3_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b100u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM3_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b100u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC12_TIM4_CC4'}, self.value='0b101', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM4_CC4);
  ASSERT_EQ(ADC1->CR2, (0b101u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_TIM4_CC4);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b101u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC12_EXTI11'}, self.value='0b110', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_EXTI11);
  ASSERT_EQ(ADC1->CR2, (0b110u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC12_EXTI11);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b110u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_SWSTART'}, self.value='0b111', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(ADC1->CR2, (0b111u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b111u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC3_TIM3_CC1'}, self.value='0b000', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM3_CC1);
  ASSERT_EQ(ADC1->CR2, (0b000u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM3_CC1);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b000u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC3_TIM2_CC3'}, self.value='0b001', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM2_CC3);
  ASSERT_EQ(ADC1->CR2, (0b001u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM2_CC3);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b001u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC3_TIM1_CC3'}, self.value='0b010', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM1_CC3);
  ASSERT_EQ(ADC1->CR2, (0b010u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM1_CC3);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b010u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC3_TIM8_CC1'}, self.value='0b011', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_CC1);
  ASSERT_EQ(ADC1->CR2, (0b011u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_CC1);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b011u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC3_TIM8_TRGO'}, self.value='0b100', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b100u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b100u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC1'}, self.value='0b101', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC1);
  ASSERT_EQ(ADC1->CR2, (0b101u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC1);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b101u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC3'}, self.value='0b110', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC3);
  ASSERT_EQ(ADC1->CR2, (0b110u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC3);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b110u << 17));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='17', self.mask='0x7', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_SWSTART'}, self.value='0b111', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(ADC1->CR2, (0b111u << 17));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(ADC1->CR2, ~(0x7u << 17) | (0b111u << 17));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
test_adc_set_reg_external_event(void)
{
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM1_OC1'}, self.value='0b0000', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM1_OC1);
  ASSERT_EQ(ADC1->CR2, (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM1_OC1);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0000u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM1_OC2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM1_OC2);
  ASSERT_EQ(ADC1->CR2, (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM1_OC2);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0001u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM1_OC3'}, self.value='0b0010', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM1_OC3);
  ASSERT_EQ(ADC1->CR2, (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM1_OC3);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0010u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM2)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM2_OC2'}, self.value='0b0011', self.ifdef=['STM32_TIM2'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_OC2);
  ASSERT_EQ(ADC1->CR2, (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_OC2);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM2_OC3'}, self.value='0b0100', self.ifdef=['STM32_TIM2'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_OC3);
  ASSERT_EQ(ADC1->CR2, (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_OC3);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM2_OC4'}, self.value='0b0101', self.ifdef=['STM32_TIM2'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_OC4);
  ASSERT_EQ(ADC1->CR2, (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_OC4);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM2_TRGO'}, self.value='0b0110', self.ifdef=['STM32_TIM2'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM3_OC1'}, self.value='0b0111', self.ifdef=['STM32_TIM3'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM3_OC1);
  ASSERT_EQ(ADC1->CR2, (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM3_OC1);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM3_TRGO'}, self.value='0b1000', self.ifdef=['STM32_TIM3'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM3_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM3_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM4_OC4'}, self.value='0b1001', self.ifdef=['STM32_TIM4'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM4_OC4);
  ASSERT_EQ(ADC1->CR2, (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM4_OC4);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM5_OC1'}, self.value='0b1010', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM5_OC1);
  ASSERT_EQ(ADC1->CR2, (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM5_OC1);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1010u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM5_OC2'}, self.value='0b1011', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM5_OC2);
  ASSERT_EQ(ADC1->CR2, (0b1011u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM5_OC2);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1011u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM5_OC3'}, self.value='0b1100', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM5_OC3);
  ASSERT_EQ(ADC1->CR2, (0b1100u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM5_OC3);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1100u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM8)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM8_OC1'}, self.value='0b1101', self.ifdef=['STM32_TIM8'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM8_OC1);
  ASSERT_EQ(ADC1->CR2, (0b1101u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM8_OC1);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1101u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM8)
  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_TIM8_TRGO'}, self.value='0b1110', self.ifdef=['STM32_TIM8'], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM8_TRGO);
  ASSERT_EQ(ADC1->CR2, (0b1110u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_TIM8_TRGO);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

  // scope=self.reg='CR2', self.shift='24', self.mask='0xf', self.varsmap={'event': 'ADC_REG_TRIGGER_EVENT_EXTI11'}, self.value='0b1111', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_EXTI11);
  ASSERT_EQ(ADC1->CR2, (0b1111u << 24));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_EXTI11);
  ASSERT_EQ(ADC1->CR2, ~(0xfu << 24) | (0b1111u << 24));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_reg_start(void)
{
  ADC1->CR2 = 0;
  adc_reg_start(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 30));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 30);
  adc_reg_start(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT1)
void
test_adc_reg_start(void)
{
  ADC1->CR2 = 0;
  adc_reg_start(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 22));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 22);
  adc_reg_start(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT1)
void
test_adc_temperature_sensor(void)
{
  ADC1->CR2 = 0;
  adc_temperature_sensor_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, (1u << 23));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(1u << 23);
  adc_temperature_sensor_enable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = (1u << 23);
  adc_temperature_sensor_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, 0);
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = 0xffffffff;
  adc_temperature_sensor_disable(ADC1);
  ASSERT_EQ(ADC1->CR2, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_set_inj_external_trigger_edge(void)
{
  // scope=self.reg='CR2', self.shift='20', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_OFF'}, self.value='0b00', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(ADC1->CR2, (0b00u << 20));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 20) | (0b00u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='20', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_RISING'}, self.value='0b01', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(ADC1->CR2, (0b01u << 20));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 20) | (0b01u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='20', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_FALLING'}, self.value='0b10', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(ADC1->CR2, (0b10u << 20));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 20) | (0b10u << 20));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='20', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_BOTH'}, self.value='0b11', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(ADC1->CR2, (0b11u << 20));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 20) | (0b11u << 20));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_set_reg_external_trigger_edge(void)
{
  // scope=self.reg='CR2', self.shift='28', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_OFF'}, self.value='0b00', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(ADC1->CR2, (0b00u << 28));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 28) | (0b00u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='28', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_RISING'}, self.value='0b01', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(ADC1->CR2, (0b01u << 28));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 28) | (0b01u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='28', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_FALLING'}, self.value='0b10', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(ADC1->CR2, (0b10u << 28));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 28) | (0b10u << 28));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift='28', self.mask='0x3', self.varsmap={'edge': 'ADC_EXTERNAL_TRIGGER_EDGE_BOTH'}, self.value='0b11', self.ifdef=[], self.halt=False
  ADC1->CR2 = 0;
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(ADC1->CR2, (0b11u << 28));
  ASSERT_FALSE(execution_halted());

  ADC1->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(ADC1, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(ADC1->CR2, ~(0x3u << 28) | (0b11u << 28));
  ASSERT_FALSE(execution_halted());


}
#endif

// └─Skipping type 'inject' (adc_set_inj_offset)
void
test_adc_set_watchdog_high_threshold(void)
{
  ADC1->HTR = 0;
  adc_set_watchdog_high_threshold(ADC1, 0);
  ASSERT_EQ(ADC1->HTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  ADC1->HTR = 0xffffffff;
  adc_set_watchdog_high_threshold(ADC1, 0);
  ASSERT_EQ(ADC1->HTR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  ADC1->HTR = 0;
  adc_set_watchdog_high_threshold(ADC1, 0xfff);
  ASSERT_EQ(ADC1->HTR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  ADC1->HTR = 0xffffffff;
  adc_set_watchdog_high_threshold(ADC1, 0xfff);
  ASSERT_EQ(ADC1->HTR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  ADC1->HTR = 0;
  adc_set_watchdog_high_threshold(ADC1, 0x1fff);
  ASSERT_EQ(ADC1->HTR, 0x1fffu << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  ADC1->HTR = 0xffffffff;
  adc_set_watchdog_high_threshold(ADC1, 0x1fff);
  ASSERT_EQ(ADC1->HTR, ~(0xfffu << 0) | (0x1fffu << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_adc_set_watchdog_low_threshold(void)
{
  ADC1->LTR = 0;
  adc_set_watchdog_low_threshold(ADC1, 0);
  ASSERT_EQ(ADC1->LTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  ADC1->LTR = 0xffffffff;
  adc_set_watchdog_low_threshold(ADC1, 0);
  ASSERT_EQ(ADC1->LTR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  ADC1->LTR = 0;
  adc_set_watchdog_low_threshold(ADC1, 0xfff);
  ASSERT_EQ(ADC1->LTR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  ADC1->LTR = 0xffffffff;
  adc_set_watchdog_low_threshold(ADC1, 0xfff);
  ASSERT_EQ(ADC1->LTR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  ADC1->LTR = 0;
  adc_set_watchdog_low_threshold(ADC1, 0x1fff);
  ASSERT_EQ(ADC1->LTR, 0x1fffu << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  ADC1->LTR = 0xffffffff;
  adc_set_watchdog_low_threshold(ADC1, 0x1fff);
  ASSERT_EQ(ADC1->LTR, ~(0xfffu << 0) | (0x1fffu << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

// └─Skipping type 'inject' (adc_set_reg_sequence)
// └─Skipping type 'inject' (adc_set_inj_sequence)
// └─Skipping type 'inject' (adc_inj_data_read)
// └─Skipping type 'inject' (adc_reg_data_read)
int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_adc_is_flag_set),
    TEST_FUNC(test_adc_flag_clear),
    TEST_FUNC(test_adc_set_analog_watchdog_channel),
    TEST_FUNC(test_adc_interrupt),
    TEST_FUNC(test_adc_scan_mode),
    TEST_FUNC(test_adc_set_watchdog_mode),
    TEST_FUNC(test_adc_automatic_inj_group_conversion),
    TEST_FUNC(test_adc_discontinuous_mode_reg_channels),
    TEST_FUNC(test_adc_discontinuous_mode_inj_channels),
    TEST_FUNC(test_adc_set_discontinuous_mode_channel_count),
#if defined(STM32_ADC_DUALMODE)
    TEST_FUNC(test_adc_set_dualmode),
#endif
    TEST_FUNC(test_adc_watchdog_inj),
    TEST_FUNC(test_adc_watchdog_reg),
#if defined(STM32_ADC_RESOLUTION)
    TEST_FUNC(test_adc_set_resolution),
#endif
    TEST_FUNC(test_adc),
    TEST_FUNC(test_adc_set_conversion_method),
#if defined(STM32_ADC_CALIBRATION)
    TEST_FUNC(test_adc_calibration_begin),
#endif
#if defined(STM32_ADC_CALIBRATION)
    TEST_FUNC(test_adc_is_calibration_in_progress),
#endif
#if defined(STM32_ADC_CALIBRATION)
    TEST_FUNC(test_adc_calibration_reset),
#endif
    TEST_FUNC(test_adc_dma),
#if defined(STM32_ADC_CR2_LAYOUT2)
    TEST_FUNC(test_adc_dma_requests),
#endif
#if defined(STM32_ADC_CR2_LAYOUT2)
    TEST_FUNC(test_adc_set_eoc_policy),
#endif
    TEST_FUNC(test_adc_set_data_alignment),
#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
    TEST_FUNC(test_adc_set_inj_external_event),
#endif
#if defined(STM32_ADC_xEXTSEL_LAYOUT2)
    TEST_FUNC(test_adc_set_inj_external_event),
#endif
#if defined(STM32_ADC_CR2_LAYOUT2)
    TEST_FUNC(test_adc_inj_start),
#endif
#if defined(STM32_ADC_CR2_LAYOUT1)
    TEST_FUNC(test_adc_inj_start),
#endif
#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
    TEST_FUNC(test_adc_set_reg_external_event),
#endif
#if defined(STM32_ADC_xEXTSEL_LAYOUT2)
    TEST_FUNC(test_adc_set_reg_external_event),
#endif
#if defined(STM32_ADC_CR2_LAYOUT2)
    TEST_FUNC(test_adc_reg_start),
#endif
#if defined(STM32_ADC_CR2_LAYOUT1)
    TEST_FUNC(test_adc_reg_start),
#endif
#if defined(STM32_ADC_CR2_LAYOUT1)
    TEST_FUNC(test_adc_temperature_sensor),
#endif
#if defined(STM32_ADC_CR2_LAYOUT2)
    TEST_FUNC(test_adc_set_inj_external_trigger_edge),
#endif
#if defined(STM32_ADC_CR2_LAYOUT2)
    TEST_FUNC(test_adc_set_reg_external_trigger_edge),
#endif
    TEST_FUNC(test_adc_set_watchdog_high_threshold),
    TEST_FUNC(test_adc_set_watchdog_low_threshold),
  };

  return TESTS_RUN(tests);
}
