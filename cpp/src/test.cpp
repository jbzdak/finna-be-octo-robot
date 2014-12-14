#define BOOST_TEST_MODULE "C++ Unit Tests for MyTangledLibrary"
#define BOOST_TEST_CATCH_SYSTEM_ERRORS yes
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <memory>
#include <vector>
#include "lg.hh"
#include "capi.hh"


void make_test(std::string snippet, std::string expected_lang){

    auto lg = LanguageGuesser::from_file("/home/jb/programs/coursera/wsdm/hw4/cpp/outfile.txt");

    auto res = lg->get_language(snippet, " ");

//    std::cout << "Result " << res << std::endl;

    std::stringstream msg;

    msg << "Expected " << expected_lang << " got " << lg->langs().at(res);

    BOOST_CHECK_MESSAGE(lg->langs().at(res) == expected_lang, msg.str());

}

BOOST_AUTO_TEST_SUITE(TestLg)

BOOST_AUTO_TEST_CASE(TEST_ENG){
    std::string snippet = "Different algorithms use different metrics for measuring \"best\". These generally measure the homogeneity of the target variable within the subsets. Some examples are given below. These metrics are applied to each candidate subset, and the resulting values are combined (e.g., averaged) to provide a measure of the quality of the split.";
    make_test(snippet, "english");
}

BOOST_AUTO_TEST_CASE(TEST_DAN){
    std::string snippet = "En af metoderne, som Sea Shepherd folkene brugte for at forhindre grindedrab, var at holde udkig. De brugte kikkerter, som de spejdede med ud på havet, fra deres udvalgte udkigsposter fra land. Selv i stormvejr, hvor grindedrab ikke vil finde sted og i tåget vejr, hvor sigtbarheden var lig med nul, stod Sea Shepherd folk på deres poster og spejdede ud mod havet. Da de - formodentlig på dage uden tåge - fik øje på en flok grindehvaler, kunne de ringe til andre aktivister, som sejlede ude på have i små både, hvorefter disse kunne jage hvalerne ud på åbent hav. Sea Shepherds leder, Paul Watson, fortalte i et interview med Færøernes TV-avis, at hans folk fire gange havde jaget flokke af grindehvaler til havs før færinger fik øje på dem De færøske (tidligere danske/norske) myndigheder har ført statistik over hvalfangsten i flere århundreder og har tal tilbage til 1584, og før det førte katolske kirkemyndigheder statistikken, men de tal findes ikke på Færøerne. Det angives på Færøernes Fiskeriministeriums grindehjemmeside whaling.fo, at der i perioden fra 2000 til 2013 slagtedes 671 grindehvaler årligt, dette varierede fra 0 i 2008 til det højeste fangsttal som var 1107 (i 2010). Hvidsidede delfiner (springarar på færøsk), døglinger og andre hvalarter føres i separat statistik og tælles ikke sammen med grindehvalen, som er den mest almindelige hvalart som fanges på Færøerne, men ikke den eneste.";
    make_test(snippet, "danish");
}

BOOST_AUTO_TEST_CASE(TEST_DUTCH){
    std::string snippet = "Rond 1500 kwam er een streven op gang om een algemene schrijftaal te ontwikkelen die in ruimere gebieden bruikbaar kon zijn door verschillende regionale elementen in zich te verenigen. Dat was ook een behoefte vanuit de centralisering van het bestuur onder het Bourgondische hertogschap dat zijn gezag vanuit Brussel over de gehele Nederlanden wilde uitbreiden, een streven waarin keizer Karel V tenslotte ook zou slagen. In de reformatietijd waren het vooral de Bijbelvertalingen en religieuze traktaten waarmee een brede verspreiding werd beoogd, en welke daarom doelbewust in een algemene schrijftaal werden gesteld. Voorlopig bleef het bij pogingen waarin elke auteur zijn eigen streektaal het meeste gewicht gaf. De tenaamstelling van de 'algemene' schrijftaal in deze werken is interessant omdat 'Nederlands' daarbij een uitzondering is. Men vindt 'Plat duytsch' (1524), 'Brabants' (1526 en 1546), 'Nederlantsch duytsch' (1558) aangegeven als Bijbeltaal en de voornaamste, de Statenvertaling van 1637, heet dan voor het eerst 'Nederlandsch'. Maar voor seculiere werken is de benaming 'Nederduytsch' of zelfs kortweg 'Duytsch' en opvallend genoeg wordt de taal juist in grammatica's en spraak- en spellingboeken voor het onderwijs tot aan de";
    make_test(snippet, "dutch");
}

BOOST_AUTO_TEST_CASE(TEST_FIN){
    std::string snippet = "Istuntojen ulkopuolisessa salaisessa neuvottelussa päätettiin, että eduskunta siirtyy Kauhajoelle, jonne muutto tapahtui välittömästi kello kolme joulukuun 1. päivän vastaisena yönä. Kauhajoki valittiin, koska se sijaitsi kaukana itärajasta eikä siellä ollut Neuvostoliiton pommituksille kiinnostavia kohteita kuten satamaa tai lentokenttää. Kansanedustajilla avustajineen oli vain muutama tunti aikaa koota tavaransa pimeästä eduskuntatalosta, ennen kuin kaksitoistatuntinen junamatka Kauhajoelle alkoi. Kauhajoella eduskunnan tulosta tiedettiin vain tunti ennen junan saapumista kello 14.30. Ensimmäinen istunto pidettiin 5. joulukuuta. Koko Kauhajoella olon ajan eduskunnan toiminta oli niin salaista, etteivät edes kaikki kauhajokelaiset tienneet, mitä pitäjässä tapahtui";
    make_test(snippet, "finnish");
}


BOOST_AUTO_TEST_SUITE_END();
void make_test_capi(std::string snippet, std::string expected_lang){

    void* lg;

    BOOST_CHECK(init("/home/jb/programs/coursera/wsdm/hw4/cpp/outfile.txt", &lg)==0);

    std::string res = guess_language(lg, snippet.c_str(), " ");

//    std::cout << "Result " << res << std::endl;

    std::stringstream msg;

    msg << "Expected " << expected_lang << " got " << res;

    BOOST_CHECK_MESSAGE(res== expected_lang, msg.str());

}


BOOST_AUTO_TEST_SUITE(Capi)
BOOST_AUTO_TEST_CASE(TEST_ENG){
    std::string snippet = "Different algorithms use different metrics for measuring \"best\". These generally measure the homogeneity of the target variable within the subsets. Some examples are given below. These metrics are applied to each candidate subset, and the resulting values are combined (e.g., averaged) to provide a measure of the quality of the split.";
    make_test_capi(snippet, "english");
}
BOOST_AUTO_TEST_SUITE_END();