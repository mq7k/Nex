target_compile_options(nex_hw_flags INTERFACE
  -mcpu=cortex-m4
  -mthumb
)

target_link_options(nex_hw_flags INTERFACE
  -mcpu=cortex-m4
  -mthumb
)

nex_add_sources_property(
  TARGET nex_synapse_cpu
  SOURCES
    systick/systick_v1.c
    nvic/nvic_v1.c
    scb/scb_v1.c
)

# No need for a test for these.
nex_add_sources(
  TARGET nex_synapse_cpu
  PATH ${NEX_SYN_SRC_DIR}/cpu/cortex
  SOURCES 
    common/fpu.S
    drivers/vtable/vtable_v1.c
)

set_target_properties(nex_buildcfg PROPERTIES
  NEX_HAS_FPU "ON"

  # VFPv4, single-precision only, 16 double-precision registers.
  NEX_FPU_TYPE fpv4-sp-d16
)

