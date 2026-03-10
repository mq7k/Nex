# Now we have all requested drivers in MCU_PERIPH_DRIVERS.
# They are formatted as follow:
# {periph}/{periph_version}.c
# For example: `dma/dma_v2.c`, `spi/spi_v1.c`
# We need to translate it first to an
# absolute path.
set(ABS_PATH_DRIVERS ${MCU_PERIPH_DRIVERS})

# list(APPEND ABS_PATH_DRIVERS ${})
syn_add_sources(nex_synapse ${ABS_PATH_DRIVERS})

