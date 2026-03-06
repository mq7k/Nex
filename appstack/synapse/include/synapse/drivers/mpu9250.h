#ifndef DRIVERS_MPU9250_H
#define DRIVERS_MPU9250_H

#include "libcom/util.h"
#include "synapse/io/ioif.h"

BEGIN_DECLARATIONS

enum mpu9250_reg
{
  // Gyroscope self-test registers.
  MPU9250_REG_SELF_TEST_X_GYRO = 0,
  MPU9250_REG_SELF_TEST_Y_GYRO = 1,
  MPU9250_REG_SELF_TEST_Z_GYRO = 2,

  // Accelerometer self-test registers.
  MPU9250_REG_SELF_TEST_X_ACCEL = 13,
  MPU9250_REG_SELF_TEST_Y_ACCEL = 14,
  MPU9250_REG_SELF_TEST_Z_ACCEL = 15,

  // Gyro offset registers.
  MPU9250_REG_XG_OFFSET_H = 19,
  MPU9250_REG_XG_OFFSET_L = 20,

  MPU9250_REG_YG_OFFSET_H = 21,
  MPU9250_REG_YG_OFFSET_L = 22,

  MPU9250_REG_ZG_OFFSET_H = 23,
  MPU9250_REG_ZG_OFFSET_L = 24,

  // Sample rate divider.
  MPU9250_REG_SMPLRT_DIV = 25,

  // Configuration.
  MPU9250_REG_CONFIG = 26,
  MPU9250_REG_GYRO_CONFIG = 27,

  // Accelerometer configuration.
  MPU9250_REG_ACCEL_CONFIG = 28,

  // Accelerometer configuration 2.
  MPU9250_REG_ACCEL_CONFIG2 = 29,

  // Low power accelerometer ODR control.
  MPU9250_REG_LP_ACCEL_ODR = 30,

  // Wake-on motion threshold.
  MPU9250_REG_WOM_THR = 31,

  // FIFO enable.
  MPU9250_REG_FIFO_EN = 35,

  // I2C master control.
  MPU9250_REG_I2C_MST_CTRL = 36,

  // I2C slave 0 control.
  MPU9250_REG_I2C_SLV0_ADDR = 37,
  MPU9250_REG_I2C_SLV0_REG = 38,
  MPU9250_REG_I2C_SLV0_CTRL = 39,

  // I2C slave 1 control.
  MPU9250_REG_I2C_SLV1_ADDR = 40,
  MPU9250_REG_I2C_SLV1_REG = 41,
  MPU9250_REG_I2C_SLV1_CTRL = 42,

  // I2C slave 2 control.
  MPU9250_REG_I2C_SLV2_ADDR = 43,
  MPU9250_REG_I2C_SLV2_REG = 44,
  MPU9250_REG_I2C_SLV2_CTRL = 45,

  // I2C slave 3 control.
  MPU9250_REG_I2C_SLV3_ADDR = 46,
  MPU9250_REG_I2C_SLV3_REG = 47,
  MPU9250_REG_I2C_SLV3_CTRL = 48,

  // I2C slave 4 control.
  MPU9250_REG_I2C_SLV4_ADDR = 49,
  MPU9250_REG_I2C_SLV4_REG = 50,
  MPU9250_REG_I2C_SLV4_DO = 51,
  MPU9250_REG_I2C_SLV4_CTRL = 52,
  MPU9250_REG_I2C_SLV4_DI = 53,

  // I2C master status.
  MPU9250_REG_I2C_MST_STATUS = 54,

  // Int pin / bypass enable configuration.
  MPU9250_REG_INT_PIN_CFG = 55,

  // Interrupt enable.
  MPU9250_REG_INT_ENABLE = 56,

  // Interrupt status.
  MPU9250_REG_INT_STATUS = 58,

  // Accelerometer measurements.
  MPU9250_REG_ACCEL_XOUT_H = 59,
  MPU9250_REG_ACCEL_XOUT_L = 60,

  MPU9250_REG_ACCEL_YOUT_H = 61,
  MPU9250_REG_ACCEL_YOUT_L = 62,

  MPU9250_REG_ACCEL_ZOUT_H = 63,
  MPU9250_REG_ACCEL_ZOUT_L = 64,

  // Temperature measurements.
  MPU9250_REG_TEMP_OUT_H = 65,
  MPU9250_REG_TEMP_OUT_L = 66,

  // Gyroscope measurements.
  MPU9250_REG_GYRO_XOUT_H = 67,
  MPU9250_REG_GYRO_XOUT_L = 68,

  MPU9250_REG_GYRO_YOUT_H = 69,
  MPU9250_REG_GYRO_YOUT_L = 70,

  MPU9250_REG_GYRO_ZOUT_H = 71,
  MPU9250_REG_GYRO_ZOUT_L = 72,

