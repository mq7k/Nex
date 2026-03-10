set(ARCH_COMPILER_FLAGS_ARM
  -mcpu=cortex-m4
)

set(ARCH_LINKER_FLAGS_ARM
  -mcpu=cortex-m4
)

set(ARCH_PERIPH_DRIVERS
  systick/systick_v1
  nvic/nvic_v1
  vtable/vtable_v1
  scb/scb_v1
)
