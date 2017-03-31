cmake_minimum_required(VERSION 3.6)
project(datalib)

set(CMAKE_CXX_STANDARD 14)

set(LIB_SOURCES datalib/stack.h datalib/stack.cpp datalib/queue.cpp datalib/queue.h)
add_library(datalib SHARED ${LIB_SOURCES})

set(STACK_FILES demo/demo_stack.cpp)
add_executable(stackdemo ${STACK_FILES})
target_link_libraries(stackdemo datalib)

set(QUEUE_FILES demo/demo_queue.cpp)
add_executable(queuedemo ${QUEUE_FILES})
target_link_libraries(queuedemo datalib)
