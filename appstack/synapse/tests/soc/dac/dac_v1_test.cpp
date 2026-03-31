#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/dac/dac_v1.h"
#include "libtest/libtest.hpp"

#define ASSERT_ADDR(periph, reg, offset)\
	ASSERT_EQ(offsetof(periph, reg), offset)


void
setup(void)
{
  DAC = (struct dac_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_ADDR(struct dac_registers_map, CR, 0x00lu);
  ASSERT_ADDR(struct dac_registers_map, SWTRIGR, 0x04lu);
  ASSERT_ADDR(struct dac_registers_map, DHR12R1, 0x08lu);
  ASSERT_ADDR(struct dac_registers_map, DHR12L1, 0x0clu);
  ASSERT_ADDR(struct dac_registers_map, DHR8R1, 0x10lu);
#if defined(STM32_DAC_CHANNEL2)
  ASSERT_ADDR(struct dac_registers_map, DHR12R2, 0x14lu);
#endif
#if defined(STM32_DAC_CHANNEL2)
  ASSERT_ADDR(struct dac_registers_map, DHR12L2, 0x18lu);
#endif
#if defined(STM32_DAC_CHANNEL2)
  ASSERT_ADDR(struct dac_registers_map, DHR8R2, 0x1clu);
#endif
#if defined(STM32_DAC_CHANNEL_COMMON)
  ASSERT_ADDR(struct dac_registers_map, DHR12RD, 0x20lu);
#endif
#if defined(STM32_DAC_CHANNEL_COMMON)
  ASSERT_ADDR(struct dac_registers_map, DHR12LD, 0x24lu);
#endif
#if defined(STM32_DAC_CHANNEL_COMMON)
  ASSERT_ADDR(struct dac_registers_map, DHR8RD, 0x28lu);
#endif
  ASSERT_ADDR(struct dac_registers_map, DOR1, 0x2clu);
#if defined(STM32_DAC_CHANNEL2)
  ASSERT_ADDR(struct dac_registers_map, DOR2, 0x30lu);
#endif
  ASSERT_ADDR(struct dac_registers_map, SR, 0x34lu);
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


#if defined(STM32_DAC_CHANNEL2)
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

#endif

}

void
test_dac_channel_output_buffer(void)
{
  DAC->CR = 0;
  dac_channel_output_buffer_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 1);
  dac_channel_output_buffer_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_output_buffer_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 1);
  dac_channel_output_buffer_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_output_buffer_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 17);
  dac_channel_output_buffer_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_output_buffer_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 17);
  dac_channel_output_buffer_disable(DAC_CHANNEL2);
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
#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM6_TRGO);
  ASSERT_EQ(DAC->CR, (0b000u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM6_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b000u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM8_TRGO);
  ASSERT_EQ(DAC->CR, (0b001u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM8_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b001u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM7_TRGO);
  ASSERT_EQ(DAC->CR, (0b010u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM7_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b010u << 3));
  ASSERT_FALSE(execution_halted());

#endif

  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM5_TRGO);
  ASSERT_EQ(DAC->CR, (0b011u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM5_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b011u << 3));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM2_TRGO);
  ASSERT_EQ(DAC->CR, (0b100u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM2_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b100u << 3));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM4_TRGO);
  ASSERT_EQ(DAC->CR, (0b101u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_TIM4_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b101u << 3));
  ASSERT_FALSE(execution_halted());

