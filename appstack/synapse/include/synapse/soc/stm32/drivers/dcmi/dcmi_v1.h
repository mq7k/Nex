#ifndef STM32_DRIVER_DCMI_H
#define STM32_DRIVER_DCMI_H

#include "synapse/common/util/common.h"
#include "libcom/types.h"
#include "synapse/specs.h"

BEGIN_DECLARATIONS

struct dcmi_registers_map
{
  u32 CR;
  u32 SR;
  u32 RIS;
  u32 IER;
  u32 MIS;
  u32 ICR;
  u32 ESCR;
  u32 ESUR;
  u32 CWSTRT;
  u32 CWSIZE;
  u32 DR;
};

// Core
enum dcmi_cr : u32
{
  DCMI_CR_CAPTURE = (1 << 0),
  DCMI_CR_CM = (1 << 1),
  DCMI_CR_CROP = (1 << 2),
  DCMI_CR_JPEG = (1 << 3),
  DCMI_CR_ESS = (1 << 4),
  DCMI_CR_PCKPOL = (1 << 5),
  DCMI_CR_HSPOL = (1 << 6),
  DCMI_CR_VSPOL = (1 << 7),
  DCMI_CR_ENABLE = (1 << 14),

#if defined(STM32_DCMI_CR_EXTENDED)
  DCMI_CR_OEBS = (1 << 18),
  DCMI_CR_LSM = (1 << 19),
  DCMI_CR_OELS = (1 << 20)
#endif
};

#if defined(STM32_DCMI_CR_EXTENDED)
#define DCMI_CR_BSM_SHIFT (16)
#define DCMI_CR_BSM_MASK (0x3)

enum dcmi_cr_bsm : u32
{
  DCMI_CR_BSM_ALL = 0b00,
  DCMI_CR_BSM_SKIP1 = 0b01,
  DCMI_CR_BSM_SKIP3 = 0b10,
  DCMI_CR_BSM_SKIP2 = 0b11
};
#endif

#define DCMI_CR_FCRC_SHIFT (8)
#define DCMI_CR_FCRC_MASK (0x3)

enum dcmi_cr_fcrc : u32
{
  DCMI_CR_FCRC_ALL = 0b00,
  DCMI_CR_FCRC_SKIP2 = 0b01,
  DCMI_CR_FCRC_SKIP4 = 0b10
};

#define DCMI_CR_EDM_SHIFT (10)
#define DCMI_CR_EDM_MASK (0x3)

enum dcmi_cr_edm : u32
{
  DCMI_CR_EDM_8BIT = 0b00,
  DCMI_CR_EDM_10BIT = 0b01,
  DCMI_CR_EDM_12BIT = 0b10,
  DCMI_CR_EDM_14BIT = 0b11
};

enum dcmi_sr : u32
{
  DCMI_SR_HSYNC = (1 << 0),
  DCMI_SR_VSYNC = (1 << 1),
  DCMI_SR_FNE = (1 << 2)
};

enum dcmi_ris : u32
{
  DCMI_RIS_FRAMERIS = (1 << 0),
  DCMI_RIS_OVRRIS = (1 << 1),
  DCMI_RIS_ERRRIS = (1 << 2),
  DCMI_RIS_VSYNCRIS = (1 << 3),
  DCMI_RIS_LINERIS = (1 << 4)
};

enum dcmi_ier : u32
{
  DCMI_IER_FRAMEIE = (1 << 0),
  DCMI_IER_OVRIE = (1 << 1),
  DCMI_IER_ERRIE = (1 << 2),
  DCMI_IER_VSYNCIE = (1 << 3),
  DCMI_IER_LINEIE = (1 << 4)
};

enum dcmi_mis : u32
{
  DCMI_MIS_FRAMEMIS = (1 << 0),
  DCMI_MIS_OVRMIS = (1 << 1),
  DCMI_MIS_ERRMIS = (1 << 2),
  DCMI_MIS_VSYNCMIS = (1 << 3),
  DCMI_MIS_LINEMIS = (1 << 4)
};

