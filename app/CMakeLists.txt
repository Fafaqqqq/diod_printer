cmake_minimum_required(VERSION 3.21)

set(target diod_printer_test)

project(${target})

file(GLOB_RECURSE sources 
    src/*.h
    src/*.cpp
    src/*.c
)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${target} ${sources})

target_link_libraries(${target} diod_printer)

set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

