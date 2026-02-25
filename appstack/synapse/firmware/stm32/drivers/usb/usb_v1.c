#include "synapse/stm32/drivers/usb/usb_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct usb_registers_map usb_periph;
usb_periph* USB = (usb_periph*) (USB_FS_ADDR);

void
usb_control_enable(
  enum usb_control control
)
{
  volatile u32* reg = &USB->CNTR;

  switch (control)
  {
    case USB_CONTROL_FORCE_RESET:
      *reg |= USB_CNTR_FRES;
      break;

    case USB_CONTROL_POWER_DOWN:
      *reg |= USB_CNTR_PDWN;
      break;

    case USB_CONTROL_LOW_POWER:
      *reg |= USB_CNTR_LP_MODE;
      break;

    case USB_CONTROL_FORCE_SUSPEND:
      *reg |= USB_CNTR_FSUSP;
      break;

    case USB_CONTROL_RESUME_REQUEST:
      *reg |= USB_CNTR_RESUME;
      break;

    default:
      devmode_error_invalid_enum(enum usb_control, control);
      break;
  }
}

void
usb_control_disable(
  enum usb_control control
)
{
  volatile u32* reg = &USB->CNTR;

  switch (control)
  {
    case USB_CONTROL_FORCE_RESET:
      *reg &= ~USB_CNTR_FRES;
      break;

    case USB_CONTROL_POWER_DOWN:
      *reg &= ~USB_CNTR_PDWN;
      break;

    case USB_CONTROL_LOW_POWER:
      *reg &= ~USB_CNTR_LP_MODE;
      break;

    case USB_CONTROL_FORCE_SUSPEND:
      *reg &= ~USB_CNTR_FSUSP;
      break;

    case USB_CONTROL_RESUME_REQUEST:
      *reg &= ~USB_CNTR_RESUME;
      break;

    default:
      devmode_error_invalid_enum(enum usb_control, control);
      break;
  }
}

void
usb_interrupt_enable(
  enum usb_interrupt interrupt
)
{
  volatile u32* reg = &USB->CNTR;

  switch (interrupt)
  {
    case USB_INTERRUPT_EXPECTED_START_OF_FRAME:
      *reg |= USB_CNTR_ESOFM;
      break;

    case USB_INTERRUPT_START_OF_FRAME:
      *reg |= USB_CNTR_SOFM;
      break;

    case USB_INTERRUPT_USB_RESET:
      *reg |= USB_CNTR_RESETM;
      break;

    case USB_INTERRUPT_SUSPEND_MODE:
      *reg |= USB_CNTR_SUSPM;
      break;

    case USB_INTERRUPT_WAKEUP:
      *reg |= USB_CNTR_WKUPM;
      break;

    case USB_INTERRUPT_ERROR:
      *reg |= USB_CNTR_ERRM;
      break;

    case USB_INTERRUPT_PMA_UNDERRUN_OVERRUN:
      *reg |= USB_CNTR_PMAOVRM;
      break;

    case USB_INTERRUPT_CORRECT_TRANSFER:
      *reg |= USB_CNTR_CTRM;
      break;

    default:
      devmode_error_invalid_enum(enum usb_interrupt, interrupt);
      break;
  }
}

void
usb_interrupt_disable(
  enum usb_interrupt interrupt
)
{
  volatile u32* reg = &USB->CNTR;

  switch (interrupt)
  {
    case USB_INTERRUPT_EXPECTED_START_OF_FRAME:
      *reg &= ~USB_CNTR_ESOFM;
      break;

    case USB_INTERRUPT_START_OF_FRAME:
      *reg &= ~USB_CNTR_SOFM;
      break;

    case USB_INTERRUPT_USB_RESET:
      *reg &= ~USB_CNTR_RESETM;
      break;

    case USB_INTERRUPT_SUSPEND_MODE:
      *reg &= ~USB_CNTR_SUSPM;
      break;

    case USB_INTERRUPT_WAKEUP:
      *reg &= ~USB_CNTR_WKUPM;
      break;

    case USB_INTERRUPT_ERROR:
      *reg &= ~USB_CNTR_ERRM;
      break;

    case USB_INTERRUPT_PMA_UNDERRUN_OVERRUN:
      *reg &= ~USB_CNTR_PMAOVRM;
      break;

    case USB_INTERRUPT_CORRECT_TRANSFER:
      *reg &= ~USB_CNTR_CTRM;
      break;

    default:
      devmode_error_invalid_enum(enum usb_interrupt, interrupt);
      break;
  }
}

