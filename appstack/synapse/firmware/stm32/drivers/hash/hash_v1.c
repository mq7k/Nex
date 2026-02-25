#include "synapse/stm32/drivers/hash/hash_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "synapse/stm32/system/chips/f4/memorymap.h"
#include "synapse/specs.h"

typedef volatile struct hash_registers_map hash_periph;
hash_periph* HASH = (hash_periph*) (HASH_ADDR);

typedef volatile struct hash_digest_registers hash_digests;
hash_digests* HASHHR = (hash_digests*) (HASH_HR1_ADDR);

typedef volatile struct hash_cs_registers hash_cs;
hash_cs* HASHCSR = (hash_cs*) (HASH_CSR_ADDR);

void
hash_init(void)
{
  HASH->CR |= HASH_CR_INIT;
}

void
hash_dma_enable(void)
{
  HASH->CR |= HASH_CR_DMAE;
}

void
hash_dma_disable(void)
{
  HASH->CR &= ~HASH_CR_DMAE;
}

void
hash_set_data_type(
  enum hash_data_type type
)
{
  constexpr u32 shift = HASH_CR_DATATYPE_SHIFT;
  constexpr u32 mask = HASH_CR_DATATYPE_MASK << shift;
  volatile u32* reg = &HASH->CR;

  switch (type)
  {
    case HASH_DATA_TYPE_32BIT:
      *reg &= ~mask;
      break;
      
    case HASH_DATA_TYPE_16BIT:
      syn_set_register_bits(reg, mask, HASH_CR_DATATYPE_16BIT << shift);
      break;

    case HASH_DATA_TYPE_8BIT:
      syn_set_register_bits(reg, mask, HASH_CR_DATATYPE_8BIT << shift);
      break;

    case HASH_DATA_TYPE_BITSTR:
      *reg |= (HASH_CR_DATATYPE_BITSTR << shift);
      break;

    default:
      devmode_error_invalid_enum(enum hash_data_type, type);
      break;
  }
}

void
hash_set_mode(
  enum hash_mode mode
)
{
  volatile u32* reg = &HASH->CR;
  switch (mode)
  {
    case HASH_MODE_HASH:
      *reg &= ~HASH_CR_MODE;
      break;

    case HASH_MODE_HMAC:
      *reg |= HASH_CR_MODE;
      break;

    default:
      devmode_error_invalid_enum(enum hash_mode, mode);
      break;
  }
}

void
hash_set_algorithm(
  enum hash_algorithm algorithm
)
{
#if defined(STM32_HASH_ALGO_EXTENDED)
  constexpr u32 mask = HASH_CR_ALGO1 | HASH_CR_ALGO2;
#else
  constexpr u32 mask = HASH_CR_ALGO1;
#endif

  volatile u32* reg = &HASH->CR;
  switch (algorithm)
  {
    case HASH_ALGORITHM_SHA1:
      *reg &= ~mask;
      break;

    case HASH_ALGORITHM_MD5:
      *reg &= ~mask;
      *reg |= HASH_CR_ALGO1;
      break;

#if defined(STM32_HASH_ALGO_EXTENDED)
    case HASH_ALGORITHM_SHA224:
      *reg &= ~HASH_CR_ALGO1;
      *reg |= HASH_CR_ALGO2;
      break;

    case HASH_ALGORITHM_SHA256:
      *reg |= (HASH_CR_ALGO1 | HASH_CR_ALGO2);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum hash_algorithm, algorithm);
      break;
  }
}

u32
hash_get_transferred_word_count(void)
{
  constexpr u32 shift = HASH_CR_NBW_SHIFT;
  constexpr u32 mask = HASH_CR_NBW_MASK;
  volatile u32* reg = &HASH->CR;
  return (*reg >> shift) & mask;
}

#if defined(STM32_HASH_MULTI_DMA_TRANSFERS)
void
hash_multiple_dma_transfers_enable(void)
{
  HASH->CR &= ~HASH_CR_MDMAT;
}

void
hash_multiple_dma_transfers_disable(void)
{
  HASH->CR |= HASH_CR_MDMAT;
}
#endif

