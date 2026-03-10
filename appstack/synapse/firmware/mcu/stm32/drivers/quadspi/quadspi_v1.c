#include "synapse/stm32/drivers/quadspi/quadspi_v1.h"
#include "libcom/sys/devmode.h"
#include "synapse/common/util/common.h"
#include "synapse/stm32/system/chips/f4/memorymap.h"

typedef volatile struct quadspi_registers_map quadspi_periph;
quadspi_periph* QUADSPI = (quadspi_periph*) (QSPI_CONTROL_ADDR);

void
quadspi_enable(void)
{
  QUADSPI->CR |= QUADSPI_CR_EN;
}

void
quadspi_disable(void)
{
  QUADSPI->CR &= ~QUADSPI_CR_EN;
}

void
quadspi_abort(void)
{
  QUADSPI->CR |= QUADSPI_CR_ABORT;
}

void
quadspi_dma_enable(void)
{
  QUADSPI->CR |= QUADSPI_CR_DMAEN;
}

void
quadspi_dma_disable(void)
{
  QUADSPI->CR &= ~QUADSPI_CR_DMAEN;
}

void
quadspi_timeout_counter_enable(void)
{
  QUADSPI->CR |= QUADSPI_CR_TCEN;
}

void
quadspi_timeout_counter_disable(void)
{
  QUADSPI->CR &= ~QUADSPI_CR_TCEN;
}

void
quadspi_set_sample_shift(
  enum quadspi_sample_shift shift
)
{
  volatile u32* reg = &QUADSPI->CR;
  switch (shift)
  {
    case QUADSPI_SAMPLE_SHIFT_NO_SHIFT:
      *reg &= ~QUADSPI_CR_SSHIFT;
      break;

    case QUADSPI_SAMPLE_SHIFT_HALF_SHIFT:
      *reg |= QUADSPI_CR_SSHIFT;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_sample_shift, shift);
      break;
  }
}

void
quadspi_dual_flash_enable(void)
{
  QUADSPI->CR |= QUADSPI_CR_DFM;
}

void
quadspi_dual_flash_disable(void)
{
  QUADSPI->CR &= ~QUADSPI_CR_DFM;
}

void
quadspi_select_flash_memory(
  enum quadspi_flash_memory memory
)
{
  volatile u32* reg = &QUADSPI->CR;
  switch (memory)
  {
    case QUADSPI_FLASH_MEMORY_FLASH1:
      *reg &= ~QUADSPI_CR_FSEL;
      break;

    case QUADSPI_FLASH_MEMORY_FLASH2:
      *reg |= QUADSPI_CR_FSEL;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_flash_memory, memory);
      break;
  }
}

void
quadspi_set_fifo_threshold_level(
  u32 level
)
{
  devmode_assert_lower_or_eq(level, QUADSPI_CR_FTHRES_MASK);
  constexpr u32 shift = QUADSPI_CR_FTHRES_SHIFT;
  constexpr u32 mask = QUADSPI_CR_FTHRES_MASK << shift;
  volatile u32* reg = &QUADSPI->CR;
  syn_set_register_bits(reg, mask, level << shift);
}

void
quadspi_interrupt_enable(
  enum quadspi_interrupt interrupt
)
{
  volatile u32* reg = &QUADSPI->CR;
  switch (interrupt)
  {
    case QUADSPI_INTERRUPT_TRANSFER_ERROR:
      *reg |= QUADSPI_CR_TEIE;
      break;

    case QUADSPI_INTERRUPT_TRANSFER_COMPLETE:
      *reg |= QUADSPI_CR_TCIE;
      break;

    case QUADSPI_INTERRUPT_FIFO_THRESHOLD:
      *reg |= QUADSPI_CR_FTIE;
      break;

    case QUADSPI_INTERRUPT_STATUS_MATCH:
      *reg |= QUADSPI_CR_SMIE;
      break;

    case QUADSPI_INTERRUPT_TIMEOUT:
      *reg |= QUADSPI_CR_TOIE;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_interrupt, interrupt);
      break;
  }
}