  // External sensor data.
  MPU9250_REG_EXT_SENS_DATA_00 = 73,
  MPU9250_REG_EXT_SENS_DATA_01 = 74,
  MPU9250_REG_EXT_SENS_DATA_02 = 75,
  MPU9250_REG_EXT_SENS_DATA_03 = 76,
  MPU9250_REG_EXT_SENS_DATA_04 = 77,
  MPU9250_REG_EXT_SENS_DATA_05 = 78,
  MPU9250_REG_EXT_SENS_DATA_06 = 79,
  MPU9250_REG_EXT_SENS_DATA_07 = 80,
  MPU9250_REG_EXT_SENS_DATA_08 = 81,
  MPU9250_REG_EXT_SENS_DATA_09 = 82,
  MPU9250_REG_EXT_SENS_DATA_10 = 83,
  MPU9250_REG_EXT_SENS_DATA_11 = 84,
  MPU9250_REG_EXT_SENS_DATA_12 = 85,
  MPU9250_REG_EXT_SENS_DATA_13 = 86,
  MPU9250_REG_EXT_SENS_DATA_14 = 87,
  MPU9250_REG_EXT_SENS_DATA_15 = 88,
  MPU9250_REG_EXT_SENS_DATA_16 = 89,
  MPU9250_REG_EXT_SENS_DATA_17 = 90,
  MPU9250_REG_EXT_SENS_DATA_18 = 91,
  MPU9250_REG_EXT_SENS_DATA_19 = 92,
  MPU9250_REG_EXT_SENS_DATA_20 = 93,
  MPU9250_REG_EXT_SENS_DATA_21 = 94,
  MPU9250_REG_EXT_SENS_DATA_22 = 95,
  MPU9250_REG_EXT_SENS_DATA_23 = 96,

  // I2C slave 0 data out.
  MPU9250_REG_I2C_SLV0_DO = 99,

  // I2C slave 1 data out.
  MPU9250_REG_I2C_SLV1_DO = 100,

  // I2C slave 2 data out.
  MPU9250_REG_I2C_SLV2_DO = 101,

  // I2C slave 3 data out.
  MPU9250_REG_I2C_SLV3_DO = 102,

  // I2C master delay control.
  MPU9250_REG_I2C_MST_DELAY_CTRL = 103,

  // Signal path reset.
  MPU9250_REG_SIGNAL_PATH_RESET = 104,

  // Accelerometer interrupt control.
  MPU9250_REG_MOT_DETECT_CTRL = 105,

  // User control.
  MPU9250_REG_USER_CTRL = 106,

  // Power managemenet 1.
  MPU9250_REG_PWR_MGMT_1 = 107,

  // Power managemenet 2.
  MPU9250_REG_PWR_MGMT_2 = 108,

  // FIFO count registers.
  MPU9250_REG_FIFO_COUNTH = 114,
  MPU9250_REG_FIFO_COUNTL = 115,

  // FIFO read write.
  MPU9250_REG_FIFO_R_W = 116,

  // Who am I.
  MPU9250_REG_WHO_AM_I = 117,

  // Accelerometer offset registers.
  MPU9250_REG_XA_OFFSET_H = 119,
  MPU9250_REG_XA_OFFSET_L = 120,

  MPU9250_REG_YA_OFFSET_H = 122,
  MPU9250_REG_YA_OFFSET_L = 123,

  MPU9250_REG_ZA_OFFSET_H = 125,
  MPU9250_REG_ZA_OFFSET_L = 126
};

#define MPU9250_CONFIGURATION_DLPF_SHIFT (0)
#define MPU9250_CONFIGURATION_DLPF_MASK (0x7)

#define MPU9250_CONFIGURATION_EXT_SYNC_SET_SHIFT (3)
#define MPU9250_CONFIGURATION_EXT_SYNC_SET_MASK (0x7)

enum mpu9250_config_ext_sync_set : u32
{
  MPU9250_CONFIG_EXT_SYNC_SET_OFF = 0b000,
  MPU9250_CONFIG_EXT_SYNC_SET_TEMP_OUT_L = 0b001,
  MPU9250_CONFIG_EXT_SYNC_SET_GYRO_XOUT_L = 0b010,
  MPU9250_CONFIG_EXT_SYNC_SET_GYRO_YOUT_L = 0b011,
  MPU9250_CONFIG_EXT_SYNC_SET_GYRO_ZOUT_L = 0b100,
  MPU9250_CONFIG_EXT_SYNC_SET_ACCEL_XOUT_L = 0b101,
  MPU9250_CONFIG_EXT_SYNC_SET_ACCEL_YOUT_L = 0b110,
  MPU9250_CONFIG_EXT_SYNC_SET_ACCEL_ZOUT_L = 0b111
};

enum mpu9250_configuration : u32
{
  MPU9250_CONFIGURATION_FIFO_MODE = BIT(6)
};

#define MPU9250_GYRO_CONFIG_FCHOICE_SHIFT (0)
#define MPU9250_GYRO_CONFIG_FCHOICE_MASK (0x3)

