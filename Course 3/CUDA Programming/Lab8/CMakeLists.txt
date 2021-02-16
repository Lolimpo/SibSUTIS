cmake_minimum_required(VERSION 3.16)
project(Lab8 CUDA)

set(CMAKE_CUDA_STANDARD 14)

#add_executable(Lab8 8_1.cu)
add_executable(Lab8 8_2.cu)
target_link_libraries(Lab8 -lcublas -lcufft)
set_target_properties(
        Lab8
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)