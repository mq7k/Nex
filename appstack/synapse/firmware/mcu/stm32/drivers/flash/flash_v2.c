#include "synapse/stm32/drivers/flash/flash_v2.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct flash_registers_map flash_periph;
flash_periph* FLASH = (flash_periph*) (FLASH_ADDR);

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

    case FLASH_WAIT_STATE3:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS3 << shift);
      break;

    case FLASH_WAIT_STATE4:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS4 << shift);
      break;

    case FLASH_WAIT_STATE5:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS5 << shift);
      break;

    case FLASH_WAIT_STATE6:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS6 << shift);
      break;

    case FLASH_WAIT_STATE7:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS7 << shift);
      break;

    case FLASH_WAIT_STATE8:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS8 << shift);
      break;

    case FLASH_WAIT_STATE9:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS9 << shift);
      break;

    case FLASH_WAIT_STATE10:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS10 << shift);
      break;

    case FLASH_WAIT_STATE11:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS11 << shift);
      break;

    case FLASH_WAIT_STATE12:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS12 << shift);
      break;

    case FLASH_WAIT_STATE13:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS13 << shift);
      break;

    case FLASH_WAIT_STATE14:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS14 << shift);
      break;

    case FLASH_WAIT_STATE15:
      syn_set_register_bits(reg, mask, FLASH_ACR_LATENCY_WS15 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum flash_wait_state, wait_state);
      break;
  }
}

#if defined(STM32_FLASH_PREFETCH)
void
flash_prefetch_enable(void)
{
  FLASH->ACR |= FLASH_ACR_PRFTEN;
}

void
flash_prefetch_disable(void)
{
  FLASH->ACR &= ~FLASH_ACR_PRFTEN;
}
#endif

#if defined(STM32_FLASH_CACHE)
void
flash_cache_enable(
  enum flash_cache cache
)
{
  volatile u32* reg = &FLASH->ACR;
  switch (cache)
  {
    case FLASH_CACHE_INSTRUCTION:
      *reg |= FLASH_ACR_ICEN;
      break;

    case FLASH_CACHE_DATA:
      *reg |= FLASH_ACR_DCEN;
      break;

    default:
      devmode_error_invalid_enum(enum flash_cache, cache);
      break;
  }
}

void
flash_cache_disable(
  enum flash_cache cache
)
{
  volatile u32* reg = &FLASH->ACR;
  switch (cache)
  {
    case FLASH_CACHE_INSTRUCTION:
      *reg &= ~FLASH_ACR_ICEN;
      break;

    case FLASH_CACHE_DATA:
      *reg &= ~FLASH_ACR_DCEN;
      break;

    default:
      devmode_error_invalid_enum(enum flash_cache, cache);
      break;
  }
}

void
flash_cache_reset(
  enum flash_cache cache
)
{
  volatile u32* reg = &FLASH->ACR;
  switch (cache)
  {
    case FLASH_CACHE_INSTRUCTION:
      *reg |= FLASH_ACR_ICRST;
      break;

    case FLASH_CACHE_DATA:
      *reg |= FLASH_ACR_DCRST;
      break;

    default:
      devmode_error_invalid_enum(enum flash_cache, cache);
      break;
  }
}
#endif

#if defined(STM32_FLASH_ART)
void
flash_art_acceleration_enable(void)
{
  FLASH->ACR |= FLASH_ACR_ARTEN;
}

void
flash_art_acceleration_disable(void)
{
  FLASH->ACR &= ~FLASH_ACR_ARTEN;
}

void
flash_art_acceleration_reset(void)
{
  FLASH->ACR |= FLASH_ACR_ARTRST;
}
#endif

void
flash_unlock(void)
{
  FLASH->KEYR = FLASH_KEYR_KEY1;
  FLASH->KEYR = FLASH_KEYR_KEY2;
}

void
flash_option_unlock(void)
{
  FLASH->OPTKEYR = FLASH_OPTKEYR_KEY1;
  FLASH->OPTKEYR = FLASH_OPTKEYR_KEY2;
}

