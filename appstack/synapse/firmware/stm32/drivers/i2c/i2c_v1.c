#include "synapse/stm32/drivers/i2c/i2c_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct i2c_registers_map i2c_periph;

#if defined(STM32_I2C1)
i2c_periph* I2C1 = (i2c_periph*) (I2C1_ADDR);
#endif

#if defined(STM32_I2C2)
i2c_periph* I2C2 = (i2c_periph*) (I2C2_ADDR);
#endif

#if defined(STM32_I2C3)
i2c_periph* I2C3 = (i2c_periph*) (I2C3_ADDR);
#endif

void
i2c_enable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_PE;
}

void
i2c_disable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 &= ~I2C_CR1_PE;
}

void
i2c_set_operational_mode(
  volatile struct i2c_registers_map* i2c,
  enum i2c_operational_mode mode
)
{
  volatile u32* reg = &i2c->CR1;
  switch (mode)
  {
    case I2C_OPERATIONAL_MODE_I2C:
      *reg &= ~I2C_CR1_SMBUS;
      break;

    case I2C_OPERATIONAL_MODE_SMBUS:
      *reg |= I2C_CR1_SMBUS;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_operational_mode, mode);
      break;
  }
}

void
i2c_set_smbus_type(
  volatile struct i2c_registers_map* i2c,
  enum i2c_smbus_type type
)
{
  volatile u32* reg = &i2c->CR1;
  switch (type)
  {
    case I2C_SMBUS_TYPE_DEVICE:
      *reg &= ~I2C_CR1_SMBTYPE;
      break;

    case I2C_SMBUS_TYPE_HOST:
      *reg |= I2C_CR1_SMBTYPE;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_smbus_type, type);
      break;
  }
}

void
i2c_config_enable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_config config
)
{
  volatile u32* reg = &i2c->CR1;
  switch (config)
  {
    case I2C_CONFIG_ARP:
      *reg |= I2C_CR1_ENARP;
      break;

    case I2C_CONFIG_PEC:
      *reg |= I2C_CR1_ENPEC;
      break;

    case I2C_CONFIG_GENERAL_CALL:
      *reg |= I2C_CR1_ENGC;
      break;

    case I2C_CONFIG_NO_CLOCK_STRETCH:
      *reg |= I2C_CR1_NOSTRETCH;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_config, config);
      break;
  }
}

void
i2c_config_disable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_config config
)
{
  volatile u32* reg = &i2c->CR1;
  switch (config)
  {
    case I2C_CONFIG_ARP:
      *reg &= ~I2C_CR1_ENARP;
      break;

    case I2C_CONFIG_PEC:
      *reg &= ~I2C_CR1_ENPEC;
      break;

    case I2C_CONFIG_GENERAL_CALL:
      *reg &= ~I2C_CR1_ENGC;
      break;

    case I2C_CONFIG_NO_CLOCK_STRETCH:
      *reg &= ~I2C_CR1_NOSTRETCH;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_config, config);
      break;
  }
}

void
i2c_transaction_start(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_START;
}

void
i2c_transaction_stop(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_STOP;
}

void
i2c_send_ack(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_ACK;
}

void
i2c_send_nack(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 &= ~I2C_CR1_ACK;
}

// Might need a better name.
void
i2c_nack_on_next_byte(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_POS;
}

// Might need a better name.
void
i2c_nack_on_current_byte(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 &= ~I2C_CR1_POS;
}

void
i2c_send_pec_byte(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_PEC;
}

void
i2c_send_smbus_alert_enable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_ALERT;
}

void
i2c_send_smbus_alert_disable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 &= ~I2C_CR1_ALERT;
}

void
i2c_software_reset_enable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 |= I2C_CR1_SWRST;
}

void
i2c_software_reset_disable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR1 &= ~I2C_CR1_SWRST;
}

