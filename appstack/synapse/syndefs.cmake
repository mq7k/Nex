set(NEX_SYN_BASE_DIR ${CMAKE_SOURCE_DIR}/appstack/synapse)
set(NEX_SYN_CMAKE_DIR ${NEX_SYN_BASE_DIR}/cmake)
set(NEX_SYN_LD_SCRIPTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ld)
set(NEX_SYN_INCLUDE_DIR ${NEX_SYN_BASE_DIR}/include)
set(NEX_SYN_TESTS_DIR ${NEX_SYN_BASE_DIR}/tests)
set(NEX_SYN_SRC_DIR ${NEX_SYN_BASE_DIR}/src)

set(
  NEX_SYN_CPU_DRIVERS_SRC_DIR 
  ${NEX_SYN_SRC_DIR}/cpu/${NEX_CPU_FAMILY}/drivers
)

set(
  NEX_SYN_CPU_DRIVERS_INC_DIR 
  ${NEX_SYN_BASE_DIR}/include/synapse/cpu/${NEX_CPU_FAMILY}/drivers
)

set(
  NEX_SYN_SOC_DRIVERS_SRC_DIR 
  ${NEX_SYN_SRC_DIR}/soc/${NEX_MCU_FAMILY}/drivers
)

set(
  NEX_SYN_SOC_DRIVERS_INC_DIR 
  ${NEX_SYN_BASE_DIR}/include/synapse/soc/${NEX_MCU_FAMILY}/drivers
)

if (NEX_FLOAT STREQUAL "hard")
  set(NEX_FLOAT_HARD ON)
elseif (NEX_FLOAT STREQUAL "softfp")
  set(NEX_FLOAT_SOFTFP ON)
elseif (NEX_FLOAT STREQUAL "soft")
  set(NEX_FLOAT_SOFT ON)
else()
  nex_log(FATAL_ERROR "Invalid float type: '${NEX_FLOAT}'")
endif()
