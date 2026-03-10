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

# Takes in a list of macros, transport them to upper case,
# and defines them to be access from C code.
function (nex_define_macros_p target)
  set(MACROS_LIST ${ARGN})
  list(TRANSFORM MACROS_LIST TOUPPER)
  target_compile_definitions(${target} PUBLIC ${MACROS_LIST})
endfunction()

function (nex_define_macros_i target)
  set(MACROS_LIST ${ARGN})
  list(TRANSFORM MACROS_LIST TOUPPER)
  target_compile_definitions(${target} INTERFACE ${MACROS_LIST})
endfunction()

function (nex_define_macros_iraw target)
  set(MACROS_LIST ${ARGN})
  target_compile_definitions(${target} INTERFACE ${MACROS_LIST})
endfunction()

