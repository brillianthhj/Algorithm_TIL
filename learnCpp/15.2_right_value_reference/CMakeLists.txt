# project(multithreading)
set(EXE_NAME right_value_reference)
set(SOURCES main.cpp)
add_executable(${EXE_NAME} ${SOURCES})

target_include_directories(${EXE_NAME} PRIVATE
                           ${CMAKE_SOURCE_DIR})