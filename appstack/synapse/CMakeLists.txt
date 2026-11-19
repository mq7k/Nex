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

syn_is_supported_family_line(${NEX_MCU_FAMILY_LINE} IS_SUPPORTED)
if (NOT IS_SUPPORTED)
  nex_log(FATAL_ERROR "Unsupported target MCU: ${NEX_MCU_FULLNAME}")
endif()

# Defines supported MCU for the selected family line.
# For example, if family line = stm32f4, it defines
# each supported stm32f4xxxx MCU.
include(mcu/${NEX_MCU_FAMILY_LINE})

syn_is_supported_mcu(${NEX_MCU_FULLNAME} IS_SUPPORTED)
if (NOT IS_SUPPORTED)
  nex_log(FATAL_ERROR "Unsupported target MCU: ${NEX_MCU_FULLNAME}")
endif()

# Retrieve information on the target MCU.
syn_get_device_cdg(${NEX_MCU_FULLNAME} SYN_CDG_GROUP)
syn_get_device_mdg(${NEX_MCU_FULLNAME} SYN_MDG_GROUP)
syn_get_device_defs(${NEX_MCU_FULLNAME} SYN_DEFS_LIST)
syn_get_soc_drivers(${NEX_MCU_FULLNAME} SYN_SOC_DRIVERS)
syn_get_soc_ld(${NEX_MCU_FULLNAME} SYN_SOC_LD)

set(FULLPATH ${NEX_SYN_CMAKE_DIR}/cpu/${SYN_CDG_GROUP}.cmake)
if (NOT EXISTS ${FULLPATH})
  nex_log(FATAL_ERROR "Unsupported target CPU: ${SYN_CDG_GROUP}")
endif()

include(cpu/${SYN_CDG_GROUP})

# Retrieve information on the target CPU.
syn_get_cpu_model(${SYN_CDG_GROUP} SYN_CPU_MODEL)
syn_get_cpu_fpu(${SYN_CDG_GROUP} SYN_CPU_FPU)
syn_get_cpu_compile_options(${SYN_CDG_GROUP} SYN_CPU_CO)
syn_get_cpu_link_options(${SYN_CDG_GROUP} SYN_CPU_LO)
syn_get_cpu_drivers(${SYN_CDG_GROUP} SYN_CPU_DRIVERS)

get_target_property(NEX_COMPILER_FLAGS nex_buildcfg INTERFACE_COMPILE_OPTIONS)
get_target_property(NEX_LINKER_FLAGS nex_buildcfg INTERFACE_LINK_OPTIONS)

nex_log(STATUS "MCU fullname: ${NEX_MCU_FULLNAME}")
nex_log(STATUS "Family: ${NEX_MCU_FAMILY_LINE}")
nex_log(STATUS "CPU: ${SYN_CPU_MODEL}")
nex_log(STATUS "Platform: ${NEX_PLATFORM}")

if (NEX_VERBOSE)
  nex_log(STATUS "LD script: ${SYN_SOC_LD}")
  nex_log(STATUS "Compiler flags: ${NEX_COMPILER_FLAGS};${SYN_CPU_CO}")
  nex_log(STATUS "Linker flags: ${NEX_LINKER_FLAGS};${SYN_CPU_LO}")
endif()

# Adds common CPU files.
# Examples: `cm.S` is shared across the entire Cortex lineup.
add_subdirectory(src/cpu/${NEX_CPU_FAMILY})

if (NEX_PLATFORM_ARM)
  add_subdirectory(src/soc/${NEX_MCU_FAMILY}/port)
endif()

add_subdirectory(src/common)
add_subdirectory(src/drivers)
add_subdirectory(src/io)

# Sets up the cmake (nex_synapse) target.
# Defines macros, links against other layers,
# adds compiler/linker flags...
include(syn)

nex_add_sources(
  TARGET nex_synapse_soc
  PATH ${NEX_SYN_SRC_DIR}/soc/${NEX_MCU_FAMILY}/drivers
  SOURCES ${SYN_SOC_DRIVERS}
  MSG "Adding SoC driver: "
)

nex_add_sources(
  TARGET nex_synapse_cpu
  PATH ${NEX_SYN_SRC_DIR}/cpu/${NEX_CPU_FAMILY}
  SOURCES ${SYN_CPU_DRIVERS}
  MSG "Adding CPU driver: "
)

syn_add_interfaces_from_sources(
  TARGET nex_synapse_soc
  PATH ${NEX_SYN_SRC_DIR}/soc/${NEX_MCU_FAMILY}/drivers
  SOURCES ${SYN_SOC_DRIVERS}
  MSG "Adding periph interface: "
)

target_link_libraries(nex_synapse PUBLIC nex_synapse_soc)
target_link_libraries(nex_synapse PUBLIC nex_synapse_cpu)
target_link_libraries(nex_synapse PUBLIC nex_synapse_util)

if (NEX_BUILD_TESTS)
  enable_testing()

  set(SOC_SRC_LIST ${SYN_SOC_DRIVERS})
  list(TRANSFORM SOC_SRC_LIST REPLACE "\\.c" "_test.cpp")
  list(TRANSFORM SOC_SRC_LIST PREPEND ${NEX_SYN_TESTS_DIR}/soc/)

  set(CPU_SRC_LIST ${SYN_CPU_DRIVERS})
  list(TRANSFORM CPU_SRC_LIST REPLACE "\\.c" "_test.cpp")
  list(TRANSFORM CPU_SRC_LIST PREPEND ${NEX_SYN_TESTS_DIR}/cpu/)

  syn_register_tests(${SOC_SRC_LIST})
  syn_register_tests(${CPU_SRC_LIST})
endif()
