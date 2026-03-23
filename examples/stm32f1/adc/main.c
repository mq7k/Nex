#include "libcom/unit.h"
#include "synapse/common/common.h"
#include "synapse/soc/stm32/drivers/adc/adc_v1.h"
#include "synapse/soc/stm32/drivers/usart/usart_v1.h"
#include <synapse/soc/stm32/periph/rcc.h>
#include <synapse/soc/stm32/periph/gpio.h>
#include <synapse/soc/stm32/periph/adc.h>
#include <synapse/soc/stm32/periph/usart.h>

void
rcc_setup(void)
{
  rcc_periph_clock_enable(RCC_PERIPH_GPIOA);
  rcc_periph_clock_enable(RCC_PERIPH_AFIO);
  rcc_periph_clock_enable(RCC_PERIPH_USART1);
  rcc_periph_clock_enable(RCC_PERIPH_ADC1);
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
}

void
usart_setup(void)
{
  constexpr u32 baudrate = 115200;
  const u32 apb2_clock = nex_convert_freq_unit(8, NEX_FREQ_UNIT_MHz, NEX_FREQ_UNIT_Hz);
  usart_set_baudrate(USART1, apb2_clock, baudrate);
  usart_set_word_length(USART1, USART_WORD_LENGTH_8BITS);
  usart_set_stop_bits(USART1, USART_STOP_BITS_1BIT);
  usart_transmitter_enable(USART1);
  usart_parity_control_disable(USART1);
  usart_cts_disable(USART1);
  usart_rts_disable(USART1);
  usart_enable(USART1);
}

void
adc_setup(void)
{
  adc_enable(ADC1);

  syn_delay_nop(1000000);
  u32 channels[] = { ADC_REG_CHANNEL16 };

  adc_calibration_reset(ADC1);
  while (!adc_is_calibration_init_complete(ADC1));

  adc_calibration_begin(ADC1);
  adc_calibration_ready_wait(ADC1);
  adc_set_reg_external_event(ADC1, ADC_REG_TRIGGER_EVENT_SWSTART);
  adc_external_trigger_reg_enable(ADC1);
  adc_set_conversion_method(ADC1, ADC_CONVERSION_METHOD_SINGLE);
  adc_scan_mode_disable(ADC1);
  adc_set_data_alignment(ADC1, ADC_DATA_ALIGNMENT_RIGHT);
  adc_set_reg_sequence(ADC1, channels, 1);
  adc_set_sample_time_all_channels(ADC1, ADC_SAMPLE_RATE_239dot5_CYCLES);
  adc_temperature_sensor_enable(ADC1);
  adc_enable(ADC1);
}

int 
main() 
{
  rcc_setup();
  gpio_setup();
  usart_setup();
  adc_setup();

  while (1)
  {
    adc_reg_start(ADC1);
    while (adc_is_flag_set(ADC1, ADC_FLAG_EOC) == 0);

    double value = adc_reg_data_read(ADC1);
    value = (3.3 / 4096) * value;
    double temp = ((1.43 - value) / 0.0043) + 25;
    usart_send_strfln(USART1, "Temperature: %f", temp);
    syn_delay_nop(1500000);
  }
}

