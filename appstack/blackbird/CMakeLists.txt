add_library(nex_blackbird)

list(APPEND CMAKE_MODULE_PATH ${NEX_BLACKBIRD_BASE_DIR})
include(${CMAKE_CURRENT_SOURCE_DIR}/blackbirddefs.cmake)

nex_add_sources(
  TARGET nex_blackbird
  PATH ${NEX_BLACKBIRD_SRC_DIR}
  SOURCES
    modes/acro.c
    modes/angle.c
    modes/ddrive.c

    motors/mixer.c

    proto/crsf.c
    proto/dshot.c
    proto/pwm.c

    vehicle/airplane.c
    vehicle/quadcopter.c
    vehicle/vehicle.c

  MSG "Adding blackbird file: "
)

nex_add_headers(
  TARGET nex_blackbird
  PATH ${NEX_BLACKBIRD_INCLUDE_DIR}
  HEADERS
)

target_link_libraries(nex_blackbird PUBLIC nex_libcom)
target_link_libraries(nex_blackbird PUBLIC nex_synapse)
target_link_libraries(nex_blackbird PUBLIC nex_system)
target_link_libraries(nex_blackbird PUBLIC nex_buildcfg)
target_link_libraries(nex_blackbird PUBLIC m)
target_include_directories(nex_blackbird PUBLIC ${NEX_BLACKBIRD_INCLUDE_DIR})

# if (NEX_BUILD_TESTS)
  # enable_testing()
# endif()
