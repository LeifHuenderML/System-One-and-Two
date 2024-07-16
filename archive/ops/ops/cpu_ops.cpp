#include "andrea/ops/cpu_ops.hpp"
#include "andrea/tensor.hpp"

namespace andrea {

Tensor* cpu_add(const Tensor* a, const Tensor* b) {
    // Check if tensors are on CPU
    if (a->device != "cpu" || b->device != "cpu") {
        throw std::runtime_error("Both tensors must be on CPU for cpu_add operation.");
    }

    // Check if shapes match
    if (a->ndim != b->ndim || !std::equal(a->shape, a->shape + a->ndim, b->shape)) {
        throw std::runtime_error("Tensor shapes must match for addition.");
    }

    // Create result tensor
    std::vector<int> shape(a->shape, a->shape + a->ndim);
    Tensor* result = create_tensor(nullptr, shape, "cpu");

    // Perform addition
    #pragma omp parallel for if(a->size > 1000)
    for (int i = 0; i < a->size; ++i) {
        result->data[i] = a->data[i] + b->data[i];
    }

    return result;
}

}  // namespace andrea
