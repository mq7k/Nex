# Contains custom functions used in the project.

function(syn_add_tests dir)
  set(TESTS_LIST ${ARGN})

  foreach (test IN LISTS TESTS_LIST)
    string(FIND "${test}" "/" POS)
    math(EXPR START "${POS} + 1")
    string(SUBSTRING "${test}" ${START} -1 TEST_NAME)

    set(TEST_PATH "${test}_test.c")

    syn_register_test("${dir}" "${TEST_NAME}" "${TEST_PATH}")
  endforeach()
endfunction()

function(syn_register_test dir test_name test_file)
  # set(TEST_FULLPATH "${SYN_MCU_DRIVER_TESTS_DIR}/${test_file}")
  set(TEST_FULLPATH "${dir}/${test_file}")
  if (NOT EXISTS ${TEST_FULLPATH})
    syn_log(WARNING "Test file not found: '${TEST_FULLPATH}'")
    return()
  endif()
  
  add_executable(${test_name} ${TEST_FULLPATH})
  target_link_libraries(${test_name} PRIVATE eco_libtest)
  target_link_libraries(${test_name} PRIVATE synapse)
  add_test(NAME ${test_name} COMMAND ${test_name})
  set_target_properties(${test_name} 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/tests"
  )

  syn_log(STATUS "Adding test: ${test_name} (${test_file})")
endfunction()

function(sys_add_tests dir)
  set(TESTS_LIST ${ARGN})

  foreach (test IN LISTS TESTS_LIST)
    string(FIND "${test}" "/" POS)
    math(EXPR START "${POS} + 1")
    string(SUBSTRING "${test}" ${START} -1 TEST_NAME)

    set(TEST_PATH "${test}_test.c")

    sys_register_test("${dir}" "${TEST_NAME}" "${TEST_PATH}")
  endforeach()
endfunction()

function(sys_register_test dir test_name test_file)
  # set(TEST_FULLPATH "${SYN_MCU_DRIVER_TESTS_DIR}/${test_file}")
  set(TEST_FULLPATH "${dir}/${test_file}")
  if (NOT EXISTS ${TEST_FULLPATH})
    eco_log(WARNING "Test file not found: '${TEST_FULLPATH}'")
    return()
  endif()
  
  add_executable(${test_name} ${TEST_FULLPATH})
  target_link_libraries(${test_name} PRIVATE eco_libtest)
  target_link_libraries(${test_name} PRIVATE synapse)
  target_link_libraries(${test_name} PRIVATE systeml)
  add_test(NAME ${test_name} COMMAND ${test_name})
  set_target_properties(${test_name} 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/tests"
  )

  syn_log(STATUS "Adding test: ${test_name} (${test_file})")
endfunction()

function(syn_add_mcu_drivers)
  set(DRIVERS_LIST_HEADERS ${ARGN})
  set(DRIVERS_LIST_SOURCES ${ARGN})
  set(DRIVERS_LIST_IN ${ARGN})

  __syn_format_drivers_headers(
    "${SYN_MCU_DRIVER_INCLUDE_DIR}/" DRIVERS_LIST_HEADERS
  )

  __syn_format_drivers_sources(
  "${SYN_MCU_DRIVER_SOURCES_DIR}/" DRIVERS_LIST_SOURCES
  )

  target_sources(syn_chip PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${SYN_INCLUDE_DIR}
    FILES ${DRIVERS_LIST_HEADERS}
  )

  target_sources(syn_chip PUBLIC
    ${DRIVERS_LIST_SOURCES}
  )

  foreach (driver IN LISTS DRIVERS_LIST_IN)
    syn_log(STATUS "Requested mcu driver: ${driver}.c")
  endforeach()
endfunction()

function(syn_add_arch_drivers)
  set(DRIVERS_LIST_HEADERS ${ARGN})
  set(DRIVERS_LIST_SOURCES ${ARGN})
  set(DRIVERS_LIST_IN ${ARGN})

  __syn_format_drivers_headers("${SYN_ARCH_DRIVERS_INCLUDE_DIR}/" DRIVERS_LIST_HEADERS)
  __syn_format_drivers_sources("${SYN_ARCH_DRIVERS_SOURCES_DIR}/" DRIVERS_LIST_SOURCES)

  target_sources(syn_arch PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${SYN_INCLUDE_DIR}
    FILES ${DRIVERS_LIST_HEADERS}
  )

  target_sources(syn_arch PUBLIC
    ${DRIVERS_LIST_SOURCES}
  )

  foreach (driver IN LISTS DRIVERS_LIST_IN)
    syn_log(STATUS "Requested arch driver: ${driver}.c")
  endforeach()
endfunction()

