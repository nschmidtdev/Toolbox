from setuptools import setup
from Cython.Build import cythonize
import os

# Zielordner für kompilierten Code
build_dir = os.path.join(os.getcwd(), "cython")

setup(
    ext_modules=cythonize("main.py", compiler_directives={'language_level': "3"}),
    script_args=["build_ext", "--build-lib", build_dir]
)
