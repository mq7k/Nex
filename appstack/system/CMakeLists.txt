add_library(nex_system)

list(APPEND CMAKE_MODULE_PATH ${NEX_SYSTEM_BASE_DIR})
include(${CMAKE_CURRENT_SOURCE_DIR}/sysdefs.cmake)

target_sources(nex_system PUBLIC
  src/profiler/profiler.c

  src/scheduler/backend/arch/arm.c
  src/scheduler/backend/ts/stm32_tim.c
  src/scheduler/scheduler.c
  src/scheduler/task_history.c

  src/time/backend/stm32_tim.c
  src/time/time.c
)

target_sources(nex_system PUBLIC
  FILE_SET HEADERS
  BASE_DIRS ${NEX_SYSTEM_INCLUDE_DIR}
  FILES
    include/system/backends/crc/becrc.h

    include/system/profiler/profiler.h

    include/system/scheduler/backend/ts/stm32_tim.h
    include/system/scheduler/backend/sif.h
    include/system/scheduler/scheduler.h
    include/system/scheduler/task_history.h

    include/system/time/backend/stm32_tim.h
    include/system/time/backend/timeif.h
    include/system/time/time.h
)

target_link_libraries(nex_system PUBLIC nex_libcom)
target_link_libraries(nex_system PUBLIC nex_synapse)
target_include_directories(nex_system PUBLIC ${NEX_SYSTEM_INCLUDE_DIR})

if (NEX_BUILD_TESTS)
  enable_testing()
  sys_register_tests(foo/bar.c)
endif()
