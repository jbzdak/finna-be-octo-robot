# -*- coding: utf-8 -*-

import ctypes


class LanguageGuesser(object):
    lib = ctypes.cdll.LoadLibrary("/home/jb/programs/coursera/wsdm/hw4/cpp/libstopwords.so")
    lib.init.restype = ctypes.c_void_p
    lib.guess_language.restype = ctypes.c_char_p

    def __init__(self, infile=b"/home/jb/programs/coursera/wsdm/hw4/outfile.txt"):
        self.ctx = self.lib.init(ctypes.c_char_p(infile))

    def guess_language(self, snippet):
        return self.lib.guess_language(
            self.ctx,
            ctypes.c_char_p(snippet.encode("utf8")),
            ctypes.c_char_p(b" "))

    def __del__(self):
        self.lib.deinit(self.ctx)


if __name__ == "__main__":
    lg = LanguageGuesser()
    print(lg.guess_language("To be or not to be"))