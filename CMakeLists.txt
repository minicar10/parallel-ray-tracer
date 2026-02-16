cmake_minimum_required(VERSION 3.10)
project(ParallelRayTracer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable SIMD instructions (SSE/AVX) for the compiler
if(MSVC)
    add_compile_options(/arch:AVX2)
else()
    add_compile_options(-mavx2 -pthread)
endif()

add_executable(RayTracer main.cpp)
