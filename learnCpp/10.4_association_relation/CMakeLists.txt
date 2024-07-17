# project(multithreading)
set(SOURCES main.cpp)
add_executable(association_relation ${SOURCES})

target_include_directories(association_relation PRIVATE
                           ${CMAKE_SOURCE_DIR})