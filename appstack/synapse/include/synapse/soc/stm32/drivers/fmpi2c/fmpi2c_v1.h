#ifndef STM32_DRIVER_FMPI2C_H
#define STM32_DRIVER_FMPI2C_H

#include "libcom/util.h"
#include "libcom/types.h"

BEGIN_DECLARATIONS

struct fmpi2c_registers_map
{
  u32 CR1;
  u32 CR2;
  u32 OAR1;
  u32 OAR2;
  u32 TIMINGR;
  u32 TIMEOUTR;
  u32 ISR;
  u32 ICR;
  u32 PECR;
  u32 RXDR;
  u32 TXDR;
};

// Core

enum fmpi2c_cr1 : u32
{
  FMPI2C_CR1_PE = (1 << 0),
  FMPI2C_CR1_TXIE = (1 << 1),
  FMPI2C_CR1_RXIE = (1 << 2),
  FMPI2C_CR1_ADDRIE = (1 << 3),
  FMPI2C_CR1_NACKIE = (1 << 4),
  FMPI2C_CR1_STOPIE = (1 << 5),
  FMPI2C_CR1_TCIE = (1 << 6),
  FMPI2C_CR1_ERRIE = (1 << 7),
  FMPI2C_CR1_ANFOFF = (1 << 12),
  FMPI2C_CR1_TXDMAEN = (1 << 14), 
  FMPI2C_CR1_RXDMAEN = (1 << 15),
  FMPI2C_CR1_SBC = (1 << 16),
  FMPI2C_CR1_NOSTRETCH = (1 << 17),
  FMPI2C_CR1_GCEN = (1 << 19),
  FMPI2C_CR1_SMBHEN = (1 << 20),
  FMPI2C_CR1_SMBDEN = (1 << 21),
  FMPI2C_CR1_ALERTEN = (1 << 22),
  FMPI2C_CR1_PECEN = (1 << 23)
};

#define FMPI2C_CR1_DNF_SHIFT (8)
#define FMPI2C_CR1_DNF_MASK (0xf)

enum fmpi2c_cr2 : u32
{
  FMPI2C_CR2_RDWRN = (1 << 10),
  FMPI2C_CR2_ADD10 = (1 << 11),
  FMPI2C_CR2_HEAD10R = (1 << 12),
  FMPI2C_CR2_START = (1 << 13),
  FMPI2C_CR2_STOP = (1 << 14),
  FMPI2C_CR2_NACK = (1 << 15),
  FMPI2C_CR2_RELOAD = (1 << 24),
  FMPI2C_CR2_AUTOEND = (1 << 25),
  FMPI2C_CR2_PECBYTE = (1 << 26)
};

#define FMPI2C_CR2_SADD_SHIFT (0)
#define FMPI2C_CR2_SADD_MASK (0x3ff)

#define FMPI2C_CR2_NBYTES_SHIFT (16)
#define FMPI2C_CR2_NBYTES_MASK (0xff)

enum fmpi2c_oar1 : u32
{
  FMPI2C_OAR1_OA1MODE = (1 << 10),
  FMPI2C_OAR1_OA1EN = (1 << 15)
};

#define FMPI2C_OAR1_OA1_7BIT_SHIFT (1)
#define FMPI2C_OAR1_OA1_7BIT_MASK (0x7fu)

#define FMPI2C_OAR1_OA1_10BIT_SHIFT (0)
#define FMPI2C_OAR1_OA1_10BIT_MASK (0x3ffu)

enum fmpi2c_oar2 : u32
{
  FMPI2C_OAR2_OA2EN = (1 << 15)
};

#define FMPI2C_OAR2_OA2_SHIFT (1)
#define FMPI2C_OAR2_OA2_MASK (0x7fu)

#define FMPI2C_OAR2_OA2MSK_SHIFT (8)
#define FMPI2C_OAR2_OA2MSK_MASK (0x7)

#define FMPI2C_TIMINGR_SCLL_SHIFT (0)
#define FMPI2C_TIMINGR_SCLL_MASK (0xff)

#define FMPI2C_TIMINGR_SCLH_SHIFT (8)
#define FMPI2C_TIMINGR_SCLH_MASK (0xff)

#define FMPI2C_TIMINGR_SDADEL_SHIFT (16)
#define FMPI2C_TIMINGR_SDADEL_MASK (0xf)

#define FMPI2C_TIMINGR_SCLDEL_SHIFT (20)
#define FMPI2C_TIMINGR_SCLDEL_MASK (0xf)

