# -*- coding: utf-8 -*-

import os, sys

so = os.path.join(os.path.dirname(__file__), "cpp", "libstopwords.so")
stopwords = os.path.join(os.path.dirname(__file__), "outfile.txt").encode("utf-8")

from cffi import FFI

ffi = FFI()

ffi.cdef("""
uint32_t init( const char* infile, void** lg);

void deinit(void* ctx);

const char* guess_language(void* ctx, const char* text, const char* delim);
""")

sw = ffi.dlopen(so)

path = ffi.new("char[]", stopwords)
ctx = ffi.new("void **")
if sw.init(path, ctx) != 0:
    raise ValueError()

ctx = ctx[0]
snippet = ffi.new("char[]", b"To be or not to be")
delim = ffi.new("char[]", b" ")


print(ffi.string(sw.guess_language(ctx, snippet, delim)))