cmake_minimum_required(VERSION 3.15.0)
project(uuid)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(uuid main.cpp)
add_executable(test_uuid ./test_random_uuid.cpp ./contrib/catch_amalgamated.cpp)

if (WIN32)
    target_sources(uuid PRIVATE ./uuid_win.cpp)
    target_sources(test_uuid PRIVATE ./uuid_win.cpp)
else()
    target_sources(uuid PRIVATE ./uuid_linux.cpp)
    target_sources(test_uuid PRIVATE ./uuid_linux.cpp)
endif()

if(WIN32)
    message("hello")
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

    set_target_properties(uuid PROPERTIES COMPILE_FLAGS "/wd4819")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ignore:4099 /ignore:4819")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

install(TARGETS uuid)
