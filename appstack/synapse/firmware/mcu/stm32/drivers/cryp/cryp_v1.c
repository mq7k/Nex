#include "synapse/stm32/drivers/cryp/cryp_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct cryp_registers_map cryp_periph;
cryp_periph* CRYP = (cryp_periph*) (CRYP_ADDR);

void
cryp_set_algorithm_direction(
  enum cryp_algorithm_direction direction
)
{
  volatile u32* reg = &CRYP->CR;
  switch (direction)
  {
    case CRYP_ALGORITHM_DIRECTION_ENCRYPT:
      *reg &= ~CRYP_CR_ALGODIR;
      break;

    case CRYP_ALGORITHM_DIRECTION_DECRYPT:
      *reg |= CRYP_CR_ALGODIR;
      break;

    default:
      devmode_error_invalid_enum(enum cryp_algorithm_direction, direction);
      break;
  }
}

void
cryp_set_algorithm_mode(
  enum cryp_algorithm_mode mode
)
{
  constexpr u32 shift = CRYP_CR_ALGOMODE_SHIFT;
  constexpr u32 mask = CRYP_CR_ALGOMODE_MASK << shift;
  volatile u32* reg = &CRYP->CR;

  switch (mode)
  {
    case CRYP_ALGORITHM_MODE_TDES_ECB:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~(CRYP_CR_ALGOMODE3 | mask);
#else
      *reg &= ~mask;
#endif
      break;

    case CRYP_ALGORITHM_MODE_TDES_CBC:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~CRYP_CR_ALGOMODE3;
#endif
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_TDES_CBC << shift);
      break;

    case CRYP_ALGORITHM_MODE_DES_ECB:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~CRYP_CR_ALGOMODE3;
#endif
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_DES_ECB << shift);
      break;

    case CRYP_ALGORITHM_MODE_DES_CBC:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~CRYP_CR_ALGOMODE3;
#endif
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_DES_CBC << shift);
      break;

    case CRYP_ALGORITHM_MODE_AES_ECB:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~CRYP_CR_ALGOMODE3;
#endif
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_AES_ECB << shift);
      break;

    case CRYP_ALGORITHM_MODE_AES_CBC:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~CRYP_CR_ALGOMODE3;
#endif
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_AES_CBC << shift);
      break;

    case CRYP_ALGORITHM_MODE_AES_CTR:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~CRYP_CR_ALGOMODE3;
#endif
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_AES_CTR << shift);
      break;

    case CRYP_ALGORITHM_MODE_AES_KEY_DEC:
#if defined(STM32_CRYP_ALGO_EXTENDED)
      *reg &= ~CRYP_CR_ALGOMODE3;
#endif
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_AES_KEY_DEC << shift);
      break;

#if defined(STM32_CRYP_ALGO_EXTENDED)
    case CRYP_ALGORITHM_MODE_AES_GCM_GMAC:
      *reg |= CRYP_CR_ALGOMODE3;
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_AES_GCM_GMAC << shift);
      break;

    case CRYP_ALGORITHM_MODE_AES_CCM:
      *reg |= CRYP_CR_ALGOMODE3;
      syn_set_register_bits(reg, mask, CRYP_CR_ALGOMODE_AES_CCM << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum cryp_algorithm_mode, mode);
      break;
  }
}

void
cryp_set_data_type(
  enum cryp_data_type type
)
{
  constexpr u32 shift = CRYP_CR_DATATYPE_SHIFT;
  constexpr u32 mask = CRYP_CR_DATATYPE_MASK << shift;
  volatile u32* reg = &CRYP->CR;

  switch (type)
  {
    case CRYP_DATA_TYPE_32BIT:
      *reg &= ~mask;
      break;

    case CRYP_DATA_TYPE_16BIT:
      syn_set_register_bits(reg, mask, CRYP_CR_DATATYPE_16BIT << shift);
      break;

    case CRYP_DATA_TYPE_8BIT:
      syn_set_register_bits(reg, mask, CRYP_CR_DATATYPE_8BIT << shift);
      break;

    case CRYP_DATA_TYPE_BITSTR:
      *reg |= (CRYP_CR_DATATYPE_BITSTR << shift);
      break;

    default:
      devmode_error_invalid_enum(enum cryp_data_type, type);
      break;
  }
}

