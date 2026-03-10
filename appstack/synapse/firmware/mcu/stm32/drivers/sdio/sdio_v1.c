#include "synapse/stm32/drivers/sdio/sdio_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct sdio_registers_map sdio_periph;
sdio_periph* SDIO = (sdio_periph*) (SDIO_ADDR);

void
sdio_power_on(void)
{
  SDIO->POWER |= SDIO_POWER_PWRCTRL_POWERON;
}

void
sdio_power_off(void)
{
  SDIO->POWER &= ~SDIO_POWER_PWRCTRL_POWERON;
}

void
sdio_set_clock_divide_factor(
  u32 factor
)
{
  devmode_assert_lower_or_eq(factor, SDIO_CLKCR_CLKDIV_MASK);
  
  constexpr u32 shift = SDIO_CLKCR_CLKDIV_SHIFT;
  constexpr u32 mask = SDIO_CLKCR_CLKDIV_MASK << shift;
  volatile u32* reg = &SDIO->CLKCR;
  syn_set_register_bits(reg, mask, factor << shift);
}

void
sdio_clock_config_enable(
  enum sdio_clock_config config
)
{
  volatile u32* reg = &SDIO->CLKCR;

  switch (config)
  {
    case SDIO_CLOCK_CONFIG_ENABLE:
      *reg |= SDIO_CLKCR_CLKEN;
      break;

    case SDIO_CLOCK_CONFIG_POWER_SAVING:
      *reg |= SDIO_CLKCR_PWRSAV;
      break;

    case SDIO_CLOCK_CONFIG_CLOCK_DIVIDER_BYPASS:
      *reg |= SDIO_CLKCR_BYPASS;
      break;

    case SDIO_CLOCK_CONFIG_HARDWARE_FLOW:
      *reg |= SDIO_CLKCR_HWFC_EN;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_clock_config, config);
      break;
  }
}

void
sdio_clock_config_disable(
  enum sdio_clock_config config
)
{
  volatile u32* reg = &SDIO->CLKCR;

  switch (config)
  {
    case SDIO_CLOCK_CONFIG_ENABLE:
      *reg &= ~SDIO_CLKCR_CLKEN;
      break;

    case SDIO_CLOCK_CONFIG_POWER_SAVING:
      *reg &= ~SDIO_CLKCR_PWRSAV;
      break;

    case SDIO_CLOCK_CONFIG_CLOCK_DIVIDER_BYPASS:
      *reg &= ~SDIO_CLKCR_BYPASS;
      break;

    case SDIO_CLOCK_CONFIG_HARDWARE_FLOW:
      *reg &= ~SDIO_CLKCR_HWFC_EN;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_clock_config, config);
      break;
  }
}

void
sdio_set_widebus_mode(
  enum sdio_widebus_mode mode
)
{
  volatile u32* reg = &SDIO->CLKCR;
  constexpr u32 shift = SDIO_CLKCR_WIDBUS_SHIFT;
  constexpr u32 mask = SDIO_CLKCR_WIDBUS_MASK << shift;

  switch (mode)
  {
    case SDIO_WIDEBUS_MODE_DEFAULT:
      *reg &= ~mask;
      break;

    case SDIO_WIDEBUS_MODE_4WIDE:
      syn_set_register_bits(reg, mask, SDIO_CLKCR_WIDBUS_4WIDE << shift);
      break;

    case SDIO_WIDEBUS_MODE_8WIDE:
      syn_set_register_bits(reg, mask, SDIO_CLKCR_WIDBUS_8WIDE << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sdio_widebus_mode, mode);
      break;
  }
}

void
sdio_set_clock_edge(
  enum sdio_clock_edge edge
)
{
  volatile u32* reg = &SDIO->CLKCR;
  switch (edge)
  {
    case SDIO_CLOCK_EDGE_RISING:
      *reg &= ~SDIO_CLKCR_NEGEDGE;
      break;

    case SDIO_CLOCK_EDGE_FALLING:
      *reg |= SDIO_CLKCR_NEGEDGE;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_clock_edge, edge);
      break;
  }
}

void
sdio_set_cmd_arg(
  u32 arg
)
{
  SDIO->ARG = arg;
}

