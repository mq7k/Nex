include(${CMAKE_CURRENT_SOURCE_DIR}/libtestdefs.cmake)

add_library(nex_libtest
  # src/libtest.c
)

# target_sources(nex_libtest PUBLIC
#   FILE_SET HEADERS
#   BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
#   FILES
#     include/libtest/libtest.h
# )

nex_add_sources(
  TARGET nex_libtest
  PATH ${NEX_LIBTEST_SRC_DIR}
  SOURCES
    libtest.c
)

nex_add_headers(
  TARGET nex_libtest
  PATH ${NEX_LIBTEST_INC_DIR}
  HEADERS
    include/libtest/libtest.h
)

set_property(TARGET nex_libtest PROPERTY C_STANDARD 23)
target_link_libraries(nex_libtest PUBLIC nex_buildcfg)
target_link_libraries(nex_libtest PUBLIC nex_libcom)

