#ifndef ANDREA_CUDA_OPS_HPP
#define ANDREA_CUDA_OPS_HPP

#include "andrea/common.hpp"
#include <stdexcept>
#include <cuda_runtime.h>
#include <vector>
#include "andrea/tensor.hpp"

namespace andrea{

Tensor* cuda_add(const Tensor* a, const Tensor* b);


} // namespace andrea

#endif