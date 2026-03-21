#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/can/can_v1.h"
#include "libtest/libtest.h"

volatile struct can_registers_map* _CAN;

void
setup(void)
{
  _CAN = (struct can_registers_map*) membuf;
}

void
test_can_set_hardware_mode(void)
{
  _CAN->MCR = 0;
  can_set_hardware_mode(_CAN, CAN_HARDWARE_MODE_INIT);
  ASSERT_EQ(_CAN->MCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 0);
  can_set_hardware_mode(_CAN, CAN_HARDWARE_MODE_INIT);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 0);
  can_set_hardware_mode(_CAN, CAN_HARDWARE_MODE_NORMAL);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_set_hardware_mode(_CAN, CAN_HARDWARE_MODE_NORMAL);
  ASSERT_EQ(_CAN->MCR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_can_sleep_mode(void)
{
  _CAN->MCR = 0;
  can_sleep_mode_enable(_CAN);
  ASSERT_EQ(_CAN->MCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 1);
  can_sleep_mode_enable(_CAN);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 1);
  can_sleep_mode_disable(_CAN);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_sleep_mode_disable(_CAN);
  ASSERT_EQ(_CAN->MCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_tx_fifo_priority(void)
{
  _CAN->MCR = 0;
  can_set_tx_fifo_priority(_CAN, CAN_TX_FIFO_PRIORTY_REQUEST_ORDER);
  ASSERT_EQ(_CAN->MCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 2);
  can_set_tx_fifo_priority(_CAN, CAN_TX_FIFO_PRIORTY_REQUEST_ORDER);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 2);
  can_set_tx_fifo_priority(_CAN, CAN_TX_FIFO_PRIORTY_MESSAGE_IDENTIFIER);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_set_tx_fifo_priority(_CAN, CAN_TX_FIFO_PRIORTY_MESSAGE_IDENTIFIER);
  ASSERT_EQ(_CAN->MCR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_rx_fifo_locked_mode(void)
{
  _CAN->MCR = 0;
  can_set_rx_fifo_locked_mode(_CAN, CAN_RX_FIFO_LOCKED_MODE_DISCARD);
  ASSERT_EQ(_CAN->MCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 3);
  can_set_rx_fifo_locked_mode(_CAN, CAN_RX_FIFO_LOCKED_MODE_DISCARD);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 3);
  can_set_rx_fifo_locked_mode(_CAN, CAN_RX_FIFO_LOCKED_MODE_OVERRIDE);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_set_rx_fifo_locked_mode(_CAN, CAN_RX_FIFO_LOCKED_MODE_OVERRIDE);
  ASSERT_EQ(_CAN->MCR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_automatic_transmission_policy(void)
{
  _CAN->MCR = 0;
  can_set_automatic_transmission_policy(_CAN, CAN_AUTOMATIC_TRANSMISSION_POLICY_ONCE);
  ASSERT_EQ(_CAN->MCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 4);
  can_set_automatic_transmission_policy(_CAN, CAN_AUTOMATIC_TRANSMISSION_POLICY_ONCE);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 4);
  can_set_automatic_transmission_policy(_CAN, CAN_AUTOMATIC_TRANSMISSION_POLICY_REPEATED);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_set_automatic_transmission_policy(_CAN, CAN_AUTOMATIC_TRANSMISSION_POLICY_REPEATED);
  ASSERT_EQ(_CAN->MCR, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_automatic_wakeup_mode(void)
{
  _CAN->MCR = 0;
  can_set_automatic_wakeup_mode(_CAN, CAN_AUTOMATIC_WAKEUP_MODE_HARDWARE);
  ASSERT_EQ(_CAN->MCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 5);
  can_set_automatic_wakeup_mode(_CAN, CAN_AUTOMATIC_WAKEUP_MODE_HARDWARE);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 5);
  can_set_automatic_wakeup_mode(_CAN, CAN_AUTOMATIC_WAKEUP_MODE_SOFTWARE);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_set_automatic_wakeup_mode(_CAN, CAN_AUTOMATIC_WAKEUP_MODE_SOFTWARE);
  ASSERT_EQ(_CAN->MCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_automatic_bus_off(void)
{
  _CAN->MCR = 0;
  can_set_automatic_bus_off(_CAN, CAN_BUS_OFF_MANAGEMENT_HARDWARE);
  ASSERT_EQ(_CAN->MCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 6);
  can_set_automatic_bus_off(_CAN, CAN_BUS_OFF_MANAGEMENT_HARDWARE);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 6);
  can_set_automatic_bus_off(_CAN, CAN_BUS_OFF_MANAGEMENT_SOFTWARE);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_set_automatic_bus_off(_CAN, CAN_BUS_OFF_MANAGEMENT_SOFTWARE);
  ASSERT_EQ(_CAN->MCR, 0xffffffff & ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}

void
test_can_time_triggered_communication(void)
{
  _CAN->MCR = 0;
  can_time_triggered_communication_enable(_CAN);
  ASSERT_EQ(_CAN->MCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 7);
  can_time_triggered_communication_enable(_CAN);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 7);
  can_time_triggered_communication_disable(_CAN);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_time_triggered_communication_disable(_CAN);
  ASSERT_EQ(_CAN->MCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_can_software_reset(void)
{
  _CAN->MCR = 0;
  can_software_reset(_CAN);
  ASSERT_EQ(_CAN->MCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 15);
  can_software_reset(_CAN);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_debug_freeze(void)
{
  _CAN->MCR = 0;
  can_set_debug_freeze(_CAN, CAN_DEBUG_FREEZE_FROZEN);
  ASSERT_EQ(_CAN->MCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = ~(1u << 16);
  can_set_debug_freeze(_CAN, CAN_DEBUG_FREEZE_FROZEN);
  ASSERT_EQ(_CAN->MCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = (1u << 16);
  can_set_debug_freeze(_CAN, CAN_DEBUG_FREEZE_UNFROZEN);
  ASSERT_EQ(_CAN->MCR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MCR = 0xffffffff;
  can_set_debug_freeze(_CAN, CAN_DEBUG_FREEZE_UNFROZEN);
  ASSERT_EQ(_CAN->MCR, 0xffffffff & ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}

void
test_can_is_flag_set(void)
{
  u32 res;

  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_INIT_ACK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 0);
  res = can_is_flag_set(_CAN, CAN_FLAG_INIT_ACK);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 0);
  res = can_is_flag_set(_CAN, CAN_FLAG_INIT_ACK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_INIT_ACK);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 1);
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 1);
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_ERROR_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 2);
  res = can_is_flag_set(_CAN, CAN_FLAG_ERROR_INTERRUPT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 2);
  res = can_is_flag_set(_CAN, CAN_FLAG_ERROR_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_ERROR_INTERRUPT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_WAKEUP_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 3);
  res = can_is_flag_set(_CAN, CAN_FLAG_WAKEUP_INTERRUPT);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 3);
  res = can_is_flag_set(_CAN, CAN_FLAG_WAKEUP_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_WAKEUP_INTERRUPT);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 4);
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK_INTERRUPT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 4);
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK_INTERRUPT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_SLEEP_ACK_INTERRUPT);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_TX_MODE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 8);
  res = can_is_flag_set(_CAN, CAN_FLAG_TX_MODE);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 8);
  res = can_is_flag_set(_CAN, CAN_FLAG_TX_MODE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_TX_MODE);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_MODE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 9);
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_MODE);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 9);
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_MODE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_MODE);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_LAST_SAMPLE_POINT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 10);
  res = can_is_flag_set(_CAN, CAN_FLAG_LAST_SAMPLE_POINT);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 10);
  res = can_is_flag_set(_CAN, CAN_FLAG_LAST_SAMPLE_POINT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_LAST_SAMPLE_POINT);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_SIGNAL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = (1u << 11);
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_SIGNAL);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 11);
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_SIGNAL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = 0xffffffff;
  res = can_is_flag_set(_CAN, CAN_FLAG_RX_SIGNAL);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


}