void
cryp_set_key_size(
  enum cryp_key_size size
)
{
  constexpr u32 shift = CRYP_CR_KEYSIZE_SHIFT;
  constexpr u32 mask = CRYP_CR_KEYSIZE_MASK << shift;
  volatile u32* reg = &CRYP->CR;

  switch (size)
  {
    case CRYP_KEY_SIZE_128BIT:
      *reg &= ~mask;
      break;

    case CRYP_KEY_SIZE_192BIT:
      syn_set_register_bits(reg, mask, CRYP_CR_KEYSIZE_192BIT << shift);
      break;

    case CRYP_KEY_SIZE_256BIT:
      syn_set_register_bits(reg, mask, CRYP_CR_KEYSIZE_256BIT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum cryp_key_size, size);
      break;
  }
}

void
cryp_fifo_flush(void)
{
  CRYP->CR |= CRYP_CR_FFLUSH;
}

void
cryp_enable(void)
{
  CRYP->CR |= CRYP_CR_CRYPEN;
}

void
cryp_disable(void)
{
  CRYP->CR &= ~CRYP_CR_CRYPEN;
}

#if defined(STM32_CRYP_ALGO_EXTENDED)
void
cryp_set_gcm_phase(
  enum cryp_gcm_phase phase
)
{
  constexpr u32 shift = CRYP_CR_GCMCCMPH_SHIFT;
  constexpr u32 mask = CRYP_CR_GCMCCMPH_MASK << shift;
  volatile u32* reg = &CRYP->CR;

  switch (phase)
  {
    case CRYP_GCM_PHASE_INIT:
      *reg &= ~mask;
      break;

    case CRYP_GCM_PHASE_HEADER:
      syn_set_register_bits(reg, mask, CRYP_CR_GCMCCMPH_HEADER_PHASE << shift);
      break;

    case CRYP_GCM_PHASE_PAYLOAD:
      syn_set_register_bits(reg, mask, CRYP_CR_GCMCCMPH_PAYLOAD_PHASE << shift);
      break;

    case CRYP_GCM_PHASE_FINAL:
      *reg |= (CRYP_CR_GCMCCMPH_FINAL_PHASE << shift);
      break;

    default:
      devmode_error_invalid_enum(enum cryp_gcm_phase, phase);
      break;
  }
}
#endif

u32
cryp_is_flag_set(
  enum cryp_flag flag
)
{
  volatile u32* reg = &CRYP->SR;
  switch (flag)
  {
    case CRYP_FLAG_INPUT_FIFO_EMPTY:
      return *reg & CRYP_SR_IFEM;

    case CRYP_FLAG_INPUT_FIFO_NOT_NULL:
      return *reg & CRYP_SR_IFNF;

    case CRYP_FLAG_OUTPUT_FIFO_NOT_EMPTY:
      return *reg & CRYP_SR_OFNE;

    case CRYP_FLAG_OUTPUT_FIFO_FULL:
      return *reg & CRYP_SR_OFFU;

    case CRYP_FLAG_BUSY:
      return *reg & CRYP_SR_BUSY;

    default:
      devmode_error_invalid_enum(enum cryp_flag, flag);
      return 0;
  }
}

void
cryp_write_input_data(
  u32 data
)
{
  CRYP->DIN = data;
}

u32
cryp_read_output_data(void)
{
  return CRYP->DOUT;
}

void
cryp_dma_enable(
  enum cryp_dma dma
)
{
  volatile u32* reg = &CRYP->DMACR;
  switch (dma)
  {
    case CRYP_DMA_INPUT:
      *reg |= CRYP_DMACR_DIEN;
      break;

    case CRYP_DMA_OUTPUT:
      *reg |= CRYP_DMACR_DOEN;
      break;

    default:
      devmode_error_invalid_enum(enum cryp_dma, dma);
      break;
  }
}

void
cryp_dma_disable(
  enum cryp_dma dma
)
{
  volatile u32* reg = &CRYP->DMACR;
  switch (dma)
  {
    case CRYP_DMA_INPUT:
      *reg &= ~CRYP_DMACR_DIEN;
      break;

    case CRYP_DMA_OUTPUT:
      *reg &= ~CRYP_DMACR_DOEN;
      break;

    default:
      devmode_error_invalid_enum(enum cryp_dma, dma);
      break;
  }
}

void
cryp_interrupt_enable(
  enum cryp_interrupt interrupt
)
{
  volatile u32* reg = &CRYP->IMSCR;
  switch (interrupt)
  {
    case CRYP_INTERRUPT_INPUT_FIFO_SERVICE:
      *reg |= CRYP_IMSCR_INIM;
      break;

    case CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE:
      *reg |= CRYP_IMSCR_OUTIM;
      break;

    default:
      devmode_error_invalid_enum(enum cryp_interrupt, interrupt);
      break;
  }
}

