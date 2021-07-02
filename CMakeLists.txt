cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(hello_pico)

pico_sdk_init()

add_executable(hello_pico main.cc)

pico_add_extra_outputs(hello_pico)

target_link_libraries(hello_pico pico_stdlib)