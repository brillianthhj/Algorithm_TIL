# project(multithreading)
set(SOURCES main.cpp Worker.cpp)
add_executable(dependency_relation ${SOURCES})

target_include_directories(dependency_relation PRIVATE
                           ${CMAKE_SOURCE_DIR})