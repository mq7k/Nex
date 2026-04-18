add_library(nex_system)

list(APPEND CMAKE_MODULE_PATH ${NEX_SYSTEM_BASE_DIR})
include(${CMAKE_CURRENT_SOURCE_DIR}/sysdefs.cmake)

nex_add_sources(
  TARGET nex_system
  PATH ${NEX_SYSTEM_SRC_DIR}
  SOURCES
    profiler/profiler.c

    scheduler/scheduler.c
    # scheduler/task_history.c

    time/backend/stm32_coarse_time.c
    time/backend/stm32_monotonic_time.c
    time/dispatcher.c
    time/time.c

  MSG "Adding system file: "
)

nex_add_headers(
  TARGET nex_system
  PATH ${NEX_SYSTEM_INCLUDE_DIR}
  HEADERS
    system/backends/crc/becrc.h

    system/profiler/profiler.h

    system/scheduler/scheduler.h
    system/scheduler/task_history.h

    system/time/backend/stm32_tim.h
    system/time/backend/timeif.h
    system/time/time.h
)

target_link_libraries(nex_system PUBLIC nex_libcom)
target_link_libraries(nex_system PUBLIC nex_synapse)
target_include_directories(nex_system PUBLIC ${NEX_SYSTEM_INCLUDE_DIR})

if (NEX_BUILD_TESTS)
  enable_testing()
endif()
