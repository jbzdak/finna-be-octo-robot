
#include "capi.hh"
extern "C" {
uint32_t init(const char *infile, void **result) {
    try {
        *result = reinterpret_cast<void *>(LanguageGuesser::from_file_ptr(infile));
        return 0;
    }catch(std::exception e){
        *result = 0;
        return 1; //Note: probably this should hab
    }
}

void deinit(void *ctx) {
    LanguageGuesser *lg = reinterpret_cast<LanguageGuesser *>(ctx);
    delete lg;
}

const char *guess_language(void *ctx, const char *text, const char *delim) {
    LanguageGuesser *lg = reinterpret_cast<LanguageGuesser *>(ctx);
    return lg->langs()[lg->get_language(text, delim)].c_str();
}
}