#endif

  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_EXTERNAL_LINE9);
  ASSERT_EQ(DAC->CR, (0b110u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_EXTERNAL_LINE9);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b110u << 3));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_SOFTWARE_TRIGGER);
  ASSERT_EQ(DAC->CR, (0b111u << 3));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 3);
  dac_channel_set_trigger(DAC_CHANNEL1, DAC_CHANNEL_TRIGGER_SOFTWARE_TRIGGER);
  ASSERT_EQ(DAC->CR, ~(0x7u << 3) | (0b111u << 3));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2) && defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM6_TRGO);
  ASSERT_EQ(DAC->CR, (0b000u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM6_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b000u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2) && defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM8_TRGO);
  ASSERT_EQ(DAC->CR, (0b001u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM8_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b001u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2) && defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM7_TRGO);
  ASSERT_EQ(DAC->CR, (0b010u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM7_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b010u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM5_TRGO);
  ASSERT_EQ(DAC->CR, (0b011u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM5_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b011u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2) && defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM2_TRGO);
  ASSERT_EQ(DAC->CR, (0b100u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM2_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b100u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2) && defined(STM32_DAC_TSEL_EXTENDED)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM4_TRGO);
  ASSERT_EQ(DAC->CR, (0b101u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_TIM4_TRGO);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b101u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_EXTERNAL_LINE9);
  ASSERT_EQ(DAC->CR, (0b110u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_EXTERNAL_LINE9);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b110u << 19));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_SOFTWARE_TRIGGER);
  ASSERT_EQ(DAC->CR, (0b111u << 19));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x7u << 19);
  dac_channel_set_trigger(DAC_CHANNEL2, DAC_CHANNEL_TRIGGER_SOFTWARE_TRIGGER);
  ASSERT_EQ(DAC->CR, ~(0x7u << 19) | (0b111u << 19));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_channel_set_wave(void)
{
  DAC->CR = 0;
  dac_channel_set_wave(DAC_CHANNEL1, DAC_CHANNEL_WAVE_OFF);
  ASSERT_EQ(DAC->CR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 6);
  dac_channel_set_wave(DAC_CHANNEL1, DAC_CHANNEL_WAVE_OFF);
  ASSERT_EQ(DAC->CR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_channel_set_wave(DAC_CHANNEL1, DAC_CHANNEL_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 6);
  dac_channel_set_wave(DAC_CHANNEL1, DAC_CHANNEL_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_channel_set_wave(DAC_CHANNEL1, DAC_CHANNEL_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, (0b10u << 6));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 6);
  dac_channel_set_wave(DAC_CHANNEL1, DAC_CHANNEL_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 6) | (0b10u << 6));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_set_wave(DAC_CHANNEL2, DAC_CHANNEL_WAVE_OFF);
  ASSERT_EQ(DAC->CR, (0b00u << 22));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 22);
  dac_channel_set_wave(DAC_CHANNEL2, DAC_CHANNEL_WAVE_OFF);
  ASSERT_EQ(DAC->CR, ~(0x3u << 22) | (0b00u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_set_wave(DAC_CHANNEL2, DAC_CHANNEL_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, (0b01u << 22));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 22);
  dac_channel_set_wave(DAC_CHANNEL2, DAC_CHANNEL_WAVE_NOISE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 22) | (0b01u << 22));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_set_wave(DAC_CHANNEL2, DAC_CHANNEL_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, (0b10u << 22));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0x3u << 22);
  dac_channel_set_wave(DAC_CHANNEL2, DAC_CHANNEL_WAVE_TRIANGLE);
  ASSERT_EQ(DAC->CR, ~(0x3u << 22) | (0b10u << 22));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_set_channel_amplitude(void)
{
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());


  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, (0b1011u << 8));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 8);
  dac_set_channel_amplitude(DAC_CHANNEL1, DAC_CHANNEL_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, ~(0xfu << 8) | (0b1011u << 8));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE1);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE3);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE7);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0010u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE15);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE31);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0100u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE63);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0101u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE127);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0110u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE255);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b0111u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE511);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1000u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE1023);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1001u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE2047);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1010u << 24));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, (0b1011u << 24));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(0xfu << 24);
  dac_set_channel_amplitude(DAC_CHANNEL2, DAC_CHANNEL_AMPLITUDE4095);
  ASSERT_EQ(DAC->CR, ~(0xfu << 24) | (0b1011u << 24));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_channel_dma(void)
{
  DAC->CR = 0;
  dac_channel_dma_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 12);
  dac_channel_dma_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_dma_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 12);
  dac_channel_dma_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_dma_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, (1u << 28));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 28);
  dac_channel_dma_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_dma_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, ~(1u << 28));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 28);
  dac_channel_dma_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_channel_dma_underrun_interrupt(void)
{
  DAC->CR = 0;
  dac_channel_dma_underrun_interrupt_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 13);
  dac_channel_dma_underrun_interrupt_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_dma_underrun_interrupt_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 13);
  dac_channel_dma_underrun_interrupt_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->CR = 0;
  dac_channel_dma_underrun_interrupt_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  DAC->CR = ~(1u << 29);
  dac_channel_dma_underrun_interrupt_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->CR = 0xffffffff;
  dac_channel_dma_underrun_interrupt_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, ~(1u << 29));
  ASSERT_FALSE(execution_halted());

  DAC->CR = (1u << 29);
  dac_channel_dma_underrun_interrupt_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->CR, 0);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_channel_software_trigger(void)
{
  DAC->SWTRIGR = 0;
  dac_channel_software_trigger_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = ~(1u << 0);
  dac_channel_software_trigger_enable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = 0xffffffff;
  dac_channel_software_trigger_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = (1u << 0);
  dac_channel_software_trigger_disable(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SWTRIGR, 0);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->SWTRIGR = 0;
  dac_channel_software_trigger_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SWTRIGR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = ~(1u << 1);
  dac_channel_software_trigger_enable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SWTRIGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = 0xffffffff;
  dac_channel_software_trigger_disable(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SWTRIGR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  DAC->SWTRIGR = (1u << 1);
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


  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0xfff);
  ASSERT_EQ(DAC->DHR12R1, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());


  DAC->DHR12R1 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL1, 0x1000);
  ASSERT_EQ(DAC->DHR12R1, 0x1000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12R2 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR12R2, 0u << 0);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12R2 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0xfff);
  ASSERT_EQ(DAC->DHR12R2, 0xfffu << 0);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12R2 = 0;
  dac_set_channel_12bit_right_aligned_data(DAC_CHANNEL2, 0x1000);
  ASSERT_EQ(DAC->DHR12R2, 0x1000u << 0);
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


  DAC->DHR12L1 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0xfff);
  ASSERT_EQ(DAC->DHR12L1, 0xfffu << 4);
  ASSERT_FALSE(execution_halted());


  DAC->DHR12L1 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL1, 0x1000);
  ASSERT_EQ(DAC->DHR12L1, 0x1000u << 4);
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12L2 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR12L2, 0u << 4);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12L2 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0xfff);
  ASSERT_EQ(DAC->DHR12L2, 0xfffu << 4);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR12L2 = 0;
  dac_set_channel_12bit_left_aligned_data(DAC_CHANNEL2, 0x1000);
  ASSERT_EQ(DAC->DHR12L2, 0x1000u << 4);
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

}

