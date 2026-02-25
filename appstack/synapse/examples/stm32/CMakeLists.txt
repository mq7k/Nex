foreach(example ${MCU_EXAMPLES})
  syn_log(STATUS "Adding example project: ${example}")
  add_subdirectory(${example})
endforeach()
