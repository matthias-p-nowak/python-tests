#define PY_SSIZE_T_CLEAN
#include <Python.h>

// Our function: add two numbers
static PyObject* myext_add(PyObject* self, PyObject* args) {
    int a, b;
    int result;
Py_BEGIN_ALLOW_THREADS
    // Parse Python arguments: two ints
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    sleep(1);
    printf("adding(%d, %d)\n", a, b);
    result = a + b;
    
    Py_END_ALLOW_THREADS
    // Return a Python integer
    return PyLong_FromLong(result);
}

// List of functions available in the module
static PyMethodDef MyExtMethods[] = {
    {"add", myext_add, METH_VARARGS, "Add two integers."},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// Module definition
static struct PyModuleDef myextmodule = {
    PyModuleDef_HEAD_INIT,
    "myext",   // module name
    NULL,      // module documentation
    -1,        // state (or per-interpreter)
    MyExtMethods
};

// Module initialization function
PyMODINIT_FUNC PyInit_myext(void) {
    return PyModule_Create(&myextmodule);
}
