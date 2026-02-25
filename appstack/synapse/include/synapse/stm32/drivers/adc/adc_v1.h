#ifndef STM32_DRIVER_ADC_H
#define STM32_DRIVER_ADC_H 

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct adc_registers_map
{
  u32 SR;
  u32 CR1;
  u32 CR2;
  u32 SMPR1;
  u32 SMPR2;
  u32 JOFR1;
  u32 JOFR2;
  u32 JOFR3;
  u32 JOFR4;
  u32 HTR;
  u32 LTR;
  u32 SQR1;
  u32 SQR2;
  u32 SQR3;
  u32 JSQR;
  u32 JDR1;
  u32 JDR2;
  u32 JDR3;
  u32 JDR4;
  u32 DR;
};

#if defined(STM32_ADC_COM)

struct adc_common_registers_map
{
#if defined(STM32_ADC_CSR_REG)
  u32 CSR;
#else
  u32 __reserved0;
#endif

#if defined(STM32_ADC_CCR_REG)
  u32 CCR;
#else
  u32 __reserved1;
#endif

#if defined(STM32_ADC_CDR_REG)
  u32 CDR;
#else
  u32 __reserved2;
#endif
};
#endif

// Core
enum adc_sr : u32
{
  ADC_SR_AWD = (1 << 0),
  ADC_SR_EOC = (1 << 1),
  ADC_SR_JEOC = (1 << 2),
  ADC_SR_JSTRT = (1 << 3),
  ADC_SR_STRT = (1 << 4),

#if defined(STM32_ADC_OVR)
  ADC_SR_OVR = (1 << 5)
#endif
};

enum adc_cr1 : u32
{
  ADC_CR1_EOCIE = (1 << 5),
  ADC_CR1_AWDIE = (1 << 6),
  ADC_CR1_JEOCIE = (1 << 7),
  ADC_CR1_SCAN = (1 << 8),
  ADC_CR1_AWDSGL = (1 << 9),
  ADC_CR1_JAUTO = (1 << 10),
  ADC_CR1_DISCEN = (1 << 11),
  ADC_CR1_JDISCEN = (1 << 12),
  ADC_CR1_JAWDEN = (1 << 22),
  ADC_CR1_AWDEN = (1 << 23),

#if defined(STM32_ADC_OVR)
  ADC_CR1_OVRIE = (1 << 26)
  #endif
};

#if defined(STM32_ADC_RESOLUTION)
#define ADC_CR1_RES_SHIFT (24)
#define ADC_CR1_RES_MASK (0x3)

enum adc_cr1_res : u32
{
  ADC_CR1_RES_12BIT = 0b00,
  ADC_CR1_RES_10BIT = 0b01,
  ADC_CR1_RES_8BIT = 0b10,
  ADC_CR1_RES_6BIT = 0b11
};
#endif

/* Bits[4:0] */
#define ADC_CR1_AWDCH_SHIFT (0)
#define ADC_CR1_AWDCH_MASK (0x1fu)

enum adc_cr1_awdch : u32
{
  ADC_CR1_AWDCH_CH0 = 0b00000,
  ADC_CR1_AWDCH_CH1 = 0b00001,
  ADC_CR1_AWDCH_CH2 = 0b00010,
  ADC_CR1_AWDCH_CH3 = 0b00011,
  ADC_CR1_AWDCH_CH4 = 0b00100,
  ADC_CR1_AWDCH_CH5 = 0b00101,
  ADC_CR1_AWDCH_CH6 = 0b00110,
  ADC_CR1_AWDCH_CH7 = 0b00111,
  ADC_CR1_AWDCH_CH8 = 0b01000,
  ADC_CR1_AWDCH_CH9 = 0b01001,
  ADC_CR1_AWDCH_CH10 = 0b01010,
  ADC_CR1_AWDCH_CH11 = 0b01011,
  ADC_CR1_AWDCH_CH12 = 0b01100,
  ADC_CR1_AWDCH_CH13 = 0b01101,
  ADC_CR1_AWDCH_CH14 = 0b01110,
  ADC_CR1_AWDCH_CH15 = 0b01111,
  ADC_CR1_AWDCH_CH16 = 0b10000,

#if defined(STM32_ADC_AWDCH17)
  ADC_CR1_AWDCH_CH17 = 0b10001,
#endif

#if defined(STM32_ADC_AWDCH18)
  ADC_CR1_AWDCH_CH18 = 0b10010
#endif
};

/* Bits[15:13] */
#define ADC_CR1_DISCNUM_SHIFT (13)
#define ADC_CR1_DISCNUM_MASK (0x7)

#if defined(STM32_ADC_DUALMODE)
#define ADC_CR1_DUALMOD_SHIFT (16)
#define ADC_CR1_DUALMOD_MASK (0xfu)

enum adc_cr1_dualmod : u32
{
  ADC_CR1_DUALMOD_INDEPENDENET = 0b0000,
  ADC_CR1_DUALMOD_REG_SIM_INJ_SIM = 0b0001,
  ADC_CR1_DUALMOD_REG_SIM_ALT_TRG = 0b0010,
  ADC_CR1_DUALMOD_INJ_SIM_FST_INLV = 0b0011,
  ADC_CR1_DUALMOD_INJ_SIM_SLW_INLV = 0b0100,
  ADC_CR1_DUALMOD_INJ_SIM = 0b0101,
  ADC_CR1_DUALMOD_REG_SIM = 0b0110,
  ADC_CR1_DUALMOD_FST_INLV = 0b0111,
  ADC_CR1_DUALMOD_SLW_INLV = 0b1000,
  ADC_CR1_DUALMOD_ALT_TRG = 0b1001
};
#endif

