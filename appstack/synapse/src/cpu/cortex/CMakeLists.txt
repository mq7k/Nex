nex_add_sources(
  TARGET nex_synapse_util
  PATH ${NEX_SYN_SRC_DIR}/cpu/cortex
  SOURCES 
    common/cm.S
  MSG "Adding CPU-intrinsic instructions file: "
)