enum dcmi_icr : u32
{
  DCMI_ICR_FRAMEISC = (1 << 0),
  DCMI_ICR_OVRISC = (1 << 1),
  DCMI_ICR_ERRISC = (1 << 2),
  DCMI_ICR_VSYNCISC = (1 << 3),
  DCMI_ICR_LINEISC = (1 << 4)
};

#define DCMI_ESCR_FSC_SHIFT (0)
#define DCMI_ESCR_FSC_MASK (0xffu)

#define DCMI_ESCR_LSC_SHIFT (8)
#define DCMI_ESCR_LSC_MASK (0xffu)

#define DCMI_ESCR_LEC_SHIFT (16)
#define DCMI_ESCR_LEC_MASK (0xffu)

#define DCMI_ESCR_FEC_SHIFT (24)
#define DCMI_ESCR_FEC_MASK (0xffu)

#define DCMI_ESUR_FSU_SHIFT (0)
#define DCMI_ESUR_FSU_MASK (0xffu)

#define DCMI_ESUR_LSU_SHIFT (8)
#define DCMI_ESUR_LSU_MASK (0xffu)

#define DCMI_ESUR_LEU_SHIFT (16)
#define DCMI_ESUR_LEU_MASK (0xffu)

#define DCMI_ESUR_FEU_SHIFT (24)
#define DCMI_ESUR_FEU_MASK (0xffu)

#define DCMI_CWSTRT_HOFFCNT_SHIFT (0)
#define DCMI_CWSTRT_HOFFCNT_MASK (0x3fff)

#define DCMI_CWSTRT_VST_SHIFT (16)
#define DCMI_CWSTRT_VST_MASK (0x1fff)

#define DCMI_CWSIZE_CAPCNT_SHIFT (0)
#define DCMI_CWSIZE_CAPCNT_MASK (0x3fff)

#define DCMI_CWSIZE_VLINE_SHIFT (16)
#define DCMI_CWSIZE_VLINE_MASK (0x3fff)

#define DCMI_DR_BYTE_SHIFT (8)
#define DCMI_DR_BYTE_MASK (0xff)

// API

enum dcmi_capture_mode
{
  DCMI_CAPTURE_MODE_CONTINUOUS,
  DCMI_CAPTURE_MODE_SNAPSHOT
};

enum dcmi_image_crop
{
  DCMI_IMAGE_CROP_FULL_IMAGE,
  DCMI_IMAGE_CROP_WINDOW
};

enum dcmi_jpeg_format
{
  DCMI_JPEG_FORMAT_UNCOMPRESSED,
  DCMI_JPEG_FORMAT_JPEG
};

enum dcmi_embedded_sync
{
  DCMI_EMBEDDED_SYNC_HARDWARE,
  DCMI_EMBEDDED_SYNC_DATA_FLOW
};

enum dcmi_pixel_clock_polarity
{
  DCMI_PIXEL_CLOCK_POLARITY_FALLING_EDGE,
  DCMI_PIXEL_CLOCK_POLARITY_RISING_EDGE
};

enum dcmi_hsync_polarity
{
  DCMI_HSYNC_POLARITY_ACTIVE_LOW,
  DCMI_HSYNC_POLARITY_ACTIVE_HIGH
};

enum dcmi_vsync_polarity
{
  DCMI_VSYNC_POLARITY_ACTIVE_LOW,
  DCMI_VSYNC_POLARITY_ACTIVE_HIGH
};

enum dcmi_frame_capture_rate
{
  DCMI_FRAME_CAPTURE_RATE_ALL,
  DCMI_FRAME_CAPTURE_RATE_SKIP2,
  DCMI_FRAME_CAPTURE_RATE_SKIP4
};

enum dcmi_extended_data_mode
{
  DCMI_EXTENDED_DATA_MODE_8BIT,
  DCMI_EXTENDED_DATA_MODE_10BIT,
  DCMI_EXTENDED_DATA_MODE_12BIT,
  DCMI_EXTENDED_DATA_MODE_14BIT
};

enum dcmi_flag
{
  DCMI_FLAG_HSYNC,
  DCMI_FLAG_VSYNC,
  DCMI_FLAG_FIFO_NOT_EMPTY
};

