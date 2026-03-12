#ifndef STM32_DRIVER_USB_H
#define STM32_DRIVER_USB_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

/**
 * Supports:
 *  - STM32F1x
 */

BEGIN_DECLARATIONS

struct usb_endpoint_descriptor
{
  u16 ADDR_TX;
  u16 COUNT_TX;
  u16 ADDR_RX;
  u16 COUNT_RX;
};

struct usb_registers_map
{
  u32 EPR[8];
  u32 __padding0[8];
  u32 CNTR;
  u32 ISTR;
  u32 FNR;
  u32 DADDR;
  u32 BTABLE;
  struct usb_endpoint_descriptor DESC[8];
};

struct usb_descriptor_buffers
{
  u16* txbuf;
  u16* rxbuf;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum usb_cntr : u32
{
  USB_CNTR_FRES = (1 << 0),
  USB_CNTR_PDWN = (1 << 1),
  USB_CNTR_LP_MODE = (1 << 2),
  USB_CNTR_FSUSP = (1 << 3),
  USB_CNTR_RESUME = (1 << 4),
  USB_CNTR_ESOFM = (1 << 8),
  USB_CNTR_SOFM = (1 << 9),
  USB_CNTR_RESETM = (1 << 10),
  USB_CNTR_SUSPM = (1 << 11),
  USB_CNTR_WKUPM = (1 << 12),
  USB_CNTR_ERRM = (1 << 13),
  USB_CNTR_PMAOVRM = (1 << 14),
  USB_CNTR_CTRM = (1 << 15)
};

// #define USB_EPR_RW_MASK (0x70f)
#define USB_EPR_RW_MASK (\
      (USB_EPR_EA_MASK << USB_EPR_EA_SHIFT) |\
      (USB_EPR_EP_KIND) |\
      (USB_EPR_EP_TYPE_MASK << USB_EPR_EP_TYPE_SHIFT)\
    )

//#define USB_EPR_W0_MASK (0x8080)
#define USB_EPR_W0_MASK (USB_EPR_CTR_TX | USB_EPR_CTR_RX)

enum usb_epr : u32
{
  USB_EPR_DTOG_TX = (1 << 6),
  USB_EPR_CTR_TX = (1 << 7),
  USB_EPR_EP_KIND = (1 << 8),
  USB_EPR_SETUP = (1 << 11),
  USB_EPR_DTOG_RX = (1 << 14),
  USB_EPR_CTR_RX = (1 << 15)
};

#define USB_EPR_EA_SHIFT (0)
#define USB_EPR_EA_MASK (0xf)

#define USB_EPR_EP_TYPE_SHIFT (9)
#define USB_EPR_EP_TYPE_MASK (0x3)

enum usb_epr_ep_type : u32
{
  USB_EPR_EP_TYPE_BULK = 0b00,
  USB_EPR_EP_TYPE_CONTROL = 0b01,
  USB_EPR_EP_TYPE_ISO = 0b10,
  USB_EPR_EP_TYPE_INTERRUPT = 0b11
};

#define USB_EPR_STAT_TX_SHIFT (4)
#define USB_EPR_STAT_TX_MASK (0x3)

enum usb_epr_stat_tx : u32
{
  USB_EPR_STAT_TX_DISABLED = 0b00,
  USB_EPR_STAT_TX_STALL = 0b01,
  USB_EPR_STAT_TX_NAK = 0b10,
  USB_EPR_STAT_TX_VALID = 0b11
};

#define USB_EPR_STAT_RX_SHIFT (12)
#define USB_EPR_STAT_RX_MASK (0x3)

enum usb_epr_stat_rx : u32
{
  USB_EPR_STAT_RX_DISABLED = 0b00,
  USB_EPR_STAT_RX_STALL = 0b01,
  USB_EPR_STAT_RX_NAK = 0b10,
  USB_EPR_STAT_RX_VALID = 0b11
};

enum usb_istr : u32
{
  USB_ISTR_DIR = (1 << 4),
  USB_ISTR_ESOF = (1 << 8),
  USB_ISTR_SOF = (1 << 9),
  USB_ISTR_RESET = (1 << 10),
  USB_ISTR_SUSP = (1 << 11),
  USB_ISTR_WKUP = (1 << 12),
  USB_ISTR_ERR = (1 << 13),
  USB_ISTR_PMA_OVR = (1 << 14),
  USB_ISTR_CTR = (1 << 15)
};

#define USB_ISTR_EP_ID_SHIFT (0)
#define USB_ISTR_EP_ID_MASK (0xf)

enum usb_fnr : u32
{
  USB_FNR_LCK = (1 << 13),
  USB_FNR_RXDM = (1 << 14),
  USB_FNR_RXDP = (1 << 15)
};

#define USB_FNR_FN_SHIFT (0)
#define USB_FNR_FN_MASK (0x3ff)

#define USB_FNR_LSOF_SHIFT (11)
#define USB_FNR_LSOF_MASK (0x3)

enum usb_daddr : u32
{
  USB_DADDR_EF = (1 << 7)
};

#define USB_DADDR_ADD_SHIFT (0)
#define USB_DADDR_ADD_MASK (0x3f)

#define USB_BTABLE_BTABLE_SHIFT (3)
#define USB_BTABLE_BTABLE_MASK (0x1fff)

#define USB_COUNT_RX_COUNT_SHIFT (0)
#define USB_COUNT_RX_COUNT_MASK (0x3ff)

