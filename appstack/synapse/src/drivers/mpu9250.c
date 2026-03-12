#include "synapse/drivers/mpu9250.h"
#include "libcom/sys/devmode.h"
#include "libcom/types.h"
#include "libcom/util.h"
#include "synapse/io/io_spi.h"
#include "synapse/soc/stm32/drivers/gpio/gpioif.h"

u32
mpu9250_init(
  struct mpu9250* mpu,
  enum mpu9250_protocol protocol,
  void* ctx
)
{
  if (mpu->cs_port == NULL || mpu->cs_pin > (1u << 16))
  {
    return NEX_FAILURE;
  }

  struct ioops* ops;

  switch (protocol)
  {
    case MPU9250_PROTOCOL_I2C:
      // TODO: Implement I2C.
      return NEX_FAILURE;

    case MPU9250_PROTOCOL_SPI:
      // We configure the backend to
      // automatically skip dummy bytes
      // before the actual payload.
      struct beio_spi* beiospi = (struct beio_spi*) ctx;
      beiospi->cflags |= BEIO_SPI_CFLAG_SKIP_DUMMY_DATA;
      beiospi->dummy = 0x00;
      ops = &ioops_spi;
      break;

    default:
      return NEX_FAILURE;
  }

  mpu->beio->ops = ops;
  mpu->beio->ctx = ctx;

  return NEX_SUCCESS;
}

static void
_cs_low(
  struct mpu9250* mpu
)
{
  gpioif_pin_set_low(mpu->cs_port, mpu->cs_pin);
}

static void
_cs_high(
  struct mpu9250* mpu
)
{
  gpioif_pin_set_high(mpu->cs_port, mpu->cs_pin);
}

static u32
_read_reg_sync(
  struct mpu9250* mpu,
  u8 reg,
  u8* response
)
{
  _cs_low(mpu);

  reg |= 0x80;
  if (beio_write(mpu->beio, &reg, 1) != 1)
  {
    return NEX_FAILURE;
  }

  if (beio_read(mpu->beio, response, 1) != 1)
  {
    return NEX_FAILURE;
  }

  _cs_high(mpu);
  return NEX_SUCCESS;
}

static u32
_write_reg_sync(
  struct mpu9250* mpu,
  u8 reg,
  u8 value
)
{
  _cs_low(mpu);

  if (beio_write(mpu->beio, &reg, 1) != 1)
  {
    return NEX_FAILURE;
  }

  if (beio_write(mpu->beio, &value, 1) != 1)
  {
    return NEX_FAILURE;
  }

  _cs_high(mpu);
  return NEX_SUCCESS;
}

static u32
_read_regs_sync(
  struct mpu9250* mpu,
  u8 reg,
  u8* buf,
  u32 count
)
{
  _cs_low(mpu);

  reg |= 0x80;
  if (beio_write(mpu->beio, &reg, 1) != 1)
  {
    return NEX_FAILURE;
  }

  if (beio_read(mpu->beio, buf, count) != count)
  {
    return NEX_FAILURE;
  }

  _cs_high(mpu);
  return NEX_SUCCESS;
}

static u32
_write_regs_sync(
  struct mpu9250* mpu,
  u8 reg,
  u8* buf,
  u32 count
)
{
  _cs_low(mpu);

  if (beio_write(mpu->beio, &reg, 1) != 1)
  {
    return NEX_FAILURE;
  }

  if (beio_write(mpu->beio, buf, count) != count)
  {
    return NEX_FAILURE;
  }

  _cs_high(mpu);
  return NEX_SUCCESS;
}

static void
_decode_vec16(
  struct mpu9250_vec16* vec,
  u8* buf
)
{
  const i16 x = (i16) ((buf[0] << 8) | buf[1]);
  const i16 y = (i16) ((buf[2] << 8) | buf[3]);
  const i16 z = (i16) ((buf[4] << 8) | buf[5]);

  vec->x = x;
  vec->y = y;
  vec->z = z;
}

static void
_encode_vec16(
  struct mpu9250_vec16* vec,
  u8* buf
)
{
  buf[0] = (u8) (vec->x >> 8);
  buf[1] = (u8) vec->x;

  buf[2] = (u8) (vec->y >> 8);
  buf[3] = (u8) vec->y;

  buf[4] = (u8) (vec->z >> 8);
  buf[5] = (u8) vec->z;
}

u32
mpu9250_get_self_test_gyro(
  struct mpu9250* mpu,
  struct mpu9250_vec8* vec
)
{
  u8 buf[3];
  buf[0] = vec->x;
  buf[1] = vec->y;
  buf[2] = vec->z;
  return _read_regs_sync(mpu, MPU9250_REG_SELF_TEST_X_GYRO, buf, 3);
}

u32
mpu9250_get_self_test_accel(
  struct mpu9250* mpu,
  struct mpu9250_vec8* vec
)
{
  u8 buf[3];
  buf[0] = vec->x;
  buf[1] = vec->y;
  buf[2] = vec->z;
  return _read_regs_sync(mpu, MPU9250_REG_SELF_TEST_X_ACCEL, buf, 3);
}

u32
mpu9250_get_gyro_offset(
  struct mpu9250* mpu,
  struct mpu9250_vec16* vec
)
{
  u8 buf[6];
  u32 res = _read_regs_sync(mpu, MPU9250_REG_XG_OFFSET_H, buf, 6);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  _decode_vec16(vec, buf);
  return NEX_SUCCESS;
}

