# Contains mcu specific implementation files.
# add_library(syn_chip)

# Contains architecture specific implementation files.
# add_library(syn_arch)

# add_library(syn_util)

# include(cmake/sources)

set(NEX_COMPILER_FLAGS ${MCU_COMPILER_FLAGS_COM} ${ARCH_COMPILER_FLAGS_COM})
set(NEX_LINKER_FLAGS ${MCU_LINKER_FLAGS_COM} ${ARCH_LINKER_FLAGS_COM})

if (NEX_PLATFORM_ARM)
  # Links with the specified linker script.
  # `PUBLIC` to allow projects to inherits from it,
  # and being compiled with the same ld.
  target_link_options(nex_synapse PUBLIC 
    -T${NEX_MCU_LD_SCRIPT} 
    -L${NEX_SYN_LD_SCRIPTS_DIR}
  )

  list(APPEND NEX_COMPILER_FLAGS 
    ${MCU_COMPILER_FLAGS_ARM}
    ${ARCH_COMPILER_FLAGS_ARM}
  )

  list(APPEND NEX_LINKER_FLAGS 
    ${MCU_LINKER_FLAGS_ARM}
    ${ARCH_LINKER_FLAGS_ARM}
  )

else()
  list(APPEND NEX_COMPILER_FLAGS 
    ${MCU_COMPILER_FLAGS_DESKTOP}
    ${ARCH_COMPILER_FLAGS_DESKTOP}
  )

  list(APPEND NEX_LINKER_FLAGS 
    ${MCU_LINKER_FLAGS_DESKTOP}
    ${ARCH_LINKER_FLAGS_DESKTOP}
  )
endif()

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

target_link_libraries(nex_synapse PUBLIC nex_buildcfg)
target_link_libraries(nex_synapse PUBLIC nex_libcom)
# target_link_libraries(nex_synapse PUBLIC gcc)

# if (NOT NEX_NOCSTD)
#   target_link_libraries(nex_synapse PUBLIC c)
# endif()

if (NEX_BUILD_EXAMPLES)
  include(appstack/nex_synapse/cmake/post/examples)
endif()
