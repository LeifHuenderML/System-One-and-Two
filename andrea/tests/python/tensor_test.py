import andrea
import numpy as np

print(dir(andrea))

# tensor = andrea.create_ones([2,4,4], device="cpu")
# print(tensor.data)
# print(tensor.shape)
# print(tensor.size)
# print(tensor.strides)
# print(tensor.ndim)

tensor = andrea.create_ones([2,4,4], device="cuda")
print(tensor.data)
print(tensor.shape)
print(tensor.size)
print(tensor.strides)
print(tensor.ndim)

# tensor = andrea.create_random([2,4,4])
# print(tensor.data)
# print(tensor.shape)
# print(tensor.size)
# print(tensor.strides)
# print(tensor.ndim)

# arr = np.random.rand(2,4,4)
# tensor = andrea.create_tensor(arr, [2,4,4])
# print(tensor.data)
# print(tensor.shape)
# print(tensor.size)
# print(tensor.strides)
# print(tensor.ndim)

# tensor1 = andrea.create_ones([10,10,10],)
# tensor2 = andrea.create_ones([10,10,10],)


# result = andrea.add_tensor(tensor1, tensor2)
# print(result.data)

# print(result.shape)
# print(result.size)
# print(result.strides)
# print(result.ndim)
# print(result.device)

# tensor = andrea.create_random([2,2], )
# print(tensor.data)
# print(tensor.shape)
# print(tensor.size)
# print(tensor.strides)
# print(tensor.ndim)
# print(tensor.device)

# andrea.to_device(tensor, "cuda")
# print(tensor.data)
# print(tensor.shape)
# print(tensor.size)
# print(tensor.strides)
# print(tensor.ndim)
# print(tensor.device)