u32
flash_is_flag_set(
  enum flash_flag flag
)
{
#if defined(STM32_FLASH_SR_LAYOUT1)
  volatile u32* reg = &FLASH->SR;
  switch (flag)
  {
    case FLASH_FLAG_EOP:
      return *reg & FLASH_SR_EOP;

    case FLASH_FLAG_OPERATION_ERROR:
      return *reg & FLASH_SR_OPERR;

    case FLASH_FLAG_WRITE_PROTECTION_ERROR:
      return *reg & FLASH_SR_WRPERR;

    case FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR:
      return *reg & FLASH_SR_PGAERR;

    case FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR:
      return *reg & FLASH_SR_PGPERR;

    case FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR:
      return *reg & FLASH_SR_PGSERR;

#if defined(STM32_FLASH_PCROP)
    case FLASH_FLAG_PCROP_ERROR:
      return *reg & FLASH_SR_RDERR;
#endif

    case FLASH_FLAG_BUSY:
      return *reg & FLASH_SR_BSY;

    default:
      devmode_error_invalid_enum(enum flash_flag, flag);
      return 0;
  }
#elif defined(STM32_FLASH_SR_LAYOUT2)
  (void) flag;
  return 0;
#else
  (void) flag;
  return 0;
#endif
}

void
flash_flag_clear(
  enum flash_flag flag
)
{
#if defined(STM32_FLASH_SR_LAYOUT1)
  volatile u32* reg = &FLASH->SR;
  switch (flag)
  {
    case FLASH_FLAG_EOP:
      *reg |= FLASH_SR_EOP;
      break;

    case FLASH_FLAG_OPERATION_ERROR:
      *reg |= FLASH_SR_OPERR;
      break;

    case FLASH_FLAG_WRITE_PROTECTION_ERROR:
      *reg |= FLASH_SR_WRPERR;
      break;

    case FLASH_FLAG_PROGRAMMING_ALIGNMENT_ERROR:
      *reg |= FLASH_SR_PGAERR;
      break;

    case FLASH_FLAG_PROGRAMMING_PARALLELISM_ERROR:
      *reg |= FLASH_SR_PGPERR;
      break;

    case FLASH_FLAG_PROGRAMMING_SEQUENCE_ERROR:
      *reg |= FLASH_SR_PGSERR;
      break;

#if defined(STM32_FLASH_PCROP)
    case FLASH_FLAG_PCROP_ERROR:
      *reg |= FLASH_SR_RDERR;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum flash_flag, flag);
      break;
  }
#elif defined(STM32_FLASH_SR_LAYOUT2)
#else
  (void) flag;
#endif
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
flash_sector_erase_enable(void)
{
  FLASH->CR |= FLASH_CR_SER;
}

void
flash_sector_erase_disable(void)
{
  FLASH->CR &= ~FLASH_CR_SER;
}

void
flash_mass_erase_bank1_enable(void)
{
  FLASH->CR |= FLASH_CR_MER;
}

void
flash_mass_erase_bank1_disable(void)
{
  FLASH->CR &= ~FLASH_CR_MER;
}

void
flash_set_sector_number(
  u32 sector_number
)
{
  devmode_assert_lower_or_eq(sector_number, FLASH_CR_SNB_MASK);
  constexpr u32 shift = FLASH_CR_SNB_SHIFT;
  constexpr u32 mask = FLASH_CR_SNB_MASK << shift;
  volatile u32* reg = &FLASH->CR;
  syn_set_register_bits(reg, mask, sector_number << shift);
}

void
flash_set_program_size(
  enum flash_program_size size
)
{
  constexpr u32 shift = FLASH_CR_PSIZE_SHIFT;
  constexpr u32 mask = FLASH_CR_PSIZE_MASK << shift;
  volatile u32* reg = &FLASH->CR;

  switch (size)
  {
    case FLASH_PROGRAM_SIZE_x8:
      *reg &= ~mask;
      break;

    case FLASH_PROGRAM_SIZE_x16:
      syn_set_register_bits(reg, mask, FLASH_CR_PSIZE_x16 << shift);
      break;

    case FLASH_PROGRAM_SIZE_x32:
      syn_set_register_bits(reg, mask, FLASH_CR_PSIZE_x32 << shift);
      break;

    case FLASH_PROGRAM_SIZE_x64:
      *reg |= (FLASH_CR_PSIZE_x64 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum flash_program_size, size);
      break;
  }
}

#if defined(STM32_FLASH_MASS_ERASE_BANK2)
void
flash_mass_erase_bank2_enable(void)
{
  FLASH->CR |= FLASH_CR_MER1;
}

void
flash_mass_erase_bank2_disable(void)
{
  FLASH->CR &= ~FLASH_CR_MER1;
}
#endif

