# notes for referencing and paper compilations

Recreating PyTorch from Scratch (with GPU Support and Automatic Differentiation)

- medium article
- goes over how to build a tensor in cpp, make a cuda for it and wrap it in python

What is a tensor
    Data structure that efficiently stores and manipulates large amounts of data and is capable of handling any type of data dimensionality.

Important parts include:
    shape: is the size of each dimension 
    strides: aids in indexing through the data array
    