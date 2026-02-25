#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/flash/flash_v2.h"
#include "libtest/libtest.h"

void
setup(void)
{
  FLASH = (struct flash_registers_map*) membuf;
}

void
test_flash_set_wait_state(void)
{
  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE0'}, self.value='0b0000', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE0);
  ASSERT_EQ(FLASH->ACR, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE0);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE1'}, self.value='0b0001', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE1);
  ASSERT_EQ(FLASH->ACR, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE1);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE2'}, self.value='0b0010', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE2);
  ASSERT_EQ(FLASH->ACR, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE2);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE3'}, self.value='0b0011', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE3);
  ASSERT_EQ(FLASH->ACR, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE3);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE4'}, self.value='0b0100', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE4);
  ASSERT_EQ(FLASH->ACR, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE4);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE5'}, self.value='0b0101', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE5);
  ASSERT_EQ(FLASH->ACR, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE5);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE6'}, self.value='0b0110', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE6);
  ASSERT_EQ(FLASH->ACR, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE6);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE7'}, self.value='0b0111', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE7);
  ASSERT_EQ(FLASH->ACR, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE7);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE8'}, self.value='0b1000', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE8);
  ASSERT_EQ(FLASH->ACR, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE8);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE9'}, self.value='0b1001', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE9);
  ASSERT_EQ(FLASH->ACR, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE9);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE10'}, self.value='0b1010', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE10);
  ASSERT_EQ(FLASH->ACR, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE10);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE11'}, self.value='0b1011', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE11);
  ASSERT_EQ(FLASH->ACR, (0b1011u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE11);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE12'}, self.value='0b1100', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE12);
  ASSERT_EQ(FLASH->ACR, (0b1100u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE12);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE13'}, self.value='0b1101', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE13);
  ASSERT_EQ(FLASH->ACR, (0b1101u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE13);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE14'}, self.value='0b1110', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE14);
  ASSERT_EQ(FLASH->ACR, (0b1110u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE14);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE15'}, self.value='0b1111', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE15);
  ASSERT_EQ(FLASH->ACR, (0b1111u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE15);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b1111u << 0));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_FLASH_PREFETCH)
void
test_flash_prefetch(void)
{
  FLASH->ACR = 0;
  flash_prefetch_enable();
  ASSERT_EQ(FLASH->ACR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 8);
  flash_prefetch_enable();
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = (1u << 8);
  flash_prefetch_disable();
  ASSERT_EQ(FLASH->ACR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = 0xffffffff;
  flash_prefetch_disable();
  ASSERT_EQ(FLASH->ACR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_CACHE)
void
test_flash_cache(void)
{
  FLASH->ACR = 0;
  flash_cache_enable(FLASH_CACHE_INSTRUCTION);
  ASSERT_EQ(FLASH->ACR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 9);
  flash_cache_enable(FLASH_CACHE_INSTRUCTION);
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = (1u << 9);
  flash_cache_disable(FLASH_CACHE_INSTRUCTION);
  ASSERT_EQ(FLASH->ACR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = 0xffffffff;
  flash_cache_disable(FLASH_CACHE_INSTRUCTION);
  ASSERT_EQ(FLASH->ACR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  FLASH->ACR = 0;
  flash_cache_enable(FLASH_CACHE_DATA);
  ASSERT_EQ(FLASH->ACR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 10);
  flash_cache_enable(FLASH_CACHE_DATA);
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = (1u << 10);
  flash_cache_disable(FLASH_CACHE_DATA);
  ASSERT_EQ(FLASH->ACR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = 0xffffffff;
  flash_cache_disable(FLASH_CACHE_DATA);
  ASSERT_EQ(FLASH->ACR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_FLASH_CACHE)
void
test_flash_cache_reset(void)
{
  FLASH->ACR = 0;
  flash_cache_reset(FLASH_CACHE_INSTRUCTION);
  ASSERT_EQ(FLASH->ACR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 11);
  flash_cache_reset(FLASH_CACHE_INSTRUCTION);
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FLASH->ACR = 0;
  flash_cache_reset(FLASH_CACHE_DATA);
  ASSERT_EQ(FLASH->ACR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 12);
  flash_cache_reset(FLASH_CACHE_DATA);
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_FLASH_ART)
void
test_flash_art_acceleration(void)
{
  FLASH->ACR = 0;
  flash_art_acceleration_enable();
  ASSERT_EQ(FLASH->ACR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 9);
  flash_art_acceleration_enable();
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = (1u << 9);
  flash_art_acceleration_disable();
  ASSERT_EQ(FLASH->ACR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = 0xffffffff;
  flash_art_acceleration_disable();
  ASSERT_EQ(FLASH->ACR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_ART)
void
test_flash_art_acceleration_reset(void)
{
  FLASH->ACR = 0;
  flash_art_acceleration_reset();
  ASSERT_EQ(FLASH->ACR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 11);
  flash_art_acceleration_reset();
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

// └─Skipping type 'fn_call (TODO)' (flash_unlock)
// └─Skipping type 'fn_call (TODO)' (flash_option_unlock)
void
test_flash_is_flag_set(void)
{
  u32 res;

  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 0);
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 0);
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_OPERATION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 1);
  res = flash_is_flag_set(FLASH_FLAG_OPERATION_ERROR);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 1);
  res = flash_is_flag_set(FLASH_FLAG_OPERATION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_OPERATION_ERROR);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_WRITE_PROTECTION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 4);
  res = flash_is_flag_set(FLASH_FLAG_WRITE_PROTECTION_ERROR);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 4);
  res = flash_is_flag_set(FLASH_FLAG_WRITE_PROTECTION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_WRITE_PROTECTION_ERROR);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 5);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 5);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 6);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 6);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 7);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 7);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_FLASH_PCROP)
  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_PCROP_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 8);
  res = flash_is_flag_set(FLASH_FLAG_PCROP_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 8);
  res = flash_is_flag_set(FLASH_FLAG_PCROP_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_PCROP_ERROR);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

