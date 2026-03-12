# Should this be enabled only if NOT ARM_BUILD?
target_compile_options(nex_buildcfg INTERFACE
  -ggdb3
  -O0
  -fno-omit-frame-pointer
  -fstack-usage
  -fstack-protector-strong
)

target_link_options(nex_buildcfg INTERFACE
  -ggdb3
  -O0
  -fno-omit-frame-pointer
  -Wl,-Map=linker.map
)

if (NEX_BUILD_TESTS)
  target_compile_options(nex_buildcfg INTERFACE
    -fsanitize=address,undefined,leak
  )

  target_link_options(nex_buildcfg INTERFACE
    -rdynamic
    -fno-inline
  )
endif()

nex_define_macros_i(nex_buildcfg NEX_DEBUG_BUILD)
