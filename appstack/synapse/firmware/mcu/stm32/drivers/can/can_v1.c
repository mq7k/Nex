#include "synapse/stm32/drivers/can/can_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"

typedef volatile struct can_registers_map can_periph;

#if defined(STM32_CAN1)
can_periph* CAN1 = (can_periph*) (CAN1_ADDR);
#endif

#if defined(STM32_CAN2)
can_periph* CAN2 = (can_periph*) (CAN2_ADDR);
#endif

#if defined(STM32_CAN3)
can_periph* CAN3 = (can_periph*) (CAN3_ADDR);
#endif

static volatile struct can_mailbox_registers_map*
get_can_mailbox(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox
)
{
  devmode_assert_lower_or_eq(mailbox, CAN_MAILBOX2);
  return &can->mailboxes[mailbox];
}

static volatile struct can_fifo_registers_map*
get_can_fifo(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  devmode_assert_lower_or_eq(fifo, CAN_FIFO1);
  return &can->recv[fifo];
}

void
can_set_hardware_mode(
  volatile struct can_registers_map* can,
  enum can_hardware_mode mode
)
{
  volatile u32* reg = &can->MCR;
  switch (mode)
  {
    case CAN_HARDWARE_MODE_NORMAL:
      *reg &= ~CAN_MCR_INRQ;
      break;

    case CAN_HARDWARE_MODE_INIT:
      *reg |= CAN_MCR_INRQ;
      break;

    default:
      devmode_error_invalid_enum(enum can_hardware_mode, mode);
      break;
  }
}

void
can_sleep_mode_enable(
  volatile struct can_registers_map* can
)
{
  can->MCR |= CAN_MCR_SLEEP;
}

void
can_sleep_mode_disable(
  volatile struct can_registers_map* can
)
{
  can->MCR &= ~CAN_MCR_SLEEP;
}

void
can_set_tx_fifo_priority(
  volatile struct can_registers_map* can,
  enum can_tx_fifo_priority priority
)
{
  volatile u32* reg = &can->MCR;
  switch (priority)
  {
    case CAN_TX_FIFO_PRIORTY_MESSAGE_IDENTIFIER:
      *reg &= ~CAN_MCR_TXFP;
      break;

    case CAN_TX_FIFO_PRIORTY_REQUEST_ORDER:
      *reg |= CAN_MCR_TXFP;
      break;

    default:
      devmode_error_invalid_enum(enum can_tx_fifo_priority, priority);
      break;
  }
}

void
can_set_rx_fifo_locked_mode(
  volatile struct can_registers_map* can,
  enum can_rx_fifo_locked_mode mode
)
{
  volatile u32* reg = &can->MCR;
  switch (mode)
  {
    case CAN_RX_FIFO_LOCKED_MODE_OVERRIDE:
      *reg &= ~CAN_MCR_RFLM;
      break;

    case CAN_RX_FIFO_LOCKED_MODE_DISCARD:
      *reg |= CAN_MCR_RFLM;
      break;

    default:
      devmode_error_invalid_enum(enum can_rx_fifo_locked_mode, mode);
      break;
  }
}

void
can_set_automatic_transmission_policy(
  volatile struct can_registers_map* can,
  enum can_automatic_transmission_policy policy
)
{
  volatile u32* reg = &can->MCR;
  switch (policy)
  {
    case CAN_AUTOMATIC_TRANSMISSION_POLICY_REPEATED:
      *reg &= ~CAN_MCR_NART;
      break;

    case CAN_AUTOMATIC_TRANSMISSION_POLICY_ONCE:
      *reg |= CAN_MCR_NART;
      break;

    default:
      devmode_error_invalid_enum(enum can_automatic_transmission_policy, policy);
      break;
  }
}