void
i2c_set_peripheral_clock_frequency(
  volatile struct i2c_registers_map* i2c,
  u32 frequency
)
{
  devmode_assert_lower_or_eq(frequency, I2C_CR2_FREQ_MASK);

  constexpr u32 shift = I2C_CR2_FREQ_SHIFT;
  constexpr u32 mask = I2C_CR2_FREQ_MASK << shift;
  volatile u32* reg = &i2c->CR2;
  syn_set_register_bits(reg, mask, frequency << shift);
}

void
i2c_interrupt_enable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_interrupt interrupt
)
{
  volatile u32* reg = &i2c->CR2;
  switch (interrupt)
  {
    case I2C_INTERRUPT_ERROR:
      *reg |= I2C_CR2_ITERREN;
      break;

    case I2C_INTERRUPT_EVENT:
      *reg |= I2C_CR2_ITEVTEN;
      break;

    case I2C_INTERRUPT_BUFFER:
      *reg |= I2C_CR2_ITBUFEN;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_interrupt, interrupt);
      break;
  }
}

void
i2c_interrupt_disable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_interrupt interrupt
)
{
  volatile u32* reg = &i2c->CR2;
  switch (interrupt)
  {
    case I2C_INTERRUPT_ERROR:
      *reg &= ~I2C_CR2_ITERREN;
      break;

    case I2C_INTERRUPT_EVENT:
      *reg &= ~I2C_CR2_ITEVTEN;
      break;

    case I2C_INTERRUPT_BUFFER:
      *reg &= ~I2C_CR2_ITBUFEN;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_interrupt, interrupt);
      break;
  }
}

void
i2c_dma_requests_enable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR2 |= I2C_CR2_DMAEN;
}

void
i2c_dma_requests_disable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR2 &= ~I2C_CR2_DMAEN;
}

void
i2c_dma_last_transfer_enable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR2 |= I2C_CR2_LAST;
}

void
i2c_dma_last_transfer_disable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->CR2 &= ~I2C_CR2_LAST;
}

void
i2c_set_7bit_address(
  volatile struct i2c_registers_map* i2c,
  u32 address
)
{
  devmode_assert_lower_or_eq(address, I2C_OAR1_ADD_7BIT_MASK);

  constexpr u32 shift = I2C_OAR1_ADD_7BIT_SHIFT;
  constexpr u32 mask = I2C_OAR1_ADD_7BIT_MASK << shift;
  volatile u32* reg = &i2c->OAR1;
  syn_set_register_bits(reg, mask, address << shift);
}

void
i2c_set_10bit_address(
  volatile struct i2c_registers_map* i2c,
  u32 address
)
{
  devmode_assert_lower_or_eq(address, I2C_OAR1_ADD_10BIT_MASK);

  constexpr u32 shift = I2C_OAR1_ADD_10BIT_SHIFT;
  constexpr u32 mask = I2C_OAR1_ADD_10BIT_MASK << shift;
  volatile u32* reg = &i2c->OAR1;
  syn_set_register_bits(reg, mask, address << shift);
}

void
i2c_set_address_mode(
  volatile struct i2c_registers_map* i2c,
  enum i2c_address_mode mode
)
{
  volatile u32* reg = &i2c->OAR1;
  switch (mode)
  {
    case I2C_ADDRESS_MODE_7BITS:
      *reg &= ~I2C_OAR1_ADDMODE;
      break;

    case I2C_ADDRESS_MODE_10BITS:
      *reg |= I2C_OAR1_ADDMODE;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_address_mode, mode);
      break;
  }
}

void
i2c_dual_addressing_mode_enable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->OAR2 |= I2C_OAR2_ENDUAL;
}

void
i2c_dual_addressing_mode_disable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->OAR2 &= ~I2C_OAR2_ENDUAL;
}

void
i2c_set_secondary_address(
  volatile struct i2c_registers_map* i2c,
  u32 address
)
{
  devmode_assert_lower_or_eq(address, I2C_OAR2_ADD2_MASK);

  constexpr u32 shift = I2C_OAR2_ADD2_SHIFT;
  constexpr u32 mask = I2C_OAR2_ADD2_MASK << shift;
  volatile u32* reg = &i2c->OAR2;
  syn_set_register_bits(reg, mask, address << shift);
}

