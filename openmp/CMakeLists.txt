cmake_minimum_required(VERSION 3.7)
project(counting_sort)

set(CMAKE_C_STANDARD 99)

# added -fopenmp
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


set(SOURCE_FILES main.c)
add_executable(counting_sort ${SOURCE_FILES})
