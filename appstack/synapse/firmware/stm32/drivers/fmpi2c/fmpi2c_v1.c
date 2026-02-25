#include "synapse/stm32/drivers/fmpi2c/fmpi2c_v1.h"
#include "libcom/sys/devmode.h"
#include "synapse/common/util/common.h"
#include "synapse/stm32/system/chips/f4/memorymap.h"

typedef struct fmpi2c_registers_map fmpi2c_periph;
fmpi2c_periph* FMPI2C1 = (fmpi2c_periph*) (FMPI2C1_ADDR);

void
fmpi2c_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_PE;
}

void
fmpi2c_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_PE;
}

void
fmpi2c_interrupt_enable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interrupt interrupt
)
{
  volatile u32* reg = &fmpi2c->CR1;
  switch (interrupt)
  {
    case FMPI2C_INTERRUPT_TX:
      *reg |= FMPI2C_CR1_TXIE;
      break;

    case FMPI2C_INTERRUPT_RX:
      *reg |= FMPI2C_CR1_RXIE;
      break;

    case FMPI2C_INTERRUPT_ADDR_MATCH:
      *reg |= FMPI2C_CR1_ADDRIE;
      break;

    case FMPI2C_INTERRUPT_NACK:
      *reg |= FMPI2C_CR1_NACKIE;
      break;

    case FMPI2C_INTERRUPT_STOP:
      *reg |= FMPI2C_CR1_STOPIE;
      break;

    case FMPI2C_INTERRUPT_TRANSFER_COMPLETE:
      *reg |= FMPI2C_CR1_TCIE;
      break;

    case FMPI2C_INTERRUPT_ERR:
      *reg |= FMPI2C_CR1_ERRIE;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_interrupt, interrupt);
      break;
  }
}

void
fmpi2c_interrupt_disable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interrupt interrupt
)
{
  volatile u32* reg = &fmpi2c->CR1;
  switch (interrupt)
  {
    case FMPI2C_INTERRUPT_TX:
      *reg &= ~FMPI2C_CR1_TXIE;
      break;

    case FMPI2C_INTERRUPT_RX:
      *reg &= ~FMPI2C_CR1_RXIE;
      break;

    case FMPI2C_INTERRUPT_ADDR_MATCH:
      *reg &= ~FMPI2C_CR1_ADDRIE;
      break;

    case FMPI2C_INTERRUPT_NACK:
      *reg &= ~FMPI2C_CR1_NACKIE;
      break;

    case FMPI2C_INTERRUPT_STOP:
      *reg &= ~FMPI2C_CR1_STOPIE;
      break;

    case FMPI2C_INTERRUPT_TRANSFER_COMPLETE:
      *reg &= ~FMPI2C_CR1_TCIE;
      break;

    case FMPI2C_INTERRUPT_ERR:
      *reg &= ~FMPI2C_CR1_ERRIE;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_interrupt, interrupt);
      break;
  }
}

void
fmpi2c_set_digital_noise_filter(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 filter
)
{
  devmode_assert_lower_or_eq(filter, FMPI2C_CR1_DNF_MASK);
  volatile u32* reg = &fmpi2c->CR1;
  constexpr u32 shift = FMPI2C_CR1_DNF_SHIFT;
  constexpr u32 mask = FMPI2C_CR1_DNF_MASK << shift;
  syn_set_register_bits(reg, mask, filter << shift);
}

void
fmpi2c_analog_noise_filter_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_ANFOFF;
}

void
fmpi2c_analog_noise_filter_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_ANFOFF;
}

void
fmpi2c_dma_tx_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_TXDMAEN;
}

void
fmpi2c_dma_tx_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_TXDMAEN;
}

void
fmpi2c_dma_rx_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_RXDMAEN;
}

void
fmpi2c_dma_rx_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_RXDMAEN;
}

void
fmpi2c_target_byte_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_SBC;
}

void
fmpi2c_target_byte_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_SBC;
}

void
fmpi2c_clock_stretching_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_NOSTRETCH;
}

void
fmpi2c_clock_stretching_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_NOSTRETCH;
}

void
fmpi2c_general_call_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_GCEN;
}

void
fmpi2c_general_call_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_GCEN;
}

void
fmpi2c_smbus_host_addr_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_SMBHEN;
}