void
i2c_send_byte(
  volatile struct i2c_registers_map* i2c,
  u32 byte
)
{
  devmode_assert_lower_or_eq(byte, I2C_DR_MASK);

  constexpr u32 shift = I2C_DR_SHIFT;
  constexpr u32 mask = I2C_DR_MASK << shift;
  volatile u32* reg = &i2c->DR;
  syn_set_register_bits(reg, mask, byte << shift);
}

u32
i2c_read_byte(
  volatile struct i2c_registers_map* i2c
)
{
  return (i2c->DR >> I2C_DR_SHIFT) & I2C_DR_MASK;
}

u32
i2c_is_flag_set(
  volatile struct i2c_registers_map* i2c,
  enum i2c_flag flag
)
{
  switch (flag)
  {
    case I2C_FLAG_START_BIT:
      return i2c->SR1 & I2C_SR1_SB;

    case I2C_FLAG_ADDRESS:
      return i2c->SR1 & I2C_SR1_ADDR;

    case I2C_FLAG_BYTE_TRANSFER_FINISHED:
      return i2c->SR1 & I2C_SR1_BTF;

    case I2C_FLAG_ADDRESS10:
      return i2c->SR1 & I2C_SR1_ADD10;

    case I2C_FLAG_STOP_BIT:
      return i2c->SR1 & I2C_SR1_STOPF;

    case I2C_FLAG_DATA_REG_NOT_EMPTY:
      return i2c->SR1 & I2C_SR1_RxNE;

    case I2C_FLAG_DATA_REG_EMPTY:
      return i2c->SR1 & I2C_SR1_TxE;

    case I2C_FLAG_BUS_ERROR:
      return i2c->SR1 & I2C_SR1_BERR;

    case I2C_FLAG_ARBITRACTION_LOST:
      return i2c->SR1 & I2C_SR1_ARLO;

    case I2C_FLAG_ACK_FAIL:
      return i2c->SR1 & I2C_SR1_AF;

    case I2C_FLAG_OVERRUN_UNDERRUN:
      return i2c->SR1 & I2C_SR1_OVR;

    case I2C_FLAG_PEC_ERROR:
      return i2c->SR1 & I2C_SR1_PECERR;

    case I2C_FLAG_TIMEOUT:
      return i2c->SR1 & I2C_SR1_TIMEOUT;

    case I2C_FLAG_SMBUS_ALERT:
      return i2c->SR1 & I2C_SR1_SMBALERT;

    case I2C_FLAG_MASTER_SLAVE:
      return i2c->SR2 & I2C_SR2_MSL;
      
    case I2C_FLAG_BUS_BUSY:
      return i2c->SR2 & I2C_SR2_BUSY;

    case I2C_FLAG_BYTES_TRANSMITTED:
      return i2c->SR2 & I2C_SR2_TRA;

    case I2C_FLAG_GENERAL_CALL_ADDRESS:
      return i2c->SR2 & I2C_SR2_GENCALL;

    case I2C_FLAG_SMBUS_DEFAULT_ADDRESS:
      return i2c->SR2 & I2C_SR2_SMBDEFAULT;

    case I2C_FLAG_SMBUS_HOST_HEADER:
      return i2c->SR2 & I2C_SR2_SMBHOST;

    case I2C_FLAG_DUAL_FLAG:
      return i2c->SR2 & I2C_SR2_DUALF;

    default:
      devmode_error_invalid_enum(enum i2c_flag, flag);
      return 0;
  }
}

