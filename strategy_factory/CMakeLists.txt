cmake_minimum_required(VERSION 3.15.0)
project(multibackend)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(multibackend ./main.cpp ./backend.cpp ./mcu_backend.cpp ./mqtt_backend.cpp)
