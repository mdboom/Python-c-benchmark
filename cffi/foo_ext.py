import cffi

ffi = cffi.FFI()
ffi.cdef("""
void void_foo_void(void);

int int_foo_int(int a);

void void_foo_int(int a);

void void_foo_int_int(int a, int b);

void void_foo_int_int_int(int a, int b, int c);

void void_foo_int_int_int_int(int a, int b, int c, int d);

void void_foo_constchar(const char* str);
""")

_ext = ffi.dlopen("./liba.so")

void_foo_void = _ext.void_foo_void
int_foo_int = _ext.void_foo_int
void_foo_int_int = _ext.void_foo_int_int
void_foo_int_int_int = _ext.void_foo_int_int_int
void_foo_int_int_int_int = _ext.void_foo_int_int_int_int
void_foo_constchar = _ext.void_foo_constchar
