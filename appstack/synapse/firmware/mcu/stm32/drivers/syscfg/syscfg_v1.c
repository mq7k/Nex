#include "synapse/stm32/drivers/syscfg/syscfg_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"
#include "synapse/specs.h"

typedef volatile struct syscfg_registers_map syscfg_periph;
syscfg_periph* SYSCFG = (syscfg_periph*) (SYSCFG_ADDR);

static enum syscfg_exticr
convert_exti_port_api_to_impl(
  enum syscfg_exti_port port
)
{
  switch (port)
  {
#if defined(STM32_GPIOA)
    case SYSCFG_EXTI_PORTA:
      return SYSCFG_EXTICR_PORTA;
#endif

#if defined(STM32_GPIOB)
    case SYSCFG_EXTI_PORTB:
      return SYSCFG_EXTICR_PORTB;
#endif

#if defined(STM32_GPIOC)
    case SYSCFG_EXTI_PORTC:
      return SYSCFG_EXTICR_PORTC;
#endif

#if defined(STM32_GPIOD)
    case SYSCFG_EXTI_PORTD:
      return SYSCFG_EXTICR_PORTD;
#endif

#if defined(STM32_GPIOE)
    case SYSCFG_EXTI_PORTE:
      return SYSCFG_EXTICR_PORTE;
#endif

#if defined(STM32_GPIOF)
    case SYSCFG_EXTI_PORTF:
      return SYSCFG_EXTICR_PORTF;
#endif

#if defined(STM32_GPIOG)
    case SYSCFG_EXTI_PORTG:
      return SYSCFG_EXTICR_PORTG;
#endif

#if defined(STM32_GPIOH)
    case SYSCFG_EXTI_PORTH:
      return SYSCFG_EXTICR_PORTH;
#endif

#if defined(STM32_GPIOI)
    case SYSCFG_EXTI_PORTI:
      return SYSCFG_EXTICR_PORTI;
#endif

#if defined(STM32_GPIOJ)
    case SYSCFG_EXTI_PORTJ:
      return SYSCFG_EXTICR_PORTJ;
#endif

#if defined(STM32_GPIOK)
    case SYSCFG_EXTI_PORTK:
      return SYSCFG_EXTICR_PORTK;
#endif

    default:
      devmode_error_invalid_enum(enum syscfg_exti_port, port);
      return 0;
  }
}

void
syscfg_set_memory_mapping(
  enum syscfg_memory_mapping mem_mapping
)
{
  constexpr u32 shift = SYSCFG_MEMRMP_MEMMODE_SHIFT;
  constexpr u32 mask = SYSCFG_MEMRMP_MEMMODE_MASK << shift;
  volatile u32* reg = &SYSCFG->MEMRMP;
  switch (mem_mapping)
  {
    case SYSCFG_MEMORY_MAPPING_MAIN_FLASH:
      *reg &= ~mask;
      break;

    case SYSCFG_MEMORY_MAPPING_SYSTEM_FLASH:
      syn_set_register_bits(reg, mask, SYSCFG_MEMRMP_MEMMODE_SYSTEM_FLASH << shift);
      break;

#if defined(STM32_SYSCFG_FMC)
    case SYSCFG_MEMORY_MAPPING_FMC_BANK1:
      syn_set_register_bits(reg, mask, SYSCFG_MEMRMP_MEMMODE_FMC_BANK1 << shift);
      break;
#endif

    case SYSCFG_MEMORY_MAPPING_EMBEDDED_SRAM:
      syn_set_register_bits(reg, mask, SYSCFG_MEMRMP_MEMMODE_EMBEDDED_SRAM << shift);
      break;
      
#if defined(STM32_SYSCFG_FMC_SDRAM)
    case SYSCFG_MEMORY_MAPPING_FMC_SDRAM_BANK1:
      *reg |= (SYSCFG_MEMRMP_MEMMODE_FMC_SDRAM_BANK1 << shift);
      break;
#endif

    default:
      devmode_error_invalid_enum(enum syscfg_memory_mapping, mem_mapping);
      break;
  }
}