u32
mpu9250_set_gyro_offset(
  struct mpu9250* mpu,
  struct mpu9250_vec16* vec
)
{
  u8 buf[6];
  _encode_vec16(vec, buf);
  return _write_regs_sync(mpu, MPU9250_REG_XG_OFFSET_H, buf, 6);
}

u32
mpu9250_get_sample_rate_div(
  struct mpu9250* mpu,
  u8* sample_rate
)
{
  return _read_reg_sync(mpu, MPU9250_REG_SMPLRT_DIV, sample_rate);
}

u32
mpu9250_set_sample_rate_div(
  struct mpu9250* mpu,
  u8 sample_rate
)
{
  return _write_reg_sync(mpu, MPU9250_REG_SMPLRT_DIV, sample_rate);
}

u32
mpu9250_set_digital_low_pass_filter(
  struct mpu9250* mpu,
  u32 value
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return NEX_FAILURE;
  }

  constexpr u32 shift = MPU9250_CONFIGURATION_DLPF_SHIFT;
  constexpr u32 mask = MPU9250_CONFIGURATION_DLPF_MASK;
  config &= (u8) ~(mask << shift);
  config |= (u8) (value << shift);

  return _write_reg_sync(mpu, MPU9250_REG_CONFIG, config);
}

u32
mpu9250_set_ext_sync(
  struct mpu9250* mpu,
  enum mpu9250_ext_sync sync
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_CONFIGURATION_DLPF_SHIFT;
  constexpr u32 mask = MPU9250_CONFIGURATION_DLPF_MASK;

  config &= (u8) ~(mask << shift);

  switch (sync)
  {
    case MPU9250_EXT_SYNC_OFF:
      break;

    case MPU9250_EXT_SYNC_TEMP_OUT:
      config |= (MPU9250_CONFIG_EXT_SYNC_SET_TEMP_OUT_L << shift);
      break;

    case MPU9250_EXT_SYNC_GYRO_XOUT:
      config |= (MPU9250_CONFIG_EXT_SYNC_SET_GYRO_XOUT_L << shift);
      break;

    case MPU9250_EXT_SYNC_GYRO_YOUT:
      config |= (MPU9250_CONFIG_EXT_SYNC_SET_GYRO_YOUT_L << shift);
      break;

    case MPU9250_EXT_SYNC_GYRO_ZOUT:
      config |= (MPU9250_CONFIG_EXT_SYNC_SET_GYRO_ZOUT_L << shift);
      break;

    case MPU9250_EXT_SYNC_ACCEL_XOUT:
      config |= (MPU9250_CONFIG_EXT_SYNC_SET_ACCEL_XOUT_L << shift);
      break;

    case MPU9250_EXT_SYNC_ACCEL_YOUT:
      config |= (MPU9250_CONFIG_EXT_SYNC_SET_ACCEL_YOUT_L << shift);
      break;

    case MPU9250_EXT_SYNC_ACCEL_ZOUT:
      config |= (MPU9250_CONFIG_EXT_SYNC_SET_ACCEL_ZOUT_L << shift);
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_ext_sync, sync);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_CONFIG, config);
}

u32
mpu9250_circular_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_CONFIGURATION_FIFO_MODE;
  return _write_reg_sync(mpu, MPU9250_REG_CONFIG, config);
}

u32
mpu9250_circular_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_CONFIGURATION_FIFO_MODE;
  return _write_reg_sync(mpu, MPU9250_REG_CONFIG, config);
}

u32
mpu9250_set_config_reg(
  struct mpu9250* mpu,
  u8 reg
)
{
  return _write_reg_sync(mpu, MPU9250_REG_CONFIG, reg);
}

u32
mpu9250_set_fchoice(
  struct mpu9250* mpu,
  u32 choice
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_GYRO_CONFIG_FCHOICE_SHIFT;
  constexpr u32 mask = MPU9250_GYRO_CONFIG_FCHOICE_MASK;

  config &= (u8) ~(mask << shift);
  config |= (u8) (choice << shift);

  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_set_gyro_full_scale(
  struct mpu9250* mpu,
  enum mpu9250_gyro_full_scale fs
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_GYRO_CONFIG_GYRO_FS_SEL_SHIFT;
  constexpr u32 mask = MPU9250_GYRO_CONFIG_GYRO_FS_SEL_MASK;

  config &= (u8) ~(mask << shift);

  switch (fs)
  {
    case GYRO_FULL_SCALE_P250dps:
      break;

    case GYRO_FULL_SCALE_P500dps:
      config |= (MPU9250_GYRO_CONFIG_GYRO_FS_SEL_500DPS << shift);
      break;

    case GYRO_FULL_SCALE_P1000dps:
      config |= (MPU9250_GYRO_CONFIG_GYRO_FS_SEL_1000DPS << shift);
      break;

    case GYRO_FULL_SCALE_P2000dps:
      config |= (MPU9250_GYRO_CONFIG_GYRO_FS_SEL_2000DPS << shift);
      break;

    default:
      devmode_error_invalid_enum(enum gyro_full_scale, fs);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_zgyro_self_test_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_GYRO_CONFIG_ZGYRO_CTEN;
  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_zgyro_self_test_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_GYRO_CONFIG_ZGYRO_CTEN;
  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_ygyro_self_test_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_GYRO_CONFIG_YGYRO_CTEN;
  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_ygyro_self_test_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8)(u8)  ~MPU9250_GYRO_CONFIG_YGYRO_CTEN;
  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_xgyro_self_test_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_GYRO_CONFIG_XGYRO_CTEN;
  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_xgyro_self_test_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_GYRO_CONFIG_XGYRO_CTEN;
  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, config);
}