enum mpu9250_gyro_config : u32
{
  MPU9250_GYRO_CONFIG_ZGYRO_CTEN = BIT(5),
  MPU9250_GYRO_CONFIG_YGYRO_CTEN = BIT(6),
  MPU9250_GYRO_CONFIG_XGYRO_CTEN = BIT(7)
};

#define MPU9250_GYRO_CONFIG_GYRO_FS_SEL_SHIFT (3)
#define MPU9250_GYRO_CONFIG_GYRO_FS_SEL_MASK (0x3)

enum mpu9250_gyro_config_gyro_fs_sel : u32
{
  MPU9250_GYRO_CONFIG_GYRO_FS_SEL_250DPS = 0b00,
  MPU9250_GYRO_CONFIG_GYRO_FS_SEL_500DPS = 0b01,
  MPU9250_GYRO_CONFIG_GYRO_FS_SEL_1000DPS = 0b10,
  MPU9250_GYRO_CONFIG_GYRO_FS_SEL_2000DPS = 0b11
};

enum mpu9250_accel_config : u32
{
  MPU9250_ACCEL_CONFIG_STZ = BIT(5),
  MPU9250_ACCEL_CONFIG_STY = BIT(6),
  MPU9250_ACCEL_CONFIG_STX = BIT(7)
};

#define MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_SHIFT (3)
#define MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_MASK (0x3)

enum mpu9250_accel_config_accel_fs_sel : u32
{
  MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_PM_2G = 0b00,
  MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_PM_4G = 0b01,
  MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_PM_8G = 0b10,
  MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_PM_16G = 0b11
};

enum mpu9250_accel_config2 : u32
{
  MPU9250_ACCEL_CONFIG2_ACCEL_FCHOICE = BIT(3)
};

#define MPU9250_ACCEL_CONFIG2_DLPFCFG_SHIFT (0)
#define MPU9250_ACCEL_CONFIG2_DLPFCFG_MASK (0x7)

#define MPU9250_ACCEL_CONFIG2_CLKSEL_SHIFT (0) 
#define MPU9250_ACCEL_CONFIG2_CLKSEL_MASK (0xf)

#define MPU9250_LPACCEL_ODR_LPOSC_CLKSEL_SHIFT (0)
#define MPU9250_LPACCEL_ODR_LPOSC_CLKSEL_MASK (0xf)

#define MPU9250_WOM_THR_SHIFT (0)
#define MPU9250_WOM_THR_MASK (0xff)

enum mpu9250_fifoen : u32
{
  MPU9250_FIFOEN_SLV0 = BIT(0),
  MPU9250_FIFOEN_SLV1 = BIT(1),
  MPU9250_FIFOEN_SLV2 = BIT(2),
  MPU9250_FIFOEN_ACCEL = BIT(3),
  MPU9250_FIFOEN_GYRO_ZOUT = BIT(4),
  MPU9250_FIFOEN_GYRO_YOUT = BIT(5),
  MPU9250_FIFOEN_GYRO_XOUT = BIT(6),
  MPU9250_FIFOEN_TEMP_OUT = BIT(7)
};

enum mpu9250_mstctrl : u32
{
  MPU9250_MSTCTRL_I2C_MST_P_NSR = BIT(4),
  MPU9250_MSTCTRL_SLV_3_FIFO_EN = BIT(5),
  MPU9250_MSTCTRL_WAIT_FOR_ES = BIT(6),
  MPU9250_MSTCTRL_MULT_MST_EN = BIT(7)
};

#define MPU9250_I2C_MSTCTRL_MSTCLK_SHIFT (0)
#define MPU9250_I2C_MSTCTRL_MSTCLK_MASK (0xf)

enum mpu9250_i2c_mstctrl : u32
{
  MPU9250_I2C_MSTCTRL_DIV23 = 0b0000,
  MPU9250_I2C_MSTCTRL_DIV24 = 0b0001,
  MPU9250_I2C_MSTCTRL_DIV25 = 0b0010,
  MPU9250_I2C_MSTCTRL_DIV26 = 0b0011,
  MPU9250_I2C_MSTCTRL_DIV27 = 0b0100,
  MPU9250_I2C_MSTCTRL_DIV28 = 0b0101,
  MPU9250_I2C_MSTCTRL_DIV29 = 0b0110,
  MPU9250_I2C_MSTCTRL_DIV30 = 0b0111,
  MPU9250_I2C_MSTCTRL_DIV31 = 0b1000,
  MPU9250_I2C_MSTCTRL_DIV16 = 0b1001,
  MPU9250_I2C_MSTCTRL_DIV17 = 0b1010,
  MPU9250_I2C_MSTCTRL_DIV18 = 0b1011,
  MPU9250_I2C_MSTCTRL_DIV19 = 0b1100,
  MPU9250_I2C_MSTCTRL_DIV20 = 0b1101,
  MPU9250_I2C_MSTCTRL_DIV21 = 0b1110,
  MPU9250_I2C_MSTCTRL_DIV22 = 0b1111
};

