cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(BOARD stm32u575vgtx_custom)

set(EXTRA_CONF_FILE fs.conf)
#set(EXTRA_CONF_FILE usb.conf)
find_package(Zephyr)

project(hello_world)
include_directories(include)


target_sources(app PRIVATE 
    src/main.c
    src/sensor_sht40_test.c
    src/analog_temp_test.c
)