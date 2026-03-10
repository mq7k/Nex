#include "synapse/stm32/drivers/flash/flash_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct flash_registers_map flash_periph;
flash_periph* FLASH = (flash_periph*) (FLASH_INTERFACE_ADDR);

void
flash_set_wait_state(
  enum flash_wait_state wait_state
)
{
  constexpr u32 shift = FLASH_ACR_LATENCY_SHIFT;
  constexpr u32 mask = FLASH_ACR_LATENCY_MASK << shift;
  volatile u32* reg = &FLASH->ACR;
  
  switch (wait_state)
  {
    case FLASH_WAIT_STATE0:
      *reg &= ~mask;
      break;

    case FLASH_WAIT_STATE1:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS1 << shift);
      break;

    case FLASH_WAIT_STATE2:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS2 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum flash_wait_state, wait_state);
      break;
  }
}

#if defined(STM32_FLASH_HALF_CYCLE_ACCESS)
void
flash_half_cycle_access_enable(void)
{
  FLASH->ACR |= FLASH_ACR_HLFCYA;
}

void
flash_half_cycle_access_disable(void)
{
  FLASH->ACR &= ~FLASH_ACR_HLFCYA;
}
#endif

#if defined(STM32_FLASH_PREFETCH_BUFFER)
void
flash_prefetch_buffer_enable(void)
{
  FLASH->ACR |= FLASH_ACR_PRFTBE;
}

void
flash_prefetch_buffer_disable(void)
{
  FLASH->ACR &= ~FLASH_ACR_PRFTBE;
}

u32
flash_get_prefetch_buffer_status(void)
{
  return FLASH->ACR & FLASH_ACR_PRFTBS;
}
#endif

#if defined(STM32_FLASH_EXTENDED)
void
flash_unlock(void)
{
  FLASH->KEYR = FLASH_KEYR_FKEY;
}

void
flash_option_unlock(void)
{
  FLASH->OPTKEYR = FLASH_OPTKEYR_OPTKEY;
}

u32
flash_is_flag_set(
  enum flash_flag flag
)
{
  volatile u32* reg = &FLASH->SR;
  switch (flag)
  {
    case FLASH_FLAG_BUSY:
      return *reg & FLASH_SR_BSY;

    case FLASH_FLAG_PROGRAMMING_ERROR:
      return *reg & FLASH_SR_PGERR;

    case FLASH_FLAG_WRITE_PROTECTION_ERROR:
      return *reg & FLASH_SR_WRPRTERR;

    case FLASH_FLAG_EOP:
      return *reg & FLASH_SR_EOP;
      
    default:
      devmode_error_invalid_enum(enum flash_flag, flag);
      return 0;
  }
}

void
flash_flag_clear(
  enum flash_flag flag
)
{
  volatile u32* reg = &FLASH->SR;
  switch (flag)
  {
    case FLASH_FLAG_PROGRAMMING_ERROR:
      *reg |= FLASH_SR_PGERR;
      break;

    case FLASH_FLAG_WRITE_PROTECTION_ERROR:
      *reg |= FLASH_SR_WRPRTERR;
      break;

    case FLASH_FLAG_EOP:
      *reg |= FLASH_SR_EOP;
      break;
      
    default:
      devmode_error_invalid_enum(enum flash_flag, flag);
      break;
  }
}

void
flash_programming_enable(void)
{
  FLASH->CR |= FLASH_CR_PG;
}

void
flash_programming_disable(void)
{
  FLASH->CR &= ~FLASH_CR_PG;
}

void
flash_page_erase_enable(void)
{
  FLASH->CR |= FLASH_CR_PER;
}

void
flash_page_erase_disable(void)
{
  FLASH->CR &= ~FLASH_CR_PER;
}

void
flash_mass_erase_enable(void)
{
  FLASH->CR |= FLASH_CR_MER;
}

void
flash_mass_erase_disable(void)
{
  FLASH->CR &= ~FLASH_CR_MER;
}

void
flash_option_byte_programming_enable(void)
{
  FLASH->CR |= FLASH_CR_OPTPG;
}

void
flash_option_byte_programming_disable(void)
{
  FLASH->CR &= ~FLASH_CR_OPTPG;
}

void
flash_option_byte_erase_enable(void)
{
  FLASH->CR |= FLASH_CR_OPTER;
}

void
flash_option_byte_erase_disable(void)
{
  FLASH->CR &= ~FLASH_CR_OPTER;
}