u32
mpu9250_set_gyro_config_reg(
  struct mpu9250* mpu,
  u8 reg
)
{
  return _write_reg_sync(mpu, MPU9250_REG_GYRO_CONFIG, reg);
}

u32
mpu9250_set_accel_full_scale(
  struct mpu9250* mpu,
  enum mpu9250_accel_full_scale fs
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }
  
  constexpr u32 shift = MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_SHIFT;
  constexpr u32 mask = MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_MASK;

  config &= (u8) ~(mask << shift);

  switch (fs)
  {
    case MPU9250_ACCEL_FULL_SCALE_PM_2g:
      break;

    case MPU9250_ACCEL_FULL_SCALE_PM_4g:
      config |= (MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_PM_4G << shift);
      break;

    case MPU9250_ACCEL_FULL_SCALE_PM_8g:
      config |= (MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_PM_8G << shift);
      break;

    case MPU9250_ACCEL_FULL_SCALE_PM_16g:
      config |= (MPU9250_ACCEL_CONFIG_ACCEL_FS_SEL_PM_16G << shift);
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_accel_full_scale, fs);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, config);
}

u32
mpu9250_zaccel_self_test_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_ACCEL_CONFIG_STZ;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, config);
}

u32
mpu9250_zaccel_self_test_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_ACCEL_CONFIG_STZ;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, config);
}

u32
mpu9250_yaccel_self_test_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_ACCEL_CONFIG_STY;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, config);
}

u32
mpu9250_yaccel_self_test_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_ACCEL_CONFIG_STY;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, config);
}

u32
mpu9250_xaccel_self_test_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_ACCEL_CONFIG_STX;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, config);
}

u32
mpu9250_xaccel_self_test_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_ACCEL_CONFIG_STX;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG, config);
}

u32
mpu9250_set_accel_low_pass_filter(
  struct mpu9250* mpu,
  u32 filter
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG2, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_ACCEL_CONFIG2_DLPFCFG_SHIFT;
  constexpr u32 mask = MPU9250_ACCEL_CONFIG2_DLPFCFG_MASK;

  config &= (u8) ~(mask << shift);
  config |= (u8) (filter << shift);

  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG2, config);
}

u32
mpu9250_accel_fchoice_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG2, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_ACCEL_CONFIG2_ACCEL_FCHOICE;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG2, config);
}

u32
mpu9250_accel_fchoice_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG2, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_ACCEL_CONFIG2_ACCEL_FCHOICE;
  return _write_reg_sync(mpu, MPU9250_REG_ACCEL_CONFIG2, config);
}

u32
mpu9250_set_low_power_accel_clksrc(
  struct mpu9250* mpu,
  u8 clksel
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_LP_ACCEL_ODR, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_LPACCEL_ODR_LPOSC_CLKSEL_SHIFT;
  constexpr u32 mask = MPU9250_LPACCEL_ODR_LPOSC_CLKSEL_MASK;

  config &= (u8) ~(mask << shift);
  config |= (clksel << shift);

  return _write_reg_sync(mpu, MPU9250_REG_LP_ACCEL_ODR, config);
}

u32
mpu9250_set_wom_threshold(
  struct mpu9250* mpu,
  u8 value
)
{
  return _write_reg_sync(mpu, MPU9250_REG_WOM_THR, value);
}

u32
mpu9250_slv0_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_SLV0;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_slv0_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_SLV0;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_slv1_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_SLV1;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_slv1_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_SLV1;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_slv2_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_SLV2;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_slv2_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_SLV2;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_accel_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_ACCEL;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_accel_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_ACCEL;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_zgyro_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_GYRO_ZOUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_zgyro_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_GYRO_ZOUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_ygyro_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_GYRO_YOUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_ygyro_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_GYRO_YOUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_xgyro_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_GYRO_XOUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_xgyro_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_GYRO_XOUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_temp_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_FIFOEN_TEMP_OUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_temp_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_FIFO_EN, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_FIFOEN_TEMP_OUT;
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, config);
}

u32
mpu9250_set_fifo_en_reg(
  struct mpu9250* mpu,
  u8 reg
)
{
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_EN, reg);
}

