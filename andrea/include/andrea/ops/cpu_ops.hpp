#ifndef ANDREA_CPU_OPS_HPP
#define ANDREA_CPU_OPS_HPP

#include "common.hpp"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <vector>
namespace andrea{

Tensor* cpu_add(const Tensor* a, const Tensor* b);

} //namespace andrea

#endif /* ANDREA_CPU_OPS_HPP */