void
test_can_flag_clear(void)
{
  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_INIT_ACK);
  ASSERT_EQ(_CAN->MSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->MSR = ~(1u << 0);
  can_flag_clear(_CAN, CAN_FLAG_INIT_ACK);
  ASSERT_EQ(_CAN->MSR, ~(1u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_SLEEP_ACK);
  ASSERT_EQ(_CAN->MSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->MSR = ~(1u << 1);
  can_flag_clear(_CAN, CAN_FLAG_SLEEP_ACK);
  ASSERT_EQ(_CAN->MSR, ~(1u << 1));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_ERROR_INTERRUPT);
  ASSERT_EQ(_CAN->MSR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 2);
  can_flag_clear(_CAN, CAN_FLAG_ERROR_INTERRUPT);
  ASSERT_EQ(_CAN->MSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_WAKEUP_INTERRUPT);
  ASSERT_EQ(_CAN->MSR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 3);
  can_flag_clear(_CAN, CAN_FLAG_WAKEUP_INTERRUPT);
  ASSERT_EQ(_CAN->MSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_SLEEP_ACK_INTERRUPT);
  ASSERT_EQ(_CAN->MSR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->MSR = ~(1u << 4);
  can_flag_clear(_CAN, CAN_FLAG_SLEEP_ACK_INTERRUPT);
  ASSERT_EQ(_CAN->MSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_TX_MODE);
  ASSERT_EQ(_CAN->MSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->MSR = ~(1u << 8);
  can_flag_clear(_CAN, CAN_FLAG_TX_MODE);
  ASSERT_EQ(_CAN->MSR, ~(1u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_RX_MODE);
  ASSERT_EQ(_CAN->MSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->MSR = ~(1u << 9);
  can_flag_clear(_CAN, CAN_FLAG_RX_MODE);
  ASSERT_EQ(_CAN->MSR, ~(1u << 9));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_LAST_SAMPLE_POINT);
  ASSERT_EQ(_CAN->MSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->MSR = ~(1u << 10);
  can_flag_clear(_CAN, CAN_FLAG_LAST_SAMPLE_POINT);
  ASSERT_EQ(_CAN->MSR, ~(1u << 10));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->MSR = 0;
  can_flag_clear(_CAN, CAN_FLAG_RX_SIGNAL);
  ASSERT_EQ(_CAN->MSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->MSR = ~(1u << 11);
  can_flag_clear(_CAN, CAN_FLAG_RX_SIGNAL);
  ASSERT_EQ(_CAN->MSR, ~(1u << 11));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_is_mailbox_flag_set(void)
{
  u32 res;

  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 0);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 0);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 1);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 1);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 2);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 2);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 3);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 3);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 7);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 7);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 8);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 8);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 9);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 9);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 10);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 10);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 11);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 11);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 15);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 15);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 16);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 16);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 17);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 17);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 18);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 18);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 19);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 19);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = (1u << 23);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, (1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 23);
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0xffffffff;
  res = can_is_mailbox_flag_set(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(res, (1u << 23));
  ASSERT_FALSE(execution_halted());


}

