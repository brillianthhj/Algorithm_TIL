# project(multithreading)
set(SOURCES main.cpp)
add_executable(inheritance_multiple ${SOURCES})

target_include_directories(inheritance_multiple PRIVATE
                           ${CMAKE_SOURCE_DIR})