void
fmpi2c_smbus_host_addr_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_SMBHEN;
}

void
fmpi2c_smbus_device_default_addr_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_SMBDEN;
}

void
fmpi2c_smbus_device_default_addr_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_SMBDEN;
}

void
fmpi2c_smbus_alert_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_ALERTEN;
}

void
fmpi2c_smbus_alert_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_ALERTEN;
}

void
fmpi2c_pec_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 |= FMPI2C_CR1_PECEN;
}

void
fmpi2c_pec_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR1 &= ~FMPI2C_CR1_PECEN;
}

void
fmpi2c_set_target_addr(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 addr
)
{
  devmode_assert_lower_or_eq(addr, FMPI2C_CR2_SADD_MASK);
  volatile u32* reg = &fmpi2c->CR2;
  constexpr u32 shift = FMPI2C_CR2_SADD_SHIFT;
  constexpr u32 mask = FMPI2C_CR2_SADD_MASK << shift;
  syn_set_register_bits(reg, mask, addr << shift);
}

void
fmpi2c_set_transfer_direction(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_transfer_dir dir
)
{
  volatile u32* reg = &fmpi2c->CR2;
  switch (dir)
  {
    case FMPI2C_TRANSFER_DIR_WRITE:
      *reg &= ~FMPI2C_CR2_RDWRN;
      break;

    case FMPI2C_TRANSFER_DIR_READ:
      *reg |= FMPI2C_CR2_RDWRN;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_transfer_dir, dir);
      break;
  }
}

void
fmpi2c_set_addressing_mode(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_addressing_mode mode
)
{
  volatile u32* reg = &fmpi2c->CR2;
  switch (mode)
  {
    case FMPI2C_ADDRESSING_MODE_7BIT:
      *reg &= ~FMPI2C_CR2_ADD10;
      break;

    case FMPI2C_ADDRESSING_MODE_10BIT:
      *reg |= FMPI2C_CR2_ADD10;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_addressing_mode, mode);
      break;
  }
}

void
fmpi2c_set_10bit_addr_dir_change_seq(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_10bit_addr_dir_change_seq seq
)
{
  volatile u32* reg = &fmpi2c->CR2;
  switch (seq)
  {
    case FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_HEADER_ONLY:
      *reg |= FMPI2C_CR2_HEAD10R;
      break;

    case FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_FULL:
      *reg &= ~FMPI2C_CR2_HEAD10R;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_10bit_addr_dir_change_seq, seq);
      break;
  }
}

void
fmpi2c_generate_start(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR2 |= FMPI2C_CR2_START;
}

void
fmpi2c_generate_stop(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR2 |= FMPI2C_CR2_STOP;
}

void
fmpi2c_generate_nack(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR2 |= FMPI2C_CR2_NACK;
}

void
fmpi2c_set_transfer_bytes_count(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 count
)
{
  devmode_assert_lower_or_eq(count, FMPI2C_CR2_NBYTES_MASK);
  volatile u32* reg = &fmpi2c->CR2;
  constexpr u32 shift = FMPI2C_CR2_NBYTES_SHIFT;
  constexpr u32 mask = FMPI2C_CR2_NBYTES_MASK << shift;
  syn_set_register_bits(reg, mask, count << shift);
}

void
fmpi2c_set_reload_mode(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_reload_mode mode
)
{
  volatile u32* reg = &fmpi2c->CR2;
  switch (mode)
  {
    case FMPI2C_RELOAD_MODE_COMPLETE:
      *reg &= ~FMPI2C_CR2_RELOAD;
      break;

    case FMPI2C_RELOAD_MODE_CONTINUE:
      *reg |= FMPI2C_CR2_RELOAD;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_reload_mode, mode);
      break;
  }
}

void
fmpi2c_set_end_mode(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_end_mode mode
)
{
  volatile u32* reg = &fmpi2c->CR2;
  switch (mode)
  {
    case FMPI2C_END_MODE_SOFTWARE:
      *reg &= ~FMPI2C_CR2_AUTOEND;
      break;

    case FMPI2C_END_MODE_AUTOMATIC:
      *reg |= FMPI2C_CR2_AUTOEND;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_end_mode, mode);
      break;
  }
}

void
fmpi2c_pec_byte_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR2 |= FMPI2C_CR2_PECBYTE;
}