enum mpu9250_i2c_slv_addr : u32
{
  MPU9250_I2C_SLV_ADDR_I2C_RNW = BIT(7)
};

#define MPU9250_I2C_SLV_ADDR_ID_SHIFT (0)
#define MPU9250_I2C_SLV_ADDR_ID_MASK (0x7f)

enum mpu9250_i2c_slv_ctrl : u32
{
  MPU9250_I2C_SLV_CTRL_I2C_SLV_GRP = BIT(4),
  MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS = BIT(5),
  MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW = BIT(6),
  MPU9250_I2C_SLV_CTRL_I2C_SLV_EN = BIT(7)
};

#define MPU9250_I2C_SLV4_DO_SHIFT (0)
#define MPU9250_I2C_SLV4_DO_MASK (0xff)

#define MPU9250_I2C_SLV_CTRL_LEN_SHIFT (0)
#define MPU9250_I2C_SLV_CTRL_LEN_MASK (0xf)

enum mpu9250_i2c_slv4_ctrl : u32
{
  MPU9250_I2C_SLV4_CTRL_I2C_SLV4_REG_DIS = BIT(5),
  MPU9250_I2C_SLV4_CTRL_SLV4_DONE_INT_EN = BIT(6),
  MPU9250_I2C_SLV4_CTRL_I2C_SLV4_EN = BIT(7)
};

#define MPU9250_I2C_SLV4_CTRL_I2C_MST_DLY_SHIFT (0)
#define MPU9250_I2C_SLV4_CTRL_I2C_MST_DLY_MASK (0x1f)

#define MPU9250_I2C_SLV4_DI_SHIFT (0)
#define MPU9250_I2C_SLV4_DI_MASK (0xff)

enum mpu9250_mst_status : u32
{
  MPU9250_MST_STATUS_I2C_SLV0_NACK = BIT(0),
  MPU9250_MST_STATUS_I2C_SLV1_NACK = BIT(1),
  MPU9250_MST_STATUS_I2C_SLV2_NACK = BIT(2),
  MPU9250_MST_STATUS_I2C_SLV3_NACK = BIT(3),
  MPU9250_MST_STATUS_I2C_SLV4_NACK = BIT(4),
  MPU9250_MST_STATUS_I2C_LOST_ARB = BIT(5),
  MPU9250_MST_STATUS_I2C_SLV4_DONE = BIT(6),
  MPU9250_MST_STATUS_PASS_THROUGH = BIT(7)
};

enum mpu9250_int_pin_cfg : u32
{
  MPU9250_INT_PIN_CFG_BYPASS_EN = BIT(1),
  MPU9250_INT_PIN_CFG_FSYNC_INT_MODE_EN = BIT(2),
  MPU9250_INT_PIN_CFG_ACTL_FSYNC = BIT(3),
  MPU9250_INT_PIN_CFG_INT_ANYRD_2CLEAR = BIT(4),
  MPU9250_INT_PIN_CFG_LATCH_INT_EN = BIT(5),
  MPU9250_INT_PIN_CFG_OPEN = BIT(6),
  MPU9250_INT_PIN_CFG_ACTL = BIT(7)
};

enum mpu9250_int_enable : u32
{
  MPU9250_INT_ENABLE_RAW_RDY_EN = BIT(0),
  MPU9250_INT_ENABLE_FSYNC_INT_EN = BIT(3),
  MPU9250_INT_ENABLE_FIFO_OVERFLOW_EN = BIT(4),
  MPU9250_INT_ENABLE_WOM_EN = BIT(6)
};

enum mpu9250_int_status : u32
{
  MPU9250_INT_STATUS_RAW_DATA_RDY_INT = BIT(0),
  MPU9250_INT_STATUS_FSYNC_INT = BIT(3),
  MPU9250_INT_STATUS_FIFO_OVERFLOW_INT = BIT(4),
  MPU9250_INT_STATUS_WOM_INT = BIT(6)
};

enum mpu9250_i2c_mst_delay_ctrl : u32
{
  MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV0_DLY_EN = BIT(0),
  MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV1_DLY_EN = BIT(1),
  MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV2_DLY_EN = BIT(2),
  MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV3_DLY_EN = BIT(3),
  MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV4_DLY_EN = BIT(4),
  MPU9250_I2C_MST_DELAY_CTRL_DELAY_ES_SHADOW = BIT(7)
};

enum mpu9250_signal_path_reset : u32
{
  MPU9250_SIGNAL_PATH_RESET_TEMP_RST = BIT(0),
  MPU9250_SIGNAL_PATH_RESET_ACCEL_RST = BIT(1),
  MPU9250_SIGNAL_PATH_RESET_GYRO_RST = BIT(2)
};

enum mpu9250_mot_detect_ctrl : u32
{
  MPU9250_MOT_DETECT_CTRL_ACCEL_INTEL_MODE = BIT(6),
  MPU9250_MOT_DETECT_CTRL_ACCEL_INTEL_EN = BIT(7)
};

