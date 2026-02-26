#include "synapse/stm32/drivers/afio/afio_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct afio_registers_map afio_periph;
afio_periph* AFIO = (afio_periph*) (AFIO_ADDR);

static enum afio_exticr_exti
convert_afio_port_api_to_exti_port(
  enum afio_port port
)
{
  switch (port)
  {
    case AFIO_PORTA:
      return AFIO_EXTICR_EXTI_PA;

    case AFIO_PORTB:
      return AFIO_EXTICR_EXTI_PB;

    case AFIO_PORTC:
      return AFIO_EXTICR_EXTI_PC;

    case AFIO_PORTD:
      return AFIO_EXTICR_EXTI_PD;

    case AFIO_PORTE:
      return AFIO_EXTICR_EXTI_PE;

    default:
      devmode_error_invalid_enum(enum afio_port, port);
      return 0;
  }
}

void
afio_set_eventout_port(
  enum afio_port port
)
{
  constexpr u32 shift = AFIO_EVCR_PORT_SHIFT;
  constexpr u32 mask = AFIO_EVCR_PORT_MASK << shift;
  volatile u32* reg = &AFIO->EVCR;
  switch (port)
  {
    case AFIO_PORTA:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PORT_PA << shift);
      break;

    case AFIO_PORTB:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PORT_PB << shift);
      break;

    case AFIO_PORTC:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PORT_PC << shift);
      break;

    case AFIO_PORTD:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PORT_PD << shift);
      break;

    case AFIO_PORTE:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PORT_PE << shift);
      break;

    default:
      devmode_error_invalid_enum(enum afio_port, port);
      break;
  }
}

void
afio_set_eventout_pin(
  enum afio_pin pin
)
{
  constexpr u32 shift = AFIO_EVCR_PIN_SHIFT;
  constexpr u32 mask = AFIO_EVCR_PIN_MASK << shift;
  volatile u32* reg = &AFIO->EVCR;
  switch (pin)
  {
    case AFIO_PIN0:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px0 << shift);
      break;

    case AFIO_PIN1:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px1 << shift);
      break;

    case AFIO_PIN2:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px2 << shift);
      break;

    case AFIO_PIN3:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px3 << shift);
      break;

    case AFIO_PIN4:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px4 << shift);
      break;

    case AFIO_PIN5:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px5 << shift);
      break;

    case AFIO_PIN6:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px6 << shift);
      break;

    case AFIO_PIN7:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px7 << shift);
      break;

    case AFIO_PIN8:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px8 << shift);
      break;

    case AFIO_PIN9:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px9 << shift);
      break;

    case AFIO_PIN10:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px10 << shift);
      break;

    case AFIO_PIN11:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px11 << shift);
      break;

    case AFIO_PIN12:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px12 << shift);
      break;

    case AFIO_PIN13:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px13 << shift);
      break;

    case AFIO_PIN14:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px14 << shift);
      break;

    case AFIO_PIN15:
      syn_set_register_bits(reg, mask, AFIO_EVCR_PIN_Px15 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum afio_pin, pin);
      break;
  }
}

void
afio_set_eventout_gpio(
  enum afio_port port,
  enum afio_pin pin
)
{
  afio_set_eventout_port(port);
  afio_set_eventout_pin(pin);
}

void
afio_eventout_enable(void)
{
  AFIO->EVCR |= AFIO_EVCR_EVOE;
}

void
afio_eventout_disable(void)
{
  AFIO->EVCR &= ~AFIO_EVCR_EVOE;
}

