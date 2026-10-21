set(NEX_BLACKBIRD_BASE_DIR ${PROJECT_SOURCE_DIR}/appstack/blackbird)
set(NEX_BLACKBIRD_INCLUDE_DIR ${NEX_BLACKBIRD_BASE_DIR}/inc)
set(NEX_BLACKBIRD_SRC_DIR ${NEX_BLACKBIRD_BASE_DIR}/src)
set(NEX_BLACKBIRD_TESTS_DIR ${NEX_BLACKBIRD_BASE_DIR}/tests)

function (bb_register_tests)
  set(TESTS_LIST ${ARGN})
  foreach (test IN LISTS TESTS_LIST)

    string(REPLACE ".cpp" "" TEST_NAME ${test})
    string(PREPEND test ${NEX_BLACKBIRD_TESTS_DIR}/)
    string(FIND ${TEST_NAME} "/" POS REVERSE)
    math(EXPR START "${POS} + 1")
    string(SUBSTRING ${TEST_NAME} ${START} -1 TEST_NAME)

    bb_register_test(${test} ${TEST_NAME})
  endforeach()
endfunction()

function (bb_register_test test name)
  add_executable(${name} ${test})
  target_link_libraries(${name} PUBLIC nex_buildcfg)
  target_link_libraries(${name} PUBLIC nex_libcom)
  target_link_libraries(${name} PUBLIC nex_libtest)
  target_link_libraries(${name} PUBLIC nex_system)
  target_link_libraries(${name} PUBLIC nex_synapse)
  target_link_libraries(${name} PUBLIC nex_blackbird)
  add_test(NAME ${name} COMMAND ${name})

  set_target_properties(${name} 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/tests"
  )
endfunction()
