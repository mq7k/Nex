function (syn_register_tests)
  set(TESTS_LIST ${ARGN})
  foreach (test IN LISTS TESTS_LIST)

    # We parse the test name from the C file source name.
    # dma/dma_v1_test.c -> dma_v1_test
    string(REPLACE ".cpp" "" TEST_NAME ${test})
    string(FIND ${TEST_NAME} "/" POS REVERSE)
    math(EXPR START "${POS} + 1")
    string(SUBSTRING ${TEST_NAME} ${START} -1 TEST_NAME)
    
    syn_register_test(${test} ${TEST_NAME})
  endforeach()
endfunction()

function (syn_register_test test name)
  if (NOT EXISTS ${test})
    # nex_log(WARNING "Test not found: ${test}")
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

function(syn_add_interfaces_from_sources)
  cmake_parse_arguments(ARG "" "TARGET;PATH;MSG" "SOURCES" ${ARGN})
  foreach (source IN LISTS ARG_SOURCES)
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

function (syn_register_example name)
  set(SRC_LIST ${ARGN})
  add_executable(${name} ${SRC_LIST})
  target_link_libraries(${name} PRIVATE nex_buildcfg)
  target_link_libraries(${name} PRIVATE nex_libcom)
  target_link_libraries(${name} PRIVATE nex_system)
  target_link_libraries(${name} PRIVATE nex_synapse)
  nex_add_generate_binary_file_cmd(${name})

  if (NEX_VERBOSE)
    nex_log(STATUS "Registering example: ${name}")
  endif()
endfunction()

function(syn_device)
  cmake_parse_arguments(ARG "" "ID;MDG;CDG;LD" "DEFS" ${ARGN})

  string(TOLOWER ${ARG_ID} id)

  if (NOT ARG_MDG)
    set(ARG_MDG ${id})
  endif()

  if (NOT ARG_CDG)
    get_property(GBL_CDG GLOBAL PROPERTY SYN_GBL_CDG)
    set(ARG_CDG ${GBL_CDG})
  endif()

  if (ARG_DEFS)
    set_property(GLOBAL PROPERTY SYN_DEV_${id}_DEFS ${ARG_DEFS})
  endif()

  if (NOT ARG_LD)
    string(REGEX MATCH "^stm32(.)(.)(..).(.)" _ "${id}")
    set(ARG_LD "${CMAKE_MATCH_1}x")
    set(ARG_LD "${ARG_LD}/${CMAKE_MATCH_1}${CMAKE_MATCH_2}")
    set(
      ARG_LD
      "${ARG_LD}/${NEX_MCU_FAMILY_LINE}${CMAKE_MATCH_3}x${CMAKE_MATCH_4}"
    )
  endif()

  set_property(GLOBAL PROPERTY SYN_DEV_${id}_ID "${id}")
  set_property(GLOBAL PROPERTY SYN_DEV_${id}_MDG "${ARG_MDG}")
  set_property(GLOBAL PROPERTY SYN_DEV_${id}_CDG "${ARG_CDG}")
  set_property(GLOBAL PROPERTY SYN_DEV_${id}_LD "${ARG_LD}")
endfunction()

function(syn_driver_group)
  cmake_parse_arguments(ARG "" "ID" "DRIVERS" ${ARGN})
  string(TOLOWER ${ARG_ID} id)
  set_property(GLOBAL PROPERTY SYN_DG_${id}_DRIVERS ${ARG_DRIVERS})
endfunction()

function(syn_set_cdg group)
  # SYN_GBL_CDG = Syn global cpu driver group.
  set_property(GLOBAL PROPERTY SYN_GBL_CDG ${group})
endfunction()

function(syn_cpu_group)
  cmake_parse_arguments(ARG "" "ID;FPU;MODEL" "DRIVERS;COMPILE_OPTIONS;LINK_OPTIONS" ${ARGN})
  string(TOLOWER ${ARG_ID} id)

  if (ARG_FPU)
    set_property(GLOBAL PROPERTY SYN_DG_${id}_FPU ${ARG_FPU})
  endif()

  if (ARG_COMPILE_OPTIONS)
    set_property(GLOBAL PROPERTY SYN_DG_${id}_CO ${ARG_COMPILE_OPTIONS})
  endif()

  if (ARG_LINK_OPTIONS)
    set_property(GLOBAL PROPERTY SYN_DG_${id}_LO ${ARG_LINK_OPTIONS})
  endif()

  set_property(GLOBAL PROPERTY SYN_DG_${id}_DRIVERS ${ARG_DRIVERS})
  set_property(GLOBAL PROPERTY SYN_DG_${id}_MODEL ${ARG_MODEL})
endfunction()

function(syn_cpu_group_append)
  cmake_parse_arguments(ARG "" "ID" "DRIVERS" ${ARGN})
  string(TOLOWER ${ARG_ID} id)
  set_property(GLOBAL APPEND PROPERTY SYN_DG_${id}_DRIVERS ${ARG_DRIVERS})
endfunction()

function(syn_is_supported_mcu id var)
  get_property(IS_SET GLOBAL PROPERTY SYN_DEV_${id}_ID SET)
  set(${var} ${IS_SET} PARENT_SCOPE)
endfunction()

function(syn_is_supported_family_line family_line var)
  set(FULLPATH "${NEX_SYN_CMAKE_DIR}/mcu/${family_line}.cmake")
  if (EXISTS ${FULLPATH})
    # Any non-empty string do the trick.
    set(${var} "YES" PARENT_SCOPE)
  endif()
endfunction()

function(syn_get_device_cdg id var)
  get_property(VAL GLOBAL PROPERTY SYN_DEV_${id}_CDG)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_device_mdg id var)
  get_property(VAL GLOBAL PROPERTY SYN_DEV_${id}_MDG)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_device_defs id var)
  get_property(VAL GLOBAL PROPERTY SYN_DEV_${id}_DEFS)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_soc_ld id var)
  get_property(VAL GLOBAL PROPERTY SYN_DEV_${id}_LD)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_soc_drivers id var)
  get_property(GRP GLOBAL PROPERTY SYN_DEV_${id}_MDG)
  string(SUBSTRING ${GRP} 0 9 family)
  get_property(VAL GLOBAL PROPERTY SYN_DG_${family}_DRIVERS)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_cpu_model group var)
  get_property(VAL GLOBAL PROPERTY SYN_DG_${group}_MODEL)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_cpu_fpu group var)
  get_property(VAL GLOBAL PROPERTY SYN_DG_${group}_FPU)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_cpu_compile_options group var)
  get_property(VAL GLOBAL PROPERTY SYN_DG_${group}_CO)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_cpu_link_options group var)
  get_property(VAL GLOBAL PROPERTY SYN_DG_${group}_LO)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

function(syn_get_cpu_drivers group var)
  get_property(VAL GLOBAL PROPERTY SYN_DG_${group}_DRIVERS)
  set(${var} ${VAL} PARENT_SCOPE)
endfunction()