u32
mpu9250_set_i2c_master_clk_div(
  struct mpu9250* mpu,
  enum mpu9250_i2c_master_clk_div div
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_I2C_MSTCTRL_MSTCLK_SHIFT;
  constexpr u32 mask = MPU9250_I2C_MSTCTRL_MSTCLK_MASK;

  config &= (u8) ~(mask << shift);

  switch (div)
  {
    case MPU9250_I2C_MASTER_CLK_DIV_DIV16:
      config |= (MPU9250_I2C_MSTCTRL_DIV16 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV17:
      config |= (MPU9250_I2C_MSTCTRL_DIV17 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV18:
      config |= (MPU9250_I2C_MSTCTRL_DIV18 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV19:
      config |= (MPU9250_I2C_MSTCTRL_DIV19 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV20:
      config |= (MPU9250_I2C_MSTCTRL_DIV20 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV21:
      config |= (MPU9250_I2C_MSTCTRL_DIV21 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV22:
      config |= (MPU9250_I2C_MSTCTRL_DIV22 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV23:
      config |= (MPU9250_I2C_MSTCTRL_DIV23 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV24:
      config |= (MPU9250_I2C_MSTCTRL_DIV24 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV25:
      config |= (MPU9250_I2C_MSTCTRL_DIV25 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV26:
      config |= (MPU9250_I2C_MSTCTRL_DIV26 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV27:
      config |= (MPU9250_I2C_MSTCTRL_DIV27 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV28:
      config |= (MPU9250_I2C_MSTCTRL_DIV28 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV29:
      config |= (MPU9250_I2C_MSTCTRL_DIV29 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV30:
      config |= (MPU9250_I2C_MSTCTRL_DIV30 << shift);
      break;

    case MPU9250_I2C_MASTER_CLK_DIV_DIV31:
      config |= (MPU9250_I2C_MSTCTRL_DIV31 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_i2c_master_clk_div, div);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_set_i2c_master_slaves_transitions(
  struct mpu9250* mpu,
  enum mpu9250_i2c_master_slaves_transitions transition
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (transition)
  {
    case MPU9250_SET_I2C_MASTER_SLAVES_TRANSITIONS_RESTART:
      config &= (u8) ~MPU9250_MSTCTRL_I2C_MST_P_NSR;
      break;

    case MPU9250_SET_I2C_MASTER_SLAVES_TRANSITIONS_STOP:
      config |= MPU9250_MSTCTRL_I2C_MST_P_NSR;
      break;

    default:
      devmode_error_invalid_enum(
        enum mpu9250_set_i2c_master_slaves_transitions,
        transition
      );
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_slv3_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_MSTCTRL_SLV_3_FIFO_EN;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_slv3_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_MSTCTRL_SLV_3_FIFO_EN;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_data_ready_int_delay_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_MSTCTRL_WAIT_FOR_ES;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_data_ready_int_delay_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_MSTCTRL_WAIT_FOR_ES;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_i2c_multi_master_enable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config |= MPU9250_MSTCTRL_MULT_MST_EN;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_i2c_multi_master_disable(
  struct mpu9250* mpu
)
{
  u8 config;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &config);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  config &= (u8) ~MPU9250_MSTCTRL_MULT_MST_EN;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, config);
}

u32
mpu9250_set_slave_dst(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  enum mpu9250_transfer transfer,
  u8 addr
)
{
  switch (transfer)
  {
    case MPU9250_TRANSFER_READ:
      addr |= 0x80;
      break;

    case MPU9250_TRANSFER_WRITE:
      addr &= (u8) ~0x80;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_transfer, transfer);
      return NEX_FAILURE;
  }

  u32 res;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_ADDR, addr);
      if (res != NEX_SUCCESS)
      {
        return res;
      }
      break;

    case MPU9250_SLAVE1:
      res = _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_ADDR, addr);
      if (res != NEX_SUCCESS)
      {
        return res;
      }
      break;

    case MPU9250_SLAVE2:
      res = _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_ADDR, addr);
      if (res != NEX_SUCCESS)
      {
        return res;
      }
      break;

    case MPU9250_SLAVE3:
      res = _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_ADDR, addr);
      if (res != NEX_SUCCESS)
      {
        return res;
      }
      break;

    case MPU9250_SLAVE4:
      res = _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_ADDR, addr);
      if (res != NEX_SUCCESS)
      {
        return res;
      }
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

u32
mpu9250_set_slave_addr_src(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  u8 addr
)
{
  switch (slave)
  {
    case MPU9250_SLAVE0:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_REG, addr);

    case MPU9250_SLAVE1:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_REG, addr);

    case MPU9250_SLAVE2:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_REG, addr);

    case MPU9250_SLAVE3:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_REG, addr);

    case MPU9250_SLAVE4:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_REG, addr);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

u32
mpu9250_set_slave_bytes_count(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  u8 count
)
{
  constexpr u32 shift = MPU9250_I2C_SLV_CTRL_LEN_SHIFT;
  constexpr u32 mask = MPU9250_I2C_SLV_CTRL_LEN_MASK;

  u32 res;
  u8 reg;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~(mask << shift);
      reg |= (count << shift);
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, reg);

    case MPU9250_SLAVE1:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~(mask << shift);
      reg |= (count << shift);
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, reg);

    case MPU9250_SLAVE2:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~(mask << shift);
      reg |= (count << shift);
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, reg);

    case MPU9250_SLAVE3:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~(mask << shift);
      reg |= (count << shift);
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, reg);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

static u32
_set_slave_grp(
  u8* reg,
  enum mpu9250_slave_group group
)
{
  switch (group)
  {
    case MPU9250_SLAVE_GROUP_EVEN:
      *reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_GRP;
      return NEX_SUCCESS;

    case MPU9250_SLAVE_GROUP_ODD:
      *reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_GRP;
      return NEX_SUCCESS;

    default:
      return NEX_FAILURE;
  }
}

u32
mpu9250_set_slave_group_type(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  enum mpu9250_slave_group group
)
{
  u32 res;
  u8 reg;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      res = _set_slave_grp(&reg, group);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, reg);

    case MPU9250_SLAVE1:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      res = _set_slave_grp(&reg, group);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, reg);

    case MPU9250_SLAVE2:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      res = _set_slave_grp(&reg, group);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, reg);

    case MPU9250_SLAVE3:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      res = _set_slave_grp(&reg, group);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, reg);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

u32
mpu9250_slave_reg_bypass_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
)
{
  u32 res;
  u8 reg;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, reg);

    case MPU9250_SLAVE1:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, reg);

    case MPU9250_SLAVE2:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, reg);

    case MPU9250_SLAVE3:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, reg);

    case MPU9250_SLAVE4:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, reg);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

