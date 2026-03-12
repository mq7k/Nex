#ifndef STM32_DRIVER_TIM_H
#define STM32_DRIVER_TIM_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct tim_registers_map
{
  u32 CR1;
  u32 CR2;
  u32 SMCR;
  u32 DIER;
  u32 SR;
  u32 EGR;
  u32 CCMR1;
  u32 CCMR2;
  u32 CCER;
  u32 CNT;
  u32 PSC;
  u32 ARR;
  u32 RCR;
  u32 CCR1;
  u32 CCR2;
  u32 CCR3;
  u32 CCR4;
  u32 BDTR;
  u32 DCR;
  u32 DMAR;
};

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                    Core section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum tim_cr1 : u32
{
  TIM_CR1_CEN = (1 << 0),
  TIM_CR1_UDIS = (1 << 1),
  TIM_CR1_URS = (1 << 2),
  TIM_CR1_OPM = (1 << 3),
  TIM_CR1_DIR = (1 << 4),
  TIM_CR1_ARPE = (1 << 7)
};

#define TIM_CR1_CMS_SHIFT (5)
#define TIM_CR1_CMS_MASK (0x3)

enum tim_cr1_cms : u32
{
  TIM_CR1_CMS_EDGE_ALIGNED = 0b00,
  TIM_CR1_CMS_CENTER_ALIGNED1 = 0b01,
  TIM_CR1_CMS_CENTER_ALIGNED2 = 0b10,
  TIM_CR1_CMS_CENTER_ALIGNED3 = 0b11,
};

#define TIM_CR1_CKD_SHIFT (8)
#define TIM_CR1_CKD_MASK (0x3)

enum tim_cr1_ckd : u32
{
  TIM_CR1_CKD_DTS_CK = 0b00,
  TIM_CR1_CKD_DTS_2CK = 0b01,
  TIM_CR1_CKD_DTS_4CK = 0b10
};

enum tim_cr2_ccpc : u32
{
  TIM_CR2_CCPC = (1 << 0),
  TIM_CR2_CCUS = (1 << 2),
  TIM_CR2_CCDS = (1 << 3),
  TIM_CR2_TI1S = (1 << 7),
  TIM_CR2_OIS1 = (1 << 8),
  TIM_CR2_OIS1N = (1 << 9),
  TIM_CR2_OIS2 = (1 << 10),
  TIM_CR2_OIS2N = (1 << 11),
  TIM_CR2_OIS3 = (1 << 12),
  TIM_CR2_OIS3N = (1 << 13),
  TIM_CR2_OIS4 = (1 << 14)
};

#define TIM_CR2_MMS_SHIFT (4)
#define TIM_CR2_MMS_MASK (0x7)

enum tim_cr2_mms : u32
{
  TIM_CR2_MMS_RESET = 0b000,
  TIM_CR2_MMS_ENABLE = 0b001,
  TIM_CR2_MMS_UPDATE = 0b010,
  TIM_CR2_MMS_COMPARE_PULSE = 0b011,
  TIM_CR2_MMS_COMPARE_OC1 = 0b100,
  TIM_CR2_MMS_COMPARE_OC2 = 0b101,
  TIM_CR2_MMS_COMPARE_OC3 = 0b110,
  TIM_CR2_MMS_COMPARE_OC4 = 0b111
};

enum tim_smcr : u32
{
  TIM_SMCR_MSM = (1 << 7),
  TIM_SMCR_ECE = (1 << 14),
  TIM_SMCR_ETP = (1 << 15)
};

#define TIM_SMCR_SMS_SHIFT (0)
#define TIM_SMCR_SMS_MASK (0x7)

enum tim_smcr_sms : u32
{
  TIM_SMCR_SMS_SLAVE_MODE_DISABLED = 0b000,
  TIM_SMCR_SMS_ENCODER_MODE1 = 0b001,
  TIM_SMCR_SMS_ENCODER_MODE2 = 0b010,
  TIM_SMCR_SMS_ENCODER_MODE3 = 0b011,
  TIM_SMCR_SMS_RESET_MODE = 0b100,
  TIM_SMCR_SMS_GATED_MODE = 0b101,
  TIM_SMCR_SMS_TRIGGER_MODE = 0b110,
  TIM_SMCR_SMS_EXTERNAL_CLOCK_MODE1 = 0b111
};

#define TIM_SMCR_TS_SHIFT (4)
#define TIM_SMCR_TS_MASK (0x7)

enum tim_smcr_ts : u32
{
  TIM_SMCR_TS_ITR0 = 0b000,
  TIM_SMCR_TS_ITR1 = 0b001,
  TIM_SMCR_TS_ITR2 = 0b010,
  TIM_SMCR_TS_ITR3 = 0b011,
  TIM_SMCR_TS_TI1FED = 0b100,
  TIM_SMCR_TS_TI1FP1 = 0b101,
  TIM_SMCR_TS_TI2FP2 = 0b110,
  TIM_SMCR_TS_ETRF = 0b111
};

