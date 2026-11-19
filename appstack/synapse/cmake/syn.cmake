# Formats `stm32f411xe` -> `STM32F411xE`
list(TRANSFORM SYN_DEFS_LIST TOUPPER OUTPUT_VARIABLE NEX_MCU_FORMATTED_GROUPS)
list(TRANSFORM NEX_MCU_FORMATTED_GROUPS REPLACE "X" "x")

# Example: CPU_CM4F
set(NEX_CPU_MODEL CPU_${SYN_CDG_GROUP})
string(TOUPPER ${NEX_CPU_MODEL} NEX_CPU_MODEL)

# We add those macros to `nex_buildcfg`
# so any layer can inherit them.
nex_define_macros_i(nex_buildcfg
  ${NEX_CPU_MODEL}
  ${NEX_CPU_FAMILY}
  ${NEX_MCU_FAMILY}
  ${NEX_MCU_FAMILY_LINE}
  ${NEX_MCU_FULLNAME}
)

nex_define_macros_iraw(nex_buildcfg ${NEX_MCU_FORMATTED_GROUPS})

target_link_libraries(nex_synapse PUBLIC nex_synapse_soc)
target_link_libraries(nex_synapse PUBLIC nex_buildcfg)
target_link_libraries(nex_synapse PUBLIC nex_libcom)

# Toggling hardware (FPU) floats.
# The user can specify preferences with '--float'.
if (NEX_PLATFORM_ARM)

  # First, we can safely add CPU flags.
  if (DEFINED SYN_CPU_CO)
    target_compile_options(nex_buildcfg INTERFACE ${SYN_CPU_CO})
  endif()

  if (DEFINED SYN_CPU_LO)
    target_link_options(nex_buildcfg INTERFACE ${SYN_CPU_LO})
  endif()

  # We always need this one.
  nex_add_sources(
    TARGET nex_synapse_soc
    PATH ${NEX_SYN_SRC_DIR}/cpu/${NEX_CPU_FAMILY}
    SOURCES common/init.c
    MSG "Adding startup file: "
  )

  # Not the most aesthetic piece of code, I know.
  target_link_options(nex_synapse PUBLIC 
    -T${NEX_SYN_LD_SCRIPTS_DIR}/${NEX_MCU_FAMILY}/${SYN_SOC_LD}.ld
    -L${NEX_SYN_LD_SCRIPTS_DIR}/${NEX_MCU_FAMILY}
  )

  # Now we can select the FPU implementation.
  # CPUs files (cm4f.cmake, cm3.cmake, ...) sets
  # this property, if available.
  # NEX_FLOAT_HARD, NEX_FLOAT_SOFTFP and NEX_FLOAT_SOFT
  # are preferences specified by the user.
  if ((DEFINED NEX_FLOAT_HARD OR DEFINED NEX_FLOAT_AUTO) AND DEFINED SYN_CPU_FPU)
    target_compile_options(nex_buildcfg INTERFACE
      -mfloat-abi=hard
      -mfpu=${SYN_CPU_FPU}
    )

    target_link_options(nex_buildcfg INTERFACE
      -mfloat-abi=hard
      -mfpu=${SYN_CPU_FPU}
    )

    nex_define_macros_i(nex_buildcfg NEX_FPU NEX_FPU_FPREG)
    nex_log(STATUS "Using hardware float (Full).")

  elseif (DEFINED NEX_FLOAT_SOFTFP AND DEFINED SYN_CPU_FPU)
    target_compile_options(nex_buildcfg INTERFACE
      -mfloat-abi=softfp
      -mfpu=${SYN_CPU_FPU}
    )

    target_link_options(nex_buildcfg INTERFACE
      -mfloat-abi=softfp
      -mfpu=${SYN_CPU_FPU}
    )

    nex_define_macros_i(nex_buildcfg NEX_FPU)
    nex_log(STATUS "Using hardware float (Op-only).")

  else()
    target_compile_options(nex_buildcfg INTERFACE
      -mfloat-abi=soft
    )

    target_link_options(nex_buildcfg INTERFACE
      -mfloat-abi=soft
    )

    if ((DEFINED NEX_FLOAT_HARD OR DEFINED NEX_FLOAT_SOFTFP) AND NOT DEFINED NEX_FLOAT_AUTO)
      nex_log(WARNING "Float type was set to '${NEX_FLOAT}' but the hardware does not support it. Falling back to software float.")
    else()
      nex_log(STATUS "Using software float.")
    endif()
  endif()
endif()

