cmake_minimum_required(VERSION 3.8)
project(LAB4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        fridge_organizer.cpp
        fridge_organizer.hpp)

add_executable(LAB4 ${SOURCE_FILES})