#define TIM_SMCR_ETF_SHIFT (8)
#define TIM_SMCR_ETF_MASK (0xf)

enum tim_smcr_etf : u32
{
  TIM_SMCR_ETF_NOFILTER = 0b0000,
  TIM_SMCR_ETF_NODIV_N2 = 0b0001,
  TIM_SMCR_ETF_NODIV_N4 = 0b0010,
  TIM_SMCR_ETF_NODIV_N8 = 0b0011,
  TIM_SMCR_ETF_DIV2_N6 = 0b0100,
  TIM_SMCR_ETF_DIV2_N8 = 0b0101,
  TIM_SMCR_ETF_DIV4_N6 = 0b0110,
  TIM_SMCR_ETF_DIV4_N8 = 0b0111,
  TIM_SMCR_ETF_DIV8_N6 = 0b1000,
  TIM_SMCR_ETF_DIV8_N8 = 0b1001,
  TIM_SMCR_ETF_DIV16_N5 = 0b1010,
  TIM_SMCR_ETF_DIV16_N6 = 0b1011,
  TIM_SMCR_ETF_DIV16_N8 = 0b1100,
  TIM_SMCR_ETF_DIV32_N5 = 0b1101,
  TIM_SMCR_ETF_DIV32_N6 = 0b1110,
  TIM_SMCR_ETF_DIV32_N8 = 0b1111
};

#define TIM_SMCR_ETPS_SHIFT (12)
#define TIM_SMCR_ETPS_MASK (0x3)

enum tim_smcr_etps : u32
{
  TIM_SMCR_ETPS_PSC_OFF = 0b00,
  TIM_SMCR_ETPS_ETRP_DIV2 = 0b01,
  TIM_SMCR_ETPS_ETRP_DIV4 = 0b10,
  TIM_SMCR_ETPS_ETRP_DIV8 = 0b11
};

enum tim_dier : u32
{
  TIM_DIER_UIE = (1 << 0),
  TIM_DIER_CC1IE = (1 << 1),
  TIM_DIER_CC2IE = (1 << 2),
  TIM_DIER_CC3IE = (1 << 3),
  TIM_DIER_CC4IE = (1 << 4),
  TIM_DIER_COMIE = (1 << 5),
  TIM_DIER_TIE = (1 << 6),
  TIM_DIER_BIE = (1 << 7),
  TIM_DIER_UDE = (1 << 8),
  TIM_DIER_CC1DE = (1 << 9),
  TIM_DIER_CC2DE = (1 << 10),
  TIM_DIER_CC3DE = (1 << 11),
  TIM_DIER_CC4DE = (1 << 12),
  TIM_DIER_COMDE = (1 << 13),
  TIM_DIER_TDE = (1 << 14)
};

enum tim_sr : u32
{
  TIM_SR_UIF = (1 << 0),
  TIM_SR_CC1IF = (1 << 1),
  TIM_SR_CC2IF = (1 << 2),
  TIM_SR_CC3IF = (1 << 3),
  TIM_SR_CC4IF = (1 << 4),
  TIM_SR_COMIF = (1 << 5),
  TIM_SR_TIF = (1 << 6),
  TIM_SR_BIF = (1 << 7),
  TIM_SR_CC1OF = (1 << 9),
  TIM_SR_CC2OF = (1 << 10),
  TIM_SR_CC3OF = (1 << 11),
  TIM_SR_CC4OF = (1 << 12)
};

enum tim_egr : u32
{
  TIM_EGR_UG = (1 << 0),
  TIM_EGR_CC1G = (1 << 1),
  TIM_EGR_CC2G = (1 << 2),
  TIM_EGR_CC3G = (1 << 3),
  TIM_EGR_CC4G = (1 << 4),
  TIM_EGR_COMG = (1 << 5),
  TIM_EGR_TG = (1 << 6),
  TIM_EGR_BG = (1 << 7)
};

enum tim_ccmr1 : u32
{
  TIM_CCMR1_OC1FE = (1 << 2),
  TIM_CCMR1_OC1PE = (1 << 3),
  TIM_CCMR1_OC1CE = (1 << 7),
  TIM_CCMR1_OC2FE = (1 << 10),
  TIM_CCMR1_OC2PE = (1 << 11),
  TIM_CCMR1_OC2CE = (1 << 15)
};

#define TIM_CCMR1_CC1S_SHIFT (0)
#define TIM_CCMR1_CC2S_SHIFT (8)
#define TIM_CCMR1_CCS_MASK (0x3)

enum tim_ccmr1_ccs : u32
{
  TIM_CCMR1_CC1S_OUTPUT = 0b00,
  TIM_CCMR1_CC1S_TI1 = 0b01,
  TIM_CCMR1_CC1S_TI2 = 0b10,
  TIM_CCMR1_CC1S_TRC = 0b11,

