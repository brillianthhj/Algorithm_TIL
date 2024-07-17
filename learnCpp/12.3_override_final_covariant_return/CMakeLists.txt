# project(multithreading)
set(EXE_NAME override_final_covariant_return)
set(SOURCES main.cpp)
add_executable(${EXE_NAME} ${SOURCES})

target_include_directories(${EXE_NAME} PRIVATE
                           ${CMAKE_SOURCE_DIR})