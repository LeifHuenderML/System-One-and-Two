#ifndef ANDREA_TENSOR_OPS_HPP
#define ANDREA_TENSOR_OPS_HPP

#include "common.hpp"
#include "andrea/tensor.hpp"
#include "andrea/ops/cpu_ops.hpp"

namespace andrea {

// High-level operations that work on both CPU and GPU
Tensor* add(const Tensor* a, const Tensor* b);
// Other high-level operations...

}  // namespace andrea

#endif // ANDREA_TENSOR_OPS_HPP