#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "B01_string_tolower.cc"

TEST_CASE("B1: string tolower") {
    string a = "PASAR a minUSCUlas";
    string b = "Hola Mundo 123";
    string c = "ya en minusculas";
    string d = "";
    CHECK(string_tolower(a) == "pasar a minusculas");
    CHECK(string_tolower(b) == "hola mundo 123");
    CHECK(string_tolower(c) == "ya en minusculas");
    CHECK(string_tolower(d) == "");
}

TEST_CASE("B1: string tolower no modifica el original") {
    string s = "ABC";
    string r = string_tolower(s);
    CHECK(r == "abc");
    CHECK(s == "ABC");
}