u32
mpu9250_slave_reg_bypass_disable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
)
{
  u32 res;
  u8 reg;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, reg);

    case MPU9250_SLAVE1:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, reg);

    case MPU9250_SLAVE2:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }
      
      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, reg);

    case MPU9250_SLAVE3:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, reg);

    case MPU9250_SLAVE4:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_REG_DIS;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, reg);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

u32
mpu9250_slave_bytes_swap_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
)
{
  u32 res;
  u8 reg;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, reg);

    case MPU9250_SLAVE1:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, reg);

    case MPU9250_SLAVE2:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, reg);

    case MPU9250_SLAVE3:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, reg);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

u32
mpu9250_slave_bytes_swap_disable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
)
{
  u32 res;
  u8 reg;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, reg);

    case MPU9250_SLAVE1:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, reg);

    case MPU9250_SLAVE2:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, reg);

    case MPU9250_SLAVE3:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg &= (u8) ~MPU9250_I2C_SLV_CTRL_I2C_SLV_BYTE_SW;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, reg);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

u32
mpu9250_slave_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
)
{
  u32 res;
  u8 reg;
  switch (slave)
  {
    case MPU9250_SLAVE0:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_EN;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_CTRL, reg);

    case MPU9250_SLAVE1:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_EN;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_CTRL, reg);

    case MPU9250_SLAVE2:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_EN;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_CTRL, reg);

    case MPU9250_SLAVE3:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_EN;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_CTRL, reg);

    case MPU9250_SLAVE4:
      res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, &reg);
      if (res != NEX_SUCCESS)
      {
        return res;
      }

      reg |= MPU9250_I2C_SLV_CTRL_I2C_SLV_EN;
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, reg);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_SUCCESS;
  }
}

u32
mpu9250_set_slave_data(
  struct mpu9250* mpu,
  enum mpu9250_slave slave,
  u8 data
)
{
  switch (slave)
  {
    case MPU9250_SLAVE0:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV0_DO, data);

    case MPU9250_SLAVE1:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV1_DO, data);

    case MPU9250_SLAVE2:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV2_DO, data);

    case MPU9250_SLAVE3:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV3_DO, data);

    case MPU9250_SLAVE4:
      return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_DO, data);

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }
}

u32
mpu9250_set_slave4_delay(
  struct mpu9250* mpu,
  u8 delay
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_I2C_SLV4_DI_SHIFT;
  constexpr u32 mask = MPU9250_I2C_SLV4_DI_MASK;

  reg &= (u8) ~(mask << shift);
  reg |= (delay << shift);

  return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, reg);
}

u32
mpu9250_slave4_int_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_I2C_SLV4_CTRL_SLV4_DONE_INT_EN;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, reg);
}

u32
mpu9250_slave4_int_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_I2C_SLV4_CTRL_SLV4_DONE_INT_EN;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_SLV4_CTRL, reg);
}

u32
mpu9250_get_slave4_data(
  struct mpu9250* mpu,
  u8* data
)
{
  return _read_reg_sync(mpu, MPU9250_REG_I2C_SLV4_DI, data);
}