enum adc_cr2 : u32
{
  ADC_CR2_ADON = (1 << 0),
  ADC_CR2_CONT = (1 << 1),

#if defined(STM32_ADC_CALIBRATION)
  ADC_CR2_CAL = (1 << 2),
  ADC_CR2_RSTCAL = (1 << 3),
#endif

  ADC_CR2_DMA = (1 << 8),

#if defined(STM32_ADC_CR2_LAYOUT2)
  ADC_CR2_DDS = (1 << 9),
  ADC_CR2_EOCS = (1 << 10),
#endif

  ADC_CR2_ALIGN = (1 << 11),

#if defined(STM32_ADC_CR2_LAYOUT1)
  ADC_CR2_JEXTTRIG = (1 << 15),
  ADC_CR2_EXTTRIG = (1 << 20),
  ADC_CR2_JSWSTART = (1 << 21),
  ADC_CR2_SWSTART = (1 << 22),
  ADC_CR2_TSVREFE = (1 << 23),
#elif defined(STM32_ADC_CR2_LAYOUT2)
  ADC_CR2_JSWSTART = (1 << 22),
  ADC_CR2_SWSTART = (1 << 30)
#endif
};

#if defined(STM32_ADC_xEXTSEL_LAYOUT1)

#define ADC_CR2_JEXTSEL_SHIFT (12)
#define ADC_CR2_JEXTSEL_MASK (0x7)

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)

#define ADC_CR2_JEXTSEL_SHIFT (16)
#define ADC_CR2_JEXTSEL_MASK (0xf)

#endif

enum adc_cr2_jextsel : u32
{
#if defined(STM32_ADC_xEXTSEL_LAYOUT1)

  ADC_CR2_JEXTSEL_ADC12_TIM1_TRGO = 0b000,
  ADC_CR2_JEXTSEL_ADC12_TIM1_CC4 = 0b001,
  ADC_CR2_JEXTSEL_ADC12_TIM2_TRGO = 0b010,
  ADC_CR2_JEXTSEL_ADC12_TIM2_CC1 = 0b011,
  ADC_CR2_JEXTSEL_ADC12_TIM3_CC4 = 0b100,
  ADC_CR2_JEXTSEL_ADC12_TIM4_TRGO = 0b101,
  ADC_CR2_JEXTSEL_ADC12_EXTI15 = 0b110,
  ADC_CR2_JEXTSEL_ADC12_JSWSTART = 0b111,
  ADC_CR2_JEXTSEL_ADC3_TIM1_TRGO = 0b000,
  ADC_CR2_JEXTSEL_ADC3_TIM1_CC4 = 0b001,
  ADC_CR2_JEXTSEL_ADC3_TIM4_CC3 = 0b010,
  ADC_CR2_JEXTSEL_ADC3_TIM8_CC2 = 0b011,
  ADC_CR2_JEXTSEL_ADC3_TIM8_CC4 = 0b100,
  ADC_CR2_JEXTSEL_ADC3_TIM5_TRGO = 0b101,
  ADC_CR2_JEXTSEL_ADC3_TIM5_CC4 = 0b110,
  ADC_CR2_JEXTSEL_ADC3_JSWSTART = 0b111

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)

  ADC_CR2_JEXTSEL_TIM1_OC4 = 0b0000,
  ADC_CR2_JEXTSEL_TIM1_TRGO = 0b0001,

#if defined(STM32_TIM2)
  ADC_CR2_JEXTSEL_TIM2_OC1 = 0b0010,
  ADC_CR2_JEXTSEL_TIM2_TRGO = 0b0011,
#endif

#if defined(STM32_TIM3)
  ADC_CR2_JEXTSEL_TIM3_OC2 = 0b0100,
  ADC_CR2_JEXTSEL_TIM3_OC4 = 0b0101,
#endif

#if defined(STM32_TIM4)
  ADC_CR2_JEXTSEL_TIM4_OC1 = 0b0110,
  ADC_CR2_JEXTSEL_TIM4_OC2 = 0b0111,
  ADC_CR2_JEXTSEL_TIM4_OC3 = 0b1000,
  ADC_CR2_JEXTSEL_TIM4_TRGO = 0b1001,
#endif

  ADC_CR2_JEXTSEL_TIM5_OC4 = 0b1010,
  ADC_CR2_JEXTSEL_TIM5_TRGO = 0b1011,

#if defined(STM32_TIM8)
  ADC_CR2_JEXTSEL_TIM8_OC2 = 0b1100,
  ADC_CR2_JEXTSEL_TIM8_OC3 = 0b1101,
  ADC_CR2_JEXTSEL_TIM8_OC4 = 0b1110,
#endif

  ADC_CR2_JEXTSEL_EXTI15 = 0b1111

#endif
};

#if defined(STM32_ADC_xEXTSEL_LAYOUT1)

#define ADC_CR2_EXTSEL_SHIFT (17)
#define ADC_CR2_EXTSEL_MASK (0x7)

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)

