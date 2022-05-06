import ctypes

_ext = ctypes.cdll.LoadLibrary("./liba.so")

void_foo_void = _ext.void_foo_void
void_foo_void.argtypes = []
void_foo_void.restype = None

int_foo_int = _ext.void_foo_int
int_foo_int.argtypes = [ctypes.c_int]
int_foo_int.restype = ctypes.c_int

void_foo_int_int = _ext.void_foo_int_int
void_foo_int_int.argtypes = [ctypes.c_int, ctypes.c_int]
void_foo_int_int.restype = None

void_foo_int_int_int = _ext.void_foo_int_int_int
void_foo_int_int_int.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
void_foo_int_int_int.restype = None

void_foo_int_int_int_int = _ext.void_foo_int_int_int_int
void_foo_int_int_int_int.argtypes = [
    ctypes.c_int,
    ctypes.c_int,
    ctypes.c_int,
    ctypes.c_int,
]
void_foo_int_int_int_int.restype = None

void_foo_constchar = _ext.void_foo_constchar
void_foo_constchar.argtypes = [ctypes.c_char_p]
void_foo_constchar.restype = None
