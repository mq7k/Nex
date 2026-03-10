#include "synapse/stm32/drivers/dcmi/dcmi_v1.h"
#include "synapse/common/util/common.h"
#include "libcom/sys/devmode.h"

typedef volatile struct dcmi_registers_map dcmi_periph;
dcmi_periph* DCMI = (dcmi_periph*) (DCMI_ADDR);

void
dcmi_capture_enable(void)
{
  DCMI->CR |= DCMI_CR_CAPTURE;
}

void
dcmi_capture_disable(void)
{
  DCMI->CR &= ~DCMI_CR_CAPTURE;
}

void
dcmi_set_capture_mode(
  enum dcmi_capture_mode mode
)
{
  volatile u32* reg = &DCMI->CR;
  switch (mode)
  {
    case DCMI_CAPTURE_MODE_CONTINUOUS:
      *reg &= ~DCMI_CR_CM;
      break;

    case DCMI_CAPTURE_MODE_SNAPSHOT:
      *reg |= DCMI_CR_CM;
      break;
      
    default:
      devmode_error_invalid_enum(enum dcmi_capture_mode, mode);
      break;
  }
}

void
dcmi_set_image_crop(
  enum dcmi_image_crop crop
)
{
  volatile u32* reg = &DCMI->CR;
  switch (crop)
  {
    case DCMI_IMAGE_CROP_FULL_IMAGE:
      *reg &= ~DCMI_CR_CROP;
      break;

    case DCMI_IMAGE_CROP_WINDOW:
      *reg |= DCMI_CR_CROP;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_image_crop, crop);
      break;
  }
}

void
dcmi_set_jpeg_format(
  enum dcmi_jpeg_format format
)
{
  volatile u32* reg = &DCMI->CR;
  switch (format)
  {
    case DCMI_JPEG_FORMAT_UNCOMPRESSED:
      *reg &= ~DCMI_CR_JPEG;
      break;

    case DCMI_JPEG_FORMAT_JPEG:
      *reg |= DCMI_CR_JPEG;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_jpeg_format, format);
      break;
  }
}

void
dcmi_set_embedded_sync(
  enum dcmi_embedded_sync sync
)
{
  volatile u32* reg = &DCMI->CR;
  switch (sync)
  {
    case DCMI_EMBEDDED_SYNC_HARDWARE:
      *reg &= ~DCMI_CR_ESS;
      break;

    case DCMI_EMBEDDED_SYNC_DATA_FLOW:
      *reg |= DCMI_CR_ESS;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_embedded_sync, sync);
      break;
  }
}

void
dcmi_set_pixel_clock_polarity(
  enum dcmi_pixel_clock_polarity polarity
)
{
  volatile u32* reg = &DCMI->CR;
  switch (polarity)
  {
    case DCMI_PIXEL_CLOCK_POLARITY_FALLING_EDGE:
      *reg &= ~DCMI_CR_PCKPOL;
      break;

    case DCMI_PIXEL_CLOCK_POLARITY_RISING_EDGE:
      *reg |= DCMI_CR_PCKPOL;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_pixel_clock_polarity, polarity);
      break;
  }
}

void
dcmi_set_hsync_polarity(
  enum dcmi_hsync_polarity polarity
)
{
  volatile u32* reg = &DCMI->CR;
  switch (polarity)
  {
    case DCMI_HSYNC_POLARITY_ACTIVE_LOW:
      *reg &= ~DCMI_CR_HSPOL;
      break;

    case DCMI_HSYNC_POLARITY_ACTIVE_HIGH:
      *reg |= DCMI_CR_HSPOL;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_hsync_polarity, polarity);
      break;
  }
}

void
dcmi_set_vsync_polarity(
  enum dcmi_vsync_polarity polarity
)
{
  volatile u32* reg = &DCMI->CR;
  switch (polarity)
  {
    case DCMI_VSYNC_POLARITY_ACTIVE_LOW:
      *reg &= ~DCMI_CR_VSPOL;
      break;

    case DCMI_VSYNC_POLARITY_ACTIVE_HIGH:
      *reg |= DCMI_CR_VSPOL;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_vsync_polarity, polarity);
      break;
  }
}

void
dcmi_set_frame_capture_rate(
  enum dcmi_frame_capture_rate rate
)
{
  constexpr u32 shift = DCMI_CR_FCRC_SHIFT;
  constexpr u32 mask = DCMI_CR_FCRC_MASK << shift;
  volatile u32* reg = &DCMI->CR;

  switch (rate)
  {
    case DCMI_FRAME_CAPTURE_RATE_ALL:
      *reg &= ~mask;
      break;

    case DCMI_FRAME_CAPTURE_RATE_SKIP2:
      syn_set_register_bits(reg, mask, DCMI_CR_FCRC_SKIP2 << shift);
      break;

    case DCMI_FRAME_CAPTURE_RATE_SKIP4:
      syn_set_register_bits(reg, mask, DCMI_CR_FCRC_SKIP4 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_frame_capture_rate, rate);
      break;
  }
}

