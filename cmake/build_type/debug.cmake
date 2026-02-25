# Should this be enabled only if NOT ARM_BUILD?
target_compile_options(eco_buildtype INTERFACE
  -ggdb3
  -O0
)

target_link_options(eco_buildtype INTERFACE
  -ggdb3
  -O0
)

target_compile_definitions(eco_buildtype INTERFACE
  NEX_DEBUG_BUILD
)
