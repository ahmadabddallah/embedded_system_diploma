cmake_minimum_required(VERSION 3.26)
project(Embedded_Diploma C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Embedded_Diploma
        main.c
        math.c
        math.h
        queue.c
        queue.h
        stack.c
        stack.h
        string.c
        string.h)
