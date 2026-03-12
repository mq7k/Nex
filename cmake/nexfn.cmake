function(nex_log level message)
  message(${level} "[Nex] ${message}")
endfunction()

# Converts the compiled ELF file into a binary file
# executable by a microcontroller.
# The output file is placed in the same directory
# as the ELF input file.
function(nex_add_generate_binary_file_cmd target)
  add_custom_command(TARGET ${target} POST_BUILD
    COMMAND
      ${CMAKE_OBJCOPY} -O binary 
      $<TARGET_FILE:${target}> 
      ${CMAKE_CURRENT_BINARY_DIR}/${target}.bin
    COMMENT
      "Generating binary file ${CMAKE_CURRENT_BINARY_DIR}/${target}.bin"
  )
endfunction()

# Takes in a list of macros, transform them to upper case,
# and defines them to be access from C code.
# They are defined as PUBLIC.
function (nex_define_macros_p target)
  set(MACROS_LIST ${ARGN})
  list(TRANSFORM MACROS_LIST TOUPPER)
  target_compile_definitions(${target} PUBLIC ${MACROS_LIST})
endfunction()

# Takes in a list of macros, transform them to upper case,
# and defines them to be access from C code.
# $target must be an interface.
function (nex_define_macros_i target)
  set(MACROS_LIST ${ARGN})
  list(TRANSFORM MACROS_LIST TOUPPER)
  target_compile_definitions(${target} INTERFACE ${MACROS_LIST})
endfunction()

# Takes in a list of macros
# and defines them to be access from C code.
# $target must be an interface.
function (nex_define_macros_iraw target)
  set(MACROS_LIST ${ARGN})
  target_compile_definitions(${target} INTERFACE ${MACROS_LIST})
endfunction()

# Adds a list of sources to a specific target.
# Each source file is assumed to be relative to $PATH.
# The final include path for each $source in $SOURCES is:
# ${PATH}/${source} if ${PATH} is not an empty string;
# ${source} otherwise.
function (nex_add_sources)
  cmake_parse_arguments(ARG "" "TARGET;PATH;MSG" "SOURCES" ${ARGN})
  set(ORIGINAL_LIST ${ARG_SOURCES})

  if (ARG_PATH)
    list(TRANSFORM ARG_SOURCES PREPEND ${ARG_PATH}/)
  endif()

  target_sources(${ARG_TARGET} PUBLIC ${ARG_SOURCES})

  if (ARG_MSG AND NEX_VERBOSE)
    foreach (source IN LISTS ORIGINAL_LIST)
      nex_log(STATUS "${ARG_MSG}${source}")
    endforeach()
  endif()
endfunction()

# Adds a list of headers to a specific target.
# Each header file is assumed to be relative to $PATH.
# The final include path for each $header in $HEADERS is:
# ${PATH}/${header} if ${PATH} is not an empty string;
# ${header} otherwise.
function (nex_add_headers)
  cmake_parse_arguments(ARG "" "TARGET;PATH;MSG" "HEADERS" ${ARGN})
  set(ORIGINAL_LIST ${ARG_HEADERS})
  list(TRANSFORM ARG_SOURCES PREPEND ${ARG_PATH}/)

  target_sources(${ARG_TARGET} PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${ARG_PATH}
    FILES ${ORIGINAL_LIST}
  )

  if (ARG_MSG AND NEX_VERBOSE)
    foreach (header IN LISTS ORIGINAL_LIST)
      nex_log(STATUS "${ARG_MSG}${header}")
    endforeach()
  endif()
endfunction()

# Takes in a list of sources, prepend them with ${PATH} if ${PATH}/
# is not an empty string, and sets them as NEX_SRC_FILES property
# to ${TARGET}.
function (nex_add_sources_property)
  cmake_parse_arguments(ARG "" "TARGET;PATH" "SOURCES" ${ARGN})
  set(ORIGINAL_LIST ${ARG_SOURCES})

  if (ARG_PATH)
    list(TRANSFORM ARG_SOURCES PREPEND ${ARG_PATH}/)
  endif()

  set_target_properties(${ARG_TARGET} PROPERTIES NEX_SRC_FILES "${ARG_SOURCES}")
endfunction()

# Reads a list of sources from NEX_SRC_FILES property of ${TARGET},
# prepend them with ${PATH}/ if ${PATH} is not an empty string,
# and adds them to the cmake target to compile.
function (nex_add_sources_from_property)
  cmake_parse_arguments(ARG "" "TARGET;PATH;MSG" "" ${ARGN})
  get_target_property(SRC_LIST ${ARG_TARGET} NEX_SRC_FILES)
  set(ORIGINAL_LIST ${SRC_LIST})

  if (ARG_PATH)
    list(TRANSFORM SRC_LIST PREPEND ${ARG_PATH}/)
  endif()

  target_sources(${ARG_TARGET} PUBLIC ${SRC_LIST})

  if (ARG_MSG AND NEX_VERBOSE)
    foreach (file IN LISTS ORIGINAL_LIST)
      nex_log(STATUS "${ARG_MSG}${file}")
    endforeach()
  endif()
endfunction()