  TIM_CCMR1_CC2S_OUTPUT = 0b00,
  TIM_CCMR1_CC2S_TI2 = 0b01,
  TIM_CCMR1_CC2S_TI1 = 0b10,
  TIM_CCMR1_CC2S_TRC = 0b11
};

#define TIM_CCMR1_IC1PSC_SHIFT (2)
#define TIM_CCMR1_IC2PSC_SHIFT (10)
#define TIM_CCMR_ICPSC_MASK (0x3)

enum tim_ccmr_icpsc : u32
{
  TIM_CCMR_ICPSC_NOPSC = 0b00,
  TIM_CCMR_ICPSC_2EVENTS = 0b01,
  TIM_CCMR_ICPSC_4EVENTS = 0b10,
  TIM_CCMR_ICPSC_8EVENTS = 0b11
};

#define TIM_CCMR1_IC1F_SHIFT (4)
#define TIM_CCMR1_IC2F_SHIFT (12)
#define TIM_CCMR_ICF_MASK (0xf)

enum tim_ccmr_icf : u32
{
  TIM_CCMR_ICF_NOFILTER = 0b0000,
  TIM_CCMR_ICF_NODIV_N2 = 0b0001,
  TIM_CCMR_ICF_NODIV_N4 = 0b0010,
  TIM_CCMR_ICF_NODIV_N8 = 0b0011,
  TIM_CCMR_ICF_DIV2_N6 = 0b0100,
  TIM_CCMR_ICF_DIV2_N8 = 0b0101,
  TIM_CCMR_ICF_DIV4_N6 = 0b0110,
  TIM_CCMR_ICF_DIV4_N8 = 0b0111,
  TIM_CCMR_ICF_DIV8_N6 = 0b1000,
  TIM_CCMR_ICF_DIV8_N8 = 0b1001,
  TIM_CCMR_ICF_DIV16_N5 = 0b1010,
  TIM_CCMR_ICF_DIV16_N6 = 0b1011,
  TIM_CCMR_ICF_DIV16_N8 = 0b1100,
  TIM_CCMR_ICF_DIV32_N5 = 0b1101,
  TIM_CCMR_ICF_DIV32_N6 = 0b1110,
  TIM_CCMR_ICF_DIV32_N8 = 0b1111
};

#define TIM_CCMR1_OC1M_SHIFT (4)
#define TIM_CCMR1_OC2M_SHIFT (12)
#define TIM_CCMR1_OCM_MASK (0x7)

enum tim_ccmr_ocm : u32
{
  TIM_CCMR_OCM_FROZEN = 0b000,
  TIM_CCMR_OCM_FORCE_HIGH = 0b001,
  TIM_CCMR_OCM_FORCE_LOW = 0b010,
  TIM_CCMR_OCM_TOGGLE = 0b011,
  TIM_CCMR_OCM_FORCE_INACTIVE = 0b100,
  TIM_CCMR_OCM_FORCE_ACTIVE = 0b101,
  TIM_CCMR_OCM_PWM1 = 0b110,
  TIM_CCMR_OCM_PWM2 = 0b111
};

enum tim_ccmr2 : u32
{
  TIM_CCMR2_OC3FE = (1 << 2),
  TIM_CCMR2_OC3PE = (1 << 3),
  TIM_CCMR2_OC3CE = (1 << 7),
  TIM_CCMR2_OC4FE = (1 << 10),
  TIM_CCMR2_OC4PE = (1 << 11),
  TIM_CCMR2_OC4CE = (1 << 15)
};

#define TIM_CCMR2_CC3S_SHIFT (0)
#define TIM_CCMR2_CC4S_SHIFT (8)
#define TIM_CCMR2_CCS_MASK (0x3)

enum tim_ccmr2_ccs : u32
{
  TIM_CCMR2_CC3S_OUTPUT = 0b00,
  TIM_CCMR2_CC3S_TI3 = 0b01,
  TIM_CCMR2_CC3S_TI4 = 0b10,
  TIM_CCMR2_CC3S_TRC = 0b11,

  TIM_CCMR2_CC4S_OUTPUT = 0b00,
  TIM_CCMR2_CC4S_TI4 = 0b01,
  TIM_CCMR2_CC4S_TI3 = 0b10,
  TIM_CCMR2_CC4S_TRC = 0b11
};

#define TIM_CCMR2_IC3PSC_SHIFT (2)
#define TIM_CCMR2_IC4PSC_SHIFT (10)

#define TIM_CCMR2_IC3F_SHIFT (4)
#define TIM_CCMR2_IC4F_SHIFT (12)

#define TIM_CCMR2_OC3M_SHIFT (4)
#define TIM_CCMR2_OC4M_SHIFT (12)
#define TIM_CCMR2_OCM_MASK (0x7)