void
flash_erase_start(void)
{
  FLASH->CR |= FLASH_CR_STRT;
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
flash_lock(void)
{
  FLASH->CR |= FLASH_CR_LOCK;
}

void
flash_option_lock(void)
{
  FLASH->OPTCR |= FLASH_OPTCR_OPTLOCK;
}

void
flash_option_start(void)
{
  FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;
}

void
flash_set_bor_level(
  enum flash_bor_level level
)
{
  constexpr u32 shift = FLASH_OPTCR_BORLEV_SHIFT;
  constexpr u32 mask = FLASH_OPTCR_BORLEV_MASK << shift;
  volatile u32* reg = &FLASH->OPTCR;

  switch (level)
  {
    case FLASH_BOR_LEVEL3:
      *reg &= ~mask;
      break;

    case FLASH_BOR_LEVEL2:
      syn_set_register_bits(reg, mask, FLASH_OPTCR_BORLEV_LEVEL2 << shift);
      break;

    case FLASH_BOR_LEVEL1:
      *reg |= (FLASH_OPTCR_BORLEV_LEVEL1 << shift);
      break;

    case FLASH_BOR_LEVEL_OFF:
      *reg |= mask;
      break;

    default:
      devmode_error_invalid_enum(enum flash_bor_level, level);
      break;
  }
}

#if defined(STM32_FLASH_DUALBANK)
void
flash_set_dual_bank_boot_option_enable(void)
{
  FLASH->OPTCR |= FLASH_OPTCR_BFB2;
}

void
flash_set_dual_bank_boot_option_disable(void)
{
  FLASH->OPTCR &= ~FLASH_OPTCR_BFB2;
}
#endif

void
flash_user_option_byte_enable(
  enum flash_user_option_byte option
)
{
  volatile u32* reg = &FLASH->OPTCR;
  switch (option)
  {
    case FLASH_USER_OPTION_BYTE_RST_STANDBY:
      *reg |= FLASH_OPTCR_RSTSTDBY;
      break;

    case FLASH_USER_OPTION_BYTE_RST_STOP:
      *reg |= FLASH_OPTCR_RSTSTOP;
      break;
      
    case FLASH_USER_OPTION_BYTE_IWDG_SW:
      *reg |= FLASH_OPTCR_WDGSW;
      break;

#if defined(STM32_FLASH_WWDG)
    case FLASH_USER_OPTION_BYTE_WWDG_SW:
      *reg |= FLASH_OPTCR_WWDGSW;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum flash_user_option_byte, option);
      break;
  }
}

void
flash_user_option_byte_disable(
  enum flash_user_option_byte option
)
{
  volatile u32* reg = &FLASH->OPTCR;
  switch (option)
  {
    case FLASH_USER_OPTION_BYTE_RST_STANDBY:
      *reg &= ~FLASH_OPTCR_RSTSTDBY;
      break;

    case FLASH_USER_OPTION_BYTE_RST_STOP:
      *reg &= ~FLASH_OPTCR_RSTSTOP;
      break;
      
    case FLASH_USER_OPTION_BYTE_IWDG_SW:
      *reg &= ~FLASH_OPTCR_WDGSW;
      break;

#if defined(STM32_FLASH_WWDG)
    case FLASH_USER_OPTION_BYTE_WWDG_SW:
      *reg &= ~FLASH_OPTCR_WWDGSW;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum flash_user_option_byte, option);
      break;
  }
}

void
flash_set_read_protection_level(
  enum flash_read_protection_level level
)
{
  constexpr u32 shift = FLASH_OPTCR_RDP_SHIFT;
  constexpr u32 mask = FLASH_OPTCR_RDP_MASK << shift;
  volatile u32* reg = &FLASH->OPTCR;

  switch (level)
  {
    case FLASH_READ_PROTECTION_LEVEL0:
      syn_set_register_bits(reg, mask, FLASH_OPTCR_RDP_LEVEL0 << shift);
      break;

    case FLASH_READ_PROTECTION_LEVEL1:
      syn_set_register_bits(reg, mask, FLASH_OPTCR_RDP_LEVEL1 << shift);
      break;

    case FLASH_READ_PROTECTION_LEVEL2:
      syn_set_register_bits(reg, mask, FLASH_OPTCR_RDP_LEVEL2 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum flash_read_protection_level, level);
      break;
  }
}

u32
flash_get_read_protection_level(void)
{
  constexpr u32 shift = FLASH_OPTCR_RDP_SHIFT;
  constexpr u32 mask = FLASH_OPTCR_RDP_MASK;
  volatile u32* reg = &FLASH->OPTCR;
  return (*reg >> shift) & mask;
}

