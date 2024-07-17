# project(multithreading)
set(SOURCES main.cpp)
add_executable(inheritance_1 ${SOURCES})

target_include_directories(inheritance_1 PRIVATE
                           ${CMAKE_SOURCE_DIR})