u32
usb_get_endpoint_id(void)
{
  constexpr u32 mask = USB_ISTR_EP_ID_MASK;
  constexpr u32 shift = USB_ISTR_EP_ID_SHIFT;
  return (USB->ISTR >> shift) & mask;
}

u32
usb_get_transaction_direction(void)
{
  return USB->ISTR & USB_ISTR_DIR;
}

u32
usb_is_flag_set(
  enum usb_flag flag
)
{
  volatile u32* reg = &USB->ISTR;

  switch (flag)
  {
    case USB_FLAG_EXPECTED_START_OF_FRAME:
      return *reg & USB_ISTR_ESOF;

    case USB_FLAG_START_OF_FRAME:
      return *reg & USB_ISTR_SOF;

    case USB_FLAG_USB_RESET:
      return *reg & USB_ISTR_RESET;

    case USB_FLAG_SUSPEND_MODE:
      return *reg & USB_ISTR_SUSP;

    case USB_FLAG_WAKEUP:
      return *reg & USB_ISTR_WKUP;

    case USB_FLAG_ERROR:
      return *reg & USB_ISTR_ERR;

    case USB_FLAG_PMA_UNDERRUN_OVERRUN:
      return *reg & USB_ISTR_PMA_OVR;

    case USB_FLAG_CORRECT_TRANSFER:
      return *reg & USB_ISTR_CTR;

    default:
      devmode_error_invalid_enum(enum usb_flag, flag);
      return 0;
  }
}

void
usb_flag_clear(
  enum usb_flag flag
)
{
  volatile u32* reg = &USB->ISTR;

  switch (flag)
  {
    case USB_FLAG_EXPECTED_START_OF_FRAME:
      *reg &= ~USB_ISTR_ESOF;
			break;

    case USB_FLAG_START_OF_FRAME:
      *reg &= ~USB_ISTR_SOF;
			break;

    case USB_FLAG_USB_RESET:
      *reg &= ~USB_ISTR_RESET;
			break;

    case USB_FLAG_SUSPEND_MODE:
      *reg &= ~USB_ISTR_SUSP;
			break;

    case USB_FLAG_WAKEUP:
      *reg &= ~USB_ISTR_WKUP;
			break;

    case USB_FLAG_ERROR:
      *reg &= ~USB_ISTR_ERR;
			break;

    case USB_FLAG_PMA_UNDERRUN_OVERRUN:
      *reg &= ~USB_ISTR_PMA_OVR;
			break;

    default:
      devmode_error_invalid_enum(enum usb_flag, flag);
      break;
  }
}

u32
usb_get_frame_number(void)
{
  constexpr u32 mask = USB_FNR_FN_MASK;
  constexpr u32 shift = USB_FNR_FN_SHIFT;
  return (USB->FNR >> shift) & mask;
}

u32
usb_get_consecutive_sof_packet_lost(void)
{
  constexpr u32 mask = USB_FNR_LSOF_MASK;
  constexpr u32 shift = USB_FNR_LSOF_SHIFT;
  return (USB->FNR >> shift) & mask;
}

u32
usb_is_locked(void)
{
  return USB->FNR & USB_FNR_LCK;
}

u32
usb_get_receive_data_neg_line_status(void)
{
  return USB->FNR & USB_FNR_RXDM;
}

u32
usb_get_receive_data_pos_line_status(void)
{
  return USB->FNR & USB_FNR_RXDP;
}

void
usb_set_device_address(
  u32 address
)
{
  devmode_assert_lower_or_eq(address, USB_DADDR_ADD_MASK);
  constexpr u32 shift = USB_DADDR_ADD_SHIFT;
  constexpr u32 mask = USB_DADDR_ADD_MASK << shift;
  volatile u32* reg = &USB->DADDR;
  syn_set_register_bits(reg, mask, address << shift);
}

void
usb_enable(void)
{
  USB->DADDR |= USB_DADDR_EF;
}

void
usb_disable(void)
{
  USB->DADDR &= ~USB_DADDR_EF;
}

void
usb_set_buffer_table_address(
  u32 address
)
{
  volatile u32* reg = &USB->BTABLE;
  constexpr u32 shift = USB_BTABLE_BTABLE_SHIFT;
  constexpr u32 mask = USB_BTABLE_BTABLE_MASK;
  syn_set_register_bits(reg, mask, address << shift);
}

