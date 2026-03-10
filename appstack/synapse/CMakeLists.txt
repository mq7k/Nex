# Includes nex_synapse's variables definition.
include(${CMAKE_CURRENT_SOURCE_DIR}/syndefs.cmake)

list(APPEND CMAKE_MODULE_PATH ${NEX_SYN_CMAKE_DIR})

# Includes nex_synapse's functions definition.
include(synfn)

# The main project library.
add_library(nex_synapse)

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

# Includes the MCU peripheral group of the current target.
# This selects what peripheral to build.
# It stores them into MCU_PERIPH_DRIVERS.
include(mcu/${NEX_MCU_DRIVERS_GROUP})

# Adds the selected peripherals to the build target `nex_synapse`,
# and adds CPU-specific compiler/linker flags.
# NEX_MCU_FAMILY = stm32, ...
# It stores them into ARCH_PERIPH_DRIVERS.
add_subdirectory(firmware/mcu/${NEX_MCU_FAMILY}/drivers)

# Includes the CPU peripheral group of the current target.
# This selects what peripheral to build.
include(cpu/${NEX_ARCH_DRIVERS_GROUP})

# Adds the selected peripherals to the build target `nex_synapse`. 
# NEX_ARCH_FAMILY = cortex, ...
add_subdirectory(firmware/arch/${NEX_CPU_FAMILY}/drivers)

add_subdirectory(firmware/common)
add_subdirectory(firmware/drivers)
add_subdirectory(firmware/io)

# Sets up the cmake (nex_synapse) target.
# Defines macros, links against other layers,
# adds compiler/linker flags...
include(syn)

# TODO: Make sure this is correct.
# if (BUILD_EXAMPLES AND SYN_PLATFORM_ARM)
#   include(cmake/post/examples)
# endif()

get_target_property(NEX_COMPILER_FLAGS nex_buildcfg INTERFACE_COMPILE_OPTIONS)
get_target_property(NEX_LINKER_FLAGS nex_buildcfg INTERFACE_LINK_OPTIONS)

nex_log(STATUS "MCU fullname: ${NEX_MCU_FULLNAME}")
nex_log(STATUS "Family: ${NEX_MCU_FAMILY}")
nex_log(STATUS "CPU: ${NEX_CPU_FAMILY} ${NEX_ARCH_DRIVERS_GROUP}")
nex_log(STATUS "Platform: ${NEX_PLATFORM}")
nex_log(STATUS "LD script: ${NEX_MCU_LD_SCRIPT}")

nex_log(STATUS "Compiler flags: ${NEX_COMPILER_FLAGS}")
nex_log(STATUS "Linker flags: ${NEX_LINKER_FLAGS}")

foreach (driver IN LISTS MCU_PERIPH_DRIVERS)
  nex_log(STATUS "Adding MCU driver: ${driver}")
endforeach()

nex_log(STATUS "")

foreach (driver IN LISTS ARCH_PERIPH_DRIVERS)
  nex_log(STATUS "Adding CPU driver: ${driver}")
endforeach()

nex_log(STATUS "")

if (NEX_BUILD_TESTS)
  enable_testing()
  syn_format_tests_from_periph_drivers(
    MCU_PERIPH_DRIVER_TESTS
    ${MCU_PERIPH_DRIVERS}
  )

  syn_register_tests(
    ${MCU_PERIPH_DRIVER_TESTS}
  )
endif()
