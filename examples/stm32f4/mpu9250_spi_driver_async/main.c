#include "cpu/cortex/drivers/nvic/nvic_v1.h"
#include "libcom/util.h"
#include "soc/stm32/drivers/dma/dma_v1.h"
#include "soc/stm32/drivers/dma/dmaif.h"
#include "soc/stm32/drivers/spi/spi_v1.h"
#include "soc/stm32/drivers/spi/spiif.h"
#include "soc/stm32/drivers/usart/usart_v1.h"
#include "synapse/cpu/cortex/periph/fpu.h"
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
  rcc_periph_clock_enable(RCC_PERIPH_DMA2);
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
  spi_dma_rx_enable(SPI1);
  spi_dma_tx_enable(SPI1);
  // spi_enable(SPI1);
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
      usart_send_strfln(USART1, "Device: Unknown (0x%x)", response);
      return NEX_FAILURE;
  }

  return NEX_SUCCESS;
}

struct mpu9250 mpu;
struct beio be;

void
dma2_stream0_isr(void)
{
  // usart_send_strfln(USART1, "Fired 1");
  beio_transfer_complete(&be);

  if (dma_is_stream_flag_set(DMA2, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
  {
    dma_stream_flag_clear(DMA2, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  }

  if (dma_is_stream_flag_set(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
  {
    dma_stream_flag_clear(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  }

  nvic_clear_pending_irq(NVIC_IRQ_DMA2_STREAM0);
  nvic_clear_pending_irq(NVIC_IRQ_DMA2_STREAM5);
}

void
dma2_stream5_isr(void)
{
  // usart_send_strfln(USART1, "Fired 5");
  beio_transfer_complete(&be);

  if (dma_is_stream_flag_set(DMA2, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
  {
    dma_stream_flag_clear(DMA2, DMA_STREAM0, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  }

  if (dma_is_stream_flag_set(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE))
  {
    dma_stream_flag_clear(DMA2, DMA_STREAM5, DMA_STREAM_FLAG_TRANSFER_COMPLETE);
  }

  nvic_clear_pending_irq(NVIC_IRQ_DMA2_STREAM0);
  nvic_clear_pending_irq(NVIC_IRQ_DMA2_STREAM5);
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

  struct beio_spi bespi = {
    .spiconf = {
      .spi = SPI1,
      .role = SPIIF_ROLE_MASTER,
      .baudrate = SPIIF_BAUDRATE_CLK_DIV256,
      .clk_polarity = SPIIF_CLK_POLARITY_CLK_IDLE1,
      .clk_phase = SPIIF_CLK_PHASE_SECOND,
      .options = SPIIF_CAP_MSB
    },
    .rxconf = {
      .dma = DMA2,
      .stream = DMAIF_STREAM0,
      .channel = DMAIF_CHANNEL3,
      .periph = DMAIF_PERIPH_SPI,
      .msize = DMAIF_DATA_8bit,
      .psize = DMAIF_DATA_8bit,
      .direction = DMAIF_DIR_PERIPH2MEM,
      .periph_addr = (u32) &SPI1->DR,
      .options = DMAIF_CAP_MEM_INC_MODE
    },
    .txconf = {
      .dma = DMA2,
      .stream = DMAIF_STREAM5,
      .channel = DMAIF_CHANNEL3,
      .periph = DMAIF_PERIPH_SPI,
      .msize = DMAIF_DATA_8bit,
      .psize = DMAIF_DATA_8bit,
      .direction = DMAIF_DIR_MEM2PERIPH,
      .periph_addr = (u32) &SPI1->DR
    },
    .dma_active_caps = DMAIF_CAP_PERIPH_BURST1,
    .cflags = BEIO_SPI_CFLAG_DMA,
    .cs_port = GPIOA,
    .cs_pin = GPIO0
  };
  
  nvic_irq_enable(NVIC_IRQ_DMA2_STREAM0);
  nvic_irq_enable(NVIC_IRQ_DMA2_STREAM5);

  be.ctx = &bespi;
  be.ops = &ioops_spi;

  u32 code;
  if ((code = beio_init(&be)) != NEX_SUCCESS)
  {
    usart_send_strfln(USART1, "Failed to init beio (%d)", code);
    while (1);
  }

  spi_enable(SPI1);
  mpu.beio = &be;

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
    u8 buf[14] = {};
    struct mpu9250_sensors sensors = {
      .temp_offset = 0,
      .temp_sensitivity = 333.87f
    };
    struct mpu9250_transaction transaction = {
      .buf = buf,
      .count = 14
    };

    mpu9250_get_accel_temp_gyro_async(&mpu, &sensors, &transaction);
    while (!transaction.complete);

    double xgyro = (double) sensors.gyro.x * gyro_scale;
    double ygyro = (double) sensors.gyro.y * gyro_scale;
    double zgyro = (double) sensors.gyro.z * gyro_scale;

    double xaccel = (double) sensors.accel.x * accel_scale;
    double yaccel = (double) sensors.accel.y * accel_scale;
    double zaccel = (double) sensors.accel.z * accel_scale;

    float temp = sensors.temp;

    usart_send_strfln(USART1, "Gyro: %f, %f, %f", xgyro, ygyro, zgyro);
    usart_send_strfln(USART1, "Accel: %f, %f, %f", xaccel, yaccel, zaccel);
    usart_send_strfln(USART1, "Temperature: %f°", temp);
    usart_send_strfln(USART1, "=========================");
    syn_delay_nop(2000000);
  }
}
