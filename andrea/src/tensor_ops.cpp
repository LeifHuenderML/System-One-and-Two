#include "andrea/tensor_ops.hpp"

// #include "andrea/ops/gpu_ops.hpp"  // If you have GPU operations

namespace andrea {

Tensor* add(const Tensor* a, const Tensor* b) {
    if (a->device == "cpu" && b->device == "cpu") {
        return cpu_add(a, b);
    } else if (a->device == "cuda" && b->device == "cuda") {
        // return gpu_add(a, b);  // Uncomment when you implement GPU ops
        return cpu_add(a,b);
    } else {
        throw std::runtime_error("Tensors must be on the same device");
        return cpu_add(a,b);
    }
}

// Implement other high-level operations...

}  // namespace andrea