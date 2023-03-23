cmake_minimum_required(VERSION 3.15.0)
project(uuid)

# conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(uuid ./main.cpp ./random_uuid.cpp)
add_executable(test_uuid ./test_random_uuid.cpp ./random_uuid.cpp )

target_link_libraries(uuid ${CONAN_LIBS})
target_link_libraries(test_uuid ${CONAN_LIBS})

if(WIN32)
    set_target_properties(uuid PROPERTIES COMPILE_FLAGS "/wd4819")

    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
    add_definitions(-D_WIN32_WINNT=0x0601)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)

    add_definitions(-DBOOST_SYSTEM_USE_UTF8) # 使用 UTF-8 编码

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ignore:4099")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

install(TARGETS uuid)
