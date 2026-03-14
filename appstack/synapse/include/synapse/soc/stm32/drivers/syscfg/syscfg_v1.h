#ifndef STM32_DRIVER_SYSCFG_H
#define STM32_DRIVER_SYSCFG_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct syscfg_registers_map
{
  u32 MEMRMP;
  u32 PMC;
  u32 EXTICR1;
  u32 EXTICR2;
  u32 EXTICR3;
  u32 EXTICR4;

  u32 __reserved0;

#if defined(STM32_SYSCFG_CFGR2)
  u32 CFGR2;
#else
  u32 __reserved1;
#endif

#if defined(STM32_SYSCFG_CMPCR)
  u32 CMPCR;
#else
  u32 __reserved2;
#endif

  u32 __reserved3[3];

#if defined(STM32_SYSCFG_CFGR)
  u32 CFGR;
#else
  u32 __reserved4;
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
  u32 MCHDLYCR;
#else
  u32 __reserved5;
#endif
};

// Prevents defining an empty enum.
#if defined(STM32_SYSCFG_FLASH_BANK_MODE)
enum syscfg_memrmp : u32
{
  SYSCFG_MEMRMP_FBMODE = (1 << 8)
};
#endif

#define SYSCFG_MEMRMP_MEMMODE_SHIFT (0)

#if defined(STM32_SYSCFG_MEMMODE_3BIT)
#define SYSCFG_MEMRMP_MEMMODE_MASK (0x7)
#elif defined(STM32_SYSCFG_MEMMODE_2BIT)
#define SYSCFG_MEMRMP_MEMMODE_MASK (0x3)
#endif

enum syscfg_memrmp_memmode : u32
{
  SYSCFG_MEMRMP_MEMMODE_MAIN_FLASH = 0b000,
  SYSCFG_MEMRMP_MEMMODE_SYSTEM_FLASH = 0b001,

#if defined(STM32_SYSCFG_FMC)
  SYSCFG_MEMRMP_MEMMODE_FMC_BANK1 = 0b010,
#endif

  SYSCFG_MEMRMP_MEMMODE_EMBEDDED_SRAM = 0b011,

#if defined(STM32_SYSCFG_FMC_SDRAM)
  SYSCFG_MEMRMP_MEMMODE_FMC_SDRAM_BANK1 = 0b100
#endif
};

#if defined(STM32_SYSCFG_FMC_SWAP)
#define SYSCFG_MEMRMP_SWP_FMC_SHIFT (10)
#define SYSCFG_MEMRMP_SWP_FMC_MASK (0x3)

enum syscfg_memrmp_swpfmc : u32
{
  SYSCFG_MEMRMP_SWPFMC_NOFMC_MAPPING = 0b00,
  SYSCFG_MEMRMP_SWPFMC_SDRAM_NAND_AND_PCCARD_SWAPPED = 0b01,
};
#endif

#if defined(STM32_SYSCFG_PMC)
enum syscfg_pmc : u32
{
#if defined(STM32_SYSCFG_ADCxDC)
#if defined(STM32_SYSCFG_ADC1DC)
  SYSCFG_PMC_ADC1DC2 = (1 << 16),
#endif

#if defined(STM32_SYSCFG_ADC2DC)
  SYSCFG_PMC_ADC2DC2 = (1 << 17),
#endif

#if defined(STM32_SYSCFG_ADC3DC)
  SYSCFG_PMC_ADC3DC2 = (1 << 18),
#endif
#endif

#if defined(STM32_SYSCFG_PMC_MII_RMII)
  SYSCFG_PMC_MII_RMII_SEL = (1 << 23)
#endif
};
#endif

#define SYSCFG_EXTICR_EXTI_STRIDE (4)
#define SYSCFG_EXTICR_EXTI_MASK (0xfu)

enum syscfg_exticr : u32
{
#if defined(STM32_GPIOA)
  SYSCFG_EXTICR_PORTA = 0b0000,
#endif

#if defined(STM32_GPIOB)
  SYSCFG_EXTICR_PORTB = 0b0001,
#endif

#if defined(STM32_GPIOC)
  SYSCFG_EXTICR_PORTC = 0b0010,
#endif

#if defined(STM32_GPIOD)
  SYSCFG_EXTICR_PORTD = 0b0011,
#endif

#if defined(STM32_GPIOE)
  SYSCFG_EXTICR_PORTE = 0b0100,
#endif

#if defined(STM32_GPIOF)
  SYSCFG_EXTICR_PORTF = 0b0101,
#endif

#if defined(STM32_GPIOG)
  SYSCFG_EXTICR_PORTG = 0b0110,
#endif

#if defined(STM32_GPIOH)
  SYSCFG_EXTICR_PORTH = 0b0111,
#endif

#if defined(STM32_GPIOI)
  SYSCFG_EXTICR_PORTI = 0b1000,
#endif

#if defined(STM32_GPIOJ)
  SYSCFG_EXTICR_PORTJ = 0b1001,
#endif

#if defined(STM32_GPIOK)
  SYSCFG_EXTICR_PORTK = 0b1010
#endif
};

