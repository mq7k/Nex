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
    nex_log(WARNING "Test not found: ${test}")
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

  if (NEX_VERBOSE)
    nex_log(STATUS "Registering test: ${name}")
  endif()
endfunction()

function (syn_add_interfaces_from_property)
  cmake_parse_arguments(ARG "" "TARGET;PATH;MSG" "" ${ARGN})
  get_target_property(SRC_LIST ${ARG_TARGET} NEX_SRC_FILES)
  foreach (source IN LISTS SRC_LIST)
    string(FIND ${source} "/" POS REVERSE)
    string(SUBSTRING ${source} 0 ${POS} PERIPH_NAME)
    set(INTERFACE "${PERIPH_NAME}/${PERIPH_NAME}if.c")

    if (EXISTS ${ARG_PATH}/${INTERFACE})
      nex_add_sources(
        TARGET ${ARG_TARGET}
        PATH ${ARG_PATH}
        SOURCES ${INTERFACE}
      )

      if (NEX_VERBOSE)
        nex_log(STATUS "${ARG_MSG}${INTERFACE}")
      endif()
    endif()
  endforeach()
endfunction()
