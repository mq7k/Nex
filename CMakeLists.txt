cmake_minimum_required(VERSION 3.28)
project(nex VERSION 1.0.0 LANGUAGES C ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(NEX_BUILD_TESTS "Toggles tests build. (Def=ON)" ON)
option(NEX_BUILD_EXAMPLES "Toggles examples build. (Def=OFF)" OFF)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# include(cmake/ecofn)
# include(cmake/ecodefs)
# include(cmake/build_config)

include(cmake/nexfn)
include(cmake/nexdefs)
include(cmake/build_config)

nex_log(STATUS "Target: ${MCU_FULLNAME}")
nex_log(STATUS "Root directory: ${PROJECT_SOURCE_DIR}")
nex_log(STATUS "LD script: ${NEX_MCU_LD_SCRIPT}")
nex_log(STATUS "LD path: ${SYN_LD_SCRIPT_PATH}")
nex_log(STATUS "LD family dir: ${SYN_LD_SCRIPTS_MCU_DIR}")

nex_log(STATUS "Using compiler: ${CMAKE_C_COMPILER}")
nex_log(STATUS "Using objcopy: ${CMAKE_OBJCOPY}")
nex_log(STATUS "Using C standard: ${CMAKE_C_STANDARD}")

if (NEX_PLATFORM_ARM)
  nex_log(STATUS "ARM build")
elseif (NEX_PLATFORM_DESKTOP)
  nex_log(STATUS "Desktop build")
endif()

nex_log(STATUS "Tests: ${NEX_BUILD_TESTS}")
nex_log(STATUS "Examples: ${NEX_BUILD_EXAMPLES}")

add_subdirectory(appstack/libcom)
add_subdirectory(appstack/synapse)
add_subdirectory(appstack/system)

if (NEX_BUILD_TESTS)
  add_subdirectory(appstack/libtest)
endif()

