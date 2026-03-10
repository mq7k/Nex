target_sources(nex_libcom PUBLIC
  data/queue.c
  data/ring_buffer.c

  sys/devmode.c
  sys/runtime.c

  bytebuf.c
  format.c
  semver.c
  unit.c
  util.c
)

# target_sources(systeml PUBLIC 
#   FILE_SET HEADERS
#   BASE_DIRS ${NEX_SYSTEM_BASE_DIR}
#   FILES ${LIST_HEADERS}
# )

target_sources(nex_libcom PUBLIC
  FILE_SET HEADERS
  # BASE_DIRS ${NEX_SYNAPSE_BASE_DIR}
  BASE_DIRS ${PROJECT_SOURCE_DIR}/appstack/libcom/include
  FILES
    data/queue.h
    data/ring_buffer.h

    sys/devmode.h
    sys/runtime.h

    bytebuf.h
    format.h
    semver.h
    types.h
    unit.h
    util.h
)
