#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/sdio/sdio_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  SDIO = (struct sdio_registers_map*) membuf;
}

void
test_sdio_power(void)
{
  SDIO->POWER = 0;
  sdio_power_on();
  ASSERT_EQ(SDIO->POWER, (0b11u << 0));
  ASSERT_FALSE(execution_halted());

  SDIO->POWER = ~(0b11u << 0);
  sdio_power_on();
  ASSERT_EQ(SDIO->POWER, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->POWER = (0b11u << 0);
  sdio_power_off();
  ASSERT_EQ(SDIO->POWER, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->POWER = 0xffffffff;
  sdio_power_off();
  ASSERT_EQ(SDIO->POWER, ~(0b11u << 0));
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_set_clock_divide_factor(void)
{
  SDIO->CLKCR = 0;
  sdio_set_clock_divide_factor(0);
  ASSERT_EQ(SDIO->CLKCR, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = 0xffffffff;
  sdio_set_clock_divide_factor(0);
  ASSERT_EQ(SDIO->CLKCR, ~(0xffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  SDIO->CLKCR = 0;
  sdio_set_clock_divide_factor(0xff);
  ASSERT_EQ(SDIO->CLKCR, 0xffu << 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = 0xffffffff;
  sdio_set_clock_divide_factor(0xff);
  ASSERT_EQ(SDIO->CLKCR, ~(0xffu << 0) | (0xffu << 0));
  ASSERT_FALSE(execution_halted());


  SDIO->CLKCR = 0;
  sdio_set_clock_divide_factor(0x100);
  ASSERT_EQ(SDIO->CLKCR, 0x100u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->CLKCR = 0xffffffff;
  sdio_set_clock_divide_factor(0x100);
  ASSERT_EQ(SDIO->CLKCR, ~(0xffu << 0) | (0x100u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_sdio_clock_config(void)
{
  SDIO->CLKCR = 0;
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_ENABLE);
  ASSERT_EQ(SDIO->CLKCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(1u << 8);
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_ENABLE);
  ASSERT_EQ(SDIO->CLKCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = (1u << 8);
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_ENABLE);
  ASSERT_EQ(SDIO->CLKCR, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = 0xffffffff;
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_ENABLE);
  ASSERT_EQ(SDIO->CLKCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  SDIO->CLKCR = 0;
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_POWER_SAVING);
  ASSERT_EQ(SDIO->CLKCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(1u << 9);
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_POWER_SAVING);
  ASSERT_EQ(SDIO->CLKCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = (1u << 9);
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_POWER_SAVING);
  ASSERT_EQ(SDIO->CLKCR, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = 0xffffffff;
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_POWER_SAVING);
  ASSERT_EQ(SDIO->CLKCR, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  SDIO->CLKCR = 0;
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_CLOCK_DIVIDER_BYPASS);
  ASSERT_EQ(SDIO->CLKCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(1u << 10);
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_CLOCK_DIVIDER_BYPASS);
  ASSERT_EQ(SDIO->CLKCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = (1u << 10);
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_CLOCK_DIVIDER_BYPASS);
  ASSERT_EQ(SDIO->CLKCR, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = 0xffffffff;
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_CLOCK_DIVIDER_BYPASS);
  ASSERT_EQ(SDIO->CLKCR, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  SDIO->CLKCR = 0;
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_HARDWARE_FLOW);
  ASSERT_EQ(SDIO->CLKCR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(1u << 14);
  sdio_clock_config_enable(SDIO_CLOCK_CONFIG_HARDWARE_FLOW);
  ASSERT_EQ(SDIO->CLKCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = (1u << 14);
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_HARDWARE_FLOW);
  ASSERT_EQ(SDIO->CLKCR, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = 0xffffffff;
  sdio_clock_config_disable(SDIO_CLOCK_CONFIG_HARDWARE_FLOW);
  ASSERT_EQ(SDIO->CLKCR, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_set_widebus_mode(void)
{
  // scope=self.reg='CLKCR', self.shift=11, self.mask='0x3', self.varsmap={'mode': 'SDIO_WIDEBUS_MODE_DEFAULT'}, self.value='0b00', self.ifdef=[], self.halt=False
  SDIO->CLKCR = 0;
  sdio_set_widebus_mode(SDIO_WIDEBUS_MODE_DEFAULT);
  ASSERT_EQ(SDIO->CLKCR, (0b00u << 11));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(0x3u << 11);
  sdio_set_widebus_mode(SDIO_WIDEBUS_MODE_DEFAULT);
  ASSERT_EQ(SDIO->CLKCR, ~(0x3u << 11) | (0b00u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CLKCR', self.shift=11, self.mask='0x3', self.varsmap={'mode': 'SDIO_WIDEBUS_MODE_4WIDE'}, self.value='0b01', self.ifdef=[], self.halt=False
  SDIO->CLKCR = 0;
  sdio_set_widebus_mode(SDIO_WIDEBUS_MODE_4WIDE);
  ASSERT_EQ(SDIO->CLKCR, (0b01u << 11));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(0x3u << 11);
  sdio_set_widebus_mode(SDIO_WIDEBUS_MODE_4WIDE);
  ASSERT_EQ(SDIO->CLKCR, ~(0x3u << 11) | (0b01u << 11));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CLKCR', self.shift=11, self.mask='0x3', self.varsmap={'mode': 'SDIO_WIDEBUS_MODE_8WIDE'}, self.value='0b10', self.ifdef=[], self.halt=False
  SDIO->CLKCR = 0;
  sdio_set_widebus_mode(SDIO_WIDEBUS_MODE_8WIDE);
  ASSERT_EQ(SDIO->CLKCR, (0b10u << 11));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(0x3u << 11);
  sdio_set_widebus_mode(SDIO_WIDEBUS_MODE_8WIDE);
  ASSERT_EQ(SDIO->CLKCR, ~(0x3u << 11) | (0b10u << 11));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_set_clock_edge(void)
{
  SDIO->CLKCR = 0;
  sdio_set_clock_edge(SDIO_CLOCK_EDGE_FALLING);
  ASSERT_EQ(SDIO->CLKCR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = ~(1u << 13);
  sdio_set_clock_edge(SDIO_CLOCK_EDGE_FALLING);
  ASSERT_EQ(SDIO->CLKCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = (1u << 13);
  sdio_set_clock_edge(SDIO_CLOCK_EDGE_RISING);
  ASSERT_EQ(SDIO->CLKCR, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CLKCR = 0xffffffff;
  sdio_set_clock_edge(SDIO_CLOCK_EDGE_RISING);
  ASSERT_EQ(SDIO->CLKCR, 0xffffffff & ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_set_cmd_arg(void)
{
  SDIO->ARG = 0;
  sdio_set_cmd_arg(0);
  ASSERT_EQ(SDIO->ARG, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SDIO->ARG = 0xffffffff;
  sdio_set_cmd_arg(0);
  ASSERT_EQ(SDIO->ARG, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_set_cmd(void)
{
  SDIO->CMD = 0;
  sdio_set_cmd(0);
  ASSERT_EQ(SDIO->CMD, 0u << 0);
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_set_response_type(void)
{
  // scope=self.reg='CMD', self.shift=6, self.mask='0x3', self.varsmap={'type': 'SDIO_RESPONSE_NO_RESPONSE'}, self.value='0b00', self.ifdef=[], self.halt=False
  SDIO->CMD = 0;
  sdio_set_response_type(SDIO_RESPONSE_NO_RESPONSE);
  ASSERT_EQ(SDIO->CMD, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(0x3u << 6);
  sdio_set_response_type(SDIO_RESPONSE_NO_RESPONSE);
  ASSERT_EQ(SDIO->CMD, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CMD', self.shift=6, self.mask='0x3', self.varsmap={'type': 'SDIO_RESPONSE_TYPE_SHORT'}, self.value='0b01', self.ifdef=[], self.halt=False
  SDIO->CMD = 0;
  sdio_set_response_type(SDIO_RESPONSE_TYPE_SHORT);
  ASSERT_EQ(SDIO->CMD, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(0x3u << 6);
  sdio_set_response_type(SDIO_RESPONSE_TYPE_SHORT);
  ASSERT_EQ(SDIO->CMD, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='CMD', self.shift=6, self.mask='0x3', self.varsmap={'type': 'SDIO_RESPONSE_TYPE_LONG'}, self.value='0b11', self.ifdef=[], self.halt=False
  SDIO->CMD = 0;
  sdio_set_response_type(SDIO_RESPONSE_TYPE_LONG);
  ASSERT_EQ(SDIO->CMD, (0b11u << 6));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(0x3u << 6);
  sdio_set_response_type(SDIO_RESPONSE_TYPE_LONG);
  ASSERT_EQ(SDIO->CMD, ~(0x3u << 6) | (0b11u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_waitint(void)
{
  SDIO->CMD = 0;
  sdio_waitint_enable();
  ASSERT_EQ(SDIO->CMD, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(1u << 8);
  sdio_waitint_enable();
  ASSERT_EQ(SDIO->CMD, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = (1u << 8);
  sdio_waitint_disable();
  ASSERT_EQ(SDIO->CMD, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = 0xffffffff;
  sdio_waitint_disable();
  ASSERT_EQ(SDIO->CMD, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_waitpending(void)
{
  SDIO->CMD = 0;
  sdio_waitpending_enable();
  ASSERT_EQ(SDIO->CMD, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(1u << 9);
  sdio_waitpending_enable();
  ASSERT_EQ(SDIO->CMD, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = (1u << 9);
  sdio_waitpending_disable();
  ASSERT_EQ(SDIO->CMD, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = 0xffffffff;
  sdio_waitpending_disable();
  ASSERT_EQ(SDIO->CMD, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_cpsm(void)
{
  SDIO->CMD = 0;
  sdio_cpsm_enable();
  ASSERT_EQ(SDIO->CMD, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(1u << 10);
  sdio_cpsm_enable();
  ASSERT_EQ(SDIO->CMD, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = (1u << 10);
  sdio_cpsm_disable();
  ASSERT_EQ(SDIO->CMD, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = 0xffffffff;
  sdio_cpsm_disable();
  ASSERT_EQ(SDIO->CMD, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_suspend(void)
{
  SDIO->CMD = 0;
  sdio_suspend_enable();
  ASSERT_EQ(SDIO->CMD, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(1u << 11);
  sdio_suspend_enable();
  ASSERT_EQ(SDIO->CMD, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = (1u << 11);
  sdio_suspend_disable();
  ASSERT_EQ(SDIO->CMD, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = 0xffffffff;
  sdio_suspend_disable();
  ASSERT_EQ(SDIO->CMD, ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}

#if defined(STM32_SDIO_CMD_COMPLETION)
void
test_sdio_cmd_completion(void)
{
  SDIO->CMD = 0;
  sdio_cmd_completion_enable();
  ASSERT_EQ(SDIO->CMD, (1u << 12));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(1u << 12);
  sdio_cmd_completion_enable();
  ASSERT_EQ(SDIO->CMD, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = (1u << 12);
  sdio_cmd_completion_disable();
  ASSERT_EQ(SDIO->CMD, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = 0xffffffff;
  sdio_cmd_completion_disable();
  ASSERT_EQ(SDIO->CMD, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SDIO_NOT_INT)
void
test_sdio_nien(void)
{
  SDIO->CMD = 0;
  sdio_nien_enable();
  ASSERT_EQ(SDIO->CMD, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(1u << 13);
  sdio_nien_enable();
  ASSERT_EQ(SDIO->CMD, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = (1u << 13);
  sdio_nien_disable();
  ASSERT_EQ(SDIO->CMD, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = 0xffffffff;
  sdio_nien_disable();
  ASSERT_EQ(SDIO->CMD, ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SDIO_CEATA_CMD)
void
test_sdio_atacmd(void)
{
  SDIO->CMD = 0;
  sdio_atacmd_enable();
  ASSERT_EQ(SDIO->CMD, (1u << 14));
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = ~(1u << 14);
  sdio_atacmd_enable();
  ASSERT_EQ(SDIO->CMD, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = (1u << 14);
  sdio_atacmd_disable();
  ASSERT_EQ(SDIO->CMD, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->CMD = 0xffffffff;
  sdio_atacmd_disable();
  ASSERT_EQ(SDIO->CMD, ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_sdio_get_response_cmdindex(void)
{
  u32 res;

  // read_bits
  SDIO->RESPCMD = 0;
  res = sdio_get_response_cmdindex();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESPCMD = ~(0x3fu << 0);
  res = sdio_get_response_cmdindex();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESPCMD = 0x3fu << 0;
  res = sdio_get_response_cmdindex();
  ASSERT_EQ(res, 0x3f);
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_get_responde_data(void)
{
  u32 res;

  // read_bits
  SDIO->RESP[SDIO_RESPONSE_REG1] = 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG1] = ~(0xffffffffu << 0);
  res = sdio_get_responde_data(SDIO_RESPONSE_REG1);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG1] = 0xffffffffu << 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG1);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  SDIO->RESP[SDIO_RESPONSE_REG2] = 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG2] = ~(0xffffffffu << 0);
  res = sdio_get_responde_data(SDIO_RESPONSE_REG2);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG2] = 0xffffffffu << 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG2);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  SDIO->RESP[SDIO_RESPONSE_REG3] = 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG3] = ~(0xffffffffu << 0);
  res = sdio_get_responde_data(SDIO_RESPONSE_REG3);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG3] = 0xffffffffu << 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG3);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  // read_bits
  SDIO->RESP[SDIO_RESPONSE_REG4] = 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG4] = ~(0xffffffffu << 0);
  res = sdio_get_responde_data(SDIO_RESPONSE_REG4);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->RESP[SDIO_RESPONSE_REG4] = 0xffffffffu << 0;
  res = sdio_get_responde_data(SDIO_RESPONSE_REG4);
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_set_data_transfer_timeout(void)
{
  SDIO->DTIMER = 0;
  sdio_set_data_transfer_timeout(0);
  ASSERT_EQ(SDIO->DTIMER, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DTIMER = 0xffffffff;
  sdio_set_data_transfer_timeout(0);
  ASSERT_EQ(SDIO->DTIMER, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_set_data_transfer_length(void)
{
  SDIO->DLEN = 0;
  sdio_set_data_transfer_length(0);
  ASSERT_EQ(SDIO->DLEN, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DLEN = 0xffffffff;
  sdio_set_data_transfer_length(0);
  ASSERT_EQ(SDIO->DLEN, ~(0x1ffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  SDIO->DLEN = 0;
  sdio_set_data_transfer_length(0x1ffffff);
  ASSERT_EQ(SDIO->DLEN, 0x1ffffffu << 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DLEN = 0xffffffff;
  sdio_set_data_transfer_length(0x1ffffff);
  ASSERT_EQ(SDIO->DLEN, ~(0x1ffffffu << 0) | (0x1ffffffu << 0));
  ASSERT_FALSE(execution_halted());


  SDIO->DLEN = 0;
  sdio_set_data_transfer_length(0x2000000);
  ASSERT_EQ(SDIO->DLEN, 0x2000000u << 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->DLEN = 0xffffffff;
  sdio_set_data_transfer_length(0x2000000);
  ASSERT_EQ(SDIO->DLEN, ~(0x1ffffffu << 0) | (0x2000000u << 0));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_sdio_data_transfer(void)
{
  SDIO->DCTRL = 0;
  sdio_data_transfer_enable();
  ASSERT_EQ(SDIO->DCTRL, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 0);
  sdio_data_transfer_enable();
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_set_data_transfer_direction(void)
{
  SDIO->DCTRL = 0;
  sdio_set_data_transfer_direction(SDIO_TRANSFER_DIRECTION_CARD_TO_CONTROLLER);
  ASSERT_EQ(SDIO->DCTRL, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 1);
  sdio_set_data_transfer_direction(SDIO_TRANSFER_DIRECTION_CARD_TO_CONTROLLER);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = (1u << 1);
  sdio_set_data_transfer_direction(SDIO_TRANSFER_DIRECTION_CONTROLLER_TO_CARD);
  ASSERT_EQ(SDIO->DCTRL, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = 0xffffffff;
  sdio_set_data_transfer_direction(SDIO_TRANSFER_DIRECTION_CONTROLLER_TO_CARD);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff & ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_set_data_transfer_mode(void)
{
  SDIO->DCTRL = 0;
  sdio_set_data_transfer_mode(SDIO_TRANSFER_MODE_STREAM);
  ASSERT_EQ(SDIO->DCTRL, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 2);
  sdio_set_data_transfer_mode(SDIO_TRANSFER_MODE_STREAM);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = (1u << 2);
  sdio_set_data_transfer_mode(SDIO_TRANSFER_MODE_BLOCK);
  ASSERT_EQ(SDIO->DCTRL, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = 0xffffffff;
  sdio_set_data_transfer_mode(SDIO_TRANSFER_MODE_BLOCK);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_control(void)
{
  SDIO->DCTRL = 0;
  sdio_control_enable(SDIO_CONTROL_DMA);
  ASSERT_EQ(SDIO->DCTRL, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 3);
  sdio_control_enable(SDIO_CONTROL_DMA);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = (1u << 3);
  sdio_control_disable(SDIO_CONTROL_DMA);
  ASSERT_EQ(SDIO->DCTRL, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = 0xffffffff;
  sdio_control_disable(SDIO_CONTROL_DMA);
  ASSERT_EQ(SDIO->DCTRL, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  SDIO->DCTRL = 0;
  sdio_control_enable(SDIO_CONTROL_READ_WAIT_START);
  ASSERT_EQ(SDIO->DCTRL, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 8);
  sdio_control_enable(SDIO_CONTROL_READ_WAIT_START);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = (1u << 8);
  sdio_control_disable(SDIO_CONTROL_READ_WAIT_START);
  ASSERT_EQ(SDIO->DCTRL, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = 0xffffffff;
  sdio_control_disable(SDIO_CONTROL_READ_WAIT_START);
  ASSERT_EQ(SDIO->DCTRL, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  SDIO->DCTRL = 0;
  sdio_control_enable(SDIO_CONTROL_READ_WAIT_STOP);
  ASSERT_EQ(SDIO->DCTRL, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 9);
  sdio_control_enable(SDIO_CONTROL_READ_WAIT_STOP);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = (1u << 9);
  sdio_control_disable(SDIO_CONTROL_READ_WAIT_STOP);
  ASSERT_EQ(SDIO->DCTRL, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = 0xffffffff;
  sdio_control_disable(SDIO_CONTROL_READ_WAIT_STOP);
  ASSERT_EQ(SDIO->DCTRL, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  SDIO->DCTRL = 0;
  sdio_control_enable(SDIO_CONTROL_READ_WAIT_MODE);
  ASSERT_EQ(SDIO->DCTRL, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 10);
  sdio_control_enable(SDIO_CONTROL_READ_WAIT_MODE);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = (1u << 10);
  sdio_control_disable(SDIO_CONTROL_READ_WAIT_MODE);
  ASSERT_EQ(SDIO->DCTRL, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = 0xffffffff;
  sdio_control_disable(SDIO_CONTROL_READ_WAIT_MODE);
  ASSERT_EQ(SDIO->DCTRL, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  SDIO->DCTRL = 0;
  sdio_control_enable(SDIO_CONTROL_SDIO_FUNCTIONS);
  ASSERT_EQ(SDIO->DCTRL, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(1u << 11);
  sdio_control_enable(SDIO_CONTROL_SDIO_FUNCTIONS);
  ASSERT_EQ(SDIO->DCTRL, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = (1u << 11);
  sdio_control_disable(SDIO_CONTROL_SDIO_FUNCTIONS);
  ASSERT_EQ(SDIO->DCTRL, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = 0xffffffff;
  sdio_control_disable(SDIO_CONTROL_SDIO_FUNCTIONS);
  ASSERT_EQ(SDIO->DCTRL, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_set_data_block_size(void)
{
  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_1BYTE'}, self.value='0b0000', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_1BYTE);
  ASSERT_EQ(SDIO->DCTRL, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_1BYTE);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_2BYTES'}, self.value='0b0001', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_2BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_2BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_4BYTES'}, self.value='0b0010', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_4BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_4BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_8BYTES'}, self.value='0b0011', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_8BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_8BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_16BYTES'}, self.value='0b0100', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_16BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_16BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_32BYTES'}, self.value='0b0101', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_32BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_32BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_64BYTES'}, self.value='0b0110', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_64BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_64BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_128BYTES'}, self.value='0b0111', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_128BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_128BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_256BYTES'}, self.value='0b1000', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_256BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_256BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_512BYTES'}, self.value='0b1001', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_512BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_512BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_1024BYTES'}, self.value='0b1010', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_1024BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_1024BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_2048BYTES'}, self.value='0b1011', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_2048BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b1011u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_2048BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b1011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_4096BYTES'}, self.value='0b1100', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_4096BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b1100u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_4096BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b1100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_8192BYTES'}, self.value='0b1101', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_8192BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b1101u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_8192BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b1101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='DCTRL', self.shift=4, self.mask='0xf', self.varsmap={'size': 'SDIO_DATA_BLOCK_SIZE_16384BYTES'}, self.value='0b1110', self.ifdef=[], self.halt=False
  SDIO->DCTRL = 0;
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_16384BYTES);
  ASSERT_EQ(SDIO->DCTRL, (0b1110u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->DCTRL = ~(0xfu << 4);
  sdio_set_data_block_size(SDIO_DATA_BLOCK_SIZE_16384BYTES);
  ASSERT_EQ(SDIO->DCTRL, ~(0xfu << 4) | (0b1110u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_get_data_transfer_bytes_left(void)
{
  u32 res;

  // read_bits
  SDIO->DCOUNT = 0;
  res = sdio_get_data_transfer_bytes_left();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCOUNT = ~(0x1ffffffu << 0);
  res = sdio_get_data_transfer_bytes_left();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->DCOUNT = 0x1ffffffu << 0;
  res = sdio_get_data_transfer_bytes_left();
  ASSERT_EQ(res, 0x1ffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_is_flag_set(void)
{
  u32 res;

  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_FAIL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 0);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_FAIL);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 0);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_FAIL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_FAIL);
  ASSERT_EQ(res, (1u << 0));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_FAIL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 1);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_FAIL);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 1);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_FAIL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_FAIL);
  ASSERT_EQ(res, (1u << 1));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 2);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TIMEOUT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 2);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TIMEOUT);
  ASSERT_EQ(res, (1u << 2));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 3);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TIMEOUT);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 3);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TIMEOUT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TIMEOUT);
  ASSERT_EQ(res, (1u << 3));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 4);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_UNDERRUN);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 4);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_UNDERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_UNDERRUN);
  ASSERT_EQ(res, (1u << 4));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 5);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_OVERRUN);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 5);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_OVERRUN);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_OVERRUN);
  ASSERT_EQ(res, (1u << 5));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 6);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_OK);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 6);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_CRC_OK);
  ASSERT_EQ(res, (1u << 6));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_SENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 7);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_SENT);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 7);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_SENT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_SENT);
  ASSERT_EQ(res, (1u << 7));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_END);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 8);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_END);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 8);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_END);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_END);
  ASSERT_EQ(res, (1u << 8));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_MISSING_START_BIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 9);
  res = sdio_is_flag_set(SDIO_FLAG_MISSING_START_BIT);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 9);
  res = sdio_is_flag_set(SDIO_FLAG_MISSING_START_BIT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_MISSING_START_BIT);
  ASSERT_EQ(res, (1u << 9));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 10);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_OK);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 10);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_OK);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_CRC_OK);
  ASSERT_EQ(res, (1u << 10));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TRANSFER_IN_PROGRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 11);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TRANSFER_IN_PROGRESS);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 11);
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TRANSFER_IN_PROGRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_CMD_TRANSFER_IN_PROGRESS);
  ASSERT_EQ(res, (1u << 11));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TRANSMIT_IN_PROGRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 12);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TRANSMIT_IN_PROGRESS);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 12);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TRANSMIT_IN_PROGRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_TRANSMIT_IN_PROGRESS);
  ASSERT_EQ(res, (1u << 12));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_RECEIVE_IN_PROGRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 13);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_RECEIVE_IN_PROGRESS);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 13);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_RECEIVE_IN_PROGRESS);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_RECEIVE_IN_PROGRESS);
  ASSERT_EQ(res, (1u << 13));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 14);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 14);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(res, (1u << 14));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_HALF_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 15);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_HALF_FULL);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 15);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_HALF_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_HALF_FULL);
  ASSERT_EQ(res, (1u << 15));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 16);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_FULL);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 16);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_FULL);
  ASSERT_EQ(res, (1u << 16));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 17);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_FULL);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 17);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_FULL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_FULL);
  ASSERT_EQ(res, (1u << 17));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 18);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_EMPTY);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 18);
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_TX_FIFO_EMPTY);
  ASSERT_EQ(res, (1u << 18));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 19);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_EMPTY);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 19);
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_EMPTY);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_RX_FIFO_EMPTY);
  ASSERT_EQ(res, (1u << 19));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_TX_FIFO);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 20);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_TX_FIFO);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 20);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_TX_FIFO);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_TX_FIFO);
  ASSERT_EQ(res, (1u << 20));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_RX_FIFO);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 21);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_RX_FIFO);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 21);
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_RX_FIFO);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_DATA_AVAILABLE_IN_RX_FIFO);
  ASSERT_EQ(res, (1u << 21));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_SDIO_INT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 22);
  res = sdio_is_flag_set(SDIO_FLAG_SDIO_INT);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 22);
  res = sdio_is_flag_set(SDIO_FLAG_SDIO_INT);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_SDIO_INT);
  ASSERT_EQ(res, (1u << 22));
  ASSERT_FALSE(execution_halted());


  SDIO->STA = 0;
  res = sdio_is_flag_set(SDIO_FLAG_CE_ATA_CMD_SIGNAL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = (1u << 23);
  res = sdio_is_flag_set(SDIO_FLAG_CE_ATA_CMD_SIGNAL);
  ASSERT_EQ(res, (1u << 23));
  ASSERT_FALSE(execution_halted());

  SDIO->STA = ~(1u << 23);
  res = sdio_is_flag_set(SDIO_FLAG_CE_ATA_CMD_SIGNAL);
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->STA = 0xffffffff;
  res = sdio_is_flag_set(SDIO_FLAG_CE_ATA_CMD_SIGNAL);
  ASSERT_EQ(res, (1u << 23));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_flag_clear(void)
{
  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_CMD_CRC_FAIL);
  ASSERT_EQ(SDIO->ICR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 0);
  sdio_flag_clear(SDIO_FLAG_CMD_CRC_FAIL);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_CRC_FAIL);
  ASSERT_EQ(SDIO->ICR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 1);
  sdio_flag_clear(SDIO_FLAG_DATA_CRC_FAIL);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_CMD_TIMEOUT);
  ASSERT_EQ(SDIO->ICR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 2);
  sdio_flag_clear(SDIO_FLAG_CMD_TIMEOUT);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_TIMEOUT);
  ASSERT_EQ(SDIO->ICR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 3);
  sdio_flag_clear(SDIO_FLAG_DATA_TIMEOUT);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->ICR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 4);
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_OVERRUN);
  ASSERT_EQ(SDIO->ICR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 5);
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_OVERRUN);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_CMD_CRC_OK);
  ASSERT_EQ(SDIO->ICR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 6);
  sdio_flag_clear(SDIO_FLAG_CMD_CRC_OK);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_CMD_SENT);
  ASSERT_EQ(SDIO->ICR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 7);
  sdio_flag_clear(SDIO_FLAG_CMD_SENT);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_END);
  ASSERT_EQ(SDIO->ICR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 8);
  sdio_flag_clear(SDIO_FLAG_DATA_END);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_MISSING_START_BIT);
  ASSERT_EQ(SDIO->ICR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 9);
  sdio_flag_clear(SDIO_FLAG_MISSING_START_BIT);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_CRC_OK);
  ASSERT_EQ(SDIO->ICR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 10);
  sdio_flag_clear(SDIO_FLAG_DATA_CRC_OK);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_CMD_TRANSFER_IN_PROGRESS);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 11);
  sdio_flag_clear(SDIO_FLAG_CMD_TRANSFER_IN_PROGRESS);
  ASSERT_EQ(SDIO->ICR, ~(1u << 11));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_TRANSMIT_IN_PROGRESS);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 12);
  sdio_flag_clear(SDIO_FLAG_DATA_TRANSMIT_IN_PROGRESS);
  ASSERT_EQ(SDIO->ICR, ~(1u << 12));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_RECEIVE_IN_PROGRESS);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 13);
  sdio_flag_clear(SDIO_FLAG_DATA_RECEIVE_IN_PROGRESS);
  ASSERT_EQ(SDIO->ICR, ~(1u << 13));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 14);
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(SDIO->ICR, ~(1u << 14));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_HALF_FULL);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 15);
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_HALF_FULL);
  ASSERT_EQ(SDIO->ICR, ~(1u << 15));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_FULL);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 16);
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_FULL);
  ASSERT_EQ(SDIO->ICR, ~(1u << 16));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_FULL);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 17);
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_FULL);
  ASSERT_EQ(SDIO->ICR, ~(1u << 17));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 18);
  sdio_flag_clear(SDIO_FLAG_TX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->ICR, ~(1u << 18));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 19);
  sdio_flag_clear(SDIO_FLAG_RX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->ICR, ~(1u << 19));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_AVAILABLE_IN_TX_FIFO);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 20);
  sdio_flag_clear(SDIO_FLAG_DATA_AVAILABLE_IN_TX_FIFO);
  ASSERT_EQ(SDIO->ICR, ~(1u << 20));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_DATA_AVAILABLE_IN_RX_FIFO);
  ASSERT_EQ(SDIO->ICR, 0);
  ASSERT_TRUE(execution_halted());
  execution_resume();

  SDIO->ICR = ~(1u << 21);
  sdio_flag_clear(SDIO_FLAG_DATA_AVAILABLE_IN_RX_FIFO);
  ASSERT_EQ(SDIO->ICR, ~(1u << 21));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_SDIO_INT);
  ASSERT_EQ(SDIO->ICR, (1u << 22));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 22);
  sdio_flag_clear(SDIO_FLAG_SDIO_INT);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


  SDIO->ICR = 0;
  sdio_flag_clear(SDIO_FLAG_CE_ATA_CMD_SIGNAL);
  ASSERT_EQ(SDIO->ICR, (1u << 23));
  ASSERT_FALSE(execution_halted());

  SDIO->ICR = ~(1u << 23);
  sdio_flag_clear(SDIO_FLAG_CE_ATA_CMD_SIGNAL);
  ASSERT_EQ(SDIO->ICR, 0xffffffff);
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_interrupt(void)
{
  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 0);
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 0);
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, ~(1u << 0));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 1);
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 1);
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_CRC_FAIL);
  ASSERT_EQ(SDIO->MASK, ~(1u << 1));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 2);
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 2);
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, ~(1u << 2));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 3);
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 3);
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_TIMEOUT);
  ASSERT_EQ(SDIO->MASK, ~(1u << 3));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 4);
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 4);
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, ~(1u << 4));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 5);
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 5);
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_UNDERRUN);
  ASSERT_EQ(SDIO->MASK, ~(1u << 5));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_RESPONSE_RECV);
  ASSERT_EQ(SDIO->MASK, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 6);
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_RESPONSE_RECV);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 6);
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_RESPONSE_RECV);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_RESPONSE_RECV);
  ASSERT_EQ(SDIO->MASK, ~(1u << 6));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_SENT);
  ASSERT_EQ(SDIO->MASK, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 7);
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_SENT);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 7);
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_SENT);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_SENT);
  ASSERT_EQ(SDIO->MASK, ~(1u << 7));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_END);
  ASSERT_EQ(SDIO->MASK, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 8);
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_END);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 8);
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_END);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_END);
  ASSERT_EQ(SDIO->MASK, ~(1u << 8));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_START_BIT_ERROR);
  ASSERT_EQ(SDIO->MASK, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 9);
  sdio_interrupt_enable(SDIO_INTERRUPT_START_BIT_ERROR);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 9);
  sdio_interrupt_disable(SDIO_INTERRUPT_START_BIT_ERROR);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_START_BIT_ERROR);
  ASSERT_EQ(SDIO->MASK, ~(1u << 9));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_BLOCK_END);
  ASSERT_EQ(SDIO->MASK, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 10);
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_BLOCK_END);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 10);
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_BLOCK_END);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_BLOCK_END);
  ASSERT_EQ(SDIO->MASK, ~(1u << 10));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_TRANSFER);
  ASSERT_EQ(SDIO->MASK, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 11);
  sdio_interrupt_enable(SDIO_INTERRUPT_CMD_TRANSFER);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 11);
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_TRANSFER);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_CMD_TRANSFER);
  ASSERT_EQ(SDIO->MASK, ~(1u << 11));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_TRANSFER);
  ASSERT_EQ(SDIO->MASK, (1u << 12));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 12);
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_TRANSFER);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 12);
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_TRANSFER);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_TRANSFER);
  ASSERT_EQ(SDIO->MASK, ~(1u << 12));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_RECV);
  ASSERT_EQ(SDIO->MASK, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 13);
  sdio_interrupt_enable(SDIO_INTERRUPT_DATA_RECV);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 13);
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_RECV);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_DATA_RECV);
  ASSERT_EQ(SDIO->MASK, ~(1u << 13));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(SDIO->MASK, (1u << 14));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 14);
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 14);
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_HALF_EMPTY);
  ASSERT_EQ(SDIO->MASK, ~(1u << 14));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_HALF_FULL);
  ASSERT_EQ(SDIO->MASK, (1u << 15));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 15);
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_HALF_FULL);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 15);
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_HALF_FULL);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_HALF_FULL);
  ASSERT_EQ(SDIO->MASK, ~(1u << 15));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, (1u << 16));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 16);
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 16);
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, ~(1u << 16));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, (1u << 17));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 17);
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 17);
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_FULL);
  ASSERT_EQ(SDIO->MASK, ~(1u << 17));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, (1u << 18));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 18);
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 18);
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, ~(1u << 18));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, (1u << 19));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 19);
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 19);
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_EMPTY);
  ASSERT_EQ(SDIO->MASK, ~(1u << 19));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, (1u << 20));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 20);
  sdio_interrupt_enable(SDIO_INTERRUPT_TX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 20);
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_TX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, ~(1u << 20));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, (1u << 21));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 21);
  sdio_interrupt_enable(SDIO_INTERRUPT_RX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 21);
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_RX_FIFO_DATA_AVAILABLE);
  ASSERT_EQ(SDIO->MASK, ~(1u << 21));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_SDIO_MODE);
  ASSERT_EQ(SDIO->MASK, (1u << 22));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 22);
  sdio_interrupt_enable(SDIO_INTERRUPT_SDIO_MODE);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 22);
  sdio_interrupt_disable(SDIO_INTERRUPT_SDIO_MODE);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_SDIO_MODE);
  ASSERT_EQ(SDIO->MASK, ~(1u << 22));
  ASSERT_FALSE(execution_halted());


  SDIO->MASK = 0;
  sdio_interrupt_enable(SDIO_INTERRUPT_CE_ATA_SIGNAL);
  ASSERT_EQ(SDIO->MASK, (1u << 23));
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = ~(1u << 23);
  sdio_interrupt_enable(SDIO_INTERRUPT_CE_ATA_SIGNAL);
  ASSERT_EQ(SDIO->MASK, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = (1u << 23);
  sdio_interrupt_disable(SDIO_INTERRUPT_CE_ATA_SIGNAL);
  ASSERT_EQ(SDIO->MASK, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->MASK = 0xffffffff;
  sdio_interrupt_disable(SDIO_INTERRUPT_CE_ATA_SIGNAL);
  ASSERT_EQ(SDIO->MASK, ~(1u << 23));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_get_words_left(void)
{
  u32 res;

  // read_bits
  SDIO->FIFOCNT = 0;
  res = sdio_get_words_left();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->FIFOCNT = ~(0xffffffu << 0);
  res = sdio_get_words_left();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->FIFOCNT = 0xffffffu << 0;
  res = sdio_get_words_left();
  ASSERT_EQ(res, 0xffffff);
  ASSERT_FALSE(execution_halted());

}

void
test_sdio_write_fifo(void)
{
  SDIO->FIFO = 0;
  sdio_write_fifo(0);
  ASSERT_EQ(SDIO->FIFO, 0u << 0);
  ASSERT_FALSE(execution_halted());

  SDIO->FIFO = 0xffffffff;
  sdio_write_fifo(0);
  ASSERT_EQ(SDIO->FIFO, ~(0xffffffffu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_sdio_read_fifo(void)
{
  u32 res;

  // read_bits
  SDIO->FIFO = 0;
  res = sdio_read_fifo();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->FIFO = ~(0xffffffffu << 0);
  res = sdio_read_fifo();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SDIO->FIFO = 0xffffffffu << 0;
  res = sdio_read_fifo();
  ASSERT_EQ(res, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_sdio_power),
    TEST_FUNC(test_sdio_set_clock_divide_factor),
    TEST_FUNC(test_sdio_clock_config),
    TEST_FUNC(test_sdio_set_widebus_mode),
    TEST_FUNC(test_sdio_set_clock_edge),
    TEST_FUNC(test_sdio_set_cmd_arg),
    TEST_FUNC(test_sdio_set_cmd),
    TEST_FUNC(test_sdio_set_response_type),
    TEST_FUNC(test_sdio_waitint),
    TEST_FUNC(test_sdio_waitpending),
    TEST_FUNC(test_sdio_cpsm),
    TEST_FUNC(test_sdio_suspend),
#if defined(STM32_SDIO_CMD_COMPLETION)
    TEST_FUNC(test_sdio_cmd_completion),
#endif
#if defined(STM32_SDIO_NOT_INT)
    TEST_FUNC(test_sdio_nien),
#endif
#if defined(STM32_SDIO_CEATA_CMD)
    TEST_FUNC(test_sdio_atacmd),
#endif
    TEST_FUNC(test_sdio_get_response_cmdindex),
    TEST_FUNC(test_sdio_get_responde_data),
    TEST_FUNC(test_sdio_set_data_transfer_timeout),
    TEST_FUNC(test_sdio_set_data_transfer_length),
    TEST_FUNC(test_sdio_data_transfer),
    TEST_FUNC(test_sdio_set_data_transfer_direction),
    TEST_FUNC(test_sdio_set_data_transfer_mode),
    TEST_FUNC(test_sdio_control),
    TEST_FUNC(test_sdio_set_data_block_size),
    TEST_FUNC(test_sdio_get_data_transfer_bytes_left),
    TEST_FUNC(test_sdio_is_flag_set),
    TEST_FUNC(test_sdio_flag_clear),
    TEST_FUNC(test_sdio_interrupt),
    TEST_FUNC(test_sdio_get_words_left),
    TEST_FUNC(test_sdio_write_fifo),
    TEST_FUNC(test_sdio_read_fifo),
  };

  return TESTS_RUN(tests);
}
