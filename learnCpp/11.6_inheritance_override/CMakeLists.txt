# project(multithreading)
set(SOURCES main.cpp)
add_executable(inheritance_override ${SOURCES})

target_include_directories(inheritance_override PRIVATE
                           ${CMAKE_SOURCE_DIR})