void
usb_set_endpoint_address(
  u32 index,
  u32 address
)
{
  devmode_assert_lower_or_eq(address, USB_EPR_EA_MASK);
  devmode_assert_lower(index, ARR_SIZE(USB->EPR));

  constexpr u32 shift = USB_EPR_EA_SHIFT;
  constexpr u32 mask = USB_EPR_EA_MASK << shift;
  volatile u32* reg = &USB->EPR[index];
  syn_set_register_bits(reg, mask, address << shift);
}

void
usb_set_endpoint_transmission_status(
  u32 ep_idx,
  enum usb_ep_tx_status status
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));

  constexpr u32 shift = USB_EPR_STAT_TX_SHIFT;
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_w0 = USB_EPR_W0_MASK;
  constexpr u32 mask_stat_tx = USB_EPR_STAT_TX_MASK << shift;
  constexpr u32 mask = mask_rw | mask_stat_tx;

  volatile u32* reg = &USB->EPR[ep_idx];
  const u32 val = *reg & mask;

  switch (status)
  {
    case USB_EP_TX_STATUS_DISABLED:
      *reg = (val ^ (USB_EPR_STAT_TX_DISABLED << shift)) | mask_w0;
      break;

    case USB_EP_TX_STATUS_STALL:
      *reg = (val ^ (USB_EPR_STAT_TX_STALL << shift)) | mask_w0;
      break;

    case USB_EP_TX_STATUS_NAK:
      *reg = (val ^ (USB_EPR_STAT_TX_NAK << shift)) | mask_w0;
      break;

    case USB_EP_TX_STATUS_VALID:
      *reg = (val ^ (USB_EPR_STAT_TX_VALID << shift)) | mask_w0;
      break;

    default:
      devmode_error_invalid_enum(enum usb_ep_tx_status, status);
      break;
  }
}

u32
usb_get_endpoint_tx_data_toggle(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  return USB->EPR[ep_idx] & USB_EPR_DTOG_TX;
}

void
usb_endpoint_reset_tx_data_toggle(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_t = USB_EPR_W0_MASK;
  volatile u32* reg = &USB->EPR[ep_idx];
  *reg = (*reg & mask_rw) | USB_EPR_DTOG_TX | mask_t;
}

u32
usb_is_endpoint_correct_transfer_flag_set(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  return USB->EPR[ep_idx] & USB_EPR_CTR_TX;
}

void
usb_endpoint_correct_transfer_flag_clear(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_w0 = USB_EPR_W0_MASK;
  volatile u32* reg = &USB->EPR[ep_idx];
  *reg = ((*reg & mask_rw) | mask_w0) & ~USB_EPR_CTR_TX;
}

void
usb_set_endpoint_kind(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_w0 = USB_EPR_W0_MASK;
  volatile u32* reg = &USB->EPR[ep_idx];
  *reg = (*reg & mask_rw) | USB_EPR_EP_KIND | mask_w0;
}

void
usb_clear_endpoint_kind(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_w0 = USB_EPR_W0_MASK;
  volatile u32* reg = &USB->EPR[ep_idx];
  *reg = ((*reg & mask_rw) & ~USB_EPR_EP_KIND) | mask_w0;
}

void
usb_set_endpoint_type(
  u32 ep_idx,
  enum usb_endpoint_type type
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));

  constexpr u32 mask_rw = USB_EPR_EA_MASK | USB_EPR_EP_KIND | USB_EPR_W0_MASK;
  constexpr u32 shift = USB_EPR_EP_TYPE_SHIFT; // 9
  volatile u32* reg = &USB->EPR[ep_idx];
  const u32 val = *reg & mask_rw;

  switch (type)
  {
    case USB_ENDPOINT_TYPE_BULK:
      *reg = val | (USB_EPR_EP_TYPE_BULK << shift);
      break;

    case USB_ENDPOINT_TYPE_CONTROL:
      *reg = val | (USB_EPR_EP_TYPE_CONTROL << shift);
      break;

    case USB_ENDPOINT_TYPE_ISO:
      *reg = val | (USB_EPR_EP_TYPE_ISO << shift);
      break;

    case USB_ENDPOINT_TYPE_INTERRUPT:
      *reg = val | (USB_EPR_EP_TYPE_INTERRUPT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum usb_endpoint_type, type);
      break;
  }
}

u32
usb_is_transaction_setup(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  return USB->EPR[ep_idx] & USB_EPR_SETUP;
}

