if (EXISTS ${NEX_SYN_SOC_EXAMPLES_DIR})
  add_subdirectory(${NEX_SYN_SOC_EXAMPLES_DIR})
else()
  nex_log(WARNING "No examples were found for '${NEX_MCU_FAMILY_LINE}'")
endif()