void
can_set_automatic_wakeup_mode(
  volatile struct can_registers_map* can,
  enum can_automatic_wakeup_mode mode
)
{
  volatile u32* reg = &can->MCR;
  switch (mode)
  {
    case CAN_AUTOMATIC_WAKEUP_MODE_SOFTWARE:
      *reg &= ~CAN_MCR_AWUM;
      break;

    case CAN_AUTOMATIC_WAKEUP_MODE_HARDWARE:
      *reg |= CAN_MCR_AWUM;
      break;

    default:
      devmode_error_invalid_enum(enum can_automatic_wakeup_mode, mode);
      break;
  }
}

void
can_set_automatic_bus_off(
  volatile struct can_registers_map* can,
  enum can_bus_off_management management
)
{
  volatile u32* reg = &can->MCR;
  switch (management)
  {
    case CAN_BUS_OFF_MANAGEMENT_SOFTWARE:
      *reg &= ~CAN_MCR_ABOM;
      break;

    case CAN_BUS_OFF_MANAGEMENT_HARDWARE:
      *reg |= CAN_MCR_ABOM;
      break;

    default:
      devmode_error_invalid_enum(enum can_bus_off_management, management);
      break;
  }
}

void
can_time_triggered_communication_enable(
  volatile struct can_registers_map* can
)
{
  can->MCR |= CAN_MCR_TTCM;
}

void
can_time_triggered_communication_disable(
  volatile struct can_registers_map* can
)
{
  can->MCR &= ~CAN_MCR_TTCM;
}

void
can_software_reset(
  volatile struct can_registers_map* can
)
{
  can->MCR |= CAN_MCR_RESET;
}

void
can_set_debug_freeze(
  volatile struct can_registers_map* can,
  enum can_debug_freeze freeze
)
{
  volatile u32* reg = &can->MCR;
  switch (freeze)
  {
    case CAN_DEBUG_FREEZE_UNFROZEN:
      *reg &= ~CAN_MCR_DBF;
      break;

    case CAN_DEBUG_FREEZE_FROZEN:
      *reg |= CAN_MCR_DBF;
      break;

    default:
      devmode_error_invalid_enum(enum can_debug_freeze, freeze);
      break;
  }
}

u32
can_is_flag_set(
  volatile struct can_registers_map* can,
  enum can_flag flag
)
{
  volatile u32* reg = &can->MSR;
  switch (flag)
  {
    case CAN_FLAG_INIT_ACK:
      return *reg & CAN_MSR_INAK;

    case CAN_FLAG_SLEEP_ACK:
      return *reg & CAN_MSR_SLAK;

    case CAN_FLAG_ERROR_INTERRUPT:
      return *reg & CAN_MSR_ERRI;

    case CAN_FLAG_WAKEUP_INTERRUPT:
      return *reg & CAN_MSR_WKUI;

    case CAN_FLAG_SLEEP_ACK_INTERRUPT:
      return *reg & CAN_MSR_SLAKI;

    case CAN_FLAG_TX_MODE:
      return *reg & CAN_MSR_TXM;

    case CAN_FLAG_RX_MODE:
      return *reg & CAN_MSR_RXM;

    case CAN_FLAG_LAST_SAMPLE_POINT:
      return *reg & CAN_MSR_SAMP;

    case CAN_FLAG_RX_SIGNAL:
      return *reg & CAN_MSR_RX;

    default:
      devmode_error_invalid_enum(enum can_flag, flag);
      return 0;
  }
}

void
can_flag_clear(
  volatile struct can_registers_map* can,
  enum can_flag flag
)
{
  volatile u32* reg = &can->MSR;
  switch (flag)
  {
    case CAN_FLAG_ERROR_INTERRUPT:
      *reg |= CAN_MSR_ERRI;
      break;

    case CAN_FLAG_WAKEUP_INTERRUPT:
      *reg |= CAN_MSR_WKUI;
      break;

    case CAN_FLAG_SLEEP_ACK_INTERRUPT:
      *reg |= CAN_MSR_SLAKI;
      break;

    default:
      devmode_error_invalid_enum(enum can_flag, flag);
      break;
  }
}

