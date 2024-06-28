#include "tensor.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <ctime>
#include <vector>
#include <cmath>


std::unique_ptr<float[]> createRandomFloatArray(size_t size) {
    auto arr = std::make_unique<float[]>(size);
    std::default_random_engine generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = distribution(generator);
    }
    return arr;
}

std::unique_ptr<float[]> create_growing_array(size_t size){
    auto arr = std::make_unique<float[]>(size);
    for (size_t i = 0; i < size; ++i){
        arr[i] = i;
    }
    return arr;
}

int main() {
    std::vector<int> shape = {1000, 1000, 1000};
    size_t size = 1000 * 1000 * 1000;
    auto arr = createRandomFloatArray(size);
    Tensor tensor1(move(arr), shape);
    arr = createRandomFloatArray(size);
    Tensor tensor2(move(arr), shape);    
    std::cout << "Created tensors";
    Tensor result = tensor_ops::add_cpu(tensor1, tensor2);



    return 0;
}