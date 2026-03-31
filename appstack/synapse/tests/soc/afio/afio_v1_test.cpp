#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/afio/afio_v1.h"
#include "libtest/libtest.hpp"

#define ASSERT_ADDR(periph, reg, offset)\
	ASSERT_EQ(offsetof(periph, reg), offset)


void
setup(void)
{
  AFIO = (struct afio_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_ADDR(struct afio_registers_map, EVCR, 0x00lu);
  ASSERT_ADDR(struct afio_registers_map, MAPR, 0x04lu);
  ASSERT_ADDR(struct afio_registers_map, EXTICR[0], 0x08lu);
  ASSERT_ADDR(struct afio_registers_map, EXTICR[1], 0x0clu);
  ASSERT_ADDR(struct afio_registers_map, EXTICR[2], 0x10lu);
  ASSERT_ADDR(struct afio_registers_map, EXTICR[3], 0x14lu);
  ASSERT_ADDR(struct afio_registers_map, MAPR2, 0x1clu);
}

void
test_afio_set_eventout_port(void)
{
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTA);
  ASSERT_EQ(AFIO->EVCR, (0b000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0x7u << 4);
  afio_set_eventout_port(AFIO_PORTA);
  ASSERT_EQ(AFIO->EVCR, ~(0x7u << 4) | (0b000u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTB);
  ASSERT_EQ(AFIO->EVCR, (0b001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0x7u << 4);
  afio_set_eventout_port(AFIO_PORTB);
  ASSERT_EQ(AFIO->EVCR, ~(0x7u << 4) | (0b001u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTC);
  ASSERT_EQ(AFIO->EVCR, (0b010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0x7u << 4);
  afio_set_eventout_port(AFIO_PORTC);
  ASSERT_EQ(AFIO->EVCR, ~(0x7u << 4) | (0b010u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTD);
  ASSERT_EQ(AFIO->EVCR, (0b011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0x7u << 4);
  afio_set_eventout_port(AFIO_PORTD);
  ASSERT_EQ(AFIO->EVCR, ~(0x7u << 4) | (0b011u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTE);
  ASSERT_EQ(AFIO->EVCR, (0b100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0x7u << 4);
  afio_set_eventout_port(AFIO_PORTE);
  ASSERT_EQ(AFIO->EVCR, ~(0x7u << 4) | (0b100u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_eventout_pin(void)
{
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN0);
  ASSERT_EQ(AFIO->EVCR, (0u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN0);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN1);
  ASSERT_EQ(AFIO->EVCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN1);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN2);
  ASSERT_EQ(AFIO->EVCR, (2u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN2);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (2u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN3);
  ASSERT_EQ(AFIO->EVCR, (3u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN3);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (3u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN4);
  ASSERT_EQ(AFIO->EVCR, (4u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN4);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (4u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN5);
  ASSERT_EQ(AFIO->EVCR, (5u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN5);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (5u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN6);
  ASSERT_EQ(AFIO->EVCR, (6u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN6);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (6u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN7);
  ASSERT_EQ(AFIO->EVCR, (7u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN7);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (7u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN8);
  ASSERT_EQ(AFIO->EVCR, (8u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN8);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (8u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN9);
  ASSERT_EQ(AFIO->EVCR, (9u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN9);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (9u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN10);
  ASSERT_EQ(AFIO->EVCR, (10u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN10);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (10u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN11);
  ASSERT_EQ(AFIO->EVCR, (11u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN11);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (11u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN12);
  ASSERT_EQ(AFIO->EVCR, (12u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN12);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (12u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN13);
  ASSERT_EQ(AFIO->EVCR, (13u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN13);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (13u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN14);
  ASSERT_EQ(AFIO->EVCR, (14u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN14);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (14u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN15);
  ASSERT_EQ(AFIO->EVCR, (15u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0xfu << 0);
  afio_set_eventout_pin(AFIO_PIN15);
  ASSERT_EQ(AFIO->EVCR, ~(0xfu << 0) | (15u << 0));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_eventout(void)
{
  AFIO->EVCR = 0;
  afio_eventout_enable();
  ASSERT_EQ(AFIO->EVCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(1u << 7);
  afio_eventout_enable();
  ASSERT_EQ(AFIO->EVCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = (1u << 7);
  afio_eventout_disable();
  ASSERT_EQ(AFIO->EVCR, 0);
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = 0xffffffff;
  afio_eventout_disable();
  ASSERT_EQ(AFIO->EVCR, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}

void
test_afio_remap(void)
{
  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_SPI1);
  ASSERT_EQ(AFIO->MAPR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 0);
  afio_remap_enable(AFIO_REMAP_SPI1);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_SPI1);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 0);
  afio_remap_disable(AFIO_REMAP_SPI1);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_I2C1);
  ASSERT_EQ(AFIO->MAPR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 1);
  afio_remap_enable(AFIO_REMAP_I2C1);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_I2C1);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 1);
  afio_remap_disable(AFIO_REMAP_I2C1);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_USART1);
  ASSERT_EQ(AFIO->MAPR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 2);
  afio_remap_enable(AFIO_REMAP_USART1);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_USART1);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 2));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 2);
  afio_remap_disable(AFIO_REMAP_USART1);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_USART2);
  ASSERT_EQ(AFIO->MAPR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 3);
  afio_remap_enable(AFIO_REMAP_USART2);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_USART2);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 3));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 3);
  afio_remap_disable(AFIO_REMAP_USART2);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR2 = 0;
  afio_remap_enable(AFIO_REMAP_TIM9);
  ASSERT_EQ(AFIO->MAPR2, (1u << 5));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = ~(1u << 5);
  afio_remap_enable(AFIO_REMAP_TIM9);
  ASSERT_EQ(AFIO->MAPR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_TIM9);
  ASSERT_EQ(AFIO->MAPR2, ~(1u << 5));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = (1u << 5);
  afio_remap_disable(AFIO_REMAP_TIM9);
  ASSERT_EQ(AFIO->MAPR2, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR2 = 0;
  afio_remap_enable(AFIO_REMAP_TIM10);
  ASSERT_EQ(AFIO->MAPR2, (1u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = ~(1u << 6);
  afio_remap_enable(AFIO_REMAP_TIM10);
  ASSERT_EQ(AFIO->MAPR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_TIM10);
  ASSERT_EQ(AFIO->MAPR2, ~(1u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = (1u << 6);
  afio_remap_disable(AFIO_REMAP_TIM10);
  ASSERT_EQ(AFIO->MAPR2, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR2 = 0;
  afio_remap_enable(AFIO_REMAP_TIM11);
  ASSERT_EQ(AFIO->MAPR2, (1u << 7));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = ~(1u << 7);
  afio_remap_enable(AFIO_REMAP_TIM11);
  ASSERT_EQ(AFIO->MAPR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_TIM11);
  ASSERT_EQ(AFIO->MAPR2, ~(1u << 7));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = (1u << 7);
  afio_remap_disable(AFIO_REMAP_TIM11);
  ASSERT_EQ(AFIO->MAPR2, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR2 = 0;
  afio_remap_enable(AFIO_REMAP_TIM13);
  ASSERT_EQ(AFIO->MAPR2, (1u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = ~(1u << 8);
  afio_remap_enable(AFIO_REMAP_TIM13);
  ASSERT_EQ(AFIO->MAPR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_TIM13);
  ASSERT_EQ(AFIO->MAPR2, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = (1u << 8);
  afio_remap_disable(AFIO_REMAP_TIM13);
  ASSERT_EQ(AFIO->MAPR2, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR2 = 0;
  afio_remap_enable(AFIO_REMAP_TIM14);
  ASSERT_EQ(AFIO->MAPR2, (1u << 9));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = ~(1u << 9);
  afio_remap_enable(AFIO_REMAP_TIM14);
  ASSERT_EQ(AFIO->MAPR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_TIM14);
  ASSERT_EQ(AFIO->MAPR2, ~(1u << 9));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = (1u << 9);
  afio_remap_disable(AFIO_REMAP_TIM14);
  ASSERT_EQ(AFIO->MAPR2, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR2 = 0;
  afio_remap_enable(AFIO_REMAP_FSMC_NADV);
  ASSERT_EQ(AFIO->MAPR2, (1u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = ~(1u << 10);
  afio_remap_enable(AFIO_REMAP_FSMC_NADV);
  ASSERT_EQ(AFIO->MAPR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_FSMC_NADV);
  ASSERT_EQ(AFIO->MAPR2, ~(1u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR2 = (1u << 10);
  afio_remap_disable(AFIO_REMAP_FSMC_NADV);
  ASSERT_EQ(AFIO->MAPR2, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_TIM4);
  ASSERT_EQ(AFIO->MAPR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 12);
  afio_remap_enable(AFIO_REMAP_TIM4);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_TIM4);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 12);
  afio_remap_disable(AFIO_REMAP_TIM4);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_PD01);
  ASSERT_EQ(AFIO->MAPR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 15);
  afio_remap_enable(AFIO_REMAP_PD01);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_PD01);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 15));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 15);
  afio_remap_disable(AFIO_REMAP_PD01);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_TIM5_CH4);
  ASSERT_EQ(AFIO->MAPR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 16);
  afio_remap_enable(AFIO_REMAP_TIM5_CH4);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_TIM5_CH4);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 16);
  afio_remap_disable(AFIO_REMAP_TIM5_CH4);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_ADC1_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 17);
  afio_remap_enable(AFIO_REMAP_ADC1_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_ADC1_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 17);
  afio_remap_disable(AFIO_REMAP_ADC1_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_ADC1_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, (1u << 18));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 18);
  afio_remap_enable(AFIO_REMAP_ADC1_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_ADC1_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 18);
  afio_remap_disable(AFIO_REMAP_ADC1_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_ADC2_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, (1u << 19));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 19);
  afio_remap_enable(AFIO_REMAP_ADC2_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_ADC2_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 19));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 19);
  afio_remap_disable(AFIO_REMAP_ADC2_ETRGINJ);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_remap_enable(AFIO_REMAP_ADC2_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, (1u << 20));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(1u << 20);
  afio_remap_enable(AFIO_REMAP_ADC2_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = 0xffffffff;
  afio_remap_disable(AFIO_REMAP_ADC2_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, ~(1u << 20));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = (1u << 20);
  afio_remap_disable(AFIO_REMAP_ADC2_ETRGREG);
  ASSERT_EQ(AFIO->MAPR, 0);
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_usart3_remap(void)
{
  AFIO->MAPR = 0;
  afio_set_usart3_remap(AFIO_REMAP_USART3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 4);
  afio_set_usart3_remap(AFIO_REMAP_USART3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 4) | (0b00u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_usart3_remap(AFIO_REMAP_USART3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, (0b01u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 4);
  afio_set_usart3_remap(AFIO_REMAP_USART3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 4) | (0b01u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_usart3_remap(AFIO_REMAP_USART3_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 4);
  afio_set_usart3_remap(AFIO_REMAP_USART3_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 4) | (0b11u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_tim1_remap(void)
{
  AFIO->MAPR = 0;
  afio_set_tim1_remap(AFIO_REMAP_TIM1_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 6);
  afio_set_tim1_remap(AFIO_REMAP_TIM1_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_tim1_remap(AFIO_REMAP_TIM1_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 6);
  afio_set_tim1_remap(AFIO_REMAP_TIM1_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_tim1_remap(AFIO_REMAP_TIM1_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 6);
  afio_set_tim1_remap(AFIO_REMAP_TIM1_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 6) | (0b11u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_tim2_remap(void)
{
  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL1);
  ASSERT_EQ(AFIO->MAPR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL1);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL2);
  ASSERT_EQ(AFIO->MAPR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL2);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_tim3_remap(void)
{
  AFIO->MAPR = 0;
  afio_set_tim3_remap(AFIO_REMAP_TIM3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 10);
  afio_set_tim3_remap(AFIO_REMAP_TIM3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_tim3_remap(AFIO_REMAP_TIM3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, (0b10u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 10);
  afio_set_tim3_remap(AFIO_REMAP_TIM3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 10) | (0b10u << 10));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_tim3_remap(AFIO_REMAP_TIM3_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 10);
  afio_set_tim3_remap(AFIO_REMAP_TIM3_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 10) | (0b11u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_can1_remap(void)
{
  AFIO->MAPR = 0;
  afio_set_can1_remap(AFIO_REMAP_CAN_1);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 13);
  afio_set_can1_remap(AFIO_REMAP_CAN_1);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_can1_remap(AFIO_REMAP_CAN_2);
  ASSERT_EQ(AFIO->MAPR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 13);
  afio_set_can1_remap(AFIO_REMAP_CAN_2);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_can1_remap(AFIO_REMAP_CAN_3);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 13));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x3u << 13);
  afio_set_can1_remap(AFIO_REMAP_CAN_3);
  ASSERT_EQ(AFIO->MAPR, ~(0x3u << 13) | (0b11u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_swj_remap(void)
{
  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b000u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x7u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0x7u << 24) | (0b000u << 24));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL_NO_NJTRST);
  ASSERT_EQ(AFIO->MAPR, (0b001u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x7u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL_NO_NJTRST);
  ASSERT_EQ(AFIO->MAPR, ~(0x7u << 24) | (0b001u << 24));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG);
  ASSERT_EQ(AFIO->MAPR, (0b010u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x7u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG);
  ASSERT_EQ(AFIO->MAPR, ~(0x7u << 24) | (0b010u << 24));
  ASSERT_FALSE(execution_halted());


  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG_NOSWDP);
  ASSERT_EQ(AFIO->MAPR, (0b100u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0x7u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG_NOSWDP);
  ASSERT_EQ(AFIO->MAPR, ~(0x7u << 24) | (0b100u << 24));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_external_interrupt_source(void)
{
  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[0] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[0] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR[0], ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[1] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[1] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR[1], ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[2] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[2] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR[2], ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  AFIO->EXTICR[3] = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR[3] = ~(0xfu << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR[3], ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
    TEST_FUNC(test_afio_set_eventout_port),
    TEST_FUNC(test_afio_set_eventout_pin),
    TEST_FUNC(test_afio_eventout),
    TEST_FUNC(test_afio_remap),
    TEST_FUNC(test_afio_set_usart3_remap),
    TEST_FUNC(test_afio_set_tim1_remap),
    TEST_FUNC(test_afio_set_tim2_remap),
    TEST_FUNC(test_afio_set_tim3_remap),
    TEST_FUNC(test_afio_set_can1_remap),
    TEST_FUNC(test_afio_set_swj_remap),
    TEST_FUNC(test_afio_set_external_interrupt_source),
  };

  return TESTS_RUN(tests);
}
