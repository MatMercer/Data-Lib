cmake_minimum_required(VERSION 3.6)
project(datalib)

set(CMAKE_CXX_STANDARD 14)

# Compile all the lib sources
set(LIB_SOURCES datalib/stack.h datalib/stack.cpp datalib/queue.cpp datalib/queue.h datalib/list.cpp datalib/list.h datalib/node.cpp datalib/node.h datalib/linked_queue.cpp datalib/linked_queue.h)
add_library(datalib SHARED ${LIB_SOURCES})

# Stack demo
set(STACK_FILES demo/demo_stack.cpp)
add_executable(stackdemo ${STACK_FILES})
target_link_libraries(stackdemo datalib)

# Queue demo
set(QUEUE_FILES demo/demo_queue.cpp)
add_executable(queuedemo ${QUEUE_FILES})
target_link_libraries(queuedemo datalib)

# List demo
set(LIST_FILES demo/demo_list.cpp)
add_executable(listdemo ${LIST_FILES})
target_link_libraries(listdemo datalib)

# Linked queue demo
set(LINKED_QUEUE_FILES demo/demo_linked_queue.cpp)
add_executable(linkedqueuedemo ${LINKED_QUEUE_FILES})
target_link_libraries(linkedqueuedemo datalib)
