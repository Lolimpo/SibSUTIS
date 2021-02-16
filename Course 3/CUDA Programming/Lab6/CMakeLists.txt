cmake_minimum_required(VERSION 3.13)
project(Lab6 CUDA)

set(CMAKE_CUDA_STANDARD 11)

add_executable(Lab6 main.cu)
#add_executable(Lab6 main_2.cu)

set_target_properties(
        Lab6
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)