#if defined(STM32_SYSCFG_FLASH_BANK_MODE)
void
syscfg_set_flash_bank_mode(
  enum syscfg_flash_bank_mode mode
)
{
  volatile u32* reg = &SYSCFG->MEMRMP;
  switch (mode)
  {
    case SYSCFG_FLASH_BANK_MODE_BANK1:
      *reg &= ~SYSCFG_MEMRMP_FBMODE;
      break;

    case SYSCFG_FLASH_BANK_MODE_BANK2:
      *reg |= SYSCFG_MEMRMP_FBMODE;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_flash_bank_mode, mode);
      break;
  }
}
#endif

#if defined(STM32_SYSCFG_FMC_SWAP)
void
syscfg_set_fmc_memory_mapping_swap(
  enum syscfg_fmc_memswap swap
)
{
  constexpr u32 shift = SYSCFG_MEMRMP_SWP_FMC_SHIFT;
  constexpr u32 mask = SYSCFG_MEMRMP_SWP_FMC_MASK << shift;
  volatile u32* reg = &SYSCFG->MEMRMP;
  switch (swap)
  {
    case SYSCFG_FMC_MEMSWAP_NOSWAP:
      *reg &= ~mask;
      break;

    case SYSCFG_FMC_MEMSWAP_SDRAM_PCCARD_SWAP:
      syn_set_register_bits(
        reg,
        mask,
        SYSCFG_MEMRMP_SWPFMC_SDRAM_NAND_AND_PCCARD_SWAPPED << shift
      );
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_fmc_memswap, swap);
      break;
  }
}
#endif

#if defined(STM32_SYSCFG_PMC)
#if defined(STM32_SYSCFG_ADCxDC)
void
syscfg_adc_dc2_enable(
  enum syscfg_adc adc
)
{
  switch (adc)
  {
#if defined(STM32_SYSCFG_ADC1DC)
    case SYSCFG_ADC1:
      SYSCFG->PMC |= SYSCFG_PMC_ADC1DC2;
      break;
#endif

#if defined(STM32_SYSCFG_ADC2DC)
    case SYSCFG_ADC2:
      SYSCFG->PMC |= SYSCFG_PMC_ADC2DC2;
      break;
#endif

#if defined(STM32_SYSCFG_ADC3DC)
    case SYSCFG_ADC3:
      SYSCFG->PMC |= SYSCFG_PMC_ADC3DC2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum syscfg_adc, adc);
      break;
  }
}

void
syscfg_adc_dc2_disable(
  enum syscfg_adc adc
)
{
  switch (adc)
  {
    case SYSCFG_ADC1:
      SYSCFG->PMC &= ~SYSCFG_PMC_ADC1DC2;
      break;

#if defined(STM32_ADC2)
    case SYSCFG_ADC2:
      SYSCFG->PMC &= ~SYSCFG_PMC_ADC2DC2;
      break;
#endif

#if defined(STM32_ADC3)
    case SYSCFG_ADC3:
      SYSCFG->PMC &= ~SYSCFG_PMC_ADC3DC2;
      break;
#endif

    default:
      devmode_error_invalid_enum(enum syscfg_adc, adc);
      break;
  }
}
#endif

#if defined(STM32_SYSCFG_PMC_MII_RMII)
void
syscfg_set_ethernet_phy_interface(
  enum syscfg_eth_phy_interface interface
)
{
  volatile u32* reg = &SYSCFG->PMC;
  switch (interface)
  {
    case SYSCFH_ETH_PHY_INTERFACE_MII:
      *reg &= ~SYSCFG_PMC_MII_RMII_SEL;
      break;

    case SYSCFH_ETH_PHY_INTERFACE_RMII_PHY:
      *reg |= SYSCFG_PMC_MII_RMII_SEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_eth_phy_interface, interface);
      break;
  }
}
#endif
#endif

