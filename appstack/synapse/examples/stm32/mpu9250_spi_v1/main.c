#include "libcom/util.h"
#include "synapse/cpu/cortex/drivers/fpu/fpu_v1.h"
#include "synapse/common/util/common.h"
#include "synapse/soc/stm32/drivers/spi/spi_v1.h"
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
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOA,
    GPIO5 | GPIO6 | GPIO7 | GPIO9 | GPIO10,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO0,
    GPIO_MODE_OUTPUT,
    GPIO_SPEED_HIGH
  );

  gpio_set_port_pins_io_resistor(
    GPIOA,
    GPIO0,
    GPIO_IO_RESISTOR_PULLUP
  );

  gpio_set_pin_alternate_function(GPIOA, GPIO9 | GPIO10, GPIO_ALTFN7);
  gpio_set_pin_alternate_function(GPIOA, GPIO5 | GPIO6 | GPIO7, GPIO_ALTFN5);
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 clock = nex_convert_freq_unit(16, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
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
_enumerate_device(void)
{
  gpio_set_pin_low(GPIOA, GPIO0);

  constexpr u32 reg = 117 | 0x80;
  spi_transfer_byte(SPI1, reg);

  u8 byte = spi_receive_byte_after(SPI1, 0x00);

  while ((SPI1->SR & SPI_SR_BSY) != 0);

  gpio_set_pin_high(GPIOA, GPIO0);
  switch (byte)
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
  fpu_set_access_level(FPU_ACCESS_LEVEL_FULL);
  syn_delay_nop(1000000);

  rcc_setup();
  gpio_setup();
  usart_setup();
  spi_setup();

  gpio_set_pin_high(GPIOA, GPIO0);
  usart_send_strfln(USART1, "Starting communication");

  while (_enumerate_device() != NEX_SUCCESS)
  {
    while (1);
  }

  usart_send_strfln(USART1, "Device ok");

  constexpr u32 temp_reg = 65;
  while (1)
  {
    gpio_set_pin_low(GPIOA, GPIO0);
    spi_transfer_byte(SPI1, temp_reg | 0x80);

    u8 buf[2];
    spi_receive_bytes_after(SPI1, buf, 2, 0x00);
    gpio_set_pin_high(GPIOA, GPIO0);

    u32 raw_value = ((u16) (buf[0] << 8)) | (u16) buf[1];
    const float offset = 0;
    const float sensitivity = 333.87f;
    float deg = (((float) raw_value - offset) / sensitivity) + 21;
    usart_send_strfln(USART1, "Temperature: %f°", deg);

    syn_delay_nop(3000000);
  }
}
