if (NOT NEX_CUSTOM_CANARY_INIT)
  nex_add_sources(
    TARGET nex_synapse_util
    PATH ${NEX_SYN_SRC_DIR}/soc/stm32/port
    SOURCES
      stkchk.c
    MSG "Adding stm32 common file: "
  )
endif()