u32
can_is_mailbox_flag_set(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_mailbox_flag flag
)
{
  devmode_assert_lower_or_eq(mailbox, CAN_MAILBOX2);

  constexpr u32 stride = 8;
  volatile u32* reg = &can->TSR;

  switch (flag)
  {
    case CAN_MAILBOX_FLAG_REQUEST_COMPLETED:
      return *reg & (CAN_TSR_RQCP0 << (mailbox * stride));

    case CAN_MAILBOX_FLAG_TRANSMISSION_OK:
      return *reg & (CAN_TSR_TXOK0 << (mailbox * stride));

    case CAN_MAILBOX_FLAG_ARBITRACTION_LOST:
      return *reg & (CAN_TSR_ALST0 << (mailbox * stride));

    case CAN_MAILBOX_FLAG_TRANSMISSION_ERROR:
      return *reg & (CAN_TSR_TERR0 << (mailbox * stride));

    case CAN_MAILBOX_FLAG_ABORT_REQUEST:
      return *reg & (CAN_TSR_ABRQ0 << (mailbox * stride));

    case CAN_MAILBOX_FLAG_TRANSMIT_EMPTY:
      return *reg & (CAN_TSR_TME0 << mailbox);

    case CAN_MAILBOX_FLAG_LOWEST_PRIORITY:
      return *reg & (CAN_TSR_LOW0 << mailbox);

    default:
      devmode_error_invalid_enum(enum can_mailbox_flag, flag);
      return 0;
  }
}

void
can_mailbox_flag_clear(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_mailbox_flag flag
)
{
  devmode_assert_lower_or_eq(mailbox, CAN_MAILBOX2);

  constexpr u32 stride = 8;
  volatile u32* reg = &can->TSR;
  switch (flag)
  {
    case CAN_MAILBOX_FLAG_REQUEST_COMPLETED:
      *reg |= (CAN_TSR_RQCP0 << (mailbox * stride));
      break;

    case CAN_MAILBOX_FLAG_TRANSMISSION_OK:
      *reg |= (CAN_TSR_TXOK0 << (mailbox * stride));
      break;

    case CAN_MAILBOX_FLAG_ARBITRACTION_LOST:
      *reg |= (CAN_TSR_ALST0 << (mailbox * stride));
      break;

    case CAN_MAILBOX_FLAG_TRANSMISSION_ERROR:
      *reg |= (CAN_TSR_TERR0 << (mailbox * stride));
      break;

    default:
      devmode_error_invalid_enum(enum can_mailbox_flag, flag);
      break;
  }
}

u32
can_get_mailbox_code(
  volatile struct can_registers_map* can
)
{
  constexpr u32 shift = CAN_TSR_CODE_SHIFT;
  constexpr u32 mask = CAN_TSR_CODE_MASK;
  return (can->TSR >> shift) & mask;
}

u32
can_get_fifo_pending_messages_count(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  constexpr u32 shift = CAN_RFR_FMP_SHIFT;
  constexpr u32 mask = CAN_RFR_FMP_MASK;

  switch (fifo)
  {
    case CAN_FIFO0:
      return (can->RF0R >> shift) & mask;

    case CAN_FIFO1:
      return (can->RF1R >> shift) & mask;

    default:
      devmode_error_invalid_enum(enum can_fifo, fifo);
      return 0;
  }
}

u32
can_is_fifo_flag_set(
  volatile struct can_registers_map* can,
  enum can_fifo fifo,
  enum can_fifo_flag flag
)
{
  devmode_assert_lower_or_eq(fifo, CAN_FIFO1);

  volatile u32* reg = fifo == CAN_FIFO0 ? &can->RF0R : &can->RF1R;
  switch (flag)
  {
    case CAN_FIFO_FLAG_FULL:
      return *reg & CAN_RFR_FULL0;

    case CAN_FIFO_FLAG_OVERRUN:
      return *reg & CAN_RFR_FOVR0;

    default:
      devmode_error_invalid_enum(enum can_fifo_flag, flag);
      return 0;
  }
}

