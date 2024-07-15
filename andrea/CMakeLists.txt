cmake_minimum_required(VERSION 3.10)
project(andrea)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(pybind11 REQUIRED)

pybind11_add_module(_andrea 
    python/src/bindings.cpp
    src/tensor.cpp
    src/ops/tensor_ops.cpp
    src/ops/cpu_ops.cpp  # Make sure this is included
    # Add any other source files here
)

target_include_directories(_andrea PRIVATE include)
