cmake_minimum_required(VERSION 3.24)
project(C_Calc C)

set(CMAKE_C_STANDARD 23)

add_executable(C_Calc source/main.c source/systems.c source/systems.h source/io.c source/io.h)
target_link_libraries(C_Calc m)