#define ADC_CR2_EXTSEL_SHIFT (24)
#define ADC_CR2_EXTSEL_MASK (0xf)

#endif

enum adc_cr2_extsel : u32
{
#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
  ADC_CR2_ADC12_EXTSEL_TIM1_CC1 = 0b000,
  ADC_CR2_ADC12_EXTSEL_TIM1_CC2 = 0b0001,
  ADC_CR2_ADC12_EXTSEL_TIM1_CC3 = 0b010,
  ADC_CR2_ADC12_EXTSEL_TIM2_CC2 = 0b011,
  ADC_CR2_ADC12_EXTSEL_TIM3_TRGO = 0b100,
  ADC_CR2_ADC12_EXTSEL_TIM4_CC4 = 0b101,
  ADC_CR2_ADC12_EXTSEL_EXTI11 = 0b110,
  ADC_CR2_ADC12_EXTSEL_SWSTART = 0b111,
  ADC_CR2_ADC3_EXTSEL_TIM3_CC1 = 0b000,
  ADC_CR2_ADC3_EXTSEL_TIM2_CC3 = 0b001,
  ADC_CR2_ADC3_EXTSEL_TIM1_CC3 = 0b010,
  ADC_CR2_ADC3_EXTSEL_TIM8_CC1 = 0b011,
  ADC_CR2_ADC3_EXTSEL_TIM8_TRGO = 0b100,
  ADC_CR2_ADC3_EXTSEL_TIM5_CC1 = 0b101,
  ADC_CR2_ADC3_EXTSEL_TIM5_CC3 = 0b110,
  ADC_CR2_ADC3_EXTSEL_SWSTART = 0b111

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)
  ADC_CR2_EXTSEL_TIM1_OC1 = 0b0000,
  ADC_CR2_EXTSEL_TIM1_OC2 = 0b0001,
  ADC_CR2_EXTSEL_TIM1_OC3 = 0b0010,

#if defined(STM32_TIM2)
  ADC_CR2_EXTSEL_TIM2_OC2 = 0b0011,
  ADC_CR2_EXTSEL_TIM2_OC3 = 0b0100,
  ADC_CR2_EXTSEL_TIM2_OC4 = 0b0101,
  ADC_CR2_EXTSEL_TIM2_TRGO = 0b0110,
#endif

#if defined(STM32_TIM3)
  ADC_CR2_EXTSEL_TIM3_OC1 = 0b0111,
  ADC_CR2_EXTSEL_TIM3_TRGO = 0b1000,
#endif

#if defined(STM32_TIM4)
  ADC_CR2_EXTSEL_TIM4_OC4 = 0b1001,
#endif

  ADC_CR2_EXTSEL_TIM5_OC1 = 0b1010,
  ADC_CR2_EXTSEL_TIM5_OC2 = 0b1011,
  ADC_CR2_EXTSEL_TIM5_OC3 = 0b1100,

#if defined(STM32_TIM8)
  ADC_CR2_EXTSEL_TIM8_OC1 = 0b1101,
  ADC_CR2_EXTSEL_TIM8_TRGO = 0b1110,
#endif

  ADC_CR2_EXTSEL_EXTI11 = 0b1111
#endif
};

#if defined(STM32_ADC_CR2_LAYOUT2)

#define ADC_CR2_JEXTEN_SHIFT (20)
#define ADC_CR2_JEXTEN_MASK (0x3)

enum adc_cr2_jexten : u32
{
  ADC_CR2_JEXTEN_OFF = 0b00,
  ADC_CR2_JEXTEN_RISING_EDGE = 0b01,
  ADC_CR2_JEXTEN_FALLING_EDGE = 0b10,
  ADC_CR2_JEXTEN_BOTH = 0b11
};

#define ADC_CR2_EXTEN_SHIFT (28)
#define ADC_CR2_EXTEN_MASK (0x3)

enum adc_cr2_exten : u32
{
  ADC_CR2_EXTEN_OFF = 0b00,
  ADC_CR2_EXTEN_RISING_EDGE = 0b01,
  ADC_CR2_EXTEN_FALLING_EDGE = 0b10,
  ADC_CR2_EXTEN_BOTH = 0b11
};

#endif

#define ADC_SMPR_STRIDE (3)
#define ADC_SMPR_MASK (0x7u)

#if defined(STM32_ADC_SMPR)
#if defined(STM32_ADC_SMPR_LAYOUT1)

enum adc_smpr : u32
{
  ADC_SMPR_1dot5_CYCLES = 0b000,
  ADC_SMPR_7dot5_CYCLES = 0b001,
  ADC_SMPR_13dot5_CYCLES = 0b010,
  ADC_SMPR_28dot5_CYCLES = 0b011,
  ADC_SMPR_41dot5_CYCLES = 0b100,
  ADC_SMPR_55dot5_CYCLES = 0b101,
  ADC_SMPR_71dot5_CYCLES = 0b110,
  ADC_SMPR_239dot5_CYCLES = 0b111
};

#elif defined(STM32_ADC_SMPR_LAYOUT2)

