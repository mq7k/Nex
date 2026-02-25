#ifndef STM32_DRIVER_CAN_H
#define STM32_DRIVER_CAN_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F4
 */

BEGIN_DECLARATIONS

struct can_mailbox_registers_map
{
  u32 TIR; // 0x180, 0x190, 0x1a0
  u32 TDTR; // 0x184, 0x194, 0x1a4
  u32 TDLR; // 0x188, 0x198, 0x1a8
  u32 TDHR; // 0x18c, 0x19c, 0x1ac
};

struct can_fifo_registers_map
{
  u32 RIR; // 0x1b0, 0x1c0
  u32 RDTR; // 0x1b4, 0x1c4
  u32 RDLR; // 0x1b8, 0x1c8
  u32 RDHR; // 0x1bc, 0x1cc
};

struct can_registers_map
{
  u32 MCR;
  u32 MSR;
  u32 TSR;
  u32 RF0R;
  u32 RF1R;
  u32 IER;
  u32 ESR;
  u32 BTR;
  // Padding
  u32 __padding0[88];
  struct can_mailbox_registers_map mailboxes[3];
  struct can_fifo_registers_map recv[2];
  u32 __padding1[12];
  u32 FMR;
  u32 FM1R;
  u32 FS1R;
  u32 FFA1R;
  u32 FA1R;
  u32 FR[56];
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum can_mcr : u32
{
  CAN_MCR_INRQ = (1 << 0),
  CAN_MCR_SLEEP = (1 << 1),
  CAN_MCR_TXFP = (1 << 2),
  CAN_MCR_RFLM = (1 << 3),
  CAN_MCR_NART = (1 << 4),
  CAN_MCR_AWUM = (1 << 5),
  CAN_MCR_ABOM = (1 << 6),
  CAN_MCR_TTCM = (1 << 7),
  CAN_MCR_RESET = (1 << 15),
  CAN_MCR_DBF = (1 << 16)
};

enum can_msr : u32
{
  CAN_MSR_INAK = (1 << 0),
  CAN_MSR_SLAK = (1 << 1),
  CAN_MSR_ERRI = (1 << 2),
  CAN_MSR_WKUI = (1 << 3),
  CAN_MSR_SLAKI = (1 << 4),
  CAN_MSR_TXM = (1 << 8),
  CAN_MSR_RXM = (1 << 9),
  CAN_MSR_SAMP = (1 << 10),
  CAN_MSR_RX = (1 << 11)
};

enum can_tsr : u32
{
  CAN_TSR_RQCP0 = (1 << 0),
  CAN_TSR_TXOK0 = (1 << 1),
  CAN_TSR_ALST0 = (1 << 2),
  CAN_TSR_TERR0 = (1 << 3),
  CAN_TSR_ABRQ0 = (1 << 7),
  CAN_TSR_RQCP1 = (1 << 8),
  CAN_TSR_TXOK1 = (1 << 9),
  CAN_TSR_ALST1 = (1 << 10),
  CAN_TSR_TERR1 = (1 << 11),
  CAN_TSR_ABRQ1 = (1 << 15),
  CAN_TSR_RQCP2 = (1 << 16),
  CAN_TSR_TXOK2 = (1 << 17),
  CAN_TSR_ALST2 = (1 << 18),
  CAN_TSR_TERR2 = (1 << 19),
  CAN_TSR_ABRQ2 = (1 << 23),
  CAN_TSR_TME0 = (1 << 26),
  CAN_TSR_TME1 = (1 << 27),
  CAN_TSR_TME2 = (1 << 28),
  CAN_TSR_LOW0 = (1 << 29),
  CAN_TSR_LOW1 = (1 << 30),
  CAN_TSR_LOW2 = (1u << 31)
};

#define CAN_TSR_CODE_SHIFT (24)
#define CAN_TSR_CODE_MASK (0x3)

enum can_rfr : u32
{
  CAN_RFR_FULL0 = (1 << 3),
  CAN_RFR_FOVR0 = (1 << 4),
  CAN_RFR_RFOM0 = (1 << 5)
};

#define CAN_RFR_FMP_SHIFT (0)
#define CAN_RFR_FMP_MASK (0x3)

enum can_ier : u32
{
  CAN_IER_TMEIE = (1 << 0),
  CAN_IER_FMPIE0 = (1 << 1),
  CAN_IER_FFIE0 = (1 << 2),
  CAN_IER_FOVIE0 = (1 << 3),
  CAN_IER_FMPIE1 = (1 << 4),
  CAN_IER_FFIE1 = (1 << 5),
  CAN_IER_FOVIE1 = (1 << 6),
  CAN_IER_EWGIE = (1 << 8),
  CAN_IER_EPVIE = (1 << 9),
  CAN_IER_BOFIE = (1 << 10),
  CAN_IER_LECIE = (1 << 11),
  CAN_IER_ERRIE = (1 << 15),
  CAN_IER_WKUIE = (1 << 16),
  CAN_IER_SLKIE = (1 << 17)
};

enum can_esr : u32
{
  CAN_ESR_EWGF = (1 << 0),
  CAN_ESR_EPVF = (1 << 1),
  CAN_ESR_BOFF = (1 << 2),
};

#define CAN_ESR_LEC_SHIFT (4)
#define CAN_ESR_LEC_MASK (0x7)

enum can_esr_lec : u32
{
  CAN_ESR_LEC_NOERROR = 0b000,
  CAN_ESR_LEC_STUFF_ERROR = 0b001,
  CAN_ESR_LEC_FORM_ERROR = 0b010,
  CAN_ESR_LEC_ACK_ERROR = 0b011,
  CAN_ESR_LEC_BIT_RECESSIVE_ERROR = 0b100,
  CAN_ESR_LEC_BIT_DOMINANT_ERROR = 0b101,
  CAN_ESR_LEC_CRC_ERROR = 0b110,
  CAN_ESR_LEC_SET_BY_SOFTWARE
};

#define CAN_ESR_TEC_SHIFT (16)
#define CAN_ESR_TEC_MASK (0xff)

#define CAN_ESR_REC_SHIFT (24)
#define CAN_ESR_REC_MASK (0xff)

enum can_btr : u32
{
  CAN_BTR_LBKM = (1 << 30),
  CAN_BTR_SILM = (1u << 31)
};

#define CAN_BTR_BRP_SHIFT (0)
#define CAN_BTR_BRP_MASK (0x3ff)

#define CAN_BTR_TS1_SHIFT (16)
#define CAN_BTR_TS1_MASK (0xf)

#define CAN_BTR_TS2_SHIFT (20)
#define CAN_BTR_TS2_MASK (0x7)

#define CAN_BTR_SJW_SHIFT (24)
#define CAN_BTR_SJW_MASK (0x3)

enum can_tir : u32
{
  CAN_TIR_TXRQ = (1 << 0),
  CAN_TIR_RTR = (1 << 1),
  CAN_TIR_IDE = (1 << 2)
};

#define CAN_TIR_EXID_SHIFT (3)
#define CAN_TIR_EXID_MASK (0x1fffffffu)

#define CAN_TIR_STID_SHIFT (21)
#define CAN_TIR_STID_MASK (0x3ffu)

enum can_tdtr : u32
{
  CAN_TDTR_TGT = (1 << 8)
};

#define CAN_TDTR_DLC_SHIFT (0)
#define CAN_TDTR_DLC_MASK (0xf)

#define CAN_TDTR_TIME_SHIFT (16)
#define CAN_TDTR_TIME_MASK (0xffffu)

#define CAN_TD_DATA_STRIDE (8)
#define CAN_TD_DATA_MASK (0xff)

enum can_rir : u32
{
  CAN_RIR_RTR = (1 << 1),
  CAN_RIR_IDE = (1 << 2)
};

#define CAN_RIR_EXID_SHIFT (3)
#define CAN_RIR_EXID_MASK (0x1fffffff)

#define CAN_RIR_STID_SHIFT (21)
#define CAN_RIR_STID_MASK (0x7ff)

#define CAN_RDTR_DLC_SHIFT (0)
#define CAN_RDTR_DLC_MASK (0xf)

#define CAN_RDTR_FMI_SHIFT (8)
#define CAN_RDTR_FMI_MASK (0xff)

#define CAN_RDTR_TIME_SHIFT (16)
#define CAN_RDTR_TIME_MASK (0xffff)

#define CAN_RD_DATA_STRIDE (8)
#define CAN_RD_DATA_MASK (0xff)

enum can_fmr : u32
{
  CAN_FMR_FINIT = (1 << 0)
};

#define CAN_FMR_CAN2SB_SHIFT (8)
#define CAN_FMR_CAN2SB_MASK (0x3f)

enum can_fm1r : u32
{
  CAN_FM1R_FBM0 = (1 << 0),
  CAN_FM1R_FBM1 = (1 << 1),
  CAN_FM1R_FBM2 = (1 << 2),
  CAN_FM1R_FBM3 = (1 << 3),
  CAN_FM1R_FBM4 = (1 << 4),
  CAN_FM1R_FBM5 = (1 << 5),
  CAN_FM1R_FBM6 = (1 << 6),
  CAN_FM1R_FBM7 = (1 << 7),
  CAN_FM1R_FBM8 = (1 << 8),
  CAN_FM1R_FBM9 = (1 << 9),
  CAN_FM1R_FBM10 = (1 << 10),
  CAN_FM1R_FBM11 = (1 << 11),
  CAN_FM1R_FBM12 = (1 << 12),
  CAN_FM1R_FBM13 = (1 << 13),
  CAN_FM1R_FBM14 = (1 << 14),
  CAN_FM1R_FBM15 = (1 << 15),
  CAN_FM1R_FBM16 = (1 << 16),
  CAN_FM1R_FBM17 = (1 << 17),
  CAN_FM1R_FBM18 = (1 << 18),
  CAN_FM1R_FBM19 = (1 << 19),
  CAN_FM1R_FBM20 = (1 << 20),
  CAN_FM1R_FBM21 = (1 << 21),
  CAN_FM1R_FBM22 = (1 << 22),
  CAN_FM1R_FBM23 = (1 << 23),
  CAN_FM1R_FBM24 = (1 << 24),
  CAN_FM1R_FBM25 = (1 << 25),
  CAN_FM1R_FBM26 = (1 << 26),
  CAN_FM1R_FBM27 = (1 << 27)
};

enum can_fs1r : u32
{
  CAN_FS1R_FSC0 = (1 << 0),
  CAN_FS1R_FSC1 = (1 << 1),
  CAN_FS1R_FSC2 = (1 << 2),
  CAN_FS1R_FSC3 = (1 << 3),
  CAN_FS1R_FSC4 = (1 << 4),
  CAN_FS1R_FSC5 = (1 << 5),
  CAN_FS1R_FSC6 = (1 << 6),
  CAN_FS1R_FSC7 = (1 << 7),
  CAN_FS1R_FSC8 = (1 << 8),
  CAN_FS1R_FSC9 = (1 << 9),
  CAN_FS1R_FSC10 = (1 << 10),
  CAN_FS1R_FSC11 = (1 << 11),
  CAN_FS1R_FSC12 = (1 << 12),
  CAN_FS1R_FSC13 = (1 << 13),
  CAN_FS1R_FSC14 = (1 << 14),
  CAN_FS1R_FSC15 = (1 << 15),
  CAN_FS1R_FSC16 = (1 << 16),
  CAN_FS1R_FSC17 = (1 << 17),
  CAN_FS1R_FSC18 = (1 << 18),
  CAN_FS1R_FSC19 = (1 << 19),
  CAN_FS1R_FSC20 = (1 << 20),
  CAN_FS1R_FSC21 = (1 << 21),
  CAN_FS1R_FSC22 = (1 << 22),
  CAN_FS1R_FSC23 = (1 << 23),
  CAN_FS1R_FSC24 = (1 << 24),
  CAN_FS1R_FSC25 = (1 << 25),
  CAN_FS1R_FSC26 = (1 << 26),
  CAN_FS1R_FSC27 = (1 << 27)
};

enum can_ffa1r : u32
{
  CAN_FFA1R_FFA0 = (1 << 0),
  CAN_FFA1R_FFA1 = (1 << 1),
  CAN_FFA1R_FFA2 = (1 << 2),
  CAN_FFA1R_FFA3 = (1 << 3),
  CAN_FFA1R_FFA4 = (1 << 4),
  CAN_FFA1R_FFA5 = (1 << 5),
  CAN_FFA1R_FFA6 = (1 << 6),
  CAN_FFA1R_FFA7 = (1 << 7),
  CAN_FFA1R_FFA8 = (1 << 8),
  CAN_FFA1R_FFA9 = (1 << 9),
  CAN_FFA1R_FFA10 = (1 << 10),
  CAN_FFA1R_FFA11 = (1 << 11),
  CAN_FFA1R_FFA12 = (1 << 12),
  CAN_FFA1R_FFA13 = (1 << 13),
  CAN_FFA1R_FFA14 = (1 << 14),
  CAN_FFA1R_FFA15 = (1 << 15),
  CAN_FFA1R_FFA16 = (1 << 16),
  CAN_FFA1R_FFA17 = (1 << 17),
  CAN_FFA1R_FFA18 = (1 << 18),
  CAN_FFA1R_FFA19 = (1 << 19),
  CAN_FFA1R_FFA20 = (1 << 20),
  CAN_FFA1R_FFA21 = (1 << 21),
  CAN_FFA1R_FFA22 = (1 << 22),
  CAN_FFA1R_FFA23 = (1 << 23),
  CAN_FFA1R_FFA24 = (1 << 24),
  CAN_FFA1R_FFA25 = (1 << 25),
  CAN_FFA1R_FFA26 = (1 << 26),
  CAN_FFA1R_FFA27 = (1 << 27)
};

enum can_fa1r : u32
{
  CAN_FA1R_FACT0 = (1 << 0),
  CAN_FA1R_FACT1 = (1 << 1),
  CAN_FA1R_FACT2 = (1 << 2),
  CAN_FA1R_FACT3 = (1 << 3),
  CAN_FA1R_FACT4 = (1 << 4),
  CAN_FA1R_FACT5 = (1 << 5),
  CAN_FA1R_FACT6 = (1 << 6),
  CAN_FA1R_FACT7 = (1 << 7),
  CAN_FA1R_FACT8 = (1 << 8),
  CAN_FA1R_FACT9 = (1 << 9),
  CAN_FA1R_FACT10 = (1 << 10),
  CAN_FA1R_FACT11 = (1 << 11),
  CAN_FA1R_FACT12 = (1 << 12),
  CAN_FA1R_FACT13 = (1 << 13),
  CAN_FA1R_FACT14 = (1 << 14),
  CAN_FA1R_FACT15 = (1 << 15),
  CAN_FA1R_FACT16 = (1 << 16),
  CAN_FA1R_FACT17 = (1 << 17),
  CAN_FA1R_FACT18 = (1 << 18),
  CAN_FA1R_FACT19 = (1 << 19),
  CAN_FA1R_FACT20 = (1 << 20),
  CAN_FA1R_FACT21 = (1 << 21),
  CAN_FA1R_FACT22 = (1 << 22),
  CAN_FA1R_FACT23 = (1 << 23),
  CAN_FA1R_FACT24 = (1 << 24),
  CAN_FA1R_FACT25 = (1 << 25),
  CAN_FA1R_FACT26 = (1 << 26),
  CAN_FA1R_FACT27 = (1 << 27)
};

enum can_fir : u32
{
  CAN_FIR_FB0 = (1 << 0),
  CAN_FIR_FB1 = (1 << 1),
  CAN_FIR_FB2 = (1 << 2),
  CAN_FIR_FB3 = (1 << 3),
  CAN_FIR_FB4 = (1 << 4),
  CAN_FIR_FB5 = (1 << 5),
  CAN_FIR_FB6 = (1 << 6),
  CAN_FIR_FB7 = (1 << 7),
  CAN_FIR_FB8 = (1 << 8),
  CAN_FIR_FB9 = (1 << 9),
  CAN_FIR_FB10 = (1 << 10),
  CAN_FIR_FB11 = (1 << 11),
  CAN_FIR_FB12 = (1 << 12),
  CAN_FIR_FB13 = (1 << 13),
  CAN_FIR_FB14 = (1 << 14),
  CAN_FIR_FB15 = (1 << 15),
  CAN_FIR_FB16 = (1 << 16),
  CAN_FIR_FB17 = (1 << 17),
  CAN_FIR_FB18 = (1 << 18),
  CAN_FIR_FB19 = (1 << 19),
  CAN_FIR_FB20 = (1 << 20),
  CAN_FIR_FB21 = (1 << 21),
  CAN_FIR_FB22 = (1 << 22),
  CAN_FIR_FB23 = (1 << 23),
  CAN_FIR_FB24 = (1 << 24),
  CAN_FIR_FB25 = (1 << 25),
  CAN_FIR_FB26 = (1 << 26),
  CAN_FIR_FB27 = (1 << 27),
  CAN_FIR_FB28 = (1 << 28),
  CAN_FIR_FB29 = (1 << 29),
  CAN_FIR_FB30 = (1 << 30),
  CAN_FIR_FB31 = (1u << 31)
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum can_hardware_mode
{
  CAN_HARDWARE_MODE_NORMAL,
  CAN_HARDWARE_MODE_INIT
};

enum can_tx_fifo_priority
{
  CAN_TX_FIFO_PRIORTY_MESSAGE_IDENTIFIER,
  CAN_TX_FIFO_PRIORTY_REQUEST_ORDER
};

enum can_rx_fifo_locked_mode
{
  CAN_RX_FIFO_LOCKED_MODE_OVERRIDE,
  CAN_RX_FIFO_LOCKED_MODE_DISCARD
};

enum can_automatic_transmission_policy
{
  CAN_AUTOMATIC_TRANSMISSION_POLICY_REPEATED,
  CAN_AUTOMATIC_TRANSMISSION_POLICY_ONCE
};

enum can_automatic_wakeup_mode
{
  CAN_AUTOMATIC_WAKEUP_MODE_SOFTWARE,
  CAN_AUTOMATIC_WAKEUP_MODE_HARDWARE
};

enum can_bus_off_management
{
  CAN_BUS_OFF_MANAGEMENT_SOFTWARE,
  CAN_BUS_OFF_MANAGEMENT_HARDWARE
};

enum can_debug_freeze
{
  CAN_DEBUG_FREEZE_UNFROZEN,
  CAN_DEBUG_FREEZE_FROZEN
};

enum can_flag
{
  CAN_FLAG_INIT_ACK,
  CAN_FLAG_SLEEP_ACK,
  CAN_FLAG_ERROR_INTERRUPT,
  CAN_FLAG_WAKEUP_INTERRUPT,
  CAN_FLAG_SLEEP_ACK_INTERRUPT,
  CAN_FLAG_TX_MODE,
  CAN_FLAG_RX_MODE,
  CAN_FLAG_LAST_SAMPLE_POINT,
  CAN_FLAG_RX_SIGNAL
};

enum can_mailbox_flag
{
  CAN_MAILBOX_FLAG_REQUEST_COMPLETED,
  CAN_MAILBOX_FLAG_TRANSMISSION_OK,
  CAN_MAILBOX_FLAG_ARBITRACTION_LOST,
  CAN_MAILBOX_FLAG_TRANSMISSION_ERROR,
  CAN_MAILBOX_FLAG_ABORT_REQUEST,
  CAN_MAILBOX_FLAG_TRANSMIT_EMPTY,
  CAN_MAILBOX_FLAG_LOWEST_PRIORITY
};

enum can_fifo
{
  CAN_FIFO0,
  CAN_FIFO1
};

enum can_fifo_flag
{
  CAN_FIFO_FLAG_FULL,
  CAN_FIFO_FLAG_OVERRUN
};

enum can_interrupt
{
  CAN_INTERRUPT_TX_MAILBOX_EMPTY,
  CAN_INTERRUPT_FIFO0_MESSAGE_PENDING,
  CAN_INTERRUPT_FIFO0_FULL,
  CAN_INTERRUPT_FIFO0_OVERRUN,
  CAN_INTERRUPT_FIFO1_MESSAGE_PENDING,
  CAN_INTERRUPT_FIFO1_FULL,
  CAN_INTERRUPT_FIFO1_OVERRUN,
  CAN_INTERRUPT_ERROR_WARNING,
  CAN_INTERRUPT_ERROR_PASSIVE,
  CAN_INTERRUPT_BUS_OFF,
  CAN_INTERRUPT_LAST_ERROR_CODE,
  CAN_INTERRUPT_ERROR,
  CAN_INTERRUPT_WAKEUP,
  CAN_INTERRUPT_SLEEP
};

enum can_error_flag
{
  CAN_ERROR_FLAG_ERROR_WARNING,
  CAN_ERROR_FLAG_ERROR_PASSIVE,
  CAN_ERROR_FLAG_BUS_OFF
};

enum can_error_code
{
  CAN_ERROR_CODE_NO_ERROR,
  CAN_ERROR_CODE_STUFF,
  CAN_ERROR_CODE_FORM,
  CAN_ERROR_CODE_ACK,
  CAN_ERROR_CODE_BIT_RECESSIVE,
  CAN_ERROR_CODE_BIT_DOMINANT,
  CAN_ERROR_CODE_CRC,
  CAN_ERROR_CODE_SET_BY_SOFTWARE
};

enum can_mailbox
{
  CAN_MAILBOX0,
  CAN_MAILBOX1,
  CAN_MAILBOX2
};

enum can_remote_transmission_request
{
  CAN_REMOTE_TRANSMISSION_REQUEST_DATA,
  CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE
};

enum can_identifier_type
{
  CAN_IDENTIFIER_TYPE_STANDARD,
  CAN_IDENTIFIER_TYPE_EXTENDED
};

enum can_recv_fifo_flag
{
  CAN_RECV_FIFO_FLAG_REMOTE_FRAME,
  CAN_RECV_FIFO_FLAG_EXTENDED_IDENTIFIER
};

enum can_filter_banks_mode
{
  CAN_FILTER_BANKS_MODE_ACTIVE,
  CAN_FILTER_BANKS_MODE_INIT
};

enum can_filter_mode
{
  CAN_FILTER_MODE_IDENTIFIER_MASK,
  CAN_FILTER_MODE_IDENTIFIER_LIST
};

enum can_filter_scale
{
  CAN_FILTER_SCALE_DUAL_16BITS,
  CAN_FILTER_SCALE_SINGLE_32BITS
};

enum can_fifo_filter_assignment
{
  CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0,
  CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1
};

#if defined(STM32_CAN1)
extern volatile struct can_registers_map* CAN1;
#endif

#if defined(STM32_CAN2)
extern volatile struct can_registers_map* CAN1;
#endif

#if defined(STM32_CAN3)
extern volatile struct can_registers_map* CAN3;
#endif

void
can_set_hardware_mode(
  volatile struct can_registers_map* can,
  enum can_hardware_mode mode
);

void
can_sleep_mode_enable(
  volatile struct can_registers_map* can
);

void
can_sleep_mode_disable(
  volatile struct can_registers_map* can
);

void
can_set_tx_fifo_priority(
  volatile struct can_registers_map* can,
  enum can_tx_fifo_priority priority
);

void
can_set_rx_fifo_locked_mode(
  volatile struct can_registers_map* can,
  enum can_rx_fifo_locked_mode mode
);

void
can_set_automatic_transmission_policy(
  volatile struct can_registers_map* can,
  enum can_automatic_transmission_policy policy
);

void
can_set_automatic_wakeup_mode(
  volatile struct can_registers_map* can,
  enum can_automatic_wakeup_mode mode
);

void
can_set_automatic_bus_off(
  volatile struct can_registers_map* can,
  enum can_bus_off_management management
);

void
can_time_triggered_communication_enable(
  volatile struct can_registers_map* can
);

void
can_time_triggered_communication_disable(
  volatile struct can_registers_map* can
);

void
can_software_reset(
  volatile struct can_registers_map* can
);

void
can_set_debug_freeze(
  volatile struct can_registers_map* can,
  enum can_debug_freeze freeze
);

u32
can_is_flag_set(
  volatile struct can_registers_map* can,
  enum can_flag flag
);

void
can_flag_clear(
  volatile struct can_registers_map* can,
  enum can_flag flag
);

u32
can_is_mailbox_flag_set(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_mailbox_flag flag
);

void
can_mailbox_flag_clear(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_mailbox_flag flag
);

u32
can_get_mailbox_code(
  volatile struct can_registers_map* can
);

u32
can_get_fifo_pending_messages_count(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

u32
can_is_fifo_flag_set(
  volatile struct can_registers_map* can,
  enum can_fifo fifo,
  enum can_fifo_flag flag
);

void
can_fifo_flag_clear(
  volatile struct can_registers_map* can,
  enum can_fifo fifo,
  enum can_fifo_flag flag
);

void
can_fifo_release(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

void
can_interrupt_enable(
  volatile struct can_registers_map* can,
  enum can_interrupt interrupt
);

void
can_interrupt_disable(
  volatile struct can_registers_map* can,
  enum can_interrupt interrupt
);

u32
can_is_error_flag_set(
  volatile struct can_registers_map* can,
  enum can_error_flag flag
);

u32
can_get_last_error_code(
  volatile struct can_registers_map* can
);

void
can_last_error_code_reset(
  volatile struct can_registers_map* can
);

u32
can_get_transmit_error_counter(
  volatile struct can_registers_map* can
);

u32
can_get_receive_error_counter(
  volatile struct can_registers_map* can
);

void
can_set_baudrate(
  volatile struct can_registers_map* can,
  u32 baudrate
);

void
can_set_time_segment1(
  volatile struct can_registers_map* can,
  u32 time_segment
);

void
can_set_time_segment2(
  volatile struct can_registers_map* can,
  u32 time_segment
);

void
can_set_resync_jump_width(
  volatile struct can_registers_map* can,
  u32 jump_width
);

void
can_loopback_mode_enable(
  volatile struct can_registers_map* can
);

void
can_loopback_mode_disable(
  volatile struct can_registers_map* can
);

void
can_silent_mode_enable(
  volatile struct can_registers_map* can
);

void
can_silent_mode_disable(
  volatile struct can_registers_map* can
);

void
can_mailbox_transmit_request(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox
);

void
can_tx_fifo_transmit(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_remote_transmission_request request
);

void
can_set_tx_fifo_identifier_type(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_identifier_type type
);

void
can_set_tx_fifo_identifier_type(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_identifier_type type
);

void
can_set_tx_fifo_identifier(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  enum can_identifier_type type,
  u32 length
);

void
can_set_data_length(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 length
);

void
can_transmit_global_time_enable(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox
);

void
can_transmit_global_time_disable(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox
);

void
can_set_message_timestamp(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 timestamp
);

void
can_set_message_data_low(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 data
);

void
can_set_message_data_high(
  volatile struct can_registers_map* can,
  enum can_mailbox mailbox,
  u32 data
);

u32
can_get_rx_fifo_transmit(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

u32
can_get_rx_fifo_identifier_type(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

u32
can_get_rx_fifo_identifier(
  volatile struct can_registers_map* can,
  enum can_fifo fifo,
  enum can_identifier_type type
);

u32
can_get_rx_fifo_data_length(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

u32
can_get_rx_fifo_filter_match_index(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

u32
can_get_rx_fifo_message_timestamp(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

u32
can_get_rx_fifo_message_data_low(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

u32
can_get_rx_fifo_message_data_high(
  volatile struct can_registers_map* can,
  enum can_fifo fifo
);

void
can_set_filter_banks_mode(
  volatile struct can_registers_map* can,
  enum can_filter_banks_mode mode
);

void
can_set_start_bank(
  volatile struct can_registers_map* can,
  u32 bank
);

void
can_set_filter_mode(
  volatile struct can_registers_map* can,
  u32 filter,
  enum can_filter_mode mode
);

void
can_set_filter_scale(
  volatile struct can_registers_map* can,
  u32 filter,
  enum can_filter_scale scale
);

void
can_set_fifo_filter_assignment(
  volatile struct can_registers_map* can,
  u32 filter,
  enum can_fifo_filter_assignment assignment
);

void
can_filter_enable(
  volatile struct can_registers_map* can,
  u32 filter
);

void
can_filter_disable(
  volatile struct can_registers_map* can,
  u32 filter
);

void
can_set_filter_bank_filter_bits(
  volatile struct can_registers_map* can,
  u32 idx,
  u32 reg,
  u32 filter
);

END_DECLARATIONS

#endif
