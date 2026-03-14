set(NEX_SYSTEM_BASE_DIR ${PROJECT_SOURCE_DIR}/appstack/system)
set(NEX_SYSTEM_INCLUDE_DIR ${NEX_SYSTEM_BASE_DIR}/include)
set(
  NEX_SYSTEM_TESTS_DIR
  ${NEX_SYSTEM_BASE_DIR}/tests
)

function (sys_register_tests)
  set(TESTS_LIST ${ARGN})
  foreach (test IN LISTS TESTS_LIST)
    # `test` specify the test path starting
    # from NEX_SYSTEM_TESTS_DIR (`nex/appstack/system/tests`).
    # So, if the test is located at, for example,
    # `nex/appstack/system/tests/foo/bar.c`,
    # test would be `foo/bar.c`.

    string(PREPEND test ${NEX_SYSTEM_TESTS_DIR}/)

    string(REPLACE ".c" "" TEST_NAME ${test})
    string(FIND ${TEST_NAME} "/" POS REVERSE)
    math(EXPR START "${POS} + 1")
    string(SUBSTRING ${TEST_NAME} ${START} -1 TEST_NAME)

    sys_register_test(${test} ${TEST_NAME})
  endforeach()
endfunction()

function (sys_register_test test name)
  add_executable(${name} ${test})
  target_link_libraries(${name} PUBLIC nex_buildcfg)
  target_link_libraries(${name} PUBLIC nex_libcom)
  target_link_libraries(${name} PUBLIC nex_libtest)
  add_test(NAME ${name} COMMAND ${name})

  set_target_properties(${name} 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/tests"
  )
endfunction()