enum adc_smpr : u32
{
  ADC_SMPR_3CYCLES = 0b000,
  ADC_SMPR_15CYCLES = 0b001,
  ADC_SMPR_28CYCLES = 0b010,
  ADC_SMPR_56CYCLES = 0b011,
  ADC_SMPR_84CYCLES = 0b100,
  ADC_SMPR_112CYCLES = 0b101,
  ADC_SMPR_144CYCLES = 0b110,
  ADC_SMPR_480CYCLES = 0b111
};
#endif
#endif

#define ADC_JOFR_JOFFSET_SHIFT (0)
#define ADC_JOFR_JOFFSET_MASK (0xfff)

#define ADC_HTR_SHIFT (0)
#define ADC_HTR_MASK (0xfffu)

#define ADC_LTR_SHIFT (0)
#define ADC_LTR_MASK (0xfffu)

#define ADC_SQR_L_SHIFT (20)
#define ADC_SQR_L_MASK (0xf)
#define ADC_SQR_STRIDE (5)

#define ADC_JSQR_JL_SHIFT (20)
#define ADC_JSQR_JL_MASK (0x3)
#define ADC_JSQR_STRIDE (5)

#define ADC_JDR_JDATA_SHIFT (0)
#define ADC_JDR_JDATA_MASK (0xffff)

#define ADC_DR_DATA_SHIFT (0)
#define ADC_DR_DATA_MASK (0xffff)

#if defined(STM32_ADC_SHARED_REG_DATA_REGISTER)
#define ADC_DR_ADC2_DATA_SHIFT (16)
#define ADC_DR_ADC2_DATA_MASK (0xffffu)
#endif

#if defined(STM32_ADC_COM)

#if defined(STM32_ADC_CSR_REG)
#endif

#if defined(STM32_ADC_CCR_REG)
enum adc_ccr : u32
{
#if defined(STM32_ADC_COM_DMA)
  ADC_CCR_DDS = (1 << 13),
#endif

  ADC_CCR_VBATE = (1 << 22),
  ADC_CCR_TSVREFE = (1 << 23)
};

#if defined(STM32_ADC_COM_MULTI_MODE)
#define ADC_CCR_MULTI_SHIFT (0)
#define ADC_CCR_MULTI_MASK (0x1f)

enum adc_ccr_multi : u32
{
  ADC_CCR_MULTI_INDEPENDENT_MODE = 0b00000,
  ADC_CCR_MULTI_REG_SIM_AND_INJ_SIM = 0b00001,
  ADC_CCR_MULTI_REG_SIM_AND_ALT_TRG = 0b00010,
  ADC_CCR_MULTI_INJ_SIM = 0b00101,
  ADC_CCR_MULTI_REG_SIM = 0b00110,
  ADC_CCR_MULTI_INTERLEAVED = 0b00111,
  ADC_CCR_MULTI_ALT_TRG = 0b01001
};
#endif

#if defined(STM32_ADC_COM_DELAY)
#define ADC_CCR_DELAY_SHIFT (8)
#define ADC_CCR_DELAY_MASK (0xf)

enum adc_ccr_delay : u32
{
  ADC_CCR_DELAY5 = 0b0000,
  ADC_CCR_DELAY6 = 0b0001,
  ADC_CCR_DELAY7 = 0b0010,
  ADC_CCR_DELAY8 = 0b0011,
  ADC_CCR_DELAY9 = 0b0100,
  ADC_CCR_DELAY10 = 0b0101,
  ADC_CCR_DELAY11 = 0b0110,
  ADC_CCR_DELAY12 = 0b0111,
  ADC_CCR_DELAY13 = 0b1000,
  ADC_CCR_DELAY14 = 0b1001,
  ADC_CCR_DELAY15 = 0b1010,
  ADC_CCR_DELAY16 = 0b1011,
  ADC_CCR_DELAY17 = 0b1100,
  ADC_CCR_DELAY18 = 0b1101,
  ADC_CCR_DELAY19 = 0b1110,
  ADC_CCR_DELAY20 = 0b1111
};
#endif

#if defined(STM32_ADC_COM_DMA)
#define ADC_CCR_DMA_SHIFT (14)
#define ADC_CCR_DMA_MASK (0x3)

enum adc_ccr_dma : u32
{
  ADC_CCR_DMA_OFF = 0b00,
  ADC_CCR_DMA_DMA_MODE1 = 0b01,
  ADC_CCR_DMA_DMA_MODE2 = 0b10,
  ADC_CCR_DMA_DMA_MODE3 = 0b11
};
#endif

#if defined(STM32_ADC_COM_PRE)

#define ADC_CCR_ADCPRE_SHIFT (16)
#define ADC_CCR_ADCPRE_MASK (0x3)

enum adc_ccr_adcpre : u32
{
  ADC_CCR_ADCPRE_DIV2 = 0b00,
  ADC_CCR_ADCPRE_DIV4 = 0b01,
  ADC_CCR_ADCPRE_DIV6 = 0b10,
  ADC_CCR_ADCPRE_DIV8 = 0b11
};
#endif

#endif

#if defined(STM32_ADC_CDR_REG)

#define ADC_CDR_DATA1_SHIFT (0)
#define ADC_CDR_DATA1_MASK (0xffff)

#define ADC_CDR_DATA2_SHIFT (16)
#define ADC_CDR_DATA2_MASK (0xffff)

#endif

#endif

