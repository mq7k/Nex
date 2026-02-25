#include "synapse/stm32/drivers/usart/usart_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"
#include "libcom/format.h"

typedef volatile struct usart_registers_map usart_periph;

#if defined(STM32_USART1)
usart_periph* USART1 = (usart_periph*) (USART1_ADDR);
#endif

#if defined(STM32_USART2)
usart_periph* USART2 = (usart_periph*) (USART2_ADDR);
#endif

#if defined(STM32_USART3)
usart_periph* USART3 = (usart_periph*) (USART3_ADDR);
#endif

#if defined(STM32_UART4)
usart_periph* UART4 = (usart_periph*) (UART4_ADDR);
#endif

#if defined(STM32_UART5)
usart_periph* UART5 = (usart_periph*) (UART5_ADDR);
#endif

#if defined(STM32_USART6)
usart_periph* USART6 = (usart_periph*) (USART6_ADDR);
#endif

#if defined(STM32_USART7)
usart_periph* UART7 = (usart_periph*) (UART7_ADDR);
#endif

#if defined(STM32_USART8)
usart_periph* UART8 = (usart_periph*) (UART8_ADDR);
#endif

#if defined(STM32_UART9)
usart_periph* UART9 = (usart_periph*) (UART9_ADDR);
#endif

#if defined(STM32_UART10)
usart_periph* UART10 = (usart_periph*) (UART10_ADDR);
#endif

u32
usart_is_flag_set(
  volatile struct usart_registers_map* usart,
  enum usart_flag flag
)
{
  switch (flag)
  {
    case USART_FLAG_PARITY_ERROR:
      return usart->SR & USART_SR_PE;

    case USART_FLAG_FRAMING_ERROR:
      return usart->SR & USART_SR_FE;

    case USART_FLAG_NOISE_ERROR:
      return usart->SR & USART_SR_NF;

    case USART_FLAG_OVERRUN_ERROR:
      return usart->SR & USART_SR_ORE;

    case USART_FLAG_IDLE_LINE:
      return usart->SR & USART_SR_IDLE;

    case USART_FLAG_READ_REG_NOT_EMPTY:
      return usart->SR & USART_SR_RxNE;

    case USART_FLAG_TRANSMISSION_COMPLETE:
      return usart->SR & USART_SR_TC;

    case USART_FLAG_TRANSMIT_REG_EMPTY:
      return usart->SR & USART_SR_TxE;

    case USART_FLAG_LIN_BREAK:
      return usart->SR & USART_SR_LBD;

    case USART_FLAG_CTS:
      return usart->SR & USART_SR_CTS;

    default:
      return 0;
  }
}

void
usart_flag_clear(
  volatile struct usart_registers_map* usart,
  enum usart_flag flag
)
{
  switch (flag)
  {
    case USART_FLAG_PARITY_ERROR:
    case USART_FLAG_FRAMING_ERROR:
    case USART_FLAG_NOISE_ERROR:
    case USART_FLAG_OVERRUN_ERROR:
    case USART_FLAG_IDLE_LINE:
      (void) usart->SR;
      (void) usart->DR;
      break;

    case USART_FLAG_READ_REG_NOT_EMPTY:
      (void) usart->DR;
      break;

    case USART_FLAG_TRANSMISSION_COMPLETE:
      (void) usart->SR;
      usart->DR = usart->DR;
      break;

    case USART_FLAG_LIN_BREAK:
      usart->SR &= ~USART_SR_LBD;
      break;

    case USART_FLAG_CTS:
      usart->SR &= ~USART_SR_CTS;
      break;

    default:
      devmode_error_invalid_enum(enum usart_flag, flag);
      break;
  }
}

void
usart_flag_clear_multibuffer(
  volatile struct usart_registers_map* usart,
  enum usart_flag flag
)
{
  switch (flag)
  {
    case USART_FLAG_READ_REG_NOT_EMPTY:
      usart->SR &= ~USART_SR_RxNE;
      break;

    case USART_FLAG_TRANSMISSION_COMPLETE:
      usart->SR &= ~USART_SR_TC;
      break;

    default:
      devmode_error_invalid_enum(enum usart_flag, flag);
      break;
  }
}

