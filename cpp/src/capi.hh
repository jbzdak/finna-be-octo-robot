#pragma once
#include "lg.hh"

extern "C"{

uint32_t init( const char* infile, void** lg);

void deinit(void* ctx);

const char* guess_language(void* ctx, const char* text, const char* delim);
}
