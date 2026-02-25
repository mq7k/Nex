add_library(eco_libcom)

target_link_libraries(eco_libcom INTERFACE eco_buildtype)

set(LIBCOM_SOURCES
  data/queue
  data/ring_buffer

  sys/devmode

  bytebuf
  format
  semver
  util
  unit
)

if (NEX_PLATFORM_ARM)
  list(APPEND LIBCOM_SOURCES
    sys/runtime
  )
endif()

if (NEX_INCLUDE_DEVMODE)
  eco_log(STATUS "Included: devmode")
  target_compile_definitions(eco_buildtype INTERFACE
    NEX_INCLUDE_DEVMODE
  )
endif()

set(LIST_HEADERS "${LIBCOM_SOURCES}") 
set(LIST_SOURCES "${LIBCOM_SOURCES}")

list(TRANSFORM LIST_HEADERS PREPEND "${NEX_LIBCOM_BASE_DIR}/include/libcom/")
list(TRANSFORM LIST_HEADERS APPEND ".h")

list(TRANSFORM LIST_SOURCES PREPEND "${NEX_LIBCOM_BASE_DIR}/src/")
list(TRANSFORM LIST_SOURCES APPEND ".c")

target_sources(eco_libcom PUBLIC
  ${LIST_SOURCES}
)

target_sources(eco_libcom PUBLIC 
  FILE_SET HEADERS
  BASE_DIRS ${NEX_LIBCOM_BASE_DIR}
  FILES ${LIST_HEADERS}
)

set(
  NEX_LIBCOM_TESTS_DIR
  ${NEX_LIBCOM_BASE_DIR}/tests
)

if (NEX_BUILD_TESTS)
  eco_log(STATUS "Libcom tests: ${LIBCOM_TESTS}")
  # syn_add_tests(${SYN_MCU_DRIVER_TESTS_DIR} ${NEX_MCU_TESTS})
  # syn_add_tests(${NEX_LIBCOM_TESTS_DIR} unit)
endif()

target_include_directories(eco_libcom PUBLIC ${NEX_LIBCOM_BASE_DIR}/include)

