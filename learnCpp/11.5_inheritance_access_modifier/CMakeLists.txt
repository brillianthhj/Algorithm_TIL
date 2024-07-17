# project(multithreading)
set(SOURCES main.cpp)
add_executable(inheritance_access ${SOURCES})

target_include_directories(inheritance_access PRIVATE
                           ${CMAKE_SOURCE_DIR})