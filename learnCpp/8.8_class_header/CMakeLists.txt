# project(multithreading)
set(SOURCES main.cpp Calc.cpp)
add_executable(class_header ${SOURCES})

target_include_directories(class_header PRIVATE ${CMAKE_SOURCE_DIR})