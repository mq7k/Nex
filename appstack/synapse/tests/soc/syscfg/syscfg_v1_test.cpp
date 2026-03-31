#include "libcom/util.h"
#include "libcom/types.h"

#include "synapse/soc/stm32/drivers/syscfg/syscfg_v1.h"
#include "libtest/libtest.hpp"

#define ASSERT_ADDR(periph, reg, offset)\
	ASSERT_EQ(offsetof(periph, reg), offset)


void
setup(void)
{
  SYSCFG = (struct syscfg_registers_map*) membuf;
}

void
test_reg_addr(void)
{
  ASSERT_ADDR(struct syscfg_registers_map, MEMRMP, 0x00lu);
  ASSERT_ADDR(struct syscfg_registers_map, PMC, 0x04lu);
  ASSERT_ADDR(struct syscfg_registers_map, EXTICR1, 0x08lu);
  ASSERT_ADDR(struct syscfg_registers_map, EXTICR2, 0x0clu);
  ASSERT_ADDR(struct syscfg_registers_map, EXTICR3, 0x10lu);
  ASSERT_ADDR(struct syscfg_registers_map, EXTICR4, 0x14lu);
#if defined(STM32_SYSCFG_CFGR2)
  ASSERT_ADDR(struct syscfg_registers_map, CFGR2, 0x18lu);
#endif
#if defined(STM32_SYSCFG_CMPCR)
  ASSERT_ADDR(struct syscfg_registers_map, CMPCR, 0x20lu);
#endif
#if defined(STM32_SYSCFG_CFGR)
  ASSERT_ADDR(struct syscfg_registers_map, CFGR, 0x2clu);
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
  ASSERT_ADDR(struct syscfg_registers_map, MCHDLYCR, 0x30lu);
#endif
}

#if defined(STM32_SYSCFG_MEMMODE_2BIT)
void
test_syscfg_set_memory_mapping(void)
{
  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_MAIN_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x3u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_MAIN_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x3u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_SYSTEM_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x3u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_SYSTEM_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x3u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SYSCFG_FMC)
  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x3u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x3u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_EMBEDDED_SRAM);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x3u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_EMBEDDED_SRAM);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x3u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SYSCFG_FMC_SDRAM)
  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_SDRAM_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x3u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_SDRAM_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x3u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_SYSCFG_MEMMODE_3BIT)
void
test_syscfg_set_memory_mapping(void)
{
  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_MAIN_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x7u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_MAIN_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x7u << 0) | (0b000u << 0));
  ASSERT_FALSE(execution_halted());


  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_SYSTEM_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x7u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_SYSTEM_FLASH);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x7u << 0) | (0b001u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SYSCFG_FMC)
  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x7u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x7u << 0) | (0b010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_EMBEDDED_SRAM);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b011u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x7u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_EMBEDDED_SRAM);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x7u << 0) | (0b011u << 0));
  ASSERT_FALSE(execution_halted());


#if defined(STM32_SYSCFG_FMC_SDRAM)
  SYSCFG->MEMRMP = 0;
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_SDRAM_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b100u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x7u << 0);
  syscfg_set_memory_mapping(SYSCFG_MEMORY_MAPPING_FMC_SDRAM_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x7u << 0) | (0b100u << 0));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_SYSCFG_FLASH_BANK_MODE)
