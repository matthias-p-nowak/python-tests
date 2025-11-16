# UV

Environment was generated using `uv sync`.

# Project layout
*Visual studio code* seems to have problems with the modern layout, where the source files reside in a `src` folder. Hence, the first package folder is in the project folder.

# Module not found

`pytest` has a standard convention where to look for test files and what the files and methods should be named (containing test in the name). 
But when executing a test, the package might not be found.

## Quirks

If there are tests in the normal package folders, then pytest has loaded the modules from those folder and tests with the incorrect configuration pass. Once those temporary tests are removed, the unrelated tests under `/tests` will fail.

# Pytest configuration

~~~TOML
[project]
name = "pyt"
version = "0.1.0"
description = "Add your description here"
readme = "README.md"
requires-python = ">=3.13"
dependencies = []

[build-system]
requires = ["setuptools>=61"]
build-backend = "setuptools.build_meta"

[tool.pytest.ini_options]
addopts = ""
pythonpath = "."
~~~

The important line is `pythonpath = "."`, which extends the path to the current project.