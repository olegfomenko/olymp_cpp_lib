# cmake_minimum_required(VERSION <specify CMake version here>)
project(core)

set(CMAKE_CXX_STANDARD 14)

add_executable(core main.cpp core/algebra.h core/data_structure.h)