void
quadspi_interrupt_disable(
  enum quadspi_interrupt interrupt
)
{
  volatile u32* reg = &QUADSPI->CR;
  switch (interrupt)
  {
    case QUADSPI_INTERRUPT_TRANSFER_ERROR:
      *reg &= ~QUADSPI_CR_TEIE;
      break;

    case QUADSPI_INTERRUPT_TRANSFER_COMPLETE:
      *reg &= ~QUADSPI_CR_TCIE;
      break;

    case QUADSPI_INTERRUPT_FIFO_THRESHOLD:
      *reg &= ~QUADSPI_CR_FTIE;
      break;

    case QUADSPI_INTERRUPT_STATUS_MATCH:
      *reg &= ~QUADSPI_CR_SMIE;
      break;

    case QUADSPI_INTERRUPT_TIMEOUT:
      *reg &= ~QUADSPI_CR_TOIE;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_interrupt, interrupt);
      break;
  }
}

void
quadspi_set_automatic_status_polling_mode(
  enum quadspi_polling_stop_mode mode
)
{
  volatile u32* reg = &QUADSPI->CR;
  switch (mode)
  {
    case QUADSPI_POLLING_STOP_MODE_ONLY_ABORT:
      *reg &= ~QUADSPI_CR_APMS;
      break;

    case QUADSPI_POLLING_STOP_MODE_MATCH:
      *reg |= QUADSPI_CR_APMS;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_polling_stop_mode, mode);
      break;
  }
}

void
quadspi_set_polling_match_mode(
  enum quadspi_polling_match_mode mode
)
{
  volatile u32* reg = &QUADSPI->CR;
  switch (mode)
  {
    case QUADSPI_POLLING_MATCH_MODE_AND:
      *reg &= ~QUADSPI_CR_PMM;
      break;

    case QUADSPI_POLLING_MATCH_MODE_OR:
      *reg |= QUADSPI_CR_PMM;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_polling_match_mode, mode);
      break;
  }
}

void
quadspi_set_prescaler(
  u32 prescaler
)
{
  devmode_assert_lower_or_eq(prescaler, QUADSPI_CR_PRESCALER_MASK);
  constexpr u32 shift = QUADSPI_CR_PRESCALER_SHIFT;
  constexpr u32 mask = QUADSPI_CR_PRESCALER_MASK << shift;
  volatile u32* reg = &QUADSPI->CR;
  syn_set_register_bits(reg, mask, prescaler << shift);
}

void
quadspi_set_clock_mode(
  enum quadspi_clock_mode mode
)
{
  volatile u32* reg = &QUADSPI->DCR;
  switch (mode)
  {
    case QUADSPI_CLOCK_MODE_MODE0:
      *reg &= ~QUADSPI_DCR_CKMODE;
      break;

    case QUADSPI_CLOCK_MODE_MODE3:
      *reg |= QUADSPI_DCR_CKMODE;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_clock_mode, mode);
      break;
  }
}

void
quadspi_set_cs_min_high_cycles_count(
  u32 count
)
{
  devmode_assert_lower_or_eq(count, QUADSPI_DCR_CSHT_MASK);
  constexpr u32 shift = QUADSPI_DCR_CSHT_SHIFT;
  constexpr u32 mask = QUADSPI_DCR_CSHT_MASK << shift;
  volatile u32* reg = &QUADSPI->DCR;
  syn_set_register_bits(reg, mask, count << shift);
}

void
quadspi_set_address_bits(
  u32 bits
)
{
  devmode_assert_lower_or_eq(bits, QUADSPI_DCR_FSIZE_MASK);
  constexpr u32 shift = QUADSPI_DCR_FSIZE_SHIFT;
  constexpr u32 mask = QUADSPI_DCR_FSIZE_MASK << shift;
  volatile u32* reg = &QUADSPI->DCR;
  syn_set_register_bits(reg, mask, bits << shift);
}

