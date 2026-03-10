set(ARCH_COMPILER_FLAGS_ARM
  -mcpu=cortex-m3
)

set(ARCH_LINKER_FLAGS_ARM
  -mcpu=cortex-m3
)

set(ARCH_PERIPH_DRIVERS
  systick/systick_v1
  nvic/nvic_v2
  vtable/vtable_v2
  scb/scb_v1
)