void
sdio_set_cmd(
  enum sdio_command command
)
{
  volatile u32* reg = &SDIO->CMD;
  constexpr u32 shift = SDIO_CMD_CMDINDEX_SHIFT;
  constexpr u32 mask = SDIO_CMD_CMDINDEX_MASK << shift;

  switch (command)
  {
    case SDIO_COMMAND_GO_IDLE_STATE:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_GO_IDLE_STATE);
      break;

    case SDIO_COMMAND_SEND_OP_COND:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_OP_COND);
      break;

    case SDIO_COMMAND_ALL_SEND_CID:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ALL_SEND_CID);
      break;

    case SDIO_COMMAND_SEND_RELATIVE_ADDR:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_RELATIVE_ADDR);
      break;

    case SDIO_COMMAND_SET_DSR:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SET_DSR);
      break;

    case SDIO_COMMAND_SWITCH_FUNC:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SWITCH_FUNC);
      break;

    case SDIO_COMMAND_SELECT_DESELECT_CARD:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SELECT_DESELECT_CARD);
      break;

    case SDIO_COMMAND_SEND_IF_COND:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_IF_COND);
      break;

    case SDIO_COMMAND_SEND_CSD:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_CSD);
      break;

    case SDIO_COMMAND_SEND_CID:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_CID);
      break;

    case SDIO_COMMAND_VOLTAGE_SWITCH:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_VOLTAGE_SWITCH);
      break;

    case SDIO_COMMAND_STOP_TRANSMISSION:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_STOP_TRANSMISSION);
      break;

    case SDIO_COMMAND_SEND_STATUS:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_STATUS);
      break;

    case SDIO_COMMAND_GO_INACTIVE_STATE:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_GO_INACTIVE_STATE);
      break;

    // Basic Commands
    case SDIO_COMMAND_SET_BLOCKLEN:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SET_BLOCKLEN);
      break;

    case SDIO_COMMAND_READ_SINGLE_BLOCK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_READ_SINGLE_BLOCK);
      break;

    case SDIO_COMMAND_READ_MULTIPLE_BLOCK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_READ_MULTIPLE_BLOCK);
      break;

    case SDIO_COMMAND_SEND_TUNING_BLOCK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_TUNING_BLOCK);
      break;

    case SDIO_COMMAND_SPEED_CLASS_CONTROL:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SPEED_CLASS_CONTROL);
      break;

    case SDIO_COMMAND_ADDRESS_EXTENSION:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ADDRESS_EXTENSION);
      break;

    case SDIO_COMMAND_SET_BLOCK_COUNT:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SET_BLOCK_COUNT);
      break;

    // Block-Oriented Read Commands
    case SDIO_COMMAND_WRITE_BLOCK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_WRITE_BLOCK);
      break;

    case SDIO_COMMAND_WRITE_MULTIPLE_BLOCK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_WRITE_MULTIPLE_BLOCK);
      break;

    case SDIO_COMMAND_PROGRAM_CSD:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_PROGRAM_CSD);
      break;

    // Block-Oriented Write Commands
    case SDIO_COMMAND_SET_WRITE_PROT:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SET_WRITE_PROT);
      break;

    case SDIO_COMMAND_CLR_WRITE_PROT:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_CLR_WRITE_PROT);
      break;

    case SDIO_COMMAND_SEND_WRITE_PROT:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SEND_WRITE_PROT);
      break;

    case SDIO_COMMAND_ERASE_WR_BLK_START:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ERASE_WR_BLK_START);
      break;

    case SDIO_COMMAND_ERASE_WR_BLK_END:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ERASE_WR_BLK_END);
      break;

    case SDIO_COMMAND_ERASE:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ERASE);
      break;

    // Erase Commands
    case SDIO_COMMAND_LOCK_UNLOCK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_LOCK_UNLOCK);
      break;

    case SDIO_COMMAND_APP_CMD:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_APP_CMD);
      break;

    case SDIO_COMMAND_GEN_CMD:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_GEN_CMD);
      break;

    // I/O Commands
    case SDIO_COMMAND_SET_BUS_WIDTH:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SET_BUS_WIDTH);
      break;

    case SDIO_COMMAND_SD_STATUS:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SD_STATUS);
      break;

    case SDIO_COMMAND_SEND_NUM_WR_BLOCKS:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SEND_NUM_WR_BLOCKS);
      break;

    case SDIO_COMMAND_SET_WR_BLK_ERASE_COUNT:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SET_WR_BLK_ERASE_COUNT);
      break;

    case SDIO_COMMAND_SD_SEND_OP_COND:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SD_SEND_OP_COND);
      break;

    case SDIO_COMMAND_SET_CLR_CARD_DETECT:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SET_CLR_CARD_DETECT);
      break;

    case SDIO_COMMAND_SEND_SCR:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SEND_SCR);
      break;

    case SDIO_COMMAND_SECURE_RECEIVE:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SECURE_RECEIVE);
      break;

    case SDIO_COMMAND_SECURE_SEND:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_ACMD_SECURE_SEND);
      break;

    // Switch Function Commands
    case SDIO_COMMAND_SELECT_CARD_PARTITION:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_SELECT_CARD_PARTITION);
      break;
      
    case SDIO_COMMAND_READ_EXTR_SINGLE:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_READ_EXTR_SINGLE);
      break;

    case SDIO_COMMAND_WRITE_EXTR_SINGLE:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_WRITE_EXTR_SINGLE);
      break;

    case SDIO_COMMAND_READ_EXTR_MULTI:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_READ_EXTR_MULTI);
      break;
      
    case SDIO_COMMAND_WRITE_EXTR_MULTI:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_WRITE_EXTR_MULTI);
      break;

    case SDIO_COMMAND_Q_MANAGEMENT:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_Q_MANAGEMENT);
      break;

    case SDIO_COMMAND_Q_TASK_INFO_A:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_Q_TASK_INFO_A);
      break;

    case SDIO_COMMAND_Q_TASK_INFO_B:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_Q_TASK_INFO_B);
      break;

    case SDIO_COMMAND_Q_RD_TASK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_Q_RD_TASK);
      break;

    case SDIO_COMMAND_Q_WR_TASK:
      syn_set_register_bits(reg, mask, SDIO_CMD_CMDINDEX_Q_WR_TASK);
      break;

    default:
      devmode_error_invalid_enum(enum sdio_command, command);
      break;
  }
}