u32
mpu9250_is_flag_set(
  struct mpu9250* mpu,
  enum mpu9250_flag flag,
  u8* result
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_STATUS, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (flag)
  {
    case MPU9250_FLAG_SLAVE0_NACK:
      *result = reg & MPU9250_MST_STATUS_I2C_SLV0_NACK;
      break;

    case MPU9250_FLAG_SLAVE1_NACK:
      *result = reg & MPU9250_MST_STATUS_I2C_SLV1_NACK;
      break;

    case MPU9250_FLAG_SLAVE2_NACK:
      *result = reg & MPU9250_MST_STATUS_I2C_SLV2_NACK;
      break;

    case MPU9250_FLAG_SLAVE3_NACK:
      *result = reg & MPU9250_MST_STATUS_I2C_SLV3_NACK;
      break;

    case MPU9250_FLAG_SLAVE4_NACK:
      *result = reg & MPU9250_MST_STATUS_I2C_SLV4_NACK;
      break;

    case MPU9250_FLAG_LOST_ARB:
      *result = reg & MPU9250_MST_STATUS_I2C_LOST_ARB;
      break;

    case MPU9250_FLAG_SLAVE4_DONE:
      *result = reg & MPU9250_MST_STATUS_I2C_SLV4_DONE;
      break;

    case MPU9250_FLAG_PASS_THROUGH:
      *result = reg & MPU9250_MST_STATUS_PASS_THROUGH;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_flag, flag);
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

u32
mpu9250_i2c_master_bypass_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_INT_PIN_CFG_BYPASS_EN;
  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_i2c_master_bypass_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_INT_PIN_CFG_BYPASS_EN;
  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_set_fsync_interrupt_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_INT_PIN_CFG_FSYNC_INT_MODE_EN;
  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_set_fsync_interrupt_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_INT_PIN_CFG_FSYNC_INT_MODE_EN;
  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_set_fsync_logic(
  struct mpu9250* mpu,
  enum mpu9250_fsync_logic logic
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (logic)
  {
    case MPU9250_FSYNC_LOGIC_ACTIVE_LOW:
      reg |= MPU9250_INT_PIN_CFG_ACTL_FSYNC;
      break;

    case MPU9250_FSYNC_LOGIC_ACTIVE_HIGH:
      reg &= (u8) ~MPU9250_INT_PIN_CFG_ACTL_FSYNC;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_fsync_logic, logic);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_set_int_status_clear_policy(
  struct mpu9250* mpu,
  enum mpu9250_int_status_clear_policy policy
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (policy)
  {
    case MPU9250_INT_STATUS_CLEAR_POLICY_ANY_READ:
      reg |= MPU9250_INT_STATUS_CLEAR_POLICY_ANY_READ;
      break;

    case MPU9250_INT_STATUS_CLEAR_POLICY_STATUS_REG:
      reg &= (u8) ~MPU9250_INT_STATUS_CLEAR_POLICY_ANY_READ;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_int_status_clear_policy, policy);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_set_int_pin_latch(
  struct mpu9250* mpu,
  enum mpu9250_int_pin_latch latch
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (latch)
  {
    case MPU9250_INT_PIN_LATCH_MANUAL:
      reg |= MPU9250_INT_PIN_CFG_LATCH_INT_EN;
      break;

    case MPU9250_INT_PIN_LATCH_AUTO:
      reg &= (u8) ~MPU9250_INT_PIN_CFG_LATCH_INT_EN;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_int_pin_latch, latch);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_set_int_pin_mode(
  struct mpu9250* mpu,
  enum mpu9250_int_pin_mode mode
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (mode)
  {
    case MPU9250_INT_PIN_MODE_OPEN_DRAIN:
      reg |= MPU9250_INT_PIN_CFG_OPEN;
      break;

    case MPU9250_INT_PIN_MODE_PUSHPULL:
      reg &= (u8) ~MPU9250_INT_PIN_CFG_OPEN;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_int_pin_mode, mode);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

u32
mpu9250_set_int_pin_logic(
  struct mpu9250* mpu,
  enum mpu9250_int_pin_logic logic
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (logic)
  {
    case MPU9250_INT_PIN_LOGIC_ACTIVE_LOW:
      reg |= MPU9250_INT_PIN_CFG_ACTL;
      break;

    case MPU9250_INT_PIN_LOGIC_ACTIVE_HIGH:
      reg &= (u8) ~MPU9250_INT_PIN_CFG_ACTL;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_int_pin_logic, logic);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_INT_PIN_CFG, reg);
}

// Here
u32
mpu9250_interrupt_enable(
  struct mpu9250* mpu,
  enum mpu9250_interrupt interrupt
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_ENABLE, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (interrupt)
  {
    case MPU9250_INTERRUPT_RAW_DATA_READY:
      reg |= MPU9250_INT_ENABLE_RAW_RDY_EN;
      break;

    case MPU9250_INTERRUPT_FSYNC:
      reg |= MPU9250_INT_ENABLE_FSYNC_INT_EN;
      break;

    case MPU9250_INTERRUPT_FIFO_OVERFLOW:
      reg |= MPU9250_INT_ENABLE_FIFO_OVERFLOW_EN;
      break;

    case MPU9250_INTERRUPT_WOM:
      reg |= MPU9250_INT_ENABLE_WOM_EN;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_interrupt, interrupt);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_INT_ENABLE, reg);
}

u32
mpu9250_interrupt_disable(
  struct mpu9250* mpu,
  enum mpu9250_interrupt interrupt
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_ENABLE, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (interrupt)
  {
    case MPU9250_INTERRUPT_RAW_DATA_READY:
      reg &= (u8) ~MPU9250_INT_ENABLE_RAW_RDY_EN;
      break;

    case MPU9250_INTERRUPT_FSYNC:
      reg &= (u8) ~MPU9250_INT_ENABLE_FSYNC_INT_EN;
      break;

    case MPU9250_INTERRUPT_FIFO_OVERFLOW:
      reg &= (u8) ~MPU9250_INT_ENABLE_FIFO_OVERFLOW_EN;
      break;

    case MPU9250_INTERRUPT_WOM:
      reg &= (u8) ~MPU9250_INT_ENABLE_WOM_EN;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_interrupt, interrupt);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_INT_ENABLE, reg);
}

u32
mpu9250_set_interrupt_enable_reg(
  struct mpu9250* mpu,
  u8 reg
)
{
  return _write_reg_sync(mpu, MPU9250_REG_INT_ENABLE, reg);
}

u32
mpu9250_is_interrupt_occured(
  struct mpu9250* mpu,
  enum mpu9250_interrupt interrupt,
  u8* result
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_INT_STATUS, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (interrupt)
  {
    case MPU9250_INTERRUPT_RAW_DATA_READY:
      *result = reg & MPU9250_INT_STATUS_RAW_DATA_RDY_INT;
      break;

    case MPU9250_INTERRUPT_FSYNC:
      *result = reg & MPU9250_INT_STATUS_FSYNC_INT;
      break;

    case MPU9250_INTERRUPT_FIFO_OVERFLOW:
      *result = reg & MPU9250_INT_STATUS_FIFO_OVERFLOW_INT;
      break;

    case MPU9250_INTERRUPT_WOM:
      *result = reg & MPU9250_INT_STATUS_WOM_INT;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_interrupt, interrupt);
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

u32
mpu9250_get_int_status_reg(
  struct mpu9250* mpu,
  u8* res
)
{
  return _read_reg_sync(mpu, MPU9250_REG_INT_STATUS, res);
}

u32
mpu9250_get_accel(
  struct mpu9250* mpu,
  struct mpu9250_vec16* vec
)
{
  u8 buf[6];
  u32 res = _read_regs_sync(mpu, MPU9250_REG_ACCEL_XOUT_H, buf, 6);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  _decode_vec16(vec, buf);
  return NEX_SUCCESS;
}

u32
mpu9250_get_temperature_raw(
  struct mpu9250* mpu,
  u16* raw
)
{
  u8 buf[2];
  u32 res = _read_regs_sync(mpu, MPU9250_REG_TEMP_OUT_H, buf, 2);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  *raw = (u16) ((buf[0] << 8) | buf[1]);
  return NEX_SUCCESS;
}

u32
mpu9250_get_temperature(
  struct mpu9250* mpu,
  u32 offset,
  float sensitivity,
  float* temp
)
{
  u16 temperature;
  u32 res = mpu9250_get_temperature_raw(mpu, &temperature);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  // According to the formula in the datasheet:
  // TEMP_degC = ((TEMP_OUT - RoomTemp_Offset) / Temp_Sensitivity) + 21degC
  // Where:
  // - Temp_degC:
  //   Is the temperature in degrees C measured by the temperature sensor.
  // - TEMP_OUT:
  //   Is the actual output of the temperature sensor.
  temperature -= (u16) offset;
  float result = (float) temperature / sensitivity;
  *temp = result + 21.0f;

  return NEX_SUCCESS;
}

u32
mpu9250_get_gyro(
  struct mpu9250* mpu,
  struct mpu9250_vec16* vec
)
{
  u8 buf[6];
  u32 res = _read_regs_sync(mpu, MPU9250_REG_GYRO_XOUT_H, buf, 6);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  _decode_vec16(vec, buf);
  return NEX_SUCCESS;
}

u32
mpu9250_get_ext_sensor_data(
  struct mpu9250* mpu,
  u8 start_reg,
  u32 count,
  u8* buf
)
{
  return _read_regs_sync(mpu, MPU9250_REG_EXT_SENS_DATA_00 + start_reg, buf, count);
}

u32
mpu9250_i2c_slave_delay_enable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (slave)
  {
    case MPU9250_SLAVE0:
      reg |= MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV0_DLY_EN;
      break;

    case MPU9250_SLAVE1:
      reg |= MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV1_DLY_EN;
      break;

    case MPU9250_SLAVE2:
      reg |= MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV2_DLY_EN;
      break;

    case MPU9250_SLAVE3:
      reg |= MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV3_DLY_EN;
      break;

    case MPU9250_SLAVE4:
      reg |= MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV4_DLY_EN;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_DELAY_CTRL, reg);
}

u32
mpu9250_i2c_slave_delay_disable(
  struct mpu9250* mpu,
  enum mpu9250_slave slave
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  switch (slave)
  {
    case MPU9250_SLAVE0:
      reg &= (u8) ~MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV0_DLY_EN;
      break;

    case MPU9250_SLAVE1:
      reg &= (u8) ~MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV1_DLY_EN;
      break;

    case MPU9250_SLAVE2:
      reg &= (u8) ~MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV2_DLY_EN;
      break;

    case MPU9250_SLAVE3:
      reg &= (u8) ~MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV3_DLY_EN;
      break;

    case MPU9250_SLAVE4:
      reg &= (u8) ~MPU9250_I2C_MST_DELAY_CTRL_I2C_SLV4_DLY_EN;
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_slave, slave);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_DELAY_CTRL, reg);
}

u32
mpu9250_delay_sensor_data_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_DELAY_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_I2C_MST_DELAY_CTRL_DELAY_ES_SHADOW;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_DELAY_CTRL, reg);
}