u32
usart_data_read(
  volatile struct usart_registers_map* usart
)
{
  return usart->DR;
}

void
usart_send_byte(
  volatile struct usart_registers_map* usart,
  u32 data
)
{
  devmode_assert_lower_or_eq(data, USART_DR_MASK);

  #ifndef NEX_BUILD_TESTS
  while (!usart_is_flag_set(usart, USART_FLAG_TRANSMIT_REG_EMPTY));
  #endif

  (void) usart->SR;
  usart->DR = data;
}

void
usart_send_str(
  volatile struct usart_registers_map* usart,
  const char* str
)
{
  while (*str)
  {
    usart_send_byte(usart, (u32) *str++);
  }
}

void
usart_send_strln(
  volatile struct usart_registers_map* usart,
  const char* str
)
{
  usart_send_str(usart, str);
  usart_send_str(usart, "\r\n");
}

static void
_stream_adapter(
  volatile void* usart,
  char c
)
{
  usart_send_byte(usart, (u32) c);
}

void
usart_send_strf(
  volatile struct usart_registers_map* usart,
  const char* fmt,
  ...
)
{
  va_list args;
  va_start(args, fmt);
  usart_send_strfv(usart, fmt, args);
  va_end(args);
}

void
usart_send_strfln(
  volatile struct usart_registers_map* usart,
  const char* fmt,
  ...
)
{
  va_list args;
  va_start(args, fmt);
  usart_send_strfv(usart, fmt, args);
  va_end(args);
  usart_send_str(usart, "\r\n");
}

void
usart_send_strfv(
  volatile struct usart_registers_map* usart,
  const char* fmt,
  va_list args
)
{
  nex_format_va_args_stream(_stream_adapter, usart, fmt, args);
}

void
usart_set_baudrate(
  volatile struct usart_registers_map* usart,
  u32 clock,
  u32 baudrate
)
{
  const u32 bittime = (clock + baudrate / 2) / baudrate; 
  usart_set_bittime(usart, bittime);
}

void
usart_set_bittime(
  volatile struct usart_registers_map* usart,
  u32 bittime
)
{
  devmode_assert_lower_or_eq(bittime, USART_BRR_MASK);
  usart->BRR = bittime;
}

void
usart_set_div_fraction(
  volatile struct usart_registers_map* usart,
  u32 fraction
)
{
  devmode_assert_lower_or_eq(fraction, USART_BRR_FRACTION_MASK);
  constexpr u32 shift = USART_BRR_FRACTION_SHIFT;
  constexpr u32 mask = USART_BRR_FRACTION_MASK << shift;
  volatile u32* reg = &usart->BRR;
  syn_set_register_bits(reg, mask, fraction << shift);
}

void
usart_set_div_mantissa(
  volatile struct usart_registers_map* usart,
  u32 mantissa
)
{
  devmode_assert_lower_or_eq(mantissa, USART_BRR_MANTISSA_MASK);
  constexpr u32 shift = USART_BRR_MANTISSA_SHIFT;
  constexpr u32 mask = USART_BRR_MANTISSA_MASK << shift;
  volatile u32* reg = &usart->BRR;
  syn_set_register_bits(reg, mask, mantissa << shift);
}

void
usart_send_break(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 |= USART_CR1_SBK;
}

void
usart_set_receiver_mode(
  volatile struct usart_registers_map* usart,
  enum usart_receiver_mode mode
)
{
  volatile u32* reg = &usart->CR1;
  switch (mode)
  {
    case USART_RECEIVER_MODE_ACTIVE:
      *reg &= ~USART_CR1_RWU;
      break;

    case USART_RECEIVER_MODE_MUTE:
      *reg |= USART_CR1_RWU;
      break;

    default:
      devmode_error_invalid_enum(enum usart_receiver_mode, mode);
      break;
  }
}

void
usart_receiver_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 |= USART_CR1_RE;
}

