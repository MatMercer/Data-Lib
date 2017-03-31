cmake_minimum_required(VERSION 3.6)
project(datalib)

set(CMAKE_CXX_STANDARD 14)

set(LIB_SOURCES datalib/stack.h datalib/stack.cpp)
add_library(datalib SHARED ${LIB_SOURCES})

set(EXECUTABLE_FILES demo/demo_stack.cpp)
add_executable(stackdemo ${EXECUTABLE_FILES})
target_link_libraries(stackdemo datalib)