#if defined(STM32_HASH_KEY_TYPE)
void
hash_set_key_type(
  enum hash_key_type type
)
{
  volatile u32* reg = &HASH->CR;
  switch (type)
  {
    case HASH_KEY_TYPE_SHORT:
      *reg &= ~HASH_CR_LKEY;
      break;

    case HASH_KEY_TYPE_LONG:
      *reg |= HASH_CR_LKEY;
      break;

    default:
      devmode_error_invalid_enum(enum hash_key_type, type);
      break;
  }
}
#endif

void
hash_write_data(
  u32 data
)
{
  HASH->DIN = data;
}

void
hash_set_input_valid_bits_count(
  u32 count
)
{
  devmode_assert_lower_or_eq(count, HASH_STR_NBLW_MASK);
  constexpr u32 shift = HASH_STR_NBLW_SHIFT;
  constexpr u32 mask = HASH_STR_NBLW_MASK << shift;
  volatile u32* reg = &HASH->STR;
  syn_set_register_bits(reg, mask, count << shift);
}

void
hash_digest_calc_start(void)
{
  HASH->STR |= HASH_STR_DCAL;
}

u32
hash_read_digest(
  u32 idx
)
{
#if defined(STM32_HASH_HR_8BYTES)
  devmode_assert_lower_or_eq(idx, 8);
  return HASHHR->HR[idx];
#elif defined(STM32_HASH_HR_5BYTES)
  devmode_assert_lower_or_eq(idx, 4);
  return HASH->HRA[idx];
#endif
}

void
hash_interrupt_enable(
  enum hash_interrupt interrupt
)
{
  volatile u32* reg = &HASH->IMR;
  switch (interrupt)
  {
    case HASH_INTERRUPT_DATA_INPUT:
      *reg |= HASH_IMR_DINIE;
      break;

    case HASH_INTERRUPT_DIGEST_CALC_COMPLETE:
      *reg |= HASH_IMR_DCIE;
      break;

    default:
      devmode_error_invalid_enum(enum hash_interrupt, interrupt);
      break;
  }
}

void
hash_interrupt_disable(
  enum hash_interrupt interrupt
)
{
  volatile u32* reg = &HASH->IMR;
  switch (interrupt)
  {
    case HASH_INTERRUPT_DATA_INPUT:
      *reg &= ~HASH_IMR_DINIE;
      break;

    case HASH_INTERRUPT_DIGEST_CALC_COMPLETE:
      *reg &= ~HASH_IMR_DCIE;
      break;

    default:
      devmode_error_invalid_enum(enum hash_interrupt, interrupt);
      break;
  }
}

u32
hash_is_flag_set(
  enum hash_flag flag
)
{
  switch (flag)
  {
    case HASH_FLAG_INPUT_FULL:
      return HASH->CR & HASH_CR_DINNE;

    case HASH_FLAG_DATA_INPUT:
      return HASH->SR & HASH_SR_DINIS;

    case HASH_FLAG_DATA_OUTPUT:
      return HASH->SR & HASH_SR_DCIS;

    case HASH_FLAG_DMA:
      return HASH->SR & HASH_SR_DMAS;

    case HASH_FLAG_BUSY:
      return HASH->SR & HASH_SR_BUSY;

    default:
      devmode_error_invalid_enum(enum hash_flag, flag);
      return 0;
  }
}

void
hash_flag_clear(
  enum hash_flag flag
)
{
  volatile u32* reg = &HASH->SR;
  switch (flag)
  {
    case HASH_FLAG_DATA_INPUT:
      *reg &= ~HASH_SR_DINIS;
      break;

    case HASH_FLAG_DATA_OUTPUT:
      *reg &= ~HASH_SR_DCIS;
      break;

    default:
      devmode_error_invalid_enum(enum hash_flag, flag);
      break;
  }
}

#if defined(STM32_HASH_CSR_REG_COUNT)
void
hash_dump_all(
  struct hash_periph_registers* regs
)
{
  for (u32 i = 0; i < STM32_HASH_CSR_REG_COUNT; ++i)
  {
    regs->buf[i] = HASHCSR->CSR[i];
  }
}
#endif

#if defined(STM32_HASH_CSR_REG_COUNT)
void
hash_restore_all(
  struct hash_periph_registers* regs
)
{
  for (u32 i = 0; i < STM32_HASH_CSR_REG_COUNT; ++i)
  {
    HASHCSR->CSR[i] = regs->buf[i];
  }
}
#endif