void
fmpi2c_pec_byte_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->CR2 &= ~FMPI2C_CR2_PECBYTE;
}

void
fmpi2c_set_interface_7bit_addr(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr addr,
  u32 val
)
{
  volatile u32* reg;
  u32 shift;
  u32 mask;

  switch (addr)
  {
    case FMPI2C_INTERFACE_ADDR1:
      devmode_assert_lower_or_eq(val, FMPI2C_OAR1_OA1_7BIT_MASK);
      reg = &fmpi2c->OAR1;
      shift = FMPI2C_OAR1_OA1_7BIT_SHIFT;
      mask = FMPI2C_OAR1_OA1_7BIT_MASK << shift;
      syn_set_register_bits(reg, mask, val << shift);
      break;

    case FMPI2C_INTERFACE_ADDR2:
      devmode_assert_lower_or_eq(val, FMPI2C_OAR2_OA2_MASK);
      reg = &fmpi2c->OAR2;
      shift = FMPI2C_OAR2_OA2_SHIFT;
      mask = FMPI2C_OAR2_OA2_MASK << shift;
      syn_set_register_bits(reg, mask, val << shift);
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_interface_addr, addr);
      break;
  }
}

void
fmpi2c_set_interface_10bit_addr(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 val
)
{
  devmode_assert_lower_or_eq(val, FMPI2C_OAR1_OA1_10BIT_MASK);
  volatile u32* reg = &fmpi2c->OAR1;
  constexpr u32 shift = FMPI2C_OAR1_OA1_10BIT_SHIFT;
  constexpr u32 mask = FMPI2C_OAR1_OA1_10BIT_MASK << shift;
  syn_set_register_bits(reg, mask, val << shift);
}

void
fmpi2c_set_interface_addr1_type(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr_type type
)
{
  volatile u32* reg = &fmpi2c->OAR1; 
  switch (type)
  {
    case FMPI2C_INTERFACE_ADDR_TYPE_7BIT:
      *reg &= ~FMPI2C_OAR1_OA1MODE;
      break;

    case FMPI2C_INTERFACE_ADDR_TYPE_10BIT:
      *reg |= FMPI2C_OAR1_OA1MODE;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_interface_addr_type, type);
      break;
  }
}

void
fmpi2c_interface_addr_enable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr addr
)
{
  switch (addr)
  {
    case FMPI2C_INTERFACE_ADDR1:
      fmpi2c->OAR1 |= FMPI2C_OAR1_OA1EN;
      break;

    case FMPI2C_INTERFACE_ADDR2:
      fmpi2c->OAR2 |= FMPI2C_OAR2_OA2EN;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_interface_addr, addr);
      break;
  }
}

void
fmpi2c_interface_addr_disable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr addr
)
{
  switch (addr)
  {
    case FMPI2C_INTERFACE_ADDR1:
      fmpi2c->OAR1 &= ~FMPI2C_OAR1_OA1EN;
      break;

    case FMPI2C_INTERFACE_ADDR2:
      fmpi2c->OAR2 &= ~FMPI2C_OAR2_OA2EN;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_interface_addr, addr);
      break;
  }
}

void
fmpi2c_set_interface_addr2_mask(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 bitmask
)
{
  devmode_assert_lower_or_eq(bitmask, FMPI2C_OAR2_OA2MSK_MASK);
  volatile u32* reg = &fmpi2c->OAR2;
  constexpr u32 shift = FMPI2C_OAR2_OA2MSK_SHIFT;
  constexpr u32 mask = FMPI2C_OAR2_OA2MSK_MASK << shift;
  syn_set_register_bits(reg, mask, bitmask << shift);
}

void
fmpi2c_set_scl_low_period(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 period
)
{
  devmode_assert_lower_or_eq(period, FMPI2C_TIMINGR_SCLL_MASK);
  volatile u32* reg = &fmpi2c->TIMINGR;
  constexpr u32 shift = FMPI2C_TIMINGR_SCLL_SHIFT;
  constexpr u32 mask = FMPI2C_TIMINGR_SCLL_MASK << shift;
  syn_set_register_bits(reg, mask, period << shift);
}