void
sdio_set_response_type(
  enum sdio_response_type type
)
{
  volatile u32* reg = &SDIO->CMD;
  constexpr u32 shift = SDIO_CMD_WAITRESP_SHIFT;
  constexpr u32 mask = SDIO_CMD_WAITRESP_MASK << shift;

  switch (type)
  {
    case SDIO_RESPONSE_NO_RESPONSE:
      *reg &= ~mask;
      break;

    case SDIO_RESPONSE_TYPE_SHORT:
      syn_set_register_bits(reg, mask, SDIO_CMD_WAITRESP_SHORT_RESPONSE << shift);
      break;

    case SDIO_RESPONSE_TYPE_LONG:
      *reg |= (SDIO_CMD_WAITRESP_LONG_RESPONSE << shift);
      break;

    default:
      devmode_error_invalid_enum(enum sdio_response_type, type);
      break;
  }
}

void
sdio_waitint_enable(void)
{
  SDIO->CMD |= SDIO_CMD_WAITINT;
}

void
sdio_waitint_disable(void)
{
  SDIO->CMD &= ~SDIO_CMD_WAITINT;
}

void
sdio_waitpending_enable(void)
{
  SDIO->CMD |= SDIO_CMD_WAITPEND;
}

void
sdio_waitpending_disable(void)
{
  SDIO->CMD &= ~SDIO_CMD_WAITPEND;
}

void
sdio_cpsm_enable(void)
{
  SDIO->CMD |= SDIO_CMD_CPSMEN;
}

void
sdio_cpsm_disable(void)
{
  SDIO->CMD &= ~SDIO_CMD_CPSMEN;
}

void
sdio_suspend_enable(void)
{
  SDIO->CMD |= SDIO_CMD_SDIOSUSPEND;
}

void
sdio_suspend_disable(void)
{
  SDIO->CMD &= ~SDIO_CMD_SDIOSUSPEND;
}

#if defined(STM32_SDIO_CMD_COMPLETION)
void
sdio_cmd_completion_enable(void)
{
  SDIO->CMD |= SDIO_CMD_ENCMDCOMPL;
}

void
sdio_cmd_completion_disable(void)
{
  SDIO->CMD &= ~SDIO_CMD_ENCMDCOMPL;
}
#endif

#if defined(STM32_SDIO_NOT_INT)
void
sdio_nien_enable(void)
{
  SDIO->CMD |= SDIO_CMD_NIEN;
}

void
sdio_nien_disable(void)
{
  SDIO->CMD &= ~SDIO_CMD_NIEN;
}
#endif

