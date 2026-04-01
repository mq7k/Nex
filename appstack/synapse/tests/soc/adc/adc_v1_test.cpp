#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/adc/adc_v1.h"
#include "libtest/libtest.hpp"

volatile struct adc_registers_map* _ADC;

void
setup(void)
{
  _ADC = (struct adc_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_OFFSET(struct adc_registers_map, SR, 0x00lu);
  ASSERT_OFFSET(struct adc_registers_map, CR1, 0x04lu);
  ASSERT_OFFSET(struct adc_registers_map, CR2, 0x08lu);
  ASSERT_OFFSET(struct adc_registers_map, SMPR1, 0x0clu);
  ASSERT_OFFSET(struct adc_registers_map, SMPR2, 0x10lu);
  ASSERT_OFFSET(struct adc_registers_map, JOFR1, 0x14lu);
  ASSERT_OFFSET(struct adc_registers_map, JOFR2, 0x18lu);
  ASSERT_OFFSET(struct adc_registers_map, JOFR3, 0x1clu);
  ASSERT_OFFSET(struct adc_registers_map, JOFR4, 0x20lu);
  ASSERT_OFFSET(struct adc_registers_map, HTR, 0x24lu);
  ASSERT_OFFSET(struct adc_registers_map, LTR, 0x28lu);
  ASSERT_OFFSET(struct adc_registers_map, SQR1, 0x2clu);
  ASSERT_OFFSET(struct adc_registers_map, SQR2, 0x30lu);
  ASSERT_OFFSET(struct adc_registers_map, SQR3, 0x34lu);
  ASSERT_OFFSET(struct adc_registers_map, JSQR, 0x38lu);
  ASSERT_OFFSET(struct adc_registers_map, JDR1, 0x3clu);
  ASSERT_OFFSET(struct adc_registers_map, JDR2, 0x40lu);
  ASSERT_OFFSET(struct adc_registers_map, JDR3, 0x44lu);
  ASSERT_OFFSET(struct adc_registers_map, JDR4, 0x48lu);
  ASSERT_OFFSET(struct adc_registers_map, DR, 0x4clu);
}

void
test_adc_is_flag_set(void)
{
  u32 res;

  _ADC->SR = 0;
  res = adc_is_flag_set(_ADC, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = (1u << 0);
  res = adc_is_flag_set(_ADC, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->SR = ~(1u << 0);
  res = adc_is_flag_set(_ADC, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  res = adc_is_flag_set(_ADC, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = 0;
  res = adc_is_flag_set(_ADC, ADC_FLAG_EOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = (1u << 1);
  res = adc_is_flag_set(_ADC, ADC_FLAG_EOC);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _ADC->SR = ~(1u << 1);
  res = adc_is_flag_set(_ADC, ADC_FLAG_EOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  res = adc_is_flag_set(_ADC, ADC_FLAG_EOC);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = 0;
  res = adc_is_flag_set(_ADC, ADC_FLAG_JEOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = (1u << 2);
  res = adc_is_flag_set(_ADC, ADC_FLAG_JEOC);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _ADC->SR = ~(1u << 2);
  res = adc_is_flag_set(_ADC, ADC_FLAG_JEOC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  res = adc_is_flag_set(_ADC, ADC_FLAG_JEOC);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = 0;
  res = adc_is_flag_set(_ADC, ADC_FLAG_JSTART);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = (1u << 3);
  res = adc_is_flag_set(_ADC, ADC_FLAG_JSTART);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _ADC->SR = ~(1u << 3);
  res = adc_is_flag_set(_ADC, ADC_FLAG_JSTART);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  res = adc_is_flag_set(_ADC, ADC_FLAG_JSTART);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = 0;
  res = adc_is_flag_set(_ADC, ADC_FLAG_START);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = (1u << 4);
  res = adc_is_flag_set(_ADC, ADC_FLAG_START);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _ADC->SR = ~(1u << 4);
  res = adc_is_flag_set(_ADC, ADC_FLAG_START);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  res = adc_is_flag_set(_ADC, ADC_FLAG_START);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_OVR)
  _ADC->SR = 0;
  res = adc_is_flag_set(_ADC, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = (1u << 5);
  res = adc_is_flag_set(_ADC, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _ADC->SR = ~(1u << 5);
  res = adc_is_flag_set(_ADC, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  res = adc_is_flag_set(_ADC, ADC_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_flag_clear(void)
{
  _ADC->SR = (1u << 0);
  adc_flag_clear(_ADC, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(_ADC->SR, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  adc_flag_clear(_ADC, ADC_FLAG_ANALOG_WATCHDOG);
  ASSERT_EQ(_ADC->SR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = (1u << 1);
  adc_flag_clear(_ADC, ADC_FLAG_EOC);
  ASSERT_EQ(_ADC->SR, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  adc_flag_clear(_ADC, ADC_FLAG_EOC);
  ASSERT_EQ(_ADC->SR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = (1u << 2);
  adc_flag_clear(_ADC, ADC_FLAG_JEOC);
  ASSERT_EQ(_ADC->SR, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  adc_flag_clear(_ADC, ADC_FLAG_JEOC);
  ASSERT_EQ(_ADC->SR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = (1u << 3);
  adc_flag_clear(_ADC, ADC_FLAG_JSTART);
  ASSERT_EQ(_ADC->SR, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  adc_flag_clear(_ADC, ADC_FLAG_JSTART);
  ASSERT_EQ(_ADC->SR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  _ADC->SR = (1u << 4);
  adc_flag_clear(_ADC, ADC_FLAG_START);
  ASSERT_EQ(_ADC->SR, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  adc_flag_clear(_ADC, ADC_FLAG_START);
  ASSERT_EQ(_ADC->SR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_OVR)
  _ADC->SR = (1u << 5);
  adc_flag_clear(_ADC, ADC_FLAG_OVERRUN);
  ASSERT_EQ(_ADC->SR, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->SR = 0xffffffff;
  adc_flag_clear(_ADC, ADC_FLAG_OVERRUN);
  ASSERT_EQ(_ADC->SR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_set_analog_watchdog_channel(void)
{
  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL0);
  ASSERT_EQ(_ADC->CR1, (0u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL0);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL1);
  ASSERT_EQ(_ADC->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL1);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL2);
  ASSERT_EQ(_ADC->CR1, (2u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL2);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (2u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL3);
  ASSERT_EQ(_ADC->CR1, (3u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL3);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (3u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL4);
  ASSERT_EQ(_ADC->CR1, (4u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL4);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (4u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL5);
  ASSERT_EQ(_ADC->CR1, (5u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL5);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (5u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL6);
  ASSERT_EQ(_ADC->CR1, (6u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL6);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (6u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL7);
  ASSERT_EQ(_ADC->CR1, (7u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL7);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (7u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL8);
  ASSERT_EQ(_ADC->CR1, (8u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL8);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (8u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL9);
  ASSERT_EQ(_ADC->CR1, (9u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL9);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (9u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL10);
  ASSERT_EQ(_ADC->CR1, (10u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL10);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (10u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL11);
  ASSERT_EQ(_ADC->CR1, (11u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL11);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (11u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL12);
  ASSERT_EQ(_ADC->CR1, (12u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL12);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (12u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL13);
  ASSERT_EQ(_ADC->CR1, (13u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL13);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (13u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL14);
  ASSERT_EQ(_ADC->CR1, (14u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL14);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (14u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL15);
  ASSERT_EQ(_ADC->CR1, (15u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL15);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (15u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL16);
  ASSERT_EQ(_ADC->CR1, (16u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL16);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (16u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_AWDCH17)
  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL17);
  ASSERT_EQ(_ADC->CR1, (17u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL17);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (17u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_ADC_MAX_CHANNELS18) && defined(STM32_ADC_AWDCH18)
  _ADC->CR1 = 0;
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL18);
  ASSERT_EQ(_ADC->CR1, (18u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x1fu << 0);
  adc_set_analog_watchdog_channel(_ADC, ADC_REG_CHANNEL18);
  ASSERT_EQ(_ADC->CR1, ~(0x1fu << 0) | (18u << 0));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_interrupt(void)
{
  _ADC->CR1 = 0;
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_EOC);
  ASSERT_EQ(_ADC->CR1, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 5);
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_EOC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_EOC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 5);
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_EOC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(_ADC->CR1, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 6);
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(_ADC->CR1, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 6);
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_ANALOG_WATCHDOG);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(_ADC->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 7);
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 7);
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_JEOC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_ADC_OVR)
  _ADC->CR1 = 0;
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(_ADC->CR1, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 26);
  adc_interrupt_enable(_ADC, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(_ADC->CR1, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 26);
  adc_interrupt_disable(_ADC, ADC_INTERRUPT_OVERRUN);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_adc_scan_mode(void)
{
  _ADC->CR1 = 0;
  adc_scan_mode_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 8);
  adc_scan_mode_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 8);
  adc_scan_mode_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_scan_mode_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_set_watchdog_mode(void)
{
  _ADC->CR1 = 0;
  adc_set_watchdog_mode(_ADC, ADC_WATCHDOG_MODE_SINGLE_CHANNEL);
  ASSERT_EQ(_ADC->CR1, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 9);
  adc_set_watchdog_mode(_ADC, ADC_WATCHDOG_MODE_SINGLE_CHANNEL);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 9);
  adc_set_watchdog_mode(_ADC, ADC_WATCHDOG_MODE_ALL_CHANNELS);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_set_watchdog_mode(_ADC, ADC_WATCHDOG_MODE_ALL_CHANNELS);
  ASSERT_EQ(_ADC->CR1, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_automatic_inj_group_conversion(void)
{
  _ADC->CR1 = 0;
  adc_automatic_inj_group_conversion_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 10);
  adc_automatic_inj_group_conversion_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 10);
  adc_automatic_inj_group_conversion_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_automatic_inj_group_conversion_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_discontinuous_mode_reg_channels(void)
{
  _ADC->CR1 = 0;
  adc_discontinuous_mode_reg_channels_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 11);
  adc_discontinuous_mode_reg_channels_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 11);
  adc_discontinuous_mode_reg_channels_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_discontinuous_mode_reg_channels_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_discontinuous_mode_inj_channels(void)
{
  _ADC->CR1 = 0;
  adc_discontinuous_mode_inj_channels_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 12);
  adc_discontinuous_mode_inj_channels_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 12);
  adc_discontinuous_mode_inj_channels_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_discontinuous_mode_inj_channels_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_set_discontinuous_mode_channel_count(void)
{
  _ADC->CR1 = 0;
  adc_set_discontinuous_mode_channel_count(_ADC, 0);
  ASSERT_EQ(_ADC->CR1, 0u << 13);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_set_discontinuous_mode_channel_count(_ADC, 0);
  ASSERT_EQ(_ADC->CR1, ~(0x7u << 13) | (0u << 13));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_discontinuous_mode_channel_count(_ADC, 7);
  ASSERT_EQ(_ADC->CR1, 7u << 13);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_set_discontinuous_mode_channel_count(_ADC, 7);
  ASSERT_EQ(_ADC->CR1, ~(0x7u << 13) | (7u << 13));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_discontinuous_mode_channel_count(_ADC, 8);
  ASSERT_EQ(_ADC->CR1, 8u << 13);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _ADC->CR1 = 0xffffffff;
  adc_set_discontinuous_mode_channel_count(_ADC, 8);
  ASSERT_EQ(_ADC->CR1, ~(0x7u << 13) | (8u << 13));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

#if defined(STM32_ADC_DUALMODE)
void
test_adc_set_dualmode(void)
{
  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_INDEPENDENT);
  ASSERT_EQ(_ADC->CR1, (0b0000u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_INDEPENDENT);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0000u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_REG_SIM_AND_INJ_SIM);
  ASSERT_EQ(_ADC->CR1, (0b0001u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_REG_SIM_AND_INJ_SIM);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0001u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_REG_SIM_AND_ALT_TRG);
  ASSERT_EQ(_ADC->CR1, (0b0010u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_REG_SIM_AND_ALT_TRG);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0010u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_INJ_SIM_AND_FAST_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, (0b0011u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_INJ_SIM_AND_FAST_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0011u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_INJ_SIM_AND_SLOW_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, (0b0100u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_INJ_SIM_AND_SLOW_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0100u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_INJ_SIM);
  ASSERT_EQ(_ADC->CR1, (0b0101u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_INJ_SIM);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0101u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_REG_SIM);
  ASSERT_EQ(_ADC->CR1, (0b0110u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_REG_SIM);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0110u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_FAST_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, (0b0111u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_FAST_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b0111u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_SLOW_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, (0b1000u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_SLOW_INTERLEAVED);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b1000u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_dualmode(_ADC, ADC_DUALMODE_ALT_TRG);
  ASSERT_EQ(_ADC->CR1, (0b1001u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0xfu << 16);
  adc_set_dualmode(_ADC, ADC_DUALMODE_ALT_TRG);
  ASSERT_EQ(_ADC->CR1, ~(0xfu << 16) | (0b1001u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_adc_watchdog_inj(void)
{
  _ADC->CR1 = 0;
  adc_watchdog_inj_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 22);
  adc_watchdog_inj_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 22);
  adc_watchdog_inj_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_watchdog_inj_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_watchdog_reg(void)
{
  _ADC->CR1 = 0;
  adc_watchdog_reg_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, (1u << 23));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(1u << 23);
  adc_watchdog_reg_enable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = (1u << 23);
  adc_watchdog_reg_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = 0xffffffff;
  adc_watchdog_reg_disable(_ADC);
  ASSERT_EQ(_ADC->CR1, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_RESOLUTION)
void
test_adc_set_resolution(void)
{
  _ADC->CR1 = 0;
  adc_set_resolution(_ADC, ADC_RESOLUTION_12BIT);
  ASSERT_EQ(_ADC->CR1, (0b00u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x3u << 24);
  adc_set_resolution(_ADC, ADC_RESOLUTION_12BIT);
  ASSERT_EQ(_ADC->CR1, ~(0x3u << 24) | (0b00u << 24));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_resolution(_ADC, ADC_RESOLUTION_10BIT);
  ASSERT_EQ(_ADC->CR1, (0b01u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x3u << 24);
  adc_set_resolution(_ADC, ADC_RESOLUTION_10BIT);
  ASSERT_EQ(_ADC->CR1, ~(0x3u << 24) | (0b01u << 24));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_resolution(_ADC, ADC_RESOLUTION_8BIT);
  ASSERT_EQ(_ADC->CR1, (0b10u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x3u << 24);
  adc_set_resolution(_ADC, ADC_RESOLUTION_8BIT);
  ASSERT_EQ(_ADC->CR1, ~(0x3u << 24) | (0b10u << 24));
  ASSERT_FALSE(execution_halted());


  _ADC->CR1 = 0;
  adc_set_resolution(_ADC, ADC_RESOLUTION_6BIT);
  ASSERT_EQ(_ADC->CR1, (0b11u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR1 = ~(0x3u << 24);
  adc_set_resolution(_ADC, ADC_RESOLUTION_6BIT);
  ASSERT_EQ(_ADC->CR1, ~(0x3u << 24) | (0b11u << 24));
  ASSERT_FALSE(execution_halted());


}
#endif

void
test_adc(void)
{
  _ADC->CR2 = 0;
  adc_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 0);
  adc_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = (1u << 0);
  adc_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0xffffffff;
  adc_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_adc_set_conversion_method(void)
{
  _ADC->CR2 = 0;
  adc_set_conversion_method(_ADC, ADC_CONVERSION_METHOD_CONTINUOUS);
  ASSERT_EQ(_ADC->CR2, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 1);
  adc_set_conversion_method(_ADC, ADC_CONVERSION_METHOD_CONTINUOUS);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = (1u << 1);
  adc_set_conversion_method(_ADC, ADC_CONVERSION_METHOD_SINGLE);
  ASSERT_EQ(_ADC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0xffffffff;
  adc_set_conversion_method(_ADC, ADC_CONVERSION_METHOD_SINGLE);
  ASSERT_EQ(_ADC->CR2, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_CALIBRATION)
void
test_adc_calibration_begin(void)
{
  _ADC->CR2 = 0;
  adc_calibration_begin(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 2);
  adc_calibration_begin(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CALIBRATION)
void
test_adc_is_calibration_in_progress(void)
{
  u32 res;

  _ADC->CR2 = 0;
  res = adc_is_calibration_in_progress(_ADC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x1u << 2);
  res = adc_is_calibration_in_progress(_ADC);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0x1u << 2;
  res = adc_is_calibration_in_progress(_ADC);
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CALIBRATION)
void
test_adc_calibration_reset(void)
{
  _ADC->CR2 = 0;
  adc_calibration_reset(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 3);
  adc_calibration_reset(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_adc_dma(void)
{
  _ADC->CR2 = 0;
  adc_dma_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 8);
  adc_dma_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = (1u << 8);
  adc_dma_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0xffffffff;
  adc_dma_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_dma_requests(void)
{
  _ADC->CR2 = 0;
  adc_dma_requests_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 9);
  adc_dma_requests_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = (1u << 9);
  adc_dma_requests_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0xffffffff;
  adc_dma_requests_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_set_eoc_policy(void)
{
  _ADC->CR2 = 0;
  adc_set_eoc_policy(_ADC, ADC_EOC_POLICY_EACH_CONVERSION);
  ASSERT_EQ(_ADC->CR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 10);
  adc_set_eoc_policy(_ADC, ADC_EOC_POLICY_EACH_CONVERSION);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = (1u << 10);
  adc_set_eoc_policy(_ADC, ADC_EOC_POLICY_EACH_SEQUENCE);
  ASSERT_EQ(_ADC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0xffffffff;
  adc_set_eoc_policy(_ADC, ADC_EOC_POLICY_EACH_SEQUENCE);
  ASSERT_EQ(_ADC->CR2, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_adc_set_data_alignment(void)
{
  _ADC->CR2 = 0;
  adc_set_data_alignment(_ADC, ADC_DATA_ALIGNMENT_LEFT);
  ASSERT_EQ(_ADC->CR2, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 11);
  adc_set_data_alignment(_ADC, ADC_DATA_ALIGNMENT_LEFT);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = (1u << 11);
  adc_set_data_alignment(_ADC, ADC_DATA_ALIGNMENT_RIGHT);
  ASSERT_EQ(_ADC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0xffffffff;
  adc_set_data_alignment(_ADC, ADC_DATA_ALIGNMENT_RIGHT);
  ASSERT_EQ(_ADC->CR2, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
void
test_adc_set_inj_external_event(void)
{
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b000u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b000u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_CC4);
  ASSERT_EQ(_ADC->CR2, (0b001u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_CC4);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b001u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b010u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b010u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_CC1);
  ASSERT_EQ(_ADC->CR2, (0b011u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_CC1);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b011u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM3_CC4);
  ASSERT_EQ(_ADC->CR2, (0b100u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM3_CC4);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b100u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM4_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b101u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_TIM4_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b101u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_EXTI);
  ASSERT_EQ(_ADC->CR2, (0b110u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC12_EXTI);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b110u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b000u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b000u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_CC4);
  ASSERT_EQ(_ADC->CR2, (0b001u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_CC4);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b001u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM4_CC3);
  ASSERT_EQ(_ADC->CR2, (0b010u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM4_CC3);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b010u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC2);
  ASSERT_EQ(_ADC->CR2, (0b011u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC2);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b011u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC4);
  ASSERT_EQ(_ADC->CR2, (0b100u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC4);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b100u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b101u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b101u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_CC4);
  ASSERT_EQ(_ADC->CR2, (0b110u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_CC4);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b110u << 12));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_JSWSTART);
  ASSERT_EQ(_ADC->CR2, (0b111u << 12));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 12);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_JSWSTART);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 12) | (0b111u << 12));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
test_adc_set_inj_external_event(void)
{
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM1_OC4);
  ASSERT_EQ(_ADC->CR2, (0b0000u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM1_OC4);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0000u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM1_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b0001u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM1_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0001u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM2)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM2_OC1);
  ASSERT_EQ(_ADC->CR2, (0b0010u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM2_OC1);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0010u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b0011u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0011u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM3_OC2);
  ASSERT_EQ(_ADC->CR2, (0b0100u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM3_OC2);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0100u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM3_OC4);
  ASSERT_EQ(_ADC->CR2, (0b0101u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM3_OC4);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0101u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_OC1);
  ASSERT_EQ(_ADC->CR2, (0b0110u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_OC1);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0110u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_OC2);
  ASSERT_EQ(_ADC->CR2, (0b0111u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_OC2);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b0111u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_OC3);
  ASSERT_EQ(_ADC->CR2, (0b1000u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_OC3);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1000u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b1001u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM4_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1001u << 16));
  ASSERT_FALSE(execution_halted());

#endif

  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM5_OC4);
  ASSERT_EQ(_ADC->CR2, (0b1010u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM5_OC4);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1010u << 16));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM5_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b1011u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM5_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1011u << 16));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM8)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM8_OC2);
  ASSERT_EQ(_ADC->CR2, (0b1100u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM8_OC2);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1100u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM8)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM8_OC3);
  ASSERT_EQ(_ADC->CR2, (0b1101u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM8_OC3);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1101u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM8)
  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM8_OC4);
  ASSERT_EQ(_ADC->CR2, (0b1110u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_TIM8_OC4);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1110u << 16));
  ASSERT_FALSE(execution_halted());

#endif

  _ADC->CR2 = 0;
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_EXTI15);
  ASSERT_EQ(_ADC->CR2, (0b1111u << 16));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 16);
  adc_set_inj_external_event(_ADC, ADC_INJ_TRIGGER_EVENT_EXTI15);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 16) | (0b1111u << 16));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_inj_start(void)
{
  _ADC->CR2 = 0;
  adc_inj_start(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 22);
  adc_inj_start(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT1)
void
test_adc_inj_start(void)
{
  _ADC->CR2 = 0;
  adc_inj_start(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 21);
  adc_inj_start(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
void
test_adc_set_reg_external_event(void)
{
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC1);
  ASSERT_EQ(_ADC->CR2, (0b000u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC1);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b000u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC2);
  ASSERT_EQ(_ADC->CR2, (0b001u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC2);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b001u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC3);
  ASSERT_EQ(_ADC->CR2, (0b010u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC3);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b010u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM2_CC2);
  ASSERT_EQ(_ADC->CR2, (0b011u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM2_CC2);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b011u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM3_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b100u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM3_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b100u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM4_CC4);
  ASSERT_EQ(_ADC->CR2, (0b101u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_TIM4_CC4);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b101u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_EXTI11);
  ASSERT_EQ(_ADC->CR2, (0b110u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC12_EXTI11);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b110u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(_ADC->CR2, (0b111u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b111u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM3_CC1);
  ASSERT_EQ(_ADC->CR2, (0b000u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM3_CC1);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b000u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM2_CC3);
  ASSERT_EQ(_ADC->CR2, (0b001u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM2_CC3);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b001u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM1_CC3);
  ASSERT_EQ(_ADC->CR2, (0b010u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM1_CC3);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b010u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_CC1);
  ASSERT_EQ(_ADC->CR2, (0b011u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_CC1);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b011u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b100u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM8_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b100u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC1);
  ASSERT_EQ(_ADC->CR2, (0b101u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC1);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b101u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC3);
  ASSERT_EQ(_ADC->CR2, (0b110u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC3);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b110u << 17));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(_ADC->CR2, (0b111u << 17));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x7u << 17);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_SWSTART);
  ASSERT_EQ(_ADC->CR2, ~(0x7u << 17) | (0b111u << 17));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
test_adc_set_reg_external_event(void)
{
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM1_OC1);
  ASSERT_EQ(_ADC->CR2, (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM1_OC1);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0000u << 24));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM1_OC2);
  ASSERT_EQ(_ADC->CR2, (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM1_OC2);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0001u << 24));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM1_OC3);
  ASSERT_EQ(_ADC->CR2, (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM1_OC3);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0010u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM2)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_OC2);
  ASSERT_EQ(_ADC->CR2, (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_OC2);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_OC3);
  ASSERT_EQ(_ADC->CR2, (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_OC3);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_OC4);
  ASSERT_EQ(_ADC->CR2, (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_OC4);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM2)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM2_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM3_OC1);
  ASSERT_EQ(_ADC->CR2, (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM3_OC1);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM3)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM3_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM3_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM4)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM4_OC4);
  ASSERT_EQ(_ADC->CR2, (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM4_OC4);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM5_OC1);
  ASSERT_EQ(_ADC->CR2, (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM5_OC1);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1010u << 24));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM5_OC2);
  ASSERT_EQ(_ADC->CR2, (0b1011u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM5_OC2);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1011u << 24));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM5_OC3);
  ASSERT_EQ(_ADC->CR2, (0b1100u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM5_OC3);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1100u << 24));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_TIM8)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM8_OC1);
  ASSERT_EQ(_ADC->CR2, (0b1101u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM8_OC1);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1101u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_TIM8)
  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM8_TRGO);
  ASSERT_EQ(_ADC->CR2, (0b1110u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_TIM8_TRGO);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

  _ADC->CR2 = 0;
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_EXTI11);
  ASSERT_EQ(_ADC->CR2, (0b1111u << 24));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0xfu << 24);
  adc_set_reg_external_event(_ADC, ADC_REG_TRIGGER_EVENT_EXTI11);
  ASSERT_EQ(_ADC->CR2, ~(0xfu << 24) | (0b1111u << 24));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_reg_start(void)
{
  _ADC->CR2 = 0;
  adc_reg_start(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 30));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 30);
  adc_reg_start(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT1)
void
test_adc_reg_start(void)
{
  _ADC->CR2 = 0;
  adc_reg_start(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 22);
  adc_reg_start(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT1)
void
test_adc_temperature_sensor(void)
{
  _ADC->CR2 = 0;
  adc_temperature_sensor_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, (1u << 23));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(1u << 23);
  adc_temperature_sensor_enable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = (1u << 23);
  adc_temperature_sensor_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = 0xffffffff;
  adc_temperature_sensor_disable(_ADC);
  ASSERT_EQ(_ADC->CR2, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_set_inj_external_trigger_edge(void)
{
  _ADC->CR2 = 0;
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(_ADC->CR2, (0b00u << 20));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 20) | (0b00u << 20));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(_ADC->CR2, (0b01u << 20));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 20) | (0b01u << 20));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(_ADC->CR2, (0b10u << 20));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 20) | (0b10u << 20));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(_ADC->CR2, (0b11u << 20));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 20);
  adc_set_inj_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 20) | (0b11u << 20));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
test_adc_set_reg_external_trigger_edge(void)
{
  _ADC->CR2 = 0;
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(_ADC->CR2, (0b00u << 28));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_OFF);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 28) | (0b00u << 28));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(_ADC->CR2, (0b01u << 28));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_RISING);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 28) | (0b01u << 28));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(_ADC->CR2, (0b10u << 28));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_FALLING);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 28) | (0b10u << 28));
  ASSERT_FALSE(execution_halted());


  _ADC->CR2 = 0;
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(_ADC->CR2, (0b11u << 28));
  ASSERT_FALSE(execution_halted());

  _ADC->CR2 = ~(0x3u << 28);
  adc_set_reg_external_trigger_edge(_ADC, ADC_EXTERNAL_TRIGGER_EDGE_BOTH);
  ASSERT_EQ(_ADC->CR2, ~(0x3u << 28) | (0b11u << 28));
  ASSERT_FALSE(execution_halted());


}
#endif

// └─Skipping type 'inject' (adc_set_inj_offset)
void
test_adc_set_watchdog_high_threshold(void)
{
  _ADC->HTR = 0;
  adc_set_watchdog_high_threshold(_ADC, 0);
  ASSERT_EQ(_ADC->HTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _ADC->HTR = 0xffffffff;
  adc_set_watchdog_high_threshold(_ADC, 0);
  ASSERT_EQ(_ADC->HTR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->HTR = 0;
  adc_set_watchdog_high_threshold(_ADC, 0xfff);
  ASSERT_EQ(_ADC->HTR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  _ADC->HTR = 0xffffffff;
  adc_set_watchdog_high_threshold(_ADC, 0xfff);
  ASSERT_EQ(_ADC->HTR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->HTR = 0;
  adc_set_watchdog_high_threshold(_ADC, 0x1fff);
  ASSERT_EQ(_ADC->HTR, 0x1fffu << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _ADC->HTR = 0xffffffff;
  adc_set_watchdog_high_threshold(_ADC, 0x1fff);
  ASSERT_EQ(_ADC->HTR, ~(0xfffu << 0) | (0x1fffu << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_adc_set_watchdog_low_threshold(void)
{
  _ADC->LTR = 0;
  adc_set_watchdog_low_threshold(_ADC, 0);
  ASSERT_EQ(_ADC->LTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _ADC->LTR = 0xffffffff;
  adc_set_watchdog_low_threshold(_ADC, 0);
  ASSERT_EQ(_ADC->LTR, ~(0xfffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->LTR = 0;
  adc_set_watchdog_low_threshold(_ADC, 0xfff);
  ASSERT_EQ(_ADC->LTR, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  _ADC->LTR = 0xffffffff;
  adc_set_watchdog_low_threshold(_ADC, 0xfff);
  ASSERT_EQ(_ADC->LTR, ~(0xfffu << 0) | (0xfffu << 0));
  ASSERT_FALSE(execution_halted());


  _ADC->LTR = 0;
  adc_set_watchdog_low_threshold(_ADC, 0x1fff);
  ASSERT_EQ(_ADC->LTR, 0x1fffu << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _ADC->LTR = 0xffffffff;
  adc_set_watchdog_low_threshold(_ADC, 0x1fff);
  ASSERT_EQ(_ADC->LTR, ~(0xfffu << 0) | (0x1fffu << 0));
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
    TEST_FUNC(test_reg_addr),
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
