#include "synapse/common/util/common.h"
#include "synapse/stm32/periph/gpio.h"
#include "synapse/stm32/periph/i2c.h"
#include "synapse/stm32/periph/usart.h"
#include "libcom/unit.h"
#include "synapse/stm32/periph/rcc.h"

constexpr u32 mpu9250_addr = 0x68;
constexpr u32 write_bit = 0;
constexpr u32 read_bit = 1;

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_GPIOB);
  rcc_periph_clock_enable(RCC_PERIPH_I2C1);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
}

void
gpio_setup(void)
{
  gpio_setup_port_pins(
    GPIOB,
    GPIO6,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOB,
    GPIO7,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_pin_alternate_function(
    GPIOB,
    GPIO6 | GPIO7,
    GPIO_ALTFN4
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO9,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_setup_port_pins(
    GPIOA,
    GPIO10,
    GPIO_MODE_ALTFN,
    GPIO_SPEED_HIGH
  );

  gpio_set_port_pins_output_type(
    GPIOB,
    GPIO6 | GPIO7,
    GPIO_OUTPUT_TYPE_OPEN_DRAIN
  );

  gpio_set_pin_alternate_function(GPIOA, GPIO9 | GPIO10, GPIO_ALTFN7);
  gpio_set_pin_alternate_function(GPIOB, GPIO6 | GPIO7, GPIO_ALTFN4);
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
i2c_setup(void)
{
  i2c_set_peripheral_clock_frequency(I2C1, 16);
  i2c_set_clock(I2C1, 80);
  i2c_enable(I2C1);
}

void
query_device_id(void)
{
  usart_send_strln(USART1, "Attempting to query the device...");

  i2c_transaction_start(I2C1);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT));

  i2c_flag_clear(I2C1, I2C_FLAG_START_BIT);
  i2c_send_byte(I2C1, (mpu9250_addr << 1) | write_bit);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS));

  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY));

  constexpr u32 reg_addr = 117;
  i2c_send_byte(I2C1, reg_addr);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY));

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED));

  i2c_transaction_start(I2C1);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT));
  i2c_flag_clear(I2C1, I2C_FLAG_START_BIT);

  i2c_send_byte(I2C1, (mpu9250_addr << 1) | read_bit);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS));

  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS);

  i2c_send_nack(I2C1);
  i2c_transaction_stop(I2C1);
  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY));
  
  u32 id = i2c_read_byte(I2C1);

  usart_send_strfln(USART1, "Device is: %u", id);

  switch (id)
  {
    case 0x70:
      usart_send_strln(USART1, "Recognized device: MPU6500");
      break;

    case 0x71:
      usart_send_strln(USART1, "Recognized device: MPU9250");
      break;

    default:
      usart_send_strln(USART1, "Unknown device");
      break;
  }

  usart_send_strln(USART1, "");
}

void
query_device_temperature(void)
{
  i2c_transaction_start(I2C1);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT));

  i2c_flag_clear(I2C1, I2C_FLAG_START_BIT);
  i2c_send_byte(I2C1, (mpu9250_addr << 1) | write_bit);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS));

  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY));

  constexpr u32 reg_addr = 65;
  i2c_send_byte(I2C1, reg_addr);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_EMPTY));

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_BYTE_TRANSFER_FINISHED));

  i2c_transaction_start(I2C1);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_START_BIT));
  
  i2c_flag_clear(I2C1, I2C_FLAG_START_BIT);

  i2c_send_byte(I2C1, (mpu9250_addr << 1) | read_bit);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_ADDRESS));

  i2c_flag_clear(I2C1, I2C_FLAG_ADDRESS);

  i2c_send_ack(I2C1);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY));
  i8 msb = (i8) i2c_read_byte(I2C1);

  i2c_send_nack(I2C1);

  WAIT_UNTIL(i2c_is_flag_set(I2C1, I2C_FLAG_DATA_REG_NOT_EMPTY));
  
  i8 lsb = (i8) i2c_read_byte(I2C1);

  i2c_transaction_stop(I2C1);

  i32 value = (msb << 8) | lsb;
  float temp = ((float) value / 333.87f) + 21.0f;
  usart_send_strfln(USART1, "Raw value: %d", value);
  usart_send_strfln(USART1, "Processed value: %f", temp);
  usart_send_strln(USART1, "****************");
}

int
main(void)
{
  syn_delay_nop(1000000);

  rcc_setup();
  gpio_setup();
  usart_setup();
  i2c_setup();

  query_device_id();

  while (1)
  {
    query_device_temperature();
    syn_delay_nop(1000000);
  }

  while (1);
}
