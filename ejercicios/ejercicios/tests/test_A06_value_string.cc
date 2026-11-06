#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "common/doctest.h"
#include "A06_value_string.cc"

TEST_CASE("A6: anade el sufijo") {
    string s = "hola";
    string suf = "_1";
    CHECK(with_suffix(s, suf) == "hola_1");
}

TEST_CASE("A6: no modifica los originales") {
    string s = "hola";
    string suf = "_1";
    string r = with_suffix(s, suf);
    CHECK(r == "hola_1");
    CHECK(s == "hola");
    CHECK(suf == "_1");
}

TEST_CASE("A6: cadenas vacias") {
    string vacio = "";
    string x = "x";
    CHECK(with_suffix(vacio, x) == "x");
    CHECK(with_suffix(x, vacio) == "x");
}