#define USB_COUNT_NUM_BLOCK_SHIFT (10)
#define USB_COUNT_NUM_BLOCK_MASK (0x1f)

enum usb_count_rx : u32
{
  USB_COUNT_RX_BL_SIZE = (1u << 15)
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum usb_control
{
  USB_CONTROL_FORCE_RESET,
  USB_CONTROL_POWER_DOWN,
  USB_CONTROL_LOW_POWER,
  USB_CONTROL_FORCE_SUSPEND,
  USB_CONTROL_RESUME_REQUEST
};

enum usb_interrupt
{
  USB_INTERRUPT_EXPECTED_START_OF_FRAME,
  USB_INTERRUPT_START_OF_FRAME,
  USB_INTERRUPT_USB_RESET,
  USB_INTERRUPT_SUSPEND_MODE,
  USB_INTERRUPT_WAKEUP,
  USB_INTERRUPT_ERROR,
  USB_INTERRUPT_PMA_UNDERRUN_OVERRUN,
  USB_INTERRUPT_CORRECT_TRANSFER
};

enum usb_flag
{
  USB_FLAG_EXPECTED_START_OF_FRAME,
  USB_FLAG_START_OF_FRAME,
  USB_FLAG_USB_RESET,
  USB_FLAG_SUSPEND_MODE,
  USB_FLAG_WAKEUP,
  USB_FLAG_ERROR,
  USB_FLAG_PMA_UNDERRUN_OVERRUN,
  USB_FLAG_CORRECT_TRANSFER
};

enum usb_ep_tx_status
{
  USB_EP_TX_STATUS_DISABLED,
  USB_EP_TX_STATUS_STALL,
  USB_EP_TX_STATUS_NAK,
  USB_EP_TX_STATUS_VALID
};

enum usb_endpoint_type
{
  USB_ENDPOINT_TYPE_BULK,
  USB_ENDPOINT_TYPE_CONTROL,
  USB_ENDPOINT_TYPE_ISO,
  USB_ENDPOINT_TYPE_INTERRUPT
};

enum usb_ep_rx_status
{
  USB_EP_RX_STATUS_DISABLED,
  USB_EP_RX_STATUS_STALL,
  USB_EP_RX_STATUS_NAK,
  USB_EP_RX_STATUS_VALID
};

enum usb_reception_block_size
{
  USB_RECEPTION_BLOCK_SIZE_SMALL,
  USB_RECEPTION_BLOCK_SIZE_LARGE
};

extern volatile struct usb_registers_map* USB;

void
usb_control_enable(
  enum usb_control control
);

void
usb_control_disable(
  enum usb_control control
);

void
usb_interrupt_enable(
  enum usb_interrupt interrupt
);

void
usb_interrupt_disable(
  enum usb_interrupt interrupt
);

u32
usb_get_endpoint_id(void);

u32
usb_get_transaction_direction(void);

u32
usb_is_flag_set(
  enum usb_flag flag
);

void
usb_flag_clear(
  enum usb_flag flag
);

u32
usb_get_frame_number(void);

u32
usb_get_consecutive_sof_packet_lost(void);

u32
usb_is_locked(void);

u32
usb_get_receive_data_neg_line_status(void);

u32
usb_get_receive_data_pos_line_status(void);

void
usb_set_device_address(
  u32 address
);

void
usb_enable(void);

void
usb_disable(void);

void
usb_set_buffer_table_address(
  u32 address
);

void
usb_set_endpoint_address(
  u32 index,
  u32 address
);

void
usb_set_endpoint_transmission_status(
  u32 ep_idx,
  enum usb_ep_tx_status status
);

u32
usb_get_endpoint_tx_data_toggle(
  u32 ep_idx
);

void
usb_endpoint_reset_tx_data_toggle(
  u32 ep_idx
);

u32
usb_is_endpoint_correct_transfer_flag_set(
  u32 ep_idx
);

void
usb_endpoint_correct_transfer_flag_clear(
  u32 ep_idx
);

void
usb_set_endpoint_kind(
  u32 ep_idx
);

void
usb_clear_endpoint_kind(
  u32 ep_idx
);

void
usb_set_endpoint_type(
  u32 ep_idx,
  enum usb_endpoint_type type
);

u32
usb_is_transaction_setup(
  u32 ep_idx
);

void
usb_set_endpoint_receive_status(
  u32 ep_idx,
  enum usb_ep_rx_status status
);

u32
usb_get_endpoint_rx_data_toggle(
  u32 ep_idx
);

void
usb_endpoint_reset_rx_data_toggle(
  u32 ep_idx
);

u32
usb_is_endpoint_correct_receive_flag_set(
  u32 ep_idx
);

void
usb_endpoint_correct_receive_flag_clear(
  u32 ep_idx
);

void
usb_set_transmission_buffer_address(
  u32 ep_idx,
  u32 address
);

void
usb_set_transmission_byte_count(
  u32 ep_idx,
  u32 count
);

void
usb_set_reception_buffer_address(
  u32 ep_idx,
  u32 address
);

void
usb_set_reception_byte_count(
  u32 ep_idx,
  u32 count
);

void
usb_set_reception_block_num(
  u32 ep_idx,
  u32 count
);

void
usb_set_reception_block_size(
  u32 ep_idx,
  enum usb_reception_block_size size
);

END_DECLARATIONS

#endif
