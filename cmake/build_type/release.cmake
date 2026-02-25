target_compile_options(eco_buildtype INTERFACE
  -ffunction-sections
  -fdata-sections
  -fno-common
  -Os
  -O3
  -flto=auto
  -g0
)

target_link_options(eco_buildtype INTERFACE
  -Wl,--gc-sections
  -Wl,--strip-debug
  -s
  -Os
  -O3
  -flto=auto
  -g0
)

target_compile_definitions(eco_buildtype INTERFACE
  RELEASE_BUILD
)
