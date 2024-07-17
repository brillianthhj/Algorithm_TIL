# project(multithreading)
set(SOURCES main.cpp)
add_executable(polymorphism ${SOURCES})

target_include_directories(polymorphism PRIVATE
                           ${CMAKE_SOURCE_DIR})