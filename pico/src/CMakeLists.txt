cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(garage_guardian_pico CXX C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# All the rest
add_executable(garage_guardian
    main.cpp
)

target_link_libraries(garage_guardian pico_stdlib hardware_rtc)

# enable usb output, disable uart output
pico_enable_stdio_usb(garage_guardian 1)
pico_enable_stdio_uart(garage_guardian 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(garage_guardian)
