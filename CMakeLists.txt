# cmake_minimum_required(VERSION <specify CMake version here>)
project(core)

set(CMAKE_CXX_STANDARD 14)

add_executable(core main.cpp core/other/algebra.h core/data_structure/segment_tree.h core/data_structure/graph.h core/data_structure/dsu.h)