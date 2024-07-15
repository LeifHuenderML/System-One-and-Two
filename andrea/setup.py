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
        ['python/src/bindings.cpp', 'src/hello_world.cpp'],
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
    author='Your Name',
    author_email='your.email@example.com',
    description='Andrea tensor library',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.4'],
    setup_requires=['pybind11>=2.4'],
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
    packages=['andrea'],
    package_dir={'': 'python'}
)
