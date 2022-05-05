/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Python.h>
#include <stdio.h>

static PyObject *void_foo_void(PyObject *self, PyObject *args) {
    Py_RETURN_NONE;
}


static PyObject *int_foo_int(PyObject *self, PyObject *const *args,
                             Py_ssize_t nargs) {
    long a_int;

    a_int = PyLong_AsLong(args[0]);
    if (a_int == -1 && PyErr_Occurred()) {
        return NULL;
    }

    return PyLong_FromLong(a_int + 1);
}

static PyObject *void_foo_int(PyObject *self, PyObject *const *args,
                              Py_ssize_t nargs) {
    long a_int;

    a_int = PyLong_AsLong(args[0]);
    if (a_int == -1 && PyErr_Occurred()) {
      return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject *void_foo_int_int(PyObject *self, PyObject *const *args,
                                  Py_ssize_t nargs) {
  int a_int, b_int;

  a_int = PyLong_AsLong(args[0]);
  if (a_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  b_int = PyLong_AsLong(args[1]);
  if (b_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  Py_RETURN_NONE;
}

static PyObject *void_foo_int_int_int(PyObject *self, PyObject *const *args,
                                      Py_ssize_t nargs) {
  int a_int, b_int, c_int;

  a_int = PyLong_AsLong(args[0]);
  if (a_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  b_int = PyLong_AsLong(args[1]);
  if (b_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  c_int = PyLong_AsLong(args[2]);
  if (c_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  Py_RETURN_NONE;
}

static PyObject *void_foo_int_int_int_int(PyObject *self, PyObject *const *args,
                                          Py_ssize_t nargs) {
  int a_int, b_int, c_int, d_int;

  a_int = PyLong_AsLong(args[0]);
  if (a_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  b_int = PyLong_AsLong(args[1]);
  if (b_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  c_int = PyLong_AsLong(args[2]);
  if (c_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  d_int = PyLong_AsLong(args[3]);
  if (d_int == -1 && PyErr_Occurred()) {
    return NULL;
  }

  Py_RETURN_NONE;
}

static PyObject *void_foo_constchar(PyObject *self, PyObject *const *args,
                                    Py_ssize_t nargs) {
  const char *a;
  Py_ssize_t size;

  a = PyUnicode_AsUTF8AndSize(args[0], &size);

  if (a == NULL) {
      return NULL;
  }

  Py_RETURN_NONE;
}

static PyMethodDef foo_methods[] = {
    {"void_foo_void",  (PyCFunction) void_foo_void, METH_NOARGS, "void foo(void)"},
    {"int_foo_int",  (PyCFunction) int_foo_int, METH_FASTCALL, "int foo(int)"},
    {"void_foo_int",  (PyCFunction) void_foo_int, METH_FASTCALL, "void foo(int)"},
    {"void_foo_int_int",  (PyCFunction) void_foo_int_int, METH_FASTCALL, "void foo(int, int)"},
    {"void_foo_int_int_int",  (PyCFunction) void_foo_int_int_int, METH_FASTCALL, "void foo(int, int, int)"},
    {"void_foo_int_int_int_int",  (PyCFunction) void_foo_int_int_int_int, METH_FASTCALL, "void foo(int, int, int, int)"},
    {"void_foo_constchar",  (PyCFunction) void_foo_constchar, METH_FASTCALL, "void foo(const char *)"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef foo_module =
{
    PyModuleDef_HEAD_INIT,
    "foo_ext", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    foo_methods
};


PyMODINIT_FUNC PyInit_foo_ext(void)
{
    return PyModule_Create(&foo_module);
}

