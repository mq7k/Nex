# add_library(eco_libcom)
#
# target_link_libraries(eco_libcom INTERFACE eco_buildtype)
#
# set(LIBCOM_SOURCES
#   data/queue
#   data/ring_buffer
#
#   sys/devmode
#
#   bytebuf
#   format
#   semver
#   util
#   unit
# )
#
# if (NEX_PLATFORM_ARM)
#   list(APPEND LIBCOM_SOURCES
#     sys/runtime
#   )
# endif()
#
# if (NEX_INCLUDE_DEVMODE)
#   eco_log(STATUS "Included: devmode")
#   target_compile_definitions(eco_buildtype INTERFACE
#     NEX_INCLUDE_DEVMODE
#   )
# endif()
#
# set(LIST_HEADERS "${LIBCOM_SOURCES}") 
# set(LIST_SOURCES "${LIBCOM_SOURCES}")
#
# list(TRANSFORM LIST_HEADERS PREPEND "${NEX_LIBCOM_BASE_DIR}/include/libcom/")
# list(TRANSFORM LIST_HEADERS APPEND ".h")
#
# list(TRANSFORM LIST_SOURCES PREPEND "${NEX_LIBCOM_BASE_DIR}/src/")
# list(TRANSFORM LIST_SOURCES APPEND ".c")
#
# target_sources(eco_libcom PUBLIC
#   ${LIST_SOURCES}
# )
#
# target_sources(eco_libcom PUBLIC 
#   FILE_SET HEADERS
#   BASE_DIRS ${NEX_LIBCOM_BASE_DIR}
#   FILES ${LIST_HEADERS}
# )
#
# set(
#   NEX_LIBCOM_TESTS_DIR
#   ${NEX_LIBCOM_BASE_DIR}/tests
# )
#
# if (NEX_BUILD_TESTS)
#   eco_log(STATUS "Libcom tests: ${LIBCOM_TESTS}")
# endif()
#
# target_include_directories(eco_libcom PUBLIC ${NEX_LIBCOM_BASE_DIR}/include)

# New
add_library(nex_libcom)

target_sources(nex_libcom PUBLIC
  src/data/queue.c
  src/data/ring_buffer.c

  src/sys/devmode.c
  src/sys/runtime.c

  src/bytebuf.c
  src/format.c
  src/semver.c
  src/unit.c
  src/util.c
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
    include/libcom/data/queue.h
    include/libcom/data/ring_buffer.h

    include/libcom/sys/devmode.h
    include/libcom/sys/runtime.h

    include/libcom/bytebuf.h
    include/libcom/format.h
    include/libcom/semver.h
    include/libcom/types.h
    include/libcom/unit.h
    include/libcom/util.h
)

target_link_libraries(nex_libcom PUBLIC nex_buildcfg)

