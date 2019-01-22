cmake_minimum_required(VERSION 3.10)
project(LAB6)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(LAB6
        InterpersonalAffinity.cpp
        InterpersonalAffinity.hpp
        InterpersonalAffinityTest.cpp)
