set(
  SYN_COMMON_SOURCES_DIR
  ${SYN_BASE_DIR}/firmware/common
)

set(
  SYN_COMMON_HEADERS_DIR
  ${SYN_BASE_DIR}/include/synapse/common
)

set(
  SYN_MCU_DRIVER_INCLUDE_DIR
  ${SYN_BASE_DIR}/include/synapse/${NEX_TARGET_FAMILY}/drivers
)

set(
  SYN_MCU_SOURCES_DIRECTORY
  ${SYN_BASE_DIR}/firmware/${NEX_TARGET_FAMILY}
)

set(
  SYN_MCU_INCLUDE_DIRECTORY
  ${SYN_BASE_DIR}/include/${NEX_TARGET_FAMILY}
)

set(
  SYN_MCU_DRIVER_SOURCES_DIR
  ${SYN_BASE_DIR}/firmware/${NEX_TARGET_FAMILY}/drivers
)

set(
  SYN_MCU_UTIL_SOURCES_DIR
  ${SYN_BASE_DIR}/firmware/${NEX_TARGET_FAMILY}/util
)

set(
  SYN_MCU_UTIL_HEADERS_DIR
  ${SYN_BASE_DIR}/include/synapse/${NEX_TARGET_FAMILY}/util
)

set(
  SYN_ARCH_DRIVERS_INCLUDE_DIR
  ${SYN_BASE_DIR}/include/synapse/arch/${NEX_TARGET_CPU_FAMILY}/drivers
)

set(
  SYN_ARCH_DRIVERS_COM_INCLUDE_DIR
  ${SYN_BASE_DIR}/include/synapse/arch/${NEX_TARGET_CPU_FAMILY}/common
)

set(
  SYN_ARCH_DRIVERS_SOURCES_DIR
  ${SYN_BASE_DIR}/firmware/arch/${NEX_TARGET_CPU_FAMILY}/drivers
)

set(
  SYN_ARCH_COM_SOURCES_DIR
  ${SYN_BASE_DIR}/firmware/arch/${NEX_TARGET_CPU_FAMILY}/common
)

set(
  SYN_MCU_DRIVER_TESTS_DIR
  ${SYN_BASE_DIR}/tests/periph
)

set(
  SYN_ARCH_DRIVER_TESTS_DIR
  ${SYN_BASE_DIR}/tests/arch
)

set(
  SYN_MCU_EXAMPLES_DIR
  ${SYN_BASE_DIR}/examples/${NEX_TARGET_FAMILY}
)

set(
  SYN_ARCH_EXAMPLES_DIR
  ${SYN_BASE_DIR}/examples/${NEX_TARGET_ARCH}
)

set(SYN_INCLUDE_DIR ${SYN_BASE_DIR}/include)

if (NOT DEFINED SYN_MCU_DRIVER_TESTS_DIR)
  set(
    SYN_MCU_DRIVER_TESTS_DIR
    ${SYN_BASE_DIR}/tests/periph
  )
endif()

if (NOT EXISTS ${SYN_ARCH_DRIVERS_INCLUDE_DIR})
  syn_log(FATAL_ERROR "Arch include directory '${SYN_ARCH_DRIVERS_INCLUDE_DIR}' doesn't exist.")
endif()

if (NOT EXISTS ${SYN_ARCH_DRIVERS_SOURCES_DIR})
  syn_log(FATAL_ERROR "Arch sources directory '${SYN_ARCH_DRIVERS_SOURCES_DIR}' doesn't exist.")
endif()

if (NOT EXISTS ${SYN_MCU_DRIVER_TESTS_DIR})
  syn_log(WARNING "!! No tests found for '${NEX_MCU_FULLNAME}' !!")
endif()

if (NOT EXISTS ${SYN_ARCH_DRIVER_TESTS_DIR})
  syn_log(WARNING "!! No tests found for '${NEX_TARGET_ARCH}' !!")
endif()

