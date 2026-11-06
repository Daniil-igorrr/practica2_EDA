#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A08_constref_string.cc"

TEST_CASE("A8: invierte el texto") {
    string a = "abc";
    string b = "hola mundo";
    string c = "a";
    CHECK(reversed(a) == "cba");
    CHECK(reversed(b) == "odnum aloh");
    CHECK(reversed(c) == "a");
}

TEST_CASE("A8: vacio") {
    string vacio = "";
    CHECK(reversed(vacio) == "");
}

TEST_CASE("A8: no modifica el original") {
    string s = "abc";
    string r = reversed(s);
    CHECK(r == "cba");
    CHECK(s == "abc");
}