void
flash_write_protection_enable(
  u32 sector
)
{

#if defined(STM32_FLASH_OPTCR1_WRP)
  if (sector > FLASH_OPTCR_WRP_SECTOR_MAX)
  {
    const u32 sector_norm = sector - FLASH_OPTCR_WRP_SECTOR_MAX;
    devmode_assert_lower_or_eq(sector_norm, FLASH_OPTCR1_WRP_SECTOR_MAX);
    constexpr u32 shift = FLASH_OPTCR1_WRP_SHIFT;
    FLASH->OPTCR1 |= (1u << (sector_norm + shift));
  }
  else
  {
    devmode_assert_lower_or_eq(sector, FLASH_OPTCR_WRP_SECTOR_MAX);
    constexpr u32 shift = FLASH_OPTCR_WRP_SHIFT;
    FLASH->OPTCR |= (1u << (sector + shift));
  }
#else
    devmode_assert_lower_or_eq(sector, FLASH_OPTCR_WRP_SECTOR_MAX);
    constexpr u32 shift = FLASH_OPTCR_WRP_SHIFT;
    FLASH->OPTCR |= (1 << (sector + shift));
#endif
}

void
flash_write_protection_disable(
  u32 sector
)
{
  constexpr u32 shift = FLASH_OPTCR_WRP_SHIFT;
  FLASH->OPTCR &= ~(1u << (sector + shift));
}

u32
flash_is_write_protection_enabled(
  u32 sector
)
{
  constexpr u32 shift = FLASH_OPTCR_WRP_SHIFT;
  return FLASH->OPTCR & (1u << (sector + shift));
}

#if defined(STM32_FLASH_DUALBANK)
void
flash_dual_bank_enable(void)
{
  FLASH->OPTCR |= FLASH_OPTCR_DB1M;
}

void
flash_dual_bank_disable(void)
{
  FLASH->OPTCR &= ~FLASH_OPTCR_DB1M;
}
#endif

#if defined(STM32_FLASH_PROTECTION_MODE)
void
flash_set_protection_mode(
  enum flash_protection_mode mode
)
{
  volatile u32* reg = &FLASH->OPTCR;
  switch (mode)
  {
    case FLASH_PROTECTION_MODE_WRITE:
      *reg &= ~FLASH_OPTCR_SPRMOD;
      break;

    case FLASH_PROTECTION_MODE_PCROP:
      *reg |= FLASH_OPTCR_SPRMOD;
      break;

    default:
      devmode_error_invalid_enum(enum flash_protection_mode, mode);
      break;
  }
}
#endif

#if defined(STM32_FLASH_IWDG_CONFIG)
void
flash_set_iwdg_standby_mode(
  enum flash_iwdg_standby_mode mode
)
{
  volatile u32* reg = &FLASH->OPTCR;
  switch (mode)
  {
    case FLASH_IWDG_STANDBY_MODE_FREEZE:
      *reg &= ~FLASH_OPTCR_IWDGSTDBY;
      break;

    case FLASH_IWDG_STANDBY_MODE_RUNNING:
      *reg |= FLASH_OPTCR_IWDGSTDBY;
      break;

    default:
      devmode_error_invalid_enum(enum flash_iwdg_standby_mode, mode);
      break;
  }
}

void
flash_set_iwdg_stop_mode(
  enum flash_iwdg_stop_mode mode
)
{
  volatile u32* reg = &FLASH->OPTCR;
  switch (mode)
  {
    case FLASH_IWDG_STOP_MODE_FREEZE:
      *reg &= ~FLASH_OPTCR_IWDGSTOP;
      break;

    case FLASH_IWDG_STOP_MODE_RUNNING:
      *reg |= FLASH_OPTCR_IWDGSTOP;
      break;

    default:
      devmode_error_invalid_enum(enum flash_iwdg_stop_mode, mode);
      break;
  }
}
#endif

#if defined(STM32_FLASH_BOOTADD)
void
flash_set_boot_address0(
  u32 address
)
{
  devmode_assert_lower_or_eq(address, FLASH_OPTCR1_BOOTADD0_MASK);
  constexpr u32 shift = FLASH_OPTCR1_BOOTADD0_SHIFT;
  constexpr u32 mask = FLASH_OPTCR1_BOOTADD0_MASK << shift;
  volatile u32* reg = &FLASH->OPTCR1;
  syn_set_register_bits(reg, mask, address << shift);
}

void
flash_set_boot_address1(
  u32 address
)
{
  devmode_assert_lower_or_eq(address, FLASH_OPTCR1_BOOTADD0_MASK);
  constexpr u32 shift = FLASH_OPTCR1_BOOTADD1_SHIFT;
  constexpr u32 mask = FLASH_OPTCR1_BOOTADD1_MASK << shift;
  volatile u32* reg = &FLASH->OPTCR1;
  syn_set_register_bits(reg, mask, address << shift);
}
#endif
