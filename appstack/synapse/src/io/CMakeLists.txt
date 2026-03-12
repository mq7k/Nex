nex_add_sources(
  TARGET nex_synapse_util
  PATH ${NEX_SYN_SRC_DIR}/io
  SOURCES
    io_spi.c
    ioif.c
  MSG "Adding util file: "
)
