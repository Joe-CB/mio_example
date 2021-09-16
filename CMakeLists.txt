cmake_minimum_required(VERSION 3.0)
project(mio_test)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

MESSAGE(STATUS "this var key = ${CMAKE_BUILD_TYPE}.")


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Og -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -g")
    message("MINGW - Debug mode")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    message("MINGW - Release mode")
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")


MESSAGE(STATUS "this var key = ${CMAKE_CXX_FLAGS}.")
MESSAGE(STATUS "this var key = ${CMAKE_C_FLAGS}.")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

add_executable(monitor ${CMAKE_CURRENT_SOURCE_DIR}/src/monitor.cpp)
add_executable(amender ${CMAKE_CURRENT_SOURCE_DIR}/src/amender.cpp)
add_executable(monitor_sink ${CMAKE_CURRENT_SOURCE_DIR}/src/monitor_sink.cpp)