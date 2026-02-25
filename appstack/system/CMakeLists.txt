include(appstack/system/sysdefs)
add_library(systeml)

target_link_libraries(systeml INTERFACE eco_buildtype)
target_link_libraries(systeml PUBLIC eco_libcom)
target_link_libraries(systeml PUBLIC syn_chip)
target_link_libraries(systeml PUBLIC syn_arch)
# target_link_libraries(systeml PUBLIC eco_contracts)

set(SYSL_SOURCES
  profiler/profiler

  scheduler/backend/ts/stm32_tim
  scheduler/wiring/dispatcher
  scheduler/task_history
  scheduler/scheduler

  time/backend/stm32_tim
  time/wiring/dispatcher
  time/time
)

set(LIST_HEADERS "${SYSL_SOURCES}") 
set(LIST_SOURCES "${SYSL_SOURCES}")

list(APPEND LIST_SOURCES
  scheduler/backend/arch/arm
)

list(APPEND LIST_HEADERS
  time/backend/timeif
)

list(TRANSFORM LIST_HEADERS PREPEND "${NEX_SYSTEM_BASE_DIR}/include/system/")
list(TRANSFORM LIST_HEADERS APPEND ".h")

list(TRANSFORM LIST_SOURCES PREPEND "${NEX_SYSTEM_BASE_DIR}/src/")
list(TRANSFORM LIST_SOURCES APPEND ".c")

target_sources(systeml PUBLIC
  ${LIST_SOURCES}
)

target_sources(systeml PUBLIC 
  FILE_SET HEADERS
  BASE_DIRS ${NEX_SYSTEM_BASE_DIR}
  FILES ${LIST_HEADERS}
)

set(
  NEX_SYSTEM_TESTS_DIR
  ${NEX_SYSTEM_BASE_DIR}/tests
)

if (NEX_BUILD_TESTS)
  enable_testing()
  eco_log(STATUS "System tests in: ${NEX_SYSTEM_TESTS_DIR}")
  eco_log(STATUS "System tests: ${NEX_SYSTEM_TESTS}")
  sys_add_tests(${NEX_SYSTEM_TESTS_DIR} ${NEX_SYSTEM_TESTS})
endif()

target_include_directories(systeml PUBLIC ${NEX_SYSTEM_BASE_DIR}/include)

# TODO: Fix this.
target_include_directories(systeml PUBLIC ${PROJECT_SOURCE_DIR}/appstack/contracts/include)