#if defined(STM32_SDIO_CEATA_CMD)
void
sdio_atacmd_enable(void)
{
  SDIO->CMD |= SDIO_CMD_ATACMD;
}

void
sdio_atacmd_disable(void)
{
  SDIO->CMD &= ~SDIO_CMD_ATACMD;
}
#endif

u32
sdio_get_response_cmdindex(void)
{
  constexpr u32 shift = SDIO_RESPCMD_SHIFT;
  constexpr u32 mask = SDIO_RESPCMD_MASK;

  return (SDIO->RESPCMD >> shift) & mask;
}

u32
sdio_get_responde_data(
  enum sdio_response_reg reg
)
{
  return SDIO->RESP[reg];
}

void
sdio_set_data_transfer_timeout(
  u32 timeout
)
{
  SDIO->DTIMER = timeout;
}

void
sdio_set_data_transfer_length(
  u32 length
)
{
  devmode_assert_lower_or_eq(length, SDIO_DLEN_DATALENGTH_MASK);

  constexpr u32 shift = SDIO_DLEN_DATALENGTH_SHIFT;
  constexpr u32 mask = SDIO_DLEN_DATALENGTH_MASK << shift;
  volatile u32* reg = &SDIO->DLEN;
  syn_set_register_bits(reg, mask, length << shift);
}

void
sdio_data_transfer_enable(void)
{
  SDIO->DCTRL |= SDIO_DCTRL_DTEN;
}

void
sdio_set_data_transfer_direction(
  enum sdio_transfer_direction direction
)
{
  volatile u32* reg = &SDIO->DCTRL;
  switch (direction)
  {
    case SDIO_TRANSFER_DIRECTION_CONTROLLER_TO_CARD:
      *reg &= ~SDIO_DCTRL_DTDIR;
      break;

    case SDIO_TRANSFER_DIRECTION_CARD_TO_CONTROLLER:
      *reg |= SDIO_DCTRL_DTDIR;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_transfer_direction, direction);
      break;
  }
}

void
sdio_set_data_transfer_mode(
  enum sdio_transfer_mode mode
)
{
  volatile u32* reg = &SDIO->DCTRL;
  switch (mode)
  {
    case SDIO_TRANSFER_MODE_BLOCK:
      *reg &= ~SDIO_DCTRL_DTMODE;
      break;

    case SDIO_TRANSFER_MODE_STREAM:
      *reg |= SDIO_DCTRL_DTMODE;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_transfer_mode, mode);
      break;
  }
}

void
sdio_control_enable(
  enum sdio_control control
)
{
  volatile u32* reg = &SDIO->DCTRL;
  switch (control)
  {
    case SDIO_CONTROL_DMA:
      *reg |= SDIO_DCTRL_DMAEN;
      break;

    case SDIO_CONTROL_READ_WAIT_START:
      *reg |= SDIO_DCTRL_RWSTART;
      break;

    case SDIO_CONTROL_READ_WAIT_STOP:
      *reg |= SDIO_DCTRL_RWSTOP;
      break;

    case SDIO_CONTROL_READ_WAIT_MODE:
      *reg |= SDIO_DCTRL_RWMOD;
      break;

    case SDIO_CONTROL_SDIO_FUNCTIONS:
      *reg |= SDIO_DCTRL_SDIOEN;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_control, control);
      break;
  }
}

void
sdio_control_disable(
  enum sdio_control control
)
{
  volatile u32* reg = &SDIO->DCTRL;
  switch (control)
  {
    case SDIO_CONTROL_DMA:
      *reg &= ~SDIO_DCTRL_DMAEN;
      break;

    case SDIO_CONTROL_READ_WAIT_START:
      *reg &= ~SDIO_DCTRL_RWSTART;
      break;

    case SDIO_CONTROL_READ_WAIT_STOP:
      *reg &= ~SDIO_DCTRL_RWSTOP;
      break;

    case SDIO_CONTROL_READ_WAIT_MODE:
      *reg &= ~SDIO_DCTRL_RWMOD;
      break;

    case SDIO_CONTROL_SDIO_FUNCTIONS:
      *reg &= ~SDIO_DCTRL_SDIOEN;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_control, control);
      break;
  }
}