void
afio_remap_enable(
  enum afio_remap remap
)
{
  switch (remap)
  {
    case AFIO_REMAP_SPI1:
      AFIO->MAPR |= AFIO_MAPR_SPI1_REMAP;
      break;

    case AFIO_REMAP_I2C1:
      AFIO->MAPR |= AFIO_MAPR_I2C1_REMAP;
      break;

    case AFIO_REMAP_USART1:
      AFIO->MAPR |= AFIO_MAPR_USART1_REMAP;
      break;

    case AFIO_REMAP_USART2:
      AFIO->MAPR |= AFIO_MAPR_USART2_REMAP;
      break;

    case AFIO_REMAP_TIM4:
      AFIO->MAPR |= AFIO_MAPR_TIM4_REMAP;
      break;

    case AFIO_REMAP_PD01:
      AFIO->MAPR |= AFIO_MAPR_PD01_REMAP;
      break;

    case AFIO_REMAP_TIM5_CH4:
      AFIO->MAPR |= AFIO_MAPR_TIM5CH4_IREMAP;
      break;

    case AFIO_REMAP_ADC1_ETRGINJ:
      AFIO->MAPR |= AFIO_MAPR_ADC1_ETRGINJ_REMAP;
      break;

    case AFIO_REMAP_ADC1_ETRGREG:
      AFIO->MAPR |= AFIO_MAPR_ADC1_ETRGREG_REMAP;
      break;

    case AFIO_REMAP_ADC2_ETRGINJ:
      AFIO->MAPR |= AFIO_MAPR_ADC2_ETRGINJ_REMAP;
      break;

    case AFIO_REMAP_ADC2_ETRGREG:
      AFIO->MAPR |= AFIO_MAPR_ADC2_ETRGREG_REMAP;
      break;

    // Connectivity only
    case AFIO_REMAP_TIM9:
      AFIO->MAPR2 |= AFIO_MAPR2_TIM9_REMAP;
      break;

    case AFIO_REMAP_TIM10:
      AFIO->MAPR2 |= AFIO_MAPR2_TIM10_REMAP;
      break;

    case AFIO_REMAP_TIM11:
      AFIO->MAPR2 |= AFIO_MAPR2_TIM11_REMAP;
      break;

    case AFIO_REMAP_TIM13:
      AFIO->MAPR2 |= AFIO_MAPR2_TIM13_REMAP;
      break;

    case AFIO_REMAP_TIM14:
      AFIO->MAPR2 |= AFIO_MAPR2_TIM14_REMAP;
      break;

    case AFIO_REMAP_FSMC_NADV:
      AFIO->MAPR2 |= AFIO_MAPR2_FSMC_NADV;
      break;

    default:
      devmode_error_invalid_enum(enum afio_remap, remap);
      break;
  }
}

void
afio_remap_disable(
  enum afio_remap remap
)
{
  switch (remap)
  {
    case AFIO_REMAP_SPI1:
      AFIO->MAPR &= ~AFIO_MAPR_SPI1_REMAP;
      break;

    case AFIO_REMAP_I2C1:
      AFIO->MAPR &= ~AFIO_MAPR_I2C1_REMAP;
      break;

    case AFIO_REMAP_USART1:
      AFIO->MAPR &= ~AFIO_MAPR_USART1_REMAP;
      break;

    case AFIO_REMAP_USART2:
      AFIO->MAPR &= ~AFIO_MAPR_USART2_REMAP;
      break;

    case AFIO_REMAP_TIM4:
      AFIO->MAPR &= ~AFIO_MAPR_TIM4_REMAP;
      break;

    case AFIO_REMAP_PD01:
      AFIO->MAPR &= ~AFIO_MAPR_PD01_REMAP;
      break;

    case AFIO_REMAP_TIM5_CH4:
      AFIO->MAPR &= ~AFIO_MAPR_TIM5CH4_IREMAP;
      break;

    case AFIO_REMAP_ADC1_ETRGINJ:
      AFIO->MAPR &= ~AFIO_MAPR_ADC1_ETRGINJ_REMAP;
      break;

    case AFIO_REMAP_ADC1_ETRGREG:
      AFIO->MAPR &= ~AFIO_MAPR_ADC1_ETRGREG_REMAP;
      break;

    case AFIO_REMAP_ADC2_ETRGINJ:
      AFIO->MAPR &= ~AFIO_MAPR_ADC2_ETRGINJ_REMAP;
      break;

    case AFIO_REMAP_ADC2_ETRGREG:
      AFIO->MAPR &= ~AFIO_MAPR_ADC2_ETRGREG_REMAP;
      break;

    // Connectivity only
    case AFIO_REMAP_TIM9:
      AFIO->MAPR2 &= ~AFIO_MAPR2_TIM9_REMAP;
      break;

    case AFIO_REMAP_TIM10:
      AFIO->MAPR2 &= ~AFIO_MAPR2_TIM10_REMAP;
      break;

    case AFIO_REMAP_TIM11:
      AFIO->MAPR2 &= ~AFIO_MAPR2_TIM11_REMAP;
      break;

    case AFIO_REMAP_TIM13:
      AFIO->MAPR2 &= ~AFIO_MAPR2_TIM13_REMAP;
      break;

    case AFIO_REMAP_TIM14:
      AFIO->MAPR2 &= ~AFIO_MAPR2_TIM14_REMAP;
      break;

    case AFIO_REMAP_FSMC_NADV:
      AFIO->MAPR2 &= ~AFIO_MAPR2_FSMC_NADV;
      break;

    default:
      devmode_error_invalid_enum(enum afio_remap, remap);
      break;
  }
}

