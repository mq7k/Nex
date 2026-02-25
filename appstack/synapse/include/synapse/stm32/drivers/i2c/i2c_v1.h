#ifndef STM32_DRIVER_I2C_H
#define STM32_DRIVER_I2C_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F1
 *  - STM32F4
 */

BEGIN_DECLARATIONS

struct i2c_registers_map
{
  u32 CR1;
  u32 CR2;
  u32 OAR1;
  u32 OAR2;
  u32 DR;
  u32 SR1;
  u32 SR2;
  u32 CCR;
  u32 TRISE;

#if defined(STM32_I2C_FILTER)
  u32 FLTR;
#endif
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum i2c_cr1 : u32
{
  I2C_CR1_PE = (1 << 0),
  I2C_CR1_SMBUS = (1 << 1),
  I2C_CR1_SMBTYPE = (1 << 3),
  I2C_CR1_ENARP = (1 << 4),
  I2C_CR1_ENPEC = (1 << 5),
  I2C_CR1_ENGC = (1 << 6),
  I2C_CR1_NOSTRETCH = (1 << 7),
  I2C_CR1_START = (1 << 8),
  I2C_CR1_STOP = (1 << 9),
  I2C_CR1_ACK = (1 << 10),
  I2C_CR1_POS = (1 << 11),
  I2C_CR1_PEC = (1 << 12),
  I2C_CR1_ALERT = (1 << 13),
  I2C_CR1_SWRST = (1 << 15)
};

enum i2c_cr2 : u32
{
  I2C_CR2_ITERREN = (1 << 8),
  I2C_CR2_ITEVTEN = (1 << 9),
  I2C_CR2_ITBUFEN = (1 << 10),
  I2C_CR2_DMAEN = (1 << 11),
  I2C_CR2_LAST = (1 << 12)
};

#define I2C_CR2_FREQ_SHIFT (0)
#define I2C_CR2_FREQ_MASK (0x3f)

enum i2c_oar1 : u32
{
  I2C_OAR1_ADD0 = (1 << 0),
  I2C_OAR1_ADDMODE = (1 << 15)
};

#define I2C_OAR1_ADD_7BIT_SHIFT (1)
#define I2C_OAR1_ADD_7BIT_MASK (0x3f)

#define I2C_OAR1_ADD_10BIT_SHIFT (0)
#define I2C_OAR1_ADD_10BIT_MASK (0x3ff)

enum i2c_oar2 : u32
{
  I2C_OAR2_ENDUAL = (1 << 0)
};

#define I2C_OAR2_ADD2_SHIFT (1)
#define I2C_OAR2_ADD2_MASK (0x7f)

#define I2C_DR_SHIFT (0)
#define I2C_DR_MASK (0xff)

enum i2c_sr1 : u32
{
  I2C_SR1_SB = (1 << 0),
  I2C_SR1_ADDR = (1 << 1),
  I2C_SR1_BTF = (1 << 2),
  I2C_SR1_ADD10 = (1 << 3),
  I2C_SR1_STOPF = (1 << 4),
  I2C_SR1_RxNE = (1 << 6),
  I2C_SR1_TxE = (1 << 7),
  I2C_SR1_BERR = (1 << 8),
  I2C_SR1_ARLO = (1 << 9),
  I2C_SR1_AF = (1 << 10),
  I2C_SR1_OVR = (1 << 11),
  I2C_SR1_PECERR = (1 << 12),
  I2C_SR1_TIMEOUT = (1 << 14),
  I2C_SR1_SMBALERT = (1 << 15)
};

enum i2c_sr2 : u32
{
  I2C_SR2_MSL = (1 << 0),
  I2C_SR2_BUSY = (1 << 1),
  I2C_SR2_TRA = (1 << 2),
  I2C_SR2_GENCALL = (1 << 4),
  I2C_SR2_SMBDEFAULT = (1 << 5),
  I2C_SR2_SMBHOST = (1 << 6),
  I2C_SR2_DUALF = (1 << 7)
};

#define I2C_SR2_PEC_SHIFT (8)
#define I2C_SR2_PEC_MASK (0xff)

enum i2c_ccr : u32
{
  I2C_CCR_DUTY = (1 << 14),
  I2C_CCR_FS = (1 << 15)
};

#define I2C_CCR_CCR_SHIFT (0)
#define I2C_CCR_CCR_MASK (0xfff)

#define I2C_TRISE_SHIFT (0)
#define I2C_TRISE_MASK (0x3f)

#if defined(STM32_I2C_FILTER)
enum i2c_fltr : u32
{
  I2C_FLTR_ANOFF = (1 << 4)
};

#define I2C_FLTR_DNF_SHIFT (0)
#define I2C_FLTR_DNF_MASK (0xf)

#endif

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum i2c_operational_mode
{
  I2C_OPERATIONAL_MODE_I2C,
  I2C_OPERATIONAL_MODE_SMBUS
};

enum i2c_smbus_type
{
  I2C_SMBUS_TYPE_DEVICE,
  I2C_SMBUS_TYPE_HOST
};

enum i2c_config
{
  I2C_CONFIG_ARP,
  I2C_CONFIG_PEC,
  I2C_CONFIG_GENERAL_CALL,
  I2C_CONFIG_NO_CLOCK_STRETCH,
};

enum i2c_interrupt
{
  I2C_INTERRUPT_ERROR,
  I2C_INTERRUPT_EVENT,
  I2C_INTERRUPT_BUFFER
};

enum i2c_address_mode
{
  I2C_ADDRESS_MODE_7BITS,
  I2C_ADDRESS_MODE_10BITS
};

enum i2c_flag
{
  I2C_FLAG_START_BIT,
  I2C_FLAG_ADDRESS,
  I2C_FLAG_BYTE_TRANSFER_FINISHED,
  I2C_FLAG_ADDRESS10,
  I2C_FLAG_STOP_BIT,
  I2C_FLAG_DATA_REG_NOT_EMPTY,
  I2C_FLAG_DATA_REG_EMPTY,
  I2C_FLAG_BUS_ERROR,
  I2C_FLAG_ARBITRACTION_LOST,
  I2C_FLAG_ACK_FAIL,
  I2C_FLAG_OVERRUN_UNDERRUN,
  I2C_FLAG_PEC_ERROR,
  I2C_FLAG_TIMEOUT,
  I2C_FLAG_SMBUS_ALERT,
  I2C_FLAG_MASTER_SLAVE,
  I2C_FLAG_BUS_BUSY,
  I2C_FLAG_BYTES_TRANSMITTED,
  I2C_FLAG_GENERAL_CALL_ADDRESS,
  I2C_FLAG_SMBUS_DEFAULT_ADDRESS,
  I2C_FLAG_SMBUS_HOST_HEADER,
  I2C_FLAG_DUAL_FLAG,
};

enum i2c_fm_duty_cycle
{
  I2C_FM_DUTY_CYCLE_2,
  I2C_FM_DUTY_CYCLE_16_9
};

enum i2c_master_mode
{
  I2C_MASTER_MODE_SM,
  I2C_MASTER_MODE_FM
};

#if defined(STM32_I2C1)
extern volatile struct i2c_registers_map* I2C1;
#endif

#if defined(STM32_I2C2)
extern volatile struct i2c_registers_map* I2C2;
#endif

#if defined(STM32_I2C3)
extern volatile struct i2c_registers_map* I2C3;
#endif

void
i2c_enable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_disable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_set_operational_mode(
  volatile struct i2c_registers_map* i2c,
  enum i2c_operational_mode mode
);

void
i2c_set_smbus_type(
  volatile struct i2c_registers_map* i2c,
  enum i2c_smbus_type type
);

void
i2c_config_enable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_config config
);

