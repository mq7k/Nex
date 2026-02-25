function(eco_log level message)
  message(${level} "[Eco] ${message}")
endfunction()

function(eco_sublog level prefix message)
  message(${level} "[Eco::${prefix}] ${message}")
endfunction()

# Converts the compiled ELF file into a binary file
# executable by a microcontroller.
# The output file is placed in the same directory
# as the ELF input file.
function(eco_add_generate_binary_file_cmd target)
  add_custom_command(TARGET ${target} POST_BUILD
    COMMAND
      ${CMAKE_OBJCOPY} -O binary 
      $<TARGET_FILE:${target}> 
      ${CMAKE_CURRENT_BINARY_DIR}/${target}.bin
    COMMENT
      "Generating binary file ${CMAKE_CURRENT_BINARY_DIR}/${target}.bin"
  )
endfunction()
