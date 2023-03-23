cmake_minimum_required(VERSION 3.15.0)
project(multibackend)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BACKEND_MQTT "use mqtt backend" OFF) # Enabled by default
add_executable(multibackend ./main.cpp)

if(BACKEND_MQTT)
  target_sources(multibackend PRIVATE ./mqtt_backend.cpp)
else()
  target_sources(multibackend PRIVATE ./mcu_backend.cpp)
endif(BACKEND_MQTT)
