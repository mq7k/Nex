set(NEX_LIBCOM_BASE_DIR ${CMAKE_SOURCE_DIR}/appstack/libcom)
set(NEX_LIBCOM_SRC_DIR ${NEX_LIBCOM_BASE_DIR}/src)
set(NEX_LIBCOM_INC_DIR ${NEX_LIBCOM_BASE_DIR}/inc)
set(NEX_LIBCOM_TESTS_DIR ${NEX_LIBCOM_BASE_DIR}/tests)

function (libcom_register_tests)
  set(TESTS_LIST ${ARGN})
  foreach (test IN LISTS TESTS_LIST)

    string(REPLACE ".c" "" TEST_NAME ${test})
    string(PREPEND test ${NEX_LIBCOM_TESTS_DIR}/)
    string(FIND ${TEST_NAME} "/" POS REVERSE)
    math(EXPR START "${POS} + 1")
    string(SUBSTRING ${TEST_NAME} ${START} -1 TEST_NAME)
    
    libcom_register_test(${test} ${TEST_NAME})
  endforeach()
endfunction()

function (libcom_register_test test name)
  if (NOT EXISTS ${test})
    nex_log(WARNING "Test not found: ${test}")
    return()
  endif()

  add_executable(${name} ${test})
  target_link_libraries(${name} PRIVATE nex_buildcfg)
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
