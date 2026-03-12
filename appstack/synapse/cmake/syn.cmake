# Formats `stm32f411xe` -> `STM32F411xE`
list(TRANSFORM NEX_MCU_GROUPS TOUPPER OUTPUT_VARIABLE NEX_MCU_FORMATTED_GROUPS)
list(TRANSFORM NEX_MCU_FORMATTED_GROUPS REPLACE "X" "x")

# Example: CPU_CM4F
set(NEX_CPU_MODEL CPU_${NEX_ARCH_DRIVERS_GROUP})

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
target_link_libraries(nex_synapse PUBLIC gcc)

# if (NEX_BUILD_EXAMPLES)
#   include(appstack/nex_synapse/cmake/post/examples)
# endif()

# Toggling hardware (FPU) floats.
# The user can specify preferences with '--float'.
if (NEX_PLATFORM_ARM)

  # First, we can safely add CPU flags.
  get_target_property(HW_CFLAGS nex_hw_flags INTERFACE_COMPILE_OPTIONS)
  get_target_property(HW_LFLAGS nex_hw_flags INTERFACE_LINK_OPTIONS)

  if (NOT HW_CFLAGS STREQUAL "HW_CFLAGS-NOTFOUND")
    target_compile_options(nex_buildcfg INTERFACE ${HW_CFLAGS})
  endif()

  if (NOT HW_LFLAGS STREQUAL "HW_LFLAGS-NOTFOUND")
    target_link_options(nex_buildcfg INTERFACE ${HW_LFLAGS})
  endif()

  # We always need this one.
  nex_add_sources(
    TARGET nex_synapse_soc
    PATH ${NEX_SYN_SRC_DIR}/cpu/${NEX_CPU_FAMILY}
    SOURCES common/init.c
    MSG "Adding startup file: "
  )

  # Now we can select the FPU implementation.
  # CPUs files (cm4f.cmake, cm3.cmake, ...) sets
  # this property, if available.
  # NEX_FLOAT_HARD, NEX_FLOAT_SOFTFP and NEX_FLOAT_SOFT
  # are preferences specified by the user.
  get_target_property(has_fpu nex_buildcfg NEX_HAS_FPU)
  if (DEFINED NEX_FLOAT_HARD AND ${has_fpu} STREQUAL "ON")
    get_target_property(FPU_HW_TYPE nex_buildcfg NEX_FPU_TYPE)

    target_compile_options(nex_buildcfg INTERFACE
      -mfloat-abi=hard
      -mfpu=${FPU_HW_TYPE}
    )

    target_link_options(nex_buildcfg INTERFACE
      -mfloat-abi=hard
      -mfpu=${FPU_HW_TYPE}
    )

    nex_define_macros_i(nex_buildcfg NEX_FPU NEX_FPU_FPREG)
    nex_log(STATUS "Using hardware float (Full).")

  elseif (DEFINED NEX_FLOAT_SOFTFP AND ${has_fpu} STREQUAL "ON")
    get_target_property(FPU_HW_TYPE nex_buildcfg NEX_FPU_TYPE)

    target_compile_options(nex_buildcfg INTERFACE
      -mfloat-abi=softfp
      -mfpu=${FPU_HW_TYPE}
    )

    target_link_options(nex_buildcfg INTERFACE
      -mfloat-abi=softfp
      -mfpu=${FPU_HW_TYPE}
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

    if (DEFINED NEX_FLOAT_HARD OR DEFINED NEX_FLOAT_SOFTFP)
      nex_log(WARNING "Float type was set to '${NEX_FLOAT}' but the hardware does not support it. Falling back to software float.")
    else()
      nex_log(STATUS "Using software float.")
    endif()
  endif()
endif()