void
fmpi2c_set_scl_high_period(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 period
)
{
  devmode_assert_lower_or_eq(period, FMPI2C_TIMINGR_SCLH_MASK);
  volatile u32* reg = &fmpi2c->TIMINGR;
  constexpr u32 shift = FMPI2C_TIMINGR_SCLH_SHIFT;
  constexpr u32 mask = FMPI2C_TIMINGR_SCLH_MASK << shift;
  syn_set_register_bits(reg, mask, period << shift);
}

void
fmpi2c_set_data_hold_time(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 time
)
{
  devmode_assert_lower_or_eq(time, FMPI2C_TIMINGR_SDADEL_MASK);
  volatile u32* reg = &fmpi2c->TIMINGR;
  constexpr u32 shift = FMPI2C_TIMINGR_SDADEL_SHIFT;
  constexpr u32 mask = FMPI2C_TIMINGR_SDADEL_MASK << shift;
  syn_set_register_bits(reg, mask, time << shift);
}

void
fmpi2c_set_data_setup_time(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 time
)
{
  devmode_assert_lower_or_eq(time, FMPI2C_TIMINGR_SCLDEL_MASK);
  volatile u32* reg = &fmpi2c->TIMINGR;
  constexpr u32 shift = FMPI2C_TIMINGR_SCLDEL_SHIFT;
  constexpr u32 mask = FMPI2C_TIMINGR_SCLDEL_MASK << shift;
  syn_set_register_bits(reg, mask, time << shift);
}

void
fmpi2c_set_timing_prescaler(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 prescaler
)
{
  devmode_assert_lower_or_eq(prescaler, FMPI2C_TIMINGR_SCLDEL_MASK);
  volatile u32* reg = &fmpi2c->TIMINGR;
  constexpr u32 shift = FMPI2C_TIMINGR_PRESC_SHIFT;
  constexpr u32 mask = FMPI2C_TIMINGR_PRESC_MASK << shift;
  syn_set_register_bits(reg, mask, prescaler << shift);
}

void
fmpi2c_set_timeouta(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 timeout
)
{
  devmode_assert_lower_or_eq(timeout, FMPI2C_TIMEOUTR_TIMEOUTA_MASK);
  volatile u32* reg = &fmpi2c->TIMEOUTR;
  constexpr u32 shift = FMPI2C_TIMEOUTR_TIMEOUTA_SHIFT;
  constexpr u32 mask = FMPI2C_TIMEOUTR_TIMEOUTA_MASK << shift;
  syn_set_register_bits(reg, mask, timeout << shift);
}

void
fmpi2c_idle_clock_timeout_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->TIMEOUTR |= FMPI2C_TIMEOUTR_TIDLE;
}

void
fmpi2c_idle_clock_timeout_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->TIMEOUTR &= ~FMPI2C_TIMEOUTR_TIDLE;
}

void
fmpi2c_clock_timeout_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->TIMEOUTR |= FMPI2C_TIMEOUTR_TIMEOUTEN;
}

void
fmpi2c_clock_timeout_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->TIMEOUTR &= ~FMPI2C_TIMEOUTR_TIMEOUTEN;
}

void
fmpi2c_set_timeoutb(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 timeout
)
{
  devmode_assert_lower_or_eq(timeout, FMPI2C_TIMEOUTR_TIMEOUTB_MASK);
  volatile u32* reg = &fmpi2c->TIMEOUTR;
  constexpr u32 shift = FMPI2C_TIMEOUTR_TIMEOUTB_SHIFT;
  constexpr u32 mask = FMPI2C_TIMEOUTR_TIMEOUTB_MASK << shift;
  syn_set_register_bits(reg, mask, timeout << shift);
}

void
fmpi2c_extended_clock_timeout_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->TIMEOUTR |= FMPI2C_TIMEOUTR_TEXTEN;
}

void
fmpi2c_extended_clock_timeout_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->TIMEOUTR &= ~FMPI2C_TIMEOUTR_TEXTEN;
}

