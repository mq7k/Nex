nex_add_sources(
  TARGET nex_synapse_util
  PATH ${NEX_SYN_SRC_DIR}/common
  SOURCES syscall.c
  MSG "Adding common file: "
)

nex_add_headers(
  TARGET nex_synapse_util
  PATH ${NEX_SYN_INCLUDE_DIR}/synapse
  HEADERS
    common/common.h
  MSG "Adding common: "
)

