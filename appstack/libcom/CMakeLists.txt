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
  PATH ${NEX_LIBCOM_INC_DIR}/libcom
  HEADERS
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

target_link_libraries(nex_libcom PUBLIC nex_buildcfg)
target_include_directories(nex_libcom PUBLIC ${NEX_LIBCOM_INC_DIR})

if (NEX_BUILD_TESTS)
  enable_testing()
  libcom_register_tests(
    unit_test.c
    format_test.c
  )
endif()