u32
fmpi2c_is_flag_set(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_flag flag
)
{
  volatile u32* reg = &fmpi2c->ISR;
  switch (flag)
  {
    case FMPI2C_FLAG_TXE:
      return *reg & FMPI2C_ISR_TXE;
      break;

    case FMPI2C_FLAG_TXI:
      return *reg & FMPI2C_ISR_TXIS;
      break;

    case FMPI2C_FLAG_RXNE:
      return *reg & FMPI2C_ISR_RXNE;
      break;

    case FMPI2C_FLAG_ADDR_MATCH:
      return *reg & FMPI2C_ISR_ADDR;
      break;

    case FMPI2C_FLAG_NACK:
      return *reg & FMPI2C_ISR_NACKF;
      break;

    case FMPI2C_FLAG_STOP:
      return *reg & FMPI2C_ISR_STOPF;
      break;

    case FMPI2C_FLAG_TRANSFER_COMPLETE:
      return *reg & FMPI2C_ISR_TC;
      break;

    case FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD:
      return *reg & FMPI2C_ISR_TCR;
      break;

    case FMPI2C_FLAG_BUS_ERR:
      return *reg & FMPI2C_ISR_BERR;
      break;

    case FMPI2C_FLAG_ARBITRATION_LOST:
      return *reg & FMPI2C_ISR_ARLO;
      break;

    case FMPI2C_FLAG_OVERRUN_UNDERRUN:
      return *reg & FMPI2C_ISR_OVR;
      break;

    case FMPI2C_FLAG_PEC_ERR:
      return *reg & FMPI2C_ISR_PECERR;
      break;

    case FMPI2C_FLAG_TIMEOUT:
      return *reg & FMPI2C_ISR_TIMEOUT;
      break;

    case FMPI2C_FLAG_SMBUS_ALERT:
      return *reg & FMPI2C_ISR_ALERT;
      break;

    case FMPI2C_FLAG_BUS_BUSY:
      return *reg & FMPI2C_ISR_BUSY;
      break;

    case FMPI2C_FLAG_TRANSFER_DIRECTION:
      return *reg & FMPI2C_ISR_DIR;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_flag, flag);
      return 0;
  }
}

u32
fmpi2c_get_addr_match_code(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  volatile u32* reg = &fmpi2c->ISR;
  constexpr u32 shift = FMPI2C_ISR_ADDCODE_SHIFT;
  constexpr u32 mask = FMPI2C_ISR_ADDCODE_MASK;
  return (*reg >> shift) & mask;
}

void
fmpi2c_flush_tx(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->ISR |= FMPI2C_ISR_TXE;
}

void
fmpi2c_generate_txis_event(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  fmpi2c->ISR |= FMPI2C_ISR_TXIS;
}

void
fmpi2c_flag_clear(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_flag flag
)
{
  volatile u32* reg = &fmpi2c->ICR;
  switch (flag)
  {
    case FMPI2C_FLAG_ADDR_MATCH:
      *reg |= FMPI2C_ICR_ADDRCF;
      break;

    case FMPI2C_FLAG_NACK:
      *reg |= FMPI2C_ICR_NACKCF;
      break;

    case FMPI2C_FLAG_STOP:
      *reg |= FMPI2C_ICR_STOPCF;
      break;

    case FMPI2C_FLAG_BUS_ERR:
      *reg |= FMPI2C_ICR_BERRCF;
      break;

    case FMPI2C_FLAG_ARBITRATION_LOST:
      *reg |= FMPI2C_ICR_ARLOCF;
      break;

    case FMPI2C_FLAG_OVERRUN_UNDERRUN:
      *reg |= FMPI2C_ICR_OVRCF;
      break;

    case FMPI2C_FLAG_PEC_ERR:
      *reg |= FMPI2C_ICR_PECCF;
      break;

    case FMPI2C_FLAG_TIMEOUT:
      *reg |= FMPI2C_ICR_TIMEOUTCF;
      break;

    case FMPI2C_FLAG_SMBUS_ALERT:
      *reg |= FMPI2C_ICR_ALERTCF;
      break;

    default:
      devmode_error_invalid_enum(enum fmpi2c_flag, flag);
      break;
  }
}

u32
fmpi2c_get_pec(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  volatile u32* reg = &fmpi2c->PECR;
  constexpr u32 shift = FMPI2C_PECR_PEC_SHIFT;
  constexpr u32 mask = FMPI2C_PECR_PEC_MASK;
  return (*reg >> shift) & mask;
}

u32
fmpi2c_read_data(
  volatile struct fmpi2c_registers_map* fmpi2c
)
{
  return fmpi2c->RXDR;
}

void
fmpi2c_write_data(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 data
)
{
  devmode_assert_lower_or_eq(data, FMPI2C_TXDR_TXDATA_MASK);
  fmpi2c->TXDR = data;
}
