# -*- coding: utf-8 -*-

import os, sys

from cffi import FFI

ffi = FFI()

ffi.cdef("""
uint32_t init( const char* infile, void** lg);

void deinit(void* ctx);

const char* guess_language(void* ctx, const char* text, const char* delim);
""")

sw = ffi.dlopen("/home/jb/programs/coursera/wsdm/hw4/cpp/libstopwords.so")

path = ffi.new("char[]", b"/home/jb/programs/coursera/wsdm/hw4/outfile.txt")
ctx = ffi.new("void **")
if sw.init(path, ctx) != 0:
    raise ValueError()

ctx = ctx[0]
snippet = ffi.new("char[]", b"To be or not to be")
delim = ffi.new("char[]", b" ")


print(ffi.string(sw.guess_language(ctx, snippet, delim)))