void
flash_erase_start(void)
{
  FLASH->CR |= FLASH_CR_STRT;
}

void
flash_lock(void)
{
  FLASH->CR |= FLASH_CR_LOCK;
}

void
flash_option_byte_write_enable(void)
{
  FLASH->CR |= FLASH_CR_OPTWRE;
}

void
flash_option_byte_write_disable(void)
{
  FLASH->CR &= ~FLASH_CR_OPTWRE;
}

void
flash_interrupt_enable(
  enum flash_interrupt interrupt
)
{
  volatile u32* reg = &FLASH->CR;
  switch (interrupt)
  {
    case FLASH_INTERRUPT_ERROR:
      *reg |= FLASH_CR_ERRIE;
      break;

    case FLASH_INTERRUPT_EOP:
      *reg |= FLASH_CR_EOPIE;
      break;

    default:
      devmode_error_invalid_enum(enum flash_interrupt, interrupt);
      break;
  }
}

void
flash_interrupt_disable(
  enum flash_interrupt interrupt
)
{
  volatile u32* reg = &FLASH->CR;
  switch (interrupt)
  {
    case FLASH_INTERRUPT_ERROR:
      *reg &= ~FLASH_CR_ERRIE;
      break;

    case FLASH_INTERRUPT_EOP:
      *reg &= ~FLASH_CR_EOPIE;
      break;

    default:
      devmode_error_invalid_enum(enum flash_interrupt, interrupt);
      break;
  }
}

void
flash_force_option_byte_reload(void)
{
  FLASH->CR |= FLASH_CR_OBLLAUNCH;
}

void
flash_set_address(
  u32 address
)
{
  FLASH->AR = address;
}

u32
flash_get_current_address(void)
{
  return FLASH->AR;
}

u32
flash_is_option_set(
  enum flash_option option
)
{
  volatile u32* reg = &FLASH->OBR;
  switch (option)
  {
    case FLASH_OPTION_OPTION_BYTE_ERROR:
      return *reg & FLASH_OBR_OPTERR;

    case FLASH_OPTION_RST_STANDBY:
      return *reg & FLASH_OBR_RSTSTDBY;

    case FLASH_OPTION_RST_STOP:
      return *reg & FLASH_OBR_RSTSTOP;

    case FLASH_OPTION_WDG_SW:
      return *reg & FLASH_OBR_WDGSW;

    case FLASH_OPTION_RAM_PARITY_CHECK:
      return *reg & FLASH_OBR_RAM_PARITY_CHECK;

    case FLASH_OPTION_VDDA_MONITOR:
      return *reg & FLASH_OBR_VDDA_MONITOR;

#if defined(STM32_FLASH_BOOT0)
    case FLASH_OPTION_BOOT0:
      return *reg & FLASH_OBR_BOOT0;
#endif

    case FLASH_OPTION_BOOT1:
      return *reg & FLASH_OBR_BOOT1;

#if defined(STM32_FLASH_BOOTSEL)
    case FLASH_OPTION_BOOTSEL:
      return *reg & FLASH_OBR_BOOTSEL;
#elif defined(FLASH_OBR_SDADC12_VDD_MONITOR)
    case FLASH_OPTION_SDADC12_VDD_MONITOR:
      return *reg & FLASH_OBR_SDADC12_VDD_MONITOR;
#endif

    default:
      devmode_error_invalid_enum(enum flash_option, option);
      return 0;
  }
}

u32
flash_get_read_protection_level(void)
{
  constexpr u32 shift = FLASH_OBR_RDPRT_SHIFT;
  constexpr u32 mask = FLASH_OBR_RDPRT_MASK;
  volatile u32* reg = &FLASH->OBR;
  return (*reg >> shift) & mask;
}

u32
flash_get_option_data0(void)
{
  constexpr u32 shift = FLASH_OBR_DATA0_SHIFT;
  constexpr u32 mask = FLASH_OBR_DATA0_MASK;
  volatile u32* reg = &FLASH->OBR;
  return (*reg >> shift) & mask;
}

u32
flash_get_option_data1(void)
{
  constexpr u32 shift = FLASH_OBR_DATA1_SHIFT;
  constexpr u32 mask = FLASH_OBR_DATA1_MASK;
  volatile u32* reg = &FLASH->OBR;
  return (*reg >> shift) & mask;
}

u32
flash_get_reloaded_option_byte(void)
{
  return FLASH->WRPR;
}
#endif