void
usart_receiver_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 &= ~USART_CR1_RE;
}

void
usart_transmitter_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 |= USART_CR1_TE;
}

void
usart_transmitter_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 &= ~USART_CR1_TE;
}

void
usart_interrupt_enable(
  volatile struct usart_registers_map* usart,
  enum usart_interrupt interrupt
)
{
  switch (interrupt)
  {
    case USART_INTERRUPT_IDLE:
      usart->CR1 |= USART_CR1_IDLEIE;
      break;

    case USART_INTERRUPT_READ_REG_NOT_EMPTY:
      usart->CR1 |= USART_CR1_RXNEIE;
      break;

    case USART_INTERRUPT_TRANSMITTION_COMPLETE:
      usart->CR1 |= USART_CR1_TCIE;
      break;

    case USART_INTERRUPT_WRITE_REG_EMPTY:
      usart->CR1 |= USART_CR1_TXEIE;
      break;

    case USART_INTERRUPT_PARITY_ERROR:
      usart->CR1 |= USART_CR1_PEIE;
      break;

    case USART_INTERRUPT_LINE_BREAK_DETECTION:
      usart->CR2 |= USART_CR2_LBDIE;
      break;

    case USART_INTERRUPT_ERROR:
      usart->CR3 |= USART_CR3_EIE;
      break;

    case USART_INTERRUPT_CTS:
      usart->CR3 |= USART_CR3_CTSIE;
      break;

    default:
      devmode_error_invalid_enum(enum usart_interrupt, interrupt);
      break;
  }
}

void
usart_interrupt_disable(
  volatile struct usart_registers_map* usart,
  enum usart_interrupt interrupt
)
{
  switch (interrupt)
  {
    case USART_INTERRUPT_IDLE:
      usart->CR1 &= ~USART_CR1_IDLEIE;
      break;

    case USART_INTERRUPT_READ_REG_NOT_EMPTY:
      usart->CR1 &= ~USART_CR1_RXNEIE;
      break;

    case USART_INTERRUPT_TRANSMITTION_COMPLETE:
      usart->CR1 &= ~USART_CR1_TCIE;
      break;

    case USART_INTERRUPT_WRITE_REG_EMPTY:
      usart->CR1 &= ~USART_CR1_TXEIE;
      break;

    case USART_INTERRUPT_PARITY_ERROR:
      usart->CR1 &= ~USART_CR1_PEIE;
      break;

    case USART_INTERRUPT_LINE_BREAK_DETECTION:
      usart->CR2 &= ~USART_CR2_LBDIE;
      break;

    case USART_INTERRUPT_ERROR:
      usart->CR3 &= ~USART_CR3_EIE;
      break;

    case USART_INTERRUPT_CTS:
      usart->CR3 &= ~USART_CR3_CTSIE;
      break;

    default:
      devmode_error_invalid_enum(enum usart_interrupt, interrupt);
      break;
  }
}

void
usart_set_parity(
  volatile struct usart_registers_map* usart,
  enum usart_parity parity
)
{
  volatile u32* reg = &usart->CR1;
  switch (parity)
  {
    case USART_PARITY_EVEN:
      *reg &= ~USART_CR1_PS;
      break;

    case USART_PARITY_ODD:
      *reg |= USART_CR1_PS;
      break;

    default:
      devmode_error_invalid_enum(enum usart_parity, parity);
      break;
  }
}

void
usart_parity_control_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 |= USART_CR1_PCE;
}

void
usart_parity_control_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 &= ~USART_CR1_PCE;
}

void
usart_set_wakeup_method(
  volatile struct usart_registers_map* usart,
  enum usart_wakeup_method method
)
{
  volatile u32* reg = &usart->CR1;
  switch (method)
  {
    case USART_WAKEUP_METHOD_IDLE_LINE:
      *reg &= ~USART_CR1_WAKE;
      break;

    case USART_WAKEUP_METHOD_ADDRESS_MARK:
      *reg |= USART_CR1_WAKE;
      break;

    default:
      devmode_error_invalid_enum(enum usart_wakeup_method, method);
      break;
  }
}

