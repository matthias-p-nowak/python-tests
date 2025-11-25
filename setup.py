from setuptools import setup, Extension

module = Extension("myext", sources=["pyt/myext.c"])

setup(
    name="myext",
    version="0.1",
    ext_modules=[module],
)
