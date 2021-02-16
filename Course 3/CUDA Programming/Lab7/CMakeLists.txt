cmake_minimum_required(VERSION 3.16)
project(Lab7 CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(Lab7 main.cu)

set_target_properties(
        Lab7
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)