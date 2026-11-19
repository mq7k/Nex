syn_cpu_group(
  ID cm3
  MODEL cortex-m3
  DRIVERS
    drivers/systick/systick_v1.c
    drivers/nvic/nvic_v2.c
    drivers/scb/scb_v1.c
    drivers/vtable/vtable_v2.c

  COMPILE_OPTIONS
    -mthumb
    -mcpu=cortex-m3

  LINK_OPTIONS
    -mthumb
    -mcpu=cortex-m3
)

if (NEX_PLATFORM_ARM)
  syn_cpu_group_append(
    ID cm3 
    DRIVERS
      common/memcpy.S
      common/memset.S
      common/string.S
  )
endif()