// API
enum adc_reg_channel
{
  ADC_REG_CHANNEL0,
  ADC_REG_CHANNEL1,
  ADC_REG_CHANNEL2,
  ADC_REG_CHANNEL3,
  ADC_REG_CHANNEL4,
  ADC_REG_CHANNEL5,
  ADC_REG_CHANNEL6,
  ADC_REG_CHANNEL7,
  ADC_REG_CHANNEL8,
  ADC_REG_CHANNEL9,
  ADC_REG_CHANNEL10,
  ADC_REG_CHANNEL11,
  ADC_REG_CHANNEL12,
  ADC_REG_CHANNEL13,
  ADC_REG_CHANNEL14,
  ADC_REG_CHANNEL15,
  ADC_REG_CHANNEL16,
  ADC_REG_CHANNEL17,

#if defined(STM32_ADC_MAX_CHANNELS18)
  ADC_REG_CHANNEL18
#endif
};

enum adc_inj_channel
{
  ADC_INJ_CHANNEL0,
  ADC_INJ_CHANNEL1,
  ADC_INJ_CHANNEL2,
  ADC_INJ_CHANNEL3
};

enum adc_flag
{
  ADC_FLAG_ANALOG_WATCHDOG,
  ADC_FLAG_EOC,
  ADC_FLAG_JEOC,
  ADC_FLAG_JSTART,
  ADC_FLAG_START,

#if defined(STM32_ADC_OVR)
  ADC_FLAG_OVERRUN
#endif
};

enum adc_interrupt
{
  ADC_INTERRUPT_EOC,
  ADC_INTERRUPT_ANALOG_WATCHDOG,
  ADC_INTERRUPT_JEOC,

#if defined(STM32_ADC_OVR)
  ADC_INTERRUPT_OVERRUN
#endif
};

enum adc_watchdog_mode
{
  ADC_WATCHDOG_MODE_ALL_CHANNELS,
  ADC_WATCHDOG_MODE_SINGLE_CHANNEL
};

#if defined(STM32_ADC_DUALMODE)
enum adc_dualmode
{
  ADC_DUALMODE_INDEPENDENT,
  ADC_DUALMODE_REG_SIM_AND_INJ_SIM,
  ADC_DUALMODE_REG_SIM_AND_ALT_TRG,
  ADC_DUALMODE_INJ_SIM_AND_FAST_INTERLEAVED,
  ADC_DUALMODE_INJ_SIM_AND_SLOW_INTERLEAVED,
  ADC_DUALMODE_INJ_SIM,
  ADC_DUALMODE_REG_SIM,
  ADC_DUALMODE_FAST_INTERLEAVED,
  ADC_DUALMODE_SLOW_INTERLEAVED,
  ADC_DUALMODE_ALT_TRG
};
#endif

#if defined(STM32_ADC_RESOLUTION)
enum adc_resolution
{
  ADC_RESOLUTION_12BIT,
  ADC_RESOLUTION_10BIT,
  ADC_RESOLUTION_8BIT,
  ADC_RESOLUTION_6BIT
};
#endif

enum adc_conversion_method
{
  ADC_CONVERSION_METHOD_SINGLE,
  ADC_CONVERSION_METHOD_CONTINUOUS
};

#if defined(STM32_ADC_CR2_LAYOUT2)
enum adc_eoc_policy
{
  ADC_EOC_POLICY_EACH_SEQUENCE,
  ADC_EOC_POLICY_EACH_CONVERSION
};
#endif

enum adc_data_alignment
{
  ADC_DATA_ALIGNMENT_RIGHT,
  ADC_DATA_ALIGNMENT_LEFT
};

#if defined(STM32_ADC_xEXTSEL_LAYOUT1)
enum adc_inj_trigger_event
{
  ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_TRGO,
  ADC_INJ_TRIGGER_EVENT_ADC12_TIM1_CC4,
  ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_TRGO,
  ADC_INJ_TRIGGER_EVENT_ADC12_TIM2_CC1,
  ADC_INJ_TRIGGER_EVENT_ADC12_TIM3_CC4,
  ADC_INJ_TRIGGER_EVENT_ADC12_TIM4_TRGO,
  ADC_INJ_TRIGGER_EVENT_ADC12_EXTI,

  ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_TRGO,
  ADC_INJ_TRIGGER_EVENT_ADC3_TIM1_CC4,
  ADC_INJ_TRIGGER_EVENT_ADC3_TIM4_CC3,
  ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC2,
  ADC_INJ_TRIGGER_EVENT_ADC3_TIM8_CC4,
  ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_TRGO,
  ADC_INJ_TRIGGER_EVENT_ADC3_TIM5_CC4,

  ADC_INJ_TRIGGER_EVENT_JSWSTART
};

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)

enum adc_inj_trigger_event
{
  ADC_INJ_TRIGGER_EVENT_TIM1_OC4,
  ADC_INJ_TRIGGER_EVENT_TIM1_TRGO,

#if defined(STM32_TIM2)
  ADC_INJ_TRIGGER_EVENT_TIM2_OC1,
  ADC_INJ_TRIGGER_EVENT_TIM2_TRGO,
#endif

#if defined(STM32_TIM3)
  ADC_INJ_TRIGGER_EVENT_TIM3_OC2,
  ADC_INJ_TRIGGER_EVENT_TIM3_OC4,
#endif

#if defined(STM32_TIM4)
  ADC_INJ_TRIGGER_EVENT_TIM4_OC1,
  ADC_INJ_TRIGGER_EVENT_TIM4_OC2,
  ADC_INJ_TRIGGER_EVENT_TIM4_OC3,
  ADC_INJ_TRIGGER_EVENT_TIM4_TRGO,
#endif

