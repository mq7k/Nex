#ifndef STM32_DRIVER_USART_H
#define STM32_DRIVER_USART_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

#include <stdarg.h>

/**
 * Supports:
 *  - STM32F1
 *  - STM32F4
 */

BEGIN_DECLARATIONS

struct usart_registers_map
{
  u32 SR;
  u32 DR;
  u32 BRR;
  u32 CR1;
  u32 CR2;
  u32 CR3;
  u32 GTPR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum usart_sr : u32
{
  USART_SR_PE = (1 << 0),
  USART_SR_FE = (1 << 1),
  USART_SR_NF = (1 << 2),
  USART_SR_ORE = (1 << 3),
  USART_SR_IDLE = (1 << 4),
  USART_SR_RxNE = (1 << 5),
  USART_SR_TC = (1 << 6),
  USART_SR_TxE = (1 << 7),
  USART_SR_LBD = (1 << 8),
  USART_SR_CTS = (1 << 9)
};

#define USART_DR_SHIFT (0)
#define USART_DR_MASK (0x1ff)

#define USART_BRR_MASK (0xffff)

#define USART_BRR_FRACTION_SHIFT (0)
#define USART_BRR_FRACTION_MASK (0xf)

#define USART_BRR_MANTISSA_SHIFT (4)
#define USART_BRR_MANTISSA_MASK (0xfff)

enum usart_cr1 : u32
{
  USART_CR1_SBK = (1 << 0),
  USART_CR1_RWU = (1 << 1),
  USART_CR1_RE = (1 << 2),
  USART_CR1_TE = (1 << 3),
  USART_CR1_IDLEIE = (1 << 4),
  USART_CR1_RXNEIE = (1 << 5),
  USART_CR1_TCIE = (1 << 6),
  USART_CR1_TXEIE = (1 << 7),
  USART_CR1_PEIE = (1 << 8),
  USART_CR1_PS = (1 << 9),
  USART_CR1_PCE = (1 << 10),
  USART_CR1_WAKE = (1 << 11),
  USART_CR1_M = (1 << 12),
  USART_CR1_UE = (1 << 13),

#if defined(STM32_USART_OVERSAMPLING)
  USART_CR1_OVER8 = (1 << 15)
#endif
};

enum usart_cr2 : u32
{
  USART_CR2_LBDL = (1 << 5),
  USART_CR2_LBDIE = (1 << 6),
  USART_CR2_LBCL = (1 << 8),
  USART_CR2_CPHA = (1 << 9),
  USART_CR2_CPOL = (1 << 10),
  USART_CR2_CLKEN = (1 << 11),
  USART_CR2_LINEN = (1 << 14)
};

#define USART_CR2_ADD_SHIFT (0)
#define USART_CR2_ADD_MASK (0xf)

#define USART_CR2_STOP_BITS_SHIFT (12)
#define USART_CR2_STOP_BITS_MASK (0x3)

enum usart_cr2_stop_bits : u32
{
  USART_CR2_STOP_BITS_1BIT = 0b00,
  USART_CR2_STOP_BITS_0DOT5BITS = 0b01,
  USART_CR2_STOP_BITS_2BITS = 0b10,
  USART_CR2_STOP_BITS_1DOT5_BITS = 0b11
};

enum usart_cr3 : u32
{
  USART_CR3_EIE = (1 << 0),
  USART_CR3_IREN = (1 << 1),
  USART_CR3_IRLP = (1 << 2),
  USART_CR3_HDSEL = (1 << 3),
  USART_CR3_NACK = (1 << 4),
  USART_CR3_SCEN = (1 << 5),
  USART_CR3_DMAR = (1 << 6),
  USART_CR3_DMAT = (1 << 7),
  USART_CR3_RTSE = (1 << 8),
  USART_CR3_CTSE = (1 << 9),
  USART_CR3_CTSIE = (1 << 10),

#if defined(STM32_USART_ONEBIT_SAMPLING)
  USART_CR3_ONEBIT = (1 << 11)
#endif
};

#define USART_GTPR_PSC_SHIFT (0)
#define USART_GTPR_PSC_MASK (0xff)

#define USART_GTPR_GT_SHIFT (8)
#define USART_GTPR_GT_MASK (0xff)

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum usart_flag
{
  USART_FLAG_PARITY_ERROR,
  USART_FLAG_FRAMING_ERROR,
  USART_FLAG_NOISE_ERROR,
  USART_FLAG_OVERRUN_ERROR,
  USART_FLAG_IDLE_LINE,
  USART_FLAG_READ_REG_NOT_EMPTY,
  USART_FLAG_TRANSMISSION_COMPLETE,
  USART_FLAG_TRANSMIT_REG_EMPTY,
  USART_FLAG_LIN_BREAK,
  USART_FLAG_CTS
};

enum usart_receiver_mode
{
  USART_RECEIVER_MODE_ACTIVE,
  USART_RECEIVER_MODE_MUTE
};

enum usart_interrupt
{
  USART_INTERRUPT_IDLE,
  USART_INTERRUPT_READ_REG_NOT_EMPTY,
  USART_INTERRUPT_TRANSMITTION_COMPLETE,
  USART_INTERRUPT_WRITE_REG_EMPTY,
  USART_INTERRUPT_PARITY_ERROR,
  USART_INTERRUPT_LINE_BREAK_DETECTION,
  USART_INTERRUPT_ERROR,
  USART_INTERRUPT_CTS
};

enum usart_parity
{
  USART_PARITY_EVEN,
  USART_PARITY_ODD
};

enum usart_wakeup_method
{
  USART_WAKEUP_METHOD_IDLE_LINE,
  USART_WAKEUP_METHOD_ADDRESS_MARK
};

enum usart_word_length
{
  USART_WORD_LENGTH_8BITS,
  USART_WORD_LENGTH_9BITS
};

#if defined(STM32_USART_OVERSAMPLING)
enum usart_oversampling_mode
{
  USART_OVERSAMPLING_MODE16,
  USART_OVERSAMPLING_MODE8
};
#endif

enum usart_line_break_length
{
  USART_LINE_BREAK_LENGTH_10BITS,
  USART_LINE_BREAK_LENGTH_11BITS
};

enum usart_clock_phase
{
  USART_CLOCK_PHASE_FIRST,
  USART_CLOCK_PHASE_SECOND
};

enum usart_clock_polarity
{
  USART_CLOCK_POLARITY_STEADY_LOW,
  USART_CLOCK_POLARITY_STEADY_HIGH
};

enum usart_stop_bits
{
  USART_STOP_BITS_1BIT,
  USART_STOP_BITS_0DOT5_BITS,
  USART_STOP_BITS_2BITS,
  USART_STOP_BITS_1DOT5_BITS
};

#if defined(STM32_USART_ONEBIT_SAMPLING)
enum usart_onebit_sampling_method
{
  USART_ONEBIT_SAMPLING_METHOD_THREE_SAMPLE,
  USART_ONEBIT_SAMPLING_METHOD_ONE_SAMPLE
};
#endif

#if defined(STM32_USART1)
extern volatile struct usart_registers_map* USART1;
#endif

#if defined(STM32_USART2)
extern volatile struct usart_registers_map* USART2;
#endif

#if defined(STM32_USART3)
extern volatile struct usart_registers_map* USART3;
#endif

#if defined(STM32_UART4)
extern volatile struct usart_registers_map* UART4;
#endif

#if defined(STM32_UART5)
extern volatile struct usart_registers_map* UART5;
#endif

#if defined(STM32_USART6)
extern volatile struct usart_registers_map* USART6;
#endif

#if defined(STM32_UART7)
extern volatile struct usart_registers_map* UART7;
#endif

#if defined(STM32_UART8)
extern volatile struct usart_registers_map* UART8;
#endif

#if defined(STM32_UART9)
extern volatile struct usart_registers_map* UART9;
#endif

#if defined(STM32_UART10)
extern volatile struct usart_registers_map* UART10;
#endif

u32
usart_is_flag_set(
  volatile struct usart_registers_map* usart,
  enum usart_flag flag
);

void
usart_flag_clear(
  volatile struct usart_registers_map* usart,
  enum usart_flag flag
);

void
usart_flag_clear_multibuffer(
  volatile struct usart_registers_map* usart,
  enum usart_flag flag
);

u32
usart_data_read(
  volatile struct usart_registers_map* usart
);

void
usart_send_byte(
  volatile struct usart_registers_map* usart,
  u32 data
);

void
usart_send_str(
  volatile struct usart_registers_map* usart,
  const char* str
);

void
usart_send_strln(
  volatile struct usart_registers_map* usart,
  const char* str
);

void
usart_send_strf(
  volatile struct usart_registers_map* usart,
  const char* fmt,
  ...
);

void
usart_send_strfln(
  volatile struct usart_registers_map* usart,
  const char* fmt,
  ...
);

void
usart_send_strfv(
  volatile struct usart_registers_map* usart,
  const char* fmt,
  va_list list
);

// void
// usart_send_signed_int(
//   volatile struct usart_registers_map* usart,
//   i32 value
// );
//
// void
// usart_send_unsigned_int(
//   volatile struct usart_registers_map* usart,
//   u32 value
// );
//
// void
// usart_send_double(
//   volatile struct usart_registers_map* usart,
//   double value
// );
//
// void
// usart_send_hex(
//   volatile struct usart_registers_map* usart,
//   u32 value
// );
//
// void
// usart_send_binary(
//   volatile struct usart_registers_map* usart,
//   u32 value
// );
//
// void
// usart_send_boolean(
//   volatile struct usart_registers_map* usart,
//   u32 value
// );

// baudrate_arg = round(clock / baudrate)
// baudrate_arg = (u32) ((clock / baudrate) + 0.5f)
// where:
//  baudrate_arg -> The value to pass to this function
//  clock -> The bus clock the peripheral is connected to.
//  baudrate -> The desired peripheral baudrate (9600, 115200, ...)
void
usart_set_baudrate(
  volatile struct usart_registers_map* usart,
  u32 clock,
  u32 baudrate
);

void
usart_set_bittime(
  volatile struct usart_registers_map* usart,
  u32 bittime
);

void
usart_set_div_fraction(
  volatile struct usart_registers_map* usart,
  u32 fraction
);

void
usart_set_div_mantissa(
  volatile struct usart_registers_map* usart,
  u32 mantissa
);

void
usart_send_break(
  volatile struct usart_registers_map* usart
);

void
usart_set_receiver_mode(
  volatile struct usart_registers_map* usart,
  enum usart_receiver_mode mode
);

void
usart_receiver_enable(
  volatile struct usart_registers_map* usart
);

void
usart_receiver_disable(
  volatile struct usart_registers_map* usart
);

void
usart_transmitter_enable(
  volatile struct usart_registers_map* usart
);

void
usart_transmitter_disable(
  volatile struct usart_registers_map* usart
);

void
usart_interrupt_enable(
  volatile struct usart_registers_map* usart,
  enum usart_interrupt interrupt
);

void
usart_interrupt_disable(
  volatile struct usart_registers_map* usart,
  enum usart_interrupt interrupt
);

void
usart_set_parity(
  volatile struct usart_registers_map* usart,
  enum usart_parity parity
);

void
usart_parity_control_enable(
  volatile struct usart_registers_map* usart
);

void
usart_parity_control_disable(
  volatile struct usart_registers_map* usart
);

void
usart_set_wakeup_method(
  volatile struct usart_registers_map* usart,
  enum usart_wakeup_method method
);

void
usart_set_word_length(
  volatile struct usart_registers_map* usart,
  enum usart_word_length length
);

void
usart_enable(
  volatile struct usart_registers_map* usart
);

void
usart_disable(
  volatile struct usart_registers_map* usart
);

#if defined(STM32_USART_OVERSAMPLING)
void
usart_set_oversampling_mode(
  volatile struct usart_registers_map* usart,
  enum usart_oversampling_mode mode
);
#endif

void
usart_set_node_address(
  volatile struct usart_registers_map* usart,
  u32 address
);

void
usart_set_line_break_detection_length(
  volatile struct usart_registers_map* usart,
  enum usart_line_break_length length
);

void
usart_last_bit_clock_pulse_output_enable(
  volatile struct usart_registers_map* usart
);

void
usart_last_bit_clock_pulse_output_disable(
  volatile struct usart_registers_map* usart
);

void
usart_set_clock_phase(
  volatile struct usart_registers_map* usart,
  enum usart_clock_phase phase
);

void
usart_set_clock_polarity(
  volatile struct usart_registers_map* usart,
  enum usart_clock_polarity polarity
);

void
usart_clock_enable(
  volatile struct usart_registers_map* usart
);

void
usart_clock_disable(
  volatile struct usart_registers_map* usart
);

void
usart_set_stop_bits(
  volatile struct usart_registers_map* usart,
  enum usart_stop_bits bits
);

void
usart_line_mode_enable(
  volatile struct usart_registers_map* usart
);

void
usart_line_mode_disable(
  volatile struct usart_registers_map* usart
);

void
usart_irda_mode_enable(
  volatile struct usart_registers_map* usart
);

void
usart_irda_mode_disable(
  volatile struct usart_registers_map* usart
);

void
usart_irda_low_power_enable(
  volatile struct usart_registers_map* usart 
);

void
usart_irda_low_power_disable(
  volatile struct usart_registers_map* usart 
);

void
usart_half_duplex_enable(
  volatile struct usart_registers_map* usart
);

void
usart_half_duplex_disable(
  volatile struct usart_registers_map* usart
);

void
usart_smartcard_nack_enable(
  volatile struct usart_registers_map* usart
);

void
usart_smartcard_nack_disable(
  volatile struct usart_registers_map* usart
);

void
usart_smardcard_mode_enable(
  volatile struct usart_registers_map* usart
);

void
usart_smardcard_mode_disable(
  volatile struct usart_registers_map* usart
);

void
usart_dma_reception_enable(
  volatile struct usart_registers_map* usart
);

void
usart_dma_reception_disable(
  volatile struct usart_registers_map* usart
);

void
usart_dma_transmission_enable(
  volatile struct usart_registers_map* usart
);

void
usart_dma_transmission_disable(
  volatile struct usart_registers_map* usart
);

void
usart_rts_enable(
  volatile struct usart_registers_map* usart
);

void
usart_rts_disable(
  volatile struct usart_registers_map* usart
);

void
usart_cts_enable(
  volatile struct usart_registers_map* usart
);

void
usart_cts_disable(
  volatile struct usart_registers_map* usart
);

#if defined(STM32_USART_ONEBIT_SAMPLING)
void
usart_set_onebit_sampling_method(
  volatile struct usart_registers_map* usart,
  enum usart_onebit_sampling_method method
);
#endif

void
usart_set_prescaler(
  volatile struct usart_registers_map* usart,
  u32 prescaler
);

void
usart_set_guard_time(
  volatile struct usart_registers_map* usart,
  u32 guard_time
);

END_DECLARATIONS

#endif