void
test_dac_set_channel_8bit_right_aligned_data(void)
{
  DAC->DHR8R1 = 0;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR8R1, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R1 = 0xffffffff;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL1, 0);
  ASSERT_EQ(DAC->DHR8R1, 0);
  ASSERT_FALSE(execution_halted());


  DAC->DHR8R1 = 0;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL1, 0xff);
  ASSERT_EQ(DAC->DHR8R1, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R1 = 0xffffffff;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL1, 0xff);
  ASSERT_EQ(DAC->DHR8R1, 0xff);
  ASSERT_FALSE(execution_halted());


  DAC->DHR8R1 = 0;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL1, 0x100);
  ASSERT_EQ(DAC->DHR8R1, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR8R1 = 0xffffffff;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL1, 0x100);
  ASSERT_EQ(DAC->DHR8R1, 0x100);
  ASSERT_TRUE(execution_halted());
  execution_resume();


#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR8R2 = 0;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR8R2, 0u << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R2 = 0xffffffff;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL2, 0);
  ASSERT_EQ(DAC->DHR8R2, 0);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR8R2 = 0;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL2, 0xff);
  ASSERT_EQ(DAC->DHR8R2, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  DAC->DHR8R2 = 0xffffffff;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL2, 0xff);
  ASSERT_EQ(DAC->DHR8R2, 0xff);
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_DAC_CHANNEL2)
  DAC->DHR8R2 = 0;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL2, 0x100);
  ASSERT_EQ(DAC->DHR8R2, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  DAC->DHR8R2 = 0xffffffff;
  dac_set_channel_8bit_right_aligned_data(DAC_CHANNEL2, 0x100);
  ASSERT_EQ(DAC->DHR8R2, 0x100);
  ASSERT_TRUE(execution_halted());
  execution_resume();

#endif

}