void
can_fifo_flag_clear(
  volatile struct can_registers_map* can,
  enum can_fifo fifo,
  enum can_fifo_flag flag
)
{
  devmode_assert_lower_or_eq(fifo, CAN_FIFO1);

  volatile u32* reg = fifo == CAN_FIFO0 ? &can->RF0R : &can->RF1R;
  switch (flag)
  {
    case CAN_FIFO_FLAG_FULL:
      *reg |= CAN_RFR_FULL0;
      break;

    case CAN_FIFO_FLAG_OVERRUN:
      *reg |= CAN_RFR_FOVR0;
      break;

    default:
      devmode_error_invalid_enum(enum can_fifo_flag, flag);
      break;
  }
}

void
can_fifo_release(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  devmode_assert_lower_or_eq(fifo, CAN_FIFO1);

  switch (fifo)
  {
    case CAN_FIFO0:
      can->RF0R |= CAN_RFR_RFOM0;
      break;

    case CAN_FIFO1:
      can->RF1R |= CAN_RFR_RFOM0;
      break;

    default:
      devmode_error_invalid_enum(enum can_fifo, fifo);
      break;
  }
}

void
can_interrupt_enable(
  volatile struct can_registers_map* can,
  enum can_interrupt interrupt
)
{
  volatile u32* reg = &can->IER;
  switch (interrupt)
  {
    case CAN_INTERRUPT_TX_MAILBOX_EMPTY:
      *reg |= CAN_IER_TMEIE;
      break;

    case CAN_INTERRUPT_FIFO0_MESSAGE_PENDING:
      *reg |= CAN_IER_FMPIE0;
      break;

    case CAN_INTERRUPT_FIFO0_FULL:
      *reg |= CAN_IER_FFIE0;
      break;

    case CAN_INTERRUPT_FIFO0_OVERRUN:
      *reg |= CAN_IER_FOVIE0;
      break;

    case CAN_INTERRUPT_FIFO1_MESSAGE_PENDING:
      *reg |= CAN_IER_FMPIE1;
      break;

    case CAN_INTERRUPT_FIFO1_FULL:
      *reg |= CAN_IER_FFIE1;
      break;

    case CAN_INTERRUPT_FIFO1_OVERRUN:
      *reg |= CAN_IER_FOVIE1;
      break;

    case CAN_INTERRUPT_ERROR_WARNING:
      *reg |= CAN_IER_EWGIE;
      break;

    case CAN_INTERRUPT_ERROR_PASSIVE:
      *reg |= CAN_IER_EPVIE;
      break;

    case CAN_INTERRUPT_BUS_OFF:
      *reg |= CAN_IER_BOFIE;
      break;

    case CAN_INTERRUPT_LAST_ERROR_CODE:
      *reg |= CAN_IER_LECIE;
      break;

    case CAN_INTERRUPT_ERROR:
      *reg |= CAN_IER_ERRIE;
      break;

    case CAN_INTERRUPT_WAKEUP:
      *reg |= CAN_IER_WKUIE;
      break;

    case CAN_INTERRUPT_SLEEP:
      *reg |= CAN_IER_SLKIE;
      break;

    default:
      devmode_error_invalid_enum(enum can_interrupt, interrupt);
      break;
  }
}

