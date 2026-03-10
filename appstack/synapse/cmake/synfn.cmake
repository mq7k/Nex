function (syn_add_sources target)
  set(DRIVERS ${ARGN})

  # Adds .c files.
  target_sources(${target} PUBLIC ${DRIVERS})

  # Add .h files.
  # target_sources(${target})
endfunction()

# Takes in a list of peripheral drivers
# and create a new list with their test file. 
# Example: 
# DRIVERS = dma/dma_v2.c;spi/spi_v1.c
# Output = dma/dma_v2_test.c;spi/spi_v1_test.c
function (syn_format_tests_from_periph_drivers output)
  set(drivers ${ARGN})
  set(TESTS_LIST "")
  foreach (driver IN LISTS drivers)
    string(REPLACE ".c" "_test.c" DRIVER_TEST ${driver})
    string(PREPEND DRIVER_TEST ${NEX_SYN_TESTS_DIR}/mcu/)
    list(APPEND TESTS_LIST ${DRIVER_TEST})
  endforeach()
  set(${output} ${TESTS_LIST} PARENT_SCOPE)
endfunction()

function (syn_register_tests)
  set(TESTS_LIST ${ARGN})
  foreach (test IN LISTS TESTS_LIST)

    # We parse the test name from the C file source name.
    # dma/dma_v1_test.c -> dma_v1_test
    string(REPLACE ".c" "" TEST_NAME ${test})
    string(FIND ${TEST_NAME} "/" POS REVERSE)
    math(EXPR START "${POS} + 1")
    string(SUBSTRING ${TEST_NAME} ${START} -1 TEST_NAME)
    
    syn_register_test(${test} ${TEST_NAME})
  endforeach()
endfunction()

function (syn_register_test test name)
  if (NOT EXISTS ${test})
    nex_log(STATUS "Test not found: ${test}")
    return()
  endif()

  add_executable(${name} ${test})
  target_link_libraries(${name} PRIVATE nex_buildcfg)
  target_link_libraries(${name} PRIVATE nex_libcom)
  target_link_libraries(${name} PRIVATE nex_synapse)
  target_link_libraries(${name} PRIVATE nex_libtest)
  add_test(NAME ${name} COMMAND ${name})

  set_target_properties(${name} 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/tests"
  )

  nex_log(STATUS "Registering test: ${name}")
endfunction()