  ADC_INJ_TRIGGER_EVENT_TIM5_OC4,
  ADC_INJ_TRIGGER_EVENT_TIM5_TRGO,

#if defined(STM32_TIM8)
  ADC_INJ_TRIGGER_EVENT_TIM8_OC2,
  ADC_INJ_TRIGGER_EVENT_TIM8_OC3,
  ADC_INJ_TRIGGER_EVENT_TIM8_OC4,
#endif

  ADC_INJ_TRIGGER_EVENT_EXTI15
};
#endif

enum adc_reg_trigger_event
{
#if defined(STM32_ADC_xEXTSEL_LAYOUT1)

  ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC1,
  ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC2,
  ADC_REG_TRIGGER_EVENT_ADC12_TIM1_CC3,
  ADC_REG_TRIGGER_EVENT_ADC12_TIM2_CC2,
  ADC_REG_TRIGGER_EVENT_ADC12_TIM3_TRGO,
  ADC_REG_TRIGGER_EVENT_ADC12_TIM4_CC4,
  ADC_REG_TRIGGER_EVENT_ADC12_EXTI11,
  
  ADC_REG_TRIGGER_EVENT_ADC3_TIM3_CC1,
  ADC_REG_TRIGGER_EVENT_ADC3_TIM2_CC3,
  ADC_REG_TRIGGER_EVENT_ADC3_TIM1_CC3,
  ADC_REG_TRIGGER_EVENT_ADC3_TIM8_CC1,
  ADC_REG_TRIGGER_EVENT_ADC3_TIM8_TRGO,
  ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC1,
  ADC_REG_TRIGGER_EVENT_ADC3_TIM5_CC3,

  ADC_REG_TRIGGER_EVENT_SWSTART,

#elif defined(STM32_ADC_xEXTSEL_LAYOUT2)

  ADC_REG_TRIGGER_EVENT_TIM1_OC1,
  ADC_REG_TRIGGER_EVENT_TIM1_OC2,
  ADC_REG_TRIGGER_EVENT_TIM1_OC3,

#if defined(STM32_TIM2)
  ADC_REG_TRIGGER_EVENT_TIM2_OC2,
  ADC_REG_TRIGGER_EVENT_TIM2_OC3,
  ADC_REG_TRIGGER_EVENT_TIM2_OC4,
  ADC_REG_TRIGGER_EVENT_TIM2_TRGO,
#endif

#if defined(STM32_TIM3)
  ADC_REG_TRIGGER_EVENT_TIM3_OC1,
  ADC_REG_TRIGGER_EVENT_TIM3_TRGO,
#endif

#if defined(STM32_TIM4)
  ADC_REG_TRIGGER_EVENT_TIM4_OC4,
#endif

  ADC_REG_TRIGGER_EVENT_TIM5_OC1,
  ADC_REG_TRIGGER_EVENT_TIM5_OC2,
  ADC_REG_TRIGGER_EVENT_TIM5_OC3,

#if defined(STM32_TIM8)
  ADC_REG_TRIGGER_EVENT_TIM8_OC1,
  ADC_REG_TRIGGER_EVENT_TIM8_TRGO,
#endif

  ADC_REG_TRIGGER_EVENT_EXTI11

#endif
};

#if defined(STM32_ADC_CR2_LAYOUT2)
enum adc_external_trigger_edge
{
  ADC_EXTERNAL_TRIGGER_EDGE_OFF,
  ADC_EXTERNAL_TRIGGER_EDGE_RISING,
  ADC_EXTERNAL_TRIGGER_EDGE_FALLING,
  ADC_EXTERNAL_TRIGGER_EDGE_BOTH
};
#endif

#if defined(STM32_ADC_SMPR)
#if defined(STM32_ADC_SMPR_LAYOUT1)
enum adc_sample_rate
{
  ADC_SAMPLE_RATE_1dot5_CYCLES,
  ADC_SAMPLE_RATE_7dot5_CYCLES,
  ADC_SAMPLE_RATE_13dot5_CYCLES,
  ADC_SAMPLE_RATE_28dot5_CYCLES,
  ADC_SAMPLE_RATE_41dot5_CYCLES,
  ADC_SAMPLE_RATE_55dot5_CYCLES,
  ADC_SAMPLE_RATE_71dot5_CYCLES,
  ADC_SAMPLE_RATE_239dot5_CYCLES
};

#elif defined(STM32_ADC_SMPR_LAYOUT2)
enum adc_sample_rate
{
  ADC_SAMPLE_RATE_3CYCLES,
  ADC_SAMPLE_RATE_15CYCLES,
  ADC_SAMPLE_RATE_28CYCLES,
  ADC_SAMPLE_RATE_56CYCLES,
  ADC_SAMPLE_RATE_84CYCLES,
  ADC_SAMPLE_RATE_112CYCLES,
  ADC_SAMPLE_RATE_144CYCLES,
  ADC_SAMPLE_RATE_480CYCLES
};
#endif
#endif

#if defined(STM32_ADC_COM)