u32
mpu9250_delay_sensor_data_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_I2C_MST_DELAY_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_I2C_MST_DELAY_CTRL_DELAY_ES_SHADOW;
  return _write_reg_sync(mpu, MPU9250_REG_I2C_MST_DELAY_CTRL, reg);
}

u32
mpu9250_temp_reset(
  struct mpu9250* mpu
)
{
  return _write_reg_sync(
    mpu,
    MPU9250_REG_SIGNAL_PATH_RESET,
    MPU9250_SIGNAL_PATH_RESET_TEMP_RST
  );
}

u32
mpu9250_accel_reset(
  struct mpu9250* mpu
)
{
  return _write_reg_sync(
    mpu,
    MPU9250_REG_SIGNAL_PATH_RESET,
    MPU9250_SIGNAL_PATH_RESET_ACCEL_RST
  );
}

u32
mpu9250_gyro_reset(
  struct mpu9250* mpu
)
{
  return _write_reg_sync(
    mpu,
    MPU9250_REG_SIGNAL_PATH_RESET,
    MPU9250_SIGNAL_PATH_RESET_TEMP_RST
  );
}

u32
mpu9250_accel_intel_mode_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_MOT_DETECT_CTRL_ACCEL_INTEL_MODE;
  return _write_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, reg);
}

