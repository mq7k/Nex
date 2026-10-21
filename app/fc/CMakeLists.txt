add_executable(
  flight_controller 
  main.c
)

target_link_libraries(flight_controller PRIVATE nex_buildcfg)
target_link_libraries(flight_controller PRIVATE nex_libcom)
target_link_libraries(flight_controller PRIVATE nex_system)
target_link_libraries(flight_controller PRIVATE nex_synapse)
target_link_libraries(flight_controller PRIVATE nex_blackbird)

nex_add_generate_binary_file_cmd(flight_controller)