void
sdio_set_data_block_size(
  enum sdio_data_block_size size
)
{
  volatile u32* reg = &SDIO->DCTRL;
  constexpr u32 shift = SDIO_DCTRL_DBLOCKSIZE_SHIFT;
  constexpr u32 mask = SDIO_DCTRL_DBLOCKSIZE_MASK << shift;

  switch (size)
  {
    case SDIO_DATA_BLOCK_SIZE_1BYTE:
      *reg &= ~mask;
      break;

    case SDIO_DATA_BLOCK_SIZE_2BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_2BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_4BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_4BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_8BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_8BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_16BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_16BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_32BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_32BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_64BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_64BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_128BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_128BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_256BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_256BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_512BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_512BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_1024BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_1024BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_2048BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_2048BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_4096BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_4096BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_8192BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_8192BYTES << shift);
      break;

    case SDIO_DATA_BLOCK_SIZE_16384BYTES:
      syn_set_register_bits(reg, mask, SDIO_DCTRL_DBLOCKSIZE_16384BYTES << shift);
      break;
      
    default:
      devmode_error_invalid_enum(enum sdio_data_block_size, size);
      break;
  }
}

u32
sdio_get_data_transfer_bytes_left(void)
{
  constexpr u32 shift = SDIO_DCOUNT_DATACOUNT_SHIFT;
  constexpr u32 mask = SDIO_DCOUNT_DATACOUNT_MASK;
  return (SDIO->DCOUNT >> shift) & mask;
}

u32
sdio_is_flag_set(
  enum sdio_flag flag
)
{
  volatile u32 reg = SDIO->STA; 
  switch (flag)
  {
    case SDIO_FLAG_CMD_CRC_FAIL:
      return reg & SDIO_STA_CCRCFAIL;

    case SDIO_FLAG_DATA_CRC_FAIL:
      return reg & SDIO_STA_DCRCFAIL;

    case SDIO_FLAG_CMD_TIMEOUT:
      return reg & SDIO_STA_CTIMEOUT;

    case SDIO_FLAG_DATA_TIMEOUT:
      return reg & SDIO_STA_DTIMEOUT;

    case SDIO_FLAG_TX_FIFO_UNDERRUN:
      return reg & SDIO_STA_TXUNDERR;

    case SDIO_FLAG_RX_FIFO_OVERRUN:
      return reg & SDIO_STA_RXOVERR;

    case SDIO_FLAG_CMD_CRC_OK:
      return reg & SDIO_STA_CMDREND;

    case SDIO_FLAG_CMD_SENT:
      return reg & SDIO_STA_CMDSENT;

    case SDIO_FLAG_DATA_END:
      return reg & SDIO_STA_DATAEND;

    case SDIO_FLAG_MISSING_START_BIT:
      return reg & SDIO_STA_STBITERR;

    case SDIO_FLAG_DATA_CRC_OK:
      return reg & SDIO_STA_DBCKEND;

    case SDIO_FLAG_CMD_TRANSFER_IN_PROGRESS:
      return reg & SDIO_STA_CMDACT;

    case SDIO_FLAG_DATA_TRANSMIT_IN_PROGRESS:
      return reg & SDIO_STA_TXACT;

    case SDIO_FLAG_DATA_RECEIVE_IN_PROGRESS:
      return reg & SDIO_STA_RXACT;

    case SDIO_FLAG_TX_FIFO_HALF_EMPTY:
      return reg & SDIO_STA_TXFIFOHE;

    case SDIO_FLAG_RX_FIFO_HALF_FULL:
      return reg & SDIO_STA_RXFIFOHF;

    case SDIO_FLAG_TX_FIFO_FULL:
      return reg & SDIO_STA_TXFIFOF;

    case SDIO_FLAG_RX_FIFO_FULL:
      return reg & SDIO_STA_RXFIFOF;

    case SDIO_FLAG_TX_FIFO_EMPTY:
      return reg & SDIO_STA_TXFIFOE;

    case SDIO_FLAG_RX_FIFO_EMPTY:
      return reg & SDIO_STA_RXFIFOE;

    case SDIO_FLAG_DATA_AVAILABLE_IN_TX_FIFO:
      return reg & SDIO_STA_TXDAVL;

    case SDIO_FLAG_DATA_AVAILABLE_IN_RX_FIFO:
      return reg & SDIO_STA_RXDAVL;

    case SDIO_FLAG_SDIO_INT:
      return reg & SDIO_STA_SDIOIT;

    case SDIO_FLAG_CE_ATA_CMD_SIGNAL:
      return reg & SDIO_STA_CEATAEND;

    default:
      devmode_error_invalid_enum(enum sdio_flag, flag);
      return 0;
  }
}

