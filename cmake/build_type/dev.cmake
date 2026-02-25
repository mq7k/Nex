target_compile_options(eco_buildtype INTERFACE
  -ggdb3
  -O0
)

target_link_options(eco_buildtype INTERFACE
  -Wl,--gc-sections
  -ggdb3
  -O0
)

if (NEX_BUILD_TESTS)
  target_compile_options(eco_buildtype INTERFACE
    -fsanitize=address
    -fsanitize=undefined
  )

  target_link_options(eco_buildtype INTERFACE
    -fsanitize=address
    -fsanitize=undefined
  )
endif()

eco_define_option(NEX_INCLUDE_DEVMODE)

target_compile_definitions(eco_buildtype INTERFACE
  DEV_BUILD
)