#if defined(STM32_ADC_CSR_REG)
#endif

#if defined(STM32_ADC_CCR_REG)

#if defined(STM32_ADC_COM_MULTI_MODE)
enum adc_multi_adc_config
{
  ADC_MULTI_ADC_CONFIG_DUAL_MODE,
  ADC_MULTI_ADC_CONFIG_TRIPLE_MODE
};

enum adc_multi_adc_mode
{
  ADC_MULTI_ADC_MODE_REG_SIM_AND_INJ_SIM,
  ADC_MULTI_ADC_MODE_REG_SIM_AND_ALT_TRG,
  ADC_MULTI_ADC_MODE_INJ_SIM,
  ADC_MULTI_ADC_MODE_REG_SIM,
  ADC_MULTI_ADC_MODE_INTERLEAVED,
  ADC_MULTI_ADC_MODE_ALT_TRG
};
#endif

#if defined(STM32_ADC_COM_DELAY)
enum adc_sampling_delay
{
  ADC_SAMPLING_DELAY5,
  ADC_SAMPLING_DELAY6,
  ADC_SAMPLING_DELAY7,
  ADC_SAMPLING_DELAY8,
  ADC_SAMPLING_DELAY9,
  ADC_SAMPLING_DELAY10,
  ADC_SAMPLING_DELAY11,
  ADC_SAMPLING_DELAY12,
  ADC_SAMPLING_DELAY13,
  ADC_SAMPLING_DELAY14,
  ADC_SAMPLING_DELAY15,
  ADC_SAMPLING_DELAY16,
  ADC_SAMPLING_DELAY17,
  ADC_SAMPLING_DELAY18,
  ADC_SAMPLING_DELAY19,
  ADC_SAMPLING_DELAY20
};
#endif

#if defined(STM32_ADC_COM_DMA)
enum adc_multi_adc_dma_policy
{
  ADC_MULTI_ADC_DMA_POLICY_LAST_TRANSFER,
  ADC_MULTI_ADC_DMA_POLICY_REPEAT
};

enum adc_multi_adc_dma_mode
{
  ADC_MULTI_ADC_DMA_MODE_OFF,
  ADC_MULTI_ADC_DMA_MODE1,
  ADC_MULTI_ADC_DMA_MODE2,
  ADC_MULTI_ADC_DMA_MODE3
};
#endif

#if defined(STM32_ADC_COM_PRE)
enum adc_multi_adc_prescaler
{
  ADC_MULTI_ADC_PRESCALER_DIV2,
  ADC_MULTI_ADC_PRESCALER_DIV4,
  ADC_MULTI_ADC_PRESCALER_DIV6,
  ADC_MULTI_ADC_PRESCALER_DIV8
};
#endif
#endif

extern volatile struct adc_common_registers_map* ADCCOM;
#endif

#if defined(STM32_ADC1)
extern volatile struct adc_registers_map* ADC1;
#endif

#if defined(STM32_ADC2)
extern volatile struct adc_registers_map* ADC2;
#endif

#if defined(STM32_ADC3)
extern volatile struct adc_registers_map* ADC3;
#endif

u32
adc_is_flag_set(
  volatile struct adc_registers_map* adc,
  enum adc_flag flag
);

void
adc_flag_clear(
  volatile struct adc_registers_map* adc,
  enum adc_flag flag
);

void
adc_set_analog_watchdog_channel(
  volatile struct adc_registers_map* adc,
  enum adc_reg_channel channel
);

void
adc_interrupt_enable(
  volatile struct adc_registers_map* adc,
  enum adc_interrupt interrupt
);

void
adc_interrupt_disable(
  volatile struct adc_registers_map* adc,
  enum adc_interrupt interrupt
);

void
adc_scan_mode_enable(
  volatile struct adc_registers_map* adc
);

void
adc_scan_mode_disable(
  volatile struct adc_registers_map* adc
);

void
adc_set_watchdog_mode(
  volatile struct adc_registers_map* adc,
  enum adc_watchdog_mode mode
);

void
adc_automatic_inj_group_conversion_enable(
  volatile struct adc_registers_map* adc
);

void
adc_automatic_inj_group_conversion_disable(
  volatile struct adc_registers_map* adc
);

void
adc_discontinuous_mode_reg_channels_enable(
  volatile struct adc_registers_map* adc
);

void
adc_discontinuous_mode_reg_channels_disable(
  volatile struct adc_registers_map* adc
);

void
adc_discontinuous_mode_inj_channels_enable(
  volatile struct adc_registers_map* adc
);

void
adc_discontinuous_mode_inj_channels_disable(
  volatile struct adc_registers_map* adc
);

void
adc_set_discontinuous_mode_channel_count(
  volatile struct adc_registers_map* adc,
  u32 count
);

#if defined(STM32_ADC_DUALMODE)
void
adc_set_dualmode(
  volatile struct adc_registers_map* adc,
  enum adc_dualmode mode
);
#endif

void
adc_watchdog_inj_enable(
  volatile struct adc_registers_map* adc
);

void
adc_watchdog_inj_disable(
  volatile struct adc_registers_map* adc
);

void
adc_watchdog_reg_enable(
  volatile struct adc_registers_map* adc
);

void
adc_watchdog_reg_disable(
  volatile struct adc_registers_map* adc
);

