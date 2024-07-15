#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "andrea/hello_world.h"
#include "andrea/tensor.hpp"
#include "andrea/tensor_ops.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_andrea, m) {
    py::class_<Hello>(m, "Hello")
        .def(py::init<>())
        .def("print", &Hello::print);

    py::class_<andrea::Tensor>(m, "Tensor")  // Change this line
        .def_property_readonly("data", [](const andrea::Tensor& t) {
            return py::array_t<float>({t.size}, {sizeof(float)}, t.data, py::cast(t));
        })
        .def_property_readonly("shape", [](const andrea::Tensor& t) {
            return py::array_t<int>({t.ndim}, {sizeof(int)}, t.shape, py::cast(t));
        })
        .def_property_readonly("strides", [](const andrea::Tensor& t) {
            return py::array_t<int>({t.ndim}, {sizeof(int)}, t.strides, py::cast(t));
        })
        .def_readonly("ndim", &andrea::Tensor::ndim)
        .def_readonly("size", &andrea::Tensor::size)
        .def_readonly("device", &andrea::Tensor::device);

    m.def("create_tensor", [](py::array_t<float, py::array::c_style | py::array::forcecast> data,
                              std::vector<int> shape, std::string device="cuda") {
        if (!data.is_none()) {
            if (data.size() != std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int>())) {
                throw std::runtime_error("Data size does not match the specified shape");
            }
            return andrea::create_tensor(static_cast<const float*>(data.data()), shape, device);
        } else {
            return andrea::create_tensor(nullptr, shape, device);
        }
    }, py::arg("data") = py::none(), py::arg("shape"), py::arg("device") = "cuda",
    "Create a new tensor with given data, shape, and device");

    m.def("create_ones", &andrea::create_ones, py::arg("shape"), py::arg("device") = "cuda",
          "Create a new tensor filled with ones");
    m.def("create_zeros", &andrea::create_zeros, py::arg("shape"), py::arg("device") = "cuda",
          "Create a new tensor filled with zeros");
    m.def("create_random", &andrea::create_random, py::arg("shape"), py::arg("device") = "cuda",
          "Create a new tensor filled with random values");
    m.def("delete_tensor", &andrea::delete_tensor, "Delete a tensor and free its memory");
    m.def("add", &andrea::add, py::arg("a"), py::arg("b"), "Add 2 tensors of same shape");
}