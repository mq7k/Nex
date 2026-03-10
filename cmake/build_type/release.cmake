target_compile_options(nex_buildcfg INTERFACE
  -ffunction-sections
  -fdata-sections
  -fno-common
  -Os
  -O3
  -flto=auto
  -g0
)

target_link_options(nex_buildcfg INTERFACE
  -Wl,--gc-sections
  -Wl,--strip-debug
  -s
  -Os
  -O3
  -flto=auto
  -g0
)

target_compile_definitions(nex_buildcfg INTERFACE
  RELEASE_BUILD
)
