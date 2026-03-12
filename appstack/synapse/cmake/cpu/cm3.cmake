target_compile_options(nex_hw_flags INTERFACE
  -mcpu=cortex-m3
  -mthumb
)

target_link_options(nex_hw_flags INTERFACE
  -mcpu=cortex-m3
  -mthumb
)

nex_add_sources_property(
  TARGET nex_synapse_cpu
  SOURCES
    systick/systick_v1.c
    nvic/nvic_v2.c
    scb/scb_v1.c
)

# No need for a test for the vtable.
nex_add_sources(
  TARGET nex_synapse_cpu
  PATH ${NEX_SYN_SRC_DIR}/cpu/cortex/drivers
  SOURCES
    vtable/vtable_v2.c
)

set_target_properties(nex_buildcfg PROPERTIES
  NEX_HAS_FPU "OFF"
)
