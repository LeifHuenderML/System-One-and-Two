#ifndef ANDREA_TENSOR_OPS_HPP
#define ANDREA_TENSOR_OPS_HPP

#include "andrea/common.hpp"

#include "andrea/ops/cpu_ops.hpp"
#include "andrea/ops/cuda_ops.hpp"

namespace andrea {

// High-level operations that work on both CPU and GPU
Tensor* add(const Tensor* a, const Tensor* b);


}  // namespace andrea

#endif // ANDREA_TENSOR_OPS_HPP