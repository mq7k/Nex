add_library(drivers)

target_link_libraries(drivers PUBLIC eco_libcom)
target_link_libraries(drivers INTERFACE eco_buildtype)
target_link_libraries(drivers INTERFACE syn_chip)
target_link_libraries(drivers INTERFACE syn_arch)

set(DRIVERSL_SOURCES
  mpu9250
)

set(DRIVERSL_LIST_HEADERS "${DRIVERSL_SOURCES}") 
set(LIST_SOURCES "${DRIVERSL_SOURCES}")

list(TRANSFORM DRIVERSL_LIST_HEADERS PREPEND "${NEX_DRIVERS_BASE_DIR}/include/drivers/")
list(TRANSFORM DRIVERSL_LIST_HEADERS APPEND ".h")

list(TRANSFORM LIST_SOURCES PREPEND "${NEX_DRIVERS_BASE_DIR}/src/")
list(TRANSFORM LIST_SOURCES APPEND ".c")

target_sources(drivers PUBLIC
  ${LIST_SOURCES}
)

target_sources(drivers PUBLIC 
  FILE_SET HEADERS
  BASE_DIRS ${NEX_DRIVERS_BASE_DIR}
  FILES ${DRIVERSL_LIST_HEADERS}
)

set(
  NEX_DRIVERS_TESTS_DIR
  ${NEX_DRIVERS_BASE_DIR}/tests
)

# if (NEX_BUILD_TESTS)
#   enable_testing()
#   eco_log(STATUS "Drivers tests in: ${NEX_DRIVERS_TESTS_DIR}")
#   eco_log(STATUS "Drivers tests: ${NEX_DRIVERS_TESTS}")
#   drivers_add_tests(${NEX_DRIVERS_TESTS_DIR} ${NEX_DRIVERS_TESTS})
# endif()

target_include_directories(drivers PUBLIC ${NEX_DRIVERS_BASE_DIR}/include)
