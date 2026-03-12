nex_add_sources(
  TARGET nex_synapse_util
  PATH ${NEX_SYN_SRC_DIR}/drivers
  SOURCES
    mpu9250.c
  MSG "Adding device driver: "
)