void
can_interrupt_disable(
  volatile struct can_registers_map* can,
  enum can_interrupt interrupt
)
{
  volatile u32* reg = &can->IER;
  switch (interrupt)
  {
    case CAN_INTERRUPT_TX_MAILBOX_EMPTY:
      *reg &= ~CAN_IER_TMEIE;
      break;

    case CAN_INTERRUPT_FIFO0_MESSAGE_PENDING:
      *reg &= ~CAN_IER_FMPIE0;
      break;

    case CAN_INTERRUPT_FIFO0_FULL:
      *reg &= ~CAN_IER_FFIE0;
      break;

    case CAN_INTERRUPT_FIFO0_OVERRUN:
      *reg &= ~CAN_IER_FOVIE0;
      break;

    case CAN_INTERRUPT_FIFO1_MESSAGE_PENDING:
      *reg &= ~CAN_IER_FMPIE1;
      break;

    case CAN_INTERRUPT_FIFO1_FULL:
      *reg &= ~CAN_IER_FFIE1;
      break;

    case CAN_INTERRUPT_FIFO1_OVERRUN:
      *reg &= ~CAN_IER_FOVIE1;
      break;

    case CAN_INTERRUPT_ERROR_WARNING:
      *reg &= ~CAN_IER_EWGIE;
      break;

    case CAN_INTERRUPT_ERROR_PASSIVE:
      *reg &= ~CAN_IER_EPVIE;
      break;

    case CAN_INTERRUPT_BUS_OFF:
      *reg &= ~CAN_IER_BOFIE;
      break;

    case CAN_INTERRUPT_LAST_ERROR_CODE:
      *reg &= ~CAN_IER_LECIE;
      break;

    case CAN_INTERRUPT_ERROR:
      *reg &= ~CAN_IER_ERRIE;
      break;

    case CAN_INTERRUPT_WAKEUP:
      *reg &= ~CAN_IER_WKUIE;
      break;

    case CAN_INTERRUPT_SLEEP:
      *reg &= ~CAN_IER_SLKIE;
      break;

    default:
      devmode_error_invalid_enum(enum can_interrupt, interrupt);
      break;
  }
}

u32
can_is_error_flag_set(
  volatile struct can_registers_map* can,
  enum can_error_flag flag
)
{
  volatile u32* reg = &can->ESR;
  switch (flag)
  {
    case CAN_ERROR_FLAG_ERROR_WARNING:
      return *reg & CAN_ESR_EWGF;

    case CAN_ERROR_FLAG_ERROR_PASSIVE:
      return *reg & CAN_ESR_EPVF;
      
    case CAN_ERROR_FLAG_BUS_OFF:
      return *reg & CAN_ESR_BOFF;

    default:
      devmode_error_invalid_enum(enum can_error_flag, flag);
      return 0;
  }
}

u32
can_get_last_error_code(
  volatile struct can_registers_map* can
)
{
  constexpr u32 shift = CAN_ESR_LEC_SHIFT;
  constexpr u32 mask = CAN_ESR_LEC_MASK;
  return (can->ESR >> shift) & mask;
}

void
can_last_error_code_reset(
  volatile struct can_registers_map* can
)
{
  constexpr u32 shift = CAN_ESR_LEC_SHIFT;
  constexpr u32 mask = CAN_ESR_LEC_MASK << shift;
  volatile u32* reg = &can->ESR;
  syn_set_register_bits(reg, mask, CAN_ESR_LEC_SET_BY_SOFTWARE << shift);
}

u32
can_get_transmit_error_counter(
  volatile struct can_registers_map* can
)
{
  constexpr u32 shift = CAN_ESR_TEC_SHIFT;
  constexpr u32 mask = CAN_ESR_TEC_MASK;
  return (can->ESR >> shift) & mask;
}

u32
can_get_receive_error_counter(
  volatile struct can_registers_map* can
)
{
  constexpr u32 shift = CAN_ESR_REC_SHIFT;
  constexpr u32 mask = CAN_ESR_REC_MASK;
  return (can->ESR >> shift) & mask;
}

void
can_set_baudrate(
  volatile struct can_registers_map* can,
  u32 baudrate
)
{
  devmode_assert_lower_or_eq(baudrate, CAN_BTR_BRP_MASK);

  constexpr u32 shift = CAN_BTR_BRP_SHIFT;
  constexpr u32 mask = CAN_BTR_BRP_MASK << shift;
  volatile u32* reg = &can->BTR;
  syn_set_register_bits(reg, mask, baudrate << shift);
}

