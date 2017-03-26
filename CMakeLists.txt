cmake_minimum_required(VERSION 3.6)
project(stacklib)

set(CMAKE_CXX_STANDARD 14)

set(LIB_SOURCES stacklib/stack.h stacklib/stack.cpp)
add_library(stacklib SHARED ${LIB_SOURCES})

set(EXECUTABLE_FILES demo/demo.cpp)
add_executable(stackdemo ${EXECUTABLE_FILES})
target_link_libraries(stackdemo stacklib)
