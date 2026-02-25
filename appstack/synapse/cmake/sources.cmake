# syn_log(STATUS "Requested drivers: ${NEX_PERIPH_DRIVERS}")
# syn_log(STATUS "Requested examples: ${NEX_EXAMPLES}")
# syn_log(STATUS "Requested tests: ${NEX_TESTS}")

syn_add_mcu_drivers(${SYN_MCU_PERIPH_DRIVERS})
syn_add_arch_drivers(${SYN_ARCH_PERIPH_DRIVERS})

if (NEX_PLATFORM_ARM)
  syn_add_arch_com_file(
    init.c
    cm.S
  )
elseif (NEX_PLATFORM_DESKTOP)
  syn_add_arch_com_file(
    cmd.S
  )
endif()

syn_add_arch_com_header(
  memorymap
  sys
)

if (NEX_BUILD_TESTS)
  enable_testing()
  syn_add_tests(${SYN_MCU_DRIVER_TESTS_DIR} ${NEX_MCU_TESTS})
  syn_add_tests(${SYN_ARCH_DRIVER_TESTS_DIR} ${SYN_ARCH_TESTS})
  # syn_add_tests(${SYN_ARCH_TESTS})
  # syn_add_tests(${LIBCOM_TESTS})
endif()

syn_add_examples(${SYN_MCU_EXAMPLES})
syn_add_examples(${SYN_ARCH_EXAMPLES})