void
test_syscfg_set_flash_bank_mode(void)
{
  SYSCFG->MEMRMP = 0;
  syscfg_set_flash_bank_mode(SYSCFG_FLASH_BANK_MODE_BANK2);
  ASSERT_EQ(SYSCFG->MEMRMP, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(1u << 8);
  syscfg_set_flash_bank_mode(SYSCFG_FLASH_BANK_MODE_BANK2);
  ASSERT_EQ(SYSCFG->MEMRMP, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = (1u << 8);
  syscfg_set_flash_bank_mode(SYSCFG_FLASH_BANK_MODE_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = 0xffffffff;
  syscfg_set_flash_bank_mode(SYSCFG_FLASH_BANK_MODE_BANK1);
  ASSERT_EQ(SYSCFG->MEMRMP, 0xffffffff & ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_FMC_SWAP)
void
test_syscfg_set_fmc_memory_mapping_swap(void)
{
  SYSCFG->MEMRMP = 0;
  syscfg_set_fmc_memory_mapping_swap(SYSCFG_FMC_MEMSWAP_NOSWAP);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b00u << 10));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x3u << 10);
  syscfg_set_fmc_memory_mapping_swap(SYSCFG_FMC_MEMSWAP_NOSWAP);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x3u << 10) | (0b00u << 10));
  ASSERT_FALSE(execution_halted());


  SYSCFG->MEMRMP = 0;
  syscfg_set_fmc_memory_mapping_swap(SYSCFG_FMC_MEMSWAP_SDRAM_PCCARD_SWAP);
  ASSERT_EQ(SYSCFG->MEMRMP, (0b01u << 10));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MEMRMP = ~(0x3u << 10);
  syscfg_set_fmc_memory_mapping_swap(SYSCFG_FMC_MEMSWAP_SDRAM_PCCARD_SWAP);
  ASSERT_EQ(SYSCFG->MEMRMP, ~(0x3u << 10) | (0b01u << 10));
  ASSERT_FALSE(execution_halted());


}
#endif

#if defined(STM32_SYSCFG_PMC) && defined(STM32_SYSCFG_ADCxDC)
void
test_syscfg_adc_dc2(void)
{
#if defined(STM32_SYSCFG_ADC1DC)
  SYSCFG->PMC = 0;
  syscfg_adc_dc2_enable(SYSCFG_ADC1);
  ASSERT_EQ(SYSCFG->PMC, (1u << 16));
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = ~(1u << 16);
  syscfg_adc_dc2_enable(SYSCFG_ADC1);
  ASSERT_EQ(SYSCFG->PMC, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = (1u << 16);
  syscfg_adc_dc2_disable(SYSCFG_ADC1);
  ASSERT_EQ(SYSCFG->PMC, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = 0xffffffff;
  syscfg_adc_dc2_disable(SYSCFG_ADC1);
  ASSERT_EQ(SYSCFG->PMC, ~(1u << 16));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SYSCFG_ADC2DC)
  SYSCFG->PMC = 0;
  syscfg_adc_dc2_enable(SYSCFG_ADC2);
  ASSERT_EQ(SYSCFG->PMC, (1u << 17));
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = ~(1u << 17);
  syscfg_adc_dc2_enable(SYSCFG_ADC2);
  ASSERT_EQ(SYSCFG->PMC, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = (1u << 17);
  syscfg_adc_dc2_disable(SYSCFG_ADC2);
  ASSERT_EQ(SYSCFG->PMC, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = 0xffffffff;
  syscfg_adc_dc2_disable(SYSCFG_ADC2);
  ASSERT_EQ(SYSCFG->PMC, ~(1u << 17));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_SYSCFG_ADC3DC)
  SYSCFG->PMC = 0;
  syscfg_adc_dc2_enable(SYSCFG_ADC3);
  ASSERT_EQ(SYSCFG->PMC, (1u << 18));
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = ~(1u << 18);
  syscfg_adc_dc2_enable(SYSCFG_ADC3);
  ASSERT_EQ(SYSCFG->PMC, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = (1u << 18);
  syscfg_adc_dc2_disable(SYSCFG_ADC3);
  ASSERT_EQ(SYSCFG->PMC, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = 0xffffffff;
  syscfg_adc_dc2_disable(SYSCFG_ADC3);
  ASSERT_EQ(SYSCFG->PMC, ~(1u << 18));
  ASSERT_FALSE(execution_halted());

#endif

}
#endif

#if defined(STM32_SYSCFG_PMC) && defined(STM32_SYSCFG_PMC_MII_RMII)
void
test_syscfg_set_ethernet_phy_interface(void)
{
  SYSCFG->PMC = 0;
  syscfg_set_ethernet_phy_interface(SYSCFH_ETH_PHY_INTERFACE_RMII_PHY);
  ASSERT_EQ(SYSCFG->PMC, (1u << 23));
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = ~(1u << 23);
  syscfg_set_ethernet_phy_interface(SYSCFH_ETH_PHY_INTERFACE_RMII_PHY);
  ASSERT_EQ(SYSCFG->PMC, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = (1u << 23);
  syscfg_set_ethernet_phy_interface(SYSCFH_ETH_PHY_INTERFACE_MII);
  ASSERT_EQ(SYSCFG->PMC, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->PMC = 0xffffffff;
  syscfg_set_ethernet_phy_interface(SYSCFH_ETH_PHY_INTERFACE_MII);
  ASSERT_EQ(SYSCFG->PMC, 0xffffffff & ~(1u << 23));
  ASSERT_FALSE(execution_halted());

}
#endif

void
test_syscfg_set_exti_line(void)
{
#if defined(STM32_GPIOA)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOA)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTA, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOB)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTB, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOC)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTC, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0011u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0011u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0011u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOD)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTD, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0011u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0100u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0100u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0100u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOE)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTE, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0100u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0101u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0101u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0101u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOF)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTF, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0101u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0110u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0110u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0110u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOG)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTG, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0110u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b0111u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b0111u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b0111u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOH)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTH, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b0111u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b1000u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b1000u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b1000u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOI)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTI, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b1000u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b1001u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b1001u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b1001u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOJ)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTJ, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b1001u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN0);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN1);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN2);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR1 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR1 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN3);
  ASSERT_EQ(SYSCFG->EXTICR1, ~(0xfu << 12) | (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN4);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN5);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN6);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR2 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR2 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN7);
  ASSERT_EQ(SYSCFG->EXTICR2, ~(0xfu << 12) | (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN8);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN9);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN10);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR3 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR3 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN11);
  ASSERT_EQ(SYSCFG->EXTICR3, ~(0xfu << 12) | (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 0);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN12);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 0) | (0b1010u << 0));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 4);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN13);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 4) | (0b1010u << 4));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 8);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN14);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 8) | (0b1010u << 8));
  ASSERT_FALSE(execution_halted());

