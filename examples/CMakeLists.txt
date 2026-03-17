if (EXISTS ${NEX_EXAMPLES_DIR})
  if (NEX_VERBOSE)
    nex_log(STATUS "Including examples for: ${NEX_MCU_FAMILY_LINE}")
  endif()

  add_subdirectory(${NEX_EXAMPLES_DIR})
else()
  nex_log(WARNING "No examples were found for '${NEX_MCU_FAMILY_LINE}'")
endif()

