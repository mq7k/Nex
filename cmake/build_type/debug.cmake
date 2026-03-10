# Should this be enabled only if NOT ARM_BUILD?
target_compile_options(nex_buildcfg INTERFACE
  -ggdb3
  -O0
)

target_link_options(nex_buildcfg INTERFACE
  -ggdb3
  -O0
)

target_compile_definitions(nex_buildcfg INTERFACE
  NEX_DEBUG_BUILD
)
