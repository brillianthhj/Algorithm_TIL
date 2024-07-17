# project(multithreading)
set(EXE_NAME stack_unwinding)
set(SOURCES main.cpp)
add_executable(${EXE_NAME} ${SOURCES})

target_include_directories(${EXE_NAME} PRIVATE
                           ${CMAKE_SOURCE_DIR})