#define FMPI2C_TIMINGR_PRESC_SHIFT (28)
#define FMPI2C_TIMINGR_PRESC_MASK (0xfu)

enum fmpi2c_timeoutr : u32
{
  FMPI2C_TIMEOUTR_TIDLE = (1 << 12),
  FMPI2C_TIMEOUTR_TIMEOUTEN = (1 << 15),
  FMPI2C_TIMEOUTR_TEXTEN = (1u << 31)
};

#define FMPI2C_TIMEOUTR_TIMEOUTA_SHIFT (0)
#define FMPI2C_TIMEOUTR_TIMEOUTA_MASK (0xfff)

#define FMPI2C_TIMEOUTR_TIMEOUTB_SHIFT (16)
#define FMPI2C_TIMEOUTR_TIMEOUTB_MASK (0xfff)

enum fmpi2c_isr : u32
{
  FMPI2C_ISR_TXE = (1 << 0),
  FMPI2C_ISR_TXIS = (1 << 1),
  FMPI2C_ISR_RXNE = (1 << 2),
  FMPI2C_ISR_ADDR = (1 << 3),
  FMPI2C_ISR_NACKF = (1 << 4),
  FMPI2C_ISR_STOPF = (1 << 5),
  FMPI2C_ISR_TC = (1 << 6),
  FMPI2C_ISR_TCR = (1 << 7),
  FMPI2C_ISR_BERR = (1 << 8),
  FMPI2C_ISR_ARLO = (1 << 9),
  FMPI2C_ISR_OVR = (1 << 10),
  FMPI2C_ISR_PECERR = (1 << 11),
  FMPI2C_ISR_TIMEOUT = (1 << 12),
  FMPI2C_ISR_ALERT = (1 << 13),
  FMPI2C_ISR_BUSY = (1 << 15),
  FMPI2C_ISR_DIR = (1 << 16)
};

#define FMPI2C_ISR_ADDCODE_SHIFT (17)
#define FMPI2C_ISR_ADDCODE_MASK (0x7f)

enum fmpi2c_icr : u32
{
  FMPI2C_ICR_ADDRCF = (1 << 3),
  FMPI2C_ICR_NACKCF = (1 << 4),
  FMPI2C_ICR_STOPCF = (1 << 5),
  FMPI2C_ICR_BERRCF = (1 << 8),
  FMPI2C_ICR_ARLOCF = (1 << 9),
  FMPI2C_ICR_OVRCF = (1 << 10),
  FMPI2C_ICR_PECCF = (1 << 11),
  FMPI2C_ICR_TIMEOUTCF = (1 << 12),
  FMPI2C_ICR_ALERTCF = (1 << 13)
};

#define FMPI2C_PECR_PEC_SHIFT (0)
#define FMPI2C_PECR_PEC_MASK (0xff)

#define FMPI2C_RXDR_RXDATA_SHIFT (0)
#define FMPI2C_RXDR_RXDATA_MASK (0xff)

#define FMPI2C_TXDR_TXDATA_SHIFT (0)
#define FMPI2C_TXDR_TXDATA_MASK (0xff)

// API

enum fmpi2c_interrupt
{
  FMPI2C_INTERRUPT_TX,
  FMPI2C_INTERRUPT_RX,
  FMPI2C_INTERRUPT_ADDR_MATCH,
  FMPI2C_INTERRUPT_NACK,
  FMPI2C_INTERRUPT_STOP,
  FMPI2C_INTERRUPT_TRANSFER_COMPLETE,
  FMPI2C_INTERRUPT_ERR
};

enum fmpi2c_transfer_dir
{
  FMPI2C_TRANSFER_DIR_WRITE,
  FMPI2C_TRANSFER_DIR_READ
};

enum fmpi2c_addressing_mode
{
  FMPI2C_ADDRESSING_MODE_7BIT,
  FMPI2C_ADDRESSING_MODE_10BIT
};

enum fmpi2c_10bit_addr_dir_change_seq
{
  FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_HEADER_ONLY,
  FMPI2C_10BIT_ADDR_DIR_CHANGE_SEQ_FULL
};

enum fmpi2c_reload_mode
{
  FMPI2C_RELOAD_MODE_COMPLETE,
  FMPI2C_RELOAD_MODE_CONTINUE
};

enum fmpi2c_end_mode
{
  FMPI2C_END_MODE_SOFTWARE,
  FMPI2C_END_MODE_AUTOMATIC
};

