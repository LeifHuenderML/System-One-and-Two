#include "andrea/ops/cuda_ops.hpp"


namespace andrea{

__global__ void add_kernel(float* a, float* b, float* result, int size) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < size) {
        result[idx] = a[idx] + b[idx];
    }
}

Tensor* cuda_add(const Tensor* a, const Tensor* b) {
    if (a->device != "cuda" || b->device != "cuda") {
        throw std::runtime_error("Both tensors must be on CUDA device for cuda_add operation.");
    }
    if (a->size != b->size) {
        throw std::runtime_error("Tensor sizes must match for addition.");
    }

    Tensor* result = create_tensor(nullptr, std::vector<int>(a->shape, a->shape + a->ndim), "cuda");

    int block_size = 256;
    int num_blocks = (a->size + block_size - 1) / block_size;

    add_kernel<<<num_blocks, block_size>>>(a->data, b->data, result->data, a->size);

    cudaError_t err = cudaGetLastError();
    if (err != cudaSuccess) {
        throw std::runtime_error(cudaGetErrorString(err));
    }

    return result;
}

} // namespace andrea