#endif

  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 16);
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 16);
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


}

void
test_flash_flag_clear(void)
{
  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_EOP);
  ASSERT_EQ(FLASH->SR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 0);
  flash_flag_clear(FLASH_FLAG_EOP);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_OPERATION_ERROR);
  ASSERT_EQ(FLASH->SR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 1);
  flash_flag_clear(FLASH_FLAG_OPERATION_ERROR);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_WRITE_PROTECTION_ERROR);
  ASSERT_EQ(FLASH->SR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 4);
  flash_flag_clear(FLASH_FLAG_WRITE_PROTECTION_ERROR);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR);
  ASSERT_EQ(FLASH->SR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 5);
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR);
  ASSERT_EQ(FLASH->SR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 6);
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR);
  ASSERT_EQ(FLASH->SR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 7);
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


#if defined(STM32_FLASH_PCROP)
  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_PCROP_ERROR);
  ASSERT_EQ(FLASH->SR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 8);
  flash_flag_clear(FLASH_FLAG_PCROP_ERROR);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

#endif

  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_BUSY);
  ASSERT_EQ(FLASH->SR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FLASH->SR = ~(1u << 16);
  flash_flag_clear(FLASH_FLAG_BUSY);
  ASSERT_EQ(FLASH->SR, ~(1u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_flash_programming(void)
{
  FLASH->CR = 0;
  flash_programming_enable();
  ASSERT_EQ(FLASH->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 0);
  flash_programming_enable();
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 0);
  flash_programming_disable();
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_programming_disable();
  ASSERT_EQ(FLASH->CR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_flash_sector_erase(void)
{
  FLASH->CR = 0;
  flash_sector_erase_enable();
  ASSERT_EQ(FLASH->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 1);
  flash_sector_erase_enable();
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 1);
  flash_sector_erase_disable();
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_sector_erase_disable();
  ASSERT_EQ(FLASH->CR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_flash_mass_erase_bank1(void)
{
  FLASH->CR = 0;
  flash_mass_erase_bank1_enable();
  ASSERT_EQ(FLASH->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 2);
  flash_mass_erase_bank1_enable();
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 2);
  flash_mass_erase_bank1_disable();
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_mass_erase_bank1_disable();
  ASSERT_EQ(FLASH->CR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_FLASH_SNB_4BIT)
void
test_flash_set_sector_number(void)
{
  FLASH->CR = 0;
  flash_set_sector_number(0);
  ASSERT_EQ(FLASH->CR, 0u << 3);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_set_sector_number(0);
  ASSERT_EQ(FLASH->CR, ~(0xfu << 3) | (0u << 3));
  ASSERT_FALSE(execution_halted());


  FLASH->CR = 0;
  flash_set_sector_number(0xf);
  ASSERT_EQ(FLASH->CR, 0xfu << 3);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_set_sector_number(0xf);
  ASSERT_EQ(FLASH->CR, ~(0xfu << 3) | (0xfu << 3));
  ASSERT_FALSE(execution_halted());


  FLASH->CR = 0;
  flash_set_sector_number(0x10);
  ASSERT_EQ(FLASH->CR, 0x10u << 3);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FLASH->CR = 0xffffffff;
  flash_set_sector_number(0x10);
  ASSERT_EQ(FLASH->CR, ~(0xfu << 3) | (0x10u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_FLASH_SNB_5BIT)
void
test_flash_set_sector_number(void)
{
  FLASH->CR = 0;
  flash_set_sector_number(0);
  ASSERT_EQ(FLASH->CR, 0u << 3);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_set_sector_number(0);
  ASSERT_EQ(FLASH->CR, ~(0x1fu << 3) | (0u << 3));
  ASSERT_FALSE(execution_halted());


  FLASH->CR = 0;
  flash_set_sector_number(0x1f);
  ASSERT_EQ(FLASH->CR, 0x1fu << 3);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_set_sector_number(0x1f);
  ASSERT_EQ(FLASH->CR, ~(0x1fu << 3) | (0x1fu << 3));
  ASSERT_FALSE(execution_halted());


  FLASH->CR = 0;
  flash_set_sector_number(0x20);
  ASSERT_EQ(FLASH->CR, 0x20u << 3);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FLASH->CR = 0xffffffff;
  flash_set_sector_number(0x20);
  ASSERT_EQ(FLASH->CR, ~(0x1fu << 3) | (0x20u << 3));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

void
test_flash_set_program_size(void)
{
  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'val': 'FLASH_PROGRAM_SIZE_x8'}, self.value='0b00', self.ifdef=[], self.halt=False
  FLASH->CR = 0;
  flash_set_program_size(FLASH_PROGRAM_SIZE_x8);
  ASSERT_EQ(FLASH->CR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(0x3u << 8);
  flash_set_program_size(FLASH_PROGRAM_SIZE_x8);
  ASSERT_EQ(FLASH->CR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'val': 'FLASH_PROGRAM_SIZE_x16'}, self.value='0b01', self.ifdef=[], self.halt=False
  FLASH->CR = 0;
  flash_set_program_size(FLASH_PROGRAM_SIZE_x16);
  ASSERT_EQ(FLASH->CR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(0x3u << 8);
  flash_set_program_size(FLASH_PROGRAM_SIZE_x16);
  ASSERT_EQ(FLASH->CR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'val': 'FLASH_PROGRAM_SIZE_x32'}, self.value='0b10', self.ifdef=[], self.halt=False
  FLASH->CR = 0;
  flash_set_program_size(FLASH_PROGRAM_SIZE_x32);
  ASSERT_EQ(FLASH->CR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(0x3u << 8);
  flash_set_program_size(FLASH_PROGRAM_SIZE_x32);
  ASSERT_EQ(FLASH->CR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CR', self.shift=8, self.mask='0x3', self.varsmap={'val': 'FLASH_PROGRAM_SIZE_x64'}, self.value='0b11', self.ifdef=[], self.halt=False
  FLASH->CR = 0;
  flash_set_program_size(FLASH_PROGRAM_SIZE_x64);
  ASSERT_EQ(FLASH->CR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(0x3u << 8);
  flash_set_program_size(FLASH_PROGRAM_SIZE_x64);
  ASSERT_EQ(FLASH->CR, ~(0x3u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_FLASH_MASS_ERASE_BANK2)
void
test_flash_mass_erase_bank2(void)
{
  FLASH->CR = 0;
  flash_mass_erase_bank2_enable();
  ASSERT_EQ(FLASH->CR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 15);
  flash_mass_erase_bank2_enable();
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 15);
  flash_mass_erase_bank2_disable();
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_mass_erase_bank2_disable();
  ASSERT_EQ(FLASH->CR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_flash_erase_start(void)
{
  FLASH->CR = 0;
  flash_erase_start();
  ASSERT_EQ(FLASH->CR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 16);
  flash_erase_start();
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_flash_interrupt(void)
{
  FLASH->CR = 0;
  flash_interrupt_enable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, (1u << 25));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 25);
  flash_interrupt_enable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 25);
  flash_interrupt_disable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_interrupt_disable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, ~(1u << 25));
  ASSERT_FALSE(execution_halted());


  FLASH->CR = 0;
  flash_interrupt_enable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, (1u << 24));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 24);
  flash_interrupt_enable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 24);
  flash_interrupt_disable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_interrupt_disable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, ~(1u << 24));
  ASSERT_FALSE(execution_halted());


}

void
test_flash_lock(void)
{
  FLASH->CR = 0;
  flash_lock();
  ASSERT_EQ(FLASH->CR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 31);
  flash_lock();
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_flash_option_lock(void)
{
  FLASH->OPTCR = 0;
  flash_option_lock();
  ASSERT_EQ(FLASH->OPTCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 0);
  flash_option_lock();
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_flash_option_start(void)
{
  FLASH->OPTCR = 0;
  flash_option_start();
  ASSERT_EQ(FLASH->OPTCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 1);
  flash_option_start();
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_flash_set_bor_level(void)
{
  // scope=self.reg='OPTCR', self.shift=2, self.mask='0x3', self.varsmap={'level': 'FLASH_BOR_LEVEL1'}, self.value='0b10', self.ifdef=[], self.halt=False
  FLASH->OPTCR = 0;
  flash_set_bor_level(FLASH_BOR_LEVEL1);
  ASSERT_EQ(FLASH->OPTCR, (0b10u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0x3u << 2);
  flash_set_bor_level(FLASH_BOR_LEVEL1);
  ASSERT_EQ(FLASH->OPTCR, ~(0x3u << 2) | (0b10u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPTCR', self.shift=2, self.mask='0x3', self.varsmap={'level': 'FLASH_BOR_LEVEL2'}, self.value='0b01', self.ifdef=[], self.halt=False
  FLASH->OPTCR = 0;
  flash_set_bor_level(FLASH_BOR_LEVEL2);
  ASSERT_EQ(FLASH->OPTCR, (0b01u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0x3u << 2);
  flash_set_bor_level(FLASH_BOR_LEVEL2);
  ASSERT_EQ(FLASH->OPTCR, ~(0x3u << 2) | (0b01u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPTCR', self.shift=2, self.mask='0x3', self.varsmap={'level': 'FLASH_BOR_LEVEL3'}, self.value='0b00', self.ifdef=[], self.halt=False
  FLASH->OPTCR = 0;
  flash_set_bor_level(FLASH_BOR_LEVEL3);
  ASSERT_EQ(FLASH->OPTCR, (0b00u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0x3u << 2);
  flash_set_bor_level(FLASH_BOR_LEVEL3);
  ASSERT_EQ(FLASH->OPTCR, ~(0x3u << 2) | (0b00u << 2));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPTCR', self.shift=2, self.mask='0x3', self.varsmap={'level': 'FLASH_BOR_LEVEL_OFF'}, self.value='0b11', self.ifdef=[], self.halt=False
  FLASH->OPTCR = 0;
  flash_set_bor_level(FLASH_BOR_LEVEL_OFF);
  ASSERT_EQ(FLASH->OPTCR, (0b11u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0x3u << 2);
  flash_set_bor_level(FLASH_BOR_LEVEL_OFF);
  ASSERT_EQ(FLASH->OPTCR, ~(0x3u << 2) | (0b11u << 2));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_FLASH_DUALBANK)
void
test_flash_set_dual_bank_boot_option(void)
{
  FLASH->OPTCR = 0;
  flash_set_dual_bank_boot_option_enable();
  ASSERT_EQ(FLASH->OPTCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 4);
  flash_set_dual_bank_boot_option_enable();
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 4);
  flash_set_dual_bank_boot_option_disable();
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_set_dual_bank_boot_option_disable();
  ASSERT_EQ(FLASH->OPTCR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_flash_user_option_byte(void)
{
  FLASH->OPTCR = 0;
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_RST_STANDBY);
  ASSERT_EQ(FLASH->OPTCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 7);
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_RST_STANDBY);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 7);
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_RST_STANDBY);
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_RST_STANDBY);
  ASSERT_EQ(FLASH->OPTCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  FLASH->OPTCR = 0;
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_RST_STOP);
  ASSERT_EQ(FLASH->OPTCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 6);
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_RST_STOP);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 6);
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_RST_STOP);
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_RST_STOP);
  ASSERT_EQ(FLASH->OPTCR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  FLASH->OPTCR = 0;
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_IWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 5);
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_IWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 5);
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_IWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_IWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_FLASH_WWDG)
  FLASH->OPTCR = 0;
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_WWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 4);
  flash_user_option_byte_enable(FLASH_USER_OPTION_BYTE_WWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 4);
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_WWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_user_option_byte_disable(FLASH_USER_OPTION_BYTE_WWDG_SW);
  ASSERT_EQ(FLASH->OPTCR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

#endif

}

void
test_flash_set_read_protection_level(void)
{
  // scope=self.reg='OPTCR', self.shift=8, self.mask='0xff', self.varsmap={'level': 'FLASH_READ_PROTECTION_LEVEL0'}, self.value='0xaa', self.ifdef=[], self.halt=False
  FLASH->OPTCR = 0;
  flash_set_read_protection_level(FLASH_READ_PROTECTION_LEVEL0);
  ASSERT_EQ(FLASH->OPTCR, (0xaau << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0xffu << 8);
  flash_set_read_protection_level(FLASH_READ_PROTECTION_LEVEL0);
  ASSERT_EQ(FLASH->OPTCR, ~(0xffu << 8) | (0xaau << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPTCR', self.shift=8, self.mask='0xff', self.varsmap={'level': 'FLASH_READ_PROTECTION_LEVEL1'}, self.value='0xbb', self.ifdef=[], self.halt=False
  FLASH->OPTCR = 0;
  flash_set_read_protection_level(FLASH_READ_PROTECTION_LEVEL1);
  ASSERT_EQ(FLASH->OPTCR, (0xbbu << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0xffu << 8);
  flash_set_read_protection_level(FLASH_READ_PROTECTION_LEVEL1);
  ASSERT_EQ(FLASH->OPTCR, ~(0xffu << 8) | (0xbbu << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='OPTCR', self.shift=8, self.mask='0xff', self.varsmap={'level': 'FLASH_READ_PROTECTION_LEVEL2'}, self.value='0xcc', self.ifdef=[], self.halt=False
  FLASH->OPTCR = 0;
  flash_set_read_protection_level(FLASH_READ_PROTECTION_LEVEL2);
  ASSERT_EQ(FLASH->OPTCR, (0xccu << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0xffu << 8);
  flash_set_read_protection_level(FLASH_READ_PROTECTION_LEVEL2);
  ASSERT_EQ(FLASH->OPTCR, ~(0xffu << 8) | (0xccu << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_flash_get_read_protection_level(void)
{
  u32 res;

  // read_bits
  FLASH->OPTCR = 0;
  res = flash_get_read_protection_level();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(0xffu << 8);
  res = flash_get_read_protection_level();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffu << 8;
  res = flash_get_read_protection_level();
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

// └─Skipping type 'bitmap (todo)' (flash_write_protection)
// └─Skipping type 'bitmap_get (todo)' (flash_is_write_protection_enabled)
#if defined(STM32_FLASH_DUALBANK)
void
test_flash_dual_bank(void)
{
  FLASH->OPTCR = 0;
  flash_dual_bank_enable();
  ASSERT_EQ(FLASH->OPTCR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 30);
  flash_dual_bank_enable();
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 30);
  flash_dual_bank_disable();
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_dual_bank_disable();
  ASSERT_EQ(FLASH->OPTCR, ~(1u << 30));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_PROTECTION_MODE)
void
test_flash_set_protection_mode(void)
{
  FLASH->OPTCR = 0;
  flash_set_protection_mode(FLASH_PROTECTION_MODE_PCROP);
  ASSERT_EQ(FLASH->OPTCR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 31);
  flash_set_protection_mode(FLASH_PROTECTION_MODE_PCROP);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 31);
  flash_set_protection_mode(FLASH_PROTECTION_MODE_WRITE);
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_set_protection_mode(FLASH_PROTECTION_MODE_WRITE);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff & ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_IWDG_CONFIG)
void
test_flash_set_iwdg_standby_mode(void)
{
  FLASH->OPTCR = 0;
  flash_set_iwdg_standby_mode(FLASH_IWDG_STANDBY_MODE_RUNNING);
  ASSERT_EQ(FLASH->OPTCR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 30);
  flash_set_iwdg_standby_mode(FLASH_IWDG_STANDBY_MODE_RUNNING);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 30);
  flash_set_iwdg_standby_mode(FLASH_IWDG_STANDBY_MODE_FREEZE);
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_set_iwdg_standby_mode(FLASH_IWDG_STANDBY_MODE_FREEZE);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff & ~(1u << 30));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_IWDG_CONFIG)
void
test_flash_set_iwdg_stop_mode(void)
{
  FLASH->OPTCR = 0;
  flash_set_iwdg_stop_mode(FLASH_IWDG_STOP_MODE_RUNNING);
  ASSERT_EQ(FLASH->OPTCR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = ~(1u << 31);
  flash_set_iwdg_stop_mode(FLASH_IWDG_STOP_MODE_RUNNING);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = (1u << 31);
  flash_set_iwdg_stop_mode(FLASH_IWDG_STOP_MODE_FREEZE);
  ASSERT_EQ(FLASH->OPTCR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR = 0xffffffff;
  flash_set_iwdg_stop_mode(FLASH_IWDG_STOP_MODE_FREEZE);
  ASSERT_EQ(FLASH->OPTCR, 0xffffffff & ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_BOOTADD)
void
test_flash_set_boot_address0(void)
{
  FLASH->OPTCR1 = 0;
  flash_set_boot_address0(0);
  ASSERT_EQ(FLASH->OPTCR1, 0u << 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR1 = 0xffffffff;
  flash_set_boot_address0(0);
  ASSERT_EQ(FLASH->OPTCR1, ~(0xffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  FLASH->OPTCR1 = 0;
  flash_set_boot_address0(0xffff);
  ASSERT_EQ(FLASH->OPTCR1, 0xffffu << 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR1 = 0xffffffff;
  flash_set_boot_address0(0xffff);
  ASSERT_EQ(FLASH->OPTCR1, ~(0xffffu << 0) | (0xffffu << 0));
  ASSERT_FALSE(execution_halted());


  FLASH->OPTCR1 = 0;
  flash_set_boot_address0(0x10000);
  ASSERT_EQ(FLASH->OPTCR1, 0x10000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FLASH->OPTCR1 = 0xffffffff;
  flash_set_boot_address0(0x10000);
  ASSERT_EQ(FLASH->OPTCR1, ~(0xffffu << 0) | (0x10000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

#if defined(STM32_FLASH_BOOTADD)
void
test_flash_set_boot_address1(void)
{
  FLASH->OPTCR1 = 0;
  flash_set_boot_address1(0);
  ASSERT_EQ(FLASH->OPTCR1, 0u << 16);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR1 = 0xffffffff;
  flash_set_boot_address1(0);
  ASSERT_EQ(FLASH->OPTCR1, ~(0xffffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  FLASH->OPTCR1 = 0;
  flash_set_boot_address1(0xffff);
  ASSERT_EQ(FLASH->OPTCR1, 0xffffu << 16);
  ASSERT_FALSE(execution_halted());

  FLASH->OPTCR1 = 0xffffffff;
  flash_set_boot_address1(0xffff);
  ASSERT_EQ(FLASH->OPTCR1, ~(0xffffu << 16) | (0xffffu << 16));
  ASSERT_FALSE(execution_halted());


  FLASH->OPTCR1 = 0;
  flash_set_boot_address1(0x10000);
  ASSERT_EQ(FLASH->OPTCR1, 0x10000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FLASH->OPTCR1 = 0xffffffff;
  flash_set_boot_address1(0x10000);
  ASSERT_EQ(FLASH->OPTCR1, ~(0xffffu << 16) | (0x10000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_flash_set_wait_state),
#if defined(STM32_FLASH_PREFETCH)
    TEST_FUNC(test_flash_prefetch),
#endif
#if defined(STM32_FLASH_CACHE)
    TEST_FUNC(test_flash_cache),
#endif
#if defined(STM32_FLASH_CACHE)
    TEST_FUNC(test_flash_cache_reset),
#endif
#if defined(STM32_FLASH_ART)
    TEST_FUNC(test_flash_art_acceleration),
#endif
#if defined(STM32_FLASH_ART)
    TEST_FUNC(test_flash_art_acceleration_reset),
#endif
    TEST_FUNC(test_flash_is_flag_set),
    TEST_FUNC(test_flash_flag_clear),
    TEST_FUNC(test_flash_programming),
    TEST_FUNC(test_flash_sector_erase),
    TEST_FUNC(test_flash_mass_erase_bank1),
#if defined(STM32_FLASH_SNB_4BIT)
    TEST_FUNC(test_flash_set_sector_number),
#endif
#if defined(STM32_FLASH_SNB_5BIT)
    TEST_FUNC(test_flash_set_sector_number),
#endif
    TEST_FUNC(test_flash_set_program_size),
#if defined(STM32_FLASH_MASS_ERASE_BANK2)
    TEST_FUNC(test_flash_mass_erase_bank2),
#endif
    TEST_FUNC(test_flash_erase_start),
    TEST_FUNC(test_flash_interrupt),
    TEST_FUNC(test_flash_lock),
    TEST_FUNC(test_flash_option_lock),
    TEST_FUNC(test_flash_option_start),
    TEST_FUNC(test_flash_set_bor_level),
#if defined(STM32_FLASH_DUALBANK)
    TEST_FUNC(test_flash_set_dual_bank_boot_option),
#endif
    TEST_FUNC(test_flash_user_option_byte),
    TEST_FUNC(test_flash_set_read_protection_level),
    TEST_FUNC(test_flash_get_read_protection_level),
#if defined(STM32_FLASH_DUALBANK)
    TEST_FUNC(test_flash_dual_bank),
#endif
#if defined(STM32_FLASH_PROTECTION_MODE)
    TEST_FUNC(test_flash_set_protection_mode),
#endif
#if defined(STM32_FLASH_IWDG_CONFIG)
    TEST_FUNC(test_flash_set_iwdg_standby_mode),
#endif
#if defined(STM32_FLASH_IWDG_CONFIG)
    TEST_FUNC(test_flash_set_iwdg_stop_mode),
#endif
#if defined(STM32_FLASH_BOOTADD)
    TEST_FUNC(test_flash_set_boot_address0),
#endif
#if defined(STM32_FLASH_BOOTADD)
    TEST_FUNC(test_flash_set_boot_address1),
#endif
  };

  return TESTS_RUN(tests);
}
