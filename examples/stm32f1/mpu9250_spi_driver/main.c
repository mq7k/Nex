#include "libcom/util.h"
#include "synapse/common/common.h"
#include "synapse/drivers/mpu9250.h"
#include "synapse/io/io_spi.h"
#include "synapse/io/ioif.h"
#include "synapse/soc/stm32/periph/gpio.h"
#include "synapse/soc/stm32/periph/spi.h"
#include "synapse/soc/stm32/periph/usart.h"
#include "libcom/unit.h"
#include "synapse/soc/stm32/periph/rcc.h"

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_SPI1);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
}

void
gpio_setup(void)
{
  gpio_setup_port_pin(
    GPIOA,
    GPIO9,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOA,
    GPIO10,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOA,
    GPIO5,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOA,
    GPIO6,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOA,
    GPIO7,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_ALTFN_PUSHPULL
  );

  gpio_setup_port_pin(
    GPIOA,
    GPIO0,
    GPIO_MODE_OUTPUT_50MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL
  );

  gpio_set_pin_high(GPIOA, GPIO0);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 clock = nex_convert_freq_unit(8, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, clock, baudrate);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  usart_transmitter_enable(USART1);
  usart_parity_control_disable(USART1);
  usart_cts_disable(USART1);
  usart_rts_disable(USART1);
  usart_enable(USART1);
}

void
spi_setup(void)
{
  spi_set_data_frame_format(SPI1, SPI_DATA_FRAME_FORMAT_8BITS);
  spi_set_baudrate_control(SPI1, SPI_BAUDRATE_CONTROL_DIV256);
  spi_set_role(SPI1, SPI_ROLE_MASTER);
  spi_set_frame_format(SPI1, SPI_FRAME_FORMAT_MSB_FIRST);
  spi_software_slave_management_enable(SPI1);
  spi_internal_slave_select_enable(SPI1);
  spi_enable(SPI1);
}

static u32
_enumerate_device(
  struct mpu9250* mpu
)
{
  u8 response;
  u32 res = mpu9250_get_device_id(mpu, &response);
  if (res != NEX_SUCCESS)
  {
    usart_send_strfln(USART1, "Something went wrong");
    return res;
  }

  switch (response)
  {
    case 0x68:
    case 0x69:
      usart_send_strfln(USART1, "Device: MPU6050");
      break;

    case 0x70:
      usart_send_strfln(USART1, "Device: MPU6500");
      break;

    case 0x71:
      usart_send_strfln(USART1, "Device: MPU9250");
      break;

    default:
      usart_send_strfln(USART1, "Device: Unknown");
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

int
main(void)
{
  syn_delay_nop(1000000);

  rcc_setup();
  gpio_setup();
  usart_setup();
  spi_setup();

  gpio_set_pin_high(GPIOA, GPIO0);
  usart_send_strfln(USART1, "Starting communication");

  struct beio_spi bespi = {
    .spiconf = {
      .spi = SPI1,
      .role = SPIIF_ROLE_MASTER,
      .options = SPIIF_CAP_MSB
    }
  };

  struct beio be = {
    .ctx = &bespi,
    .ops = &ioops_spi
  };

  beio_init(&be);

  struct mpu9250 mpu = {
    .beio = &be,
    .cs_port = GPIOA,
    .cs_pin = GPIO0
  };

  mpu9250_sleep_disable(&mpu);
  mpu9250_gyro_standby_disable(&mpu);
  mpu9250_set_clk_source(&mpu, MPU9250_CLK_SOURCE_AUTO);

  if (_enumerate_device(&mpu) != NEX_SUCCESS)
  {
    while (1);
  }

  // Waiting a couple of seconds to simplify reading
  // device enumeration output in the console.
  usart_send_strfln(USART1, "Waiting a couple of seconds...");
  syn_delay_nop(10000000);

  constexpr double gyro_scale = 3.14159265 / 180.0 / 131.0;
  constexpr double accel_scale = 1.0 / 16384;
  while (1)
  {
    float temp;
    mpu9250_get_temperature(&mpu, 0, 333.87f, &temp);

    struct mpu9250_vec16 vec;
    mpu9250_get_gyro(&mpu, &vec);
    double xgyro = (double) vec.x * gyro_scale;
    double ygyro = (double) vec.y * gyro_scale;
    double zgyro = (double) vec.z * gyro_scale;

    mpu9250_get_accel(&mpu, &vec);
    double xaccel = (double) vec.x * accel_scale;
    double yaccel = (double) vec.y * accel_scale;
    double zaccel = (double) vec.z * accel_scale;

    usart_send_strfln(USART1, "Gyro: %f, %f, %f", xgyro, ygyro, zgyro);
    usart_send_strfln(USART1, "Accel: %f, %f, %f", xaccel, yaccel, zaccel);
    usart_send_strfln(USART1, "Temperature: %f°", temp);
    usart_send_strfln(USART1, "=========================");
    syn_delay_nop(2000000);
  }
}
