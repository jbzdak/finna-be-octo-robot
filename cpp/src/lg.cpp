#include "lg.hh"


LanguageGuesser::cnstr_pars LanguageGuesser::pars_from_file(std::string infile){
    std::ifstream file;
    internal_map map;
    file.open(infile, std::ios_base::in);
    if(file.rdstate()){
        throw std::logic_error("Couldn't open stopwordss file");
    }
    std::string lang_string;
    std::getline(file, lang_string);

    internal_vec languages;
    boost::split(languages, lang_string, boost::is_any_of(";"));

    std::string stop;
    uint32_t lang;
    while (!file.fail()) {
        file >> stop >> lang;
//        std::cout << stop << " " << lang << std::endl;
        auto item = map.find(stop);
        if (item == map.end()) {
            map[stop] = std::set<uint32_t>();
            item = map.find(stop);
        }
        item->second.insert(lang);
    }
    return std::make_tuple(map, languages);
}

LanguageGuesser* LanguageGuesser::from_file_ptr(std::string infile){
    auto pars = LanguageGuesser::pars_from_file(infile);

    return new LanguageGuesser(
        std::get<0>(pars),
        std::get<1>(pars)
    );
}

std::shared_ptr<LanguageGuesser> LanguageGuesser::from_file(std::string infile){
    auto pars = LanguageGuesser::pars_from_file(infile);

    return std::make_shared<LanguageGuesser>(
        std::get<0>(pars),
        std::get<1>(pars)
    );
}

uint32_t LanguageGuesser::get_language(std::string input, std::string delims){
    internal_vec vec;
    boost::split(vec, input, boost::is_any_of(delims));
    std::vector<uint64_t> languages;
    languages.resize(this->languages.size(), 0);
    for(auto item : vec){
        auto current = stopwords.find(item);
        if (current != stopwords.end()){
            for(auto langid : current->second){
                languages[langid]+=1;
            }
        }
    }

    return std::distance(languages.begin(), std::max_element(languages.begin(), languages.end()));
}
