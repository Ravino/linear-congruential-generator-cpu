cmake_minimum_required(VERSION 3.16)
project(linear-congruential-generator-cpu)

set(CMAKE_CXX_STANDARD 20)

add_executable(build randomizer.h randomizer.cpp flow.h flow.cpp worker.h worker.cpp generator.h generator.cpp index.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")
