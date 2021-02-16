cmake_minimum_required(VERSION 3.15.3)
project(Lab1 CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(Lab1 main.cu)

set_target_properties(
        Lab1
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)