u32
mpu9250_accel_intel_mode_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_MOT_DETECT_CTRL_ACCEL_INTEL_MODE;
  return _write_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, reg);
}

u32
mpu9250_wom_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_MOT_DETECT_CTRL_ACCEL_INTEL_EN;
  return _write_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, reg);
}

u32
mpu9250_wom_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_MOT_DETECT_CTRL_ACCEL_INTEL_EN;
  return _write_reg_sync(mpu, MPU9250_REG_MOT_DETECT_CTRL, reg);
}

u32
mpu9250_reset_sensors(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_USER_CTRL_SIG_COND_RST;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_reset_i2c(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_USER_CTRL_I2C_MST_RST;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_reset_fifo(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_USER_CTRL_FIFO_RST;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_i2c_if_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_USER_CTRL_I2C_IF_DIS;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_i2c_if_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_USER_CTRL_I2C_IF_DIS;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_i2c_master_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_USER_CTRL_I2C_MST_EN;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_i2c_master_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_USER_CTRL_I2C_MST_EN;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_fifo_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_USER_CTRL_FIFO_EN;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_fifo_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_USER_CTRL, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_USER_CTRL_FIFO_EN;
  return _write_reg_sync(mpu, MPU9250_REG_USER_CTRL, reg);
}

u32
mpu9250_set_clk_source(
  struct mpu9250* mpu,
  enum mpu9250_clk_source src
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = MPU9250_PWR_MGMT1_CLKSEL_SHIFT;
  constexpr u32 mask = MPU9250_PWR_MGMT1_CLKSEL_MASK;

  reg &= (u8) ~(mask << shift);

  switch (src)
  {
    case MPU9250_CLK_SOURCE_INTERNAL_20MHZ:
      break;

    case MPU9250_CLK_SOURCE_AUTO:
      reg |= (MPU9250_PWR_MGMT1_CLKSEL_AUTO << shift);
      break;

    case MPU9250_CLK_SOURCE_STOP:
      reg |= (MPU9250_PWR_MGMT1_CLKSEL_CLKOFF << shift);
      break;

    default:
      devmode_error_invalid_enum(enum mpu9250_clk_source, src);
      return NEX_FAILURE;
  }

  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_ptat_power_down_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_PWR_MGMT1_PD_PTAT;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_ptat_power_down_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_PWR_MGMT1_PD_PTAT;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_gyro_standby_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_PWR_MGMT1_GYRO_STANDBY;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_gyro_standby_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_PWR_MGMT1_GYRO_STANDBY;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_low_power_sample_cycles_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_PWR_MGMT1_CYCLE;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_low_power_sample_cycles_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_PWR_MGMT1_CYCLE;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_sleep_enable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_PWR_MGMT1_SLEEP;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_sleep_disable(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg &= (u8) ~MPU9250_PWR_MGMT1_SLEEP;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_reset(
  struct mpu9250* mpu
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  reg |= MPU9250_PWR_MGMT1_H_RESET;
  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_1, reg);
}

u32
mpu9250_set_gyro_disabled_axis(
  struct mpu9250* mpu,
  u32 disabled_axis
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_2, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = 0;
  reg &= (u8) (~(MPU9250_AXIS_MASK << shift));
  reg |= ((u8) disabled_axis << shift);

  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_2, reg);
}

u32
mpu9250_set_accel_disabled_axis(
  struct mpu9250* mpu,
  u32 disabled_axis
)
{
  u8 reg;
  u32 res = _read_reg_sync(mpu, MPU9250_REG_PWR_MGMT_2, &reg);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  constexpr u32 shift = 3;
  reg &= (u8) (~(MPU9250_AXIS_MASK << shift));
  reg |= ((u8) disabled_axis << shift);

  return _write_reg_sync(mpu, MPU9250_REG_PWR_MGMT_2, reg);
}

u32
mpu9250_get_fifo_bytes_count(
  struct mpu9250* mpu,
  u32* result
)
{
  u8 buf[2];
  u32 res = _read_regs_sync(mpu, MPU9250_REG_FIFO_COUNTH, buf, 2);
  if (res != NEX_SUCCESS)
  {
    return res;
  }

  *result = (u32) ((buf[0] << 8) | buf[1]);
  return NEX_SUCCESS;
}

u32
mpu9250_set_fifo_rw_command(
  struct mpu9250* mpu,
  u8 command
)
{
  return _write_reg_sync(mpu, MPU9250_REG_FIFO_R_W, command);
}

u32
mpu9250_get_device_id(
  struct mpu9250* mpu,
  u8* id
)
{
  return _read_reg_sync(mpu, MPU9250_REG_WHO_AM_I, id);
}

u32
mpu9250_set_accel_offset(
  struct mpu9250* mpu,
  struct mpu9250_vec16* vec
)
{
  u8 buf[6];
  _encode_vec16(vec, buf);
  return _write_regs_sync(mpu, MPU9250_REG_XA_OFFSET_H, buf, 6);
}