void
can_set_time_segment1(
  volatile struct can_registers_map* can,
  u32 time_segment
)
{
  devmode_assert_lower_or_eq(time_segment, CAN_BTR_TS1_MASK);

  constexpr u32 shift = CAN_BTR_TS1_SHIFT;
  constexpr u32 mask = CAN_BTR_TS1_MASK << shift;
  volatile u32* reg = &can->BTR;
  syn_set_register_bits(reg, mask, time_segment << shift);
}

void
can_set_time_segment2(
  volatile struct can_registers_map* can,
  u32 time_segment
)
{
  devmode_assert_lower_or_eq(time_segment, CAN_BTR_TS2_MASK);

  constexpr u32 shift = CAN_BTR_TS2_SHIFT;
  constexpr u32 mask = CAN_BTR_TS2_MASK << shift;
  volatile u32* reg = &can->BTR;
  syn_set_register_bits(reg, mask, time_segment << shift);
}

void
can_set_resync_jump_width(
  volatile struct can_registers_map* can,
  u32 jump_width
)
{
  devmode_assert_lower_or_eq(jump_width, CAN_BTR_SJW_MASK);

  constexpr u32 shift = CAN_BTR_SJW_SHIFT;
  constexpr u32 mask = CAN_BTR_SJW_MASK << shift;
  volatile u32* reg = &can->BTR;
  syn_set_register_bits(reg, mask, jump_width << shift);
}

void
can_loopback_mode_enable(
  volatile struct can_registers_map* can
)
{
  can->BTR |= CAN_BTR_LBKM;
}

void
can_loopback_mode_disable(
  volatile struct can_registers_map* can
)
{
  can->BTR &= ~CAN_BTR_LBKM;
}

void
can_silent_mode_enable(
  volatile struct can_registers_map* can
)
{
  can->BTR |= CAN_BTR_SILM;
}

void
can_silent_mode_disable(
  volatile struct can_registers_map* can
)
{
  can->BTR &= ~CAN_BTR_SILM;
}

void
can_mailbox_transmit_request(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox
)
{
  switch (mailbox)
  {
    case CAN_MAILBOX0:
      can->mailboxes[0].TIR |= CAN_TIR_TXRQ;
      break;

    case CAN_MAILBOX1:
      can->mailboxes[1].TIR |= CAN_TIR_TXRQ;
      break;

    case CAN_MAILBOX2:
      can->mailboxes[2].TIR |= CAN_TIR_TXRQ;
      break;

    default:
      devmode_error_invalid_enum(enum can_mailbox, mailbox);
      break;
  }
}

void
can_tx_fifo_transmit(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_remote_transmission_request request
)
{
  devmode_assert_lower_or_eq(mailbox, CAN_MAILBOX2);

  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);

  switch (request)
  {
    case CAN_REMOTE_TRANSMISSION_REQUEST_DATA:
      map->TIR &= ~CAN_TIR_RTR;
      break;

    case CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE:
      map->TIR |= CAN_TIR_RTR;
      break;

    default:
      devmode_error_invalid_enum(enum can_remote_transmission_request, request);
      break;
  }
}

void
can_set_tx_fifo_identifier_type(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_identifier_type type
)
{
  devmode_assert_lower_or_eq(mailbox, CAN_MAILBOX2);

  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);

  switch (type)
  {
    case CAN_IDENTIFIER_TYPE_STANDARD:
      map->TIR &= ~CAN_TIR_IDE;
      break;

    case CAN_IDENTIFIER_TYPE_EXTENDED:
      map->TIR |= CAN_TIR_IDE;
      break;

    default:
      devmode_error_invalid_enum(enum can_identifier_type, type);
      break;
  }
}

