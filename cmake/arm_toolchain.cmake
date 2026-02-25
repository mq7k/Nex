# Configures the cross-compiler toolchain.

message(STATUS "Setting arm cross-compiler")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

# These flags are necessary for Cortex-M3
# set(CMAKE_C_FLAGS_INIT "-mcpu=cortex-m3 -mthumb --specs=nosys.specs -nostartfiles")
# set(CMAKE_CXX_FLAGS_INIT "-mcpu=cortex-m3 -mthumb --specs=nosys.specs -nostartfiles")

# This tells CMake not to try to link executables during its tests
# which would fail for bare-metal targets
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

