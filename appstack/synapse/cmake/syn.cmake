# The main project library.
add_library(synapse)

syn_log(STATUS "Family: ${NEX_MCU_FAMILY}")
syn_log(STATUS "CPU: ${NEX_TARGET_CPU_FAMILY} ${NEX_TARGET_ARCH}")
syn_log(STATUS "Platform: ${NEX_PLATFORM}")

syn_log(STATUS "Compiler flags: ${NEX_COMPILER_FLAGS}")
syn_log(STATUS "Linker flags: ${NEX_LINKER_FLAGS}")
syn_log(STATUS "Tests dir: ${SYN_MCU_DRIVER_TESTS_DIR}")

# Contains mcu specific implementation files.
add_library(syn_chip)

# Contains architecture specific implementation files.
add_library(syn_arch)

include(cmake/sources)

target_link_libraries(syn_chip PRIVATE eco_buildtype)
target_link_libraries(syn_arch PRIVATE eco_buildtype)
target_link_libraries(syn_chip PRIVATE eco_libcom)
target_link_libraries(syn_arch PRIVATE eco_libcom)

# `synapse` is the final project library
# created by merging all the other targets.
target_link_libraries(synapse PUBLIC syn_chip)
target_link_libraries(synapse PUBLIC syn_arch)
target_link_libraries(synapse PUBLIC eco_buildtype)
target_link_libraries(synapse PUBLIC eco_libcom)
target_link_libraries(synapse PUBLIC gcc)

if (NOT NEX_NOCSTD)
  target_link_libraries(synapse PUBLIC c)
endif()

# Links with the specified linker script.
# `PUBLIC` to allow projects to inherits from it,
# and being compiled with the same ld.
if (NEX_PLATFORM_ARM)
  target_link_options(synapse PUBLIC 
    -T${NEX_LD_SCRIPT_PATH} 
    -L${NEX_LD_SCRIPTS_MCU_DIR}
  )
endif()

if (NEX_BUILD_EXAMPLES)
  include(appstack/synapse/cmake/post/examples)
endif()
