cmake_minimum_required(VERSION 3.10)
project(Andrea CUDA CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CUDA REQUIRED)

include_directories(include)

# Library target
add_library(andrea
    src/tensor.cpp
    src/ops/cuda_ops.cu
    src/hello_world.cpp  # Make sure this line is present
)

target_include_directories(andrea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(andrea ${CUDA_LIBRARIES})

# Test target
add_executable(tests tests/cpp/test_tensor.cpp)
target_link_libraries(tests PRIVATE andrea)

# Installation
install(TARGETS andrea DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