u32
quadspi_is_flag_set(
  enum quadspi_flag flag
)
{
  volatile u32* reg = &QUADSPI->SR;
  switch (flag)
  {
    case QUADSPI_FLAG_TRANSFER_ERROR:
      return *reg & QUADSPI_SR_TEF;
      break;

    case QUADSPI_FLAG_TRANSFER_COMPLETE:
      return *reg & QUADSPI_SR_TCF;
      break;

    case QUADSPI_FLAG_FIFO_THRESHOLD:
      return *reg & QUADSPI_SR_FTF;
      break;

    case QUADSPI_FLAG_STATUS_MATCH:
      return *reg & QUADSPI_SR_SMF;
      break;

    case QUADSPI_FLAG_TIMEOUT:
      return *reg & QUADSPI_SR_TOF;
      break;

    case QUADSPI_FLAG_BUSY:
      return *reg & QUADSPI_SR_BUSY;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_flag, flag);
      return 0;
  }
}

u32
quadspi_get_fifo_bytes_count(void)
{
  constexpr u32 shift = QUADSPI_SR_FLEVEL_SHIFT;
  constexpr u32 mask = QUADSPI_SR_FLEVEL_MASK;
  volatile u32* reg = &QUADSPI->SR;
  return (*reg >> shift) & mask;
}

void
quadspi_flag_clear(
  enum quadspi_flag flag
)
{
  volatile u32* reg = &QUADSPI->FCR;
  switch (flag)
  {
    case QUADSPI_FLAG_TRANSFER_ERROR:
      *reg |= QUADSPI_FCR_CTEF;
      break;

    case QUADSPI_FLAG_TRANSFER_COMPLETE:
      *reg |= QUADSPI_FCR_CTCF;
      break;

    case QUADSPI_FLAG_STATUS_MATCH:
      *reg |= QUADSPI_FCR_CSMF;
      break;
      
    case QUADSPI_FLAG_TIMEOUT:
      *reg |= QUADSPI_FCR_CTOF;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_flag, flag);
      break;
  }
}

void
quadspi_set_transfer_bytes_count(
  u32 count
)
{
  QUADSPI->DLR = count;
}

void
quadspi_set_instruction(
  u32 instruction
)
{
  devmode_assert_lower_or_eq(instruction, QUADSPI_CCR_INSTRUCTION_MASK);
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_INSTRUCTION_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_INSTRUCTION_MASK << shift;
  syn_set_register_bits(reg, mask, instruction << shift);
}

void
quadspi_set_intruction_mode(
  enum quadspi_intruction_mode mode
)
{
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_IMODE_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_IMODE_MASK << shift;

  switch (mode)
  {
    case QUADSPI_INTRUCTION_MODE_NO_INSTRUCTION:
      *reg &= ~mask;
      break;

    case QUADSPI_INTRUCTION_MODE_1LINE:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_IMODE_INSTRUCTION_1LINE << shift
      );
      break;

    case QUADSPI_INTRUCTION_MODE_2LINES:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_IMODE_INSTRUCTION_2LINES << shift
      );
      break;

    case QUADSPI_INTRUCTION_MODE_4LINES:
      *reg |= (QUADSPI_CCR_IMODE_INSTRUCTION_4LINES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_instruction_mode, mode);
      break;
  }
}

void
quadspi_set_address_mode(
  enum quadspi_address_mode mode
)
{
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_ADMODE_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_ADMODE_MASK << shift;

  switch (mode)
  {
    case QUADSPI_ADDRESS_MODE_NO_ADDRESS:
      *reg &= ~mask;
      break;

    case QUADSPI_ADDRESS_MODE_1LINE:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ADMODE_ADDRESS_1LINE << shift
      );
      break;

    case QUADSPI_ADDRESS_MODE_2LINES:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ADMODE_ADDRESS_2LINES << shift
      );
      break;

    case QUADSPI_ADDRESS_MODE_4LINES:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ADMODE_ADDRESS_4LINES << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_address_mode, mode);
      break;
  }
}