enum tim_ccer : u32
{
  TIM_CCER_CC1E = (1 << 0),
  TIM_CCER_CC1P = (1 << 1),
  TIM_CCER_CC1NE = (1 << 2),
  TIM_CCER_CC1NP = (1 << 3),
  TIM_CCER_CC2E = (1 << 4),
  TIM_CCER_CC2P = (1 << 5),
  TIM_CCER_CC2NE = (1 << 6),
  TIM_CCER_CC2NP = (1 << 7),
  TIM_CCER_CC3E = (1 << 8),
  TIM_CCER_CC3P = (1 << 9),
  TIM_CCER_CC3NE = (1 << 10),
  TIM_CCER_CC3NP = (1 << 11),
  TIM_CCER_CC4E = (1 << 12),
  TIM_CCER_CC4P = (1 << 13),

#if defined(STM32_TIM_CC4NP)
  TIM_CCER_CC4NP = (1 << 15)
#endif
};

#define TIM_CCER_CCP_MASK (0x3)
#define TIM_CCER_CC1P_SHIFT (1)
#define TIM_CCER_CC2P_SHIFT (5)
#define TIM_CCER_CC3P_SHIFT (9)
#define TIM_CCER_CC4P_SHIFT (13)

enum tim_ccer_ccp : u32
{
  TIM_CCER_CCP_NONINV_RISING_EDGE = 0b00,
  TIM_CCER_CCP_INV_FALLING_EDGE = 0b01,
  TIM_CCER_CCP_NONINV_BOTH_EDGES = 0b11
};

#define TIM_CCER_CCNP_MASK (0x3)
#define TIM_CCER_CC1NP_SHIFT (3)
#define TIM_CCER_CC2NP_SHIFT (7)
#define TIM_CCER_CC3NP_SHIFT (10)
#define TIM_CCER_CC4NP_SHIFT (13)

#define TIM_CNT_MASK (0xffff)
#define TIM_PSC_MASK (0xffff)
#define TIM_ARR_MASK (0xffff)
#define TIM_RCR_MASK (0xff)
#define TIM_CCR_MASK (0xffff)

enum tim_bdtr : u32
{
  TIM_BDTR_OSSI = (1 << 10),
  TIM_BDTR_OSSR = (1 << 11),
  TIM_BDTR_BKE = (1 << 12),
  TIM_BDTR_BKP = (1 << 13),
  TIM_BDTR_AOE = (1 << 14),
  TIM_BDTR_MOE = (1 << 15)
};

#define TIM_BDTR_DTG_MASK (0xff)
#define TIM_BDTR_DTG_SHIFT (0)
#define TIM_BDTR_DTG_FORMULA_SHIFT (5)

enum tim_bdtr_dtg_formula : u32
{
  TIM_BDTR_DTG_FORMULA1 = 0b000,
  TIM_BDTR_DTG_FORMULA2 = 0b100,
  TIM_BDTR_DTG_FORMULA3 = 0b110,
  TIM_BDTR_DTG_FORMULA4 = 0b111
};

#define TIM_BDTR_DTG_FORMULA1_VALUE_MASK (0xff)
#define TIM_BDTR_DTG_FORMULA2_VALUE_MASK (0x3f)
#define TIM_BDTR_DTG_FORMULA3_VALUE_MASK (0x1f)
#define TIM_BDTR_DTG_FORMULA4_VALUE_MASK (0x1f)

#define TIM_BDTR_LOCK_SHIFT (8)
#define TIM_BDTR_LOCK_MASK (0x3)

enum tim_bdtr_lock : u32
{
  TIM_BDTR_LOCK_OFF = 0b00,
  TIM_BDTR_LOCK_LEVEL1 = 0b01,
  TIM_BDTR_LOCK_LEVEL2 = 0b10,
  TIM_BDTR_LOCK_LEVEL3 = 0b11
};

#define TIM_DCR_DBA_SHIFT (0)
#define TIM_DCR_DBA_MASK (0x1f)

#define TIM_DCR_DBL_SHIFT (8)
#define TIM_DCR_DBL_MASK (0x1f)

enum tim_dcr_dba : u32
{
  TIM_DCR_DBA_CR1 = 0,
  TIM_DCR_DBA_CR2 = 1,
  TIM_DCR_DBA_SMCR = 2,
  TIM_DCR_DBA_DIER = 3,
  TIM_DCR_DBA_SR = 4,
  TIM_DCR_DBA_EGR = 5,
  TIM_DCR_DBA_CCMR1 = 6,
  TIM_DCR_DBA_CCMR2 = 7,
  TIM_DCR_DBA_CCER = 8,
  TIM_DCR_DBA_CNT = 9,
  TIM_DCR_DBA_PSC = 10,
  TIM_DCR_DBA_ARR = 11,
  TIM_DCR_DBA_RCR = 12,
  TIM_DCR_DBA_CCR1 = 13,
  TIM_DCR_DBA_CCR2 = 14,
  TIM_DCR_DBA_CCR3 = 15,
  TIM_DCR_DBA_CCR4 = 16,
  TIM_DCR_DBA_BDTR = 17,
  TIM_DCR_DBA_DCR = 18,
  TIM_DCR_DBA_DMAR = 19
};

