cmake_minimum_required(VERSION 3.15)
project(Courseweork2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Courseweork2 main.cpp RandomSequence.cpp RandomSequence.h parasailFunction.cpp parasailFunction.h)
include_directories("/home/andrei/CLionProjects/parasail")
target_link_libraries(Courseweork2 "/home/andrei/CLionProjects/parasail/cmake-build-debug/libparasail.so")