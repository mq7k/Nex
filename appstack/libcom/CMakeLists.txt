include(${CMAKE_CURRENT_SOURCE_DIR}/libcomdefs.cmake)
add_library(nex_libcom)

nex_add_sources(
  TARGET nex_libcom
  PATH ${NEX_LIBCOM_SRC_DIR}
  SOURCES
    data/queue.c
    data/ring_buffer.c

    sys/devmode.c

    bytebuf.c
    format.c
    semver.c
    unit.c
    util.c
  MSG "Adding common file: "
)

if (NEX_PLATFORM_ARM)
  nex_add_sources(
    TARGET nex_libcom
    PATH ${NEX_LIBCOM_SRC_DIR}
    SOURCES sys/runtime.c
    MSG "Adding common file: "
  )
endif()

nex_add_headers(
  TARGET nex_libcom
  PATH ${NEX_LIBCOM_INC_DIR}
  SOURCES
    libcom/data/queue.h
    libcom/data/ring_buffer.h

    libcom/sys/devmode.h
    libcom/sys/runtime.h

    libcom/bytebuf.h
    libcom/format.h
    libcom/semver.h
    libcom/types.h
    libcom/unit.h
    libcom/util.h
)

target_link_libraries(nex_libcom PUBLIC nex_buildcfg)

