# project(multithreading)
set(SOURCES main.cpp)
add_executable(inheritance_2 ${SOURCES})

target_include_directories(inheritance_2 PRIVATE
                           ${CMAKE_SOURCE_DIR})