void
afio_set_usart3_remap(
  enum afio_remap_usart3 remap
)
{
  constexpr u32 shift = AFIO_MAPR_USART3_REMAP_SHIFT;
  constexpr u32 mask = AFIO_MAPR_USART3_REMAP_MASK << shift; 

  switch (remap)
  {
    case AFIO_REMAP_USART3_NOREMAP:
      AFIO->MAPR &= ~mask;
      break;

    case AFIO_REMAP_USART3_PARTIAL:
      syn_set_register_bits(
        &AFIO->MAPR,
        mask,
        AFIO_MAPR_USART3_REMAP_PARTIAL_REMAP << shift
      );
      break;

    case AFIO_REMAP_USART3_FULL:
      AFIO->MAPR |= (AFIO_MAPR_USART3_REMAP_FULL_REMAP << shift);
      break;

    default:
      devmode_error_invalid_enum(enum afio_remap_usart3, remap);
      break;
  }
}

void
afio_set_tim1_remap(
  enum afio_remap_tim1 remap
)
{
  constexpr u32 shift = AFIO_MAPR_TIM1_REMAP_SHIFT;
  constexpr u32 mask = AFIO_MAPR_TIM1_REMAP_MASK << shift;

  switch (remap)
  {
    case AFIO_REMAP_TIM1_NOREMAP:
      AFIO->MAPR &= ~mask;
      break;

    case AFIO_REMAP_TIM1_PARTIAL:
      syn_set_register_bits(
        &AFIO->MAPR,
        mask,
        AFIO_MAPR_TIM1_REMAP_PARTIAL_REMAP << shift
      );
      break;

    case AFIO_REMAP_TIM1_FULL:
      AFIO->MAPR |= (AFIO_MAPR_TIM1_REMAP_FULL_REMAP << shift);
      break;

    default:
      devmode_error_invalid_enum(enum afio_remap_tim1, remap);
      break;
  }
}

void
afio_set_tim2_remap(
  enum afio_remap_tim2 remap
)
{
  constexpr u32 shift = AFIO_MAPR_TIM2_REMAP_SHIFT;
  constexpr u32 mask = AFIO_MAPR_TIM2_REMAP_MASK << shift;

  switch (remap)
  {
    case AFIO_REMAP_TIM2_NOREMAP:
      AFIO->MAPR &= ~mask;
      break;

    case AFIO_REMAP_TIM2_PARTIAL1:
      syn_set_register_bits(
        &AFIO->MAPR,
        mask,
        AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP1 << shift
      );
      break;

    case AFIO_REMAP_TIM2_PARTIAL2:
      syn_set_register_bits(
        &AFIO->MAPR,
        mask,
        AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP2 << shift
      );
      break;

    case AFIO_REMAP_TIM2_FULL:
      AFIO->MAPR |= (AFIO_MAPR_TIM2_REMAP_FULL_REMAP << shift);
      break;

    default:
      devmode_error_invalid_enum(enum afio_remap_tim2, remap);
      break;
  }
}