void
can_set_tx_fifo_identifier(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_identifier_type type,
  u32 identifier
)
{
  can_set_tx_fifo_identifier_type(can, mailbox, type);

  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);
  u32 mask;
  u32 shift;

  switch (type)
  {
    case CAN_IDENTIFIER_TYPE_STANDARD:
      shift = CAN_TIR_STID_SHIFT;
      mask = CAN_TIR_STID_MASK << shift;
      devmode_assert_lower_or_eq(identifier, mask);
      syn_set_register_bits(&map->TIR, mask, identifier << shift);
      break;

    case CAN_IDENTIFIER_TYPE_EXTENDED:
      shift = CAN_TIR_EXID_SHIFT;
      mask = CAN_TIR_EXID_MASK << shift;
      devmode_assert_lower_or_eq(identifier, mask);
      syn_set_register_bits(&map->TIR, mask, identifier << shift);
      break;

    default:
      devmode_error_invalid_enum(enum can_identifier_type, type);
      break;
  }
}

void
can_set_data_length(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 length
)
{
  devmode_assert_lower_or_eq(length, CAN_TDTR_DLC_MASK);

  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);

  constexpr u32 shift = CAN_TDTR_DLC_SHIFT;
  constexpr u32 mask = CAN_TDTR_DLC_MASK << shift;
  volatile u32* reg = &map->TDTR;
  syn_set_register_bits(reg, mask, length << shift);
}

void
can_transmit_global_time_enable(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox
)
{
  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);
  map->TDTR |= CAN_TDTR_TGT;
}

void
can_transmit_global_time_disable(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox
)
{
  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);
  map->TDTR &= ~CAN_TDTR_TGT;
}

void
can_set_message_timestamp(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 timestamp
)
{
  devmode_assert_lower_or_eq(timestamp, CAN_TDTR_TIME_MASK);

  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);

  constexpr u32 shift = CAN_TDTR_TIME_SHIFT;
  constexpr u32 mask = CAN_TDTR_TIME_MASK << shift;
  volatile u32* reg = &map->TDTR;
  syn_set_register_bits(reg, mask, timestamp << shift);
}

void
can_set_message_data_low(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 data
)
{
  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);
  map->TDLR = data;
}

void
can_set_message_data_high(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 data
)
{
  volatile struct can_mailbox_registers_map* map;
  map = get_can_mailbox(can, mailbox);
  map->TDHR = data;
}

u32
can_get_rx_fifo_transmit(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);
  return map->RIR & CAN_RIR_RTR;
}

u32
can_get_rx_fifo_identifier_type(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);
  return map->RIR & CAN_RIR_IDE;
}

u32
can_get_rx_fifo_identifier(
  volatile struct can_registers_map* can,
  enum can_fifo fifo,
  enum can_identifier_type type
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);
  u32 shift;
  u32 mask;

  switch (type)
  {
    case CAN_IDENTIFIER_TYPE_STANDARD:
      shift = CAN_RIR_STID_SHIFT;
      mask = CAN_RIR_STID_MASK;
      return (map->RIR >> shift) & mask;

    case CAN_IDENTIFIER_TYPE_EXTENDED:
      shift = CAN_RIR_EXID_SHIFT;
      mask = CAN_RIR_EXID_MASK;
      return (map->RIR >> shift) & mask;

    default:
      devmode_error_invalid_enum(enum can_identifier_type, type);
      return 0;
  }
}

u32
can_get_rx_fifo_data_length(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);

  constexpr u32 shift = CAN_RDTR_DLC_SHIFT;
  constexpr u32 mask = CAN_RDTR_DLC_MASK;
  return (map->RDTR >> shift) & mask;
}

u32
can_get_rx_fifo_filter_match_index(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);

  constexpr u32 shift = CAN_RDTR_FMI_SHIFT;
  constexpr u32 mask = CAN_RDTR_FMI_MASK;
  return (map->RDTR >> shift) & mask;
}

u32
can_get_rx_fifo_message_timestamp(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);

  constexpr u32 shift = CAN_RDTR_TIME_SHIFT;
  constexpr u32 mask = CAN_RDTR_TIME_MASK;
  return (map->RDTR >> shift) & mask;
}

