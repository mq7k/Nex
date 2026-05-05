include(${CMAKE_CURRENT_SOURCE_DIR}/libtestdefs.cmake)
add_library(nex_libtest)

nex_add_sources(
  TARGET nex_libtest
  PATH ${NEX_LIBTEST_SRC_DIR}
  SOURCES
    libtest.cpp
    printutil.cpp
)

nex_add_headers(
  TARGET nex_libtest
  PATH ${NEX_LIBTEST_INC_DIR}
  HEADERS
    libtest/libtest.hpp
    libtest/comparator.hpp
    libtest/assertions.hpp
)

set_property(TARGET nex_libtest PROPERTY C_STANDARD 23)
set_property(TARGET nex_libtest PROPERTY CXX_STANDARD 23)

target_link_libraries(nex_libtest PUBLIC nex_buildcfg)
target_link_libraries(nex_libtest PUBLIC nex_libcom)

# Math library.
target_link_libraries(nex_libtest PUBLIC m)