void
quadspi_set_address_size(
  enum quadspi_address_size size
)
{
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_ADSIZE_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_ADSIZE_MASK << shift;

  switch (size)
  {
    case QUADSPI_ADDRESS_SIZE_8BIT:
      *reg &= ~mask;
      break;

    case QUADSPI_ADDRESS_SIZE_16BIT:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ADSIZE_16BIT << shift
      );
      break;

    case QUADSPI_ADDRESS_SIZE_24BIT:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ADSIZE_24BIT << shift
      );
      break;

    case QUADSPI_ADDRESS_SIZE_32BIT:
      *reg |= (QUADSPI_CCR_ADSIZE_32BIT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_address_size, size);
      break;
  }
}

void
quadspi_set_alternate_byte_mode(
  enum quadspi_alternate_byte_mode mode
)
{
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_ABMODE_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_ABMODE_MASK << shift;

  switch (mode)
  {
    case QUADSPI_ALTERNATE_BYTE_MODE_NO_ALTERNATE:
      *reg &= ~mask;
      break;

    case QUADSPI_ALTERNATE_BYTE_MODE_1LINE:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ABMODE_ALT_BYTES_1LINE << shift
      );
      break;

    case QUADSPI_ALTERNATE_BYTE_MODE_2LINES:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ABMODE_ALT_BYTES_2LINES << shift
      );
      break;

    case QUADSPI_ALTERNATE_BYTE_MODE_4LINES:
      *reg |= (QUADSPI_CCR_ABMODE_ALT_BYTES_4LINES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_alternate_byte_mode, mode);
      break;
  }
}

void
quadspi_set_alternate_byte_size(
  enum quadspi_alternate_byte_size size
)
{
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_ABSIZE_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_ABSIZE_MASK << shift;

  switch (size)
  {
    case QUADSPI_ALTERNATE_BYTE_SIZE_8BIT:
      *reg &= ~mask;
      break;

    case QUADSPI_ALTERNATE_BYTE_SIZE_16BIT:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ABSIZE_ALT_BYTES_16BIT << shift
      );
      break;

    case QUADSPI_ALTERNATE_BYTE_SIZE_24BIT:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_ABSIZE_ALT_BYTES_24BIT << shift
      );
      break;

    case QUADSPI_ALTERNATE_BYTE_SIZE_32BIT:
      *reg |= (QUADSPI_CCR_ABSIZE_ALT_BYTES_32BIT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_alternate_byte_size, size);
      break;
  }
}

void
quadspi_set_dummy_cycles_count(
  u32 count
)
{
  devmode_assert_lower_or_eq(count, QUADSPI_CCR_DCYC_MASK);
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_DCYC_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_DCYC_MASK << shift;
  syn_set_register_bits(reg, mask, count << shift);
}

void
quadspi_set_data_mode(
  enum quadspi_data_mode mode
)
{
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_DMODE_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_DMODE_MASK << shift;

  switch (mode)
  {
    case QUADSPI_DATA_MODE_NO_DATA:
      *reg &= ~mask;
      break;

    case QUADSPI_DATA_MODE_1LINE:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_DMODE_DATA_1LINE << shift
      );
      break;

    case QUADSPI_DATA_MODE_2LINES:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_DMODE_DATA_2LINES << shift
      );
      break;

    case QUADSPI_DATA_MODE_4LINES:
      *reg |= (QUADSPI_CCR_DMODE_DATA_4LINES << shift);
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_data_mode, mode);
      break;
  }
}

