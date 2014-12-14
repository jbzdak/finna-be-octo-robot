

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

#include "lg.hh"

int main() {

    auto lg = LanguageGuesser::from_file("/home/jb/programs/coursera/wsdm/hw4/cpp/outfile.txt");


    for (std::string input; std::getline(std::cin, input);) {
        std::cout << input << " " << lg->langs()[lg->get_language(input, " ")] << std::endl;
    }


    return 0;
}