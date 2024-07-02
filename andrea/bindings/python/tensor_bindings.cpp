#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "tensor.hpp"  // Assuming the C++ code is in this header

namespace py = pybind11;

PYBIND11_MODULE(pytensor, m) {
    py::class_<Tensor>(m, "Tensor")
        .def(py::init<std::unique_ptr<float[]>, const std::vector<int>&, const std::string&>())
        .def("reshape", &Tensor::reshape)
        .def("get_ndim", &Tensor::get_ndim)
        .def("get_size", &Tensor::get_size)
        .def("get_shape", &Tensor::get_shape)
        .def("get_strides", &Tensor::get_strides)
        .def("get_device", &Tensor::get_device)
        .def("print_tensor", &Tensor::print_tensor)
        .def("get_data", [](const Tensor &t) {
            auto data = t.get_data();
            auto shape = t.get_shape();
            return py::array_t<float>(shape, data.get());
        });

    m.def("add_cpu", &tensor_ops::add_cpu);
}