#endif

#if defined(STM32_GPIOK)
  SYSCFG->EXTICR4 = 0;
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->EXTICR4 = ~(0xfu << 12);
  syscfg_set_exti_line(SYSCFG_EXTI_PORTK, SYSCFG_EXTI_PIN15);
  ASSERT_EQ(SYSCFG->EXTICR4, ~(0xfu << 12) | (0b1010u << 12));
  ASSERT_FALSE(execution_halted());

#endif

}

#if defined(STM32_SYSCFG_CFGR2)
void
test_syscfg_cm4_lockup(void)
{
  SYSCFG->CFGR2 = 0;
  syscfg_cm4_lockup_enable();
  ASSERT_EQ(SYSCFG->CFGR2, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR2 = ~(1u << 0);
  syscfg_cm4_lockup_enable();
  ASSERT_EQ(SYSCFG->CFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR2 = (1u << 0);
  syscfg_cm4_lockup_disable();
  ASSERT_EQ(SYSCFG->CFGR2, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR2 = 0xffffffff;
  syscfg_cm4_lockup_disable();
  ASSERT_EQ(SYSCFG->CFGR2, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_CFGR2)
void
test_syscfg_lock_pvd_to_tim1_break_input(void)
{
  SYSCFG->CFGR2 = 0;
  syscfg_lock_pvd_to_tim1_break_input();
  ASSERT_EQ(SYSCFG->CFGR2, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR2 = ~(1u << 2);
  syscfg_lock_pvd_to_tim1_break_input();
  ASSERT_EQ(SYSCFG->CFGR2, 0xffffffff);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_CMPCR)
void
test_syscfg_set_cell_compensation_mode(void)
{
  SYSCFG->CMPCR = 0;
  syscfg_set_cell_compensation_mode(SYSCFG_CELL_COMPENSATION_MODE_ENABLED);
  ASSERT_EQ(SYSCFG->CMPCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->CMPCR = ~(1u << 0);
  syscfg_set_cell_compensation_mode(SYSCFG_CELL_COMPENSATION_MODE_ENABLED);
  ASSERT_EQ(SYSCFG->CMPCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CMPCR = (1u << 0);
  syscfg_set_cell_compensation_mode(SYSCFG_CELL_COMPENSATION_MODE_POWERDOWN);
  ASSERT_EQ(SYSCFG->CMPCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CMPCR = 0xffffffff;
  syscfg_set_cell_compensation_mode(SYSCFG_CELL_COMPENSATION_MODE_POWERDOWN);
  ASSERT_EQ(SYSCFG->CMPCR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_CMPCR)
void
test_syscfg_is_cell_compensation_ready(void)
{
  u32 res;

  SYSCFG->CMPCR = 0;
  res = syscfg_is_cell_compensation_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CMPCR = ~(0x1u << 8);
  res = syscfg_is_cell_compensation_ready();
  ASSERT_EQ(res, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CMPCR = 0x1u << 8;
  res = syscfg_is_cell_compensation_ready();
  ASSERT_EQ(res, 0x1u << 8);
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_CFGR)
void
test_syscfg_force_i2c_fmplus_scl_drive(void)
{
  SYSCFG->CFGR = 0;
  syscfg_force_i2c_fmplus_scl_drive_enable();
  ASSERT_EQ(SYSCFG->CFGR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR = ~(1u << 0);
  syscfg_force_i2c_fmplus_scl_drive_enable();
  ASSERT_EQ(SYSCFG->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR = (1u << 0);
  syscfg_force_i2c_fmplus_scl_drive_disable();
  ASSERT_EQ(SYSCFG->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR = 0xffffffff;
  syscfg_force_i2c_fmplus_scl_drive_disable();
  ASSERT_EQ(SYSCFG->CFGR, ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_CFGR)
void
test_syscfg_force_i2c_fmplus_sda_drive(void)
{
  SYSCFG->CFGR = 0;
  syscfg_force_i2c_fmplus_sda_drive_enable();
  ASSERT_EQ(SYSCFG->CFGR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR = ~(1u << 1);
  syscfg_force_i2c_fmplus_sda_drive_enable();
  ASSERT_EQ(SYSCFG->CFGR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR = (1u << 1);
  syscfg_force_i2c_fmplus_sda_drive_disable();
  ASSERT_EQ(SYSCFG->CFGR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->CFGR = 0xffffffff;
  syscfg_force_i2c_fmplus_sda_drive_disable();
  ASSERT_EQ(SYSCFG->CFGR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_bitstream_clock_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_DFSDM2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 0));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 0);
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_DFSDM2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 0);
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_OFF);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_OFF);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 0));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_dfsdm1_delay_clock(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_dfsdm1_delay_clock_enable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 1));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 1);
  syscfg_dfsdm1_delay_clock_enable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 1);
  syscfg_dfsdm1_delay_clock_disable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_dfsdm1_delay_clock_disable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, ~(1u << 1));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_bitstream_clock_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_DFSDM2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 2);
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_DFSDM2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 2);
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_OFF);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_bitstream_clock_source(SYSCFG_BITSTREAM_CLOCK_SOURCE_OFF);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm1_data_input0_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm1_data_input0_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 2));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 2);
  syscfg_set_dfsdm1_data_input0_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 2);
  syscfg_set_dfsdm1_data_input0_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm1_data_input0_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 2));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm1_data_input2_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm1_data_input2_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 3));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 3);
  syscfg_set_dfsdm1_data_input2_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 3);
  syscfg_set_dfsdm1_data_input2_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm1_data_input2_source(SYSCFG_DFSDM1_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 3));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm1_oc2_gated_clock_distribution(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm1_oc2_gated_clock_distribution(SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 4));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 4);
  syscfg_set_dfsdm1_oc2_gated_clock_distribution(SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 4);
  syscfg_set_dfsdm1_oc2_gated_clock_distribution(SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN0);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm1_oc2_gated_clock_distribution(SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN0);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 4));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm1_oc1_gated_clock_distribution(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm1_oc1_gated_clock_distribution(SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN3);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 5));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 5);
  syscfg_set_dfsdm1_oc1_gated_clock_distribution(SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN3);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 5);
  syscfg_set_dfsdm1_oc1_gated_clock_distribution(SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN1);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm1_oc1_gated_clock_distribution(SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN1);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 5));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm1_clock_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm1_clock_source(SYSCFG_DFSDM1_CLOCK_SOURCE_DM);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 6));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 6);
  syscfg_set_dfsdm1_clock_source(SYSCFG_DFSDM1_CLOCK_SOURCE_DM);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 6);
  syscfg_set_dfsdm1_clock_source(SYSCFG_DFSDM1_CLOCK_SOURCE_CKIN);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm1_clock_source(SYSCFG_DFSDM1_CLOCK_SOURCE_CKIN);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 6));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm1_output_clock(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm1_output_clock(SYSCFG_DFSDM1_OUTPUT_SOURCE_M27);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 7));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 7);
  syscfg_set_dfsdm1_output_clock(SYSCFG_DFSDM1_OUTPUT_SOURCE_M27);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 7);
  syscfg_set_dfsdm1_output_clock(SYSCFG_DFSDM1_OUTPUT_SOURCE_CKOUT);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm1_output_clock(SYSCFG_DFSDM1_OUTPUT_SOURCE_CKOUT);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 7));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_dfsdm2_clock(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_dfsdm2_clock_enable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 8));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 8);
  syscfg_dfsdm2_clock_enable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 8);
  syscfg_dfsdm2_clock_disable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_dfsdm2_clock_disable();
  ASSERT_EQ(SYSCFG->MCHDLYCR, ~(1u << 8));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_data_input0_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_data_input0_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 9));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 9);
  syscfg_set_dfsdm2_data_input0_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 9);
  syscfg_set_dfsdm2_data_input0_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_data_input0_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 9));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_data_input2_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_data_input2_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 10));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 10);
  syscfg_set_dfsdm2_data_input2_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 10);
  syscfg_set_dfsdm2_data_input2_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_data_input2_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 10));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_data_input4_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_data_input4_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 11));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 11);
  syscfg_set_dfsdm2_data_input4_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 11);
  syscfg_set_dfsdm2_data_input4_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_data_input4_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 11));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_data_input6_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_data_input6_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 12));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 12);
  syscfg_set_dfsdm2_data_input6_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 12);
  syscfg_set_dfsdm2_data_input6_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_data_input6_source(SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 12));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_oc4_gated_clock_distribution(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_oc4_gated_clock_distribution(SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN4);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 13));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 13);
  syscfg_set_dfsdm2_oc4_gated_clock_distribution(SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN4);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 13);
  syscfg_set_dfsdm2_oc4_gated_clock_distribution(SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN0);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_oc4_gated_clock_distribution(SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN0);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 13));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_oc3_gated_clock_distribution(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_oc3_gated_clock_distribution(SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN5);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 14));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 14);
  syscfg_set_dfsdm2_oc3_gated_clock_distribution(SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN5);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 14);
  syscfg_set_dfsdm2_oc3_gated_clock_distribution(SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN1);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_oc3_gated_clock_distribution(SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN1);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 14));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_oc2_gated_clock_distribution(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_oc2_gated_clock_distribution(SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN6);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 15));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 15);
  syscfg_set_dfsdm2_oc2_gated_clock_distribution(SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN6);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 15);
  syscfg_set_dfsdm2_oc2_gated_clock_distribution(SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_oc2_gated_clock_distribution(SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN2);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 15));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_oc1_gated_clock_distribution(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_oc1_gated_clock_distribution(SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN7);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 16));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 16);
  syscfg_set_dfsdm2_oc1_gated_clock_distribution(SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN7);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 16);
  syscfg_set_dfsdm2_oc1_gated_clock_distribution(SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN3);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_oc1_gated_clock_distribution(SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN3);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 16));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_clock_source(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_clock_source(SYSCFG_DFSDM2_CLOCK_SOURCE_DM);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 17);
  syscfg_set_dfsdm2_clock_source(SYSCFG_DFSDM2_CLOCK_SOURCE_DM);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 17);
  syscfg_set_dfsdm2_clock_source(SYSCFG_DFSDM2_CLOCK_SOURCE_CKIN);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_clock_source(SYSCFG_DFSDM2_CLOCK_SOURCE_CKIN);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