// └─Skipping type 'fn_set_value (TODO)' (dac_set_channels_12bit_right_aligned_data)
// └─Skipping type 'fn_set_value (TODO)' (dac_set_channels_12bit_left_aligned_data)
// └─Skipping type 'fn_set_value (TODO)' (dac_set_channels_8bit_data)
void
test_dac_get_channel_output_data(void)
{
  u32 res;

  DAC->DOR1 = 0;
  res = dac_get_channel_output_data(DAC_CHANNEL1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->DOR1 = 0xffffffff;
  res = dac_get_channel_output_data(DAC_CHANNEL1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->DOR2 = 0;
  res = dac_get_channel_output_data(DAC_CHANNEL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->DOR2 = 0xffffffff;
  res = dac_get_channel_output_data(DAC_CHANNEL2);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_is_dma_underrun_flag_set(void)
{
  u32 res;

  DAC->SR = 0;
  res = dac_is_dma_underrun_flag_set(DAC_CHANNEL1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->SR = ~(0x1u << 13);
  res = dac_is_dma_underrun_flag_set(DAC_CHANNEL1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->SR = 0x1u << 13;
  res = dac_is_dma_underrun_flag_set(DAC_CHANNEL1);
  ASSERT_EQ(res, 0x1u << 13);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->SR = 0;
  res = dac_is_dma_underrun_flag_set(DAC_CHANNEL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->SR = ~(0x1u << 29);
  res = dac_is_dma_underrun_flag_set(DAC_CHANNEL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  DAC->SR = 0x1u << 29;
  res = dac_is_dma_underrun_flag_set(DAC_CHANNEL2);
  ASSERT_EQ(res, 0x1u << 29);
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_dac_dma_underrun_flag_clear(void)
{
  DAC->SR = 0;
  dac_dma_underrun_flag_clear(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  DAC->SR = ~(1u << 13);
  dac_dma_underrun_flag_clear(DAC_CHANNEL1);
  ASSERT_EQ(DAC->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_DAC_CHANNEL2)
  DAC->SR = 0;
  dac_dma_underrun_flag_clear(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SR, (1u << 29));
  ASSERT_FALSE(execution_halted());

  DAC->SR = ~(1u << 29);
  dac_dma_underrun_flag_clear(DAC_CHANNEL2);
  ASSERT_EQ(DAC->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
    TEST_FUNC(test_dac_channel),
    TEST_FUNC(test_dac_channel_output_buffer),
    TEST_FUNC(test_dac_channel_trigger),
    TEST_FUNC(test_dac_channel_set_trigger),
    TEST_FUNC(test_dac_channel_set_wave),
    TEST_FUNC(test_dac_set_channel_amplitude),
    TEST_FUNC(test_dac_channel_dma),
    TEST_FUNC(test_dac_channel_dma_underrun_interrupt),
    TEST_FUNC(test_dac_channel_software_trigger),
    TEST_FUNC(test_dac_set_channel_12bit_right_aligned_data),
    TEST_FUNC(test_dac_set_channel_12bit_left_aligned_data),
    TEST_FUNC(test_dac_set_channel_8bit_right_aligned_data),
    TEST_FUNC(test_dac_get_channel_output_data),
    TEST_FUNC(test_dac_is_dma_underrun_flag_set),
    TEST_FUNC(test_dac_dma_underrun_flag_clear),
  };

  return TESTS_RUN(tests);
}