#define TIM_DMAR_SHIFT (0)
#define TIM_DMAR_MASK (0xffff)

// ┌──────────────────────────────────────────────────────┐
// │                                                      │
// │                     API section                      │
// │                                                      │
// └──────────────────────────────────────────────────────┘

enum tim_update_request_source
{
  TIM_UPDATE_REQUEST_SOURCE_COUNTER_AND_DMA,
  TIM_UPDATE_REQUEST_SOURCE_ALL
};

enum tim_counter_direction
{
  TIM_COUNTER_DIRECTION_UP,
  TIM_COUNTER_DIRECTION_DOWN
};

enum tim_center_aligned_mode
{
  TIM_CENTER_ALIGNED_MODE_EDGE,
  TIM_CENTER_ALIGNED_MODE_1,
  TIM_CENTER_ALIGNED_MODE_2,
  TIM_CENTER_ALIGNED_MODE_3
};

enum tim_clock_division
{
  TIM_CLOCK_DIVISION_NODIV,
  TIM_CLOCK_DIVISION_DIV2,
  TIM_CLOCK_DIVISION_DIV4
};

enum tim_update_trigger
{
  TIM_UPDATE_TRIGGER_COMG_BIT,
  TIM_UPDATE_TRIGGER_COMG_BIT_OR_TRGI
};

enum tim_cc_dma_request_source
{
  TIM_CC_DMA_REQUEST_SOURCE_CC_EVENT,
  TIM_CC_DMA_REQUEST_SOURCE_UPDATE_EVENT
};

enum tim_master_mode_trigger
{
  TIM_MASTER_MODE_TRIGGER_RESET,
  TIM_MASTER_MODE_TRIGGER_ENABLE,
  TIM_MASTER_MODE_TRIGGER_UPDATE,
  TIM_MASTER_MODE_TRIGGER_COMPARE_PULSE,
  TIM_MASTER_MODE_TRIGGER_COMPARE_OC1,
  TIM_MASTER_MODE_TRIGGER_COMPARE_OC2,
  TIM_MASTER_MODE_TRIGGER_COMPARE_OC3,
  TIM_MASTER_MODE_TRIGGER_COMPARE_OC4
};

enum tim_ti1_mode
{
  TIM_TI1_MODE_DEFAULT,
  TIM_TI1_MODE_XOR
};

enum tim_channel
{
  TIM_CHANNEL1,
  TIM_CHANNEL2,
  TIM_CHANNEL3,
  TIM_CHANNEL4
};

enum tim_oc_output
{
  TIM_OC_OUTPUT_OIS1,
  TIM_OC_OUTPUT_OIS1N,
  TIM_OC_OUTPUT_OIS2,
  TIM_OC_OUTPUT_OIS2N,
  TIM_OC_OUTPUT_OIS3,
  TIM_OC_OUTPUT_OIS3N,
  TIM_OC_OUTPUT_OIS4
};

enum tim_oc_idle_state
{
  TIM_OC_IDLE_STATE_LOW,
  TIM_OC_IDLE_STATE_HIGH
};

enum tim_slave_mode
{
  TIM_SLAVE_MODE_DISABLED,
  TIM_SLAVE_MODE_ENCODER_MODE_1,
  TIM_SLAVE_MODE_ENCODER_MODE_2,
  TIM_SLAVE_MODE_ENCODER_MODE_3,
  TIM_SLAVE_MODE_RESET_MODE,
  TIM_SLAVE_MODE_GATED_MODE,
  TIM_SLAVE_MODE_TRIGGER_MODE,
  TIM_SLAVE_MODE_EXTERNAL_CLOCK
};

enum tim_input_trigger
{
  TIM_INPUT_TRIGGER_INTERNAL_0,
  TIM_INPUT_TRIGGER_INTERNAL_1,
  TIM_INPUT_TRIGGER_INTERNAL_2,
  TIM_INPUT_TRIGGER_INTERNAL_3,
  TIM_INPUT_TRIGGER_TI1_EDGE,
  TIM_INPUT_TRIGGER_FILTERED_INPUT_1,
  TIM_INPUT_TRIGGER_FILTERED_INPUT_2,
  TIM_INPUT_TRIGGER_EXTERNAL_TRIGGER
};

enum tim_external_trigger_filter
{
  TIM_EXTERNAL_TRIGGER_FILTER_DISABLED,
  TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N2,
  TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N4,
  TIM_EXTERNAL_TRIGGER_FILTER_NODIV_N8,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N6,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV2_N8,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N6,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV4_N8,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N6,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV8_N8,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N5,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N6,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV16_N8,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N5,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N6,
  TIM_EXTERNAL_TRIGGER_FILTER_DIV32_N8
};