void
i2c_config_disable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_config config
);

void
i2c_transaction_start(
  volatile struct i2c_registers_map* i2c
);

void
i2c_transaction_stop(
  volatile struct i2c_registers_map* i2c
);

void
i2c_send_ack(
  volatile struct i2c_registers_map* i2c
);

void
i2c_send_nack(
  volatile struct i2c_registers_map* i2c
);

// Might need a better name.
void
i2c_nack_on_next_byte(
  volatile struct i2c_registers_map* i2c
);

// Might need a better name.
void
i2c_nack_on_current_byte(
  volatile struct i2c_registers_map* i2c
);

void
i2c_send_pec_byte(
  volatile struct i2c_registers_map* i2c
);

void
i2c_send_smbus_alert_enable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_send_smbus_alert_disable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_software_reset_enable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_software_reset_disable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_set_peripheral_clock_frequency(
  volatile struct i2c_registers_map* i2c,
  u32 frequency
);

void
i2c_interrupt_enable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_interrupt interrupt
);

void
i2c_interrupt_disable(
  volatile struct i2c_registers_map* i2c,
  enum i2c_interrupt interrupt
);

void
i2c_dma_requests_enable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_dma_requests_disable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_dma_last_transfer_enable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_dma_last_transfer_disable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_set_7bit_address(
  volatile struct i2c_registers_map* i2c,
  u32 address
);

void
i2c_set_10bit_address(
  volatile struct i2c_registers_map* i2c,
  u32 address
);

void
i2c_set_address_mode(
  volatile struct i2c_registers_map* i2c,
  enum i2c_address_mode mode
);

void
i2c_dual_addressing_mode_enable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_dual_addressing_mode_disable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_set_secondary_address(
  volatile struct i2c_registers_map* i2c,
  u32 address
);

void
i2c_send_byte(
  volatile struct i2c_registers_map* i2c,
  u32 byte
);

u32
i2c_read_byte(
  volatile struct i2c_registers_map* i2c
);

u32
i2c_is_flag_set(
  volatile struct i2c_registers_map* i2c,
  enum i2c_flag flag
);

void
i2c_flag_clear(
  volatile struct i2c_registers_map* i2c,
  enum i2c_flag flag
);

u32
i2c_get_pec(
  volatile struct i2c_registers_map* i2c
);

void
i2c_set_clock(
  volatile struct i2c_registers_map* i2c,
  u32 clock
);

void
i2c_set_fm_duty_cycle(
  volatile struct i2c_registers_map* i2c,
  enum i2c_fm_duty_cycle duty_cycle
);

void
i2c_set_master_mode(
  volatile struct i2c_registers_map* i2c,
  enum i2c_master_mode mode
);

void
i2c_set_trise_time(
  volatile struct i2c_registers_map* i2c,
  u32 trise_time
);

#if defined(STM32_I2C_FILTER)
void
i2c_set_digital_noise_filter_capability(
  volatile struct i2c_registers_map* i2c,
  u32 capability
);

void
i2c_digital_noise_filter_enable(
  volatile struct i2c_registers_map* i2c
);

void
i2c_digital_noise_filter_disable(
  volatile struct i2c_registers_map* i2c
);
#endif

END_DECLARATIONS

#endif
