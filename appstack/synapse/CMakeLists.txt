# cmake_minimum_required(VERSION 3.28)
# project(drone VERSION 1.0.0 LANGUAGES C ASM)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)
#
# set(CMAKE_C_STANDARD 23)
# set(CMAKE_C_STANDARD_REQUIRED ON)

# set(SYN_INCLUDE_DIR ${SYN_BASE_PATH}/include)
# set(NEX_CMAKE_FILES ${PROJECT_SOURCE_DIR}/cmake)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

option(BUILD_TESTS "Toggles tests build. (Def=ON)" ON)
option(BUILD_EXAMPLES "Toggles examples build. (Def=OFF)" OFF)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Dev" "Release")
endif()

# Tests can only be built when compiling for a desktop computer.
# If so, examples cannot be built because they require
# a bare metal compiler, such as `arm-none-eabi-gcc`.
set(SYN_LD_SCRIPT CACHE STRING "Selects the linker script.")

include(cmake/defines/functions)
include(cmake/defines/util)
include(cmake/syndefs)
# include(synapse/defines/chip_config)
# include(synapse/build_config)

include(cmake/syn)

if (BUILD_TESTS)
  # target_link_libraries(synapse PUBLIC eco_libtest)
endif()

# TODO: Make sure this is correct.
if (BUILD_EXAMPLES AND SYN_PLATFORM_ARM)
  include(cmake/post/examples)
endif()
