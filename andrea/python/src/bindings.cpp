#include <pybind11/pybind11.h>
#include "andrea/hello_world.h"
#include "andrea/tensor.h"

namespace py = pybind11;

PYBIND11_MODULE(_andrea, m) {
    py::class_<Hello>(m, "Hello")
        .def(py::init<>())
        .def("print", &Hello::print);

    // Add other bindings here
    // For example:
    // py::class_<Tensor>(m, "Tensor")
    //     .def(py::init<>())
    //     .def("some_method", &Tensor::some_method);
}