void
cryp_interrupt_disable(
  enum cryp_interrupt interrupt
)
{
  volatile u32* reg = &CRYP->IMSCR;
  switch (interrupt)
  {
    case CRYP_INTERRUPT_INPUT_FIFO_SERVICE:
      *reg &= ~CRYP_IMSCR_INIM;
      break;

    case CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE:
      *reg &= ~CRYP_IMSCR_OUTIM;
      break;

    default:
      devmode_error_invalid_enum(enum cryp_interrupt, interrupt);
      break;
  }
}

u32
cryp_has_interrupt_occurred(
  enum cryp_interrupt interrupt
)
{
  volatile u32* reg = &CRYP->RISR;
  switch (interrupt)
  {
    case CRYP_INTERRUPT_INPUT_FIFO_SERVICE:
      return *reg & CRYP_RISR_INRIS;

    case CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE:
      return *reg & CRYP_RISR_OUTRIS;

    default:
      devmode_error_invalid_enum(enum cryp_interrupt, interrupt);
      return 0;
  }
}

u32
cryp_is_interrupt_pending(
  enum cryp_interrupt interrupt
)
{
  volatile u32* reg = &CRYP->MISR;
  switch (interrupt)
  {
    case CRYP_INTERRUPT_INPUT_FIFO_SERVICE:
      return *reg & CRYP_MISR_INMIS;

    case CRYP_INTERRUPT_OUTPUT_FIFO_SERVICE:
      return *reg & CRYP_MISR_OUTMIS;

    default:
      devmode_error_invalid_enum(enum cryp_interrupt, interrupt);
      return 0;
  }
}

void
cryp_write_key_128bit(
  struct cryp_key* key
)
{
  for (u32 i = 0; i < 4; ++i)
  {
    CRYP->KR[7 - i] = key->key[i];
  }
}

void
cryp_write_key_192bit(
  struct cryp_key* key
)
{
  for (u32 i = 0; i < 6; ++i)
  {
    CRYP->KR[7 - i] = key->key[i];
  }
}

void
cryp_write_key_256bit(
  struct cryp_key* key
)
{
  for (u32 i = 0; i < 8; ++i)
  {
    CRYP->KR[7 - i] = key->key[i];
  }
}

void
cryp_write_key(
  struct cryp_key* key,
  enum cryp_key_size size
)
{
  switch (size)
  {
    case CRYP_KEY_SIZE_128BIT:
      cryp_write_key_128bit(key);
      break;

    case CRYP_KEY_SIZE_192BIT:
      cryp_write_key_192bit(key);
      break;

    case CRYP_KEY_SIZE_256BIT:
      cryp_write_key_256bit(key);
      break;

    default:
      devmode_error_invalid_enum(enum cryp_key_size, size);
      break;
  }
}

void
cryp_write_iv_64bit(
  struct cryp_iv* iv
)
{
  for (u32 i = 0; i < 2; ++i)
  {
    CRYP->IV[i] = iv->iv[i];
  }
}

void
cryp_write_iv_128bit(
  struct cryp_iv* iv
)
{
  for (u32 i = 0; i < 4; ++i)
  {
    CRYP->IV[i] = iv->iv[i];
  }
}

void
cryp_write_iv(
  struct cryp_iv* iv,
  enum cryp_iv_size size
)
{
  switch (size)
  {
    case CRYP_IV_SIZE_64BIT:
      cryp_write_iv_64bit(iv);
      break;

    case CRYP_IV_SIZE_128BIT:
      cryp_write_iv_128bit(iv);
      break;

    default:
      devmode_error_invalid_enum(enum cryp_iv_size, size);
      break;
  }
}

#if defined(STM32_CRYP_CS)
void
cryp_dump_all(
  struct cryp_periph_registers* regs
)
{
  for (u32 i = 0; i < 8; ++i)
  {
    regs->buf[i] = CRYP->CSGCMCCMR[i];
  }

  for (u32 i = 0; i < 8; ++i)
  {
    regs->buf[8 + i] = CRYP->CSGCMR[i];
  }
}

void
cryp_restore_all(
  struct cryp_periph_registers* regs
)
{
  for (u32 i = 0; i < 8; ++i)
  {
    CRYP->CSGCMCCMR[i] = regs->buf[i];
  }

  for (u32 i = 0; i < 8; ++i)
  {
    CRYP->CSGCMR[i] = regs->buf[8 + i];
  }
}
#endif
