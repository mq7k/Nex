nex_add_sources(
  TARGET nex_synapse_util
  PATH ${NEX_SYN_SRC_DIR}/cpu/cortex
  SOURCES 
    instrinsic.c
  MSG "Adding CPU-intrinsic instructions file: "
)

if (NEX_PLATFORM_ARM)
  nex_add_sources(
    TARGET nex_synapse_util
    PATH ${NEX_SYN_SRC_DIR}/cpu/cortex
    SOURCES common/cm.S
    MSG "Adding CPU-intrinsic instructions file: "
  )
else()
  nex_add_sources(
    TARGET nex_synapse_util
    PATH ${NEX_SYN_SRC_DIR}/cpu/cortex
    SOURCES common/cmd.S
    MSG "Adding CPU-intrinsic instructions file (adapter): "
  )
endif()