enum mpu9250_user_ctrl : u32
{
  MPU9250_USER_CTRL_SIG_COND_RST = BIT(0),
  MPU9250_USER_CTRL_I2C_MST_RST = BIT(1),
  MPU9250_USER_CTRL_FIFO_RST = BIT(2),
  MPU9250_USER_CTRL_I2C_IF_DIS = BIT(4),
  MPU9250_USER_CTRL_I2C_MST_EN = BIT(5),
  MPU9250_USER_CTRL_FIFO_EN = BIT(6)
};

enum mpu9250_pwr_mgmt1 : u32
{
  MPU9250_PWR_MGMT1_PD_PTAT = BIT(3),
  MPU9250_PWR_MGMT1_GYRO_STANDBY = BIT(4),
  MPU9250_PWR_MGMT1_CYCLE = BIT(5),
  MPU9250_PWR_MGMT1_SLEEP = BIT(6),
  MPU9250_PWR_MGMT1_H_RESET = BIT(7)
};

#define MPU9250_PWR_MGMT1_CLKSEL_SHIFT (0)
#define MPU9250_PWR_MGMT1_CLKSEL_MASK (0x7)

enum mpu9250_pwr_mgmt1_clksel : u32
{
  MPU9250_PWR_MGMT1_CLKSEL_20MHZ_IO = 0b000,
  MPU9250_PWR_MGMT1_CLKSEL_AUTO = 0b001,
  MPU9250_PWR_MGMT1_CLKSEL_CLKOFF = 0b111
};

enum mpu9250_pwr_mgmt2 : u32
{
  MPU9250_PWR_MGMT2_DISABLE_ZG = BIT(0),
  MPU9250_PWR_MGMT2_DISABLE_YG = BIT(1),
  MPU9250_PWR_MGMT2_DISABLE_XG = BIT(2),
  MPU9250_PWR_MGMT2_DISABLE_ZA = BIT(3),
  MPU9250_PWR_MGMT2_DISABLE_YA = BIT(4),
  MPU9250_PWR_MGMT2_DISABLE_XA = BIT(5)
};

#define MPU9250_FIFO_COUNTH_SHIFT (0)
#define MPU9250_FIFO_COUNTH_MASK (0x1f)

#define MPU9250_ACCEL_XOFFL_SHIFT (1)
#define MPU9250_ACCEL_XOFFL_MASK (0x7f)

#define MPU9250_ACCEL_YOFFL_SHIFT (1)
#define MPU9250_ACCEL_YOFFL_MASK (0x7f)

#define MPU9250_ACCEL_ZOFFL_SHIFT (1)
#define MPU9250_ACCEL_ZOFFL_MASK (0x7f)

// TODO: Implement magnometer's registers definitions.

enum mpu9250_ext_sync
{
  MPU9250_EXT_SYNC_OFF,
  MPU9250_EXT_SYNC_TEMP_OUT,
  MPU9250_EXT_SYNC_GYRO_XOUT,
  MPU9250_EXT_SYNC_GYRO_YOUT,
  MPU9250_EXT_SYNC_GYRO_ZOUT,
  MPU9250_EXT_SYNC_ACCEL_XOUT,
  MPU9250_EXT_SYNC_ACCEL_YOUT,
  MPU9250_EXT_SYNC_ACCEL_ZOUT
};

enum mpu9250_gyro_full_scale
{
  GYRO_FULL_SCALE_P250dps,
  GYRO_FULL_SCALE_P500dps,
  GYRO_FULL_SCALE_P1000dps,
  GYRO_FULL_SCALE_P2000dps
};

enum mpu9250_accel_full_scale
{
  MPU9250_ACCEL_FULL_SCALE_PM_2g,
  MPU9250_ACCEL_FULL_SCALE_PM_4g,
  MPU9250_ACCEL_FULL_SCALE_PM_8g,
  MPU9250_ACCEL_FULL_SCALE_PM_16g
};

enum mpu9250_i2c_master_clk_div
{
  MPU9250_I2C_MASTER_CLK_DIV_DIV16,
  MPU9250_I2C_MASTER_CLK_DIV_DIV17,
  MPU9250_I2C_MASTER_CLK_DIV_DIV18,
  MPU9250_I2C_MASTER_CLK_DIV_DIV19,
  MPU9250_I2C_MASTER_CLK_DIV_DIV20,
  MPU9250_I2C_MASTER_CLK_DIV_DIV21,
  MPU9250_I2C_MASTER_CLK_DIV_DIV22,
  MPU9250_I2C_MASTER_CLK_DIV_DIV23,
  MPU9250_I2C_MASTER_CLK_DIV_DIV24,
  MPU9250_I2C_MASTER_CLK_DIV_DIV25,
  MPU9250_I2C_MASTER_CLK_DIV_DIV26,
  MPU9250_I2C_MASTER_CLK_DIV_DIV27,
  MPU9250_I2C_MASTER_CLK_DIV_DIV28,
  MPU9250_I2C_MASTER_CLK_DIV_DIV29,
  MPU9250_I2C_MASTER_CLK_DIV_DIV30,
  MPU9250_I2C_MASTER_CLK_DIV_DIV31
};

