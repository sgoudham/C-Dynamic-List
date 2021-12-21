cmake_minimum_required(VERSION 3.22)
project(C_Dynamic_List C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src/test)

add_executable(C_Dynamic_List src/list.c src/test/test.c src/list.h)
