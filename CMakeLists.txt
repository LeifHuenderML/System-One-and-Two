andrea/
├── bindings/
│   ├── python/
│   │   ├── tensor_bindings.cpp
│   │   ├── ops_bindings.cpp
│   │   └── autograd_bindings.cpp
│   └── javascript/
│       └── wasm_bindings.cpp
├── cpp/
│   ├── include/
│   │   └── andrea/
│   │       ├── core/
│   │       │   ├── tensor.hpp
│   │       │   ├── device.hpp
│   │       │   └── memory.hpp
│   │       ├── ops/
│   │       │   ├── basic_ops.hpp
│   │       │   ├── nn_ops.hpp
│   │       │   └── linear_algebra.hpp
│   │       ├── autograd/
│   │       │   ├── variable.hpp
│   │       │   └── function.hpp
│   │       ├── optimizers/
│   │       │   ├── sgd.hpp
│   │       │   └── adam.hpp
│   │       └── io/
│   │           ├── serialization.hpp
│   │           └── data_loader.hpp
│   └── src/
│       ├── core/
│       ├── ops/
│       ├── autograd/
│       ├── optimizers/
│       └── io/
├── cuda/
│   ├── include/
│   │   └── andrea/
│   │       ├── cuda_ops.hpp
│   │       └── cuda_kernels.hpp
│   └── src/
│       ├── cuda_ops.cu
│       └── cuda_kernels.cu
├── python/
│   ├── andrea/
│   │   ├── __init__.py
│   │   ├── tensor.py
│   │   ├── ops.py
│   │   ├── nn/
│   │   │   ├── __init__.py
│   │   │   ├── modules.py
│   │   │   └── functional.py
│   │   ├── optim/
│   │   │   ├── __init__.py
│   │   │   └── optimizers.py
│   │   └── utils/
│   │       ├── __init__.py
│   │       ├── data.py
│   │       └── visualization.py
│   └── examples/
│       ├── basic_usage.py
│       ├── neural_network.py
│       └── data_loading.py
├── tests/
│   ├── cpp/
│   │   ├── core/
│   │   ├── ops/
│   │   ├── autograd/
│   │   └── optimizers/
│   ├── cuda/
│   │   └── test_cuda_ops.cu
│   └── python/
│       ├── test_tensor.py
│       ├── test_ops.py
│       ├── test_nn.py
│       └── test_optim.py
├── benchmarks/
│   ├── cpp/
│   │   └── benchmark_ops.cpp
│   └── python/
│       └── benchmark_tensor_ops.py
├── docs/
│   ├── api/
│   ├── user_guide/
│   ├── tutorials/
│   └── performance_guide/
├── tools/
│   ├── code_generation/
│   │   └── op_generator.py
│   └── profiling/
│       └── memory_profiler.py
├── third_party/
│   ├── eigen/
│   └── pybind11/
├── cmake/
│   ├── FindCUDA.cmake
│   └── FindEigen.cmake
├── scripts/
│   ├── install_dependencies.sh
│   └── run_tests.sh
├── CMakeLists.txt
├── setup.py
├── pyproject.toml
├── README.md
├── CONTRIBUTING.md
├── CHANGELOG.md
└── LICENSE