enum mpu9250_i2c_master_slaves_transitions
{
  MPU9250_SET_I2C_MASTER_SLAVES_TRANSITIONS_RESTART,
  MPU9250_SET_I2C_MASTER_SLAVES_TRANSITIONS_STOP
};

enum mpu9250_slave
{
  MPU9250_SLAVE0,
  MPU9250_SLAVE1,
  MPU9250_SLAVE2,
  MPU9250_SLAVE3,
  MPU9250_SLAVE4
};

enum mpu9250_slave_group
{
  MPU9250_SLAVE_GROUP_EVEN,
  MPU9250_SLAVE_GROUP_ODD
};

enum mpu9250_transfer
{
  MPU9250_TRANSFER_READ,
  MPU9250_TRANSFER_WRITE
};

enum mpu9250_flag
{
  MPU9250_FLAG_SLAVE0_NACK,
  MPU9250_FLAG_SLAVE1_NACK,
  MPU9250_FLAG_SLAVE2_NACK,
  MPU9250_FLAG_SLAVE3_NACK,
  MPU9250_FLAG_SLAVE4_NACK,
  MPU9250_FLAG_LOST_ARB,
  MPU9250_FLAG_SLAVE4_DONE,
  MPU9250_FLAG_PASS_THROUGH
};

enum mpu9250_fsync_logic
{
  MPU9250_FSYNC_LOGIC_ACTIVE_LOW,
  MPU9250_FSYNC_LOGIC_ACTIVE_HIGH
};

enum mpu9250_int_status_clear_policy
{
  MPU9250_INT_STATUS_CLEAR_POLICY_ANY_READ,
  MPU9250_INT_STATUS_CLEAR_POLICY_STATUS_REG
};

enum mpu9250_int_pin_latch
{
  MPU9250_INT_PIN_LATCH_MANUAL,
  MPU9250_INT_PIN_LATCH_AUTO
};

enum mpu9250_int_pin_mode
{
  MPU9250_INT_PIN_MODE_OPEN_DRAIN,
  MPU9250_INT_PIN_MODE_PUSHPULL
};

enum mpu9250_int_pin_logic
{
  MPU9250_INT_PIN_LOGIC_ACTIVE_LOW,
  MPU9250_INT_PIN_LOGIC_ACTIVE_HIGH
};

enum mpu9250_interrupt
{
  MPU9250_INTERRUPT_RAW_DATA_READY,
  MPU9250_INTERRUPT_FSYNC,
  MPU9250_INTERRUPT_FIFO_OVERFLOW,
  MPU9250_INTERRUPT_WOM
};

enum mpu9250_clk_source
{
  MPU9250_CLK_SOURCE_INTERNAL_20MHZ,
  MPU9250_CLK_SOURCE_AUTO,
  MPU9250_CLK_SOURCE_STOP
};

enum mpu9250_protocol
{
  MPU9250_PROTOCOL_I2C,
  MPU9250_PROTOCOL_SPI
};

#define MPU9250_AXIS_MASK (0x7u)

enum mpu9250_axis
{
  MPU9250_AXIS_Z = BIT(0),
  MPU9250_AXIS_Y = BIT(1),
  MPU9250_AXIS_X = BIT(2)
};

struct mpu9250_vec8
{
  u8 x;
  u8 y;
  u8 z;
};

struct mpu9250_vec16
{
  i16 x;
  i16 y;
  i16 z;
};

struct mpu9250
{
  struct beio* beio;
  enum mpu9250_protocol protocol;

  // Only used in SPI.
  volatile void* cs_port;
  u32 cs_pin;
};

u32
mpu9250_init(
  struct mpu9250* mpu,
  enum mpu9250_protocol protocol,
  void* ctx
);

u32
mpu9250_get_self_test_gyro(
  struct mpu9250* mpu,
  struct mpu9250_vec8* vec
);

u32
mpu9250_get_self_test_accel(
  struct mpu9250* mpu,
  struct mpu9250_vec8* vec
);

u32
mpu9250_get_gyro_offset(
  struct mpu9250* mpu,
  struct mpu9250_vec16* axis
);

u32
mpu9250_set_gyro_offset(
  struct mpu9250* mpu,
  struct mpu9250_vec16* axis
);

u32
mpu9250_get_sample_rate_div(
  struct mpu9250* mpu,
  u8* sample_rate
);

u32
mpu9250_set_sample_rate_div(
  struct mpu9250* mpu,
  u8 sample_rate
);

u32
mpu9250_set_digital_low_pass_filter(
  struct mpu9250* mpu,
  u32 value
);