void
dcmi_set_extended_data_mode(
  enum dcmi_extended_data_mode mode
)
{
  constexpr u32 shift = DCMI_CR_EDM_SHIFT;
  constexpr u32 mask = DCMI_CR_EDM_MASK << shift;
  volatile u32* reg = &DCMI->CR;

  switch (mode)
  {
    case DCMI_EXTENDED_DATA_MODE_8BIT:
      *reg &= ~mask;
      break;

    case DCMI_EXTENDED_DATA_MODE_10BIT:
      syn_set_register_bits(reg, mask, DCMI_CR_EDM_10BIT << shift);
      break;

    case DCMI_EXTENDED_DATA_MODE_12BIT:
      syn_set_register_bits(reg, mask, DCMI_CR_EDM_12BIT << shift);
      break;

    case DCMI_EXTENDED_DATA_MODE_14BIT:
      *reg |= (DCMI_CR_EDM_14BIT << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_extended_data_mode, mode);
      break;
  }
}

void
dcmi_enable(void)
{
  DCMI->CR |= DCMI_CR_ENABLE;
}

void
dcmi_disable(void)
{
  DCMI->CR &= ~DCMI_CR_ENABLE;
}

#if defined(STM32_DCMI_CR_EXTENDED)
void
dcmi_set_byte_capture_mode(
  enum dcmi_byte_capture_mode mode
)
{
  constexpr u32 shift = DCMI_CR_BSM_SHIFT;
  constexpr u32 mask = DCMI_CR_BSM_MASK << shift;
  volatile u32* reg = &DCMI->CR;

  switch (mode)
  {
    case DCMI_BYTE_CAPTURE_MODE_ALL:
      *reg &= ~mask;
      break;

    case DCMI_BYTE_CAPTURE_MODE_SKIP1:
      syn_set_register_bits(reg, mask, DCMI_CR_BSM_SKIP1 << shift);
      break;

    case DCMI_BYTE_CAPTURE_MODE_SKIP3:
      syn_set_register_bits(reg, mask, DCMI_CR_BSM_SKIP3 << shift);
      break;

    case DCMI_BYTE_CAPTURE_MODE_SKIP2:
      *reg |= (DCMI_CR_BSM_SKIP2 << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_byte_capture_mode, mode);
      break;
  }
}

void
dcmi_set_byte_capture_start(
  enum dcmi_byte_capture_start start
)
{
  volatile u32* reg = &DCMI->CR;
  switch (start)
  {
    case DCMI_BYTE_CAPTURE_START_EVEN:
      *reg &= ~DCMI_CR_OEBS;
      break;

    case DCMI_BYTE_CAPTURE_START_ODD:
      *reg |= DCMI_CR_OEBS;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_byte_capture_start, start);
      break;
  }
}

void
dcmi_set_line_capture_mode(
  enum dcmi_line_capture_mode mode
)
{
  volatile u32* reg = &DCMI->CR;
  switch (mode)
  {
    case DCMI_LINE_CAPTURE_MODE_ALL:
      *reg &= ~DCMI_CR_LSM;
      break;

    case DCMI_LINE_CAPTURE_MODE_ALTERNATE:
      *reg |= DCMI_CR_LSM;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_line_capture_mode, mode);
      break;
  }
}

void
dcmi_set_line_capture_start(
  enum dcmi_line_capture_start start
)
{
  volatile u32* reg = &DCMI->CR;
  switch (start)
  {
    case DCMI_LINE_CAPTURE_START_EVEN:
      *reg &= ~DCMI_CR_OELS;
      break;

    case DCMI_LINE_CAPTURE_START_ODD:
      *reg |= DCMI_CR_OELS;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_line_capture_start, start);
      break;
  }
}
#endif

u32
dcmi_is_flag_set(
  enum dcmi_flag flag
)
{
  volatile u32* reg = &DCMI->SR;
  switch (flag)
  {
    case DCMI_FLAG_HSYNC:
      return *reg & DCMI_SR_HSYNC;

    case DCMI_FLAG_VSYNC:
      return *reg & DCMI_SR_VSYNC;

    case DCMI_FLAG_FIFO_NOT_EMPTY:
      return *reg & DCMI_SR_FNE;

    default:
      devmode_error_invalid_enum(enum dcmi_flag, flag);
      return 0;
  }
}