function(syn_add_chip_source_file)
  set(DRIVERS_LIST_SOURCES ${ARGN})
  set(DRIVERS_LIST_IN ${ARGN})

  __syn_format_drivers_sources("${SYN_MCU_SOURCES_DIRECTORY}/" DRIVERS_LIST_SOURCES)

  target_sources(syn_chip PUBLIC
    ${DRIVERS_LIST_SOURCES}
  )

  foreach (driver IN LISTS DRIVERS_LIST_SOURCES)
    syn_log(STATUS "Requested chip source: ${driver}")
  endforeach()
endfunction()

function(syn_add_examples)
  list(APPEND MCU_EXAMPLES ${ARGN})
  set(MCU_EXAMPLES "${MCU_EXAMPLES}" PARENT_SCOPE)
endfunction()

function(syn_add_arch_com_file)
  set(FILES_LIST ${ARGN})
  set(ORIGINAL_LIST ${ARGN})

  __syn_format_files_path("${SYN_ARCH_COM_SOURCES_DIR}/" "" FILES_LIST)

  target_sources(syn_arch PUBLIC
    ${FILES_LIST}
  )

  foreach (file IN LISTS ORIGINAL_LIST)
    syn_log(STATUS "Adding arch com file: arch/${NEX_TARGET_CPU_FAMILY}/common/${file}")
  endforeach()
endfunction()

function(__syn_format_drivers_sources prefix DRIVERS)
  set(DRIVERS_LIST "${${DRIVERS}}")
  list(TRANSFORM DRIVERS_LIST PREPEND "${prefix}")
  list(TRANSFORM DRIVERS_LIST APPEND ".c")
  set(${DRIVERS} ${DRIVERS_LIST} PARENT_SCOPE)
endfunction()

function(__syn_format_drivers_headers prefix DRIVERS)
  set(DRIVERS_LIST "${${DRIVERS}}")
  list(TRANSFORM DRIVERS_LIST PREPEND "${prefix}")
  list(TRANSFORM DRIVERS_LIST APPEND ".h")
  set(${DRIVERS} ${DRIVERS_LIST} PARENT_SCOPE)
endfunction()

function(__syn_format_files_path prefix suffix INLIST)
  set(OUT_LIST "${${INLIST}}")
  list(TRANSFORM OUT_LIST PREPEND "${prefix}")
  list(TRANSFORM OUT_LIST APPEND "${suffix}")
  set(${INLIST} ${OUT_LIST} PARENT_SCOPE)
endfunction()

function(syn_add_arch_com_header)
  set(FILES_LIST ${ARGN})
  __syn_format_drivers_headers("${SYN_ARCH_DRIVERS_COM_INCLUDE_DIR}/" FILES_LIST)
  target_sources(syn_arch PUBLIC
    ${FILES_LIST}
  )
  foreach (header IN LISTS HEADERS_LIST)
    syn_log(STATUS "Adding arch common header: ${header}")
  endforeach()
endfunction()

function(syn_add_common_headers)
  set(HEADERS_LIST ${ARGN})
  set(ORIGINAL_LIST ${ARGN})

  list(TRANSFORM HEADERS_LIST PREPEND "${SYN_COMMON_HEADERS_DIR}/")
  list(TRANSFORM HEADERS_LIST APPEND ".h")

  target_sources(syn_common PUBLIC 
    FILE_SET HEADERS
    BASE_DIRS ${SYN_INCLUDE_DIR}
    FILES ${HEADERS_LIST}
  )

  foreach (header IN LISTS ORIGINAL_LIST)
    syn_log(STATUS "Adding common header: ${header}.h")
  endforeach()
endfunction()

function(syn_add_common)
  set(COMMON_SOURCES_FILES ${ARGN})
  set(COMMON_HEADERS_FILES ${ARGN})
  set(ORIGINAL_LIST ${ARGN})

  list(TRANSFORM COMMON_SOURCES_FILES PREPEND "${SYN_COMMON_SOURCES_DIR}/")
  list(TRANSFORM COMMON_SOURCES_FILES APPEND ".c")

  list(TRANSFORM COMMON_HEADERS_FILES PREPEND "${SYN_COMMON_HEADERS_DIR}/")
  list(TRANSFORM COMMON_HEADERS_FILES APPEND ".h")

  target_sources(syn_common PUBLIC
    ${COMMON_SOURCES_FILES}
  )

  target_sources(syn_common PUBLIC 
    FILE_SET HEADERS
    BASE_DIRS ${SYN_INCLUDE_DIR}
    FILES ${COMMON_HEADERS_FILES}
  )

  foreach (file IN LISTS ORIGINAL_LIST)
    syn_log(STATUS "Adding common file: ${file}.c")
  endforeach()
endfunction()

function(syn_create_example name)
  set(SOURCE_FILES ${ARGN})
  add_executable(${name} main.c ${SOURCE_FILES})
  target_link_libraries(${name} PRIVATE eco_buildtype)
  target_link_libraries(${name} PRIVATE eco_libcom)
  target_link_libraries(${name} PRIVATE systeml)
  target_link_libraries(${name} PRIVATE synapse)
  eco_add_generate_binary_file_cmd(${name})
endfunction()

