#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/dac/dac_v2.h"
#include "libtest/libtest.h"

void
setup(void)
{
  DAC = (struct dac_registers_map*) membuf;
}

void
test_dac_channel(void)
{
  DAC->CR = 0;
  dac_channel_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 0);
  dac_channel_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 0);
  dac_channel_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_channel_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 16);
  dac_channel_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 16);
  dac_channel_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


}

void
test_dac_channel_buffer(void)
{
  DAC->CR = 0;
  dac_channel_buffer_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 1);
  dac_channel_buffer_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_buffer_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 1);
  dac_channel_buffer_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_buffer_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 17);
  dac_channel_buffer_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_buffer_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 17);
  dac_channel_buffer_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_channel_trigger(void)
{
  DAC->CR = 0;
  dac_channel_trigger_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 2);
  dac_channel_trigger_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_trigger_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 2);
  dac_channel_trigger_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_trigger_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 18);
  dac_channel_trigger_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_trigger_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 18);
  dac_channel_trigger_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_channel_set_trigger(void)
{
  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM6'}, self.value='0b000', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM6);
  ASSERT_EQ(DAC->CR, (0b000u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM6);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b000u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM3'}, self.value='0b001', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM3);
  ASSERT_EQ(DAC->CR, (0b001u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM3);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b001u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM7'}, self.value='0b010', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM7);
  ASSERT_EQ(DAC->CR, (0b010u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM7);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b010u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM5'}, self.value='0b011', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM5);
  ASSERT_EQ(DAC->CR, (0b011u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM5);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b011u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM2'}, self.value='0b100', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM2);
  ASSERT_EQ(DAC->CR, (0b100u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM2);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b100u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM4'}, self.value='0b101', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM4);
  ASSERT_EQ(DAC->CR, (0b101u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM4);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b101u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_EXT_LINE9'}, self.value='0b110', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_EXT_LINE9);
  ASSERT_EQ(DAC->CR, (0b110u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_EXT_LINE9);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b110u << 3));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=3, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL1', 'trigger': 'DAC_CHANNEL_TRIGGER_SOFTWARE'}, self.value='0b111', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_SOFTWARE);
  ASSERT_EQ(DAC->CR, (0b111u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_SOFTWARE);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b111u << 3));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM6'}, self.value='0b000', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM6);
  ASSERT_EQ(DAC->CR, (0b000u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM6);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b000u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM3'}, self.value='0b001', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM3);
  ASSERT_EQ(DAC->CR, (0b001u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM3);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b001u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM7'}, self.value='0b010', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM7);
  ASSERT_EQ(DAC->CR, (0b010u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM7);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b010u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM5'}, self.value='0b011', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM5);
  ASSERT_EQ(DAC->CR, (0b011u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM5);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b011u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM2'}, self.value='0b100', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM2);
  ASSERT_EQ(DAC->CR, (0b100u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM2);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b100u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_TIM4'}, self.value='0b101', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM4);
  ASSERT_EQ(DAC->CR, (0b101u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM4);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b101u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_EXT_LINE9'}, self.value='0b110', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_EXT_LINE9);
  ASSERT_EQ(DAC->CR, (0b110u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_EXT_LINE9);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b110u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=19, self.mask='0x7', self.varsmap={'channel': 'DAC_CHANNEL2', 'trigger': 'DAC_CHANNEL_TRIGGER_SOFTWARE'}, self.value='0b111', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_SOFTWARE);
  ASSERT_EQ(DAC->CR, (0b111u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_SOFTWARE);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b111u << 19));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_set_channel_wave(void)
{
  // scope=self.reg='CR', self.shift=6, self.mask='0x3', self.varsmap={'channel': 'DAC_CHANNEL1', 'wave': 'DAC_WAVE_OFF'}, self.value='0b00', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_wave(DAC_CHANNEL1, DAC_WAVE_OFF);
  ASSERT_EQ(DAC->CR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 6);
  dac_set_channel_wave(DAC_CHANNEL1, DAC_WAVE_OFF);
  ASSERT_EQ(DAC->CR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=6, self.mask='0x3', self.varsmap={'channel': 'DAC_CHANNEL1', 'wave': 'DAC_WAVE_NOISE'}, self.value='0b01', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_wave(DAC_CHANNEL1, DAC_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 6);
  dac_set_channel_wave(DAC_CHANNEL1, DAC_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=6, self.mask='0x3', self.varsmap={'channel': 'DAC_CHANNEL1', 'wave': 'DAC_WAVE_TRIANGLE'}, self.value='0b10', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_wave(DAC_CHANNEL1, DAC_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 6);
  dac_set_channel_wave(DAC_CHANNEL1, DAC_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=22, self.mask='0x3', self.varsmap={'channel': 'DAC_CHANNEL2', 'wave': 'DAC_WAVE_OFF'}, self.value='0b00', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_wave(DAC_CHANNEL2, DAC_WAVE_OFF);
  ASSERT_EQ(DAC->CR, (0b00u << 22));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 22);
  dac_set_channel_wave(DAC_CHANNEL2, DAC_WAVE_OFF);
  ASSERT_EQ(DAC->CR, ~(0x3u << 22) | (0b00u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=22, self.mask='0x3', self.varsmap={'channel': 'DAC_CHANNEL2', 'wave': 'DAC_WAVE_NOISE'}, self.value='0b01', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_wave(DAC_CHANNEL2, DAC_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, (0b01u << 22));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 22);
  dac_set_channel_wave(DAC_CHANNEL2, DAC_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 22) | (0b01u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=22, self.mask='0x3', self.varsmap={'channel': 'DAC_CHANNEL2', 'wave': 'DAC_WAVE_TRIANGLE'}, self.value='0b10', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_wave(DAC_CHANNEL2, DAC_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, (0b10u << 22));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 22);
  dac_set_channel_wave(DAC_CHANNEL2, DAC_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 22) | (0b10u << 22));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_set_channel_amplitude(void)
{
  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE1'}, self.value='0b0000', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE3'}, self.value='0b0001', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE7'}, self.value='0b0010', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE15'}, self.value='0b0011', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE31'}, self.value='0b0100', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE63'}, self.value='0b0101', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE127'}, self.value='0b0110', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE255'}, self.value='0b0111', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE511'}, self.value='0b1000', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE1023'}, self.value='0b1001', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE2047'}, self.value='0b1010', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL1', 'amplitude': 'DAC_AMPLITUDE4095'}, self.value='0b1011', self.ifdef=[], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, (0b1011u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1011u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE1'}, self.value='0b0000', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE3'}, self.value='0b0001', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE7'}, self.value='0b0010', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE15'}, self.value='0b0011', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE31'}, self.value='0b0100', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE63'}, self.value='0b0101', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE127'}, self.value='0b0110', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE255'}, self.value='0b0111', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE511'}, self.value='0b1000', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE1023'}, self.value='0b1001', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE2047'}, self.value='0b1010', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  // scope=self.reg='CR', self.shift=24, self.mask='0xf', self.varsmap={'channel': 'DAC_CHANNEL2', 'amplitude': 'DAC_AMPLITUDE4095'}, self.value='0b1011', self.ifdef=['STM32_DAC_CHANNEL2'], self.halt=False
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, (0b1011u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_dma_enable(void)
{
  DAC->CR = 0;
  dac_dma_enable_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 12);
  dac_dma_enable_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_dma_enable_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 12);
  dac_dma_enable_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_dma_enable_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 28);
  dac_dma_enable_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_dma_enable_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 28);
  dac_dma_enable_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_channel_software_trigger(void)
{
  DAC->SWTRIGR = 0;
  dac_channel_software_trigger_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = ~(1u << 1);
  dac_channel_software_trigger_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = 0xffffffff;
  dac_channel_software_trigger_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = (1u << 1);
  dac_channel_software_trigger_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->SWTRIGR = 0;
  dac_channel_software_trigger_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SWTRIGR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = ~(1u << 2);
  dac_channel_software_trigger_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SWTRIGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = 0xffffffff;
  dac_channel_software_trigger_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SWTRIGR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = (1u << 2);
  dac_channel_software_trigger_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SWTRIGR, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_set_channel_12bit_right_aligned_data(void)
{
  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR12R1, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12R1 = 0xffffffff;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR12R1, 0);
  ASSERT_FALSE(execution_halted());


  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0xfff);
  ASSERT_EQ(DAC->DHR12R1, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12R1 = 0xffffffff;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0xfff);
  ASSERT_EQ(DAC->DHR12R1, 0xfff);
  ASSERT_FALSE(execution_halted());


  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0x1000);
  ASSERT_EQ(DAC->DHR12R1, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR12R1 = 0xffffffff;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0x1000);
  ASSERT_EQ(DAC->DHR12R1, 0x1000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR12R1, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12R1 = 0xffffffff;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR12R1, 0);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0xfff);
  ASSERT_EQ(DAC->DHR12R1, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12R1 = 0xffffffff;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0xfff);
  ASSERT_EQ(DAC->DHR12R1, 0xfff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0x1000);
  ASSERT_EQ(DAC->DHR12R1, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR12R1 = 0xffffffff;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0x1000);
  ASSERT_EQ(DAC->DHR12R1, 0x1000);
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

}

