#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <immintrin.h>
#include <thread>
#include <sstream>
#include <iostream>
#include <iomanip>

class Tensor {
private:
    std::vector<int> shape;
    std::vector<int> strides;
    int ndim;
    int size;
    std::string device;
    std::unique_ptr<float[]> data;

    void set_size() {
        size = 1;
        for (int dim : shape) {
            size *= dim;
        }
    }

    void set_ndim() {
        ndim = static_cast<int>(shape.size());
    }

    void calc_strides() {
        strides.resize(shape.size());
        int s = 1;
        for (int i = static_cast<int>(shape.size()) - 1; i >= 0; --i) {
            strides[i] = s;
            s *= shape[i];
        }
    }

    void check_shape() {
        if (shape.empty()) {
            throw std::invalid_argument("Shape cannot be empty.");
        }
    }
    
    void print_recursive(std::ostringstream& oss, int dimension, int offset) const {
        if (dimension == ndim - 1) {
            // Print the last dimension
            oss << "[";
            for (int i = 0; i < shape[dimension]; ++i) {
                oss << std::fixed  << data[offset + i];
                if (i < shape[dimension] - 1) oss << ", ";
            }
            oss << "]";
        } else {
            // Print higher dimensions
            oss << "[";
            int stride = strides[dimension];
            for (int i = 0; i < shape[dimension]; ++i) {
                print_recursive(oss, dimension + 1, offset + i * stride);
                if (i < shape[dimension] - 1) oss << ",\n" << std::string(dimension + 1, ' ');
            }
            oss << "]";
        }
    }

public:
    // Constructor
    Tensor(std::unique_ptr<float[]> data, const std::vector<int>& shape, const std::string& device="cuda")
        : data(std::move(data)), shape(shape), device(device) {
        check_shape();
        set_ndim();
        set_size();
        calc_strides();
    }

    // Utility functions
    void reshape(std::vector<int> new_shape) {
        int old_size = size;
        shape = std::move(new_shape);
        set_ndim();
        set_size();
        if (size != old_size) {
            throw std::invalid_argument("New shape must preserve the total number of elements.");
        }
        check_shape();
        calc_strides();
    }

    // Getter functions
    int get_ndim() const { return ndim; }
    int get_size() const { return size; }
    std::vector<int> get_shape() const { return shape; }
    std::vector<int> get_strides() const { return strides; }
    std::string get_device() const { return device; }
    const float* get_data_ptr() const { return data.get(); }

    std::unique_ptr<float[]> get_data() const {
        auto data_copy = std::make_unique<float[]>(size);
        std::copy(data.get(), data.get() + size, data_copy.get());
        return data_copy;
    }

    // Display Functions
    void print_tensor() const {
        std::ostringstream oss;
        print_recursive(oss, 0, 0);
        std::cout << oss.str() << std::endl;
    }
};

namespace tensor_ops {

    void add_chunk(const float* a, const float* b, float* result, size_t start, size_t end) {
        for (size_t i = start; i < end; ++i) {
            result[i] = a[i] + b[i];
        }
    }

    Tensor add_cpu(const Tensor& tensor1, const Tensor& tensor2) {
        // Check shapes
        if (tensor1.get_shape() != tensor2.get_shape()) {
            throw std::invalid_argument("Tensors must have the same shape for addition.");
        }

        size_t size = tensor1.get_size();
        auto result = std::make_unique<float[]>(size);
        const float* a = tensor1.get_data_ptr();
        const float* b = tensor2.get_data_ptr();

        unsigned int num_threads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads(num_threads);
        
        size_t chunk_size = size / num_threads;
        
        for (unsigned int t = 0; t < num_threads; ++t) {
            size_t start = t * chunk_size;
            size_t end = (t == num_threads - 1) ? size : (t + 1) * chunk_size;
            
            threads[t] = std::thread(add_chunk, a, b, result.get(), start, end);
        }
        
        for (auto& thread : threads) {
            thread.join();
        }

        return Tensor(std::move(result), tensor1.get_shape(), tensor1.get_device());
    }

    // Tensor randn(){

    //     return;
    // }

} // namespace tensor_ops

#endif // TENSOR_HPP