void
syscfg_set_exti_line(
  enum syscfg_exti_port port,
  enum syscfg_exti_pin pin
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg;
  const enum syscfg_exticr port_bits = convert_exti_port_api_to_impl(port);

  switch (pin)
  {
    case SYSCFG_EXTI_PIN0:
    case SYSCFG_EXTI_PIN1:
    case SYSCFG_EXTI_PIN2:
    case SYSCFG_EXTI_PIN3:
      shift = (pin % SYSCFG_EXTICR_EXTI_STRIDE) * SYSCFG_EXTICR_EXTI_STRIDE;
      mask = SYSCFG_EXTICR_EXTI_MASK << shift;
      reg = &SYSCFG->EXTICR1;
      syn_set_register_bits(reg, mask, port_bits << shift);
      break;

    case SYSCFG_EXTI_PIN4:
    case SYSCFG_EXTI_PIN5:
    case SYSCFG_EXTI_PIN6:
    case SYSCFG_EXTI_PIN7:
      shift = (pin % SYSCFG_EXTICR_EXTI_STRIDE) * SYSCFG_EXTICR_EXTI_STRIDE;
      mask = SYSCFG_EXTICR_EXTI_MASK << shift;
      reg = &SYSCFG->EXTICR2;
      syn_set_register_bits(reg, mask, port_bits << shift);
      break;

    case SYSCFG_EXTI_PIN8:
    case SYSCFG_EXTI_PIN9:
    case SYSCFG_EXTI_PIN10:
    case SYSCFG_EXTI_PIN11:
      shift = (pin % SYSCFG_EXTICR_EXTI_STRIDE) * SYSCFG_EXTICR_EXTI_STRIDE;
      mask = SYSCFG_EXTICR_EXTI_MASK << shift;
      reg = &SYSCFG->EXTICR3;
      syn_set_register_bits(reg, mask, port_bits << shift);
      break;
      
    case SYSCFG_EXTI_PIN12:
    case SYSCFG_EXTI_PIN13:
    case SYSCFG_EXTI_PIN14:
    case SYSCFG_EXTI_PIN15:
      shift = (pin % SYSCFG_EXTICR_EXTI_STRIDE) * SYSCFG_EXTICR_EXTI_STRIDE;
      mask = SYSCFG_EXTICR_EXTI_MASK << shift;
      reg = &SYSCFG->EXTICR4;
      syn_set_register_bits(reg, mask, port_bits << shift);
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_exti_pin, pin);
      break;
  }
}

#if defined(STM32_SYSCFG_CFGR2)
void
syscfg_cm4_lockup_enable(void)
{
  SYSCFG->CFGR2 |= SYSCFG_CFGR2_CLL;
}

void
syscfg_cm4_lockup_disable(void)
{
  SYSCFG->CFGR2 &= ~SYSCFG_CFGR2_CLL;
}

void
syscfg_lock_pvd_to_tim1_break_input(void)
{
  SYSCFG->CFGR2 |= SYSCFG_CFGR2_PVDL;
}
#endif

#if defined(STM32_SYSCFG_CMPCR)
void
syscfg_set_cell_compensation_mode(
  enum syscfg_cell_compensation_mode mode
)
{
  volatile u32* reg = &SYSCFG->CMPCR;
  switch (mode)
  {
    case SYSCFG_CELL_COMPENSATION_MODE_POWERDOWN:
      *reg &= ~SYSCFG_CMPCR_CMPPD;
      break;

    case SYSCFG_CELL_COMPENSATION_MODE_ENABLED:
      *reg |= SYSCFG_CMPCR_CMPPD;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_cell_compensation_mode, mode);
      break;
  }
}

u32
syscfg_is_cell_compensation_ready(void)
{
  return SYSCFG->CMPCR & SYSCFG_CMPCR_READY;
}
#endif

#if defined(STM32_SYSCFG_CFGR)
void
syscfg_force_i2c_fmplus_scl_drive_enable(void)
{
  SYSCFG->CFGR |= SYSCFG_CFGR_I2CFMP1SCL;
}

void
syscfg_force_i2c_fmplus_scl_drive_disable(void)
{
  SYSCFG->CFGR &= ~SYSCFG_CFGR_I2CFMP1SCL;
}