#if defined(STM32_SYSCFG_CFGR2)
enum syscfg_cfgr2 : u32
{
  SYSCFG_CFGR2_CLL = (1 << 0),
  SYSCFG_CFGR2_PVDL = (1 << 2)
};
#endif

enum syscfg_cmpcr : u32
{
  SYSCFG_CMPCR_CMPPD = (1 << 0),
  SYSCFG_CMPCR_READY = (1 << 8)
};

#if defined(STM32_SYSCFG_CFGR)
enum syscfg_cfgr : u32
{
  SYSCFG_CFGR_I2CFMP1SCL = (1 << 0),
  SYSCFG_CFGR_I2CFMP1SDA = (1 << 1)
};
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
enum syscfg_mchdlycr : u32
{
  SYSCFG_MCHDLYCR_BSCKSEL = (1 << 0),
  SYSCFG_MCHDLYCR_MCHDLYEN1 = (1 << 1),
  SYSCFG_MCHDLYCR_DFSDM1D0SEL = (1 << 2),
  SYSCFG_MCHDLYCR_DFSDM1D2SEL = (1 << 3),
  SYSCFG_MCHDLYCR_DFSDM1CK02SEL = (1 << 4),
  SYSCFG_MCHDLYCR_DFSFM1CK13SEL = (1 << 5),
  SYSCFG_MCHDLYCR_DFSDM1CFG = (1 << 6),
  SYSCFG_MCHDLYCR_DFSDM1CKOSEL = (1 << 7),
  SYSCFG_MCHDLYCR_MCHDLYEN2 = (1 << 8),
  SYSCFG_MCHDLYCR_DFSDM2D0SEL = (1 << 9),
  SYSCFG_MCHDLYCR_DFSDM2D2SEL = (1 << 10),
  SYSCFG_MCHDLYCR_DFSDM2D4SEL = (1 << 11),
  SYSCFG_MCHDLYCR_DFSDM2D6SEL = (1 << 12),
  SYSCFG_MCHDLYCR_DFSDM2CK04SEL = (1 << 13),
  SYSCFG_MCHDLYCR_DFSDM2CK15SEL = (1 << 14),
  SYSCFG_MCHDLYCR_DFSDM2CK26SEL = (1 << 15),
  SYSCFG_MCHDLYCR_DFSDM2CK37SEL = (1 << 16),
  SYSCFG_MCHDLYCR_DFSDM2CFG = (1 << 17),
  SYSCFG_MCHDLYCR_DFSDM2CKOSEL = (1 << 18)
};
#endif

// API

enum syscfg_memory_mapping
{
  SYSCFG_MEMORY_MAPPING_MAIN_FLASH,
  SYSCFG_MEMORY_MAPPING_SYSTEM_FLASH,

#if defined(STM32_SYSCFG_FMC)
  SYSCFG_MEMORY_MAPPING_FMC_BANK1,
#endif

  SYSCFG_MEMORY_MAPPING_EMBEDDED_SRAM,

#if defined(STM32_SYSCFG_FMC_SDRAM)
  SYSCFG_MEMORY_MAPPING_FMC_SDRAM_BANK1
#endif
};

#if defined(STM32_SYSCFG_FLASH_BANK_MODE)
enum syscfg_flash_bank_mode
{
  SYSCFG_FLASH_BANK_MODE_BANK1,
  SYSCFG_FLASH_BANK_MODE_BANK2
};
#endif

#if defined(STM32_SYSCFG_FMC_SWAP)
enum syscfg_fmc_memswap
{
  SYSCFG_FMC_MEMSWAP_NOSWAP,
  SYSCFG_FMC_MEMSWAP_SDRAM_PCCARD_SWAP
};
#endif

#if defined(STM32_SYSCFG_PMC_MII_RMII)
enum syscfg_eth_phy_interface
{
  SYSCFH_ETH_PHY_INTERFACE_MII,
  SYSCFH_ETH_PHY_INTERFACE_RMII_PHY
};
#endif

enum syscfg_adc
{
  SYSCFG_ADC1,

#if defined(STM32_SYSCFG_ADC2DC)
  SYSCFG_ADC2,
#endif

#if defined(STM32_SYSCFG_ADC3DC)
  SYSCFG_ADC3
#endif
};

