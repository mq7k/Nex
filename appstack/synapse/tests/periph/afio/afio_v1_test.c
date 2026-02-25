#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/stm32/drivers/afio/afio_v1.h"
#include "libtest/libtest.h"

void
setup(void)
{
  AFIO = (struct afio_registers_map*) membuf;
}

void
test_afio_set_eventout_port(void)
{
  // scope=self.reg='EVCR', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTA'}, self.value='0b000', self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTA);
  ASSERT_EQ(AFIO->EVCR, (0b000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 4);
  afio_set_eventout_port(AFIO_PORTA);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 4) | (0b000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTB'}, self.value='0b001', self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTB);
  ASSERT_EQ(AFIO->EVCR, (0b001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 4);
  afio_set_eventout_port(AFIO_PORTB);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 4) | (0b001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTC'}, self.value='0b010', self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTC);
  ASSERT_EQ(AFIO->EVCR, (0b010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 4);
  afio_set_eventout_port(AFIO_PORTC);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 4) | (0b010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTD'}, self.value='0b011', self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTD);
  ASSERT_EQ(AFIO->EVCR, (0b011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 4);
  afio_set_eventout_port(AFIO_PORTD);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 4) | (0b011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTE'}, self.value='0b100', self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTE);
  ASSERT_EQ(AFIO->EVCR, (0b100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 4);
  afio_set_eventout_port(AFIO_PORTE);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 4) | (0b100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTF'}, self.value='0b101', self.ifdef=[], self.halt=True
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTF);
  ASSERT_EQ(AFIO->EVCR, (0b101u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  AFIO->EVCR = ~(0u << 4);
  afio_set_eventout_port(AFIO_PORTF);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 4) | (0b101u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();


  // scope=self.reg='EVCR', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTG'}, self.value='0b110', self.ifdef=[], self.halt=True
  AFIO->EVCR = 0;
  afio_set_eventout_port(AFIO_PORTG);
  ASSERT_EQ(AFIO->EVCR, (0b110u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();

  AFIO->EVCR = ~(0u << 4);
  afio_set_eventout_port(AFIO_PORTG);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 4) | (0b110u << 4));
  ASSERT_TRUE(execution_halted());
  execution_resume();


}

void
test_afio_set_eventout_pin(void)
{
  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN0'}, self.value=0, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN0);
  ASSERT_EQ(AFIO->EVCR, (0u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN0);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (0u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN1'}, self.value=1, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN1);
  ASSERT_EQ(AFIO->EVCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN1);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (1u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN2'}, self.value=2, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN2);
  ASSERT_EQ(AFIO->EVCR, (2u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN2);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (2u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN3'}, self.value=3, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN3);
  ASSERT_EQ(AFIO->EVCR, (3u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN3);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (3u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN4'}, self.value=4, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN4);
  ASSERT_EQ(AFIO->EVCR, (4u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN4);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (4u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN5'}, self.value=5, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN5);
  ASSERT_EQ(AFIO->EVCR, (5u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN5);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (5u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN6'}, self.value=6, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN6);
  ASSERT_EQ(AFIO->EVCR, (6u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN6);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (6u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN7'}, self.value=7, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN7);
  ASSERT_EQ(AFIO->EVCR, (7u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN7);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (7u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN8'}, self.value=8, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN8);
  ASSERT_EQ(AFIO->EVCR, (8u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN8);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (8u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN9'}, self.value=9, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN9);
  ASSERT_EQ(AFIO->EVCR, (9u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN9);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (9u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN10'}, self.value=10, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN10);
  ASSERT_EQ(AFIO->EVCR, (10u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN10);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (10u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN11'}, self.value=11, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN11);
  ASSERT_EQ(AFIO->EVCR, (11u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN11);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (11u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN12'}, self.value=12, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN12);
  ASSERT_EQ(AFIO->EVCR, (12u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN12);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (12u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN13'}, self.value=13, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN13);
  ASSERT_EQ(AFIO->EVCR, (13u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN13);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (13u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN14'}, self.value=14, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN14);
  ASSERT_EQ(AFIO->EVCR, (14u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN14);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (14u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EVCR', self.shift=0, self.mask=None, self.varsmap={'pin': 'AFIO_PIN15'}, self.value=15, self.ifdef=[], self.halt=False
  AFIO->EVCR = 0;
  afio_set_eventout_pin(AFIO_PIN15);
  ASSERT_EQ(AFIO->EVCR, (15u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EVCR = ~(0u << 0);
  afio_set_eventout_pin(AFIO_PIN15);
  ASSERT_EQ(AFIO->EVCR, ~(0u << 0) | (15u << 0));
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
  // scope=self.reg='MAPR', self.shift=4, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_USART3_NOREMAP'}, self.value='0b00', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_usart3_remap(AFIO_REMAP_USART3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 4);
  afio_set_usart3_remap(AFIO_REMAP_USART3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 4) | (0b00u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=4, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_USART3_PARTIAL'}, self.value='0b01', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_usart3_remap(AFIO_REMAP_USART3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, (0b01u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 4);
  afio_set_usart3_remap(AFIO_REMAP_USART3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 4) | (0b01u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=4, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_USART3_FULL'}, self.value='0b11', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_usart3_remap(AFIO_REMAP_USART3_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 4);
  afio_set_usart3_remap(AFIO_REMAP_USART3_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 4) | (0b11u << 4));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_tim1_remap(void)
{
  // scope=self.reg='MAPR', self.shift=6, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM1_NOREMAP'}, self.value='0b00', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim1_remap(AFIO_REMAP_TIM1_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 6);
  afio_set_tim1_remap(AFIO_REMAP_TIM1_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 6) | (0b00u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=6, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM1_PARTIAL'}, self.value='0b01', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim1_remap(AFIO_REMAP_TIM1_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, (0b01u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 6);
  afio_set_tim1_remap(AFIO_REMAP_TIM1_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 6) | (0b01u << 6));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=6, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM1_FULL'}, self.value='0b11', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim1_remap(AFIO_REMAP_TIM1_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 6));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 6);
  afio_set_tim1_remap(AFIO_REMAP_TIM1_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 6) | (0b11u << 6));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_tim2_remap(void)
{
  // scope=self.reg='MAPR', self.shift=8, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM2_NOREMAP'}, self.value='0b00', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 8) | (0b00u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=8, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM2_PARTIAL1'}, self.value='0b01', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL1);
  ASSERT_EQ(AFIO->MAPR, (0b01u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL1);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 8) | (0b01u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=8, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM2_PARTIAL2'}, self.value='0b10', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL2);
  ASSERT_EQ(AFIO->MAPR, (0b10u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_PARTIAL2);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 8) | (0b10u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=8, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM2_FULL'}, self.value='0b11', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim2_remap(AFIO_REMAP_TIM2_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 8);
  afio_set_tim2_remap(AFIO_REMAP_TIM2_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 8) | (0b11u << 8));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_tim3_remap(void)
{
  // scope=self.reg='MAPR', self.shift=10, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM3_NOREMAP'}, self.value='0b00', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim3_remap(AFIO_REMAP_TIM3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 10);
  afio_set_tim3_remap(AFIO_REMAP_TIM3_NOREMAP);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=10, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM3_PARTIAL'}, self.value='0b10', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim3_remap(AFIO_REMAP_TIM3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, (0b10u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 10);
  afio_set_tim3_remap(AFIO_REMAP_TIM3_PARTIAL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 10) | (0b10u << 10));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=10, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_TIM3_FULL'}, self.value='0b11', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_tim3_remap(AFIO_REMAP_TIM3_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 10));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 10);
  afio_set_tim3_remap(AFIO_REMAP_TIM3_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 10) | (0b11u << 10));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_can1_remap(void)
{
  // scope=self.reg='MAPR', self.shift=13, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_CAN_1'}, self.value='0b00', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_can1_remap(AFIO_REMAP_CAN_1);
  ASSERT_EQ(AFIO->MAPR, (0b00u << 13));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 13);
  afio_set_can1_remap(AFIO_REMAP_CAN_1);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 13) | (0b00u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=13, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_CAN_2'}, self.value='0b10', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_can1_remap(AFIO_REMAP_CAN_2);
  ASSERT_EQ(AFIO->MAPR, (0b10u << 13));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 13);
  afio_set_can1_remap(AFIO_REMAP_CAN_2);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 13) | (0b10u << 13));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=13, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_CAN_3'}, self.value='0b11', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_can1_remap(AFIO_REMAP_CAN_3);
  ASSERT_EQ(AFIO->MAPR, (0b11u << 13));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 13);
  afio_set_can1_remap(AFIO_REMAP_CAN_3);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 13) | (0b11u << 13));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_swj_remap(void)
{
  // scope=self.reg='MAPR', self.shift=24, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_SWJ_FULL'}, self.value='0b000', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL);
  ASSERT_EQ(AFIO->MAPR, (0b000u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 24) | (0b000u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=24, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_SWJ_FULL_NO_NJTRST'}, self.value='0b001', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL_NO_NJTRST);
  ASSERT_EQ(AFIO->MAPR, (0b001u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_FULL_NO_NJTRST);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 24) | (0b001u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=24, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_SWJ_NOJTAG'}, self.value='0b010', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG);
  ASSERT_EQ(AFIO->MAPR, (0b010u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 24) | (0b010u << 24));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='MAPR', self.shift=24, self.mask=None, self.varsmap={'remap': 'AFIO_REMAP_SWJ_NOJTAG_NOSWDP'}, self.value='0b100', self.ifdef=[], self.halt=False
  AFIO->MAPR = 0;
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG_NOSWDP);
  ASSERT_EQ(AFIO->MAPR, (0b100u << 24));
  ASSERT_FALSE(execution_halted());

  AFIO->MAPR = ~(0u << 24);
  afio_set_swj_remap(AFIO_REMAP_SWJ_NOJTAG_NOSWDP);
  ASSERT_EQ(AFIO->MAPR, ~(0u << 24) | (0b100u << 24));
  ASSERT_FALSE(execution_halted());


}

void
test_afio_set_external_interrupt_source(void)
{
  // scope=self.reg='EXTICR1', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN0'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN1'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN2'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN3'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN4'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN5'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN6'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN7'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN8'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN9'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN10'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN11'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN12'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN13'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN14'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTA', 'pin': 'AFIO_PIN15'}, self.value='0b0000', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTA, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN0'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN1'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN2'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN3'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN4'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN5'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN6'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN7'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN8'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN9'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN10'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN11'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN12'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN13'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN14'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTB', 'pin': 'AFIO_PIN15'}, self.value='0b0001', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTB, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN0'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN1'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN2'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN3'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN4'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN5'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN6'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN7'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN8'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN9'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN10'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN11'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN12'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN13'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN14'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTC', 'pin': 'AFIO_PIN15'}, self.value='0b0010', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTC, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN0'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN1'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN2'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN3'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN4'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN5'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN6'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN7'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN8'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN9'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN10'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN11'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN12'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN13'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN14'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTD', 'pin': 'AFIO_PIN15'}, self.value='0b0011', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTD, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN0'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN1'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN2'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN3'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN4'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN5'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN6'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN7'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN8'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN9'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN10'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN11'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN12'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN13'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN14'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTE', 'pin': 'AFIO_PIN15'}, self.value='0b0100', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTE, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN0'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN1'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN2'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN3'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN4'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN5'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN6'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN7'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN8'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN9'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN10'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN11'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN12'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN13'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN14'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTF', 'pin': 'AFIO_PIN15'}, self.value='0b0101', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTF, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN0'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN0);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN1'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN1);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN2'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN2);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR1', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN3'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR1 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR1 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN3);
  ASSERT_EQ(AFIO->EXTICR1, ~(0u << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN4'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN4);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN5'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN5);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN6'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN6);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR2', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN7'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR2 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR2 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN7);
  ASSERT_EQ(AFIO->EXTICR2, ~(0u << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN8'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN8);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN9'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN9);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN10'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN10);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR3', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN11'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR3 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR3 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN11);
  ASSERT_EQ(AFIO->EXTICR3, ~(0u << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=0, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN12'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 0);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN12);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=4, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN13'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 4);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN13);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=8, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN14'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 8);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN14);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());


  // scope=self.reg='EXTICR4', self.shift=12, self.mask=None, self.varsmap={'port': 'AFIO_PORTG', 'pin': 'AFIO_PIN15'}, self.value='0b0110', self.ifdef=[], self.halt=False
  AFIO->EXTICR4 = 0;
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  AFIO->EXTICR4 = ~(0u << 12);
  afio_set_external_interrupt_source(AFIO_PORTG, AFIO_PIN15);
  ASSERT_EQ(AFIO->EXTICR4, ~(0u << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());


}

int
main(void)
{
  const test_function_t tests[] =
  {
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
