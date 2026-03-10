add_subdirectory(drivers)

if (NEX_PLATFORM_ARM)
  # add_source_file(syn_arch common/cm.S common/init.c)
else()
  # add_source_file(syn_arch common/cmd.S)
endif()

if (ARCH_CPU_HAS_FPU)
  # add_source_file(syn_arch common/fpu.S)
endif()