u32
mpu9250_set_ext_sync(
  struct mpu9250* mpu,
  enum mpu9250_ext_sync sync
);

u32
mpu9250_circular_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_circular_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_config_reg(
  struct mpu9250* mpu,
  u8 reg
);

u32
mpu9250_set_fchoice(
  struct mpu9250* mpu,
  u32 choice
);

u32
mpu9250_set_gyro_full_scale(
  struct mpu9250* mpu,
  enum mpu9250_gyro_full_scale fs
);

u32
mpu9250_zgyro_self_test_enable(
  struct mpu9250* mpu
);

u32
mpu9250_zgyro_self_test_disable(
  struct mpu9250* mpu
);

u32
mpu9250_ygyro_self_test_enable(
  struct mpu9250* mpu
);

u32
mpu9250_ygyro_self_test_disable(
  struct mpu9250* mpu
);

u32
mpu9250_xgyro_self_test_enable(
  struct mpu9250* mpu
);

u32
mpu9250_xgyro_self_test_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_gyro_config_reg(
  struct mpu9250* mpu,
  u8 reg
);

u32
mpu9250_set_accel_full_scale(
  struct mpu9250* mpu,
  enum mpu9250_accel_full_scale fs
);

u32
mpu9250_zaccel_self_test_enable(
  struct mpu9250* mpu
);

u32
mpu9250_zaccel_self_test_disable(
  struct mpu9250* mpu
);

u32
mpu9250_yaccel_self_test_enable(
  struct mpu9250* mpu
);

u32
mpu9250_yaccel_self_test_disable(
  struct mpu9250* mpu
);

u32
mpu9250_xaccel_self_test_enable(
  struct mpu9250* mpu
);

u32
mpu9250_xaccel_self_test_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_accel_low_pass_filter(
  struct mpu9250* mpu,
  u32 filter
);

u32
mpu9250_accel_fchoice_enable(
  struct mpu9250* mpu
);

u32
mpu9250_accel_fchoice_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_low_power_accel_clksrc(
  struct mpu9250* mpu,
  u8 clksel
);

u32
mpu9250_set_wom_threshold(
  struct mpu9250* mpu,
  u8 value
);

u32
mpu9250_slv0_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_slv0_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_slv1_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_slv1_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_slv2_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_slv2_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_accel_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_accel_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_zgyro_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_zgyro_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_ygyro_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_ygyro_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_xgyro_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_xgyro_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_temp_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_temp_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_fifo_en_reg(
  struct mpu9250* mpu,
  u8 reg
);

u32
mpu9250_set_i2c_master_clk_div(
  struct mpu9250* mpu,
  enum mpu9250_i2c_master_clk_div div
);

u32
mpu9250_set_i2c_master_slaves_transitions(
  struct mpu9250* mpu,
  enum mpu9250_i2c_master_slaves_transitions transition
);

u32
mpu9250_slv3_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_slv3_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_data_ready_int_delay_enable(
  struct mpu9250* mpu
);

u32
mpu9250_data_ready_int_delay_disable(
  struct mpu9250* mpu
);

u32
mpu9250_i2c_multi_master_enable(
  struct mpu9250* mpu
);

u32
mpu9250_i2c_multi_master_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_slave_dst(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  enum mpu9250_transfer dir,
  u8 addr
);

u32
mpu9250_set_slave_addr_src(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  u8 addr
);

u32
mpu9250_set_slave_bytes_count(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  u8 count
);

u32
mpu9250_set_slave_group_type(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  enum mpu9250_slave_group group
);

u32
mpu9250_slave_reg_bypass_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
);

u32
mpu9250_slave_reg_bypass_disable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
);

u32
mpu9250_slave_bytes_swap_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
);

u32
mpu9250_slave_bytes_swap_disable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
);

u32
mpu9250_slave_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
);

u32
mpu9250_set_slave_data(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  u8 data
);

u32
mpu9250_set_slave4_delay(
  struct mpu9250* mpu,
  u8 delay
);

u32
mpu9250_slave4_int_enable(
  struct mpu9250* mpu
);

u32
mpu9250_slave4_int_disable(
  struct mpu9250* mpu
);

u32
mpu9250_get_slave4_data(
  struct mpu9250* mpu,
  u8* data
);

u32
mpu9250_is_flag_set(
  struct mpu9250* mpu,
  enum mpu9250_flag flag,
  u8* result
);

u32
mpu9250_i2c_master_bypass_enable(
  struct mpu9250* mpu
);

u32
mpu9250_i2c_master_bypass_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_fsync_interrupt_enable(
  struct mpu9250* mpu
);

u32
mpu9250_set_fsync_interrupt_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_fsync_logic(
  struct mpu9250* mpu,
  enum mpu9250_fsync_logic logic
);

u32
mpu9250_set_int_status_clear_policy(
  struct mpu9250* mpu,
  enum mpu9250_int_status_clear_policy policy
);

