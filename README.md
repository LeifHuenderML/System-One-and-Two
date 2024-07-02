# System-One-and-Two

## Introduction
This repository is dedicated to the active development of an intelligent system designed to integrate both System 1 and System 2 thinking parameters. Our aim is to create a model that seamlessly combines intuitive, fast-thinking processes with analytical, slow-thinking capabilities, reflecting the full spectrum of human cognition. In the real of AI/AGI research System 1 thinking can be though of as the models that are prevalent in almost every domain you see today. They are the CNN's, LSTM's, Transformers and many more popular model architectures. These are programmed or I should say program themselves ahead of time to find the optimal solution. ### add in more here

This being a long term research project with constant need for low level manipulation of library components without dependency nightmare we took the George Hotz route and created our own machine learning library titled ANDREA (Advanced Neural Development Research Engine Application). It is lightweight, and uses the same front end interface as pytorch to give it a very easy onboardning experience. It is written solely to compile with CUDA drivers. 

## Table of Contents
[Stages of Development](docs/stages/README.md)


## Structure
├── andrea
│   ├── bindings
│   │   ├── python
│   │   │   └── tensor_bindings.cpp
│   │   └── rust
│   ├── cpp
│   │   ├── include
│   │   │   └── andrea
│   │   │       ├── autograd
│   │   │       │   ├── function.hpp
│   │   │       │   └── variable.hpp
│   │   │       ├── core
│   │   │       │   ├── device.hpp
│   │   │       │   ├── memory.hpp
│   │   │       │   └── tensor.hpp
│   │   │       ├── io
│   │   │       │   ├── data_loader.hpp
│   │   │       │   └── serialization.hpp
│   │   │       ├── ops
│   │   │       │   ├── basic_ops.hpp
│   │   │       │   ├── lin_alg.hpp
│   │   │       │   └── nn_ops.hpp
│   │   │       └── optimizers
│   │   │           ├── adam.hpp
│   │   │           └── sgd.hpp
│   │   └── src
│   │       ├── autograd
│   │       │   ├── function.cpp
│   │       │   └── variable.cpp
│   │       ├── core
│   │       │   ├── device.cpp
│   │       │   ├── memory.cpp
│   │       │   └── tensor.cpp
│   │       ├── io
│   │       │   ├── data_loader.cpp
│   │       │   └── serialization.cpp
│   │       ├── ops
│   │       │   ├── basic_ops.cpp
│   │       │   ├── lin_alg.cpp
│   │       │   └── nn_ops.cpp
│   │       └── optimizers
│   │           ├── adam.cpp
│   │           └── sgd.cpp
│   ├── cuda
│   │   ├── include
│   │   │   └── andrea
│   │   │       ├── cuda_kernels.hpp
│   │   │       └── cuda_ops.hpp
│   │   └── src
│   │       ├── cuda_kernels.cu
│   │       └── cuda_ops.cu
│   ├── python
│   │   ├── andrea
│   │   │   ├── __init__.py
│   │   │   ├── nn
│   │   │   │   ├── functional.py
│   │   │   │   ├── __init__.py
│   │   │   │   └── modules.py
│   │   │   ├── ops.py
│   │   │   ├── optim
│   │   │   │   ├── __init__.py
│   │   │   │   └── optimizers.py
│   │   │   └── utils
│   │   │       ├── data.py
│   │   │       ├── __init__.py
│   │   │       └── visualization.py
│   │   └── examples
│   │       ├── basic_usage.py
│   │       ├── data_loading.py
│   │       └── neural_netowrk.py
│   └── tests
├── build
│   ├── CMakeCache.txt
│   └── CMakeFiles
│       └── cmake.check_cache
├── CMakeLists.txt
├── data
│   └── MNIST
│       └── raw
│           ├── t10k-images-idx3-ubyte
│           ├── t10k-images-idx3-ubyte.gz
│           ├── t10k-labels-idx1-ubyte
│           ├── t10k-labels-idx1-ubyte.gz
│           ├── train-images-idx3-ubyte
│           ├── train-images-idx3-ubyte.gz
│           ├── train-labels-idx1-ubyte
│           └── train-labels-idx1-ubyte.gz
├── dependencies.sh
├── docs
│   ├── images
│   └── stages
│       └── README.md
├── LICENSE
├── main.py
├── papers
│   ├── links.md
│   └── UnderstandingDeepLearning.pdf
├── README.md
├── research
└── setup.py

## Installation

## Adknowledgements

## Liscence