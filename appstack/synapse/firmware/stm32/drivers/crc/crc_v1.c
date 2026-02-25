#include "synapse/stm32/drivers/crc/crc_v1.h"
#include "synapse/stm32/system/specs.h"

#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"

typedef volatile struct crc_registers_map crc_periph;
crc_periph* CRC = (crc_periph*) (CRC_ADDR);

u32
crc_data_read(void)
{
  return CRC->DR;
}

void
crc_data_write(
  u32 data
)
{
  CRC->DR = data;
}

u32
crc_independent_data_read(void)
{
  return CRC->IDR & CRC_IDR_MASK;
}

void
crc_independent_data_write(
  u32 data
)
{
  devmode_assert_lower_or_eq(data, CRC_IDR_MASK);

  constexpr u32 shift = CRC_IDR_SHIFT;
  constexpr u32 mask = CRC_IDR_MASK << shift;
  syn_set_register_bits(&CRC->IDR, mask, data << shift);
}

void
crc_reset(void)
{
  CRC->CR |= CRC_CR_RESET;
}

#if defined(STM32_CRC_REVERSE_DATA)
void
crc_set_input_data_reverse(
  enum crc_input_data_reverse reverse
)
{
  constexpr u32 shift = CRC_CR_REVIN_SHIFT;
  constexpr u32 mask = CRC_cR_REVIN_MASK << shift;
  volatile u32* reg = &CRC->CR;

  switch (reverse)
  {
    case CRC_INPUT_DATA_REVERSE_OFF:
      *reg &= ~mask;
      break;

    case CRC_INPUT_DATA_REVERSE_BYTE:
      syn_set_register_bits(reg, mask, CRC_CR_REVIN_BY_BYTE << shift);
      break;

    case CRC_INPUT_DATA_REVERSE_HALF_WORD:
      syn_set_register_bits(reg, mask, CRC_CR_REVIN_BY_HALF_WORD << shift);
      break;

    case CRC_INPUT_DATA_REVERSE_WORD:
      *reg |= (CRC_CR_REVIN_BY_WORD << shift);
      break;

    default:
      devmode_error_invalid_enum(enum crc_input_data_reverse, reverse);
      break;
  }
}

void
crc_output_data_reverse_enable(void)
{
  CRC->CR |= CRC_CR_REVOUT;
}

void
crc_output_data_reverse_disable(void)
{
  CRC->CR &= ~CRC_CR_REVOUT;
}
#endif

#if defined(STM32_CRC_EXTENDED)
void
crc_set_initial_value(
  u32 value
)
{
  CRC->INIT = value;
}
#endif