enum tim_external_trigger_prescaler
{
  TIM_EXTERNAL_TRIGGER_PRESCALER_OFF,
  TIM_EXTERNAL_TRIGGER_PRESCALER_DIV2,
  TIM_EXTERNAL_TRIGGER_PRESCALER_DIV4,
  TIM_EXTERNAL_TRIGGER_PRESCALER_DIV8
};

enum tim_external_trigger_polarity
{
  TIM_EXTERNAL_TRIGGER_POLARITY_NON_INVERTED,
  TIM_EXTERNAL_TRIGGER_POLARITY_INVERTED
};

enum tim_interrupt
{
  TIM_INTERRUPT_UPDATE,
  TIM_INTERRUPT_CC1,
  TIM_INTERRUPT_CC2,
  TIM_INTERRUPT_CC3,
  TIM_INTERRUPT_CC4,
  TIM_INTERRUPT_COM,
  TIM_INTERRUPT_TRIGGER,
  TIM_INTERRUPT_BREAK
};

enum tim_dma_request
{
  TIM_DMA_MODE_UPDATE,
  TIM_DMA_MODE_CC1,
  TIM_DMA_MODE_CC2,
  TIM_DMA_MODE_CC3,
  TIM_DMA_MODE_CC4,
  TIM_DMA_MODE_COM,
  TIM_DMA_MODE_TRIGGER
};

enum tim_flag
{
  TIM_FLAG_UPDATE,
  TIM_FLAG_CC1_INTERRUPT,
  TIM_FLAG_CC2_INTERRUPT,
  TIM_FLAG_CC3_INTERRUPT,
  TIM_FLAG_CC4_INTERRUPT,
  TIM_FLAG_COM,
  TIM_FLAG_TRIGGER,
  TIM_FLAG_BREAK,
  TIM_FLAG_CC1_OVERCAPTURE,
  TIM_FLAG_CC2_OVERCAPTURE,
  TIM_FLAG_CC3_OVERCAPTURE,
  TIM_FLAG_CC4_OVERCAPTURE
};

enum tim_event
{
  TIM_EVENT_UPDATE,
  TIM_EVENT_CC1,
  TIM_EVENT_CC2,
  TIM_EVENT_CC3,
  TIM_EVENT_CC4,
  TIM_EVENT_COM,
  TIM_EVENT_TRIGGER,
  TIM_EVENT_BREAK
};

enum tim_channel_direction
{
  TIM_CHANNEL_DIRECTION_OUTPUT,
  TIM_CHANNEL_DIRECTION_TI13,
  TIM_CHANNEL_DIRECTION_TI24,
  TIM_CHANNEL_DIRECTION_TRC
};

enum tim_ic_prescaler
{
  TIM_IC_PRESCALER_NOSKIP,
  TIM_IC_PRESCALER_SKIP_2,
  TIM_IC_PRESCALER_SKIP_4,
  TIM_IC_PRESCALER_SKIP_8
};

enum tim_ic_filter
{
  TIM_IC_FILTER_NOFILTER,
  TIM_IC_FILTER_NODIV_N2,
  TIM_IC_FILTER_NODIV_N4,
  TIM_IC_FILTER_NODIV_N8,
  TIM_IC_FILTER_DIV2_N6,
  TIM_IC_FILTER_DIV2_N8,
  TIM_IC_FILTER_DIV4_N6,
  TIM_IC_FILTER_DIV4_N8,
  TIM_IC_FILTER_DIV8_N6,
  TIM_IC_FILTER_DIV8_N8,
  TIM_IC_FILTER_DIV16_N5,
  TIM_IC_FILTER_DIV16_N6,
  TIM_IC_FILTER_DIV16_N8,
  TIM_IC_FILTER_DIV32_N5,
  TIM_IC_FILTER_DIV32_N6,
  TIM_IC_FILTER_DIV32_N8
};

enum tim_oc_mode
{
  TIM_OC_MODE_FROZEN,
  TIM_OC_MODE_FORCED_HIGH,
  TIM_OC_MODE_FORCED_LOW,
  TIM_OC_MODE_TOGGLE,
  TIM_OC_MODE_FORCE_INACTIVE,
  TIM_OC_MODE_FORCE_ACTIVE,
  TIM_OC_MODE_PWM1,
  TIM_OC_MODE_PWM2
};

enum tim_oc_polarity
{
  TIM_OC_POLARITY_ACTIVE_HIGH,
  TIM_OC_POLARITY_ACTIVE_LOW
};

enum tim_ic_polarity
{
  TIM_IC_POLARITY_NON_INVERTED_RISING_EDGE,
  TIM_IC_POLARITY_INVERTED_FALLING_EDGE,
  TIM_IC_POLARITY_NON_INVERTED_BOTH
};

