# project(multithreading)
set(EXE_NAME object_slicing_reference_wrapper)
set(SOURCES main.cpp)
add_executable(${EXE_NAME} ${SOURCES})

target_include_directories(${EXE_NAME} PRIVATE
                           ${CMAKE_SOURCE_DIR})