void
sdio_flag_clear(
  enum sdio_flag flag
)
{
  volatile u32* reg = &SDIO->ICR;
  switch (flag)
  {
    case SDIO_FLAG_CMD_CRC_FAIL:
      *reg |= SDIO_ICR_CCRCFAILC;
      break;

    case SDIO_FLAG_DATA_CRC_FAIL:
      *reg |= SDIO_ICR_DCRCFAILC;
      break;

    case SDIO_FLAG_CMD_TIMEOUT:
      *reg |= SDIO_ICR_CTIMEOUTC;
      break;

    case SDIO_FLAG_DATA_TIMEOUT:
      *reg |= SDIO_ICR_DTIMEOUTC;
			break;

    case SDIO_FLAG_TX_FIFO_UNDERRUN:
      *reg |= SDIO_ICR_TXUNDERRC;
			break;

    case SDIO_FLAG_RX_FIFO_OVERRUN:
      *reg |= SDIO_ICR_RXOVERRC;
			break;

    case SDIO_FLAG_CMD_CRC_OK:
      *reg |= SDIO_ICR_CMDRENDC;
			break;

    case SDIO_FLAG_CMD_SENT:
      *reg |= SDIO_ICR_CMDSENTC;
			break;

    case SDIO_FLAG_DATA_END:
      *reg |= SDIO_ICR_DATAENDC;
			break;

    case SDIO_FLAG_MISSING_START_BIT:
      *reg |= SDIO_ICR_STBITERRC;
			break;

    case SDIO_FLAG_DATA_CRC_OK:
      *reg |= SDIO_ICR_DBCKENDC;
			break;

    case SDIO_FLAG_SDIO_INT:
      *reg |= SDIO_ICR_SDIOITC;
			break;

    case SDIO_FLAG_CE_ATA_CMD_SIGNAL:
      *reg |= SDIO_ICR_CEATAENDC;
			break;

    default:
      devmode_error_invalid_enum(enum sdio_flag, flag);
      break;
  }
}

void
sdio_interrupt_enable(
  enum sdio_interrupt interrupt
)
{
  volatile u32* reg = &SDIO->MASK;
  switch (interrupt)
  {
    case SDIO_INTERRUPT_CMD_CRC_FAIL:
      *reg |= SDIO_MASK_CCRCFAILIE;
      break;

    case SDIO_INTERRUPT_DATA_CRC_FAIL:
      *reg |= SDIO_MASK_DCRCFAILIE;
      break;

    case SDIO_INTERRUPT_CMD_TIMEOUT:
      *reg |= SDIO_MASK_CTIMEOUTIE;
      break;

    case SDIO_INTERRUPT_DATA_TIMEOUT:
      *reg |= SDIO_MASK_DTIMEOUTIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_UNDERRUN:
      *reg |= SDIO_MASK_TXUNDERRIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_UNDERRUN:
      *reg |= SDIO_MASK_RXOVERRIE;
      break;

    case SDIO_INTERRUPT_CMD_RESPONSE_RECV:
      *reg |= SDIO_MASK_CMDRENDIE;
      break;

    case SDIO_INTERRUPT_CMD_SENT:
      *reg |= SDIO_MASK_CMDSENTIE;
      break;

    case SDIO_INTERRUPT_DATA_END:
      *reg |= SDIO_MASK_DATAENDIE;
      break;

    case SDIO_INTERRUPT_START_BIT_ERROR:
      *reg |= SDIO_MASK_STBITERRIE;
      break;

    case SDIO_INTERRUPT_DATA_BLOCK_END:
      *reg |= SDIO_MASK_DBCKENDIE;
      break;

    case SDIO_INTERRUPT_CMD_TRANSFER:
      *reg |= SDIO_MASK_CMDACTIE;
      break;

    case SDIO_INTERRUPT_DATA_TRANSFER:
      *reg |= SDIO_MASK_TXACTIE;
      break;

    case SDIO_INTERRUPT_DATA_RECV:
      *reg |= SDIO_MASK_RXACTIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_HALF_EMPTY:
      *reg |= SDIO_MASK_TXFIFOHEIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_HALF_FULL:
      *reg |= SDIO_MASK_RXFIFOHFIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_FULL:
      *reg |= SDIO_MASK_TXFIFOFIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_FULL:
      *reg |= SDIO_MASK_RXFIFOFIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_EMPTY:
      *reg |= SDIO_MASK_TXFIFOEIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_EMPTY:
      *reg |= SDIO_MASK_RXFIFOEIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_DATA_AVAILABLE:
      *reg |= SDIO_MASK_TXDAVLIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_DATA_AVAILABLE:
      *reg |= SDIO_MASK_RXDAVLIE;
      break;

    case SDIO_INTERRUPT_SDIO_MODE:
      *reg |= SDIO_MASK_SDIOITIE;
      break;

    case SDIO_INTERRUPT_CE_ATA_SIGNAL:
      *reg |= SDIO_MASK_CEATAENDIE;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_interrupt, interrupt);
      break;
  }
}

