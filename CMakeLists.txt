cmake_minimum_required(VERSION 3.28)
project(synapse VERSION 1.0.0 LANGUAGES C ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# set(NEX_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
# set(SYN_CMAKE_FILES ${PROJECT_SOURCE_DIR}/cmake)

option(NEX_BUILD_TESTS "Toggles tests build. (Def=ON)" ON)
option(NEX_BUILD_EXAMPLES "Toggles examples build. (Def=OFF)" OFF)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Dev" "Release")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

include(cmake/ecofn)
include(cmake/ecodefs)
include(cmake/build_config)

eco_log(STATUS "Target: ${MCU_FULLNAME}")
eco_log(STATUS "Root directory: ${PROJECT_SOURCE_DIR}")
eco_log(STATUS "LD script: ${SYN_LD_SCRIPT}")
eco_log(STATUS "LD path: ${SYN_LD_SCRIPT_PATH}")
eco_log(STATUS "LD family dir: ${SYN_LD_SCRIPTS_MCU_DIR}")

eco_log(STATUS "Using compiler: ${CMAKE_C_COMPILER}")
eco_log(STATUS "Using objcopy: ${CMAKE_OBJCOPY}")
eco_log(STATUS "Using C standard: ${CMAKE_C_STANDARD}")

if (NEX_PLATFORM_ARM)
  eco_log(STATUS "ARM build")
elseif (NEX_PLATFORM_DESKTOP)
  eco_log(STATUS "Desktop build")
endif()

eco_log(STATUS "Tests: ${NEX_BUILD_TESTS}")
eco_log(STATUS "Examples: ${NEX_BUILD_EXAMPLES}")

add_subdirectory(appstack/libcom)
add_subdirectory(appstack/synapse)
add_subdirectory(appstack/system)
add_subdirectory(appstack/drivers)
# add_subdirectory(autonomy)

if (NEX_BUILD_TESTS)
  add_subdirectory(appstack/libtest)
endif()

