from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools
import os

class GetPybindInclude(object):
    def __init__(self, user=False):
        self.user = user

    def __str__(self):
        import pybind11
        return pybind11.get_include(self.user)

ext_modules = [
    Extension(
        'andrea._andrea',
        ['python/src/bindings.cpp', 'src/tensor.cpp', 'src/hello_world.cpp', 'src/tensor_ops.cpp', 'src/ops/cpu_ops.cpp'],
        include_dirs=[
            GetPybindInclude(),
            GetPybindInclude(user=True),
            'include'
        ],
        language='c++',
        extra_compile_args=['-std=c++17']
    ),
]

setup(
    name='andrea',
    version='0.0.1',
    author='Leif Huender',
    author_email='leifhuenderai@gmail.com',
    description='Tensor and autograd library.',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.4'],
    setup_requires=['pybind11>=2.4'],
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
    packages=['andrea'],
    package_dir={'': 'python'}
)