void
test_can_mailbox_flag_clear(void)
{
  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(_CAN->TSR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 0);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(_CAN->TSR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 1);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(_CAN->TSR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 2);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(_CAN->TSR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 3);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(_CAN->TSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->TSR = ~(1u << 7);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX0, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(_CAN->TSR, ~(1u << 7));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(_CAN->TSR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 8);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(_CAN->TSR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 9);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(_CAN->TSR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 10);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(_CAN->TSR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 11);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(_CAN->TSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->TSR = ~(1u << 15);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX1, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(_CAN->TSR, ~(1u << 15));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(_CAN->TSR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 16);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_REQUEST_COMPLETED);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(_CAN->TSR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 17);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_OK);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(_CAN->TSR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 18);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ARBITRACTION_LOST);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(_CAN->TSR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(1u << 19);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_TRANSMISSION_ERROR);
  ASSERT_EQ(_CAN->TSR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->TSR = 0;
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(_CAN->TSR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->TSR = ~(1u << 23);
  can_mailbox_flag_clear(_CAN, CAN_MAILBOX2, CAN_MAILBOX_FLAG_ABORT_REQUEST);
  ASSERT_EQ(_CAN->TSR, ~(1u << 23));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_get_mailbox_code(void)
{
  u32 res;

  // read_bits
  _CAN->TSR = 0;
  res = can_get_mailbox_code(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = ~(0x3u << 24);
  res = can_get_mailbox_code(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->TSR = 0x3u << 24;
  res = can_get_mailbox_code(_CAN);
  ASSERT_EQ(res, 0x3);
  ASSERT_FALSE(execution_halted());

}

void
test_can_get_fifo_pending_messages_count(void)
{
  u32 res;

  // read_bits
  _CAN->RF0R = 0;
  res = can_get_fifo_pending_messages_count(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = ~(0x3u << 0);
  res = can_get_fifo_pending_messages_count(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = 0x3u << 0;
  res = can_get_fifo_pending_messages_count(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0x3);
  ASSERT_FALSE(execution_halted());


  // read_bits
  _CAN->RF1R = 0;
  res = can_get_fifo_pending_messages_count(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = ~(0x3u << 0);
  res = can_get_fifo_pending_messages_count(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = 0x3u << 0;
  res = can_get_fifo_pending_messages_count(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0x3);
  ASSERT_FALSE(execution_halted());


}

void
test_can_is_fifo_flag_set(void)
{
  u32 res;

  _CAN->RF0R = 0;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = (1u << 3);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = ~(1u << 3);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = 0xffffffff;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _CAN->RF0R = 0;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = (1u << 4);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = ~(1u << 4);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = 0xffffffff;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  _CAN->RF1R = 0;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = (1u << 3);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = ~(1u << 3);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = 0xffffffff;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  _CAN->RF1R = 0;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = (1u << 4);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = ~(1u << 4);
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = 0xffffffff;
  res = can_is_fifo_flag_set(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_can_fifo_flag_clear(void)
{
  _CAN->RF0R = 0;
  can_fifo_flag_clear(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(_CAN->RF0R, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = ~(1u << 3);
  can_fifo_flag_clear(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(_CAN->RF0R, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->RF0R = 0;
  can_fifo_flag_clear(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(_CAN->RF0R, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = ~(1u << 4);
  can_fifo_flag_clear(_CAN, CAN_FIFO0, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(_CAN->RF0R, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->RF1R = 0;
  can_fifo_flag_clear(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(_CAN->RF1R, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = ~(1u << 3);
  can_fifo_flag_clear(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_FULL);
  ASSERT_EQ(_CAN->RF1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->RF1R = 0;
  can_fifo_flag_clear(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(_CAN->RF1R, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = ~(1u << 4);
  can_fifo_flag_clear(_CAN, CAN_FIFO1, CAN_FIFO_FLAG_OVERRUN);
  ASSERT_EQ(_CAN->RF1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_fifo_release(void)
{
  _CAN->RF0R = 0;
  can_fifo_release(_CAN, CAN_FIFO0);
  ASSERT_EQ(_CAN->RF0R, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->RF0R = ~(1u << 5);
  can_fifo_release(_CAN, CAN_FIFO0);
  ASSERT_EQ(_CAN->RF0R, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  _CAN->RF1R = 0;
  can_fifo_release(_CAN, CAN_FIFO1);
  ASSERT_EQ(_CAN->RF1R, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->RF1R = ~(1u << 5);
  can_fifo_release(_CAN, CAN_FIFO1);
  ASSERT_EQ(_CAN->RF1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_interrupt_toggle(void)
{
  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_TX_MAILBOX_EMPTY);
  ASSERT_EQ(_CAN->IER, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 0);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_TX_MAILBOX_EMPTY);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_TX_MAILBOX_EMPTY);
  ASSERT_EQ(_CAN->IER, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 0);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_TX_MAILBOX_EMPTY);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO0_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 1);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO0_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO0_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 1);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO0_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO0_FULL);
  ASSERT_EQ(_CAN->IER, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 2);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO0_FULL);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO0_FULL);
  ASSERT_EQ(_CAN->IER, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 2);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO0_FULL);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO0_OVERRUN);
  ASSERT_EQ(_CAN->IER, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 3);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO0_OVERRUN);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO0_OVERRUN);
  ASSERT_EQ(_CAN->IER, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 3);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO0_OVERRUN);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO1_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 4);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO1_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO1_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 4);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO1_MESSAGE_PENDING);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO1_FULL);
  ASSERT_EQ(_CAN->IER, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 5);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO1_FULL);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO1_FULL);
  ASSERT_EQ(_CAN->IER, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 5);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO1_FULL);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO1_OVERRUN);
  ASSERT_EQ(_CAN->IER, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 6);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_FIFO1_OVERRUN);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO1_OVERRUN);
  ASSERT_EQ(_CAN->IER, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 6);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_FIFO1_OVERRUN);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_ERROR_WARNING);
  ASSERT_EQ(_CAN->IER, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 8);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_ERROR_WARNING);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_ERROR_WARNING);
  ASSERT_EQ(_CAN->IER, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 8);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_ERROR_WARNING);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_ERROR_PASSIVE);
  ASSERT_EQ(_CAN->IER, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 9);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_ERROR_PASSIVE);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_ERROR_PASSIVE);
  ASSERT_EQ(_CAN->IER, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 9);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_ERROR_PASSIVE);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_BUS_OFF);
  ASSERT_EQ(_CAN->IER, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 10);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_BUS_OFF);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_BUS_OFF);
  ASSERT_EQ(_CAN->IER, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 10);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_BUS_OFF);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_LAST_ERROR_CODE);
  ASSERT_EQ(_CAN->IER, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 11);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_LAST_ERROR_CODE);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_LAST_ERROR_CODE);
  ASSERT_EQ(_CAN->IER, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 11);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_LAST_ERROR_CODE);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_ERROR);
  ASSERT_EQ(_CAN->IER, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 15);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_ERROR);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_ERROR);
  ASSERT_EQ(_CAN->IER, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 15);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_ERROR);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_WAKEUP);
  ASSERT_EQ(_CAN->IER, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 16);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_WAKEUP);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_WAKEUP);
  ASSERT_EQ(_CAN->IER, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 16);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_WAKEUP);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


  _CAN->IER = 0;
  can_interrupt_enable(_CAN, CAN_INTERRUPT_SLEEP);
  ASSERT_EQ(_CAN->IER, (1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = ~(1u << 17);
  can_interrupt_enable(_CAN, CAN_INTERRUPT_SLEEP);
  ASSERT_EQ(_CAN->IER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->IER = 0xffffffff;
  can_interrupt_disable(_CAN, CAN_INTERRUPT_SLEEP);
  ASSERT_EQ(_CAN->IER, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->IER = (1u << 17);
  can_interrupt_disable(_CAN, CAN_INTERRUPT_SLEEP);
  ASSERT_EQ(_CAN->IER, 0);
  ASSERT_FALSE(execution_halted());


}

void
test_can_is_error_flag_set(void)
{
  u32 res;

  _CAN->ESR = 0;
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_WARNING);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = (1u << 0);
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_WARNING);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = ~(1u << 0);
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_WARNING);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = 0xffffffff;
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_WARNING);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->ESR = 0;
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_PASSIVE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = (1u << 1);
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_PASSIVE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = ~(1u << 1);
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_PASSIVE);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = 0xffffffff;
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_ERROR_PASSIVE);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  _CAN->ESR = 0;
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_BUS_OFF);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = (1u << 2);
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_BUS_OFF);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = ~(1u << 2);
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_BUS_OFF);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = 0xffffffff;
  res = can_is_error_flag_set(_CAN, CAN_ERROR_FLAG_BUS_OFF);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_last_error_code(void)
{
  u32 res;

  // read_bits
  _CAN->ESR = 0;
  res = can_get_last_error_code(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = ~(0x7u << 4);
  res = can_get_last_error_code(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = 0x7u << 4;
  res = can_get_last_error_code(_CAN);
  ASSERT_EQ(res, 0x7);
  ASSERT_FALSE(execution_halted());

}

void
test_can_last_error_code_reset(void)
{
  _CAN->ESR = 0;
  can_last_error_code_reset(_CAN);
  ASSERT_EQ(_CAN->ESR, (0b111u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = ~(0b111u << 4);
  can_last_error_code_reset(_CAN);
  ASSERT_EQ(_CAN->ESR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_transmit_error_counter(void)
{
  u32 res;

  // read_bits
  _CAN->ESR = 0;
  res = can_get_transmit_error_counter(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = ~(0xffu << 16);
  res = can_get_transmit_error_counter(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = 0xffu << 16;
  res = can_get_transmit_error_counter(_CAN);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_can_get_receive_error_counter(void)
{
  u32 res;

  // read_bits
  _CAN->ESR = 0;
  res = can_get_receive_error_counter(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = ~(0xffu << 24);
  res = can_get_receive_error_counter(_CAN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->ESR = 0xffu << 24;
  res = can_get_receive_error_counter(_CAN);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_baudrate(void)
{
  _CAN->BTR = 0;
  can_set_baudrate(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_baudrate(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, ~(0x3ffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_baudrate(_CAN, 0x3ff);
  ASSERT_EQ(_CAN->BTR, 0x3ffu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_baudrate(_CAN, 0x3ff);
  ASSERT_EQ(_CAN->BTR, ~(0x3ffu << 0) | (0x3ffu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_baudrate(_CAN, 0x400);
  ASSERT_EQ(_CAN->BTR, 0x400u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->BTR = 0xffffffff;
  can_set_baudrate(_CAN, 0x400);
  ASSERT_EQ(_CAN->BTR, ~(0x3ffu << 0) | (0x400u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_set_time_segment1(void)
{
  _CAN->BTR = 0;
  can_set_time_segment1(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_time_segment1(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, ~(0xfu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_time_segment1(_CAN, 0xf);
  ASSERT_EQ(_CAN->BTR, 0xfu << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_time_segment1(_CAN, 0xf);
  ASSERT_EQ(_CAN->BTR, ~(0xfu << 16) | (0xfu << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_time_segment1(_CAN, 0x10);
  ASSERT_EQ(_CAN->BTR, 0x10u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->BTR = 0xffffffff;
  can_set_time_segment1(_CAN, 0x10);
  ASSERT_EQ(_CAN->BTR, ~(0xfu << 16) | (0x10u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_set_time_segment2(void)
{
  _CAN->BTR = 0;
  can_set_time_segment2(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, 0u << 20);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_time_segment2(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, ~(0x7u << 20) | (0u << 20));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_time_segment2(_CAN, 0x7);
  ASSERT_EQ(_CAN->BTR, 0x7u << 20);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_time_segment2(_CAN, 0x7);
  ASSERT_EQ(_CAN->BTR, ~(0x7u << 20) | (0x7u << 20));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_time_segment2(_CAN, 0x8);
  ASSERT_EQ(_CAN->BTR, 0x8u << 20);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->BTR = 0xffffffff;
  can_set_time_segment2(_CAN, 0x8);
  ASSERT_EQ(_CAN->BTR, ~(0x7u << 20) | (0x8u << 20));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_set_resync_jump_width(void)
{
  _CAN->BTR = 0;
  can_set_resync_jump_width(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, 0u << 24);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_resync_jump_width(_CAN, 0);
  ASSERT_EQ(_CAN->BTR, ~(0x3u << 24) | (0u << 24));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_resync_jump_width(_CAN, 0x3);
  ASSERT_EQ(_CAN->BTR, 0x3u << 24);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_set_resync_jump_width(_CAN, 0x3);
  ASSERT_EQ(_CAN->BTR, ~(0x3u << 24) | (0x3u << 24));
  ASSERT_FALSE(execution_halted());


  _CAN->BTR = 0;
  can_set_resync_jump_width(_CAN, 0x4);
  ASSERT_EQ(_CAN->BTR, 0x4u << 24);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->BTR = 0xffffffff;
  can_set_resync_jump_width(_CAN, 0x4);
  ASSERT_EQ(_CAN->BTR, ~(0x3u << 24) | (0x4u << 24));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_loopback_mode(void)
{
  _CAN->BTR = 0;
  can_loopback_mode_enable(_CAN);
  ASSERT_EQ(_CAN->BTR, (1u << 30));
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = ~(1u << 30);
  can_loopback_mode_enable(_CAN);
  ASSERT_EQ(_CAN->BTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = (1u << 30);
  can_loopback_mode_disable(_CAN);
  ASSERT_EQ(_CAN->BTR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_loopback_mode_disable(_CAN);
  ASSERT_EQ(_CAN->BTR, ~(1u << 30));
  ASSERT_FALSE(execution_halted());

}

void
test_can_silent_mode(void)
{
  _CAN->BTR = 0;
  can_silent_mode_enable(_CAN);
  ASSERT_EQ(_CAN->BTR, (1u << 31));
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = ~(1u << 31);
  can_silent_mode_enable(_CAN);
  ASSERT_EQ(_CAN->BTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = (1u << 31);
  can_silent_mode_disable(_CAN);
  ASSERT_EQ(_CAN->BTR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->BTR = 0xffffffff;
  can_silent_mode_disable(_CAN);
  ASSERT_EQ(_CAN->BTR, ~(1u << 31));
  ASSERT_FALSE(execution_halted());

}

void
test_can_mailbox_transmit_request(void)
{
  // scope=self.reg='mailboxes[0].TIR', self.shift=0, self.mask=None, self.varsmap={'mailbox': 'CAN_MAILBOX0'}, self.value=1, self.ifdef=[], self.halt=False
  _CAN->mailboxes[0].TIR = 0;
  can_mailbox_transmit_request(_CAN, CAN_MAILBOX0);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TIR = ~(0u << 0);
  can_mailbox_transmit_request(_CAN, CAN_MAILBOX0);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='mailboxes[1].TIR', self.shift=0, self.mask=None, self.varsmap={'mailbox': 'CAN_MAILBOX1'}, self.value=1, self.ifdef=[], self.halt=False
  _CAN->mailboxes[1].TIR = 0;
  can_mailbox_transmit_request(_CAN, CAN_MAILBOX1);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TIR = ~(0u << 0);
  can_mailbox_transmit_request(_CAN, CAN_MAILBOX1);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='mailboxes[2].TIR', self.shift=0, self.mask=None, self.varsmap={'mailbox': 'CAN_MAILBOX2'}, self.value=1, self.ifdef=[], self.halt=False
  _CAN->mailboxes[2].TIR = 0;
  can_mailbox_transmit_request(_CAN, CAN_MAILBOX2);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TIR = ~(0u << 0);
  can_mailbox_transmit_request(_CAN, CAN_MAILBOX2);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_can_tx_fifo_transmit(void)
{
#if defined(bar)
  _CAN->mailboxes[0].TIR = 0;
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX0, CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TIR = ~(1u << 1);
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX0, CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TIR = (1u << 1);
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX0, CAN_REMOTE_TRANSMISSION_REQUEST_DATA);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TIR = 0xffffffff;
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX0, CAN_REMOTE_TRANSMISSION_REQUEST_DATA);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(buzz)
  _CAN->mailboxes[1].TIR = 0;
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX1, CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TIR = ~(1u << 1);
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX1, CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TIR = (1u << 1);
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX1, CAN_REMOTE_TRANSMISSION_REQUEST_DATA);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TIR = 0xffffffff;
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX1, CAN_REMOTE_TRANSMISSION_REQUEST_DATA);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

#endif

  _CAN->mailboxes[2].TIR = 0;
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX2, CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TIR = ~(1u << 1);
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX2, CAN_REMOTE_TRANSMISSION_REQUEST_REMOTE);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TIR = (1u << 1);
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX2, CAN_REMOTE_TRANSMISSION_REQUEST_DATA);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TIR = 0xffffffff;
  can_tx_fifo_transmit(_CAN, CAN_MAILBOX2, CAN_REMOTE_TRANSMISSION_REQUEST_DATA);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());


}

void
test_can_set_tx_fifo_identifier_type(void)
{
  _CAN->mailboxes[0].TIR = 0;
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX0, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TIR = ~(1u << 2);
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX0, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TIR = (1u << 2);
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX0, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TIR = 0xffffffff;
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX0, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(_CAN->mailboxes[0].TIR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TIR = 0;
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX1, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TIR = ~(1u << 2);
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX1, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TIR = (1u << 2);
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX1, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TIR = 0xffffffff;
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX1, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(_CAN->mailboxes[1].TIR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TIR = 0;
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX2, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TIR = ~(1u << 2);
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX2, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TIR = (1u << 2);
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX2, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TIR = 0xffffffff;
  can_set_tx_fifo_identifier_type(_CAN, CAN_MAILBOX2, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(_CAN->mailboxes[2].TIR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());


}

// └─Skipping type 'fn_set_value (TODO)' (can_set_tx_fifo_identifier)
void
test_can_set_data_length(void)
{
  _CAN->mailboxes[0].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[0].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX0, 0xf);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0xfu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX0, 0xf);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, ~(0xfu << 0) | (0xfu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[0].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX0, 0x10);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0x10u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->mailboxes[0].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX0, 0x10);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, ~(0xfu << 0) | (0x10u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->mailboxes[1].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX1, 0xf);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0xfu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX1, 0xf);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, ~(0xfu << 0) | (0xfu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX1, 0x10);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0x10u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->mailboxes[1].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX1, 0x10);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, ~(0xfu << 0) | (0x10u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->mailboxes[2].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX2, 0xf);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0xfu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX2, 0xf);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, ~(0xfu << 0) | (0xfu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDTR = 0;
  can_set_data_length(_CAN, CAN_MAILBOX2, 0x10);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0x10u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->mailboxes[2].TDTR = 0xffffffff;
  can_set_data_length(_CAN, CAN_MAILBOX2, 0x10);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, ~(0xfu << 0) | (0x10u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_transmit_global_time(void)
{
  _CAN->mailboxes[0].TDTR = 0;
  can_transmit_global_time_enable(_CAN, CAN_MAILBOX0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDTR = ~(1u << 8);
  can_transmit_global_time_enable(_CAN, CAN_MAILBOX0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDTR = (1u << 8);
  can_transmit_global_time_disable(_CAN, CAN_MAILBOX0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDTR = 0xffffffff;
  can_transmit_global_time_disable(_CAN, CAN_MAILBOX0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDTR = 0;
  can_transmit_global_time_enable(_CAN, CAN_MAILBOX1);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDTR = ~(1u << 8);
  can_transmit_global_time_enable(_CAN, CAN_MAILBOX1);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDTR = (1u << 8);
  can_transmit_global_time_disable(_CAN, CAN_MAILBOX1);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDTR = 0xffffffff;
  can_transmit_global_time_disable(_CAN, CAN_MAILBOX1);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDTR = 0;
  can_transmit_global_time_enable(_CAN, CAN_MAILBOX2);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDTR = ~(1u << 8);
  can_transmit_global_time_enable(_CAN, CAN_MAILBOX2);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDTR = (1u << 8);
  can_transmit_global_time_disable(_CAN, CAN_MAILBOX2);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDTR = 0xffffffff;
  can_transmit_global_time_disable(_CAN, CAN_MAILBOX2);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_can_set_message_timestamp(void)
{
  _CAN->mailboxes[0].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, ~(0xffffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[0].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX0, 0xffff);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0xffffu << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX0, 0xffff);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, ~(0xffffu << 16) | (0xffffu << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[0].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX0, 0x10000);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, 0x10000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->mailboxes[0].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX0, 0x10000);
  ASSERT_EQ(_CAN->mailboxes[0].TDTR, ~(0xffffu << 16) | (0x10000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->mailboxes[1].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, ~(0xffffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX1, 0xffff);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0xffffu << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX1, 0xffff);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, ~(0xffffu << 16) | (0xffffu << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX1, 0x10000);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, 0x10000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->mailboxes[1].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX1, 0x10000);
  ASSERT_EQ(_CAN->mailboxes[1].TDTR, ~(0xffffu << 16) | (0x10000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  _CAN->mailboxes[2].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0u << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, ~(0xffffu << 16) | (0u << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX2, 0xffff);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0xffffu << 16);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX2, 0xffff);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, ~(0xffffu << 16) | (0xffffu << 16));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDTR = 0;
  can_set_message_timestamp(_CAN, CAN_MAILBOX2, 0x10000);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, 0x10000u << 16);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->mailboxes[2].TDTR = 0xffffffff;
  can_set_message_timestamp(_CAN, CAN_MAILBOX2, 0x10000);
  ASSERT_EQ(_CAN->mailboxes[2].TDTR, ~(0xffffu << 16) | (0x10000u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_set_message_data_low(void)
{
  _CAN->mailboxes[0].TDLR = 0;
  can_set_message_data_low(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDLR = 0xffffffff;
  can_set_message_data_low(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDLR, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[0].TDLR = 0;
  can_set_message_data_low(_CAN, CAN_MAILBOX0, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[0].TDLR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDLR = 0xffffffff;
  can_set_message_data_low(_CAN, CAN_MAILBOX0, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[0].TDLR, ~(0xffffffffu << 0) | (0xffffffffu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDLR = 0;
  can_set_message_data_low(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDLR = 0xffffffff;
  can_set_message_data_low(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDLR, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDLR = 0;
  can_set_message_data_low(_CAN, CAN_MAILBOX1, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[1].TDLR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDLR = 0xffffffff;
  can_set_message_data_low(_CAN, CAN_MAILBOX1, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[1].TDLR, ~(0xffffffffu << 0) | (0xffffffffu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDLR = 0;
  can_set_message_data_low(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDLR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDLR = 0xffffffff;
  can_set_message_data_low(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDLR, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDLR = 0;
  can_set_message_data_low(_CAN, CAN_MAILBOX2, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[2].TDLR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDLR = 0xffffffff;
  can_set_message_data_low(_CAN, CAN_MAILBOX2, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[2].TDLR, ~(0xffffffffu << 0) | (0xffffffffu << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_can_set_message_data_high(void)
{
  _CAN->mailboxes[0].TDHR = 0;
  can_set_message_data_high(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDHR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDHR = 0xffffffff;
  can_set_message_data_high(_CAN, CAN_MAILBOX0, 0);
  ASSERT_EQ(_CAN->mailboxes[0].TDHR, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[0].TDHR = 0;
  can_set_message_data_high(_CAN, CAN_MAILBOX0, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[0].TDHR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[0].TDHR = 0xffffffff;
  can_set_message_data_high(_CAN, CAN_MAILBOX0, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[0].TDHR, ~(0xffffffffu << 0) | (0xffffffffu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDHR = 0;
  can_set_message_data_high(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDHR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDHR = 0xffffffff;
  can_set_message_data_high(_CAN, CAN_MAILBOX1, 0);
  ASSERT_EQ(_CAN->mailboxes[1].TDHR, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[1].TDHR = 0;
  can_set_message_data_high(_CAN, CAN_MAILBOX1, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[1].TDHR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[1].TDHR = 0xffffffff;
  can_set_message_data_high(_CAN, CAN_MAILBOX1, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[1].TDHR, ~(0xffffffffu << 0) | (0xffffffffu << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDHR = 0;
  can_set_message_data_high(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDHR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDHR = 0xffffffff;
  can_set_message_data_high(_CAN, CAN_MAILBOX2, 0);
  ASSERT_EQ(_CAN->mailboxes[2].TDHR, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  _CAN->mailboxes[2].TDHR = 0;
  can_set_message_data_high(_CAN, CAN_MAILBOX2, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[2].TDHR, 0xffffffffu << 0);
  ASSERT_FALSE(execution_halted());

  _CAN->mailboxes[2].TDHR = 0xffffffff;
  can_set_message_data_high(_CAN, CAN_MAILBOX2, 0xffffffff);
  ASSERT_EQ(_CAN->mailboxes[2].TDHR, ~(0xffffffffu << 0) | (0xffffffffu << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_transmit(void)
{
  u32 res;

  // read_bit
  _CAN->recv[0].RIR = 0;
  res = can_get_rx_fifo_transmit(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = ~(0x1u << 1);
  res = can_get_rx_fifo_transmit(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = 0x1u << 1;
  res = can_get_rx_fifo_transmit(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0x1u << 1);
  ASSERT_FALSE(execution_halted());


  // read_bit
  _CAN->recv[1].RIR = 0;
  res = can_get_rx_fifo_transmit(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = ~(0x1u << 1);
  res = can_get_rx_fifo_transmit(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = 0x1u << 1;
  res = can_get_rx_fifo_transmit(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0x1u << 1);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_identifier_type(void)
{
  u32 res;

  // read_bit
  _CAN->recv[0].RIR = 0;
  res = can_get_rx_fifo_identifier_type(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = ~(0x1u << 2);
  res = can_get_rx_fifo_identifier_type(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = 0x1u << 2;
  res = can_get_rx_fifo_identifier_type(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());


  // read_bit
  _CAN->recv[1].RIR = 0;
  res = can_get_rx_fifo_identifier_type(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = ~(0x1u << 2);
  res = can_get_rx_fifo_identifier_type(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = 0x1u << 2;
  res = can_get_rx_fifo_identifier_type(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0x1u << 2);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_identifier(void)
{
  u32 res;

  // read_bits
  _CAN->recv[0].RIR = 0;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO0, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = ~(0x7ffu << 21);
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO0, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = 0x7ffu << 21;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO0, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(res, 0x7ff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  _CAN->recv[0].RIR = 0;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO0, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = ~(0x1fffffffu << 3);
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO0, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RIR = 0x1fffffffu << 3;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO0, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(res, 0x1fffffff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  _CAN->recv[1].RIR = 0;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO1, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = ~(0x7ffu << 21);
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO1, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = 0x7ffu << 21;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO1, CAN_IDENTIFIER_TYPE_STANDARD);
  ASSERT_EQ(res, 0x7ff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  _CAN->recv[1].RIR = 0;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO1, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = ~(0x1fffffffu << 3);
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO1, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RIR = 0x1fffffffu << 3;
  res = can_get_rx_fifo_identifier(_CAN, CAN_FIFO1, CAN_IDENTIFIER_TYPE_EXTENDED);
  ASSERT_EQ(res, 0x1fffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_data_length(void)
{
  u32 res;

  // read_bits
  _CAN->recv[0].RDTR = 0;
  res = can_get_rx_fifo_data_length(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDTR = ~(0xfu << 0);
  res = can_get_rx_fifo_data_length(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDTR = 0xfu << 0;
  res = can_get_rx_fifo_data_length(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0xf);
  ASSERT_FALSE(execution_halted());


  // read_bits
  _CAN->recv[1].RDTR = 0;
  res = can_get_rx_fifo_data_length(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDTR = ~(0xfu << 0);
  res = can_get_rx_fifo_data_length(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDTR = 0xfu << 0;
  res = can_get_rx_fifo_data_length(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0xf);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_filter_match_index(void)
{
  u32 res;

  // read_bits
  _CAN->recv[0].RDTR = 0;
  res = can_get_rx_fifo_filter_match_index(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDTR = ~(0xffu << 8);
  res = can_get_rx_fifo_filter_match_index(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDTR = 0xffu << 8;
  res = can_get_rx_fifo_filter_match_index(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  _CAN->recv[1].RDTR = 0;
  res = can_get_rx_fifo_filter_match_index(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDTR = ~(0xffu << 8);
  res = can_get_rx_fifo_filter_match_index(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDTR = 0xffu << 8;
  res = can_get_rx_fifo_filter_match_index(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0xff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_message_timestamp(void)
{
  u32 res;

  // read_bits
  _CAN->recv[0].RDTR = 0;
  res = can_get_rx_fifo_message_timestamp(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDTR = ~(0xffffu << 16);
  res = can_get_rx_fifo_message_timestamp(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDTR = 0xffffu << 16;
  res = can_get_rx_fifo_message_timestamp(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0xffff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  _CAN->recv[1].RDTR = 0;
  res = can_get_rx_fifo_message_timestamp(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDTR = ~(0xffffu << 16);
  res = can_get_rx_fifo_message_timestamp(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDTR = 0xffffu << 16;
  res = can_get_rx_fifo_message_timestamp(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0xffff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_message_data_low(void)
{
  u32 res;

  // read_reg
  _CAN->recv[0].RDLR = 0;
  res = can_get_rx_fifo_message_data_low(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDLR = 0xffffffff;
  res = can_get_rx_fifo_message_data_low(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  _CAN->recv[1].RDLR = 0;
  res = can_get_rx_fifo_message_data_low(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDLR = 0xffffffff;
  res = can_get_rx_fifo_message_data_low(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_get_rx_fifo_message_data_high(void)
{
  u32 res;

  // read_reg
  _CAN->recv[0].RDHR = 0;
  res = can_get_rx_fifo_message_data_high(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[0].RDHR = 0xffffffff;
  res = can_get_rx_fifo_message_data_high(_CAN, CAN_FIFO0);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_reg
  _CAN->recv[1].RDHR = 0;
  res = can_get_rx_fifo_message_data_high(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->recv[1].RDHR = 0xffffffff;
  res = can_get_rx_fifo_message_data_high(_CAN, CAN_FIFO1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_can_set_filter_banks_mode(void)
{
  _CAN->FMR = 0;
  can_set_filter_banks_mode(_CAN, CAN_FILTER_BANKS_MODE_INIT);
  ASSERT_EQ(_CAN->FMR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FMR = ~(1u << 0);
  can_set_filter_banks_mode(_CAN, CAN_FILTER_BANKS_MODE_INIT);
  ASSERT_EQ(_CAN->FMR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FMR = (1u << 0);
  can_set_filter_banks_mode(_CAN, CAN_FILTER_BANKS_MODE_ACTIVE);
  ASSERT_EQ(_CAN->FMR, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FMR = 0xffffffff;
  can_set_filter_banks_mode(_CAN, CAN_FILTER_BANKS_MODE_ACTIVE);
  ASSERT_EQ(_CAN->FMR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_start_bank(void)
{
  _CAN->FMR = 0;
  can_set_start_bank(_CAN, 0);
  ASSERT_EQ(_CAN->FMR, 0u << 8);
  ASSERT_FALSE(execution_halted());

  _CAN->FMR = 0xffffffff;
  can_set_start_bank(_CAN, 0);
  ASSERT_EQ(_CAN->FMR, ~(0x3fu << 8) | (0u << 8));
  ASSERT_FALSE(execution_halted());


  _CAN->FMR = 0;
  can_set_start_bank(_CAN, 0x3f);
  ASSERT_EQ(_CAN->FMR, 0x3fu << 8);
  ASSERT_FALSE(execution_halted());

  _CAN->FMR = 0xffffffff;
  can_set_start_bank(_CAN, 0x3f);
  ASSERT_EQ(_CAN->FMR, ~(0x3fu << 8) | (0x3fu << 8));
  ASSERT_FALSE(execution_halted());


  _CAN->FMR = 0;
  can_set_start_bank(_CAN, 0x40);
  ASSERT_EQ(_CAN->FMR, 0x40u << 8);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  _CAN->FMR = 0xffffffff;
  can_set_start_bank(_CAN, 0x40);
  ASSERT_EQ(_CAN->FMR, ~(0x3fu << 8) | (0x40u << 8));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_can_set_filter_mode(void)
{
  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 0, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 0);
  can_set_filter_mode(_CAN, 0, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 0, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 0, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 1, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 1);
  can_set_filter_mode(_CAN, 1, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 1, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 1, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 2, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 2);
  can_set_filter_mode(_CAN, 2, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 2, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 2, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 3, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 3);
  can_set_filter_mode(_CAN, 3, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 3, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 3, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 4, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 4);
  can_set_filter_mode(_CAN, 4, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 4, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 4, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 5, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 5);
  can_set_filter_mode(_CAN, 5, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 5, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 5, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 6, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 6);
  can_set_filter_mode(_CAN, 6, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 6, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 6, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 7, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 7);
  can_set_filter_mode(_CAN, 7, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 7, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 7, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 8, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 8);
  can_set_filter_mode(_CAN, 8, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 8, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 8, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 9, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 9);
  can_set_filter_mode(_CAN, 9, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 9, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 9, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 10, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 10);
  can_set_filter_mode(_CAN, 10, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 10, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 10, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 11, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 11);
  can_set_filter_mode(_CAN, 11, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 11, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 11, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 12, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 12);
  can_set_filter_mode(_CAN, 12, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 12, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 12, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 13, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 13);
  can_set_filter_mode(_CAN, 13, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 13, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 13, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 14, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 14);
  can_set_filter_mode(_CAN, 14, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 14, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 14, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 15, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 15);
  can_set_filter_mode(_CAN, 15, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 15, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 15, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 16, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 16);
  can_set_filter_mode(_CAN, 16, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 16, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 16, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 17, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 17);
  can_set_filter_mode(_CAN, 17, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 17, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 17, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 18, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 18);
  can_set_filter_mode(_CAN, 18, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 18, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 18, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 19, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 19);
  can_set_filter_mode(_CAN, 19, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 19, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 19, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 20, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 20);
  can_set_filter_mode(_CAN, 20, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 20, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 20, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 21, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 21);
  can_set_filter_mode(_CAN, 21, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 21, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 21, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 22, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 22);
  can_set_filter_mode(_CAN, 22, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 22, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 22, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 23, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 23);
  can_set_filter_mode(_CAN, 23, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 23, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 23, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 24, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 24);
  can_set_filter_mode(_CAN, 24, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 24, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 24, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 25, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 25);
  can_set_filter_mode(_CAN, 25, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 25, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 25, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 26, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = ~(1u << 26);
  can_set_filter_mode(_CAN, 26, CAN_FILTER_MODE_IDENTIFIER_LIST);
  ASSERT_EQ(_CAN->FM1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0;
  can_set_filter_mode(_CAN, 26, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FM1R = 0xffffffff;
  can_set_filter_mode(_CAN, 26, CAN_FILTER_MODE_IDENTIFIER_MASK);
  ASSERT_EQ(_CAN->FM1R, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_filter_scale(void)
{
  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 0, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 0);
  can_set_filter_scale(_CAN, 0, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 0, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 0, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 1, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 1);
  can_set_filter_scale(_CAN, 1, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 1, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 1, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 2, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 2);
  can_set_filter_scale(_CAN, 2, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 2, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 2, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 3, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 3);
  can_set_filter_scale(_CAN, 3, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 3, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 3, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 4, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 4);
  can_set_filter_scale(_CAN, 4, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 4, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 4, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 5, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 5);
  can_set_filter_scale(_CAN, 5, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 5, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 5, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 6, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 6);
  can_set_filter_scale(_CAN, 6, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 6, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 6, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 7, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 7);
  can_set_filter_scale(_CAN, 7, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 7, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 7, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 8, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 8);
  can_set_filter_scale(_CAN, 8, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 8, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 8, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 9, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 9);
  can_set_filter_scale(_CAN, 9, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 9, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 9, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 10, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 10);
  can_set_filter_scale(_CAN, 10, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 10, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 10, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 11, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 11);
  can_set_filter_scale(_CAN, 11, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 11, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 11, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 12, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 12);
  can_set_filter_scale(_CAN, 12, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 12, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 12, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 13, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 13);
  can_set_filter_scale(_CAN, 13, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 13, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 13, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 14, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 14);
  can_set_filter_scale(_CAN, 14, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 14, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 14, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 15, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 15);
  can_set_filter_scale(_CAN, 15, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 15, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 15, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 16, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 16);
  can_set_filter_scale(_CAN, 16, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 16, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 16, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 17, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 17);
  can_set_filter_scale(_CAN, 17, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 17, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 17, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 18, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 18);
  can_set_filter_scale(_CAN, 18, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 18, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 18, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 19, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 19);
  can_set_filter_scale(_CAN, 19, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 19, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 19, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 20, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 20);
  can_set_filter_scale(_CAN, 20, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 20, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 20, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 21, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 21);
  can_set_filter_scale(_CAN, 21, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 21, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 21, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 22, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 22);
  can_set_filter_scale(_CAN, 22, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 22, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 22, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 23, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 23);
  can_set_filter_scale(_CAN, 23, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 23, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 23, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 24, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 24);
  can_set_filter_scale(_CAN, 24, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 24, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 24, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 25, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 25);
  can_set_filter_scale(_CAN, 25, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 25, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 25, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 26, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = ~(1u << 26);
  can_set_filter_scale(_CAN, 26, CAN_FILTER_SCALE_SINGLE_32BITS);
  ASSERT_EQ(_CAN->FS1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0;
  can_set_filter_scale(_CAN, 26, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FS1R = 0xffffffff;
  can_set_filter_scale(_CAN, 26, CAN_FILTER_SCALE_DUAL_16BITS);
  ASSERT_EQ(_CAN->FS1R, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

}

void
test_can_set_fifo_filter_assignment(void)
{
  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 0, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 0);
  can_set_fifo_filter_assignment(_CAN, 0, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 0, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 0, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 1, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 1);
  can_set_fifo_filter_assignment(_CAN, 1, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 1, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 1, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 2, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 2);
  can_set_fifo_filter_assignment(_CAN, 2, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 2, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 2, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 3, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 3);
  can_set_fifo_filter_assignment(_CAN, 3, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 3, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 3, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 4, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 4);
  can_set_fifo_filter_assignment(_CAN, 4, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 4, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 4, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 5, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 5);
  can_set_fifo_filter_assignment(_CAN, 5, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 5, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 5, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 6, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 6);
  can_set_fifo_filter_assignment(_CAN, 6, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 6, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 6, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 7, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 7);
  can_set_fifo_filter_assignment(_CAN, 7, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 7, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 7, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 8, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 8);
  can_set_fifo_filter_assignment(_CAN, 8, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 8, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 8, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 9, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 9);
  can_set_fifo_filter_assignment(_CAN, 9, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 9, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 9, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 10, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 10);
  can_set_fifo_filter_assignment(_CAN, 10, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 10, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 10, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 11, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 11);
  can_set_fifo_filter_assignment(_CAN, 11, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 11, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 11, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 12, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 12);
  can_set_fifo_filter_assignment(_CAN, 12, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 12, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 12, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 13, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 13);
  can_set_fifo_filter_assignment(_CAN, 13, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 13, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 13, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 14, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 14);
  can_set_fifo_filter_assignment(_CAN, 14, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 14, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 14, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 15, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 15);
  can_set_fifo_filter_assignment(_CAN, 15, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 15, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 15, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 16, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 16);
  can_set_fifo_filter_assignment(_CAN, 16, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 16, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 16, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 17, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 17);
  can_set_fifo_filter_assignment(_CAN, 17, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 17, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 17, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 18, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 18);
  can_set_fifo_filter_assignment(_CAN, 18, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 18, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 18, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 19, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 19);
  can_set_fifo_filter_assignment(_CAN, 19, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 19, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 19, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 20, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 20);
  can_set_fifo_filter_assignment(_CAN, 20, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 20, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 20, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 21, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 21);
  can_set_fifo_filter_assignment(_CAN, 21, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 21, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 21, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 22, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 22);
  can_set_fifo_filter_assignment(_CAN, 22, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 22, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 22, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 23, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 23);
  can_set_fifo_filter_assignment(_CAN, 23, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 23, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 23, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 24, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 24);
  can_set_fifo_filter_assignment(_CAN, 24, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 24, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 24, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 25, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 25);
  can_set_fifo_filter_assignment(_CAN, 25, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 25, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 25, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 26, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = ~(1u << 26);
  can_set_fifo_filter_assignment(_CAN, 26, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO1);
  ASSERT_EQ(_CAN->FFA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0;
  can_set_fifo_filter_assignment(_CAN, 26, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FFA1R = 0xffffffff;
  can_set_fifo_filter_assignment(_CAN, 26, CAN_FIFO_FILTER_ASSIGNEMENT_FIFO0);
  ASSERT_EQ(_CAN->FFA1R, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

}

void
test_can_filter_toggle(void)
{
  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 0);
  ASSERT_EQ(_CAN->FA1R, (1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 0);
  can_filter_enable(_CAN, 0);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 0);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 0);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 1);
  ASSERT_EQ(_CAN->FA1R, (1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 1);
  can_filter_enable(_CAN, 1);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 1);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 1);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 2);
  ASSERT_EQ(_CAN->FA1R, (1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 2);
  can_filter_enable(_CAN, 2);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 2);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 2);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 3);
  ASSERT_EQ(_CAN->FA1R, (1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 3);
  can_filter_enable(_CAN, 3);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 3);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 3);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 4);
  ASSERT_EQ(_CAN->FA1R, (1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 4);
  can_filter_enable(_CAN, 4);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 4);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 4);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 4));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 5);
  ASSERT_EQ(_CAN->FA1R, (1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 5);
  can_filter_enable(_CAN, 5);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 5);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 5);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 6);
  ASSERT_EQ(_CAN->FA1R, (1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 6);
  can_filter_enable(_CAN, 6);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 6);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 6);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 7);
  ASSERT_EQ(_CAN->FA1R, (1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 7);
  can_filter_enable(_CAN, 7);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 7);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 7);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 8);
  ASSERT_EQ(_CAN->FA1R, (1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 8);
  can_filter_enable(_CAN, 8);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 8);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 8);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 9);
  ASSERT_EQ(_CAN->FA1R, (1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 9);
  can_filter_enable(_CAN, 9);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 9);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 9);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 10);
  ASSERT_EQ(_CAN->FA1R, (1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 10);
  can_filter_enable(_CAN, 10);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 10);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 10);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 11);
  ASSERT_EQ(_CAN->FA1R, (1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 11);
  can_filter_enable(_CAN, 11);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 11);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 11);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 12);
  ASSERT_EQ(_CAN->FA1R, (1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 12);
  can_filter_enable(_CAN, 12);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 12);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 12);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 13);
  ASSERT_EQ(_CAN->FA1R, (1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 13);
  can_filter_enable(_CAN, 13);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 13);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 13);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 14);
  ASSERT_EQ(_CAN->FA1R, (1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 14);
  can_filter_enable(_CAN, 14);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 14);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 14);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 15);
  ASSERT_EQ(_CAN->FA1R, (1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 15);
  can_filter_enable(_CAN, 15);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 15);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 15);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 16);
  ASSERT_EQ(_CAN->FA1R, (1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 16);
  can_filter_enable(_CAN, 16);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 16);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 16);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 17);
  ASSERT_EQ(_CAN->FA1R, (1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 17);
  can_filter_enable(_CAN, 17);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 17);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 17);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 18);
  ASSERT_EQ(_CAN->FA1R, (1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 18);
  can_filter_enable(_CAN, 18);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 18);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 18);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 19);
  ASSERT_EQ(_CAN->FA1R, (1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 19);
  can_filter_enable(_CAN, 19);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 19);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 19);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 20);
  ASSERT_EQ(_CAN->FA1R, (1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 20);
  can_filter_enable(_CAN, 20);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 20);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 20);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 21);
  ASSERT_EQ(_CAN->FA1R, (1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 21);
  can_filter_enable(_CAN, 21);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 21);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 21);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 21));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 22);
  ASSERT_EQ(_CAN->FA1R, (1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 22);
  can_filter_enable(_CAN, 22);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 22);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 22);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 22));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 23);
  ASSERT_EQ(_CAN->FA1R, (1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 23);
  can_filter_enable(_CAN, 23);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 23);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 23);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 23));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 24);
  ASSERT_EQ(_CAN->FA1R, (1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 24);
  can_filter_enable(_CAN, 24);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 24);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 24);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 24));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 25);
  ASSERT_EQ(_CAN->FA1R, (1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 25);
  can_filter_enable(_CAN, 25);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 25);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 25);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 25));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_enable(_CAN, 26);
  ASSERT_EQ(_CAN->FA1R, (1u << 26));
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = ~(1u << 26);
  can_filter_enable(_CAN, 26);
  ASSERT_EQ(_CAN->FA1R, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0;
  can_filter_disable(_CAN, 26);
  ASSERT_EQ(_CAN->FA1R, 0);
  ASSERT_FALSE(execution_halted());

  _CAN->FA1R = 0xffffffff;
  can_filter_disable(_CAN, 26);
  ASSERT_EQ(_CAN->FA1R, ~(1u << 26));
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_can_set_hardware_mode),
    TEST_FUNC(test_can_sleep_mode),
    TEST_FUNC(test_can_set_tx_fifo_priority),
    TEST_FUNC(test_can_set_rx_fifo_locked_mode),
    TEST_FUNC(test_can_set_automatic_transmission_policy),
    TEST_FUNC(test_can_set_automatic_wakeup_mode),
    TEST_FUNC(test_can_set_automatic_bus_off),
    TEST_FUNC(test_can_time_triggered_communication),
    TEST_FUNC(test_can_software_reset),
    TEST_FUNC(test_can_set_debug_freeze),
    TEST_FUNC(test_can_is_flag_set),
    TEST_FUNC(test_can_flag_clear),
    TEST_FUNC(test_can_is_mailbox_flag_set),
    TEST_FUNC(test_can_mailbox_flag_clear),
    TEST_FUNC(test_can_get_mailbox_code),
    TEST_FUNC(test_can_get_fifo_pending_messages_count),
    TEST_FUNC(test_can_is_fifo_flag_set),
    TEST_FUNC(test_can_fifo_flag_clear),
    TEST_FUNC(test_can_fifo_release),
    TEST_FUNC(test_can_interrupt_toggle),
    TEST_FUNC(test_can_is_error_flag_set),
    TEST_FUNC(test_can_get_last_error_code),
    TEST_FUNC(test_can_last_error_code_reset),
    TEST_FUNC(test_can_get_transmit_error_counter),
    TEST_FUNC(test_can_get_receive_error_counter),
    TEST_FUNC(test_can_set_baudrate),
    TEST_FUNC(test_can_set_time_segment1),
    TEST_FUNC(test_can_set_time_segment2),
    TEST_FUNC(test_can_set_resync_jump_width),
    TEST_FUNC(test_can_loopback_mode),
    TEST_FUNC(test_can_silent_mode),
    TEST_FUNC(test_can_mailbox_transmit_request),
    TEST_FUNC(test_can_tx_fifo_transmit),
    TEST_FUNC(test_can_set_tx_fifo_identifier_type),
    TEST_FUNC(test_can_set_data_length),
    TEST_FUNC(test_can_transmit_global_time),
    TEST_FUNC(test_can_set_message_timestamp),
    TEST_FUNC(test_can_set_message_data_low),
    TEST_FUNC(test_can_set_message_data_high),
    TEST_FUNC(test_can_get_rx_fifo_transmit),
    TEST_FUNC(test_can_get_rx_fifo_identifier_type),
    TEST_FUNC(test_can_get_rx_fifo_identifier),
    TEST_FUNC(test_can_get_rx_fifo_data_length),
    TEST_FUNC(test_can_get_rx_fifo_filter_match_index),
    TEST_FUNC(test_can_get_rx_fifo_message_timestamp),
    TEST_FUNC(test_can_get_rx_fifo_message_data_low),
    TEST_FUNC(test_can_get_rx_fifo_message_data_high),
    TEST_FUNC(test_can_set_filter_banks_mode),
    TEST_FUNC(test_can_set_start_bank),
    TEST_FUNC(test_can_set_filter_mode),
    TEST_FUNC(test_can_set_filter_scale),
    TEST_FUNC(test_can_set_fifo_filter_assignment),
    TEST_FUNC(test_can_filter_toggle),
  };

  return TESTS_RUN(tests);
}