void
usart_set_word_length(
  volatile struct usart_registers_map* usart,
  enum usart_word_length length
)
{
  volatile u32* reg = &usart->CR1;
  switch (length)
  {
    case USART_WORD_LENGTH_8BITS:
      *reg &= ~USART_CR1_M;
      break;

    case USART_WORD_LENGTH_9BITS:
      *reg |= USART_CR1_M;
      break;

    default:
      devmode_error_invalid_enum(enum usart_word_length, length);
      break;
  }
}

void
usart_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 |= USART_CR1_UE;
}

void
usart_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR1 &= ~USART_CR1_UE;
}

#if defined(STM32_USART_OVERSAMPLING)
void
usart_set_oversampling_mode(
  volatile struct usart_registers_map* usart,
  enum usart_oversampling_mode mode
)
{
  volatile u32* reg = &usart->CR1;
  switch (mode)
  {
    case USART_OVERSAMPLING_MODE16:
      *reg &= ~USART_CR1_OVER8;
      break;

    case USART_OVERSAMPLING_MODE8:
      *reg |= USART_CR1_OVER8;
      break;

    default:
      devmode_error_invalid_enum(enum usart_set_oversampling_mode, mode);
      break;
  }
}
#endif

void
usart_set_node_address(
  volatile struct usart_registers_map* usart,
  u32 address
)
{
  devmode_assert_lower_or_eq(address, USART_CR2_ADD_MASK);
  constexpr u32 shift = USART_CR2_ADD_SHIFT;
  constexpr u32 mask = USART_CR2_ADD_MASK << shift;
  volatile u32* reg = &usart->CR2;
  syn_set_register_bits(reg, mask, address << shift);
}

void
usart_set_line_break_detection_length(
  volatile struct usart_registers_map* usart,
  enum usart_line_break_length length
)
{
  volatile u32* reg = &usart->CR2;
  switch (length)
  {
    case USART_LINE_BREAK_LENGTH_10BITS:
      *reg &= ~USART_CR2_LBDL;
      break;

    case USART_LINE_BREAK_LENGTH_11BITS:
      *reg |= USART_CR2_LBDL;
      break;

    default:
      devmode_error_invalid_enum(enum usart_line_break_length, length);
      break;
  }
}

void
usart_last_bit_clock_pulse_output_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR2 |= USART_CR2_LBCL;
}

void
usart_last_bit_clock_pulse_output_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR2 &= ~USART_CR2_LBCL;
}

void
usart_set_clock_phase(
  volatile struct usart_registers_map* usart,
  enum usart_clock_phase phase
)
{
  volatile u32* reg = &usart->CR2;
  switch (phase)
  {
    case USART_CLOCK_PHASE_FIRST:
      *reg &= ~USART_CR2_CPHA;
      break;

    case USART_CLOCK_PHASE_SECOND:
      *reg |= USART_CR2_CPHA;
      break;

    default:
      devmode_error_invalid_enum(enum usart_clock_phase, phase);
      break;
  }
}

void
usart_set_clock_polarity(
  volatile struct usart_registers_map* usart,
  enum usart_clock_polarity polarity
)
{
  volatile u32* reg = &usart->CR2;
  switch (polarity)
  {
    case USART_CLOCK_POLARITY_STEADY_LOW:
      *reg &= ~USART_CR2_CPOL;
      break;

    case USART_CLOCK_POLARITY_STEADY_HIGH:
      *reg |= USART_CR2_CPOL;
      break;

    default:
      devmode_error_invalid_enum(enum usart_clock_polarity, polarity);
      break;
  }
}

void
usart_clock_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR2 |= USART_CR2_CLKEN;
}

void
usart_clock_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR2 &= ~USART_CR2_CLKEN;
}