void
i2c_flag_clear(
  volatile struct i2c_registers_map* i2c,
  enum i2c_flag flag
)
{
  switch (flag)
  {
    case I2C_FLAG_BUS_ERROR:
      i2c->SR1 &= ~I2C_SR1_BERR;
      break;

    case I2C_FLAG_ARBITRACTION_LOST:
      i2c->SR1 &= ~I2C_SR1_ARLO;
      break;

    case I2C_FLAG_ACK_FAIL:
      i2c->SR1 &= ~I2C_SR1_AF;
      break;

    case I2C_FLAG_OVERRUN_UNDERRUN:
      i2c->SR1 &= ~I2C_SR1_OVR;
      break;

    case I2C_FLAG_PEC_ERROR:
      i2c->SR1 &= ~I2C_SR1_PECERR;
      break;

    case I2C_FLAG_TIMEOUT:
      i2c->SR1 &= ~I2C_SR1_TIMEOUT;
      break;

    case I2C_FLAG_SMBUS_ALERT:
      i2c->SR1 &= ~I2C_SR1_SMBALERT;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_flag, flag);
      break;
  }
}

u32
i2c_get_pec(
  volatile struct i2c_registers_map* i2c
)
{
  constexpr u32 shift = I2C_SR2_PEC_SHIFT;
  constexpr u32 mask = I2C_SR2_PEC_MASK;
  return (i2c->SR2 >> shift) & mask;
}

void
i2c_set_clock(
  volatile struct i2c_registers_map* i2c,
  u32 clock
)
{
  devmode_assert_lower_or_eq(clock, I2C_CCR_CCR_MASK);

  constexpr u32 shift = I2C_CCR_CCR_SHIFT;
  constexpr u32 mask = I2C_CCR_CCR_MASK << shift;
  volatile u32* reg = &i2c->CCR;
  syn_set_register_bits(reg, mask, clock << shift);
}

void
i2c_set_fm_duty_cycle(
  volatile struct i2c_registers_map* i2c,
  enum i2c_fm_duty_cycle duty_cycle
)
{
  volatile u32* reg = &i2c->CCR;
  switch (duty_cycle)
  {
    case I2C_FM_DUTY_CYCLE_2:
      *reg &= ~I2C_CCR_DUTY;
      break;

    case I2C_FM_DUTY_CYCLE_16_9:
      *reg |= I2C_CCR_DUTY;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_fm_duty_cycle, duty_cycle);
      break;
  }
}

void
i2c_set_master_mode(
  volatile struct i2c_registers_map* i2c,
  enum i2c_master_mode mode
)
{
  volatile u32* reg = &i2c->CCR;
  switch (mode)
  {
    case I2C_MASTER_MODE_SM:
      *reg &= ~I2C_CCR_FS;
      break;

    case I2C_MASTER_MODE_FM:
      *reg |= I2C_CCR_FS;
      break;

    default:
      devmode_error_invalid_enum(enum i2c_master_mode, mode);
      break;
  }
}

void
i2c_set_trise_time(
  volatile struct i2c_registers_map* i2c,
  u32 trise_time
)
{
  devmode_assert_lower_or_eq(trise_time, I2C_TRISE_MASK);

  constexpr u32 shift = I2C_TRISE_SHIFT;
  constexpr u32 mask = I2C_TRISE_MASK << shift;
  volatile u32* reg = &i2c->TRISE;
  syn_set_register_bits(reg, mask, trise_time << shift);
}

#if defined(STM32_I2C_FILTER)
void
i2c_set_digital_noise_filter_capability(
  volatile struct i2c_registers_map* i2c,
  u32 capability
)
{
  devmode_assert_lower_or_eq(capability, I2C_FLTR_DNF_MASK);
  constexpr u32 shift = I2C_FLTR_DNF_SHIFT;
  constexpr u32 mask = I2C_FLTR_DNF_MASK << shift;
  volatile u32* reg = &i2c->FLTR;
  syn_set_register_bits(reg, mask, capability << shift);
}

void
i2c_digital_noise_filter_enable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->FLTR |= I2C_FLTR_ANOFF;
}

void
i2c_digital_noise_filter_disable(
  volatile struct i2c_registers_map* i2c
)
{
  i2c->FLTR &= ~I2C_FLTR_ANOFF;
}
#endif
