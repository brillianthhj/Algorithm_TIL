# project(multithreading)
set(SOURCES main.cpp)
add_executable(aggregation_relation ${SOURCES})

target_include_directories(aggregation_relation PRIVATE ${CMAKE_SOURCE_DIR})