void
afio_set_tim3_remap(
  enum afio_remap_tim3 remap
)
{
  constexpr u32 shift = AFIO_MAPR_TIM3_REMAP_SHIFT;
  constexpr u32 mask = AFIO_MAPR_TIM3_REMAP_MASK << shift;

  switch (remap)
  {
    case AFIO_REMAP_TIM3_NOREMAP:
      AFIO->MAPR &= ~mask;
      break;

    case AFIO_REMAP_TIM3_PARTIAL:
      syn_set_register_bits(
        &AFIO->MAPR,
        mask,
        AFIO_MAPR_TIM3_REMAP_PARTIAL_REMAP << shift
      );
      break;

    case AFIO_REMAP_TIM3_FULL:
      AFIO->MAPR |= (AFIO_MAPR_TIM3_REMAP_FULL_REMAP << shift);
      break;
      
    default:
      devmode_error_invalid_enum(enum afio_remap_tim3, remap);
      break;
  }
}

void
afio_set_can1_remap(
  enum afio_remap_can remap
)
{
  constexpr u32 shift = AFIO_MAPR_CAN1_REMAP_SHIFT;
  constexpr u32 mask = AFIO_MAPR_CAN1_REMAP_MASK << shift;

  switch (remap)
  {
    case AFIO_REMAP_CAN_1:
      AFIO->MAPR &= ~mask;
      break;

    case AFIO_REMAP_CAN_2:
      syn_set_register_bits(
        &AFIO->MAPR,
        mask,
        AFIO_MAPR_CAN1_REMAP_2 << shift
      );
      break;

    case AFIO_REMAP_CAN_3:
      AFIO->MAPR |= (AFIO_MAPR_CAN1_REMAP_3 << shift);
      break;
      
    default:
      devmode_error_invalid_enum(enum afio_remap_can, remap);
      break;
  }
}

void
afio_set_swj_remap(
  enum afio_remap_swj remap
)
{
  constexpr u32 shift = AFIO_MAPR_SWJ_CFG_SHIFT;
  constexpr u32 mask = AFIO_MAPR_SWJ_CFG_MASK << shift;
  volatile u32* reg = &AFIO->MAPR;

  switch (remap)
  {
    case AFIO_REMAP_SWJ_FULL:
      *reg &= ~mask;
      break;

    case AFIO_REMAP_SWJ_FULL_NO_NJTRST:
      syn_set_register_bits(
        reg,
        mask,
        AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_NJTRST << shift
      );
      break;

    case AFIO_REMAP_SWJ_NOJTAG:
      syn_set_register_bits(
        reg,
        mask,
        AFIO_MAPR_SWJ_CFG_NOJTAG << shift
      );
      break;

    case AFIO_REMAP_SWJ_NOJTAG_NOSWDP:
      syn_set_register_bits(
        reg,
        mask,
        AFIO_MAPR_SWJ_CFG_NOJTAG_NOSWDP << shift 
      );
      break;

    default:
      devmode_error_invalid_enum(enum afio_remap_swj, remap);
      break;
  }
}

void
afio_set_external_interrupt_source(
  enum afio_port port,
  enum afio_pin pin
)
{
  enum afio_exticr_exti port_bits = convert_afio_port_api_to_exti_port(port);
  constexpr u32 mask = AFIO_EXTICR_EXTI_MASK;
  const u32 shift = (pin & 3) * 4;
  const u32 reg_idx = pin >> 2;

  volatile u32* reg = &AFIO->EXTICR[reg_idx];
  syn_set_register_bits(reg, mask << shift, port_bits << shift);
}
