#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/flash/flash_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  FLASH = (struct flash_registers_map*) membuf;
}

void
test_flash_set_wait_state(void)
{
  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE0'}, self.value='0b000', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE0);
  ASSERT_EQ(FLASH->ACR, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE0);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE1'}, self.value='0b001', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE1);
  ASSERT_EQ(FLASH->ACR, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE1);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='ACR', self.shift=0, self.mask='0xf', self.varsmap={'ws': 'FLASH_WAIT_STATE2'}, self.value='0b010', self.ifdef=[], self.halt=False
  FLASH->ACR = 0;
  flash_set_wait_state(FLASH_WAIT_STATE2);
  ASSERT_EQ(FLASH->ACR, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0xfu << 0);
  flash_set_wait_state(FLASH_WAIT_STATE2);
  ASSERT_EQ(FLASH->ACR, ~(0xfu << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());


}

#if defined(STM32_FLASH_HALF_CYCLE_ACCESS)
void
test_flash_half_cycle_access(void)
{
  FLASH->ACR = 0;
  flash_half_cycle_access_enable();
  ASSERT_EQ(FLASH->ACR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 3);
  flash_half_cycle_access_enable();
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = (1u << 3);
  flash_half_cycle_access_disable();
  ASSERT_EQ(FLASH->ACR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = 0xffffffff;
  flash_half_cycle_access_disable();
  ASSERT_EQ(FLASH->ACR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_PREFETCH_BUFFER)
void
test_flash_prefetch_buffer(void)
{
  FLASH->ACR = 0;
  flash_prefetch_buffer_enable();
  ASSERT_EQ(FLASH->ACR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(1u << 4);
  flash_prefetch_buffer_enable();
  ASSERT_EQ(FLASH->ACR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = (1u << 4);
  flash_prefetch_buffer_disable();
  ASSERT_EQ(FLASH->ACR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = 0xffffffff;
  flash_prefetch_buffer_disable();
  ASSERT_EQ(FLASH->ACR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_PREFETCH_BUFFER)
void
test_flash_get_prefetch_buffer_status(void)
{
  u32 res;

  // read_bit
  FLASH->ACR = 0;
  res = flash_get_prefetch_buffer_status();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = ~(0x1u << 5);
  res = flash_get_prefetch_buffer_status();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->ACR = 0x1u << 5;
  res = flash_get_prefetch_buffer_status();
  ASSERT_EQ(res, 0x1u << 5);
  ASSERT_FALSE(execution_halted());

}
#endif

// └─Skipping type 'fn_call (TODO)' (flash_unlock)
// └─Skipping type 'fn_call (TODO)' (flash_option_unlock)
#if defined(STM32_FLASH_EXTENDED)
void
test_flash_is_flag_set(void)
{
  u32 res;

  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 0);
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 0);
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_BUSY);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  FLASH->SR = 0;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 2);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ERROR);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 2);
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_PROGRAMMING_ERROR);
  ASSERT_EQ(res, (1u << 2));
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
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = (1u << 5);
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 5);
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->SR = 0xffffffff;
  res = flash_is_flag_set(FLASH_FLAG_EOP);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_flag_clear(void)
{
  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_BUSY);
  ASSERT_EQ(FLASH->SR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  FLASH->SR = ~(1u << 0);
  flash_flag_clear(FLASH_FLAG_BUSY);
  ASSERT_EQ(FLASH->SR, ~(1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  FLASH->SR = 0;
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_ERROR);
  ASSERT_EQ(FLASH->SR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 2);
  flash_flag_clear(FLASH_FLAG_PROGRAMMING_ERROR);
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
  flash_flag_clear(FLASH_FLAG_EOP);
  ASSERT_EQ(FLASH->SR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FLASH->SR = ~(1u << 5);
  flash_flag_clear(FLASH_FLAG_EOP);
  ASSERT_EQ(FLASH->SR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_programming(void)
{
  FLASH->CR = 0;
  flash_programming_enable(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 0);
  flash_programming_enable(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 0);
  flash_programming_disable(FLASH);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_programming_disable(FLASH);
  ASSERT_EQ(FLASH->CR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_page_erase(void)
{
  FLASH->CR = 0;
  flash_page_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 1);
  flash_page_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 1);
  flash_page_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_page_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_mass_erase(void)
{
  FLASH->CR = 0;
  flash_mass_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 2);
  flash_mass_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 2);
  flash_mass_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_mass_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_option_byte_programming(void)
{
  FLASH->CR = 0;
  flash_option_byte_programming_enable(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 4);
  flash_option_byte_programming_enable(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 4);
  flash_option_byte_programming_disable(FLASH);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_option_byte_programming_disable(FLASH);
  ASSERT_EQ(FLASH->CR, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_option_byte_erase(void)
{
  FLASH->CR = 0;
  flash_option_byte_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 5);
  flash_option_byte_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 5);
  flash_option_byte_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_option_byte_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_erase(void)
{
  FLASH->CR = 0;
  flash_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 6);
  flash_erase_enable(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 6);
  flash_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_erase_disable(FLASH);
  ASSERT_EQ(FLASH->CR, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_lock(void)
{
  FLASH->CR = 0;
  flash_lock(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 7);
  flash_lock(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_option_byte_write(void)
{
  FLASH->CR = 0;
  flash_option_byte_write_enable(FLASH);
  ASSERT_EQ(FLASH->CR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 9);
  flash_option_byte_write_enable(FLASH);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 9);
  flash_option_byte_write_disable(FLASH);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_option_byte_write_disable(FLASH);
  ASSERT_EQ(FLASH->CR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_interrupt(void)
{
  FLASH->CR = 0;
  flash_interrupt_enable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 10);
  flash_interrupt_enable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 10);
  flash_interrupt_disable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_interrupt_disable(FLASH_INTERRUPT_ERROR);
  ASSERT_EQ(FLASH->CR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  FLASH->CR = 0;
  flash_interrupt_enable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 12);
  flash_interrupt_enable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = (1u << 12);
  flash_interrupt_disable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->CR = 0xffffffff;
  flash_interrupt_disable(FLASH_INTERRUPT_EOP);
  ASSERT_EQ(FLASH->CR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_force_option_byte_reload(void)
{
  FLASH->CR = 0;
  flash_force_option_byte_reload();
  ASSERT_EQ(FLASH->CR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  FLASH->CR = ~(1u << 13);
  flash_force_option_byte_reload();
  ASSERT_EQ(FLASH->CR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_set_address(void)
{
  FLASH->AR = 0;
  flash_set_address(0);
  ASSERT_EQ(FLASH->AR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = 0xffffffff;
  flash_set_address(0);
  ASSERT_EQ(FLASH->AR, 0);
  ASSERT_FALSE(execution_halted());


  FLASH->AR = 0;
  flash_set_address(0xffffffff);
  ASSERT_EQ(FLASH->AR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = 0xffffffff;
  flash_set_address(0xffffffff);
  ASSERT_EQ(FLASH->AR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_get_current_address(void)
{
  u32 res;

  // read_reg
  FLASH->AR = 0;
  res = flash_get_current_address();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = 0xffffffff;
  res = flash_get_current_address();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_is_option_set(void)
{
  u32 res;

  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_OPTION_BYTE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 0);
  res = flash_is_option_set(FLASH_OPTION_OPTION_BYTE_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 0);
  res = flash_is_option_set(FLASH_OPTION_OPTION_BYTE_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_OPTION_BYTE_ERROR);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_WDG_SW);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 8);
  res = flash_is_option_set(FLASH_OPTION_WDG_SW);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 8);
  res = flash_is_option_set(FLASH_OPTION_WDG_SW);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_WDG_SW);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_RST_STOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 9);
  res = flash_is_option_set(FLASH_OPTION_RST_STOP);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 9);
  res = flash_is_option_set(FLASH_OPTION_RST_STOP);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_RST_STOP);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_RST_STANDBY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 10);
  res = flash_is_option_set(FLASH_OPTION_RST_STANDBY);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 10);
  res = flash_is_option_set(FLASH_OPTION_RST_STANDBY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_RST_STANDBY);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_FLASH_BOOT0)
  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_BOOT0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 11);
  res = flash_is_option_set(FLASH_OPTION_BOOT0);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 11);
  res = flash_is_option_set(FLASH_OPTION_BOOT0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_BOOT0);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

#endif

  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_BOOT1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 12);
  res = flash_is_option_set(FLASH_OPTION_BOOT1);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 12);
  res = flash_is_option_set(FLASH_OPTION_BOOT1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_BOOT1);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_VDDA_MONITOR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 13);
  res = flash_is_option_set(FLASH_OPTION_VDDA_MONITOR);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 13);
  res = flash_is_option_set(FLASH_OPTION_VDDA_MONITOR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_VDDA_MONITOR);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());


  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_RAM_PARITY_CHECK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 14);
  res = flash_is_option_set(FLASH_OPTION_RAM_PARITY_CHECK);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 14);
  res = flash_is_option_set(FLASH_OPTION_RAM_PARITY_CHECK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_RAM_PARITY_CHECK);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_FLASH_BOOTSEL)
  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_BOOTSEL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 15);
  res = flash_is_option_set(FLASH_OPTION_BOOTSEL);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 15);
  res = flash_is_option_set(FLASH_OPTION_BOOTSEL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_BOOTSEL);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(FLASH_OPTION_SDADC12_VDD_MONITOR)
  FLASH->OBR = 0;
  res = flash_is_option_set(FLASH_OPTION_SDADC12_VDD_MONITOR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = (1u << 13);
  res = flash_is_option_set(FLASH_OPTION_SDADC12_VDD_MONITOR);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = ~(1u << 13);
  res = flash_is_option_set(FLASH_OPTION_SDADC12_VDD_MONITOR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->OBR = 0xffffffff;
  res = flash_is_option_set(FLASH_OPTION_SDADC12_VDD_MONITOR);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_get_read_protection_level(void)
{
  u32 res;

  // read_bits
  FLASH->AR = 0;
  res = flash_get_read_protection_level();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = ~(0x3u << 1);
  res = flash_get_read_protection_level();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = 0x3u << 1;
  res = flash_get_read_protection_level();
  ASSERT_EQ(res, 0x3);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_get_option_data0(void)
{
  u32 res;

  // read_bits
  FLASH->AR = 0;
  res = flash_get_option_data0();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = ~(0xffu << 16);
  res = flash_get_option_data0();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = 0xffu << 16;
  res = flash_get_option_data0();
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_get_option_data1(void)
{
  u32 res;

  // read_bits
  FLASH->AR = 0;
  res = flash_get_option_data1();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = ~(0xffu << 24);
  res = flash_get_option_data1();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->AR = 0xffu << 24;
  res = flash_get_option_data1();
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
test_flash_get_reloaded_option_byte(void)
{
  u32 res;

  // read_reg
  FLASH->WRPR = 0;
  res = flash_get_reloaded_option_byte();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  FLASH->WRPR = 0xffffffff;
  res = flash_get_reloaded_option_byte();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_flash_set_wait_state),
#if defined(STM32_FLASH_HALF_CYCLE_ACCESS)
    TEST_FUNC(test_flash_half_cycle_access),
#endif
#if defined(STM32_FLASH_PREFETCH_BUFFER)
    TEST_FUNC(test_flash_prefetch_buffer),
#endif
#if defined(STM32_FLASH_PREFETCH_BUFFER)
    TEST_FUNC(test_flash_get_prefetch_buffer_status),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_is_flag_set),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_flag_clear),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_programming),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_page_erase),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_mass_erase),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_option_byte_programming),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_option_byte_erase),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_erase),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_lock),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_option_byte_write),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_interrupt),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_force_option_byte_reload),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_set_address),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_get_current_address),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_is_option_set),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_get_read_protection_level),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_get_option_data0),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_get_option_data1),
#endif
#if defined(STM32_FLASH_EXTENDED)
    TEST_FUNC(test_flash_get_reloaded_option_byte),
#endif
  };

  return TESTS_RUN(tests);
}