enum syscfg_exti_port
{
#if defined(STM32_GPIOA)
  SYSCFG_EXTI_PORTA,
#endif

#if defined(STM32_GPIOB)
  SYSCFG_EXTI_PORTB,
#endif

#if defined(STM32_GPIOC)
  SYSCFG_EXTI_PORTC,
#endif

#if defined(STM32_GPIOD)
  SYSCFG_EXTI_PORTD,
#endif

#if defined(STM32_GPIOE)
  SYSCFG_EXTI_PORTE,
#endif

#if defined(STM32_GPIOF)
  SYSCFG_EXTI_PORTF,
#endif

#if defined(STM32_GPIOG)
  SYSCFG_EXTI_PORTG,
#endif

#if defined(STM32_GPIOH)
  SYSCFG_EXTI_PORTH,
#endif

#if defined(STM32_GPIOI)
  SYSCFG_EXTI_PORTI,
#endif

#if defined(STM32_GPIOJ)
  SYSCFG_EXTI_PORTJ,
#endif

#if defined(STM32_GPIOK)
  SYSCFG_EXTI_PORTK
#endif
};

enum syscfg_exti_pin
{
  SYSCFG_EXTI_PIN0,
  SYSCFG_EXTI_PIN1,
  SYSCFG_EXTI_PIN2,
  SYSCFG_EXTI_PIN3,
  SYSCFG_EXTI_PIN4,
  SYSCFG_EXTI_PIN5,
  SYSCFG_EXTI_PIN6,
  SYSCFG_EXTI_PIN7,
  SYSCFG_EXTI_PIN8,
  SYSCFG_EXTI_PIN9,
  SYSCFG_EXTI_PIN10,
  SYSCFG_EXTI_PIN11,
  SYSCFG_EXTI_PIN12,
  SYSCFG_EXTI_PIN13,
  SYSCFG_EXTI_PIN14,
  SYSCFG_EXTI_PIN15
};

#if defined(STM32_SYSCFG_CMPCR)
enum syscfg_cell_compensation_mode
{
  SYSCFG_CELL_COMPENSATION_MODE_POWERDOWN,
  SYSCFG_CELL_COMPENSATION_MODE_ENABLED
};
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
enum syscfg_bitstream_clock_source
{
  SYSCFG_BITSTREAM_CLOCK_SOURCE_OFF,
  SYSCFG_BITSTREAM_CLOCK_SOURCE_DFSDM2
};

enum syscfg_dfsdm
{
  SYSCFG_DFSDM1,
  SYSCFG_DFSDM2
};

enum syscfg_dfsdm1_data_input_source
{
  SYSCFG_DFSDM1_DATA_INPUT_SOURCE_UNIQUE,
  SYSCFG_DFSDM1_DATA_INPUT_SOURCE_SHARED
};

enum syscfg_dfsdm1_oc2_gated_clock_distrubition
{
  SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN0,
  SYSCFG_DFSDM1_OC2_GATED_CLOCK_DISTRUBITION_CKIN2
};

enum syscfg_dfsdm1_oc1_gated_clock_distrubition
{
  SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN1,
  SYSCFG_DFSDM1_OC1_GATED_CLOCK_DISTRUBITION_CKIN3
};

enum syscfg_dfsdm1_clock_source
{
  SYSCFG_DFSDM1_CLOCK_SOURCE_CKIN,
  SYSCFG_DFSDM1_CLOCK_SOURCE_DM
};

enum syscfg_dfsdm1_output_source
{
  SYSCFG_DFSDM1_OUTPUT_SOURCE_CKOUT,
  SYSCFG_DFSDM1_OUTPUT_SOURCE_M27
};

enum syscfg_dfsdm2_data_input_source
{
  SYSCFG_DFSDM2_DATA_INPUT_SOURCE_UNIQUE,
  SYSCFG_DFSDM2_DATA_INPUT_SOURCE_SHARED
};

enum syscfg_dfsdm2_oc4_gated_clock_distribution
{
  SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN0,
  SYSCFG_DFSDM2_OC4_GATED_CLOCK_DISTRIBUTION_CKIN4
};

enum syscfg_dfsdm2_oc3_gated_clock_distribution
{
  SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN1,
  SYSCFG_DFSDM2_OC3_GATED_CLOCK_DISTRIBUTION_CKIN5
};

enum syscfg_dfsdm2_oc2_gated_clock_distribution
{
  SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN2,
  SYSCFG_DFSDM2_OC2_GATED_CLOCK_DISTRIBUTION_CKIN6
};

enum syscfg_dfsdm2_oc1_gated_clock_distribution
{
  SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN3,
  SYSCFG_DFSDM2_OC1_GATED_CLOCK_DISTRIBUTION_CKIN7
};

enum syscfg_dfsdm2_clock_source
{
  SYSCFG_DFSDM2_CLOCK_SOURCE_CKIN,
  SYSCFG_DFSDM2_CLOCK_SOURCE_DM
};

