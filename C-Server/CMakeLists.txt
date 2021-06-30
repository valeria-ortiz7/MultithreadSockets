cmake_minimum_required(VERSION 3.19)
project(ServerC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

add_executable(ServerC
        Server.c
        Server.h)