void
test_dac_set_channel_12bit_left_aligned_data(void)
{
  DAC->DHR12L1 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR12L1, 0u << 4);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12L1 = 0xffffffff;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR12L1, 0);
  ASSERT_FALSE(execution_halted());


  DAC->DHR12L1 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0xfff);
  ASSERT_EQ(DAC->DHR12L1, 0xfffu << 4);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12L1 = 0xffffffff;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0xfff);
  ASSERT_EQ(DAC->DHR12L1, 0xfff);
  ASSERT_FALSE(execution_halted());


  DAC->DHR12L1 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0x1000);
  ASSERT_EQ(DAC->DHR12L1, 0x1000u << 4);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR12L1 = 0xffffffff;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0x1000);
  ASSERT_EQ(DAC->DHR12L1, 0x1000);
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12L2 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR12L2, 0u << 4);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12L2 = 0xffffffff;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR12L2, 0);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12L2 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0xfff);
  ASSERT_EQ(DAC->DHR12L2, 0xfffu << 4);
  ASSERT_FALSE(execution_halted());

  DAC->DHR12L2 = 0xffffffff;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0xfff);
  ASSERT_EQ(DAC->DHR12L2, 0xfff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12L2 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0x1000);
  ASSERT_EQ(DAC->DHR12L2, 0x1000u << 4);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR12L2 = 0xffffffff;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0x1000);
  ASSERT_EQ(DAC->DHR12L2, 0x1000);
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

}

