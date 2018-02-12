#include <Python.h>

#include "argon2d/argon2.h"



static PyObject *argon2d_getpowhash(PyObject *self, PyObject *args)
{
    void* ctx;
    WolfArgon2dAllocateCtx(&ctx);
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    WolfArgon2dPoWHash(output(char *), ctx, PyBytes_AsString((PyObject*) input));
#else
    WolfArgon2dPoWHash(output, ctx, (char *)PyString_AsString((PyObject*) input));
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef Argon2dMethods[] = {
    { "getPoWHash", argon2d_getpowhash, METH_VARARGS, "Returns the Argon2d hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef Argon2dModule = {
    PyModuleDef_HEAD_INIT,
    "argon2d_hash",
    "...",
    -1,
    Argon2dMethods
};

PyMODINIT_FUNC PyInit_argon2d_hash(void) {
    return PyModule_Create(&Argon2dModule);
}

#else

PyMODINIT_FUNC initargon2d_hash(void) {
    (void) Py_InitModule("argon2d_hash", Argon2dMethods);
}
#endif
