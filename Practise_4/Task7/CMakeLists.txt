cmake_minimum_required(VERSION 3.26)
project(Homework_env C)

set(CMAKE_C_STANDARD 11)

add_executable(Homework_env main.c
        env_func.c
        env_func_head.h)