u32
dcmi_is_interrupt_event_occurred(
  enum dcmi_interrupt interrupt
)
{
  volatile u32* reg = &DCMI->RIS;
  switch (interrupt)
  {
    case DCMI_INTERRUPT_CAPTURE_COMPLETE:
      return *reg & DCMI_RIS_FRAMERIS;

    case DCMI_INTERRUPT_OVERRUN:
      return *reg & DCMI_RIS_OVRRIS;

    case DCMI_INTERRUPT_SYNC_ERROR:
      return *reg & DCMI_RIS_ERRRIS;

    case DCMI_INTERRUPT_VSYNC:
      return *reg & DCMI_RIS_VSYNCRIS;

    case DCMI_INTERRUPT_LINE:
      return *reg & DCMI_RIS_LINERIS;

    default:
      devmode_error_invalid_enum(enum dcmi_interrupt, interrupt);
      return 0;
  }
}

void
dcmi_interrupt_enable(
  enum dcmi_interrupt interrupt
)
{
  volatile u32* reg = &DCMI->IER;
  switch (interrupt)
  {
    case DCMI_INTERRUPT_CAPTURE_COMPLETE:
      *reg |= DCMI_IER_FRAMEIE;
      break;

    case DCMI_INTERRUPT_OVERRUN:
      *reg |= DCMI_IER_OVRIE;
      break;

    case DCMI_INTERRUPT_SYNC_ERROR:
      *reg |= DCMI_IER_ERRIE;
      break;

    case DCMI_INTERRUPT_VSYNC:
      *reg |= DCMI_IER_VSYNCIE;
      break;

    case DCMI_INTERRUPT_LINE:
      *reg |= DCMI_IER_LINEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_interrupt, interrupt);
      break;
  }
}

void
dcmi_interrupt_disable(
  enum dcmi_interrupt interrupt
)
{
  volatile u32* reg = &DCMI->IER;
  switch (interrupt)
  {
    case DCMI_INTERRUPT_CAPTURE_COMPLETE:
      *reg &= ~DCMI_IER_FRAMEIE;
      break;

    case DCMI_INTERRUPT_OVERRUN:
      *reg &= ~DCMI_IER_OVRIE;
      break;

    case DCMI_INTERRUPT_SYNC_ERROR:
      *reg &= ~DCMI_IER_ERRIE;
      break;

    case DCMI_INTERRUPT_VSYNC:
      *reg &= ~DCMI_IER_VSYNCIE;
      break;

    case DCMI_INTERRUPT_LINE:
      *reg &= ~DCMI_IER_LINEIE;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_interrupt, interrupt);
      break;
  }
}

u32
dcmi_is_interrupt_pending(
  enum dcmi_interrupt interrupt
)
{
  volatile u32* reg = &DCMI->MIS;
  switch (interrupt)
  {
    case DCMI_INTERRUPT_CAPTURE_COMPLETE:
      return *reg & DCMI_MIS_FRAMEMIS;
        
    case DCMI_INTERRUPT_OVERRUN:
      return *reg & DCMI_MIS_OVRMIS;

    case DCMI_INTERRUPT_SYNC_ERROR:
      return *reg & DCMI_MIS_ERRMIS;
        
    case DCMI_INTERRUPT_VSYNC:
      return *reg & DCMI_MIS_VSYNCMIS;

    case DCMI_INTERRUPT_LINE:
      return *reg & DCMI_MIS_LINEMIS;

    default:
      devmode_error_invalid_enum(enum dcmi_interrupt, interrupt);
      return 0;
  }
}

void
dcmi_interrupt_pending_clear(
  enum dcmi_interrupt interrupt
)
{
  volatile u32* reg = &DCMI->ICR;
  switch (interrupt)
  {
    case DCMI_INTERRUPT_CAPTURE_COMPLETE:
      *reg |= DCMI_ICR_FRAMEISC;
      break;
        
    case DCMI_INTERRUPT_OVERRUN:
      *reg |= DCMI_ICR_OVRISC;
      break;

    case DCMI_INTERRUPT_SYNC_ERROR:
      *reg |= DCMI_ICR_ERRISC;
      break;
        
    case DCMI_INTERRUPT_VSYNC:
      *reg |= DCMI_ICR_VSYNCISC;
      break;

    case DCMI_INTERRUPT_LINE:
      *reg |= DCMI_ICR_LINEISC;
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_interrupt, interrupt);
      break;
  }
}

