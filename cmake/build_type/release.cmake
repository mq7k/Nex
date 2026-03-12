target_compile_options(nex_buildcfg INTERFACE
  -ffunction-sections
  -fdata-sections
  -fno-common
  -Os
  -O3
  -flto=auto
)

target_link_options(nex_buildcfg INTERFACE
  -Wl,--gc-sections
  -Wl,--strip-debug
  -s
  -Os
  -O3
  -flto=auto
)

nex_define_macros_i(nex_buildcfg RELEASE_BUILD)
