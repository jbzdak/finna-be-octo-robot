#pragma once

#include <iostream>
#include <sstream>
#include <locale>
#include <fstream>

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <tuple>
#include<memory>
using namespace std;

class LanguageGuesser{
public:
    typedef std::map<std::string, std::set<uint32_t>>  internal_map;
    typedef std::vector<std::string> internal_vec;
    typedef std::tuple<internal_map, internal_vec> cnstr_pars;
private:
    const internal_map stopwords;
    const internal_vec languages;
    static cnstr_pars pars_from_file(std::string infile);

public:

    LanguageGuesser(const internal_map& stopwords, const internal_vec& languages):
        stopwords(stopwords),
        languages(languages)
    {}

    /**
    * Creates LanguageGuesser from a datafile containing stopwords.
    */
    static LanguageGuesser* from_file_ptr(std::string infile);

    static std::shared_ptr<LanguageGuesser> from_file(std::string infile);

    /**
    * input string will be tokenized using delimiters from delims, then we will guess
    * the language and return language_index.
    *
    * To obtain language name use: this->langs()[language_index]
    */
    uint32_t get_language(std::string input, std::string delims);

    /**
    * Vector with all languages we can detect.
    */
    const internal_vec& langs(){return languages;}

};