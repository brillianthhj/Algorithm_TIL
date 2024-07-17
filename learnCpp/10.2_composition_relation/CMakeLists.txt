# project(multithreading)
set(SOURCES main.cpp)
add_executable(composition_relation ${SOURCES})

target_include_directories(composition_relation PRIVATE ${CMAKE_SOURCE_DIR})