#if defined(STM32_ADC_RESOLUTION)
void
adc_set_resolution(
  volatile struct adc_registers_map* adc,
  enum adc_resolution resolution
);
#endif

void
adc_enable(
  volatile struct adc_registers_map* adc
);

void
adc_disable(
  volatile struct adc_registers_map* adc
);

void
adc_set_conversion_method(
  volatile struct adc_registers_map* adc,
  enum adc_conversion_method method
);

#if defined(STM32_ADC_CALIBRATION)
void
adc_calibration_begin(
  volatile struct adc_registers_map* adc
);

u32
adc_is_calibration_in_progress(
  volatile struct adc_registers_map* adc
);

void
adc_calibration_ready_wait(
  volatile struct adc_registers_map* adc
);

void
adc_calibration_reset(
  volatile struct adc_registers_map* adc
);
#endif

void
adc_dma_enable(
  volatile struct adc_registers_map* adc
);

void
adc_dma_disable(
  volatile struct adc_registers_map* adc
);

#if defined(STM32_ADC_CR2_LAYOUT2)
void
adc_dma_requests_enable(
  volatile struct adc_registers_map* adc
);

void
adc_dma_requests_disable(
  volatile struct adc_registers_map* adc
);

void
adc_set_eoc_policy(
  volatile struct adc_registers_map* adc,
  enum adc_eoc_policy policy
);
#endif

void
adc_set_data_alignment(
  volatile struct adc_registers_map* adc,
  enum adc_data_alignment alignment
);

#if defined(STM32_ADC_xEXTSEL_LAYOUT1) || defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
adc_set_inj_external_event(
  volatile struct adc_registers_map* adc,
  enum adc_inj_trigger_event event
);
#endif

void
adc_inj_start(
  volatile struct adc_registers_map* adc
);

#if defined(STM32_ADC_xEXTSEL_LAYOUT1) || defined(STM32_ADC_xEXTSEL_LAYOUT2)
void
adc_set_reg_external_event(
  volatile struct adc_registers_map* adc,
  enum adc_reg_trigger_event event
);
#endif

void
adc_reg_start(
  volatile struct adc_registers_map* adc
);

#if defined(STM32_ADC_CR2_LAYOUT1)
void
adc_temperature_sensor_enable(
  volatile struct adc_registers_map* adc
);

void
adc_temperature_sensor_disable(
  volatile struct adc_registers_map* adc
);
#endif

#if defined(STM32_ADC_CR2_LAYOUT2)
void
adc_set_inj_external_trigger_edge(
  volatile struct adc_registers_map* adc,
  enum adc_external_trigger_edge edge
);

void
adc_set_reg_external_trigger_edge(
  volatile struct adc_registers_map* adc,
  enum adc_external_trigger_edge edge
);
#endif

#if defined(STM32_ADC_SMPR)
void
adc_set_channel_sample_rate(
  volatile struct adc_registers_map* adc,
  enum adc_reg_channel channel,
  enum adc_sample_rate rate
);

void
adc_set_sample_time_all_channels(
  volatile struct adc_registers_map* adc,
  enum adc_sample_rate rate
);
#endif

void
adc_set_inj_offset(
  volatile struct adc_registers_map* adc,
  enum adc_inj_channel channel,
  u32 offset
);

void
adc_set_watchdog_high_threshold(
  volatile struct adc_registers_map* adc,
  u32 threshold
);

void
adc_set_watchdog_low_threshold(
  volatile struct adc_registers_map* adc,
  u32 threshold
);
void

adc_set_reg_sequence(
  volatile struct adc_registers_map* adc,
  u32* sequence,
  u32 count
);

void
adc_set_inj_sequence(
  volatile struct adc_registers_map* adc,
  u32* sequence,
  u32 count
);

u32
adc_inj_data_read(
  volatile struct adc_registers_map* adc,
  enum adc_inj_channel channel
);

u32
adc_reg_data_read(
  volatile struct adc_registers_map* adc
);

#if defined(STM32_ADC_COM)

#if defined(STM32_ADC_CCR_REG)

#if defined(STM32_ADC_COM_MULTI_MODE)
void
adc_set_multi_adc_mode(
  enum adc_multi_adc_config config,
  enum adc_multi_adc_mode mode
);
#endif

#if defined(STM32_ADC_COM_DELAY)
void
adc_set_delay(
  enum adc_sampling_delay delay
);
#endif

#if defined(STM32_ADC_COM_DMA)
void
adc_set_multi_adc_dma_policy(
  enum adc_multi_adc_dma_policy policy
);

void
adc_set_multi_adc_dma_mode(
  enum adc_multi_adc_dma_mode mode
);
#endif

#if defined(STM32_ADC_COM_PRE)
void
adc_set_multi_adc_adc_prescaler(
  enum adc_multi_adc_prescaler prescaler
);
#endif

void
adc_multi_adc_vbat_enable(void);

void
adc_multi_adc_vbat_disable(void);

void
adc_multi_adc_temperature_sensor_enable(void);

void
adc_multi_adc_temperature_sensor_disable(void);

#endif

#if defined(STM32_ADC_CDR_REG)

u32
adc_get_reg_conversion_data1(void);

u32
adc_get_reg_conversion_data2(void);

#endif

#endif

END_DECLARATIONS

#endif
