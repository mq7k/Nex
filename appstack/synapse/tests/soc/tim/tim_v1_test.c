#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/tim/tim_v1.h"
#include "libtest/libtest.h"

volatile struct tim_registers_map* _TIM;

void
setup(void)
{
  _TIM = (struct tim_registers_map*) membuf;
}

void
test_tim_counter(void)
{
  _TIM->CR1 = 0;
  tim_counter_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(1u << 0);
  tim_counter_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = (1u << 0);
  tim_counter_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = 0xffffffff;
  tim_counter_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_update_event(void)
{
  _TIM->CR1 = 0;
  tim_update_event_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(1u << 1);
  tim_update_event_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = (1u << 1);
  tim_update_event_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = 0xffffffff;
  tim_update_event_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_update_request_event_source(void)
{
  _TIM->CR1 = 0;
  tim_set_update_request_event_source(_TIM, TIM_UPDATE_REQUEST_SOURCE_ALL);
  ASSERT_EQ(_TIM->CR1, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(1u << 2);
  tim_set_update_request_event_source(_TIM, TIM_UPDATE_REQUEST_SOURCE_ALL);
  ASSERT_EQ(_TIM->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = (1u << 2);
  tim_set_update_request_event_source(_TIM, TIM_UPDATE_REQUEST_SOURCE_COUNTER_AND_DMA);
  ASSERT_EQ(_TIM->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = 0xffffffff;
  tim_set_update_request_event_source(_TIM, TIM_UPDATE_REQUEST_SOURCE_COUNTER_AND_DMA);
  ASSERT_EQ(_TIM->CR1, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_one_pulse_mode(void)
{
  _TIM->CR1 = 0;
  tim_one_pulse_mode_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(1u << 3);
  tim_one_pulse_mode_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = (1u << 3);
  tim_one_pulse_mode_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = 0xffffffff;
  tim_one_pulse_mode_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_counter_direction(void)
{
  _TIM->CR1 = 0;
  tim_set_counter_direction(_TIM, TIM_COUNTER_DIRECTION_DOWN);
  ASSERT_EQ(_TIM->CR1, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(1u << 4);
  tim_set_counter_direction(_TIM, TIM_COUNTER_DIRECTION_DOWN);
  ASSERT_EQ(_TIM->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = (1u << 4);
  tim_set_counter_direction(_TIM, TIM_COUNTER_DIRECTION_UP);
  ASSERT_EQ(_TIM->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = 0xffffffff;
  tim_set_counter_direction(_TIM, TIM_COUNTER_DIRECTION_UP);
  ASSERT_EQ(_TIM->CR1, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_get_counter_direction(void)
{
  u32 res;

  // read_bit
  _TIM->CR1 = 0;
  res = tim_get_counter_direction(_TIM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x1u << 4);
  res = tim_get_counter_direction(_TIM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = 0x1u << 4;
  res = tim_get_counter_direction(_TIM);
  ASSERT_EQ(res, 0x1u << 4);
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_center_aligned_mode(void)
{
  // scope=self.reg='CR1', self.shift=5, self.mask='0x3', self.varsmap={'mode': 'TIM_CENTER_ALIGNED_MODE_EDGE'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CR1 = 0;
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_EDGE);
  ASSERT_EQ(_TIM->CR1, (0b00u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x3u << 5);
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_EDGE);
  ASSERT_EQ(_TIM->CR1, ~(0x3u << 5) | (0b00u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x3', self.varsmap={'mode': 'TIM_CENTER_ALIGNED_MODE_1'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CR1 = 0;
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_1);
  ASSERT_EQ(_TIM->CR1, (0b01u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x3u << 5);
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_1);
  ASSERT_EQ(_TIM->CR1, ~(0x3u << 5) | (0b01u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x3', self.varsmap={'mode': 'TIM_CENTER_ALIGNED_MODE_2'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->CR1 = 0;
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_2);
  ASSERT_EQ(_TIM->CR1, (0b10u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x3u << 5);
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_2);
  ASSERT_EQ(_TIM->CR1, ~(0x3u << 5) | (0b10u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=5, self.mask='0x3', self.varsmap={'mode': 'TIM_CENTER_ALIGNED_MODE_3'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CR1 = 0;
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_3);
  ASSERT_EQ(_TIM->CR1, (0b11u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x3u << 5);
  tim_set_center_aligned_mode(_TIM, TIM_CENTER_ALIGNED_MODE_3);
  ASSERT_EQ(_TIM->CR1, ~(0x3u << 5) | (0b11u << 5));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_auto_reload_preload(void)
{
  _TIM->CR1 = 0;
  tim_auto_reload_preload_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(1u << 7);
  tim_auto_reload_preload_enable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = (1u << 7);
  tim_auto_reload_preload_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = 0xffffffff;
  tim_auto_reload_preload_disable(_TIM);
  ASSERT_EQ(_TIM->CR1, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_clock_division(void)
{
  // scope=self.reg='CR1', self.shift=8, self.mask='0x3', self.varsmap={'division': 'TIM_CLOCK_DIVISION_NODIV'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CR1 = 0;
  tim_set_clock_division(_TIM, TIM_CLOCK_DIVISION_NODIV);
  ASSERT_EQ(_TIM->CR1, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x3u << 8);
  tim_set_clock_division(_TIM, TIM_CLOCK_DIVISION_NODIV);
  ASSERT_EQ(_TIM->CR1, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=8, self.mask='0x3', self.varsmap={'division': 'TIM_CLOCK_DIVISION_DIV2'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CR1 = 0;
  tim_set_clock_division(_TIM, TIM_CLOCK_DIVISION_DIV2);
  ASSERT_EQ(_TIM->CR1, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x3u << 8);
  tim_set_clock_division(_TIM, TIM_CLOCK_DIVISION_DIV2);
  ASSERT_EQ(_TIM->CR1, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR1', self.shift=8, self.mask='0x3', self.varsmap={'division': 'TIM_CLOCK_DIVISION_DIV4'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->CR1 = 0;
  tim_set_clock_division(_TIM, TIM_CLOCK_DIVISION_DIV4);
  ASSERT_EQ(_TIM->CR1, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->CR1 = ~(0x3u << 8);
  tim_set_clock_division(_TIM, TIM_CLOCK_DIVISION_DIV4);
  ASSERT_EQ(_TIM->CR1, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_cc_preload(void)
{
  _TIM->CR2 = 0;
  tim_cc_preload_enable(_TIM);
  ASSERT_EQ(_TIM->CR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 0);
  tim_cc_preload_enable(_TIM);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 0);
  tim_cc_preload_disable(_TIM);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_cc_preload_disable(_TIM);
  ASSERT_EQ(_TIM->CR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_cc_update_trigger(void)
{
  _TIM->CR2 = 0;
  tim_set_cc_update_trigger(_TIM, TIM_UPDATE_TRIGGER_COMG_BIT_OR_TRGI);
  ASSERT_EQ(_TIM->CR2, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 2);
  tim_set_cc_update_trigger(_TIM, TIM_UPDATE_TRIGGER_COMG_BIT_OR_TRGI);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 2);
  tim_set_cc_update_trigger(_TIM, TIM_UPDATE_TRIGGER_COMG_BIT);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_cc_update_trigger(_TIM, TIM_UPDATE_TRIGGER_COMG_BIT);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_cc_dma_request_source(void)
{
  _TIM->CR2 = 0;
  tim_set_cc_dma_request_source(_TIM, TIM_CC_DMA_REQUEST_SOURCE_UPDATE_EVENT);
  ASSERT_EQ(_TIM->CR2, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 3);
  tim_set_cc_dma_request_source(_TIM, TIM_CC_DMA_REQUEST_SOURCE_UPDATE_EVENT);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 3);
  tim_set_cc_dma_request_source(_TIM, TIM_CC_DMA_REQUEST_SOURCE_CC_EVENT);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_cc_dma_request_source(_TIM, TIM_CC_DMA_REQUEST_SOURCE_CC_EVENT);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_master_mode_trigger(void)
{
  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_RESET'}, self.value='0b000', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_RESET);
  ASSERT_EQ(_TIM->CR2, (0b000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_RESET);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_ENABLE'}, self.value='0b001', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_ENABLE);
  ASSERT_EQ(_TIM->CR2, (0b001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_ENABLE);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_UPDATE'}, self.value='0b010', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_UPDATE);
  ASSERT_EQ(_TIM->CR2, (0b010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_UPDATE);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_COMPARE_PULSE'}, self.value='0b011', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_PULSE);
  ASSERT_EQ(_TIM->CR2, (0b011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_PULSE);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_COMPARE_OC1'}, self.value='0b100', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC1);
  ASSERT_EQ(_TIM->CR2, (0b100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC1);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_COMPARE_OC2'}, self.value='0b101', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC2);
  ASSERT_EQ(_TIM->CR2, (0b101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC2);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_COMPARE_OC3'}, self.value='0b110', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC3);
  ASSERT_EQ(_TIM->CR2, (0b110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC3);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR2', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_MASTER_MODE_TRIGGER_COMPARE_OC4'}, self.value='0b111', self.ifdef=[], self.halt=False
  _TIM->CR2 = 0;
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC4);
  ASSERT_EQ(_TIM->CR2, (0b111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(0x7u << 4);
  tim_set_master_mode_trigger(_TIM, TIM_MASTER_MODE_TRIGGER_COMPARE_OC4);
  ASSERT_EQ(_TIM->CR2, ~(0x7u << 4) | (0b111u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_ti1_mode(void)
{
  _TIM->CR2 = 0;
  tim_set_ti1_mode(_TIM, TIM_TI1_MODE_XOR);
  ASSERT_EQ(_TIM->CR2, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 7);
  tim_set_ti1_mode(_TIM, TIM_TI1_MODE_XOR);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 7);
  tim_set_ti1_mode(_TIM, TIM_TI1_MODE_DEFAULT);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_ti1_mode(_TIM, TIM_TI1_MODE_DEFAULT);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_output_idle_state(void)
{
  _TIM->CR2 = 0;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 8);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 8);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _TIM->CR2 = 0;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1N, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 9);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1N, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 9);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1N, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS1N, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _TIM->CR2 = 0;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 10);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 10);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _TIM->CR2 = 0;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2N, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 11);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2N, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 11);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2N, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS2N, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  _TIM->CR2 = 0;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 12);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 12);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  _TIM->CR2 = 0;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3N, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 13);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3N, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 13);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3N, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS3N, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 13));
  ASSERT_FALSE(execution_halted());


  _TIM->CR2 = 0;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS4, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = ~(1u << 14);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS4, TIM_OC_IDLE_STATE_HIGH);
  ASSERT_EQ(_TIM->CR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = (1u << 14);
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS4, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CR2 = 0xffffffff;
  tim_set_output_idle_state(_TIM, TIM_OC_OUTPUT_OIS4, TIM_OC_IDLE_STATE_LOW);
  ASSERT_EQ(_TIM->CR2, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_slave_mode(void)
{
  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_DISABLED'}, self.value='0b000', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_DISABLED);
  ASSERT_EQ(_TIM->SMCR, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_DISABLED);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_ENCODER_MODE_1'}, self.value='0b001', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_ENCODER_MODE_1);
  ASSERT_EQ(_TIM->SMCR, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_ENCODER_MODE_1);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_ENCODER_MODE_2'}, self.value='0b010', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_ENCODER_MODE_2);
  ASSERT_EQ(_TIM->SMCR, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_ENCODER_MODE_2);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_ENCODER_MODE_3'}, self.value='0b011', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_ENCODER_MODE_3);
  ASSERT_EQ(_TIM->SMCR, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_ENCODER_MODE_3);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_RESET_MODE'}, self.value='0b100', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_RESET_MODE);
  ASSERT_EQ(_TIM->SMCR, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_RESET_MODE);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_GATED_MODE'}, self.value='0b101', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_GATED_MODE);
  ASSERT_EQ(_TIM->SMCR, (0b101u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_GATED_MODE);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_TRIGGER_MODE'}, self.value='0b110', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_TRIGGER_MODE);
  ASSERT_EQ(_TIM->SMCR, (0b110u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_TRIGGER_MODE);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=0, self.mask='0x7', self.varsmap={'mode': 'TIM_SLAVE_MODE_EXTERNAL_CLOCK'}, self.value='0b111', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_EXTERNAL_CLOCK);
  ASSERT_EQ(_TIM->SMCR, (0b111u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 0);
  tim_set_slave_mode(_TIM, TIM_SLAVE_MODE_EXTERNAL_CLOCK);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 0) | (0b111u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_input_trigger(void)
{
  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_INTERNAL_0'}, self.value='0b000', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_0);
  ASSERT_EQ(_TIM->SMCR, (0b000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_0);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_INTERNAL_1'}, self.value='0b001', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_1);
  ASSERT_EQ(_TIM->SMCR, (0b001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_1);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_INTERNAL_2'}, self.value='0b010', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_2);
  ASSERT_EQ(_TIM->SMCR, (0b010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_2);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_INTERNAL_3'}, self.value='0b011', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_3);
  ASSERT_EQ(_TIM->SMCR, (0b011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_INTERNAL_3);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_TI1_EDGE'}, self.value='0b100', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_TI1_EDGE);
  ASSERT_EQ(_TIM->SMCR, (0b100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_TI1_EDGE);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_FILTERED_INPUT_1'}, self.value='0b101', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_FILTERED_INPUT_1);
  ASSERT_EQ(_TIM->SMCR, (0b101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_FILTERED_INPUT_1);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_FILTERED_INPUT_2'}, self.value='0b110', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_FILTERED_INPUT_2);
  ASSERT_EQ(_TIM->SMCR, (0b110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_FILTERED_INPUT_2);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=4, self.mask='0x7', self.varsmap={'trigger': 'TIM_INPUT_TRIGGER_EXTERNAL_TRIGGER'}, self.value='0b111', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_EXTERNAL_TRIGGER);
  ASSERT_EQ(_TIM->SMCR, (0b111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x7u << 4);
  tim_set_input_trigger(_TIM, TIM_INPUT_TRIGGER_EXTERNAL_TRIGGER);
  ASSERT_EQ(_TIM->SMCR, ~(0x7u << 4) | (0b111u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_master_slave_sync(void)
{
  _TIM->SMCR = 0;
  tim_master_slave_sync_enable(_TIM);
  ASSERT_EQ(_TIM->SMCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(1u << 7);
  tim_master_slave_sync_enable(_TIM);
  ASSERT_EQ(_TIM->SMCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = (1u << 7);
  tim_master_slave_sync_disable(_TIM);
  ASSERT_EQ(_TIM->SMCR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = 0xffffffff;
  tim_master_slave_sync_disable(_TIM);
  ASSERT_EQ(_TIM->SMCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_external_trigger_filter(void)
{
  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DISABLED'}, self.value='0b0000', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DISABLED);
  ASSERT_EQ(_TIM->SMCR, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DISABLED);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->SMCR, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N4'}, self.value='0b0010', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->SMCR, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N8'}, self.value='0b0011', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->SMCR, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N6'}, self.value='0b0100', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->SMCR, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->SMCR, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N6'}, self.value='0b0110', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->SMCR, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N8'}, self.value='0b0111', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->SMCR, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N6'}, self.value='0b1000', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->SMCR, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N8'}, self.value='0b1001', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->SMCR, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N5'}, self.value='0b1010', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->SMCR, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N6'}, self.value='0b1011', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->SMCR, (0b1011u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N8'}, self.value='0b1100', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->SMCR, (0b1100u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N5'}, self.value='0b1101', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->SMCR, (0b1101u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N6'}, self.value='0b1110', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->SMCR, (0b1110u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=8, self.mask='0xf', self.varsmap={'filter': 'TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N8'}, self.value='0b1111', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->SMCR, (0b1111u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0xfu << 8);
  tim_set_external_trigger_filter(_TIM, TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->SMCR, ~(0xfu << 8) | (0b1111u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_external_trigger_prescaler(void)
{
  // scope=self.reg='SMCR', self.shift=12, self.mask='0x3', self.varsmap={'prescaler': 'TIM_EXTERNAL_TRIGGER_PRESCALER_OFF'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_OFF);
  ASSERT_EQ(_TIM->SMCR, (0b00u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x3u << 12);
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_OFF);
  ASSERT_EQ(_TIM->SMCR, ~(0x3u << 12) | (0b00u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=12, self.mask='0x3', self.varsmap={'prescaler': 'TIM_EXTERNAL_TRIGGER_PRESCALER_DIV2'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_DIV2);
  ASSERT_EQ(_TIM->SMCR, (0b01u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x3u << 12);
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_DIV2);
  ASSERT_EQ(_TIM->SMCR, ~(0x3u << 12) | (0b01u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=12, self.mask='0x3', self.varsmap={'prescaler': 'TIM_EXTERNAL_TRIGGER_PRESCALER_DIV4'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_DIV4);
  ASSERT_EQ(_TIM->SMCR, (0b10u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x3u << 12);
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_DIV4);
  ASSERT_EQ(_TIM->SMCR, ~(0x3u << 12) | (0b10u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='SMCR', self.shift=12, self.mask='0x3', self.varsmap={'prescaler': 'TIM_EXTERNAL_TRIGGER_PRESCALER_DIV8'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->SMCR = 0;
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_DIV8);
  ASSERT_EQ(_TIM->SMCR, (0b11u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(0x3u << 12);
  tim_set_external_trigger_prescaler(_TIM, TIM_EXTERNAL_TRIGGER_PRESCALER_DIV8);
  ASSERT_EQ(_TIM->SMCR, ~(0x3u << 12) | (0b11u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_external_clock(void)
{
  _TIM->SMCR = 0;
  tim_external_clock_enable(_TIM);
  ASSERT_EQ(_TIM->SMCR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(1u << 14);
  tim_external_clock_enable(_TIM);
  ASSERT_EQ(_TIM->SMCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = (1u << 14);
  tim_external_clock_disable(_TIM);
  ASSERT_EQ(_TIM->SMCR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = 0xffffffff;
  tim_external_clock_disable(_TIM);
  ASSERT_EQ(_TIM->SMCR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_external_trigger_polarity(void)
{
  _TIM->SMCR = 0;
  tim_set_external_trigger_polarity(_TIM, TIM_EXTERNAL_TRIGGER_POLARITY_INVERTED);
  ASSERT_EQ(_TIM->SMCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = ~(1u << 15);
  tim_set_external_trigger_polarity(_TIM, TIM_EXTERNAL_TRIGGER_POLARITY_INVERTED);
  ASSERT_EQ(_TIM->SMCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = (1u << 15);
  tim_set_external_trigger_polarity(_TIM, TIM_EXTERNAL_TRIGGER_POLARITY_NON_INVERTED);
  ASSERT_EQ(_TIM->SMCR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SMCR = 0xffffffff;
  tim_set_external_trigger_polarity(_TIM, TIM_EXTERNAL_TRIGGER_POLARITY_NON_INVERTED);
  ASSERT_EQ(_TIM->SMCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_interrupt(void)
{
  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_UPDATE);
  ASSERT_EQ(_TIM->DIER, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 0);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_UPDATE);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 0);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_UPDATE);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_UPDATE);
  ASSERT_EQ(_TIM->DIER, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC1);
  ASSERT_EQ(_TIM->DIER, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 1);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC1);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 1);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC1);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC1);
  ASSERT_EQ(_TIM->DIER, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC2);
  ASSERT_EQ(_TIM->DIER, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 2);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC2);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 2);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC2);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC2);
  ASSERT_EQ(_TIM->DIER, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC3);
  ASSERT_EQ(_TIM->DIER, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 3);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC3);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 3);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC3);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC3);
  ASSERT_EQ(_TIM->DIER, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC4);
  ASSERT_EQ(_TIM->DIER, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 4);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_CC4);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 4);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC4);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_CC4);
  ASSERT_EQ(_TIM->DIER, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_COM);
  ASSERT_EQ(_TIM->DIER, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 5);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_COM);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 5);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_COM);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_COM);
  ASSERT_EQ(_TIM->DIER, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_TRIGGER);
  ASSERT_EQ(_TIM->DIER, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 6);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_TRIGGER);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 6);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_TRIGGER);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_TRIGGER);
  ASSERT_EQ(_TIM->DIER, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_BREAK);
  ASSERT_EQ(_TIM->DIER, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 7);
  tim_interrupt_enable(_TIM, TIM_INTERRUPT_BREAK);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 7);
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_BREAK);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_interrupt_disable(_TIM, TIM_INTERRUPT_BREAK);
  ASSERT_EQ(_TIM->DIER, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_dma_request(void)
{
  _TIM->DIER = 0;
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_UPDATE);
  ASSERT_EQ(_TIM->DIER, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 8);
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_UPDATE);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 8);
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_UPDATE);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_UPDATE);
  ASSERT_EQ(_TIM->DIER, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC1);
  ASSERT_EQ(_TIM->DIER, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 9);
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC1);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 9);
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC1);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC1);
  ASSERT_EQ(_TIM->DIER, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC2);
  ASSERT_EQ(_TIM->DIER, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 10);
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC2);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 10);
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC2);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC2);
  ASSERT_EQ(_TIM->DIER, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC3);
  ASSERT_EQ(_TIM->DIER, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 11);
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC3);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 11);
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC3);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC3);
  ASSERT_EQ(_TIM->DIER, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC4);
  ASSERT_EQ(_TIM->DIER, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 12);
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_CC4);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 12);
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC4);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_CC4);
  ASSERT_EQ(_TIM->DIER, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_COM);
  ASSERT_EQ(_TIM->DIER, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 13);
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_COM);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 13);
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_COM);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_COM);
  ASSERT_EQ(_TIM->DIER, ~(1u << 13));
  ASSERT_FALSE(execution_halted());


  _TIM->DIER = 0;
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_TRIGGER);
  ASSERT_EQ(_TIM->DIER, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = ~(1u << 14);
  tim_dma_request_enable(_TIM, TIM_DMA_MODE_TRIGGER);
  ASSERT_EQ(_TIM->DIER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = (1u << 14);
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_TRIGGER);
  ASSERT_EQ(_TIM->DIER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DIER = 0xffffffff;
  tim_dma_request_disable(_TIM, TIM_DMA_MODE_TRIGGER);
  ASSERT_EQ(_TIM->DIER, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_is_flag_set(void)
{
  u32 res;

  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_UPDATE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 0);
  res = tim_is_flag_set(_TIM, TIM_FLAG_UPDATE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 0);
  res = tim_is_flag_set(_TIM, TIM_FLAG_UPDATE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_UPDATE);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 1);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_INTERRUPT);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 1);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_INTERRUPT);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 2);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_INTERRUPT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 2);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_INTERRUPT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 3);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_INTERRUPT);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 3);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_INTERRUPT);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 4);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_INTERRUPT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 4);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_INTERRUPT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_COM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 5);
  res = tim_is_flag_set(_TIM, TIM_FLAG_COM);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 5);
  res = tim_is_flag_set(_TIM, TIM_FLAG_COM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_COM);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_TRIGGER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 6);
  res = tim_is_flag_set(_TIM, TIM_FLAG_TRIGGER);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 6);
  res = tim_is_flag_set(_TIM, TIM_FLAG_TRIGGER);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_TRIGGER);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_BREAK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 7);
  res = tim_is_flag_set(_TIM, TIM_FLAG_BREAK);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 7);
  res = tim_is_flag_set(_TIM, TIM_FLAG_BREAK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_BREAK);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 9);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 9);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC1_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 10);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 10);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC2_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 11);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 11);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC3_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = 0;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = (1u << 12);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->SR = ~(1u << 12);
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_OVERCAPTURE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  res = tim_is_flag_set(_TIM, TIM_FLAG_CC4_OVERCAPTURE);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_flag_clear(void)
{
  _TIM->SR = (1u << 0);
  tim_flag_clear(_TIM, TIM_FLAG_UPDATE);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_UPDATE);
  ASSERT_EQ(_TIM->SR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 1);
  tim_flag_clear(_TIM, TIM_FLAG_CC1_INTERRUPT);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC1_INTERRUPT);
  ASSERT_EQ(_TIM->SR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 2);
  tim_flag_clear(_TIM, TIM_FLAG_CC2_INTERRUPT);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC2_INTERRUPT);
  ASSERT_EQ(_TIM->SR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 3);
  tim_flag_clear(_TIM, TIM_FLAG_CC3_INTERRUPT);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC3_INTERRUPT);
  ASSERT_EQ(_TIM->SR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 4);
  tim_flag_clear(_TIM, TIM_FLAG_CC4_INTERRUPT);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC4_INTERRUPT);
  ASSERT_EQ(_TIM->SR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 5);
  tim_flag_clear(_TIM, TIM_FLAG_COM);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_COM);
  ASSERT_EQ(_TIM->SR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 6);
  tim_flag_clear(_TIM, TIM_FLAG_TRIGGER);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_TRIGGER);
  ASSERT_EQ(_TIM->SR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 7);
  tim_flag_clear(_TIM, TIM_FLAG_BREAK);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_BREAK);
  ASSERT_EQ(_TIM->SR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 9);
  tim_flag_clear(_TIM, TIM_FLAG_CC1_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC1_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 10);
  tim_flag_clear(_TIM, TIM_FLAG_CC2_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC2_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 11);
  tim_flag_clear(_TIM, TIM_FLAG_CC3_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC3_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  _TIM->SR = (1u << 12);
  tim_flag_clear(_TIM, TIM_FLAG_CC4_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->SR = 0xffffffff;
  tim_flag_clear(_TIM, TIM_FLAG_CC4_OVERCAPTURE);
  ASSERT_EQ(_TIM->SR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_trigger_event_generation(void)
{
  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_UPDATE);
  ASSERT_EQ(_TIM->EGR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 0);
  tim_trigger_event_generation(_TIM, TIM_EVENT_UPDATE);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC1);
  ASSERT_EQ(_TIM->EGR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 1);
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC1);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC2);
  ASSERT_EQ(_TIM->EGR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 2);
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC2);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC3);
  ASSERT_EQ(_TIM->EGR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 3);
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC3);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC4);
  ASSERT_EQ(_TIM->EGR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 4);
  tim_trigger_event_generation(_TIM, TIM_EVENT_CC4);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_COM);
  ASSERT_EQ(_TIM->EGR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 5);
  tim_trigger_event_generation(_TIM, TIM_EVENT_COM);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_TRIGGER);
  ASSERT_EQ(_TIM->EGR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 6);
  tim_trigger_event_generation(_TIM, TIM_EVENT_TRIGGER);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _TIM->EGR = 0;
  tim_trigger_event_generation(_TIM, TIM_EVENT_BREAK);
  ASSERT_EQ(_TIM->EGR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->EGR = ~(1u << 7);
  tim_trigger_event_generation(_TIM, TIM_EVENT_BREAK);
  ASSERT_EQ(_TIM->EGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'enum_set (TODO)' (tim_set_channel_direction)
void
test_tim_set_channel_ic_prescaler(void)
{
  // scope=self.reg='CCMR1', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL1', 'prescaler': 'TIM_IC_PRESCALER_NOSKIP'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR1, (0b00u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 2) | (0b00u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL1', 'prescaler': 'TIM_IC_PRESCALER_SKIP_2'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR1, (0b01u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 2) | (0b01u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL1', 'prescaler': 'TIM_IC_PRESCALER_SKIP_4'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR1, (0b10u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 2) | (0b10u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL1', 'prescaler': 'TIM_IC_PRESCALER_SKIP_8'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR1, (0b11u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL1, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 2) | (0b11u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL2', 'prescaler': 'TIM_IC_PRESCALER_NOSKIP'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR1, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL2', 'prescaler': 'TIM_IC_PRESCALER_SKIP_2'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR1, (0b01u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 10) | (0b01u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL2', 'prescaler': 'TIM_IC_PRESCALER_SKIP_4'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR1, (0b10u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 10) | (0b10u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL2', 'prescaler': 'TIM_IC_PRESCALER_SKIP_8'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR1, (0b11u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL2, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR1, ~(0x3u << 10) | (0b11u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL3', 'prescaler': 'TIM_IC_PRESCALER_NOSKIP'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR2, (0b00u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 2) | (0b00u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL3', 'prescaler': 'TIM_IC_PRESCALER_SKIP_2'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR2, (0b01u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 2) | (0b01u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL3', 'prescaler': 'TIM_IC_PRESCALER_SKIP_4'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR2, (0b10u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 2) | (0b10u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=2, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL3', 'prescaler': 'TIM_IC_PRESCALER_SKIP_8'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR2, (0b11u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 2);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL3, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 2) | (0b11u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL4', 'prescaler': 'TIM_IC_PRESCALER_NOSKIP'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR2, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_NOSKIP);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL4', 'prescaler': 'TIM_IC_PRESCALER_SKIP_2'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR2, (0b01u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_SKIP_2);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 10) | (0b01u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL4', 'prescaler': 'TIM_IC_PRESCALER_SKIP_4'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR2, (0b10u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_SKIP_4);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 10) | (0b10u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=10, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL4', 'prescaler': 'TIM_IC_PRESCALER_SKIP_8'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR2, (0b11u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x3u << 10);
  tim_set_channel_ic_prescaler(_TIM, TIM_CHANNEL4, TIM_IC_PRESCALER_SKIP_8);
  ASSERT_EQ(_TIM->CCMR2, ~(0x3u << 10) | (0b11u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_ic_filter(void)
{
  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_NOFILTER'}, self.value='0b0000', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR1, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_NODIV_N2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR1, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_NODIV_N4'}, self.value='0b0010', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR1, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_NODIV_N8'}, self.value='0b0011', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV2_N6'}, self.value='0b0100', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV2_N8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV4_N6'}, self.value='0b0110', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV4_N8'}, self.value='0b0111', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV8_N6'}, self.value='0b1000', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV8_N8'}, self.value='0b1001', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV16_N5'}, self.value='0b1010', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR1, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV16_N6'}, self.value='0b1011', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b1011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV16_N8'}, self.value='0b1100', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b1100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV32_N5'}, self.value='0b1101', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR1, (0b1101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV32_N6'}, self.value='0b1110', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b1110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL1', 'filter': 'TIM_IC_FILTER_DIV32_N8'}, self.value='0b1111', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b1111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL1, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 4) | (0b1111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_NOFILTER'}, self.value='0b0000', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR1, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_NODIV_N2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR1, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_NODIV_N4'}, self.value='0b0010', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR1, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_NODIV_N8'}, self.value='0b0011', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV2_N6'}, self.value='0b0100', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV2_N8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV4_N6'}, self.value='0b0110', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV4_N8'}, self.value='0b0111', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b0111u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV8_N6'}, self.value='0b1000', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV8_N8'}, self.value='0b1001', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV16_N5'}, self.value='0b1010', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR1, (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV16_N6'}, self.value='0b1011', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b1011u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV16_N8'}, self.value='0b1100', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b1100u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV32_N5'}, self.value='0b1101', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR1, (0b1101u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV32_N6'}, self.value='0b1110', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR1, (0b1110u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL2', 'filter': 'TIM_IC_FILTER_DIV32_N8'}, self.value='0b1111', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR1, (0b1111u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL2, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR1, ~(0xfu << 12) | (0b1111u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_NOFILTER'}, self.value='0b0000', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR2, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_NODIV_N2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR2, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_NODIV_N4'}, self.value='0b0010', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR2, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_NODIV_N8'}, self.value='0b0011', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV2_N6'}, self.value='0b0100', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV2_N8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV4_N6'}, self.value='0b0110', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV4_N8'}, self.value='0b0111', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV8_N6'}, self.value='0b1000', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV8_N8'}, self.value='0b1001', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV16_N5'}, self.value='0b1010', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR2, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV16_N6'}, self.value='0b1011', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b1011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV16_N8'}, self.value='0b1100', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b1100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV32_N5'}, self.value='0b1101', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR2, (0b1101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV32_N6'}, self.value='0b1110', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b1110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL3', 'filter': 'TIM_IC_FILTER_DIV32_N8'}, self.value='0b1111', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b1111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 4);
  tim_set_ic_filter(_TIM, TIM_CHANNEL3, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 4) | (0b1111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_NOFILTER'}, self.value='0b0000', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR2, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NOFILTER);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_NODIV_N2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR2, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NODIV_N2);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_NODIV_N4'}, self.value='0b0010', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR2, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NODIV_N4);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_NODIV_N8'}, self.value='0b0011', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_NODIV_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV2_N6'}, self.value='0b0100', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV2_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV2_N8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV2_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV4_N6'}, self.value='0b0110', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV4_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV4_N8'}, self.value='0b0111', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV4_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b0111u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV8_N6'}, self.value='0b1000', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV8_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV8_N8'}, self.value='0b1001', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV8_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV16_N5'}, self.value='0b1010', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR2, (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV16_N5);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV16_N6'}, self.value='0b1011', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b1011u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV16_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV16_N8'}, self.value='0b1100', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b1100u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV16_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV32_N5'}, self.value='0b1101', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR2, (0b1101u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV32_N5);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV32_N6'}, self.value='0b1110', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR2, (0b1110u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV32_N6);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0xf', self.varsmap={'channel': 'TIM_CHANNEL4', 'filter': 'TIM_IC_FILTER_DIV32_N8'}, self.value='0b1111', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR2, (0b1111u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0xfu << 12);
  tim_set_ic_filter(_TIM, TIM_CHANNEL4, TIM_IC_FILTER_DIV32_N8);
  ASSERT_EQ(_TIM->CCMR2, ~(0xfu << 12) | (0b1111u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_oc_fast(void)
{
  _TIM->CCMR1 = 0;
  tim_oc_fast_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(1u << 2);
  tim_oc_fast_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = (1u << 2);
  tim_oc_fast_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = 0xffffffff;
  tim_oc_fast_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR1 = 0;
  tim_oc_fast_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(1u << 10);
  tim_oc_fast_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = (1u << 10);
  tim_oc_fast_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = 0xffffffff;
  tim_oc_fast_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR2 = 0;
  tim_oc_fast_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(1u << 2);
  tim_oc_fast_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = (1u << 2);
  tim_oc_fast_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = 0xffffffff;
  tim_oc_fast_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR2 = 0;
  tim_oc_fast_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(1u << 10);
  tim_oc_fast_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = (1u << 10);
  tim_oc_fast_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = 0xffffffff;
  tim_oc_fast_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_oc_preload(void)
{
  _TIM->CCMR1 = 0;
  tim_oc_preload_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(1u << 3);
  tim_oc_preload_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = (1u << 3);
  tim_oc_preload_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = 0xffffffff;
  tim_oc_preload_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR1 = 0;
  tim_oc_preload_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(1u << 11);
  tim_oc_preload_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = (1u << 11);
  tim_oc_preload_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = 0xffffffff;
  tim_oc_preload_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR2 = 0;
  tim_oc_preload_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(1u << 3);
  tim_oc_preload_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = (1u << 3);
  tim_oc_preload_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = 0xffffffff;
  tim_oc_preload_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR2 = 0;
  tim_oc_preload_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(1u << 11);
  tim_oc_preload_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = (1u << 11);
  tim_oc_preload_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = 0xffffffff;
  tim_oc_preload_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_oc_mode(void)
{
  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_FROZEN'}, self.value='0b000', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR1, (0b000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_FORCED_HIGH'}, self.value='0b001', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR1, (0b001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_FORCED_LOW'}, self.value='0b010', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR1, (0b010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_TOGGLE'}, self.value='0b011', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR1, (0b011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_FORCE_INACTIVE'}, self.value='0b100', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR1, (0b100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_FORCE_ACTIVE'}, self.value='0b101', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR1, (0b101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_PWM1'}, self.value='0b110', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR1, (0b110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL1', 'mode': 'TIM_OC_MODE_PWM2'}, self.value='0b111', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR1, (0b111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL1, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 4) | (0b111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_FROZEN'}, self.value='0b000', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR1, (0b000u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_FORCED_HIGH'}, self.value='0b001', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR1, (0b001u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_FORCED_LOW'}, self.value='0b010', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR1, (0b010u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_TOGGLE'}, self.value='0b011', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR1, (0b011u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_FORCE_INACTIVE'}, self.value='0b100', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR1, (0b100u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_FORCE_ACTIVE'}, self.value='0b101', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR1, (0b101u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_PWM1'}, self.value='0b110', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR1, (0b110u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR1', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL2', 'mode': 'TIM_OC_MODE_PWM2'}, self.value='0b111', self.ifdef=[], self.halt=False
  _TIM->CCMR1 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR1, (0b111u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL2, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR1, ~(0x7u << 12) | (0b111u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_FROZEN'}, self.value='0b000', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR2, (0b000u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_FORCED_HIGH'}, self.value='0b001', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR2, (0b001u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_FORCED_LOW'}, self.value='0b010', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR2, (0b010u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_TOGGLE'}, self.value='0b011', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR2, (0b011u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_FORCE_INACTIVE'}, self.value='0b100', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR2, (0b100u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_FORCE_ACTIVE'}, self.value='0b101', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR2, (0b101u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_PWM1'}, self.value='0b110', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR2, (0b110u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=4, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL3', 'mode': 'TIM_OC_MODE_PWM2'}, self.value='0b111', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR2, (0b111u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 4);
  tim_set_oc_mode(_TIM, TIM_CHANNEL3, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 4) | (0b111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_FROZEN'}, self.value='0b000', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR2, (0b000u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FROZEN);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_FORCED_HIGH'}, self.value='0b001', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR2, (0b001u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCED_HIGH);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_FORCED_LOW'}, self.value='0b010', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR2, (0b010u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCED_LOW);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_TOGGLE'}, self.value='0b011', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR2, (0b011u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_TOGGLE);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_FORCE_INACTIVE'}, self.value='0b100', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR2, (0b100u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCE_INACTIVE);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_FORCE_ACTIVE'}, self.value='0b101', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR2, (0b101u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_FORCE_ACTIVE);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_PWM1'}, self.value='0b110', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR2, (0b110u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_PWM1);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCMR2', self.shift=12, self.mask='0x7', self.varsmap={'channel': 'TIM_CHANNEL4', 'mode': 'TIM_OC_MODE_PWM2'}, self.value='0b111', self.ifdef=[], self.halt=False
  _TIM->CCMR2 = 0;
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR2, (0b111u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(0x7u << 12);
  tim_set_oc_mode(_TIM, TIM_CHANNEL4, TIM_OC_MODE_PWM2);
  ASSERT_EQ(_TIM->CCMR2, ~(0x7u << 12) | (0b111u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_oc_clear(void)
{
  _TIM->CCMR1 = 0;
  tim_oc_clear_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(1u << 7);
  tim_oc_clear_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = (1u << 7);
  tim_oc_clear_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = 0xffffffff;
  tim_oc_clear_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCMR1, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR1 = 0;
  tim_oc_clear_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = ~(1u << 15);
  tim_oc_clear_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = (1u << 15);
  tim_oc_clear_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR1 = 0xffffffff;
  tim_oc_clear_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCMR1, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR2 = 0;
  tim_oc_clear_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(1u << 7);
  tim_oc_clear_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = (1u << 7);
  tim_oc_clear_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = 0xffffffff;
  tim_oc_clear_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCMR2, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  _TIM->CCMR2 = 0;
  tim_oc_clear_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = ~(1u << 15);
  tim_oc_clear_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = (1u << 15);
  tim_oc_clear_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCMR2 = 0xffffffff;
  tim_oc_clear_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCMR2, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_cc_channel(void)
{
  _TIM->CCER = 0;
  tim_cc_channel_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 0);
  tim_cc_channel_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 0);
  tim_cc_channel_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_cc_channel_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 4);
  tim_cc_channel_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 4);
  tim_cc_channel_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_cc_channel_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 8);
  tim_cc_channel_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 8);
  tim_cc_channel_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_cc_channel_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 12);
  tim_cc_channel_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 12);
  tim_cc_channel_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_ic_channel_polarity(void)
{
  // scope=self.reg='CCER', self.shift=1, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL1', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL1, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b00u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 1);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL1, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 1) | (0b00u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=1, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL1', 'polarity': 'TIM_IC_POLARITY_INVERTED_FALLING_EDGE'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL1, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b01u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 1);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL1, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 1) | (0b01u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=1, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL1', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_BOTH'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL1, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, (0b11u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 1);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL1, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 1) | (0b11u << 1));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=5, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL2', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL2, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b00u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 5);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL2, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 5) | (0b00u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=5, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL2', 'polarity': 'TIM_IC_POLARITY_INVERTED_FALLING_EDGE'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL2, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b01u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 5);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL2, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 5) | (0b01u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=5, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL2', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_BOTH'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL2, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, (0b11u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 5);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL2, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 5) | (0b11u << 5));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=9, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL3', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL3, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b00u << 9));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 9);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL3, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 9) | (0b00u << 9));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=9, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL3', 'polarity': 'TIM_IC_POLARITY_INVERTED_FALLING_EDGE'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL3, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b01u << 9));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 9);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL3, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 9) | (0b01u << 9));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=9, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL3', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_BOTH'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL3, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, (0b11u << 9));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 9);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL3, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 9) | (0b11u << 9));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=13, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL4', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL4, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 13);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL4, TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=13, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL4', 'polarity': 'TIM_IC_POLARITY_INVERTED_FALLING_EDGE'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL4, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, (0b01u << 13));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 13);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL4, TIM_IC_POLARITY_INVERTED_FALLING_EDGE);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 13) | (0b01u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CCER', self.shift=13, self.mask='0x3', self.varsmap={'channel': 'TIM_CHANNEL4', 'polarity': 'TIM_IC_POLARITY_NON_INVERTED_BOTH'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->CCER = 0;
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL4, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, (0b11u << 13));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(0x3u << 13);
  tim_set_ic_channel_polarity(_TIM, TIM_CHANNEL4, TIM_IC_POLARITY_NON_INVERTED_BOTH);
  ASSERT_EQ(_TIM->CCER, ~(0x3u << 13) | (0b11u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_oc_channel_polarity(void)
{
  _TIM->CCER = 0;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL1, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 1);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL1, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 1);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL1, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL1, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL2, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 5);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL2, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 5);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL2, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL2, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL3, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 9);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL3, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 9);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL3, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL3, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL4, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 13);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL4, TIM_OC_POLARITY_ACTIVE_LOW);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 13);
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL4, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_set_oc_channel_polarity(_TIM, TIM_CHANNEL4, TIM_OC_POLARITY_ACTIVE_HIGH);
  ASSERT_EQ(_TIM->CCER, 0xffffffff & ~(1u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_cc_channel_complementary_output(void)
{
  _TIM->CCER = 0;
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 2);
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 2);
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(_TIM->CCER, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 6);
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 6);
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(_TIM->CCER, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = ~(1u << 10);
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = (1u << 10);
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(_TIM->CCER, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  _TIM->CCER = 0;
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _TIM->CCER = ~(1u << 14);
  tim_cc_channel_complementary_output_enable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, ~(1u << 14));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _TIM->CCER = (1u << 14);
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, (1u << 14));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _TIM->CCER = 0xffffffff;
  tim_cc_channel_complementary_output_disable(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(_TIM->CCER, 0xffffffff);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_set_counter_value(void)
{
  _TIM->CNT = 0;
  tim_set_counter_value(_TIM, 0);
  ASSERT_EQ(_TIM->CNT, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CNT = 0;
  tim_set_counter_value(_TIM, 0xffff);
  ASSERT_EQ(_TIM->CNT, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CNT = 0;
  tim_set_counter_value(_TIM, 0x10000);
  ASSERT_EQ(_TIM->CNT, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_get_counter_value(void)
{
  u32 res;

  // read_reg
  _TIM->CNT = 0;
  res = tim_get_counter_value(_TIM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CNT = 0xffffffff;
  res = tim_get_counter_value(_TIM);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_prescaler(void)
{
  _TIM->PSC = 0;
  tim_set_prescaler(_TIM, 0);
  ASSERT_EQ(_TIM->PSC, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->PSC = 0;
  tim_set_prescaler(_TIM, 0xffff);
  ASSERT_EQ(_TIM->PSC, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->PSC = 0;
  tim_set_prescaler(_TIM, 0x10000);
  ASSERT_EQ(_TIM->PSC, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_get_prescaler(void)
{
  u32 res;

  // read_reg
  _TIM->PSC = 0;
  res = tim_get_prescaler(_TIM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->PSC = 0xffffffff;
  res = tim_get_prescaler(_TIM);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_autoreload_value(void)
{
  _TIM->ARR = 0;
  tim_set_autoreload_value(_TIM, 0);
  ASSERT_EQ(_TIM->ARR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->ARR = 0;
  tim_set_autoreload_value(_TIM, 0xffff);
  ASSERT_EQ(_TIM->ARR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->ARR = 0;
  tim_set_autoreload_value(_TIM, 0x10000);
  ASSERT_EQ(_TIM->ARR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_get_autoreload_value(void)
{
  u32 res;

  // read_reg
  _TIM->ARR = 0;
  res = tim_get_autoreload_value(_TIM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->ARR = 0xffffffff;
  res = tim_get_autoreload_value(_TIM);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_repetition_counter(void)
{
  _TIM->RCR = 0;
  tim_set_repetition_counter(_TIM, 0);
  ASSERT_EQ(_TIM->RCR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->RCR = 0;
  tim_set_repetition_counter(_TIM, 0xff);
  ASSERT_EQ(_TIM->RCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->RCR = 0;
  tim_set_repetition_counter(_TIM, 0x100);
  ASSERT_EQ(_TIM->RCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_get_repetition_counter(void)
{
  u32 res;

  // read_reg
  _TIM->RCR = 0;
  res = tim_get_repetition_counter(_TIM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->RCR = 0xffffffff;
  res = tim_get_repetition_counter(_TIM);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_cc_value(void)
{
  _TIM->CCR1 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL1, 0);
  ASSERT_EQ(_TIM->CCR1, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR1 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL1, 0xffff);
  ASSERT_EQ(_TIM->CCR1, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR1 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL1, 0x10000);
  ASSERT_EQ(_TIM->CCR1, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _TIM->CCR2 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL2, 0);
  ASSERT_EQ(_TIM->CCR2, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR2 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL2, 0xffff);
  ASSERT_EQ(_TIM->CCR2, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR2 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL2, 0x10000);
  ASSERT_EQ(_TIM->CCR2, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _TIM->CCR3 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL3, 0);
  ASSERT_EQ(_TIM->CCR3, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR3 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL3, 0xffff);
  ASSERT_EQ(_TIM->CCR3, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR3 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL3, 0x10000);
  ASSERT_EQ(_TIM->CCR3, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _TIM->CCR4 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL4, 0);
  ASSERT_EQ(_TIM->CCR4, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR4 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL4, 0xffff);
  ASSERT_EQ(_TIM->CCR4, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->CCR4 = 0;
  tim_set_cc_value(_TIM, TIM_CHANNEL4, 0x10000);
  ASSERT_EQ(_TIM->CCR4, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_get_cc_value(void)
{
  u32 res;

  // read_reg
  _TIM->CCR1 = 0;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCR1 = 0xffffffff;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  _TIM->CCR2 = 0;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCR2 = 0xffffffff;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL2);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  _TIM->CCR3 = 0;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCR3 = 0xffffffff;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL3);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  _TIM->CCR4 = 0;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->CCR4 = 0xffffffff;
  res = tim_get_cc_value(_TIM, TIM_CHANNEL4);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'fn_set_value (TODO)' (tim_set_deadtime_generator)
void
test_tim_set_dead_time_generator_value(void)
{
  _TIM->BDTR = 0;
  tim_set_dead_time_generator_value(_TIM, 0);
  ASSERT_EQ(_TIM->BDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_set_dead_time_generator_value(_TIM, 0);
  ASSERT_EQ(_TIM->BDTR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _TIM->BDTR = 0;
  tim_set_dead_time_generator_value(_TIM, 0xff);
  ASSERT_EQ(_TIM->BDTR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_set_dead_time_generator_value(_TIM, 0xff);
  ASSERT_EQ(_TIM->BDTR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  _TIM->BDTR = 0;
  tim_set_dead_time_generator_value(_TIM, 0x100);
  ASSERT_EQ(_TIM->BDTR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _TIM->BDTR = 0xffffffff;
  tim_set_dead_time_generator_value(_TIM, 0x100);
  ASSERT_EQ(_TIM->BDTR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_set_lock_configuration(void)
{
  // scope=self.reg='BDTR', self.shift=8, self.mask='0x3', self.varsmap={'config': 'TIM_LOCK_CONFIGURATION_OFF'}, self.value='0b00', self.ifdef=[], self.halt=False
  _TIM->BDTR = 0;
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_OFF);
  ASSERT_EQ(_TIM->BDTR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(0x3u << 8);
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_OFF);
  ASSERT_EQ(_TIM->BDTR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDTR', self.shift=8, self.mask='0x3', self.varsmap={'config': 'TIM_LOCK_CONFIGURATION_LVL1'}, self.value='0b01', self.ifdef=[], self.halt=False
  _TIM->BDTR = 0;
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_LVL1);
  ASSERT_EQ(_TIM->BDTR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(0x3u << 8);
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_LVL1);
  ASSERT_EQ(_TIM->BDTR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDTR', self.shift=8, self.mask='0x3', self.varsmap={'config': 'TIM_LOCK_CONFIGURATION_LVL2'}, self.value='0b10', self.ifdef=[], self.halt=False
  _TIM->BDTR = 0;
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_LVL2);
  ASSERT_EQ(_TIM->BDTR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(0x3u << 8);
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_LVL2);
  ASSERT_EQ(_TIM->BDTR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='BDTR', self.shift=8, self.mask='0x3', self.varsmap={'config': 'TIM_LOCK_CONFIGURATION_LVL3'}, self.value='0b11', self.ifdef=[], self.halt=False
  _TIM->BDTR = 0;
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_LVL3);
  ASSERT_EQ(_TIM->BDTR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(0x3u << 8);
  tim_set_lock_configuration(_TIM, TIM_LOCK_CONFIGURATION_LVL3);
  ASSERT_EQ(_TIM->BDTR, ~(0x3u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_idle_mode_off_state(void)
{
  _TIM->BDTR = 0;
  tim_set_idle_mode_off_state(_TIM, TIM_IDLE_MODE_OFF_STATE_FORCED);
  ASSERT_EQ(_TIM->BDTR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(1u << 10);
  tim_set_idle_mode_off_state(_TIM, TIM_IDLE_MODE_OFF_STATE_FORCED);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = (1u << 10);
  tim_set_idle_mode_off_state(_TIM, TIM_IDLE_MODE_OFF_STATE_OFF);
  ASSERT_EQ(_TIM->BDTR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_set_idle_mode_off_state(_TIM, TIM_IDLE_MODE_OFF_STATE_OFF);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_run_mode_off_state(void)
{
  _TIM->BDTR = 0;
  tim_set_run_mode_off_state(_TIM, TIM_RUN_MODE_OFF_STATE_FORCED);
  ASSERT_EQ(_TIM->BDTR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(1u << 11);
  tim_set_run_mode_off_state(_TIM, TIM_RUN_MODE_OFF_STATE_FORCED);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = (1u << 11);
  tim_set_run_mode_off_state(_TIM, TIM_RUN_MODE_OFF_STATE_OFF);
  ASSERT_EQ(_TIM->BDTR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_set_run_mode_off_state(_TIM, TIM_RUN_MODE_OFF_STATE_OFF);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_break_input(void)
{
  _TIM->BDTR = 0;
  tim_break_input_enable(_TIM);
  ASSERT_EQ(_TIM->BDTR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(1u << 12);
  tim_break_input_enable(_TIM);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = (1u << 12);
  tim_break_input_disable(_TIM);
  ASSERT_EQ(_TIM->BDTR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_break_input_disable(_TIM);
  ASSERT_EQ(_TIM->BDTR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_break_pin_polarity(void)
{
  _TIM->BDTR = 0;
  tim_set_break_pin_polarity(_TIM, TIM_BREAK_PIN_POLARITY_ON);
  ASSERT_EQ(_TIM->BDTR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(1u << 13);
  tim_set_break_pin_polarity(_TIM, TIM_BREAK_PIN_POLARITY_ON);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = (1u << 13);
  tim_set_break_pin_polarity(_TIM, TIM_BREAK_PIN_POLARITY_OFF);
  ASSERT_EQ(_TIM->BDTR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_set_break_pin_polarity(_TIM, TIM_BREAK_PIN_POLARITY_OFF);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff & ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_automatic_output(void)
{
  _TIM->BDTR = 0;
  tim_automatic_output_enable(_TIM);
  ASSERT_EQ(_TIM->BDTR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(1u << 14);
  tim_automatic_output_enable(_TIM);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = (1u << 14);
  tim_automatic_output_disable(_TIM);
  ASSERT_EQ(_TIM->BDTR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_automatic_output_disable(_TIM);
  ASSERT_EQ(_TIM->BDTR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_main_output(void)
{
  _TIM->BDTR = 0;
  tim_main_output_enable(_TIM);
  ASSERT_EQ(_TIM->BDTR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = ~(1u << 15);
  tim_main_output_enable(_TIM);
  ASSERT_EQ(_TIM->BDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = (1u << 15);
  tim_main_output_disable(_TIM);
  ASSERT_EQ(_TIM->BDTR, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->BDTR = 0xffffffff;
  tim_main_output_disable(_TIM);
  ASSERT_EQ(_TIM->BDTR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}

void
test_tim_set_dma_base_address(void)
{
  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CR1'}, self.value='0b00000', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CR1);
  ASSERT_EQ(_TIM->DCR, (0b00000u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CR1);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CR2'}, self.value='0b00001', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CR2);
  ASSERT_EQ(_TIM->DCR, (0b00001u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CR2);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_SMCR'}, self.value='0b00010', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_SMCR);
  ASSERT_EQ(_TIM->DCR, (0b00010u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_SMCR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_DIER'}, self.value='0b00011', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_DIER);
  ASSERT_EQ(_TIM->DCR, (0b00011u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_DIER);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_SR'}, self.value='0b00100', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_SR);
  ASSERT_EQ(_TIM->DCR, (0b00100u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_SR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_EGR'}, self.value='0b00101', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_EGR);
  ASSERT_EQ(_TIM->DCR, (0b00101u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_EGR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CCMR1'}, self.value='0b00110', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCMR1);
  ASSERT_EQ(_TIM->DCR, (0b00110u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCMR1);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CCMR2'}, self.value='0b00111', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCMR2);
  ASSERT_EQ(_TIM->DCR, (0b00111u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCMR2);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b00111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CCER'}, self.value='0b01000', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCER);
  ASSERT_EQ(_TIM->DCR, (0b01000u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCER);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CNT'}, self.value='0b01001', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CNT);
  ASSERT_EQ(_TIM->DCR, (0b01001u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CNT);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_PSC'}, self.value='0b01010', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_PSC);
  ASSERT_EQ(_TIM->DCR, (0b01010u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_PSC);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_ARR'}, self.value='0b01011', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_ARR);
  ASSERT_EQ(_TIM->DCR, (0b01011u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_ARR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_RCR'}, self.value='0b01100', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_RCR);
  ASSERT_EQ(_TIM->DCR, (0b01100u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_RCR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CCR1'}, self.value='0b01101', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR1);
  ASSERT_EQ(_TIM->DCR, (0b01101u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR1);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CCR2'}, self.value='0b01110', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR2);
  ASSERT_EQ(_TIM->DCR, (0b01110u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR2);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CCR3'}, self.value='0b01111', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR3);
  ASSERT_EQ(_TIM->DCR, (0b01111u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR3);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b01111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_CCR4'}, self.value='0b10000', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR4);
  ASSERT_EQ(_TIM->DCR, (0b10000u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_CCR4);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b10000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_BDTR'}, self.value='0b10001', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_BDTR);
  ASSERT_EQ(_TIM->DCR, (0b10001u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_BDTR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b10001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_DCR'}, self.value='0b10010', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_DCR);
  ASSERT_EQ(_TIM->DCR, (0b10010u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_DCR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b10010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCR', self.shift=0, self.mask='0x1f', self.varsmap={'register': 'TIM_REGISTER_DMAR'}, self.value='0b10011', self.ifdef=[], self.halt=False
  _TIM->DCR = 0;
  tim_set_dma_base_address(_TIM, TIM_REGISTER_DMAR);
  ASSERT_EQ(_TIM->DCR, (0b10011u << 0));
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = ~(0x1fu << 0);
  tim_set_dma_base_address(_TIM, TIM_REGISTER_DMAR);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 0) | (0b10011u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_tim_set_dma_burst_length(void)
{
  _TIM->DCR = 0;
  tim_set_dma_burst_length(_TIM, 0);
  ASSERT_EQ(_TIM->DCR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = 0xffffffff;
  tim_set_dma_burst_length(_TIM, 0);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  _TIM->DCR = 0;
  tim_set_dma_burst_length(_TIM, 0x1f);
  ASSERT_EQ(_TIM->DCR, 0x1fu << 8);
  ASSERT_FALSE(execution_halted());

  _TIM->DCR = 0xffffffff;
  tim_set_dma_burst_length(_TIM, 0x1f);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 8) | (0x1fu << 8));
  ASSERT_FALSE(execution_halted());


  _TIM->DCR = 0;
  tim_set_dma_burst_length(_TIM, 0x20);
  ASSERT_EQ(_TIM->DCR, 0x20u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _TIM->DCR = 0xffffffff;
  tim_set_dma_burst_length(_TIM, 0x20);
  ASSERT_EQ(_TIM->DCR, ~(0x1fu << 8) | (0x20u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tim_dma_burst_access_reg_write(void)
{
  _TIM->DMAR = 0;
  tim_dma_burst_access_reg_write(_TIM, 0);
  ASSERT_EQ(_TIM->DMAR, 0u << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->DMAR = 0;
  tim_dma_burst_access_reg_write(_TIM, 0xffff);
  ASSERT_EQ(_TIM->DMAR, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());


  _TIM->DMAR = 0;
  tim_dma_burst_access_reg_write(_TIM, 0x10000);
  ASSERT_EQ(_TIM->DMAR, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_tma_dma_burst_access_reg_read(void)
{
  u32 res;

  // read_reg
  _TIM->DMAR = 0;
  res = tma_dma_burst_access_reg_read(_TIM);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _TIM->DMAR = 0xffffffff;
  res = tma_dma_burst_access_reg_read(_TIM);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_tim_counter),
    TEST_FUNC(test_tim_update_event),
    TEST_FUNC(test_tim_set_update_request_event_source),
    TEST_FUNC(test_tim_one_pulse_mode),
    TEST_FUNC(test_tim_set_counter_direction),
    TEST_FUNC(test_tim_get_counter_direction),
    TEST_FUNC(test_tim_set_center_aligned_mode),
    TEST_FUNC(test_tim_auto_reload_preload),
    TEST_FUNC(test_tim_set_clock_division),
    TEST_FUNC(test_tim_cc_preload),
    TEST_FUNC(test_tim_set_cc_update_trigger),
    TEST_FUNC(test_tim_set_cc_dma_request_source),
    TEST_FUNC(test_tim_set_master_mode_trigger),
    TEST_FUNC(test_tim_set_ti1_mode),
    TEST_FUNC(test_tim_set_output_idle_state),
    TEST_FUNC(test_tim_set_slave_mode),
    TEST_FUNC(test_tim_set_input_trigger),
    TEST_FUNC(test_tim_master_slave_sync),
    TEST_FUNC(test_tim_set_external_trigger_filter),
    TEST_FUNC(test_tim_set_external_trigger_prescaler),
    TEST_FUNC(test_tim_external_clock),
    TEST_FUNC(test_tim_set_external_trigger_polarity),
    TEST_FUNC(test_tim_interrupt),
    TEST_FUNC(test_tim_dma_request),
    TEST_FUNC(test_tim_is_flag_set),
    TEST_FUNC(test_tim_flag_clear),
    TEST_FUNC(test_tim_trigger_event_generation),
    TEST_FUNC(test_tim_set_channel_ic_prescaler),
    TEST_FUNC(test_tim_set_ic_filter),
    TEST_FUNC(test_tim_oc_fast),
    TEST_FUNC(test_tim_oc_preload),
    TEST_FUNC(test_tim_set_oc_mode),
    TEST_FUNC(test_tim_oc_clear),
    TEST_FUNC(test_tim_cc_channel),
    TEST_FUNC(test_tim_set_ic_channel_polarity),
    TEST_FUNC(test_tim_set_oc_channel_polarity),
    TEST_FUNC(test_tim_cc_channel_complementary_output),
    TEST_FUNC(test_tim_set_counter_value),
    TEST_FUNC(test_tim_get_counter_value),
    TEST_FUNC(test_tim_set_prescaler),
    TEST_FUNC(test_tim_get_prescaler),
    TEST_FUNC(test_tim_set_autoreload_value),
    TEST_FUNC(test_tim_get_autoreload_value),
    TEST_FUNC(test_tim_set_repetition_counter),
    TEST_FUNC(test_tim_get_repetition_counter),
    TEST_FUNC(test_tim_set_cc_value),
    TEST_FUNC(test_tim_get_cc_value),
    TEST_FUNC(test_tim_set_dead_time_generator_value),
    TEST_FUNC(test_tim_set_lock_configuration),
    TEST_FUNC(test_tim_set_idle_mode_off_state),
    TEST_FUNC(test_tim_set_run_mode_off_state),
    TEST_FUNC(test_tim_break_input),
    TEST_FUNC(test_tim_set_break_pin_polarity),
    TEST_FUNC(test_tim_automatic_output),
    TEST_FUNC(test_tim_main_output),
    TEST_FUNC(test_tim_set_dma_base_address),
    TEST_FUNC(test_tim_set_dma_burst_length),
    TEST_FUNC(test_tim_dma_burst_access_reg_write),
    TEST_FUNC(test_tma_dma_burst_access_reg_read),
  };

  return TESTS_RUN(tests);
}