enum tim_deadtime_formula
{
  TIM_DEADTIME_FORMULA1,
  TIM_DEADTIME_FORMULA2,
  TIM_DEADTIME_FORMULA3,
  TIM_DEADTIME_FORMULA4
};

enum tim_lock_configuration
{
  TIM_LOCK_CONFIGURATION_OFF,
  TIM_LOCK_CONFIGURATION_LVL1,
  TIM_LOCK_CONFIGURATION_LVL2,
  TIM_LOCK_CONFIGURATION_LVL3
};

enum tim_idle_mode_off_state
{
  TIM_IDLE_MODE_OFF_STATE_OFF,
  TIM_IDLE_MODE_OFF_STATE_FORCED
};

enum tim_run_mode_off_state
{
  TIM_RUN_MODE_OFF_STATE_OFF,
  TIM_RUN_MODE_OFF_STATE_FORCED
};

enum tim_break_pin_polarity
{
  TIM_BREAK_PIN_POLARITY_OFF,
  TIM_BREAK_PIN_POLARITY_ON
};

enum tim_register
{
  TIM_REGISTER_CR1,
  TIM_REGISTER_CR2,
  TIM_REGISTER_SMCR,
  TIM_REGISTER_DIER,
  TIM_REGISTER_SR,
  TIM_REGISTER_EGR,
  TIM_REGISTER_CCMR1,
  TIM_REGISTER_CCMR2,
  TIM_REGISTER_CCER,
  TIM_REGISTER_CNT,
  TIM_REGISTER_PSC,
  TIM_REGISTER_ARR,
  TIM_REGISTER_RCR,
  TIM_REGISTER_CCR1,
  TIM_REGISTER_CCR2,
  TIM_REGISTER_CCR3,
  TIM_REGISTER_CCR4,
  TIM_REGISTER_BDTR,
  TIM_REGISTER_DCR,
  TIM_REGISTER_DMAR
};

extern volatile struct tim_registers_map* TIM1;
extern volatile struct tim_registers_map* TIM2;
extern volatile struct tim_registers_map* TIM3;
extern volatile struct tim_registers_map* TIM4;
extern volatile struct tim_registers_map* TIM5;
extern volatile struct tim_registers_map* TIM6;
extern volatile struct tim_registers_map* TIM7;
extern volatile struct tim_registers_map* TIM8;
extern volatile struct tim_registers_map* TIM9;
extern volatile struct tim_registers_map* TIM10;
extern volatile struct tim_registers_map* TIM11;
extern volatile struct tim_registers_map* TIM12;
extern volatile struct tim_registers_map* TIM13;
extern volatile struct tim_registers_map* TIM14;

void
tim_counter_enable(
  volatile struct tim_registers_map* tim
);

void
tim_counter_disable(
  volatile struct tim_registers_map* tim
);

void
tim_update_event_enable(
  volatile struct tim_registers_map* tim
);

void
tim_update_event_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_update_request_event_source(
  volatile struct tim_registers_map* tim,
  enum tim_update_request_source source
);

void
tim_one_pulse_mode_enable(
  volatile struct tim_registers_map* tim
);

void
tim_one_pulse_mode_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_counter_direction(
  volatile struct tim_registers_map* tim,
  enum tim_counter_direction direction
);

u32
tim_get_counter_direction(
  volatile struct tim_registers_map* tim
);

void
tim_set_center_aligned_mode(
  volatile struct tim_registers_map* tim,
  enum tim_center_aligned_mode mode
);

void
tim_auto_reload_preload_enable(
  volatile struct tim_registers_map* tim
);

void
tim_auto_reload_preload_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_clock_division(
  volatile struct tim_registers_map* tim,
  enum tim_clock_division division
);

void
tim_cc_preload_enable(
  volatile struct tim_registers_map* tim
);

void
tim_cc_preload_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_cc_update_trigger(
  volatile struct tim_registers_map* tim,
  enum tim_update_trigger trigger
);

void
tim_set_cc_dma_request_source(
  volatile struct tim_registers_map* tim,
  enum tim_cc_dma_request_source source
);

void
tim_set_master_mode_trigger(
  volatile struct tim_registers_map* tim,
  enum tim_master_mode_trigger trigger
);

void
tim_set_ti1_mode(
  volatile struct tim_registers_map* tim,
  enum tim_ti1_mode mode
);

void
tim_set_output_idle_state(
  volatile struct tim_registers_map* tim,
  enum tim_oc_output output,
  enum tim_oc_idle_state state
);

void
tim_set_slave_mode(
  volatile struct tim_registers_map* tim,
  enum tim_slave_mode mode
);

void
tim_set_input_trigger(
  volatile struct tim_registers_map* tim,
  enum tim_input_trigger trigger
);

