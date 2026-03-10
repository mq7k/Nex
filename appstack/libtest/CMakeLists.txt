add_library(nex_libtest
  src/libtest.c
)

set_property(TARGET nex_libtest PROPERTY C_STANDARD 23)
target_link_libraries(nex_libtest PUBLIC nex_buildcfg)
target_link_libraries(nex_libtest PUBLIC nex_libcom)

target_sources(nex_libtest PUBLIC
  FILE_SET HEADERS
  # BASE_DIRS ${NEX_LIBTEST_BASE_DIR}/include
  BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
  FILES
    include/libtest/libtest.h
)

