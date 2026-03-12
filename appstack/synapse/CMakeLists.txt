# Includes nex_synapse's variables definition.
include(${CMAKE_CURRENT_SOURCE_DIR}/syndefs.cmake)

list(APPEND CMAKE_MODULE_PATH ${NEX_SYN_CMAKE_DIR})

# Includes nex_synapse's functions definition.
include(synfn)

# The main project library.
add_library(nex_synapse)

# Contains the source files for the SoC drivers.
add_library(nex_synapse_soc INTERFACE)

# Contains the source files for the CPU drivers.
add_library(nex_synapse_cpu INTERFACE)

# Contains other synapse source files (Interfaces, backends, ...).
add_library(nex_synapse_util INTERFACE)

# Contains only compiler/linker flags of the current CPU architecture.
# Examples: `-mcpu=cortex-m3`.
add_library(nex_hw_flags INTERFACE)

target_include_directories(nex_synapse PUBLIC ${NEX_SYN_INCLUDE_DIR})
string(REPLACE ".cmake" "" NEX_TARGET_PATH ${NEX_TARGET_PATH})

nex_log(CHECK_START "Looking for MCU target specs file...")
set(FULLPATH ${NEX_SYN_CMAKE_DIR}/targets/${NEX_TARGET_PATH}.cmake)
if (EXISTS ${FULLPATH})
  message(CHECK_PASS "found it.")
else()
  message(CHECK_FAIL "not found.")
  nex_log(FATAL_ERROR "Error: file '${FULLPATH}' not found.")
endif()

# Includes the cmake file of the current target.
# This defines some variables we are going to use here,
# such as NEX_MCU_DRIVERS_GROUP and NEX_ARCH_DRIVERS_GROUP.
include(targets/${NEX_TARGET_PATH})

nex_log(CHECK_START "Looking for MCU driver group file...")
set(FULLPATH ${NEX_SYN_CMAKE_DIR}/mcu/${NEX_MCU_DRIVERS_GROUP}.cmake)
if (EXISTS ${FULLPATH})
  message(CHECK_PASS "found it.")
else()
  message(CHECK_FAIL "not found.")
  nex_log(FATAL_ERROR "Error: file '${FULLPATH}' not found.")
endif()

# Includes the SoC peripheral drivers of the current target.
# The full list is set as `NEX_SRC_FILES` property to `nex_synapse_soc`.
# Example: synapse/cmake/mcu/stm32f103.cmake
include(mcu/${NEX_MCU_DRIVERS_GROUP})

# Includes the CPU peripheral group of the current target.
# This selects what peripheral to build.
# Example: synapse/cmake/cpu/cm3.cmake
include(cpu/${NEX_ARCH_DRIVERS_GROUP})

# Adds common CPU files.
# Examples: `cm.S` is shared across the entire Cortex lineup.
add_subdirectory(src/cpu/${NEX_CPU_FAMILY})

add_subdirectory(src/common)
add_subdirectory(src/drivers)
add_subdirectory(src/io)

# Sets up the cmake (nex_synapse) target.
# Defines macros, links against other layers,
# adds compiler/linker flags...
include(syn)

# TODO: Make sure this is correct.
# if (BUILD_EXAMPLES AND SYN_PLATFORM_ARM)
#   include(cmake/post/examples)
# endif()

nex_add_sources_from_property(
  TARGET nex_synapse_soc
  PATH ${NEX_SYN_SRC_DIR}/soc/${NEX_MCU_FAMILY}/drivers
  MSG "Adding SoC driver: "
)

nex_add_sources_from_property(
  TARGET nex_synapse_cpu
  PATH ${NEX_SYN_SRC_DIR}/cpu/${NEX_CPU_FAMILY}/drivers
  MSG "Adding CPU driver: "
)

syn_add_interfaces_from_property(
  TARGET nex_synapse_soc
  PATH ${NEX_SYN_SRC_DIR}/soc/${NEX_MCU_FAMILY}/drivers
  MSG "Adding periph interface: "
)

target_link_libraries(nex_synapse PUBLIC nex_synapse_soc)
target_link_libraries(nex_synapse PUBLIC nex_synapse_cpu)
target_link_libraries(nex_synapse PUBLIC nex_synapse_util)

get_target_property(NEX_COMPILER_FLAGS nex_buildcfg INTERFACE_COMPILE_OPTIONS)
get_target_property(NEX_LINKER_FLAGS nex_buildcfg INTERFACE_LINK_OPTIONS)

nex_log(STATUS "MCU fullname: ${NEX_MCU_FULLNAME}")
nex_log(STATUS "Family: ${NEX_MCU_FAMILY}")
nex_log(STATUS "CPU: ${NEX_CPU_FAMILY} ${NEX_ARCH_DRIVERS_GROUP}")
nex_log(STATUS "Platform: ${NEX_PLATFORM}")

if (NEX_VERBOSE)
  nex_log(STATUS "LD script: ${NEX_MCU_LD_SCRIPT}")
  nex_log(STATUS "Compiler flags: ${NEX_COMPILER_FLAGS}")
  nex_log(STATUS "Linker flags: ${NEX_LINKER_FLAGS}")
endif()

if (NEX_BUILD_TESTS)
  enable_testing()

  get_target_property(SOC_SRC_LIST nex_synapse_soc NEX_SRC_FILES)
  list(TRANSFORM SOC_SRC_LIST REPLACE "\\.c" "_test.c")
  list(TRANSFORM SOC_SRC_LIST PREPEND ${NEX_SYN_TESTS_DIR}/soc/)

  get_target_property(CPU_SRC_LIST nex_synapse_cpu NEX_SRC_FILES)
  list(TRANSFORM CPU_SRC_LIST REPLACE "\\.c" "_test.c")
  list(TRANSFORM CPU_SRC_LIST PREPEND ${NEX_SYN_TESTS_DIR}/cpu/)

  syn_register_tests(${SOC_SRC_LIST})
  syn_register_tests(${CPU_SRC_LIST})
endif()