test_syscfg_set_dfsdm2_output_clock(void)
{
  SYSCFG->MCHDLYCR = 0;
  syscfg_set_dfsdm2_output_clock(SYSCFG_DFSDM2_OUTPUT_SOURCE_M27);
  ASSERT_EQ(SYSCFG->MCHDLYCR, (1u << 17));
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = ~(1u << 17);
  syscfg_set_dfsdm2_output_clock(SYSCFG_DFSDM2_OUTPUT_SOURCE_M27);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = (1u << 17);
  syscfg_set_dfsdm2_output_clock(SYSCFG_DFSDM2_OUTPUT_SOURCE_CKOUT);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0);
  ASSERT_FALSE(execution_halted());

  SYSCFG->MCHDLYCR = 0xffffffff;
  syscfg_set_dfsdm2_output_clock(SYSCFG_DFSDM2_OUTPUT_SOURCE_CKOUT);
  ASSERT_EQ(SYSCFG->MCHDLYCR, 0xffffffff & ~(1u << 17));
  ASSERT_FALSE(execution_halted());

}
#endif

int
main(void)
{
  const test_function_t tests[] =
  {
    TEST_FUNC(test_reg_addr),
#if defined(STM32_SYSCFG_MEMMODE_2BIT)
    TEST_FUNC(test_syscfg_set_memory_mapping),
#endif
#if defined(STM32_SYSCFG_MEMMODE_3BIT)
    TEST_FUNC(test_syscfg_set_memory_mapping),
#endif
#if defined(STM32_SYSCFG_FLASH_BANK_MODE)
    TEST_FUNC(test_syscfg_set_flash_bank_mode),
#endif
#if defined(STM32_SYSCFG_FMC_SWAP)
    TEST_FUNC(test_syscfg_set_fmc_memory_mapping_swap),
#endif
#if defined(STM32_SYSCFG_PMC) && defined(STM32_SYSCFG_ADCxDC)
    TEST_FUNC(test_syscfg_adc_dc2),
#endif
#if defined(STM32_SYSCFG_PMC) && defined(STM32_SYSCFG_PMC_MII_RMII)
    TEST_FUNC(test_syscfg_set_ethernet_phy_interface),
#endif
    TEST_FUNC(test_syscfg_set_exti_line),
#if defined(STM32_SYSCFG_CFGR2)
    TEST_FUNC(test_syscfg_cm4_lockup),
#endif
#if defined(STM32_SYSCFG_CFGR2)
    TEST_FUNC(test_syscfg_lock_pvd_to_tim1_break_input),
#endif
#if defined(STM32_SYSCFG_CMPCR)
    TEST_FUNC(test_syscfg_set_cell_compensation_mode),
#endif
#if defined(STM32_SYSCFG_CMPCR)
    TEST_FUNC(test_syscfg_is_cell_compensation_ready),
#endif
#if defined(STM32_SYSCFG_CFGR)
    TEST_FUNC(test_syscfg_force_i2c_fmplus_scl_drive),
#endif
#if defined(STM32_SYSCFG_CFGR)
    TEST_FUNC(test_syscfg_force_i2c_fmplus_sda_drive),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_bitstream_clock_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_dfsdm1_delay_clock),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_bitstream_clock_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm1_data_input0_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm1_data_input2_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm1_oc2_gated_clock_distribution),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm1_oc1_gated_clock_distribution),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm1_clock_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm1_output_clock),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_dfsdm2_clock),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_data_input0_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_data_input2_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_data_input4_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_data_input6_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_oc4_gated_clock_distribution),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_oc3_gated_clock_distribution),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_oc2_gated_clock_distribution),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_oc1_gated_clock_distribution),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_clock_source),
#endif
#if defined(STM32_SYSCFG_MCHDLYCR)
    TEST_FUNC(test_syscfg_set_dfsdm2_output_clock),
#endif
  };

  return TESTS_RUN(tests);
}
