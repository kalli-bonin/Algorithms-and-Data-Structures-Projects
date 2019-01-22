cmake_minimum_required(VERSION 3.8.2)
project(LAB3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(LAB3
        drones_manager.cpp
        drones_manager.h
        drones_manager_test.h
        main.cpp)
