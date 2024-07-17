# project(multithreading)
set(SOURCES main.cpp)
add_executable(inheritance_sequence ${SOURCES})

target_include_directories(inheritance_sequence PRIVATE
                           ${CMAKE_SOURCE_DIR})