void
test_dac_set_channel_8bit_data(void)
{
  DAC->DHR8R1 = 0;
  dac_set_channel_8bit_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR8R1, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R1 = 0xffffffff;
  dac_set_channel_8bit_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR8R1, 0);
  ASSERT_FALSE(execution_halted());


  DAC->DHR8R1 = 0;
  dac_set_channel_8bit_data(DAC_CHANNEL1, 0xff);
  ASSERT_EQ(DAC->DHR8R1, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R1 = 0xffffffff;
  dac_set_channel_8bit_data(DAC_CHANNEL1, 0xff);
  ASSERT_EQ(DAC->DHR8R1, 0xff);
  ASSERT_FALSE(execution_halted());


  DAC->DHR8R1 = 0;
  dac_set_channel_8bit_data(DAC_CHANNEL1, 0x100);
  ASSERT_EQ(DAC->DHR8R1, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR8R1 = 0xffffffff;
  dac_set_channel_8bit_data(DAC_CHANNEL1, 0x100);
  ASSERT_EQ(DAC->DHR8R1, 0x100);
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR8R2 = 0;
  dac_set_channel_8bit_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR8R2, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R2 = 0xffffffff;
  dac_set_channel_8bit_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR8R2, 0);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR8R2 = 0;
  dac_set_channel_8bit_data(DAC_CHANNEL2, 0xff);
  ASSERT_EQ(DAC->DHR8R2, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R2 = 0xffffffff;
  dac_set_channel_8bit_data(DAC_CHANNEL2, 0xff);
  ASSERT_EQ(DAC->DHR8R2, 0xff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR8R2 = 0;
  dac_set_channel_8bit_data(DAC_CHANNEL2, 0x100);
  ASSERT_EQ(DAC->DHR8R2, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR8R2 = 0xffffffff;
  dac_set_channel_8bit_data(DAC_CHANNEL2, 0x100);
  ASSERT_EQ(DAC->DHR8R2, 0x100);
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

}

// └─Skipping type 'fn_set_value (TODO)' (dac_set_channels_12bit_data)
// └─Skipping type 'fn_set_value (TODO)' (dac_set_channels_8bit_data)
void
test_dac_get_channel_output_data(void)
{
  u32 res;

  // read_bits
  DAC->DOR1 = 0;
  res = dac_get_channel_output_data(DAC_CHANNEL1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->DOR1 = ~(0xfffu << 0);
  res = dac_get_channel_output_data(DAC_CHANNEL1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->DOR1 = 0xfffu << 0;
  res = dac_get_channel_output_data(DAC_CHANNEL1);
  ASSERT_EQ(res, 0xfff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  DAC->DOR2 = 0;
  res = dac_get_channel_output_data(DAC_CHANNEL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->DOR2 = ~(0xfffu << 0);
  res = dac_get_channel_output_data(DAC_CHANNEL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->DOR2 = 0xfffu << 0;
  res = dac_get_channel_output_data(DAC_CHANNEL2);
  ASSERT_EQ(res, 0xfff);
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_dac_channel),
    TEST_FUNC(test_dac_channel_buffer),
    TEST_FUNC(test_dac_channel_trigger),
    TEST_FUNC(test_dac_channel_set_trigger),
    TEST_FUNC(test_dac_set_channel_wave),
    TEST_FUNC(test_dac_set_channel_amplitude),
    TEST_FUNC(test_dac_dma_enable),
    TEST_FUNC(test_dac_channel_software_trigger),
    TEST_FUNC(test_dac_set_channel_12bit_right_aligned_data),
    TEST_FUNC(test_dac_set_channel_12bit_left_aligned_data),
    TEST_FUNC(test_dac_set_channel_8bit_data),
    TEST_FUNC(test_dac_get_channel_output_data),
  };

  return TESTS_RUN(tests);
}
