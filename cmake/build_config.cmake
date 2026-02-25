add_library(eco_buildtype INTERFACE)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  eco_log(STATUS "Build type configuration: Debug")
  set(NEX_DEBUG_BUILD ON)
  include(cmake/build_type/debug)
elseif (CMAKE_BUILD_TYPE STREQUAL "Dev")
  eco_log(STATUS "Build type configuration: Dev")
  set(NEX_DEV_BUILD ON)
  include(cmake/build_type/dev)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
  eco_log(STATUS "Build type configuration: Release")
  set(NEX_REL_BUILD ON)
  include(cmake/build_type/release)
else()
  eco_log(FATAL_ERROR "Invalid build type configuration: ${CMAKE_BUILD_TYPE}")
endif()

if (NEX_PLATFORM STREQUAL "arm")
  set(NEX_PLATFORM_ARM TRUE)

  target_compile_definitions(eco_buildtype INTERFACE
    NEX_PLATFORM_ARM
  )
elseif (NEX_PLATFORM STREQUAL "desktop")
  set(NEX_PLATFORM_DESKTOP TRUE)

  target_compile_definitions(eco_buildtype INTERFACE
    NEX_PLATFORM_DESKTOP
  )
endif()

if (NEX_BUILD_EXAMPLES)
  # Defines `NEX_BUILD_EXAMPLES` macro accessible from C code.
  target_compile_definitions(eco_buildtype INTERFACE
    NEX_BUILD_EXAMPLES
  )
endif()

if (NEX_BUILD_TESTS)
  # Defines `NEX_BUILD_TESTS` macro accessible from C code.
  target_compile_definitions(eco_buildtype INTERFACE
    NEX_BUILD_TESTS
  )
endif()

target_compile_options(eco_buildtype INTERFACE
  -fmessage-length=0
  -Wall
  -Wextra
  -Wpedantic
  -Werror
  -Wunused
  -Wconversion
  -Wshadow
  -Wundef
  -Wformat=2
  -lc
)

target_compile_definitions(eco_buildtype INTERFACE
  ${NEX_CPU_MODEL}
  ${NEX_CPU_BRAND}
  ${NEX_MCU_FAMILY}
  ${NEX_MCU_FAMILY_LINE}
  ${NEX_MCU_GROUPS}
  ${NEX_MCU_FULLNAME}
)

target_compile_features(eco_buildtype INTERFACE c_std_23)
target_include_directories(eco_buildtype INTERFACE ${NEX_INCLUDE_DIR})

if (NEX_PLATFORM_ARM)
  target_link_options(eco_buildtype INTERFACE
    -nostartfiles
    -nostdlib
    -specs=nosys.specs
    -ffreestanding
  )

  target_compile_options(eco_buildtype INTERFACE
    # ARM CPU uses Thumb, but (for examples) RISC-V does not.
    # Might be necessary to move this into `cortex.cmake` or
    # similar in the future.
    -mthumb
  )

  if (NEX_NOCSTD)
    target_compile_options(eco_buildtype INTERFACE -ffreestanding)
  endif()
endif()

target_link_options(eco_buildtype INTERFACE
  ${NEX_COMPILER_FLAGS}
)

target_compile_options(eco_buildtype INTERFACE
  ${NEX_LINKER_FLAGS}
)