void
tim_master_slave_sync_enable(
  volatile struct tim_registers_map* tim
);

void
tim_master_slave_sync_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_external_trigger_filter(
  volatile struct tim_registers_map* tim,
  enum tim_external_trigger_filter filter
);

void
tim_set_external_trigger_prescaler(
  volatile struct tim_registers_map* tim,
  enum tim_external_trigger_prescaler prescaler
);

void
tim_external_clock_enable(
  volatile struct tim_registers_map* tim
);

void
tim_external_clock_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_external_trigger_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_external_trigger_polarity polarity
);

void
tim_interrupt_enable(
  volatile struct tim_registers_map* tim,
  enum tim_interrupt interrupt
);

void
tim_interrupt_disable(
  volatile struct tim_registers_map* tim,
  enum tim_interrupt interrupt
);

void
tim_dma_request_enable(
  volatile struct tim_registers_map* tim,
  enum tim_dma_request request
);

void
tim_dma_request_disable(
  volatile struct tim_registers_map* tim,
  enum tim_dma_request request
);

u32
tim_is_flag_set(
  volatile struct tim_registers_map* tim,
  enum tim_flag flag
);

void
tim_flag_clear(
  volatile struct tim_registers_map* tim,
  enum tim_flag flag
);

void
tim_trigger_event_generation(
  volatile struct tim_registers_map* tim,
  enum tim_event event
);

void
tim_set_channel_direction(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_channel_direction direction
);

void
tim_set_channel_ic_prescaler(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_prescaler prescaler
);

void
tim_set_ic_filter(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_filter filter
);

void
tim_oc_fast_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_oc_fast_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_oc_preload_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_oc_preload_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_set_oc_mode(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_oc_mode mode
);

void
tim_oc_clear_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_oc_clear_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_cc_channel_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_cc_channel_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_set_oc_channel_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_oc_polarity polarity
);

void
tim_set_ic_channel_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_polarity polarity
);

void
tim_cc_channel_complementary_output_enable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_cc_channel_complementary_output_disable(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

void
tim_cc_channel_complementary_oc_output_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_oc_polarity polarity
);

void
tim_cc_channel_complementary_ic_output_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  enum tim_ic_polarity polarity
);

void
tim_set_counter_value(
  volatile struct tim_registers_map* tim,
  u32 value
);

u32
tim_get_counter_value(
  volatile struct tim_registers_map* tim
);

void
tim_set_prescaler(
  volatile struct tim_registers_map* tim,
  u32 value
);

u32
tim_get_prescaler(
  volatile struct tim_registers_map* tim
);

void
tim_set_autoreload_value(
  volatile struct tim_registers_map* tim,
  u32 value
);

u32
tim_get_autoreload_value(
  volatile struct tim_registers_map* tim
);

void
tim_set_repetition_counter(
  volatile struct tim_registers_map* tim,
  u32 value
);

u32
tim_get_repetition_counter(
  volatile struct tim_registers_map* tim
);

void
tim_set_cc_value(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel,
  u32 value
);

u32
tim_get_cc_value(
  volatile struct tim_registers_map* tim,
  enum tim_channel channel
);

// Register: BDTR
void
tim_set_deadtime_generator(
  volatile struct tim_registers_map* tim,
  enum tim_deadtime_formula prescaler,
  u32 ticks
);

void
tim_set_dead_time_generator_value(
  volatile struct tim_registers_map* tim,
  u32 value
);

void
tim_set_lock_configuration(
  volatile struct tim_registers_map* tim,
  enum tim_lock_configuration config
);

void
tim_set_idle_mode_off_state(
  volatile struct tim_registers_map* tim,
  enum tim_idle_mode_off_state state
);

void
tim_set_run_mode_off_state(
  volatile struct tim_registers_map* tim,
  enum tim_run_mode_off_state state
);

void
tim_break_input_enable(
  volatile struct tim_registers_map* tim
);

void
tim_break_input_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_break_pin_polarity(
  volatile struct tim_registers_map* tim,
  enum tim_break_pin_polarity polarity
);

void
tim_automatic_output_enable(
  volatile struct tim_registers_map* tim
);

void
tim_automatic_output_disable(
  volatile struct tim_registers_map* tim
);

void
tim_main_output_enable(
  volatile struct tim_registers_map* tim
);

void
tim_main_output_disable(
  volatile struct tim_registers_map* tim
);

void
tim_set_dma_base_address(
  volatile struct tim_registers_map* tim,
  enum tim_register treg
);

void
tim_set_dma_burst_length(
  volatile struct tim_registers_map* tim,
  u32 length
);

void
tim_dma_burst_access_reg_write(
  volatile struct tim_registers_map* tim,
  u32 val
);

u32
tma_dma_burst_access_reg_read(
  volatile struct tim_registers_map* tim
);

END_DECLARATIONS

#endif