void
dcmi_set_delimiter(
  enum dcmi_delimiter delimiter,
  u32 value
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DCMI->ESCR;
  switch (delimiter)
  {
    case DCMI_DELIMITER_FRAME_START:
      devmode_assert_lower_or_eq(value, DCMI_ESCR_FSC_MASK);
      shift = DCMI_ESCR_FSC_SHIFT;
      mask = DCMI_ESCR_FSC_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DCMI_DELIMITER_LINE_START:
      devmode_assert_lower_or_eq(value, DCMI_ESCR_LSC_MASK);
      shift = DCMI_ESCR_LSC_SHIFT;
      mask = DCMI_ESCR_LSC_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DCMI_DELIMITER_LINE_END:
      devmode_assert_lower_or_eq(value, DCMI_ESCR_LEC_MASK);
      shift = DCMI_ESCR_LEC_SHIFT;
      mask = DCMI_ESCR_LEC_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    case DCMI_DELIMITER_FRAME_END:
      devmode_assert_lower_or_eq(value, DCMI_ESCR_FEC_MASK);
      shift = DCMI_ESCR_FEC_SHIFT;
      mask = DCMI_ESCR_FEC_MASK << shift;
      syn_set_register_bits(reg, mask, value << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_delimiter, delimiter);
      break;
  }
}

void
dcmi_set_delimiter_unmask(
  enum dcmi_delimiter delimiter,
  u32 unmask
)
{
  u32 shift;
  u32 mask;
  volatile u32* reg = &DCMI->ESUR;
  
  switch (delimiter)
  {
    case DCMI_DELIMITER_FRAME_START:
      devmode_assert_lower_or_eq(unmask, DCMI_ESUR_FSU_MASK);
      shift = DCMI_ESUR_FSU_SHIFT;
      mask = DCMI_ESUR_FSU_MASK << shift;
      syn_set_register_bits(reg, mask, unmask << shift);
      break;

    case DCMI_DELIMITER_LINE_START:
      devmode_assert_lower_or_eq(unmask, DCMI_ESUR_LSU_MASK);
      shift = DCMI_ESUR_LSU_SHIFT;
      mask = DCMI_ESUR_LSU_MASK << shift;
      syn_set_register_bits(reg, mask, unmask << shift);
      break;

    case DCMI_DELIMITER_LINE_END:
      devmode_assert_lower_or_eq(unmask, DCMI_ESUR_LEU_MASK);
      shift = DCMI_ESUR_LEU_SHIFT;
      mask = DCMI_ESUR_LEU_MASK << shift;
      syn_set_register_bits(reg, mask, unmask << shift);
      break;

    case DCMI_DELIMITER_FRAME_END:
      devmode_assert_lower_or_eq(unmask, DCMI_ESUR_FEU_MASK);
      shift = DCMI_ESUR_FEU_SHIFT;
      mask = DCMI_ESUR_FEU_MASK << shift;
      syn_set_register_bits(reg, mask, unmask << shift);
      break;

    default:
      devmode_error_invalid_enum(enum dcmi_delimiter, delimiter);
      break;
  }
}

void
dcmi_set_horizontal_offset(
  u32 offset
)
{
  devmode_assert_lower_or_eq(offset, DCMI_CWSTRT_HOFFCNT_MASK);
  constexpr u32 shift = DCMI_CWSTRT_HOFFCNT_SHIFT;
  constexpr u32 mask = DCMI_CWSTRT_HOFFCNT_MASK << shift;
  volatile u32* reg = &DCMI->CWSTRT;
  syn_set_register_bits(reg, mask, offset << shift);
}

void
dcmi_set_vertical_start_line(
  u32 line_start
)
{
  devmode_assert_lower_or_eq(line_start, DCMI_CWSTRT_VST_MASK);
  constexpr u32 shift = DCMI_CWSTRT_VST_SHIFT;
  constexpr u32 mask = DCMI_CWSTRT_VST_MASK << shift;
  volatile u32* reg = &DCMI->CWSTRT;
  syn_set_register_bits(reg, mask, line_start << shift);
}

void
dcmi_set_capture_count(
  u32 count
)
{
  devmode_assert_lower_or_eq(count, DCMI_CWSIZE_CAPCNT_MASK);
  constexpr u32 shift = DCMI_CWSIZE_CAPCNT_SHIFT;
  constexpr u32 mask = DCMI_CWSIZE_CAPCNT_MASK << shift;
  volatile u32* reg = &DCMI->CWSIZE;
  syn_set_register_bits(reg, mask, count << shift);
}

void
dcmi_set_vertical_line_count(
  u32 count
)
{
  devmode_assert_lower_or_eq(count, DCMI_CWSIZE_VLINE_MASK);
  constexpr u32 shift = DCMI_CWSIZE_VLINE_SHIFT;
  constexpr u32 mask = DCMI_CWSIZE_VLINE_MASK << shift;
  volatile u32* reg = &DCMI->CWSIZE;
  syn_set_register_bits(reg, mask, count << shift);
}

u32
dcmi_data_read(void)
{
  return DCMI->DR;
}