void
sdio_interrupt_disable(
  enum sdio_interrupt interrupt
)
{
  volatile u32* reg = &SDIO->MASK;
  switch (interrupt)
  {
    case SDIO_INTERRUPT_CMD_CRC_FAIL:
      *reg &= ~SDIO_MASK_CCRCFAILIE;
      break;

    case SDIO_INTERRUPT_DATA_CRC_FAIL:
      *reg &= ~SDIO_MASK_DCRCFAILIE;
      break;

    case SDIO_INTERRUPT_CMD_TIMEOUT:
      *reg &= ~SDIO_MASK_CTIMEOUTIE;
      break;

    case SDIO_INTERRUPT_DATA_TIMEOUT:
      *reg &= ~SDIO_MASK_DTIMEOUTIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_UNDERRUN:
      *reg &= ~SDIO_MASK_TXUNDERRIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_UNDERRUN:
      *reg &= ~SDIO_MASK_RXOVERRIE;
      break;

    case SDIO_INTERRUPT_CMD_RESPONSE_RECV:
      *reg &= ~SDIO_MASK_CMDRENDIE;
      break;

    case SDIO_INTERRUPT_CMD_SENT:
      *reg &= ~SDIO_MASK_CMDSENTIE;
      break;

    case SDIO_INTERRUPT_DATA_END:
      *reg &= ~SDIO_MASK_DATAENDIE;
      break;

    case SDIO_INTERRUPT_START_BIT_ERROR:
      *reg &= ~SDIO_MASK_STBITERRIE;
      break;

    case SDIO_INTERRUPT_DATA_BLOCK_END:
      *reg &= ~SDIO_MASK_DBCKENDIE;
      break;

    case SDIO_INTERRUPT_CMD_TRANSFER:
      *reg &= ~SDIO_MASK_CMDACTIE;
      break;

    case SDIO_INTERRUPT_DATA_TRANSFER:
      *reg &= ~SDIO_MASK_TXACTIE;
      break;

    case SDIO_INTERRUPT_DATA_RECV:
      *reg &= ~SDIO_MASK_RXACTIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_HALF_EMPTY:
      *reg &= ~SDIO_MASK_TXFIFOHEIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_HALF_FULL:
      *reg &= ~SDIO_MASK_RXFIFOHFIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_FULL:
      *reg &= ~SDIO_MASK_TXFIFOFIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_FULL:
      *reg &= ~SDIO_MASK_RXFIFOFIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_EMPTY:
      *reg &= ~SDIO_MASK_TXFIFOEIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_EMPTY:
      *reg &= ~SDIO_MASK_RXFIFOEIE;
      break;

    case SDIO_INTERRUPT_TX_FIFO_DATA_AVAILABLE:
      *reg &= ~SDIO_MASK_TXDAVLIE;
      break;

    case SDIO_INTERRUPT_RX_FIFO_DATA_AVAILABLE:
      *reg &= ~SDIO_MASK_RXDAVLIE;
      break;

    case SDIO_INTERRUPT_SDIO_MODE:
      *reg &= ~SDIO_MASK_SDIOITIE;
      break;

    case SDIO_INTERRUPT_CE_ATA_SIGNAL:
      *reg &= ~SDIO_MASK_CEATAENDIE;
      break;

    default:
      devmode_error_invalid_enum(enum sdio_interrupt, interrupt);
      break;
  }
}

u32
sdio_get_words_left(void)
{
  constexpr u32 shift = SDIO_FIFOCNT_SHIFT;
  constexpr u32 mask = SDIO_FIFOCNT_MASK;
  return (SDIO->FIFOCNT >> shift) & mask;
}

void
sdio_write_fifo(
  u32 value
)
{
  SDIO->FIFO = value;
}

u32
sdio_read_fifo(void)
{
  return SDIO->FIFO;
}