void
usb_set_endpoint_receive_status(
  u32 ep_idx,
  enum usb_ep_rx_status status
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));

  constexpr u32 shift = USB_EPR_STAT_RX_SHIFT;
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_w0 = USB_EPR_W0_MASK;
  constexpr u32 mask_stat_rx = USB_EPR_STAT_RX_MASK << shift;
  constexpr u32 mask = mask_rw | mask_stat_rx;

  volatile u32* reg = &USB->EPR[ep_idx];
  const u32 val = *reg & mask;

  switch (status)
  {
    case USB_EP_RX_STATUS_DISABLED:
      *reg = (val ^ (USB_EPR_STAT_RX_DISABLED << shift)) | mask_w0;
      break;

    case USB_EP_RX_STATUS_STALL:
      *reg = (val ^ (USB_EPR_STAT_RX_STALL << shift)) | mask_w0;
      break;

    case USB_EP_RX_STATUS_NAK:
      *reg = (val ^ (USB_EPR_STAT_RX_NAK << shift)) | mask_w0;
      break;

    case USB_EP_RX_STATUS_VALID:
      *reg = (val ^ (USB_EPR_STAT_RX_VALID << shift)) | mask_w0;
      break;

    default:
      devmode_error_invalid_enum(enum usb_ep_rx_status, status);
      break;
  }
}

u32
usb_get_endpoint_rx_data_toggle(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  return USB->EPR[ep_idx] & USB_EPR_DTOG_RX;
}

void
usb_endpoint_reset_rx_data_toggle(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_t = USB_EPR_W0_MASK;
  volatile u32* reg = &USB->EPR[ep_idx];
  *reg = (*reg & mask_rw) | USB_EPR_DTOG_RX | mask_t;
}

u32
usb_is_endpoint_correct_receive_flag_set(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  return USB->EPR[ep_idx] & USB_EPR_CTR_RX;
}

void
usb_endpoint_correct_receive_flag_clear(
  u32 ep_idx
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  constexpr u32 mask_rw = USB_EPR_RW_MASK;
  constexpr u32 mask_w0 = USB_EPR_W0_MASK;
  volatile u32* reg = &USB->EPR[ep_idx];
  *reg = ((*reg & mask_rw) | mask_w0) & ~USB_EPR_CTR_RX;
}

void
usb_set_transmission_buffer_address(
  u32 ep_idx,
  u32 address
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  devmode_assert_lower_or_eq(address, 0xffff);
  volatile u16* reg = &USB->DESC[ep_idx].ADDR_TX;
  *reg = (u16) address;
}

void
usb_set_transmission_byte_count(
  u32 ep_idx,
  u32 count
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  devmode_assert_lower_or_eq(count, 0xffff);
  volatile u16* reg = &USB->DESC[ep_idx].COUNT_TX;
  *reg = (u16) count;
}

void
usb_set_reception_buffer_address(
  u32 ep_idx,
  u32 address
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  devmode_assert_lower_or_eq(address, 0xffff);
  volatile u16* reg = &USB->DESC[ep_idx].ADDR_RX;
  *reg = (u16) address;
}

void
usb_set_reception_byte_count(
  u32 ep_idx,
  u32 count
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  devmode_assert_lower_or_eq(count, 0xffff);
  volatile u16* reg = &USB->DESC[ep_idx].COUNT_RX;
  *reg = (u16) count;
}

void
usb_set_reception_block_num(
  u32 ep_idx,
  u32 count
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  devmode_assert_lower_or_eq(count, 0xffff);

  volatile u16* reg = &USB->DESC[ep_idx].COUNT_RX;
  constexpr u32 mask = USB_COUNT_NUM_BLOCK_MASK;
  constexpr u32 shift = USB_COUNT_NUM_BLOCK_SHIFT;
  *reg = (u16) ((*reg & ~mask) | ((u16) (count << shift)));
}

void
usb_set_reception_block_size(
  u32 ep_idx,
  enum usb_reception_block_size size
)
{
  devmode_assert_lower(ep_idx, ARR_SIZE(USB->EPR));
  volatile u16* reg = &USB->DESC[ep_idx].COUNT_RX;

  switch (size)
  {
    case USB_RECEPTION_BLOCK_SIZE_SMALL:
      *reg &= (u16) (~USB_COUNT_RX_BL_SIZE);
      break;

    case USB_RECEPTION_BLOCK_SIZE_LARGE:
      *reg |= USB_COUNT_RX_BL_SIZE;
      break;
      
    default:
      devmode_error_invalid_enum(enum usb_reception_block_size, size);
      break;
  }
}