enum dcmi_interrupt
{
  DCMI_INTERRUPT_CAPTURE_COMPLETE,
  DCMI_INTERRUPT_OVERRUN,
  DCMI_INTERRUPT_SYNC_ERROR,
  DCMI_INTERRUPT_VSYNC,
  DCMI_INTERRUPT_LINE
};

enum dcmi_delimiter
{
  DCMI_DELIMITER_FRAME_START,
  DCMI_DELIMITER_LINE_START,
  DCMI_DELIMITER_LINE_END,
  DCMI_DELIMITER_FRAME_END
};

#if defined(STM32_DCMI_CR_EXTENDED)
enum dcmi_byte_capture_mode
{
  DCMI_BYTE_CAPTURE_MODE_ALL,
  DCMI_BYTE_CAPTURE_MODE_SKIP1,
  DCMI_BYTE_CAPTURE_MODE_SKIP3,
  DCMI_BYTE_CAPTURE_MODE_SKIP2
};

enum dcmi_byte_capture_start
{
  DCMI_BYTE_CAPTURE_START_EVEN,
  DCMI_BYTE_CAPTURE_START_ODD
};

enum dcmi_line_capture_mode
{
  DCMI_LINE_CAPTURE_MODE_ALL,
  DCMI_LINE_CAPTURE_MODE_ALTERNATE
};

enum dcmi_line_capture_start
{
  DCMI_LINE_CAPTURE_START_EVEN,
  DCMI_LINE_CAPTURE_START_ODD
};
#endif

extern volatile struct dcmi_registers_map* DCMI;

void
dcmi_capture_enable(void);

void
dcmi_capture_disable(void);

void
dcmi_set_capture_mode(
  enum dcmi_capture_mode mode
);

void
dcmi_set_image_crop(
  enum dcmi_image_crop crop
);

void
dcmi_set_jpeg_format(
  enum dcmi_jpeg_format format
);

void
dcmi_set_embedded_sync(
  enum dcmi_embedded_sync sync
);

void
dcmi_set_pixel_clock_polarity(
  enum dcmi_pixel_clock_polarity polarity
);

void
dcmi_set_pixel_clock_polarity(
  enum dcmi_pixel_clock_polarity polarity
);

void
dcmi_set_hsync_polarity(
  enum dcmi_hsync_polarity polarity
);

void
dcmi_set_vsync_polarity(
  enum dcmi_vsync_polarity polarity
);

void
dcmi_set_frame_capture_rate(
  enum dcmi_frame_capture_rate rate
);

void
dcmi_set_extended_data_mode(
  enum dcmi_extended_data_mode mode
);

void
dcmi_enable(void);

void
dcmi_disable(void);

#if defined(STM32_DCMI_CR_EXTENDED)
void
dcmi_set_byte_capture_mode(
  enum dcmi_byte_capture_mode mode
);

void
dcmi_set_byte_capture_start(
  enum dcmi_byte_capture_start start
);

void
dcmi_set_line_capture_mode(
  enum dcmi_line_capture_mode mode
);

void
dcmi_set_line_capture_start(
  enum dcmi_line_capture_start start
);
#endif

u32
dcmi_is_flag_set(
  enum dcmi_flag flag
);

u32
dcmi_is_interrupt_event_occurred(
  enum dcmi_interrupt interrupt
);

void
dcmi_interrupt_enable(
  enum dcmi_interrupt interrupt
);

void
dcmi_interrupt_disable(
  enum dcmi_interrupt interrupt
);

u32
dcmi_is_interrupt_pending(
  enum dcmi_interrupt interrupt
);

void
dcmi_interrupt_pending_clear(
  enum dcmi_interrupt interrupt
);

void
dcmi_set_delimiter(
  enum dcmi_delimiter delimiter,
  u32 value
);

void
dcmi_set_delimiter_unmask(
  enum dcmi_delimiter delimiter,
  u32 unmask
);

void
dcmi_set_horizontal_offset(
  u32 offset
);

void
dcmi_set_vertical_start_line(
  u32 line_start
);

void
dcmi_set_capture_count(
  u32 count
);

void
dcmi_set_vertical_line_count(
  u32 count
);

u32
dcmi_data_read(void);

END_DECLARATIONS

#endif
