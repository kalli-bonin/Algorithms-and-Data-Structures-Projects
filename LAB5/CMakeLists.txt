cmake_minimum_required(VERSION 3.8)
project(LAB5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        binary_search_tree.cpp
        binary_search_tree.hpp
        main.cpp
        priority_queue.cpp
        priority_queue.hpp
        tests.hpp)

add_executable(LAB5 ${SOURCE_FILES})