void
usart_set_stop_bits(
  volatile struct usart_registers_map* usart,
  enum usart_stop_bits bits
)
{
  constexpr u32 shift = USART_CR2_STOP_BITS_SHIFT;
  constexpr u32 mask = USART_CR2_STOP_BITS_MASK << shift;
  volatile u32* reg = &usart->CR2;

  switch (bits)
  {
    case USART_STOP_BITS_1BIT:
      *reg &= ~mask;
      break;

    case USART_STOP_BITS_0DOT5_BITS:
      syn_set_register_bits(reg, mask, USART_CR2_STOP_BITS_0DOT5BITS << shift);
      break;

    case USART_STOP_BITS_2BITS:
      syn_set_register_bits(reg, mask, USART_CR2_STOP_BITS_2BITS << shift);
      break;

    case USART_STOP_BITS_1DOT5_BITS:
      *reg |= (USART_CR2_STOP_BITS_1DOT5_BITS << shift);
      break;

    default:
      devmode_error_invalid_enum(enum usart_stop_bits, bits);
      break;
  }
}

void
usart_line_mode_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR2 |= USART_CR2_LINEN;
}

void
usart_line_mode_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR2 &= ~USART_CR2_LINEN;
}

void
usart_irda_mode_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_IREN;
}

void
usart_irda_mode_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_IREN;
}

void
usart_irda_low_power_enable(
  volatile struct usart_registers_map* usart 
)
{
  usart->CR3 |= USART_CR3_IRLP;
}

void
usart_irda_low_power_disable(
  volatile struct usart_registers_map* usart 
)
{
  usart->CR3 &= ~USART_CR3_IRLP;
}

void
usart_half_duplex_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_HDSEL;
}

void
usart_half_duplex_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_HDSEL;
}

void
usart_smartcard_nack_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_NACK;
}

void
usart_smartcard_nack_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_NACK;
}

void
usart_smardcard_mode_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_SCEN;
}

void
usart_smardcard_mode_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_SCEN;
}

void
usart_dma_reception_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_DMAR;
}

void
usart_dma_reception_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_DMAR;
}

void
usart_dma_transmission_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_DMAT;
}

void
usart_dma_transmission_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_DMAT;
}

void
usart_rts_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_RTSE;
}

void
usart_rts_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_RTSE;
}

void
usart_cts_enable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 |= USART_CR3_CTSE;
}

void
usart_cts_disable(
  volatile struct usart_registers_map* usart
)
{
  usart->CR3 &= ~USART_CR3_CTSE;
}

#if defined(STM32_USART_ONEBIT_SAMPLING)
void
usart_set_onebit_sampling_method(
  volatile struct usart_registers_map* usart,
  enum usart_onebit_sampling_method method
)
{
  volatile u32* reg = &usart->CR3;
  switch (method)
  {
    case USART_ONEBIT_SAMPLING_METHOD_THREE_SAMPLE:
      *reg &= ~USART_CR3_ONEBIT;
      break;

    case USART_ONEBIT_SAMPLING_METHOD_ONE_SAMPLE:
      *reg |= USART_CR3_ONEBIT;
      break;

    default:
      devmode_error_invalid_enum(enum usart_onebit_sampling_method, method);
      break;
  }
}
#endif

void
usart_set_prescaler(
  volatile struct usart_registers_map* usart,
  u32 prescaler
)
{
  devmode_assert_lower_or_eq(prescaler, USART_GTPR_PSC_MASK);
  constexpr u32 shift = USART_GTPR_PSC_SHIFT;
  constexpr u32 mask = USART_GTPR_PSC_MASK << shift;
  volatile u32* reg = &usart->GTPR;
  syn_set_register_bits(reg, mask, prescaler << shift);
}

void
usart_set_guard_time(
  volatile struct usart_registers_map* usart,
  u32 guard_time
)
{
  devmode_assert_lower_or_eq(guard_time, USART_GTPR_GT_MASK);
  constexpr u32 shift = USART_GTPR_GT_SHIFT;
  constexpr u32 mask = USART_GTPR_GT_MASK << shift;
  volatile u32* reg = &usart->GTPR;
  syn_set_register_bits(reg, mask, guard_time << shift);
}