void
syscfg_force_i2c_fmplus_sda_drive_enable(void)
{
  SYSCFG->CFGR |= SYSCFG_CFGR_I2CFMP1SDA;
}

void
syscfg_force_i2c_fmplus_sda_drive_disable(void)
{
  SYSCFG->CFGR &= ~SYSCFG_CFGR_I2CFMP1SDA;
}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
syscfg_set_bitstream_clock_source(
  enum syscfg_bitstream_clock_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_BITSTREAM_CLOCK_SOURCE_OFF:
      *reg &= ~SYSCFG_MCHDLYCR_BSCKSEL;
      break;

    case SYSCFG_BITSTREAM_CLOCK_SOURCE_DFSDM2:
      *reg |= SYSCFG_MCHDLYCR_BSCKSEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_bitstream_clock_source, source);
      break;
  }
}

void
syscfg_dfsdm1_delay_clock_enable(void)
{
  SYSCFG->MCHDLYCR |= SYSCFG_MCHDLYCR_MCHDLYEN1;
}

void
syscfg_dfsdm1_delay_clock_disable(void)
{
  SYSCFG->MCHDLYCR &= ~SYSCFG_MCHDLYCR_MCHDLYEN1;
}

void
syscfg_set_dfsdm1_data_input0_source(
  enum syscfg_dfsdm1_data_input_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM1_DATA_INPUT_SOURCE_UNIQUE:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM1D0SEL;
      break;

    case SYSCFG_DFSDM1_DATA_INPUT_SOURCE_SHARED:
      *reg |= SYSCFG_MCHDLYCR_DFSDM1D0SEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm1_data_input_source, source);
      break;
  }
}

void
syscfg_set_dfsdm1_data_input2_source(
  enum syscfg_dfsdm1_data_input_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM1_DATA_INPUT_SOURCE_UNIQUE:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM1D2SEL;
      break;

    case SYSCFG_DFSDM1_DATA_INPUT_SOURCE_SHARED:
      *reg |= SYSCFG_MCHDLYCR_DFSDM1D2SEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm1_data_input_source, source);
      break;
  }
}

void
syscfg_set_dfsdm1_oc2_gated_clock_distribution(
  enum syscfg_dfsdm1_oc2_gated_clock_distrubition distribution
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (distribution)
  {
    case SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN0:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM1CK02SEL;
      break;

    case SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN2:
      *reg |= SYSCFG_MCHDLYCR_DFSDM1CK02SEL;
      break;

    default:
      devmode_error_invalid_enum(
        enum syscfg_dfsdm1_oc2_gated_clock_distrubition,
        distribution
      );
      break;
  }
}

void
syscfg_set_dfsdm1_oc1_gated_clock_distribution(
  enum syscfg_dfsdm1_oc1_gated_clock_distrubition distribution
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (distribution)
  {
    case SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN1:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM1CK13SEL;
      break;

    case SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN3:
      *reg |= SYSCFG_MCHDLYCR_DFSDM1CK13SEL;
      break;

    default:
      devmode_error_invalid_enum(
        enum syscfg_dfsdm1_oc1_gated_clock_distrubition,
        distribution
      );
      break;
  }
}

void
syscfg_set_dfsdm1_clock_source(
  enum syscfg_dfsdm1_clock_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM1_CLOCK_SOURCE_CKIN:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM1CFG;
      break;

    case SYSCFG_DFSDM1_CLOCK_SOURCE_DM:
      *reg |= SYSCFG_MCHDLYCR_DFSDM1CFG;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsm1_clock_source, source);
      break;
  }
}

void
syscfg_set_dfsdm1_output_clock(
  enum syscfg_dfsdm1_output_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM1_OUTPUT_SOURCE_CKOUT:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM1CKOSEL;
      break;

    case SYSCFG_DFSDM1_OUTPUT_SOURCE_M27:
      *reg |= SYSCFG_MCHDLYCR_DFSDM1CKOSEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm1_output_source, source);
      break;
  }
}