enum syscfg_dfsdm2_output_source
{
  SYSCFG_DFSDM2_OUTPUT_SOURCE_CKOUT,
  SYSCFG_DFSDM2_OUTPUT_SOURCE_M27
};
#endif

extern volatile struct syscfg_registers_map* SYSCFG;

void
syscfg_set_memory_mapping(
  enum syscfg_memory_mapping mem_mapping
);

#if defined(STM32_SYSCFG_FLASH_BANK_MODE)
void
syscfg_set_flash_bank_mode(
  enum syscfg_flash_bank_mode mode
);
#endif

#if defined(STM32_SYSCFG_FMC_SWAP)
void
syscfg_set_fmc_memory_mapping_swap(
  enum syscfg_fmc_memswap swap
);
#endif

#if defined(STM32_SYSCFG_ADCxDC)
void
syscfg_adc_dc2_enable(
  enum syscfg_adc adc
);
#endif

void
syscfg_adc_dc2_disable(
  enum syscfg_adc adc
);

#if defined(STM32_SYSCFG_PMC_MII_RMII)
void
syscfg_set_ethernet_phy_interface(
  enum syscfg_eth_phy_interface interface
);
#endif

void
syscfg_set_exti_line(
  enum syscfg_exti_port port,
  enum syscfg_exti_pin pin
);

#if defined(STM32_SYSCFG_CFGR2)
void
syscfg_cm4_lockup_enable(void);

void
syscfg_cm4_lockup_disable(void);

void
syscfg_lock_pvd_to_tim1_break_input(void);
#endif

#if defined(STM32_SYSCFG_CMPCR)
void
syscfg_set_cell_compensation_mode(
  enum syscfg_cell_compensation_mode mode
);

u32
syscfg_is_cell_compensation_ready(void);
#endif

#if defined(STM32_SYSCFG_CFGR)
void
syscfg_force_i2c_fmplus_scl_drive_enable(void);

void
syscfg_force_i2c_fmplus_scl_drive_disable(void);

void
syscfg_force_i2c_fmplus_sda_drive_enable(void);

void
syscfg_force_i2c_fmplus_sda_drive_disable(void);
#endif

#if defined(STM32_SYSCFG_MCHDLYCR)
void
syscfg_set_bitstream_clock_source(
  enum syscfg_bitstream_clock_source source
);

void
syscfg_dfsdm2_clock_enable(void);

void
syscfg_dfsdm2_clock_disable(void);

void
syscfg_set_dfsdm1_data_input0_source(
  enum syscfg_dfsdm1_data_input_source source
);

void
syscfg_set_dfsdm1_data_input2_source(
  enum syscfg_dfsdm1_data_input_source source
);

void
syscfg_set_dfsdm1_oc2_gated_clock_distribution(
  enum syscfg_dfsdm1_oc2_gated_clock_distrubition distribution
);

void
syscfg_set_dfsdm1_oc1_gated_clock_distribution(
  enum syscfg_dfsdm1_oc1_gated_clock_distrubition distribution
);

void
syscfg_set_dfsdm1_clock_source(
  enum syscfg_dfsdm1_clock_source source
);

void
syscfg_set_dfsdm1_output_clock(
  enum syscfg_dfsdm1_output_source source
);

void
syscfg_dfsdm1_delay_clock_enable(void);

void
syscfg_dfsdm1_delay_clock_disable(void);

void
syscfg_set_dfsdm2_data_input0_source(
  enum syscfg_dfsdm2_data_input_source source
);

void
syscfg_set_dfsdm2_data_input0_source(
  enum syscfg_dfsdm2_data_input_source source
);

void
syscfg_set_dfsdm2_data_input2_source(
  enum syscfg_dfsdm2_data_input_source source
);

void
syscfg_set_dfsdm2_data_input4_source(
  enum syscfg_dfsdm2_data_input_source source
);

void
syscfg_set_dfsdm2_data_input6_source(
  enum syscfg_dfsdm2_data_input_source source
);

void
syscfg_set_dfsdm2_oc4_gated_clock_distribution(
  enum syscfg_dfsdm2_oc4_gated_clock_distribution distribution
);

void
syscfg_set_dfsdm2_oc3_gated_clock_distribution(
  enum syscfg_dfsdm2_oc3_gated_clock_distribution distribution
);

void
syscfg_set_dfsdm2_oc2_gated_clock_distribution(
  enum syscfg_dfsdm2_oc2_gated_clock_distribution distribution
);

void
syscfg_set_dfsdm2_oc1_gated_clock_distribution(
  enum syscfg_dfsdm2_oc1_gated_clock_distribution distribution
);

void
syscfg_set_dfsdm2_clock_source(
  enum syscfg_dfsdm2_clock_source source
);

void
syscfg_set_dfsdm2_output_clock(
  enum syscfg_dfsdm2_output_source source
);
#endif

END_DECLARATIONS

#endif
