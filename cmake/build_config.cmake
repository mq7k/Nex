add_library(nex_buildcfg INTERFACE)

if (NEX_INCLUDE_DEVMODE)
  nex_define_macros_i(nex_buildcfg NEX_INCLUDE_DEVMODE)
endif()

# Equals ignore case.
string(TOLOWER ${CMAKE_BUILD_TYPE} _BUILDTYPE)

if (_BUILDTYPE STREQUAL "debug")
  nex_log(STATUS "Build type configuration: Debug")
  set(NEX_DEBUG_BUILD ON)
  include(cmake/build_type/debug)
elseif (_BUILDTYPE STREQUAL "release")
  nex_log(STATUS "Build type configuration: Release")
  set(NEX_REL_BUILD ON)
  include(cmake/build_type/release)
else()
  nex_log(FATAL_ERROR "Invalid build type configuration: ${_BUILDTYPE}")
endif()

if (NEX_PLATFORM STREQUAL "arm")
  set(NEX_PLATFORM_ARM TRUE)
  nex_define_macros_i(nex_buildcfg NEX_PLATFORM_ARM)

elseif (NEX_PLATFORM STREQUAL "desktop")
  set(NEX_PLATFORM_DESKTOP TRUE)
  nex_define_macros_i(nex_buildcfg NEX_PLATFORM_DESKTOP)

else()
  nex_log(FATAL_ERROR "Invalid platform: ${NEX_PLATFORM}")
endif()

if (NEX_BUILD_EXAMPLES)
  nex_define_macros_i(nex_buildcfg NEX_BUILD_EXAMPLES)
endif()

if (NEX_BUILD_TESTS)
  nex_define_macros_i(nex_buildcfg NEX_BUILD_TESTS)
endif()

target_compile_options(nex_buildcfg INTERFACE
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

target_compile_features(nex_buildcfg INTERFACE c_std_23)

if (NEX_PLATFORM_ARM)
  target_link_options(nex_buildcfg INTERFACE
    -nostartfiles
    -nostdlib
    -specs=nosys.specs
  )

  target_compile_options(nex_buildcfg INTERFACE
    # ARM CPU uses Thumb, but (for examples) RISC-V does not.
    # Might be necessary to move this into `cortex.cmake` or
    # similar in the future.
    -mthumb
    -ffreestanding
  )
endif()

# if (NEX_NOCSTD)
#   target_compile_options(nex_buildcfg INTERFACE -ffreestanding)
# endif()

target_link_options(nex_buildcfg INTERFACE
  ${NEX_COMPILER_FLAGS}
)

target_compile_options(nex_buildcfg INTERFACE
  ${NEX_LINKER_FLAGS}
)
