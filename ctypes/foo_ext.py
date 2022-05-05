from ctypes import cdll

_ext = cdll.LoadLibrary("./liba.so")

void_foo_void = _ext.void_foo_void
int_foo_int = _ext.void_foo_int
void_foo_int_int = _ext.void_foo_int_int
void_foo_int_int_int = _ext.void_foo_int_int_int
void_foo_int_int_int_int = _ext.void_foo_int_int_int_int
void_foo_constchar = _ext.void_foo_constchar