u32
mpu9250_set_int_pin_latch(
  struct mpu9250* mpu,
  enum mpu9250_int_pin_latch latch
);

u32
mpu9250_set_int_pin_mode(
  struct mpu9250* mpu,
  enum mpu9250_int_pin_mode mode
);

u32
mpu9250_set_int_pin_logic(
  struct mpu9250* mpu,
  enum mpu9250_int_pin_logic logic
);

u32
mpu9250_interrupt_enable(
  struct mpu9250* mpu,
  enum mpu9250_interrupt interrupt
);

u32
mpu9250_interrupt_disable(
  struct mpu9250* mpu,
  enum mpu9250_interrupt interrupt
);

u32
mpu9250_set_interrupt_enable_reg(
  struct mpu9250* mpu,
  u8 reg
);

u32
mpu9250_is_interrupt_occured(
  struct mpu9250* mpu,
  enum mpu9250_interrupt interrupt,
  u8* result
);

u32
mpu9250_get_int_status_reg(
  struct mpu9250* mpu,
  u8* res
);

u32
mpu9250_get_accel(
  struct mpu9250* mpu,
  struct mpu9250_vec16* axis
);

u32
mpu9250_get_temperature_raw(
  struct mpu9250* mpu,
  u16* raw
);

u32
mpu9250_get_temperature(
  struct mpu9250* mpu,
  u32 offset,
  float sensitivity,
  float* temp
);

u32
mpu9250_get_gyro(
  struct mpu9250* mpu,
  struct mpu9250_vec16* axis
);

u32
mpu9250_get_ext_sensor_data(
  struct mpu9250* mpu,
  u8 start_reg,
  u32 count,
  u8* buf
);

u32
mpu9250_i2c_slave_delay_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
);

u32
mpu9250_i2c_slave_delay_disable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
);

u32
mpu9250_delay_sensor_data_enable(
  struct mpu9250* mpu
);

u32
mpu9250_delay_sensor_data_disable(
  struct mpu9250* mpu
);

u32
mpu9250_temp_reset(
  struct mpu9250* mpu
);

u32
mpu9250_accel_reset(
  struct mpu9250* mpu
);

u32
mpu9250_gyro_reset(
  struct mpu9250* mpu
);

u32
mpu9250_accel_intel_mode_enable(
  struct mpu9250* mpu
);

u32
mpu9250_accel_intel_mode_disable(
  struct mpu9250* mpu
);

u32
mpu9250_wom_enable(
  struct mpu9250* mpu
);

u32
mpu9250_wom_disable(
  struct mpu9250* mpu
);

u32
mpu9250_reset_sensors(
  struct mpu9250* mpu
);

u32
mpu9250_reset_i2c(
  struct mpu9250* mpu
);

u32
mpu9250_reset_fifo(
  struct mpu9250* mpu
);

u32
mpu9250_i2c_if_enable(
  struct mpu9250* mpu
);

u32
mpu9250_i2c_if_disable(
  struct mpu9250* mpu
);

u32
mpu9250_i2c_master_enable(
  struct mpu9250* mpu
);

u32
mpu9250_i2c_master_disable(
  struct mpu9250* mpu
);

u32
mpu9250_fifo_enable(
  struct mpu9250* mpu
);

u32
mpu9250_fifo_disable(
  struct mpu9250* mpu
);

u32
mpu9250_set_clk_source(
  struct mpu9250* mpu,
  enum mpu9250_clk_source src
);

u32
mpu9250_ptat_power_down_enable(
  struct mpu9250* mpu
);

u32
mpu9250_ptat_power_down_disable(
  struct mpu9250* mpu
);

u32
mpu9250_gyro_standby_enable(
  struct mpu9250* mpu
);

u32
mpu9250_gyro_standby_disable(
  struct mpu9250* mpu
);

u32
mpu9250_low_power_sample_cycles_enable(
  struct mpu9250* mpu
);

u32
mpu9250_low_power_sample_cycles_disable(
  struct mpu9250* mpu
);

u32
mpu9250_sleep_enable(
  struct mpu9250* mpu
);

u32
mpu9250_sleep_disable(
  struct mpu9250* mpu
);

u32
mpu9250_reset(
  struct mpu9250* mpu
);

u32
mpu9250_set_gyro_disabled_axis(
  struct mpu9250* mpu,
  u32 disabled_axis
);

u32
mpu9250_set_accel_disabled_axis(
  struct mpu9250* mpu,
  u32 disabled_axis
);

u32
mpu9250_get_fifo_bytes_count(
  struct mpu9250* mpu,
  u32* result
);

u32
mpu9250_set_fifo_rw_command(
  struct mpu9250* mpu,
  u8 command
);

u32
mpu9250_get_device_id(
  struct mpu9250* mpu,
  u8* id
);

u32
mpu9250_set_accel_offset(
  struct mpu9250* mpu,
  struct mpu9250_vec16* vec
);

END_DECLARATIONS

#endif