u32
can_get_rx_fifo_message_data_low(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);
  return map->RDLR;
}

u32
can_get_rx_fifo_message_data_high(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
)
{
  volatile struct can_fifo_registers_map* map;
  map = get_can_fifo(can, fifo);
  return map->RDHR;
}

void
can_set_filter_banks_mode(
  volatile struct can_registers_map* can,
  enum can_filter_banks_mode mode
)
{
  volatile u32* reg = &can->FMR;
  switch (mode)
  {
    case CAN_FILTER_BANKS_MODE_ACTIVE:
      *reg &= ~CAN_FMR_FINIT;
      break;

    case CAN_FILTER_BANKS_MODE_INIT:
      *reg |= CAN_FMR_FINIT;
      break;

    default:
      devmode_error_invalid_enum(enum can_filter_banks_mode, mode);
      break;
  }
}

void
can_set_start_bank(
  volatile struct can_registers_map* can,
  u32 bank
)
{
  devmode_assert_lower_or_eq(bank, CAN_FMR_CAN2SB_MASK);

  constexpr u32 shift = CAN_FMR_CAN2SB_SHIFT;
  constexpr u32 mask = CAN_FMR_CAN2SB_MASK << shift;
  volatile u32* reg = &can->FMR;
  syn_set_register_bits(reg, mask, bank << shift);
}

void
can_set_filter_mode(
  volatile struct can_registers_map* can,
  u32 filter,
  enum can_filter_mode mode
)
{
  devmode_assert_lower_or_eq(filter, 27);

  volatile u32* reg = &can->FM1R;
  switch (mode)
  {
    case CAN_FILTER_MODE_IDENTIFIER_MASK:
      *reg &= ~(1u << filter);
      break;

    case CAN_FILTER_MODE_IDENTIFIER_LIST:
      *reg |= (1u << filter);
      break;

    default:
      devmode_error_invalid_enum(enum can_filter_mode, mode);
      break;
  }
}

void
can_set_filter_scale(
  volatile struct can_registers_map* can,
  u32 filter,
  enum can_filter_scale scale
)
{
  devmode_assert_lower_or_eq(scale, 27);

  volatile u32* reg = &can->FS1R;
  switch (scale)
  {
    case CAN_FILTER_SCALE_DUAL_16BITS:
      *reg &= ~(1u << filter);
      break;

    case CAN_FILTER_SCALE_SINGLE_32BITS:
      *reg |= (1u << filter);
      break;

    default:
      devmode_error_invalid_enum(enum can_filter_scale, scale);
      break;
  }
}

void
can_set_fifo_filter_assignment(
  volatile struct can_registers_map* can,
  u32 filter,
  enum can_fifo_filter_assignment assignment
)
{
  devmode_assert_lower_or_eq(assignment, 27);

  volatile u32* reg = &can->FFA1R;
  switch (assignment)
  {
    case CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0:
      *reg &= ~(1u << filter);
      break;

    case CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1:
      *reg |= (1u << filter);
      break;

    default:
      devmode_error_invalid_enum(enum can_fifo_filter_assignment, assignment);
      break;
  }
}

void
can_filter_enable(
  volatile struct can_registers_map* can,
  u32 filter
)
{
  devmode_assert_lower_or_eq(filter, 27);
  can->FA1R |= (1u << filter);
}

void
can_filter_disable(
  volatile struct can_registers_map* can,
  u32 filter
)
{
  devmode_assert_lower_or_eq(filter, 27);
  can->FA1R &= ~(1u << filter);
}

void
can_set_filter_bank_filter_bits(
  volatile struct can_registers_map* can,
  u32 idx,
  u32 reg,
  u32 filter
)
{
  devmode_assert_lower_or_eq(idx, 27);
  devmode_assert_lower_or_eq(reg, 1);
  can->FR[idx * 2 + reg] = filter;
}