void
syscfg_dfsdm2_clock_enable(void)
{
  SYSCFG->MCHDLYCR |= SYSCFG_MCHDLYCR_MCHDLYEN2;
}

void
syscfg_dfsdm2_clock_disable(void)
{
  SYSCFG->MCHDLYCR &= ~SYSCFG_MCHDLYCR_MCHDLYEN2;
}

void
syscfg_set_dfsdm2_data_input0_source(
  enum syscfg_dfsdm2_data_input_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2D0SEL;
      break;

    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2D0SEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm2_data_input_source, source);
      break;
  }
}

void
syscfg_set_dfsdm2_data_input2_source(
  enum syscfg_dfsdm2_data_input_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2D2SEL;
      break;

    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2D2SEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm2_data_input_source, source);
      break;
  }
}

void
syscfg_set_dfsdm2_data_input4_source(
  enum syscfg_dfsdm2_data_input_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2D4SEL;
      break;

    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2D4SEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm2_data_input_source, source);
      break;
  }
}

void
syscfg_set_dfsdm2_data_input6_source(
  enum syscfg_dfsdm2_data_input_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM6D4SEL;
      break;

    case SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2D6SEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm2_data_input_source, source);
      break;
  }
}

void
syscfg_set_dfsdm2_oc4_gated_clock_distribution(
  enum syscfg_dfsdm2_oc4_gated_clock_distribution distribution
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (distribution)
  {
    case SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN0:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2CK04SEL;
      break;

    case SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN4:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2CK04SEL;
      break;

    default:
      devmode_error_invalid_enum(
        enum syscfg_dfsdm2_oc4_gated_clock_distribution,
        distribution
      );
      break;
  }
}

void
syscfg_set_dfsdm2_oc3_gated_clock_distribution(
  enum syscfg_dfsdm2_oc3_gated_clock_distribution distribution
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (distribution)
  {
    case SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN0:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2CK15SEL;
      break;

    case SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN4:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2CK15SEL;
      break;

    default:
      devmode_error_invalid_enum(
        enum syscfg_dfsdm2_oc4_gated_clock_distribution,
        distribution
      );
      break;
  }
}

void
syscfg_set_dfsdm2_oc2_gated_clock_distribution(
  enum syscfg_dfsdm2_oc2_gated_clock_distribution distribution
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (distribution)
  {
    case SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN0:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2CK26SEL;
      break;

    case SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN4:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2CK26SEL;
      break;

    default:
      devmode_error_invalid_enum(
        enum syscfg_dfsdm2_oc4_gated_clock_distribution,
        distribution
      );
      break;
  }
}

void
syscfg_set_dfsdm2_oc1_gated_clock_distribution(
  enum syscfg_dfsdm2_oc1_gated_clock_distribution distribution
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (distribution)
  {
    case SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN3:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2CK37SEL;
      break;

    case SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN7:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2CK37SEL;
      break;

    default:
      devmode_error_invalid_enum(
        enum syscfg_dfsdm2_oc1_gated_clock_distribution,
        distribution
      );
      break;
  }
}

void
syscfg_set_dfsdm2_clock_source(
  enum syscfg_dfsdm2_clock_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM2_CLOCK_SOURCE_CKIN:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2CFG;
      break;

    case SYSCFG_DFSDM2_CLOCK_SOURCE_DM:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2CFG;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm2_clock_source, source);
      break;
  }
}

void
syscfg_set_dfsdm2_output_clock(
  enum syscfg_dfsdm2_output_source source
)
{
  volatile u32* reg = &SYSCFG->MCHDLYCR;
  switch (source)
  {
    case SYSCFG_DFSDM2_OUTPUT_SOURCE_CKOUT:
      *reg &= ~SYSCFG_MCHDLYCR_DFSDM2CKOSEL;
      break;

    case SYSCFG_DFSDM2_OUTPUT_SOURCE_M27:
      *reg |= SYSCFG_MCHDLYCR_DFSDM2CKOSEL;
      break;

    default:
      devmode_error_invalid_enum(enum syscfg_dfsdm2_output_source, source);
      break;
  }
}
#endif