void
quadspi_set_functional_mode(
  enum quadspi_functional_mode mode
)
{
  volatile u32* reg = &QUADSPI->CCR;
  constexpr u32 shift = QUADSPI_CCR_FMODE_SHIFT;
  constexpr u32 mask = QUADSPI_CCR_FMODE_MASK << shift;

  switch (mode)
  {
    case QUADSPI_FUNCTIONAL_MODE_INDIRECT_WRITE:
      *reg &= ~mask;
      break;

    case QUADSPI_FUNCTIONAL_MODE_INDIRECT_READ:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_FMODE_INDIRECT_READ << shift
      );
      break;

    case QUADSPI_FUNCTIONAL_MODE_AUTOMATIC_STATUS_POLLING:
      syn_set_register_bits(
        reg,
        mask,
        QUADSPI_CCR_FMODE_AUTO_STATUS_POLLING << shift
      );
      break;

    case QUADSPI_FUNCTIONAL_MODE_MEMORY_MAPPED:
      *reg |= (QUADSPI_CCR_FMODE_MEMORY_MAPPED << shift);
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_functional_mode, mode);
      break;
  }
}

void
quadspi_set_send_instruction_mode(
  enum quadspi_send_instruction_mode mode
)
{
  volatile u32* reg = &QUADSPI->CCR;

  switch (mode)
  {
    case QUADSPI_SEND_INSTRUCTION_MODE_EVERY_TRANSACTION:
      *reg &= ~QUADSPI_CCR_SIOO;
      break;

    case QUADSPI_SEND_INSTRUCTION_MODE_FIRST_CMD_ONLY:
      *reg |= QUADSPI_CCR_SIOO;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_send_instruction_mode, mode);
      break;
  }
}

void
quadspi_set_double_data_rate_delay_mode(
  enum quadspi_data_delay delay
)
{
  volatile u32* reg = &QUADSPI->CCR;
  switch (delay)
  {
    case QUADSPI_DATA_DELAY_ANALOG_DELAY:
      *reg &= ~QUADSPI_CCR_DHHC;
      break;

    case QUADSPI_DATA_DELAY_1over4_CLK_CYCLE:
      *reg |= QUADSPI_CCR_DHHC;
      break;

    default:
      devmode_error_invalid_enum(enum quadspi_data_delay, delay);
      break;
  }
}

void
quadspi_double_data_rate_enable(void)
{
  QUADSPI->CCR |= QUADSPI_CCR_DDRM;
}

void
quadspi_double_data_rate_disable(void)
{
  QUADSPI->CCR &= ~QUADSPI_CCR_DDRM;
}

void
quadspi_set_flash_address(
  u32 address
)
{
  QUADSPI->AR = address;
}

void
quadspi_set_alternate_bytes(
  u32 bytes
)
{
  QUADSPI->ABR = bytes;
}

void
quadspi_data_write(
  u32 data
)
{
  QUADSPI->DR = data;
}

u32
quadspi_data_read(void)
{
  return QUADSPI->DR;
}

void
quadspi_set_status_byte_mask(
  u32 mask
)
{
  QUADSPI->PSMKR = mask;
}

void
quadspi_set_status_match(
  u32 value
)
{
  QUADSPI->PSMAR = value;
}

void
quadspi_set_polling_interval(
  u32 interval
)
{
  devmode_assert_lower_or_eq(interval, QUADSPI_PIR_INTERVAL_MASK);
  volatile u32* reg = &QUADSPI->PIR;
  constexpr u32 shift = QUADSPI_PIR_INTERVAL_SHIFT;
  constexpr u32 mask = QUADSPI_PIR_INTERVAL_MASK << shift;
  syn_set_register_bits(reg, mask, interval << shift);
}

void
quadspi_set_timeout_period(
  u32 period
)
{
  devmode_assert_lower_or_eq(period, QUADSPI_LPTR_TIMEOUT_MASK);
  volatile u32* reg = &QUADSPI->LPTR;
  constexpr u32 shift = QUADSPI_LPTR_TIMEOUT_SHIFT;
  constexpr u32 mask = QUADSPI_LPTR_TIMEOUT_MASK << shift;
  syn_set_register_bits(reg, mask, period << shift);
}
