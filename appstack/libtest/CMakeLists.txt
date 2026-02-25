add_library(eco_libtest
  src/libtest.c
)

set_property(TARGET eco_libtest PROPERTY C_STANDARD 23)
target_link_libraries(eco_libtest PUBLIC eco_buildtype)
target_link_libraries(eco_libtest PUBLIC eco_libcom)

target_sources(eco_libtest PUBLIC
  FILE_SET HEADERS
  BASE_DIRS ${NEX_LIBTEST_BASE_DIR}/include
  FILES
    ${NEX_LIBTEST_BASE_DIR}/include/libtest/libtest.h
)

