syn_cpu_group(
  ID cm4f 
  MODEL cortex-m4
  FPU fpv4-sp-d16
  DRIVERS
    drivers/systick/systick_v1.c
    drivers/nvic/nvic_v1.c
    drivers/scb/scb_v1.c

    common/fpu.S
    drivers/fpu/fpu_v1.c
    drivers/vtable/vtable_v1.c

  COMPILE_OPTIONS
    -mthumb
    -mcpu=cortex-m4

  LINK_OPTIONS
    -mthumb
    -mcpu=cortex-m4
)

if (NEX_PLATFORM_ARM)
  syn_cpu_group_append(
    ID cm4f 
    DRIVERS
      common/memcpy.S
      common/memset.S
      common/string.S
  )
endif()