enum fmpi2c_interface_addr
{
  FMPI2C_INTERFACE_ADDR1,
  FMPI2C_INTERFACE_ADDR2
};

enum fmpi2c_interface_addr_type
{
  FMPI2C_INTERFACE_ADDR_TYPE_7BIT,
  FMPI2C_INTERFACE_ADDR_TYPE_10BIT
};

enum fmpi2c_flag
{
  FMPI2C_FLAG_TXE,
  FMPI2C_FLAG_TXI,
  FMPI2C_FLAG_RXNE,
  FMPI2C_FLAG_ADDR_MATCH,
  FMPI2C_FLAG_NACK,
  FMPI2C_FLAG_STOP,
  FMPI2C_FLAG_TRANSFER_COMPLETE,
  FMPI2C_FLAG_TRANSFER_COMPLETE_RELOAD,
  FMPI2C_FLAG_BUS_ERR,
  FMPI2C_FLAG_ARBITRATION_LOST,
  FMPI2C_FLAG_OVERRUN_UNDERRUN,
  FMPI2C_FLAG_PEC_ERR,
  FMPI2C_FLAG_TIMEOUT,
  FMPI2C_FLAG_SMBUS_ALERT,
  FMPI2C_FLAG_BUS_BUSY,
  FMPI2C_FLAG_TRANSFER_DIRECTION
};

extern struct fmpi2c_registers_map* FMPI2C1;

void
fmpi2c_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_interrupt_enable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interrupt interrupt
);

void
fmpi2c_interrupt_disable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interrupt interrupt
);

void
fmpi2c_set_digital_noise_filter(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 filter
);

void
fmpi2c_analog_noise_filter_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_analog_noise_filter_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_dma_tx_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_dma_tx_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_dma_rx_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_dma_rx_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_target_byte_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_target_byte_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_clock_stretching_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_clock_stretching_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_general_call_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_general_call_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_smbus_host_addr_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_smbus_host_addr_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_smbus_device_default_addr_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_smbus_device_default_addr_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_smbus_alert_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_smbus_alert_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_pec_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_pec_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_set_target_addr(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 addr
);

void
fmpi2c_set_transfer_direction(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_transfer_dir dir
);

void
fmpi2c_set_addressing_mode(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_addressing_mode mode
);

void
fmpi2c_set_10bit_addr_dir_change_seq(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_10bit_addr_dir_change_seq seq
);

void
fmpi2c_generate_start(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_generate_stop(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_generate_nack(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_set_transfer_bytes_count(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 count
);

void
fmpi2c_set_reload_mode(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_reload_mode mode
);

void
fmpi2c_set_end_mode(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_end_mode mode
);

void
fmpi2c_pec_byte_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_pec_byte_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_set_interface_7bit_addr(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr addr,
  u32 val
);

void
fmpi2c_set_interface_10bit_addr(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 val
);

void
fmpi2c_set_interface_addr1_type(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr_type type
);

void
fmpi2c_interface_addr_enable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr addr
);

void
fmpi2c_interface_addr_disable(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_interface_addr addr
);

void
fmpi2c_set_interface_addr2_mask(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 bitmask
);

void
fmpi2c_set_scl_low_period(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 period
);

void
fmpi2c_set_scl_high_period(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 period
);

void
fmpi2c_set_data_hold_time(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 time
);

void
fmpi2c_set_data_setup_time(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 time
);

void
fmpi2c_set_timing_prescaler(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 prescaler
);

void
fmpi2c_set_timeouta(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 timeout
);

void
fmpi2c_idle_clock_timeout_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_idle_clock_timeout_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_clock_timeout_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_clock_timeout_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_set_timeoutb(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 timeout
);

void
fmpi2c_extended_clock_timeout_enable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_extended_clock_timeout_disable(
  volatile struct fmpi2c_registers_map* fmpi2c
);

u32
fmpi2c_is_flag_set(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_flag flag
);

u32
fmpi2c_get_addr_match_code(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_flush_tx(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_generate_txis_event(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_flag_clear(
  volatile struct fmpi2c_registers_map* fmpi2c,
  enum fmpi2c_flag flag
);

u32
fmpi2c_get_pec(
  volatile struct fmpi2c_registers_map* fmpi2c
);

u32
fmpi2c_read_data(
  volatile struct fmpi2c_registers_map* fmpi2c
);

void
fmpi2c_write_data(
  volatile struct fmpi2c_registers_map* fmpi2c,
  u32 data
);

END_DECLARATIONS

#endif
