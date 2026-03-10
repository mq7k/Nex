# We have all requested drivers in ARCH_PERIPH_DRIVERS.
# They are formatted as follow:
# {periph}/{periph_version}.c
# For example: `systick/systick_v1.c`, `nvic/nvic_v2.c`
set(ABS_PATH_DRIVERS ${MCU_PERIPH_DRIVERS})

# add_source_files(syn_arch ${ABS_PATH_DRIVERS})

