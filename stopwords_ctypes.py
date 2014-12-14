# -*- coding: utf-8 -*-

import ctypes
import os

so = os.path.join(os.path.dirname(__file__), "cpp", "libstopwords.so")
stopwords = os.path.join(os.path.dirname(__file__), "outfile.txt").encode("utf-8")

class LanguageGuesser(object):
    lib = ctypes.cdll.LoadLibrary(so)
    lib.init.restype = ctypes.c_uint32
    lib.guess_language.restype = ctypes.c_char_p

    def __init__(self, infile=stopwords):
        self.ctx = ctypes.c_void_p()
        if self.lib.init(ctypes.c_char_p(infile), ctypes.byref(self.ctx)) != 0:
            raise ValueError("Invalid file")

    def guess_language(self, snippet):
        return self.lib.guess_language(
            self.ctx,
            ctypes.c_char_p(snippet.encode("utf8")),
            ctypes.c_char_p(b" "))

    def __del__(self):
        self.lib.deinit(self.ctx)

lg = LanguageGuesser()
print(lg.guess_language("To be or not to be"))